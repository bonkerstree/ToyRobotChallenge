#pragma once
#include <string>
#include "RobotWorld.h"
#include "CommandConsoleReader.h"

void Prompt(std::string prompt);
void Execute(std::pair<CommandReader::Command, std::vector<std::string>> commandWithArgs, RobotWorld& rw);
void ManagePlaceCommand(const CommandReader::Command command, const std::vector<std::string>& args, RobotWorld& rw);