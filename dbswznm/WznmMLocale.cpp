/**
	* \file WznmMLocale.cpp
	* database access for table TblWznmMLocale (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmMLocale.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMLocale
 ******************************************************************************/

WznmMLocale::WznmMLocale(
			const ubigint ref
			, const string sref
			, const ubigint refJTitle
			, const string Title
		) {

	this->ref = ref;
	this->sref = sref;
	this->refJTitle = refJTitle;
	this->Title = Title;
};

bool WznmMLocale::operator==(
			const WznmMLocale& comp
		) {
	return false;
};

bool WznmMLocale::operator!=(
			const WznmMLocale& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMLocale
 ******************************************************************************/

ListWznmMLocale::ListWznmMLocale() {
};

ListWznmMLocale::ListWznmMLocale(
			const ListWznmMLocale& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMLocale(*(src.nodes[i]));
};

ListWznmMLocale::~ListWznmMLocale() {
	clear();
};

void ListWznmMLocale::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMLocale::size() const {
	return(nodes.size());
};

void ListWznmMLocale::append(
			WznmMLocale* rec
		) {
	nodes.push_back(rec);
};

WznmMLocale* ListWznmMLocale::operator[](
			const uint ix
		) {
	WznmMLocale* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMLocale& ListWznmMLocale::operator=(
			const ListWznmMLocale& src
		) {
	WznmMLocale* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMLocale(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMLocale::operator==(
			const ListWznmMLocale& comp
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

bool ListWznmMLocale::operator!=(
			const ListWznmMLocale& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMLocale
 ******************************************************************************/

TblWznmMLocale::TblWznmMLocale() {
};

TblWznmMLocale::~TblWznmMLocale() {
};

bool TblWznmMLocale::loadRecBySQL(
			const string& sqlstr
			, WznmMLocale** rec
		) {
	return false;
};

ubigint TblWznmMLocale::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMLocale& rst
		) {
	return 0;
};

ubigint TblWznmMLocale::insertRec(
			WznmMLocale* rec
		) {
	return 0;
};

ubigint TblWznmMLocale::insertNewRec(
			WznmMLocale** rec
			, const string sref
			, const ubigint refJTitle
			, const string Title
		) {
	ubigint retval = 0;
	WznmMLocale* _rec = NULL;

	_rec = new WznmMLocale(0, sref, refJTitle, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMLocale::appendNewRecToRst(
			ListWznmMLocale& rst
			, WznmMLocale** rec
			, const string sref
			, const ubigint refJTitle
			, const string Title
		) {
	ubigint retval = 0;
	WznmMLocale* _rec = NULL;

	retval = insertNewRec(&_rec, sref, refJTitle, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMLocale::insertRst(
			ListWznmMLocale& rst
			, bool transact
		) {
};

void TblWznmMLocale::updateRec(
			WznmMLocale* rec
		) {
};

void TblWznmMLocale::updateRst(
			ListWznmMLocale& rst
			, bool transact
		) {
};

void TblWznmMLocale::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMLocale::loadRecByRef(
			ubigint ref
			, WznmMLocale** rec
		) {
	return false;
};

bool TblWznmMLocale::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

bool TblWznmMLocale::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMLocale::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMLocale& rst
		) {
	ubigint numload = 0;
	WznmMLocale* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMLocale
 ******************************************************************************/

MyTblWznmMLocale::MyTblWznmMLocale() :
			TblWznmMLocale()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMLocale::~MyTblWznmMLocale() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMLocale::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMLocale (sref, refJTitle, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMLocale SET sref = ?, refJTitle = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMLocale WHERE ref = ?", false);
};

bool MyTblWznmMLocale::loadRecBySQL(
			const string& sqlstr
			, WznmMLocale** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMLocale* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMLocale::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMLocale::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMLocale();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->sref.assign(dbrow[1], dblengths[1]); else _rec->sref = "";
		if (dbrow[2]) _rec->refJTitle = atoll((char*) dbrow[2]); else _rec->refJTitle = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMLocale::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMLocale& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMLocale* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMLocale::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMLocale::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMLocale();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->sref.assign(dbrow[1], dblengths[1]); else rec->sref = "";
			if (dbrow[2]) rec->refJTitle = atoll((char*) dbrow[2]); else rec->refJTitle = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMLocale::insertRec(
			WznmMLocale* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[0] = rec->sref.length();
	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->sref.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refJTitle,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMLocale::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMLocale::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMLocale::insertRst(
			ListWznmMLocale& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMLocale::updateRec(
			WznmMLocale* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[0] = rec->sref.length();
	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->sref.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refJTitle,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMLocale::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMLocale::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMLocale::updateRst(
			ListWznmMLocale& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMLocale::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMLocale::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMLocale::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMLocale::loadRecByRef(
			ubigint ref
			, WznmMLocale** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMLocale WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMLocale::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMLocale WHERE sref = '" + sref + "'", ref);
};

bool MyTblWznmMLocale::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMLocale WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMLocale
 ******************************************************************************/

PgTblWznmMLocale::PgTblWznmMLocale() :
			TblWznmMLocale()
			, PgTable()
		{
};

PgTblWznmMLocale::~PgTblWznmMLocale() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMLocale::initStatements() {
	createStatement("TblWznmMLocale_insertRec", "INSERT INTO TblWznmMLocale (sref, refJTitle, Title) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmMLocale_updateRec", "UPDATE TblWznmMLocale SET sref = $1, refJTitle = $2, Title = $3 WHERE ref = $4", 4);
	createStatement("TblWznmMLocale_removeRecByRef", "DELETE FROM TblWznmMLocale WHERE ref = $1", 1);

	createStatement("TblWznmMLocale_loadRecByRef", "SELECT ref, sref, refJTitle, Title FROM TblWznmMLocale WHERE ref = $1", 1);
	createStatement("TblWznmMLocale_loadRefBySrf", "SELECT ref FROM TblWznmMLocale WHERE sref = $1", 1);
	createStatement("TblWznmMLocale_loadSrfByRef", "SELECT sref FROM TblWznmMLocale WHERE ref = $1", 1);
};

bool PgTblWznmMLocale::loadRec(
			PGresult* res
			, WznmMLocale** rec
		) {
	char* ptr;

	WznmMLocale* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMLocale();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[1]));
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refJTitle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMLocale::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMLocale& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMLocale* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmMLocale();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[1]));
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refJTitle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMLocale::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMLocale** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMLocale::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmMLocale::loadRecBySQL(
			const string& sqlstr
			, WznmMLocale** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMLocale::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMLocale::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMLocale& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMLocale::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMLocale::insertRec(
			WznmMLocale* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refJTitle = htonl64(rec->refJTitle);

	const char* vals[] = {
		rec->sref.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str()
	};
	const int l[] = {
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMLocale_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMLocale::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMLocale::insertRst(
			ListWznmMLocale& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMLocale::updateRec(
			WznmMLocale* rec
		) {
	PGresult* res;

	ubigint _refJTitle = htonl64(rec->refJTitle);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		rec->sref.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMLocale_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMLocale::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMLocale::updateRst(
			ListWznmMLocale& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMLocale::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMLocale_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMLocale::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMLocale::loadRecByRef(
			ubigint ref
			, WznmMLocale** rec
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

	return loadRecByStmt("TblWznmMLocale_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMLocale::loadRefBySrf(
			string sref
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRefByStmt("TblWznmMLocale_loadRefBySrf", 1, vals, l, f, ref);
};

bool PgTblWznmMLocale::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMLocale_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

