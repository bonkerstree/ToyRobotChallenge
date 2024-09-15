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

TEST(RobotWorldTest, GetDims_WillReturnLengthOneAndWidthOne_WhenRobotWorldIsConstructedWithNegativeLengthAndNegativeWidth) {
  RobotWorld rw(-5, -1);
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

TEST(RobotWorldTest, PlaceRobot_WillReturnFalse_WhenRobotWorldIsConstructedWithLengthOneWidthOneAndRobotIsPlacedInXOneYOne) {
  RobotWorld rw(1, 1);
  bool isRobotPlaced = rw.PlaceRobot(1, 1);

  EXPECT_FALSE(isRobotPlaced);
}

TEST(RobotWorldTest, PlaceRobot_WillReturnTrue_WhenRobotWorldIsConstructedWithLengthOneWidthOneAndRobotIsPlacedInXZeroYZero) {
  RobotWorld rw(1, 1);
  bool isRobotPlaced = rw.PlaceRobot(0, 0);

  EXPECT_TRUE(isRobotPlaced);
}

TEST(RobotWorldTest, PlaceRobot_WillReturnFalse_WhenRobotWorldIsConstructedWithLengthOneWidthOneAndRobotIsPlacedInXZeroYOne) {
  RobotWorld rw(1, 1);
  bool isRobotPlaced = rw.PlaceRobot(0, 1);

  EXPECT_FALSE(isRobotPlaced);
}

TEST(RobotWorldTest, PlaceRobot_WillReturnFalse_WhenRobotWorldIsConstructedWithLengthOneWidthOneAndRobotIsPlacedInXOneYZero) {
  RobotWorld rw(1, 1);
  bool isRobotPlaced = rw.PlaceRobot(1, 0);

  EXPECT_FALSE(isRobotPlaced);
}


TEST(RobotWorldTest, PlaceRobot_WillReturnFalse_WhenRobotWorldIsConstructedWithLengthOneWidthOneAndRobotIsPlacedInNegativeXAndYZero) {
  RobotWorld rw(1, 1);
  bool isRobotPlaced = rw.PlaceRobot(-1, 0);

  EXPECT_FALSE(isRobotPlaced);
}

TEST(RobotWorldTest, PlaceRobot_WillReturnFalse_WhenRobotWorldIsConstructedWithLengthOneWidthOneAndRobotIsPlacedInXZeroAndNegativeY) {
  RobotWorld rw(1, 1);
  bool isRobotPlaced = rw.PlaceRobot(0, -1);

  EXPECT_FALSE(isRobotPlaced);
}

/*
TEST(RobotWorldTest, PlaceRobot_WillReturnFalse_WhenRobotWorldIsConstructedWithLengthOneWidthOneAndRobotIsPlacedInXOneAndYTwo) {
  RobotWorld rw(1, 1);
  bool isRobotPlaced = rw.PlaceRobot(-1, 2);

  EXPECT_FALSE(isRobotPlaced);
}
/*
TEST(RobotWorldTest, GetRobotCoords_WillReturnXOneYOne_WhenRobotWorldIsConstructedWithLengthOneWidthOneAndRobotIsPlacedInXOneYOne) {
  RobotWorld rw(1, 1);
  rw.PlaceRobot(1, 1);
  auto coords = rw.GetRobotCoords();

  EXPECT_EQ(coords.first, 1);
  EXPECT_EQ(coords.second, 1);
}
*/