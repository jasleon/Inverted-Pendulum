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
      x_(Eigen::VectorXd(4)),
      x_dot_(Eigen::VectorXd(4)),
      previous_time_(0.0) {
  x_ << 0, 0, 0, 0;
  x_dot_ << 0, 0, 0, 0;
}

void InvertedPendulum::update(double time, double u) {
  // Recover state parameters
  double x     = x_(0); // position of the base
  double theta = x_(1); // angle of the pendulum
  double vx    = x_(2); // velocity of the base
  double omega = x_(3); // angular rate of the pendulum

  // Compute common terms
  double s_t = std::sin(theta);
  double c_t = std::cos(theta);
  double o_2 = std::pow(omega, 2);
  double l_2 = std::pow(l_, 2);

  // Calculate derivatives
  x_dot_(0) = vx;
  x_dot_(1) = omega;
  x_dot_(2) = (-m_ * l_ * s_t * o_2 + m_ * g_ * (m_ * l_2 / J_t_) * s_t * c_t -
               c_ * vx - (gamma_ / J_t_) * m_ * l_ * c_t * omega + u) /
              (M_t_ - m_ * (m_ * l_2 / J_t_) * c_t * c_t);
  x_dot_(3) =
      (-m_ * l_2 * s_t * c_t * o_2 + M_t_ * g_ * l_ * s_t - c_ * l_ * c_t * vx -
       gamma_ * (M_t_ / m_) * omega + l_ * c_t * u) /
      (J_t_ * (M_t_ / m_) - m_ * (l_ * c_t) * (l_ * c_t));
  
  // Apply Euler method to solve differential equations
  double dt = time - previous_time_;
  previous_time_ = time;
  x_ += x_dot_ * dt;
}

Eigen::VectorXd InvertedPendulum::getState() const { return x_; }
