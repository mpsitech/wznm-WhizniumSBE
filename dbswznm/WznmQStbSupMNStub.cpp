/**
	* \file WznmQStbSupMNStub.cpp
	* Dbs and XML wrapper for table TblWznmQStbSupMNStub (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQStbSupMNStub.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQStbSupMNStub
 ******************************************************************************/

WznmQStbSupMNStub::WznmQStbSupMNStub(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
};

void WznmQStbSupMNStub::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
	} else {
		me["stubMref"] = stubMref;
	};
};

void WznmQStbSupMNStub::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQStbSupMNStub";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
	} else {
		writeString(wr, "stubMref", stubMref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQStbSupMNStub
 ******************************************************************************/

ListWznmQStbSupMNStub::ListWznmQStbSupMNStub() {
};

ListWznmQStbSupMNStub::ListWznmQStbSupMNStub(
			const ListWznmQStbSupMNStub& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQStbSupMNStub(*(src.nodes[i]));
};

ListWznmQStbSupMNStub::~ListWznmQStbSupMNStub() {
	clear();
};

void ListWznmQStbSupMNStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQStbSupMNStub::size() const {
	return(nodes.size());
};

void ListWznmQStbSupMNStub::append(
			WznmQStbSupMNStub* rec
		) {
	nodes.push_back(rec);
};

ListWznmQStbSupMNStub& ListWznmQStbSupMNStub::operator=(
			const ListWznmQStbSupMNStub& src
		) {
	WznmQStbSupMNStub* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQStbSupMNStub(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQStbSupMNStub::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQStbSupMNStub";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQStbSupMNStub::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQStbSupMNStub";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQStbSupMNStub
 ******************************************************************************/

TblWznmQStbSupMNStub::TblWznmQStbSupMNStub() {
};

TblWznmQStbSupMNStub::~TblWznmQStbSupMNStub() {
};

bool TblWznmQStbSupMNStub::loadRecBySQL(
			const string& sqlstr
			, WznmQStbSupMNStub** rec
		) {
	return false;
};

ubigint TblWznmQStbSupMNStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQStbSupMNStub& rst
		) {
	return 0;
};

ubigint TblWznmQStbSupMNStub::insertRec(
			WznmQStbSupMNStub* rec
		) {
	return 0;
};

ubigint TblWznmQStbSupMNStub::insertNewRec(
			WznmQStbSupMNStub** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	ubigint retval = 0;
	WznmQStbSupMNStub* _rec = NULL;

	_rec = new WznmQStbSupMNStub(0, jref, jnum, mref, stubMref, ref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQStbSupMNStub::appendNewRecToRst(
			ListWznmQStbSupMNStub& rst
			, WznmQStbSupMNStub** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	ubigint retval = 0;
	WznmQStbSupMNStub* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQStbSupMNStub::insertRst(
			ListWznmQStbSupMNStub& rst
		) {
};

void TblWznmQStbSupMNStub::updateRec(
			WznmQStbSupMNStub* rec
		) {
};

void TblWznmQStbSupMNStub::updateRst(
			ListWznmQStbSupMNStub& rst
		) {
};

void TblWznmQStbSupMNStub::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQStbSupMNStub::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQStbSupMNStub::loadRecByQref(
			ubigint qref
			, WznmQStbSupMNStub** rec
		) {
	return false;
};

ubigint TblWznmQStbSupMNStub::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQStbSupMNStub& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQStbSupMNStub
 ******************************************************************************/

MyTblWznmQStbSupMNStub::MyTblWznmQStbSupMNStub() :
			TblWznmQStbSupMNStub()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQStbSupMNStub::~MyTblWznmQStbSupMNStub() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQStbSupMNStub::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQStbSupMNStub (jref, jnum, mref, ref) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQStbSupMNStub SET jref = ?, jnum = ?, mref = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQStbSupMNStub WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQStbSupMNStub WHERE jref = ?", false);
};

bool MyTblWznmQStbSupMNStub::loadRecBySQL(
			const string& sqlstr
			, WznmQStbSupMNStub** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQStbSupMNStub* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQStbSupMNStub::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQStbSupMNStub::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQStbSupMNStub();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQStbSupMNStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQStbSupMNStub& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQStbSupMNStub* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQStbSupMNStub::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQStbSupMNStub::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQStbSupMNStub();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQStbSupMNStub::insertRec(
			WznmQStbSupMNStub* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQStbSupMNStub::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQStbSupMNStub::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQStbSupMNStub::insertRst(
			ListWznmQStbSupMNStub& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQStbSupMNStub::updateRec(
			WznmQStbSupMNStub* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQStbSupMNStub::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQStbSupMNStub::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQStbSupMNStub::updateRst(
			ListWznmQStbSupMNStub& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQStbSupMNStub::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQStbSupMNStub::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQStbSupMNStub::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQStbSupMNStub::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQStbSupMNStub::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQStbSupMNStub::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQStbSupMNStub::loadRecByQref(
			ubigint qref
			, WznmQStbSupMNStub** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQStbSupMNStub WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQStbSupMNStub::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQStbSupMNStub& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQStbSupMNStub WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQStbSupMNStub
 ******************************************************************************/

PgTblWznmQStbSupMNStub::PgTblWznmQStbSupMNStub() :
			TblWznmQStbSupMNStub()
			, PgTable()
		{
};

PgTblWznmQStbSupMNStub::~PgTblWznmQStbSupMNStub() {
};

void PgTblWznmQStbSupMNStub::initStatements() {
	createStatement("TblWznmQStbSupMNStub_insertRec", "INSERT INTO TblWznmQStbSupMNStub (jref, jnum, mref, ref) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWznmQStbSupMNStub_updateRec", "UPDATE TblWznmQStbSupMNStub SET jref = $1, jnum = $2, mref = $3, ref = $4 WHERE qref = $5", 5);
	createStatement("TblWznmQStbSupMNStub_removeRecByQref", "DELETE FROM TblWznmQStbSupMNStub WHERE qref = $1", 1);
	createStatement("TblWznmQStbSupMNStub_removeRstByJref", "DELETE FROM TblWznmQStbSupMNStub WHERE jref = $1", 1);

	createStatement("TblWznmQStbSupMNStub_loadRecByQref", "SELECT qref, jref, jnum, mref, ref FROM TblWznmQStbSupMNStub WHERE qref = $1", 1);
	createStatement("TblWznmQStbSupMNStub_loadRstByJref", "SELECT qref, jref, jnum, mref, ref FROM TblWznmQStbSupMNStub WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQStbSupMNStub::loadRec(
			PGresult* res
			, WznmQStbSupMNStub** rec
		) {
	char* ptr;

	WznmQStbSupMNStub* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQStbSupMNStub();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQStbSupMNStub::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQStbSupMNStub& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQStbSupMNStub* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new WznmQStbSupMNStub();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQStbSupMNStub::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQStbSupMNStub** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQStbSupMNStub::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQStbSupMNStub::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQStbSupMNStub& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQStbSupMNStub::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQStbSupMNStub::loadRecBySQL(
			const string& sqlstr
			, WznmQStbSupMNStub** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQStbSupMNStub::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQStbSupMNStub::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQStbSupMNStub& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQStbSupMNStub::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQStbSupMNStub::insertRec(
			WznmQStbSupMNStub* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQStbSupMNStub_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQStbSupMNStub::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQStbSupMNStub::insertRst(
			ListWznmQStbSupMNStub& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQStbSupMNStub::updateRec(
			WznmQStbSupMNStub* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQStbSupMNStub_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQStbSupMNStub::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQStbSupMNStub::updateRst(
			ListWznmQStbSupMNStub& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQStbSupMNStub::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQStbSupMNStub_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQStbSupMNStub::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQStbSupMNStub::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQStbSupMNStub_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQStbSupMNStub::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQStbSupMNStub::loadRecByQref(
			ubigint qref
			, WznmQStbSupMNStub** rec
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

	return loadRecByStmt("TblWznmQStbSupMNStub_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQStbSupMNStub::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQStbSupMNStub& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQStbSupMNStub_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
