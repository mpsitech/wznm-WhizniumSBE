/**
	* \file WznmQImeHk1NVector.cpp
	* Dbs and XML wrapper for table TblWznmQImeHk1NVector (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQImeHk1NVector.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQImeHk1NVector
 ******************************************************************************/

WznmQImeHk1NVector::WznmQImeHk1NVector(
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

void WznmQImeHk1NVector::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["ref"] = stubRef;
	} else {
		me["stubRef"] = stubRef;
	};
};

void WznmQImeHk1NVector::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQImeHk1NVector";

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
 class ListWznmQImeHk1NVector
 ******************************************************************************/

ListWznmQImeHk1NVector::ListWznmQImeHk1NVector() {
};

ListWznmQImeHk1NVector::ListWznmQImeHk1NVector(
			const ListWznmQImeHk1NVector& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQImeHk1NVector(*(src.nodes[i]));
};

ListWznmQImeHk1NVector::~ListWznmQImeHk1NVector() {
	clear();
};

void ListWznmQImeHk1NVector::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQImeHk1NVector::size() const {
	return(nodes.size());
};

void ListWznmQImeHk1NVector::append(
			WznmQImeHk1NVector* rec
		) {
	nodes.push_back(rec);
};

ListWznmQImeHk1NVector& ListWznmQImeHk1NVector::operator=(
			const ListWznmQImeHk1NVector& src
		) {
	WznmQImeHk1NVector* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQImeHk1NVector(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQImeHk1NVector::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQImeHk1NVector";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQImeHk1NVector::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQImeHk1NVector";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQImeHk1NVector
 ******************************************************************************/

TblWznmQImeHk1NVector::TblWznmQImeHk1NVector() {
};

TblWznmQImeHk1NVector::~TblWznmQImeHk1NVector() {
};

bool TblWznmQImeHk1NVector::loadRecBySQL(
			const string& sqlstr
			, WznmQImeHk1NVector** rec
		) {
	return false;
};

ubigint TblWznmQImeHk1NVector::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQImeHk1NVector& rst
		) {
	return 0;
};

ubigint TblWznmQImeHk1NVector::insertRec(
			WznmQImeHk1NVector* rec
		) {
	return 0;
};

ubigint TblWznmQImeHk1NVector::insertNewRec(
			WznmQImeHk1NVector** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQImeHk1NVector* _rec = NULL;

	_rec = new WznmQImeHk1NVector(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQImeHk1NVector::appendNewRecToRst(
			ListWznmQImeHk1NVector& rst
			, WznmQImeHk1NVector** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQImeHk1NVector* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQImeHk1NVector::insertRst(
			ListWznmQImeHk1NVector& rst
		) {
};

void TblWznmQImeHk1NVector::updateRec(
			WznmQImeHk1NVector* rec
		) {
};

void TblWznmQImeHk1NVector::updateRst(
			ListWznmQImeHk1NVector& rst
		) {
};

void TblWznmQImeHk1NVector::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQImeHk1NVector::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQImeHk1NVector::loadRecByQref(
			ubigint qref
			, WznmQImeHk1NVector** rec
		) {
	return false;
};

ubigint TblWznmQImeHk1NVector::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQImeHk1NVector& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQImeHk1NVector
 ******************************************************************************/

MyTblWznmQImeHk1NVector::MyTblWznmQImeHk1NVector() :
			TblWznmQImeHk1NVector()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQImeHk1NVector::~MyTblWznmQImeHk1NVector() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQImeHk1NVector::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQImeHk1NVector (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQImeHk1NVector SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQImeHk1NVector WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQImeHk1NVector WHERE jref = ?", false);
};

bool MyTblWznmQImeHk1NVector::loadRecBySQL(
			const string& sqlstr
			, WznmQImeHk1NVector** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQImeHk1NVector* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQImeHk1NVector::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQImeHk1NVector::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQImeHk1NVector();

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

ubigint MyTblWznmQImeHk1NVector::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQImeHk1NVector& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQImeHk1NVector* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQImeHk1NVector::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQImeHk1NVector::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQImeHk1NVector();

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

ubigint MyTblWznmQImeHk1NVector::insertRec(
			WznmQImeHk1NVector* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQImeHk1NVector::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQImeHk1NVector::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQImeHk1NVector::insertRst(
			ListWznmQImeHk1NVector& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQImeHk1NVector::updateRec(
			WznmQImeHk1NVector* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQImeHk1NVector::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQImeHk1NVector::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQImeHk1NVector::updateRst(
			ListWznmQImeHk1NVector& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQImeHk1NVector::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQImeHk1NVector::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQImeHk1NVector::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQImeHk1NVector::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQImeHk1NVector::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQImeHk1NVector::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQImeHk1NVector::loadRecByQref(
			ubigint qref
			, WznmQImeHk1NVector** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQImeHk1NVector WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQImeHk1NVector::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQImeHk1NVector& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQImeHk1NVector WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQImeHk1NVector
 ******************************************************************************/

PgTblWznmQImeHk1NVector::PgTblWznmQImeHk1NVector() :
			TblWznmQImeHk1NVector()
			, PgTable()
		{
};

PgTblWznmQImeHk1NVector::~PgTblWznmQImeHk1NVector() {
};

void PgTblWznmQImeHk1NVector::initStatements() {
	createStatement("TblWznmQImeHk1NVector_insertRec", "INSERT INTO TblWznmQImeHk1NVector (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWznmQImeHk1NVector_updateRec", "UPDATE TblWznmQImeHk1NVector SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWznmQImeHk1NVector_removeRecByQref", "DELETE FROM TblWznmQImeHk1NVector WHERE qref = $1", 1);
	createStatement("TblWznmQImeHk1NVector_removeRstByJref", "DELETE FROM TblWznmQImeHk1NVector WHERE jref = $1", 1);

	createStatement("TblWznmQImeHk1NVector_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWznmQImeHk1NVector WHERE qref = $1", 1);
	createStatement("TblWznmQImeHk1NVector_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWznmQImeHk1NVector WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQImeHk1NVector::loadRec(
			PGresult* res
			, WznmQImeHk1NVector** rec
		) {
	char* ptr;

	WznmQImeHk1NVector* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQImeHk1NVector();

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

ubigint PgTblWznmQImeHk1NVector::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQImeHk1NVector& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQImeHk1NVector* rec;

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
			rec = new WznmQImeHk1NVector();

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

bool PgTblWznmQImeHk1NVector::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQImeHk1NVector** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQImeHk1NVector::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQImeHk1NVector::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQImeHk1NVector& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQImeHk1NVector::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQImeHk1NVector::loadRecBySQL(
			const string& sqlstr
			, WznmQImeHk1NVector** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQImeHk1NVector::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQImeHk1NVector::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQImeHk1NVector& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQImeHk1NVector::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQImeHk1NVector::insertRec(
			WznmQImeHk1NVector* rec
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

	res = PQexecPrepared(dbs, "TblWznmQImeHk1NVector_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQImeHk1NVector::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQImeHk1NVector::insertRst(
			ListWznmQImeHk1NVector& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQImeHk1NVector::updateRec(
			WznmQImeHk1NVector* rec
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

	res = PQexecPrepared(dbs, "TblWznmQImeHk1NVector_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQImeHk1NVector::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQImeHk1NVector::updateRst(
			ListWznmQImeHk1NVector& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQImeHk1NVector::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQImeHk1NVector_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQImeHk1NVector::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQImeHk1NVector::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQImeHk1NVector_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQImeHk1NVector::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQImeHk1NVector::loadRecByQref(
			ubigint qref
			, WznmQImeHk1NVector** rec
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

	return loadRecByStmt("TblWznmQImeHk1NVector_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQImeHk1NVector::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQImeHk1NVector& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQImeHk1NVector_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
