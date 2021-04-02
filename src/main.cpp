#include <iostream>
#include <sciplot/sciplot.hpp>

#include "Eigen/Dense"
#include "inverted_pendulum.h"
#include "tools.h"

int main() {
  // Set initial conditions
  Eigen::VectorXd x_0(4);
  x_0 << 0, M_PI / 4, 0, 0;

  // Create a model with default parameters
  InvertedPendulum model(x_0);

  // Define simulation time
  sciplot::Vec time = sciplot::linspace(0.0, 20.0, 1000);

  // Store data from the simulation
  std::vector<std::vector<double>> data;
  std::vector<double> theta;

  // Simulate model
  for (auto t : time) {
    model.Update(t, 0);

    Eigen::VectorXd x = model.GetState();
    theta.push_back(x(1));
    data.push_back({t, x(0), x(1)});
  }

  // Create Plot object
  sciplot::Plot plot;

  // Set color palette
  plot.palette("set2");

  // Draw theta over the simulation time
  plot.drawCurve(time, theta).label("theta(t)").lineWidth(4);

  // Show the plot in a pop-up window
  plot.show();

  // Export data to file
  Export("data.csv", {"time", "position", "angle"}, data);
}
