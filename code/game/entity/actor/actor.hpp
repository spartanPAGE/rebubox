#pragma once

#include "math/2d/point.hpp"

#include "actor-representation.hpp"

#include "game/draw-target/target.hpp"
namespace rebubox{

class actor{
public:
    using representation_block_t = actor_representation_block_t;
    using representation_t = actor_representation_t;
public:
    actor(focused_draw_target_t, const math::point2d &position);
    virtual ~actor();

    virtual math::point2d &get_position();
    virtual const math::point2d &get_position() const;

    virtual void set_position(const math::point2d &);

    virtual void update() abstract;
    virtual void draw() abstract;

    focused_draw_target_t get_draw_target();
    draw_target_view_t get_draw_target() const;
protected:
    focused_draw_target_t draw_target;
    math::point2d position;
};

}