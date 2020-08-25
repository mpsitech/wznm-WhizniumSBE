/**
	* \file WznmMCapability.cpp
	* database access for table TblWznmMCapability (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmMCapability.h"

#include "WznmMCapability_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMCapability
 ******************************************************************************/

WznmMCapability::WznmMCapability(
			const ubigint ref
			, const ubigint refWznmMVersion
			, const ubigint tplRefWznmMCapability
			, const string sref
			, const uint ixWArtefact
			, const string Title
		) {

	this->ref = ref;
	this->refWznmMVersion = refWznmMVersion;
	this->tplRefWznmMCapability = tplRefWznmMCapability;
	this->sref = sref;
	this->ixWArtefact = ixWArtefact;
	this->Title = Title;
};

bool WznmMCapability::operator==(
			const WznmMCapability& comp
		) {
	return false;
};

bool WznmMCapability::operator!=(
			const WznmMCapability& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMCapability
 ******************************************************************************/

ListWznmMCapability::ListWznmMCapability() {
};

ListWznmMCapability::ListWznmMCapability(
			const ListWznmMCapability& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMCapability(*(src.nodes[i]));
};

ListWznmMCapability::~ListWznmMCapability() {
	clear();
};

void ListWznmMCapability::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMCapability::size() const {
	return(nodes.size());
};

void ListWznmMCapability::append(
			WznmMCapability* rec
		) {
	nodes.push_back(rec);
};

WznmMCapability* ListWznmMCapability::operator[](
			const uint ix
		) {
	WznmMCapability* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMCapability& ListWznmMCapability::operator=(
			const ListWznmMCapability& src
		) {
	WznmMCapability* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMCapability(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMCapability::operator==(
			const ListWznmMCapability& comp
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

bool ListWznmMCapability::operator!=(
			const ListWznmMCapability& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMCapability
 ******************************************************************************/

TblWznmMCapability::TblWznmMCapability() {
};

TblWznmMCapability::~TblWznmMCapability() {
};

bool TblWznmMCapability::loadRecBySQL(
			const string& sqlstr
			, WznmMCapability** rec
		) {
	return false;
};

ubigint TblWznmMCapability::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMCapability& rst
		) {
	return 0;
};

ubigint TblWznmMCapability::insertRec(
			WznmMCapability* rec
		) {
	return 0;
};

ubigint TblWznmMCapability::insertNewRec(
			WznmMCapability** rec
			, const ubigint refWznmMVersion
			, const ubigint tplRefWznmMCapability
			, const string sref
			, const uint ixWArtefact
			, const string Title
		) {
	ubigint retval = 0;
	WznmMCapability* _rec = NULL;

	_rec = new WznmMCapability(0, refWznmMVersion, tplRefWznmMCapability, sref, ixWArtefact, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMCapability::appendNewRecToRst(
			ListWznmMCapability& rst
			, WznmMCapability** rec
			, const ubigint refWznmMVersion
			, const ubigint tplRefWznmMCapability
			, const string sref
			, const uint ixWArtefact
			, const string Title
		) {
	ubigint retval = 0;
	WznmMCapability* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMVersion, tplRefWznmMCapability, sref, ixWArtefact, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMCapability::insertRst(
			ListWznmMCapability& rst
			, bool transact
		) {
};

void TblWznmMCapability::updateRec(
			WznmMCapability* rec
		) {
};

void TblWznmMCapability::updateRst(
			ListWznmMCapability& rst
			, bool transact
		) {
};

void TblWznmMCapability::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMCapability::loadRecByRef(
			ubigint ref
			, WznmMCapability** rec
		) {
	return false;
};

ubigint TblWznmMCapability::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMCapability& rst
		) {
	return 0;
};

ubigint TblWznmMCapability::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMCapability& rst
		) {
	ubigint numload = 0;
	WznmMCapability* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMCapability
 ******************************************************************************/

MyTblWznmMCapability::MyTblWznmMCapability() :
			TblWznmMCapability()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMCapability::~MyTblWznmMCapability() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMCapability::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMCapability (refWznmMVersion, tplRefWznmMCapability, sref, ixWArtefact, Title) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMCapability SET refWznmMVersion = ?, tplRefWznmMCapability = ?, sref = ?, ixWArtefact = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMCapability WHERE ref = ?", false);
};

bool MyTblWznmMCapability::loadRecBySQL(
			const string& sqlstr
			, WznmMCapability** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMCapability* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMCapability::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMCapability::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMCapability();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMVersion = atoll((char*) dbrow[1]); else _rec->refWznmMVersion = 0;
		if (dbrow[2]) _rec->tplRefWznmMCapability = atoll((char*) dbrow[2]); else _rec->tplRefWznmMCapability = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->ixWArtefact = atol((char*) dbrow[4]); else _rec->ixWArtefact = 0;
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMCapability::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMCapability& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMCapability* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMCapability::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMCapability::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMCapability();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMVersion = atoll((char*) dbrow[1]); else rec->refWznmMVersion = 0;
			if (dbrow[2]) rec->tplRefWznmMCapability = atoll((char*) dbrow[2]); else rec->tplRefWznmMCapability = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->ixWArtefact = atol((char*) dbrow[4]); else rec->ixWArtefact = 0;
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMCapability::insertRec(
			WznmMCapability* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->tplRefWznmMCapability,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWArtefact,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMCapability::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMCapability::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMCapability::insertRst(
			ListWznmMCapability& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMCapability::updateRec(
			WznmMCapability* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->tplRefWznmMCapability,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWArtefact,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMCapability::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMCapability::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMCapability::updateRst(
			ListWznmMCapability& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMCapability::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMCapability::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMCapability::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMCapability::loadRecByRef(
			ubigint ref
			, WznmMCapability** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMCapability WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMCapability::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMCapability& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMVersion, tplRefWznmMCapability, sref, ixWArtefact, Title FROM TblWznmMCapability WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMCapability
 ******************************************************************************/

PgTblWznmMCapability::PgTblWznmMCapability() :
			TblWznmMCapability()
			, PgTable()
		{
};

PgTblWznmMCapability::~PgTblWznmMCapability() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMCapability::initStatements() {
	createStatement("TblWznmMCapability_insertRec", "INSERT INTO TblWznmMCapability (refWznmMVersion, tplRefWznmMCapability, sref, ixWArtefact, Title) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmMCapability_updateRec", "UPDATE TblWznmMCapability SET refWznmMVersion = $1, tplRefWznmMCapability = $2, sref = $3, ixWArtefact = $4, Title = $5 WHERE ref = $6", 6);
	createStatement("TblWznmMCapability_removeRecByRef", "DELETE FROM TblWznmMCapability WHERE ref = $1", 1);

	createStatement("TblWznmMCapability_loadRecByRef", "SELECT ref, refWznmMVersion, tplRefWznmMCapability, sref, ixWArtefact, Title FROM TblWznmMCapability WHERE ref = $1", 1);
	createStatement("TblWznmMCapability_loadRstByVer", "SELECT ref, refWznmMVersion, tplRefWznmMCapability, sref, ixWArtefact, Title FROM TblWznmMCapability WHERE refWznmMVersion = $1 ORDER BY sref ASC", 1);
};

bool PgTblWznmMCapability::loadRec(
			PGresult* res
			, WznmMCapability** rec
		) {
	char* ptr;

	WznmMCapability* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMCapability();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "tplrefwznmmcapability"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwartefact"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->tplRefWznmMCapability = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWArtefact = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMCapability::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMCapability& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMCapability* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "tplrefwznmmcapability"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwartefact"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmMCapability();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->tplRefWznmMCapability = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWArtefact = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMCapability::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMCapability** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCapability::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMCapability::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMCapability& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCapability::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMCapability::loadRecBySQL(
			const string& sqlstr
			, WznmMCapability** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCapability::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMCapability::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMCapability& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCapability::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMCapability::insertRec(
			WznmMCapability* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _tplRefWznmMCapability = htonl64(rec->tplRefWznmMCapability);
	uint _ixWArtefact = htonl(rec->ixWArtefact);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		(char*) &_tplRefWznmMCapability,
		rec->sref.c_str(),
		(char*) &_ixWArtefact,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMCapability_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCapability::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMCapability::insertRst(
			ListWznmMCapability& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMCapability::updateRec(
			WznmMCapability* rec
		) {
	PGresult* res;

	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _tplRefWznmMCapability = htonl64(rec->tplRefWznmMCapability);
	uint _ixWArtefact = htonl(rec->ixWArtefact);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		(char*) &_tplRefWznmMCapability,
		rec->sref.c_str(),
		(char*) &_ixWArtefact,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMCapability_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMCapability::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMCapability::updateRst(
			ListWznmMCapability& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMCapability::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMCapability_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMCapability::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMCapability::loadRecByRef(
			ubigint ref
			, WznmMCapability** rec
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

	return loadRecByStmt("TblWznmMCapability_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMCapability::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMCapability& rst
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMCapability_loadRstByVer", 1, vals, l, f, append, rst);
};

#endif

