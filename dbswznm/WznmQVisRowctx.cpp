/**
	* \file WznmQVisRowctx.cpp
	* Dbs and XML wrapper for table TblWznmQVisRowctx (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQVisRowctx.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVisRowctx
 ******************************************************************************/

WznmQVisRowctx::WznmQVisRowctx(
			const ubigint qref
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const int jnumBox
			, const string Content1
			, const string Content2
			, const string Content3
		) :
			qref(qref)
			, qwr(qwr)
			, jref(jref)
			, jnum(jnum)
			, jnumBox(jnumBox)
			, Content1(Content1)
			, Content2(Content2)
			, Content3(Content3)
		{
};

void WznmQVisRowctx::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["jnumBox"] = jnumBox;
		me["cnt1"] = Content1;
		me["cnt2"] = Content2;
		me["cnt3"] = Content3;
	} else {
		me["jnumBox"] = jnumBox;
		me["Content1"] = Content1;
		me["Content2"] = Content2;
		me["Content3"] = Content3;
	};
};

void WznmQVisRowctx::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQVisRowctx";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeInt(wr, "jnumBox", jnumBox);
		writeString(wr, "cnt1", Content1);
		writeString(wr, "cnt2", Content2);
		writeString(wr, "cnt3", Content3);
	} else {
		writeInt(wr, "jnumBox", jnumBox);
		writeString(wr, "Content1", Content1);
		writeString(wr, "Content2", Content2);
		writeString(wr, "Content3", Content3);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQVisRowctx
 ******************************************************************************/

ListWznmQVisRowctx::ListWznmQVisRowctx() {
};

ListWznmQVisRowctx::ListWznmQVisRowctx(
			const ListWznmQVisRowctx& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisRowctx(*(src.nodes[i]));
};

ListWznmQVisRowctx::~ListWznmQVisRowctx() {
	clear();
};

void ListWznmQVisRowctx::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQVisRowctx::size() const {
	return(nodes.size());
};

void ListWznmQVisRowctx::append(
			WznmQVisRowctx* rec
		) {
	nodes.push_back(rec);
};

ListWznmQVisRowctx& ListWznmQVisRowctx::operator=(
			const ListWznmQVisRowctx& src
		) {
	WznmQVisRowctx* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQVisRowctx(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQVisRowctx::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQVisRowctx";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]->qwr) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQVisRowctx::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQVisRowctx";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]->qwr) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQVisRowctx
 ******************************************************************************/

TblWznmQVisRowctx::TblWznmQVisRowctx() {
};

TblWznmQVisRowctx::~TblWznmQVisRowctx() {
};

bool TblWznmQVisRowctx::loadRecBySQL(
			const string& sqlstr
			, WznmQVisRowctx** rec
		) {
	return false;
};

ubigint TblWznmQVisRowctx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVisRowctx& rst
		) {
	return 0;
};

ubigint TblWznmQVisRowctx::insertRec(
			WznmQVisRowctx* rec
		) {
	return 0;
};

ubigint TblWznmQVisRowctx::insertNewRec(
			WznmQVisRowctx** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const int jnumBox
			, const string Content1
			, const string Content2
			, const string Content3
		) {
	ubigint retval = 0;
	WznmQVisRowctx* _rec = NULL;

	_rec = new WznmQVisRowctx(0, qwr, jref, jnum, jnumBox, Content1, Content2, Content3);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQVisRowctx::appendNewRecToRst(
			ListWznmQVisRowctx& rst
			, WznmQVisRowctx** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const int jnumBox
			, const string Content1
			, const string Content2
			, const string Content3
		) {
	ubigint retval = 0;
	WznmQVisRowctx* _rec = NULL;

	retval = insertNewRec(&_rec, qwr, jref, jnum, jnumBox, Content1, Content2, Content3);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQVisRowctx::insertRst(
			ListWznmQVisRowctx& rst
		) {
};

void TblWznmQVisRowctx::updateRec(
			WznmQVisRowctx* rec
		) {
};

void TblWznmQVisRowctx::updateRst(
			ListWznmQVisRowctx& rst
		) {
};

void TblWznmQVisRowctx::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQVisRowctx::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQVisRowctx::loadRecByQref(
			ubigint qref
			, WznmQVisRowctx** rec
		) {
	return false;
};

ubigint TblWznmQVisRowctx::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVisRowctx& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQVisRowctx
 ******************************************************************************/

MyTblWznmQVisRowctx::MyTblWznmQVisRowctx() :
			TblWznmQVisRowctx()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQVisRowctx::~MyTblWznmQVisRowctx() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQVisRowctx::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQVisRowctx (qwr, jref, jnum) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQVisRowctx SET qwr = ?, jref = ?, jnum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQVisRowctx WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQVisRowctx WHERE jref = ?", false);
};

bool MyTblWznmQVisRowctx::loadRecBySQL(
			const string& sqlstr
			, WznmQVisRowctx** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQVisRowctx* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVisRowctx::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVisRowctx::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQVisRowctx();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->qwr = (atoi((char*) dbrow[1]) != 0); else _rec->qwr = false;
		if (dbrow[2]) _rec->jref = atoll((char*) dbrow[2]); else _rec->jref = 0;
		if (dbrow[3]) _rec->jnum = atol((char*) dbrow[3]); else _rec->jnum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQVisRowctx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVisRowctx& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQVisRowctx* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVisRowctx::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVisRowctx::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQVisRowctx();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->qwr = (atoi((char*) dbrow[1]) != 0); else rec->qwr = false;
			if (dbrow[2]) rec->jref = atoll((char*) dbrow[2]); else rec->jref = 0;
			if (dbrow[3]) rec->jnum = atol((char*) dbrow[3]); else rec->jnum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQVisRowctx::insertRec(
			WznmQVisRowctx* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQVisRowctx::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQVisRowctx::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQVisRowctx::insertRst(
			ListWznmQVisRowctx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQVisRowctx::updateRec(
			WznmQVisRowctx* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQVisRowctx::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQVisRowctx::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVisRowctx::updateRst(
			ListWznmQVisRowctx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQVisRowctx::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQVisRowctx::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQVisRowctx::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVisRowctx::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQVisRowctx::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQVisRowctx::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQVisRowctx::loadRecByQref(
			ubigint qref
			, WznmQVisRowctx** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQVisRowctx WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQVisRowctx::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVisRowctx& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQVisRowctx WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQVisRowctx
 ******************************************************************************/

PgTblWznmQVisRowctx::PgTblWznmQVisRowctx() :
			TblWznmQVisRowctx()
			, PgTable()
		{
};

PgTblWznmQVisRowctx::~PgTblWznmQVisRowctx() {
};

void PgTblWznmQVisRowctx::initStatements() {
	createStatement("TblWznmQVisRowctx_insertRec", "INSERT INTO TblWznmQVisRowctx (qwr, jref, jnum) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWznmQVisRowctx_updateRec", "UPDATE TblWznmQVisRowctx SET qwr = $1, jref = $2, jnum = $3 WHERE qref = $4", 4);
	createStatement("TblWznmQVisRowctx_removeRecByQref", "DELETE FROM TblWznmQVisRowctx WHERE qref = $1", 1);
	createStatement("TblWznmQVisRowctx_removeRstByJref", "DELETE FROM TblWznmQVisRowctx WHERE jref = $1", 1);

	createStatement("TblWznmQVisRowctx_loadRecByQref", "SELECT qref, qwr, jref, jnum FROM TblWznmQVisRowctx WHERE qref = $1", 1);
	createStatement("TblWznmQVisRowctx_loadRstByJref", "SELECT qref, qwr, jref, jnum FROM TblWznmQVisRowctx WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQVisRowctx::loadRec(
			PGresult* res
			, WznmQVisRowctx** rec
		) {
	char* ptr;

	WznmQVisRowctx* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQVisRowctx();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->qwr = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->jnum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQVisRowctx::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQVisRowctx& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQVisRowctx* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum")
		};

		while (numread < numrow) {
			rec = new WznmQVisRowctx();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->qwr = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->jnum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQVisRowctx::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQVisRowctx** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVisRowctx::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVisRowctx::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQVisRowctx& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVisRowctx::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQVisRowctx::loadRecBySQL(
			const string& sqlstr
			, WznmQVisRowctx** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVisRowctx::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVisRowctx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVisRowctx& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVisRowctx::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQVisRowctx::insertRec(
			WznmQVisRowctx* rec
		) {
	PGresult* res;
	char* ptr;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQVisRowctx_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVisRowctx::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQVisRowctx::insertRst(
			ListWznmQVisRowctx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQVisRowctx::updateRec(
			WznmQVisRowctx* rec
		) {
	PGresult* res;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQVisRowctx_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVisRowctx::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVisRowctx::updateRst(
			ListWznmQVisRowctx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQVisRowctx::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQVisRowctx_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVisRowctx::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVisRowctx::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQVisRowctx_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVisRowctx::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQVisRowctx::loadRecByQref(
			ubigint qref
			, WznmQVisRowctx** rec
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

	return loadRecByStmt("TblWznmQVisRowctx_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQVisRowctx::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVisRowctx& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQVisRowctx_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
