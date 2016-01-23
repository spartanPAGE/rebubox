#include "console-drawer.hpp"

#include "console/graphics-utils/graphics-utils.hpp"
#include <iostream>

console_drawer::console_drawer(observed_canvas_t observed): canvas(observed){}

void console_drawer::draw(){
    auto buffer = canvas.get_buffer();
    for(size_t y = 0; y < buffer.height(); ++y){
        for(size_t x = 0; x < buffer.width(); ++x){
            auto field = buffer[x][y];
            console::set_color(field.fcol, field.bgcol);
            std::cout.put(field.c);
        }
        std::cout.put('\n');
    }
    std::cout.flush();
}

void console_drawer::update_drawing(){
    const auto diff = canvas.diff();
    if(diff.empty()){
        return;
    }

    for(auto &element : diff){
        auto field = element.val;
        math::point2d pos = { static_cast<int>(element.x), static_cast<int>(element.y) };
        console::set_color(field.fcol, field.bgcol);
        console::write_char_at(pos, field.c);
    }

    std::cout.flush();
}