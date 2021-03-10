#include "inverted_pendulum.h"

#include "Eigen/Dense"

InvertedPendulum::InvertedPendulum()
    : M_(1.0),
      m_(1.0),
      J_(1.0),
      l_(1.0),
      c_(1.0),
      gamma_(1.0),
      g_(9.81),
      M_t_(2.0),
      J_t_(2.0),
      x_(Eigen::VectorXd(4)) {
  x_ << 0, 0, 0, 0;
}

Eigen::VectorXd InvertedPendulum::getState() const { return x_; }
