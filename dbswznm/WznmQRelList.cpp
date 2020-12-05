/**
	* \file WznmQRelList.cpp
	* Dbs and XML wrapper for table TblWznmQRelList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQRelList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRelList
 ******************************************************************************/

WznmQRelList::WznmQRelList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint frRefWznmMTable
			, const string stubFrRefWznmMTable
			, const ubigint frsRefWznmMSubset
			, const string stubFrsRefWznmMSubset
			, const ubigint toRefWznmMTable
			, const string stubToRefWznmMTable
			, const ubigint tosRefWznmMSubset
			, const string stubTosRefWznmMSubset
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const ubigint supRefWznmMRelation
			, const string stubSupRefWznmMRelation
			, const uint supIxVSubrole
			, const string srefSupIxVSubrole
			, const string titSupIxVSubrole
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
			, const string Prefix
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->frRefWznmMTable = frRefWznmMTable;
	this->stubFrRefWznmMTable = stubFrRefWznmMTable;
	this->frsRefWznmMSubset = frsRefWznmMSubset;
	this->stubFrsRefWznmMSubset = stubFrsRefWznmMSubset;
	this->toRefWznmMTable = toRefWznmMTable;
	this->stubToRefWznmMTable = stubToRefWznmMTable;
	this->tosRefWznmMSubset = tosRefWznmMSubset;
	this->stubTosRefWznmMSubset = stubTosRefWznmMSubset;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->refWznmMVersion = refWznmMVersion;
	this->stubRefWznmMVersion = stubRefWznmMVersion;
	this->supRefWznmMRelation = supRefWznmMRelation;
	this->stubSupRefWznmMRelation = stubSupRefWznmMRelation;
	this->supIxVSubrole = supIxVSubrole;
	this->srefSupIxVSubrole = srefSupIxVSubrole;
	this->titSupIxVSubrole = titSupIxVSubrole;
	this->refWznmMTable = refWznmMTable;
	this->stubRefWznmMTable = stubRefWznmMTable;
	this->Prefix = Prefix;
};

void WznmQRelList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQRelList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "frt", stubFrRefWznmMTable);
		writeString(wr, "frs", stubFrsRefWznmMSubset);
		writeString(wr, "tot", stubToRefWznmMTable);
		writeString(wr, "tos", stubTosRefWznmMSubset);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "ver", stubRefWznmMVersion);
		writeString(wr, "sup", stubSupRefWznmMRelation);
		writeString(wr, "srl", srefSupIxVSubrole);
		writeString(wr, "srl2", titSupIxVSubrole);
		writeString(wr, "tbl", stubRefWznmMTable);
		writeString(wr, "pfx", Prefix);
	} else {
		writeString(wr, "stubFrRefWznmMTable", stubFrRefWznmMTable);
		writeString(wr, "stubFrsRefWznmMSubset", stubFrsRefWznmMSubset);
		writeString(wr, "stubToRefWznmMTable", stubToRefWznmMTable);
		writeString(wr, "stubTosRefWznmMSubset", stubTosRefWznmMSubset);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubRefWznmMVersion", stubRefWznmMVersion);
		writeString(wr, "stubSupRefWznmMRelation", stubSupRefWznmMRelation);
		writeString(wr, "srefSupIxVSubrole", srefSupIxVSubrole);
		writeString(wr, "titSupIxVSubrole", titSupIxVSubrole);
		writeString(wr, "stubRefWznmMTable", stubRefWznmMTable);
		writeString(wr, "Prefix", Prefix);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQRelList
 ******************************************************************************/

ListWznmQRelList::ListWznmQRelList() {
};

ListWznmQRelList::ListWznmQRelList(
			const ListWznmQRelList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRelList(*(src.nodes[i]));
};

ListWznmQRelList::~ListWznmQRelList() {
	clear();
};

void ListWznmQRelList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQRelList::size() const {
	return(nodes.size());
};

void ListWznmQRelList::append(
			WznmQRelList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQRelList& ListWznmQRelList::operator=(
			const ListWznmQRelList& src
		) {
	WznmQRelList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQRelList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQRelList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQRelList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQRelList
 ******************************************************************************/

TblWznmQRelList::TblWznmQRelList() {
};

TblWznmQRelList::~TblWznmQRelList() {
};

bool TblWznmQRelList::loadRecBySQL(
			const string& sqlstr
			, WznmQRelList** rec
		) {
	return false;
};

ubigint TblWznmQRelList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRelList& rst
		) {
	return 0;
};

ubigint TblWznmQRelList::insertRec(
			WznmQRelList* rec
		) {
	return 0;
};

ubigint TblWznmQRelList::insertNewRec(
			WznmQRelList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint frRefWznmMTable
			, const string stubFrRefWznmMTable
			, const ubigint frsRefWznmMSubset
			, const string stubFrsRefWznmMSubset
			, const ubigint toRefWznmMTable
			, const string stubToRefWznmMTable
			, const ubigint tosRefWznmMSubset
			, const string stubTosRefWznmMSubset
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const ubigint supRefWznmMRelation
			, const string stubSupRefWznmMRelation
			, const uint supIxVSubrole
			, const string srefSupIxVSubrole
			, const string titSupIxVSubrole
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
			, const string Prefix
		) {
	ubigint retval = 0;
	WznmQRelList* _rec = NULL;

	_rec = new WznmQRelList(0, jref, jnum, ref, frRefWznmMTable, stubFrRefWznmMTable, frsRefWznmMSubset, stubFrsRefWznmMSubset, toRefWznmMTable, stubToRefWznmMTable, tosRefWznmMSubset, stubTosRefWznmMSubset, ixVBasetype, srefIxVBasetype, titIxVBasetype, refWznmMVersion, stubRefWznmMVersion, supRefWznmMRelation, stubSupRefWznmMRelation, supIxVSubrole, srefSupIxVSubrole, titSupIxVSubrole, refWznmMTable, stubRefWznmMTable, Prefix);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQRelList::appendNewRecToRst(
			ListWznmQRelList& rst
			, WznmQRelList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint frRefWznmMTable
			, const string stubFrRefWznmMTable
			, const ubigint frsRefWznmMSubset
			, const string stubFrsRefWznmMSubset
			, const ubigint toRefWznmMTable
			, const string stubToRefWznmMTable
			, const ubigint tosRefWznmMSubset
			, const string stubTosRefWznmMSubset
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const ubigint supRefWznmMRelation
			, const string stubSupRefWznmMRelation
			, const uint supIxVSubrole
			, const string srefSupIxVSubrole
			, const string titSupIxVSubrole
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
			, const string Prefix
		) {
	ubigint retval = 0;
	WznmQRelList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, frRefWznmMTable, stubFrRefWznmMTable, frsRefWznmMSubset, stubFrsRefWznmMSubset, toRefWznmMTable, stubToRefWznmMTable, tosRefWznmMSubset, stubTosRefWznmMSubset, ixVBasetype, srefIxVBasetype, titIxVBasetype, refWznmMVersion, stubRefWznmMVersion, supRefWznmMRelation, stubSupRefWznmMRelation, supIxVSubrole, srefSupIxVSubrole, titSupIxVSubrole, refWznmMTable, stubRefWznmMTable, Prefix);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQRelList::insertRst(
			ListWznmQRelList& rst
		) {
};

void TblWznmQRelList::updateRec(
			WznmQRelList* rec
		) {
};

void TblWznmQRelList::updateRst(
			ListWznmQRelList& rst
		) {
};

void TblWznmQRelList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQRelList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQRelList::loadRecByQref(
			ubigint qref
			, WznmQRelList** rec
		) {
	return false;
};

ubigint TblWznmQRelList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRelList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQRelList
 ******************************************************************************/

MyTblWznmQRelList::MyTblWznmQRelList() :
			TblWznmQRelList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQRelList::~MyTblWznmQRelList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQRelList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQRelList (jref, jnum, ref, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, ixVBasetype, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, refWznmMTable, Prefix) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQRelList SET jref = ?, jnum = ?, ref = ?, frRefWznmMTable = ?, frsRefWznmMSubset = ?, toRefWznmMTable = ?, tosRefWznmMSubset = ?, ixVBasetype = ?, refWznmMVersion = ?, supRefWznmMRelation = ?, supIxVSubrole = ?, refWznmMTable = ?, Prefix = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQRelList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQRelList WHERE jref = ?", false);
};

bool MyTblWznmQRelList::loadRecBySQL(
			const string& sqlstr
			, WznmQRelList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQRelList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQRelList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQRelList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQRelList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->frRefWznmMTable = atoll((char*) dbrow[4]); else _rec->frRefWznmMTable = 0;
		if (dbrow[5]) _rec->frsRefWznmMSubset = atoll((char*) dbrow[5]); else _rec->frsRefWznmMSubset = 0;
		if (dbrow[6]) _rec->toRefWznmMTable = atoll((char*) dbrow[6]); else _rec->toRefWznmMTable = 0;
		if (dbrow[7]) _rec->tosRefWznmMSubset = atoll((char*) dbrow[7]); else _rec->tosRefWznmMSubset = 0;
		if (dbrow[8]) _rec->ixVBasetype = atol((char*) dbrow[8]); else _rec->ixVBasetype = 0;
		if (dbrow[9]) _rec->refWznmMVersion = atoll((char*) dbrow[9]); else _rec->refWznmMVersion = 0;
		if (dbrow[10]) _rec->supRefWznmMRelation = atoll((char*) dbrow[10]); else _rec->supRefWznmMRelation = 0;
		if (dbrow[11]) _rec->supIxVSubrole = atol((char*) dbrow[11]); else _rec->supIxVSubrole = 0;
		if (dbrow[12]) _rec->refWznmMTable = atoll((char*) dbrow[12]); else _rec->refWznmMTable = 0;
		if (dbrow[13]) _rec->Prefix.assign(dbrow[13], dblengths[13]); else _rec->Prefix = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQRelList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRelList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQRelList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQRelList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQRelList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQRelList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->frRefWznmMTable = atoll((char*) dbrow[4]); else rec->frRefWznmMTable = 0;
			if (dbrow[5]) rec->frsRefWznmMSubset = atoll((char*) dbrow[5]); else rec->frsRefWznmMSubset = 0;
			if (dbrow[6]) rec->toRefWznmMTable = atoll((char*) dbrow[6]); else rec->toRefWznmMTable = 0;
			if (dbrow[7]) rec->tosRefWznmMSubset = atoll((char*) dbrow[7]); else rec->tosRefWznmMSubset = 0;
			if (dbrow[8]) rec->ixVBasetype = atol((char*) dbrow[8]); else rec->ixVBasetype = 0;
			if (dbrow[9]) rec->refWznmMVersion = atoll((char*) dbrow[9]); else rec->refWznmMVersion = 0;
			if (dbrow[10]) rec->supRefWznmMRelation = atoll((char*) dbrow[10]); else rec->supRefWznmMRelation = 0;
			if (dbrow[11]) rec->supIxVSubrole = atol((char*) dbrow[11]); else rec->supIxVSubrole = 0;
			if (dbrow[12]) rec->refWznmMTable = atoll((char*) dbrow[12]); else rec->refWznmMTable = 0;
			if (dbrow[13]) rec->Prefix.assign(dbrow[13], dblengths[13]); else rec->Prefix = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQRelList::insertRec(
			WznmQRelList* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[12] = rec->Prefix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->frRefWznmMTable,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->frsRefWznmMSubset,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->toRefWznmMTable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->tosRefWznmMSubset,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVBasetype,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMVersion,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->supRefWznmMRelation,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->supIxVSubrole,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->refWznmMTable,&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Prefix.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQRelList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQRelList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQRelList::insertRst(
			ListWznmQRelList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQRelList::updateRec(
			WznmQRelList* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[12] = rec->Prefix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->frRefWznmMTable,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->frsRefWznmMSubset,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->toRefWznmMTable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->tosRefWznmMSubset,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVBasetype,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMVersion,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->supRefWznmMRelation,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->supIxVSubrole,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->refWznmMTable,&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Prefix.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->qref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQRelList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQRelList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQRelList::updateRst(
			ListWznmQRelList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQRelList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQRelList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQRelList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQRelList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQRelList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQRelList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQRelList::loadRecByQref(
			ubigint qref
			, WznmQRelList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQRelList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQRelList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRelList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQRelList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQRelList
 ******************************************************************************/

PgTblWznmQRelList::PgTblWznmQRelList() :
			TblWznmQRelList()
			, PgTable()
		{
};

PgTblWznmQRelList::~PgTblWznmQRelList() {
};

void PgTblWznmQRelList::initStatements() {
	createStatement("TblWznmQRelList_insertRec", "INSERT INTO TblWznmQRelList (jref, jnum, ref, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, ixVBasetype, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, refWznmMTable, Prefix) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING qref", 13);
	createStatement("TblWznmQRelList_updateRec", "UPDATE TblWznmQRelList SET jref = $1, jnum = $2, ref = $3, frRefWznmMTable = $4, frsRefWznmMSubset = $5, toRefWznmMTable = $6, tosRefWznmMSubset = $7, ixVBasetype = $8, refWznmMVersion = $9, supRefWznmMRelation = $10, supIxVSubrole = $11, refWznmMTable = $12, Prefix = $13 WHERE qref = $14", 14);
	createStatement("TblWznmQRelList_removeRecByQref", "DELETE FROM TblWznmQRelList WHERE qref = $1", 1);
	createStatement("TblWznmQRelList_removeRstByJref", "DELETE FROM TblWznmQRelList WHERE jref = $1", 1);

	createStatement("TblWznmQRelList_loadRecByQref", "SELECT qref, jref, jnum, ref, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, ixVBasetype, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, refWznmMTable, Prefix FROM TblWznmQRelList WHERE qref = $1", 1);
	createStatement("TblWznmQRelList_loadRstByJref", "SELECT qref, jref, jnum, ref, frRefWznmMTable, frsRefWznmMSubset, toRefWznmMTable, tosRefWznmMSubset, ixVBasetype, refWznmMVersion, supRefWznmMRelation, supIxVSubrole, refWznmMTable, Prefix FROM TblWznmQRelList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQRelList::loadRec(
			PGresult* res
			, WznmQRelList** rec
		) {
	char* ptr;

	WznmQRelList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQRelList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "frrefwznmmtable"),
			PQfnumber(res, "frsrefwznmmsubset"),
			PQfnumber(res, "torefwznmmtable"),
			PQfnumber(res, "tosrefwznmmsubset"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "suprefwznmmrelation"),
			PQfnumber(res, "supixvsubrole"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "prefix")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->frRefWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->frsRefWznmMSubset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->toRefWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->tosRefWznmMSubset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->supRefWznmMRelation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->supIxVSubrole = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Prefix.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQRelList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQRelList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQRelList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "frrefwznmmtable"),
			PQfnumber(res, "frsrefwznmmsubset"),
			PQfnumber(res, "torefwznmmtable"),
			PQfnumber(res, "tosrefwznmmsubset"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "suprefwznmmrelation"),
			PQfnumber(res, "supixvsubrole"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "prefix")
		};

		while (numread < numrow) {
			rec = new WznmQRelList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->frRefWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->frsRefWznmMSubset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->toRefWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->tosRefWznmMSubset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->supRefWznmMRelation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->supIxVSubrole = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Prefix.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQRelList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQRelList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRelList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQRelList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQRelList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRelList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQRelList::loadRecBySQL(
			const string& sqlstr
			, WznmQRelList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQRelList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQRelList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRelList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQRelList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQRelList::insertRec(
			WznmQRelList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _frRefWznmMTable = htonl64(rec->frRefWznmMTable);
	ubigint _frsRefWznmMSubset = htonl64(rec->frsRefWznmMSubset);
	ubigint _toRefWznmMTable = htonl64(rec->toRefWznmMTable);
	ubigint _tosRefWznmMSubset = htonl64(rec->tosRefWznmMSubset);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _supRefWznmMRelation = htonl64(rec->supRefWznmMRelation);
	uint _supIxVSubrole = htonl(rec->supIxVSubrole);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_frRefWznmMTable,
		(char*) &_frsRefWznmMSubset,
		(char*) &_toRefWznmMTable,
		(char*) &_tosRefWznmMSubset,
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_supRefWznmMRelation,
		(char*) &_supIxVSubrole,
		(char*) &_refWznmMTable,
		rec->Prefix.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQRelList_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRelList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQRelList::insertRst(
			ListWznmQRelList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQRelList::updateRec(
			WznmQRelList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _frRefWznmMTable = htonl64(rec->frRefWznmMTable);
	ubigint _frsRefWznmMSubset = htonl64(rec->frsRefWznmMSubset);
	ubigint _toRefWznmMTable = htonl64(rec->toRefWznmMTable);
	ubigint _tosRefWznmMSubset = htonl64(rec->tosRefWznmMSubset);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _supRefWznmMRelation = htonl64(rec->supRefWznmMRelation);
	uint _supIxVSubrole = htonl(rec->supIxVSubrole);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_frRefWznmMTable,
		(char*) &_frsRefWznmMSubset,
		(char*) &_toRefWznmMTable,
		(char*) &_tosRefWznmMSubset,
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_supRefWznmMRelation,
		(char*) &_supIxVSubrole,
		(char*) &_refWznmMTable,
		rec->Prefix.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQRelList_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRelList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQRelList::updateRst(
			ListWznmQRelList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQRelList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQRelList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRelList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQRelList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQRelList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRelList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQRelList::loadRecByQref(
			ubigint qref
			, WznmQRelList** rec
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

	return loadRecByStmt("TblWznmQRelList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQRelList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRelList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQRelList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

