#pragma once
#include <string>

class SQLCommand {
private:
	std::string command;
public:
	SQLCommand();
	SQLCommand(std::string Command);
	std::string getCommand();
	void setCommand(std::string Command);
};