/**
	* \file WznmQDlgHk1NControl.cpp
	* Dbs and XML wrapper for table TblWznmQDlgHk1NControl (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQDlgHk1NControl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQDlgHk1NControl
 ******************************************************************************/

WznmQDlgHk1NControl::WznmQDlgHk1NControl(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint hkNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->hkNum = hkNum;
};

void WznmQDlgHk1NControl::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQDlgHk1NControl";

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
 class ListWznmQDlgHk1NControl
 ******************************************************************************/

ListWznmQDlgHk1NControl::ListWznmQDlgHk1NControl() {
};

ListWznmQDlgHk1NControl::ListWznmQDlgHk1NControl(
			const ListWznmQDlgHk1NControl& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQDlgHk1NControl(*(src.nodes[i]));
};

ListWznmQDlgHk1NControl::~ListWznmQDlgHk1NControl() {
	clear();
};

void ListWznmQDlgHk1NControl::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQDlgHk1NControl::size() const {
	return(nodes.size());
};

void ListWznmQDlgHk1NControl::append(
			WznmQDlgHk1NControl* rec
		) {
	nodes.push_back(rec);
};

ListWznmQDlgHk1NControl& ListWznmQDlgHk1NControl::operator=(
			const ListWznmQDlgHk1NControl& src
		) {
	WznmQDlgHk1NControl* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQDlgHk1NControl(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQDlgHk1NControl::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQDlgHk1NControl";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQDlgHk1NControl
 ******************************************************************************/

TblWznmQDlgHk1NControl::TblWznmQDlgHk1NControl() {
};

TblWznmQDlgHk1NControl::~TblWznmQDlgHk1NControl() {
};

bool TblWznmQDlgHk1NControl::loadRecBySQL(
			const string& sqlstr
			, WznmQDlgHk1NControl** rec
		) {
	return false;
};

ubigint TblWznmQDlgHk1NControl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQDlgHk1NControl& rst
		) {
	return 0;
};

ubigint TblWznmQDlgHk1NControl::insertRec(
			WznmQDlgHk1NControl* rec
		) {
	return 0;
};

ubigint TblWznmQDlgHk1NControl::insertNewRec(
			WznmQDlgHk1NControl** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint hkNum
		) {
	ubigint retval = 0;
	WznmQDlgHk1NControl* _rec = NULL;

	_rec = new WznmQDlgHk1NControl(0, jref, jnum, ref, stubRef, hkNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQDlgHk1NControl::appendNewRecToRst(
			ListWznmQDlgHk1NControl& rst
			, WznmQDlgHk1NControl** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint hkNum
		) {
	ubigint retval = 0;
	WznmQDlgHk1NControl* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, hkNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQDlgHk1NControl::insertRst(
			ListWznmQDlgHk1NControl& rst
		) {
};

void TblWznmQDlgHk1NControl::updateRec(
			WznmQDlgHk1NControl* rec
		) {
};

void TblWznmQDlgHk1NControl::updateRst(
			ListWznmQDlgHk1NControl& rst
		) {
};

void TblWznmQDlgHk1NControl::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQDlgHk1NControl::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQDlgHk1NControl::loadRecByQref(
			ubigint qref
			, WznmQDlgHk1NControl** rec
		) {
	return false;
};

ubigint TblWznmQDlgHk1NControl::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQDlgHk1NControl& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQDlgHk1NControl
 ******************************************************************************/

MyTblWznmQDlgHk1NControl::MyTblWznmQDlgHk1NControl() :
			TblWznmQDlgHk1NControl()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQDlgHk1NControl::~MyTblWznmQDlgHk1NControl() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQDlgHk1NControl::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQDlgHk1NControl (jref, jnum, ref, hkNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQDlgHk1NControl SET jref = ?, jnum = ?, ref = ?, hkNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQDlgHk1NControl WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQDlgHk1NControl WHERE jref = ?", false);
};

bool MyTblWznmQDlgHk1NControl::loadRecBySQL(
			const string& sqlstr
			, WznmQDlgHk1NControl** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQDlgHk1NControl* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQDlgHk1NControl::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQDlgHk1NControl::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQDlgHk1NControl();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->hkNum = atol((char*) dbrow[4]); else _rec->hkNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQDlgHk1NControl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQDlgHk1NControl& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQDlgHk1NControl* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQDlgHk1NControl::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQDlgHk1NControl::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQDlgHk1NControl();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->hkNum = atol((char*) dbrow[4]); else rec->hkNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQDlgHk1NControl::insertRec(
			WznmQDlgHk1NControl* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->hkNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQDlgHk1NControl::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQDlgHk1NControl::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQDlgHk1NControl::insertRst(
			ListWznmQDlgHk1NControl& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQDlgHk1NControl::updateRec(
			WznmQDlgHk1NControl* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->hkNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQDlgHk1NControl::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQDlgHk1NControl::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQDlgHk1NControl::updateRst(
			ListWznmQDlgHk1NControl& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQDlgHk1NControl::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQDlgHk1NControl::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQDlgHk1NControl::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQDlgHk1NControl::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQDlgHk1NControl::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQDlgHk1NControl::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQDlgHk1NControl::loadRecByQref(
			ubigint qref
			, WznmQDlgHk1NControl** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQDlgHk1NControl WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQDlgHk1NControl::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQDlgHk1NControl& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQDlgHk1NControl WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQDlgHk1NControl
 ******************************************************************************/

PgTblWznmQDlgHk1NControl::PgTblWznmQDlgHk1NControl() :
			TblWznmQDlgHk1NControl()
			, PgTable()
		{
};

PgTblWznmQDlgHk1NControl::~PgTblWznmQDlgHk1NControl() {
};

void PgTblWznmQDlgHk1NControl::initStatements() {
	createStatement("TblWznmQDlgHk1NControl_insertRec", "INSERT INTO TblWznmQDlgHk1NControl (jref, jnum, ref, hkNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQDlgHk1NControl_updateRec", "UPDATE TblWznmQDlgHk1NControl SET jref = $1, jnum = $2, ref = $3, hkNum = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQDlgHk1NControl_removeRecByQref", "DELETE FROM TblWznmQDlgHk1NControl WHERE qref = $1", 1);
	createStatement("TblWznmQDlgHk1NControl_removeRstByJref", "DELETE FROM TblWznmQDlgHk1NControl WHERE jref = $1", 1);

	createStatement("TblWznmQDlgHk1NControl_loadRecByQref", "SELECT qref, jref, jnum, ref, hkNum FROM TblWznmQDlgHk1NControl WHERE qref = $1", 1);
	createStatement("TblWznmQDlgHk1NControl_loadRstByJref", "SELECT qref, jref, jnum, ref, hkNum FROM TblWznmQDlgHk1NControl WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQDlgHk1NControl::loadRec(
			PGresult* res
			, WznmQDlgHk1NControl** rec
		) {
	char* ptr;

	WznmQDlgHk1NControl* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQDlgHk1NControl();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "hknum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->hkNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQDlgHk1NControl::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQDlgHk1NControl& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQDlgHk1NControl* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "hknum")
		};

		while (numread < numrow) {
			rec = new WznmQDlgHk1NControl();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->hkNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQDlgHk1NControl::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQDlgHk1NControl** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQDlgHk1NControl::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQDlgHk1NControl::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQDlgHk1NControl& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQDlgHk1NControl::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQDlgHk1NControl::loadRecBySQL(
			const string& sqlstr
			, WznmQDlgHk1NControl** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQDlgHk1NControl::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQDlgHk1NControl::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQDlgHk1NControl& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQDlgHk1NControl::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQDlgHk1NControl::insertRec(
			WznmQDlgHk1NControl* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _hkNum = htonl(rec->hkNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_hkNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQDlgHk1NControl_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQDlgHk1NControl::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQDlgHk1NControl::insertRst(
			ListWznmQDlgHk1NControl& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQDlgHk1NControl::updateRec(
			WznmQDlgHk1NControl* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _hkNum = htonl(rec->hkNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_hkNum,
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

	res = PQexecPrepared(dbs, "TblWznmQDlgHk1NControl_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQDlgHk1NControl::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQDlgHk1NControl::updateRst(
			ListWznmQDlgHk1NControl& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQDlgHk1NControl::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQDlgHk1NControl_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQDlgHk1NControl::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQDlgHk1NControl::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQDlgHk1NControl_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQDlgHk1NControl::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQDlgHk1NControl::loadRecByQref(
			ubigint qref
			, WznmQDlgHk1NControl** rec
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

	return loadRecByStmt("TblWznmQDlgHk1NControl_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQDlgHk1NControl::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQDlgHk1NControl& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQDlgHk1NControl_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

