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
      x_dot_(Eigen::VectorXd(4)) {
  x_ << 0, 0, 0, 0;
  x_dot_ << 0, 0, 0, 0;
}

Eigen::VectorXd InvertedPendulum::getState() const { return x_; }

void InvertedPendulum::update() {
  double u = 0.0;
  double q = x_(0);
  double t = x_(1);
  double q_dot = x_(2);
  double t_dot = x_(3);

  double s_t = std::sin(t);
  double c_t = std::cos(t);
  double t_dot_2 = std::pow(t_dot, 2.0);
  double l_2 = std::pow(l_, 2.0);
  
  x_dot_(0) = q_dot;
  x_dot_(1) = t_dot;
  x_dot_(2) =
      (-m_ * l_ * s_t * t_dot_2 + m_ * g_ * (m_ * l_2 / J_t_) * s_t * c_t -
       c_ * q_dot - (gamma_ / J_t_) * m_ * l_ * c_t * t + u) /
      (M_t_ - m_ * (m_ * l_2 / J_t_) * c_t * c_t);
  x_dot_(3) =
      (-m_ * l_2 * s_t * c_t * t_dot_2 + M_t_ * g_ * l_ * s_t -
       c_ * l_ * c_t * q_dot - gamma_ * (M_t_ / m_) * t_dot + l_ * c_t * u) /
      (J_t_ * (M_t_ / m_) - m_ * (l_ * c_t) * (l_ * c_t));
}
