#ifndef TOOLS_H_
#define TOOLS_H_

#include <string>
#include <vector>

void Export(std::string filename, std::vector<std::string> columns,
            std::vector<std::vector<double>> &data);

#endif  // TOOLS_H_
