
#include "Brush.cpp"
#include "Color.cpp"
#include <vector>
#include<iostream>
#include "ArtArea.cpp"

class ArtistW: public Gtk::Window{
    private:
      Gtk::Box t_Box,m_Box;
      ArtArea artArea;
      Gtk::Frame d_frame;
      Gtk::ToggleButton tb[10];
      void on_button_clicked();
    public:
        ArtistW(std::vector<Tools *>);
};

ArtistW::ArtistW(std::vector<Tools *> v):
t_Box(Gtk::ORIENTATION_VERTICAL, 5)
, m_Box(Gtk::ORIENTATION_HORIZONTAL, 5)
{
  set_title("Wellcome Artist!");
  set_default_size(600,400);
  set_border_width(5);
  add(m_Box);m_Box.add(t_Box);m_Box.add(d_frame);
  d_frame.set_label("Artist Area");
  artArea.set_size_request(300,300);
  d_frame.add(artArea);
      std::cout<<v.size()<<"\n";
  for(int i=0;i<v.size();i++){
    std::cout<<i<<":"<<v[i]->getProperty()<<"\n";
    tb[i].set_label(v[i]->getProperty());
    tb[i].signal_clicked().connect( sigc::mem_fun(*this,
              &ArtistW::on_button_clicked) );
    t_Box.add(tb[i]);
  }
   
  show_all();
}
void ArtistW::on_button_clicked(){
  artArea.incColor();
}
