/**
	* \file WznmCRelation.cpp
	* Dbs and XML wrapper for table TblWznmCRelation (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmCRelation.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWznmCRelation
 ******************************************************************************/

TblWznmCRelation::TblWznmCRelation() {
};

TblWznmCRelation::~TblWznmCRelation() {
};

ubigint TblWznmCRelation::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmCRelation
 ******************************************************************************/

MyTblWznmCRelation::MyTblWznmCRelation() :
			TblWznmCRelation()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWznmCRelation::~MyTblWznmCRelation() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWznmCRelation::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWznmCRelation () VALUES ()", false);
};

ubigint MyTblWznmCRelation::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWznmCRelation::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWznmCRelation::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmCRelation
 ******************************************************************************/

PgTblWznmCRelation::PgTblWznmCRelation() :
			TblWznmCRelation()
			, PgTable()
		{
};

PgTblWznmCRelation::~PgTblWznmCRelation() {
};

void PgTblWznmCRelation::initStatements() {
	createStatement("TblWznmCRelation_getNewRef", "SELECT nextval('TblWznmCRelation')", 0);
};

ubigint PgTblWznmCRelation::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWznmCRelation_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmCRelation::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif

