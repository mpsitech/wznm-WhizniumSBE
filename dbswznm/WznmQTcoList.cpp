/**
	* \file WznmQTcoList.cpp
	* Dbs and XML wrapper for table TblWznmQTcoList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQTcoList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQTcoList
 ******************************************************************************/

WznmQTcoList::WznmQTcoList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Short
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint tblRefWznmMTable
			, const string stubTblRefWznmMTable
			, const uint fctIxVTbl
			, const string srefFctIxVTbl
			, const string titFctIxVTbl
			, const uint ixVSubtype
			, const string srefIxVSubtype
			, const string titIxVSubtype
			, const uint ixVAxisfct
			, const string srefIxVAxisfct
			, const string titIxVAxisfct
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Short = Short;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->tblRefWznmMTable = tblRefWznmMTable;
	this->stubTblRefWznmMTable = stubTblRefWznmMTable;
	this->fctIxVTbl = fctIxVTbl;
	this->srefFctIxVTbl = srefFctIxVTbl;
	this->titFctIxVTbl = titFctIxVTbl;
	this->ixVSubtype = ixVSubtype;
	this->srefIxVSubtype = srefIxVSubtype;
	this->titIxVSubtype = titIxVSubtype;
	this->ixVAxisfct = ixVAxisfct;
	this->srefIxVAxisfct = srefIxVAxisfct;
	this->titIxVAxisfct = titIxVAxisfct;
};

void WznmQTcoList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQTcoList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "sho", Short);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "tbl", stubTblRefWznmMTable);
		writeString(wr, "fct", srefFctIxVTbl);
		writeString(wr, "fct2", titFctIxVTbl);
		writeString(wr, "sty", srefIxVSubtype);
		writeString(wr, "sty2", titIxVSubtype);
		writeString(wr, "axf", srefIxVAxisfct);
		writeString(wr, "axf2", titIxVAxisfct);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Short", Short);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubTblRefWznmMTable", stubTblRefWznmMTable);
		writeString(wr, "srefFctIxVTbl", srefFctIxVTbl);
		writeString(wr, "titFctIxVTbl", titFctIxVTbl);
		writeString(wr, "srefIxVSubtype", srefIxVSubtype);
		writeString(wr, "titIxVSubtype", titIxVSubtype);
		writeString(wr, "srefIxVAxisfct", srefIxVAxisfct);
		writeString(wr, "titIxVAxisfct", titIxVAxisfct);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQTcoList
 ******************************************************************************/

ListWznmQTcoList::ListWznmQTcoList() {
};

ListWznmQTcoList::ListWznmQTcoList(
			const ListWznmQTcoList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQTcoList(*(src.nodes[i]));
};

ListWznmQTcoList::~ListWznmQTcoList() {
	clear();
};

void ListWznmQTcoList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQTcoList::size() const {
	return(nodes.size());
};

void ListWznmQTcoList::append(
			WznmQTcoList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQTcoList& ListWznmQTcoList::operator=(
			const ListWznmQTcoList& src
		) {
	WznmQTcoList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQTcoList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQTcoList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQTcoList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQTcoList
 ******************************************************************************/

TblWznmQTcoList::TblWznmQTcoList() {
};

TblWznmQTcoList::~TblWznmQTcoList() {
};

bool TblWznmQTcoList::loadRecBySQL(
			const string& sqlstr
			, WznmQTcoList** rec
		) {
	return false;
};

ubigint TblWznmQTcoList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTcoList& rst
		) {
	return 0;
};

ubigint TblWznmQTcoList::insertRec(
			WznmQTcoList* rec
		) {
	return 0;
};

ubigint TblWznmQTcoList::insertNewRec(
			WznmQTcoList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Short
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint tblRefWznmMTable
			, const string stubTblRefWznmMTable
			, const uint fctIxVTbl
			, const string srefFctIxVTbl
			, const string titFctIxVTbl
			, const uint ixVSubtype
			, const string srefIxVSubtype
			, const string titIxVSubtype
			, const uint ixVAxisfct
			, const string srefIxVAxisfct
			, const string titIxVAxisfct
		) {
	ubigint retval = 0;
	WznmQTcoList* _rec = NULL;

	_rec = new WznmQTcoList(0, jref, jnum, ref, sref, Short, ixVBasetype, srefIxVBasetype, titIxVBasetype, tblRefWznmMTable, stubTblRefWznmMTable, fctIxVTbl, srefFctIxVTbl, titFctIxVTbl, ixVSubtype, srefIxVSubtype, titIxVSubtype, ixVAxisfct, srefIxVAxisfct, titIxVAxisfct);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQTcoList::appendNewRecToRst(
			ListWznmQTcoList& rst
			, WznmQTcoList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Short
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint tblRefWznmMTable
			, const string stubTblRefWznmMTable
			, const uint fctIxVTbl
			, const string srefFctIxVTbl
			, const string titFctIxVTbl
			, const uint ixVSubtype
			, const string srefIxVSubtype
			, const string titIxVSubtype
			, const uint ixVAxisfct
			, const string srefIxVAxisfct
			, const string titIxVAxisfct
		) {
	ubigint retval = 0;
	WznmQTcoList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Short, ixVBasetype, srefIxVBasetype, titIxVBasetype, tblRefWznmMTable, stubTblRefWznmMTable, fctIxVTbl, srefFctIxVTbl, titFctIxVTbl, ixVSubtype, srefIxVSubtype, titIxVSubtype, ixVAxisfct, srefIxVAxisfct, titIxVAxisfct);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQTcoList::insertRst(
			ListWznmQTcoList& rst
		) {
};

void TblWznmQTcoList::updateRec(
			WznmQTcoList* rec
		) {
};

void TblWznmQTcoList::updateRst(
			ListWznmQTcoList& rst
		) {
};

void TblWznmQTcoList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQTcoList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQTcoList::loadRecByQref(
			ubigint qref
			, WznmQTcoList** rec
		) {
	return false;
};

ubigint TblWznmQTcoList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTcoList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQTcoList
 ******************************************************************************/

MyTblWznmQTcoList::MyTblWznmQTcoList() :
			TblWznmQTcoList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQTcoList::~MyTblWznmQTcoList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQTcoList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQTcoList (jref, jnum, ref, sref, Short, ixVBasetype, tblRefWznmMTable, fctIxVTbl, ixVSubtype, ixVAxisfct) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQTcoList SET jref = ?, jnum = ?, ref = ?, sref = ?, Short = ?, ixVBasetype = ?, tblRefWznmMTable = ?, fctIxVTbl = ?, ixVSubtype = ?, ixVAxisfct = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQTcoList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQTcoList WHERE jref = ?", false);
};

bool MyTblWznmQTcoList::loadRecBySQL(
			const string& sqlstr
			, WznmQTcoList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQTcoList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTcoList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTcoList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQTcoList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Short.assign(dbrow[5], dblengths[5]); else _rec->Short = "";
		if (dbrow[6]) _rec->ixVBasetype = atol((char*) dbrow[6]); else _rec->ixVBasetype = 0;
		if (dbrow[7]) _rec->tblRefWznmMTable = atoll((char*) dbrow[7]); else _rec->tblRefWznmMTable = 0;
		if (dbrow[8]) _rec->fctIxVTbl = atol((char*) dbrow[8]); else _rec->fctIxVTbl = 0;
		if (dbrow[9]) _rec->ixVSubtype = atol((char*) dbrow[9]); else _rec->ixVSubtype = 0;
		if (dbrow[10]) _rec->ixVAxisfct = atol((char*) dbrow[10]); else _rec->ixVAxisfct = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQTcoList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTcoList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQTcoList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQTcoList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQTcoList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQTcoList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Short.assign(dbrow[5], dblengths[5]); else rec->Short = "";
			if (dbrow[6]) rec->ixVBasetype = atol((char*) dbrow[6]); else rec->ixVBasetype = 0;
			if (dbrow[7]) rec->tblRefWznmMTable = atoll((char*) dbrow[7]); else rec->tblRefWznmMTable = 0;
			if (dbrow[8]) rec->fctIxVTbl = atol((char*) dbrow[8]); else rec->fctIxVTbl = 0;
			if (dbrow[9]) rec->ixVSubtype = atol((char*) dbrow[9]); else rec->ixVSubtype = 0;
			if (dbrow[10]) rec->ixVAxisfct = atol((char*) dbrow[10]); else rec->ixVAxisfct = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQTcoList::insertRec(
			WznmQTcoList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();
	l[4] = rec->Short.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Short.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->tblRefWznmMTable,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->fctIxVTbl,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVSubtype,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixVAxisfct,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQTcoList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQTcoList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQTcoList::insertRst(
			ListWznmQTcoList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQTcoList::updateRec(
			WznmQTcoList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->sref.length();
	l[4] = rec->Short.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Short.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->tblRefWznmMTable,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->fctIxVTbl,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVSubtype,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixVAxisfct,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQTcoList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQTcoList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTcoList::updateRst(
			ListWznmQTcoList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQTcoList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQTcoList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQTcoList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQTcoList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQTcoList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQTcoList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQTcoList::loadRecByQref(
			ubigint qref
			, WznmQTcoList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQTcoList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQTcoList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTcoList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQTcoList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQTcoList
 ******************************************************************************/

PgTblWznmQTcoList::PgTblWznmQTcoList() :
			TblWznmQTcoList()
			, PgTable()
		{
};

PgTblWznmQTcoList::~PgTblWznmQTcoList() {
};

void PgTblWznmQTcoList::initStatements() {
	createStatement("TblWznmQTcoList_insertRec", "INSERT INTO TblWznmQTcoList (jref, jnum, ref, sref, Short, ixVBasetype, tblRefWznmMTable, fctIxVTbl, ixVSubtype, ixVAxisfct) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblWznmQTcoList_updateRec", "UPDATE TblWznmQTcoList SET jref = $1, jnum = $2, ref = $3, sref = $4, Short = $5, ixVBasetype = $6, tblRefWznmMTable = $7, fctIxVTbl = $8, ixVSubtype = $9, ixVAxisfct = $10 WHERE qref = $11", 11);
	createStatement("TblWznmQTcoList_removeRecByQref", "DELETE FROM TblWznmQTcoList WHERE qref = $1", 1);
	createStatement("TblWznmQTcoList_removeRstByJref", "DELETE FROM TblWznmQTcoList WHERE jref = $1", 1);

	createStatement("TblWznmQTcoList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Short, ixVBasetype, tblRefWznmMTable, fctIxVTbl, ixVSubtype, ixVAxisfct FROM TblWznmQTcoList WHERE qref = $1", 1);
	createStatement("TblWznmQTcoList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Short, ixVBasetype, tblRefWznmMTable, fctIxVTbl, ixVSubtype, ixVAxisfct FROM TblWznmQTcoList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQTcoList::loadRec(
			PGresult* res
			, WznmQTcoList** rec
		) {
	char* ptr;

	WznmQTcoList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQTcoList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "tblrefwznmmtable"),
			PQfnumber(res, "fctixvtbl"),
			PQfnumber(res, "ixvsubtype"),
			PQfnumber(res, "ixvaxisfct")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->tblRefWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->fctIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVSubtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixVAxisfct = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQTcoList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQTcoList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQTcoList* rec;

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
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "tblrefwznmmtable"),
			PQfnumber(res, "fctixvtbl"),
			PQfnumber(res, "ixvsubtype"),
			PQfnumber(res, "ixvaxisfct")
		};

		while (numread < numrow) {
			rec = new WznmQTcoList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->tblRefWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->fctIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVSubtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixVAxisfct = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQTcoList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQTcoList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTcoList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTcoList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQTcoList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTcoList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQTcoList::loadRecBySQL(
			const string& sqlstr
			, WznmQTcoList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTcoList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQTcoList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQTcoList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQTcoList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQTcoList::insertRec(
			WznmQTcoList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _tblRefWznmMTable = htonl64(rec->tblRefWznmMTable);
	uint _fctIxVTbl = htonl(rec->fctIxVTbl);
	uint _ixVSubtype = htonl(rec->ixVSubtype);
	uint _ixVAxisfct = htonl(rec->ixVAxisfct);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_tblRefWznmMTable,
		(char*) &_fctIxVTbl,
		(char*) &_ixVSubtype,
		(char*) &_ixVAxisfct
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQTcoList_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQTcoList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQTcoList::insertRst(
			ListWznmQTcoList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQTcoList::updateRec(
			WznmQTcoList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _tblRefWznmMTable = htonl64(rec->tblRefWznmMTable);
	uint _fctIxVTbl = htonl(rec->fctIxVTbl);
	uint _ixVSubtype = htonl(rec->ixVSubtype);
	uint _ixVAxisfct = htonl(rec->ixVAxisfct);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_tblRefWznmMTable,
		(char*) &_fctIxVTbl,
		(char*) &_ixVSubtype,
		(char*) &_ixVAxisfct,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQTcoList_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTcoList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTcoList::updateRst(
			ListWznmQTcoList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQTcoList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQTcoList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTcoList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQTcoList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQTcoList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQTcoList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQTcoList::loadRecByQref(
			ubigint qref
			, WznmQTcoList** rec
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

	return loadRecByStmt("TblWznmQTcoList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQTcoList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQTcoList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQTcoList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

