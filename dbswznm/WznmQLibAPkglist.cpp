/**
	* \file WznmQLibAPkglist.cpp
	* Dbs and XML wrapper for table TblWznmQLibAPkglist (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQLibAPkglist.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQLibAPkglist
 ******************************************************************************/

WznmQLibAPkglist::WznmQLibAPkglist(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1RefIxVTbl
			, const string srefX1RefIxVTbl
			, const string titX1RefIxVTbl
			, const ubigint x1RefUref
			, const string stubX1RefUref
			, const string Pkglist
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1RefIxVTbl = x1RefIxVTbl;
	this->srefX1RefIxVTbl = srefX1RefIxVTbl;
	this->titX1RefIxVTbl = titX1RefIxVTbl;
	this->x1RefUref = x1RefUref;
	this->stubX1RefUref = stubX1RefUref;
	this->Pkglist = Pkglist;
};

void WznmQLibAPkglist::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQLibAPkglist";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ret", srefX1RefIxVTbl);
		writeString(wr, "ret2", titX1RefIxVTbl);
		writeString(wr, "reu", stubX1RefUref);
		writeString(wr, "pkl", Pkglist);
	} else {
		writeString(wr, "srefX1RefIxVTbl", srefX1RefIxVTbl);
		writeString(wr, "titX1RefIxVTbl", titX1RefIxVTbl);
		writeString(wr, "stubX1RefUref", stubX1RefUref);
		writeString(wr, "Pkglist", Pkglist);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQLibAPkglist
 ******************************************************************************/

ListWznmQLibAPkglist::ListWznmQLibAPkglist() {
};

ListWznmQLibAPkglist::ListWznmQLibAPkglist(
			const ListWznmQLibAPkglist& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQLibAPkglist(*(src.nodes[i]));
};

ListWznmQLibAPkglist::~ListWznmQLibAPkglist() {
	clear();
};

void ListWznmQLibAPkglist::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQLibAPkglist::size() const {
	return(nodes.size());
};

void ListWznmQLibAPkglist::append(
			WznmQLibAPkglist* rec
		) {
	nodes.push_back(rec);
};

ListWznmQLibAPkglist& ListWznmQLibAPkglist::operator=(
			const ListWznmQLibAPkglist& src
		) {
	WznmQLibAPkglist* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQLibAPkglist(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQLibAPkglist::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQLibAPkglist";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQLibAPkglist
 ******************************************************************************/

TblWznmQLibAPkglist::TblWznmQLibAPkglist() {
};

TblWznmQLibAPkglist::~TblWznmQLibAPkglist() {
};

bool TblWznmQLibAPkglist::loadRecBySQL(
			const string& sqlstr
			, WznmQLibAPkglist** rec
		) {
	return false;
};

ubigint TblWznmQLibAPkglist::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQLibAPkglist& rst
		) {
	return 0;
};

ubigint TblWznmQLibAPkglist::insertRec(
			WznmQLibAPkglist* rec
		) {
	return 0;
};

ubigint TblWznmQLibAPkglist::insertNewRec(
			WznmQLibAPkglist** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1RefIxVTbl
			, const string srefX1RefIxVTbl
			, const string titX1RefIxVTbl
			, const ubigint x1RefUref
			, const string stubX1RefUref
			, const string Pkglist
		) {
	ubigint retval = 0;
	WznmQLibAPkglist* _rec = NULL;

	_rec = new WznmQLibAPkglist(0, jref, jnum, ref, x1RefIxVTbl, srefX1RefIxVTbl, titX1RefIxVTbl, x1RefUref, stubX1RefUref, Pkglist);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQLibAPkglist::appendNewRecToRst(
			ListWznmQLibAPkglist& rst
			, WznmQLibAPkglist** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1RefIxVTbl
			, const string srefX1RefIxVTbl
			, const string titX1RefIxVTbl
			, const ubigint x1RefUref
			, const string stubX1RefUref
			, const string Pkglist
		) {
	ubigint retval = 0;
	WznmQLibAPkglist* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1RefIxVTbl, srefX1RefIxVTbl, titX1RefIxVTbl, x1RefUref, stubX1RefUref, Pkglist);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQLibAPkglist::insertRst(
			ListWznmQLibAPkglist& rst
		) {
};

void TblWznmQLibAPkglist::updateRec(
			WznmQLibAPkglist* rec
		) {
};

void TblWznmQLibAPkglist::updateRst(
			ListWznmQLibAPkglist& rst
		) {
};

void TblWznmQLibAPkglist::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQLibAPkglist::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQLibAPkglist::loadRecByQref(
			ubigint qref
			, WznmQLibAPkglist** rec
		) {
	return false;
};

ubigint TblWznmQLibAPkglist::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQLibAPkglist& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQLibAPkglist
 ******************************************************************************/

MyTblWznmQLibAPkglist::MyTblWznmQLibAPkglist() :
			TblWznmQLibAPkglist()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQLibAPkglist::~MyTblWznmQLibAPkglist() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQLibAPkglist::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQLibAPkglist (jref, jnum, ref, x1RefIxVTbl, x1RefUref, Pkglist) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQLibAPkglist SET jref = ?, jnum = ?, ref = ?, x1RefIxVTbl = ?, x1RefUref = ?, Pkglist = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQLibAPkglist WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQLibAPkglist WHERE jref = ?", false);
};

bool MyTblWznmQLibAPkglist::loadRecBySQL(
			const string& sqlstr
			, WznmQLibAPkglist** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQLibAPkglist* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQLibAPkglist::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQLibAPkglist::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQLibAPkglist();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1RefIxVTbl = atol((char*) dbrow[4]); else _rec->x1RefIxVTbl = 0;
		if (dbrow[5]) _rec->x1RefUref = atoll((char*) dbrow[5]); else _rec->x1RefUref = 0;
		if (dbrow[6]) _rec->Pkglist.assign(dbrow[6], dblengths[6]); else _rec->Pkglist = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQLibAPkglist::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQLibAPkglist& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQLibAPkglist* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQLibAPkglist::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQLibAPkglist::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQLibAPkglist();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1RefIxVTbl = atol((char*) dbrow[4]); else rec->x1RefIxVTbl = 0;
			if (dbrow[5]) rec->x1RefUref = atoll((char*) dbrow[5]); else rec->x1RefUref = 0;
			if (dbrow[6]) rec->Pkglist.assign(dbrow[6], dblengths[6]); else rec->Pkglist = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQLibAPkglist::insertRec(
			WznmQLibAPkglist* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[5] = rec->Pkglist.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1RefIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x1RefUref,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Pkglist.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQLibAPkglist::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQLibAPkglist::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQLibAPkglist::insertRst(
			ListWznmQLibAPkglist& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQLibAPkglist::updateRec(
			WznmQLibAPkglist* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[5] = rec->Pkglist.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1RefIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x1RefUref,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Pkglist.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQLibAPkglist::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQLibAPkglist::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQLibAPkglist::updateRst(
			ListWznmQLibAPkglist& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQLibAPkglist::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQLibAPkglist::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQLibAPkglist::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQLibAPkglist::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQLibAPkglist::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQLibAPkglist::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQLibAPkglist::loadRecByQref(
			ubigint qref
			, WznmQLibAPkglist** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQLibAPkglist WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQLibAPkglist::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQLibAPkglist& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQLibAPkglist WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQLibAPkglist
 ******************************************************************************/

PgTblWznmQLibAPkglist::PgTblWznmQLibAPkglist() :
			TblWznmQLibAPkglist()
			, PgTable()
		{
};

PgTblWznmQLibAPkglist::~PgTblWznmQLibAPkglist() {
};

void PgTblWznmQLibAPkglist::initStatements() {
	createStatement("TblWznmQLibAPkglist_insertRec", "INSERT INTO TblWznmQLibAPkglist (jref, jnum, ref, x1RefIxVTbl, x1RefUref, Pkglist) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWznmQLibAPkglist_updateRec", "UPDATE TblWznmQLibAPkglist SET jref = $1, jnum = $2, ref = $3, x1RefIxVTbl = $4, x1RefUref = $5, Pkglist = $6 WHERE qref = $7", 7);
	createStatement("TblWznmQLibAPkglist_removeRecByQref", "DELETE FROM TblWznmQLibAPkglist WHERE qref = $1", 1);
	createStatement("TblWznmQLibAPkglist_removeRstByJref", "DELETE FROM TblWznmQLibAPkglist WHERE jref = $1", 1);

	createStatement("TblWznmQLibAPkglist_loadRecByQref", "SELECT qref, jref, jnum, ref, x1RefIxVTbl, x1RefUref, Pkglist FROM TblWznmQLibAPkglist WHERE qref = $1", 1);
	createStatement("TblWznmQLibAPkglist_loadRstByJref", "SELECT qref, jref, jnum, ref, x1RefIxVTbl, x1RefUref, Pkglist FROM TblWznmQLibAPkglist WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQLibAPkglist::loadRec(
			PGresult* res
			, WznmQLibAPkglist** rec
		) {
	char* ptr;

	WznmQLibAPkglist* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQLibAPkglist();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refixvtbl"),
			PQfnumber(res, "x1refuref"),
			PQfnumber(res, "pkglist")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1RefIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1RefUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Pkglist.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQLibAPkglist::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQLibAPkglist& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQLibAPkglist* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refixvtbl"),
			PQfnumber(res, "x1refuref"),
			PQfnumber(res, "pkglist")
		};

		while (numread < numrow) {
			rec = new WznmQLibAPkglist();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1RefIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1RefUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Pkglist.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQLibAPkglist::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQLibAPkglist** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQLibAPkglist::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQLibAPkglist::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQLibAPkglist& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQLibAPkglist::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQLibAPkglist::loadRecBySQL(
			const string& sqlstr
			, WznmQLibAPkglist** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQLibAPkglist::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQLibAPkglist::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQLibAPkglist& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQLibAPkglist::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQLibAPkglist::insertRec(
			WznmQLibAPkglist* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1RefIxVTbl = htonl(rec->x1RefIxVTbl);
	ubigint _x1RefUref = htonl64(rec->x1RefUref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefIxVTbl,
		(char*) &_x1RefUref,
		rec->Pkglist.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQLibAPkglist_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQLibAPkglist::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQLibAPkglist::insertRst(
			ListWznmQLibAPkglist& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQLibAPkglist::updateRec(
			WznmQLibAPkglist* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1RefIxVTbl = htonl(rec->x1RefIxVTbl);
	ubigint _x1RefUref = htonl64(rec->x1RefUref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefIxVTbl,
		(char*) &_x1RefUref,
		rec->Pkglist.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQLibAPkglist_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQLibAPkglist::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQLibAPkglist::updateRst(
			ListWznmQLibAPkglist& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQLibAPkglist::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQLibAPkglist_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQLibAPkglist::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQLibAPkglist::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQLibAPkglist_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQLibAPkglist::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQLibAPkglist::loadRecByQref(
			ubigint qref
			, WznmQLibAPkglist** rec
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

	return loadRecByStmt("TblWznmQLibAPkglist_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQLibAPkglist::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQLibAPkglist& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQLibAPkglist_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

