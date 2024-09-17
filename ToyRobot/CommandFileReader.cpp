#include "CommandFileReader.h"
#include "Utilities.h"
#include <sstream>
#include <filesystem>

CommandFileReader::CommandFileReader(std::string filename)
{
  m_InputStream.open(filename, std::fstream::in);
}

CommandFileReader::~CommandFileReader()
{
  m_InputStream.close();
}

// Retrieves the command and arguments from the command string. The command string is also returned
std::tuple<CommandReader::Command, std::vector<std::string>, std::string> CommandFileReader::GetCommand()
{
  Command command = Command::Invalid;
  std::string commandString;
  std::string argString;
  std::vector<std::string> commandArgs;

  if(!m_InputStream.is_open())
  {
    command = Command::Exit;
  }
  else
  {
    int c = m_InputStream.peek();

    if(c == EOF)
    {
      command = Command::Exit;
    }
    else
    {
      m_InputStream >> commandString;
      command = ParseCommand(commandString);
      
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
    }
  }

  return std::make_tuple(command, commandArgs, commandString + argString);
}

bool CommandFileReader::IsFileOpen()
{
  return m_InputStream.is_open();
}