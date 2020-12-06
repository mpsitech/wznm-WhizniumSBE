/**
	* \file WznmQVer1NImpexpcplx.cpp
	* Dbs and XML wrapper for table TblWznmQVer1NImpexpcplx (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQVer1NImpexpcplx.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVer1NImpexpcplx
 ******************************************************************************/

WznmQVer1NImpexpcplx::WznmQVer1NImpexpcplx(
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

void WznmQVer1NImpexpcplx::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQVer1NImpexpcplx";

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
 class ListWznmQVer1NImpexpcplx
 ******************************************************************************/

ListWznmQVer1NImpexpcplx::ListWznmQVer1NImpexpcplx() {
};

ListWznmQVer1NImpexpcplx::ListWznmQVer1NImpexpcplx(
			const ListWznmQVer1NImpexpcplx& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVer1NImpexpcplx(*(src.nodes[i]));
};

ListWznmQVer1NImpexpcplx::~ListWznmQVer1NImpexpcplx() {
	clear();
};

void ListWznmQVer1NImpexpcplx::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQVer1NImpexpcplx::size() const {
	return(nodes.size());
};

void ListWznmQVer1NImpexpcplx::append(
			WznmQVer1NImpexpcplx* rec
		) {
	nodes.push_back(rec);
};

ListWznmQVer1NImpexpcplx& ListWznmQVer1NImpexpcplx::operator=(
			const ListWznmQVer1NImpexpcplx& src
		) {
	WznmQVer1NImpexpcplx* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQVer1NImpexpcplx(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQVer1NImpexpcplx::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQVer1NImpexpcplx";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQVer1NImpexpcplx
 ******************************************************************************/

TblWznmQVer1NImpexpcplx::TblWznmQVer1NImpexpcplx() {
};

TblWznmQVer1NImpexpcplx::~TblWznmQVer1NImpexpcplx() {
};

bool TblWznmQVer1NImpexpcplx::loadRecBySQL(
			const string& sqlstr
			, WznmQVer1NImpexpcplx** rec
		) {
	return false;
};

ubigint TblWznmQVer1NImpexpcplx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVer1NImpexpcplx& rst
		) {
	return 0;
};

ubigint TblWznmQVer1NImpexpcplx::insertRec(
			WznmQVer1NImpexpcplx* rec
		) {
	return 0;
};

ubigint TblWznmQVer1NImpexpcplx::insertNewRec(
			WznmQVer1NImpexpcplx** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQVer1NImpexpcplx* _rec = NULL;

	_rec = new WznmQVer1NImpexpcplx(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQVer1NImpexpcplx::appendNewRecToRst(
			ListWznmQVer1NImpexpcplx& rst
			, WznmQVer1NImpexpcplx** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQVer1NImpexpcplx* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQVer1NImpexpcplx::insertRst(
			ListWznmQVer1NImpexpcplx& rst
		) {
};

void TblWznmQVer1NImpexpcplx::updateRec(
			WznmQVer1NImpexpcplx* rec
		) {
};

void TblWznmQVer1NImpexpcplx::updateRst(
			ListWznmQVer1NImpexpcplx& rst
		) {
};

void TblWznmQVer1NImpexpcplx::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQVer1NImpexpcplx::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQVer1NImpexpcplx::loadRecByQref(
			ubigint qref
			, WznmQVer1NImpexpcplx** rec
		) {
	return false;
};

ubigint TblWznmQVer1NImpexpcplx::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVer1NImpexpcplx& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQVer1NImpexpcplx
 ******************************************************************************/

MyTblWznmQVer1NImpexpcplx::MyTblWznmQVer1NImpexpcplx() :
			TblWznmQVer1NImpexpcplx()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQVer1NImpexpcplx::~MyTblWznmQVer1NImpexpcplx() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQVer1NImpexpcplx::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQVer1NImpexpcplx (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQVer1NImpexpcplx SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQVer1NImpexpcplx WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQVer1NImpexpcplx WHERE jref = ?", false);
};

bool MyTblWznmQVer1NImpexpcplx::loadRecBySQL(
			const string& sqlstr
			, WznmQVer1NImpexpcplx** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQVer1NImpexpcplx* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVer1NImpexpcplx::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVer1NImpexpcplx::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQVer1NImpexpcplx();

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

ubigint MyTblWznmQVer1NImpexpcplx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVer1NImpexpcplx& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQVer1NImpexpcplx* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVer1NImpexpcplx::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVer1NImpexpcplx::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQVer1NImpexpcplx();

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

ubigint MyTblWznmQVer1NImpexpcplx::insertRec(
			WznmQVer1NImpexpcplx* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQVer1NImpexpcplx::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQVer1NImpexpcplx::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQVer1NImpexpcplx::insertRst(
			ListWznmQVer1NImpexpcplx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQVer1NImpexpcplx::updateRec(
			WznmQVer1NImpexpcplx* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQVer1NImpexpcplx::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQVer1NImpexpcplx::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVer1NImpexpcplx::updateRst(
			ListWznmQVer1NImpexpcplx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQVer1NImpexpcplx::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQVer1NImpexpcplx::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQVer1NImpexpcplx::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVer1NImpexpcplx::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQVer1NImpexpcplx::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQVer1NImpexpcplx::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQVer1NImpexpcplx::loadRecByQref(
			ubigint qref
			, WznmQVer1NImpexpcplx** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQVer1NImpexpcplx WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQVer1NImpexpcplx::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVer1NImpexpcplx& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQVer1NImpexpcplx WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQVer1NImpexpcplx
 ******************************************************************************/

PgTblWznmQVer1NImpexpcplx::PgTblWznmQVer1NImpexpcplx() :
			TblWznmQVer1NImpexpcplx()
			, PgTable()
		{
};

PgTblWznmQVer1NImpexpcplx::~PgTblWznmQVer1NImpexpcplx() {
};

void PgTblWznmQVer1NImpexpcplx::initStatements() {
	createStatement("TblWznmQVer1NImpexpcplx_insertRec", "INSERT INTO TblWznmQVer1NImpexpcplx (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWznmQVer1NImpexpcplx_updateRec", "UPDATE TblWznmQVer1NImpexpcplx SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWznmQVer1NImpexpcplx_removeRecByQref", "DELETE FROM TblWznmQVer1NImpexpcplx WHERE qref = $1", 1);
	createStatement("TblWznmQVer1NImpexpcplx_removeRstByJref", "DELETE FROM TblWznmQVer1NImpexpcplx WHERE jref = $1", 1);

	createStatement("TblWznmQVer1NImpexpcplx_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWznmQVer1NImpexpcplx WHERE qref = $1", 1);
	createStatement("TblWznmQVer1NImpexpcplx_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWznmQVer1NImpexpcplx WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQVer1NImpexpcplx::loadRec(
			PGresult* res
			, WznmQVer1NImpexpcplx** rec
		) {
	char* ptr;

	WznmQVer1NImpexpcplx* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQVer1NImpexpcplx();

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

ubigint PgTblWznmQVer1NImpexpcplx::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQVer1NImpexpcplx& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQVer1NImpexpcplx* rec;

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
			rec = new WznmQVer1NImpexpcplx();

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

bool PgTblWznmQVer1NImpexpcplx::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQVer1NImpexpcplx** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVer1NImpexpcplx::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVer1NImpexpcplx::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQVer1NImpexpcplx& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVer1NImpexpcplx::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQVer1NImpexpcplx::loadRecBySQL(
			const string& sqlstr
			, WznmQVer1NImpexpcplx** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVer1NImpexpcplx::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVer1NImpexpcplx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVer1NImpexpcplx& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVer1NImpexpcplx::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQVer1NImpexpcplx::insertRec(
			WznmQVer1NImpexpcplx* rec
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

	res = PQexecPrepared(dbs, "TblWznmQVer1NImpexpcplx_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVer1NImpexpcplx::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQVer1NImpexpcplx::insertRst(
			ListWznmQVer1NImpexpcplx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQVer1NImpexpcplx::updateRec(
			WznmQVer1NImpexpcplx* rec
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

	res = PQexecPrepared(dbs, "TblWznmQVer1NImpexpcplx_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVer1NImpexpcplx::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVer1NImpexpcplx::updateRst(
			ListWznmQVer1NImpexpcplx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQVer1NImpexpcplx::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQVer1NImpexpcplx_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVer1NImpexpcplx::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVer1NImpexpcplx::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQVer1NImpexpcplx_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVer1NImpexpcplx::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQVer1NImpexpcplx::loadRecByQref(
			ubigint qref
			, WznmQVer1NImpexpcplx** rec
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

	return loadRecByStmt("TblWznmQVer1NImpexpcplx_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQVer1NImpexpcplx::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVer1NImpexpcplx& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQVer1NImpexpcplx_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
