/**
	* \file WznmQBoxList.cpp
	* Dbs and XML wrapper for table TblWznmQBoxList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmQBoxList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQBoxList
 ******************************************************************************/

WznmQBoxList::WznmQBoxList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWznmMSheet
			, const string stubRefWznmMSheet
			, const uint unvIxWznmVMaintable
			, const string srefUnvIxWznmVMaintable
			, const string titUnvIxWznmVMaintable
			, const ubigint unvUref
			, const string stubUnvUref
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, refWznmMSheet(refWznmMSheet)
			, stubRefWznmMSheet(stubRefWznmMSheet)
			, unvIxWznmVMaintable(unvIxWznmVMaintable)
			, srefUnvIxWznmVMaintable(srefUnvIxWznmVMaintable)
			, titUnvIxWznmVMaintable(titUnvIxWznmVMaintable)
			, unvUref(unvUref)
			, stubUnvUref(stubUnvUref)
		{
};

void WznmQBoxList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["sht"] = stubRefWznmMSheet;
		me["mtb"] = srefUnvIxWznmVMaintable;
		me["mtb2"] = titUnvIxWznmVMaintable;
		me["unv"] = stubUnvUref;
	} else {
		me["stubRefWznmMSheet"] = stubRefWznmMSheet;
		me["srefUnvIxWznmVMaintable"] = srefUnvIxWznmVMaintable;
		me["titUnvIxWznmVMaintable"] = titUnvIxWznmVMaintable;
		me["stubUnvUref"] = stubUnvUref;
	};
};

void WznmQBoxList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQBoxList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "sht", stubRefWznmMSheet);
		writeString(wr, "mtb", srefUnvIxWznmVMaintable);
		writeString(wr, "mtb2", titUnvIxWznmVMaintable);
		writeString(wr, "unv", stubUnvUref);
	} else {
		writeString(wr, "stubRefWznmMSheet", stubRefWznmMSheet);
		writeString(wr, "srefUnvIxWznmVMaintable", srefUnvIxWznmVMaintable);
		writeString(wr, "titUnvIxWznmVMaintable", titUnvIxWznmVMaintable);
		writeString(wr, "stubUnvUref", stubUnvUref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQBoxList
 ******************************************************************************/

ListWznmQBoxList::ListWznmQBoxList() {
};

ListWznmQBoxList::ListWznmQBoxList(
			const ListWznmQBoxList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQBoxList(*(src.nodes[i]));
};

ListWznmQBoxList::~ListWznmQBoxList() {
	clear();
};

void ListWznmQBoxList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQBoxList::size() const {
	return(nodes.size());
};

void ListWznmQBoxList::append(
			WznmQBoxList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQBoxList& ListWznmQBoxList::operator=(
			const ListWznmQBoxList& src
		) {
	WznmQBoxList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQBoxList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQBoxList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWznmQBoxList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWznmQBoxList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQBoxList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQBoxList
 ******************************************************************************/

TblWznmQBoxList::TblWznmQBoxList() {
};

TblWznmQBoxList::~TblWznmQBoxList() {
};

bool TblWznmQBoxList::loadRecBySQL(
			const string& sqlstr
			, WznmQBoxList** rec
		) {
	return false;
};

ubigint TblWznmQBoxList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBoxList& rst
		) {
	return 0;
};

ubigint TblWznmQBoxList::insertRec(
			WznmQBoxList* rec
		) {
	return 0;
};

ubigint TblWznmQBoxList::insertNewRec(
			WznmQBoxList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWznmMSheet
			, const string stubRefWznmMSheet
			, const uint unvIxWznmVMaintable
			, const string srefUnvIxWznmVMaintable
			, const string titUnvIxWznmVMaintable
			, const ubigint unvUref
			, const string stubUnvUref
		) {
	ubigint retval = 0;
	WznmQBoxList* _rec = NULL;

	_rec = new WznmQBoxList(0, jref, jnum, ref, refWznmMSheet, stubRefWznmMSheet, unvIxWznmVMaintable, srefUnvIxWznmVMaintable, titUnvIxWznmVMaintable, unvUref, stubUnvUref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQBoxList::appendNewRecToRst(
			ListWznmQBoxList& rst
			, WznmQBoxList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refWznmMSheet
			, const string stubRefWznmMSheet
			, const uint unvIxWznmVMaintable
			, const string srefUnvIxWznmVMaintable
			, const string titUnvIxWznmVMaintable
			, const ubigint unvUref
			, const string stubUnvUref
		) {
	ubigint retval = 0;
	WznmQBoxList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refWznmMSheet, stubRefWznmMSheet, unvIxWznmVMaintable, srefUnvIxWznmVMaintable, titUnvIxWznmVMaintable, unvUref, stubUnvUref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQBoxList::insertRst(
			ListWznmQBoxList& rst
		) {
};

void TblWznmQBoxList::updateRec(
			WznmQBoxList* rec
		) {
};

void TblWznmQBoxList::updateRst(
			ListWznmQBoxList& rst
		) {
};

void TblWznmQBoxList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQBoxList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQBoxList::loadRecByQref(
			ubigint qref
			, WznmQBoxList** rec
		) {
	return false;
};

ubigint TblWznmQBoxList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBoxList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQBoxList
 ******************************************************************************/

MyTblWznmQBoxList::MyTblWznmQBoxList() :
			TblWznmQBoxList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQBoxList::~MyTblWznmQBoxList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQBoxList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQBoxList (jref, jnum, ref, refWznmMSheet, unvIxWznmVMaintable, unvUref) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQBoxList SET jref = ?, jnum = ?, ref = ?, refWznmMSheet = ?, unvIxWznmVMaintable = ?, unvUref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQBoxList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQBoxList WHERE jref = ?", false);
};

bool MyTblWznmQBoxList::loadRecBySQL(
			const string& sqlstr
			, WznmQBoxList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQBoxList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQBoxList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQBoxList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQBoxList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refWznmMSheet = atoll((char*) dbrow[4]); else _rec->refWznmMSheet = 0;
		if (dbrow[5]) _rec->unvIxWznmVMaintable = atol((char*) dbrow[5]); else _rec->unvIxWznmVMaintable = 0;
		if (dbrow[6]) _rec->unvUref = atoll((char*) dbrow[6]); else _rec->unvUref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQBoxList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBoxList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQBoxList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQBoxList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQBoxList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQBoxList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refWznmMSheet = atoll((char*) dbrow[4]); else rec->refWznmMSheet = 0;
			if (dbrow[5]) rec->unvIxWznmVMaintable = atol((char*) dbrow[5]); else rec->unvIxWznmVMaintable = 0;
			if (dbrow[6]) rec->unvUref = atoll((char*) dbrow[6]); else rec->unvUref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQBoxList::insertRec(
			WznmQBoxList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMSheet,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->unvUref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQBoxList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQBoxList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQBoxList::insertRst(
			ListWznmQBoxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQBoxList::updateRec(
			WznmQBoxList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWznmMSheet,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->unvIxWznmVMaintable,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->unvUref,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQBoxList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQBoxList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQBoxList::updateRst(
			ListWznmQBoxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQBoxList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQBoxList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQBoxList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQBoxList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQBoxList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQBoxList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQBoxList::loadRecByQref(
			ubigint qref
			, WznmQBoxList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQBoxList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQBoxList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBoxList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQBoxList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQBoxList
 ******************************************************************************/

PgTblWznmQBoxList::PgTblWznmQBoxList() :
			TblWznmQBoxList()
			, PgTable()
		{
};

PgTblWznmQBoxList::~PgTblWznmQBoxList() {
};

void PgTblWznmQBoxList::initStatements() {
	createStatement("TblWznmQBoxList_insertRec", "INSERT INTO TblWznmQBoxList (jref, jnum, ref, refWznmMSheet, unvIxWznmVMaintable, unvUref) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQBoxList_updateRec", "UPDATE TblWznmQBoxList SET jref = $1, jnum = $2, ref = $3, refWznmMSheet = $4, unvIxWznmVMaintable = $5, unvUref = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQBoxList_removeRecByQref", "DELETE FROM TblWznmQBoxList WHERE qref = $1", 1);
	createStatement("TblWznmQBoxList_removeRstByJref", "DELETE FROM TblWznmQBoxList WHERE jref = $1", 1);

	createStatement("TblWznmQBoxList_loadRecByQref", "SELECT qref, jref, jnum, ref, refWznmMSheet, unvIxWznmVMaintable, unvUref FROM TblWznmQBoxList WHERE qref = $1", 1);
	createStatement("TblWznmQBoxList_loadRstByJref", "SELECT qref, jref, jnum, ref, refWznmMSheet, unvIxWznmVMaintable, unvUref FROM TblWznmQBoxList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQBoxList::loadRec(
			PGresult* res
			, WznmQBoxList** rec
		) {
	char* ptr;

	WznmQBoxList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQBoxList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmsheet"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWznmMSheet = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->unvIxWznmVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->unvUref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQBoxList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQBoxList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQBoxList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmsheet"),
			PQfnumber(res, "unvixwznmvmaintable"),
			PQfnumber(res, "unvuref")
		};

		while (numread < numrow) {
			rec = new WznmQBoxList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWznmMSheet = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->unvIxWznmVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->unvUref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQBoxList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQBoxList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBoxList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQBoxList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQBoxList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBoxList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQBoxList::loadRecBySQL(
			const string& sqlstr
			, WznmQBoxList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQBoxList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQBoxList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQBoxList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQBoxList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQBoxList::insertRec(
			WznmQBoxList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMSheet = htonl64(rec->refWznmMSheet);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refWznmMSheet,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQBoxList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQBoxList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQBoxList::insertRst(
			ListWznmQBoxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQBoxList::updateRec(
			WznmQBoxList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMSheet = htonl64(rec->refWznmMSheet);
	uint _unvIxWznmVMaintable = htonl(rec->unvIxWznmVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refWznmMSheet,
		(char*) &_unvIxWznmVMaintable,
		(char*) &_unvUref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQBoxList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBoxList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQBoxList::updateRst(
			ListWznmQBoxList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQBoxList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQBoxList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBoxList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQBoxList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQBoxList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQBoxList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQBoxList::loadRecByQref(
			ubigint qref
			, WznmQBoxList** rec
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

	return loadRecByStmt("TblWznmQBoxList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQBoxList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQBoxList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQBoxList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
