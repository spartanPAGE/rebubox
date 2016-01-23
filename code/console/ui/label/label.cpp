#include "label.hpp"

namespace console{
namespace ui{

label::label(
    target_t &target,
    const std::string &str,
    math::point2d pos,
    size_t w,
    graphics::color fg,
    graphics::color bg
): ui_element(target, pos, w, 1, fg, bg), text(str){}

void label::update(){}

void label::draw(){
    for(size_t i = 0; i < get_width(); ++i){
        auto pos = get_position();
        access_target().draw_at(pos.x + i, pos.y, {
            (i<text.size()? text[i] : ' '),
            get_foreground_color(),
            get_background_color()
        });
    }
}

void label::set_height(size_t h){
    /* ignore */
}

std::string label::get_text() const{
    return text;
}

void label::set_text(const std::string &str){
    text = str;
}


}
}