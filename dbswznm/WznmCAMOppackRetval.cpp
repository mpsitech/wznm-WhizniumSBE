/**
	* \file WznmCAMOppackRetval.cpp
	* Dbs and XML wrapper for table TblWznmCAMOppackRetval (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmCAMOppackRetval.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWznmCAMOppackRetval
 ******************************************************************************/

TblWznmCAMOppackRetval::TblWznmCAMOppackRetval() {
};

TblWznmCAMOppackRetval::~TblWznmCAMOppackRetval() {
};

ubigint TblWznmCAMOppackRetval::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmCAMOppackRetval
 ******************************************************************************/

MyTblWznmCAMOppackRetval::MyTblWznmCAMOppackRetval() :
			TblWznmCAMOppackRetval()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWznmCAMOppackRetval::~MyTblWznmCAMOppackRetval() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWznmCAMOppackRetval::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWznmCAMOppackRetval () VALUES ()", false);
};

ubigint MyTblWznmCAMOppackRetval::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWznmCAMOppackRetval::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWznmCAMOppackRetval::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmCAMOppackRetval
 ******************************************************************************/

PgTblWznmCAMOppackRetval::PgTblWznmCAMOppackRetval() :
			TblWznmCAMOppackRetval()
			, PgTable()
		{
};

PgTblWznmCAMOppackRetval::~PgTblWznmCAMOppackRetval() {
};

void PgTblWznmCAMOppackRetval::initStatements() {
	createStatement("TblWznmCAMOppackRetval_getNewRef", "SELECT nextval('TblWznmCAMOppackRetval')", 0);
};

ubigint PgTblWznmCAMOppackRetval::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWznmCAMOppackRetval_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmCAMOppackRetval::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif

