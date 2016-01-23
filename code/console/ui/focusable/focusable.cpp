#include "focusable.hpp"

namespace console{
namespace ui{

focusable::focusable(bool state){
    set_focus_state(state);
}

void focusable::focus(){
    set_focus_state(true);
}

void focusable::unfocus(){
    set_focus_state(false);
}

bool focusable::focused() const{
    return focus_state;
}

void focusable::set_focus_state(bool state){
    focus_state = state;
}

}
}