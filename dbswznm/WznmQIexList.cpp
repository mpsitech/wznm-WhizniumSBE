/**
	* \file WznmQIexList.cpp
	* Dbs and XML wrapper for table TblWznmQIexList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQIexList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQIexList
 ******************************************************************************/

WznmQIexList::WznmQIexList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Short
			, const string Title
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const string Minversion
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Short = Short;
	this->Title = Title;
	this->refWznmMVersion = refWznmMVersion;
	this->stubRefWznmMVersion = stubRefWznmMVersion;
	this->Minversion = Minversion;
};

void WznmQIexList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["srf"] = sref;
		me["sho"] = Short;
		me["tit"] = Title;
		me["ver"] = stubRefWznmMVersion;
		me["miv"] = Minversion;
	} else {
		me["sref"] = sref;
		me["Short"] = Short;
		me["Title"] = Title;
		me["stubRefWznmMVersion"] = stubRefWznmMVersion;
		me["Minversion"] = Minversion;
	};
};

void WznmQIexList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQIexList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "sho", Short);
		writeString(wr, "tit", Title);
		writeString(wr, "ver", stubRefWznmMVersion);
		writeString(wr, "miv", Minversion);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Short", Short);
		writeString(wr, "Title", Title);
		writeString(wr, "stubRefWznmMVersion", stubRefWznmMVersion);
		writeString(wr, "Minversion", Minversion);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQIexList
 ******************************************************************************/

ListWznmQIexList::ListWznmQIexList() {
};

ListWznmQIexList::ListWznmQIexList(
			const ListWznmQIexList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQIexList(*(src.nodes[i]));
};

ListWznmQIexList::~ListWznmQIexList() {
	clear();
};

void ListWznmQIexList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQIexList::size() const {
	return(nodes.size());
};

void ListWznmQIexList::append(
			WznmQIexList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQIexList& ListWznmQIexList::operator=(
			const ListWznmQIexList& src
		) {
	WznmQIexList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQIexList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQIexList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQIexList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQIexList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQIexList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQIexList
 ******************************************************************************/

TblWznmQIexList::TblWznmQIexList() {
};

TblWznmQIexList::~TblWznmQIexList() {
};

bool TblWznmQIexList::loadRecBySQL(
			const string& sqlstr
			, WznmQIexList** rec
		) {
	return false;
};

ubigint TblWznmQIexList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQIexList& rst
		) {
	return 0;
};

ubigint TblWznmQIexList::insertRec(
			WznmQIexList* rec
		) {
	return 0;
};

ubigint TblWznmQIexList::insertNewRec(
			WznmQIexList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Short
			, const string Title
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const string Minversion
		) {
	ubigint retval = 0;
	WznmQIexList* _rec = NULL;

	_rec = new WznmQIexList(0, jref, jnum, ref, sref, Short, Title, refWznmMVersion, stubRefWznmMVersion, Minversion);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQIexList::appendNewRecToRst(
			ListWznmQIexList& rst
			, WznmQIexList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Short
			, const string Title
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const string Minversion
		) {
	ubigint retval = 0;
	WznmQIexList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Short, Title, refWznmMVersion, stubRefWznmMVersion, Minversion);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQIexList::insertRst(
			ListWznmQIexList& rst
		) {
};

void TblWznmQIexList::updateRec(
			WznmQIexList* rec
		) {
};

void TblWznmQIexList::updateRst(
			ListWznmQIexList& rst
		) {
};

void TblWznmQIexList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQIexList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQIexList::loadRecByQref(
			ubigint qref
			, WznmQIexList** rec
		) {
	return false;
};

ubigint TblWznmQIexList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQIexList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQIexList
 ******************************************************************************/

MyTblWznmQIexList::MyTblWznmQIexList() :
			TblWznmQIexList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQIexList::~MyTblWznmQIexList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQIexList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQIexList (jref, jnum, ref, sref, Short, Title, refWznmMVersion, Minversion) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQIexList SET jref = ?, jnum = ?, ref = ?, sref = ?, Short = ?, Title = ?, refWznmMVersion = ?, Minversion = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQIexList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQIexList WHERE jref = ?", false);
};

bool MyTblWznmQIexList::loadRecBySQL(
			const string& sqlstr
			, WznmQIexList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQIexList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQIexList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQIexList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQIexList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Short.assign(dbrow[5], dblengths[5]); else _rec->Short = "";
		if (dbrow[6]) _rec->Title.assign(dbrow[6], dblengths[6]); else _rec->Title = "";
		if (dbrow[7]) _rec->refWznmMVersion = atoll((char*) dbrow[7]); else _rec->refWznmMVersion = 0;
		if (dbrow[8]) _rec->Minversion.assign(dbrow[8], dblengths[8]); else _rec->Minversion = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQIexList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQIexList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQIexList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQIexList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQIexList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQIexList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Short.assign(dbrow[5], dblengths[5]); else rec->Short = "";
			if (dbrow[6]) rec->Title.assign(dbrow[6], dblengths[6]); else rec->Title = "";
			if (dbrow[7]) rec->refWznmMVersion = atoll((char*) dbrow[7]); else rec->refWznmMVersion = 0;
			if (dbrow[8]) rec->Minversion.assign(dbrow[8], dblengths[8]); else rec->Minversion = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQIexList::insertRec(
			WznmQIexList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[4] = rec->Short.length();
	l[5] = rec->Title.length();
	l[7] = rec->Minversion.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Short.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVersion,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Minversion.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQIexList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQIexList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQIexList::insertRst(
			ListWznmQIexList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQIexList::updateRec(
			WznmQIexList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[4] = rec->Short.length();
	l[5] = rec->Title.length();
	l[7] = rec->Minversion.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Short.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVersion,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Minversion.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQIexList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQIexList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQIexList::updateRst(
			ListWznmQIexList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQIexList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQIexList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQIexList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQIexList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQIexList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQIexList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQIexList::loadRecByQref(
			ubigint qref
			, WznmQIexList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQIexList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQIexList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQIexList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQIexList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQIexList
 ******************************************************************************/

PgTblWznmQIexList::PgTblWznmQIexList() :
			TblWznmQIexList()
			, PgTable()
		{
};

PgTblWznmQIexList::~PgTblWznmQIexList() {
};

void PgTblWznmQIexList::initStatements() {
	createStatement("TblWznmQIexList_insertRec", "INSERT INTO TblWznmQIexList (jref, jnum, ref, sref, Short, Title, refWznmMVersion, Minversion) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8);
	createStatement("TblWznmQIexList_updateRec", "UPDATE TblWznmQIexList SET jref = $1, jnum = $2, ref = $3, sref = $4, Short = $5, Title = $6, refWznmMVersion = $7, Minversion = $8 WHERE qref = $9", 9);
	createStatement("TblWznmQIexList_removeRecByQref", "DELETE FROM TblWznmQIexList WHERE qref = $1", 1);
	createStatement("TblWznmQIexList_removeRstByJref", "DELETE FROM TblWznmQIexList WHERE jref = $1", 1);

	createStatement("TblWznmQIexList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Short, Title, refWznmMVersion, Minversion FROM TblWznmQIexList WHERE qref = $1", 1);
	createStatement("TblWznmQIexList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Short, Title, refWznmMVersion, Minversion FROM TblWznmQIexList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQIexList::loadRec(
			PGresult* res
			, WznmQIexList** rec
		) {
	char* ptr;

	WznmQIexList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQIexList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "minversion")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Minversion.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQIexList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQIexList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQIexList* rec;

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
			PQfnumber(res, "short"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "minversion")
		};

		while (numread < numrow) {
			rec = new WznmQIexList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Minversion.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQIexList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQIexList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQIexList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQIexList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQIexList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQIexList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQIexList::loadRecBySQL(
			const string& sqlstr
			, WznmQIexList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQIexList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQIexList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQIexList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQIexList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQIexList::insertRec(
			WznmQIexList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Short.c_str(),
		rec->Title.c_str(),
		(char*) &_refWznmMVersion,
		rec->Minversion.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQIexList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQIexList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQIexList::insertRst(
			ListWznmQIexList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQIexList::updateRec(
			WznmQIexList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Short.c_str(),
		rec->Title.c_str(),
		(char*) &_refWznmMVersion,
		rec->Minversion.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQIexList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQIexList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQIexList::updateRst(
			ListWznmQIexList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQIexList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQIexList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQIexList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQIexList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQIexList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQIexList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQIexList::loadRecByQref(
			ubigint qref
			, WznmQIexList** rec
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

	return loadRecByStmt("TblWznmQIexList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQIexList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQIexList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQIexList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
