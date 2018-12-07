#pragma once
#include <string>

class column {
private:
	std::string columnName;
	std::string columnAlias;
	std::string columnTable;
public:
	column();
	void setColumnName(std::string ColumnName);
	std::string getColumnName();
	void setColumnAlias(std::string ColumnAlias);
	std::string getColumnAlias();
	void setColumnTable(std::string ColumnTable);
	std::string getColumnTable();
};
