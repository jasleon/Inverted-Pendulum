#ifndef TOOLS_H_
#define TOOLS_H_

#include <string>
#include <vector>

void Save(std::string filename, const std::vector<double> &time,
          std::vector<double> &position, const std::vector<double> &angle);

#endif  // TOOLS_H_
