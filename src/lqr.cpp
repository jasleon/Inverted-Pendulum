#include "lqr.h"

#include "riccati_solver.h"

void LQR::Compute() {
    (void)solveRiccatiArimotoPotter(A_, B_, Q_, R_, P_);
    K_ = R_.inverse() * B_.transpose() * P_;
}

Eigen::VectorXd LQR::Control(const Eigen::VectorXd &x) {
    Eigen::VectorXd u = - K_ * x;
    return u;
}