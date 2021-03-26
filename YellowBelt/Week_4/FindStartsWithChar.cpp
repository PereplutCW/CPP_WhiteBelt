#include <algorithm>
#include <utility>
#include <string>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end, char prefix) {
      
  auto left_bound = lower_bound(range_begin, range_end, string(1, prefix));
  
  char next_prefix = static_cast<char>(prefix + 1);
  
  auto right_bound = lower_bound(range_begin, range_end, string(1, next_prefix));
  
  return {left_bound, right_bound};
}