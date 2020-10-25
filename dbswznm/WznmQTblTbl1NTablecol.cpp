/**
	* \file WznmQTblTbl1NTablecol.cpp
	* Dbs and XML wrapper for table TblWznmQTblTbl1NTablecol (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQTblTbl1NTablecol.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTblTbl1NTablecol
 ******************************************************************************/

WznmQTblTbl1NTablecol::WznmQTblTbl1NTablecol(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint tblNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->tblNum = tblNum;
};

void WznmQTblTbl1NTablecol::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQTblTbl1NTablecol";

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
 class ListWznmQTblTbl1NTablecol
 ******************************************************************************/

ListWznmQTblTbl1NTablecol::ListWznmQTblTbl1NTablecol() {
};

ListWznmQTblTbl1NTablecol::ListWznmQTblTbl1NTablecol(
			const ListWznmQTblTbl1NTablecol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTblTbl1NTablecol(*(src.nodes[i]));
};

ListWznmQTblTbl1NTablecol::~ListWznmQTblTbl1NTablecol() {
	clear();
};

void ListWznmQTblTbl1NTablecol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQTblTbl1NTablecol::size() const {
	return(nodes.size());
};

void ListWznmQTblTbl1NTablecol::append(
			WznmQTblTbl1NTablecol* rec
		) {
	nodes.push_back(rec);
};

ListWznmQTblTbl1NTablecol& ListWznmQTblTbl1NTablecol::operator=(
			const ListWznmQTblTbl1NTablecol& src
		) {
	WznmQTblTbl1NTablecol* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQTblTbl1NTablecol(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQTblTbl1NTablecol::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQTblTbl1NTablecol";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQTblTbl1NTablecol
 ******************************************************************************/

TblWznmQTblTbl1NTablecol::TblWznmQTblTbl1NTablecol() {
};

TblWznmQTblTbl1NTablecol::~TblWznmQTblTbl1NTablecol() {
};

bool TblWznmQTblTbl1NTablecol::loadRecBySQL(
			const string& sqlstr
			, WznmQTblTbl1NTablecol** rec
		) {
	return false;
};

ubigint TblWznmQTblTbl1NTablecol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblTbl1NTablecol& rst
		) {
	return 0;
};

ubigint TblWznmQTblTbl1NTablecol::insertRec(
			WznmQTblTbl1NTablecol* rec
		) {
	return 0;
};

ubigint TblWznmQTblTbl1NTablecol::insertNewRec(
			WznmQTblTbl1NTablecol** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint tblNum
		) {
	ubigint retval = 0;
	WznmQTblTbl1NTablecol* _rec = NULL;

	_rec = new WznmQTblTbl1NTablecol(0, jref, jnum, ref, stubRef, tblNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQTblTbl1NTablecol::appendNewRecToRst(
			ListWznmQTblTbl1NTablecol& rst
			, WznmQTblTbl1NTablecol** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint tblNum
		) {
	ubigint retval = 0;
	WznmQTblTbl1NTablecol* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, tblNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQTblTbl1NTablecol::insertRst(
			ListWznmQTblTbl1NTablecol& rst
		) {
};

void TblWznmQTblTbl1NTablecol::updateRec(
			WznmQTblTbl1NTablecol* rec
		) {
};

void TblWznmQTblTbl1NTablecol::updateRst(
			ListWznmQTblTbl1NTablecol& rst
		) {
};

void TblWznmQTblTbl1NTablecol::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQTblTbl1NTablecol::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQTblTbl1NTablecol::loadRecByQref(
			ubigint qref
			, WznmQTblTbl1NTablecol** rec
		) {
	return false;
};

ubigint TblWznmQTblTbl1NTablecol::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblTbl1NTablecol& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQTblTbl1NTablecol
 ******************************************************************************/

MyTblWznmQTblTbl1NTablecol::MyTblWznmQTblTbl1NTablecol() :
			TblWznmQTblTbl1NTablecol()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQTblTbl1NTablecol::~MyTblWznmQTblTbl1NTablecol() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQTblTbl1NTablecol::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQTblTbl1NTablecol (jref, jnum, ref, tblNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQTblTbl1NTablecol SET jref = ?, jnum = ?, ref = ?, tblNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQTblTbl1NTablecol WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQTblTbl1NTablecol WHERE jref = ?", false);
};

bool MyTblWznmQTblTbl1NTablecol::loadRecBySQL(
			const string& sqlstr
			, WznmQTblTbl1NTablecol** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQTblTbl1NTablecol* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTblTbl1NTablecol::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTblTbl1NTablecol::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQTblTbl1NTablecol();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->tblNum = atol((char*) dbrow[4]); else _rec->tblNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQTblTbl1NTablecol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblTbl1NTablecol& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQTblTbl1NTablecol* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTblTbl1NTablecol::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTblTbl1NTablecol::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQTblTbl1NTablecol();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->tblNum = atol((char*) dbrow[4]); else rec->tblNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQTblTbl1NTablecol::insertRec(
			WznmQTblTbl1NTablecol* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->tblNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQTblTbl1NTablecol::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQTblTbl1NTablecol::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQTblTbl1NTablecol::insertRst(
			ListWznmQTblTbl1NTablecol& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQTblTbl1NTablecol::updateRec(
			WznmQTblTbl1NTablecol* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->tblNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQTblTbl1NTablecol::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQTblTbl1NTablecol::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTblTbl1NTablecol::updateRst(
			ListWznmQTblTbl1NTablecol& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQTblTbl1NTablecol::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQTblTbl1NTablecol::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQTblTbl1NTablecol::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTblTbl1NTablecol::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQTblTbl1NTablecol::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQTblTbl1NTablecol::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQTblTbl1NTablecol::loadRecByQref(
			ubigint qref
			, WznmQTblTbl1NTablecol** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQTblTbl1NTablecol WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQTblTbl1NTablecol::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblTbl1NTablecol& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQTblTbl1NTablecol WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQTblTbl1NTablecol
 ******************************************************************************/

PgTblWznmQTblTbl1NTablecol::PgTblWznmQTblTbl1NTablecol() :
			TblWznmQTblTbl1NTablecol()
			, PgTable()
		{
};

PgTblWznmQTblTbl1NTablecol::~PgTblWznmQTblTbl1NTablecol() {
};

void PgTblWznmQTblTbl1NTablecol::initStatements() {
	createStatement("TblWznmQTblTbl1NTablecol_insertRec", "INSERT INTO TblWznmQTblTbl1NTablecol (jref, jnum, ref, tblNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQTblTbl1NTablecol_updateRec", "UPDATE TblWznmQTblTbl1NTablecol SET jref = $1, jnum = $2, ref = $3, tblNum = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQTblTbl1NTablecol_removeRecByQref", "DELETE FROM TblWznmQTblTbl1NTablecol WHERE qref = $1", 1);
	createStatement("TblWznmQTblTbl1NTablecol_removeRstByJref", "DELETE FROM TblWznmQTblTbl1NTablecol WHERE jref = $1", 1);

	createStatement("TblWznmQTblTbl1NTablecol_loadRecByQref", "SELECT qref, jref, jnum, ref, tblNum FROM TblWznmQTblTbl1NTablecol WHERE qref = $1", 1);
	createStatement("TblWznmQTblTbl1NTablecol_loadRstByJref", "SELECT qref, jref, jnum, ref, tblNum FROM TblWznmQTblTbl1NTablecol WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQTblTbl1NTablecol::loadRec(
			PGresult* res
			, WznmQTblTbl1NTablecol** rec
		) {
	char* ptr;

	WznmQTblTbl1NTablecol* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQTblTbl1NTablecol();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "tblnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->tblNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQTblTbl1NTablecol::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQTblTbl1NTablecol& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQTblTbl1NTablecol* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "tblnum")
		};

		while (numread < numrow) {
			rec = new WznmQTblTbl1NTablecol();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->tblNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQTblTbl1NTablecol::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQTblTbl1NTablecol** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblTbl1NTablecol::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTblTbl1NTablecol::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQTblTbl1NTablecol& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblTbl1NTablecol::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQTblTbl1NTablecol::loadRecBySQL(
			const string& sqlstr
			, WznmQTblTbl1NTablecol** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTblTbl1NTablecol::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTblTbl1NTablecol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTblTbl1NTablecol& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTblTbl1NTablecol::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQTblTbl1NTablecol::insertRec(
			WznmQTblTbl1NTablecol* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _tblNum = htonl(rec->tblNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_tblNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQTblTbl1NTablecol_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTblTbl1NTablecol::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQTblTbl1NTablecol::insertRst(
			ListWznmQTblTbl1NTablecol& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQTblTbl1NTablecol::updateRec(
			WznmQTblTbl1NTablecol* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _tblNum = htonl(rec->tblNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_tblNum,
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

	res = PQexecPrepared(dbs, "TblWznmQTblTbl1NTablecol_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblTbl1NTablecol::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTblTbl1NTablecol::updateRst(
			ListWznmQTblTbl1NTablecol& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQTblTbl1NTablecol::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQTblTbl1NTablecol_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblTbl1NTablecol::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTblTbl1NTablecol::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQTblTbl1NTablecol_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTblTbl1NTablecol::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQTblTbl1NTablecol::loadRecByQref(
			ubigint qref
			, WznmQTblTbl1NTablecol** rec
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

	return loadRecByStmt("TblWznmQTblTbl1NTablecol_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQTblTbl1NTablecol::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTblTbl1NTablecol& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQTblTbl1NTablecol_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

