/**
	* \file WznmMPreset.cpp
	* database access for table TblWznmMPreset (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmMPreset.h"

#include "WznmMPreset_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMPreset
 ******************************************************************************/

WznmMPreset::WznmMPreset(
			const ubigint ref
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint ixVScope
			, const string sref
			, const uint ixWznmWArgtype
			, const ubigint refJTitle
			, const string Title
		) {

	this->ref = ref;
	this->refWznmMVersion = refWznmMVersion;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->ixVScope = ixVScope;
	this->sref = sref;
	this->ixWznmWArgtype = ixWznmWArgtype;
	this->refJTitle = refJTitle;
	this->Title = Title;
};

bool WznmMPreset::operator==(
			const WznmMPreset& comp
		) {
	return false;
};

bool WznmMPreset::operator!=(
			const WznmMPreset& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMPreset
 ******************************************************************************/

ListWznmMPreset::ListWznmMPreset() {
};

ListWznmMPreset::ListWznmMPreset(
			const ListWznmMPreset& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMPreset(*(src.nodes[i]));
};

ListWznmMPreset::~ListWznmMPreset() {
	clear();
};

void ListWznmMPreset::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMPreset::size() const {
	return(nodes.size());
};

void ListWznmMPreset::append(
			WznmMPreset* rec
		) {
	nodes.push_back(rec);
};

WznmMPreset* ListWznmMPreset::operator[](
			const uint ix
		) {
	WznmMPreset* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMPreset& ListWznmMPreset::operator=(
			const ListWznmMPreset& src
		) {
	WznmMPreset* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMPreset(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMPreset::operator==(
			const ListWznmMPreset& comp
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

bool ListWznmMPreset::operator!=(
			const ListWznmMPreset& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMPreset
 ******************************************************************************/

TblWznmMPreset::TblWznmMPreset() {
};

TblWznmMPreset::~TblWznmMPreset() {
};

bool TblWznmMPreset::loadRecBySQL(
			const string& sqlstr
			, WznmMPreset** rec
		) {
	return false;
};

ubigint TblWznmMPreset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMPreset& rst
		) {
	return 0;
};

ubigint TblWznmMPreset::insertRec(
			WznmMPreset* rec
		) {
	return 0;
};

ubigint TblWznmMPreset::insertNewRec(
			WznmMPreset** rec
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint ixVScope
			, const string sref
			, const uint ixWznmWArgtype
			, const ubigint refJTitle
			, const string Title
		) {
	ubigint retval = 0;
	WznmMPreset* _rec = NULL;

	_rec = new WznmMPreset(0, refWznmMVersion, refIxVTbl, refUref, ixVScope, sref, ixWznmWArgtype, refJTitle, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMPreset::appendNewRecToRst(
			ListWznmMPreset& rst
			, WznmMPreset** rec
			, const ubigint refWznmMVersion
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint ixVScope
			, const string sref
			, const uint ixWznmWArgtype
			, const ubigint refJTitle
			, const string Title
		) {
	ubigint retval = 0;
	WznmMPreset* _rec = NULL;

	retval = insertNewRec(&_rec, refWznmMVersion, refIxVTbl, refUref, ixVScope, sref, ixWznmWArgtype, refJTitle, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMPreset::insertRst(
			ListWznmMPreset& rst
			, bool transact
		) {
};

void TblWznmMPreset::updateRec(
			WznmMPreset* rec
		) {
};

void TblWznmMPreset::updateRst(
			ListWznmMPreset& rst
			, bool transact
		) {
};

void TblWznmMPreset::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMPreset::loadRecByRef(
			ubigint ref
			, WznmMPreset** rec
		) {
	return false;
};

bool TblWznmMPreset::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMPreset** rec
		) {
	return false;
};

bool TblWznmMPreset::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWznmMPreset::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMPreset& rst
		) {
	return 0;
};

ubigint TblWznmMPreset::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMPreset& rst
		) {
	ubigint numload = 0;
	WznmMPreset* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMPreset
 ******************************************************************************/

MyTblWznmMPreset::MyTblWznmMPreset() :
			TblWznmMPreset()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMPreset::~MyTblWznmMPreset() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMPreset::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMPreset (refWznmMVersion, refIxVTbl, refUref, ixVScope, sref, ixWznmWArgtype, refJTitle, Title) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMPreset SET refWznmMVersion = ?, refIxVTbl = ?, refUref = ?, ixVScope = ?, sref = ?, ixWznmWArgtype = ?, refJTitle = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMPreset WHERE ref = ?", false);
};

bool MyTblWznmMPreset::loadRecBySQL(
			const string& sqlstr
			, WznmMPreset** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMPreset* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMPreset::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMPreset::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMPreset();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWznmMVersion = atoll((char*) dbrow[1]); else _rec->refWznmMVersion = 0;
		if (dbrow[2]) _rec->refIxVTbl = atol((char*) dbrow[2]); else _rec->refIxVTbl = 0;
		if (dbrow[3]) _rec->refUref = atoll((char*) dbrow[3]); else _rec->refUref = 0;
		if (dbrow[4]) _rec->ixVScope = atol((char*) dbrow[4]); else _rec->ixVScope = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->ixWznmWArgtype = atol((char*) dbrow[6]); else _rec->ixWznmWArgtype = 0;
		if (dbrow[7]) _rec->refJTitle = atoll((char*) dbrow[7]); else _rec->refJTitle = 0;
		if (dbrow[8]) _rec->Title.assign(dbrow[8], dblengths[8]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMPreset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMPreset& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMPreset* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMPreset::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMPreset::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMPreset();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWznmMVersion = atoll((char*) dbrow[1]); else rec->refWznmMVersion = 0;
			if (dbrow[2]) rec->refIxVTbl = atol((char*) dbrow[2]); else rec->refIxVTbl = 0;
			if (dbrow[3]) rec->refUref = atoll((char*) dbrow[3]); else rec->refUref = 0;
			if (dbrow[4]) rec->ixVScope = atol((char*) dbrow[4]); else rec->ixVScope = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->ixWznmWArgtype = atol((char*) dbrow[6]); else rec->ixWznmWArgtype = 0;
			if (dbrow[7]) rec->refJTitle = atoll((char*) dbrow[7]); else rec->refJTitle = 0;
			if (dbrow[8]) rec->Title.assign(dbrow[8], dblengths[8]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMPreset::insertRec(
			WznmMPreset* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->sref.length();
	l[7] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->refIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVScope,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmWArgtype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJTitle,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMPreset::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMPreset::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMPreset::insertRst(
			ListWznmMPreset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMPreset::updateRec(
			WznmMPreset* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();
	l[7] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWznmMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->refIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVScope,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmWArgtype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJTitle,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMPreset::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMPreset::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMPreset::updateRst(
			ListWznmMPreset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMPreset::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMPreset::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMPreset::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMPreset::loadRecByRef(
			ubigint ref
			, WznmMPreset** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMPreset WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmMPreset::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMPreset** rec
		) {
	return loadRecBySQL("SELECT ref, refWznmMVersion, refIxVTbl, refUref, ixVScope, sref, ixWznmWArgtype, refJTitle, Title FROM TblWznmMPreset WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", rec);
};

bool MyTblWznmMPreset::loadRefByVerSrf(
			ubigint refWznmMVersion
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWznmMPreset::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMPreset& rst
		) {
	return loadRstBySQL("SELECT ref, refWznmMVersion, refIxVTbl, refUref, ixVScope, sref, ixWznmWArgtype, refJTitle, Title FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " ORDER BY sref ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMPreset
 ******************************************************************************/

PgTblWznmMPreset::PgTblWznmMPreset() :
			TblWznmMPreset()
			, PgTable()
		{
};

PgTblWznmMPreset::~PgTblWznmMPreset() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMPreset::initStatements() {
	createStatement("TblWznmMPreset_insertRec", "INSERT INTO TblWznmMPreset (refWznmMVersion, refIxVTbl, refUref, ixVScope, sref, ixWznmWArgtype, refJTitle, Title) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWznmMPreset_updateRec", "UPDATE TblWznmMPreset SET refWznmMVersion = $1, refIxVTbl = $2, refUref = $3, ixVScope = $4, sref = $5, ixWznmWArgtype = $6, refJTitle = $7, Title = $8 WHERE ref = $9", 9);
	createStatement("TblWznmMPreset_removeRecByRef", "DELETE FROM TblWznmMPreset WHERE ref = $1", 1);

	createStatement("TblWznmMPreset_loadRecByRef", "SELECT ref, refWznmMVersion, refIxVTbl, refUref, ixVScope, sref, ixWznmWArgtype, refJTitle, Title FROM TblWznmMPreset WHERE ref = $1", 1);
	createStatement("TblWznmMPreset_loadRecByRetReu", "SELECT ref, refWznmMVersion, refIxVTbl, refUref, ixVScope, sref, ixWznmWArgtype, refJTitle, Title FROM TblWznmMPreset WHERE refIxVTbl = $1 AND refUref = $2", 2);
	createStatement("TblWznmMPreset_loadRefByVerSrf", "SELECT ref FROM TblWznmMPreset WHERE refWznmMVersion = $1 AND sref = $2", 2);
	createStatement("TblWznmMPreset_loadRstByVer", "SELECT ref, refWznmMVersion, refIxVTbl, refUref, ixVScope, sref, ixWznmWArgtype, refJTitle, Title FROM TblWznmMPreset WHERE refWznmMVersion = $1 ORDER BY sref ASC", 1);
};

bool PgTblWznmMPreset::loadRec(
			PGresult* res
			, WznmMPreset** rec
		) {
	char* ptr;

	WznmMPreset* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMPreset();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "ixvscope"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmwargtype"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVScope = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixWznmWArgtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJTitle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMPreset::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMPreset& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMPreset* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwznmmversion"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "ixvscope"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwznmwargtype"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmMPreset();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVScope = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWznmWArgtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJTitle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMPreset::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMPreset** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPreset::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMPreset::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMPreset& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPreset::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMPreset::loadRecBySQL(
			const string& sqlstr
			, WznmMPreset** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPreset::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMPreset::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMPreset& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPreset::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMPreset::insertRec(
			WznmMPreset* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _ixVScope = htonl(rec->ixVScope);
	uint _ixWznmWArgtype = htonl(rec->ixWznmWArgtype);
	ubigint _refJTitle = htonl64(rec->refJTitle);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_ixVScope,
		rec->sref.c_str(),
		(char*) &_ixWznmWArgtype,
		(char*) &_refJTitle,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmMPreset_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPreset::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMPreset::insertRst(
			ListWznmMPreset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMPreset::updateRec(
			WznmMPreset* rec
		) {
	PGresult* res;

	ubigint _refWznmMVersion = htonl64(rec->refWznmMVersion);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _ixVScope = htonl(rec->ixVScope);
	uint _ixWznmWArgtype = htonl(rec->ixWznmWArgtype);
	ubigint _refJTitle = htonl64(rec->refJTitle);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWznmMVersion,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_ixVScope,
		rec->sref.c_str(),
		(char*) &_ixWznmWArgtype,
		(char*) &_refJTitle,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMPreset_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMPreset::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMPreset::updateRst(
			ListWznmMPreset& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMPreset::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMPreset_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMPreset::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMPreset::loadRecByRef(
			ubigint ref
			, WznmMPreset** rec
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

	return loadRecByStmt("TblWznmMPreset_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmMPreset::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, WznmMPreset** rec
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWznmMPreset_loadRecByRetReu", 2, vals, l, f, rec);
};

bool PgTblWznmMPreset::loadRefByVerSrf(
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

	return loadRefByStmt("TblWznmMPreset_loadRefByVerSrf", 2, vals, l, f, ref);
};

ubigint PgTblWznmMPreset::loadRstByVer(
			ubigint refWznmMVersion
			, const bool append
			, ListWznmMPreset& rst
		) {
	ubigint _refWznmMVersion = htonl64(refWznmMVersion);

	const char* vals[] = {
		(char*) &_refWznmMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMPreset_loadRstByVer", 1, vals, l, f, append, rst);
};

#endif

