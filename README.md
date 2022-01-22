# Artist
a small example for learning gtkmm
what you need: mingw + gtkmm
compile:
g++ -std=c++11 Artist.cpp $(pkg-config gtkmm-3.0 --cflags --libs | sed 's/ -I/ -isystem /g')
run
./a
