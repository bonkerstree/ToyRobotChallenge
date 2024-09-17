#pragma once
#include "CommandReader.h"
#include <memory>
#include <sstream>
#include <iostream>

class CommandConsoleReader : public CommandReader
{
public:
  CommandConsoleReader();
  ~CommandConsoleReader();
  std::tuple<Command, std::vector<std::string>, std::string> virtual GetCommand();
  void SetStreamBuffer(std::stringbuf& buffer);

private:
  std::istream m_InputStream;
  std::stringbuf m_InputBuffer;
};

