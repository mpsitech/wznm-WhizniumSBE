/**
	* \file WznmCControl.cpp
	* Dbs and XML wrapper for table TblWznmCControl (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmCControl.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWznmCControl
 ******************************************************************************/

TblWznmCControl::TblWznmCControl() {
};

TblWznmCControl::~TblWznmCControl() {
};

ubigint TblWznmCControl::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmCControl
 ******************************************************************************/

MyTblWznmCControl::MyTblWznmCControl() :
			TblWznmCControl()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWznmCControl::~MyTblWznmCControl() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWznmCControl::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWznmCControl () VALUES ()", false);
};

ubigint MyTblWznmCControl::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWznmCControl::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWznmCControl::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmCControl
 ******************************************************************************/

PgTblWznmCControl::PgTblWznmCControl() :
			TblWznmCControl()
			, PgTable()
		{
};

PgTblWznmCControl::~PgTblWznmCControl() {
};

void PgTblWznmCControl::initStatements() {
	createStatement("TblWznmCControl_getNewRef", "SELECT nextval('TblWznmCControl')", 0);
};

ubigint PgTblWznmCControl::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWznmCControl_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmCControl::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif

