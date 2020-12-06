/**
	* \file WznmCFile.cpp
	* Dbs and XML wrapper for table TblWznmCFile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmCFile.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWznmCFile
 ******************************************************************************/

TblWznmCFile::TblWznmCFile() {
};

TblWznmCFile::~TblWznmCFile() {
};

ubigint TblWznmCFile::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmCFile
 ******************************************************************************/

MyTblWznmCFile::MyTblWznmCFile() :
			TblWznmCFile()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWznmCFile::~MyTblWznmCFile() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWznmCFile::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWznmCFile () VALUES ()", false);
};

ubigint MyTblWznmCFile::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWznmCFile::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWznmCFile::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmCFile
 ******************************************************************************/

PgTblWznmCFile::PgTblWznmCFile() :
			TblWznmCFile()
			, PgTable()
		{
};

PgTblWznmCFile::~PgTblWznmCFile() {
};

void PgTblWznmCFile::initStatements() {
	createStatement("TblWznmCFile_getNewRef", "SELECT nextval('TblWznmCFile')", 0);
};

ubigint PgTblWznmCFile::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWznmCFile_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmCFile::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif
