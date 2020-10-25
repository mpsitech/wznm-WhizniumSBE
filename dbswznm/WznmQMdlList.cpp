/**
	* \file WznmQMdlList.cpp
	* Dbs and XML wrapper for table TblWznmQMdlList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQMdlList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQMdlList
 ******************************************************************************/

WznmQMdlList::WznmQMdlList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint verRefWznmMVersion
			, const string stubVerRefWznmMVersion
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->verRefWznmMVersion = verRefWznmMVersion;
	this->stubVerRefWznmMVersion = stubVerRefWznmMVersion;
};

void WznmQMdlList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQMdlList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "ver", stubVerRefWznmMVersion);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "stubVerRefWznmMVersion", stubVerRefWznmMVersion);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQMdlList
 ******************************************************************************/

ListWznmQMdlList::ListWznmQMdlList() {
};

ListWznmQMdlList::ListWznmQMdlList(
			const ListWznmQMdlList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQMdlList(*(src.nodes[i]));
};

ListWznmQMdlList::~ListWznmQMdlList() {
	clear();
};

void ListWznmQMdlList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQMdlList::size() const {
	return(nodes.size());
};

void ListWznmQMdlList::append(
			WznmQMdlList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQMdlList& ListWznmQMdlList::operator=(
			const ListWznmQMdlList& src
		) {
	WznmQMdlList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQMdlList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQMdlList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQMdlList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQMdlList
 ******************************************************************************/

TblWznmQMdlList::TblWznmQMdlList() {
};

TblWznmQMdlList::~TblWznmQMdlList() {
};

bool TblWznmQMdlList::loadRecBySQL(
			const string& sqlstr
			, WznmQMdlList** rec
		) {
	return false;
};

ubigint TblWznmQMdlList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQMdlList& rst
		) {
	return 0;
};

ubigint TblWznmQMdlList::insertRec(
			WznmQMdlList* rec
		) {
	return 0;
};

ubigint TblWznmQMdlList::insertNewRec(
			WznmQMdlList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint verRefWznmMVersion
			, const string stubVerRefWznmMVersion
		) {
	ubigint retval = 0;
	WznmQMdlList* _rec = NULL;

	_rec = new WznmQMdlList(0, jref, jnum, ref, sref, Title, verRefWznmMVersion, stubVerRefWznmMVersion);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQMdlList::appendNewRecToRst(
			ListWznmQMdlList& rst
			, WznmQMdlList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint verRefWznmMVersion
			, const string stubVerRefWznmMVersion
		) {
	ubigint retval = 0;
	WznmQMdlList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Title, verRefWznmMVersion, stubVerRefWznmMVersion);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQMdlList::insertRst(
			ListWznmQMdlList& rst
		) {
};

void TblWznmQMdlList::updateRec(
			WznmQMdlList* rec
		) {
};

void TblWznmQMdlList::updateRst(
			ListWznmQMdlList& rst
		) {
};

void TblWznmQMdlList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQMdlList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQMdlList::loadRecByQref(
			ubigint qref
			, WznmQMdlList** rec
		) {
	return false;
};

ubigint TblWznmQMdlList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQMdlList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQMdlList
 ******************************************************************************/

MyTblWznmQMdlList::MyTblWznmQMdlList() :
			TblWznmQMdlList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQMdlList::~MyTblWznmQMdlList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQMdlList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQMdlList (jref, jnum, ref, sref, Title, verRefWznmMVersion) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQMdlList SET jref = ?, jnum = ?, ref = ?, sref = ?, Title = ?, verRefWznmMVersion = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQMdlList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQMdlList WHERE jref = ?", false);
};

bool MyTblWznmQMdlList::loadRecBySQL(
			const string& sqlstr
			, WznmQMdlList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQMdlList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQMdlList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQMdlList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQMdlList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->verRefWznmMVersion = atoll((char*) dbrow[6]); else _rec->verRefWznmMVersion = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQMdlList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQMdlList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQMdlList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQMdlList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQMdlList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQMdlList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->verRefWznmMVersion = atoll((char*) dbrow[6]); else rec->verRefWznmMVersion = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQMdlList::insertRec(
			WznmQMdlList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->verRefWznmMVersion,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQMdlList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQMdlList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQMdlList::insertRst(
			ListWznmQMdlList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQMdlList::updateRec(
			WznmQMdlList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->verRefWznmMVersion,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQMdlList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQMdlList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQMdlList::updateRst(
			ListWznmQMdlList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQMdlList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQMdlList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQMdlList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQMdlList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQMdlList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQMdlList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQMdlList::loadRecByQref(
			ubigint qref
			, WznmQMdlList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQMdlList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQMdlList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQMdlList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQMdlList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQMdlList
 ******************************************************************************/

PgTblWznmQMdlList::PgTblWznmQMdlList() :
			TblWznmQMdlList()
			, PgTable()
		{
};

PgTblWznmQMdlList::~PgTblWznmQMdlList() {
};

void PgTblWznmQMdlList::initStatements() {
	createStatement("TblWznmQMdlList_insertRec", "INSERT INTO TblWznmQMdlList (jref, jnum, ref, sref, Title, verRefWznmMVersion) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQMdlList_updateRec", "UPDATE TblWznmQMdlList SET jref = $1, jnum = $2, ref = $3, sref = $4, Title = $5, verRefWznmMVersion = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQMdlList_removeRecByQref", "DELETE FROM TblWznmQMdlList WHERE qref = $1", 1);
	createStatement("TblWznmQMdlList_removeRstByJref", "DELETE FROM TblWznmQMdlList WHERE jref = $1", 1);

	createStatement("TblWznmQMdlList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Title, verRefWznmMVersion FROM TblWznmQMdlList WHERE qref = $1", 1);
	createStatement("TblWznmQMdlList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Title, verRefWznmMVersion FROM TblWznmQMdlList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQMdlList::loadRec(
			PGresult* res
			, WznmQMdlList** rec
		) {
	char* ptr;

	WznmQMdlList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQMdlList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "verrefwznmmversion")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->verRefWznmMVersion = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQMdlList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQMdlList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQMdlList* rec;

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
			PQfnumber(res, "title"),
			PQfnumber(res, "verrefwznmmversion")
		};

		while (numread < numrow) {
			rec = new WznmQMdlList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->verRefWznmMVersion = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQMdlList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQMdlList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQMdlList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQMdlList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQMdlList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQMdlList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQMdlList::loadRecBySQL(
			const string& sqlstr
			, WznmQMdlList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQMdlList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQMdlList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQMdlList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQMdlList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQMdlList::insertRec(
			WznmQMdlList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _verRefWznmMVersion = htonl64(rec->verRefWznmMVersion);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_verRefWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQMdlList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQMdlList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQMdlList::insertRst(
			ListWznmQMdlList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQMdlList::updateRec(
			WznmQMdlList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _verRefWznmMVersion = htonl64(rec->verRefWznmMVersion);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_verRefWznmMVersion,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQMdlList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQMdlList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQMdlList::updateRst(
			ListWznmQMdlList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQMdlList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQMdlList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQMdlList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQMdlList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQMdlList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQMdlList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQMdlList::loadRecByQref(
			ubigint qref
			, WznmQMdlList** rec
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

	return loadRecByStmt("TblWznmQMdlList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQMdlList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQMdlList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQMdlList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

