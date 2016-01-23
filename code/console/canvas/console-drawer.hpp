#pragma once

#include "console-canvas.hpp"

class console_drawer{
public:
    using observed_canvas_t = const console_canvas &;
public:
    console_drawer(observed_canvas_t observed);
public:
    void draw();
    void update_drawing();
private:
    observed_canvas_t canvas;
};