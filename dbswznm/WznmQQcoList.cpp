/**
	* \file WznmQQcoList.cpp
	* Dbs and XML wrapper for table TblWznmQQcoList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQQcoList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQcoList
 ******************************************************************************/

WznmQQcoList::WznmQQcoList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Short
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint qryRefWznmMQuery
			, const string stubQryRefWznmMQuery
			, const ubigint refWznmMTablecol
			, const string stubRefWznmMTablecol
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
	this->qryRefWznmMQuery = qryRefWznmMQuery;
	this->stubQryRefWznmMQuery = stubQryRefWznmMQuery;
	this->refWznmMTablecol = refWznmMTablecol;
	this->stubRefWznmMTablecol = stubRefWznmMTablecol;
};

void WznmQQcoList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQQcoList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "sho", Short);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "qry", stubQryRefWznmMQuery);
		writeString(wr, "tco", stubRefWznmMTablecol);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Short", Short);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubQryRefWznmMQuery", stubQryRefWznmMQuery);
		writeString(wr, "stubRefWznmMTablecol", stubRefWznmMTablecol);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQQcoList
 ******************************************************************************/

ListWznmQQcoList::ListWznmQQcoList() {
};

ListWznmQQcoList::ListWznmQQcoList(
			const ListWznmQQcoList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQcoList(*(src.nodes[i]));
};

ListWznmQQcoList::~ListWznmQQcoList() {
	clear();
};

void ListWznmQQcoList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQQcoList::size() const {
	return(nodes.size());
};

void ListWznmQQcoList::append(
			WznmQQcoList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQQcoList& ListWznmQQcoList::operator=(
			const ListWznmQQcoList& src
		) {
	WznmQQcoList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQQcoList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQQcoList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQQcoList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQQcoList
 ******************************************************************************/

TblWznmQQcoList::TblWznmQQcoList() {
};

TblWznmQQcoList::~TblWznmQQcoList() {
};

bool TblWznmQQcoList::loadRecBySQL(
			const string& sqlstr
			, WznmQQcoList** rec
		) {
	return false;
};

ubigint TblWznmQQcoList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQcoList& rst
		) {
	return 0;
};

ubigint TblWznmQQcoList::insertRec(
			WznmQQcoList* rec
		) {
	return 0;
};

ubigint TblWznmQQcoList::insertNewRec(
			WznmQQcoList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Short
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint qryRefWznmMQuery
			, const string stubQryRefWznmMQuery
			, const ubigint refWznmMTablecol
			, const string stubRefWznmMTablecol
		) {
	ubigint retval = 0;
	WznmQQcoList* _rec = NULL;

	_rec = new WznmQQcoList(0, jref, jnum, ref, sref, Short, ixVBasetype, srefIxVBasetype, titIxVBasetype, qryRefWznmMQuery, stubQryRefWznmMQuery, refWznmMTablecol, stubRefWznmMTablecol);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQQcoList::appendNewRecToRst(
			ListWznmQQcoList& rst
			, WznmQQcoList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Short
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint qryRefWznmMQuery
			, const string stubQryRefWznmMQuery
			, const ubigint refWznmMTablecol
			, const string stubRefWznmMTablecol
		) {
	ubigint retval = 0;
	WznmQQcoList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Short, ixVBasetype, srefIxVBasetype, titIxVBasetype, qryRefWznmMQuery, stubQryRefWznmMQuery, refWznmMTablecol, stubRefWznmMTablecol);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQQcoList::insertRst(
			ListWznmQQcoList& rst
		) {
};

void TblWznmQQcoList::updateRec(
			WznmQQcoList* rec
		) {
};

void TblWznmQQcoList::updateRst(
			ListWznmQQcoList& rst
		) {
};

void TblWznmQQcoList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQQcoList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQQcoList::loadRecByQref(
			ubigint qref
			, WznmQQcoList** rec
		) {
	return false;
};

ubigint TblWznmQQcoList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQcoList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQQcoList
 ******************************************************************************/

MyTblWznmQQcoList::MyTblWznmQQcoList() :
			TblWznmQQcoList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQQcoList::~MyTblWznmQQcoList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQQcoList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQQcoList (jref, jnum, ref, sref, Short, ixVBasetype, qryRefWznmMQuery, refWznmMTablecol) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQQcoList SET jref = ?, jnum = ?, ref = ?, sref = ?, Short = ?, ixVBasetype = ?, qryRefWznmMQuery = ?, refWznmMTablecol = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQQcoList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQQcoList WHERE jref = ?", false);
};

bool MyTblWznmQQcoList::loadRecBySQL(
			const string& sqlstr
			, WznmQQcoList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQQcoList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQcoList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQcoList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQQcoList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Short.assign(dbrow[5], dblengths[5]); else _rec->Short = "";
		if (dbrow[6]) _rec->ixVBasetype = atol((char*) dbrow[6]); else _rec->ixVBasetype = 0;
		if (dbrow[7]) _rec->qryRefWznmMQuery = atoll((char*) dbrow[7]); else _rec->qryRefWznmMQuery = 0;
		if (dbrow[8]) _rec->refWznmMTablecol = atoll((char*) dbrow[8]); else _rec->refWznmMTablecol = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQQcoList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQcoList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQQcoList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQcoList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQcoList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQQcoList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Short.assign(dbrow[5], dblengths[5]); else rec->Short = "";
			if (dbrow[6]) rec->ixVBasetype = atol((char*) dbrow[6]); else rec->ixVBasetype = 0;
			if (dbrow[7]) rec->qryRefWznmMQuery = atoll((char*) dbrow[7]); else rec->qryRefWznmMQuery = 0;
			if (dbrow[8]) rec->refWznmMTablecol = atoll((char*) dbrow[8]); else rec->refWznmMTablecol = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQQcoList::insertRec(
			WznmQQcoList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[4] = rec->Short.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Short.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qryRefWznmMQuery,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMTablecol,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQQcoList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQQcoList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQQcoList::insertRst(
			ListWznmQQcoList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQQcoList::updateRec(
			WznmQQcoList* rec
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
		bindUbigint(&rec->qryRefWznmMQuery,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWznmMTablecol,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQQcoList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQQcoList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQcoList::updateRst(
			ListWznmQQcoList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQQcoList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQQcoList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQQcoList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQcoList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQQcoList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQQcoList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQQcoList::loadRecByQref(
			ubigint qref
			, WznmQQcoList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQQcoList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQQcoList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQcoList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQQcoList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQQcoList
 ******************************************************************************/

PgTblWznmQQcoList::PgTblWznmQQcoList() :
			TblWznmQQcoList()
			, PgTable()
		{
};

PgTblWznmQQcoList::~PgTblWznmQQcoList() {
};

void PgTblWznmQQcoList::initStatements() {
	createStatement("TblWznmQQcoList_insertRec", "INSERT INTO TblWznmQQcoList (jref, jnum, ref, sref, Short, ixVBasetype, qryRefWznmMQuery, refWznmMTablecol) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8);
	createStatement("TblWznmQQcoList_updateRec", "UPDATE TblWznmQQcoList SET jref = $1, jnum = $2, ref = $3, sref = $4, Short = $5, ixVBasetype = $6, qryRefWznmMQuery = $7, refWznmMTablecol = $8 WHERE qref = $9", 9);
	createStatement("TblWznmQQcoList_removeRecByQref", "DELETE FROM TblWznmQQcoList WHERE qref = $1", 1);
	createStatement("TblWznmQQcoList_removeRstByJref", "DELETE FROM TblWznmQQcoList WHERE jref = $1", 1);

	createStatement("TblWznmQQcoList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Short, ixVBasetype, qryRefWznmMQuery, refWznmMTablecol FROM TblWznmQQcoList WHERE qref = $1", 1);
	createStatement("TblWznmQQcoList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Short, ixVBasetype, qryRefWznmMQuery, refWznmMTablecol FROM TblWznmQQcoList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQQcoList::loadRec(
			PGresult* res
			, WznmQQcoList** rec
		) {
	char* ptr;

	WznmQQcoList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQQcoList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "qryrefwznmmquery"),
			PQfnumber(res, "refwznmmtablecol")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->qryRefWznmMQuery = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWznmMTablecol = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQQcoList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQQcoList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQQcoList* rec;

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
			PQfnumber(res, "qryrefwznmmquery"),
			PQfnumber(res, "refwznmmtablecol")
		};

		while (numread < numrow) {
			rec = new WznmQQcoList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->qryRefWznmMQuery = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWznmMTablecol = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQQcoList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQQcoList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQcoList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQcoList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQQcoList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQcoList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQQcoList::loadRecBySQL(
			const string& sqlstr
			, WznmQQcoList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQcoList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQcoList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQcoList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQcoList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQQcoList::insertRec(
			WznmQQcoList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _qryRefWznmMQuery = htonl64(rec->qryRefWznmMQuery);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_qryRefWznmMQuery,
		(char*) &_refWznmMTablecol
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQQcoList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQcoList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQQcoList::insertRst(
			ListWznmQQcoList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQQcoList::updateRec(
			WznmQQcoList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _qryRefWznmMQuery = htonl64(rec->qryRefWznmMQuery);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_qryRefWznmMQuery,
		(char*) &_refWznmMTablecol,
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
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQQcoList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQcoList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQcoList::updateRst(
			ListWznmQQcoList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQQcoList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQQcoList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQcoList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQcoList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQQcoList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQcoList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQQcoList::loadRecByQref(
			ubigint qref
			, WznmQQcoList** rec
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

	return loadRecByStmt("TblWznmQQcoList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQQcoList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQcoList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQQcoList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

