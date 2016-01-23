#pragma once

#include "console/graphics-utils/graphics-utils.hpp"
#include "console/input-utils/input-utils.hpp"

#include "console/ui/focusable/focusable.hpp"
#include "console/ui/ui-element/ui-element.hpp"

#include <string>
#include <functional>
namespace console{
namespace ui{

class inputbox: 
    public ui_element, 
    public focusable
{
public:
    using on_enter_action = std::function<void(std::string)>;
public:
    inputbox(
        target_t &target, 
        math::point2d pos, 
        size_t w, 
        bool focused_state = true,
        graphics::color fg = graphics::color::white,
        graphics::color bg = graphics::color::black);
    void set_on_enter_action(on_enter_action);
    virtual void update() override;
    virtual void draw() override;
    virtual void set_height(size_t h) override;
    virtual void set_width(size_t w) override;

    virtual std::string get_text() const;
    virtual void set_text(const std::string &);
private:
    on_enter_action enter_action;
private:
    std::string text;
    size_t chars_num = 0;
};

}
}