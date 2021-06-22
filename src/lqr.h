#ifndef LQR_H_
#define LQR_H_

#include "Eigen/Dense"

class LQR {
 public:
  Eigen::MatrixXd A_;
  Eigen::MatrixXd B_;
  Eigen::MatrixXd Q_;
  Eigen::MatrixXd R_;
  Eigen::MatrixXd K_;
};

#endif  // LQR_H_
