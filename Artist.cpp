#include <vector>
#include <stdexcept>
#include "ArtistW.cpp"
using namespace std;

int main(int argc, char** argv)
{
        vector<Tools*> tt(10);
        Brush b;
        for(int i=1;i<=5;i++){
                b=Brush(i);
                tt.push_back(&b);
        }

        auto app = Gtk::Application::create(argc, argv);
        
        ArtistW window=ArtistW(tt);
        
        return app->run(window);
}