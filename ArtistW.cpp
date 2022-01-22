#include <gtkmm.h>
#include "Brush.cpp"
#include "Color.cpp"
#include <vector>

class ArtistW: public Gtk::Window{
    private:
      Gtk::Box t_Box,w_Box;
      Gtk::ToggleButton tb[10];
      void on_button_clicked();
    public:
        ArtistW(std::vector<Tools *>);
};

ArtistW::ArtistW(std::vector<Tools *> v)
{
  set_title("Wellcome Artist!");
  set_default_size(600,400);
  set_border_width(5);
  add(t_Box);
  add(w_Box);
  for(int i=0;i<v.size();i++){
    tb[i].add_label(v[i]->getProperty());
    t_Box.add(tb[i]);
    tb[i].signal_clicked().connect( sigc::mem_fun(*this,
              &ArtistW::on_button_clicked) );
  }
  show_all();
}
void ArtistW::on_button_clicked(){

}