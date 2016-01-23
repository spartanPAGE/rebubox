#include "console/canvas/console-canvas.hpp"
#include "console/canvas/console-drawer.hpp"

using console::graphics::color;
int main(){
    console_canvas canvas(119, 29);
    console_drawer canvas_drawer(canvas);
    canvas.fill({ ' ', color::white, console::graphics::color::cyan });
    canvas_drawer.draw();
    console::set_color(color::white, color::black);
}