#pragma once

#include "console/graphics-utils/graphics-utils.hpp"

#include "math/2d/point.hpp"

#include "console/ui/drawable/drawable.hpp"

namespace console{
namespace ui{

class ui_element:
    public drawable{
public:
    ui_element(
        target_t &target,
        math::point2d position, 
        size_t w, size_t h, 
        graphics::color fgcol = graphics::color::white,
        graphics::color bgcol = graphics::color::black);

    virtual void update() abstract;

    virtual math::point2d get_position() const;
    virtual void set_position(math::point2d);

    virtual size_t get_width() const;
    virtual void set_width(size_t w);
    
    virtual size_t get_height() const;
    virtual void set_height(size_t h);

    virtual graphics::color get_foreground_color() const;
    virtual graphics::color get_background_color() const;

    virtual void set_colors(graphics::color fg, graphics::color bg);
private:
    math::point2d pos;
    size_t width, height;
    graphics::color foreground, background;
};

}
}