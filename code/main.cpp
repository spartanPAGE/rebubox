#include "console/canvas/console-canvas.hpp"
#include "console/canvas/console-drawer.hpp"

#include "game/world/world.hpp"
#include "game/world/drawer/world-drawer.hpp"

using console::graphics::color;
int main(){
    console_canvas canvas(119, 29);
    console_drawer canvas_drawer(canvas);

    rebubox::world world(60, 29);
    rebubox::world_drawer world_drawer(canvas, world);

    auto &blocks = world.get_blocks();

    for(size_t y = 0; y < blocks.height(); ++y){
        auto block_id = (rebubox::world_block_id)(y/10);
        for(size_t x = 0; x < blocks.width(); ++x){
            blocks[x][y] = block_id;
        }
    }

    world_drawer.draw();
    canvas_drawer.draw();
    console::set_color(color::white, color::black);
}