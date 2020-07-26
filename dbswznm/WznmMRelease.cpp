/**
	* \file WznmMRelease.cpp
	* database access for table TblWznmMRelease (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMRelease.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMRelease
 ******************************************************************************/

WznmMRelease::WznmMRelease(
			const ubigint ref
			, const ubigint refWznmMComponent
			, const ubigint refWznmMMachine
			, const string sref
			, const string srefsKOption
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmMComponent = refWznmMComponent;
	this->refWznmMMachine = refWznmMMachine;
	this->sref = sref;
	this->srefsKOption = srefsKOption;
	this->Comment = Comment;
};

bool WznmMRelease::operator==(
			const WznmMRelease& comp
		) {
	return false;
};

bool WznmMRelease::operator!=(
			const WznmMRelease& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMRelease
 ******************************************************************************/

ListWznmMRelease::ListWznmMRelease() {
};

ListWznmMRelease::ListWznmMRelease(
			const ListWznmMRelease& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMRelease(*(src.nodes[i]));
};

ListWznmMRelease::~ListWznmMRelease() {
	clear();
};

void ListWznmMRelease::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMRelease::size() const {
	return(nodes.size());
};

void ListWznmMRelease::append(
			WznmMRelease* rec
		) {
	nodes.push_back(rec);
};

WznmMRelease* ListWznmMRelease::operator[](
			const uint ix
		) {
	WznmMRelease* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMRelease& ListWznmMRelease::operator=(
			const ListWznmMRelease& src
		) {
	WznmMRelease* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMRelease(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMRelease::operator==(
			const ListWznmMRelease& comp
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

bool ListWznmMRelease::operator!=(
			const ListWznmMRelease& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMRelease
 ******************************************************************************/

TblWznmMRelease::TblWznmMRelease() {
};

TblWznmMRelease::~TblWznmMRelease() {
};

bool TblWznmMRelease::loadRecBySQL(
			const string& sqlstr
			, WznmMRelease** rec
		) {
	return false;
};

ubigint TblWznmMRelease::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRelease& rst
		) {
	return 0;
};

ubigint TblWznmMRelease::insertRec(
			WznmMRelease* rec
		) {
	return 0;
};

ubigint TblWznmMRelease::insertNewRec(
			WznmMRelease** rec
			, const ubigint refWznmMComponent
			, const ubigint refWznmMMachine
			, const string sref
			, const string srefsKOption
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMRelease* _rec = NULL;

	_rec = new WznmMRelease(0, refWznmMComponent, refWznmMMachine, sref, srefsKOption, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMRelease::appendNewRecToRst(
			ListWznmMRelease& rst
			, WznmMRelease** rec
			, const ubigint refWznmMComponent
			, const ubigint refWznmMMachine
			, const string sref
			, const string srefsKOption
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMRelease* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMComponent, refWznmMMachine, sref, srefsKOption, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMRelease::insertRst(
			ListWznmMRelease& rst
			, bool transact
		) {
};

void TblWznmMRelease::updateRec(
			WznmMRelease* rec
		) {
};

void TblWznmMRelease::updateRst(
			ListWznmMRelease& rst
			, bool transact
		) {
};

void TblWznmMRelease::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMRelease::loadRecByRef(
			ubigint ref
			, WznmMRelease** rec
		) {
	return false;
};

ubigint TblWznmMRelease::loadRefsByCmp(
			ubigint refWznmMComponent
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMRelease::loadRstByCmp(
			ubigint refWznmMComponent
			, const bool append
			, ListWznmMRelease& rst
		) {
	return 0;
};

bool TblWznmMRelease::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMRelease::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMRelease& rst
		) {
	ubigint numload = 0;
	WznmMRelease* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMRelease
 ******************************************************************************/

MyTblWznmMRelease::MyTblWznmMRelease() :
			TblWznmMRelease()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMRelease::~MyTblWznmMRelease() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMRelease::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMRelease (refWznmMComponent, refWznmMMachine, sref, srefsKOption, Comment) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMRelease SET refWznmMComponent = ?, refWznmMMachine = ?, sref = ?, srefsKOption = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMRelease WHERE ref = ?", false);
};

bool MyTblWznmMRelease::loadRecBySQL(
			const string& sqlstr
			, WznmMRelease** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMRelease* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMRelease::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMRelease::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMRelease();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMComponent = atoll((char*) dbrow[1]); else _rec->refWznmMComponent = 0;
		if (dbrow[2]) _rec->refWznmMMachine = atoll((char*) dbrow[2]); else _rec->refWznmMMachine = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->srefsKOption.assign(dbrow[4], dblengths[4]); else _rec->srefsKOption = "";
		if (dbrow[5]) _rec->Comment.assign(dbrow[5], dblengths[5]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMRelease::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRelease& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMRelease* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMRelease::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMRelease::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMRelease();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMComponent = atoll((char*) dbrow[1]); else rec->refWznmMComponent = 0;
			if (dbrow[2]) rec->refWznmMMachine = atoll((char*) dbrow[2]); else rec->refWznmMMachine = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->srefsKOption.assign(dbrow[4], dblengths[4]); else rec->srefsKOption = "";
			if (dbrow[5]) rec->Comment.assign(dbrow[5], dblengths[5]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMRelease::insertRec(
			WznmMRelease* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[3] = rec->srefsKOption.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMComponent,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMMachine,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMRelease::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMRelease::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMRelease::insertRst(
			ListWznmMRelease& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMRelease::updateRec(
			WznmMRelease* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->sref.length();
	l[3] = rec->srefsKOption.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMComponent,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMMachine,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMRelease::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMRelease::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMRelease::updateRst(
			ListWznmMRelease& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMRelease::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMRelease::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMRelease::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMRelease::loadRecByRef(
			ubigint ref
			, WznmMRelease** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMRelease WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMRelease::loadRefsByCmp(
			ubigint refWznmMComponent
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMRelease WHERE refWznmMComponent = " + to_string(refWznmMComponent) + "", append, refs);
};

ubigint MyTblWznmMRelease::loadRstByCmp(
			ubigint refWznmMComponent
			, const bool append
			, ListWznmMRelease& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMComponent, refWznmMMachine, sref, srefsKOption, Comment FROM TblWznmMRelease WHERE refWznmMComponent = " + to_string(refWznmMComponent) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMRelease::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMRelease WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMRelease
 ******************************************************************************/

PgTblWznmMRelease::PgTblWznmMRelease() :
			TblWznmMRelease()
			, PgTable()
		{
};

PgTblWznmMRelease::~PgTblWznmMRelease() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMRelease::initStatements() {
	createStatement("TblWznmMRelease_insertRec", "INSERT INTO TblWznmMRelease (refWznmMComponent, refWznmMMachine, sref, srefsKOption, Comment) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmMRelease_updateRec", "UPDATE TblWznmMRelease SET refWznmMComponent = $1, refWznmMMachine = $2, sref = $3, srefsKOption = $4, Comment = $5 WHERE ref = $6", 6);
	createStatement("TblWznmMRelease_removeRecByRef", "DELETE FROM TblWznmMRelease WHERE ref = $1", 1);

	createStatement("TblWznmMRelease_loadRecByRef", "SELECT ref, refWznmMComponent, refWznmMMachine, sref, srefsKOption, Comment FROM TblWznmMRelease WHERE ref = $1", 1);
	createStatement("TblWznmMRelease_loadRefsByCmp", "SELECT ref FROM TblWznmMRelease WHERE refWznmMComponent = $1", 1);
	createStatement("TblWznmMRelease_loadRstByCmp", "SELECT ref, refWznmMComponent, refWznmMMachine, sref, srefsKOption, Comment FROM TblWznmMRelease WHERE refWznmMComponent = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMRelease_loadSrfByRef", "SELECT sref FROM TblWznmMRelease WHERE ref = $1", 1);
};

bool PgTblWznmMRelease::loadRec(
			PGresult* res
			, WznmMRelease** rec
		) {
	char* ptr;

	WznmMRelease* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMRelease();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcomponent"),
			PQfnumber(res, "refwznmmmachine"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefskoption"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMComponent = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->srefsKOption.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMRelease::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMRelease& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMRelease* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcomponent"),
			PQfnumber(res, "refwznmmmachine"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefskoption"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMRelease();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMComponent = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->srefsKOption.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMRelease::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMRelease** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRelease::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMRelease::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMRelease& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRelease::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMRelease::loadRecBySQL(
			const string& sqlstr
			, WznmMRelease** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRelease::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMRelease::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMRelease& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRelease::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMRelease::insertRec(
			WznmMRelease* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMComponent = htonl64(rec->refWznmMComponent);
	ubigint _refWznmMMachine = htonl64(rec->refWznmMMachine);

	const char* vals[] = {
		(char*) &_refWznmMComponent,
		(char*) &_refWznmMMachine,
		rec->sref.c_str(),
		rec->srefsKOption.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMRelease_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMRelease::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMRelease::insertRst(
			ListWznmMRelease& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMRelease::updateRec(
			WznmMRelease* rec
		) {
	PGresult* res;

	ubigint _refWznmMComponent = htonl64(rec->refWznmMComponent);
	ubigint _refWznmMMachine = htonl64(rec->refWznmMMachine);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMComponent,
		(char*) &_refWznmMMachine,
		rec->sref.c_str(),
		rec->srefsKOption.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMRelease_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMRelease::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMRelease::updateRst(
			ListWznmMRelease& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMRelease::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMRelease_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMRelease::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMRelease::loadRecByRef(
			ubigint ref
			, WznmMRelease** rec
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

	return loadRecByStmt("TblWznmMRelease_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMRelease::loadRefsByCmp(
			ubigint refWznmMComponent
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMComponent = htonl64(refWznmMComponent);

	const char* vals[] = {
		(char*) &_refWznmMComponent
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMRelease_loadRefsByCmp", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMRelease::loadRstByCmp(
			ubigint refWznmMComponent
			, const bool append
			, ListWznmMRelease& rst
		) {
	ubigint _refWznmMComponent = htonl64(refWznmMComponent);

	const char* vals[] = {
		(char*) &_refWznmMComponent
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMRelease_loadRstByCmp", 1, vals, l, f, append, rst);
};

bool PgTblWznmMRelease::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMRelease_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

