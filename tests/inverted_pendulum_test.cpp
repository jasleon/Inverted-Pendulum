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

  std::vector<std::tuple<Eigen::MatrixXd, Eigen::MatrixXd>> pairs;
  pairs.push_back(std::make_tuple(exp_A, model.A_));
  pairs.push_back(std::make_tuple(exp_B, model.B_));

  for (auto &p : pairs) {
    auto expected = std::get<0>(p);
    auto observed = std::get<1>(p);

    EXPECT_EQ(expected.rows(), observed.rows());
    EXPECT_EQ(expected.cols(), observed.cols());

    size_t n = expected.rows();
    size_t m = expected.cols();

    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < m; ++j) {
        EXPECT_NEAR(expected(i, j), observed(i, j), 1e-3);
      }
    }
  }
}