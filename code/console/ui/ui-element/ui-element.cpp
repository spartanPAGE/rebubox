#include "ui-element.hpp"

namespace console{
namespace ui{

ui_element::ui_element(
    target_t &target,
    math::point2d position,
    size_t w, size_t h,
    graphics::color fgcol,
    graphics::color bgcol
): drawable(target){
    set_position(position);
    set_width(w);
    set_height(h);
    set_colors(fgcol, bgcol);
}

void ui_element::update(){}

math::point2d ui_element::get_position() const{
    return pos;
}

void ui_element::set_position(math::point2d newpos){
    pos = newpos;
}

size_t ui_element::get_width() const{
    return width;
}

void ui_element::set_width(size_t w){
    width = w;
}

size_t ui_element::get_height() const{
    return height;
}

void ui_element::set_height(size_t h){
    height = h;
}

graphics::color ui_element::get_foreground_color() const{
    return foreground;
}

graphics::color ui_element::get_background_color() const{
    return background;
}

void ui_element::set_colors(graphics::color fg, graphics::color bg){
    foreground = fg;
    background = bg;
}

}
}