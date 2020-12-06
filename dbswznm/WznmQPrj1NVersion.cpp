/**
	* \file WznmQPrj1NVersion.cpp
	* Dbs and XML wrapper for table TblWznmQPrj1NVersion (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQPrj1NVersion.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQPrj1NVersion
 ******************************************************************************/

WznmQPrj1NVersion::WznmQPrj1NVersion(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint prjNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->prjNum = prjNum;
};

void WznmQPrj1NVersion::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQPrj1NVersion";

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
 class ListWznmQPrj1NVersion
 ******************************************************************************/

ListWznmQPrj1NVersion::ListWznmQPrj1NVersion() {
};

ListWznmQPrj1NVersion::ListWznmQPrj1NVersion(
			const ListWznmQPrj1NVersion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPrj1NVersion(*(src.nodes[i]));
};

ListWznmQPrj1NVersion::~ListWznmQPrj1NVersion() {
	clear();
};

void ListWznmQPrj1NVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQPrj1NVersion::size() const {
	return(nodes.size());
};

void ListWznmQPrj1NVersion::append(
			WznmQPrj1NVersion* rec
		) {
	nodes.push_back(rec);
};

ListWznmQPrj1NVersion& ListWznmQPrj1NVersion::operator=(
			const ListWznmQPrj1NVersion& src
		) {
	WznmQPrj1NVersion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQPrj1NVersion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQPrj1NVersion::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQPrj1NVersion";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQPrj1NVersion
 ******************************************************************************/

TblWznmQPrj1NVersion::TblWznmQPrj1NVersion() {
};

TblWznmQPrj1NVersion::~TblWznmQPrj1NVersion() {
};

bool TblWznmQPrj1NVersion::loadRecBySQL(
			const string& sqlstr
			, WznmQPrj1NVersion** rec
		) {
	return false;
};

ubigint TblWznmQPrj1NVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPrj1NVersion& rst
		) {
	return 0;
};

ubigint TblWznmQPrj1NVersion::insertRec(
			WznmQPrj1NVersion* rec
		) {
	return 0;
};

ubigint TblWznmQPrj1NVersion::insertNewRec(
			WznmQPrj1NVersion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint prjNum
		) {
	ubigint retval = 0;
	WznmQPrj1NVersion* _rec = NULL;

	_rec = new WznmQPrj1NVersion(0, jref, jnum, ref, stubRef, prjNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQPrj1NVersion::appendNewRecToRst(
			ListWznmQPrj1NVersion& rst
			, WznmQPrj1NVersion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint prjNum
		) {
	ubigint retval = 0;
	WznmQPrj1NVersion* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, prjNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQPrj1NVersion::insertRst(
			ListWznmQPrj1NVersion& rst
		) {
};

void TblWznmQPrj1NVersion::updateRec(
			WznmQPrj1NVersion* rec
		) {
};

void TblWznmQPrj1NVersion::updateRst(
			ListWznmQPrj1NVersion& rst
		) {
};

void TblWznmQPrj1NVersion::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQPrj1NVersion::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQPrj1NVersion::loadRecByQref(
			ubigint qref
			, WznmQPrj1NVersion** rec
		) {
	return false;
};

ubigint TblWznmQPrj1NVersion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPrj1NVersion& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQPrj1NVersion
 ******************************************************************************/

MyTblWznmQPrj1NVersion::MyTblWznmQPrj1NVersion() :
			TblWznmQPrj1NVersion()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQPrj1NVersion::~MyTblWznmQPrj1NVersion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQPrj1NVersion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQPrj1NVersion (jref, jnum, ref, prjNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQPrj1NVersion SET jref = ?, jnum = ?, ref = ?, prjNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQPrj1NVersion WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQPrj1NVersion WHERE jref = ?", false);
};

bool MyTblWznmQPrj1NVersion::loadRecBySQL(
			const string& sqlstr
			, WznmQPrj1NVersion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQPrj1NVersion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQPrj1NVersion::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQPrj1NVersion::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQPrj1NVersion();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->prjNum = atol((char*) dbrow[4]); else _rec->prjNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQPrj1NVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPrj1NVersion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQPrj1NVersion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQPrj1NVersion::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQPrj1NVersion::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQPrj1NVersion();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->prjNum = atol((char*) dbrow[4]); else rec->prjNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQPrj1NVersion::insertRec(
			WznmQPrj1NVersion* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->prjNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQPrj1NVersion::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQPrj1NVersion::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQPrj1NVersion::insertRst(
			ListWznmQPrj1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQPrj1NVersion::updateRec(
			WznmQPrj1NVersion* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->prjNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQPrj1NVersion::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQPrj1NVersion::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQPrj1NVersion::updateRst(
			ListWznmQPrj1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQPrj1NVersion::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQPrj1NVersion::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQPrj1NVersion::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQPrj1NVersion::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQPrj1NVersion::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQPrj1NVersion::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQPrj1NVersion::loadRecByQref(
			ubigint qref
			, WznmQPrj1NVersion** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQPrj1NVersion WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQPrj1NVersion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPrj1NVersion& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQPrj1NVersion WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQPrj1NVersion
 ******************************************************************************/

PgTblWznmQPrj1NVersion::PgTblWznmQPrj1NVersion() :
			TblWznmQPrj1NVersion()
			, PgTable()
		{
};

PgTblWznmQPrj1NVersion::~PgTblWznmQPrj1NVersion() {
};

void PgTblWznmQPrj1NVersion::initStatements() {
	createStatement("TblWznmQPrj1NVersion_insertRec", "INSERT INTO TblWznmQPrj1NVersion (jref, jnum, ref, prjNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQPrj1NVersion_updateRec", "UPDATE TblWznmQPrj1NVersion SET jref = $1, jnum = $2, ref = $3, prjNum = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQPrj1NVersion_removeRecByQref", "DELETE FROM TblWznmQPrj1NVersion WHERE qref = $1", 1);
	createStatement("TblWznmQPrj1NVersion_removeRstByJref", "DELETE FROM TblWznmQPrj1NVersion WHERE jref = $1", 1);

	createStatement("TblWznmQPrj1NVersion_loadRecByQref", "SELECT qref, jref, jnum, ref, prjNum FROM TblWznmQPrj1NVersion WHERE qref = $1", 1);
	createStatement("TblWznmQPrj1NVersion_loadRstByJref", "SELECT qref, jref, jnum, ref, prjNum FROM TblWznmQPrj1NVersion WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQPrj1NVersion::loadRec(
			PGresult* res
			, WznmQPrj1NVersion** rec
		) {
	char* ptr;

	WznmQPrj1NVersion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQPrj1NVersion();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "prjnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->prjNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQPrj1NVersion::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQPrj1NVersion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQPrj1NVersion* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "prjnum")
		};

		while (numread < numrow) {
			rec = new WznmQPrj1NVersion();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->prjNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQPrj1NVersion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQPrj1NVersion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPrj1NVersion::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQPrj1NVersion::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQPrj1NVersion& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPrj1NVersion::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQPrj1NVersion::loadRecBySQL(
			const string& sqlstr
			, WznmQPrj1NVersion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQPrj1NVersion::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQPrj1NVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPrj1NVersion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQPrj1NVersion::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQPrj1NVersion::insertRec(
			WznmQPrj1NVersion* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _prjNum = htonl(rec->prjNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_prjNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQPrj1NVersion_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPrj1NVersion::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQPrj1NVersion::insertRst(
			ListWznmQPrj1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQPrj1NVersion::updateRec(
			WznmQPrj1NVersion* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _prjNum = htonl(rec->prjNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_prjNum,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQPrj1NVersion_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPrj1NVersion::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQPrj1NVersion::updateRst(
			ListWznmQPrj1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQPrj1NVersion::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQPrj1NVersion_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPrj1NVersion::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQPrj1NVersion::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQPrj1NVersion_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPrj1NVersion::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQPrj1NVersion::loadRecByQref(
			ubigint qref
			, WznmQPrj1NVersion** rec
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

	return loadRecByStmt("TblWznmQPrj1NVersion_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQPrj1NVersion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPrj1NVersion& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQPrj1NVersion_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
