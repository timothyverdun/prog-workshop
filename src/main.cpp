#include <sil/sil.hpp>
#include "random.hpp"
#include <cmath>
#include <algorithm>

// NE GARDER QUE LE VERT
void onlygreen(sil::Image &image)
{
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = 0.f;
            image.pixel(x, y).b = 0.f;
        }
    }
    image.save("output/onlygreen.png");
}

// PASSER EN NOIR ET BLANC
void blackandwhite(sil::Image &image)
{
    for (glm::vec3 &color : image.pixels())
    {
        float gray = 0.299f * color.r + 0.587f * color.g + 0.114f * color.b;
        color.r = gray;
        color.g = gray;
        color.b = gray;
    }
    image.save("output/blackandwhite.png");
}

// NEGATIF
void negative(sil::Image &image)
{
    for (glm::vec3 &color : image.pixels())
    {
        color.r = 1 - color.r;
        color.g = 1 - color.g;
        color.b = 1 - color.b;
    }
    image.save("output/negative.png");
}

// DEGRADE
void degrade()
{
    sil::Image image{300 /*width*/, 200 /*height*/};

    for (float x{0}; x < image.width(); x++)
    {
        float color = x * 1 / image.width();

        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = color;
            image.pixel(x, y).g = color;
            image.pixel(x, y).b = color;
        }
    }
    image.save("output/degrade.png");
}

// MIROIR
void miror(sil::Image &image)
{
    sil::Image new_image{image.width(), image.height()};
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            int new_x = image.width() - 1 - x;
            new_image.pixel(new_x, y) = image.pixel(x, y);
        }
    }
    new_image.save("output/miror.png");
}

// IMAGE BRUITEE
void noise(sil::Image &image)
{
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            int rd = random_int(0, 100);
            if (rd % 100 < 5)
            {
                image.pixel(x, y) = glm::vec3{
                    random_float(0, 1),
                    random_float(0, 1),
                    random_float(0, 1)};
            }
        }
    }
    image.save("output/noise.png");
}

// ROTATION DE 90
void rotate90(sil::Image &image)
{
    sil::Image new_image{image.height(), image.width()};
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            int new_x = -y;
            int new_y = x;
            new_image.pixel(new_x, new_y) = image.pixel(x, y);
        }
    }
    new_image.save("output/rotate90.png");
}

// RGB SPLIT
void rgbsplit(sil::Image &image)
{
    sil::Image new_image{image.width(), image.height()};
    int splitvalue = 5;
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            int x_left = std::max(0, x - splitvalue);
            int x_right = std::min(image.width() - 1, x + splitvalue);
            new_image.pixel(x, y) = glm::vec3{
                image.pixel(x_left, y).r,
                image.pixel(x, y).g,
                image.pixel(x_right, y).b};
        }
    }
    new_image.save("output/rgbsplit.png");
}

// LUMINOSITE
void lum(sil::Image &image)
{
    float lum_value = 1.5;
    for (glm::vec3 &color : image.pixels())
    {
        color.r = std::pow(color.r, lum_value);
        color.g = std::pow(color.g, lum_value);
        color.b = std::pow(color.b, lum_value);
    }
    image.save("output/lum.png");
}

// DISQUE
void disk()
{
    sil::Image image{500, 500};
    float a = image.width() / 2;
    float b = image.height() / 2;
    float r = 100;
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            if (std::pow((x - a), 2) + std::pow((y - b), 2) < (r * r))
            {
                image.pixel(x, y) = glm::vec3{1, 1, 1};
            }
        }
    }
    image.save("output/disk.png");
}

// CERCLE
void circle(sil::Image &image, int cx, int cy, int thickness)
{
    int r = 100;
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            float dist2 = std::pow(x - cx, 2) + std::pow(y - cy, 2);
            if (dist2 < r * r && dist2 > std::pow(r - thickness, 2))
            {
                image.pixel(x, y) = glm::vec3{1, 0.8, 1};
            }
        }
    }
}

// ROSACE
void rosace()
{
    sil::Image image{500, 500};
    int center_x = image.width() / 2.0f;
    int center_y = image.height() / 2.0f;
    int r = 100;
    int thickness = 5;
    int nb_cercles = 8;
    float pas = (2.0f * 3.14159265f) / nb_cercles;

    circle(image, 250, 250, 5);
    for (int k = 0; k < nb_cercles; k++)
    {
        float angle = k * pas;
        int a = center_x + r * std::cos(angle);
        int b = center_y + r * std::sin(angle);
        circle(image, a, b, thickness);
    }

    image.save("output/rosace.png");
}

// RETRECIR IMAGE
void smallimg(sil::Image &image, int div_size)
{

    sil::Image small_image{image.width() / div_size, image.height() / div_size};
    for (int x = 0; x < image.width(); x += div_size)
    {
        for (int y{0}; y < image.height(); y += div_size)
        {
            small_image.pixel(x / div_size, y / div_size) = image.pixel(x, y);
        }
    }
    small_image.save("output/smallimg.png");
}

// MOSAIQUE
void mosaic(sil::Image &image, int size)
{
    sil::Image mosaic_image{image.width(), image.height()};

    int small_w = image.width() / size;
    int small_h = image.height() / size;

    for (int x = 0; x < mosaic_image.width(); x++)
    {
        for (int y = 0; y < mosaic_image.height(); y++)
        {
            int src_x = (x % small_w) * size;
            int src_y = (y % small_h) * size;

            mosaic_image.pixel(x, y) = image.pixel(src_x, src_y);
        }
    }

    mosaic_image.save("output/mosaic.png");
}

// GLITCH
void glitch(sil::Image &image, int gain)
{
    sil::Image glitch_image = image;
    for (int i = 0; i < gain; i++)
    {
        
        int x_size = random_int(0, image.height()/10);
        int y_size = random_int(0, image.height()/20);

        int max_x = std::max(0, image.width() - x_size);
        int max_y = std::max(0, image.height() - y_size);

        int src_x = random_int(0, max_x);
        int src_y = random_int(0, max_y);
        int new_x = random_int(0, max_x);
        int new_y = random_int(0, max_y);
        for (int i = 0; i < x_size; i++)
        {
            for (int j = 0; j < y_size; j++)
            {
                glitch_image.pixel(new_x + i,new_y + j)=image.pixel(src_x + i,src_y + j);
                glitch_image.pixel(src_x + i,src_y + j)=image.pixel(new_x + i,new_y + j);
            }
        }
    }
    glitch_image.save("output/glitch.png");
}

// TRI DES PIXELS
void sortpixels(sil::Image &image)
{
    sil::Image sorted_img = image;
    auto &px = sorted_img.pixels();
    int w = sorted_img.width();
    int h = sorted_img.height();

    for (int y = 0; y < h; y++)
    {
        auto begin_it = px.begin() + y * w;
        auto end_it   = begin_it + w;

        std::sort(begin_it, end_it, [](const glm::vec3 &a, const glm::vec3 &b) {
            return a.r > b.r;
        });
    }

    sorted_img.save("output/sortedpixels.png");
}

int main()
{
    sil::Image image{"images/logo.png"};
    sortpixels(image);
}