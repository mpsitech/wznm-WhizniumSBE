/**
	* \file WznmMError.cpp
	* database access for table TblWznmMError (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmMError.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMError
 ******************************************************************************/

WznmMError::WznmMError(
			const ubigint ref
			, const ubigint verRefWznmMVersion
			, const uint verNum
			, const string sref
			, const ubigint refJTitle
			, const string Title
		) {

	this->ref = ref;
	this->verRefWznmMVersion = verRefWznmMVersion;
	this->verNum = verNum;
	this->sref = sref;
	this->refJTitle = refJTitle;
	this->Title = Title;
};

bool WznmMError::operator==(
			const WznmMError& comp
		) {
	return false;
};

bool WznmMError::operator!=(
			const WznmMError& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMError
 ******************************************************************************/

ListWznmMError::ListWznmMError() {
};

ListWznmMError::ListWznmMError(
			const ListWznmMError& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMError(*(src.nodes[i]));
};

ListWznmMError::~ListWznmMError() {
	clear();
};

void ListWznmMError::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMError::size() const {
	return(nodes.size());
};

void ListWznmMError::append(
			WznmMError* rec
		) {
	nodes.push_back(rec);
};

WznmMError* ListWznmMError::operator[](
			const uint ix
		) {
	WznmMError* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMError& ListWznmMError::operator=(
			const ListWznmMError& src
		) {
	WznmMError* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMError(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMError::operator==(
			const ListWznmMError& comp
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

bool ListWznmMError::operator!=(
			const ListWznmMError& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMError
 ******************************************************************************/

TblWznmMError::TblWznmMError() {
};

TblWznmMError::~TblWznmMError() {
};

bool TblWznmMError::loadRecBySQL(
			const string& sqlstr
			, WznmMError** rec
		) {
	return false;
};

ubigint TblWznmMError::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMError& rst
		) {
	return 0;
};

ubigint TblWznmMError::insertRec(
			WznmMError* rec
		) {
	return 0;
};

ubigint TblWznmMError::insertNewRec(
			WznmMError** rec
			, const ubigint verRefWznmMVersion
			, const uint verNum
			, const string sref
			, const ubigint refJTitle
			, const string Title
		) {
	ubigint retval = 0;
	WznmMError* _rec = NULL;

	_rec = new WznmMError(0, verRefWznmMVersion, verNum, sref, refJTitle, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMError::appendNewRecToRst(
			ListWznmMError& rst
			, WznmMError** rec
			, const ubigint verRefWznmMVersion
			, const uint verNum
			, const string sref
			, const ubigint refJTitle
			, const string Title
		) {
	ubigint retval = 0;
	WznmMError* _rec = NULL;

	retval = insertNewRec(&_rec, verRefWznmMVersion, verNum, sref, refJTitle, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMError::insertRst(
			ListWznmMError& rst
			, bool transact
		) {
};

void TblWznmMError::updateRec(
			WznmMError* rec
		) {
};

void TblWznmMError::updateRst(
			ListWznmMError& rst
			, bool transact
		) {
};

void TblWznmMError::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMError::loadRecByRef(
			ubigint ref
			, WznmMError** rec
		) {
	return false;
};

ubigint TblWznmMError::loadRstByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, ListWznmMError& rst
		) {
	return 0;
};

ubigint TblWznmMError::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMError& rst
		) {
	ubigint numload = 0;
	WznmMError* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMError
 ******************************************************************************/

MyTblWznmMError::MyTblWznmMError() :
			TblWznmMError()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMError::~MyTblWznmMError() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMError::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMError (verRefWznmMVersion, verNum, sref, refJTitle, Title) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMError SET verRefWznmMVersion = ?, verNum = ?, sref = ?, refJTitle = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMError WHERE ref = ?", false);
};

bool MyTblWznmMError::loadRecBySQL(
			const string& sqlstr
			, WznmMError** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMError* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMError::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMError::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMError();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->verRefWznmMVersion = atoll((char*) dbrow[1]); else _rec->verRefWznmMVersion = 0;
		if (dbrow[2]) _rec->verNum = atol((char*) dbrow[2]); else _rec->verNum = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->refJTitle = atoll((char*) dbrow[4]); else _rec->refJTitle = 0;
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMError::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMError& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMError* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMError::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMError::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMError();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->verRefWznmMVersion = atoll((char*) dbrow[1]); else rec->verRefWznmMVersion = 0;
			if (dbrow[2]) rec->verNum = atol((char*) dbrow[2]); else rec->verNum = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->refJTitle = atoll((char*) dbrow[4]); else rec->refJTitle = 0;
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMError::insertRec(
			WznmMError* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->verRefWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->verNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refJTitle,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMError::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMError::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMError::insertRst(
			ListWznmMError& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMError::updateRec(
			WznmMError* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->verRefWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->verNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refJTitle,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMError::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMError::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMError::updateRst(
			ListWznmMError& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMError::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMError::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMError::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMError::loadRecByRef(
			ubigint ref
			, WznmMError** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMError WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMError::loadRstByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, ListWznmMError& rst
		) {
	return loadRstBySQL("SELECT ref, verRefWznmMVersion, verNum, sref, refJTitle, Title FROM TblWznmMError WHERE verRefWznmMVersion = " + to_string(verRefWznmMVersion) + " ORDER BY verNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMError
 ******************************************************************************/

PgTblWznmMError::PgTblWznmMError() :
			TblWznmMError()
			, PgTable()
		{
};

PgTblWznmMError::~PgTblWznmMError() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMError::initStatements() {
	createStatement("TblWznmMError_insertRec", "INSERT INTO TblWznmMError (verRefWznmMVersion, verNum, sref, refJTitle, Title) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmMError_updateRec", "UPDATE TblWznmMError SET verRefWznmMVersion = $1, verNum = $2, sref = $3, refJTitle = $4, Title = $5 WHERE ref = $6", 6);
	createStatement("TblWznmMError_removeRecByRef", "DELETE FROM TblWznmMError WHERE ref = $1", 1);

	createStatement("TblWznmMError_loadRecByRef", "SELECT ref, verRefWznmMVersion, verNum, sref, refJTitle, Title FROM TblWznmMError WHERE ref = $1", 1);
	createStatement("TblWznmMError_loadRstByVer", "SELECT ref, verRefWznmMVersion, verNum, sref, refJTitle, Title FROM TblWznmMError WHERE verRefWznmMVersion = $1 ORDER BY verNum ASC", 1);
};

bool PgTblWznmMError::loadRec(
			PGresult* res
			, WznmMError** rec
		) {
	char* ptr;

	WznmMError* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMError();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "verrefwznmmversion"),
			PQfnumber(res, "vernum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->verRefWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->verNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refJTitle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMError::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMError& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMError* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "verrefwznmmversion"),
			PQfnumber(res, "vernum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmMError();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->verRefWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->verNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refJTitle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMError::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMError** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMError::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMError::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMError& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMError::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMError::loadRecBySQL(
			const string& sqlstr
			, WznmMError** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMError::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMError::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMError& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMError::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMError::insertRec(
			WznmMError* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _verRefWznmMVersion = htonl64(rec->verRefWznmMVersion);
	uint _verNum = htonl(rec->verNum);
	ubigint _refJTitle = htonl64(rec->refJTitle);

	const char* vals[] = {
		(char*) &_verRefWznmMVersion,
		(char*) &_verNum,
		rec->sref.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMError_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMError::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMError::insertRst(
			ListWznmMError& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMError::updateRec(
			WznmMError* rec
		) {
	PGresult* res;

	ubigint _verRefWznmMVersion = htonl64(rec->verRefWznmMVersion);
	uint _verNum = htonl(rec->verNum);
	ubigint _refJTitle = htonl64(rec->refJTitle);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_verRefWznmMVersion,
		(char*) &_verNum,
		rec->sref.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMError_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMError::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMError::updateRst(
			ListWznmMError& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMError::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMError_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMError::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMError::loadRecByRef(
			ubigint ref
			, WznmMError** rec
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

	return loadRecByStmt("TblWznmMError_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMError::loadRstByVer(
			ubigint verRefWznmMVersion
			, const bool append
			, ListWznmMError& rst
		) {
	ubigint _verRefWznmMVersion = htonl64(verRefWznmMVersion);

	const char* vals[] = {
		(char*) &_verRefWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMError_loadRstByVer", 1, vals, l, f, append, rst);
};

#endif

