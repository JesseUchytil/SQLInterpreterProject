#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "SQLInterpreter.h"
#include "SQLCommand.h"
#include "SQLFrom.h"
#include "SQLSelect.h"
#include "table.h"
#include "column.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	string command = "SELECT * FROM asdf;";
	SQLInterpreter interpreter;
	vector<SQLCommand> commands;
	commands = interpreter.getSQLCommandsFromString(command);
	cin >> command;
	return 0;
}