#pragma once

#include <memory>
#include <list>
#include "game/entity/actor/actor.hpp"

namespace rebubox{

namespace entity{

class actors_manager{
public:
    using actor_pointer_t = std::unique_ptr<actor>;
    using actors_container_t = std::list<actor_pointer_t>;
public:
    actors_manager &add_actor(actor *);

    void update_all();
    void draw_all();
private:
    actors_container_t actors;
};



}
}