#ifndef SATIREV_UTILS_H
#define SATIREV_UTILS_H

#include <type_traits>
#include <tuple>

namespace std
{

  template <typename T>
  struct is_default_or_protected_constructible
  {
    struct X : T {};
    static const auto value = std::is_default_constructible<X>::value;
  };
  
  /*
   * Implementation of function std::apply from proposal n3915
   * www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3915.pdf
   */
  
  template <typename>
  struct apply_impl;

  template <std::size_t... Index>
  struct apply_impl<std::index_sequence<Index...>>
  {
    template <typename F, typename... T>
    auto operator()(F&& f, std::tuple<T...>& t)
    {
      return std::forward<F>(f)(std::forward<T>(std::get<Index>(t))...);
    }
  };

  template <typename F, typename... T>
  auto apply(F&& f, std::tuple<T...>& t)
  {
    return apply_impl<std::index_sequence_for<T...>>()(std::forward<F>(f), t);
  }

  template <typename F, typename... T>
  auto apply(F&& f, T&&... t)
  {
    return [f = std::forward<F>(f),
            t = std::forward_as_tuple<T...>(std::forward<T>(t)...)
           ]() mutable { return apply(std::forward<F>(f), t); };
  }

}

#endif /* SATIREV_UTILS_H */
