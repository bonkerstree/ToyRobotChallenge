#include "Client.h"

int main(int argc, char* argv[])
{
  RobotWorld rw(5, 5);
  std::unique_ptr<CommandReader> reader;
  bool fileReaderUsed = false;

  if(argc > 1)
  {
    std::string filename (argv[1]);
    reader = std::make_unique<CommandFileReader>(filename);
    fileReaderUsed = true;
  }
  else
  {
    reader = std::make_unique<CommandConsoleReader>();

    Trace("Please enter any of the following commands:\n");
    Trace("  PLACE X,Y,F\n");
    Trace("  MOVE\n");
    Trace("  LEFT\n");
    Trace("  RIGHT\n");
    Trace("  REPORT\n\n");
  }
  
  while(1)
  {
    if(!Execute(reader->GetCommand(), rw, fileReaderUsed))
    {
      break;
    }
  }

  return 0;
}

void Trace(std::string prompt)
{
  std::cout << prompt;
}

// Retrieves the command from either the console or a file and executes it in the RobotWorld
bool Execute(std::tuple<CommandReader::Command, std::vector<std::string>, std::string> commandWithArgs,
             RobotWorld& rw,
             bool fileReaderUsed/* = false*/)
{
  bool continueExecution = true;
  auto command       = std::get<0>(commandWithArgs);
  auto args          = std::get<1>(commandWithArgs);
  auto commandString = std::get<2>(commandWithArgs);

  bool robotIsNotPlaced = rw.GetRobotDirection() == RobotWorld::Direction::NONE;

  if(fileReaderUsed)
  {
    Trace(commandString + "\n");
  }

  if(command == CommandReader::Command::Exit)
  {
    continueExecution = false;
  }
  else
  {
    if(command == CommandReader::Command::Invalid)
    {
      Trace("Invalid command!\n");
    }
    else
    {
      if(robotIsNotPlaced && command != CommandReader::Command::Place)
      {
        Trace("Robot is not yet placed! Place robot first before entering any other command\n");
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
            Trace("Robot cannot move forward any further!\n");
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
          Trace("Output: ");
          Trace(std::to_string(rw.GetRobotCoords().first) + "," + std::to_string(rw.GetRobotCoords().second) + "," + RobotWorld::DirectionValToString(rw.GetRobotDirection()) + "\n");
        }
      }
    }
  }

  return continueExecution;
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
    Trace(error);
  }
}