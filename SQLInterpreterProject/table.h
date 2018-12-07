#pragma once
#include <string>

class table {
private:
	std::string tableName;
	std::string tableAlias;
public:
	table();
	void setTableName(std::string TableName);
	std::string getTableName();
	void setTableAlias(std::string TableAlias);
	std::string getTableAlias();
};