/**
	* \file WznmQQryQry1NQuerycol.cpp
	* Dbs and XML wrapper for table TblWznmQQryQry1NQuerycol (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQQryQry1NQuerycol.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQryQry1NQuerycol
 ******************************************************************************/

WznmQQryQry1NQuerycol::WznmQQryQry1NQuerycol(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint qryNum
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, stubRef(stubRef)
			, qryNum(qryNum)
		{
};

void WznmQQryQry1NQuerycol::writeJSON(
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

void WznmQQryQry1NQuerycol::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQQryQry1NQuerycol";

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
 class ListWznmQQryQry1NQuerycol
 ******************************************************************************/

ListWznmQQryQry1NQuerycol::ListWznmQQryQry1NQuerycol() {
};

ListWznmQQryQry1NQuerycol::ListWznmQQryQry1NQuerycol(
			const ListWznmQQryQry1NQuerycol& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryQry1NQuerycol(*(src.nodes[i]));
};

ListWznmQQryQry1NQuerycol::~ListWznmQQryQry1NQuerycol() {
	clear();
};

void ListWznmQQryQry1NQuerycol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQQryQry1NQuerycol::size() const {
	return(nodes.size());
};

void ListWznmQQryQry1NQuerycol::append(
			WznmQQryQry1NQuerycol* rec
		) {
	nodes.push_back(rec);
};

ListWznmQQryQry1NQuerycol& ListWznmQQryQry1NQuerycol::operator=(
			const ListWznmQQryQry1NQuerycol& src
		) {
	WznmQQryQry1NQuerycol* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQQryQry1NQuerycol(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQQryQry1NQuerycol::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQQryQry1NQuerycol";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQQryQry1NQuerycol::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQQryQry1NQuerycol";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQQryQry1NQuerycol
 ******************************************************************************/

TblWznmQQryQry1NQuerycol::TblWznmQQryQry1NQuerycol() {
};

TblWznmQQryQry1NQuerycol::~TblWznmQQryQry1NQuerycol() {
};

bool TblWznmQQryQry1NQuerycol::loadRecBySQL(
			const string& sqlstr
			, WznmQQryQry1NQuerycol** rec
		) {
	return false;
};

ubigint TblWznmQQryQry1NQuerycol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryQry1NQuerycol& rst
		) {
	return 0;
};

ubigint TblWznmQQryQry1NQuerycol::insertRec(
			WznmQQryQry1NQuerycol* rec
		) {
	return 0;
};

ubigint TblWznmQQryQry1NQuerycol::insertNewRec(
			WznmQQryQry1NQuerycol** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint qryNum
		) {
	ubigint retval = 0;
	WznmQQryQry1NQuerycol* _rec = NULL;

	_rec = new WznmQQryQry1NQuerycol(0, jref, jnum, ref, stubRef, qryNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQQryQry1NQuerycol::appendNewRecToRst(
			ListWznmQQryQry1NQuerycol& rst
			, WznmQQryQry1NQuerycol** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint qryNum
		) {
	ubigint retval = 0;
	WznmQQryQry1NQuerycol* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, qryNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQQryQry1NQuerycol::insertRst(
			ListWznmQQryQry1NQuerycol& rst
		) {
};

void TblWznmQQryQry1NQuerycol::updateRec(
			WznmQQryQry1NQuerycol* rec
		) {
};

void TblWznmQQryQry1NQuerycol::updateRst(
			ListWznmQQryQry1NQuerycol& rst
		) {
};

void TblWznmQQryQry1NQuerycol::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQQryQry1NQuerycol::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQQryQry1NQuerycol::loadRecByQref(
			ubigint qref
			, WznmQQryQry1NQuerycol** rec
		) {
	return false;
};

ubigint TblWznmQQryQry1NQuerycol::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryQry1NQuerycol& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQQryQry1NQuerycol
 ******************************************************************************/

MyTblWznmQQryQry1NQuerycol::MyTblWznmQQryQry1NQuerycol() :
			TblWznmQQryQry1NQuerycol()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQQryQry1NQuerycol::~MyTblWznmQQryQry1NQuerycol() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQQryQry1NQuerycol::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQQryQry1NQuerycol (jref, jnum, ref, qryNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQQryQry1NQuerycol SET jref = ?, jnum = ?, ref = ?, qryNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQQryQry1NQuerycol WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQQryQry1NQuerycol WHERE jref = ?", false);
};

bool MyTblWznmQQryQry1NQuerycol::loadRecBySQL(
			const string& sqlstr
			, WznmQQryQry1NQuerycol** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQQryQry1NQuerycol* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQryQry1NQuerycol::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQryQry1NQuerycol::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQQryQry1NQuerycol();

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

ubigint MyTblWznmQQryQry1NQuerycol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryQry1NQuerycol& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQQryQry1NQuerycol* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQryQry1NQuerycol::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQryQry1NQuerycol::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQQryQry1NQuerycol();

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

ubigint MyTblWznmQQryQry1NQuerycol::insertRec(
			WznmQQryQry1NQuerycol* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->qryNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQQryQry1NQuerycol::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQQryQry1NQuerycol::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQQryQry1NQuerycol::insertRst(
			ListWznmQQryQry1NQuerycol& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQQryQry1NQuerycol::updateRec(
			WznmQQryQry1NQuerycol* rec
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
		string dbms = "MyTblWznmQQryQry1NQuerycol::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQQryQry1NQuerycol::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQryQry1NQuerycol::updateRst(
			ListWznmQQryQry1NQuerycol& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQQryQry1NQuerycol::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQQryQry1NQuerycol::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQQryQry1NQuerycol::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQryQry1NQuerycol::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQQryQry1NQuerycol::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQQryQry1NQuerycol::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQQryQry1NQuerycol::loadRecByQref(
			ubigint qref
			, WznmQQryQry1NQuerycol** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQQryQry1NQuerycol WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQQryQry1NQuerycol::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryQry1NQuerycol& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQQryQry1NQuerycol WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQQryQry1NQuerycol
 ******************************************************************************/

PgTblWznmQQryQry1NQuerycol::PgTblWznmQQryQry1NQuerycol() :
			TblWznmQQryQry1NQuerycol()
			, PgTable()
		{
};

PgTblWznmQQryQry1NQuerycol::~PgTblWznmQQryQry1NQuerycol() {
};

void PgTblWznmQQryQry1NQuerycol::initStatements() {
	createStatement("TblWznmQQryQry1NQuerycol_insertRec", "INSERT INTO TblWznmQQryQry1NQuerycol (jref, jnum, ref, qryNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQQryQry1NQuerycol_updateRec", "UPDATE TblWznmQQryQry1NQuerycol SET jref = $1, jnum = $2, ref = $3, qryNum = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQQryQry1NQuerycol_removeRecByQref", "DELETE FROM TblWznmQQryQry1NQuerycol WHERE qref = $1", 1);
	createStatement("TblWznmQQryQry1NQuerycol_removeRstByJref", "DELETE FROM TblWznmQQryQry1NQuerycol WHERE jref = $1", 1);

	createStatement("TblWznmQQryQry1NQuerycol_loadRecByQref", "SELECT qref, jref, jnum, ref, qryNum FROM TblWznmQQryQry1NQuerycol WHERE qref = $1", 1);
	createStatement("TblWznmQQryQry1NQuerycol_loadRstByJref", "SELECT qref, jref, jnum, ref, qryNum FROM TblWznmQQryQry1NQuerycol WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQQryQry1NQuerycol::loadRec(
			PGresult* res
			, WznmQQryQry1NQuerycol** rec
		) {
	char* ptr;

	WznmQQryQry1NQuerycol* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQQryQry1NQuerycol();

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

ubigint PgTblWznmQQryQry1NQuerycol::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQQryQry1NQuerycol& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQQryQry1NQuerycol* rec;

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
			rec = new WznmQQryQry1NQuerycol();

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

bool PgTblWznmQQryQry1NQuerycol::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQQryQry1NQuerycol** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryQry1NQuerycol::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQryQry1NQuerycol::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQQryQry1NQuerycol& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryQry1NQuerycol::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQQryQry1NQuerycol::loadRecBySQL(
			const string& sqlstr
			, WznmQQryQry1NQuerycol** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQryQry1NQuerycol::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQryQry1NQuerycol::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryQry1NQuerycol& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQryQry1NQuerycol::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQQryQry1NQuerycol::insertRec(
			WznmQQryQry1NQuerycol* rec
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

	res = PQexecPrepared(dbs, "TblWznmQQryQry1NQuerycol_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryQry1NQuerycol::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQQryQry1NQuerycol::insertRst(
			ListWznmQQryQry1NQuerycol& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQQryQry1NQuerycol::updateRec(
			WznmQQryQry1NQuerycol* rec
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

	res = PQexecPrepared(dbs, "TblWznmQQryQry1NQuerycol_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryQry1NQuerycol::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQryQry1NQuerycol::updateRst(
			ListWznmQQryQry1NQuerycol& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQQryQry1NQuerycol::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQQryQry1NQuerycol_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryQry1NQuerycol::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQryQry1NQuerycol::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQQryQry1NQuerycol_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryQry1NQuerycol::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQQryQry1NQuerycol::loadRecByQref(
			ubigint qref
			, WznmQQryQry1NQuerycol** rec
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

	return loadRecByStmt("TblWznmQQryQry1NQuerycol_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQQryQry1NQuerycol::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryQry1NQuerycol& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQQryQry1NQuerycol_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
