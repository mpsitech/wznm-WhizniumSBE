/**
	* \file WznmMSquawk.cpp
	* database access for table TblWznmMSquawk (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMSquawk.h"

#include "WznmMSquawk_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMSquawk
 ******************************************************************************/

WznmMSquawk::WznmMSquawk(
			const ubigint ref
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refJTitle
			, const string Title
			, const string Example
		) {

	this->ref = ref;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->refJTitle = refJTitle;
	this->Title = Title;
	this->Example = Example;
};

bool WznmMSquawk::operator==(
			const WznmMSquawk& comp
		) {
	return false;
};

bool WznmMSquawk::operator!=(
			const WznmMSquawk& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMSquawk
 ******************************************************************************/

ListWznmMSquawk::ListWznmMSquawk() {
};

ListWznmMSquawk::ListWznmMSquawk(
			const ListWznmMSquawk& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMSquawk(*(src.nodes[i]));
};

ListWznmMSquawk::~ListWznmMSquawk() {
	clear();
};

void ListWznmMSquawk::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMSquawk::size() const {
	return(nodes.size());
};

void ListWznmMSquawk::append(
			WznmMSquawk* rec
		) {
	nodes.push_back(rec);
};

WznmMSquawk* ListWznmMSquawk::operator[](
			const uint ix
		) {
	WznmMSquawk* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMSquawk& ListWznmMSquawk::operator=(
			const ListWznmMSquawk& src
		) {
	WznmMSquawk* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMSquawk(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMSquawk::operator==(
			const ListWznmMSquawk& comp
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

bool ListWznmMSquawk::operator!=(
			const ListWznmMSquawk& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMSquawk
 ******************************************************************************/

TblWznmMSquawk::TblWznmMSquawk() {
};

TblWznmMSquawk::~TblWznmMSquawk() {
};

bool TblWznmMSquawk::loadRecBySQL(
			const string& sqlstr
			, WznmMSquawk** rec
		) {
	return false;
};

ubigint TblWznmMSquawk::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSquawk& rst
		) {
	return 0;
};

ubigint TblWznmMSquawk::insertRec(
			WznmMSquawk* rec
		) {
	return 0;
};

ubigint TblWznmMSquawk::insertNewRec(
			WznmMSquawk** rec
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refJTitle
			, const string Title
			, const string Example
		) {
	ubigint retval = 0;
	WznmMSquawk* _rec = NULL;

	_rec = new WznmMSquawk(0, refIxVTbl, refUref, refJTitle, Title, Example);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMSquawk::appendNewRecToRst(
			ListWznmMSquawk& rst
			, WznmMSquawk** rec
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refJTitle
			, const string Title
			, const string Example
		) {
	ubigint retval = 0;
	WznmMSquawk* _rec = NULL;

	retval = insertNewRec(&_rec, refIxVTbl, refUref, refJTitle, Title, Example);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMSquawk::insertRst(
			ListWznmMSquawk& rst
			, bool transact
		) {
};

void TblWznmMSquawk::updateRec(
			WznmMSquawk* rec
		) {
};

void TblWznmMSquawk::updateRst(
			ListWznmMSquawk& rst
			, bool transact
		) {
};

void TblWznmMSquawk::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMSquawk::loadRecByRef(
			ubigint ref
			, WznmMSquawk** rec
		) {
	return false;
};

bool TblWznmMSquawk::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMSquawk** rec
		) {
	return false;
};

ubigint TblWznmMSquawk::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMSquawk::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMSquawk& rst
		) {
	ubigint numload = 0;
	WznmMSquawk* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMSquawk
 ******************************************************************************/

MyTblWznmMSquawk::MyTblWznmMSquawk() :
			TblWznmMSquawk()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMSquawk::~MyTblWznmMSquawk() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMSquawk::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMSquawk (refIxVTbl, refUref, refJTitle, Title, Example) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMSquawk SET refIxVTbl = ?, refUref = ?, refJTitle = ?, Title = ?, Example = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMSquawk WHERE ref = ?", false);
};

bool MyTblWznmMSquawk::loadRecBySQL(
			const string& sqlstr
			, WznmMSquawk** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMSquawk* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMSquawk::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMSquawk::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMSquawk();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refIxVTbl = atol((char*) dbrow[1]); else _rec->refIxVTbl = 0;
		if (dbrow[2]) _rec->refUref = atoll((char*) dbrow[2]); else _rec->refUref = 0;
		if (dbrow[3]) _rec->refJTitle = atoll((char*) dbrow[3]); else _rec->refJTitle = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->Example.assign(dbrow[5], dblengths[5]); else _rec->Example = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMSquawk::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSquawk& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMSquawk* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMSquawk::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMSquawk::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMSquawk();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refIxVTbl = atol((char*) dbrow[1]); else rec->refIxVTbl = 0;
			if (dbrow[2]) rec->refUref = atoll((char*) dbrow[2]); else rec->refUref = 0;
			if (dbrow[3]) rec->refJTitle = atoll((char*) dbrow[3]); else rec->refJTitle = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->Example.assign(dbrow[5], dblengths[5]); else rec->Example = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMSquawk::insertRec(
			WznmMSquawk* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Title.length();
	l[4] = rec->Example.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->refIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refUref,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refJTitle,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Example.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMSquawk::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMSquawk::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMSquawk::insertRst(
			ListWznmMSquawk& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMSquawk::updateRec(
			WznmMSquawk* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->Title.length();
	l[4] = rec->Example.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->refIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refUref,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refJTitle,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Example.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMSquawk::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMSquawk::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMSquawk::updateRst(
			ListWznmMSquawk& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMSquawk::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMSquawk::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMSquawk::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMSquawk::loadRecByRef(
			ubigint ref
			, WznmMSquawk** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMSquawk WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMSquawk::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMSquawk** rec
		) {
	return loadRecBySQL("SELECT ref, refIxVTbl, refUref, refJTitle, Title, Example FROM TblWznmMSquawk WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", rec);
};

ubigint MyTblWznmMSquawk::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMSquawk WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMSquawk
 ******************************************************************************/

PgTblWznmMSquawk::PgTblWznmMSquawk() :
			TblWznmMSquawk()
			, PgTable()
		{
};

PgTblWznmMSquawk::~PgTblWznmMSquawk() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMSquawk::initStatements() {
	createStatement("TblWznmMSquawk_insertRec", "INSERT INTO TblWznmMSquawk (refIxVTbl, refUref, refJTitle, Title, Example) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmMSquawk_updateRec", "UPDATE TblWznmMSquawk SET refIxVTbl = $1, refUref = $2, refJTitle = $3, Title = $4, Example = $5 WHERE ref = $6", 6);
	createStatement("TblWznmMSquawk_removeRecByRef", "DELETE FROM TblWznmMSquawk WHERE ref = $1", 1);

	createStatement("TblWznmMSquawk_loadRecByRef", "SELECT ref, refIxVTbl, refUref, refJTitle, Title, Example FROM TblWznmMSquawk WHERE ref = $1", 1);
	createStatement("TblWznmMSquawk_loadRecByRetReu", "SELECT ref, refIxVTbl, refUref, refJTitle, Title, Example FROM TblWznmMSquawk WHERE refIxVTbl = $1 AND refUref = $2", 2);
	createStatement("TblWznmMSquawk_loadRefsByRetReu", "SELECT ref FROM TblWznmMSquawk WHERE refIxVTbl = $1 AND refUref = $2", 2);
};

bool PgTblWznmMSquawk::loadRec(
			PGresult* res
			, WznmMSquawk** rec
		) {
	char* ptr;

	WznmMSquawk* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMSquawk();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title"),
			PQfnumber(res, "example")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refJTitle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Example.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMSquawk::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMSquawk& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMSquawk* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title"),
			PQfnumber(res, "example")
		};

		while (numread < numrow) {
			rec = new WznmMSquawk();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refJTitle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Example.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMSquawk::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMSquawk** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSquawk::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmMSquawk::loadRecBySQL(
			const string& sqlstr
			, WznmMSquawk** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSquawk::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMSquawk::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMSquawk& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSquawk::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMSquawk::insertRec(
			WznmMSquawk* rec
		) {
	PGresult* res;
	char* ptr;

	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refJTitle = htonl64(rec->refJTitle);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refJTitle,
		rec->Title.c_str(),
		rec->Example.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMSquawk_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMSquawk::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMSquawk::insertRst(
			ListWznmMSquawk& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMSquawk::updateRec(
			WznmMSquawk* rec
		) {
	PGresult* res;

	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refJTitle = htonl64(rec->refJTitle);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refJTitle,
		rec->Title.c_str(),
		rec->Example.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMSquawk_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMSquawk::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMSquawk::updateRst(
			ListWznmMSquawk& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMSquawk::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMSquawk_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMSquawk::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMSquawk::loadRecByRef(
			ubigint ref
			, WznmMSquawk** rec
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

	return loadRecByStmt("TblWznmMSquawk_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMSquawk::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMSquawk** rec
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmMSquawk_loadRecByRetReu", 2, vals, l, f, rec);
};

ubigint PgTblWznmMSquawk::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblWznmMSquawk_loadRefsByRetReu", 2, vals, l, f, append, refs);
};

#endif

