#include <sil/sil.hpp>
#include "random.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>

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
void degrade(sil::Image &image)
{

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
            int new_x = image.height() - 1 - y;
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
void lum(sil::Image &image, float lum_value)
{
    for (glm::vec3 &color : image.pixels())
    {
        color.r = std::pow(color.r, lum_value);
        color.g = std::pow(color.g, lum_value);
        color.b = std::pow(color.b, lum_value);
    }
    image.save("output/lum.png");
}

// DISQUE
void disk(sil::Image &image)
{
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
void rosace(sil::Image &image)
{
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
    int w = image.width();
    int h = image.height();
    sil::Image small_image{w / div_size, h / div_size};
    for (int x = 0; x < image.width(); x += div_size)
    {
        for (int y{0}; y < image.height(); y += div_size)
        {
            int sx = x / div_size;
            int sy = y / div_size;
            if (sx < small_image.width() && sy < small_image.height())
            {
                small_image.pixel(sx, sy) = image.pixel(x, y);
            }
        }
    }
    small_image.save("output/smallimg.png");
    std::cout << "Image sauvgardee dans output/smallimg.png. \n";
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

        int x_size = random_int(0, image.height() / 10);
        int y_size = random_int(0, image.height() / 20);

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
                glitch_image.pixel(new_x + i, new_y + j) = image.pixel(src_x + i, src_y + j);
                glitch_image.pixel(src_x + i, src_y + j) = image.pixel(new_x + i, new_y + j);
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
        auto end_it = begin_it + w;

        std::sort(begin_it, end_it, [](const glm::vec3 &a, const glm::vec3 &b)
                  { return a.r > b.r; });
    }

    sorted_img.save("output/sortedpixels.png");
}

int main()
{
    sil::Image test{"images/logo.png"};
    circle(test, 100, 100, 20);

    int choix;

    std::cout << "\n=== CHOISIR UNE IMAGE ===\n"
              << "1. Logo IMAC\n"
              << "2. Photo Mr Cherrier\n"
              << "3. Photo faible contraste\n"
              << "4. Fond noir\n";
    std::cin >> choix;

    sil::Image image{500, 500}; // Initialisation par défaut

    switch (choix)
    {
    case 1:
        image = sil::Image{"images/logo.png"};
        break;
    case 2:
        image = sil::Image{"images/photo.jpg"};
        break;
    case 3:
        image = sil::Image{"images/photo_faible_contraste.jpg"};
        break;
    case 4:
        image = sil::Image{500, 500};
        break;
    default:
        image = sil::Image{500, 500};
        break;
    }

    int choix_effet;

    std::cout << "\n=== CHOISIR UN EFFET ===\n"
              << " 1. Only green (onlygreen.png)\n"
              << " 2. Noir et blanc (blackandwhite.png)\n"
              << " 3. Negatif (negative.png)\n"
              << " 4. Degrade (degrade.png)\n"
              << " 5. Miroir (miror.png)\n"
              << " 6. Bruit (noise.png)\n"
              << " 7. Rotation 90 (rotate90.png)\n"
              << " 8. RGB Split (rgbsplit.png)\n"
              << " 9. Luminosite (lum.png)\n"
              << "10. Disque (disk.png)\n"
              << "11. Cercle (circle.png)\n"
              << "12. Rosace (rosace.png)\n"
              << "13. Retrecir image / smallimg (smallimg.png)\n"
              << "14. Mosaique / mosaic (mosaic.png)\n"
              << "15. Glitch (glitch.png)\n"
              << "16. Tri des pixels / sortpixels (sortedpixels.png)\n";
    std::cin >> choix_effet;

    switch (choix_effet)
    {
    case 1:
        onlygreen(image);
        std::cout << "Image sauvegardee dans output/onlygreen.png\n";
        break;
    case 2:
        blackandwhite(image);
        std::cout << "Image sauvegardee dans output/blackandwhite.png\n";
        break;
    case 3:
        negative(image);
        std::cout << "Image sauvegardee dans output/negative.png\n";
        break;
    case 4:
        degrade(image);
        std::cout << "Image sauvegardee dans output/degrade.png\n";
        break;
    case 5:
        miror(image);
        std::cout << "Image sauvegardee dans output/miror.png\n";
        break;
    case 6:
        noise(image);
        std::cout << "Image sauvegardee dans output/noise.png\n";
        break;
    case 7:
        rotate90(image);
        std::cout << "Image sauvegardee dans output/rotate90.png\n";
        break;
    case 8:
        rgbsplit(image);
        std::cout << "Image sauvegardee dans output/rgbsplit.png\n";
        break;
    case 9:
        float lum_value;
        std::cout << "Choisir une valeur de luminosite entre 0.1(plus clair) et 9(plus sombre) :\n";
        std::cin >> lum_value;
        lum(image, lum_value);
        std::cout << "Image sauvegardee dans output/lum.png\n";
        break;
    case 10:
        disk(image);
        std::cout << "Image sauvegardee dans output/disk.png\n";
        break;
    case 11:
    {
        int thickness;
        std::cout << "Choisir une épaisseur de trait :";
        std::cin >> thickness;
        int cx = image.width() / 2;
        int cy = image.height() / 2;
        circle(image, cx, cy, thickness);
        image.save("output/circle.png");
        std::cout << "Image sauvegardee dans output/circle.png !\n";
        break;
    }
    case 12:
        rosace(image);
        std::cout << "Image sauvegardee dans output/rosace.png\n";
        break;
    case 13:
    {
        int div_size;
        std::cout << "Choisir un facteur de division entier (entre 1 et 10) :";
        std::cin >> div_size;
        smallimg(image, div_size);
        break;
    }
     case 14:
     {
         int size;
         std::cout<<"Choisir la taille de la mosaique :\n";
         std::cin>>size;
         mosaic(image, size);
         break;
     }
     case 15:
     {
         int gain;
         std::cout<<"Choisir le gain (entre 0 et 100) :\n";
         std::cin>>gain;
         glitch(image, gain);
         break;
     }
     case 16:
         sortpixels(image);
         std::cout << "Image sauvegardee dans output/sortedpixels.png\n";
         break;
     case 0:
         std::cout << "Fermeture du programme.\n";
         break;
    default:
        std::cout << "Option invalide, choisissez entre 0 et 15.\n";
        break;
    }
}