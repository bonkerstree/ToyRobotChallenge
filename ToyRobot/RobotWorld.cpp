#include "RobotWorld.h"

RobotWorld::RobotWorld(int length, int width):
  m_RoboX(-1),
  m_RoboY(-1),
  m_RoboDirection(Direction::NONE)
{
  m_Length = 1;
  if(length > 0)
  {
    m_Length = length;
  }

  m_Width = 1;
  if(width > 0)
  {
    m_Width = width;
  }
}

RobotWorld::~RobotWorld()
{
  
}

std::pair<int, int> RobotWorld::GetDims()
{
  return std::make_pair(m_Length, m_Width);
}

std::pair<int, int> RobotWorld::GetRobotCoords()
{
  return std::make_pair(m_RoboX, m_RoboY);
}

RobotWorld::Direction RobotWorld::GetRobotDirection()
{
  return m_RoboDirection;
}

// Places the robot within the bounds of the world. If direction is omitted or set to None, it will face the North by default.
// The method returns true if the robot is placed successfully inside the world.
bool RobotWorld::PlaceRobot(int x, int y, Direction d/* = Direction::NORTH*/)
{
  bool isRobotPlaced = false;

  // NONE is not valid. Set the default direction to NORTH.
  if(d == Direction::NONE)
  {
    d = Direction::NORTH;
  }

  // Bounds checking
  if(x >= 0 && y >= 0 && x < m_Width && y < m_Length)
  {
    m_RoboX = x;
    m_RoboY = y;
    m_RoboDirection = d;
    isRobotPlaced = true;
  }
  
  return isRobotPlaced;
}

// Will move the robot one unit towards the direction it is facing. If it will go out of bounds, it will remain in place.
// The method returns true if it successfully moves.
bool RobotWorld::MoveRobotForward()
{
  bool robotMoved = false;

  if(m_RoboX >= 0 && m_RoboY >= 0)
  {
    if(m_RoboDirection == Direction::NORTH && m_RoboY + 1 < m_Length)
    {
      m_RoboY += 1;
      robotMoved = true;
    }
    else if(m_RoboDirection == Direction::EAST && m_RoboX + 1 < m_Width)
    {
      m_RoboX += 1;
      robotMoved = true;
    }
    else if(m_RoboDirection == Direction::SOUTH && m_RoboY - 1 >= 0)
    {
      m_RoboY -= 1;
      robotMoved = true;
    }
    else if(m_RoboDirection == Direction::WEST && m_RoboX - 1 >= 0)
    {
      m_RoboX -= 1;
      robotMoved = true;
    }
  }

  return robotMoved;
}

bool RobotWorld::RotateRobotRight()
{
  bool robotRotated = false;
  if(m_RoboDirection == Direction::NORTH)
  {
    m_RoboDirection = Direction::EAST;
    robotRotated    = true;
  }
  else if(m_RoboDirection == Direction::EAST)
  {
    m_RoboDirection = Direction::SOUTH;
    robotRotated    = true;
  }
  else if(m_RoboDirection == Direction::SOUTH)
  {
    m_RoboDirection = Direction::WEST;
    robotRotated    = true;
  }
  else if(m_RoboDirection == Direction::WEST)
  {
    m_RoboDirection = Direction::NORTH;
    robotRotated = true;
  }

  return robotRotated;
}

bool RobotWorld::RotateRobotLeft()
{
  bool robotRotated = false;
  if(m_RoboDirection == Direction::NORTH)
  {
    m_RoboDirection = Direction::WEST;
    robotRotated    = true;
  }
  else if(m_RoboDirection == Direction::WEST)
  {
    m_RoboDirection = Direction::SOUTH;
    robotRotated    = true;
  }
  else if(m_RoboDirection == Direction::SOUTH)
  {
    m_RoboDirection = Direction::EAST;
    robotRotated    = true;
  }
  else if(m_RoboDirection == Direction::EAST)
  {
    m_RoboDirection = Direction::NORTH;
    robotRotated    = true;
  }

  return robotRotated;
}