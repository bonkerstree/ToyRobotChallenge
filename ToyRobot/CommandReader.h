#pragma once
#include <vector>
#include <string>
#include <tuple>

class CommandReader
{
public:
  enum class Command
  {
    Invalid,
    Place,
    Move,
    Left,
    Right,
    Report,
    Exit
  };

  CommandReader(){};
  ~CommandReader(){};

  std::tuple<Command, std::vector<std::string>, std::string> virtual GetCommand() = 0;
  static std::string CommandValToString(CommandReader::Command command);

protected:
  CommandReader::Command ParseCommand(std::string commandString);
};