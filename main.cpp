#include <iostream>

#include "inverted_pendulum.h"

int main() {
  InvertedPendulum model;
  std::cout << model.getState() << std::endl;
}
