/**
	* \file WznmQQmdList.cpp
	* Dbs and XML wrapper for table TblWznmQQmdList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQQmdList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQmdList
 ******************************************************************************/

WznmQQmdList::WznmQQmdList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint qryRefWznmMQuery
			, const string stubQryRefWznmMQuery
			, const ubigint refWznmMPreset
			, const string stubRefWznmMPreset
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->qryRefWznmMQuery = qryRefWznmMQuery;
	this->stubQryRefWznmMQuery = stubQryRefWznmMQuery;
	this->refWznmMPreset = refWznmMPreset;
	this->stubRefWznmMPreset = stubRefWznmMPreset;
	this->refIxVTbl = refIxVTbl;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->refUref = refUref;
	this->stubRefUref = stubRefUref;
};

void WznmQQmdList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQQmdList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "qry", stubQryRefWznmMQuery);
		writeString(wr, "pst", stubRefWznmMPreset);
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
	} else {
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubQryRefWznmMQuery", stubQryRefWznmMQuery);
		writeString(wr, "stubRefWznmMPreset", stubRefWznmMPreset);
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQQmdList
 ******************************************************************************/

ListWznmQQmdList::ListWznmQQmdList() {
};

ListWznmQQmdList::ListWznmQQmdList(
			const ListWznmQQmdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQmdList(*(src.nodes[i]));
};

ListWznmQQmdList::~ListWznmQQmdList() {
	clear();
};

void ListWznmQQmdList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQQmdList::size() const {
	return(nodes.size());
};

void ListWznmQQmdList::append(
			WznmQQmdList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQQmdList& ListWznmQQmdList::operator=(
			const ListWznmQQmdList& src
		) {
	WznmQQmdList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQQmdList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQQmdList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQQmdList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQQmdList
 ******************************************************************************/

TblWznmQQmdList::TblWznmQQmdList() {
};

TblWznmQQmdList::~TblWznmQQmdList() {
};

bool TblWznmQQmdList::loadRecBySQL(
			const string& sqlstr
			, WznmQQmdList** rec
		) {
	return false;
};

ubigint TblWznmQQmdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQmdList& rst
		) {
	return 0;
};

ubigint TblWznmQQmdList::insertRec(
			WznmQQmdList* rec
		) {
	return 0;
};

ubigint TblWznmQQmdList::insertNewRec(
			WznmQQmdList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint qryRefWznmMQuery
			, const string stubQryRefWznmMQuery
			, const ubigint refWznmMPreset
			, const string stubRefWznmMPreset
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
		) {
	ubigint retval = 0;
	WznmQQmdList* _rec = NULL;

	_rec = new WznmQQmdList(0, jref, jnum, ref, ixVBasetype, srefIxVBasetype, titIxVBasetype, qryRefWznmMQuery, stubQryRefWznmMQuery, refWznmMPreset, stubRefWznmMPreset, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQQmdList::appendNewRecToRst(
			ListWznmQQmdList& rst
			, WznmQQmdList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint qryRefWznmMQuery
			, const string stubQryRefWznmMQuery
			, const ubigint refWznmMPreset
			, const string stubRefWznmMPreset
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
		) {
	ubigint retval = 0;
	WznmQQmdList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, ixVBasetype, srefIxVBasetype, titIxVBasetype, qryRefWznmMQuery, stubQryRefWznmMQuery, refWznmMPreset, stubRefWznmMPreset, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQQmdList::insertRst(
			ListWznmQQmdList& rst
		) {
};

void TblWznmQQmdList::updateRec(
			WznmQQmdList* rec
		) {
};

void TblWznmQQmdList::updateRst(
			ListWznmQQmdList& rst
		) {
};

void TblWznmQQmdList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQQmdList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQQmdList::loadRecByQref(
			ubigint qref
			, WznmQQmdList** rec
		) {
	return false;
};

ubigint TblWznmQQmdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQmdList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQQmdList
 ******************************************************************************/

MyTblWznmQQmdList::MyTblWznmQQmdList() :
			TblWznmQQmdList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQQmdList::~MyTblWznmQQmdList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQQmdList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQQmdList (jref, jnum, ref, ixVBasetype, qryRefWznmMQuery, refWznmMPreset, refIxVTbl, refUref) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQQmdList SET jref = ?, jnum = ?, ref = ?, ixVBasetype = ?, qryRefWznmMQuery = ?, refWznmMPreset = ?, refIxVTbl = ?, refUref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQQmdList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQQmdList WHERE jref = ?", false);
};

bool MyTblWznmQQmdList::loadRecBySQL(
			const string& sqlstr
			, WznmQQmdList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQQmdList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQmdList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQmdList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQQmdList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->ixVBasetype = atol((char*) dbrow[4]); else _rec->ixVBasetype = 0;
		if (dbrow[5]) _rec->qryRefWznmMQuery = atoll((char*) dbrow[5]); else _rec->qryRefWznmMQuery = 0;
		if (dbrow[6]) _rec->refWznmMPreset = atoll((char*) dbrow[6]); else _rec->refWznmMPreset = 0;
		if (dbrow[7]) _rec->refIxVTbl = atol((char*) dbrow[7]); else _rec->refIxVTbl = 0;
		if (dbrow[8]) _rec->refUref = atoll((char*) dbrow[8]); else _rec->refUref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQQmdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQmdList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQQmdList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQmdList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQmdList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQQmdList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->ixVBasetype = atol((char*) dbrow[4]); else rec->ixVBasetype = 0;
			if (dbrow[5]) rec->qryRefWznmMQuery = atoll((char*) dbrow[5]); else rec->qryRefWznmMQuery = 0;
			if (dbrow[6]) rec->refWznmMPreset = atoll((char*) dbrow[6]); else rec->refWznmMPreset = 0;
			if (dbrow[7]) rec->refIxVTbl = atol((char*) dbrow[7]); else rec->refIxVTbl = 0;
			if (dbrow[8]) rec->refUref = atoll((char*) dbrow[8]); else rec->refUref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQQmdList::insertRec(
			WznmQQmdList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVBasetype,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qryRefWznmMQuery,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMPreset,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQQmdList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQQmdList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQQmdList::insertRst(
			ListWznmQQmdList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQQmdList::updateRec(
			WznmQQmdList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVBasetype,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qryRefWznmMQuery,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMPreset,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQQmdList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQQmdList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQmdList::updateRst(
			ListWznmQQmdList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQQmdList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQQmdList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQQmdList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQmdList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQQmdList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQQmdList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQQmdList::loadRecByQref(
			ubigint qref
			, WznmQQmdList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQQmdList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQQmdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQmdList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQQmdList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQQmdList
 ******************************************************************************/

PgTblWznmQQmdList::PgTblWznmQQmdList() :
			TblWznmQQmdList()
			, PgTable()
		{
};

PgTblWznmQQmdList::~PgTblWznmQQmdList() {
};

void PgTblWznmQQmdList::initStatements() {
	createStatement("TblWznmQQmdList_insertRec", "INSERT INTO TblWznmQQmdList (jref, jnum, ref, ixVBasetype, qryRefWznmMQuery, refWznmMPreset, refIxVTbl, refUref) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8);
	createStatement("TblWznmQQmdList_updateRec", "UPDATE TblWznmQQmdList SET jref = $1, jnum = $2, ref = $3, ixVBasetype = $4, qryRefWznmMQuery = $5, refWznmMPreset = $6, refIxVTbl = $7, refUref = $8 WHERE qref = $9", 9);
	createStatement("TblWznmQQmdList_removeRecByQref", "DELETE FROM TblWznmQQmdList WHERE qref = $1", 1);
	createStatement("TblWznmQQmdList_removeRstByJref", "DELETE FROM TblWznmQQmdList WHERE jref = $1", 1);

	createStatement("TblWznmQQmdList_loadRecByQref", "SELECT qref, jref, jnum, ref, ixVBasetype, qryRefWznmMQuery, refWznmMPreset, refIxVTbl, refUref FROM TblWznmQQmdList WHERE qref = $1", 1);
	createStatement("TblWznmQQmdList_loadRstByJref", "SELECT qref, jref, jnum, ref, ixVBasetype, qryRefWznmMQuery, refWznmMPreset, refIxVTbl, refUref FROM TblWznmQQmdList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQQmdList::loadRec(
			PGresult* res
			, WznmQQmdList** rec
		) {
	char* ptr;

	WznmQQmdList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQQmdList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "qryrefwznmmquery"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->qryRefWznmMQuery = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMPreset = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refUref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQQmdList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQQmdList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQQmdList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "qryrefwznmmquery"),
			PQfnumber(res, "refwznmmpreset"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref")
		};

		while (numread < numrow) {
			rec = new WznmQQmdList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->qryRefWznmMQuery = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMPreset = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refUref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQQmdList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQQmdList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQmdList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQmdList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQQmdList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQmdList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQQmdList::loadRecBySQL(
			const string& sqlstr
			, WznmQQmdList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQmdList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQmdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQmdList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQmdList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQQmdList::insertRec(
			WznmQQmdList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _qryRefWznmMQuery = htonl64(rec->qryRefWznmMQuery);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_ixVBasetype,
		(char*) &_qryRefWznmMQuery,
		(char*) &_refWznmMPreset,
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQQmdList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQmdList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQQmdList::insertRst(
			ListWznmQQmdList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQQmdList::updateRec(
			WznmQQmdList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _qryRefWznmMQuery = htonl64(rec->qryRefWznmMQuery);
	ubigint _refWznmMPreset = htonl64(rec->refWznmMPreset);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_ixVBasetype,
		(char*) &_qryRefWznmMQuery,
		(char*) &_refWznmMPreset,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQQmdList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQmdList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQmdList::updateRst(
			ListWznmQQmdList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQQmdList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQQmdList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQmdList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQmdList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQQmdList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQmdList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQQmdList::loadRecByQref(
			ubigint qref
			, WznmQQmdList** rec
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

	return loadRecByStmt("TblWznmQQmdList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQQmdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQmdList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQQmdList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

