#pragma once
#include "CommandReader.h"
#include <fstream>

class CommandFileReader : public CommandReader
{
public:
  CommandFileReader(std::string filename);
  ~CommandFileReader();
  std::tuple<CommandReader::Command, std::vector<std::string>, std::string> GetCommand();
  bool IsFileOpen();

private:
  std::fstream m_InputStream;
};

