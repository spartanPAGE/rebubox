#include "console/console.hpp"
#include "console/canvas/console-drawer.hpp"

#include "game/world/world.hpp"
#include "game/world/drawer/world-drawer.hpp"

#include "game/main-loop/main-loop.hpp"

#include "game/entity/player/player.hpp"
#include "game/entity/actor/manager/actors-manager.hpp"

#include "console/ui/core.hpp"
#include "console/ui/label/label.hpp"

#include <string>
#include <chrono>
using namespace std;

using console::graphics::color;
using rebubox::main_loop::frame_t;

int main(){
    console::set_cursor_visibility(false);

    console_canvas canvas(85, 15);
    console_drawer canvas_drawer(canvas);

    rebubox::world world(60, 15);
    rebubox::world_drawer world_drawer(canvas, world);

    console::ui::core ui_core;
    ui_core.add_element("frames_counter", new console::ui::label(canvas, "", { 60, 0 }, 25, color::cyan, color::dark_yellow));

    rebubox::entity::actors_manager actors;
    actors.add_actor(new rebubox::entity::player(canvas, { 2, 2 }));

    auto &blocks = world.get_blocks();

    for(size_t y = 0; y < blocks.height(); ++y){
        auto block_id = (rebubox::world_block_id)(y/10);
        for(size_t x = 0; x < blocks.width(); ++x){
            blocks[x][y] = block_id;
        }
    }

    auto consume_keys = []{
        while(console::key_pressed())
            console::get_key();
    };

    auto update = [&](frame_t){
        actors.update_all();

        ui_core.update();
        //consume_keys();
    };

    auto draw = [&](frame_t frame){
        world_drawer.draw();
        actors.draw_all();

        ui_core.access_element_by_tag("frames_counter").as<console::ui::label>()
            .set_text("frames counter: " + to_string(frame));
        ui_core.draw();

        if(frame == 1){
            canvas_drawer.draw();
        }
        else{
            canvas_drawer.update_drawing();
        }
    };

    auto end_game = [](frame_t){
        //todo: add console input buffer
        /*char esc = 27;
        if(console::key_pressed()){
            return console::get_key() == esc;
        }*/
        return false;
    };

    rebubox::start_main_loop(update, draw, end_game);

    console::set_cursor_visibility(true);
    console::set_color(color::white, color::black);
}