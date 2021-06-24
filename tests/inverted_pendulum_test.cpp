#include "inverted_pendulum.h"

#include <gtest/gtest.h>

TEST(InvertedPendulumTest, DefaultConstructor) {
  InvertedPendulum model;
  Eigen::VectorXd x(4);
  x << 0, 0, 0, 0;

  ASSERT_EQ(x, model.GetState());
  ASSERT_EQ(1, model.M_);
  ASSERT_EQ(1, model.m_);
  ASSERT_EQ(1, model.J_);
  ASSERT_EQ(1, model.l_);
  ASSERT_EQ(1, model.c_);
  ASSERT_EQ(1, model.gamma_);
  ASSERT_EQ(9.81, model.g_);
  ASSERT_EQ(2, model.M_t_);
  ASSERT_EQ(2, model.J_t_);
}

TEST(InvertedPendulumTest, Linearize) {
  InvertedPendulum model;
  model.Linearize();

  Eigen::MatrixXd exp_A = Eigen::MatrixXd::Zero(4, 4);
  exp_A << 0, 0, 1, 0, 
           0, 0, 0, 1, 
           0, 3.27, -0.6667, -0.3333, 
           0, 6.54, -0.3333, -0.6667;
  
  Eigen::MatrixXd exp_B = Eigen::MatrixXd::Zero(4, 1);
  exp_B << 0, 0, 0.6667, 0.3333;

  size_t n = exp_A.rows();
  size_t m = exp_A.cols();
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      EXPECT_NEAR(exp_A(i, j), model.A_(i, j), 1e-3);
    }
  }

  n = exp_B.rows();
  m = exp_B.cols();
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      EXPECT_NEAR(exp_B(i, j), model.B_(i, j), 1e-3);
    }
  }
}