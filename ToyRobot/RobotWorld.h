#pragma once
#include <utility>

class RobotWorld
{
public:
  RobotWorld(int length, int width);
  ~RobotWorld();

  std::pair<int, int> GetDims();

private:
  int _length;
  int _width;
};

