#pragma once

#include "console/graphics-utils/graphics-utils.hpp"
#include "console/ui/ui-element/ui-element.hpp"

#include <string>

namespace console{
namespace ui{

class label: public ui_element{
public:
    label(
        target_t &target,
        const std::string &str,
        math::point2d pos,
        size_t w,
        graphics::color fg = graphics::color::white,
        graphics::color bg = graphics::color::black);

    virtual void update() override;
    virtual void draw() override;
    virtual void set_height(size_t h) override;
    virtual std::string get_text() const;
    virtual void set_text(const std::string &);
private:
    std::string text;
};

}
}