#include "CommandConsoleReader.h"
#include "Utilities.h"

CommandConsoleReader::CommandConsoleReader():
  m_InputStream(std::cin.rdbuf())
{
}

CommandConsoleReader::~CommandConsoleReader()
{
}

// Retrieves the command and arguments from the command string. The command string is also returned
std::tuple<CommandReader::Command, std::vector<std::string>, std::string> CommandConsoleReader::GetCommand()
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

  return std::make_tuple(command, commandArgs, commandString + argString);
}

// Replaces the buffer used in the stream. Currently only used for testing the console input
void CommandConsoleReader::SetStreamBuffer(std::stringbuf& buffer)
{
  m_InputStream.rdbuf(&buffer);
}