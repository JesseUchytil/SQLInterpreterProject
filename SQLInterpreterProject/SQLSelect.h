#pragma once
#include <string>
#include <vector>
#include "SQLCommand.h"
#include "column.h"
#include "SQLFrom.h"

class SQLSelect : public SQLCommand {
private:
	std::vector<column> columns;
	SQLFrom from;
public:
	friend class SQLFrom;
	friend class column;
	SQLSelect();
	void addColumn(column Column);
	void setColumns(std::vector<column> Columns);
	void setFrom(SQLFrom toSet);
};
