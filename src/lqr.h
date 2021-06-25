#ifndef LQR_H_
#define LQR_H_

#include "Eigen/Dense"

class LQR {
 public:
  Eigen::MatrixXd A_;
  Eigen::MatrixXd B_;
  Eigen::MatrixXd Q_;
  Eigen::MatrixXd R_;
  Eigen::MatrixXd P_;
  Eigen::MatrixXd K_;

  void Compute();
  Eigen::VectorXd Control(const Eigen::VectorXd &x);
};

#endif  // LQR_H_
