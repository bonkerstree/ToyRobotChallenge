#include "RobotWorld.h"

RobotWorld::RobotWorld(int length, int width)
{
  _length = 1;
  if(length > 0)
  {
    _length = length;
  }

  _width = 1;
  if(width > 0)
  {
    _width = width;
  }
}

RobotWorld::~RobotWorld()
{
  
}

std::pair<int, int> RobotWorld::GetDims()
{
  return std::make_pair(_length, _width);
}

std::pair<int, int> RobotWorld::GetRobotCoords()
{
  return std::make_pair<int, int>(1, 1);
}

bool RobotWorld::PlaceRobot(int x, int y)
{
  return true;
}