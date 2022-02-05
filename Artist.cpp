#include <vector>
#include <stdexcept>
#include "ArtistW.cpp"
using namespace std;

int main(int argc, char** argv)
{
        vector<Tools*> tt;
        Brush *b;
        Color *c;
        for(int i=1;i<=5;i++){
                b=new Brush(i);
                cout<<"in main"<<b->getProperty()<<"\n";
                tt.push_back(b);
        }
        for(int i=1;i<=4;i++){
                c=new Color(static_cast<Color::colors>(i));
                cout<<"in main"<<c->getProperty()<<"\n";
                tt.push_back(c);
        }
        auto app = Gtk::Application::create(argc, argv);
        
        ArtistW window=ArtistW(tt);
        
        return app->run(window);
}