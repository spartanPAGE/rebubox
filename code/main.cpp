#include "console/canvas/console-canvas.hpp"
#include "console/canvas/console-drawer.hpp"

#include "console/input-utils/input-utils.hpp"

#include "game/world/world.hpp"
#include "game/world/drawer/world-drawer.hpp"

#include "game/main-loop/main-loop.hpp"
using console::graphics::color;
using rebubox::main_loop::frame_t;

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

    auto update = [&](frame_t){};
    auto draw = [&](frame_t frame){
        world_drawer.draw();

        frame == 1
            ? canvas_drawer.draw()
            : canvas_drawer.update_drawing();
    };

    auto end_game = [](frame_t){
        char esc = 27;
        if(console::key_pressed()){
            return console::get_key() == esc;
        }
    };

    rebubox::start_main_loop(update, draw, end_game);

    console::set_color(color::white, color::black);
}