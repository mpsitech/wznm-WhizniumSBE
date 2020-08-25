/**
	* \file WznmMMachtype.cpp
	* database access for table TblWznmMMachtype (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmMMachtype.h"

#include "WznmMMachtype_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMMachtype
 ******************************************************************************/

WznmMMachtype::WznmMMachtype(
			const ubigint ref
			, const string sref
			, const uint ixVArch
			, const string srefKOs
			, const ubigint cchRefWznmMMachine
			, const string srefKPkgmgr
			, const string Comment
		) {

	this->ref = ref;
	this->sref = sref;
	this->ixVArch = ixVArch;
	this->srefKOs = srefKOs;
	this->cchRefWznmMMachine = cchRefWznmMMachine;
	this->srefKPkgmgr = srefKPkgmgr;
	this->Comment = Comment;
};

bool WznmMMachtype::operator==(
			const WznmMMachtype& comp
		) {
	return false;
};

bool WznmMMachtype::operator!=(
			const WznmMMachtype& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMMachtype
 ******************************************************************************/

ListWznmMMachtype::ListWznmMMachtype() {
};

ListWznmMMachtype::ListWznmMMachtype(
			const ListWznmMMachtype& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMMachtype(*(src.nodes[i]));
};

ListWznmMMachtype::~ListWznmMMachtype() {
	clear();
};

void ListWznmMMachtype::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMMachtype::size() const {
	return(nodes.size());
};

void ListWznmMMachtype::append(
			WznmMMachtype* rec
		) {
	nodes.push_back(rec);
};

WznmMMachtype* ListWznmMMachtype::operator[](
			const uint ix
		) {
	WznmMMachtype* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMMachtype& ListWznmMMachtype::operator=(
			const ListWznmMMachtype& src
		) {
	WznmMMachtype* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMMachtype(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMMachtype::operator==(
			const ListWznmMMachtype& comp
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

bool ListWznmMMachtype::operator!=(
			const ListWznmMMachtype& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMMachtype
 ******************************************************************************/

TblWznmMMachtype::TblWznmMMachtype() {
};

TblWznmMMachtype::~TblWznmMMachtype() {
};

bool TblWznmMMachtype::loadRecBySQL(
			const string& sqlstr
			, WznmMMachtype** rec
		) {
	return false;
};

ubigint TblWznmMMachtype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMMachtype& rst
		) {
	return 0;
};

ubigint TblWznmMMachtype::insertRec(
			WznmMMachtype* rec
		) {
	return 0;
};

ubigint TblWznmMMachtype::insertNewRec(
			WznmMMachtype** rec
			, const string sref
			, const uint ixVArch
			, const string srefKOs
			, const ubigint cchRefWznmMMachine
			, const string srefKPkgmgr
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMMachtype* _rec = NULL;

	_rec = new WznmMMachtype(0, sref, ixVArch, srefKOs, cchRefWznmMMachine, srefKPkgmgr, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMMachtype::appendNewRecToRst(
			ListWznmMMachtype& rst
			, WznmMMachtype** rec
			, const string sref
			, const uint ixVArch
			, const string srefKOs
			, const ubigint cchRefWznmMMachine
			, const string srefKPkgmgr
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMMachtype* _rec = NULL;

	retval = insertNewRec(&_rec, sref, ixVArch, srefKOs, cchRefWznmMMachine, srefKPkgmgr, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMMachtype::insertRst(
			ListWznmMMachtype& rst
			, bool transact
		) {
};

void TblWznmMMachtype::updateRec(
			WznmMMachtype* rec
		) {
};

void TblWznmMMachtype::updateRst(
			ListWznmMMachtype& rst
			, bool transact
		) {
};

void TblWznmMMachtype::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMMachtype::loadRecByRef(
			ubigint ref
			, WznmMMachtype** rec
		) {
	return false;
};

bool TblWznmMMachtype::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

bool TblWznmMMachtype::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMMachtype::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMMachtype& rst
		) {
	ubigint numload = 0;
	WznmMMachtype* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMMachtype
 ******************************************************************************/

MyTblWznmMMachtype::MyTblWznmMMachtype() :
			TblWznmMMachtype()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMMachtype::~MyTblWznmMMachtype() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMMachtype::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMMachtype (sref, ixVArch, srefKOs, cchRefWznmMMachine, srefKPkgmgr, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMMachtype SET sref = ?, ixVArch = ?, srefKOs = ?, cchRefWznmMMachine = ?, srefKPkgmgr = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMMachtype WHERE ref = ?", false);
};

bool MyTblWznmMMachtype::loadRecBySQL(
			const string& sqlstr
			, WznmMMachtype** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMMachtype* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMMachtype::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMMachtype::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMMachtype();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->sref.assign(dbrow[1], dblengths[1]); else _rec->sref = "";
		if (dbrow[2]) _rec->ixVArch = atol((char*) dbrow[2]); else _rec->ixVArch = 0;
		if (dbrow[3]) _rec->srefKOs.assign(dbrow[3], dblengths[3]); else _rec->srefKOs = "";
		if (dbrow[4]) _rec->cchRefWznmMMachine = atoll((char*) dbrow[4]); else _rec->cchRefWznmMMachine = 0;
		if (dbrow[5]) _rec->srefKPkgmgr.assign(dbrow[5], dblengths[5]); else _rec->srefKPkgmgr = "";
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMMachtype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMMachtype& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMMachtype* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMMachtype::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMMachtype::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMMachtype();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->sref.assign(dbrow[1], dblengths[1]); else rec->sref = "";
			if (dbrow[2]) rec->ixVArch = atol((char*) dbrow[2]); else rec->ixVArch = 0;
			if (dbrow[3]) rec->srefKOs.assign(dbrow[3], dblengths[3]); else rec->srefKOs = "";
			if (dbrow[4]) rec->cchRefWznmMMachine = atoll((char*) dbrow[4]); else rec->cchRefWznmMMachine = 0;
			if (dbrow[5]) rec->srefKPkgmgr.assign(dbrow[5], dblengths[5]); else rec->srefKPkgmgr = "";
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMMachtype::insertRec(
			WznmMMachtype* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[0] = rec->sref.length();
	l[2] = rec->srefKOs.length();
	l[4] = rec->srefKPkgmgr.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->sref.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->ixVArch,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefKOs.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->cchRefWznmMMachine,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefKPkgmgr.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMMachtype::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMMachtype::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMMachtype::insertRst(
			ListWznmMMachtype& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMMachtype::updateRec(
			WznmMMachtype* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[0] = rec->sref.length();
	l[2] = rec->srefKOs.length();
	l[4] = rec->srefKPkgmgr.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->sref.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->ixVArch,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefKOs.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->cchRefWznmMMachine,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefKPkgmgr.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMMachtype::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMMachtype::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMMachtype::updateRst(
			ListWznmMMachtype& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMMachtype::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMMachtype::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMMachtype::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMMachtype::loadRecByRef(
			ubigint ref
			, WznmMMachtype** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMMachtype WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMMachtype::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMMachtype WHERE sref = '" + sref + "'", ref);
};

bool MyTblWznmMMachtype::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMMachtype WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMMachtype
 ******************************************************************************/

PgTblWznmMMachtype::PgTblWznmMMachtype() :
			TblWznmMMachtype()
			, PgTable()
		{
};

PgTblWznmMMachtype::~PgTblWznmMMachtype() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMMachtype::initStatements() {
	createStatement("TblWznmMMachtype_insertRec", "INSERT INTO TblWznmMMachtype (sref, ixVArch, srefKOs, cchRefWznmMMachine, srefKPkgmgr, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6);
	createStatement("TblWznmMMachtype_updateRec", "UPDATE TblWznmMMachtype SET sref = $1, ixVArch = $2, srefKOs = $3, cchRefWznmMMachine = $4, srefKPkgmgr = $5, Comment = $6 WHERE ref = $7", 7);
	createStatement("TblWznmMMachtype_removeRecByRef", "DELETE FROM TblWznmMMachtype WHERE ref = $1", 1);

	createStatement("TblWznmMMachtype_loadRecByRef", "SELECT ref, sref, ixVArch, srefKOs, cchRefWznmMMachine, srefKPkgmgr, Comment FROM TblWznmMMachtype WHERE ref = $1", 1);
	createStatement("TblWznmMMachtype_loadRefBySrf", "SELECT ref FROM TblWznmMMachtype WHERE sref = $1", 1);
	createStatement("TblWznmMMachtype_loadSrfByRef", "SELECT sref FROM TblWznmMMachtype WHERE ref = $1", 1);
};

bool PgTblWznmMMachtype::loadRec(
			PGresult* res
			, WznmMMachtype** rec
		) {
	char* ptr;

	WznmMMachtype* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMMachtype();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvarch"),
			PQfnumber(res, "srefkos"),
			PQfnumber(res, "cchrefwznmmmachine"),
			PQfnumber(res, "srefkpkgmgr"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[1]));
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->ixVArch = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->srefKOs.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->cchRefWznmMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefKPkgmgr.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMMachtype::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMMachtype& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMMachtype* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvarch"),
			PQfnumber(res, "srefkos"),
			PQfnumber(res, "cchrefwznmmmachine"),
			PQfnumber(res, "srefkpkgmgr"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMMachtype();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[1]));
			ptr = PQgetvalue(res, numread, fnum[2]); rec->ixVArch = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->srefKOs.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->cchRefWznmMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefKPkgmgr.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMMachtype::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMMachtype** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMachtype::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmMMachtype::loadRecBySQL(
			const string& sqlstr
			, WznmMMachtype** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMachtype::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMMachtype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMMachtype& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMachtype::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMMachtype::insertRec(
			WznmMMachtype* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVArch = htonl(rec->ixVArch);
	ubigint _cchRefWznmMMachine = htonl64(rec->cchRefWznmMMachine);

	const char* vals[] = {
		rec->sref.c_str(),
		(char*) &_ixVArch,
		rec->srefKOs.c_str(),
		(char*) &_cchRefWznmMMachine,
		rec->srefKPkgmgr.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		0,
		sizeof(uint),
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {0, 1, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMMachtype_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMMachtype::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMMachtype::insertRst(
			ListWznmMMachtype& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMMachtype::updateRec(
			WznmMMachtype* rec
		) {
	PGresult* res;

	uint _ixVArch = htonl(rec->ixVArch);
	ubigint _cchRefWznmMMachine = htonl64(rec->cchRefWznmMMachine);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		rec->sref.c_str(),
		(char*) &_ixVArch,
		rec->srefKOs.c_str(),
		(char*) &_cchRefWznmMMachine,
		rec->srefKPkgmgr.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		0,
		sizeof(uint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {0, 1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMMachtype_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMMachtype::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMMachtype::updateRst(
			ListWznmMMachtype& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMMachtype::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMMachtype_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMMachtype::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMMachtype::loadRecByRef(
			ubigint ref
			, WznmMMachtype** rec
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

	return loadRecByStmt("TblWznmMMachtype_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMMachtype::loadRefBySrf(
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

	return loadRefByStmt("TblWznmMMachtype_loadRefBySrf", 1, vals, l, f, ref);
};

bool PgTblWznmMMachtype::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMMachtype_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

