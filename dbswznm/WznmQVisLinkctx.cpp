/**
	* \file WznmQVisLinkctx.cpp
	* Dbs and XML wrapper for table TblWznmQVisLinkctx (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQVisLinkctx.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVisLinkctx
 ******************************************************************************/

WznmQVisLinkctx::WznmQVisLinkctx(
			const ubigint qref
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint tref
			, const ubigint ref
			, const ubigint orgRefWznmMBox
			, const ubigint dstRefWznmMBox
			, const utinyint orgClk
			, const utinyint dstClk
			, const utinyint Weight
			, const int jnumBoxOrg
			, const int jnumBoxDst
			, const string Title
			, const string Content1
			, const string Content2
		) :
			qref(qref)
			, qwr(qwr)
			, jref(jref)
			, jnum(jnum)
			, tref(tref)
			, ref(ref)
			, orgRefWznmMBox(orgRefWznmMBox)
			, dstRefWznmMBox(dstRefWznmMBox)
			, orgClk(orgClk)
			, dstClk(dstClk)
			, Weight(Weight)
			, jnumBoxOrg(jnumBoxOrg)
			, jnumBoxDst(jnumBoxDst)
			, Title(Title)
			, Content1(Content1)
			, Content2(Content2)
		{
};

void WznmQVisLinkctx::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["ocl"] = orgClk;
		me["dcl"] = dstClk;
		me["wgt"] = Weight;
		me["jnumBoxOrg"] = jnumBoxOrg;
		me["jnumBoxDst"] = jnumBoxDst;
		me["tit"] = Title;
		me["cnt1"] = Content1;
		me["cnt2"] = Content2;
	} else {
		me["orgClk"] = orgClk;
		me["dstClk"] = dstClk;
		me["Weight"] = Weight;
		me["jnumBoxOrg"] = jnumBoxOrg;
		me["jnumBoxDst"] = jnumBoxDst;
		me["Title"] = Title;
		me["Content1"] = Content1;
		me["Content2"] = Content2;
	};
};

void WznmQVisLinkctx::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQVisLinkctx";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeUint(wr, "ocl", orgClk);
		writeUint(wr, "dcl", dstClk);
		writeUint(wr, "wgt", Weight);
		writeInt(wr, "jnumBoxOrg", jnumBoxOrg);
		writeInt(wr, "jnumBoxDst", jnumBoxDst);
		writeString(wr, "tit", Title);
		writeString(wr, "cnt1", Content1);
		writeString(wr, "cnt2", Content2);
	} else {
		writeUint(wr, "orgClk", orgClk);
		writeUint(wr, "dstClk", dstClk);
		writeUint(wr, "Weight", Weight);
		writeInt(wr, "jnumBoxOrg", jnumBoxOrg);
		writeInt(wr, "jnumBoxDst", jnumBoxDst);
		writeString(wr, "Title", Title);
		writeString(wr, "Content1", Content1);
		writeString(wr, "Content2", Content2);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQVisLinkctx
 ******************************************************************************/

ListWznmQVisLinkctx::ListWznmQVisLinkctx() {
};

ListWznmQVisLinkctx::ListWznmQVisLinkctx(
			const ListWznmQVisLinkctx& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVisLinkctx(*(src.nodes[i]));
};

ListWznmQVisLinkctx::~ListWznmQVisLinkctx() {
	clear();
};

void ListWznmQVisLinkctx::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQVisLinkctx::size() const {
	return(nodes.size());
};

void ListWznmQVisLinkctx::append(
			WznmQVisLinkctx* rec
		) {
	nodes.push_back(rec);
};

ListWznmQVisLinkctx& ListWznmQVisLinkctx::operator=(
			const ListWznmQVisLinkctx& src
		) {
	WznmQVisLinkctx* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQVisLinkctx(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQVisLinkctx::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQVisLinkctx";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]->qwr) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQVisLinkctx::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQVisLinkctx";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]->qwr) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQVisLinkctx
 ******************************************************************************/

TblWznmQVisLinkctx::TblWznmQVisLinkctx() {
};

TblWznmQVisLinkctx::~TblWznmQVisLinkctx() {
};

bool TblWznmQVisLinkctx::loadRecBySQL(
			const string& sqlstr
			, WznmQVisLinkctx** rec
		) {
	return false;
};

ubigint TblWznmQVisLinkctx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVisLinkctx& rst
		) {
	return 0;
};

ubigint TblWznmQVisLinkctx::insertRec(
			WznmQVisLinkctx* rec
		) {
	return 0;
};

ubigint TblWznmQVisLinkctx::insertNewRec(
			WznmQVisLinkctx** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint tref
			, const ubigint ref
			, const ubigint orgRefWznmMBox
			, const ubigint dstRefWznmMBox
			, const utinyint orgClk
			, const utinyint dstClk
			, const utinyint Weight
			, const int jnumBoxOrg
			, const int jnumBoxDst
			, const string Title
			, const string Content1
			, const string Content2
		) {
	ubigint retval = 0;
	WznmQVisLinkctx* _rec = NULL;

	_rec = new WznmQVisLinkctx(0, qwr, jref, jnum, tref, ref, orgRefWznmMBox, dstRefWznmMBox, orgClk, dstClk, Weight, jnumBoxOrg, jnumBoxDst, Title, Content1, Content2);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQVisLinkctx::appendNewRecToRst(
			ListWznmQVisLinkctx& rst
			, WznmQVisLinkctx** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint tref
			, const ubigint ref
			, const ubigint orgRefWznmMBox
			, const ubigint dstRefWznmMBox
			, const utinyint orgClk
			, const utinyint dstClk
			, const utinyint Weight
			, const int jnumBoxOrg
			, const int jnumBoxDst
			, const string Title
			, const string Content1
			, const string Content2
		) {
	ubigint retval = 0;
	WznmQVisLinkctx* _rec = NULL;

	retval = insertNewRec(&_rec, qwr, jref, jnum, tref, ref, orgRefWznmMBox, dstRefWznmMBox, orgClk, dstClk, Weight, jnumBoxOrg, jnumBoxDst, Title, Content1, Content2);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQVisLinkctx::insertRst(
			ListWznmQVisLinkctx& rst
		) {
};

void TblWznmQVisLinkctx::updateRec(
			WznmQVisLinkctx* rec
		) {
};

void TblWznmQVisLinkctx::updateRst(
			ListWznmQVisLinkctx& rst
		) {
};

void TblWznmQVisLinkctx::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQVisLinkctx::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQVisLinkctx::loadRecByQref(
			ubigint qref
			, WznmQVisLinkctx** rec
		) {
	return false;
};

ubigint TblWznmQVisLinkctx::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVisLinkctx& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQVisLinkctx
 ******************************************************************************/

MyTblWznmQVisLinkctx::MyTblWznmQVisLinkctx() :
			TblWznmQVisLinkctx()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQVisLinkctx::~MyTblWznmQVisLinkctx() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQVisLinkctx::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQVisLinkctx (qwr, jref, jnum, tref, ref, orgRefWznmMBox, dstRefWznmMBox, orgClk, dstClk, Weight) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQVisLinkctx SET qwr = ?, jref = ?, jnum = ?, tref = ?, ref = ?, orgRefWznmMBox = ?, dstRefWznmMBox = ?, orgClk = ?, dstClk = ?, Weight = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQVisLinkctx WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQVisLinkctx WHERE jref = ?", false);
};

bool MyTblWznmQVisLinkctx::loadRecBySQL(
			const string& sqlstr
			, WznmQVisLinkctx** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQVisLinkctx* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVisLinkctx::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVisLinkctx::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQVisLinkctx();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->qwr = (atoi((char*) dbrow[1]) != 0); else _rec->qwr = false;
		if (dbrow[2]) _rec->jref = atoll((char*) dbrow[2]); else _rec->jref = 0;
		if (dbrow[3]) _rec->jnum = atol((char*) dbrow[3]); else _rec->jnum = 0;
		if (dbrow[4]) _rec->tref = atoll((char*) dbrow[4]); else _rec->tref = 0;
		if (dbrow[5]) _rec->ref = atoll((char*) dbrow[5]); else _rec->ref = 0;
		if (dbrow[6]) _rec->orgRefWznmMBox = atoll((char*) dbrow[6]); else _rec->orgRefWznmMBox = 0;
		if (dbrow[7]) _rec->dstRefWznmMBox = atoll((char*) dbrow[7]); else _rec->dstRefWznmMBox = 0;
		if (dbrow[8]) _rec->orgClk = atoi((char*) dbrow[8]); else _rec->orgClk = 0;
		if (dbrow[9]) _rec->dstClk = atoi((char*) dbrow[9]); else _rec->dstClk = 0;
		if (dbrow[10]) _rec->Weight = atoi((char*) dbrow[10]); else _rec->Weight = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQVisLinkctx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVisLinkctx& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQVisLinkctx* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVisLinkctx::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVisLinkctx::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQVisLinkctx();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->qwr = (atoi((char*) dbrow[1]) != 0); else rec->qwr = false;
			if (dbrow[2]) rec->jref = atoll((char*) dbrow[2]); else rec->jref = 0;
			if (dbrow[3]) rec->jnum = atol((char*) dbrow[3]); else rec->jnum = 0;
			if (dbrow[4]) rec->tref = atoll((char*) dbrow[4]); else rec->tref = 0;
			if (dbrow[5]) rec->ref = atoll((char*) dbrow[5]); else rec->ref = 0;
			if (dbrow[6]) rec->orgRefWznmMBox = atoll((char*) dbrow[6]); else rec->orgRefWznmMBox = 0;
			if (dbrow[7]) rec->dstRefWznmMBox = atoll((char*) dbrow[7]); else rec->dstRefWznmMBox = 0;
			if (dbrow[8]) rec->orgClk = atoi((char*) dbrow[8]); else rec->orgClk = 0;
			if (dbrow[9]) rec->dstClk = atoi((char*) dbrow[9]); else rec->dstClk = 0;
			if (dbrow[10]) rec->Weight = atoi((char*) dbrow[10]); else rec->Weight = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQVisLinkctx::insertRec(
			WznmQVisLinkctx* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->tref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->orgRefWznmMBox,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->dstRefWznmMBox,&(l[6]),&(n[6]),&(e[6])),
		bindUtinyint(&rec->orgClk,&(l[7]),&(n[7]),&(e[7])),
		bindUtinyint(&rec->dstClk,&(l[8]),&(n[8]),&(e[8])),
		bindUtinyint(&rec->Weight,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQVisLinkctx::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQVisLinkctx::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQVisLinkctx::insertRst(
			ListWznmQVisLinkctx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQVisLinkctx::updateRec(
			WznmQVisLinkctx* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->tref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->orgRefWznmMBox,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->dstRefWznmMBox,&(l[6]),&(n[6]),&(e[6])),
		bindUtinyint(&rec->orgClk,&(l[7]),&(n[7]),&(e[7])),
		bindUtinyint(&rec->dstClk,&(l[8]),&(n[8]),&(e[8])),
		bindUtinyint(&rec->Weight,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQVisLinkctx::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQVisLinkctx::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVisLinkctx::updateRst(
			ListWznmQVisLinkctx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQVisLinkctx::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQVisLinkctx::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQVisLinkctx::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVisLinkctx::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQVisLinkctx::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQVisLinkctx::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQVisLinkctx::loadRecByQref(
			ubigint qref
			, WznmQVisLinkctx** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQVisLinkctx WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQVisLinkctx::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVisLinkctx& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQVisLinkctx WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQVisLinkctx
 ******************************************************************************/

PgTblWznmQVisLinkctx::PgTblWznmQVisLinkctx() :
			TblWznmQVisLinkctx()
			, PgTable()
		{
};

PgTblWznmQVisLinkctx::~PgTblWznmQVisLinkctx() {
};

void PgTblWznmQVisLinkctx::initStatements() {
	createStatement("TblWznmQVisLinkctx_insertRec", "INSERT INTO TblWznmQVisLinkctx (qwr, jref, jnum, tref, ref, orgRefWznmMBox, dstRefWznmMBox, orgClk, dstClk, Weight) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblWznmQVisLinkctx_updateRec", "UPDATE TblWznmQVisLinkctx SET qwr = $1, jref = $2, jnum = $3, tref = $4, ref = $5, orgRefWznmMBox = $6, dstRefWznmMBox = $7, orgClk = $8, dstClk = $9, Weight = $10 WHERE qref = $11", 11);
	createStatement("TblWznmQVisLinkctx_removeRecByQref", "DELETE FROM TblWznmQVisLinkctx WHERE qref = $1", 1);
	createStatement("TblWznmQVisLinkctx_removeRstByJref", "DELETE FROM TblWznmQVisLinkctx WHERE jref = $1", 1);

	createStatement("TblWznmQVisLinkctx_loadRecByQref", "SELECT qref, qwr, jref, jnum, tref, ref, orgRefWznmMBox, dstRefWznmMBox, orgClk, dstClk, Weight FROM TblWznmQVisLinkctx WHERE qref = $1", 1);
	createStatement("TblWznmQVisLinkctx_loadRstByJref", "SELECT qref, qwr, jref, jnum, tref, ref, orgRefWznmMBox, dstRefWznmMBox, orgClk, dstClk, Weight FROM TblWznmQVisLinkctx WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQVisLinkctx::loadRec(
			PGresult* res
			, WznmQVisLinkctx** rec
		) {
	char* ptr;

	WznmQVisLinkctx* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQVisLinkctx();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "tref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "orgrefwznmmbox"),
			PQfnumber(res, "dstrefwznmmbox"),
			PQfnumber(res, "orgclk"),
			PQfnumber(res, "dstclk"),
			PQfnumber(res, "weight")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->qwr = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->tref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->orgRefWznmMBox = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->dstRefWznmMBox = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->orgClk = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->dstClk = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Weight = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQVisLinkctx::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQVisLinkctx& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQVisLinkctx* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "tref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "orgrefwznmmbox"),
			PQfnumber(res, "dstrefwznmmbox"),
			PQfnumber(res, "orgclk"),
			PQfnumber(res, "dstclk"),
			PQfnumber(res, "weight")
		};

		while (numread < numrow) {
			rec = new WznmQVisLinkctx();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->qwr = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->tref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->orgRefWznmMBox = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->dstRefWznmMBox = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->orgClk = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->dstClk = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Weight = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQVisLinkctx::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQVisLinkctx** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVisLinkctx::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVisLinkctx::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQVisLinkctx& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVisLinkctx::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQVisLinkctx::loadRecBySQL(
			const string& sqlstr
			, WznmQVisLinkctx** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVisLinkctx::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVisLinkctx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVisLinkctx& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVisLinkctx::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQVisLinkctx::insertRec(
			WznmQVisLinkctx* rec
		) {
	PGresult* res;
	char* ptr;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _tref = htonl64(rec->tref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _orgRefWznmMBox = htonl64(rec->orgRefWznmMBox);
	ubigint _dstRefWznmMBox = htonl64(rec->dstRefWznmMBox);
	usmallint _orgClk = htons(rec->orgClk);
	usmallint _dstClk = htons(rec->dstClk);
	usmallint _Weight = htons(rec->Weight);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_tref,
		(char*) &_ref,
		(char*) &_orgRefWznmMBox,
		(char*) &_dstRefWznmMBox,
		(char*) &_orgClk,
		(char*) &_dstClk,
		(char*) &_Weight
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQVisLinkctx_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVisLinkctx::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQVisLinkctx::insertRst(
			ListWznmQVisLinkctx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQVisLinkctx::updateRec(
			WznmQVisLinkctx* rec
		) {
	PGresult* res;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _tref = htonl64(rec->tref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _orgRefWznmMBox = htonl64(rec->orgRefWznmMBox);
	ubigint _dstRefWznmMBox = htonl64(rec->dstRefWznmMBox);
	usmallint _orgClk = htons(rec->orgClk);
	usmallint _dstClk = htons(rec->dstClk);
	usmallint _Weight = htons(rec->Weight);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_tref,
		(char*) &_ref,
		(char*) &_orgRefWznmMBox,
		(char*) &_dstRefWznmMBox,
		(char*) &_orgClk,
		(char*) &_dstClk,
		(char*) &_Weight,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQVisLinkctx_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVisLinkctx::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVisLinkctx::updateRst(
			ListWznmQVisLinkctx& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQVisLinkctx::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQVisLinkctx_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVisLinkctx::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVisLinkctx::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQVisLinkctx_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVisLinkctx::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQVisLinkctx::loadRecByQref(
			ubigint qref
			, WznmQVisLinkctx** rec
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

	return loadRecByStmt("TblWznmQVisLinkctx_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQVisLinkctx::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVisLinkctx& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQVisLinkctx_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
