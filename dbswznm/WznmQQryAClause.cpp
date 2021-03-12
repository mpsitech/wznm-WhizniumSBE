/**
	* \file WznmQQryAClause.cpp
	* Dbs and XML wrapper for table TblWznmQQryAClause (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmQQryAClause.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQryAClause
 ******************************************************************************/

WznmQQryAClause::WznmQQryAClause(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint qryNum
			, const ubigint x1RefWznmMQuerymod
			, const string stubX1RefWznmMQuerymod
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string Clause
			, const ubigint refWznmMPreset
			, const string stubRefWznmMPreset
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->qryNum = qryNum;
	this->x1RefWznmMQuerymod = x1RefWznmMQuerymod;
	this->stubX1RefWznmMQuerymod = stubX1RefWznmMQuerymod;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->Clause = Clause;
	this->refWznmMPreset = refWznmMPreset;
	this->stubRefWznmMPreset = stubRefWznmMPreset;
	this->refWznmMVector = refWznmMVector;
	this->stubRefWznmMVector = stubRefWznmMVector;
	this->refWznmMVectoritem = refWznmMVectoritem;
	this->stubRefWznmMVectoritem = stubRefWznmMVectoritem;
};

void WznmQQryAClause::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["qmd"] = stubX1RefWznmMQuerymod;
		me["typ"] = srefIxVBasetype;
		me["typ2"] = titIxVBasetype;
		me["cse"] = Clause;
		me["pst"] = stubRefWznmMPreset;
		me["vec"] = stubRefWznmMVector;
		me["vit"] = stubRefWznmMVectoritem;
	} else {
		me["stubX1RefWznmMQuerymod"] = stubX1RefWznmMQuerymod;
		me["srefIxVBasetype"] = srefIxVBasetype;
		me["titIxVBasetype"] = titIxVBasetype;
		me["Clause"] = Clause;
		me["stubRefWznmMPreset"] = stubRefWznmMPreset;
		me["stubRefWznmMVector"] = stubRefWznmMVector;
		me["stubRefWznmMVectoritem"] = stubRefWznmMVectoritem;
	};
};

void WznmQQryAClause::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQQryAClause";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "qmd", stubX1RefWznmMQuerymod);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "cse", Clause);
		writeString(wr, "pst", stubRefWznmMPreset);
		writeString(wr, "vec", stubRefWznmMVector);
		writeString(wr, "vit", stubRefWznmMVectoritem);
	} else {
		writeString(wr, "stubX1RefWznmMQuerymod", stubX1RefWznmMQuerymod);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "Clause", Clause);
		writeString(wr, "stubRefWznmMPreset", stubRefWznmMPreset);
		writeString(wr, "stubRefWznmMVector", stubRefWznmMVector);
		writeString(wr, "stubRefWznmMVectoritem", stubRefWznmMVectoritem);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQQryAClause
 ******************************************************************************/

ListWznmQQryAClause::ListWznmQQryAClause() {
};

ListWznmQQryAClause::ListWznmQQryAClause(
			const ListWznmQQryAClause& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryAClause(*(src.nodes[i]));
};

ListWznmQQryAClause::~ListWznmQQryAClause() {
	clear();
};

void ListWznmQQryAClause::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQQryAClause::size() const {
	return(nodes.size());
};

void ListWznmQQryAClause::append(
			WznmQQryAClause* rec
		) {
	nodes.push_back(rec);
};

ListWznmQQryAClause& ListWznmQQryAClause::operator=(
			const ListWznmQQryAClause& src
		) {
	WznmQQryAClause* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQQryAClause(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQQryAClause::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQQryAClause";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQQryAClause::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQQryAClause";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQQryAClause
 ******************************************************************************/

TblWznmQQryAClause::TblWznmQQryAClause() {
};

TblWznmQQryAClause::~TblWznmQQryAClause() {
};

bool TblWznmQQryAClause::loadRecBySQL(
			const string& sqlstr
			, WznmQQryAClause** rec
		) {
	return false;
};

ubigint TblWznmQQryAClause::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryAClause& rst
		) {
	return 0;
};

ubigint TblWznmQQryAClause::insertRec(
			WznmQQryAClause* rec
		) {
	return 0;
};

ubigint TblWznmQQryAClause::insertNewRec(
			WznmQQryAClause** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint qryNum
			, const ubigint x1RefWznmMQuerymod
			, const string stubX1RefWznmMQuerymod
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string Clause
			, const ubigint refWznmMPreset
			, const string stubRefWznmMPreset
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
		) {
	ubigint retval = 0;
	WznmQQryAClause* _rec = NULL;

	_rec = new WznmQQryAClause(0, jref, jnum, ref, qryNum, x1RefWznmMQuerymod, stubX1RefWznmMQuerymod, ixVBasetype, srefIxVBasetype, titIxVBasetype, Clause, refWznmMPreset, stubRefWznmMPreset, refWznmMVector, stubRefWznmMVector, refWznmMVectoritem, stubRefWznmMVectoritem);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQQryAClause::appendNewRecToRst(
			ListWznmQQryAClause& rst
			, WznmQQryAClause** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint qryNum
			, const ubigint x1RefWznmMQuerymod
			, const string stubX1RefWznmMQuerymod
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const string Clause
			, const ubigint refWznmMPreset
			, const string stubRefWznmMPreset
			, const ubigint refWznmMVector
			, const string stubRefWznmMVector
			, const ubigint refWznmMVectoritem
			, const string stubRefWznmMVectoritem
		) {
	ubigint retval = 0;
	WznmQQryAClause* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, qryNum, x1RefWznmMQuerymod, stubX1RefWznmMQuerymod, ixVBasetype, srefIxVBasetype, titIxVBasetype, Clause, refWznmMPreset, stubRefWznmMPreset, refWznmMVector, stubRefWznmMVector, refWznmMVectoritem, stubRefWznmMVectoritem);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQQryAClause::insertRst(
			ListWznmQQryAClause& rst
		) {
};

void TblWznmQQryAClause::updateRec(
			WznmQQryAClause* rec
		) {
};

void TblWznmQQryAClause::updateRst(
			ListWznmQQryAClause& rst
		) {
};

void TblWznmQQryAClause::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQQryAClause::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQQryAClause::loadRecByQref(
			ubigint qref
			, WznmQQryAClause** rec
		) {
	return false;
};

ubigint TblWznmQQryAClause::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryAClause& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQQryAClause
 ******************************************************************************/

MyTblWznmQQryAClause::MyTblWznmQQryAClause() :
			TblWznmQQryAClause()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQQryAClause::~MyTblWznmQQryAClause() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQQryAClause::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQQryAClause (jref, jnum, ref, qryNum, x1RefWznmMQuerymod, ixVBasetype, Clause, refWznmMPreset, refWznmMVector, refWznmMVectoritem) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQQryAClause SET jref = ?, jnum = ?, ref = ?, qryNum = ?, x1RefWznmMQuerymod = ?, ixVBasetype = ?, Clause = ?, refWznmMPreset = ?, refWznmMVector = ?, refWznmMVectoritem = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQQryAClause WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQQryAClause WHERE jref = ?", false);
};

bool MyTblWznmQQryAClause::loadRecBySQL(
			const string& sqlstr
			, WznmQQryAClause** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQQryAClause* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQryAClause::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQryAClause::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQQryAClause();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->qryNum = atol((char*) dbrow[4]); else _rec->qryNum = 0;
		if (dbrow[5]) _rec->x1RefWznmMQuerymod = atoll((char*) dbrow[5]); else _rec->x1RefWznmMQuerymod = 0;
		if (dbrow[6]) _rec->ixVBasetype = atol((char*) dbrow[6]); else _rec->ixVBasetype = 0;
		if (dbrow[7]) _rec->Clause.assign(dbrow[7], dblengths[7]); else _rec->Clause = "";
		if (dbrow[8]) _rec->refWznmMPreset = atoll((char*) dbrow[8]); else _rec->refWznmMPreset = 0;
		if (dbrow[9]) _rec->refWznmMVector = atoll((char*) dbrow[9]); else _rec->refWznmMVector = 0;
		if (dbrow[10]) _rec->refWznmMVectoritem = atoll((char*) dbrow[10]); else _rec->refWznmMVectoritem = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQQryAClause::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryAClause& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQQryAClause* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQryAClause::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQryAClause::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQQryAClause();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->qryNum = atol((char*) dbrow[4]); else rec->qryNum = 0;
			if (dbrow[5]) rec->x1RefWznmMQuerymod = atoll((char*) dbrow[5]); else rec->x1RefWznmMQuerymod = 0;
			if (dbrow[6]) rec->ixVBasetype = atol((char*) dbrow[6]); else rec->ixVBasetype = 0;
			if (dbrow[7]) rec->Clause.assign(dbrow[7], dblengths[7]); else rec->Clause = "";
			if (dbrow[8]) rec->refWznmMPreset = atoll((char*) dbrow[8]); else rec->refWznmMPreset = 0;
			if (dbrow[9]) rec->refWznmMVector = atoll((char*) dbrow[9]); else rec->refWznmMVector = 0;
			if (dbrow[10]) rec->refWznmMVectoritem = atoll((char*) dbrow[10]); else rec->refWznmMVectoritem = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQQryAClause::insertRec(
			WznmQQryAClause* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[6] = rec->Clause.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->qryNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x1RefWznmMQuerymod,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Clause.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMPreset,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMVector,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQQryAClause::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQQryAClause::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQQryAClause::insertRst(
			ListWznmQQryAClause& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQQryAClause::updateRec(
			WznmQQryAClause* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[6] = rec->Clause.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->qryNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x1RefWznmMQuerymod,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Clause.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMPreset,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMVector,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQQryAClause::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQQryAClause::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQryAClause::updateRst(
			ListWznmQQryAClause& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQQryAClause::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQQryAClause::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQQryAClause::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQryAClause::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQQryAClause::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQQryAClause::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQQryAClause::loadRecByQref(
			ubigint qref
			, WznmQQryAClause** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQQryAClause WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQQryAClause::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryAClause& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQQryAClause WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQQryAClause
 ******************************************************************************/

PgTblWznmQQryAClause::PgTblWznmQQryAClause() :
			TblWznmQQryAClause()
			, PgTable()
		{
};

PgTblWznmQQryAClause::~PgTblWznmQQryAClause() {
};

void PgTblWznmQQryAClause::initStatements() {
	createStatement("TblWznmQQryAClause_insertRec", "INSERT INTO TblWznmQQryAClause (jref, jnum, ref, qryNum, x1RefWznmMQuerymod, ixVBasetype, Clause, refWznmMPreset, refWznmMVector, refWznmMVectoritem) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblWznmQQryAClause_updateRec", "UPDATE TblWznmQQryAClause SET jref = $1, jnum = $2, ref = $3, qryNum = $4, x1RefWznmMQuerymod = $5, ixVBasetype = $6, Clause = $7, refWznmMPreset = $8, refWznmMVector = $9, refWznmMVectoritem = $10 WHERE qref = $11", 11);
	createStatement("TblWznmQQryAClause_removeRecByQref", "DELETE FROM TblWznmQQryAClause WHERE qref = $1", 1);
	createStatement("TblWznmQQryAClause_removeRstByJref", "DELETE FROM TblWznmQQryAClause WHERE jref = $1", 1);

	createStatement("TblWznmQQryAClause_loadRecByQref", "SELECT qref, jref, jnum, ref, qryNum, x1RefWznmMQuerymod, ixVBasetype, Clause, refWznmMPreset, refWznmMVector, refWznmMVectoritem FROM TblWznmQQryAClause WHERE qref = $1", 1);
	createStatement("TblWznmQQryAClause_loadRstByJref", "SELECT qref, jref, jnum, ref, qryNum, x1RefWznmMQuerymod, ixVBasetype, Clause, refWznmMPreset, refWznmMVector, refWznmMVectoritem FROM TblWznmQQryAClause WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQQryAClause::loadRec(
			PGresult* res
			, WznmQQryAClause** rec
		) {
	char* ptr;

	WznmQQryAClause* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQQryAClause();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "qrynum"),
			PQfnumber(res, "x1refwznmmquerymod"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "clause"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "refwznmmvectoritem")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->qryNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1RefWznmMQuerymod = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Clause.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMPreset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->refWznmMVectoritem = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQQryAClause::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQQryAClause& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQQryAClause* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "qrynum"),
			PQfnumber(res, "x1refwznmmquerymod"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "clause"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "refwznmmvectoritem")
		};

		while (numread < numrow) {
			rec = new WznmQQryAClause();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->qryNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1RefWznmMQuerymod = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Clause.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMPreset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->refWznmMVectoritem = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQQryAClause::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQQryAClause** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryAClause::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQryAClause::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQQryAClause& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryAClause::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQQryAClause::loadRecBySQL(
			const string& sqlstr
			, WznmQQryAClause** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQryAClause::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQryAClause::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryAClause& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQryAClause::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQQryAClause::insertRec(
			WznmQQryAClause* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _qryNum = htonl(rec->qryNum);
	ubigint _x1RefWznmMQuerymod = htonl64(rec->x1RefWznmMQuerymod);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qryNum,
		(char*) &_x1RefWznmMQuerymod,
		(char*) &_ixVBasetype,
		rec->Clause.c_str(),
		(char*) &_refWznmMPreset,
		(char*) &_refWznmMVector,
		(char*) &_refWznmMVectoritem
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQQryAClause_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryAClause::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQQryAClause::insertRst(
			ListWznmQQryAClause& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQQryAClause::updateRec(
			WznmQQryAClause* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _qryNum = htonl(rec->qryNum);
	ubigint _x1RefWznmMQuerymod = htonl64(rec->x1RefWznmMQuerymod);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qryNum,
		(char*) &_x1RefWznmMQuerymod,
		(char*) &_ixVBasetype,
		rec->Clause.c_str(),
		(char*) &_refWznmMPreset,
		(char*) &_refWznmMVector,
		(char*) &_refWznmMVectoritem,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQQryAClause_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryAClause::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQryAClause::updateRst(
			ListWznmQQryAClause& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQQryAClause::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQQryAClause_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryAClause::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQryAClause::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQQryAClause_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryAClause::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQQryAClause::loadRecByQref(
			ubigint qref
			, WznmQQryAClause** rec
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

	return loadRecByStmt("TblWznmQQryAClause_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQQryAClause::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryAClause& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQQryAClause_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
