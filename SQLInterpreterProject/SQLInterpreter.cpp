#include "SQLInterpreter.h"

void SQLInterpreter::cleanInput()
{
	bool escaped = false;//for determinining if character is escaped
	char previous;//for holding which character was used to enter escaped mode.

	for (char& c : input) {
		if (!escaped) {//if not escaped...
			if (c == '\'' || c == '"') {//If character begins a quote...
				previous = c;//set previous
				escaped = true;//and start 'escaped' mode, where characters are ignored.
			}
			else {//otherwise...
				switch (c)//enter switch that changes uppercase characters to lowercase
				{
				case 'A': 
					c = 'a';
					break;
				case 'B':
					c = 'b';
					break;
				case 'C':
					c = 'c';
					break;
				case 'D':
					c = 'd';
					break;
				case 'E':
					c = 'e';
					break;
				case 'F':
					c = 'f';
					break;
				case 'G':
					c = 'g';
					break;
				case 'H':
					c = 'h';
					break;
				case 'I':
					c = 'i';
					break;
				case 'J':
					c = 'j';
					break;
				case 'K':
					c = 'k';
					break;
				case 'L':
					c = 'l';
					break;
				case 'M':
					c = 'm';
					break;
				case 'N':
					c = 'n';
					break;
				case 'O':
					c = 'o';
					break;
				case 'P':
					c = 'p';
					break;
				case 'Q':
					c = 'q';
					break;
				case 'R':
					c = 'r';
					break;
				case 'S':
					c = 's';
					break;
				case 'T':
					c = 't';
					break;
				case 'U':
					c = 'u';
					break;
				case 'V':
					c = 'v';
					break;
				case 'W':
					c = 'w';
					break;
				case 'X':
					c = 'x';
					break;
				case 'Y':
					c = 'y';
					break;
				case 'Z':
					c = 'z';
					break;
				default:
					break;
				}
			}
		}
		else {//if in escaped mode
			if (c == previous) {//if current character matches escaped section opening...
				escaped = false;//end escaped section.
			}
		};
	}
}

SQLCommand SQLInterpreter::parseNextCommand()
{
	SQLCommand command;
	if (input.substr(0, 6) == "select") {
		command = parseSelectCommand();
	}
	return command;
}

SQLCommand SQLInterpreter::parseSelectCommand()
{
	SQLSelect command;
	SQLFrom fromCommand;
	column columnToAdd;
	table tableToAdd;
	input = input.substr(6);//drop the 'select'
	while (input.substr(0, 6) != " from ") {//add in all columns
		while (input.substr(0, 1) == " ") {
			input = input.substr(1);
		}
		if (input.substr(0, input.find(" from ")).find(", ") != std::string::npos) {
			columnToAdd = parseColumn(input.substr(0, input.find(", ")));
			input = input.substr(input.find(", ") + 2);
		}
		else {
			columnToAdd = parseColumn(input.substr(0, input.find(" from ")));
			input = input.substr(input.find(" from "));
		}
		command.addColumn(columnToAdd);
	}
	input = input.substr(6);//drop the ' from '
	while (input.substr(0, 1) != ";" && input.substr(0,6) != "where ") {
		while (input.substr(0, 1) == " ") {
			input = input.substr(1);
		}
		if (input.find(" where ") != std::string::npos) {
			if (input.substr(0, input.find(" where ")).find(", ") != std::string::npos) {
				tableToAdd = parseTable(input.substr(0, input.find(", ")));
				input = input.substr(input.find(", ") + 2);
			}
			else {
				tableToAdd = parseTable(input.substr(0, input.find(" where ")));
				input = input.substr(input.find(" where "));
			}
		}
		else {
			if (input.substr(0, input.find(";")).find(", ") != std::string::npos) {
				tableToAdd = parseTable(input.substr(0, input.find(", ")));
				input = input.substr(input.find(", ") + 2);
			}
			else {
				tableToAdd = parseTable(input.substr(0, input.find(";")));
				input = input.substr(input.find(";"));
			}
		}
		fromCommand.addTable(tableToAdd);
	}
	command.setFrom(fromCommand);
	return command;
}

column SQLInterpreter::parseColumn(std::string toParse)
{
	return column();
}

table SQLInterpreter::parseTable(std::string toParse)
{
	return table();
}

bool SQLInterpreter::hasNextCommand()
{
	if (input.substr(0, 1) != " ") {
		if (input.substr(0, 6) == "select") {
			return true;
		}
	}
	return false;
}

SQLInterpreter::SQLInterpreter()
{
	input = "";
}

std::vector<SQLCommand> SQLInterpreter::getSQLCommandsFromString(std::string Input)
{
	input = Input;
	cleanInput();
	while (hasNextCommand()) {
		SQLCommands.push_back(parseNextCommand());
	}
	return SQLCommands;
}

std::string SQLInterpreter::getInput()
{
	return input;
}
