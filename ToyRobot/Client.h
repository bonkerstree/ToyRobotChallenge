#pragma once
#include <string>
#include "RobotWorld.h"
#include "CommandConsoleReader.h"
#include "CommandFileReader.h"

void Trace(std::string prompt);
bool Execute(std::tuple<CommandReader::Command, std::vector<std::string>, std::string> commandWithArgs, RobotWorld& rw, bool fileReaderUsed = false);
void ManagePlaceCommand(const CommandReader::Command command, const std::vector<std::string>& args, RobotWorld& rw);