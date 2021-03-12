/**
	* \file WznmQQryList.cpp
	* Dbs and XML wrapper for table TblWznmQQryList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQQryList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQryList
 ******************************************************************************/

WznmQQryList::WznmQQryList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const ubigint supRefWznmMQuery
			, const string stubSupRefWznmMQuery
			, const uint supIxVSubrole
			, const string srefSupIxVSubrole
			, const string titSupIxVSubrole
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
			, const ubigint qtbRefWznmMTable
			, const string stubQtbRefWznmMTable
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->refWznmMVersion = refWznmMVersion;
	this->stubRefWznmMVersion = stubRefWznmMVersion;
	this->supRefWznmMQuery = supRefWznmMQuery;
	this->stubSupRefWznmMQuery = stubSupRefWznmMQuery;
	this->supIxVSubrole = supIxVSubrole;
	this->srefSupIxVSubrole = srefSupIxVSubrole;
	this->titSupIxVSubrole = titSupIxVSubrole;
	this->refWznmMTable = refWznmMTable;
	this->stubRefWznmMTable = stubRefWznmMTable;
	this->qtbRefWznmMTable = qtbRefWznmMTable;
	this->stubQtbRefWznmMTable = stubQtbRefWznmMTable;
};

void WznmQQryList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["srf"] = sref;
		me["typ"] = srefIxVBasetype;
		me["typ2"] = titIxVBasetype;
		me["ver"] = stubRefWznmMVersion;
		me["sup"] = stubSupRefWznmMQuery;
		me["srl"] = srefSupIxVSubrole;
		me["srl2"] = titSupIxVSubrole;
		me["tbl"] = stubRefWznmMTable;
		me["qtb"] = stubQtbRefWznmMTable;
	} else {
		me["sref"] = sref;
		me["srefIxVBasetype"] = srefIxVBasetype;
		me["titIxVBasetype"] = titIxVBasetype;
		me["stubRefWznmMVersion"] = stubRefWznmMVersion;
		me["stubSupRefWznmMQuery"] = stubSupRefWznmMQuery;
		me["srefSupIxVSubrole"] = srefSupIxVSubrole;
		me["titSupIxVSubrole"] = titSupIxVSubrole;
		me["stubRefWznmMTable"] = stubRefWznmMTable;
		me["stubQtbRefWznmMTable"] = stubQtbRefWznmMTable;
	};
};

void WznmQQryList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQQryList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "ver", stubRefWznmMVersion);
		writeString(wr, "sup", stubSupRefWznmMQuery);
		writeString(wr, "srl", srefSupIxVSubrole);
		writeString(wr, "srl2", titSupIxVSubrole);
		writeString(wr, "tbl", stubRefWznmMTable);
		writeString(wr, "qtb", stubQtbRefWznmMTable);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubRefWznmMVersion", stubRefWznmMVersion);
		writeString(wr, "stubSupRefWznmMQuery", stubSupRefWznmMQuery);
		writeString(wr, "srefSupIxVSubrole", srefSupIxVSubrole);
		writeString(wr, "titSupIxVSubrole", titSupIxVSubrole);
		writeString(wr, "stubRefWznmMTable", stubRefWznmMTable);
		writeString(wr, "stubQtbRefWznmMTable", stubQtbRefWznmMTable);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQQryList
 ******************************************************************************/

ListWznmQQryList::ListWznmQQryList() {
};

ListWznmQQryList::ListWznmQQryList(
			const ListWznmQQryList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryList(*(src.nodes[i]));
};

ListWznmQQryList::~ListWznmQQryList() {
	clear();
};

void ListWznmQQryList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQQryList::size() const {
	return(nodes.size());
};

void ListWznmQQryList::append(
			WznmQQryList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQQryList& ListWznmQQryList::operator=(
			const ListWznmQQryList& src
		) {
	WznmQQryList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQQryList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQQryList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQQryList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQQryList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQQryList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQQryList
 ******************************************************************************/

TblWznmQQryList::TblWznmQQryList() {
};

TblWznmQQryList::~TblWznmQQryList() {
};

bool TblWznmQQryList::loadRecBySQL(
			const string& sqlstr
			, WznmQQryList** rec
		) {
	return false;
};

ubigint TblWznmQQryList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryList& rst
		) {
	return 0;
};

ubigint TblWznmQQryList::insertRec(
			WznmQQryList* rec
		) {
	return 0;
};

ubigint TblWznmQQryList::insertNewRec(
			WznmQQryList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const ubigint supRefWznmMQuery
			, const string stubSupRefWznmMQuery
			, const uint supIxVSubrole
			, const string srefSupIxVSubrole
			, const string titSupIxVSubrole
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
			, const ubigint qtbRefWznmMTable
			, const string stubQtbRefWznmMTable
		) {
	ubigint retval = 0;
	WznmQQryList* _rec = NULL;

	_rec = new WznmQQryList(0, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, refWznmMVersion, stubRefWznmMVersion, supRefWznmMQuery, stubSupRefWznmMQuery, supIxVSubrole, srefSupIxVSubrole, titSupIxVSubrole, refWznmMTable, stubRefWznmMTable, qtbRefWznmMTable, stubQtbRefWznmMTable);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQQryList::appendNewRecToRst(
			ListWznmQQryList& rst
			, WznmQQryList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const ubigint supRefWznmMQuery
			, const string stubSupRefWznmMQuery
			, const uint supIxVSubrole
			, const string srefSupIxVSubrole
			, const string titSupIxVSubrole
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
			, const ubigint qtbRefWznmMTable
			, const string stubQtbRefWznmMTable
		) {
	ubigint retval = 0;
	WznmQQryList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, refWznmMVersion, stubRefWznmMVersion, supRefWznmMQuery, stubSupRefWznmMQuery, supIxVSubrole, srefSupIxVSubrole, titSupIxVSubrole, refWznmMTable, stubRefWznmMTable, qtbRefWznmMTable, stubQtbRefWznmMTable);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQQryList::insertRst(
			ListWznmQQryList& rst
		) {
};

void TblWznmQQryList::updateRec(
			WznmQQryList* rec
		) {
};

void TblWznmQQryList::updateRst(
			ListWznmQQryList& rst
		) {
};

void TblWznmQQryList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQQryList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQQryList::loadRecByQref(
			ubigint qref
			, WznmQQryList** rec
		) {
	return false;
};

ubigint TblWznmQQryList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQQryList
 ******************************************************************************/

MyTblWznmQQryList::MyTblWznmQQryList() :
			TblWznmQQryList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQQryList::~MyTblWznmQQryList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQQryList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQQryList (jref, jnum, ref, sref, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refWznmMTable, qtbRefWznmMTable) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQQryList SET jref = ?, jnum = ?, ref = ?, sref = ?, ixVBasetype = ?, refWznmMVersion = ?, supRefWznmMQuery = ?, supIxVSubrole = ?, refWznmMTable = ?, qtbRefWznmMTable = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQQryList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQQryList WHERE jref = ?", false);
};

bool MyTblWznmQQryList::loadRecBySQL(
			const string& sqlstr
			, WznmQQryList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQQryList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQryList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQryList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQQryList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixVBasetype = atol((char*) dbrow[5]); else _rec->ixVBasetype = 0;
		if (dbrow[6]) _rec->refWznmMVersion = atoll((char*) dbrow[6]); else _rec->refWznmMVersion = 0;
		if (dbrow[7]) _rec->supRefWznmMQuery = atoll((char*) dbrow[7]); else _rec->supRefWznmMQuery = 0;
		if (dbrow[8]) _rec->supIxVSubrole = atol((char*) dbrow[8]); else _rec->supIxVSubrole = 0;
		if (dbrow[9]) _rec->refWznmMTable = atoll((char*) dbrow[9]); else _rec->refWznmMTable = 0;
		if (dbrow[10]) _rec->qtbRefWznmMTable = atoll((char*) dbrow[10]); else _rec->qtbRefWznmMTable = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQQryList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQQryList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQryList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQryList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQQryList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixVBasetype = atol((char*) dbrow[5]); else rec->ixVBasetype = 0;
			if (dbrow[6]) rec->refWznmMVersion = atoll((char*) dbrow[6]); else rec->refWznmMVersion = 0;
			if (dbrow[7]) rec->supRefWznmMQuery = atoll((char*) dbrow[7]); else rec->supRefWznmMQuery = 0;
			if (dbrow[8]) rec->supIxVSubrole = atol((char*) dbrow[8]); else rec->supIxVSubrole = 0;
			if (dbrow[9]) rec->refWznmMTable = atoll((char*) dbrow[9]); else rec->refWznmMTable = 0;
			if (dbrow[10]) rec->qtbRefWznmMTable = atoll((char*) dbrow[10]); else rec->qtbRefWznmMTable = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQQryList::insertRec(
			WznmQQryList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVersion,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->supRefWznmMQuery,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->supIxVSubrole,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMTable,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qtbRefWznmMTable,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQQryList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQQryList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQQryList::insertRst(
			ListWznmQQryList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQQryList::updateRec(
			WznmQQryList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVersion,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->supRefWznmMQuery,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->supIxVSubrole,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMTable,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qtbRefWznmMTable,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQQryList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQQryList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQryList::updateRst(
			ListWznmQQryList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQQryList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQQryList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQQryList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQryList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQQryList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQQryList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQQryList::loadRecByQref(
			ubigint qref
			, WznmQQryList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQQryList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQQryList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQQryList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQQryList
 ******************************************************************************/

PgTblWznmQQryList::PgTblWznmQQryList() :
			TblWznmQQryList()
			, PgTable()
		{
};

PgTblWznmQQryList::~PgTblWznmQQryList() {
};

void PgTblWznmQQryList::initStatements() {
	createStatement("TblWznmQQryList_insertRec", "INSERT INTO TblWznmQQryList (jref, jnum, ref, sref, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refWznmMTable, qtbRefWznmMTable) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblWznmQQryList_updateRec", "UPDATE TblWznmQQryList SET jref = $1, jnum = $2, ref = $3, sref = $4, ixVBasetype = $5, refWznmMVersion = $6, supRefWznmMQuery = $7, supIxVSubrole = $8, refWznmMTable = $9, qtbRefWznmMTable = $10 WHERE qref = $11", 11);
	createStatement("TblWznmQQryList_removeRecByQref", "DELETE FROM TblWznmQQryList WHERE qref = $1", 1);
	createStatement("TblWznmQQryList_removeRstByJref", "DELETE FROM TblWznmQQryList WHERE jref = $1", 1);

	createStatement("TblWznmQQryList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refWznmMTable, qtbRefWznmMTable FROM TblWznmQQryList WHERE qref = $1", 1);
	createStatement("TblWznmQQryList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, refWznmMVersion, supRefWznmMQuery, supIxVSubrole, refWznmMTable, qtbRefWznmMTable FROM TblWznmQQryList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQQryList::loadRec(
			PGresult* res
			, WznmQQryList** rec
		) {
	char* ptr;

	WznmQQryList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQQryList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "suprefwznmmquery"),
			PQfnumber(res, "supixvsubrole"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "qtbrefwznmmtable")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->supRefWznmMQuery = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->supIxVSubrole = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->qtbRefWznmMTable = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQQryList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQQryList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQQryList* rec;

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
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "suprefwznmmquery"),
			PQfnumber(res, "supixvsubrole"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "qtbrefwznmmtable")
		};

		while (numread < numrow) {
			rec = new WznmQQryList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->supRefWznmMQuery = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->supIxVSubrole = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->qtbRefWznmMTable = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQQryList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQQryList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQryList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQQryList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQQryList::loadRecBySQL(
			const string& sqlstr
			, WznmQQryList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQryList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQryList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQryList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQQryList::insertRec(
			WznmQQryList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _supRefWznmMQuery = htonl64(rec->supRefWznmMQuery);
	uint _supIxVSubrole = htonl(rec->supIxVSubrole);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _qtbRefWznmMTable = htonl64(rec->qtbRefWznmMTable);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_supRefWznmMQuery,
		(char*) &_supIxVSubrole,
		(char*) &_refWznmMTable,
		(char*) &_qtbRefWznmMTable
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQQryList_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQQryList::insertRst(
			ListWznmQQryList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQQryList::updateRec(
			WznmQQryList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _supRefWznmMQuery = htonl64(rec->supRefWznmMQuery);
	uint _supIxVSubrole = htonl(rec->supIxVSubrole);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _qtbRefWznmMTable = htonl64(rec->qtbRefWznmMTable);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_supRefWznmMQuery,
		(char*) &_supIxVSubrole,
		(char*) &_refWznmMTable,
		(char*) &_qtbRefWznmMTable,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQQryList_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQryList::updateRst(
			ListWznmQQryList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQQryList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQQryList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQryList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQQryList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQQryList::loadRecByQref(
			ubigint qref
			, WznmQQryList** rec
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

	return loadRecByStmt("TblWznmQQryList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQQryList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQQryList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
