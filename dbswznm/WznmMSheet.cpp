/**
	* \file WznmMSheet.cpp
	* database access for table TblWznmMSheet (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#include "WznmMSheet.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMSheet
 ******************************************************************************/

WznmMSheet::WznmMSheet(
			const ubigint ref
			, const ubigint visRefWznmMVisual
			, const uint visNum
			, const string Title
		) :
			ref(ref)
			, visRefWznmMVisual(visRefWznmMVisual)
			, visNum(visNum)
			, Title(Title)
		{
};

bool WznmMSheet::operator==(
			const WznmMSheet& comp
		) {
	return false;
};

bool WznmMSheet::operator!=(
			const WznmMSheet& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMSheet
 ******************************************************************************/

ListWznmMSheet::ListWznmMSheet() {
};

ListWznmMSheet::ListWznmMSheet(
			const ListWznmMSheet& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMSheet(*(src.nodes[i]));
};

ListWznmMSheet::~ListWznmMSheet() {
	clear();
};

void ListWznmMSheet::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMSheet::size() const {
	return(nodes.size());
};

void ListWznmMSheet::append(
			WznmMSheet* rec
		) {
	nodes.push_back(rec);
};

WznmMSheet* ListWznmMSheet::operator[](
			const uint ix
		) {
	WznmMSheet* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMSheet& ListWznmMSheet::operator=(
			const ListWznmMSheet& src
		) {
	WznmMSheet* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMSheet(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMSheet::operator==(
			const ListWznmMSheet& comp
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

bool ListWznmMSheet::operator!=(
			const ListWznmMSheet& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMSheet
 ******************************************************************************/

TblWznmMSheet::TblWznmMSheet() {
};

TblWznmMSheet::~TblWznmMSheet() {
};

bool TblWznmMSheet::loadRecBySQL(
			const string& sqlstr
			, WznmMSheet** rec
		) {
	return false;
};

ubigint TblWznmMSheet::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSheet& rst
		) {
	return 0;
};

ubigint TblWznmMSheet::insertRec(
			WznmMSheet* rec
		) {
	return 0;
};

ubigint TblWznmMSheet::insertNewRec(
			WznmMSheet** rec
			, const ubigint visRefWznmMVisual
			, const uint visNum
			, const string Title
		) {
	ubigint retval = 0;
	WznmMSheet* _rec = NULL;

	_rec = new WznmMSheet(0, visRefWznmMVisual, visNum, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMSheet::appendNewRecToRst(
			ListWznmMSheet& rst
			, WznmMSheet** rec
			, const ubigint visRefWznmMVisual
			, const uint visNum
			, const string Title
		) {
	ubigint retval = 0;
	WznmMSheet* _rec = NULL;

	retval = insertNewRec(&_rec, visRefWznmMVisual, visNum, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMSheet::insertRst(
			ListWznmMSheet& rst
			, bool transact
		) {
};

void TblWznmMSheet::updateRec(
			WznmMSheet* rec
		) {
};

void TblWznmMSheet::updateRst(
			ListWznmMSheet& rst
			, bool transact
		) {
};

void TblWznmMSheet::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMSheet::loadRecByRef(
			ubigint ref
			, WznmMSheet** rec
		) {
	return false;
};

ubigint TblWznmMSheet::loadRstByVis(
			ubigint visRefWznmMVisual
			, const bool append
			, ListWznmMSheet& rst
		) {
	return 0;
};

bool TblWznmMSheet::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblWznmMSheet::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMSheet& rst
		) {
	ubigint numload = 0;
	WznmMSheet* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMSheet
 ******************************************************************************/

MyTblWznmMSheet::MyTblWznmMSheet() :
			TblWznmMSheet()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMSheet::~MyTblWznmMSheet() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMSheet::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMSheet (visRefWznmMVisual, visNum, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMSheet SET visRefWznmMVisual = ?, visNum = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMSheet WHERE ref = ?", false);
};

bool MyTblWznmMSheet::loadRecBySQL(
			const string& sqlstr
			, WznmMSheet** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMSheet* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMSheet::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMSheet::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMSheet();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->visRefWznmMVisual = atoll((char*) dbrow[1]); else _rec->visRefWznmMVisual = 0;
		if (dbrow[2]) _rec->visNum = atol((char*) dbrow[2]); else _rec->visNum = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMSheet::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSheet& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMSheet* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMSheet::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMSheet::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMSheet();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->visRefWznmMVisual = atoll((char*) dbrow[1]); else rec->visRefWznmMVisual = 0;
			if (dbrow[2]) rec->visNum = atol((char*) dbrow[2]); else rec->visNum = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMSheet::insertRec(
			WznmMSheet* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->visRefWznmMVisual,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->visNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMSheet::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMSheet::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMSheet::insertRst(
			ListWznmMSheet& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMSheet::updateRec(
			WznmMSheet* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->visRefWznmMVisual,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->visNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMSheet::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMSheet::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMSheet::updateRst(
			ListWznmMSheet& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMSheet::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMSheet::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMSheet::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMSheet::loadRecByRef(
			ubigint ref
			, WznmMSheet** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMSheet WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMSheet::loadRstByVis(
			ubigint visRefWznmMVisual
			, const bool append
			, ListWznmMSheet& rst
		) {
	return loadRstBySQL("SELECT ref, visRefWznmMVisual, visNum, Title FROM TblWznmMSheet WHERE visRefWznmMVisual = " + to_string(visRefWznmMVisual) + " ORDER BY visNum ASC", append, rst);
};

bool MyTblWznmMSheet::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmMSheet WHERE ref = " + to_string(ref) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMSheet
 ******************************************************************************/

PgTblWznmMSheet::PgTblWznmMSheet() :
			TblWznmMSheet()
			, PgTable()
		{
};

PgTblWznmMSheet::~PgTblWznmMSheet() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMSheet::initStatements() {
	createStatement("TblWznmMSheet_insertRec", "INSERT INTO TblWznmMSheet (visRefWznmMVisual, visNum, Title) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmMSheet_updateRec", "UPDATE TblWznmMSheet SET visRefWznmMVisual = $1, visNum = $2, Title = $3 WHERE ref = $4", 4);
	createStatement("TblWznmMSheet_removeRecByRef", "DELETE FROM TblWznmMSheet WHERE ref = $1", 1);

	createStatement("TblWznmMSheet_loadRecByRef", "SELECT ref, visRefWznmMVisual, visNum, Title FROM TblWznmMSheet WHERE ref = $1", 1);
	createStatement("TblWznmMSheet_loadRstByVis", "SELECT ref, visRefWznmMVisual, visNum, Title FROM TblWznmMSheet WHERE visRefWznmMVisual = $1 ORDER BY visNum ASC", 1);
	createStatement("TblWznmMSheet_loadTitByRef", "SELECT Title FROM TblWznmMSheet WHERE ref = $1", 1);
};

bool PgTblWznmMSheet::loadRec(
			PGresult* res
			, WznmMSheet** rec
		) {
	char* ptr;

	WznmMSheet* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMSheet();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "visrefwznmmvisual"),
			PQfnumber(res, "visnum"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->visRefWznmMVisual = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->visNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMSheet::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMSheet& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMSheet* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "visrefwznmmvisual"),
			PQfnumber(res, "visnum"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmMSheet();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->visRefWznmMVisual = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->visNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMSheet::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMSheet** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSheet::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMSheet::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMSheet& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSheet::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMSheet::loadRecBySQL(
			const string& sqlstr
			, WznmMSheet** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSheet::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMSheet::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSheet& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSheet::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMSheet::insertRec(
			WznmMSheet* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _visRefWznmMVisual = htonl64(rec->visRefWznmMVisual);
	uint _visNum = htonl(rec->visNum);

	const char* vals[] = {
		(char*) &_visRefWznmMVisual,
		(char*) &_visNum,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMSheet_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSheet::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMSheet::insertRst(
			ListWznmMSheet& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMSheet::updateRec(
			WznmMSheet* rec
		) {
	PGresult* res;

	ubigint _visRefWznmMVisual = htonl64(rec->visRefWznmMVisual);
	uint _visNum = htonl(rec->visNum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_visRefWznmMVisual,
		(char*) &_visNum,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMSheet_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMSheet::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMSheet::updateRst(
			ListWznmMSheet& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMSheet::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMSheet_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMSheet::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMSheet::loadRecByRef(
			ubigint ref
			, WznmMSheet** rec
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

	return loadRecByStmt("TblWznmMSheet_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMSheet::loadRstByVis(
			ubigint visRefWznmMVisual
			, const bool append
			, ListWznmMSheet& rst
		) {
	ubigint _visRefWznmMVisual = htonl64(visRefWznmMVisual);

	const char* vals[] = {
		(char*) &_visRefWznmMVisual
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMSheet_loadRstByVis", 1, vals, l, f, append, rst);
};

bool PgTblWznmMSheet::loadTitByRef(
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

	return loadStringByStmt("TblWznmMSheet_loadTitByRef", 1, vals, l, f, Title);
};

#endif
