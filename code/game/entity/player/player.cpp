#include "player.hpp"

#include "console/input-utils/input-utils.hpp"

#include <unordered_map>
#include <functional>
using namespace std;
using console::graphics::color;

namespace rebubox{

namespace entity{

player::player(focused_draw_target_t fdtarget, const math::point2d &pos):
    actor(fdtarget, pos)
{
    representation = representation_t(1, 1);
    representation[0][0] = representation_block_t{ char(1), color::white, color::black};
}

void player::update(){
    using actions_dict = unordered_map<console::key, function<void()>>;
    static actions_dict actions = {
        { 'w', [&]{ position.y -= 1; } },
        { 's', [&]{ position.y += 1; } },
        { 'a', [&]{ position.x -= 1; } },
        { 'd', [&]{ position.x += 1; } }
    };

    while(console::key_pressed()){
        

        console::key key = console::get_key();
        if(actions.count(key)){
            actions[key]();
        }
    }
}

}

}