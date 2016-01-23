#include "world-drawer.hpp"

#include "game/world/block/representation.hpp"

namespace rebubox{

world_drawer::world_drawer(focused_draw_target_t fdtarget, world_view_t worldw):
    draw_target(fdtarget),
    world_view(worldw)
{}

void world_drawer::draw(){
    auto &blocks = world_view.get_blocks();

    for(size_t y = 0; y < blocks.height(); ++y){
        for(size_t x = 0; x < blocks.width(); ++x){
            auto &repr = block_representations[(size_t) blocks[x][y]];
            draw_target.draw_at(x, y, repr);
        }
    }
}

}