#include <iostream>

#include "inverted_pendulum.h"

int main() {
  InvertedPendulum model;
  double t = 0;
  while(t < 1.0)
  {
    t += 0.001;
    model.Update(t, 0);
  }
  std::cout << model.GetState() << std::endl;
}
