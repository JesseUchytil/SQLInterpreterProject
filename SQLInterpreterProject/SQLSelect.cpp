#include "SQLSelect.h"

SQLSelect::SQLSelect() : SQLCommand("select")
{

}

void SQLSelect::addColumn(column Column)
{
	columns.push_back(Column);
}

void SQLSelect::setColumns(std::vector<column> Columns)
{
	columns = Columns;
}

void SQLSelect::setFrom(SQLFrom toSet)
{
	from = toSet;
}
