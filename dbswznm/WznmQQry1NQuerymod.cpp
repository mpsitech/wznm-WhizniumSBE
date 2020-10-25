/**
	* \file WznmQQry1NQuerymod.cpp
	* Dbs and XML wrapper for table TblWznmQQry1NQuerymod (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQQry1NQuerymod.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQry1NQuerymod
 ******************************************************************************/

WznmQQry1NQuerymod::WznmQQry1NQuerymod(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint qryNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->qryNum = qryNum;
};

void WznmQQry1NQuerymod::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQQry1NQuerymod";

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
 class ListWznmQQry1NQuerymod
 ******************************************************************************/

ListWznmQQry1NQuerymod::ListWznmQQry1NQuerymod() {
};

ListWznmQQry1NQuerymod::ListWznmQQry1NQuerymod(
			const ListWznmQQry1NQuerymod& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQry1NQuerymod(*(src.nodes[i]));
};

ListWznmQQry1NQuerymod::~ListWznmQQry1NQuerymod() {
	clear();
};

void ListWznmQQry1NQuerymod::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQQry1NQuerymod::size() const {
	return(nodes.size());
};

void ListWznmQQry1NQuerymod::append(
			WznmQQry1NQuerymod* rec
		) {
	nodes.push_back(rec);
};

ListWznmQQry1NQuerymod& ListWznmQQry1NQuerymod::operator=(
			const ListWznmQQry1NQuerymod& src
		) {
	WznmQQry1NQuerymod* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQQry1NQuerymod(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQQry1NQuerymod::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQQry1NQuerymod";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQQry1NQuerymod
 ******************************************************************************/

TblWznmQQry1NQuerymod::TblWznmQQry1NQuerymod() {
};

TblWznmQQry1NQuerymod::~TblWznmQQry1NQuerymod() {
};

bool TblWznmQQry1NQuerymod::loadRecBySQL(
			const string& sqlstr
			, WznmQQry1NQuerymod** rec
		) {
	return false;
};

ubigint TblWznmQQry1NQuerymod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQry1NQuerymod& rst
		) {
	return 0;
};

ubigint TblWznmQQry1NQuerymod::insertRec(
			WznmQQry1NQuerymod* rec
		) {
	return 0;
};

ubigint TblWznmQQry1NQuerymod::insertNewRec(
			WznmQQry1NQuerymod** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint qryNum
		) {
	ubigint retval = 0;
	WznmQQry1NQuerymod* _rec = NULL;

	_rec = new WznmQQry1NQuerymod(0, jref, jnum, ref, stubRef, qryNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQQry1NQuerymod::appendNewRecToRst(
			ListWznmQQry1NQuerymod& rst
			, WznmQQry1NQuerymod** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint qryNum
		) {
	ubigint retval = 0;
	WznmQQry1NQuerymod* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, qryNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQQry1NQuerymod::insertRst(
			ListWznmQQry1NQuerymod& rst
		) {
};

void TblWznmQQry1NQuerymod::updateRec(
			WznmQQry1NQuerymod* rec
		) {
};

void TblWznmQQry1NQuerymod::updateRst(
			ListWznmQQry1NQuerymod& rst
		) {
};

void TblWznmQQry1NQuerymod::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQQry1NQuerymod::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQQry1NQuerymod::loadRecByQref(
			ubigint qref
			, WznmQQry1NQuerymod** rec
		) {
	return false;
};

ubigint TblWznmQQry1NQuerymod::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQry1NQuerymod& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQQry1NQuerymod
 ******************************************************************************/

MyTblWznmQQry1NQuerymod::MyTblWznmQQry1NQuerymod() :
			TblWznmQQry1NQuerymod()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQQry1NQuerymod::~MyTblWznmQQry1NQuerymod() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQQry1NQuerymod::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQQry1NQuerymod (jref, jnum, ref, qryNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQQry1NQuerymod SET jref = ?, jnum = ?, ref = ?, qryNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQQry1NQuerymod WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQQry1NQuerymod WHERE jref = ?", false);
};

bool MyTblWznmQQry1NQuerymod::loadRecBySQL(
			const string& sqlstr
			, WznmQQry1NQuerymod** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQQry1NQuerymod* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQry1NQuerymod::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQry1NQuerymod::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQQry1NQuerymod();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->qryNum = atol((char*) dbrow[4]); else _rec->qryNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQQry1NQuerymod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQry1NQuerymod& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQQry1NQuerymod* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQry1NQuerymod::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQry1NQuerymod::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQQry1NQuerymod();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->qryNum = atol((char*) dbrow[4]); else rec->qryNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQQry1NQuerymod::insertRec(
			WznmQQry1NQuerymod* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->qryNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQQry1NQuerymod::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQQry1NQuerymod::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQQry1NQuerymod::insertRst(
			ListWznmQQry1NQuerymod& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQQry1NQuerymod::updateRec(
			WznmQQry1NQuerymod* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->qryNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQQry1NQuerymod::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQQry1NQuerymod::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQry1NQuerymod::updateRst(
			ListWznmQQry1NQuerymod& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQQry1NQuerymod::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQQry1NQuerymod::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQQry1NQuerymod::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQry1NQuerymod::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQQry1NQuerymod::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQQry1NQuerymod::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQQry1NQuerymod::loadRecByQref(
			ubigint qref
			, WznmQQry1NQuerymod** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQQry1NQuerymod WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQQry1NQuerymod::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQry1NQuerymod& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQQry1NQuerymod WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQQry1NQuerymod
 ******************************************************************************/

PgTblWznmQQry1NQuerymod::PgTblWznmQQry1NQuerymod() :
			TblWznmQQry1NQuerymod()
			, PgTable()
		{
};

PgTblWznmQQry1NQuerymod::~PgTblWznmQQry1NQuerymod() {
};

void PgTblWznmQQry1NQuerymod::initStatements() {
	createStatement("TblWznmQQry1NQuerymod_insertRec", "INSERT INTO TblWznmQQry1NQuerymod (jref, jnum, ref, qryNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQQry1NQuerymod_updateRec", "UPDATE TblWznmQQry1NQuerymod SET jref = $1, jnum = $2, ref = $3, qryNum = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQQry1NQuerymod_removeRecByQref", "DELETE FROM TblWznmQQry1NQuerymod WHERE qref = $1", 1);
	createStatement("TblWznmQQry1NQuerymod_removeRstByJref", "DELETE FROM TblWznmQQry1NQuerymod WHERE jref = $1", 1);

	createStatement("TblWznmQQry1NQuerymod_loadRecByQref", "SELECT qref, jref, jnum, ref, qryNum FROM TblWznmQQry1NQuerymod WHERE qref = $1", 1);
	createStatement("TblWznmQQry1NQuerymod_loadRstByJref", "SELECT qref, jref, jnum, ref, qryNum FROM TblWznmQQry1NQuerymod WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQQry1NQuerymod::loadRec(
			PGresult* res
			, WznmQQry1NQuerymod** rec
		) {
	char* ptr;

	WznmQQry1NQuerymod* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQQry1NQuerymod();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "qrynum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->qryNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQQry1NQuerymod::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQQry1NQuerymod& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQQry1NQuerymod* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "qrynum")
		};

		while (numread < numrow) {
			rec = new WznmQQry1NQuerymod();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->qryNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQQry1NQuerymod::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQQry1NQuerymod** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQry1NQuerymod::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQry1NQuerymod::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQQry1NQuerymod& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQry1NQuerymod::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQQry1NQuerymod::loadRecBySQL(
			const string& sqlstr
			, WznmQQry1NQuerymod** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQry1NQuerymod::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQry1NQuerymod::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQry1NQuerymod& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQry1NQuerymod::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQQry1NQuerymod::insertRec(
			WznmQQry1NQuerymod* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _qryNum = htonl(rec->qryNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qryNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQQry1NQuerymod_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQry1NQuerymod::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQQry1NQuerymod::insertRst(
			ListWznmQQry1NQuerymod& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQQry1NQuerymod::updateRec(
			WznmQQry1NQuerymod* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _qryNum = htonl(rec->qryNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qryNum,
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

	res = PQexecPrepared(dbs, "TblWznmQQry1NQuerymod_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQry1NQuerymod::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQry1NQuerymod::updateRst(
			ListWznmQQry1NQuerymod& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQQry1NQuerymod::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQQry1NQuerymod_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQry1NQuerymod::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQry1NQuerymod::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQQry1NQuerymod_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQry1NQuerymod::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQQry1NQuerymod::loadRecByQref(
			ubigint qref
			, WznmQQry1NQuerymod** rec
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

	return loadRecByStmt("TblWznmQQry1NQuerymod_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQQry1NQuerymod::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQry1NQuerymod& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQQry1NQuerymod_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

