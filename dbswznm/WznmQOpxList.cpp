/**
	* \file WznmQOpxList.cpp
	* Dbs and XML wrapper for table TblWznmQOpxList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQOpxList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQOpxList
 ******************************************************************************/

WznmQOpxList::WznmQOpxList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMOppack
			, const string stubRefWznmMOppack
			, const bool Shrdat
			, const string yesnoShrdat
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->refWznmMOppack = refWznmMOppack;
	this->stubRefWznmMOppack = stubRefWznmMOppack;
	this->Shrdat = Shrdat;
	this->yesnoShrdat = yesnoShrdat;
};

void WznmQOpxList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["srf"] = sref;
		me["opk"] = stubRefWznmMOppack;
		me["shd"] = yesnoShrdat;
	} else {
		me["sref"] = sref;
		me["stubRefWznmMOppack"] = stubRefWznmMOppack;
		me["yesnoShrdat"] = yesnoShrdat;
	};
};

void WznmQOpxList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQOpxList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "opk", stubRefWznmMOppack);
		writeString(wr, "shd", yesnoShrdat);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefWznmMOppack", stubRefWznmMOppack);
		writeString(wr, "yesnoShrdat", yesnoShrdat);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQOpxList
 ******************************************************************************/

ListWznmQOpxList::ListWznmQOpxList() {
};

ListWznmQOpxList::ListWznmQOpxList(
			const ListWznmQOpxList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQOpxList(*(src.nodes[i]));
};

ListWznmQOpxList::~ListWznmQOpxList() {
	clear();
};

void ListWznmQOpxList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQOpxList::size() const {
	return(nodes.size());
};

void ListWznmQOpxList::append(
			WznmQOpxList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQOpxList& ListWznmQOpxList::operator=(
			const ListWznmQOpxList& src
		) {
	WznmQOpxList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQOpxList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQOpxList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQOpxList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQOpxList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQOpxList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQOpxList
 ******************************************************************************/

TblWznmQOpxList::TblWznmQOpxList() {
};

TblWznmQOpxList::~TblWznmQOpxList() {
};

bool TblWznmQOpxList::loadRecBySQL(
			const string& sqlstr
			, WznmQOpxList** rec
		) {
	return false;
};

ubigint TblWznmQOpxList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQOpxList& rst
		) {
	return 0;
};

ubigint TblWznmQOpxList::insertRec(
			WznmQOpxList* rec
		) {
	return 0;
};

ubigint TblWznmQOpxList::insertNewRec(
			WznmQOpxList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMOppack
			, const string stubRefWznmMOppack
			, const bool Shrdat
			, const string yesnoShrdat
		) {
	ubigint retval = 0;
	WznmQOpxList* _rec = NULL;

	_rec = new WznmQOpxList(0, jref, jnum, ref, sref, refWznmMOppack, stubRefWznmMOppack, Shrdat, yesnoShrdat);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQOpxList::appendNewRecToRst(
			ListWznmQOpxList& rst
			, WznmQOpxList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMOppack
			, const string stubRefWznmMOppack
			, const bool Shrdat
			, const string yesnoShrdat
		) {
	ubigint retval = 0;
	WznmQOpxList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, refWznmMOppack, stubRefWznmMOppack, Shrdat, yesnoShrdat);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQOpxList::insertRst(
			ListWznmQOpxList& rst
		) {
};

void TblWznmQOpxList::updateRec(
			WznmQOpxList* rec
		) {
};

void TblWznmQOpxList::updateRst(
			ListWznmQOpxList& rst
		) {
};

void TblWznmQOpxList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQOpxList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQOpxList::loadRecByQref(
			ubigint qref
			, WznmQOpxList** rec
		) {
	return false;
};

ubigint TblWznmQOpxList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQOpxList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQOpxList
 ******************************************************************************/

MyTblWznmQOpxList::MyTblWznmQOpxList() :
			TblWznmQOpxList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQOpxList::~MyTblWznmQOpxList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQOpxList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQOpxList (jref, jnum, ref, sref, refWznmMOppack, Shrdat) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQOpxList SET jref = ?, jnum = ?, ref = ?, sref = ?, refWznmMOppack = ?, Shrdat = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQOpxList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQOpxList WHERE jref = ?", false);
};

bool MyTblWznmQOpxList::loadRecBySQL(
			const string& sqlstr
			, WznmQOpxList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQOpxList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQOpxList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQOpxList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQOpxList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->refWznmMOppack = atoll((char*) dbrow[5]); else _rec->refWznmMOppack = 0;
		if (dbrow[6]) _rec->Shrdat = (atoi((char*) dbrow[6]) != 0); else _rec->Shrdat = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQOpxList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQOpxList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQOpxList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQOpxList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQOpxList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQOpxList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->refWznmMOppack = atoll((char*) dbrow[5]); else rec->refWznmMOppack = 0;
			if (dbrow[6]) rec->Shrdat = (atoi((char*) dbrow[6]) != 0); else rec->Shrdat = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQOpxList::insertRec(
			WznmQOpxList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();
	tinyint Shrdat = rec->Shrdat;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMOppack,&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Shrdat,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQOpxList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQOpxList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQOpxList::insertRst(
			ListWznmQOpxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQOpxList::updateRec(
			WznmQOpxList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	tinyint Shrdat = rec->Shrdat;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMOppack,&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Shrdat,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQOpxList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQOpxList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQOpxList::updateRst(
			ListWznmQOpxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQOpxList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQOpxList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQOpxList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQOpxList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQOpxList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQOpxList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQOpxList::loadRecByQref(
			ubigint qref
			, WznmQOpxList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQOpxList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQOpxList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQOpxList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQOpxList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQOpxList
 ******************************************************************************/

PgTblWznmQOpxList::PgTblWznmQOpxList() :
			TblWznmQOpxList()
			, PgTable()
		{
};

PgTblWznmQOpxList::~PgTblWznmQOpxList() {
};

void PgTblWznmQOpxList::initStatements() {
	createStatement("TblWznmQOpxList_insertRec", "INSERT INTO TblWznmQOpxList (jref, jnum, ref, sref, refWznmMOppack, Shrdat) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQOpxList_updateRec", "UPDATE TblWznmQOpxList SET jref = $1, jnum = $2, ref = $3, sref = $4, refWznmMOppack = $5, Shrdat = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQOpxList_removeRecByQref", "DELETE FROM TblWznmQOpxList WHERE qref = $1", 1);
	createStatement("TblWznmQOpxList_removeRstByJref", "DELETE FROM TblWznmQOpxList WHERE jref = $1", 1);

	createStatement("TblWznmQOpxList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, refWznmMOppack, Shrdat FROM TblWznmQOpxList WHERE qref = $1", 1);
	createStatement("TblWznmQOpxList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, refWznmMOppack, Shrdat FROM TblWznmQOpxList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQOpxList::loadRec(
			PGresult* res
			, WznmQOpxList** rec
		) {
	char* ptr;

	WznmQOpxList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQOpxList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwznmmoppack"),
			PQfnumber(res, "shrdat")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMOppack = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Shrdat = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQOpxList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQOpxList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQOpxList* rec;

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
			PQfnumber(res, "refwznmmoppack"),
			PQfnumber(res, "shrdat")
		};

		while (numread < numrow) {
			rec = new WznmQOpxList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMOppack = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Shrdat = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQOpxList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQOpxList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQOpxList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQOpxList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQOpxList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQOpxList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQOpxList::loadRecBySQL(
			const string& sqlstr
			, WznmQOpxList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQOpxList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQOpxList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQOpxList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQOpxList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQOpxList::insertRec(
			WznmQOpxList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMOppack = htonl64(rec->refWznmMOppack);
	smallint _Shrdat = htons((smallint) rec->Shrdat);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refWznmMOppack,
		(char*) &_Shrdat
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

	res = PQexecPrepared(dbs, "TblWznmQOpxList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQOpxList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQOpxList::insertRst(
			ListWznmQOpxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQOpxList::updateRec(
			WznmQOpxList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMOppack = htonl64(rec->refWznmMOppack);
	smallint _Shrdat = htons((smallint) rec->Shrdat);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refWznmMOppack,
		(char*) &_Shrdat,
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

	res = PQexecPrepared(dbs, "TblWznmQOpxList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQOpxList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQOpxList::updateRst(
			ListWznmQOpxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQOpxList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQOpxList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQOpxList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQOpxList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQOpxList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQOpxList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQOpxList::loadRecByQref(
			ubigint qref
			, WznmQOpxList** rec
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

	return loadRecByStmt("TblWznmQOpxList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQOpxList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQOpxList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQOpxList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
