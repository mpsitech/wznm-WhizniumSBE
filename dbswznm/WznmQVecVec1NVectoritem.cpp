/**
	* \file WznmQVecVec1NVectoritem.cpp
	* Dbs and XML wrapper for table TblWznmQVecVec1NVectoritem (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQVecVec1NVectoritem.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVecVec1NVectoritem
 ******************************************************************************/

WznmQVecVec1NVectoritem::WznmQVecVec1NVectoritem(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint vecNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->vecNum = vecNum;
};

void WznmQVecVec1NVectoritem::writeJSON(
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

void WznmQVecVec1NVectoritem::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQVecVec1NVectoritem";

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
 class ListWznmQVecVec1NVectoritem
 ******************************************************************************/

ListWznmQVecVec1NVectoritem::ListWznmQVecVec1NVectoritem() {
};

ListWznmQVecVec1NVectoritem::ListWznmQVecVec1NVectoritem(
			const ListWznmQVecVec1NVectoritem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVecVec1NVectoritem(*(src.nodes[i]));
};

ListWznmQVecVec1NVectoritem::~ListWznmQVecVec1NVectoritem() {
	clear();
};

void ListWznmQVecVec1NVectoritem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQVecVec1NVectoritem::size() const {
	return(nodes.size());
};

void ListWznmQVecVec1NVectoritem::append(
			WznmQVecVec1NVectoritem* rec
		) {
	nodes.push_back(rec);
};

ListWznmQVecVec1NVectoritem& ListWznmQVecVec1NVectoritem::operator=(
			const ListWznmQVecVec1NVectoritem& src
		) {
	WznmQVecVec1NVectoritem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQVecVec1NVectoritem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQVecVec1NVectoritem::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQVecVec1NVectoritem";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQVecVec1NVectoritem::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQVecVec1NVectoritem";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQVecVec1NVectoritem
 ******************************************************************************/

TblWznmQVecVec1NVectoritem::TblWznmQVecVec1NVectoritem() {
};

TblWznmQVecVec1NVectoritem::~TblWznmQVecVec1NVectoritem() {
};

bool TblWznmQVecVec1NVectoritem::loadRecBySQL(
			const string& sqlstr
			, WznmQVecVec1NVectoritem** rec
		) {
	return false;
};

ubigint TblWznmQVecVec1NVectoritem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVecVec1NVectoritem& rst
		) {
	return 0;
};

ubigint TblWznmQVecVec1NVectoritem::insertRec(
			WznmQVecVec1NVectoritem* rec
		) {
	return 0;
};

ubigint TblWznmQVecVec1NVectoritem::insertNewRec(
			WznmQVecVec1NVectoritem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint vecNum
		) {
	ubigint retval = 0;
	WznmQVecVec1NVectoritem* _rec = NULL;

	_rec = new WznmQVecVec1NVectoritem(0, jref, jnum, ref, stubRef, vecNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQVecVec1NVectoritem::appendNewRecToRst(
			ListWznmQVecVec1NVectoritem& rst
			, WznmQVecVec1NVectoritem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint vecNum
		) {
	ubigint retval = 0;
	WznmQVecVec1NVectoritem* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, vecNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQVecVec1NVectoritem::insertRst(
			ListWznmQVecVec1NVectoritem& rst
		) {
};

void TblWznmQVecVec1NVectoritem::updateRec(
			WznmQVecVec1NVectoritem* rec
		) {
};

void TblWznmQVecVec1NVectoritem::updateRst(
			ListWznmQVecVec1NVectoritem& rst
		) {
};

void TblWznmQVecVec1NVectoritem::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQVecVec1NVectoritem::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQVecVec1NVectoritem::loadRecByQref(
			ubigint qref
			, WznmQVecVec1NVectoritem** rec
		) {
	return false;
};

ubigint TblWznmQVecVec1NVectoritem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVecVec1NVectoritem& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQVecVec1NVectoritem
 ******************************************************************************/

MyTblWznmQVecVec1NVectoritem::MyTblWznmQVecVec1NVectoritem() :
			TblWznmQVecVec1NVectoritem()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQVecVec1NVectoritem::~MyTblWznmQVecVec1NVectoritem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQVecVec1NVectoritem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQVecVec1NVectoritem (jref, jnum, ref, vecNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQVecVec1NVectoritem SET jref = ?, jnum = ?, ref = ?, vecNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQVecVec1NVectoritem WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQVecVec1NVectoritem WHERE jref = ?", false);
};

bool MyTblWznmQVecVec1NVectoritem::loadRecBySQL(
			const string& sqlstr
			, WznmQVecVec1NVectoritem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQVecVec1NVectoritem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVecVec1NVectoritem::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVecVec1NVectoritem::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQVecVec1NVectoritem();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->vecNum = atol((char*) dbrow[4]); else _rec->vecNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQVecVec1NVectoritem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVecVec1NVectoritem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQVecVec1NVectoritem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVecVec1NVectoritem::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVecVec1NVectoritem::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQVecVec1NVectoritem();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->vecNum = atol((char*) dbrow[4]); else rec->vecNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQVecVec1NVectoritem::insertRec(
			WznmQVecVec1NVectoritem* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->vecNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQVecVec1NVectoritem::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQVecVec1NVectoritem::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQVecVec1NVectoritem::insertRst(
			ListWznmQVecVec1NVectoritem& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQVecVec1NVectoritem::updateRec(
			WznmQVecVec1NVectoritem* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->vecNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQVecVec1NVectoritem::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQVecVec1NVectoritem::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVecVec1NVectoritem::updateRst(
			ListWznmQVecVec1NVectoritem& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQVecVec1NVectoritem::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQVecVec1NVectoritem::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQVecVec1NVectoritem::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVecVec1NVectoritem::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQVecVec1NVectoritem::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQVecVec1NVectoritem::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQVecVec1NVectoritem::loadRecByQref(
			ubigint qref
			, WznmQVecVec1NVectoritem** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQVecVec1NVectoritem WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQVecVec1NVectoritem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVecVec1NVectoritem& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQVecVec1NVectoritem WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQVecVec1NVectoritem
 ******************************************************************************/

PgTblWznmQVecVec1NVectoritem::PgTblWznmQVecVec1NVectoritem() :
			TblWznmQVecVec1NVectoritem()
			, PgTable()
		{
};

PgTblWznmQVecVec1NVectoritem::~PgTblWznmQVecVec1NVectoritem() {
};

void PgTblWznmQVecVec1NVectoritem::initStatements() {
	createStatement("TblWznmQVecVec1NVectoritem_insertRec", "INSERT INTO TblWznmQVecVec1NVectoritem (jref, jnum, ref, vecNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQVecVec1NVectoritem_updateRec", "UPDATE TblWznmQVecVec1NVectoritem SET jref = $1, jnum = $2, ref = $3, vecNum = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQVecVec1NVectoritem_removeRecByQref", "DELETE FROM TblWznmQVecVec1NVectoritem WHERE qref = $1", 1);
	createStatement("TblWznmQVecVec1NVectoritem_removeRstByJref", "DELETE FROM TblWznmQVecVec1NVectoritem WHERE jref = $1", 1);

	createStatement("TblWznmQVecVec1NVectoritem_loadRecByQref", "SELECT qref, jref, jnum, ref, vecNum FROM TblWznmQVecVec1NVectoritem WHERE qref = $1", 1);
	createStatement("TblWznmQVecVec1NVectoritem_loadRstByJref", "SELECT qref, jref, jnum, ref, vecNum FROM TblWznmQVecVec1NVectoritem WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQVecVec1NVectoritem::loadRec(
			PGresult* res
			, WznmQVecVec1NVectoritem** rec
		) {
	char* ptr;

	WznmQVecVec1NVectoritem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQVecVec1NVectoritem();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "vecnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->vecNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQVecVec1NVectoritem::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQVecVec1NVectoritem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQVecVec1NVectoritem* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "vecnum")
		};

		while (numread < numrow) {
			rec = new WznmQVecVec1NVectoritem();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->vecNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQVecVec1NVectoritem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQVecVec1NVectoritem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVecVec1NVectoritem::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVecVec1NVectoritem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQVecVec1NVectoritem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVecVec1NVectoritem::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQVecVec1NVectoritem::loadRecBySQL(
			const string& sqlstr
			, WznmQVecVec1NVectoritem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVecVec1NVectoritem::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVecVec1NVectoritem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVecVec1NVectoritem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVecVec1NVectoritem::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQVecVec1NVectoritem::insertRec(
			WznmQVecVec1NVectoritem* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _vecNum = htonl(rec->vecNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_vecNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQVecVec1NVectoritem_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVecVec1NVectoritem::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQVecVec1NVectoritem::insertRst(
			ListWznmQVecVec1NVectoritem& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQVecVec1NVectoritem::updateRec(
			WznmQVecVec1NVectoritem* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _vecNum = htonl(rec->vecNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_vecNum,
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

	res = PQexecPrepared(dbs, "TblWznmQVecVec1NVectoritem_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVecVec1NVectoritem::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVecVec1NVectoritem::updateRst(
			ListWznmQVecVec1NVectoritem& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQVecVec1NVectoritem::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQVecVec1NVectoritem_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVecVec1NVectoritem::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVecVec1NVectoritem::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQVecVec1NVectoritem_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVecVec1NVectoritem::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQVecVec1NVectoritem::loadRecByQref(
			ubigint qref
			, WznmQVecVec1NVectoritem** rec
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

	return loadRecByStmt("TblWznmQVecVec1NVectoritem_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQVecVec1NVectoritem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVecVec1NVectoritem& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQVecVec1NVectoritem_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
