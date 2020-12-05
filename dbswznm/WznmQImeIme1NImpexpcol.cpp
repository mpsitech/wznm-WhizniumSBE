/**
	* \file WznmQImeIme1NImpexpcol.cpp
	* Dbs and XML wrapper for table TblWznmQImeIme1NImpexpcol (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQImeIme1NImpexpcol.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQImeIme1NImpexpcol
 ******************************************************************************/

WznmQImeIme1NImpexpcol::WznmQImeIme1NImpexpcol(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint imeNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->imeNum = imeNum;
};

void WznmQImeIme1NImpexpcol::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQImeIme1NImpexpcol";

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
 class ListWznmQImeIme1NImpexpcol
 ******************************************************************************/

ListWznmQImeIme1NImpexpcol::ListWznmQImeIme1NImpexpcol() {
};

ListWznmQImeIme1NImpexpcol::ListWznmQImeIme1NImpexpcol(
			const ListWznmQImeIme1NImpexpcol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQImeIme1NImpexpcol(*(src.nodes[i]));
};

ListWznmQImeIme1NImpexpcol::~ListWznmQImeIme1NImpexpcol() {
	clear();
};

void ListWznmQImeIme1NImpexpcol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQImeIme1NImpexpcol::size() const {
	return(nodes.size());
};

void ListWznmQImeIme1NImpexpcol::append(
			WznmQImeIme1NImpexpcol* rec
		) {
	nodes.push_back(rec);
};

ListWznmQImeIme1NImpexpcol& ListWznmQImeIme1NImpexpcol::operator=(
			const ListWznmQImeIme1NImpexpcol& src
		) {
	WznmQImeIme1NImpexpcol* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQImeIme1NImpexpcol(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQImeIme1NImpexpcol::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQImeIme1NImpexpcol";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQImeIme1NImpexpcol
 ******************************************************************************/

TblWznmQImeIme1NImpexpcol::TblWznmQImeIme1NImpexpcol() {
};

TblWznmQImeIme1NImpexpcol::~TblWznmQImeIme1NImpexpcol() {
};

bool TblWznmQImeIme1NImpexpcol::loadRecBySQL(
			const string& sqlstr
			, WznmQImeIme1NImpexpcol** rec
		) {
	return false;
};

ubigint TblWznmQImeIme1NImpexpcol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQImeIme1NImpexpcol& rst
		) {
	return 0;
};

ubigint TblWznmQImeIme1NImpexpcol::insertRec(
			WznmQImeIme1NImpexpcol* rec
		) {
	return 0;
};

ubigint TblWznmQImeIme1NImpexpcol::insertNewRec(
			WznmQImeIme1NImpexpcol** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint imeNum
		) {
	ubigint retval = 0;
	WznmQImeIme1NImpexpcol* _rec = NULL;

	_rec = new WznmQImeIme1NImpexpcol(0, jref, jnum, ref, stubRef, imeNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQImeIme1NImpexpcol::appendNewRecToRst(
			ListWznmQImeIme1NImpexpcol& rst
			, WznmQImeIme1NImpexpcol** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint imeNum
		) {
	ubigint retval = 0;
	WznmQImeIme1NImpexpcol* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, imeNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQImeIme1NImpexpcol::insertRst(
			ListWznmQImeIme1NImpexpcol& rst
		) {
};

void TblWznmQImeIme1NImpexpcol::updateRec(
			WznmQImeIme1NImpexpcol* rec
		) {
};

void TblWznmQImeIme1NImpexpcol::updateRst(
			ListWznmQImeIme1NImpexpcol& rst
		) {
};

void TblWznmQImeIme1NImpexpcol::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQImeIme1NImpexpcol::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQImeIme1NImpexpcol::loadRecByQref(
			ubigint qref
			, WznmQImeIme1NImpexpcol** rec
		) {
	return false;
};

ubigint TblWznmQImeIme1NImpexpcol::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQImeIme1NImpexpcol& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQImeIme1NImpexpcol
 ******************************************************************************/

MyTblWznmQImeIme1NImpexpcol::MyTblWznmQImeIme1NImpexpcol() :
			TblWznmQImeIme1NImpexpcol()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQImeIme1NImpexpcol::~MyTblWznmQImeIme1NImpexpcol() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQImeIme1NImpexpcol::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQImeIme1NImpexpcol (jref, jnum, ref, imeNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQImeIme1NImpexpcol SET jref = ?, jnum = ?, ref = ?, imeNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQImeIme1NImpexpcol WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQImeIme1NImpexpcol WHERE jref = ?", false);
};

bool MyTblWznmQImeIme1NImpexpcol::loadRecBySQL(
			const string& sqlstr
			, WznmQImeIme1NImpexpcol** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQImeIme1NImpexpcol* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQImeIme1NImpexpcol::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQImeIme1NImpexpcol::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQImeIme1NImpexpcol();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->imeNum = atol((char*) dbrow[4]); else _rec->imeNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQImeIme1NImpexpcol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQImeIme1NImpexpcol& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQImeIme1NImpexpcol* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQImeIme1NImpexpcol::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQImeIme1NImpexpcol::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQImeIme1NImpexpcol();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->imeNum = atol((char*) dbrow[4]); else rec->imeNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQImeIme1NImpexpcol::insertRec(
			WznmQImeIme1NImpexpcol* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->imeNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQImeIme1NImpexpcol::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQImeIme1NImpexpcol::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQImeIme1NImpexpcol::insertRst(
			ListWznmQImeIme1NImpexpcol& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQImeIme1NImpexpcol::updateRec(
			WznmQImeIme1NImpexpcol* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->imeNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQImeIme1NImpexpcol::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQImeIme1NImpexpcol::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQImeIme1NImpexpcol::updateRst(
			ListWznmQImeIme1NImpexpcol& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQImeIme1NImpexpcol::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQImeIme1NImpexpcol::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQImeIme1NImpexpcol::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQImeIme1NImpexpcol::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQImeIme1NImpexpcol::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQImeIme1NImpexpcol::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQImeIme1NImpexpcol::loadRecByQref(
			ubigint qref
			, WznmQImeIme1NImpexpcol** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQImeIme1NImpexpcol WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQImeIme1NImpexpcol::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQImeIme1NImpexpcol& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQImeIme1NImpexpcol WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQImeIme1NImpexpcol
 ******************************************************************************/

PgTblWznmQImeIme1NImpexpcol::PgTblWznmQImeIme1NImpexpcol() :
			TblWznmQImeIme1NImpexpcol()
			, PgTable()
		{
};

PgTblWznmQImeIme1NImpexpcol::~PgTblWznmQImeIme1NImpexpcol() {
};

void PgTblWznmQImeIme1NImpexpcol::initStatements() {
	createStatement("TblWznmQImeIme1NImpexpcol_insertRec", "INSERT INTO TblWznmQImeIme1NImpexpcol (jref, jnum, ref, imeNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQImeIme1NImpexpcol_updateRec", "UPDATE TblWznmQImeIme1NImpexpcol SET jref = $1, jnum = $2, ref = $3, imeNum = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQImeIme1NImpexpcol_removeRecByQref", "DELETE FROM TblWznmQImeIme1NImpexpcol WHERE qref = $1", 1);
	createStatement("TblWznmQImeIme1NImpexpcol_removeRstByJref", "DELETE FROM TblWznmQImeIme1NImpexpcol WHERE jref = $1", 1);

	createStatement("TblWznmQImeIme1NImpexpcol_loadRecByQref", "SELECT qref, jref, jnum, ref, imeNum FROM TblWznmQImeIme1NImpexpcol WHERE qref = $1", 1);
	createStatement("TblWznmQImeIme1NImpexpcol_loadRstByJref", "SELECT qref, jref, jnum, ref, imeNum FROM TblWznmQImeIme1NImpexpcol WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQImeIme1NImpexpcol::loadRec(
			PGresult* res
			, WznmQImeIme1NImpexpcol** rec
		) {
	char* ptr;

	WznmQImeIme1NImpexpcol* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQImeIme1NImpexpcol();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "imenum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->imeNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQImeIme1NImpexpcol::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQImeIme1NImpexpcol& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQImeIme1NImpexpcol* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "imenum")
		};

		while (numread < numrow) {
			rec = new WznmQImeIme1NImpexpcol();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->imeNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQImeIme1NImpexpcol::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQImeIme1NImpexpcol** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQImeIme1NImpexpcol::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQImeIme1NImpexpcol::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQImeIme1NImpexpcol& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQImeIme1NImpexpcol::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQImeIme1NImpexpcol::loadRecBySQL(
			const string& sqlstr
			, WznmQImeIme1NImpexpcol** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQImeIme1NImpexpcol::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQImeIme1NImpexpcol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQImeIme1NImpexpcol& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQImeIme1NImpexpcol::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQImeIme1NImpexpcol::insertRec(
			WznmQImeIme1NImpexpcol* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _imeNum = htonl(rec->imeNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_imeNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQImeIme1NImpexpcol_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQImeIme1NImpexpcol::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQImeIme1NImpexpcol::insertRst(
			ListWznmQImeIme1NImpexpcol& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQImeIme1NImpexpcol::updateRec(
			WznmQImeIme1NImpexpcol* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _imeNum = htonl(rec->imeNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_imeNum,
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

	res = PQexecPrepared(dbs, "TblWznmQImeIme1NImpexpcol_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQImeIme1NImpexpcol::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQImeIme1NImpexpcol::updateRst(
			ListWznmQImeIme1NImpexpcol& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQImeIme1NImpexpcol::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQImeIme1NImpexpcol_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQImeIme1NImpexpcol::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQImeIme1NImpexpcol::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQImeIme1NImpexpcol_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQImeIme1NImpexpcol::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQImeIme1NImpexpcol::loadRecByQref(
			ubigint qref
			, WznmQImeIme1NImpexpcol** rec
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

	return loadRecByStmt("TblWznmQImeIme1NImpexpcol_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQImeIme1NImpexpcol::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQImeIme1NImpexpcol& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQImeIme1NImpexpcol_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

