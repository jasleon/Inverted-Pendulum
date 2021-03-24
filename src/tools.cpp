#include "tools.h"

#include <fstream>

void foo(const std::vector<double>& values) {
  std::ofstream output;

  output.open("test.txt");

  if (output.is_open()) {
    for (const auto& v : values) {
      output << v << std::endl;
    }
    output.close();
  }
}