/**
	* \file WznmQConList.cpp
	* Dbs and XML wrapper for table TblWznmQConList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQConList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQConList
 ******************************************************************************/

WznmQConList::WznmQConList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const uint hkIxVSection
			, const string srefHkIxVSection
			, const string titHkIxVSection
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const ubigint supRefWznmMControl
			, const string stubSupRefWznmMControl
			, const uint ixVSubtype
			, const string srefIxVSubtype
			, const string titIxVSubtype
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->hkIxVTbl = hkIxVTbl;
	this->srefHkIxVTbl = srefHkIxVTbl;
	this->titHkIxVTbl = titHkIxVTbl;
	this->hkUref = hkUref;
	this->stubHkUref = stubHkUref;
	this->hkIxVSection = hkIxVSection;
	this->srefHkIxVSection = srefHkIxVSection;
	this->titHkIxVSection = titHkIxVSection;
	this->refIxVTbl = refIxVTbl;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->refUref = refUref;
	this->stubRefUref = stubRefUref;
	this->supRefWznmMControl = supRefWznmMControl;
	this->stubSupRefWznmMControl = stubSupRefWznmMControl;
	this->ixVSubtype = ixVSubtype;
	this->srefIxVSubtype = srefIxVSubtype;
	this->titIxVSubtype = titIxVSubtype;
};

void WznmQConList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQConList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "hkt", srefHkIxVTbl);
		writeString(wr, "hkt2", titHkIxVTbl);
		writeString(wr, "hku", stubHkUref);
		writeString(wr, "sct", srefHkIxVSection);
		writeString(wr, "sct2", titHkIxVSection);
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
		writeString(wr, "sup", stubSupRefWznmMControl);
		writeString(wr, "sty", srefIxVSubtype);
		writeString(wr, "sty2", titIxVSubtype);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "srefHkIxVTbl", srefHkIxVTbl);
		writeString(wr, "titHkIxVTbl", titHkIxVTbl);
		writeString(wr, "stubHkUref", stubHkUref);
		writeString(wr, "srefHkIxVSection", srefHkIxVSection);
		writeString(wr, "titHkIxVSection", titHkIxVSection);
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
		writeString(wr, "stubSupRefWznmMControl", stubSupRefWznmMControl);
		writeString(wr, "srefIxVSubtype", srefIxVSubtype);
		writeString(wr, "titIxVSubtype", titIxVSubtype);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQConList
 ******************************************************************************/

ListWznmQConList::ListWznmQConList() {
};

ListWznmQConList::ListWznmQConList(
			const ListWznmQConList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQConList(*(src.nodes[i]));
};

ListWznmQConList::~ListWznmQConList() {
	clear();
};

void ListWznmQConList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQConList::size() const {
	return(nodes.size());
};

void ListWznmQConList::append(
			WznmQConList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQConList& ListWznmQConList::operator=(
			const ListWznmQConList& src
		) {
	WznmQConList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQConList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQConList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQConList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQConList
 ******************************************************************************/

TblWznmQConList::TblWznmQConList() {
};

TblWznmQConList::~TblWznmQConList() {
};

bool TblWznmQConList::loadRecBySQL(
			const string& sqlstr
			, WznmQConList** rec
		) {
	return false;
};

ubigint TblWznmQConList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQConList& rst
		) {
	return 0;
};

ubigint TblWznmQConList::insertRec(
			WznmQConList* rec
		) {
	return 0;
};

ubigint TblWznmQConList::insertNewRec(
			WznmQConList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const uint hkIxVSection
			, const string srefHkIxVSection
			, const string titHkIxVSection
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const ubigint supRefWznmMControl
			, const string stubSupRefWznmMControl
			, const uint ixVSubtype
			, const string srefIxVSubtype
			, const string titIxVSubtype
		) {
	ubigint retval = 0;
	WznmQConList* _rec = NULL;

	_rec = new WznmQConList(0, jref, jnum, ref, sref, Title, ixVBasetype, srefIxVBasetype, titIxVBasetype, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref, hkIxVSection, srefHkIxVSection, titHkIxVSection, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, supRefWznmMControl, stubSupRefWznmMControl, ixVSubtype, srefIxVSubtype, titIxVSubtype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQConList::appendNewRecToRst(
			ListWznmQConList& rst
			, WznmQConList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const uint hkIxVSection
			, const string srefHkIxVSection
			, const string titHkIxVSection
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const ubigint supRefWznmMControl
			, const string stubSupRefWznmMControl
			, const uint ixVSubtype
			, const string srefIxVSubtype
			, const string titIxVSubtype
		) {
	ubigint retval = 0;
	WznmQConList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Title, ixVBasetype, srefIxVBasetype, titIxVBasetype, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref, hkIxVSection, srefHkIxVSection, titHkIxVSection, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, supRefWznmMControl, stubSupRefWznmMControl, ixVSubtype, srefIxVSubtype, titIxVSubtype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQConList::insertRst(
			ListWznmQConList& rst
		) {
};

void TblWznmQConList::updateRec(
			WznmQConList* rec
		) {
};

void TblWznmQConList::updateRst(
			ListWznmQConList& rst
		) {
};

void TblWznmQConList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQConList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQConList::loadRecByQref(
			ubigint qref
			, WznmQConList** rec
		) {
	return false;
};

ubigint TblWznmQConList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQConList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQConList
 ******************************************************************************/

MyTblWznmQConList::MyTblWznmQConList() :
			TblWznmQConList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQConList::~MyTblWznmQConList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQConList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQConList (jref, jnum, ref, sref, Title, ixVBasetype, hkIxVTbl, hkUref, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, ixVSubtype) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQConList SET jref = ?, jnum = ?, ref = ?, sref = ?, Title = ?, ixVBasetype = ?, hkIxVTbl = ?, hkUref = ?, hkIxVSection = ?, refIxVTbl = ?, refUref = ?, supRefWznmMControl = ?, ixVSubtype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQConList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQConList WHERE jref = ?", false);
};

bool MyTblWznmQConList::loadRecBySQL(
			const string& sqlstr
			, WznmQConList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQConList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQConList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQConList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQConList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->ixVBasetype = atol((char*) dbrow[6]); else _rec->ixVBasetype = 0;
		if (dbrow[7]) _rec->hkIxVTbl = atol((char*) dbrow[7]); else _rec->hkIxVTbl = 0;
		if (dbrow[8]) _rec->hkUref = atoll((char*) dbrow[8]); else _rec->hkUref = 0;
		if (dbrow[9]) _rec->hkIxVSection = atol((char*) dbrow[9]); else _rec->hkIxVSection = 0;
		if (dbrow[10]) _rec->refIxVTbl = atol((char*) dbrow[10]); else _rec->refIxVTbl = 0;
		if (dbrow[11]) _rec->refUref = atoll((char*) dbrow[11]); else _rec->refUref = 0;
		if (dbrow[12]) _rec->supRefWznmMControl = atoll((char*) dbrow[12]); else _rec->supRefWznmMControl = 0;
		if (dbrow[13]) _rec->ixVSubtype = atol((char*) dbrow[13]); else _rec->ixVSubtype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQConList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQConList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQConList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQConList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQConList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQConList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->ixVBasetype = atol((char*) dbrow[6]); else rec->ixVBasetype = 0;
			if (dbrow[7]) rec->hkIxVTbl = atol((char*) dbrow[7]); else rec->hkIxVTbl = 0;
			if (dbrow[8]) rec->hkUref = atoll((char*) dbrow[8]); else rec->hkUref = 0;
			if (dbrow[9]) rec->hkIxVSection = atol((char*) dbrow[9]); else rec->hkIxVSection = 0;
			if (dbrow[10]) rec->refIxVTbl = atol((char*) dbrow[10]); else rec->refIxVTbl = 0;
			if (dbrow[11]) rec->refUref = atoll((char*) dbrow[11]); else rec->refUref = 0;
			if (dbrow[12]) rec->supRefWznmMControl = atoll((char*) dbrow[12]); else rec->supRefWznmMControl = 0;
			if (dbrow[13]) rec->ixVSubtype = atol((char*) dbrow[13]); else rec->ixVSubtype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQConList::insertRec(
			WznmQConList* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->hkIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->hkUref,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->hkIxVSection,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->refIxVTbl,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refUref,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->supRefWznmMControl,&(l[11]),&(n[11]),&(e[11])),
		bindUint(&rec->ixVSubtype,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQConList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQConList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQConList::insertRst(
			ListWznmQConList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQConList::updateRec(
			WznmQConList* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->hkIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->hkUref,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->hkIxVSection,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->refIxVTbl,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refUref,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->supRefWznmMControl,&(l[11]),&(n[11]),&(e[11])),
		bindUint(&rec->ixVSubtype,&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->qref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQConList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQConList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQConList::updateRst(
			ListWznmQConList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQConList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQConList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQConList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQConList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQConList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQConList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQConList::loadRecByQref(
			ubigint qref
			, WznmQConList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQConList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQConList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQConList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQConList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQConList
 ******************************************************************************/

PgTblWznmQConList::PgTblWznmQConList() :
			TblWznmQConList()
			, PgTable()
		{
};

PgTblWznmQConList::~PgTblWznmQConList() {
};

void PgTblWznmQConList::initStatements() {
	createStatement("TblWznmQConList_insertRec", "INSERT INTO TblWznmQConList (jref, jnum, ref, sref, Title, ixVBasetype, hkIxVTbl, hkUref, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, ixVSubtype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING qref", 13);
	createStatement("TblWznmQConList_updateRec", "UPDATE TblWznmQConList SET jref = $1, jnum = $2, ref = $3, sref = $4, Title = $5, ixVBasetype = $6, hkIxVTbl = $7, hkUref = $8, hkIxVSection = $9, refIxVTbl = $10, refUref = $11, supRefWznmMControl = $12, ixVSubtype = $13 WHERE qref = $14", 14);
	createStatement("TblWznmQConList_removeRecByQref", "DELETE FROM TblWznmQConList WHERE qref = $1", 1);
	createStatement("TblWznmQConList_removeRstByJref", "DELETE FROM TblWznmQConList WHERE jref = $1", 1);

	createStatement("TblWznmQConList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Title, ixVBasetype, hkIxVTbl, hkUref, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, ixVSubtype FROM TblWznmQConList WHERE qref = $1", 1);
	createStatement("TblWznmQConList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Title, ixVBasetype, hkIxVTbl, hkUref, hkIxVSection, refIxVTbl, refUref, supRefWznmMControl, ixVSubtype FROM TblWznmQConList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQConList::loadRec(
			PGresult* res
			, WznmQConList** rec
		) {
	char* ptr;

	WznmQConList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQConList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "hkixvsection"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "suprefwznmmcontrol"),
			PQfnumber(res, "ixvsubtype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->hkIxVSection = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->supRefWznmMControl = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->ixVSubtype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQConList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQConList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQConList* rec;

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
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "hkixvsection"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "suprefwznmmcontrol"),
			PQfnumber(res, "ixvsubtype")
		};

		while (numread < numrow) {
			rec = new WznmQConList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->hkIxVSection = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->supRefWznmMControl = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->ixVSubtype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQConList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQConList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQConList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQConList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQConList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQConList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQConList::loadRecBySQL(
			const string& sqlstr
			, WznmQConList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQConList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQConList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQConList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQConList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQConList::insertRec(
			WznmQConList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	uint _hkIxVSection = htonl(rec->hkIxVSection);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _supRefWznmMControl = htonl64(rec->supRefWznmMControl);
	uint _ixVSubtype = htonl(rec->ixVSubtype);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_hkIxVSection,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_supRefWznmMControl,
		(char*) &_ixVSubtype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQConList_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQConList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQConList::insertRst(
			ListWznmQConList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQConList::updateRec(
			WznmQConList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	uint _hkIxVSection = htonl(rec->hkIxVSection);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _supRefWznmMControl = htonl64(rec->supRefWznmMControl);
	uint _ixVSubtype = htonl(rec->ixVSubtype);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_hkIxVSection,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_supRefWznmMControl,
		(char*) &_ixVSubtype,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQConList_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQConList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQConList::updateRst(
			ListWznmQConList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQConList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQConList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQConList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQConList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQConList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQConList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQConList::loadRecByQref(
			ubigint qref
			, WznmQConList** rec
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

	return loadRecByStmt("TblWznmQConList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQConList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQConList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQConList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

