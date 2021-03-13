#ifndef LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_STRING_UTILS_HPP_
#define LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_STRING_UTILS_HPP_

#include <string>
#include <vector>

class StringUtils {
 public:
  static std::vector<std::string> Split(const std::string &input, char delim);
};

#endif  // LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_STRING_UTILS_HPP_
