#include "console/console.hpp"
#include "console/canvas/console-drawer.hpp"

#include "game/main-loop/main-loop.hpp"

#include "game/entity/player/player.hpp"
#include "game/entity/actor/manager/actors-manager.hpp"

#include "console/ui/core.hpp"
#include "console/ui/label/label.hpp"

#include "game/canvas/console-canvas-singleton.hpp"

#include <string>
#include <chrono>
using namespace std;

using console::graphics::color;
using rebubox::main_loop::frame_t;


#include "lua/lua-core.hpp"

int main(int argc, char *argv[]){
    console::set_cursor_visibility(false);

    rebubox::canvas_singleton::init(85, 20);
    auto &canvas = rebubox::canvas_singleton::get_instance();
    console_drawer canvas_drawer(canvas);

    console::ui::core ui_core;
    ui_core.add_element("frames_counter", new console::ui::label(canvas, "", { 60, 0 }, 25, color::cyan, color::dark_yellow));

    rebubox::lua_core lua_core;
    lua_core.init();
    lua_core.load_file("rebubox/scripts/main.lua");
    lua_core.run(0, 0, 0);

    auto consume_keys = []{
        while(console::key_pressed())
            console::get_key();
    };

    auto update = [&](frame_t){
        console::input_buffer::collect();

        lua_core.pick_global("update");
        lua_core.run(0, 0, 0);

        ui_core.update();

        console::input_buffer::clear();
    };

    auto draw = [&](frame_t frame){
        lua_core.pick_global("draw");
        lua_core.run(0, 0, 0);

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
        return false;
    };

    rebubox::start_main_loop(update, draw, end_game);

    console::set_cursor_visibility(true);
    console::set_color(color::white, color::black);

    lua_core.finish();
}