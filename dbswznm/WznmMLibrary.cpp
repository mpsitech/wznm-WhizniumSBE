/**
	* \file WznmMLibrary.cpp
	* database access for table TblWznmMLibrary (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmMLibrary.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMLibrary
 ******************************************************************************/

WznmMLibrary::WznmMLibrary(
			const ubigint ref
			, const string sref
			, const string Title
			, const string Version
			, const string srefKLictype
			, const string depSrefsWznmMLibrary
			, const string Comment
		) {

	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->Version = Version;
	this->srefKLictype = srefKLictype;
	this->depSrefsWznmMLibrary = depSrefsWznmMLibrary;
	this->Comment = Comment;
};

bool WznmMLibrary::operator==(
			const WznmMLibrary& comp
		) {
	return false;
};

bool WznmMLibrary::operator!=(
			const WznmMLibrary& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMLibrary
 ******************************************************************************/

ListWznmMLibrary::ListWznmMLibrary() {
};

ListWznmMLibrary::ListWznmMLibrary(
			const ListWznmMLibrary& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMLibrary(*(src.nodes[i]));
};

ListWznmMLibrary::~ListWznmMLibrary() {
	clear();
};

void ListWznmMLibrary::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMLibrary::size() const {
	return(nodes.size());
};

void ListWznmMLibrary::append(
			WznmMLibrary* rec
		) {
	nodes.push_back(rec);
};

WznmMLibrary* ListWznmMLibrary::operator[](
			const uint ix
		) {
	WznmMLibrary* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMLibrary& ListWznmMLibrary::operator=(
			const ListWznmMLibrary& src
		) {
	WznmMLibrary* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMLibrary(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMLibrary::operator==(
			const ListWznmMLibrary& comp
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

bool ListWznmMLibrary::operator!=(
			const ListWznmMLibrary& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMLibrary
 ******************************************************************************/

TblWznmMLibrary::TblWznmMLibrary() {
};

TblWznmMLibrary::~TblWznmMLibrary() {
};

bool TblWznmMLibrary::loadRecBySQL(
			const string& sqlstr
			, WznmMLibrary** rec
		) {
	return false;
};

ubigint TblWznmMLibrary::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMLibrary& rst
		) {
	return 0;
};

ubigint TblWznmMLibrary::insertRec(
			WznmMLibrary* rec
		) {
	return 0;
};

ubigint TblWznmMLibrary::insertNewRec(
			WznmMLibrary** rec
			, const string sref
			, const string Title
			, const string Version
			, const string srefKLictype
			, const string depSrefsWznmMLibrary
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMLibrary* _rec = NULL;

	_rec = new WznmMLibrary(0, sref, Title, Version, srefKLictype, depSrefsWznmMLibrary, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMLibrary::appendNewRecToRst(
			ListWznmMLibrary& rst
			, WznmMLibrary** rec
			, const string sref
			, const string Title
			, const string Version
			, const string srefKLictype
			, const string depSrefsWznmMLibrary
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMLibrary* _rec = NULL;

	retval = insertNewRec(&_rec, sref, Title, Version, srefKLictype, depSrefsWznmMLibrary, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMLibrary::insertRst(
			ListWznmMLibrary& rst
			, bool transact
		) {
};

void TblWznmMLibrary::updateRec(
			WznmMLibrary* rec
		) {
};

void TblWznmMLibrary::updateRst(
			ListWznmMLibrary& rst
			, bool transact
		) {
};

void TblWznmMLibrary::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMLibrary::loadRecByRef(
			ubigint ref
			, WznmMLibrary** rec
		) {
	return false;
};

bool TblWznmMLibrary::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

bool TblWznmMLibrary::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMLibrary::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMLibrary& rst
		) {
	ubigint numload = 0;
	WznmMLibrary* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMLibrary
 ******************************************************************************/

MyTblWznmMLibrary::MyTblWznmMLibrary() :
			TblWznmMLibrary()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMLibrary::~MyTblWznmMLibrary() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMLibrary::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMLibrary (sref, Title, Version, srefKLictype, depSrefsWznmMLibrary, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMLibrary SET sref = ?, Title = ?, Version = ?, srefKLictype = ?, depSrefsWznmMLibrary = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMLibrary WHERE ref = ?", false);
};

bool MyTblWznmMLibrary::loadRecBySQL(
			const string& sqlstr
			, WznmMLibrary** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMLibrary* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMLibrary::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMLibrary::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMLibrary();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->sref.assign(dbrow[1], dblengths[1]); else _rec->sref = "";
		if (dbrow[2]) _rec->Title.assign(dbrow[2], dblengths[2]); else _rec->Title = "";
		if (dbrow[3]) _rec->Version.assign(dbrow[3], dblengths[3]); else _rec->Version = "";
		if (dbrow[4]) _rec->srefKLictype.assign(dbrow[4], dblengths[4]); else _rec->srefKLictype = "";
		if (dbrow[5]) _rec->depSrefsWznmMLibrary.assign(dbrow[5], dblengths[5]); else _rec->depSrefsWznmMLibrary = "";
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMLibrary::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMLibrary& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMLibrary* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMLibrary::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMLibrary::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMLibrary();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->sref.assign(dbrow[1], dblengths[1]); else rec->sref = "";
			if (dbrow[2]) rec->Title.assign(dbrow[2], dblengths[2]); else rec->Title = "";
			if (dbrow[3]) rec->Version.assign(dbrow[3], dblengths[3]); else rec->Version = "";
			if (dbrow[4]) rec->srefKLictype.assign(dbrow[4], dblengths[4]); else rec->srefKLictype = "";
			if (dbrow[5]) rec->depSrefsWznmMLibrary.assign(dbrow[5], dblengths[5]); else rec->depSrefsWznmMLibrary = "";
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMLibrary::insertRec(
			WznmMLibrary* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[0] = rec->sref.length();
	l[1] = rec->Title.length();
	l[2] = rec->Version.length();
	l[3] = rec->srefKLictype.length();
	l[4] = rec->depSrefsWznmMLibrary.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->sref.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->Title.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Version.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefKLictype.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->depSrefsWznmMLibrary.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMLibrary::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMLibrary::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMLibrary::insertRst(
			ListWznmMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMLibrary::updateRec(
			WznmMLibrary* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[0] = rec->sref.length();
	l[1] = rec->Title.length();
	l[2] = rec->Version.length();
	l[3] = rec->srefKLictype.length();
	l[4] = rec->depSrefsWznmMLibrary.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->sref.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->Title.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Version.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefKLictype.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->depSrefsWznmMLibrary.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMLibrary::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMLibrary::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMLibrary::updateRst(
			ListWznmMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMLibrary::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMLibrary::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMLibrary::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMLibrary::loadRecByRef(
			ubigint ref
			, WznmMLibrary** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMLibrary WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMLibrary::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMLibrary WHERE sref = '" + sref + "'", ref);
};

bool MyTblWznmMLibrary::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMLibrary WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMLibrary
 ******************************************************************************/

PgTblWznmMLibrary::PgTblWznmMLibrary() :
			TblWznmMLibrary()
			, PgTable()
		{
};

PgTblWznmMLibrary::~PgTblWznmMLibrary() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMLibrary::initStatements() {
	createStatement("TblWznmMLibrary_insertRec", "INSERT INTO TblWznmMLibrary (sref, Title, Version, srefKLictype, depSrefsWznmMLibrary, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6);
	createStatement("TblWznmMLibrary_updateRec", "UPDATE TblWznmMLibrary SET sref = $1, Title = $2, Version = $3, srefKLictype = $4, depSrefsWznmMLibrary = $5, Comment = $6 WHERE ref = $7", 7);
	createStatement("TblWznmMLibrary_removeRecByRef", "DELETE FROM TblWznmMLibrary WHERE ref = $1", 1);

	createStatement("TblWznmMLibrary_loadRecByRef", "SELECT ref, sref, Title, Version, srefKLictype, depSrefsWznmMLibrary, Comment FROM TblWznmMLibrary WHERE ref = $1", 1);
	createStatement("TblWznmMLibrary_loadRefBySrf", "SELECT ref FROM TblWznmMLibrary WHERE sref = $1", 1);
	createStatement("TblWznmMLibrary_loadSrfByRef", "SELECT sref FROM TblWznmMLibrary WHERE ref = $1", 1);
};

bool PgTblWznmMLibrary::loadRec(
			PGresult* res
			, WznmMLibrary** rec
		) {
	char* ptr;

	WznmMLibrary* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMLibrary();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "version"),
			PQfnumber(res, "srefklictype"),
			PQfnumber(res, "depsrefswznmmlibrary"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[1]));
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Version.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->srefKLictype.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->depSrefsWznmMLibrary.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMLibrary::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMLibrary& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMLibrary* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "version"),
			PQfnumber(res, "srefklictype"),
			PQfnumber(res, "depsrefswznmmlibrary"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMLibrary();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[1]));
			ptr = PQgetvalue(res, numread, fnum[2]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Version.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->srefKLictype.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->depSrefsWznmMLibrary.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMLibrary::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMLibrary** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMLibrary::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmMLibrary::loadRecBySQL(
			const string& sqlstr
			, WznmMLibrary** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMLibrary::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMLibrary::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMLibrary& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMLibrary::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMLibrary::insertRec(
			WznmMLibrary* rec
		) {
	PGresult* res;
	char* ptr;

	const char* vals[] = {
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->Version.c_str(),
		rec->srefKLictype.c_str(),
		rec->depSrefsWznmMLibrary.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMLibrary_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMLibrary::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMLibrary::insertRst(
			ListWznmMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMLibrary::updateRec(
			WznmMLibrary* rec
		) {
	PGresult* res;

	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->Version.c_str(),
		rec->srefKLictype.c_str(),
		rec->depSrefsWznmMLibrary.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMLibrary_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMLibrary::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMLibrary::updateRst(
			ListWznmMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMLibrary::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMLibrary_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMLibrary::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMLibrary::loadRecByRef(
			ubigint ref
			, WznmMLibrary** rec
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

	return loadRecByStmt("TblWznmMLibrary_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMLibrary::loadRefBySrf(
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

	return loadRefByStmt("TblWznmMLibrary_loadRefBySrf", 1, vals, l, f, ref);
};

bool PgTblWznmMLibrary::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMLibrary_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

