#ifndef ARTAREA_H
#define ARTAREA_H

#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>

class ArtArea : public Gtk::DrawingArea
{
public:
  ArtArea();
  virtual ~ArtArea();

protected:
  void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);

  Glib::RefPtr<Gdk::Pixbuf> m_image;
};

#endif 
