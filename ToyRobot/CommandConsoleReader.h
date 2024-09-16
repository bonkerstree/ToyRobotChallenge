#pragma once
#include "CommandReader.h"
#include <memory>
#include <sstream>
#include <iostream>

class CommandConsoleReader : public CommandReader
{
public:
  CommandConsoleReader(std::stringbuf* streamBuffer = nullptr);
  ~CommandConsoleReader();
  std::pair<Command, std::vector<std::string>> virtual GetCommand();
  void SetStreamBuffer(std::stringbuf& buffer);

private:
  CommandReader::Command ParseCommand(std::string commandString);

  std::istream m_InputStream;
  std::stringbuf m_InputBuffer;
};

