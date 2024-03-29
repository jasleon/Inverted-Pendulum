#ifndef TOOLS_H_
#define TOOLS_H_

#include <string>
#include <vector>

/**
 * Exports simulation data to a comma-delimited file
 * @param filename File name
 * @param columns Name of the columns in the data matrix
 * @param data 2D matrix with values from the simulation
 */ 
void Export(std::string filename, std::vector<std::string> columns,
            std::vector<std::vector<double>> &data);

/**
 * Converts degrees to radians
 * @param degrees
 */
double to_radians(double degrees);

/**
 * Converts radians to degrees
 * @param radians
 */
double to_degrees(double radians);

#endif  // TOOLS_H_
