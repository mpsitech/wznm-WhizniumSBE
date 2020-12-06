/**
	* \file WznmQVerBvr1NVersion.cpp
	* Dbs and XML wrapper for table TblWznmQVerBvr1NVersion (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQVerBvr1NVersion.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVerBvr1NVersion
 ******************************************************************************/

WznmQVerBvr1NVersion::WznmQVerBvr1NVersion(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void WznmQVerBvr1NVersion::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQVerBvr1NVersion";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQVerBvr1NVersion
 ******************************************************************************/

ListWznmQVerBvr1NVersion::ListWznmQVerBvr1NVersion() {
};

ListWznmQVerBvr1NVersion::ListWznmQVerBvr1NVersion(
			const ListWznmQVerBvr1NVersion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVerBvr1NVersion(*(src.nodes[i]));
};

ListWznmQVerBvr1NVersion::~ListWznmQVerBvr1NVersion() {
	clear();
};

void ListWznmQVerBvr1NVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQVerBvr1NVersion::size() const {
	return(nodes.size());
};

void ListWznmQVerBvr1NVersion::append(
			WznmQVerBvr1NVersion* rec
		) {
	nodes.push_back(rec);
};

ListWznmQVerBvr1NVersion& ListWznmQVerBvr1NVersion::operator=(
			const ListWznmQVerBvr1NVersion& src
		) {
	WznmQVerBvr1NVersion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQVerBvr1NVersion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQVerBvr1NVersion::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQVerBvr1NVersion";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQVerBvr1NVersion
 ******************************************************************************/

TblWznmQVerBvr1NVersion::TblWznmQVerBvr1NVersion() {
};

TblWznmQVerBvr1NVersion::~TblWznmQVerBvr1NVersion() {
};

bool TblWznmQVerBvr1NVersion::loadRecBySQL(
			const string& sqlstr
			, WznmQVerBvr1NVersion** rec
		) {
	return false;
};

ubigint TblWznmQVerBvr1NVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVerBvr1NVersion& rst
		) {
	return 0;
};

ubigint TblWznmQVerBvr1NVersion::insertRec(
			WznmQVerBvr1NVersion* rec
		) {
	return 0;
};

ubigint TblWznmQVerBvr1NVersion::insertNewRec(
			WznmQVerBvr1NVersion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQVerBvr1NVersion* _rec = NULL;

	_rec = new WznmQVerBvr1NVersion(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQVerBvr1NVersion::appendNewRecToRst(
			ListWznmQVerBvr1NVersion& rst
			, WznmQVerBvr1NVersion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQVerBvr1NVersion* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQVerBvr1NVersion::insertRst(
			ListWznmQVerBvr1NVersion& rst
		) {
};

void TblWznmQVerBvr1NVersion::updateRec(
			WznmQVerBvr1NVersion* rec
		) {
};

void TblWznmQVerBvr1NVersion::updateRst(
			ListWznmQVerBvr1NVersion& rst
		) {
};

void TblWznmQVerBvr1NVersion::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQVerBvr1NVersion::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQVerBvr1NVersion::loadRecByQref(
			ubigint qref
			, WznmQVerBvr1NVersion** rec
		) {
	return false;
};

ubigint TblWznmQVerBvr1NVersion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVerBvr1NVersion& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQVerBvr1NVersion
 ******************************************************************************/

MyTblWznmQVerBvr1NVersion::MyTblWznmQVerBvr1NVersion() :
			TblWznmQVerBvr1NVersion()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQVerBvr1NVersion::~MyTblWznmQVerBvr1NVersion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQVerBvr1NVersion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQVerBvr1NVersion (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQVerBvr1NVersion SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQVerBvr1NVersion WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQVerBvr1NVersion WHERE jref = ?", false);
};

bool MyTblWznmQVerBvr1NVersion::loadRecBySQL(
			const string& sqlstr
			, WznmQVerBvr1NVersion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQVerBvr1NVersion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVerBvr1NVersion::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVerBvr1NVersion::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQVerBvr1NVersion();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQVerBvr1NVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVerBvr1NVersion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQVerBvr1NVersion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVerBvr1NVersion::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVerBvr1NVersion::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQVerBvr1NVersion();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQVerBvr1NVersion::insertRec(
			WznmQVerBvr1NVersion* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQVerBvr1NVersion::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQVerBvr1NVersion::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQVerBvr1NVersion::insertRst(
			ListWznmQVerBvr1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQVerBvr1NVersion::updateRec(
			WznmQVerBvr1NVersion* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQVerBvr1NVersion::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQVerBvr1NVersion::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVerBvr1NVersion::updateRst(
			ListWznmQVerBvr1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQVerBvr1NVersion::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQVerBvr1NVersion::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQVerBvr1NVersion::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVerBvr1NVersion::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQVerBvr1NVersion::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQVerBvr1NVersion::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQVerBvr1NVersion::loadRecByQref(
			ubigint qref
			, WznmQVerBvr1NVersion** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQVerBvr1NVersion WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQVerBvr1NVersion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVerBvr1NVersion& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQVerBvr1NVersion WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQVerBvr1NVersion
 ******************************************************************************/

PgTblWznmQVerBvr1NVersion::PgTblWznmQVerBvr1NVersion() :
			TblWznmQVerBvr1NVersion()
			, PgTable()
		{
};

PgTblWznmQVerBvr1NVersion::~PgTblWznmQVerBvr1NVersion() {
};

void PgTblWznmQVerBvr1NVersion::initStatements() {
	createStatement("TblWznmQVerBvr1NVersion_insertRec", "INSERT INTO TblWznmQVerBvr1NVersion (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWznmQVerBvr1NVersion_updateRec", "UPDATE TblWznmQVerBvr1NVersion SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWznmQVerBvr1NVersion_removeRecByQref", "DELETE FROM TblWznmQVerBvr1NVersion WHERE qref = $1", 1);
	createStatement("TblWznmQVerBvr1NVersion_removeRstByJref", "DELETE FROM TblWznmQVerBvr1NVersion WHERE jref = $1", 1);

	createStatement("TblWznmQVerBvr1NVersion_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWznmQVerBvr1NVersion WHERE qref = $1", 1);
	createStatement("TblWznmQVerBvr1NVersion_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWznmQVerBvr1NVersion WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQVerBvr1NVersion::loadRec(
			PGresult* res
			, WznmQVerBvr1NVersion** rec
		) {
	char* ptr;

	WznmQVerBvr1NVersion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQVerBvr1NVersion();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQVerBvr1NVersion::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQVerBvr1NVersion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQVerBvr1NVersion* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new WznmQVerBvr1NVersion();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQVerBvr1NVersion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQVerBvr1NVersion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVerBvr1NVersion::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVerBvr1NVersion::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQVerBvr1NVersion& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVerBvr1NVersion::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQVerBvr1NVersion::loadRecBySQL(
			const string& sqlstr
			, WznmQVerBvr1NVersion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVerBvr1NVersion::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVerBvr1NVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVerBvr1NVersion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVerBvr1NVersion::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQVerBvr1NVersion::insertRec(
			WznmQVerBvr1NVersion* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQVerBvr1NVersion_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVerBvr1NVersion::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQVerBvr1NVersion::insertRst(
			ListWznmQVerBvr1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQVerBvr1NVersion::updateRec(
			WznmQVerBvr1NVersion* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQVerBvr1NVersion_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVerBvr1NVersion::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVerBvr1NVersion::updateRst(
			ListWznmQVerBvr1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQVerBvr1NVersion::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWznmQVerBvr1NVersion_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVerBvr1NVersion::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVerBvr1NVersion::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWznmQVerBvr1NVersion_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVerBvr1NVersion::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQVerBvr1NVersion::loadRecByQref(
			ubigint qref
			, WznmQVerBvr1NVersion** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmQVerBvr1NVersion_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQVerBvr1NVersion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVerBvr1NVersion& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQVerBvr1NVersion_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
