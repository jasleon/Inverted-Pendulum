#ifndef INVERTED_PENDULUM_H_
#define INVERTED_PENDULUM_H_

#include "Eigen/Dense"

class InvertedPendulum {
 private:
  Eigen::VectorXd x_;

 public:
  InvertedPendulum();
  Eigen::VectorXd getState() const;
};

#endif  // INVERTED_PENDULUM_H_
