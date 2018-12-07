#include "column.h"

column::column()
{
}

void column::setColumnName(std::string ColumnName)
{
	columnName = ColumnName;
}

std::string column::getColumnName()
{
	return columnName;
}

void column::setColumnAlias(std::string ColumnAlias)
{
	columnAlias = ColumnAlias;
}

std::string column::getColumnAlias()
{
	return columnAlias;
}

void column::setColumnTable(std::string ColumnTable)
{
	columnTable = ColumnTable;
}

std::string column::getColumnTable()
{
	return columnTable;
}
