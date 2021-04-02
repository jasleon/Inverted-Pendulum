#include "tools.h"

#include <fstream>

void Save(std::string filename, const std::vector<double>& time,
          std::vector<double>& position, const std::vector<double>& angle) {
  if (position.size() == angle.size()) {
    std::ofstream output;
    output.open(filename);
    if (output.is_open()) {
      output << "time,position,angle\n";
      for (size_t i = 0; i < position.size(); ++i) {
        output << time[i] << "," << position[i] << "," << angle[i] << "\n";
      }
      output.close();
    }
  }
}