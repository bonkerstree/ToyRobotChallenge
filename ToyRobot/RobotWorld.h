#pragma once
#include <utility>

class RobotWorld
{
public:
  enum class Direction
  {
    NONE,
    NORTH,
    EAST,
    SOUTH,
    WEST
  };

  RobotWorld(int length, int width);
  ~RobotWorld();

  std::pair<int, int> GetDims();
  std::pair<int, int> GetRobotCoords();
  Direction GetRobotDirection();
  bool PlaceRobot(int x, int y, Direction d = Direction::NORTH);
  bool MoveRobotForward();
  bool RotateRobotRight();
  bool RotateRobotLeft();

private:
  int m_Length;
  int m_Width;
  int m_RoboX;
  int m_RoboY;
  Direction m_RoboDirection;
};

