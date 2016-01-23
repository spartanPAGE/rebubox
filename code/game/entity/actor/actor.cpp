#include "actor.hpp"

namespace rebubox{

actor::actor(focused_draw_target_t fdtarget, const math::point2d &pos):
    draw_target(fdtarget),
    position(pos)
{}

actor::~actor(){}

math::point2d &actor::get_position(){
    return position;
}

const math::point2d &actor::get_position() const{
    return position;
}

void actor::set_position(const math::point2d &pos){
    position = pos;
}

void actor::update(){}

void actor::draw(){}

focused_draw_target_t actor::get_draw_target(){
    return draw_target;
}

draw_target_view_t actor::get_draw_target() const{
    return draw_target;
}

}