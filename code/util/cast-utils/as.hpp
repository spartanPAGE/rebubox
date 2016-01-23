#pragma once

template<typename Tel>
struct as_proxy{
    Tel &element;
    template<typename Tcast>
    Tcast &as(){
        return reinterpret_cast<Tcast&>(element);
    }
};