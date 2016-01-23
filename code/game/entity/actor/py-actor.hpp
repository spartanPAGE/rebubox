#pragma once

#include <boost/python.hpp>

#include "actor.hpp"

BOOST_PYTHON_MODULE(rebubox_actor){
    using namespace boost::python;
    using namespace rebubox::entity;

    class_<actor::point>("actor_point", init<actor::point>())
        .def_readwrite("x", &actor::point::x)
        .def_readwrite("y", &actor::point::y)
        .add_property("str", &actor::point::str);

    struct actor_wrap: actor, wrapper<actor>{
        actor_wrap(rebubox::focused_draw_target_t fdt, actor::point point):
            actor(fdt, point){}
       
        virtual void update() override{
            this->get_override("update")();
        }
    };

    class_<actor_wrap, boost::noncopyable>("actor", init<actor_wrap>())
        .add_property("position", &actor_wrap::get_position, &actor_wrap::set_position)
        .def("draw", &actor_wrap::draw)
        .def("update", pure_virtual(&actor::update));
}