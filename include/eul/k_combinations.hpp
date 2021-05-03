#ifndef K_COMBINATIONS
#define K_COMBINATIONS

#include <concepts>
#include <utility> // std::index_sequence, std::move
#include <range/v3/view/cartesian_product.hpp>
#include <range/v3/view/iota.hpp> // views::ints
#include <range/v3/view/transform.hpp>
#include <tuple> // std::apply

namespace eul{

template<std::size_t K>
[[nodiscard]] constexpr
auto k_combinations(int from, int to, std::relation<int, int> auto bin_op) noexcept
{
  namespace rv = ranges::views;

  auto const k_cartesian =
  [from, to]<std::size_t ...Is>(std::index_sequence<Is...>)
  {
    return rv::cartesian_product((void(Is), rv::ints(from, to))...);
  };
  
  auto const fold_tuple = [bin_op](auto common_tuple)
  { return std::apply(bin_op, std::move(common_tuple)); };
  
  return k_cartesian(std::make_index_sequence<K>())
       | rv::transform(fold_tuple);
}

} // namespace eul

#endif // !K_COMBINATIONS