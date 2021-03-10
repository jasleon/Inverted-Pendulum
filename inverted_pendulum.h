#ifndef INVERTED_PENDULUM_H_
#define INVERTED_PENDULUM_H_

#include "Eigen/Dense"

class InvertedPendulum {
 private:
  const double M_;      // mass of the base
  const double m_;      // mass of the pendulum
  const double J_;      // moment of inertia of the pendulum
  const double l_;      // distance from the base to the pendulum
  const double c_;      // coefficient of viscous friction (base)
  const double gamma_;  // coefficient of viscous friction (pendulum)
  const double g_;      // acceleration due to gravity
  const double M_t_;    // total mass
  const double J_t_;    // total inertia
  
  Eigen::VectorXd x_;

 public:
  InvertedPendulum();
  Eigen::VectorXd getState() const;
};

#endif  // INVERTED_PENDULUM_H_
