#pragma once

#include "console/ui/ui-element/ui-element.hpp"
#include "util/cast-utils/as.hpp"

#include <memory>
#include <string>
#include <unordered_map>

namespace console{
namespace ui{

class core{
public:
    using element_t = std::unique_ptr<ui_element>;
    using element_tag_t = std::string;
    using elements_map_t = std::unordered_map<element_tag_t, element_t>;
    using access_proxy_t = as_proxy<ui_element>;
public:
    core &add_element(const element_tag_t &tag, ui_element *el);
    access_proxy_t access_element_by_tag(const element_tag_t &tag);
    
    void update();
    void draw();
private:
    elements_map_t elements_map;
};

}
}