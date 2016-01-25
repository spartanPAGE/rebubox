#ifndef SATIREV_GET_INSTANCE_SELECTOR_H
#define SATIREV_GET_INSTANCE_SELECTOR_H

#include "utils.h"
#include <cassert>
#include <mutex>
#include <memory>

namespace satirev
{

  template <typename T>
  class singleton;

  template <bool = false>
  struct get_instance_selector
  {
    template <typename T>
    static T& get_instance()
    {
      assert(singleton<T>::instance && "Instance does not exist!");
      return *singleton<T>::instance.get();
    }
  };

  template <>
  struct get_instance_selector<true>
  {
    template <typename T>
    static T& get_instance()
    {
      std::call_once(singleton<T>::once,
        [&]()
        { 
          singleton<T>::instance = 
            std::unique_ptr<T>{
              std::make_unique<singleton<T>>(typename singleton<T>::secret{})
            };
        }
      );
      return *singleton<T>::instance.get();
    }
  };

}

#endif /* SATIREV_GET_INSTANCE_SELECTOR_H */
