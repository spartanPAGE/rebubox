#include "actors-manager.hpp"

namespace rebubox{

namespace entity{

actors_manager &actors_manager::add_actor(actor *act){
    actors.push_back(actor_pointer_t(act));
    return *this;
}

void actors_manager::update_all(){
    for(auto &actor_entity: actors){
        actor_entity->update();
    }
}

void actors_manager::draw_all(){
    for(auto &actor_entity: actors){
        actor_entity->draw();
    }
}

}

}