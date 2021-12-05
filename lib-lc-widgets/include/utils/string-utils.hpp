#ifndef LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_STRING_UTILS_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_STRING_UTILS_HPP_

#include <string>
#include <vector>

class StringUtils {
 public:
  static std::vector<std::string> Split(const std::string &input, char delim);
};

#endif  // LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_STRING_UTILS_HPP_
