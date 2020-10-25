/**
	* \file WznmQChkList.cpp
	* Dbs and XML wrapper for table TblWznmQChkList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQChkList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQChkList
 ******************************************************************************/

WznmQChkList::WznmQChkList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
			, const ubigint refWznmMTablecol
			, const string stubRefWznmMTablecol
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->refWznmMTable = refWznmMTable;
	this->stubRefWznmMTable = stubRefWznmMTable;
	this->refWznmMTablecol = refWznmMTablecol;
	this->stubRefWznmMTablecol = stubRefWznmMTablecol;
};

void WznmQChkList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQChkList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "tbl", stubRefWznmMTable);
		writeString(wr, "tco", stubRefWznmMTablecol);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubRefWznmMTable", stubRefWznmMTable);
		writeString(wr, "stubRefWznmMTablecol", stubRefWznmMTablecol);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQChkList
 ******************************************************************************/

ListWznmQChkList::ListWznmQChkList() {
};

ListWznmQChkList::ListWznmQChkList(
			const ListWznmQChkList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQChkList(*(src.nodes[i]));
};

ListWznmQChkList::~ListWznmQChkList() {
	clear();
};

void ListWznmQChkList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQChkList::size() const {
	return(nodes.size());
};

void ListWznmQChkList::append(
			WznmQChkList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQChkList& ListWznmQChkList::operator=(
			const ListWznmQChkList& src
		) {
	WznmQChkList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQChkList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQChkList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQChkList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQChkList
 ******************************************************************************/

TblWznmQChkList::TblWznmQChkList() {
};

TblWznmQChkList::~TblWznmQChkList() {
};

bool TblWznmQChkList::loadRecBySQL(
			const string& sqlstr
			, WznmQChkList** rec
		) {
	return false;
};

ubigint TblWznmQChkList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQChkList& rst
		) {
	return 0;
};

ubigint TblWznmQChkList::insertRec(
			WznmQChkList* rec
		) {
	return 0;
};

ubigint TblWznmQChkList::insertNewRec(
			WznmQChkList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
			, const ubigint refWznmMTablecol
			, const string stubRefWznmMTablecol
		) {
	ubigint retval = 0;
	WznmQChkList* _rec = NULL;

	_rec = new WznmQChkList(0, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, refWznmMTable, stubRefWznmMTable, refWznmMTablecol, stubRefWznmMTablecol);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQChkList::appendNewRecToRst(
			ListWznmQChkList& rst
			, WznmQChkList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
			, const ubigint refWznmMTablecol
			, const string stubRefWznmMTablecol
		) {
	ubigint retval = 0;
	WznmQChkList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, refWznmMTable, stubRefWznmMTable, refWznmMTablecol, stubRefWznmMTablecol);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQChkList::insertRst(
			ListWznmQChkList& rst
		) {
};

void TblWznmQChkList::updateRec(
			WznmQChkList* rec
		) {
};

void TblWznmQChkList::updateRst(
			ListWznmQChkList& rst
		) {
};

void TblWznmQChkList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQChkList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQChkList::loadRecByQref(
			ubigint qref
			, WznmQChkList** rec
		) {
	return false;
};

ubigint TblWznmQChkList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQChkList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQChkList
 ******************************************************************************/

MyTblWznmQChkList::MyTblWznmQChkList() :
			TblWznmQChkList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQChkList::~MyTblWznmQChkList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQChkList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQChkList (jref, jnum, ref, sref, ixVBasetype, refWznmMTable, refWznmMTablecol) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQChkList SET jref = ?, jnum = ?, ref = ?, sref = ?, ixVBasetype = ?, refWznmMTable = ?, refWznmMTablecol = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQChkList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQChkList WHERE jref = ?", false);
};

bool MyTblWznmQChkList::loadRecBySQL(
			const string& sqlstr
			, WznmQChkList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQChkList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQChkList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQChkList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQChkList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixVBasetype = atol((char*) dbrow[5]); else _rec->ixVBasetype = 0;
		if (dbrow[6]) _rec->refWznmMTable = atoll((char*) dbrow[6]); else _rec->refWznmMTable = 0;
		if (dbrow[7]) _rec->refWznmMTablecol = atoll((char*) dbrow[7]); else _rec->refWznmMTablecol = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQChkList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQChkList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQChkList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQChkList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQChkList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQChkList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixVBasetype = atol((char*) dbrow[5]); else rec->ixVBasetype = 0;
			if (dbrow[6]) rec->refWznmMTable = atoll((char*) dbrow[6]); else rec->refWznmMTable = 0;
			if (dbrow[7]) rec->refWznmMTablecol = atoll((char*) dbrow[7]); else rec->refWznmMTablecol = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQChkList::insertRec(
			WznmQChkList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMTable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMTablecol,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQChkList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQChkList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQChkList::insertRst(
			ListWznmQChkList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQChkList::updateRec(
			WznmQChkList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMTable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMTablecol,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQChkList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQChkList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQChkList::updateRst(
			ListWznmQChkList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQChkList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQChkList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQChkList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQChkList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQChkList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQChkList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQChkList::loadRecByQref(
			ubigint qref
			, WznmQChkList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQChkList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQChkList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQChkList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQChkList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQChkList
 ******************************************************************************/

PgTblWznmQChkList::PgTblWznmQChkList() :
			TblWznmQChkList()
			, PgTable()
		{
};

PgTblWznmQChkList::~PgTblWznmQChkList() {
};

void PgTblWznmQChkList::initStatements() {
	createStatement("TblWznmQChkList_insertRec", "INSERT INTO TblWznmQChkList (jref, jnum, ref, sref, ixVBasetype, refWznmMTable, refWznmMTablecol) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWznmQChkList_updateRec", "UPDATE TblWznmQChkList SET jref = $1, jnum = $2, ref = $3, sref = $4, ixVBasetype = $5, refWznmMTable = $6, refWznmMTablecol = $7 WHERE qref = $8", 8);
	createStatement("TblWznmQChkList_removeRecByQref", "DELETE FROM TblWznmQChkList WHERE qref = $1", 1);
	createStatement("TblWznmQChkList_removeRstByJref", "DELETE FROM TblWznmQChkList WHERE jref = $1", 1);

	createStatement("TblWznmQChkList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, refWznmMTable, refWznmMTablecol FROM TblWznmQChkList WHERE qref = $1", 1);
	createStatement("TblWznmQChkList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, refWznmMTable, refWznmMTablecol FROM TblWznmQChkList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQChkList::loadRec(
			PGresult* res
			, WznmQChkList** rec
		) {
	char* ptr;

	WznmQChkList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQChkList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "refwznmmtablecol")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMTable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMTablecol = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQChkList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQChkList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQChkList* rec;

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
			PQfnumber(res, "refwznmmtable"),
			PQfnumber(res, "refwznmmtablecol")
		};

		while (numread < numrow) {
			rec = new WznmQChkList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMTable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMTablecol = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQChkList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQChkList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQChkList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQChkList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQChkList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQChkList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQChkList::loadRecBySQL(
			const string& sqlstr
			, WznmQChkList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQChkList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQChkList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQChkList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQChkList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQChkList::insertRec(
			WznmQChkList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refWznmMTable,
		(char*) &_refWznmMTablecol
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQChkList_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQChkList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQChkList::insertRst(
			ListWznmQChkList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQChkList::updateRec(
			WznmQChkList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _refWznmMTablecol = htonl64(rec->refWznmMTablecol);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refWznmMTable,
		(char*) &_refWznmMTablecol,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQChkList_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQChkList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQChkList::updateRst(
			ListWznmQChkList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQChkList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQChkList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQChkList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQChkList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQChkList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQChkList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQChkList::loadRecByQref(
			ubigint qref
			, WznmQChkList** rec
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

	return loadRecByStmt("TblWznmQChkList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQChkList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQChkList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQChkList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

