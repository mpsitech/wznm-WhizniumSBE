/**
	* \file WznmMVectoritem.cpp
	* database access for table TblWznmMVectoritem (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmMVectoritem.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMVectoritem
 ******************************************************************************/

WznmMVectoritem::WznmMVectoritem(
			const ubigint ref
			, const ubigint vecRefWznmMVector
			, const uint vecNum
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->vecRefWznmMVector = vecRefWznmMVector;
	this->vecNum = vecNum;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

bool WznmMVectoritem::operator==(
			const WznmMVectoritem& comp
		) {
	return false;
};

bool WznmMVectoritem::operator!=(
			const WznmMVectoritem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMVectoritem
 ******************************************************************************/

ListWznmMVectoritem::ListWznmMVectoritem() {
};

ListWznmMVectoritem::ListWznmMVectoritem(
			const ListWznmMVectoritem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMVectoritem(*(src.nodes[i]));
};

ListWznmMVectoritem::~ListWznmMVectoritem() {
	clear();
};

void ListWznmMVectoritem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMVectoritem::size() const {
	return(nodes.size());
};

void ListWznmMVectoritem::append(
			WznmMVectoritem* rec
		) {
	nodes.push_back(rec);
};

WznmMVectoritem* ListWznmMVectoritem::operator[](
			const uint ix
		) {
	WznmMVectoritem* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMVectoritem& ListWznmMVectoritem::operator=(
			const ListWznmMVectoritem& src
		) {
	WznmMVectoritem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMVectoritem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMVectoritem::operator==(
			const ListWznmMVectoritem& comp
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

bool ListWznmMVectoritem::operator!=(
			const ListWznmMVectoritem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMVectoritem
 ******************************************************************************/

TblWznmMVectoritem::TblWznmMVectoritem() {
};

TblWznmMVectoritem::~TblWznmMVectoritem() {
};

bool TblWznmMVectoritem::loadRecBySQL(
			const string& sqlstr
			, WznmMVectoritem** rec
		) {
	return false;
};

ubigint TblWznmMVectoritem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMVectoritem& rst
		) {
	return 0;
};

ubigint TblWznmMVectoritem::insertRec(
			WznmMVectoritem* rec
		) {
	return 0;
};

ubigint TblWznmMVectoritem::insertNewRec(
			WznmMVectoritem** rec
			, const ubigint vecRefWznmMVector
			, const uint vecNum
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMVectoritem* _rec = NULL;

	_rec = new WznmMVectoritem(0, vecRefWznmMVector, vecNum, sref, Avail, Implied, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMVectoritem::appendNewRecToRst(
			ListWznmMVectoritem& rst
			, WznmMVectoritem** rec
			, const ubigint vecRefWznmMVector
			, const uint vecNum
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMVectoritem* _rec = NULL;

	retval = insertNewRec(&_rec, vecRefWznmMVector, vecNum, sref, Avail, Implied, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMVectoritem::insertRst(
			ListWznmMVectoritem& rst
			, bool transact
		) {
};

void TblWznmMVectoritem::updateRec(
			WznmMVectoritem* rec
		) {
};

void TblWznmMVectoritem::updateRst(
			ListWznmMVectoritem& rst
			, bool transact
		) {
};

void TblWznmMVectoritem::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMVectoritem::loadRecByRef(
			ubigint ref
			, WznmMVectoritem** rec
		) {
	return false;
};

ubigint TblWznmMVectoritem::loadRefsByVec(
			ubigint vecRefWznmMVector
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMVectoritem::loadRstByVec(
			ubigint vecRefWznmMVector
			, const bool append
			, ListWznmMVectoritem& rst
		) {
	return 0;
};

bool TblWznmMVectoritem::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMVectoritem::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMVectoritem& rst
		) {
	ubigint numload = 0;
	WznmMVectoritem* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMVectoritem
 ******************************************************************************/

MyTblWznmMVectoritem::MyTblWznmMVectoritem() :
			TblWznmMVectoritem()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMVectoritem::~MyTblWznmMVectoritem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMVectoritem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMVectoritem (vecRefWznmMVector, vecNum, sref, Avail, Implied, refJ, Title, Comment) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMVectoritem SET vecRefWznmMVector = ?, vecNum = ?, sref = ?, Avail = ?, Implied = ?, refJ = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMVectoritem WHERE ref = ?", false);
};

bool MyTblWznmMVectoritem::loadRecBySQL(
			const string& sqlstr
			, WznmMVectoritem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMVectoritem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMVectoritem::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMVectoritem::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMVectoritem();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->vecRefWznmMVector = atoll((char*) dbrow[1]); else _rec->vecRefWznmMVector = 0;
		if (dbrow[2]) _rec->vecNum = atol((char*) dbrow[2]); else _rec->vecNum = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Avail.assign(dbrow[4], dblengths[4]); else _rec->Avail = "";
		if (dbrow[5]) _rec->Implied.assign(dbrow[5], dblengths[5]); else _rec->Implied = "";
		if (dbrow[6]) _rec->refJ = atoll((char*) dbrow[6]); else _rec->refJ = 0;
		if (dbrow[7]) _rec->Title.assign(dbrow[7], dblengths[7]); else _rec->Title = "";
		if (dbrow[8]) _rec->Comment.assign(dbrow[8], dblengths[8]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMVectoritem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMVectoritem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMVectoritem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMVectoritem::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMVectoritem::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMVectoritem();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->vecRefWznmMVector = atoll((char*) dbrow[1]); else rec->vecRefWznmMVector = 0;
			if (dbrow[2]) rec->vecNum = atol((char*) dbrow[2]); else rec->vecNum = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Avail.assign(dbrow[4], dblengths[4]); else rec->Avail = "";
			if (dbrow[5]) rec->Implied.assign(dbrow[5], dblengths[5]); else rec->Implied = "";
			if (dbrow[6]) rec->refJ = atoll((char*) dbrow[6]); else rec->refJ = 0;
			if (dbrow[7]) rec->Title.assign(dbrow[7], dblengths[7]); else rec->Title = "";
			if (dbrow[8]) rec->Comment.assign(dbrow[8], dblengths[8]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMVectoritem::insertRec(
			WznmMVectoritem* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[2] = rec->sref.length();
	l[3] = rec->Avail.length();
	l[4] = rec->Implied.length();
	l[6] = rec->Title.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->vecRefWznmMVector,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vecNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refJ,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMVectoritem::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMVectoritem::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMVectoritem::insertRst(
			ListWznmMVectoritem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMVectoritem::updateRec(
			WznmMVectoritem* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[2] = rec->sref.length();
	l[3] = rec->Avail.length();
	l[4] = rec->Implied.length();
	l[6] = rec->Title.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->vecRefWznmMVector,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vecNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refJ,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMVectoritem::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMVectoritem::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMVectoritem::updateRst(
			ListWznmMVectoritem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMVectoritem::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMVectoritem::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMVectoritem::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMVectoritem::loadRecByRef(
			ubigint ref
			, WznmMVectoritem** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMVectoritem WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMVectoritem::loadRefsByVec(
			ubigint vecRefWznmMVector
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(vecRefWznmMVector) + "", append, refs);
};

ubigint MyTblWznmMVectoritem::loadRstByVec(
			ubigint vecRefWznmMVector
			, const bool append
			, ListWznmMVectoritem& rst
		) {
	return loadRstBySQL("SELECT ref, vecRefWznmMVector, vecNum, sref, Avail, Implied, refJ, Title, Comment FROM TblWznmMVectoritem WHERE vecRefWznmMVector = " + to_string(vecRefWznmMVector) + " ORDER BY vecNum ASC", append, rst);
};

bool MyTblWznmMVectoritem::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMVectoritem WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMVectoritem
 ******************************************************************************/

PgTblWznmMVectoritem::PgTblWznmMVectoritem() :
			TblWznmMVectoritem()
			, PgTable()
		{
};

PgTblWznmMVectoritem::~PgTblWznmMVectoritem() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMVectoritem::initStatements() {
	createStatement("TblWznmMVectoritem_insertRec", "INSERT INTO TblWznmMVectoritem (vecRefWznmMVector, vecNum, sref, Avail, Implied, refJ, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWznmMVectoritem_updateRec", "UPDATE TblWznmMVectoritem SET vecRefWznmMVector = $1, vecNum = $2, sref = $3, Avail = $4, Implied = $5, refJ = $6, Title = $7, Comment = $8 WHERE ref = $9", 9);
	createStatement("TblWznmMVectoritem_removeRecByRef", "DELETE FROM TblWznmMVectoritem WHERE ref = $1", 1);

	createStatement("TblWznmMVectoritem_loadRecByRef", "SELECT ref, vecRefWznmMVector, vecNum, sref, Avail, Implied, refJ, Title, Comment FROM TblWznmMVectoritem WHERE ref = $1", 1);
	createStatement("TblWznmMVectoritem_loadRefsByVec", "SELECT ref FROM TblWznmMVectoritem WHERE vecRefWznmMVector = $1", 1);
	createStatement("TblWznmMVectoritem_loadRstByVec", "SELECT ref, vecRefWznmMVector, vecNum, sref, Avail, Implied, refJ, Title, Comment FROM TblWznmMVectoritem WHERE vecRefWznmMVector = $1 ORDER BY vecNum ASC", 1);
	createStatement("TblWznmMVectoritem_loadSrfByRef", "SELECT sref FROM TblWznmMVectoritem WHERE ref = $1", 1);
};

bool PgTblWznmMVectoritem::loadRec(
			PGresult* res
			, WznmMVectoritem** rec
		) {
	char* ptr;

	WznmMVectoritem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMVectoritem();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vecrefwznmmvector"),
			PQfnumber(res, "vecnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->vecRefWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->vecNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Implied.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMVectoritem::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMVectoritem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMVectoritem* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vecrefwznmmvector"),
			PQfnumber(res, "vecnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMVectoritem();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->vecRefWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->vecNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Implied.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMVectoritem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMVectoritem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVectoritem::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMVectoritem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMVectoritem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVectoritem::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMVectoritem::loadRecBySQL(
			const string& sqlstr
			, WznmMVectoritem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVectoritem::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMVectoritem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMVectoritem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVectoritem::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMVectoritem::insertRec(
			WznmMVectoritem* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _vecRefWznmMVector = htonl64(rec->vecRefWznmMVector);
	uint _vecNum = htonl(rec->vecNum);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_vecRefWznmMVector,
		(char*) &_vecNum,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMVectoritem_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVectoritem::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMVectoritem::insertRst(
			ListWznmMVectoritem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMVectoritem::updateRec(
			WznmMVectoritem* rec
		) {
	PGresult* res;

	ubigint _vecRefWznmMVector = htonl64(rec->vecRefWznmMVector);
	uint _vecNum = htonl(rec->vecNum);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_vecRefWznmMVector,
		(char*) &_vecNum,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMVectoritem_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMVectoritem::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMVectoritem::updateRst(
			ListWznmMVectoritem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMVectoritem::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMVectoritem_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMVectoritem::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMVectoritem::loadRecByRef(
			ubigint ref
			, WznmMVectoritem** rec
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

	return loadRecByStmt("TblWznmMVectoritem_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMVectoritem::loadRefsByVec(
			ubigint vecRefWznmMVector
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _vecRefWznmMVector = htonl64(vecRefWznmMVector);

	const char* vals[] = {
		(char*) &_vecRefWznmMVector
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMVectoritem_loadRefsByVec", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMVectoritem::loadRstByVec(
			ubigint vecRefWznmMVector
			, const bool append
			, ListWznmMVectoritem& rst
		) {
	ubigint _vecRefWznmMVector = htonl64(vecRefWznmMVector);

	const char* vals[] = {
		(char*) &_vecRefWznmMVector
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMVectoritem_loadRstByVec", 1, vals, l, f, append, rst);
};

bool PgTblWznmMVectoritem::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMVectoritem_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

