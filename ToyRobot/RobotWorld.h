#pragma once
#include <utility>
#include <string>

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
  virtual bool PlaceRobot(int x, int y, Direction d = Direction::NORTH);
  bool MoveRobotForward();
  bool RotateRobotRight();
  bool RotateRobotLeft();

  static RobotWorld::Direction DirectionStrToVal(std::string directionString);
  static std::string DirectionValToString(RobotWorld::Direction direction);

private:
  int m_Length;
  int m_Width;
  int m_RoboX;
  int m_RoboY;
  Direction m_RoboDirection;
};

