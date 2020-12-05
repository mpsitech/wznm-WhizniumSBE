/**
	* \file WznmQBlkRef1NRtblock.cpp
	* Dbs and XML wrapper for table TblWznmQBlkRef1NRtblock (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQBlkRef1NRtblock.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQBlkRef1NRtblock
 ******************************************************************************/

WznmQBlkRef1NRtblock::WznmQBlkRef1NRtblock(
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

void WznmQBlkRef1NRtblock::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQBlkRef1NRtblock";

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
 class ListWznmQBlkRef1NRtblock
 ******************************************************************************/

ListWznmQBlkRef1NRtblock::ListWznmQBlkRef1NRtblock() {
};

ListWznmQBlkRef1NRtblock::ListWznmQBlkRef1NRtblock(
			const ListWznmQBlkRef1NRtblock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBlkRef1NRtblock(*(src.nodes[i]));
};

ListWznmQBlkRef1NRtblock::~ListWznmQBlkRef1NRtblock() {
	clear();
};

void ListWznmQBlkRef1NRtblock::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQBlkRef1NRtblock::size() const {
	return(nodes.size());
};

void ListWznmQBlkRef1NRtblock::append(
			WznmQBlkRef1NRtblock* rec
		) {
	nodes.push_back(rec);
};

ListWznmQBlkRef1NRtblock& ListWznmQBlkRef1NRtblock::operator=(
			const ListWznmQBlkRef1NRtblock& src
		) {
	WznmQBlkRef1NRtblock* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQBlkRef1NRtblock(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQBlkRef1NRtblock::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQBlkRef1NRtblock";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQBlkRef1NRtblock
 ******************************************************************************/

TblWznmQBlkRef1NRtblock::TblWznmQBlkRef1NRtblock() {
};

TblWznmQBlkRef1NRtblock::~TblWznmQBlkRef1NRtblock() {
};

bool TblWznmQBlkRef1NRtblock::loadRecBySQL(
			const string& sqlstr
			, WznmQBlkRef1NRtblock** rec
		) {
	return false;
};

ubigint TblWznmQBlkRef1NRtblock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBlkRef1NRtblock& rst
		) {
	return 0;
};

ubigint TblWznmQBlkRef1NRtblock::insertRec(
			WznmQBlkRef1NRtblock* rec
		) {
	return 0;
};

ubigint TblWznmQBlkRef1NRtblock::insertNewRec(
			WznmQBlkRef1NRtblock** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQBlkRef1NRtblock* _rec = NULL;

	_rec = new WznmQBlkRef1NRtblock(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQBlkRef1NRtblock::appendNewRecToRst(
			ListWznmQBlkRef1NRtblock& rst
			, WznmQBlkRef1NRtblock** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQBlkRef1NRtblock* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQBlkRef1NRtblock::insertRst(
			ListWznmQBlkRef1NRtblock& rst
		) {
};

void TblWznmQBlkRef1NRtblock::updateRec(
			WznmQBlkRef1NRtblock* rec
		) {
};

void TblWznmQBlkRef1NRtblock::updateRst(
			ListWznmQBlkRef1NRtblock& rst
		) {
};

void TblWznmQBlkRef1NRtblock::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQBlkRef1NRtblock::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQBlkRef1NRtblock::loadRecByQref(
			ubigint qref
			, WznmQBlkRef1NRtblock** rec
		) {
	return false;
};

ubigint TblWznmQBlkRef1NRtblock::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBlkRef1NRtblock& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQBlkRef1NRtblock
 ******************************************************************************/

MyTblWznmQBlkRef1NRtblock::MyTblWznmQBlkRef1NRtblock() :
			TblWznmQBlkRef1NRtblock()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQBlkRef1NRtblock::~MyTblWznmQBlkRef1NRtblock() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQBlkRef1NRtblock::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQBlkRef1NRtblock (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQBlkRef1NRtblock SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQBlkRef1NRtblock WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQBlkRef1NRtblock WHERE jref = ?", false);
};

bool MyTblWznmQBlkRef1NRtblock::loadRecBySQL(
			const string& sqlstr
			, WznmQBlkRef1NRtblock** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQBlkRef1NRtblock* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQBlkRef1NRtblock::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQBlkRef1NRtblock::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQBlkRef1NRtblock();

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

ubigint MyTblWznmQBlkRef1NRtblock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBlkRef1NRtblock& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQBlkRef1NRtblock* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQBlkRef1NRtblock::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQBlkRef1NRtblock::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQBlkRef1NRtblock();

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

ubigint MyTblWznmQBlkRef1NRtblock::insertRec(
			WznmQBlkRef1NRtblock* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQBlkRef1NRtblock::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQBlkRef1NRtblock::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQBlkRef1NRtblock::insertRst(
			ListWznmQBlkRef1NRtblock& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQBlkRef1NRtblock::updateRec(
			WznmQBlkRef1NRtblock* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQBlkRef1NRtblock::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQBlkRef1NRtblock::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQBlkRef1NRtblock::updateRst(
			ListWznmQBlkRef1NRtblock& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQBlkRef1NRtblock::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQBlkRef1NRtblock::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQBlkRef1NRtblock::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQBlkRef1NRtblock::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQBlkRef1NRtblock::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQBlkRef1NRtblock::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQBlkRef1NRtblock::loadRecByQref(
			ubigint qref
			, WznmQBlkRef1NRtblock** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQBlkRef1NRtblock WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQBlkRef1NRtblock::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBlkRef1NRtblock& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQBlkRef1NRtblock WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQBlkRef1NRtblock
 ******************************************************************************/

PgTblWznmQBlkRef1NRtblock::PgTblWznmQBlkRef1NRtblock() :
			TblWznmQBlkRef1NRtblock()
			, PgTable()
		{
};

PgTblWznmQBlkRef1NRtblock::~PgTblWznmQBlkRef1NRtblock() {
};

void PgTblWznmQBlkRef1NRtblock::initStatements() {
	createStatement("TblWznmQBlkRef1NRtblock_insertRec", "INSERT INTO TblWznmQBlkRef1NRtblock (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWznmQBlkRef1NRtblock_updateRec", "UPDATE TblWznmQBlkRef1NRtblock SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWznmQBlkRef1NRtblock_removeRecByQref", "DELETE FROM TblWznmQBlkRef1NRtblock WHERE qref = $1", 1);
	createStatement("TblWznmQBlkRef1NRtblock_removeRstByJref", "DELETE FROM TblWznmQBlkRef1NRtblock WHERE jref = $1", 1);

	createStatement("TblWznmQBlkRef1NRtblock_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWznmQBlkRef1NRtblock WHERE qref = $1", 1);
	createStatement("TblWznmQBlkRef1NRtblock_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWznmQBlkRef1NRtblock WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQBlkRef1NRtblock::loadRec(
			PGresult* res
			, WznmQBlkRef1NRtblock** rec
		) {
	char* ptr;

	WznmQBlkRef1NRtblock* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQBlkRef1NRtblock();

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

ubigint PgTblWznmQBlkRef1NRtblock::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQBlkRef1NRtblock& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQBlkRef1NRtblock* rec;

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
			rec = new WznmQBlkRef1NRtblock();

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

bool PgTblWznmQBlkRef1NRtblock::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQBlkRef1NRtblock** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBlkRef1NRtblock::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQBlkRef1NRtblock::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQBlkRef1NRtblock& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBlkRef1NRtblock::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQBlkRef1NRtblock::loadRecBySQL(
			const string& sqlstr
			, WznmQBlkRef1NRtblock** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQBlkRef1NRtblock::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQBlkRef1NRtblock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBlkRef1NRtblock& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQBlkRef1NRtblock::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQBlkRef1NRtblock::insertRec(
			WznmQBlkRef1NRtblock* rec
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

	res = PQexecPrepared(dbs, "TblWznmQBlkRef1NRtblock_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBlkRef1NRtblock::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQBlkRef1NRtblock::insertRst(
			ListWznmQBlkRef1NRtblock& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQBlkRef1NRtblock::updateRec(
			WznmQBlkRef1NRtblock* rec
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

	res = PQexecPrepared(dbs, "TblWznmQBlkRef1NRtblock_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBlkRef1NRtblock::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQBlkRef1NRtblock::updateRst(
			ListWznmQBlkRef1NRtblock& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQBlkRef1NRtblock::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQBlkRef1NRtblock_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBlkRef1NRtblock::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQBlkRef1NRtblock::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQBlkRef1NRtblock_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBlkRef1NRtblock::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQBlkRef1NRtblock::loadRecByQref(
			ubigint qref
			, WznmQBlkRef1NRtblock** rec
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

	return loadRecByStmt("TblWznmQBlkRef1NRtblock_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQBlkRef1NRtblock::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBlkRef1NRtblock& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQBlkRef1NRtblock_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

