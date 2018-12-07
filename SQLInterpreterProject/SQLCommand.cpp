#include "SQLCommand.h"

SQLCommand::SQLCommand()
{
	command = "dummycommand";
}

SQLCommand::SQLCommand(std::string Command)
{
	command = Command;
}

std::string SQLCommand::getCommand()
{
	return command;
}

void SQLCommand::setCommand(std::string Command)
{
	command = Command;
}
