#ifndef SATIREV_SINGLETON_H
#define SATIREV_SINGLETON_H

#include "utils.h"
#include "get_instance_selector.h"
#include <cassert>
#include <memory>
#include <utility>

namespace satirev
{
	
  template <typename T>
  class singleton : public T
  {

    struct secret {};

  public:
	
    template <typename... Args>
    static void init(Args&&... args)
    {	
      std::call_once(once,
        std::apply(
          [](auto&&... args)
          { 
            instance = std::unique_ptr<T>{std::make_unique<singleton<T>>
              (secret{}, std::forward<decltype(args)>(args)...)};
          }, std::forward<decltype(args)>(args)...
        )
      );
    } 

    static T& get_instance()
    {
      return get_instance_selector<
          std::is_default_or_protected_constructible<T>::value
        >::template get_instance<T>();
    }

    singleton(const singleton&) = delete;

    singleton& operator=(const singleton&) = delete;  
  
    template <typename... Args>
    singleton(const secret&, Args&&... args)
      : T(std::forward<Args>(args)...) {}

  private:

    friend struct get_instance_selector<false>;
    friend struct get_instance_selector<true>;

    static std::once_flag once;
    static std::unique_ptr<T> instance;    
  };

  template <typename T>
  std::once_flag singleton<T>::once;

  template <typename T>
  std::unique_ptr<T> singleton<T>::instance = nullptr;

}

#endif /* SATIREV_SINGLETON_H */
