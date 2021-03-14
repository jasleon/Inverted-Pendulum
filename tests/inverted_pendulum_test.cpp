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