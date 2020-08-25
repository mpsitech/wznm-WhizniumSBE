/**
	* \file WznmMOp.cpp
	* database access for table TblWznmMOp (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmMOp.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMOp
 ******************************************************************************/

WznmMOp::WznmMOp(
			const ubigint ref
			, const ubigint refWznmMOppack
			, const ubigint refWznmMSquawk
			, const string sref
			, const bool Shrdat
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmMOppack = refWznmMOppack;
	this->refWznmMSquawk = refWznmMSquawk;
	this->sref = sref;
	this->Shrdat = Shrdat;
	this->Comment = Comment;
};

bool WznmMOp::operator==(
			const WznmMOp& comp
		) {
	return false;
};

bool WznmMOp::operator!=(
			const WznmMOp& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMOp
 ******************************************************************************/

ListWznmMOp::ListWznmMOp() {
};

ListWznmMOp::ListWznmMOp(
			const ListWznmMOp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMOp(*(src.nodes[i]));
};

ListWznmMOp::~ListWznmMOp() {
	clear();
};

void ListWznmMOp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMOp::size() const {
	return(nodes.size());
};

void ListWznmMOp::append(
			WznmMOp* rec
		) {
	nodes.push_back(rec);
};

WznmMOp* ListWznmMOp::operator[](
			const uint ix
		) {
	WznmMOp* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMOp& ListWznmMOp::operator=(
			const ListWznmMOp& src
		) {
	WznmMOp* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMOp(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMOp::operator==(
			const ListWznmMOp& comp
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

bool ListWznmMOp::operator!=(
			const ListWznmMOp& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMOp
 ******************************************************************************/

TblWznmMOp::TblWznmMOp() {
};

TblWznmMOp::~TblWznmMOp() {
};

bool TblWznmMOp::loadRecBySQL(
			const string& sqlstr
			, WznmMOp** rec
		) {
	return false;
};

ubigint TblWznmMOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMOp& rst
		) {
	return 0;
};

ubigint TblWznmMOp::insertRec(
			WznmMOp* rec
		) {
	return 0;
};

ubigint TblWznmMOp::insertNewRec(
			WznmMOp** rec
			, const ubigint refWznmMOppack
			, const ubigint refWznmMSquawk
			, const string sref
			, const bool Shrdat
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMOp* _rec = NULL;

	_rec = new WznmMOp(0, refWznmMOppack, refWznmMSquawk, sref, Shrdat, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMOp::appendNewRecToRst(
			ListWznmMOp& rst
			, WznmMOp** rec
			, const ubigint refWznmMOppack
			, const ubigint refWznmMSquawk
			, const string sref
			, const bool Shrdat
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMOp* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMOppack, refWznmMSquawk, sref, Shrdat, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMOp::insertRst(
			ListWznmMOp& rst
			, bool transact
		) {
};

void TblWznmMOp::updateRec(
			WznmMOp* rec
		) {
};

void TblWznmMOp::updateRst(
			ListWznmMOp& rst
			, bool transact
		) {
};

void TblWznmMOp::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMOp::loadRecByRef(
			ubigint ref
			, WznmMOp** rec
		) {
	return false;
};

bool TblWznmMOp::loadRecBySqk(
			ubigint refWznmMSquawk
			, WznmMOp** rec
		) {
	return false;
};

ubigint TblWznmMOp::loadRefsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMOp::loadRstByOpk(
			ubigint refWznmMOppack
			, const bool append
			, ListWznmMOp& rst
		) {
	return 0;
};

bool TblWznmMOp::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMOp::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMOp& rst
		) {
	ubigint numload = 0;
	WznmMOp* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMOp
 ******************************************************************************/

MyTblWznmMOp::MyTblWznmMOp() :
			TblWznmMOp()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMOp::~MyTblWznmMOp() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMOp::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMOp (refWznmMOppack, refWznmMSquawk, sref, Shrdat, Comment) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMOp SET refWznmMOppack = ?, refWznmMSquawk = ?, sref = ?, Shrdat = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMOp WHERE ref = ?", false);
};

bool MyTblWznmMOp::loadRecBySQL(
			const string& sqlstr
			, WznmMOp** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMOp* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMOp::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMOp::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMOp();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMOppack = atoll((char*) dbrow[1]); else _rec->refWznmMOppack = 0;
		if (dbrow[2]) _rec->refWznmMSquawk = atoll((char*) dbrow[2]); else _rec->refWznmMSquawk = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Shrdat = (atoi((char*) dbrow[4]) != 0); else _rec->Shrdat = false;
		if (dbrow[5]) _rec->Comment.assign(dbrow[5], dblengths[5]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMOp& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMOp* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMOp::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMOp::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMOp();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMOppack = atoll((char*) dbrow[1]); else rec->refWznmMOppack = 0;
			if (dbrow[2]) rec->refWznmMSquawk = atoll((char*) dbrow[2]); else rec->refWznmMSquawk = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Shrdat = (atoi((char*) dbrow[4]) != 0); else rec->Shrdat = false;
			if (dbrow[5]) rec->Comment.assign(dbrow[5], dblengths[5]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMOp::insertRec(
			WznmMOp* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	tinyint Shrdat = rec->Shrdat;
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMOppack,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMSquawk,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindTinyint(&Shrdat,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMOp::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMOp::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMOp::insertRst(
			ListWznmMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMOp::updateRec(
			WznmMOp* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->sref.length();
	tinyint Shrdat = rec->Shrdat;
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMOppack,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMSquawk,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindTinyint(&Shrdat,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMOp::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMOp::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMOp::updateRst(
			ListWznmMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMOp::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMOp::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMOp::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMOp::loadRecByRef(
			ubigint ref
			, WznmMOp** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMOp WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMOp::loadRecBySqk(
			ubigint refWznmMSquawk
			, WznmMOp** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMOppack, refWznmMSquawk, sref, Shrdat, Comment FROM TblWznmMOp WHERE refWznmMSquawk = " + to_string(refWznmMSquawk) + "", rec);
};

ubigint MyTblWznmMOp::loadRefsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMOp WHERE refWznmMOppack = " + to_string(refWznmMOppack) + "", append, refs);
};

ubigint MyTblWznmMOp::loadRstByOpk(
			ubigint refWznmMOppack
			, const bool append
			, ListWznmMOp& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMOppack, refWznmMSquawk, sref, Shrdat, Comment FROM TblWznmMOp WHERE refWznmMOppack = " + to_string(refWznmMOppack) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMOp::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMOp WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMOp
 ******************************************************************************/

PgTblWznmMOp::PgTblWznmMOp() :
			TblWznmMOp()
			, PgTable()
		{
};

PgTblWznmMOp::~PgTblWznmMOp() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMOp::initStatements() {
	createStatement("TblWznmMOp_insertRec", "INSERT INTO TblWznmMOp (refWznmMOppack, refWznmMSquawk, sref, Shrdat, Comment) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmMOp_updateRec", "UPDATE TblWznmMOp SET refWznmMOppack = $1, refWznmMSquawk = $2, sref = $3, Shrdat = $4, Comment = $5 WHERE ref = $6", 6);
	createStatement("TblWznmMOp_removeRecByRef", "DELETE FROM TblWznmMOp WHERE ref = $1", 1);

	createStatement("TblWznmMOp_loadRecByRef", "SELECT ref, refWznmMOppack, refWznmMSquawk, sref, Shrdat, Comment FROM TblWznmMOp WHERE ref = $1", 1);
	createStatement("TblWznmMOp_loadRecBySqk", "SELECT ref, refWznmMOppack, refWznmMSquawk, sref, Shrdat, Comment FROM TblWznmMOp WHERE refWznmMSquawk = $1", 1);
	createStatement("TblWznmMOp_loadRefsByOpk", "SELECT ref FROM TblWznmMOp WHERE refWznmMOppack = $1", 1);
	createStatement("TblWznmMOp_loadRstByOpk", "SELECT ref, refWznmMOppack, refWznmMSquawk, sref, Shrdat, Comment FROM TblWznmMOp WHERE refWznmMOppack = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMOp_loadSrfByRef", "SELECT sref FROM TblWznmMOp WHERE ref = $1", 1);
};

bool PgTblWznmMOp::loadRec(
			PGresult* res
			, WznmMOp** rec
		) {
	char* ptr;

	WznmMOp* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMOp();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmoppack"),
			PQfnumber(res, "refwznmmsquawk"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "shrdat"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMOppack = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMSquawk = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Shrdat = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMOp::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMOp& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMOp* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmoppack"),
			PQfnumber(res, "refwznmmsquawk"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "shrdat"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMOp();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMOppack = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMSquawk = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Shrdat = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMOp::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMOp** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMOp::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMOp::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMOp& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMOp::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMOp::loadRecBySQL(
			const string& sqlstr
			, WznmMOp** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMOp::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMOp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMOp& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMOp::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMOp::insertRec(
			WznmMOp* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMOppack = htonl64(rec->refWznmMOppack);
	ubigint _refWznmMSquawk = htonl64(rec->refWznmMSquawk);
	smallint _Shrdat = htons((smallint) rec->Shrdat);

	const char* vals[] = {
		(char*) &_refWznmMOppack,
		(char*) &_refWznmMSquawk,
		rec->sref.c_str(),
		(char*) &_Shrdat,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMOp_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMOp::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMOp::insertRst(
			ListWznmMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMOp::updateRec(
			WznmMOp* rec
		) {
	PGresult* res;

	ubigint _refWznmMOppack = htonl64(rec->refWznmMOppack);
	ubigint _refWznmMSquawk = htonl64(rec->refWznmMSquawk);
	smallint _Shrdat = htons((smallint) rec->Shrdat);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMOppack,
		(char*) &_refWznmMSquawk,
		rec->sref.c_str(),
		(char*) &_Shrdat,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMOp_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMOp::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMOp::updateRst(
			ListWznmMOp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMOp::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMOp_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMOp::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMOp::loadRecByRef(
			ubigint ref
			, WznmMOp** rec
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

	return loadRecByStmt("TblWznmMOp_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMOp::loadRecBySqk(
			ubigint refWznmMSquawk
			, WznmMOp** rec
		) {
	ubigint _refWznmMSquawk = htonl64(refWznmMSquawk);

	const char* vals[] = {
		(char*) &_refWznmMSquawk
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMOp_loadRecBySqk", 1, vals, l, f, rec);
};

ubigint PgTblWznmMOp::loadRefsByOpk(
			ubigint refWznmMOppack
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMOppack = htonl64(refWznmMOppack);

	const char* vals[] = {
		(char*) &_refWznmMOppack
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMOp_loadRefsByOpk", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMOp::loadRstByOpk(
			ubigint refWznmMOppack
			, const bool append
			, ListWznmMOp& rst
		) {
	ubigint _refWznmMOppack = htonl64(refWznmMOppack);

	const char* vals[] = {
		(char*) &_refWznmMOppack
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMOp_loadRstByOpk", 1, vals, l, f, append, rst);
};

bool PgTblWznmMOp::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMOp_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

