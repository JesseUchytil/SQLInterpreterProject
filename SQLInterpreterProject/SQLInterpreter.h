#include <string>
#include <vector>

#include "SQLCommand.h"
#include "SQLFrom.h"
#include "SQLSelect.h"

class SQLInterpreter {
private:
	std::vector<SQLCommand> SQLCommands;
	void cleanInput();
	std::string input;
	SQLCommand parseNextCommand();
	SQLCommand parseSelectCommand();
	column parseColumn(std::string toParse);
	table parseTable(std::string toParse);
	bool hasNextCommand();
public:
	SQLInterpreter();
	std::vector<SQLCommand> getSQLCommandsFromString(std::string Input);
	std::string getInput();
	
};