/**
	* \file WznmMFeed.cpp
	* database access for table TblWznmMFeed (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmMFeed.h"

#include "WznmMFeed_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMFeed
 ******************************************************************************/

WznmMFeed::WznmMFeed(
			const ubigint ref
			, const ubigint refWznmMControl
			, const uint srcIxVTbl
			, const ubigint srcUref
			, const string sref
			, const string srefsWznmMVectoritem
			, const string srefsWznmMTag
			, const string Comment
		) {

	this->ref = ref;
	this->refWznmMControl = refWznmMControl;
	this->srcIxVTbl = srcIxVTbl;
	this->srcUref = srcUref;
	this->sref = sref;
	this->srefsWznmMVectoritem = srefsWznmMVectoritem;
	this->srefsWznmMTag = srefsWznmMTag;
	this->Comment = Comment;
};

bool WznmMFeed::operator==(
			const WznmMFeed& comp
		) {
	return false;
};

bool WznmMFeed::operator!=(
			const WznmMFeed& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMFeed
 ******************************************************************************/

ListWznmMFeed::ListWznmMFeed() {
};

ListWznmMFeed::ListWznmMFeed(
			const ListWznmMFeed& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMFeed(*(src.nodes[i]));
};

ListWznmMFeed::~ListWznmMFeed() {
	clear();
};

void ListWznmMFeed::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMFeed::size() const {
	return(nodes.size());
};

void ListWznmMFeed::append(
			WznmMFeed* rec
		) {
	nodes.push_back(rec);
};

WznmMFeed* ListWznmMFeed::operator[](
			const uint ix
		) {
	WznmMFeed* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMFeed& ListWznmMFeed::operator=(
			const ListWznmMFeed& src
		) {
	WznmMFeed* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMFeed(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMFeed::operator==(
			const ListWznmMFeed& comp
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

bool ListWznmMFeed::operator!=(
			const ListWznmMFeed& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMFeed
 ******************************************************************************/

TblWznmMFeed::TblWznmMFeed() {
};

TblWznmMFeed::~TblWznmMFeed() {
};

bool TblWznmMFeed::loadRecBySQL(
			const string& sqlstr
			, WznmMFeed** rec
		) {
	return false;
};

ubigint TblWznmMFeed::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMFeed& rst
		) {
	return 0;
};

ubigint TblWznmMFeed::insertRec(
			WznmMFeed* rec
		) {
	return 0;
};

ubigint TblWznmMFeed::insertNewRec(
			WznmMFeed** rec
			, const ubigint refWznmMControl
			, const uint srcIxVTbl
			, const ubigint srcUref
			, const string sref
			, const string srefsWznmMVectoritem
			, const string srefsWznmMTag
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMFeed* _rec = NULL;

	_rec = new WznmMFeed(0, refWznmMControl, srcIxVTbl, srcUref, sref, srefsWznmMVectoritem, srefsWznmMTag, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMFeed::appendNewRecToRst(
			ListWznmMFeed& rst
			, WznmMFeed** rec
			, const ubigint refWznmMControl
			, const uint srcIxVTbl
			, const ubigint srcUref
			, const string sref
			, const string srefsWznmMVectoritem
			, const string srefsWznmMTag
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMFeed* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMControl, srcIxVTbl, srcUref, sref, srefsWznmMVectoritem, srefsWznmMTag, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMFeed::insertRst(
			ListWznmMFeed& rst
			, bool transact
		) {
};

void TblWznmMFeed::updateRec(
			WznmMFeed* rec
		) {
};

void TblWznmMFeed::updateRst(
			ListWznmMFeed& rst
			, bool transact
		) {
};

void TblWznmMFeed::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMFeed::loadRecByRef(
			ubigint ref
			, WznmMFeed** rec
		) {
	return false;
};

bool TblWznmMFeed::loadRecByCon(
			ubigint refWznmMControl
			, WznmMFeed** rec
		) {
	return false;
};

ubigint TblWznmMFeed::loadRefsByCon(
			ubigint refWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

bool TblWznmMFeed::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMFeed::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMFeed& rst
		) {
	ubigint numload = 0;
	WznmMFeed* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMFeed
 ******************************************************************************/

MyTblWznmMFeed::MyTblWznmMFeed() :
			TblWznmMFeed()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMFeed::~MyTblWznmMFeed() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMFeed::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMFeed (refWznmMControl, srcIxVTbl, srcUref, sref, srefsWznmMVectoritem, srefsWznmMTag, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMFeed SET refWznmMControl = ?, srcIxVTbl = ?, srcUref = ?, sref = ?, srefsWznmMVectoritem = ?, srefsWznmMTag = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMFeed WHERE ref = ?", false);
};

bool MyTblWznmMFeed::loadRecBySQL(
			const string& sqlstr
			, WznmMFeed** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMFeed* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMFeed::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMFeed::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMFeed();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMControl = atoll((char*) dbrow[1]); else _rec->refWznmMControl = 0;
		if (dbrow[2]) _rec->srcIxVTbl = atol((char*) dbrow[2]); else _rec->srcIxVTbl = 0;
		if (dbrow[3]) _rec->srcUref = atoll((char*) dbrow[3]); else _rec->srcUref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->srefsWznmMVectoritem.assign(dbrow[5], dblengths[5]); else _rec->srefsWznmMVectoritem = "";
		if (dbrow[6]) _rec->srefsWznmMTag.assign(dbrow[6], dblengths[6]); else _rec->srefsWznmMTag = "";
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMFeed::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMFeed& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMFeed* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMFeed::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMFeed::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMFeed();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMControl = atoll((char*) dbrow[1]); else rec->refWznmMControl = 0;
			if (dbrow[2]) rec->srcIxVTbl = atol((char*) dbrow[2]); else rec->srcIxVTbl = 0;
			if (dbrow[3]) rec->srcUref = atoll((char*) dbrow[3]); else rec->srcUref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->srefsWznmMVectoritem.assign(dbrow[5], dblengths[5]); else rec->srefsWznmMVectoritem = "";
			if (dbrow[6]) rec->srefsWznmMTag.assign(dbrow[6], dblengths[6]); else rec->srefsWznmMTag = "";
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMFeed::insertRec(
			WznmMFeed* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	l[4] = rec->srefsWznmMVectoritem.length();
	l[5] = rec->srefsWznmMTag.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMControl,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->srcIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->srcUref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefsWznmMVectoritem.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->srefsWznmMTag.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMFeed::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMFeed::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMFeed::insertRst(
			ListWznmMFeed& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMFeed::updateRec(
			WznmMFeed* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[4] = rec->srefsWznmMVectoritem.length();
	l[5] = rec->srefsWznmMTag.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMControl,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->srcIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->srcUref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefsWznmMVectoritem.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->srefsWznmMTag.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMFeed::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMFeed::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMFeed::updateRst(
			ListWznmMFeed& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMFeed::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMFeed::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMFeed::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMFeed::loadRecByRef(
			ubigint ref
			, WznmMFeed** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMFeed WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMFeed::loadRecByCon(
			ubigint refWznmMControl
			, WznmMFeed** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMControl, srcIxVTbl, srcUref, sref, srefsWznmMVectoritem, srefsWznmMTag, Comment FROM TblWznmMFeed WHERE refWznmMControl = " + to_string(refWznmMControl) + "", rec);
};

ubigint MyTblWznmMFeed::loadRefsByCon(
			ubigint refWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMFeed WHERE refWznmMControl = " + to_string(refWznmMControl) + "", append, refs);
};

bool MyTblWznmMFeed::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMFeed WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMFeed
 ******************************************************************************/

PgTblWznmMFeed::PgTblWznmMFeed() :
			TblWznmMFeed()
			, PgTable()
		{
};

PgTblWznmMFeed::~PgTblWznmMFeed() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMFeed::initStatements() {
	createStatement("TblWznmMFeed_insertRec", "INSERT INTO TblWznmMFeed (refWznmMControl, srcIxVTbl, srcUref, sref, srefsWznmMVectoritem, srefsWznmMTag, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWznmMFeed_updateRec", "UPDATE TblWznmMFeed SET refWznmMControl = $1, srcIxVTbl = $2, srcUref = $3, sref = $4, srefsWznmMVectoritem = $5, srefsWznmMTag = $6, Comment = $7 WHERE ref = $8", 8);
	createStatement("TblWznmMFeed_removeRecByRef", "DELETE FROM TblWznmMFeed WHERE ref = $1", 1);

	createStatement("TblWznmMFeed_loadRecByRef", "SELECT ref, refWznmMControl, srcIxVTbl, srcUref, sref, srefsWznmMVectoritem, srefsWznmMTag, Comment FROM TblWznmMFeed WHERE ref = $1", 1);
	createStatement("TblWznmMFeed_loadRecByCon", "SELECT ref, refWznmMControl, srcIxVTbl, srcUref, sref, srefsWznmMVectoritem, srefsWznmMTag, Comment FROM TblWznmMFeed WHERE refWznmMControl = $1", 1);
	createStatement("TblWznmMFeed_loadRefsByCon", "SELECT ref FROM TblWznmMFeed WHERE refWznmMControl = $1", 1);
	createStatement("TblWznmMFeed_loadSrfByRef", "SELECT sref FROM TblWznmMFeed WHERE ref = $1", 1);
};

bool PgTblWznmMFeed::loadRec(
			PGresult* res
			, WznmMFeed** rec
		) {
	char* ptr;

	WznmMFeed* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMFeed();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcontrol"),
			PQfnumber(res, "srcixvtbl"),
			PQfnumber(res, "srcuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefswznmmvectoritem"),
			PQfnumber(res, "srefswznmmtag"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMControl = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->srcIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->srcUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefsWznmMVectoritem.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->srefsWznmMTag.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMFeed::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMFeed& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMFeed* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmcontrol"),
			PQfnumber(res, "srcixvtbl"),
			PQfnumber(res, "srcuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefswznmmvectoritem"),
			PQfnumber(res, "srefswznmmtag"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMFeed();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMControl = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->srcIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->srcUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefsWznmMVectoritem.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->srefsWznmMTag.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMFeed::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMFeed** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMFeed::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmMFeed::loadRecBySQL(
			const string& sqlstr
			, WznmMFeed** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMFeed::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMFeed::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMFeed& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMFeed::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMFeed::insertRec(
			WznmMFeed* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMControl = htonl64(rec->refWznmMControl);
	uint _srcIxVTbl = htonl(rec->srcIxVTbl);
	ubigint _srcUref = htonl64(rec->srcUref);

	const char* vals[] = {
		(char*) &_refWznmMControl,
		(char*) &_srcIxVTbl,
		(char*) &_srcUref,
		rec->sref.c_str(),
		rec->srefsWznmMVectoritem.c_str(),
		rec->srefsWznmMTag.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMFeed_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMFeed::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMFeed::insertRst(
			ListWznmMFeed& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMFeed::updateRec(
			WznmMFeed* rec
		) {
	PGresult* res;

	ubigint _refWznmMControl = htonl64(rec->refWznmMControl);
	uint _srcIxVTbl = htonl(rec->srcIxVTbl);
	ubigint _srcUref = htonl64(rec->srcUref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMControl,
		(char*) &_srcIxVTbl,
		(char*) &_srcUref,
		rec->sref.c_str(),
		rec->srefsWznmMVectoritem.c_str(),
		rec->srefsWznmMTag.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMFeed_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMFeed::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMFeed::updateRst(
			ListWznmMFeed& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMFeed::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMFeed_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMFeed::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMFeed::loadRecByRef(
			ubigint ref
			, WznmMFeed** rec
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

	return loadRecByStmt("TblWznmMFeed_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMFeed::loadRecByCon(
			ubigint refWznmMControl
			, WznmMFeed** rec
		) {
	ubigint _refWznmMControl = htonl64(refWznmMControl);

	const char* vals[] = {
		(char*) &_refWznmMControl
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmMFeed_loadRecByCon", 1, vals, l, f, rec);
};

ubigint PgTblWznmMFeed::loadRefsByCon(
			ubigint refWznmMControl
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWznmMControl = htonl64(refWznmMControl);

	const char* vals[] = {
		(char*) &_refWznmMControl
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMFeed_loadRefsByCon", 1, vals, l, f, append, refs);
};

bool PgTblWznmMFeed::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMFeed_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

