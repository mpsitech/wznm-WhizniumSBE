/**
	* \file WznmCAMOppackInvarg.cpp
	* Dbs and XML wrapper for table TblWznmCAMOppackInvarg (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmCAMOppackInvarg.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWznmCAMOppackInvarg
 ******************************************************************************/

TblWznmCAMOppackInvarg::TblWznmCAMOppackInvarg() {
};

TblWznmCAMOppackInvarg::~TblWznmCAMOppackInvarg() {
};

ubigint TblWznmCAMOppackInvarg::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmCAMOppackInvarg
 ******************************************************************************/

MyTblWznmCAMOppackInvarg::MyTblWznmCAMOppackInvarg() :
			TblWznmCAMOppackInvarg()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWznmCAMOppackInvarg::~MyTblWznmCAMOppackInvarg() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWznmCAMOppackInvarg::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWznmCAMOppackInvarg () VALUES ()", false);
};

ubigint MyTblWznmCAMOppackInvarg::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWznmCAMOppackInvarg::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWznmCAMOppackInvarg::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmCAMOppackInvarg
 ******************************************************************************/

PgTblWznmCAMOppackInvarg::PgTblWznmCAMOppackInvarg() :
			TblWznmCAMOppackInvarg()
			, PgTable()
		{
};

PgTblWznmCAMOppackInvarg::~PgTblWznmCAMOppackInvarg() {
};

void PgTblWznmCAMOppackInvarg::initStatements() {
	createStatement("TblWznmCAMOppackInvarg_getNewRef", "SELECT nextval('TblWznmCAMOppackInvarg')", 0);
};

ubigint PgTblWznmCAMOppackInvarg::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWznmCAMOppackInvarg_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmCAMOppackInvarg::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif

