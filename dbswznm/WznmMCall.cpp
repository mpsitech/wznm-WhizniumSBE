/**
	* \file WznmMCall.cpp
	* database access for table TblWznmMCall (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmMCall.h"

#include "WznmMCall_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMCall
 ******************************************************************************/

WznmMCall::WznmMCall(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint invIxWznmWArgtype
			, const uint retIxWznmWArgtype
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refWznmMVersion = refWznmMVersion;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->invIxWznmWArgtype = invIxWznmWArgtype;
	this->retIxWznmWArgtype = retIxWznmWArgtype;
	this->sref = sref;
	this->Comment = Comment;
};

bool WznmMCall::operator==(
			const WznmMCall& comp
		) {
	return false;
};

bool WznmMCall::operator!=(
			const WznmMCall& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMCall
 ******************************************************************************/

ListWznmMCall::ListWznmMCall() {
};

ListWznmMCall::ListWznmMCall(
			const ListWznmMCall& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMCall(*(src.nodes[i]));
};

ListWznmMCall::~ListWznmMCall() {
	clear();
};

void ListWznmMCall::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMCall::size() const {
	return(nodes.size());
};

void ListWznmMCall::append(
			WznmMCall* rec
		) {
	nodes.push_back(rec);
};

WznmMCall* ListWznmMCall::operator[](
			const uint ix
		) {
	WznmMCall* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMCall& ListWznmMCall::operator=(
			const ListWznmMCall& src
		) {
	WznmMCall* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMCall(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMCall::operator==(
			const ListWznmMCall& comp
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

bool ListWznmMCall::operator!=(
			const ListWznmMCall& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMCall
 ******************************************************************************/

TblWznmMCall::TblWznmMCall() {
};

TblWznmMCall::~TblWznmMCall() {
};

bool TblWznmMCall::loadRecBySQL(
			const string& sqlstr
			, WznmMCall** rec
		) {
	return false;
};

ubigint TblWznmMCall::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMCall& rst
		) {
	return 0;
};

ubigint TblWznmMCall::insertRec(
			WznmMCall* rec
		) {
	return 0;
};

ubigint TblWznmMCall::insertNewRec(
			WznmMCall** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint invIxWznmWArgtype
			, const uint retIxWznmWArgtype
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMCall* _rec = NULL;

	_rec = new WznmMCall(0, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, invIxWznmWArgtype, retIxWznmWArgtype, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMCall::appendNewRecToRst(
			ListWznmMCall& rst
			, WznmMCall** rec
			, const uint ixVBasetype
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint invIxWznmWArgtype
			, const uint retIxWznmWArgtype
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMCall* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, invIxWznmWArgtype, retIxWznmWArgtype, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMCall::insertRst(
			ListWznmMCall& rst
			, bool transact
		) {
};

void TblWznmMCall::updateRec(
			WznmMCall* rec
		) {
};

void TblWznmMCall::updateRst(
			ListWznmMCall& rst
			, bool transact
		) {
};

void TblWznmMCall::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMCall::loadRecByRef(
			ubigint ref
			, WznmMCall** rec
		) {
	return false;
};

bool TblWznmMCall::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWznmMCall::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMCall& rst
		) {
	return 0;
};

bool TblWznmMCall::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMCall::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMCall& rst
		) {
	ubigint numload = 0;
	WznmMCall* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMCall
 ******************************************************************************/

MyTblWznmMCall::MyTblWznmMCall() :
			TblWznmMCall()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMCall::~MyTblWznmMCall() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMCall::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMCall (ixVBasetype, refWznmMVersion, refIxVTbl, refUref, invIxWznmWArgtype, retIxWznmWArgtype, sref, Comment) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMCall SET ixVBasetype = ?, refWznmMVersion = ?, refIxVTbl = ?, refUref = ?, invIxWznmWArgtype = ?, retIxWznmWArgtype = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMCall WHERE ref = ?", false);
};

bool MyTblWznmMCall::loadRecBySQL(
			const string& sqlstr
			, WznmMCall** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMCall* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMCall::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMCall::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMCall();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWznmMVersion = atoll((char*) dbrow[2]); else _rec->refWznmMVersion = 0;
		if (dbrow[3]) _rec->refIxVTbl = atol((char*) dbrow[3]); else _rec->refIxVTbl = 0;
		if (dbrow[4]) _rec->refUref = atoll((char*) dbrow[4]); else _rec->refUref = 0;
		if (dbrow[5]) _rec->invIxWznmWArgtype = atol((char*) dbrow[5]); else _rec->invIxWznmWArgtype = 0;
		if (dbrow[6]) _rec->retIxWznmWArgtype = atol((char*) dbrow[6]); else _rec->retIxWznmWArgtype = 0;
		if (dbrow[7]) _rec->sref.assign(dbrow[7], dblengths[7]); else _rec->sref = "";
		if (dbrow[8]) _rec->Comment.assign(dbrow[8], dblengths[8]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMCall::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMCall& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMCall* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMCall::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMCall::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMCall();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWznmMVersion = atoll((char*) dbrow[2]); else rec->refWznmMVersion = 0;
			if (dbrow[3]) rec->refIxVTbl = atol((char*) dbrow[3]); else rec->refIxVTbl = 0;
			if (dbrow[4]) rec->refUref = atoll((char*) dbrow[4]); else rec->refUref = 0;
			if (dbrow[5]) rec->invIxWznmWArgtype = atol((char*) dbrow[5]); else rec->invIxWznmWArgtype = 0;
			if (dbrow[6]) rec->retIxWznmWArgtype = atol((char*) dbrow[6]); else rec->retIxWznmWArgtype = 0;
			if (dbrow[7]) rec->sref.assign(dbrow[7], dblengths[7]); else rec->sref = "";
			if (dbrow[8]) rec->Comment.assign(dbrow[8], dblengths[8]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMCall::insertRec(
			WznmMCall* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[6] = rec->sref.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->invIxWznmWArgtype,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->retIxWznmWArgtype,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMCall::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMCall::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMCall::insertRst(
			ListWznmMCall& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMCall::updateRec(
			WznmMCall* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[6] = rec->sref.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWznmMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->invIxWznmWArgtype,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->retIxWznmWArgtype,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMCall::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMCall::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMCall::updateRst(
			ListWznmMCall& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMCall::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMCall::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMCall::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMCall::loadRecByRef(
			ubigint ref
			, WznmMCall** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMCall WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMCall::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMCall WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWznmMCall::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMCall& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, invIxWznmWArgtype, retIxWznmWArgtype, sref, Comment FROM TblWznmMCall WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWznmMCall::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMCall WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMCall
 ******************************************************************************/

PgTblWznmMCall::PgTblWznmMCall() :
			TblWznmMCall()
			, PgTable()
		{
};

PgTblWznmMCall::~PgTblWznmMCall() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMCall::initStatements() {
	createStatement("TblWznmMCall_insertRec", "INSERT INTO TblWznmMCall (ixVBasetype, refWznmMVersion, refIxVTbl, refUref, invIxWznmWArgtype, retIxWznmWArgtype, sref, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWznmMCall_updateRec", "UPDATE TblWznmMCall SET ixVBasetype = $1, refWznmMVersion = $2, refIxVTbl = $3, refUref = $4, invIxWznmWArgtype = $5, retIxWznmWArgtype = $6, sref = $7, Comment = $8 WHERE ref = $9", 9);
	createStatement("TblWznmMCall_removeRecByRef", "DELETE FROM TblWznmMCall WHERE ref = $1", 1);

	createStatement("TblWznmMCall_loadRecByRef", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, invIxWznmWArgtype, retIxWznmWArgtype, sref, Comment FROM TblWznmMCall WHERE ref = $1", 1);
	createStatement("TblWznmMCall_loadRefByVerSrf", "SELECT ref FROM TblWznmMCall WHERE refWznmMVersion = $1 AND sref = $2", 2);
	createStatement("TblWznmMCall_loadRstByVer", "SELECT ref, ixVBasetype, refWznmMVersion, refIxVTbl, refUref, invIxWznmWArgtype, retIxWznmWArgtype, sref, Comment FROM TblWznmMCall WHERE refWznmMVersion = $1 ORDER BY sref ASC", 1);
	createStatement("TblWznmMCall_loadSrfByRef", "SELECT sref FROM TblWznmMCall WHERE ref = $1", 1);
};

bool PgTblWznmMCall::loadRec(
			PGresult* res
			, WznmMCall** rec
		) {
	char* ptr;

	WznmMCall* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMCall();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "invixwznmwargtype"),
			PQfnumber(res, "retixwznmwargtype"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->invIxWznmWArgtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->retIxWznmWArgtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMCall::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMCall& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMCall* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "invixwznmwargtype"),
			PQfnumber(res, "retixwznmwargtype"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMCall();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->invIxWznmWArgtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->retIxWznmWArgtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMCall::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMCall** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCall::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMCall::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMCall& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCall::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMCall::loadRecBySQL(
			const string& sqlstr
			, WznmMCall** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCall::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMCall::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMCall& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCall::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMCall::insertRec(
			WznmMCall* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _invIxWznmWArgtype = htonl(rec->invIxWznmWArgtype);
	uint _retIxWznmWArgtype = htonl(rec->retIxWznmWArgtype);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_invIxWznmWArgtype,
		(char*) &_retIxWznmWArgtype,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMCall_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMCall::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMCall::insertRst(
			ListWznmMCall& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMCall::updateRec(
			WznmMCall* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _invIxWznmWArgtype = htonl(rec->invIxWznmWArgtype);
	uint _retIxWznmWArgtype = htonl(rec->retIxWznmWArgtype);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_invIxWznmWArgtype,
		(char*) &_retIxWznmWArgtype,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMCall_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMCall::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMCall::updateRst(
			ListWznmMCall& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMCall::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMCall_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMCall::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMCall::loadRecByRef(
			ubigint ref
			, WznmMCall** rec
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

	return loadRecByStmt("TblWznmMCall_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMCall::loadRefByVerSrf(
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

	return loadRefByStmt("TblWznmMCall_loadRefByVerSrf", 2, vals, l, f, ref);
};

ubigint PgTblWznmMCall::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMCall& rst
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMCall_loadRstByVer", 1, vals, l, f, append, rst);
};

bool PgTblWznmMCall::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMCall_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

