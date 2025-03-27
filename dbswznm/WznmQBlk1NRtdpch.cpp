/**
	* \file WznmQBlk1NRtdpch.cpp
	* Dbs and XML wrapper for table TblWznmQBlk1NRtdpch (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQBlk1NRtdpch.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQBlk1NRtdpch
 ******************************************************************************/

WznmQBlk1NRtdpch::WznmQBlk1NRtdpch(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, stubRef(stubRef)
		{
};

void WznmQBlk1NRtdpch::writeJSON(
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

void WznmQBlk1NRtdpch::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQBlk1NRtdpch";

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
 class ListWznmQBlk1NRtdpch
 ******************************************************************************/

ListWznmQBlk1NRtdpch::ListWznmQBlk1NRtdpch() {
};

ListWznmQBlk1NRtdpch::ListWznmQBlk1NRtdpch(
			const ListWznmQBlk1NRtdpch& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBlk1NRtdpch(*(src.nodes[i]));
};

ListWznmQBlk1NRtdpch::~ListWznmQBlk1NRtdpch() {
	clear();
};

void ListWznmQBlk1NRtdpch::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQBlk1NRtdpch::size() const {
	return(nodes.size());
};

void ListWznmQBlk1NRtdpch::append(
			WznmQBlk1NRtdpch* rec
		) {
	nodes.push_back(rec);
};

ListWznmQBlk1NRtdpch& ListWznmQBlk1NRtdpch::operator=(
			const ListWznmQBlk1NRtdpch& src
		) {
	WznmQBlk1NRtdpch* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQBlk1NRtdpch(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQBlk1NRtdpch::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQBlk1NRtdpch";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQBlk1NRtdpch::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQBlk1NRtdpch";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQBlk1NRtdpch
 ******************************************************************************/

TblWznmQBlk1NRtdpch::TblWznmQBlk1NRtdpch() {
};

TblWznmQBlk1NRtdpch::~TblWznmQBlk1NRtdpch() {
};

bool TblWznmQBlk1NRtdpch::loadRecBySQL(
			const string& sqlstr
			, WznmQBlk1NRtdpch** rec
		) {
	return false;
};

ubigint TblWznmQBlk1NRtdpch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBlk1NRtdpch& rst
		) {
	return 0;
};

ubigint TblWznmQBlk1NRtdpch::insertRec(
			WznmQBlk1NRtdpch* rec
		) {
	return 0;
};

ubigint TblWznmQBlk1NRtdpch::insertNewRec(
			WznmQBlk1NRtdpch** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQBlk1NRtdpch* _rec = NULL;

	_rec = new WznmQBlk1NRtdpch(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQBlk1NRtdpch::appendNewRecToRst(
			ListWznmQBlk1NRtdpch& rst
			, WznmQBlk1NRtdpch** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WznmQBlk1NRtdpch* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQBlk1NRtdpch::insertRst(
			ListWznmQBlk1NRtdpch& rst
		) {
};

void TblWznmQBlk1NRtdpch::updateRec(
			WznmQBlk1NRtdpch* rec
		) {
};

void TblWznmQBlk1NRtdpch::updateRst(
			ListWznmQBlk1NRtdpch& rst
		) {
};

void TblWznmQBlk1NRtdpch::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQBlk1NRtdpch::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQBlk1NRtdpch::loadRecByQref(
			ubigint qref
			, WznmQBlk1NRtdpch** rec
		) {
	return false;
};

ubigint TblWznmQBlk1NRtdpch::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBlk1NRtdpch& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQBlk1NRtdpch
 ******************************************************************************/

MyTblWznmQBlk1NRtdpch::MyTblWznmQBlk1NRtdpch() :
			TblWznmQBlk1NRtdpch()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQBlk1NRtdpch::~MyTblWznmQBlk1NRtdpch() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQBlk1NRtdpch::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQBlk1NRtdpch (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQBlk1NRtdpch SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQBlk1NRtdpch WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQBlk1NRtdpch WHERE jref = ?", false);
};

bool MyTblWznmQBlk1NRtdpch::loadRecBySQL(
			const string& sqlstr
			, WznmQBlk1NRtdpch** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQBlk1NRtdpch* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQBlk1NRtdpch::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQBlk1NRtdpch::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQBlk1NRtdpch();

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

ubigint MyTblWznmQBlk1NRtdpch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBlk1NRtdpch& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQBlk1NRtdpch* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQBlk1NRtdpch::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQBlk1NRtdpch::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQBlk1NRtdpch();

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

ubigint MyTblWznmQBlk1NRtdpch::insertRec(
			WznmQBlk1NRtdpch* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQBlk1NRtdpch::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQBlk1NRtdpch::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQBlk1NRtdpch::insertRst(
			ListWznmQBlk1NRtdpch& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQBlk1NRtdpch::updateRec(
			WznmQBlk1NRtdpch* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQBlk1NRtdpch::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQBlk1NRtdpch::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQBlk1NRtdpch::updateRst(
			ListWznmQBlk1NRtdpch& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQBlk1NRtdpch::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQBlk1NRtdpch::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQBlk1NRtdpch::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQBlk1NRtdpch::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQBlk1NRtdpch::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQBlk1NRtdpch::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQBlk1NRtdpch::loadRecByQref(
			ubigint qref
			, WznmQBlk1NRtdpch** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQBlk1NRtdpch WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQBlk1NRtdpch::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBlk1NRtdpch& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQBlk1NRtdpch WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQBlk1NRtdpch
 ******************************************************************************/

PgTblWznmQBlk1NRtdpch::PgTblWznmQBlk1NRtdpch() :
			TblWznmQBlk1NRtdpch()
			, PgTable()
		{
};

PgTblWznmQBlk1NRtdpch::~PgTblWznmQBlk1NRtdpch() {
};

void PgTblWznmQBlk1NRtdpch::initStatements() {
	createStatement("TblWznmQBlk1NRtdpch_insertRec", "INSERT INTO TblWznmQBlk1NRtdpch (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWznmQBlk1NRtdpch_updateRec", "UPDATE TblWznmQBlk1NRtdpch SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWznmQBlk1NRtdpch_removeRecByQref", "DELETE FROM TblWznmQBlk1NRtdpch WHERE qref = $1", 1);
	createStatement("TblWznmQBlk1NRtdpch_removeRstByJref", "DELETE FROM TblWznmQBlk1NRtdpch WHERE jref = $1", 1);

	createStatement("TblWznmQBlk1NRtdpch_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWznmQBlk1NRtdpch WHERE qref = $1", 1);
	createStatement("TblWznmQBlk1NRtdpch_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWznmQBlk1NRtdpch WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQBlk1NRtdpch::loadRec(
			PGresult* res
			, WznmQBlk1NRtdpch** rec
		) {
	char* ptr;

	WznmQBlk1NRtdpch* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQBlk1NRtdpch();

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

ubigint PgTblWznmQBlk1NRtdpch::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQBlk1NRtdpch& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQBlk1NRtdpch* rec;

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
			rec = new WznmQBlk1NRtdpch();

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

bool PgTblWznmQBlk1NRtdpch::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQBlk1NRtdpch** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBlk1NRtdpch::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQBlk1NRtdpch::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQBlk1NRtdpch& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBlk1NRtdpch::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQBlk1NRtdpch::loadRecBySQL(
			const string& sqlstr
			, WznmQBlk1NRtdpch** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQBlk1NRtdpch::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQBlk1NRtdpch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBlk1NRtdpch& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQBlk1NRtdpch::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQBlk1NRtdpch::insertRec(
			WznmQBlk1NRtdpch* rec
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

	res = PQexecPrepared(dbs, "TblWznmQBlk1NRtdpch_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBlk1NRtdpch::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQBlk1NRtdpch::insertRst(
			ListWznmQBlk1NRtdpch& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQBlk1NRtdpch::updateRec(
			WznmQBlk1NRtdpch* rec
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

	res = PQexecPrepared(dbs, "TblWznmQBlk1NRtdpch_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBlk1NRtdpch::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQBlk1NRtdpch::updateRst(
			ListWznmQBlk1NRtdpch& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQBlk1NRtdpch::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQBlk1NRtdpch_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBlk1NRtdpch::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQBlk1NRtdpch::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQBlk1NRtdpch_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBlk1NRtdpch::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQBlk1NRtdpch::loadRecByQref(
			ubigint qref
			, WznmQBlk1NRtdpch** rec
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

	return loadRecByStmt("TblWznmQBlk1NRtdpch_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQBlk1NRtdpch::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBlk1NRtdpch& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQBlk1NRtdpch_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
