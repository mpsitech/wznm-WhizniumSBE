/**
	* \file WznmQTblRef1NRtblock.cpp
	* Dbs and XML wrapper for table TblWznmQTblRef1NRtblock (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQTblRef1NRtblock.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblRef1NRtblock
 ******************************************************************************/

WznmQTblRef1NRtblock::WznmQTblRef1NRtblock(
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

void WznmQTblRef1NRtblock::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQTblRef1NRtblock";

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
 class ListWznmQTblRef1NRtblock
 ******************************************************************************/

ListWznmQTblRef1NRtblock::ListWznmQTblRef1NRtblock() {
};

ListWznmQTblRef1NRtblock::ListWznmQTblRef1NRtblock(
			const ListWznmQTblRef1NRtblock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblRef1NRtblock(*(src.nodes[i]));
};

ListWznmQTblRef1NRtblock::~ListWznmQTblRef1NRtblock() {
	clear();
};

void ListWznmQTblRef1NRtblock::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQTblRef1NRtblock::size() const {
	return(nodes.size());
};

void ListWznmQTblRef1NRtblock::append(
			WznmQTblRef1NRtblock* rec
		) {
	nodes.push_back(rec);
};

ListWznmQTblRef1NRtblock& ListWznmQTblRef1NRtblock::operator=(
			const ListWznmQTblRef1NRtblock& src
		) {
	WznmQTblRef1NRtblock* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQTblRef1NRtblock(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQTblRef1NRtblock::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQTblRef1NRtblock";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQTblRef1NRtblock
 ******************************************************************************/

TblWznmQTblRef1NRtblock::TblWznmQTblRef1NRtblock() {
};

TblWznmQTblRef1NRtblock::~TblWznmQTblRef1NRtblock() {
};

bool TblWznmQTblRef1NRtblock::loadRecBySQL(
			const string& sqlstr
			, WznmQTblRef1NRtblock** rec
		) {
	return false;
};

ubigint TblWznmQTblRef1NRtblock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblRef1NRtblock& rst
		) {
	return 0;
};

ubigint TblWznmQTblRef1NRtblock::insertRec(
			WznmQTblRef1NRtblock* rec
		) {
	return 0;
};

ubigint TblWznmQTblRef1NRtblock::insertNewRec(
			WznmQTblRef1NRtblock** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQTblRef1NRtblock* _rec = NULL;

	_rec = new WznmQTblRef1NRtblock(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQTblRef1NRtblock::appendNewRecToRst(
			ListWznmQTblRef1NRtblock& rst
			, WznmQTblRef1NRtblock** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQTblRef1NRtblock* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQTblRef1NRtblock::insertRst(
			ListWznmQTblRef1NRtblock& rst
		) {
};

void TblWznmQTblRef1NRtblock::updateRec(
			WznmQTblRef1NRtblock* rec
		) {
};

void TblWznmQTblRef1NRtblock::updateRst(
			ListWznmQTblRef1NRtblock& rst
		) {
};

void TblWznmQTblRef1NRtblock::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQTblRef1NRtblock::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQTblRef1NRtblock::loadRecByQref(
			ubigint qref
			, WznmQTblRef1NRtblock** rec
		) {
	return false;
};

ubigint TblWznmQTblRef1NRtblock::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblRef1NRtblock& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQTblRef1NRtblock
 ******************************************************************************/

MyTblWznmQTblRef1NRtblock::MyTblWznmQTblRef1NRtblock() :
			TblWznmQTblRef1NRtblock()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQTblRef1NRtblock::~MyTblWznmQTblRef1NRtblock() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQTblRef1NRtblock::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQTblRef1NRtblock (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQTblRef1NRtblock SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQTblRef1NRtblock WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQTblRef1NRtblock WHERE jref = ?", false);
};

bool MyTblWznmQTblRef1NRtblock::loadRecBySQL(
			const string& sqlstr
			, WznmQTblRef1NRtblock** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQTblRef1NRtblock* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTblRef1NRtblock::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTblRef1NRtblock::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQTblRef1NRtblock();

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

ubigint MyTblWznmQTblRef1NRtblock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblRef1NRtblock& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQTblRef1NRtblock* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTblRef1NRtblock::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTblRef1NRtblock::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQTblRef1NRtblock();

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

ubigint MyTblWznmQTblRef1NRtblock::insertRec(
			WznmQTblRef1NRtblock* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQTblRef1NRtblock::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQTblRef1NRtblock::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQTblRef1NRtblock::insertRst(
			ListWznmQTblRef1NRtblock& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQTblRef1NRtblock::updateRec(
			WznmQTblRef1NRtblock* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQTblRef1NRtblock::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQTblRef1NRtblock::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTblRef1NRtblock::updateRst(
			ListWznmQTblRef1NRtblock& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQTblRef1NRtblock::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQTblRef1NRtblock::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQTblRef1NRtblock::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTblRef1NRtblock::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQTblRef1NRtblock::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQTblRef1NRtblock::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQTblRef1NRtblock::loadRecByQref(
			ubigint qref
			, WznmQTblRef1NRtblock** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQTblRef1NRtblock WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQTblRef1NRtblock::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblRef1NRtblock& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQTblRef1NRtblock WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQTblRef1NRtblock
 ******************************************************************************/

PgTblWznmQTblRef1NRtblock::PgTblWznmQTblRef1NRtblock() :
			TblWznmQTblRef1NRtblock()
			, PgTable()
		{
};

PgTblWznmQTblRef1NRtblock::~PgTblWznmQTblRef1NRtblock() {
};

void PgTblWznmQTblRef1NRtblock::initStatements() {
	createStatement("TblWznmQTblRef1NRtblock_insertRec", "INSERT INTO TblWznmQTblRef1NRtblock (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWznmQTblRef1NRtblock_updateRec", "UPDATE TblWznmQTblRef1NRtblock SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWznmQTblRef1NRtblock_removeRecByQref", "DELETE FROM TblWznmQTblRef1NRtblock WHERE qref = $1", 1);
	createStatement("TblWznmQTblRef1NRtblock_removeRstByJref", "DELETE FROM TblWznmQTblRef1NRtblock WHERE jref = $1", 1);

	createStatement("TblWznmQTblRef1NRtblock_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWznmQTblRef1NRtblock WHERE qref = $1", 1);
	createStatement("TblWznmQTblRef1NRtblock_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWznmQTblRef1NRtblock WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQTblRef1NRtblock::loadRec(
			PGresult* res
			, WznmQTblRef1NRtblock** rec
		) {
	char* ptr;

	WznmQTblRef1NRtblock* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQTblRef1NRtblock();

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

ubigint PgTblWznmQTblRef1NRtblock::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQTblRef1NRtblock& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQTblRef1NRtblock* rec;

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
			rec = new WznmQTblRef1NRtblock();

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

bool PgTblWznmQTblRef1NRtblock::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQTblRef1NRtblock** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblRef1NRtblock::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTblRef1NRtblock::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQTblRef1NRtblock& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblRef1NRtblock::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQTblRef1NRtblock::loadRecBySQL(
			const string& sqlstr
			, WznmQTblRef1NRtblock** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTblRef1NRtblock::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTblRef1NRtblock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblRef1NRtblock& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTblRef1NRtblock::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQTblRef1NRtblock::insertRec(
			WznmQTblRef1NRtblock* rec
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

	res = PQexecPrepared(dbs, "TblWznmQTblRef1NRtblock_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblRef1NRtblock::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQTblRef1NRtblock::insertRst(
			ListWznmQTblRef1NRtblock& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQTblRef1NRtblock::updateRec(
			WznmQTblRef1NRtblock* rec
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

	res = PQexecPrepared(dbs, "TblWznmQTblRef1NRtblock_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblRef1NRtblock::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTblRef1NRtblock::updateRst(
			ListWznmQTblRef1NRtblock& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQTblRef1NRtblock::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQTblRef1NRtblock_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblRef1NRtblock::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTblRef1NRtblock::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQTblRef1NRtblock_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblRef1NRtblock::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQTblRef1NRtblock::loadRecByQref(
			ubigint qref
			, WznmQTblRef1NRtblock** rec
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

	return loadRecByStmt("TblWznmQTblRef1NRtblock_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQTblRef1NRtblock::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblRef1NRtblock& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQTblRef1NRtblock_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
