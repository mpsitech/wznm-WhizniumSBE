/**
	* \file WznmMOppack.cpp
	* database access for table TblWznmMOppack (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMOppack.h"

#include "WznmMOppack_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMOppack
 ******************************************************************************/

WznmMOppack::WznmMOppack(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const ubigint refWznmMSquawk
			, const string sref
			, const string Title
			, const bool Shrdat
			, const string Comment
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refWznmMVersion = refWznmMVersion;
	this->refWznmMSquawk = refWznmMSquawk;
	this->sref = sref;
	this->Title = Title;
	this->Shrdat = Shrdat;
	this->Comment = Comment;
};

bool WznmMOppack::operator==(
			const WznmMOppack& comp
		) {
	return false;
};

bool WznmMOppack::operator!=(
			const WznmMOppack& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMOppack
 ******************************************************************************/

ListWznmMOppack::ListWznmMOppack() {
};

ListWznmMOppack::ListWznmMOppack(
			const ListWznmMOppack& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMOppack(*(src.nodes[i]));
};

ListWznmMOppack::~ListWznmMOppack() {
	clear();
};

void ListWznmMOppack::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMOppack::size() const {
	return(nodes.size());
};

void ListWznmMOppack::append(
			WznmMOppack* rec
		) {
	nodes.push_back(rec);
};

WznmMOppack* ListWznmMOppack::operator[](
			const uint ix
		) {
	WznmMOppack* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMOppack& ListWznmMOppack::operator=(
			const ListWznmMOppack& src
		) {
	WznmMOppack* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMOppack(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMOppack::operator==(
			const ListWznmMOppack& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i = 0; i < size(); i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListWznmMOppack::operator!=(
			const ListWznmMOppack& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMOppack
 ******************************************************************************/

TblWznmMOppack::TblWznmMOppack() {
};

TblWznmMOppack::~TblWznmMOppack() {
};

bool TblWznmMOppack::loadRecBySQL(
			const string& sqlstr
			, WznmMOppack** rec
		) {
	return false;
};

ubigint TblWznmMOppack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMOppack& rst
		) {
	return 0;
};

ubigint TblWznmMOppack::insertRec(
			WznmMOppack* rec
		) {
	return 0;
};

ubigint TblWznmMOppack::insertNewRec(
			WznmMOppack** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const ubigint refWznmMSquawk
			, const string sref
			, const string Title
			, const bool Shrdat
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMOppack* _rec = NULL;

	_rec = new WznmMOppack(0, ixVBasetype, refWznmMVersion, refWznmMSquawk, sref, Title, Shrdat, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMOppack::appendNewRecToRst(
			ListWznmMOppack& rst
			, WznmMOppack** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const ubigint refWznmMSquawk
			, const string sref
			, const string Title
			, const bool Shrdat
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMOppack* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWznmMVersion, refWznmMSquawk, sref, Title, Shrdat, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMOppack::insertRst(
			ListWznmMOppack& rst
			, bool transact
		) {
};

void TblWznmMOppack::updateRec(
			WznmMOppack* rec
		) {
};

void TblWznmMOppack::updateRst(
			ListWznmMOppack& rst
			, bool transact
		) {
};

void TblWznmMOppack::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMOppack::loadRecByRef(
			ubigint ref
			, WznmMOppack** rec
		) {
	return false;
};

bool TblWznmMOppack::loadRecBySqk(
			ubigint refWznmMSquawk
			, WznmMOppack** rec
		) {
	return false;
};

ubigint TblWznmMOppack::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMOppack& rst
		) {
	return 0;
};

bool TblWznmMOppack::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMOppack::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMOppack& rst
		) {
	ubigint numload = 0;
	WznmMOppack* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMOppack
 ******************************************************************************/

MyTblWznmMOppack::MyTblWznmMOppack() :
			TblWznmMOppack()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMOppack::~MyTblWznmMOppack() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMOppack::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMOppack (ixVBasetype, refWznmMVersion, refWznmMSquawk, sref, Title, Shrdat, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMOppack SET ixVBasetype = ?, refWznmMVersion = ?, refWznmMSquawk = ?, sref = ?, Title = ?, Shrdat = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMOppack WHERE ref = ?", false);
};

bool MyTblWznmMOppack::loadRecBySQL(
			const string& sqlstr
			, WznmMOppack** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMOppack* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMOppack::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMOppack::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMOppack();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWznmMVersion = atoll((char*) dbrow[2]); else _rec->refWznmMVersion = 0;
		if (dbrow[3]) _rec->refWznmMSquawk = atoll((char*) dbrow[3]); else _rec->refWznmMSquawk = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->Shrdat = (atoi((char*) dbrow[6]) != 0); else _rec->Shrdat = false;
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMOppack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMOppack& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMOppack* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMOppack::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMOppack::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMOppack();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWznmMVersion = atoll((char*) dbrow[2]); else rec->refWznmMVersion = 0;
			if (dbrow[3]) rec->refWznmMSquawk = atoll((char*) dbrow[3]); else rec->refWznmMSquawk = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->Shrdat = (atoi((char*) dbrow[6]) != 0); else rec->Shrdat = false;
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMOppack::insertRec(
			WznmMOppack* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();
	tinyint Shrdat = rec->Shrdat;
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMSquawk,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Shrdat,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMOppack::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMOppack::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMOppack::insertRst(
			ListWznmMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMOppack::updateRec(
			WznmMOppack* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();
	tinyint Shrdat = rec->Shrdat;
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMSquawk,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Shrdat,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMOppack::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMOppack::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMOppack::updateRst(
			ListWznmMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMOppack::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMOppack::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMOppack::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMOppack::loadRecByRef(
			ubigint ref
			, WznmMOppack** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMOppack WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMOppack::loadRecBySqk(
			ubigint refWznmMSquawk
			, WznmMOppack** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refWznmMVersion, refWznmMSquawk, sref, Title, Shrdat, Comment FROM TblWznmMOppack WHERE refWznmMSquawk = " + to_string(refWznmMSquawk) + "", rec);
};

ubigint MyTblWznmMOppack::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMOppack& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMVersion, refWznmMSquawk, sref, Title, Shrdat, Comment FROM TblWznmMOppack WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMOppack::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMOppack WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMOppack
 ******************************************************************************/

PgTblWznmMOppack::PgTblWznmMOppack() :
			TblWznmMOppack()
			, PgTable()
		{
};

PgTblWznmMOppack::~PgTblWznmMOppack() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMOppack::initStatements() {
	createStatement("TblWznmMOppack_insertRec", "INSERT INTO TblWznmMOppack (ixVBasetype, refWznmMVersion, refWznmMSquawk, sref, Title, Shrdat, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWznmMOppack_updateRec", "UPDATE TblWznmMOppack SET ixVBasetype = $1, refWznmMVersion = $2, refWznmMSquawk = $3, sref = $4, Title = $5, Shrdat = $6, Comment = $7 WHERE ref = $8", 8);
	createStatement("TblWznmMOppack_removeRecByRef", "DELETE FROM TblWznmMOppack WHERE ref = $1", 1);

	createStatement("TblWznmMOppack_loadRecByRef", "SELECT ref, ixVBasetype, refWznmMVersion, refWznmMSquawk, sref, Title, Shrdat, Comment FROM TblWznmMOppack WHERE ref = $1", 1);
	createStatement("TblWznmMOppack_loadRecBySqk", "SELECT ref, ixVBasetype, refWznmMVersion, refWznmMSquawk, sref, Title, Shrdat, Comment FROM TblWznmMOppack WHERE refWznmMSquawk = $1", 1);
	createStatement("TblWznmMOppack_loadRstByVer", "SELECT ref, ixVBasetype, refWznmMVersion, refWznmMSquawk, sref, Title, Shrdat, Comment FROM TblWznmMOppack WHERE refWznmMVersion = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMOppack_loadSrfByRef", "SELECT sref FROM TblWznmMOppack WHERE ref = $1", 1);
};

bool PgTblWznmMOppack::loadRec(
			PGresult* res
			, WznmMOppack** rec
		) {
	char* ptr;

	WznmMOppack* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMOppack();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refwznmmsquawk"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "shrdat"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWznmMSquawk = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Shrdat = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMOppack::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMOppack& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMOppack* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refwznmmsquawk"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "shrdat"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMOppack();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWznmMSquawk = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Shrdat = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMOppack::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMOppack** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMOppack::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMOppack::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMOppack& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMOppack::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMOppack::loadRecBySQL(
			const string& sqlstr
			, WznmMOppack** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMOppack::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMOppack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMOppack& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMOppack::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMOppack::insertRec(
			WznmMOppack* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _refWznmMSquawk = htonl64(rec->refWznmMSquawk);
	smallint _Shrdat = htons((smallint) rec->Shrdat);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_refWznmMSquawk,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_Shrdat,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMOppack_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMOppack::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMOppack::insertRst(
			ListWznmMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMOppack::updateRec(
			WznmMOppack* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _refWznmMSquawk = htonl64(rec->refWznmMSquawk);
	smallint _Shrdat = htons((smallint) rec->Shrdat);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_refWznmMSquawk,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_Shrdat,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMOppack_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMOppack::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMOppack::updateRst(
			ListWznmMOppack& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMOppack::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWznmMOppack_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMOppack::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMOppack::loadRecByRef(
			ubigint ref
			, WznmMOppack** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMOppack_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMOppack::loadRecBySqk(
			ubigint refWznmMSquawk
			, WznmMOppack** rec
		) {
	ubigint _refWznmMSquawk = htonl64(refWznmMSquawk);

	const char* vals[] = {
		(char*) &_refWznmMSquawk
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMOppack_loadRecBySqk", 1, vals, l, f, rec);
};

ubigint PgTblWznmMOppack::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMOppack& rst
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMOppack_loadRstByVer", 1, vals, l, f, append, rst);
};

bool PgTblWznmMOppack::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWznmMOppack_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

