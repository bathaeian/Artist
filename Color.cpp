
#include "Tools.cpp"

class Color: public Tools
{
private:
    enum colors { RED = 1, BLUE, WHITE, GREEN, BLACK, YELLOW};
    colors col;
public:
    Color(colors);
    std::string getProperty();
};

Color::Color(colors c=RED)
{
    col=c;
}

std::string Color::getProperty(){
    return "color "+col;
}