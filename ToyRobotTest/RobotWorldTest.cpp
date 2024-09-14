#include "pch.h"

TEST(RobotWorldTest, GetDims_WillReturnLengthFiveAndWidthFive_WhenRobotWorldIsConstructedWithLengthFiveAndWidthFive) {
  RobotWorld rw(5, 5);
  auto dimensions = rw.GetDims();

  EXPECT_EQ(dimensions.first, 5);
  EXPECT_EQ(dimensions.second, 5);
}

TEST(RobotWorldTest, GetDims_WillReturnLengthOneAndWidthOne_WhenRobotWorldIsConstructedWithLengthZeroAndWidthZero) {
  RobotWorld rw(0, 0);
  auto dimensions = rw.GetDims();

  EXPECT_EQ(dimensions.first, 1);
  EXPECT_EQ(dimensions.second, 1);
}

TEST(RobotWorldTest, GetDims_WillReturnLengthOneAndWidthFive_WhenRobotWorldIsConstructedWithLengthZeroAndWidthFive) {
  RobotWorld rw(0, 5);
  auto dimensions = rw.GetDims();

  EXPECT_EQ(dimensions.first, 1);
  EXPECT_EQ(dimensions.second, 5);
}

TEST(RobotWorldTest, GetDims_WillReturnLengthFiveAndWidthOne_WhenRobotWorldIsConstructedWithLengthFiveAndWidthZero) {
  RobotWorld rw(5, 0);
  auto dimensions = rw.GetDims();

  EXPECT_EQ(dimensions.first, 5);
  EXPECT_EQ(dimensions.second, 1);
}