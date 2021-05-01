#include <fmt/core.h>
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/view/generate.hpp>
#include <range/v3/view/take_while.hpp>
#include <range/v3/view/filter.hpp>
#include <cstdint>
#include <concepts>

// https://projecteuler.net/problem=2

int main(){
    namespace rv = ranges::views;
    using rv::generate, rv::filter, rv::take_while, ranges::accumulate;
    using u32 = uint32_t;

    constexpr auto is_even = [](u32 n){ return n % 2 == 0; };

    auto fibonacci = [p = std::pair{1u, 2u}] () mutable -> u32
    { 
      return std::exchange(
               p, {p.second, p.first + p.second}
             ).first;
    };

    constexpr auto lt_upper_bound = [](u32 n){ return n < 4'000'000; };

    std::unsigned_integral auto result = accumulate(
                                         generate(fibonacci)
                                       | take_while(lt_upper_bound)
                                       | filter(is_even),
                                       u32{ 0 });
    
    fmt::print("{}\n", result);
}
