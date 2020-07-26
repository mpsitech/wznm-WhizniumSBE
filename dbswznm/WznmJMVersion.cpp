/**
	* \file WznmJMVersion.cpp
	* database access for table TblWznmJMVersion (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmJMVersion.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmJMVersion
 ******************************************************************************/

WznmJMVersion::WznmJMVersion(
			const ubigint ref
			, const ubigint refWznmMVersion
			, const ubigint x1RefWznmMLocale
			, const string About1
			, const string About2
			, const string About3
		) {

	this->ref = ref;
	this->refWznmMVersion = refWznmMVersion;
	this->x1RefWznmMLocale = x1RefWznmMLocale;
	this->About1 = About1;
	this->About2 = About2;
	this->About3 = About3;
};

bool WznmJMVersion::operator==(
			const WznmJMVersion& comp
		) {
	return false;
};

bool WznmJMVersion::operator!=(
			const WznmJMVersion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmJMVersion
 ******************************************************************************/

ListWznmJMVersion::ListWznmJMVersion() {
};

ListWznmJMVersion::ListWznmJMVersion(
			const ListWznmJMVersion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmJMVersion(*(src.nodes[i]));
};

ListWznmJMVersion::~ListWznmJMVersion() {
	clear();
};

void ListWznmJMVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmJMVersion::size() const {
	return(nodes.size());
};

void ListWznmJMVersion::append(
			WznmJMVersion* rec
		) {
	nodes.push_back(rec);
};

WznmJMVersion* ListWznmJMVersion::operator[](
			const uint ix
		) {
	WznmJMVersion* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmJMVersion& ListWznmJMVersion::operator=(
			const ListWznmJMVersion& src
		) {
	WznmJMVersion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmJMVersion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmJMVersion::operator==(
			const ListWznmJMVersion& comp
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

bool ListWznmJMVersion::operator!=(
			const ListWznmJMVersion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmJMVersion
 ******************************************************************************/

TblWznmJMVersion::TblWznmJMVersion() {
};

TblWznmJMVersion::~TblWznmJMVersion() {
};

bool TblWznmJMVersion::loadRecBySQL(
			const string& sqlstr
			, WznmJMVersion** rec
		) {
	return false;
};

ubigint TblWznmJMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMVersion& rst
		) {
	return 0;
};

ubigint TblWznmJMVersion::insertRec(
			WznmJMVersion* rec
		) {
	return 0;
};

ubigint TblWznmJMVersion::insertNewRec(
			WznmJMVersion** rec
			, const ubigint refWznmMVersion
			, const ubigint x1RefWznmMLocale
			, const string About1
			, const string About2
			, const string About3
		) {
	ubigint retval = 0;
	WznmJMVersion* _rec = NULL;

	_rec = new WznmJMVersion(0, refWznmMVersion, x1RefWznmMLocale, About1, About2, About3);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmJMVersion::appendNewRecToRst(
			ListWznmJMVersion& rst
			, WznmJMVersion** rec
			, const ubigint refWznmMVersion
			, const ubigint x1RefWznmMLocale
			, const string About1
			, const string About2
			, const string About3
		) {
	ubigint retval = 0;
	WznmJMVersion* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMVersion, x1RefWznmMLocale, About1, About2, About3);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmJMVersion::insertRst(
			ListWznmJMVersion& rst
			, bool transact
		) {
};

void TblWznmJMVersion::updateRec(
			WznmJMVersion* rec
		) {
};

void TblWznmJMVersion::updateRst(
			ListWznmJMVersion& rst
			, bool transact
		) {
};

void TblWznmJMVersion::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmJMVersion::loadRecByRef(
			ubigint ref
			, WznmJMVersion** rec
		) {
	return false;
};

bool TblWznmJMVersion::loadRecByVerLoc(
			ubigint refWznmMVersion
			, ubigint x1RefWznmMLocale
			, WznmJMVersion** rec
		) {
	return false;
};

ubigint TblWznmJMVersion::loadRefsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmJMVersion::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmJMVersion& rst
		) {
	return 0;
};

ubigint TblWznmJMVersion::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmJMVersion& rst
		) {
	ubigint numload = 0;
	WznmJMVersion* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmJMVersion
 ******************************************************************************/

MyTblWznmJMVersion::MyTblWznmJMVersion() :
			TblWznmJMVersion()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmJMVersion::~MyTblWznmJMVersion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmJMVersion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmJMVersion (refWznmMVersion, x1RefWznmMLocale, About1, About2, About3) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmJMVersion SET refWznmMVersion = ?, x1RefWznmMLocale = ?, About1 = ?, About2 = ?, About3 = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmJMVersion WHERE ref = ?", false);
};

bool MyTblWznmJMVersion::loadRecBySQL(
			const string& sqlstr
			, WznmJMVersion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmJMVersion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMVersion::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMVersion::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmJMVersion();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMVersion = atoll((char*) dbrow[1]); else _rec->refWznmMVersion = 0;
		if (dbrow[2]) _rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else _rec->x1RefWznmMLocale = 0;
		if (dbrow[3]) _rec->About1.assign(dbrow[3], dblengths[3]); else _rec->About1 = "";
		if (dbrow[4]) _rec->About2.assign(dbrow[4], dblengths[4]); else _rec->About2 = "";
		if (dbrow[5]) _rec->About3.assign(dbrow[5], dblengths[5]); else _rec->About3 = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmJMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMVersion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmJMVersion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmJMVersion::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmJMVersion::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmJMVersion();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMVersion = atoll((char*) dbrow[1]); else rec->refWznmMVersion = 0;
			if (dbrow[2]) rec->x1RefWznmMLocale = atoll((char*) dbrow[2]); else rec->x1RefWznmMLocale = 0;
			if (dbrow[3]) rec->About1.assign(dbrow[3], dblengths[3]); else rec->About1 = "";
			if (dbrow[4]) rec->About2.assign(dbrow[4], dblengths[4]); else rec->About2 = "";
			if (dbrow[5]) rec->About3.assign(dbrow[5], dblengths[5]); else rec->About3 = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmJMVersion::insertRec(
			WznmJMVersion* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->About1.length();
	l[3] = rec->About2.length();
	l[4] = rec->About3.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->About1.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->About2.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->About3.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmJMVersion::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmJMVersion::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmJMVersion::insertRst(
			ListWznmJMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmJMVersion::updateRec(
			WznmJMVersion* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->About1.length();
	l[3] = rec->About2.length();
	l[4] = rec->About3.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->About1.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->About2.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->About3.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmJMVersion::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmJMVersion::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmJMVersion::updateRst(
			ListWznmJMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmJMVersion::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmJMVersion::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmJMVersion::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmJMVersion::loadRecByRef(
			ubigint ref
			, WznmJMVersion** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmJMVersion WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmJMVersion::loadRecByVerLoc(
			ubigint refWznmMVersion
			, ubigint x1RefWznmMLocale
			, WznmJMVersion** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMVersion, x1RefWznmMLocale, About1, About2, About3 FROM TblWznmJMVersion WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND x1RefWznmMLocale = " + to_string(x1RefWznmMLocale) + "", rec);
};

ubigint MyTblWznmJMVersion::loadRefsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmJMVersion WHERE refWznmMVersion = " + to_string(refWznmMVersion) + "", append, refs);
};

ubigint MyTblWznmJMVersion::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmJMVersion& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMVersion, x1RefWznmMLocale, About1, About2, About3 FROM TblWznmJMVersion WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY x1RefWznmMLocale ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmJMVersion
 ******************************************************************************/

PgTblWznmJMVersion::PgTblWznmJMVersion() :
			TblWznmJMVersion()
			, PgTable()
		{
};

PgTblWznmJMVersion::~PgTblWznmJMVersion() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmJMVersion::initStatements() {
	createStatement("TblWznmJMVersion_insertRec", "INSERT INTO TblWznmJMVersion (refWznmMVersion, x1RefWznmMLocale, About1, About2, About3) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmJMVersion_updateRec", "UPDATE TblWznmJMVersion SET refWznmMVersion = $1, x1RefWznmMLocale = $2, About1 = $3, About2 = $4, About3 = $5 WHERE ref = $6", 6);
	createStatement("TblWznmJMVersion_removeRecByRef", "DELETE FROM TblWznmJMVersion WHERE ref = $1", 1);

	createStatement("TblWznmJMVersion_loadRecByRef", "SELECT ref, refWznmMVersion, x1RefWznmMLocale, About1, About2, About3 FROM TblWznmJMVersion WHERE ref = $1", 1);
	createStatement("TblWznmJMVersion_loadRecByVerLoc", "SELECT ref, refWznmMVersion, x1RefWznmMLocale, About1, About2, About3 FROM TblWznmJMVersion WHERE refWznmMVersion = $1 AND x1RefWznmMLocale = $2", 2);
	createStatement("TblWznmJMVersion_loadRefsByVer", "SELECT ref FROM TblWznmJMVersion WHERE refWznmMVersion = $1", 1);
	createStatement("TblWznmJMVersion_loadRstByVer", "SELECT ref, refWznmMVersion, x1RefWznmMLocale, About1, About2, About3 FROM TblWznmJMVersion WHERE refWznmMVersion = $1 ORDER BY x1RefWznmMLocale ASC", 1);
};

bool PgTblWznmJMVersion::loadRec(
			PGresult* res
			, WznmJMVersion** rec
		) {
	char* ptr;

	WznmJMVersion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmJMVersion();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "about1"),
			PQfnumber(res, "about2"),
			PQfnumber(res, "about3")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->About1.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->About2.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->About3.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmJMVersion::loadRst(
			PGresult* res
			, const bool append
			, ListWznmJMVersion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmJMVersion* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "x1refwznmmlocale"),
			PQfnumber(res, "about1"),
			PQfnumber(res, "about2"),
			PQfnumber(res, "about3")
		};

		while (numread < numrow) {
			rec = new WznmJMVersion();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->About1.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->About2.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->About3.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmJMVersion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmJMVersion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVersion::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMVersion::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmJMVersion& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVersion::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmJMVersion::loadRecBySQL(
			const string& sqlstr
			, WznmJMVersion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVersion::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmJMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmJMVersion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVersion::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmJMVersion::insertRec(
			WznmJMVersion* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		(char*) &_x1RefWznmMLocale,
		rec->About1.c_str(),
		rec->About2.c_str(),
		rec->About3.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmJMVersion_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmJMVersion::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmJMVersion::insertRst(
			ListWznmJMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmJMVersion::updateRec(
			WznmJMVersion* rec
		) {
	PGresult* res;

	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _x1RefWznmMLocale = htonl64(rec->x1RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		(char*) &_x1RefWznmMLocale,
		rec->About1.c_str(),
		rec->About2.c_str(),
		rec->About3.c_str(),
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

	res = PQexecPrepared(dbs, "TblWznmJMVersion_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMVersion::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmJMVersion::updateRst(
			ListWznmJMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmJMVersion::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmJMVersion_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmJMVersion::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmJMVersion::loadRecByRef(
			ubigint ref
			, WznmJMVersion** rec
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

	return loadRecByStmt("TblWznmJMVersion_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmJMVersion::loadRecByVerLoc(
			ubigint refWznmMVersion
			, ubigint x1RefWznmMLocale
			, WznmJMVersion** rec
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);
	ubigint _x1RefWznmMLocale = htonl64(x1RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		(char*) &_x1RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmJMVersion_loadRecByVerLoc", 2, vals, l, f, rec);
};

ubigint PgTblWznmJMVersion::loadRefsByVer(
			ubigint refWznmMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmJMVersion_loadRefsByVer", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmJMVersion::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmJMVersion& rst
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmJMVersion_loadRstByVer", 1, vals, l, f, append, rst);
};

#endif

