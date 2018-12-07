#pragma once
#include <vector>
#include "SQLCommand.h"
#include "table.h"


class SQLFrom : public SQLCommand {
private:
	std::vector<table> tables;
public:
	SQLFrom();
	void addTable(table Table);
	void setTables(std::vector<table> Tables);
};