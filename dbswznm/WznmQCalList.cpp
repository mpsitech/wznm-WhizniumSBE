/**
	* \file WznmQCalList.cpp
	* Dbs and XML wrapper for table TblWznmQCalList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQCalList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQCalList
 ******************************************************************************/

WznmQCalList::WznmQCalList(
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
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const uint invIxWznmWArgtype
			, const string srefsInvIxWznmWArgtype
			, const string titsInvIxWznmWArgtype
			, const uint retIxWznmWArgtype
			, const string srefsRetIxWznmWArgtype
			, const string titsRetIxWznmWArgtype
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, sref(sref)
			, ixVBasetype(ixVBasetype)
			, srefIxVBasetype(srefIxVBasetype)
			, titIxVBasetype(titIxVBasetype)
			, refWznmMVersion(refWznmMVersion)
			, stubRefWznmMVersion(stubRefWznmMVersion)
			, refIxVTbl(refIxVTbl)
			, srefRefIxVTbl(srefRefIxVTbl)
			, titRefIxVTbl(titRefIxVTbl)
			, refUref(refUref)
			, stubRefUref(stubRefUref)
			, invIxWznmWArgtype(invIxWznmWArgtype)
			, srefsInvIxWznmWArgtype(srefsInvIxWznmWArgtype)
			, titsInvIxWznmWArgtype(titsInvIxWznmWArgtype)
			, retIxWznmWArgtype(retIxWznmWArgtype)
			, srefsRetIxWznmWArgtype(srefsRetIxWznmWArgtype)
			, titsRetIxWznmWArgtype(titsRetIxWznmWArgtype)
		{
};

void WznmQCalList::writeJSON(
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
		me["ret"] = srefRefIxVTbl;
		me["ret2"] = titRefIxVTbl;
		me["reu"] = stubRefUref;
		me["iat"] = srefsInvIxWznmWArgtype;
		me["iat2"] = titsInvIxWznmWArgtype;
		me["rat"] = srefsRetIxWznmWArgtype;
		me["rat2"] = titsRetIxWznmWArgtype;
	} else {
		me["sref"] = sref;
		me["srefIxVBasetype"] = srefIxVBasetype;
		me["titIxVBasetype"] = titIxVBasetype;
		me["stubRefWznmMVersion"] = stubRefWznmMVersion;
		me["srefRefIxVTbl"] = srefRefIxVTbl;
		me["titRefIxVTbl"] = titRefIxVTbl;
		me["stubRefUref"] = stubRefUref;
		me["srefsInvIxWznmWArgtype"] = srefsInvIxWznmWArgtype;
		me["titsInvIxWznmWArgtype"] = titsInvIxWznmWArgtype;
		me["srefsRetIxWznmWArgtype"] = srefsRetIxWznmWArgtype;
		me["titsRetIxWznmWArgtype"] = titsRetIxWznmWArgtype;
	};
};

void WznmQCalList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQCalList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "ver", stubRefWznmMVersion);
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
		writeString(wr, "iat", srefsInvIxWznmWArgtype);
		writeString(wr, "iat2", titsInvIxWznmWArgtype);
		writeString(wr, "rat", srefsRetIxWznmWArgtype);
		writeString(wr, "rat2", titsRetIxWznmWArgtype);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubRefWznmMVersion", stubRefWznmMVersion);
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
		writeString(wr, "srefsInvIxWznmWArgtype", srefsInvIxWznmWArgtype);
		writeString(wr, "titsInvIxWznmWArgtype", titsInvIxWznmWArgtype);
		writeString(wr, "srefsRetIxWznmWArgtype", srefsRetIxWznmWArgtype);
		writeString(wr, "titsRetIxWznmWArgtype", titsRetIxWznmWArgtype);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQCalList
 ******************************************************************************/

ListWznmQCalList::ListWznmQCalList() {
};

ListWznmQCalList::ListWznmQCalList(
			const ListWznmQCalList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQCalList(*(src.nodes[i]));
};

ListWznmQCalList::~ListWznmQCalList() {
	clear();
};

void ListWznmQCalList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQCalList::size() const {
	return(nodes.size());
};

void ListWznmQCalList::append(
			WznmQCalList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQCalList& ListWznmQCalList::operator=(
			const ListWznmQCalList& src
		) {
	WznmQCalList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQCalList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQCalList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQCalList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQCalList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQCalList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQCalList
 ******************************************************************************/

TblWznmQCalList::TblWznmQCalList() {
};

TblWznmQCalList::~TblWznmQCalList() {
};

bool TblWznmQCalList::loadRecBySQL(
			const string& sqlstr
			, WznmQCalList** rec
		) {
	return false;
};

ubigint TblWznmQCalList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCalList& rst
		) {
	return 0;
};

ubigint TblWznmQCalList::insertRec(
			WznmQCalList* rec
		) {
	return 0;
};

ubigint TblWznmQCalList::insertNewRec(
			WznmQCalList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const uint invIxWznmWArgtype
			, const string srefsInvIxWznmWArgtype
			, const string titsInvIxWznmWArgtype
			, const uint retIxWznmWArgtype
			, const string srefsRetIxWznmWArgtype
			, const string titsRetIxWznmWArgtype
		) {
	ubigint retval = 0;
	WznmQCalList* _rec = NULL;

	_rec = new WznmQCalList(0, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, refWznmMVersion, stubRefWznmMVersion, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, invIxWznmWArgtype, srefsInvIxWznmWArgtype, titsInvIxWznmWArgtype, retIxWznmWArgtype, srefsRetIxWznmWArgtype, titsRetIxWznmWArgtype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQCalList::appendNewRecToRst(
			ListWznmQCalList& rst
			, WznmQCalList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWznmMVersion
			, const string stubRefWznmMVersion
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const uint invIxWznmWArgtype
			, const string srefsInvIxWznmWArgtype
			, const string titsInvIxWznmWArgtype
			, const uint retIxWznmWArgtype
			, const string srefsRetIxWznmWArgtype
			, const string titsRetIxWznmWArgtype
		) {
	ubigint retval = 0;
	WznmQCalList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, refWznmMVersion, stubRefWznmMVersion, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, invIxWznmWArgtype, srefsInvIxWznmWArgtype, titsInvIxWznmWArgtype, retIxWznmWArgtype, srefsRetIxWznmWArgtype, titsRetIxWznmWArgtype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQCalList::insertRst(
			ListWznmQCalList& rst
		) {
};

void TblWznmQCalList::updateRec(
			WznmQCalList* rec
		) {
};

void TblWznmQCalList::updateRst(
			ListWznmQCalList& rst
		) {
};

void TblWznmQCalList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQCalList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQCalList::loadRecByQref(
			ubigint qref
			, WznmQCalList** rec
		) {
	return false;
};

ubigint TblWznmQCalList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCalList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQCalList
 ******************************************************************************/

MyTblWznmQCalList::MyTblWznmQCalList() :
			TblWznmQCalList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQCalList::~MyTblWznmQCalList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQCalList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQCalList (jref, jnum, ref, sref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, invIxWznmWArgtype, retIxWznmWArgtype) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQCalList SET jref = ?, jnum = ?, ref = ?, sref = ?, ixVBasetype = ?, refWznmMVersion = ?, refIxVTbl = ?, refUref = ?, invIxWznmWArgtype = ?, retIxWznmWArgtype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQCalList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQCalList WHERE jref = ?", false);
};

bool MyTblWznmQCalList::loadRecBySQL(
			const string& sqlstr
			, WznmQCalList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQCalList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQCalList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQCalList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQCalList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixVBasetype = atol((char*) dbrow[5]); else _rec->ixVBasetype = 0;
		if (dbrow[6]) _rec->refWznmMVersion = atoll((char*) dbrow[6]); else _rec->refWznmMVersion = 0;
		if (dbrow[7]) _rec->refIxVTbl = atol((char*) dbrow[7]); else _rec->refIxVTbl = 0;
		if (dbrow[8]) _rec->refUref = atoll((char*) dbrow[8]); else _rec->refUref = 0;
		if (dbrow[9]) _rec->invIxWznmWArgtype = atol((char*) dbrow[9]); else _rec->invIxWznmWArgtype = 0;
		if (dbrow[10]) _rec->retIxWznmWArgtype = atol((char*) dbrow[10]); else _rec->retIxWznmWArgtype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQCalList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCalList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQCalList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQCalList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQCalList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQCalList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixVBasetype = atol((char*) dbrow[5]); else rec->ixVBasetype = 0;
			if (dbrow[6]) rec->refWznmMVersion = atoll((char*) dbrow[6]); else rec->refWznmMVersion = 0;
			if (dbrow[7]) rec->refIxVTbl = atol((char*) dbrow[7]); else rec->refIxVTbl = 0;
			if (dbrow[8]) rec->refUref = atoll((char*) dbrow[8]); else rec->refUref = 0;
			if (dbrow[9]) rec->invIxWznmWArgtype = atol((char*) dbrow[9]); else rec->invIxWznmWArgtype = 0;
			if (dbrow[10]) rec->retIxWznmWArgtype = atol((char*) dbrow[10]); else rec->retIxWznmWArgtype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQCalList::insertRec(
			WznmQCalList* rec
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
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->invIxWznmWArgtype,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->retIxWznmWArgtype,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQCalList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQCalList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQCalList::insertRst(
			ListWznmQCalList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQCalList::updateRec(
			WznmQCalList* rec
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
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->invIxWznmWArgtype,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->retIxWznmWArgtype,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQCalList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQCalList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQCalList::updateRst(
			ListWznmQCalList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQCalList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQCalList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQCalList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQCalList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQCalList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQCalList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQCalList::loadRecByQref(
			ubigint qref
			, WznmQCalList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQCalList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQCalList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCalList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQCalList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQCalList
 ******************************************************************************/

PgTblWznmQCalList::PgTblWznmQCalList() :
			TblWznmQCalList()
			, PgTable()
		{
};

PgTblWznmQCalList::~PgTblWznmQCalList() {
};

void PgTblWznmQCalList::initStatements() {
	createStatement("TblWznmQCalList_insertRec", "INSERT INTO TblWznmQCalList (jref, jnum, ref, sref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, invIxWznmWArgtype, retIxWznmWArgtype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblWznmQCalList_updateRec", "UPDATE TblWznmQCalList SET jref = $1, jnum = $2, ref = $3, sref = $4, ixVBasetype = $5, refWznmMVersion = $6, refIxVTbl = $7, refUref = $8, invIxWznmWArgtype = $9, retIxWznmWArgtype = $10 WHERE qref = $11", 11);
	createStatement("TblWznmQCalList_removeRecByQref", "DELETE FROM TblWznmQCalList WHERE qref = $1", 1);
	createStatement("TblWznmQCalList_removeRstByJref", "DELETE FROM TblWznmQCalList WHERE jref = $1", 1);

	createStatement("TblWznmQCalList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, invIxWznmWArgtype, retIxWznmWArgtype FROM TblWznmQCalList WHERE qref = $1", 1);
	createStatement("TblWznmQCalList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, invIxWznmWArgtype, retIxWznmWArgtype FROM TblWznmQCalList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQCalList::loadRec(
			PGresult* res
			, WznmQCalList** rec
		) {
	char* ptr;

	WznmQCalList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQCalList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "invixwznmwargtype"),
			PQfnumber(res, "retixwznmwargtype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->invIxWznmWArgtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->retIxWznmWArgtype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQCalList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQCalList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQCalList* rec;

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
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "invixwznmwargtype"),
			PQfnumber(res, "retixwznmwargtype")
		};

		while (numread < numrow) {
			rec = new WznmQCalList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->invIxWznmWArgtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->retIxWznmWArgtype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQCalList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQCalList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCalList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQCalList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQCalList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCalList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQCalList::loadRecBySQL(
			const string& sqlstr
			, WznmQCalList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQCalList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQCalList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQCalList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQCalList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQCalList::insertRec(
			WznmQCalList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _invIxWznmWArgtype = htonl(rec->invIxWznmWArgtype);
	uint _retIxWznmWArgtype = htonl(rec->retIxWznmWArgtype);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_invIxWznmWArgtype,
		(char*) &_retIxWznmWArgtype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQCalList_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQCalList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQCalList::insertRst(
			ListWznmQCalList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQCalList::updateRec(
			WznmQCalList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _invIxWznmWArgtype = htonl(rec->invIxWznmWArgtype);
	uint _retIxWznmWArgtype = htonl(rec->retIxWznmWArgtype);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_invIxWznmWArgtype,
		(char*) &_retIxWznmWArgtype,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQCalList_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCalList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQCalList::updateRst(
			ListWznmQCalList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQCalList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQCalList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCalList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQCalList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQCalList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQCalList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQCalList::loadRecByQref(
			ubigint qref
			, WznmQCalList** rec
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

	return loadRecByStmt("TblWznmQCalList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQCalList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQCalList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQCalList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
