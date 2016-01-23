#include "inputbox.hpp"

#include <ctype.h>

#include <algorithm>

namespace console{
namespace ui{

inputbox::inputbox(
    target_t &target, 
    math::point2d pos, 
    size_t w, 
    bool focus_state,
    graphics::color fg,
    graphics::color bg
): ui_element(target, pos, w, /*height*/1, fg, bg), focusable(focus_state){
    set_width(w);
}

void inputbox::set_on_enter_action(on_enter_action ea){
    enter_action = ea;
}

void inputbox::update(){
    ui_element::update();
    if(!focused()) return;

    if(console::key_pressed()){
        auto key = console::get_key();

        if(chars_num > 0 && key == '\b'){
            text[--chars_num] = ' ';
        } 
        else if(chars_num < get_width()){
            if(key == '\r'){
                enter_action(text);
            }
            else if(isalnum(key) || key == ' '){
                text[chars_num++] = key;
            }
            else{
                console::unget_key(key);
            }
        }
    }
}

void inputbox::draw(){
    size_t width = get_width();
    auto position = get_position();
    for(size_t i = 0; i < width; ++i){
        auto c = i < text.size()? text[i] : ' ';
        access_target().draw_at(position.x + i, position.y, {
            c,
            get_foreground_color(),
            get_background_color()
        });
    }
}

void inputbox::set_height(size_t h){
    /* ignore height changing */
}

void inputbox::set_width(size_t w){
    ui_element::set_width(w);

    text.resize(w, ' ');
    chars_num = std::min(chars_num, text.size());
}

std::string inputbox::get_text() const{
    return text;
}

void inputbox::set_text(const std::string &str){
    chars_num = str.size();
    auto end = std::min(get_width(), chars_num);
    
    for(size_t i = 0; i < end; ++i){
        text[i] = str[i];
    }

    for(size_t i = end; i < get_width(); ++i){
        text[i] = ' ';
    }
}

}
}