/**
	* \file WznmMProject.cpp
	* database access for table TblWznmMProject (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMProject.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMProject
 ******************************************************************************/

WznmMProject::WznmMProject(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refWznmMVersion
			, const string Short
			, const string Title
			, const string Giturl
			, const string Comment
		) :
			ref(ref)
			, grp(grp)
			, own(own)
			, refWznmMVersion(refWznmMVersion)
			, Short(Short)
			, Title(Title)
			, Giturl(Giturl)
			, Comment(Comment)
		{
};

bool WznmMProject::operator==(
			const WznmMProject& comp
		) {
	return false;
};

bool WznmMProject::operator!=(
			const WznmMProject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMProject
 ******************************************************************************/

ListWznmMProject::ListWznmMProject() {
};

ListWznmMProject::ListWznmMProject(
			const ListWznmMProject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMProject(*(src.nodes[i]));
};

ListWznmMProject::~ListWznmMProject() {
	clear();
};

void ListWznmMProject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMProject::size() const {
	return(nodes.size());
};

void ListWznmMProject::append(
			WznmMProject* rec
		) {
	nodes.push_back(rec);
};

WznmMProject* ListWznmMProject::operator[](
			const uint ix
		) {
	WznmMProject* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMProject& ListWznmMProject::operator=(
			const ListWznmMProject& src
		) {
	WznmMProject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMProject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMProject::operator==(
			const ListWznmMProject& comp
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

bool ListWznmMProject::operator!=(
			const ListWznmMProject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMProject
 ******************************************************************************/

TblWznmMProject::TblWznmMProject() {
};

TblWznmMProject::~TblWznmMProject() {
};

bool TblWznmMProject::loadRecBySQL(
			const string& sqlstr
			, WznmMProject** rec
		) {
	return false;
};

ubigint TblWznmMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMProject& rst
		) {
	return 0;
};

ubigint TblWznmMProject::insertRec(
			WznmMProject* rec
		) {
	return 0;
};

ubigint TblWznmMProject::insertNewRec(
			WznmMProject** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refWznmMVersion
			, const string Short
			, const string Title
			, const string Giturl
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMProject* _rec = NULL;

	_rec = new WznmMProject(0, grp, own, refWznmMVersion, Short, Title, Giturl, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMProject::appendNewRecToRst(
			ListWznmMProject& rst
			, WznmMProject** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refWznmMVersion
			, const string Short
			, const string Title
			, const string Giturl
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMProject* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refWznmMVersion, Short, Title, Giturl, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMProject::insertRst(
			ListWznmMProject& rst
			, bool transact
		) {
};

void TblWznmMProject::updateRec(
			WznmMProject* rec
		) {
};

void TblWznmMProject::updateRst(
			ListWznmMProject& rst
			, bool transact
		) {
};

void TblWznmMProject::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMProject::loadRecByRef(
			ubigint ref
			, WznmMProject** rec
		) {
	return false;
};

bool TblWznmMProject::loadShoByRef(
			ubigint ref
			, string& Short
		) {
	return false;
};

bool TblWznmMProject::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblWznmMProject::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMProject& rst
		) {
	ubigint numload = 0;
	WznmMProject* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMProject
 ******************************************************************************/

MyTblWznmMProject::MyTblWznmMProject() :
			TblWznmMProject()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMProject::~MyTblWznmMProject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMProject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMProject (grp, own, refWznmMVersion, Short, Title, Giturl, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMProject SET grp = ?, own = ?, refWznmMVersion = ?, Short = ?, Title = ?, Giturl = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMProject WHERE ref = ?", false);
};

bool MyTblWznmMProject::loadRecBySQL(
			const string& sqlstr
			, WznmMProject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMProject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMProject::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMProject::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMProject();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refWznmMVersion = atoll((char*) dbrow[3]); else _rec->refWznmMVersion = 0;
		if (dbrow[4]) _rec->Short.assign(dbrow[4], dblengths[4]); else _rec->Short = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->Giturl.assign(dbrow[6], dblengths[6]); else _rec->Giturl = "";
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMProject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMProject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMProject::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMProject::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMProject();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refWznmMVersion = atoll((char*) dbrow[3]); else rec->refWznmMVersion = 0;
			if (dbrow[4]) rec->Short.assign(dbrow[4], dblengths[4]); else rec->Short = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->Giturl.assign(dbrow[6], dblengths[6]); else rec->Giturl = "";
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMProject::insertRec(
			WznmMProject* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->Short.length();
	l[4] = rec->Title.length();
	l[5] = rec->Giturl.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMVersion,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Short.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Giturl.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMProject::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMProject::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMProject::insertRst(
			ListWznmMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMProject::updateRec(
			WznmMProject* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->Short.length();
	l[4] = rec->Title.length();
	l[5] = rec->Giturl.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWznmMVersion,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Short.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Giturl.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMProject::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMProject::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMProject::updateRst(
			ListWznmMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMProject::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMProject::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMProject::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMProject::loadRecByRef(
			ubigint ref
			, WznmMProject** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMProject WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMProject::loadShoByRef(
			ubigint ref
			, string& Short
		) {
	return loadStringBySQL("SELECT Short FROM TblWznmMProject WHERE ref = " + to_string(ref) + "", Short);
};

bool MyTblWznmMProject::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmMProject WHERE ref = " + to_string(ref) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMProject
 ******************************************************************************/

PgTblWznmMProject::PgTblWznmMProject() :
			TblWznmMProject()
			, PgTable()
		{
};

PgTblWznmMProject::~PgTblWznmMProject() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMProject::initStatements() {
	createStatement("TblWznmMProject_insertRec", "INSERT INTO TblWznmMProject (grp, own, refWznmMVersion, Short, Title, Giturl, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWznmMProject_updateRec", "UPDATE TblWznmMProject SET grp = $1, own = $2, refWznmMVersion = $3, Short = $4, Title = $5, Giturl = $6, Comment = $7 WHERE ref = $8", 8);
	createStatement("TblWznmMProject_removeRecByRef", "DELETE FROM TblWznmMProject WHERE ref = $1", 1);

	createStatement("TblWznmMProject_loadRecByRef", "SELECT ref, grp, own, refWznmMVersion, Short, Title, Giturl, Comment FROM TblWznmMProject WHERE ref = $1", 1);
	createStatement("TblWznmMProject_loadShoByRef", "SELECT Short FROM TblWznmMProject WHERE ref = $1", 1);
	createStatement("TblWznmMProject_loadTitByRef", "SELECT Title FROM TblWznmMProject WHERE ref = $1", 1);
};

bool PgTblWznmMProject::loadRec(
			PGresult* res
			, WznmMProject** rec
		) {
	char* ptr;

	WznmMProject* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMProject();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "short"),
			PQfnumber(res, "title"),
			PQfnumber(res, "giturl"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Giturl.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMProject::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMProject& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMProject* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "short"),
			PQfnumber(res, "title"),
			PQfnumber(res, "giturl"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMProject();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Giturl.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMProject::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMProject** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMProject::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmMProject::loadRecBySQL(
			const string& sqlstr
			, WznmMProject** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMProject::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMProject& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMProject::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMProject::insertRec(
			WznmMProject* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWznmMVersion,
		rec->Short.c_str(),
		rec->Title.c_str(),
		rec->Giturl.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMProject_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMProject::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMProject::insertRst(
			ListWznmMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMProject::updateRec(
			WznmMProject* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWznmMVersion,
		rec->Short.c_str(),
		rec->Title.c_str(),
		rec->Giturl.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMProject_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMProject::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMProject::updateRst(
			ListWznmMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMProject::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMProject_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMProject::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMProject::loadRecByRef(
			ubigint ref
			, WznmMProject** rec
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

	return loadRecByStmt("TblWznmMProject_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMProject::loadShoByRef(
			ubigint ref
			, string& Short
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWznmMProject_loadShoByRef", 1, vals, l, f, Short);
};

bool PgTblWznmMProject::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWznmMProject_loadTitByRef", 1, vals, l, f, Title);
};

#endif
