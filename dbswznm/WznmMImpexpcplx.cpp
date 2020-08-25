/**
	* \file WznmMImpexpcplx.cpp
	* database access for table TblWznmMImpexpcplx (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmMImpexpcplx.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMImpexpcplx
 ******************************************************************************/

WznmMImpexpcplx::WznmMImpexpcplx(
			const ubigint ref
			, const ubigint refWznmMVersion
			, const ubigint refWznmMJob
			, const string sref
			, const string Short
			, const ubigint refJTitle
			, const string Title
			, const string Minversion
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmMVersion = refWznmMVersion;
	this->refWznmMJob = refWznmMJob;
	this->sref = sref;
	this->Short = Short;
	this->refJTitle = refJTitle;
	this->Title = Title;
	this->Minversion = Minversion;
	this->Comment = Comment;
};

bool WznmMImpexpcplx::operator==(
			const WznmMImpexpcplx& comp
		) {
	return false;
};

bool WznmMImpexpcplx::operator!=(
			const WznmMImpexpcplx& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMImpexpcplx
 ******************************************************************************/

ListWznmMImpexpcplx::ListWznmMImpexpcplx() {
};

ListWznmMImpexpcplx::ListWznmMImpexpcplx(
			const ListWznmMImpexpcplx& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMImpexpcplx(*(src.nodes[i]));
};

ListWznmMImpexpcplx::~ListWznmMImpexpcplx() {
	clear();
};

void ListWznmMImpexpcplx::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMImpexpcplx::size() const {
	return(nodes.size());
};

void ListWznmMImpexpcplx::append(
			WznmMImpexpcplx* rec
		) {
	nodes.push_back(rec);
};

WznmMImpexpcplx* ListWznmMImpexpcplx::operator[](
			const uint ix
		) {
	WznmMImpexpcplx* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMImpexpcplx& ListWznmMImpexpcplx::operator=(
			const ListWznmMImpexpcplx& src
		) {
	WznmMImpexpcplx* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMImpexpcplx(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMImpexpcplx::operator==(
			const ListWznmMImpexpcplx& comp
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

bool ListWznmMImpexpcplx::operator!=(
			const ListWznmMImpexpcplx& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMImpexpcplx
 ******************************************************************************/

TblWznmMImpexpcplx::TblWznmMImpexpcplx() {
};

TblWznmMImpexpcplx::~TblWznmMImpexpcplx() {
};

bool TblWznmMImpexpcplx::loadRecBySQL(
			const string& sqlstr
			, WznmMImpexpcplx** rec
		) {
	return false;
};

ubigint TblWznmMImpexpcplx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMImpexpcplx& rst
		) {
	return 0;
};

ubigint TblWznmMImpexpcplx::insertRec(
			WznmMImpexpcplx* rec
		) {
	return 0;
};

ubigint TblWznmMImpexpcplx::insertNewRec(
			WznmMImpexpcplx** rec
			, const ubigint refWznmMVersion
			, const ubigint refWznmMJob
			, const string sref
			, const string Short
			, const ubigint refJTitle
			, const string Title
			, const string Minversion
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMImpexpcplx* _rec = NULL;

	_rec = new WznmMImpexpcplx(0, refWznmMVersion, refWznmMJob, sref, Short, refJTitle, Title, Minversion, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMImpexpcplx::appendNewRecToRst(
			ListWznmMImpexpcplx& rst
			, WznmMImpexpcplx** rec
			, const ubigint refWznmMVersion
			, const ubigint refWznmMJob
			, const string sref
			, const string Short
			, const ubigint refJTitle
			, const string Title
			, const string Minversion
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMImpexpcplx* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMVersion, refWznmMJob, sref, Short, refJTitle, Title, Minversion, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMImpexpcplx::insertRst(
			ListWznmMImpexpcplx& rst
			, bool transact
		) {
};

void TblWznmMImpexpcplx::updateRec(
			WznmMImpexpcplx* rec
		) {
};

void TblWznmMImpexpcplx::updateRst(
			ListWznmMImpexpcplx& rst
			, bool transact
		) {
};

void TblWznmMImpexpcplx::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMImpexpcplx::loadRecByRef(
			ubigint ref
			, WznmMImpexpcplx** rec
		) {
	return false;
};

bool TblWznmMImpexpcplx::loadRecByJob(
			ubigint refWznmMJob
			, WznmMImpexpcplx** rec
		) {
	return false;
};

bool TblWznmMImpexpcplx::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWznmMImpexpcplx::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMImpexpcplx& rst
		) {
	return 0;
};

bool TblWznmMImpexpcplx::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMImpexpcplx::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMImpexpcplx& rst
		) {
	ubigint numload = 0;
	WznmMImpexpcplx* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMImpexpcplx
 ******************************************************************************/

MyTblWznmMImpexpcplx::MyTblWznmMImpexpcplx() :
			TblWznmMImpexpcplx()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMImpexpcplx::~MyTblWznmMImpexpcplx() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMImpexpcplx::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMImpexpcplx (refWznmMVersion, refWznmMJob, sref, Short, refJTitle, Title, Minversion, Comment) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMImpexpcplx SET refWznmMVersion = ?, refWznmMJob = ?, sref = ?, Short = ?, refJTitle = ?, Title = ?, Minversion = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMImpexpcplx WHERE ref = ?", false);
};

bool MyTblWznmMImpexpcplx::loadRecBySQL(
			const string& sqlstr
			, WznmMImpexpcplx** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMImpexpcplx* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMImpexpcplx::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMImpexpcplx::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMImpexpcplx();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMVersion = atoll((char*) dbrow[1]); else _rec->refWznmMVersion = 0;
		if (dbrow[2]) _rec->refWznmMJob = atoll((char*) dbrow[2]); else _rec->refWznmMJob = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Short.assign(dbrow[4], dblengths[4]); else _rec->Short = "";
		if (dbrow[5]) _rec->refJTitle = atoll((char*) dbrow[5]); else _rec->refJTitle = 0;
		if (dbrow[6]) _rec->Title.assign(dbrow[6], dblengths[6]); else _rec->Title = "";
		if (dbrow[7]) _rec->Minversion.assign(dbrow[7], dblengths[7]); else _rec->Minversion = "";
		if (dbrow[8]) _rec->Comment.assign(dbrow[8], dblengths[8]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMImpexpcplx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMImpexpcplx& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMImpexpcplx* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMImpexpcplx::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMImpexpcplx::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMImpexpcplx();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMVersion = atoll((char*) dbrow[1]); else rec->refWznmMVersion = 0;
			if (dbrow[2]) rec->refWznmMJob = atoll((char*) dbrow[2]); else rec->refWznmMJob = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Short.assign(dbrow[4], dblengths[4]); else rec->Short = "";
			if (dbrow[5]) rec->refJTitle = atoll((char*) dbrow[5]); else rec->refJTitle = 0;
			if (dbrow[6]) rec->Title.assign(dbrow[6], dblengths[6]); else rec->Title = "";
			if (dbrow[7]) rec->Minversion.assign(dbrow[7], dblengths[7]); else rec->Minversion = "";
			if (dbrow[8]) rec->Comment.assign(dbrow[8], dblengths[8]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMImpexpcplx::insertRec(
			WznmMImpexpcplx* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[2] = rec->sref.length();
	l[3] = rec->Short.length();
	l[5] = rec->Title.length();
	l[6] = rec->Minversion.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMJob,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Short.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refJTitle,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Minversion.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMImpexpcplx::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMImpexpcplx::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMImpexpcplx::insertRst(
			ListWznmMImpexpcplx& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMImpexpcplx::updateRec(
			WznmMImpexpcplx* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[2] = rec->sref.length();
	l[3] = rec->Short.length();
	l[5] = rec->Title.length();
	l[6] = rec->Minversion.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMJob,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Short.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refJTitle,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Minversion.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMImpexpcplx::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMImpexpcplx::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMImpexpcplx::updateRst(
			ListWznmMImpexpcplx& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMImpexpcplx::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMImpexpcplx::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMImpexpcplx::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMImpexpcplx::loadRecByRef(
			ubigint ref
			, WznmMImpexpcplx** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMImpexpcplx WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMImpexpcplx::loadRecByJob(
			ubigint refWznmMJob
			, WznmMImpexpcplx** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMVersion, refWznmMJob, sref, Short, refJTitle, Title, Minversion, Comment FROM TblWznmMImpexpcplx WHERE refWznmMJob = " + to_string(refWznmMJob) + "", rec);
};

bool MyTblWznmMImpexpcplx::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMImpexpcplx WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWznmMImpexpcplx::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMImpexpcplx& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMVersion, refWznmMJob, sref, Short, refJTitle, Title, Minversion, Comment FROM TblWznmMImpexpcplx WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMImpexpcplx::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMImpexpcplx WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMImpexpcplx
 ******************************************************************************/

PgTblWznmMImpexpcplx::PgTblWznmMImpexpcplx() :
			TblWznmMImpexpcplx()
			, PgTable()
		{
};

PgTblWznmMImpexpcplx::~PgTblWznmMImpexpcplx() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMImpexpcplx::initStatements() {
	createStatement("TblWznmMImpexpcplx_insertRec", "INSERT INTO TblWznmMImpexpcplx (refWznmMVersion, refWznmMJob, sref, Short, refJTitle, Title, Minversion, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWznmMImpexpcplx_updateRec", "UPDATE TblWznmMImpexpcplx SET refWznmMVersion = $1, refWznmMJob = $2, sref = $3, Short = $4, refJTitle = $5, Title = $6, Minversion = $7, Comment = $8 WHERE ref = $9", 9);
	createStatement("TblWznmMImpexpcplx_removeRecByRef", "DELETE FROM TblWznmMImpexpcplx WHERE ref = $1", 1);

	createStatement("TblWznmMImpexpcplx_loadRecByRef", "SELECT ref, refWznmMVersion, refWznmMJob, sref, Short, refJTitle, Title, Minversion, Comment FROM TblWznmMImpexpcplx WHERE ref = $1", 1);
	createStatement("TblWznmMImpexpcplx_loadRecByJob", "SELECT ref, refWznmMVersion, refWznmMJob, sref, Short, refJTitle, Title, Minversion, Comment FROM TblWznmMImpexpcplx WHERE refWznmMJob = $1", 1);
	createStatement("TblWznmMImpexpcplx_loadRefByVerSrf", "SELECT ref FROM TblWznmMImpexpcplx WHERE refWznmMVersion = $1 AND sref = $2", 2);
	createStatement("TblWznmMImpexpcplx_loadRstByVer", "SELECT ref, refWznmMVersion, refWznmMJob, sref, Short, refJTitle, Title, Minversion, Comment FROM TblWznmMImpexpcplx WHERE refWznmMVersion = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMImpexpcplx_loadSrfByRef", "SELECT sref FROM TblWznmMImpexpcplx WHERE ref = $1", 1);
};

bool PgTblWznmMImpexpcplx::loadRec(
			PGresult* res
			, WznmMImpexpcplx** rec
		) {
	char* ptr;

	WznmMImpexpcplx* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMImpexpcplx();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title"),
			PQfnumber(res, "minversion"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMJob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refJTitle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Minversion.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMImpexpcplx::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMImpexpcplx& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMImpexpcplx* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refwznmmjob"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title"),
			PQfnumber(res, "minversion"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMImpexpcplx();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMJob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refJTitle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Minversion.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMImpexpcplx::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMImpexpcplx** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexpcplx::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMImpexpcplx::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMImpexpcplx& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexpcplx::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMImpexpcplx::loadRecBySQL(
			const string& sqlstr
			, WznmMImpexpcplx** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexpcplx::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMImpexpcplx::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMImpexpcplx& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexpcplx::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMImpexpcplx::insertRec(
			WznmMImpexpcplx* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _refJTitle = htonl64(rec->refJTitle);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str(),
		rec->Minversion.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 0, 0, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMImpexpcplx_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMImpexpcplx::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMImpexpcplx::insertRst(
			ListWznmMImpexpcplx& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMImpexpcplx::updateRec(
			WznmMImpexpcplx* rec
		) {
	PGresult* res;

	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	ubigint _refWznmMJob = htonl64(rec->refWznmMJob);
	ubigint _refJTitle = htonl64(rec->refJTitle);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		(char*) &_refWznmMJob,
		rec->sref.c_str(),
		rec->Short.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str(),
		rec->Minversion.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMImpexpcplx_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMImpexpcplx::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMImpexpcplx::updateRst(
			ListWznmMImpexpcplx& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMImpexpcplx::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMImpexpcplx_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMImpexpcplx::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMImpexpcplx::loadRecByRef(
			ubigint ref
			, WznmMImpexpcplx** rec
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

	return loadRecByStmt("TblWznmMImpexpcplx_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMImpexpcplx::loadRecByJob(
			ubigint refWznmMJob
			, WznmMImpexpcplx** rec
		) {
	ubigint _refWznmMJob = htonl64(refWznmMJob);

	const char* vals[] = {
		(char*) &_refWznmMJob
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMImpexpcplx_loadRecByJob", 1, vals, l, f, rec);
};

bool PgTblWznmMImpexpcplx::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadRefByStmt("TblWznmMImpexpcplx_loadRefByVerSrf", 2, vals, l, f, ref);
};

ubigint PgTblWznmMImpexpcplx::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMImpexpcplx& rst
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMImpexpcplx_loadRstByVer", 1, vals, l, f, append, rst);
};

bool PgTblWznmMImpexpcplx::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMImpexpcplx_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

