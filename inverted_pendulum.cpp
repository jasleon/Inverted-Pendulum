#include "inverted_pendulum.h"

#include "Eigen/Dense"

InvertedPendulum::InvertedPendulum() {
  x_ = Eigen::VectorXd(4);
  x_ << 0, 0, 0, 0;
}

Eigen::VectorXd InvertedPendulum::getState() const { return x_; }
