#pragma once

#include "math/2d/matrix.hpp"

namespace math{

template<typename T>
class buffered_canvas{
public:
    using canvas_t = matrix2d<T>;
    using difference_data_t = struct{ size_t x, y; T val; };
    using difference_container_t = std::vector<difference_data_t>;
public:
    buffered_canvas(
        size_t width,
        size_t height
        ): canvas(width, height), buffer(canvas){}
    buffered_canvas(
        size_t width,
        size_t height,
        T init
        ): canvas(width, height), buffer(0, 0){
        std::fill(std::begin(canvas), std::end(canvas), init);
        buffer = canvas;
    }
public:
    size_t width() const{
        return canvas.width();
    }
    size_t height() const{
        return canvas.height();
    }
    void draw_at(size_t x, size_t y, T val){
        buffer[x][y] = val;
    }
    void fill(T val){
        std::fill(begin(buffer), end(buffer), val);
    }
    const canvas_t &get_buffer() const{
        return buffer;
    }
    void update(){
        std::copy(std::begin(buffer), std::end(buffer), std::begin(canvas));
    }
    difference_container_t diff() const{
        difference_container_t cont;
        for(size_t y = 0; y < canvas.height(); ++y){
            for(size_t x = 0; x < canvas.width(); ++x){
                if(canvas[x][y] != buffer[x][y])
                    cont.push_back({ x, y, buffer[x][y] });
            }
        }
        return cont;
    }
private:
    canvas_t canvas, buffer;
};

}