/**
	* \file WznmQUsrList.cpp
	* Dbs and XML wrapper for table TblWznmQUsrList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQUsrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQUsrList
 ******************************************************************************/

WznmQUsrList::WznmQUsrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWznmMPerson
			, const string stubRefWznmMPerson
			, const string sref
			, const ubigint refWznmMUsergroup
			, const string stubRefWznmMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWznmVLocale
			, const string srefIxWznmVLocale
			, const string titIxWznmVLocale
			, const uint ixWznmVUserlevel
			, const string srefIxWznmVUserlevel
			, const string titIxWznmVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->refWznmMPerson = refWznmMPerson;
	this->stubRefWznmMPerson = stubRefWznmMPerson;
	this->sref = sref;
	this->refWznmMUsergroup = refWznmMUsergroup;
	this->stubRefWznmMUsergroup = stubRefWznmMUsergroup;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->ixWznmVLocale = ixWznmVLocale;
	this->srefIxWznmVLocale = srefIxWznmVLocale;
	this->titIxWznmVLocale = titIxWznmVLocale;
	this->ixWznmVUserlevel = ixWznmVUserlevel;
	this->srefIxWznmVUserlevel = srefIxWznmVUserlevel;
	this->titIxWznmVUserlevel = titIxWznmVUserlevel;
};

void WznmQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "prs", stubRefWznmMPerson);
		writeString(wr, "srf", sref);
		writeString(wr, "usg", stubRefWznmMUsergroup);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
		writeString(wr, "lcl", srefIxWznmVLocale);
		writeString(wr, "lcl2", titIxWznmVLocale);
		writeString(wr, "ulv", srefIxWznmVUserlevel);
		writeString(wr, "ulv2", titIxWznmVUserlevel);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "stubRefWznmMPerson", stubRefWznmMPerson);
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefWznmMUsergroup", stubRefWznmMUsergroup);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
		writeString(wr, "srefIxWznmVLocale", srefIxWznmVLocale);
		writeString(wr, "titIxWznmVLocale", titIxWznmVLocale);
		writeString(wr, "srefIxWznmVUserlevel", srefIxWznmVUserlevel);
		writeString(wr, "titIxWznmVUserlevel", titIxWznmVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQUsrList
 ******************************************************************************/

ListWznmQUsrList::ListWznmQUsrList() {
};

ListWznmQUsrList::ListWznmQUsrList(
			const ListWznmQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQUsrList(*(src.nodes[i]));
};

ListWznmQUsrList::~ListWznmQUsrList() {
	clear();
};

void ListWznmQUsrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQUsrList::size() const {
	return(nodes.size());
};

void ListWznmQUsrList::append(
			WznmQUsrList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQUsrList& ListWznmQUsrList::operator=(
			const ListWznmQUsrList& src
		) {
	WznmQUsrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQUsrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQUsrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQUsrList
 ******************************************************************************/

TblWznmQUsrList::TblWznmQUsrList() {
};

TblWznmQUsrList::~TblWznmQUsrList() {
};

bool TblWznmQUsrList::loadRecBySQL(
			const string& sqlstr
			, WznmQUsrList** rec
		) {
	return false;
};

ubigint TblWznmQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQUsrList& rst
		) {
	return 0;
};

ubigint TblWznmQUsrList::insertRec(
			WznmQUsrList* rec
		) {
	return 0;
};

ubigint TblWznmQUsrList::insertNewRec(
			WznmQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWznmMPerson
			, const string stubRefWznmMPerson
			, const string sref
			, const ubigint refWznmMUsergroup
			, const string stubRefWznmMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWznmVLocale
			, const string srefIxWznmVLocale
			, const string titIxWznmVLocale
			, const uint ixWznmVUserlevel
			, const string srefIxWznmVUserlevel
			, const string titIxWznmVUserlevel
		) {
	ubigint retval = 0;
	WznmQUsrList* _rec = NULL;

	_rec = new WznmQUsrList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, refWznmMPerson, stubRefWznmMPerson, sref, refWznmMUsergroup, stubRefWznmMUsergroup, ixVState, srefIxVState, titIxVState, ixWznmVLocale, srefIxWznmVLocale, titIxWznmVLocale, ixWznmVUserlevel, srefIxWznmVUserlevel, titIxWznmVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQUsrList::appendNewRecToRst(
			ListWznmQUsrList& rst
			, WznmQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWznmMPerson
			, const string stubRefWznmMPerson
			, const string sref
			, const ubigint refWznmMUsergroup
			, const string stubRefWznmMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWznmVLocale
			, const string srefIxWznmVLocale
			, const string titIxWznmVLocale
			, const uint ixWznmVUserlevel
			, const string srefIxWznmVUserlevel
			, const string titIxWznmVUserlevel
		) {
	ubigint retval = 0;
	WznmQUsrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, refWznmMPerson, stubRefWznmMPerson, sref, refWznmMUsergroup, stubRefWznmMUsergroup, ixVState, srefIxVState, titIxVState, ixWznmVLocale, srefIxWznmVLocale, titIxWznmVLocale, ixWznmVUserlevel, srefIxWznmVUserlevel, titIxWznmVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQUsrList::insertRst(
			ListWznmQUsrList& rst
		) {
};

void TblWznmQUsrList::updateRec(
			WznmQUsrList* rec
		) {
};

void TblWznmQUsrList::updateRst(
			ListWznmQUsrList& rst
		) {
};

void TblWznmQUsrList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQUsrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQUsrList::loadRecByQref(
			ubigint qref
			, WznmQUsrList** rec
		) {
	return false;
};

ubigint TblWznmQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQUsrList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQUsrList
 ******************************************************************************/

MyTblWznmQUsrList::MyTblWznmQUsrList() :
			TblWznmQUsrList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQUsrList::~MyTblWznmQUsrList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQUsrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQUsrList (jref, jnum, ref, grp, own, refWznmMPerson, sref, refWznmMUsergroup, ixVState, ixWznmVLocale, ixWznmVUserlevel) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQUsrList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, refWznmMPerson = ?, sref = ?, refWznmMUsergroup = ?, ixVState = ?, ixWznmVLocale = ?, ixWznmVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQUsrList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQUsrList WHERE jref = ?", false);
};

bool MyTblWznmQUsrList::loadRecBySQL(
			const string& sqlstr
			, WznmQUsrList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQUsrList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQUsrList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQUsrList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQUsrList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->refWznmMPerson = atoll((char*) dbrow[6]); else _rec->refWznmMPerson = 0;
		if (dbrow[7]) _rec->sref.assign(dbrow[7], dblengths[7]); else _rec->sref = "";
		if (dbrow[8]) _rec->refWznmMUsergroup = atoll((char*) dbrow[8]); else _rec->refWznmMUsergroup = 0;
		if (dbrow[9]) _rec->ixVState = atol((char*) dbrow[9]); else _rec->ixVState = 0;
		if (dbrow[10]) _rec->ixWznmVLocale = atol((char*) dbrow[10]); else _rec->ixWznmVLocale = 0;
		if (dbrow[11]) _rec->ixWznmVUserlevel = atol((char*) dbrow[11]); else _rec->ixWznmVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQUsrList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQUsrList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQUsrList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQUsrList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQUsrList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->refWznmMPerson = atoll((char*) dbrow[6]); else rec->refWznmMPerson = 0;
			if (dbrow[7]) rec->sref.assign(dbrow[7], dblengths[7]); else rec->sref = "";
			if (dbrow[8]) rec->refWznmMUsergroup = atoll((char*) dbrow[8]); else rec->refWznmMUsergroup = 0;
			if (dbrow[9]) rec->ixVState = atol((char*) dbrow[9]); else rec->ixVState = 0;
			if (dbrow[10]) rec->ixWznmVLocale = atol((char*) dbrow[10]); else rec->ixWznmVLocale = 0;
			if (dbrow[11]) rec->ixWznmVUserlevel = atol((char*) dbrow[11]); else rec->ixWznmVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQUsrList::insertRec(
			WznmQUsrList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[6] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMPerson,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMUsergroup,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWznmVLocale,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixWznmVUserlevel,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQUsrList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQUsrList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQUsrList::insertRst(
			ListWznmQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQUsrList::updateRec(
			WznmQUsrList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[6] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMPerson,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMUsergroup,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWznmVLocale,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixWznmVUserlevel,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQUsrList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQUsrList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQUsrList::updateRst(
			ListWznmQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQUsrList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQUsrList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQUsrList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQUsrList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQUsrList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQUsrList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQUsrList::loadRecByQref(
			ubigint qref
			, WznmQUsrList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQUsrList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQUsrList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQUsrList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQUsrList
 ******************************************************************************/

PgTblWznmQUsrList::PgTblWznmQUsrList() :
			TblWznmQUsrList()
			, PgTable()
		{
};

PgTblWznmQUsrList::~PgTblWznmQUsrList() {
};

void PgTblWznmQUsrList::initStatements() {
	createStatement("TblWznmQUsrList_insertRec", "INSERT INTO TblWznmQUsrList (jref, jnum, ref, grp, own, refWznmMPerson, sref, refWznmMUsergroup, ixVState, ixWznmVLocale, ixWznmVUserlevel) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11);
	createStatement("TblWznmQUsrList_updateRec", "UPDATE TblWznmQUsrList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, refWznmMPerson = $6, sref = $7, refWznmMUsergroup = $8, ixVState = $9, ixWznmVLocale = $10, ixWznmVUserlevel = $11 WHERE qref = $12", 12);
	createStatement("TblWznmQUsrList_removeRecByQref", "DELETE FROM TblWznmQUsrList WHERE qref = $1", 1);
	createStatement("TblWznmQUsrList_removeRstByJref", "DELETE FROM TblWznmQUsrList WHERE jref = $1", 1);

	createStatement("TblWznmQUsrList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, refWznmMPerson, sref, refWznmMUsergroup, ixVState, ixWznmVLocale, ixWznmVUserlevel FROM TblWznmQUsrList WHERE qref = $1", 1);
	createStatement("TblWznmQUsrList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, refWznmMPerson, sref, refWznmMUsergroup, ixVState, ixWznmVLocale, ixWznmVUserlevel FROM TblWznmQUsrList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQUsrList::loadRec(
			PGresult* res
			, WznmQUsrList** rec
		) {
	char* ptr;

	WznmQUsrList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQUsrList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwznmmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwznmmusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwznmvlocale"),
			PQfnumber(res, "ixwznmvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixWznmVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->ixWznmVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQUsrList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQUsrList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQUsrList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwznmmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwznmmusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwznmvlocale"),
			PQfnumber(res, "ixwznmvuserlevel")
		};

		while (numread < numrow) {
			rec = new WznmQUsrList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixWznmVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->ixWznmVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQUsrList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQUsrList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQUsrList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQUsrList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQUsrList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQUsrList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQUsrList::loadRecBySQL(
			const string& sqlstr
			, WznmQUsrList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQUsrList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQUsrList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQUsrList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQUsrList::insertRec(
			WznmQUsrList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWznmMPerson = htonl64(rec->refWznmMPerson);
	ubigint _refWznmMUsergroup = htonl64(rec->refWznmMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWznmVLocale = htonl(rec->ixWznmVLocale);
	uint _ixWznmVUserlevel = htonl(rec->ixWznmVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWznmMPerson,
		rec->sref.c_str(),
		(char*) &_refWznmMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixWznmVLocale,
		(char*) &_ixWznmVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQUsrList_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQUsrList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQUsrList::insertRst(
			ListWznmQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQUsrList::updateRec(
			WznmQUsrList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWznmMPerson = htonl64(rec->refWznmMPerson);
	ubigint _refWznmMUsergroup = htonl64(rec->refWznmMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWznmVLocale = htonl(rec->ixWznmVLocale);
	uint _ixWznmVUserlevel = htonl(rec->ixWznmVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWznmMPerson,
		rec->sref.c_str(),
		(char*) &_refWznmMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixWznmVLocale,
		(char*) &_ixWznmVUserlevel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQUsrList_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQUsrList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQUsrList::updateRst(
			ListWznmQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQUsrList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQUsrList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQUsrList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQUsrList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQUsrList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQUsrList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQUsrList::loadRecByQref(
			ubigint qref
			, WznmQUsrList** rec
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

	return loadRecByStmt("TblWznmQUsrList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQUsrList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQUsrList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

