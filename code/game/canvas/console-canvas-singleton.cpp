#include "console-canvas-singleton.hpp"

using console::graphics::color;

namespace rebubox{

void draw_at_canvas_xy(int x, int y, char c, int fcol, int bgcol){
    canvas_singleton::get_instance().draw_at(x, y, { c, color(fcol), color(bgcol) });
}

}