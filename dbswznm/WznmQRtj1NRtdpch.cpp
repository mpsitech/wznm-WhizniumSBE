/**
	* \file WznmQRtj1NRtdpch.cpp
	* Dbs and XML wrapper for table TblWznmQRtj1NRtdpch (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQRtj1NRtdpch.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRtj1NRtdpch
 ******************************************************************************/

WznmQRtj1NRtdpch::WznmQRtj1NRtdpch(
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

void WznmQRtj1NRtdpch::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQRtj1NRtdpch";

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
 class ListWznmQRtj1NRtdpch
 ******************************************************************************/

ListWznmQRtj1NRtdpch::ListWznmQRtj1NRtdpch() {
};

ListWznmQRtj1NRtdpch::ListWznmQRtj1NRtdpch(
			const ListWznmQRtj1NRtdpch& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRtj1NRtdpch(*(src.nodes[i]));
};

ListWznmQRtj1NRtdpch::~ListWznmQRtj1NRtdpch() {
	clear();
};

void ListWznmQRtj1NRtdpch::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQRtj1NRtdpch::size() const {
	return(nodes.size());
};

void ListWznmQRtj1NRtdpch::append(
			WznmQRtj1NRtdpch* rec
		) {
	nodes.push_back(rec);
};

ListWznmQRtj1NRtdpch& ListWznmQRtj1NRtdpch::operator=(
			const ListWznmQRtj1NRtdpch& src
		) {
	WznmQRtj1NRtdpch* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQRtj1NRtdpch(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQRtj1NRtdpch::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQRtj1NRtdpch";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQRtj1NRtdpch
 ******************************************************************************/

TblWznmQRtj1NRtdpch::TblWznmQRtj1NRtdpch() {
};

TblWznmQRtj1NRtdpch::~TblWznmQRtj1NRtdpch() {
};

bool TblWznmQRtj1NRtdpch::loadRecBySQL(
			const string& sqlstr
			, WznmQRtj1NRtdpch** rec
		) {
	return false;
};

ubigint TblWznmQRtj1NRtdpch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRtj1NRtdpch& rst
		) {
	return 0;
};

ubigint TblWznmQRtj1NRtdpch::insertRec(
			WznmQRtj1NRtdpch* rec
		) {
	return 0;
};

ubigint TblWznmQRtj1NRtdpch::insertNewRec(
			WznmQRtj1NRtdpch** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQRtj1NRtdpch* _rec = NULL;

	_rec = new WznmQRtj1NRtdpch(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQRtj1NRtdpch::appendNewRecToRst(
			ListWznmQRtj1NRtdpch& rst
			, WznmQRtj1NRtdpch** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQRtj1NRtdpch* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQRtj1NRtdpch::insertRst(
			ListWznmQRtj1NRtdpch& rst
		) {
};

void TblWznmQRtj1NRtdpch::updateRec(
			WznmQRtj1NRtdpch* rec
		) {
};

void TblWznmQRtj1NRtdpch::updateRst(
			ListWznmQRtj1NRtdpch& rst
		) {
};

void TblWznmQRtj1NRtdpch::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQRtj1NRtdpch::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQRtj1NRtdpch::loadRecByQref(
			ubigint qref
			, WznmQRtj1NRtdpch** rec
		) {
	return false;
};

ubigint TblWznmQRtj1NRtdpch::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRtj1NRtdpch& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQRtj1NRtdpch
 ******************************************************************************/

MyTblWznmQRtj1NRtdpch::MyTblWznmQRtj1NRtdpch() :
			TblWznmQRtj1NRtdpch()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQRtj1NRtdpch::~MyTblWznmQRtj1NRtdpch() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQRtj1NRtdpch::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQRtj1NRtdpch (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQRtj1NRtdpch SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQRtj1NRtdpch WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQRtj1NRtdpch WHERE jref = ?", false);
};

bool MyTblWznmQRtj1NRtdpch::loadRecBySQL(
			const string& sqlstr
			, WznmQRtj1NRtdpch** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQRtj1NRtdpch* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQRtj1NRtdpch::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQRtj1NRtdpch::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQRtj1NRtdpch();

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

ubigint MyTblWznmQRtj1NRtdpch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRtj1NRtdpch& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQRtj1NRtdpch* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQRtj1NRtdpch::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQRtj1NRtdpch::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQRtj1NRtdpch();

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

ubigint MyTblWznmQRtj1NRtdpch::insertRec(
			WznmQRtj1NRtdpch* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQRtj1NRtdpch::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQRtj1NRtdpch::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQRtj1NRtdpch::insertRst(
			ListWznmQRtj1NRtdpch& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQRtj1NRtdpch::updateRec(
			WznmQRtj1NRtdpch* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQRtj1NRtdpch::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQRtj1NRtdpch::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQRtj1NRtdpch::updateRst(
			ListWznmQRtj1NRtdpch& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQRtj1NRtdpch::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQRtj1NRtdpch::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQRtj1NRtdpch::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQRtj1NRtdpch::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQRtj1NRtdpch::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQRtj1NRtdpch::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQRtj1NRtdpch::loadRecByQref(
			ubigint qref
			, WznmQRtj1NRtdpch** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQRtj1NRtdpch WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQRtj1NRtdpch::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRtj1NRtdpch& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQRtj1NRtdpch WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQRtj1NRtdpch
 ******************************************************************************/

PgTblWznmQRtj1NRtdpch::PgTblWznmQRtj1NRtdpch() :
			TblWznmQRtj1NRtdpch()
			, PgTable()
		{
};

PgTblWznmQRtj1NRtdpch::~PgTblWznmQRtj1NRtdpch() {
};

void PgTblWznmQRtj1NRtdpch::initStatements() {
	createStatement("TblWznmQRtj1NRtdpch_insertRec", "INSERT INTO TblWznmQRtj1NRtdpch (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWznmQRtj1NRtdpch_updateRec", "UPDATE TblWznmQRtj1NRtdpch SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWznmQRtj1NRtdpch_removeRecByQref", "DELETE FROM TblWznmQRtj1NRtdpch WHERE qref = $1", 1);
	createStatement("TblWznmQRtj1NRtdpch_removeRstByJref", "DELETE FROM TblWznmQRtj1NRtdpch WHERE jref = $1", 1);

	createStatement("TblWznmQRtj1NRtdpch_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWznmQRtj1NRtdpch WHERE qref = $1", 1);
	createStatement("TblWznmQRtj1NRtdpch_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWznmQRtj1NRtdpch WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQRtj1NRtdpch::loadRec(
			PGresult* res
			, WznmQRtj1NRtdpch** rec
		) {
	char* ptr;

	WznmQRtj1NRtdpch* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQRtj1NRtdpch();

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

ubigint PgTblWznmQRtj1NRtdpch::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQRtj1NRtdpch& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQRtj1NRtdpch* rec;

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
			rec = new WznmQRtj1NRtdpch();

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

bool PgTblWznmQRtj1NRtdpch::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQRtj1NRtdpch** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRtj1NRtdpch::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQRtj1NRtdpch::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQRtj1NRtdpch& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRtj1NRtdpch::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQRtj1NRtdpch::loadRecBySQL(
			const string& sqlstr
			, WznmQRtj1NRtdpch** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQRtj1NRtdpch::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQRtj1NRtdpch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRtj1NRtdpch& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQRtj1NRtdpch::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQRtj1NRtdpch::insertRec(
			WznmQRtj1NRtdpch* rec
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

	res = PQexecPrepared(dbs, "TblWznmQRtj1NRtdpch_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRtj1NRtdpch::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQRtj1NRtdpch::insertRst(
			ListWznmQRtj1NRtdpch& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQRtj1NRtdpch::updateRec(
			WznmQRtj1NRtdpch* rec
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

	res = PQexecPrepared(dbs, "TblWznmQRtj1NRtdpch_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRtj1NRtdpch::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQRtj1NRtdpch::updateRst(
			ListWznmQRtj1NRtdpch& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQRtj1NRtdpch::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQRtj1NRtdpch_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRtj1NRtdpch::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQRtj1NRtdpch::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQRtj1NRtdpch_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRtj1NRtdpch::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQRtj1NRtdpch::loadRecByQref(
			ubigint qref
			, WznmQRtj1NRtdpch** rec
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

	return loadRecByStmt("TblWznmQRtj1NRtdpch_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQRtj1NRtdpch::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRtj1NRtdpch& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQRtj1NRtdpch_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
