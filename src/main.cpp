#include <sil/sil.hpp>
#include "random.hpp"

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
                    random_float(0, 1), random_float(0, 1), random_float(0, 1)};
            }
        }
    }
    image.save("output/noise.png");
}

void rotate90(sil::Image &image){
    sil::Image new_image{image.height(), image.width()};
    for (int x = 0; x < image.width(); x++)
    {
        for (int y = 0; y < image.height(); y++)
        {
            int new_x = - y;
            int new_y = x;
            new_image.pixel(new_x, new_y) = image.pixel(x,y);
        }
    }
    new_image.save("output/rotate90.png");

}

int main()
{
    sil::Image image{"images/logo.png"};
    rotate90(image);
}