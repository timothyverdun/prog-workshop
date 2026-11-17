#include <sil/sil.hpp>

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
int main()
{
    sil::Image image{"images/logo.png"};
    blackandwhite(image);
}