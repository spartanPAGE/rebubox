#include "actor.hpp"

namespace rebubox{

namespace entity{

actor::actor(focused_draw_target_t fdtarget, point pos):
    draw_target(fdtarget),
    position(pos),
    representation(0, 0){}

actor::~actor(){}

actor::point actor::get_position() const{
    return position;
}

void actor::set_position(point pos){
    position = pos;
}

void actor::update(){}

void actor::draw(){
    math::point2d translated_pos = {
        position.x+translation.x, 
        position.y+translation.y
    };

    for(size_t y = 0; y < representation.height(); ++y){
        for(size_t x = 0; x < representation.width(); ++x){
            auto finalx = translated_pos.x + x;
            auto finaly = translated_pos.y + y;

            if(finalx >= 0 && finaly >= 0 && finalx < draw_target.width() && finaly < draw_target.height()){
                draw_target.draw_at(translated_pos.x + x, translated_pos.y + y, representation[x][y]);
            }
        }
    }
}

focused_draw_target_t actor::get_draw_target(){
    return draw_target;
}

draw_target_view_t actor::get_draw_target() const{
    return draw_target;
}

}

}