/**
	* \file WznmQPstList.cpp
	* Dbs and XML wrapper for table TblWznmQPstList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQPstList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQPstList
 ******************************************************************************/

WznmQPstList::WznmQPstList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const uint ixWznmWArgtype
			, const string srefIxWznmWArgtype
			, const string titIxWznmWArgtype
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->refWznmMVersion = refWznmMVersion;
	this->stubRefWznmMVersion = stubRefWznmMVersion;
	this->refIxVTbl = refIxVTbl;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->refUref = refUref;
	this->stubRefUref = stubRefUref;
	this->ixWznmWArgtype = ixWznmWArgtype;
	this->srefIxWznmWArgtype = srefIxWznmWArgtype;
	this->titIxWznmWArgtype = titIxWznmWArgtype;
};

void WznmQPstList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["srf"] = sref;
		me["tit"] = Title;
		me["ver"] = stubRefWznmMVersion;
		me["ret"] = srefRefIxVTbl;
		me["ret2"] = titRefIxVTbl;
		me["reu"] = stubRefUref;
		me["aty"] = srefIxWznmWArgtype;
		me["aty2"] = titIxWznmWArgtype;
	} else {
		me["sref"] = sref;
		me["Title"] = Title;
		me["stubRefWznmMVersion"] = stubRefWznmMVersion;
		me["srefRefIxVTbl"] = srefRefIxVTbl;
		me["titRefIxVTbl"] = titRefIxVTbl;
		me["stubRefUref"] = stubRefUref;
		me["srefIxWznmWArgtype"] = srefIxWznmWArgtype;
		me["titIxWznmWArgtype"] = titIxWznmWArgtype;
	};
};

void WznmQPstList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQPstList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "ver", stubRefWznmMVersion);
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
		writeString(wr, "aty", srefIxWznmWArgtype);
		writeString(wr, "aty2", titIxWznmWArgtype);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "stubRefWznmMVersion", stubRefWznmMVersion);
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
		writeString(wr, "srefIxWznmWArgtype", srefIxWznmWArgtype);
		writeString(wr, "titIxWznmWArgtype", titIxWznmWArgtype);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQPstList
 ******************************************************************************/

ListWznmQPstList::ListWznmQPstList() {
};

ListWznmQPstList::ListWznmQPstList(
			const ListWznmQPstList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQPstList(*(src.nodes[i]));
};

ListWznmQPstList::~ListWznmQPstList() {
	clear();
};

void ListWznmQPstList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQPstList::size() const {
	return(nodes.size());
};

void ListWznmQPstList::append(
			WznmQPstList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQPstList& ListWznmQPstList::operator=(
			const ListWznmQPstList& src
		) {
	WznmQPstList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQPstList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQPstList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQPstList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQPstList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQPstList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQPstList
 ******************************************************************************/

TblWznmQPstList::TblWznmQPstList() {
};

TblWznmQPstList::~TblWznmQPstList() {
};

bool TblWznmQPstList::loadRecBySQL(
			const string& sqlstr
			, WznmQPstList** rec
		) {
	return false;
};

ubigint TblWznmQPstList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPstList& rst
		) {
	return 0;
};

ubigint TblWznmQPstList::insertRec(
			WznmQPstList* rec
		) {
	return 0;
};

ubigint TblWznmQPstList::insertNewRec(
			WznmQPstList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const uint ixWznmWArgtype
			, const string srefIxWznmWArgtype
			, const string titIxWznmWArgtype
		) {
	ubigint retval = 0;
	WznmQPstList* _rec = NULL;

	_rec = new WznmQPstList(0, jref, jnum, ref, sref, Title, refWznmMVersion, stubRefWznmMVersion, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, ixWznmWArgtype, srefIxWznmWArgtype, titIxWznmWArgtype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQPstList::appendNewRecToRst(
			ListWznmQPstList& rst
			, WznmQPstList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const uint ixWznmWArgtype
			, const string srefIxWznmWArgtype
			, const string titIxWznmWArgtype
		) {
	ubigint retval = 0;
	WznmQPstList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Title, refWznmMVersion, stubRefWznmMVersion, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, ixWznmWArgtype, srefIxWznmWArgtype, titIxWznmWArgtype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQPstList::insertRst(
			ListWznmQPstList& rst
		) {
};

void TblWznmQPstList::updateRec(
			WznmQPstList* rec
		) {
};

void TblWznmQPstList::updateRst(
			ListWznmQPstList& rst
		) {
};

void TblWznmQPstList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQPstList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQPstList::loadRecByQref(
			ubigint qref
			, WznmQPstList** rec
		) {
	return false;
};

ubigint TblWznmQPstList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPstList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQPstList
 ******************************************************************************/

MyTblWznmQPstList::MyTblWznmQPstList() :
			TblWznmQPstList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQPstList::~MyTblWznmQPstList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQPstList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQPstList (jref, jnum, ref, sref, Title, refWznmMVersion, refIxVTbl, refUref, ixWznmWArgtype) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQPstList SET jref = ?, jnum = ?, ref = ?, sref = ?, Title = ?, refWznmMVersion = ?, refIxVTbl = ?, refUref = ?, ixWznmWArgtype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQPstList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQPstList WHERE jref = ?", false);
};

bool MyTblWznmQPstList::loadRecBySQL(
			const string& sqlstr
			, WznmQPstList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQPstList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQPstList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQPstList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQPstList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->refWznmMVersion = atoll((char*) dbrow[6]); else _rec->refWznmMVersion = 0;
		if (dbrow[7]) _rec->refIxVTbl = atol((char*) dbrow[7]); else _rec->refIxVTbl = 0;
		if (dbrow[8]) _rec->refUref = atoll((char*) dbrow[8]); else _rec->refUref = 0;
		if (dbrow[9]) _rec->ixWznmWArgtype = atol((char*) dbrow[9]); else _rec->ixWznmWArgtype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQPstList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPstList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQPstList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQPstList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQPstList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQPstList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->refWznmMVersion = atoll((char*) dbrow[6]); else rec->refWznmMVersion = 0;
			if (dbrow[7]) rec->refIxVTbl = atol((char*) dbrow[7]); else rec->refIxVTbl = 0;
			if (dbrow[8]) rec->refUref = atoll((char*) dbrow[8]); else rec->refUref = 0;
			if (dbrow[9]) rec->ixWznmWArgtype = atol((char*) dbrow[9]); else rec->ixWznmWArgtype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQPstList::insertRec(
			WznmQPstList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVersion,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixWznmWArgtype,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQPstList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQPstList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQPstList::insertRst(
			ListWznmQPstList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQPstList::updateRec(
			WznmQPstList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVersion,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixWznmWArgtype,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQPstList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQPstList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQPstList::updateRst(
			ListWznmQPstList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQPstList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQPstList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQPstList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQPstList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQPstList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQPstList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQPstList::loadRecByQref(
			ubigint qref
			, WznmQPstList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQPstList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQPstList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPstList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQPstList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQPstList
 ******************************************************************************/

PgTblWznmQPstList::PgTblWznmQPstList() :
			TblWznmQPstList()
			, PgTable()
		{
};

PgTblWznmQPstList::~PgTblWznmQPstList() {
};

void PgTblWznmQPstList::initStatements() {
	createStatement("TblWznmQPstList_insertRec", "INSERT INTO TblWznmQPstList (jref, jnum, ref, sref, Title, refWznmMVersion, refIxVTbl, refUref, ixWznmWArgtype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9);
	createStatement("TblWznmQPstList_updateRec", "UPDATE TblWznmQPstList SET jref = $1, jnum = $2, ref = $3, sref = $4, Title = $5, refWznmMVersion = $6, refIxVTbl = $7, refUref = $8, ixWznmWArgtype = $9 WHERE qref = $10", 10);
	createStatement("TblWznmQPstList_removeRecByQref", "DELETE FROM TblWznmQPstList WHERE qref = $1", 1);
	createStatement("TblWznmQPstList_removeRstByJref", "DELETE FROM TblWznmQPstList WHERE jref = $1", 1);

	createStatement("TblWznmQPstList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Title, refWznmMVersion, refIxVTbl, refUref, ixWznmWArgtype FROM TblWznmQPstList WHERE qref = $1", 1);
	createStatement("TblWznmQPstList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Title, refWznmMVersion, refIxVTbl, refUref, ixWznmWArgtype FROM TblWznmQPstList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQPstList::loadRec(
			PGresult* res
			, WznmQPstList** rec
		) {
	char* ptr;

	WznmQPstList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQPstList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "ixwznmwargtype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixWznmWArgtype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQPstList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQPstList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQPstList* rec;

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
			PQfnumber(res, "title"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "ixwznmwargtype")
		};

		while (numread < numrow) {
			rec = new WznmQPstList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixWznmWArgtype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQPstList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQPstList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPstList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQPstList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQPstList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPstList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQPstList::loadRecBySQL(
			const string& sqlstr
			, WznmQPstList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQPstList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQPstList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQPstList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQPstList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQPstList::insertRec(
			WznmQPstList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _ixWznmWArgtype = htonl(rec->ixWznmWArgtype);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_ixWznmWArgtype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQPstList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQPstList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQPstList::insertRst(
			ListWznmQPstList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQPstList::updateRec(
			WznmQPstList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _ixWznmWArgtype = htonl(rec->ixWznmWArgtype);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_ixWznmWArgtype,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQPstList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPstList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQPstList::updateRst(
			ListWznmQPstList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQPstList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQPstList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPstList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQPstList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQPstList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQPstList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQPstList::loadRecByQref(
			ubigint qref
			, WznmQPstList** rec
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

	return loadRecByStmt("TblWznmQPstList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQPstList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQPstList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQPstList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
