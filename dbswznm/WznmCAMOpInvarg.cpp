/**
	* \file WznmCAMOpInvarg.cpp
	* Dbs and XML wrapper for table TblWznmCAMOpInvarg (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmCAMOpInvarg.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWznmCAMOpInvarg
 ******************************************************************************/

TblWznmCAMOpInvarg::TblWznmCAMOpInvarg() {
};

TblWznmCAMOpInvarg::~TblWznmCAMOpInvarg() {
};

ubigint TblWznmCAMOpInvarg::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmCAMOpInvarg
 ******************************************************************************/

MyTblWznmCAMOpInvarg::MyTblWznmCAMOpInvarg() :
			TblWznmCAMOpInvarg()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWznmCAMOpInvarg::~MyTblWznmCAMOpInvarg() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWznmCAMOpInvarg::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWznmCAMOpInvarg () VALUES ()", false);
};

ubigint MyTblWznmCAMOpInvarg::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWznmCAMOpInvarg::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWznmCAMOpInvarg::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmCAMOpInvarg
 ******************************************************************************/

PgTblWznmCAMOpInvarg::PgTblWznmCAMOpInvarg() :
			TblWznmCAMOpInvarg()
			, PgTable()
		{
};

PgTblWznmCAMOpInvarg::~PgTblWznmCAMOpInvarg() {
};

void PgTblWznmCAMOpInvarg::initStatements() {
	createStatement("TblWznmCAMOpInvarg_getNewRef", "SELECT nextval('TblWznmCAMOpInvarg')", 0);
};

ubigint PgTblWznmCAMOpInvarg::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWznmCAMOpInvarg_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmCAMOpInvarg::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif
