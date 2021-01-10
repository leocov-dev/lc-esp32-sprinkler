#ifndef LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_UTIL_STRING_UTILS_HPP_
#define LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_UTIL_STRING_UTILS_HPP_

#include <string>
#include <vector>

class StringUtils {
 public:
  static std::vector<std::string> split(const std::string &input, char delim);
};

#endif//LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_UTIL_STRING_UTILS_HPP_
