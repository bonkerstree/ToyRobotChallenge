#include "CommandReader.h"
#include "Utilities.h"

CommandReader::Command CommandReader::ParseCommand(std::string commandString)
{
  Util::toupper(commandString);
  Util::trim(commandString);

  Command command = Command::Invalid;
  if(commandString.compare("PLACE") == 0)
  {
    command = Command::Place;
  }
  else if(commandString.compare("MOVE") == 0)
  {
    command = Command::Move;
  }
  else if(commandString.compare("LEFT") == 0)
  {
    command = Command::Left;
  }
  else if(commandString.compare("RIGHT") == 0)
  {
    command = Command::Right;
  }
  else if(commandString.compare("REPORT") == 0)
  {
    command = Command::Report;
  }

  return command;
}

/*static*/ std::string CommandReader::CommandValToString(CommandReader::Command command)
{
  std::string commandString;

  if(command == Command::Place)
  {
    commandString = "PLACE";
  }
  else if(command == Command::Move)
  {
    commandString = "MOVE";
  }
  else if(command == Command::Left)
  {
    commandString = "LEFT";
  }
  else if(command == Command::Right)
  {
    commandString = "RIGHT";
  }
  else if(command == Command::Report)
  {
    commandString = "REPORT";
  }

  return commandString;
}