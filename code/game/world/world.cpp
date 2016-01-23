#include "world.hpp"

namespace rebubox{

world::world(size_t w, size_t h):
    width(w), 
    height(h), 
    blocks(w, h)
{}

world::blocks_t &world::get_blocks(){
    return blocks;
}

const world::blocks_t &world::get_blocks() const{
    return blocks;
}

}