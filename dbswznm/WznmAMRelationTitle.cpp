/**
	* \file WznmAMRelationTitle.cpp
	* database access for table TblWznmAMRelationTitle (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmAMRelationTitle.h"

#include "WznmAMRelationTitle_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMRelationTitle
 ******************************************************************************/

WznmAMRelationTitle::WznmAMRelationTitle(
			const ubigint ref
			, const ubigint refWznmMRelation
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const string Title
		) {

	this->ref = ref;
	this->refWznmMRelation = refWznmMRelation;
	this->x1IxVType = x1IxVType;
	this->x2RefWznmMLocale = x2RefWznmMLocale;
	this->Title = Title;
};

bool WznmAMRelationTitle::operator==(
			const WznmAMRelationTitle& comp
		) {
	return false;
};

bool WznmAMRelationTitle::operator!=(
			const WznmAMRelationTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMRelationTitle
 ******************************************************************************/

ListWznmAMRelationTitle::ListWznmAMRelationTitle() {
};

ListWznmAMRelationTitle::ListWznmAMRelationTitle(
			const ListWznmAMRelationTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMRelationTitle(*(src.nodes[i]));
};

ListWznmAMRelationTitle::~ListWznmAMRelationTitle() {
	clear();
};

void ListWznmAMRelationTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMRelationTitle::size() const {
	return(nodes.size());
};

void ListWznmAMRelationTitle::append(
			WznmAMRelationTitle* rec
		) {
	nodes.push_back(rec);
};

WznmAMRelationTitle* ListWznmAMRelationTitle::operator[](
			const uint ix
		) {
	WznmAMRelationTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMRelationTitle& ListWznmAMRelationTitle::operator=(
			const ListWznmAMRelationTitle& src
		) {
	WznmAMRelationTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMRelationTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMRelationTitle::operator==(
			const ListWznmAMRelationTitle& comp
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

bool ListWznmAMRelationTitle::operator!=(
			const ListWznmAMRelationTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMRelationTitle
 ******************************************************************************/

TblWznmAMRelationTitle::TblWznmAMRelationTitle() {
};

TblWznmAMRelationTitle::~TblWznmAMRelationTitle() {
};

bool TblWznmAMRelationTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMRelationTitle** rec
		) {
	return false;
};

ubigint TblWznmAMRelationTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMRelationTitle& rst
		) {
	return 0;
};

ubigint TblWznmAMRelationTitle::insertRec(
			WznmAMRelationTitle* rec
		) {
	return 0;
};

ubigint TblWznmAMRelationTitle::insertNewRec(
			WznmAMRelationTitle** rec
			, const ubigint refWznmMRelation
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmAMRelationTitle* _rec = NULL;

	_rec = new WznmAMRelationTitle(0, refWznmMRelation, x1IxVType, x2RefWznmMLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMRelationTitle::appendNewRecToRst(
			ListWznmAMRelationTitle& rst
			, WznmAMRelationTitle** rec
			, const ubigint refWznmMRelation
			, const uint x1IxVType
			, const ubigint x2RefWznmMLocale
			, const string Title
		) {
	ubigint retval = 0;
	WznmAMRelationTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMRelation, x1IxVType, x2RefWznmMLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMRelationTitle::insertRst(
			ListWznmAMRelationTitle& rst
			, bool transact
		) {
};

void TblWznmAMRelationTitle::updateRec(
			WznmAMRelationTitle* rec
		) {
};

void TblWznmAMRelationTitle::updateRst(
			ListWznmAMRelationTitle& rst
			, bool transact
		) {
};

void TblWznmAMRelationTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMRelationTitle::loadRecByRef(
			ubigint ref
			, WznmAMRelationTitle** rec
		) {
	return false;
};

ubigint TblWznmAMRelationTitle::loadRefsByRel(
			ubigint refWznmMRelation
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMRelationTitle::loadRstByRel(
			ubigint refWznmMRelation
			, const bool append
			, ListWznmAMRelationTitle& rst
		) {
	return 0;
};

bool TblWznmAMRelationTitle::loadTitByRelTypLoc(
			ubigint refWznmMRelation
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	return false;
};

ubigint TblWznmAMRelationTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMRelationTitle& rst
		) {
	ubigint numload = 0;
	WznmAMRelationTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMRelationTitle
 ******************************************************************************/

MyTblWznmAMRelationTitle::MyTblWznmAMRelationTitle() :
			TblWznmAMRelationTitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMRelationTitle::~MyTblWznmAMRelationTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMRelationTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMRelationTitle (refWznmMRelation, x1IxVType, x2RefWznmMLocale, Title) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMRelationTitle SET refWznmMRelation = ?, x1IxVType = ?, x2RefWznmMLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMRelationTitle WHERE ref = ?", false);
};

bool MyTblWznmAMRelationTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMRelationTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMRelationTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMRelationTitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMRelationTitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMRelationTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMRelation = atoll((char*) dbrow[1]); else _rec->refWznmMRelation = 0;
		if (dbrow[2]) _rec->x1IxVType = atol((char*) dbrow[2]); else _rec->x1IxVType = 0;
		if (dbrow[3]) _rec->x2RefWznmMLocale = atoll((char*) dbrow[3]); else _rec->x2RefWznmMLocale = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMRelationTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMRelationTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMRelationTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMRelationTitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMRelationTitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMRelationTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMRelation = atoll((char*) dbrow[1]); else rec->refWznmMRelation = 0;
			if (dbrow[2]) rec->x1IxVType = atol((char*) dbrow[2]); else rec->x1IxVType = 0;
			if (dbrow[3]) rec->x2RefWznmMLocale = atoll((char*) dbrow[3]); else rec->x2RefWznmMLocale = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMRelationTitle::insertRec(
			WznmAMRelationTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMRelation,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxVType,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMRelationTitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMRelationTitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMRelationTitle::insertRst(
			ListWznmAMRelationTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMRelationTitle::updateRec(
			WznmAMRelationTitle* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMRelation,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxVType,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMRelationTitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMRelationTitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMRelationTitle::updateRst(
			ListWznmAMRelationTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMRelationTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMRelationTitle::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMRelationTitle::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMRelationTitle::loadRecByRef(
			ubigint ref
			, WznmAMRelationTitle** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMRelationTitle WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMRelationTitle::loadRefsByRel(
			ubigint refWznmMRelation
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMRelationTitle WHERE refWznmMRelation = " + to_string(refWznmMRelation) + "", append, refs);
};

ubigint MyTblWznmAMRelationTitle::loadRstByRel(
			ubigint refWznmMRelation
			, const bool append
			, ListWznmAMRelationTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMRelation, x1IxVType, x2RefWznmMLocale, Title FROM TblWznmAMRelationTitle WHERE refWznmMRelation = " + to_string(refWznmMRelation) + " ORDER BY x1IxVType ASC, x2RefWznmMLocale ASC", append, rst);
};

bool MyTblWznmAMRelationTitle::loadTitByRelTypLoc(
			ubigint refWznmMRelation
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmAMRelationTitle WHERE refWznmMRelation = " + to_string(refWznmMRelation) + " AND x1IxVType = " + to_string(x1IxVType) + " AND x2RefWznmMLocale = " + to_string(x2RefWznmMLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMRelationTitle
 ******************************************************************************/

PgTblWznmAMRelationTitle::PgTblWznmAMRelationTitle() :
			TblWznmAMRelationTitle()
			, PgTable()
		{
};

PgTblWznmAMRelationTitle::~PgTblWznmAMRelationTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMRelationTitle::initStatements() {
	createStatement("TblWznmAMRelationTitle_insertRec", "INSERT INTO TblWznmAMRelationTitle (refWznmMRelation, x1IxVType, x2RefWznmMLocale, Title) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmAMRelationTitle_updateRec", "UPDATE TblWznmAMRelationTitle SET refWznmMRelation = $1, x1IxVType = $2, x2RefWznmMLocale = $3, Title = $4 WHERE ref = $5", 5);
	createStatement("TblWznmAMRelationTitle_removeRecByRef", "DELETE FROM TblWznmAMRelationTitle WHERE ref = $1", 1);

	createStatement("TblWznmAMRelationTitle_loadRecByRef", "SELECT ref, refWznmMRelation, x1IxVType, x2RefWznmMLocale, Title FROM TblWznmAMRelationTitle WHERE ref = $1", 1);
	createStatement("TblWznmAMRelationTitle_loadRefsByRel", "SELECT ref FROM TblWznmAMRelationTitle WHERE refWznmMRelation = $1", 1);
	createStatement("TblWznmAMRelationTitle_loadRstByRel", "SELECT ref, refWznmMRelation, x1IxVType, x2RefWznmMLocale, Title FROM TblWznmAMRelationTitle WHERE refWznmMRelation = $1 ORDER BY x1IxVType ASC, x2RefWznmMLocale ASC", 1);
	createStatement("TblWznmAMRelationTitle_loadTitByRelTypLoc", "SELECT Title FROM TblWznmAMRelationTitle WHERE refWznmMRelation = $1 AND x1IxVType = $2 AND x2RefWznmMLocale = $3", 3);
};

bool PgTblWznmAMRelationTitle::loadRec(
			PGresult* res
			, WznmAMRelationTitle** rec
		) {
	char* ptr;

	WznmAMRelationTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMRelationTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmrelation"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMRelation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxVType = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMRelationTitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMRelationTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMRelationTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmrelation"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmAMRelationTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMRelation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxVType = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMRelationTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMRelationTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMRelationTitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMRelationTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMRelationTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMRelationTitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMRelationTitle::loadRecBySQL(
			const string& sqlstr
			, WznmAMRelationTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMRelationTitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMRelationTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMRelationTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMRelationTitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMRelationTitle::insertRec(
			WznmAMRelationTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMRelation = htonl64(rec->refWznmMRelation);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMRelation,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmAMRelationTitle_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMRelationTitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMRelationTitle::insertRst(
			ListWznmAMRelationTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMRelationTitle::updateRec(
			WznmAMRelationTitle* rec
		) {
	PGresult* res;

	ubigint _refWznmMRelation = htonl64(rec->refWznmMRelation);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMRelation,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMRelationTitle_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMRelationTitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMRelationTitle::updateRst(
			ListWznmAMRelationTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMRelationTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMRelationTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMRelationTitle::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMRelationTitle::loadRecByRef(
			ubigint ref
			, WznmAMRelationTitle** rec
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

	return loadRecByStmt("TblWznmAMRelationTitle_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMRelationTitle::loadRefsByRel(
			ubigint refWznmMRelation
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMRelation = htonl64(refWznmMRelation);

	const char* vals[] = {
		(char*) &_refWznmMRelation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMRelationTitle_loadRefsByRel", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMRelationTitle::loadRstByRel(
			ubigint refWznmMRelation
			, const bool append
			, ListWznmAMRelationTitle& rst
		) {
	ubigint _refWznmMRelation = htonl64(refWznmMRelation);

	const char* vals[] = {
		(char*) &_refWznmMRelation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMRelationTitle_loadRstByRel", 1, vals, l, f, append, rst);
};

bool PgTblWznmAMRelationTitle::loadTitByRelTypLoc(
			ubigint refWznmMRelation
			, uint x1IxVType
			, ubigint x2RefWznmMLocale
			, string& Title
		) {
	ubigint _refWznmMRelation = htonl64(refWznmMRelation);
	uint _x1IxVType = htonl(x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(x2RefWznmMLocale);

	const char* vals[] = {
		(char*) &_refWznmMRelation,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadStringByStmt("TblWznmAMRelationTitle_loadTitByRelTypLoc", 3, vals, l, f, Title);
};

#endif

