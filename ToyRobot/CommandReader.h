#pragma once
#include <vector>
#include <string>

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
    Report
  };

  CommandReader(){};
  ~CommandReader(){};

  std::pair<Command, std::vector<std::string>> virtual GetCommand() = 0;
};