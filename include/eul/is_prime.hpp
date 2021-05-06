#ifndef IS_PRIME
#define IS_PRIME

#include <cmath>

namespace eul{

constexpr auto oddly_factorable(int const n_to_factor) -> bool
{
  for(int divider{ 3 }; divider <= std::sqrt(n_to_factor); divider += 2)
  {
    if(n_to_factor % divider == 0)
      return true;
  }

  return false;
}

constexpr auto is_prime(int const i) -> bool
{
  if(i == 1 or i == 2) return true;
  if(i % 2 == 0) return false;

  return not oddly_factorable(i);
}

}

#endif // !IS_PRIME