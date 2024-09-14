#pragma once
#include <utility>

class RobotWorld
{
public:
  RobotWorld(int length, int width);
  ~RobotWorld();

  std::pair<int, int> GetDims();
  std::pair<int, int> GetRobotCoords();
  bool PlaceRobot(int x, int y);

private:
  int _length;
  int _width;
};

