#include <gtkmm.h>
#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>
#include <iostream>
#include <gdkmm/pixbuf.h>
#include <glibmm/main.h>

class ArtArea : public Gtk::DrawingArea
{
public:
  ArtArea();
  void incColor();
  void setColors(int , int ,int);
protected:
  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);//, int width, int height);
  bool on_button_press_event(GdkEventButton *);
  Glib::RefPtr<Gdk::Pixbuf> m_image;
  private:
     int ncolor;
     int x1,y1,x2,y2;
     bool firstclick,secondclick;
     int red,green,blue;
};

ArtArea::ArtArea()
{
    m_image = Gdk::Pixbuf::create_from_file("art.png");
    add_events(Gdk::BUTTON_PRESS_MASK);
    ncolor=0;
    firstclick=false;
    secondclick=false;
    red=green=blue=0;
}

bool ArtArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  if (!m_image)
    return false;
  if(ncolor>3){
    Gdk::Cairo::set_source_pixbuf(cr, m_image);
    cr->paint();
  }
  else if(firstclick&&secondclick)
    {
        //set the width of the line
        cr->set_line_width(2);
        //set the color: black
        cr->set_source_rgb(red,green,blue);
        //move the "brush" to the first point
        cr->move_to(x1,y1);
        //draw the line to the second point
        cr->line_to(x2,y2);
        //draw the line
        cr->stroke();
        firstclick=false;
        secondclick=false;
    }
  return true;
}
void ArtArea::incColor(){ncolor++;}
bool ArtArea::on_button_press_event(GdkEventButton *event)
{
    // Check if the event is a left(1) button click.
    if( (event->type == GDK_BUTTON_PRESS) && (event->button == 1) )
    {
        //check whether this is the first click
        if(!firstclick&&!secondclick)
        {
            //the first coordinate
            x1=event->x;
            y1=event->y;
            firstclick=true;
        }
        //check whether this is the second click, and not on the same point as the previous
        if(firstclick&&!secondclick&&(int)event->x!=x1&&(int)event->y!=y1)
        {
            //the second coordinate
            x2=event->x;
            y2=event->y;
            secondclick=true;
            //refresh the screen
            queue_draw();
        }
        // The event has been handled.
        return true;
    }
    return false;
}
void ArtArea::setColors(int r,int g , int b){
  red=r;green=g;blue=b;
}