#pragma once

#include "game/entity/actor/actor.hpp"

namespace rebubox{

namespace entity{

class player: public actor{
public:
    player(focused_draw_target_t, const math::point2d &);

    virtual void update() override;
};

}

}