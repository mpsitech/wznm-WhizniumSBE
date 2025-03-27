/**
	* \file WznmQRlsList.cpp
	* Dbs and XML wrapper for table TblWznmQRlsList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQRlsList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRlsList
 ******************************************************************************/

WznmQRlsList::WznmQRlsList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMComponent
			, const string stubRefWznmMComponent
			, const ubigint refWznmMMachine
			, const string stubRefWznmMMachine
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, sref(sref)
			, refWznmMComponent(refWznmMComponent)
			, stubRefWznmMComponent(stubRefWznmMComponent)
			, refWznmMMachine(refWznmMMachine)
			, stubRefWznmMMachine(stubRefWznmMMachine)
		{
};

void WznmQRlsList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["srf"] = sref;
		me["cmp"] = stubRefWznmMComponent;
		me["mch"] = stubRefWznmMMachine;
	} else {
		me["sref"] = sref;
		me["stubRefWznmMComponent"] = stubRefWznmMComponent;
		me["stubRefWznmMMachine"] = stubRefWznmMMachine;
	};
};

void WznmQRlsList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQRlsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "cmp", stubRefWznmMComponent);
		writeString(wr, "mch", stubRefWznmMMachine);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefWznmMComponent", stubRefWznmMComponent);
		writeString(wr, "stubRefWznmMMachine", stubRefWznmMMachine);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQRlsList
 ******************************************************************************/

ListWznmQRlsList::ListWznmQRlsList() {
};

ListWznmQRlsList::ListWznmQRlsList(
			const ListWznmQRlsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRlsList(*(src.nodes[i]));
};

ListWznmQRlsList::~ListWznmQRlsList() {
	clear();
};

void ListWznmQRlsList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQRlsList::size() const {
	return(nodes.size());
};

void ListWznmQRlsList::append(
			WznmQRlsList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQRlsList& ListWznmQRlsList::operator=(
			const ListWznmQRlsList& src
		) {
	WznmQRlsList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQRlsList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQRlsList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQRlsList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQRlsList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQRlsList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQRlsList
 ******************************************************************************/

TblWznmQRlsList::TblWznmQRlsList() {
};

TblWznmQRlsList::~TblWznmQRlsList() {
};

bool TblWznmQRlsList::loadRecBySQL(
			const string& sqlstr
			, WznmQRlsList** rec
		) {
	return false;
};

ubigint TblWznmQRlsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRlsList& rst
		) {
	return 0;
};

ubigint TblWznmQRlsList::insertRec(
			WznmQRlsList* rec
		) {
	return 0;
};

ubigint TblWznmQRlsList::insertNewRec(
			WznmQRlsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMComponent
			, const string stubRefWznmMComponent
			, const ubigint refWznmMMachine
			, const string stubRefWznmMMachine
		) {
	ubigint retval = 0;
	WznmQRlsList* _rec = NULL;

	_rec = new WznmQRlsList(0, jref, jnum, ref, sref, refWznmMComponent, stubRefWznmMComponent, refWznmMMachine, stubRefWznmMMachine);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQRlsList::appendNewRecToRst(
			ListWznmQRlsList& rst
			, WznmQRlsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMComponent
			, const string stubRefWznmMComponent
			, const ubigint refWznmMMachine
			, const string stubRefWznmMMachine
		) {
	ubigint retval = 0;
	WznmQRlsList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, refWznmMComponent, stubRefWznmMComponent, refWznmMMachine, stubRefWznmMMachine);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQRlsList::insertRst(
			ListWznmQRlsList& rst
		) {
};

void TblWznmQRlsList::updateRec(
			WznmQRlsList* rec
		) {
};

void TblWznmQRlsList::updateRst(
			ListWznmQRlsList& rst
		) {
};

void TblWznmQRlsList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQRlsList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQRlsList::loadRecByQref(
			ubigint qref
			, WznmQRlsList** rec
		) {
	return false;
};

ubigint TblWznmQRlsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRlsList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQRlsList
 ******************************************************************************/

MyTblWznmQRlsList::MyTblWznmQRlsList() :
			TblWznmQRlsList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQRlsList::~MyTblWznmQRlsList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQRlsList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQRlsList (jref, jnum, ref, sref, refWznmMComponent, refWznmMMachine) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQRlsList SET jref = ?, jnum = ?, ref = ?, sref = ?, refWznmMComponent = ?, refWznmMMachine = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQRlsList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQRlsList WHERE jref = ?", false);
};

bool MyTblWznmQRlsList::loadRecBySQL(
			const string& sqlstr
			, WznmQRlsList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQRlsList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQRlsList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQRlsList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQRlsList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->refWznmMComponent = atoll((char*) dbrow[5]); else _rec->refWznmMComponent = 0;
		if (dbrow[6]) _rec->refWznmMMachine = atoll((char*) dbrow[6]); else _rec->refWznmMMachine = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQRlsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRlsList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQRlsList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQRlsList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQRlsList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQRlsList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->refWznmMComponent = atoll((char*) dbrow[5]); else rec->refWznmMComponent = 0;
			if (dbrow[6]) rec->refWznmMMachine = atoll((char*) dbrow[6]); else rec->refWznmMMachine = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQRlsList::insertRec(
			WznmQRlsList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMComponent,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMMachine,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQRlsList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQRlsList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQRlsList::insertRst(
			ListWznmQRlsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQRlsList::updateRec(
			WznmQRlsList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMComponent,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMMachine,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQRlsList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQRlsList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQRlsList::updateRst(
			ListWznmQRlsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQRlsList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQRlsList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQRlsList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQRlsList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQRlsList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQRlsList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQRlsList::loadRecByQref(
			ubigint qref
			, WznmQRlsList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQRlsList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQRlsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRlsList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQRlsList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQRlsList
 ******************************************************************************/

PgTblWznmQRlsList::PgTblWznmQRlsList() :
			TblWznmQRlsList()
			, PgTable()
		{
};

PgTblWznmQRlsList::~PgTblWznmQRlsList() {
};

void PgTblWznmQRlsList::initStatements() {
	createStatement("TblWznmQRlsList_insertRec", "INSERT INTO TblWznmQRlsList (jref, jnum, ref, sref, refWznmMComponent, refWznmMMachine) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQRlsList_updateRec", "UPDATE TblWznmQRlsList SET jref = $1, jnum = $2, ref = $3, sref = $4, refWznmMComponent = $5, refWznmMMachine = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQRlsList_removeRecByQref", "DELETE FROM TblWznmQRlsList WHERE qref = $1", 1);
	createStatement("TblWznmQRlsList_removeRstByJref", "DELETE FROM TblWznmQRlsList WHERE jref = $1", 1);

	createStatement("TblWznmQRlsList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, refWznmMComponent, refWznmMMachine FROM TblWznmQRlsList WHERE qref = $1", 1);
	createStatement("TblWznmQRlsList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, refWznmMComponent, refWznmMMachine FROM TblWznmQRlsList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQRlsList::loadRec(
			PGresult* res
			, WznmQRlsList** rec
		) {
	char* ptr;

	WznmQRlsList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQRlsList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwznmmcomponent"),
			PQfnumber(res, "refwznmmmachine")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMComponent = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMMachine = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQRlsList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQRlsList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQRlsList* rec;

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
			PQfnumber(res, "refwznmmcomponent"),
			PQfnumber(res, "refwznmmmachine")
		};

		while (numread < numrow) {
			rec = new WznmQRlsList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMComponent = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMMachine = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQRlsList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQRlsList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRlsList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQRlsList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQRlsList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRlsList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQRlsList::loadRecBySQL(
			const string& sqlstr
			, WznmQRlsList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQRlsList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQRlsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRlsList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQRlsList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQRlsList::insertRec(
			WznmQRlsList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMComponent = htonl64(rec->refWznmMComponent);
	ubigint _refWznmMMachine = htonl64(rec->refWznmMMachine);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refWznmMComponent,
		(char*) &_refWznmMMachine
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQRlsList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRlsList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQRlsList::insertRst(
			ListWznmQRlsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQRlsList::updateRec(
			WznmQRlsList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMComponent = htonl64(rec->refWznmMComponent);
	ubigint _refWznmMMachine = htonl64(rec->refWznmMMachine);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refWznmMComponent,
		(char*) &_refWznmMMachine,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQRlsList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRlsList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQRlsList::updateRst(
			ListWznmQRlsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQRlsList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQRlsList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRlsList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQRlsList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQRlsList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRlsList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQRlsList::loadRecByQref(
			ubigint qref
			, WznmQRlsList** rec
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

	return loadRecByStmt("TblWznmQRlsList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQRlsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRlsList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQRlsList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
