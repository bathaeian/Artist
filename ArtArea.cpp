#include "ArtArea.h"
#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>
#include <iostream>

ArtArea::ArtArea()
{
    m_image = Gdk::Pixbuf::create_from_file("art.png");
   // Show at least a quarter of the image.
  if (m_image)
  {
    set_content_width(m_image->get_width()/2);
    set_content_height(m_image->get_height()/2);
  }

  // Set the draw function.
  set_draw_func(sigc::mem_fun(*this, &MyArea::on_draw));
  add_events(Gdk::BUTTON_PRESS_MASK);
    //startvalues
    firstclick=false;
    secondclick=false;
}

void ArtArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
  if (!m_image)
    return;


  // Draw the image in the middle of the drawing area, or (if the image is
  // larger than the drawing area) draw the middle part of the image.
  if(ncolor>3){
    Gdk::Cairo::set_source_pixbuf(cr, m_image,
        (width - m_image->get_width())/2, (height - m_image->get_height())/2);
      cr->paint();
  }

  else if(firstclick&&secondclick)
    {
        //set the width of the line
        cr->set_line_width(2);
        //set the color: black
        cr->set_source_rgb(0,0,0);
        //move the "brush" to the first point
        cr->move_to(x1,y1);
        //draw the line to the second point
        cr->line_to(x2,y2);
        //draw the line
        cr->stroke();
        firstclick=false;
        secondclick=false;
    }

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
}