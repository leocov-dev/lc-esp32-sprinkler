#include "widgets/string-utils.hpp"

#include <sstream>

std::vector<std::string> StringUtils::Split(const std::string& input, char delim) {
  std::vector<std::string> result;
  std::stringstream ss(input);
  std::string item;

  while (getline(ss, item, delim)) {
    result.push_back(item);
  }

  return result;
}
