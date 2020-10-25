/**
	* \file WznmQImeList.cpp
	* Dbs and XML wrapper for table TblWznmQImeList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQImeList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQImeList
 ******************************************************************************/

WznmQImeList::WznmQImeList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMImpexpcplx
			, const string stubRefWznmMImpexpcplx
			, const ubigint supRefWznmMImpexp
			, const string stubSupRefWznmMImpexp
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->refWznmMImpexpcplx = refWznmMImpexpcplx;
	this->stubRefWznmMImpexpcplx = stubRefWznmMImpexpcplx;
	this->supRefWznmMImpexp = supRefWznmMImpexp;
	this->stubSupRefWznmMImpexp = stubSupRefWznmMImpexp;
	this->refWznmMTable = refWznmMTable;
	this->stubRefWznmMTable = stubRefWznmMTable;
};

void WznmQImeList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQImeList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "iex", stubRefWznmMImpexpcplx);
		writeString(wr, "sup", stubSupRefWznmMImpexp);
		writeString(wr, "tbl", stubRefWznmMTable);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefWznmMImpexpcplx", stubRefWznmMImpexpcplx);
		writeString(wr, "stubSupRefWznmMImpexp", stubSupRefWznmMImpexp);
		writeString(wr, "stubRefWznmMTable", stubRefWznmMTable);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQImeList
 ******************************************************************************/

ListWznmQImeList::ListWznmQImeList() {
};

ListWznmQImeList::ListWznmQImeList(
			const ListWznmQImeList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQImeList(*(src.nodes[i]));
};

ListWznmQImeList::~ListWznmQImeList() {
	clear();
};

void ListWznmQImeList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQImeList::size() const {
	return(nodes.size());
};

void ListWznmQImeList::append(
			WznmQImeList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQImeList& ListWznmQImeList::operator=(
			const ListWznmQImeList& src
		) {
	WznmQImeList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQImeList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQImeList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQImeList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQImeList
 ******************************************************************************/

TblWznmQImeList::TblWznmQImeList() {
};

TblWznmQImeList::~TblWznmQImeList() {
};

bool TblWznmQImeList::loadRecBySQL(
			const string& sqlstr
			, WznmQImeList** rec
		) {
	return false;
};

ubigint TblWznmQImeList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQImeList& rst
		) {
	return 0;
};

ubigint TblWznmQImeList::insertRec(
			WznmQImeList* rec
		) {
	return 0;
};

ubigint TblWznmQImeList::insertNewRec(
			WznmQImeList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMImpexpcplx
			, const string stubRefWznmMImpexpcplx
			, const ubigint supRefWznmMImpexp
			, const string stubSupRefWznmMImpexp
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
		) {
	ubigint retval = 0;
	WznmQImeList* _rec = NULL;

	_rec = new WznmQImeList(0, jref, jnum, ref, sref, refWznmMImpexpcplx, stubRefWznmMImpexpcplx, supRefWznmMImpexp, stubSupRefWznmMImpexp, refWznmMTable, stubRefWznmMTable);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQImeList::appendNewRecToRst(
			ListWznmQImeList& rst
			, WznmQImeList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMImpexpcplx
			, const string stubRefWznmMImpexpcplx
			, const ubigint supRefWznmMImpexp
			, const string stubSupRefWznmMImpexp
			, const ubigint refWznmMTable
			, const string stubRefWznmMTable
		) {
	ubigint retval = 0;
	WznmQImeList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, refWznmMImpexpcplx, stubRefWznmMImpexpcplx, supRefWznmMImpexp, stubSupRefWznmMImpexp, refWznmMTable, stubRefWznmMTable);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQImeList::insertRst(
			ListWznmQImeList& rst
		) {
};

void TblWznmQImeList::updateRec(
			WznmQImeList* rec
		) {
};

void TblWznmQImeList::updateRst(
			ListWznmQImeList& rst
		) {
};

void TblWznmQImeList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQImeList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQImeList::loadRecByQref(
			ubigint qref
			, WznmQImeList** rec
		) {
	return false;
};

ubigint TblWznmQImeList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQImeList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQImeList
 ******************************************************************************/

MyTblWznmQImeList::MyTblWznmQImeList() :
			TblWznmQImeList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQImeList::~MyTblWznmQImeList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQImeList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQImeList (jref, jnum, ref, sref, refWznmMImpexpcplx, supRefWznmMImpexp, refWznmMTable) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQImeList SET jref = ?, jnum = ?, ref = ?, sref = ?, refWznmMImpexpcplx = ?, supRefWznmMImpexp = ?, refWznmMTable = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQImeList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQImeList WHERE jref = ?", false);
};

bool MyTblWznmQImeList::loadRecBySQL(
			const string& sqlstr
			, WznmQImeList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQImeList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQImeList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQImeList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQImeList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->refWznmMImpexpcplx = atoll((char*) dbrow[5]); else _rec->refWznmMImpexpcplx = 0;
		if (dbrow[6]) _rec->supRefWznmMImpexp = atoll((char*) dbrow[6]); else _rec->supRefWznmMImpexp = 0;
		if (dbrow[7]) _rec->refWznmMTable = atoll((char*) dbrow[7]); else _rec->refWznmMTable = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQImeList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQImeList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQImeList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQImeList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQImeList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQImeList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->refWznmMImpexpcplx = atoll((char*) dbrow[5]); else rec->refWznmMImpexpcplx = 0;
			if (dbrow[6]) rec->supRefWznmMImpexp = atoll((char*) dbrow[6]); else rec->supRefWznmMImpexp = 0;
			if (dbrow[7]) rec->refWznmMTable = atoll((char*) dbrow[7]); else rec->refWznmMTable = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQImeList::insertRec(
			WznmQImeList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMImpexpcplx,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefWznmMImpexp,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMTable,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQImeList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQImeList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQImeList::insertRst(
			ListWznmQImeList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQImeList::updateRec(
			WznmQImeList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMImpexpcplx,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefWznmMImpexp,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMTable,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQImeList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQImeList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQImeList::updateRst(
			ListWznmQImeList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQImeList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQImeList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQImeList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQImeList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQImeList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQImeList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQImeList::loadRecByQref(
			ubigint qref
			, WznmQImeList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQImeList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQImeList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQImeList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQImeList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQImeList
 ******************************************************************************/

PgTblWznmQImeList::PgTblWznmQImeList() :
			TblWznmQImeList()
			, PgTable()
		{
};

PgTblWznmQImeList::~PgTblWznmQImeList() {
};

void PgTblWznmQImeList::initStatements() {
	createStatement("TblWznmQImeList_insertRec", "INSERT INTO TblWznmQImeList (jref, jnum, ref, sref, refWznmMImpexpcplx, supRefWznmMImpexp, refWznmMTable) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWznmQImeList_updateRec", "UPDATE TblWznmQImeList SET jref = $1, jnum = $2, ref = $3, sref = $4, refWznmMImpexpcplx = $5, supRefWznmMImpexp = $6, refWznmMTable = $7 WHERE qref = $8", 8);
	createStatement("TblWznmQImeList_removeRecByQref", "DELETE FROM TblWznmQImeList WHERE qref = $1", 1);
	createStatement("TblWznmQImeList_removeRstByJref", "DELETE FROM TblWznmQImeList WHERE jref = $1", 1);

	createStatement("TblWznmQImeList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, refWznmMImpexpcplx, supRefWznmMImpexp, refWznmMTable FROM TblWznmQImeList WHERE qref = $1", 1);
	createStatement("TblWznmQImeList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, refWznmMImpexpcplx, supRefWznmMImpexp, refWznmMTable FROM TblWznmQImeList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQImeList::loadRec(
			PGresult* res
			, WznmQImeList** rec
		) {
	char* ptr;

	WznmQImeList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQImeList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwznmmimpexpcplx"),
			PQfnumber(res, "suprefwznmmimpexp"),
			PQfnumber(res, "refwznmmtable")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMImpexpcplx = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->supRefWznmMImpexp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMTable = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQImeList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQImeList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQImeList* rec;

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
			PQfnumber(res, "refwznmmimpexpcplx"),
			PQfnumber(res, "suprefwznmmimpexp"),
			PQfnumber(res, "refwznmmtable")
		};

		while (numread < numrow) {
			rec = new WznmQImeList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMImpexpcplx = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->supRefWznmMImpexp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMTable = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQImeList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQImeList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQImeList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQImeList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQImeList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQImeList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQImeList::loadRecBySQL(
			const string& sqlstr
			, WznmQImeList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQImeList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQImeList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQImeList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQImeList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQImeList::insertRec(
			WznmQImeList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMImpexpcplx = htonl64(rec->refWznmMImpexpcplx);
	ubigint _supRefWznmMImpexp = htonl64(rec->supRefWznmMImpexp);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refWznmMImpexpcplx,
		(char*) &_supRefWznmMImpexp,
		(char*) &_refWznmMTable
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQImeList_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQImeList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQImeList::insertRst(
			ListWznmQImeList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQImeList::updateRec(
			WznmQImeList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMImpexpcplx = htonl64(rec->refWznmMImpexpcplx);
	ubigint _supRefWznmMImpexp = htonl64(rec->supRefWznmMImpexp);
	ubigint _refWznmMTable = htonl64(rec->refWznmMTable);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refWznmMImpexpcplx,
		(char*) &_supRefWznmMImpexp,
		(char*) &_refWznmMTable,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQImeList_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQImeList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQImeList::updateRst(
			ListWznmQImeList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQImeList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQImeList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQImeList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQImeList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQImeList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQImeList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQImeList::loadRecByQref(
			ubigint qref
			, WznmQImeList** rec
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

	return loadRecByStmt("TblWznmQImeList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQImeList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQImeList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQImeList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

