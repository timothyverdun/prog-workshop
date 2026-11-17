#include <sil/sil.hpp>

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
void blackandwhite(sil::Image &image){
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
void negative(sil::Image &image){
    for (glm::vec3 &color : image.pixels())
    {
        color.r = 1-color.r;
        color.g = 1-color.g;
        color.b = 1-color.b;
    }
    image.save("output/negative.png");
}
int main()
{
    sil::Image image{"images/logo.png"};
    negative(image);
}