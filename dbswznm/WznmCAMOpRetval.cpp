/**
	* \file WznmCAMOpRetval.cpp
	* Dbs and XML wrapper for table TblWznmCAMOpRetval (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmCAMOpRetval.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWznmCAMOpRetval
 ******************************************************************************/

TblWznmCAMOpRetval::TblWznmCAMOpRetval() {
};

TblWznmCAMOpRetval::~TblWznmCAMOpRetval() {
};

ubigint TblWznmCAMOpRetval::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmCAMOpRetval
 ******************************************************************************/

MyTblWznmCAMOpRetval::MyTblWznmCAMOpRetval() :
			TblWznmCAMOpRetval()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWznmCAMOpRetval::~MyTblWznmCAMOpRetval() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWznmCAMOpRetval::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWznmCAMOpRetval () VALUES ()", false);
};

ubigint MyTblWznmCAMOpRetval::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWznmCAMOpRetval::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWznmCAMOpRetval::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmCAMOpRetval
 ******************************************************************************/

PgTblWznmCAMOpRetval::PgTblWznmCAMOpRetval() :
			TblWznmCAMOpRetval()
			, PgTable()
		{
};

PgTblWznmCAMOpRetval::~PgTblWznmCAMOpRetval() {
};

void PgTblWznmCAMOpRetval::initStatements() {
	createStatement("TblWznmCAMOpRetval_getNewRef", "SELECT nextval('TblWznmCAMOpRetval')", 0);
};

ubigint PgTblWznmCAMOpRetval::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWznmCAMOpRetval_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmCAMOpRetval::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif

