#include "core.hpp"

namespace console{
namespace ui{

core &core::add_element(const element_tag_t &tag, ui_element *el){
    elements_map[tag] = element_t(el);
    return *this;
}

core::access_proxy_t core::access_element_by_tag(const element_tag_t &tag){
    auto &el = *elements_map.at(tag);
    return access_proxy_t{ el };
}

void core::update(){
    for(auto &tag_el_pair: elements_map){
        tag_el_pair.second->update();
    }
}

void core::draw(){
    for(auto &tag_el_pair : elements_map){
        tag_el_pair.second->draw();
    }
}

}
}