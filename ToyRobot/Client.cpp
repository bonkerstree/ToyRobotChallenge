#include "Client.h"

int main()
{
  RobotWorld rw(5, 5);
  CommandConsoleReader reader;
  Prompt("Please enter any of the following commands:\n");
  Prompt("  PLACE X,Y,F\n");
  Prompt("  MOVE\n");
  Prompt("  LEFT\n");
  Prompt("  RIGHT\n");
  Prompt("  REPORT\n\n");
  
  while(1)
  {
    Execute(reader.GetCommand(), rw);
  }

  return 0;
}

void Prompt(std::string prompt)
{
  std::cout << prompt;
}

void Execute(std::pair<CommandReader::Command, std::vector<std::string>> commandWithArgs, RobotWorld& rw)
{
  auto command = commandWithArgs.first;
  auto args = commandWithArgs.second;

  bool robotIsNotPlaced = rw.GetRobotDirection() == RobotWorld::Direction::NONE;

  if(command == CommandReader::Command::Invalid)
  {
    Prompt("Invalid command!\n");
  }
  else
  {
    if(robotIsNotPlaced && command != CommandReader::Command::Place)
    {
      Prompt("Robot is not yet placed! Place robot first before entering any other command\n");
    }
    else
    {
      if(command == CommandReader::Command::Place)
      {
        ManagePlaceCommand(command, args, rw);
      }
      else if(command == CommandReader::Command::Move)
      {
        if(!rw.MoveRobotForward())
        {
          Prompt("Robot cannot move forward any further!\n");
        }
      }
      else if(command == CommandReader::Command::Left)
      {
        rw.RotateRobotLeft();
      }
      else if(command == CommandReader::Command::Right)
      {
        rw.RotateRobotRight();
      }
      else if(command == CommandReader::Command::Report)
      {
        Prompt("Output: ");
        Prompt(std::to_string(rw.GetRobotCoords().first) + "," + std::to_string(rw.GetRobotCoords().second) + "," + RobotWorld::DirectionValToString(rw.GetRobotDirection()) + "\n");
      }
    }
  }
}

void ManagePlaceCommand(const CommandReader::Command command, const std::vector<std::string>& args, RobotWorld& rw)
{
  std::string error;
  if(args.size() < 3)
  {
    error = "Robot cannot be placed! Too few arguments to PLACE command!\n";
  }
  
  if(error.empty())
  {
    std::string numbers = "0123456789";
    if(args.at(0).find_first_of(numbers) == std::string::npos || args.at(1).find_first_of(numbers) == std::string::npos)
    {
      error = "First two arguments of the PLACE command must be numerical\n";
    }
  }

  if(error.empty())
  {    
    if(RobotWorld::DirectionStrToVal(args.at(2)) == RobotWorld::Direction::NONE)
    {
      error = "Third argument of PLACE command can only be one of the following:\n"
              "  NORTH\n"
              "  SOUTH\n"
              "  EAST\n"
              "  WEST\n";
    }
  }

  if(error.empty())
  {
    int x = stoi(args.at(0));
    int y = stoi(args.at(1));
    auto direction = RobotWorld::DirectionStrToVal(args.at(2));

    if(!rw.PlaceRobot(x, y, direction))
    {
      error = "Cannot place robot there!\n";
    }
  }

  if(!error.empty())
  {
    Prompt(error);
  }
}