#include "pch.h"

/* Legend:
    L1 = Length of 1
    W1 = Width of 1
    X1 = At X coordinate 1
    Y1 = At Y coordinate 1
    1x2 = length 1 by width 2
*/

TEST(RobotWorldTest, GetDims_WillReturnL5W5_When5x5RobotWorldIsConstructed) {
  RobotWorld rw(5, 5);
  auto dimensions = rw.GetDims();

  EXPECT_EQ(dimensions.first, 5);
  EXPECT_EQ(dimensions.second, 5);
}

TEST(RobotWorldTest, GetDims_WillReturnL1W1_When0x0RobotWorldIsConstructed) {
  RobotWorld rw(0, 0);
  auto dimensions = rw.GetDims();

  EXPECT_EQ(dimensions.first, 1);
  EXPECT_EQ(dimensions.second, 1);
}

TEST(RobotWorldTest, GetDims_WillReturnL1W1_WhenRobotWorldIsConstructedWithNegativeLengthAndNegativeWidth) {
  RobotWorld rw(-5, -1);
  auto dimensions = rw.GetDims();

  EXPECT_EQ(dimensions.first, 1);
  EXPECT_EQ(dimensions.second, 1);
}

TEST(RobotWorldTest, GetDims_WillReturnL1W5_When0x5RobotWorldIsConstructed) {
  RobotWorld rw(0, 5);
  auto dimensions = rw.GetDims();

  EXPECT_EQ(dimensions.first, 1);
  EXPECT_EQ(dimensions.second, 5);
}

TEST(RobotWorldTest, GetDims_WillReturnL5W1_When5x0RobotWorldIsConstructed) {
  RobotWorld rw(5, 0);
  auto dimensions = rw.GetDims();

  EXPECT_EQ(dimensions.first, 5);
  EXPECT_EQ(dimensions.second, 1);
}

TEST(RobotWorldTest, PlaceRobot_WillReturnFalse_WhenRobotIsPlacedOn1x1WorldAtX1Y1) {
  RobotWorld rw(1, 1);
  bool isRobotPlaced = rw.PlaceRobot(1, 1);

  EXPECT_FALSE(isRobotPlaced);
}

TEST(RobotWorldTest, PlaceRobot_WillReturnTrue_WhenRobotIsPlacedOn1x1WorldAtX0Y0) {
  RobotWorld rw(1, 1);
  bool isRobotPlaced = rw.PlaceRobot(0, 0);

  EXPECT_TRUE(isRobotPlaced);
}

TEST(RobotWorldTest, PlaceRobot_WillReturnFalse_WhenRobotIsPlacedOn1x1WorldAtX0Y1) {
  RobotWorld rw(1, 1);
  bool isRobotPlaced = rw.PlaceRobot(0, 1);

  EXPECT_FALSE(isRobotPlaced);
}

TEST(RobotWorldTest, PlaceRobot_WillReturnFalse_WhenRobotIsPlacedOn1x1WorldAtX1Y0) {
  RobotWorld rw(1, 1);
  bool isRobotPlaced = rw.PlaceRobot(1, 0);

  EXPECT_FALSE(isRobotPlaced);
}


TEST(RobotWorldTest, PlaceRobot_WillReturnFalse_WhenRobotIsPlacedOn1x1WorldAtNegativeXAndY0) {
  RobotWorld rw(1, 1);
  bool isRobotPlaced = rw.PlaceRobot(-1, 0);

  EXPECT_FALSE(isRobotPlaced);
}

TEST(RobotWorldTest, PlaceRobot_WillReturnFalse_WhenRobotIsPlacedOn1x1WorldAtX0AndNegativeY) {
  RobotWorld rw(1, 1);
  bool isRobotPlaced = rw.PlaceRobot(0, -1);

  EXPECT_FALSE(isRobotPlaced);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnNone_WhenRobotIsPlacedOutOfBounds) {
  int length = 1;
  int width = 1;

  RobotWorld rw(length, width);
  
  rw.PlaceRobot(-1, 1, RobotWorld::Direction::NORTH);
  auto robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::NONE);
  
  rw.PlaceRobot(0, 1, RobotWorld::Direction::NORTH);
  robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::NONE);

  rw.PlaceRobot(1, 1, RobotWorld::Direction::NORTH);
  robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::NONE);

  rw.PlaceRobot(-1, 0, RobotWorld::Direction::NORTH);
  robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::NONE);

  rw.PlaceRobot(1, 0, RobotWorld::Direction::NORTH);
  robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::NONE);
  
  rw.PlaceRobot(-1, -1, RobotWorld::Direction::NORTH);
  robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::NONE);

  rw.PlaceRobot(0, -1, RobotWorld::Direction::NORTH);
  robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::NONE);

  rw.PlaceRobot(1, -1, RobotWorld::Direction::NORTH);
  robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::NONE);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnNone_WhenRobotIsNotPlaced) {
  int length = 1;
  int width = 1;

  RobotWorld rw(length, width);
  
  auto robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::NONE);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnNorth_WhenRobotIsPlacedWithoutDirection) {
  int length = 1;
  int width = 1;

  RobotWorld rw(length, width);
  
  rw.PlaceRobot(0, 0);
  auto robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::NORTH);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnNorth_WhenRobotIsPlacedWithNoneDirection) {
  int length = 1;
  int width = 1;

  RobotWorld rw(length, width);
  
  rw.PlaceRobot(0, 0, RobotWorld::Direction::NONE);
  auto robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::NORTH);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnNorth_WhenRobotIsPlacedFacingNorth) {
  int length = 1;
  int width = 1;

  RobotWorld rw(length, width);
  
  rw.PlaceRobot(0, 0, RobotWorld::Direction::NORTH);
  auto robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::NORTH);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnEast_WhenRobotIsPlacedFacingEast) {
  int length = 1;
  int width = 1;

  RobotWorld rw(length, width);
  
  rw.PlaceRobot(0, 0, RobotWorld::Direction::EAST);
  auto robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::EAST);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnSouth_WhenRobotIsPlacedFacingSouth) {
  int length = 1;
  int width = 1;

  RobotWorld rw(length, width);
  
  rw.PlaceRobot(0, 0, RobotWorld::Direction::SOUTH);
  auto robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::SOUTH);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnWest_WhenRobotIsPlacedFacingWest) {
  int length = 1;
  int width = 1;

  RobotWorld rw(length, width);
  
  rw.PlaceRobot(0, 0, RobotWorld::Direction::WEST);
  auto robotDirection = rw.GetRobotDirection();
  EXPECT_EQ(robotDirection, RobotWorld::Direction::WEST);
}

TEST(RobotWorldTest, GetRobotCoords_WillReturnXNeg1YNeg1_WhenRobotIsPlacedOutOfBoundsWithPositiveValuesIn3x3) {
  int length = 3;
  int width = 3;
  RobotWorld rw(length, width);
  

  for (int i = 0; i <= length; i++)
  {
    rw.PlaceRobot(3, i);
    auto coords = rw.GetRobotCoords();  

    EXPECT_EQ(coords.first, -1);
    EXPECT_EQ(coords.second, -1);
  }

  for (int i = 0; i <= width; i++)
  {
    rw.PlaceRobot(i, 3);
    auto coords = rw.GetRobotCoords();  

    EXPECT_EQ(coords.first, -1);
    EXPECT_EQ(coords.second, -1);
  }
}

TEST(RobotWorldTest, GetRobotCoords_WillReturnXNeg1YNeg1_WhenRobotIsNotPlaced) {
  RobotWorld rw(1, 1);
  auto coords = rw.GetRobotCoords();

  EXPECT_EQ(coords.first, -1);
  EXPECT_EQ(coords.second, -1);
}

TEST(RobotWorldTest, GetRobotCoords_WillReturnX0Y0_WhenRobotIsPlacedOn1x1BoardAtX0Y0) {
  RobotWorld rw(1, 1);
  rw.PlaceRobot(0, 0);
  auto coords = rw.GetRobotCoords();

  EXPECT_EQ(coords.first, 0);
  EXPECT_EQ(coords.second, 0);
}

TEST(RobotWorldTest, GetRobotCoords_WillReturnEachCoord_WhenRobotIsPlacedInEachCoordOfRobotWorld) {
  int length = 5;
  int width = 5;
  
  RobotWorld rw(length, width);

  for(int i = 0; i < length; i++)
  {
    for(int j = 0; j < width; j++)
    {
      rw.PlaceRobot(i, j);
      auto coords = rw.GetRobotCoords();

      EXPECT_EQ(coords.first, i);
      EXPECT_EQ(coords.second, j);
    }
  }
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnFalse_WhenRobotIsNotPlaced) {
  RobotWorld rw(1, 1);

  bool robotMoved = rw.MoveRobotForward();

  EXPECT_FALSE(robotMoved);
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnFalse_WhenRobotIsPlacedOutOfBounds) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(1, 1);
  bool robotMoved = rw.MoveRobotForward();

  EXPECT_FALSE(robotMoved);
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnFalse_WhenRobotGoesOutOfBoundsNorthOf1x1) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::NORTH);
  bool robotMoved = rw.MoveRobotForward();

  EXPECT_FALSE(robotMoved);
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnFalse_WhenRobotGoesOutOfBoundsEastOf1x1) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::EAST);
  bool robotMoved = rw.MoveRobotForward();

  EXPECT_FALSE(robotMoved);
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnFalse_WhenRobotGoesOutOfBoundsSouthOf1x1) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::SOUTH);
  bool robotMoved = rw.MoveRobotForward();

  EXPECT_FALSE(robotMoved);
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnFalse_WhenRobotGoesOutOfBoundsWestOf1x1) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::WEST);
  bool robotMoved = rw.MoveRobotForward();

  EXPECT_FALSE(robotMoved);
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnTrue_WhenRobotMovesNorthFromCenterOf3x3) {
  RobotWorld rw(3, 3);

  rw.PlaceRobot(1, 1, RobotWorld::Direction::NORTH);
  bool robotMoved = rw.MoveRobotForward();

  EXPECT_TRUE(robotMoved);
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnTrue_WhenRobotMovesEastFromCenterOf3x3) {
  RobotWorld rw(3, 3);

  rw.PlaceRobot(1, 1, RobotWorld::Direction::EAST);
  bool robotMoved = rw.MoveRobotForward();

  EXPECT_TRUE(robotMoved);
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnTrue_WhenRobotMovesSouthFromCenterOf3x3) {
  RobotWorld rw(3, 3);

  rw.PlaceRobot(1, 1, RobotWorld::Direction::SOUTH);
  bool robotMoved = rw.MoveRobotForward();

  EXPECT_TRUE(robotMoved);
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnTrue_WhenRobotMovesWestFromCenterOf3x3) {
  RobotWorld rw(3, 3);

  rw.PlaceRobot(1, 1, RobotWorld::Direction::WEST);
  bool robotMoved = rw.MoveRobotForward();

  EXPECT_TRUE(robotMoved);
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnTrue_WhenRobotMovesNorthWhileOtherDirectionsAreOutOfBounds) {
  RobotWorld rw(2, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::NORTH);
  bool robotMoved = rw.MoveRobotForward();

  EXPECT_TRUE(robotMoved);
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnTrue_WhenRobotMovesEastWhileOtherDirectionsAreOutOfBounds) {
  RobotWorld rw(1, 2);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::EAST);
  bool robotMoved = rw.MoveRobotForward();

  EXPECT_TRUE(robotMoved);
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnTrue_WhenRobotMovesSouthWhileOtherDirectionsAreOutOfBounds) {
  RobotWorld rw(2, 1);

  rw.PlaceRobot(0, 1, RobotWorld::Direction::SOUTH);
  bool robotMoved = rw.MoveRobotForward();

  EXPECT_TRUE(robotMoved);
}

TEST(RobotWorldTest, MoveRobotForward_WillReturnTrue_WhenRobotMovesWestWhileOtherDirectionsAreOutOfBounds) {
  RobotWorld rw(1, 2);

  rw.PlaceRobot(1, 0, RobotWorld::Direction::WEST);
  bool robotMoved = rw.MoveRobotForward();

  EXPECT_TRUE(robotMoved);
}

TEST(RobotWorldTest, GetRobotCoords_WillReturnX1Y2_WhenRobotMovesNorthFromCenterOf3x3) {
  RobotWorld rw(3, 3);

  rw.PlaceRobot(1, 1, RobotWorld::Direction::NORTH);
  rw.MoveRobotForward();
  auto coords = rw.GetRobotCoords();

  EXPECT_EQ(coords.first, 1);
  EXPECT_EQ(coords.second, 2);
}

TEST(RobotWorldTest, GetRobotCoords_WillReturnX2Y1_WhenRobotMovesEastFromCenterOf3x3) {
  RobotWorld rw(3, 3);

  rw.PlaceRobot(1, 1, RobotWorld::Direction::EAST);
  rw.MoveRobotForward();
  auto coords = rw.GetRobotCoords();

  EXPECT_EQ(coords.first, 2);
  EXPECT_EQ(coords.second, 1);
}

TEST(RobotWorldTest, GetRobotCoords_WillReturnX1Y0_WhenRobotMovesSouthFromCenterOf3x3) {
  RobotWorld rw(3, 3);

  rw.PlaceRobot(1, 1, RobotWorld::Direction::SOUTH);
  rw.MoveRobotForward();
  auto coords = rw.GetRobotCoords();

  EXPECT_EQ(coords.first, 1);
  EXPECT_EQ(coords.second, 0);
}

TEST(RobotWorldTest, GetRobotCoords_WillReturnX0Y1_WhenRobotMovesWestFromCenterOf3x3) {
  RobotWorld rw(3, 3);

  rw.PlaceRobot(1, 1, RobotWorld::Direction::WEST);
  rw.MoveRobotForward();
  auto coords = rw.GetRobotCoords();

  EXPECT_EQ(coords.first, 0);
  EXPECT_EQ(coords.second, 1);
}

TEST(RobotWorldTest, RotateRobotRight_WillReturnFalse_WhenRobotIsNotPlaced) {
  RobotWorld rw(1, 1);

  bool robotRotated = rw.RotateRobotRight();

  EXPECT_FALSE(robotRotated);
}

TEST(RobotWorldTest, RotateRobotRight_WillReturnFalse_WhenRobotIsPlacedOutOfBounds) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(1, 1, RobotWorld::Direction::NORTH);
  bool robotRotated = rw.RotateRobotRight();

  EXPECT_FALSE(robotRotated);
}

TEST(RobotWorldTest, RotateRobotRight_WillReturnTrue_WhenRobotIsFacingNorth) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::NORTH);
  bool robotRotated = rw.RotateRobotRight();

  EXPECT_TRUE(robotRotated);
}

TEST(RobotWorldTest, RotateRobotRight_WillReturnTrue_WhenRobotIsFacingEast) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::EAST);
  bool robotRotated = rw.RotateRobotRight();

  EXPECT_TRUE(robotRotated);
}

TEST(RobotWorldTest, RotateRobotRight_WillReturnTrue_WhenRobotIsFacingSouth) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::SOUTH);
  bool robotRotated = rw.RotateRobotRight();

  EXPECT_TRUE(robotRotated);
}

TEST(RobotWorldTest, RotateRobotRight_WillReturnTrue_WhenRobotIsFacingWest) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::WEST);
  bool robotRotated = rw.RotateRobotRight();

  EXPECT_TRUE(robotRotated);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnNone_WhenRobotIsNotPlacedButRotatedRight) {
  RobotWorld rw(1, 1);

  rw.RotateRobotRight();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::NONE);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnNone_WhenRobotIsPlacedOutOfBoundsButRotatedRight) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(1, 1, RobotWorld::Direction::NORTH);
  rw.RotateRobotRight();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::NONE);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnEast_WhenRobotIsRotatedRightWhileFacingNorth) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::NORTH);
  rw.RotateRobotRight();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::EAST);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnSouth_WhenRobotIsRotatedRightWhileFacingEast) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::EAST);
  rw.RotateRobotRight();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::SOUTH);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnWest_WhenRobotIsRotatedRightWhileFacingSouth) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::SOUTH);
  rw.RotateRobotRight();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::WEST);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnNorth_WhenRobotIsRotatedRightWhileFacingWest) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::WEST);
  rw.RotateRobotRight();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::NORTH);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnNorth_WhenRobotFacingNorthIsRotatedRightFourTimes) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::NORTH);
  rw.RotateRobotRight();
  rw.RotateRobotRight();
  rw.RotateRobotRight();
  rw.RotateRobotRight();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::NORTH);
}
TEST(RobotWorldTest, RotateRobotLeft_WillReturnFalse_WhenRobotIsNotPlaced) {
  RobotWorld rw(1, 1);

  bool robotRotated = rw.RotateRobotLeft();

  EXPECT_FALSE(robotRotated);
}

TEST(RobotWorldTest, RotateRobotLeft_WillReturnFalse_WhenRobotIsPlacedOutOfBounds) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(1, 1, RobotWorld::Direction::NORTH);
  bool robotRotated = rw.RotateRobotLeft();

  EXPECT_FALSE(robotRotated);
}

TEST(RobotWorldTest, RotateRobotLeft_WillReturnTrue_WhenRobotIsFacingNorth) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::NORTH);
  bool robotRotated = rw.RotateRobotLeft();

  EXPECT_TRUE(robotRotated);
}

TEST(RobotWorldTest, RotateRobotLeft_WillReturnTrue_WhenRobotIsFacingWest) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::WEST);
  bool robotRotated = rw.RotateRobotLeft();

  EXPECT_TRUE(robotRotated);
}

TEST(RobotWorldTest, RotateRobotLeft_WillReturnTrue_WhenRobotIsFacingSouth) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::SOUTH);
  bool robotRotated = rw.RotateRobotLeft();

  EXPECT_TRUE(robotRotated);
}

TEST(RobotWorldTest, RotateRobotLeft_WillReturnTrue_WhenRobotIsFacingEast) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::EAST);
  bool robotRotated = rw.RotateRobotLeft();

  EXPECT_TRUE(robotRotated);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnNone_WhenRobotIsNotPlacedButRotatedLeft) {
  RobotWorld rw(1, 1);

  rw.RotateRobotLeft();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::NONE);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnNone_WhenRobotIsPlacedOutOfBoundsButRotatedLeft) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(1, 1, RobotWorld::Direction::NORTH);
  rw.RotateRobotLeft();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::NONE);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnWest_WhenRobotIsRotatedLeftWhileFacingNorth) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::NORTH);
  rw.RotateRobotLeft();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::WEST);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnSouth_WhenRobotIsRotatedLeftWhileFacingWest) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::WEST);
  rw.RotateRobotLeft();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::SOUTH);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnEast_WhenRobotIsRotatedLeftWhileFacingSouth) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::SOUTH);
  rw.RotateRobotLeft();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::EAST);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnNorth_WhenRobotIsRotatedLeftWhileFacingEast) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::EAST);
  rw.RotateRobotLeft();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::NORTH);
}

TEST(RobotWorldTest, GetRobotDirection_WillReturnNorth_WhenRobotFacingNorthIsRotatedLeftFourTimes) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::NORTH);
  rw.RotateRobotLeft();
  rw.RotateRobotLeft();
  rw.RotateRobotLeft();
  rw.RotateRobotLeft();
  auto robotDirection = rw.GetRobotDirection();

  EXPECT_EQ(robotDirection, RobotWorld::Direction::NORTH);
}

/*
TEST(RobotWorldTest, GetRobotCoords_WillReturnPreviousPosition_WhenRobotGoesOutOfBoundsNorth) {
  RobotWorld rw(1, 1);

  rw.PlaceRobot(0, 0, RobotWorld::Direction::NORTH);
  rw.MoveRobotForward();
  auto coords = rw.GetRobotCoords();

  EXPECT_EQ(coords.first, 0);
  EXPECT_EQ(coords.second, 0);
}
*/