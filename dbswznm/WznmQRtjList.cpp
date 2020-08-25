/**
	* \file WznmQRtjList.cpp
	* Dbs and XML wrapper for table TblWznmQRtjList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmQRtjList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQRtjList
 ******************************************************************************/

WznmQRtjList::WznmQRtjList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMApp
			, const string stubRefWznmMApp
			, const ubigint supRefWznmMRtjob
			, const string stubSupRefWznmMRtjob
			, const ubigint refWznmMJob
			, const string stubRefWznmMJob
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->refWznmMApp = refWznmMApp;
	this->stubRefWznmMApp = stubRefWznmMApp;
	this->supRefWznmMRtjob = supRefWznmMRtjob;
	this->stubSupRefWznmMRtjob = stubSupRefWznmMRtjob;
	this->refWznmMJob = refWznmMJob;
	this->stubRefWznmMJob = stubRefWznmMJob;
};

void WznmQRtjList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQRtjList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "app", stubRefWznmMApp);
		writeString(wr, "sup", stubSupRefWznmMRtjob);
		writeString(wr, "job", stubRefWznmMJob);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefWznmMApp", stubRefWznmMApp);
		writeString(wr, "stubSupRefWznmMRtjob", stubSupRefWznmMRtjob);
		writeString(wr, "stubRefWznmMJob", stubRefWznmMJob);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQRtjList
 ******************************************************************************/

ListWznmQRtjList::ListWznmQRtjList() {
};

ListWznmQRtjList::ListWznmQRtjList(
			const ListWznmQRtjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQRtjList(*(src.nodes[i]));
};

ListWznmQRtjList::~ListWznmQRtjList() {
	clear();
};

void ListWznmQRtjList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQRtjList::size() const {
	return(nodes.size());
};

void ListWznmQRtjList::append(
			WznmQRtjList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQRtjList& ListWznmQRtjList::operator=(
			const ListWznmQRtjList& src
		) {
	WznmQRtjList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQRtjList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQRtjList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQRtjList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQRtjList
 ******************************************************************************/

TblWznmQRtjList::TblWznmQRtjList() {
};

TblWznmQRtjList::~TblWznmQRtjList() {
};

bool TblWznmQRtjList::loadRecBySQL(
			const string& sqlstr
			, WznmQRtjList** rec
		) {
	return false;
};

ubigint TblWznmQRtjList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRtjList& rst
		) {
	return 0;
};

ubigint TblWznmQRtjList::insertRec(
			WznmQRtjList* rec
		) {
	return 0;
};

ubigint TblWznmQRtjList::insertNewRec(
			WznmQRtjList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMApp
			, const string stubRefWznmMApp
			, const ubigint supRefWznmMRtjob
			, const string stubSupRefWznmMRtjob
			, const ubigint refWznmMJob
			, const string stubRefWznmMJob
		) {
	ubigint retval = 0;
	WznmQRtjList* _rec = NULL;

	_rec = new WznmQRtjList(0, jref, jnum, ref, sref, refWznmMApp, stubRefWznmMApp, supRefWznmMRtjob, stubSupRefWznmMRtjob, refWznmMJob, stubRefWznmMJob);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQRtjList::appendNewRecToRst(
			ListWznmQRtjList& rst
			, WznmQRtjList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWznmMApp
			, const string stubRefWznmMApp
			, const ubigint supRefWznmMRtjob
			, const string stubSupRefWznmMRtjob
			, const ubigint refWznmMJob
			, const string stubRefWznmMJob
		) {
	ubigint retval = 0;
	WznmQRtjList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, refWznmMApp, stubRefWznmMApp, supRefWznmMRtjob, stubSupRefWznmMRtjob, refWznmMJob, stubRefWznmMJob);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQRtjList::insertRst(
			ListWznmQRtjList& rst
		) {
};

void TblWznmQRtjList::updateRec(
			WznmQRtjList* rec
		) {
};

void TblWznmQRtjList::updateRst(
			ListWznmQRtjList& rst
		) {
};

void TblWznmQRtjList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQRtjList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQRtjList::loadRecByQref(
			ubigint qref
			, WznmQRtjList** rec
		) {
	return false;
};

ubigint TblWznmQRtjList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRtjList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQRtjList
 ******************************************************************************/

MyTblWznmQRtjList::MyTblWznmQRtjList() :
			TblWznmQRtjList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQRtjList::~MyTblWznmQRtjList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQRtjList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQRtjList (jref, jnum, ref, sref, refWznmMApp, supRefWznmMRtjob, refWznmMJob) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQRtjList SET jref = ?, jnum = ?, ref = ?, sref = ?, refWznmMApp = ?, supRefWznmMRtjob = ?, refWznmMJob = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQRtjList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQRtjList WHERE jref = ?", false);
};

bool MyTblWznmQRtjList::loadRecBySQL(
			const string& sqlstr
			, WznmQRtjList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQRtjList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQRtjList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQRtjList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQRtjList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->refWznmMApp = atoll((char*) dbrow[5]); else _rec->refWznmMApp = 0;
		if (dbrow[6]) _rec->supRefWznmMRtjob = atoll((char*) dbrow[6]); else _rec->supRefWznmMRtjob = 0;
		if (dbrow[7]) _rec->refWznmMJob = atoll((char*) dbrow[7]); else _rec->refWznmMJob = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQRtjList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRtjList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQRtjList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQRtjList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQRtjList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQRtjList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->refWznmMApp = atoll((char*) dbrow[5]); else rec->refWznmMApp = 0;
			if (dbrow[6]) rec->supRefWznmMRtjob = atoll((char*) dbrow[6]); else rec->supRefWznmMRtjob = 0;
			if (dbrow[7]) rec->refWznmMJob = atoll((char*) dbrow[7]); else rec->refWznmMJob = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQRtjList::insertRec(
			WznmQRtjList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMApp,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefWznmMRtjob,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMJob,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQRtjList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQRtjList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQRtjList::insertRst(
			ListWznmQRtjList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQRtjList::updateRec(
			WznmQRtjList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMApp,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefWznmMRtjob,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMJob,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQRtjList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQRtjList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQRtjList::updateRst(
			ListWznmQRtjList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQRtjList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQRtjList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQRtjList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQRtjList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQRtjList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQRtjList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQRtjList::loadRecByQref(
			ubigint qref
			, WznmQRtjList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQRtjList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQRtjList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRtjList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQRtjList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQRtjList
 ******************************************************************************/

PgTblWznmQRtjList::PgTblWznmQRtjList() :
			TblWznmQRtjList()
			, PgTable()
		{
};

PgTblWznmQRtjList::~PgTblWznmQRtjList() {
};

void PgTblWznmQRtjList::initStatements() {
	createStatement("TblWznmQRtjList_insertRec", "INSERT INTO TblWznmQRtjList (jref, jnum, ref, sref, refWznmMApp, supRefWznmMRtjob, refWznmMJob) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWznmQRtjList_updateRec", "UPDATE TblWznmQRtjList SET jref = $1, jnum = $2, ref = $3, sref = $4, refWznmMApp = $5, supRefWznmMRtjob = $6, refWznmMJob = $7 WHERE qref = $8", 8);
	createStatement("TblWznmQRtjList_removeRecByQref", "DELETE FROM TblWznmQRtjList WHERE qref = $1", 1);
	createStatement("TblWznmQRtjList_removeRstByJref", "DELETE FROM TblWznmQRtjList WHERE jref = $1", 1);

	createStatement("TblWznmQRtjList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, refWznmMApp, supRefWznmMRtjob, refWznmMJob FROM TblWznmQRtjList WHERE qref = $1", 1);
	createStatement("TblWznmQRtjList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, refWznmMApp, supRefWznmMRtjob, refWznmMJob FROM TblWznmQRtjList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQRtjList::loadRec(
			PGresult* res
			, WznmQRtjList** rec
		) {
	char* ptr;

	WznmQRtjList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQRtjList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwznmmapp"),
			PQfnumber(res, "suprefwznmmrtjob"),
			PQfnumber(res, "refwznmmjob")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMApp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->supRefWznmMRtjob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMJob = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQRtjList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQRtjList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQRtjList* rec;

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
			PQfnumber(res, "refwznmmapp"),
			PQfnumber(res, "suprefwznmmrtjob"),
			PQfnumber(res, "refwznmmjob")
		};

		while (numread < numrow) {
			rec = new WznmQRtjList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMApp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->supRefWznmMRtjob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMJob = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQRtjList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQRtjList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRtjList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQRtjList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQRtjList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRtjList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQRtjList::loadRecBySQL(
			const string& sqlstr
			, WznmQRtjList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQRtjList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQRtjList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQRtjList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQRtjList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQRtjList::insertRec(
			WznmQRtjList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMApp = htonl64(rec->refWznmMApp);
	ubigint _supRefWznmMRtjob = htonl64(rec->supRefWznmMRtjob);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refWznmMApp,
		(char*) &_supRefWznmMRtjob,
		(char*) &_refWznmMJob
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

	res = PQexecPrepared(dbs, "TblWznmQRtjList_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQRtjList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQRtjList::insertRst(
			ListWznmQRtjList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQRtjList::updateRec(
			WznmQRtjList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWznmMApp = htonl64(rec->refWznmMApp);
	ubigint _supRefWznmMRtjob = htonl64(rec->supRefWznmMRtjob);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refWznmMApp,
		(char*) &_supRefWznmMRtjob,
		(char*) &_refWznmMJob,
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

	res = PQexecPrepared(dbs, "TblWznmQRtjList_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRtjList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQRtjList::updateRst(
			ListWznmQRtjList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQRtjList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQRtjList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRtjList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQRtjList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQRtjList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQRtjList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQRtjList::loadRecByQref(
			ubigint qref
			, WznmQRtjList** rec
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

	return loadRecByStmt("TblWznmQRtjList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQRtjList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQRtjList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQRtjList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

