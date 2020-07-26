/**
	* \file WznmCAMBlockItem.cpp
	* Dbs and XML wrapper for table TblWznmCAMBlockItem (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmCAMBlockItem.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWznmCAMBlockItem
 ******************************************************************************/

TblWznmCAMBlockItem::TblWznmCAMBlockItem() {
};

TblWznmCAMBlockItem::~TblWznmCAMBlockItem() {
};

ubigint TblWznmCAMBlockItem::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmCAMBlockItem
 ******************************************************************************/

MyTblWznmCAMBlockItem::MyTblWznmCAMBlockItem() :
			TblWznmCAMBlockItem()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWznmCAMBlockItem::~MyTblWznmCAMBlockItem() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWznmCAMBlockItem::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWznmCAMBlockItem () VALUES ()", false);
};

ubigint MyTblWznmCAMBlockItem::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWznmCAMBlockItem::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWznmCAMBlockItem::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmCAMBlockItem
 ******************************************************************************/

PgTblWznmCAMBlockItem::PgTblWznmCAMBlockItem() :
			TblWznmCAMBlockItem()
			, PgTable()
		{
};

PgTblWznmCAMBlockItem::~PgTblWznmCAMBlockItem() {
};

void PgTblWznmCAMBlockItem::initStatements() {
	createStatement("TblWznmCAMBlockItem_getNewRef", "SELECT nextval('TblWznmCAMBlockItem')", 0);
};

ubigint PgTblWznmCAMBlockItem::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWznmCAMBlockItem_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmCAMBlockItem::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif

