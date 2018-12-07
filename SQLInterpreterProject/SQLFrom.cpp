#include "SQLFrom.h"

SQLFrom::SQLFrom() : SQLCommand("FROM")
{
}

void SQLFrom::addTable(table Table)
{
	tables.push_back(Table);
}

void SQLFrom::setTables(std::vector<table> Tables)
{
	tables = Tables;
}
