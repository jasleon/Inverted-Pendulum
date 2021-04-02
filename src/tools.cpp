#include "tools.h"

#include <fstream>

void Export(std::string filename, std::vector<std::string> columns,
            std::vector<std::vector<double>>& data) {
  std::ofstream output;
  output.open(filename);
  if (output.is_open()) {
    for (size_t i = 0; i < columns.size(); ++i) {
      output << columns[i];
      char sep = (columns.size() == i + 1) ? '\n' : ',';
      output << sep;
    }
    for (const auto& line : data) {
      for (size_t i = 0; i < line.size(); ++i) {
        output << line[i];
        char sep = (line.size() == i + 1) ? '\n' : ',';
        output << sep;
      }
    }
  }
}