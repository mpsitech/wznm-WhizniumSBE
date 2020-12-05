/**
	* \file WznmCAMJobVar.cpp
	* Dbs and XML wrapper for table TblWznmCAMJobVar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmCAMJobVar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWznmCAMJobVar
 ******************************************************************************/

TblWznmCAMJobVar::TblWznmCAMJobVar() {
};

TblWznmCAMJobVar::~TblWznmCAMJobVar() {
};

ubigint TblWznmCAMJobVar::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmCAMJobVar
 ******************************************************************************/

MyTblWznmCAMJobVar::MyTblWznmCAMJobVar() :
			TblWznmCAMJobVar()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWznmCAMJobVar::~MyTblWznmCAMJobVar() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWznmCAMJobVar::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWznmCAMJobVar () VALUES ()", false);
};

ubigint MyTblWznmCAMJobVar::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWznmCAMJobVar::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWznmCAMJobVar::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmCAMJobVar
 ******************************************************************************/

PgTblWznmCAMJobVar::PgTblWznmCAMJobVar() :
			TblWznmCAMJobVar()
			, PgTable()
		{
};

PgTblWznmCAMJobVar::~PgTblWznmCAMJobVar() {
};

void PgTblWznmCAMJobVar::initStatements() {
	createStatement("TblWznmCAMJobVar_getNewRef", "SELECT nextval('TblWznmCAMJobVar')", 0);
};

ubigint PgTblWznmCAMJobVar::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWznmCAMJobVar_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmCAMJobVar::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif

