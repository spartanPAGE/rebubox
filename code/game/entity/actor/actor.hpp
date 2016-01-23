#pragma once

#include "math/2d/point.hpp"

#include "actor-representation.hpp"

#include "game/draw-target/target.hpp"
namespace rebubox{

namespace entity{

class actor{
public:
    using representation_block_t = actor_representation_block_t;
    using representation_t = actor_representation_t;
    using point = math::point2d;
public:
    actor(focused_draw_target_t, point position);
    virtual ~actor();

    point get_position() const;
    void set_position(point);

    virtual void update() abstract;
    virtual void draw();

    focused_draw_target_t get_draw_target();
    draw_target_view_t get_draw_target() const;
protected:
    focused_draw_target_t draw_target;
    point position, translation = {0, 0};
    representation_t representation;
};

}

}