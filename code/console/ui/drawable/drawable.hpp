#pragma once

#include "console/canvas/console-canvas.hpp"

class drawable{
public:
    using target_t = console_canvas;
public:
    drawable(target_t &t);
    virtual void draw() abstract;
    target_t &access_target();
private:
    target_t &target;
};