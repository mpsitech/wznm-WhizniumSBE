/**
	* \file WznmJMPersonLastname.cpp
	* database access for table TblWznmJMPersonLastname (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmJMPersonLastname.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMPersonLastname
 ******************************************************************************/

WznmJMPersonLastname::WznmJMPersonLastname(
			const ubigint ref
			, const ubigint refWznmMPerson
			, const uint x1Startd
			, const string Lastname
		) {

	this->ref = ref;
	this->refWznmMPerson = refWznmMPerson;
	this->x1Startd = x1Startd;
	this->Lastname = Lastname;
};

bool WznmJMPersonLastname::operator==(
			const WznmJMPersonLastname& comp
		) {
	return false;
};

bool WznmJMPersonLastname::operator!=(
			const WznmJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMPersonLastname
 ******************************************************************************/

ListWznmJMPersonLastname::ListWznmJMPersonLastname() {
};

ListWznmJMPersonLastname::ListWznmJMPersonLastname(
			const ListWznmJMPersonLastname& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMPersonLastname(*(src.nodes[i]));
};

ListWznmJMPersonLastname::~ListWznmJMPersonLastname() {
	clear();
};

void ListWznmJMPersonLastname::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMPersonLastname::size() const {
	return(nodes.size());
};

void ListWznmJMPersonLastname::append(
			WznmJMPersonLastname* rec
		) {
	nodes.push_back(rec);
};

WznmJMPersonLastname* ListWznmJMPersonLastname::operator[](
			const uint ix
		) {
	WznmJMPersonLastname* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMPersonLastname& ListWznmJMPersonLastname::operator=(
			const ListWznmJMPersonLastname& src
		) {
	WznmJMPersonLastname* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMPersonLastname(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMPersonLastname::operator==(
			const ListWznmJMPersonLastname& comp
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

bool ListWznmJMPersonLastname::operator!=(
			const ListWznmJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMPersonLastname
 ******************************************************************************/

TblWznmJMPersonLastname::TblWznmJMPersonLastname() {
};

TblWznmJMPersonLastname::~TblWznmJMPersonLastname() {
};

bool TblWznmJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, WznmJMPersonLastname** rec
		) {
	return false;
};

ubigint TblWznmJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMPersonLastname& rst
		) {
	return 0;
};

ubigint TblWznmJMPersonLastname::insertRec(
			WznmJMPersonLastname* rec
		) {
	return 0;
};

ubigint TblWznmJMPersonLastname::insertNewRec(
			WznmJMPersonLastname** rec
			, const ubigint refWznmMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	WznmJMPersonLastname* _rec = NULL;

	_rec = new WznmJMPersonLastname(0, refWznmMPerson, x1Startd, Lastname);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMPersonLastname::appendNewRecToRst(
			ListWznmJMPersonLastname& rst
			, WznmJMPersonLastname** rec
			, const ubigint refWznmMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	WznmJMPersonLastname* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMPerson, x1Startd, Lastname);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMPersonLastname::insertRst(
			ListWznmJMPersonLastname& rst
			, bool transact
		) {
};

void TblWznmJMPersonLastname::updateRec(
			WznmJMPersonLastname* rec
		) {
};

void TblWznmJMPersonLastname::updateRst(
			ListWznmJMPersonLastname& rst
			, bool transact
		) {
};

void TblWznmJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMPersonLastname::loadRecByRef(
			ubigint ref
			, WznmJMPersonLastname** rec
		) {
	return false;
};

bool TblWznmJMPersonLastname::loadRecByPrsSta(
			ubigint refWznmMPerson
			, uint x1Startd
			, WznmJMPersonLastname** rec
		) {
	return false;
};

ubigint TblWznmJMPersonLastname::loadRefsByPrs(
			ubigint refWznmMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMPersonLastname::loadRstByPrs(
			ubigint refWznmMPerson
			, const bool append
			, ListWznmJMPersonLastname& rst
		) {
	return 0;
};

ubigint TblWznmJMPersonLastname::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMPersonLastname& rst
		) {
	ubigint numload = 0;
	WznmJMPersonLastname* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMPersonLastname
 ******************************************************************************/

MyTblWznmJMPersonLastname::MyTblWznmJMPersonLastname() :
			TblWznmJMPersonLastname()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMPersonLastname::~MyTblWznmJMPersonLastname() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMPersonLastname::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMPersonLastname (refWznmMPerson, x1Startd, Lastname) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMPersonLastname SET refWznmMPerson = ?, x1Startd = ?, Lastname = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMPersonLastname WHERE ref = ?", false);
};

bool MyTblWznmJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, WznmJMPersonLastname** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMPersonLastname* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMPersonLastname::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMPersonLastname::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJMPersonLastname();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMPerson = atoll((char*) dbrow[1]); else _rec->refWznmMPerson = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->Lastname.assign(dbrow[3], dblengths[3]); else _rec->Lastname = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMPersonLastname& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMPersonLastname* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMPersonLastname::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMPersonLastname::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJMPersonLastname();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMPerson = atoll((char*) dbrow[1]); else rec->refWznmMPerson = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->Lastname.assign(dbrow[3], dblengths[3]); else rec->Lastname = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMPersonLastname::insertRec(
			WznmJMPersonLastname* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMPersonLastname::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMPersonLastname::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMPersonLastname::insertRst(
			ListWznmJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMPersonLastname::updateRec(
			WznmJMPersonLastname* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMPersonLastname::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMPersonLastname::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMPersonLastname::updateRst(
			ListWznmJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMPersonLastname::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMPersonLastname::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMPersonLastname::loadRecByRef(
			ubigint ref
			, WznmJMPersonLastname** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMPersonLastname WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMPersonLastname::loadRecByPrsSta(
			ubigint refWznmMPerson
			, uint x1Startd
			, WznmJMPersonLastname** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMPerson, x1Startd, Lastname FROM TblWznmJMPersonLastname WHERE refWznmMPerson = " + to_string(refWznmMPerson) + " AND x1Startd <= " + to_string(x1Startd) + " ORDER BY x1Startd DESC LIMIT 0,1", rec);
};

ubigint MyTblWznmJMPersonLastname::loadRefsByPrs(
			ubigint refWznmMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMPersonLastname WHERE refWznmMPerson = " + to_string(refWznmMPerson) + "", append, refs);
};

ubigint MyTblWznmJMPersonLastname::loadRstByPrs(
			ubigint refWznmMPerson
			, const bool append
			, ListWznmJMPersonLastname& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMPerson, x1Startd, Lastname FROM TblWznmJMPersonLastname WHERE refWznmMPerson = " + to_string(refWznmMPerson) + " ORDER BY x1Startd ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMPersonLastname
 ******************************************************************************/

PgTblWznmJMPersonLastname::PgTblWznmJMPersonLastname() :
			TblWznmJMPersonLastname()
			, PgTable()
		{
};

PgTblWznmJMPersonLastname::~PgTblWznmJMPersonLastname() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMPersonLastname::initStatements() {
	createStatement("TblWznmJMPersonLastname_insertRec", "INSERT INTO TblWznmJMPersonLastname (refWznmMPerson, x1Startd, Lastname) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWznmJMPersonLastname_updateRec", "UPDATE TblWznmJMPersonLastname SET refWznmMPerson = $1, x1Startd = $2, Lastname = $3 WHERE ref = $4", 4);
	createStatement("TblWznmJMPersonLastname_removeRecByRef", "DELETE FROM TblWznmJMPersonLastname WHERE ref = $1", 1);

	createStatement("TblWznmJMPersonLastname_loadRecByRef", "SELECT ref, refWznmMPerson, x1Startd, Lastname FROM TblWznmJMPersonLastname WHERE ref = $1", 1);
	createStatement("TblWznmJMPersonLastname_loadRecByPrsSta", "SELECT ref, refWznmMPerson, x1Startd, Lastname FROM TblWznmJMPersonLastname WHERE refWznmMPerson = $1 AND x1Startd <= $2 ORDER BY x1Startd DESC OFFSET 0 LIMIT 1", 2);
	createStatement("TblWznmJMPersonLastname_loadRefsByPrs", "SELECT ref FROM TblWznmJMPersonLastname WHERE refWznmMPerson = $1", 1);
	createStatement("TblWznmJMPersonLastname_loadRstByPrs", "SELECT ref, refWznmMPerson, x1Startd, Lastname FROM TblWznmJMPersonLastname WHERE refWznmMPerson = $1 ORDER BY x1Startd ASC", 1);
};

bool PgTblWznmJMPersonLastname::loadRec(
			PGresult* res
			, WznmJMPersonLastname** rec
		) {
	char* ptr;

	WznmJMPersonLastname* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMPersonLastname();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmperson"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "lastname")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMPersonLastname::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMPersonLastname& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMPersonLastname* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmperson"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "lastname")
		};

		while (numread < numrow) {
			rec = new WznmJMPersonLastname();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMPersonLastname::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMPersonLastname** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMPersonLastname::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMPersonLastname::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMPersonLastname& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMPersonLastname::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, WznmJMPersonLastname** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMPersonLastname::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMPersonLastname& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMPersonLastname::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMPersonLastname::insertRec(
			WznmJMPersonLastname* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMPerson = htonl64(rec->refWznmMPerson);
	uint _x1Startd = htonl(rec->x1Startd);

	const char* vals[] = {
		(char*) &_refWznmMPerson,
		(char*) &_x1Startd,
		rec->Lastname.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmJMPersonLastname_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMPersonLastname::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMPersonLastname::insertRst(
			ListWznmJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMPersonLastname::updateRec(
			WznmJMPersonLastname* rec
		) {
	PGresult* res;

	ubigint _refWznmMPerson = htonl64(rec->refWznmMPerson);
	uint _x1Startd = htonl(rec->x1Startd);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMPerson,
		(char*) &_x1Startd,
		rec->Lastname.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmJMPersonLastname_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMPersonLastname::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMPersonLastname::updateRst(
			ListWznmJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMPersonLastname::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMPersonLastname_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMPersonLastname::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMPersonLastname::loadRecByRef(
			ubigint ref
			, WznmJMPersonLastname** rec
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

	return loadRecByStmt("TblWznmJMPersonLastname_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMPersonLastname::loadRecByPrsSta(
			ubigint refWznmMPerson
			, uint x1Startd
			, WznmJMPersonLastname** rec
		) {
	ubigint _refWznmMPerson = htonl64(refWznmMPerson);
	uint _x1Startd = htonl(x1Startd);

	const char* vals[] = {
		(char*) &_refWznmMPerson,
		(char*) &_x1Startd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMPersonLastname_loadRecByPrsSta", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMPersonLastname::loadRefsByPrs(
			ubigint refWznmMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMPerson = htonl64(refWznmMPerson);

	const char* vals[] = {
		(char*) &_refWznmMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMPersonLastname_loadRefsByPrs", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMPersonLastname::loadRstByPrs(
			ubigint refWznmMPerson
			, const bool append
			, ListWznmJMPersonLastname& rst
		) {
	ubigint _refWznmMPerson = htonl64(refWznmMPerson);

	const char* vals[] = {
		(char*) &_refWznmMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMPersonLastname_loadRstByPrs", 1, vals, l, f, append, rst);
};

#endif

