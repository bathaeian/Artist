#include "Tools.cpp"

class Brush: public Tools
{
private:
    int brush_size;
public:
    Brush(int );
    std::string getProperty();
};

Brush::Brush(int s=1)
{
    brush_size=s;
}
std::string Brush::getProperty(){
    std::string s("brush "+std::to_string(brush_size));
    return s;
}