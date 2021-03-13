#include "../src/inverted_pendulum.h"

#include <gtest/gtest.h>

TEST(InvertedPendulumTest, Constructor) {
  InvertedPendulum model;
  Eigen::VectorXd x(4);
  x << 0, 0, 0, 0;
  EXPECT_EQ(x, model.GetState());
}