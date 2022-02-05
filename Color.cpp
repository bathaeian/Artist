
#include "Tools.cpp"

class Color: public Tools
{
public:
    enum colors { RED = 1,GREEN, BLUE, BLACK};
    Color(colors);
    std::string getProperty();
    private:
    colors col;
};

Color::Color(colors c=RED)
{
    col=c;
}

std::string Color::getProperty(){
    std::string s("");
    switch(col){
        case 1: {s=s+"red";break;}
        case 2: {s=s+"green";break;}
        case 3: {s=s+"blue";break;}
        case 4: {s=s+"black";break;}
    }
    return s;
}