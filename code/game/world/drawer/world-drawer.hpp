#pragma once

#include "game/draw-target/target.hpp"
#include "game/world/world.hpp"

namespace rebubox{

class world_drawer{
public:
    using world_view_t = const world &;
public:
    world_drawer(focused_draw_target_t, world_view_t);
    void draw();
private:
    focused_draw_target_t draw_target;
    world_view_t world_view;
};

}