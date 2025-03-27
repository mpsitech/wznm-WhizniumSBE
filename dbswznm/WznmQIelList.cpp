/**
	* \file WznmQIelList.cpp
	* Dbs and XML wrapper for table TblWznmQIelList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQIelList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQIelList
 ******************************************************************************/

WznmQIelList::WznmQIelList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Short
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint imeRefWznmMImpexp
			, const string stubImeRefWznmMImpexp
			, const ubigint refWznmMTablecol
			, const string stubRefWznmMTablecol
			, const uint ixVConvtype
			, const string srefIxVConvtype
			, const string titIxVConvtype
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, sref(sref)
			, Short(Short)
			, ixVBasetype(ixVBasetype)
			, srefIxVBasetype(srefIxVBasetype)
			, titIxVBasetype(titIxVBasetype)
			, imeRefWznmMImpexp(imeRefWznmMImpexp)
			, stubImeRefWznmMImpexp(stubImeRefWznmMImpexp)
			, refWznmMTablecol(refWznmMTablecol)
			, stubRefWznmMTablecol(stubRefWznmMTablecol)
			, ixVConvtype(ixVConvtype)
			, srefIxVConvtype(srefIxVConvtype)
			, titIxVConvtype(titIxVConvtype)
		{
};

void WznmQIelList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["srf"] = sref;
		me["sho"] = Short;
		me["typ"] = srefIxVBasetype;
		me["typ2"] = titIxVBasetype;
		me["ime"] = stubImeRefWznmMImpexp;
		me["tco"] = stubRefWznmMTablecol;
		me["cty"] = srefIxVConvtype;
		me["cty2"] = titIxVConvtype;
	} else {
		me["sref"] = sref;
		me["Short"] = Short;
		me["srefIxVBasetype"] = srefIxVBasetype;
		me["titIxVBasetype"] = titIxVBasetype;
		me["stubImeRefWznmMImpexp"] = stubImeRefWznmMImpexp;
		me["stubRefWznmMTablecol"] = stubRefWznmMTablecol;
		me["srefIxVConvtype"] = srefIxVConvtype;
		me["titIxVConvtype"] = titIxVConvtype;
	};
};

void WznmQIelList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQIelList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "sho", Short);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "ime", stubImeRefWznmMImpexp);
		writeString(wr, "tco", stubRefWznmMTablecol);
		writeString(wr, "cty", srefIxVConvtype);
		writeString(wr, "cty2", titIxVConvtype);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Short", Short);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubImeRefWznmMImpexp", stubImeRefWznmMImpexp);
		writeString(wr, "stubRefWznmMTablecol", stubRefWznmMTablecol);
		writeString(wr, "srefIxVConvtype", srefIxVConvtype);
		writeString(wr, "titIxVConvtype", titIxVConvtype);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQIelList
 ******************************************************************************/

ListWznmQIelList::ListWznmQIelList() {
};

ListWznmQIelList::ListWznmQIelList(
			const ListWznmQIelList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQIelList(*(src.nodes[i]));
};

ListWznmQIelList::~ListWznmQIelList() {
	clear();
};

void ListWznmQIelList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQIelList::size() const {
	return(nodes.size());
};

void ListWznmQIelList::append(
			WznmQIelList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQIelList& ListWznmQIelList::operator=(
			const ListWznmQIelList& src
		) {
	WznmQIelList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQIelList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQIelList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQIelList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQIelList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQIelList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQIelList
 ******************************************************************************/

TblWznmQIelList::TblWznmQIelList() {
};

TblWznmQIelList::~TblWznmQIelList() {
};

bool TblWznmQIelList::loadRecBySQL(
			const string& sqlstr
			, WznmQIelList** rec
		) {
	return false;
};

ubigint TblWznmQIelList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQIelList& rst
		) {
	return 0;
};

ubigint TblWznmQIelList::insertRec(
			WznmQIelList* rec
		) {
	return 0;
};

ubigint TblWznmQIelList::insertNewRec(
			WznmQIelList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Short
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint imeRefWznmMImpexp
			, const string stubImeRefWznmMImpexp
			, const ubigint refWznmMTablecol
			, const string stubRefWznmMTablecol
			, const uint ixVConvtype
			, const string srefIxVConvtype
			, const string titIxVConvtype
		) {
	ubigint retval = 0;
	WznmQIelList* _rec = NULL;

	_rec = new WznmQIelList(0, jref, jnum, ref, sref, Short, ixVBasetype, srefIxVBasetype, titIxVBasetype, imeRefWznmMImpexp, stubImeRefWznmMImpexp, refWznmMTablecol, stubRefWznmMTablecol, ixVConvtype, srefIxVConvtype, titIxVConvtype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQIelList::appendNewRecToRst(
			ListWznmQIelList& rst
			, WznmQIelList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Short
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint imeRefWznmMImpexp
			, const string stubImeRefWznmMImpexp
			, const ubigint refWznmMTablecol
			, const string stubRefWznmMTablecol
			, const uint ixVConvtype
			, const string srefIxVConvtype
			, const string titIxVConvtype
		) {
	ubigint retval = 0;
	WznmQIelList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Short, ixVBasetype, srefIxVBasetype, titIxVBasetype, imeRefWznmMImpexp, stubImeRefWznmMImpexp, refWznmMTablecol, stubRefWznmMTablecol, ixVConvtype, srefIxVConvtype, titIxVConvtype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQIelList::insertRst(
			ListWznmQIelList& rst
		) {
};

void TblWznmQIelList::updateRec(
			WznmQIelList* rec
		) {
};

void TblWznmQIelList::updateRst(
			ListWznmQIelList& rst
		) {
};

void TblWznmQIelList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQIelList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQIelList::loadRecByQref(
			ubigint qref
			, WznmQIelList** rec
		) {
	return false;
};

ubigint TblWznmQIelList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQIelList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQIelList
 ******************************************************************************/

MyTblWznmQIelList::MyTblWznmQIelList() :
			TblWznmQIelList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQIelList::~MyTblWznmQIelList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQIelList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQIelList (jref, jnum, ref, sref, Short, ixVBasetype, imeRefWznmMImpexp, refWznmMTablecol, ixVConvtype) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQIelList SET jref = ?, jnum = ?, ref = ?, sref = ?, Short = ?, ixVBasetype = ?, imeRefWznmMImpexp = ?, refWznmMTablecol = ?, ixVConvtype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQIelList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQIelList WHERE jref = ?", false);
};

bool MyTblWznmQIelList::loadRecBySQL(
			const string& sqlstr
			, WznmQIelList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQIelList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQIelList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQIelList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQIelList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Short.assign(dbrow[5], dblengths[5]); else _rec->Short = "";
		if (dbrow[6]) _rec->ixVBasetype = atol((char*) dbrow[6]); else _rec->ixVBasetype = 0;
		if (dbrow[7]) _rec->imeRefWznmMImpexp = atoll((char*) dbrow[7]); else _rec->imeRefWznmMImpexp = 0;
		if (dbrow[8]) _rec->refWznmMTablecol = atoll((char*) dbrow[8]); else _rec->refWznmMTablecol = 0;
		if (dbrow[9]) _rec->ixVConvtype = atol((char*) dbrow[9]); else _rec->ixVConvtype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQIelList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQIelList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQIelList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQIelList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQIelList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQIelList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Short.assign(dbrow[5], dblengths[5]); else rec->Short = "";
			if (dbrow[6]) rec->ixVBasetype = atol((char*) dbrow[6]); else rec->ixVBasetype = 0;
			if (dbrow[7]) rec->imeRefWznmMImpexp = atoll((char*) dbrow[7]); else rec->imeRefWznmMImpexp = 0;
			if (dbrow[8]) rec->refWznmMTablecol = atoll((char*) dbrow[8]); else rec->refWznmMTablecol = 0;
			if (dbrow[9]) rec->ixVConvtype = atol((char*) dbrow[9]); else rec->ixVConvtype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQIelList::insertRec(
			WznmQIelList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[4] = rec->Short.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Short.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->imeRefWznmMImpexp,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMTablecol,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVConvtype,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQIelList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQIelList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQIelList::insertRst(
			ListWznmQIelList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQIelList::updateRec(
			WznmQIelList* rec
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
		bindUbigint(&rec->imeRefWznmMImpexp,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMTablecol,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVConvtype,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQIelList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQIelList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQIelList::updateRst(
			ListWznmQIelList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQIelList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQIelList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQIelList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQIelList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQIelList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQIelList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQIelList::loadRecByQref(
			ubigint qref
			, WznmQIelList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQIelList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQIelList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQIelList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQIelList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQIelList
 ******************************************************************************/

PgTblWznmQIelList::PgTblWznmQIelList() :
			TblWznmQIelList()
			, PgTable()
		{
};

PgTblWznmQIelList::~PgTblWznmQIelList() {
};

void PgTblWznmQIelList::initStatements() {
	createStatement("TblWznmQIelList_insertRec", "INSERT INTO TblWznmQIelList (jref, jnum, ref, sref, Short, ixVBasetype, imeRefWznmMImpexp, refWznmMTablecol, ixVConvtype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9);
	createStatement("TblWznmQIelList_updateRec", "UPDATE TblWznmQIelList SET jref = $1, jnum = $2, ref = $3, sref = $4, Short = $5, ixVBasetype = $6, imeRefWznmMImpexp = $7, refWznmMTablecol = $8, ixVConvtype = $9 WHERE qref = $10", 10);
	createStatement("TblWznmQIelList_removeRecByQref", "DELETE FROM TblWznmQIelList WHERE qref = $1", 1);
	createStatement("TblWznmQIelList_removeRstByJref", "DELETE FROM TblWznmQIelList WHERE jref = $1", 1);

	createStatement("TblWznmQIelList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Short, ixVBasetype, imeRefWznmMImpexp, refWznmMTablecol, ixVConvtype FROM TblWznmQIelList WHERE qref = $1", 1);
	createStatement("TblWznmQIelList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Short, ixVBasetype, imeRefWznmMImpexp, refWznmMTablecol, ixVConvtype FROM TblWznmQIelList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQIelList::loadRec(
			PGresult* res
			, WznmQIelList** rec
		) {
	char* ptr;

	WznmQIelList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQIelList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "imerefwznmmimpexp"),
			PQfnumber(res, "refwznmmtablecol"),
			PQfnumber(res, "ixvconvtype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->imeRefWznmMImpexp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMTablecol = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVConvtype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQIelList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQIelList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQIelList* rec;

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
			PQfnumber(res, "imerefwznmmimpexp"),
			PQfnumber(res, "refwznmmtablecol"),
			PQfnumber(res, "ixvconvtype")
		};

		while (numread < numrow) {
			rec = new WznmQIelList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->imeRefWznmMImpexp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMTablecol = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVConvtype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQIelList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQIelList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQIelList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQIelList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQIelList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQIelList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQIelList::loadRecBySQL(
			const string& sqlstr
			, WznmQIelList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQIelList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQIelList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQIelList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQIelList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQIelList::insertRec(
			WznmQIelList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _imeRefWznmMImpexp = htonl64(rec->imeRefWznmMImpexp);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	uint _ixVConvtype = htonl(rec->ixVConvtype);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_imeRefWznmMImpexp,
		(char*) &_refWznmMTablecol,
		(char*) &_ixVConvtype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQIelList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQIelList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQIelList::insertRst(
			ListWznmQIelList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQIelList::updateRec(
			WznmQIelList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _imeRefWznmMImpexp = htonl64(rec->imeRefWznmMImpexp);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	uint _ixVConvtype = htonl(rec->ixVConvtype);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_imeRefWznmMImpexp,
		(char*) &_refWznmMTablecol,
		(char*) &_ixVConvtype,
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
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQIelList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQIelList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQIelList::updateRst(
			ListWznmQIelList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQIelList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQIelList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQIelList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQIelList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQIelList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQIelList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQIelList::loadRecByQref(
			ubigint qref
			, WznmQIelList** rec
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

	return loadRecByStmt("TblWznmQIelList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQIelList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQIelList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQIelList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
