#include <iostream>

#include "Eigen/Dense"
#include "inverted_pendulum.h"
#include "lqr.h"

int main() {
  InvertedPendulum model;
  LQR control;

  model.Linearize();

  control.A_ = model.A_;
  control.B_ = model.B_;
  control.Q_ = Eigen::MatrixXd::Identity(4, 4);
  control.Q_(0, 0) = 10;
  control.R_ = Eigen::MatrixXd::Identity(1, 1);
  control.Compute();

  std::cout << "P: \n";
  std::cout << control.P_ << '\n';
  std::cout << "K: \n";
  std::cout << control.K_ << '\n';

  Eigen::VectorXd x = Eigen::VectorXd::Zero(4);
  x << 1, 1, 1, 1;
  std::cout << "u: \n";
  std::cout << control.Control(x) << '\n';
}
