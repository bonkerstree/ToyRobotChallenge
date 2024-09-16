#include "CommandConsoleReader.h"
#include "Utilities.h"

CommandConsoleReader::CommandConsoleReader(std::stringbuf* streamBuffer):
  m_InputStream(std::cin.rdbuf())
{
}

CommandConsoleReader::~CommandConsoleReader()
{
  
}

std::pair<CommandReader::Command, std::vector<std::string>> CommandConsoleReader::GetCommand()
{
  std::string commandString;
  m_InputStream >> commandString;
  Command command = ParseCommand(commandString);
  
  std::vector<std::string> commandArgs;
  std::string argString;
  std::getline(m_InputStream, argString);
  if(command != Command::Invalid)
  {
    std::stringstream tempStream(argString);
    std::string arg;
    while(std::getline(tempStream, arg, ','))
    {
      Util::toupper(arg);
      Util::trim(arg);
      if(!arg.empty())
      {
        commandArgs.push_back(arg);
      }
    }
  }

  return std::make_pair(command, commandArgs);
}

void CommandConsoleReader::SetStreamBuffer(std::stringbuf& buffer)
{
  m_InputStream.rdbuf(&buffer);
}

CommandReader::Command CommandConsoleReader::ParseCommand(std::string commandString)
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