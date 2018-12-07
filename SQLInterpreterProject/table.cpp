#include "table.h"

table::table()
{
}

void table::setTableName(std::string TableName)
{
	tableName = TableName;
}

std::string table::getTableName()
{
	return tableName;
}

void table::setTableAlias(std::string TableAlias)
{
	tableAlias = TableAlias;
}

std::string table::getTableAlias()
{
	return tableAlias;
}
