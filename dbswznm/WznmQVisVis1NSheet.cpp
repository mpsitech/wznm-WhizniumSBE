/**
	* \file WznmQVisVis1NSheet.cpp
	* Dbs and XML wrapper for table TblWznmQVisVis1NSheet (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQVisVis1NSheet.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVisVis1NSheet
 ******************************************************************************/

WznmQVisVis1NSheet::WznmQVisVis1NSheet(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint visNum
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, stubRef(stubRef)
			, visNum(visNum)
		{
};

void WznmQVisVis1NSheet::writeJSON(
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

void WznmQVisVis1NSheet::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQVisVis1NSheet";

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
 class ListWznmQVisVis1NSheet
 ******************************************************************************/

ListWznmQVisVis1NSheet::ListWznmQVisVis1NSheet() {
};

ListWznmQVisVis1NSheet::ListWznmQVisVis1NSheet(
			const ListWznmQVisVis1NSheet& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisVis1NSheet(*(src.nodes[i]));
};

ListWznmQVisVis1NSheet::~ListWznmQVisVis1NSheet() {
	clear();
};

void ListWznmQVisVis1NSheet::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQVisVis1NSheet::size() const {
	return(nodes.size());
};

void ListWznmQVisVis1NSheet::append(
			WznmQVisVis1NSheet* rec
		) {
	nodes.push_back(rec);
};

ListWznmQVisVis1NSheet& ListWznmQVisVis1NSheet::operator=(
			const ListWznmQVisVis1NSheet& src
		) {
	WznmQVisVis1NSheet* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQVisVis1NSheet(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQVisVis1NSheet::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQVisVis1NSheet";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQVisVis1NSheet::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQVisVis1NSheet";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQVisVis1NSheet
 ******************************************************************************/

TblWznmQVisVis1NSheet::TblWznmQVisVis1NSheet() {
};

TblWznmQVisVis1NSheet::~TblWznmQVisVis1NSheet() {
};

bool TblWznmQVisVis1NSheet::loadRecBySQL(
			const string& sqlstr
			, WznmQVisVis1NSheet** rec
		) {
	return false;
};

ubigint TblWznmQVisVis1NSheet::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVisVis1NSheet& rst
		) {
	return 0;
};

ubigint TblWznmQVisVis1NSheet::insertRec(
			WznmQVisVis1NSheet* rec
		) {
	return 0;
};

ubigint TblWznmQVisVis1NSheet::insertNewRec(
			WznmQVisVis1NSheet** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint visNum
		) {
	ubigint retval = 0;
	WznmQVisVis1NSheet* _rec = NULL;

	_rec = new WznmQVisVis1NSheet(0, jref, jnum, ref, stubRef, visNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQVisVis1NSheet::appendNewRecToRst(
			ListWznmQVisVis1NSheet& rst
			, WznmQVisVis1NSheet** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint visNum
		) {
	ubigint retval = 0;
	WznmQVisVis1NSheet* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, visNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQVisVis1NSheet::insertRst(
			ListWznmQVisVis1NSheet& rst
		) {
};

void TblWznmQVisVis1NSheet::updateRec(
			WznmQVisVis1NSheet* rec
		) {
};

void TblWznmQVisVis1NSheet::updateRst(
			ListWznmQVisVis1NSheet& rst
		) {
};

void TblWznmQVisVis1NSheet::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQVisVis1NSheet::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQVisVis1NSheet::loadRecByQref(
			ubigint qref
			, WznmQVisVis1NSheet** rec
		) {
	return false;
};

ubigint TblWznmQVisVis1NSheet::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVisVis1NSheet& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQVisVis1NSheet
 ******************************************************************************/

MyTblWznmQVisVis1NSheet::MyTblWznmQVisVis1NSheet() :
			TblWznmQVisVis1NSheet()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQVisVis1NSheet::~MyTblWznmQVisVis1NSheet() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQVisVis1NSheet::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQVisVis1NSheet (jref, jnum, ref, visNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQVisVis1NSheet SET jref = ?, jnum = ?, ref = ?, visNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQVisVis1NSheet WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQVisVis1NSheet WHERE jref = ?", false);
};

bool MyTblWznmQVisVis1NSheet::loadRecBySQL(
			const string& sqlstr
			, WznmQVisVis1NSheet** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQVisVis1NSheet* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVisVis1NSheet::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVisVis1NSheet::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQVisVis1NSheet();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->visNum = atol((char*) dbrow[4]); else _rec->visNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQVisVis1NSheet::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVisVis1NSheet& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQVisVis1NSheet* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVisVis1NSheet::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVisVis1NSheet::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQVisVis1NSheet();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->visNum = atol((char*) dbrow[4]); else rec->visNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQVisVis1NSheet::insertRec(
			WznmQVisVis1NSheet* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->visNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQVisVis1NSheet::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQVisVis1NSheet::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQVisVis1NSheet::insertRst(
			ListWznmQVisVis1NSheet& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQVisVis1NSheet::updateRec(
			WznmQVisVis1NSheet* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->visNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQVisVis1NSheet::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQVisVis1NSheet::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVisVis1NSheet::updateRst(
			ListWznmQVisVis1NSheet& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQVisVis1NSheet::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQVisVis1NSheet::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQVisVis1NSheet::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVisVis1NSheet::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQVisVis1NSheet::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQVisVis1NSheet::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQVisVis1NSheet::loadRecByQref(
			ubigint qref
			, WznmQVisVis1NSheet** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQVisVis1NSheet WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQVisVis1NSheet::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVisVis1NSheet& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQVisVis1NSheet WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQVisVis1NSheet
 ******************************************************************************/

PgTblWznmQVisVis1NSheet::PgTblWznmQVisVis1NSheet() :
			TblWznmQVisVis1NSheet()
			, PgTable()
		{
};

PgTblWznmQVisVis1NSheet::~PgTblWznmQVisVis1NSheet() {
};

void PgTblWznmQVisVis1NSheet::initStatements() {
	createStatement("TblWznmQVisVis1NSheet_insertRec", "INSERT INTO TblWznmQVisVis1NSheet (jref, jnum, ref, visNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQVisVis1NSheet_updateRec", "UPDATE TblWznmQVisVis1NSheet SET jref = $1, jnum = $2, ref = $3, visNum = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQVisVis1NSheet_removeRecByQref", "DELETE FROM TblWznmQVisVis1NSheet WHERE qref = $1", 1);
	createStatement("TblWznmQVisVis1NSheet_removeRstByJref", "DELETE FROM TblWznmQVisVis1NSheet WHERE jref = $1", 1);

	createStatement("TblWznmQVisVis1NSheet_loadRecByQref", "SELECT qref, jref, jnum, ref, visNum FROM TblWznmQVisVis1NSheet WHERE qref = $1", 1);
	createStatement("TblWznmQVisVis1NSheet_loadRstByJref", "SELECT qref, jref, jnum, ref, visNum FROM TblWznmQVisVis1NSheet WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQVisVis1NSheet::loadRec(
			PGresult* res
			, WznmQVisVis1NSheet** rec
		) {
	char* ptr;

	WznmQVisVis1NSheet* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQVisVis1NSheet();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "visnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->visNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQVisVis1NSheet::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQVisVis1NSheet& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQVisVis1NSheet* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "visnum")
		};

		while (numread < numrow) {
			rec = new WznmQVisVis1NSheet();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->visNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQVisVis1NSheet::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQVisVis1NSheet** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVisVis1NSheet::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVisVis1NSheet::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQVisVis1NSheet& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVisVis1NSheet::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQVisVis1NSheet::loadRecBySQL(
			const string& sqlstr
			, WznmQVisVis1NSheet** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVisVis1NSheet::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVisVis1NSheet::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVisVis1NSheet& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVisVis1NSheet::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQVisVis1NSheet::insertRec(
			WznmQVisVis1NSheet* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _visNum = htonl(rec->visNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_visNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQVisVis1NSheet_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVisVis1NSheet::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQVisVis1NSheet::insertRst(
			ListWznmQVisVis1NSheet& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQVisVis1NSheet::updateRec(
			WznmQVisVis1NSheet* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _visNum = htonl(rec->visNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_visNum,
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

	res = PQexecPrepared(dbs, "TblWznmQVisVis1NSheet_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVisVis1NSheet::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVisVis1NSheet::updateRst(
			ListWznmQVisVis1NSheet& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQVisVis1NSheet::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQVisVis1NSheet_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVisVis1NSheet::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVisVis1NSheet::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQVisVis1NSheet_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVisVis1NSheet::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQVisVis1NSheet::loadRecByQref(
			ubigint qref
			, WznmQVisVis1NSheet** rec
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

	return loadRecByStmt("TblWznmQVisVis1NSheet_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQVisVis1NSheet::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVisVis1NSheet& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQVisVis1NSheet_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
