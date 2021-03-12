/**
	* \file WznmQMtdList.cpp
	* Dbs and XML wrapper for table TblWznmQMtdList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQMtdList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMtdList
 ******************************************************************************/

WznmQMtdList::WznmQMtdList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMJob
			, const string stubRefWznmMJob
			, const bool Execsrv
			, const string yesnoExecsrv
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->refWznmMJob = refWznmMJob;
	this->stubRefWznmMJob = stubRefWznmMJob;
	this->Execsrv = Execsrv;
	this->yesnoExecsrv = yesnoExecsrv;
};

void WznmQMtdList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["srf"] = sref;
		me["job"] = stubRefWznmMJob;
		me["exs"] = yesnoExecsrv;
	} else {
		me["sref"] = sref;
		me["stubRefWznmMJob"] = stubRefWznmMJob;
		me["yesnoExecsrv"] = yesnoExecsrv;
	};
};

void WznmQMtdList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQMtdList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "job", stubRefWznmMJob);
		writeString(wr, "exs", yesnoExecsrv);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefWznmMJob", stubRefWznmMJob);
		writeString(wr, "yesnoExecsrv", yesnoExecsrv);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQMtdList
 ******************************************************************************/

ListWznmQMtdList::ListWznmQMtdList() {
};

ListWznmQMtdList::ListWznmQMtdList(
			const ListWznmQMtdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMtdList(*(src.nodes[i]));
};

ListWznmQMtdList::~ListWznmQMtdList() {
	clear();
};

void ListWznmQMtdList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQMtdList::size() const {
	return(nodes.size());
};

void ListWznmQMtdList::append(
			WznmQMtdList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQMtdList& ListWznmQMtdList::operator=(
			const ListWznmQMtdList& src
		) {
	WznmQMtdList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQMtdList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQMtdList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQMtdList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQMtdList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQMtdList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQMtdList
 ******************************************************************************/

TblWznmQMtdList::TblWznmQMtdList() {
};

TblWznmQMtdList::~TblWznmQMtdList() {
};

bool TblWznmQMtdList::loadRecBySQL(
			const string& sqlstr
			, WznmQMtdList** rec
		) {
	return false;
};

ubigint TblWznmQMtdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQMtdList& rst
		) {
	return 0;
};

ubigint TblWznmQMtdList::insertRec(
			WznmQMtdList* rec
		) {
	return 0;
};

ubigint TblWznmQMtdList::insertNewRec(
			WznmQMtdList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMJob
			, const string stubRefWznmMJob
			, const bool Execsrv
			, const string yesnoExecsrv
		) {
	ubigint retval = 0;
	WznmQMtdList* _rec = NULL;

	_rec = new WznmQMtdList(0, jref, jnum, ref, sref, refWznmMJob, stubRefWznmMJob, Execsrv, yesnoExecsrv);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQMtdList::appendNewRecToRst(
			ListWznmQMtdList& rst
			, WznmQMtdList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMJob
			, const string stubRefWznmMJob
			, const bool Execsrv
			, const string yesnoExecsrv
		) {
	ubigint retval = 0;
	WznmQMtdList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, refWznmMJob, stubRefWznmMJob, Execsrv, yesnoExecsrv);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQMtdList::insertRst(
			ListWznmQMtdList& rst
		) {
};

void TblWznmQMtdList::updateRec(
			WznmQMtdList* rec
		) {
};

void TblWznmQMtdList::updateRst(
			ListWznmQMtdList& rst
		) {
};

void TblWznmQMtdList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQMtdList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQMtdList::loadRecByQref(
			ubigint qref
			, WznmQMtdList** rec
		) {
	return false;
};

ubigint TblWznmQMtdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQMtdList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQMtdList
 ******************************************************************************/

MyTblWznmQMtdList::MyTblWznmQMtdList() :
			TblWznmQMtdList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQMtdList::~MyTblWznmQMtdList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQMtdList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQMtdList (jref, jnum, ref, sref, refWznmMJob, Execsrv) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQMtdList SET jref = ?, jnum = ?, ref = ?, sref = ?, refWznmMJob = ?, Execsrv = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQMtdList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQMtdList WHERE jref = ?", false);
};

bool MyTblWznmQMtdList::loadRecBySQL(
			const string& sqlstr
			, WznmQMtdList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQMtdList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQMtdList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQMtdList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQMtdList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->refWznmMJob = atoll((char*) dbrow[5]); else _rec->refWznmMJob = 0;
		if (dbrow[6]) _rec->Execsrv = (atoi((char*) dbrow[6]) != 0); else _rec->Execsrv = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQMtdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQMtdList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQMtdList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQMtdList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQMtdList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQMtdList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->refWznmMJob = atoll((char*) dbrow[5]); else rec->refWznmMJob = 0;
			if (dbrow[6]) rec->Execsrv = (atoi((char*) dbrow[6]) != 0); else rec->Execsrv = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQMtdList::insertRec(
			WznmQMtdList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();
	tinyint Execsrv = rec->Execsrv;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMJob,&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Execsrv,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQMtdList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQMtdList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQMtdList::insertRst(
			ListWznmQMtdList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQMtdList::updateRec(
			WznmQMtdList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	tinyint Execsrv = rec->Execsrv;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMJob,&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Execsrv,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQMtdList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQMtdList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQMtdList::updateRst(
			ListWznmQMtdList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQMtdList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQMtdList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQMtdList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQMtdList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQMtdList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQMtdList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQMtdList::loadRecByQref(
			ubigint qref
			, WznmQMtdList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQMtdList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQMtdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQMtdList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQMtdList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQMtdList
 ******************************************************************************/

PgTblWznmQMtdList::PgTblWznmQMtdList() :
			TblWznmQMtdList()
			, PgTable()
		{
};

PgTblWznmQMtdList::~PgTblWznmQMtdList() {
};

void PgTblWznmQMtdList::initStatements() {
	createStatement("TblWznmQMtdList_insertRec", "INSERT INTO TblWznmQMtdList (jref, jnum, ref, sref, refWznmMJob, Execsrv) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQMtdList_updateRec", "UPDATE TblWznmQMtdList SET jref = $1, jnum = $2, ref = $3, sref = $4, refWznmMJob = $5, Execsrv = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQMtdList_removeRecByQref", "DELETE FROM TblWznmQMtdList WHERE qref = $1", 1);
	createStatement("TblWznmQMtdList_removeRstByJref", "DELETE FROM TblWznmQMtdList WHERE jref = $1", 1);

	createStatement("TblWznmQMtdList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, refWznmMJob, Execsrv FROM TblWznmQMtdList WHERE qref = $1", 1);
	createStatement("TblWznmQMtdList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, refWznmMJob, Execsrv FROM TblWznmQMtdList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQMtdList::loadRec(
			PGresult* res
			, WznmQMtdList** rec
		) {
	char* ptr;

	WznmQMtdList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQMtdList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "execsrv")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Execsrv = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQMtdList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQMtdList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQMtdList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "execsrv")
		};

		while (numread < numrow) {
			rec = new WznmQMtdList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Execsrv = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQMtdList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQMtdList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQMtdList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQMtdList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQMtdList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQMtdList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQMtdList::loadRecBySQL(
			const string& sqlstr
			, WznmQMtdList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQMtdList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQMtdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQMtdList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQMtdList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQMtdList::insertRec(
			WznmQMtdList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	smallint _Execsrv = htons((smallint) rec->Execsrv);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refWznmMJob,
		(char*) &_Execsrv
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQMtdList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQMtdList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQMtdList::insertRst(
			ListWznmQMtdList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQMtdList::updateRec(
			WznmQMtdList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	smallint _Execsrv = htons((smallint) rec->Execsrv);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refWznmMJob,
		(char*) &_Execsrv,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQMtdList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQMtdList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQMtdList::updateRst(
			ListWznmQMtdList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQMtdList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQMtdList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQMtdList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQMtdList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQMtdList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQMtdList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQMtdList::loadRecByQref(
			ubigint qref
			, WznmQMtdList** rec
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

	return loadRecByStmt("TblWznmQMtdList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQMtdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQMtdList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQMtdList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
