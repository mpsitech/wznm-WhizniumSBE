/**
	* \file WznmMVersion.cpp
	* database access for table TblWznmMVersion (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "WznmMVersion.h"

#include "WznmMVersion_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMVersion
 ******************************************************************************/

WznmMVersion::WznmMVersion(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint prjRefWznmMProject
			, const uint prjNum
			, const ubigint bvrRefWznmMVersion
			, const ubigint refRLocale
			, const ubigint refWznmMLocale
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWDbmstype
			, const uint ixWOption
			, const ubigint refJ
			, const string About1
			, const string About2
			, const string About3
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->prjRefWznmMProject = prjRefWznmMProject;
	this->prjNum = prjNum;
	this->bvrRefWznmMVersion = bvrRefWznmMVersion;
	this->refRLocale = refRLocale;
	this->refWznmMLocale = refWznmMLocale;
	this->Major = Major;
	this->Minor = Minor;
	this->Sub = Sub;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->ixWDbmstype = ixWDbmstype;
	this->ixWOption = ixWOption;
	this->refJ = refJ;
	this->About1 = About1;
	this->About2 = About2;
	this->About3 = About3;
	this->Comment = Comment;
};

bool WznmMVersion::operator==(
			const WznmMVersion& comp
		) {
	return false;
};

bool WznmMVersion::operator!=(
			const WznmMVersion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMVersion
 ******************************************************************************/

ListWznmMVersion::ListWznmMVersion() {
};

ListWznmMVersion::ListWznmMVersion(
			const ListWznmMVersion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMVersion(*(src.nodes[i]));
};

ListWznmMVersion::~ListWznmMVersion() {
	clear();
};

void ListWznmMVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMVersion::size() const {
	return(nodes.size());
};

void ListWznmMVersion::append(
			WznmMVersion* rec
		) {
	nodes.push_back(rec);
};

WznmMVersion* ListWznmMVersion::operator[](
			const uint ix
		) {
	WznmMVersion* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMVersion& ListWznmMVersion::operator=(
			const ListWznmMVersion& src
		) {
	WznmMVersion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMVersion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMVersion::operator==(
			const ListWznmMVersion& comp
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

bool ListWznmMVersion::operator!=(
			const ListWznmMVersion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMVersion
 ******************************************************************************/

TblWznmMVersion::TblWznmMVersion() {
};

TblWznmMVersion::~TblWznmMVersion() {
};

bool TblWznmMVersion::loadRecBySQL(
			const string& sqlstr
			, WznmMVersion** rec
		) {
	return false;
};

ubigint TblWznmMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMVersion& rst
		) {
	return 0;
};

ubigint TblWznmMVersion::insertRec(
			WznmMVersion* rec
		) {
	return 0;
};

ubigint TblWznmMVersion::insertNewRec(
			WznmMVersion** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint prjRefWznmMProject
			, const uint prjNum
			, const ubigint bvrRefWznmMVersion
			, const ubigint refRLocale
			, const ubigint refWznmMLocale
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWDbmstype
			, const uint ixWOption
			, const ubigint refJ
			, const string About1
			, const string About2
			, const string About3
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMVersion* _rec = NULL;

	_rec = new WznmMVersion(0, grp, own, prjRefWznmMProject, prjNum, bvrRefWznmMVersion, refRLocale, refWznmMLocale, Major, Minor, Sub, refJState, ixVState, ixWDbmstype, ixWOption, refJ, About1, About2, About3, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMVersion::appendNewRecToRst(
			ListWznmMVersion& rst
			, WznmMVersion** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint prjRefWznmMProject
			, const uint prjNum
			, const ubigint bvrRefWznmMVersion
			, const ubigint refRLocale
			, const ubigint refWznmMLocale
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWDbmstype
			, const uint ixWOption
			, const ubigint refJ
			, const string About1
			, const string About2
			, const string About3
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMVersion* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, prjRefWznmMProject, prjNum, bvrRefWznmMVersion, refRLocale, refWznmMLocale, Major, Minor, Sub, refJState, ixVState, ixWDbmstype, ixWOption, refJ, About1, About2, About3, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMVersion::insertRst(
			ListWznmMVersion& rst
			, bool transact
		) {
};

void TblWznmMVersion::updateRec(
			WznmMVersion* rec
		) {
};

void TblWznmMVersion::updateRst(
			ListWznmMVersion& rst
			, bool transact
		) {
};

void TblWznmMVersion::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMVersion::loadRecByRef(
			ubigint ref
			, WznmMVersion** rec
		) {
	return false;
};

ubigint TblWznmMVersion::loadRefsByPrj(
			ubigint prjRefWznmMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMVersion::loadRstByPrj(
			ubigint prjRefWznmMProject
			, const bool append
			, ListWznmMVersion& rst
		) {
	return 0;
};

ubigint TblWznmMVersion::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMVersion& rst
		) {
	ubigint numload = 0;
	WznmMVersion* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMVersion
 ******************************************************************************/

MyTblWznmMVersion::MyTblWznmMVersion() :
			TblWznmMVersion()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMVersion::~MyTblWznmMVersion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMVersion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMVersion (grp, own, prjRefWznmMProject, prjNum, bvrRefWznmMVersion, refRLocale, refWznmMLocale, Major, Minor, Sub, refJState, ixVState, ixWDbmstype, ixWOption, refJ, About1, About2, About3, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMVersion SET grp = ?, own = ?, prjRefWznmMProject = ?, prjNum = ?, bvrRefWznmMVersion = ?, refRLocale = ?, refWznmMLocale = ?, Major = ?, Minor = ?, Sub = ?, refJState = ?, ixVState = ?, ixWDbmstype = ?, ixWOption = ?, refJ = ?, About1 = ?, About2 = ?, About3 = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMVersion WHERE ref = ?", false);
};

bool MyTblWznmMVersion::loadRecBySQL(
			const string& sqlstr
			, WznmMVersion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMVersion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMVersion::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMVersion::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMVersion();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->prjRefWznmMProject = atoll((char*) dbrow[3]); else _rec->prjRefWznmMProject = 0;
		if (dbrow[4]) _rec->prjNum = atol((char*) dbrow[4]); else _rec->prjNum = 0;
		if (dbrow[5]) _rec->bvrRefWznmMVersion = atoll((char*) dbrow[5]); else _rec->bvrRefWznmMVersion = 0;
		if (dbrow[6]) _rec->refRLocale = atoll((char*) dbrow[6]); else _rec->refRLocale = 0;
		if (dbrow[7]) _rec->refWznmMLocale = atoll((char*) dbrow[7]); else _rec->refWznmMLocale = 0;
		if (dbrow[8]) _rec->Major = atoi((char*) dbrow[8]); else _rec->Major = 0;
		if (dbrow[9]) _rec->Minor = atoi((char*) dbrow[9]); else _rec->Minor = 0;
		if (dbrow[10]) _rec->Sub = atoi((char*) dbrow[10]); else _rec->Sub = 0;
		if (dbrow[11]) _rec->refJState = atoll((char*) dbrow[11]); else _rec->refJState = 0;
		if (dbrow[12]) _rec->ixVState = atol((char*) dbrow[12]); else _rec->ixVState = 0;
		if (dbrow[13]) _rec->ixWDbmstype = atol((char*) dbrow[13]); else _rec->ixWDbmstype = 0;
		if (dbrow[14]) _rec->ixWOption = atol((char*) dbrow[14]); else _rec->ixWOption = 0;
		if (dbrow[15]) _rec->refJ = atoll((char*) dbrow[15]); else _rec->refJ = 0;
		if (dbrow[16]) _rec->About1.assign(dbrow[16], dblengths[16]); else _rec->About1 = "";
		if (dbrow[17]) _rec->About2.assign(dbrow[17], dblengths[17]); else _rec->About2 = "";
		if (dbrow[18]) _rec->About3.assign(dbrow[18], dblengths[18]); else _rec->About3 = "";
		if (dbrow[19]) _rec->Comment.assign(dbrow[19], dblengths[19]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMVersion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMVersion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMVersion::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMVersion::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMVersion();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->prjRefWznmMProject = atoll((char*) dbrow[3]); else rec->prjRefWznmMProject = 0;
			if (dbrow[4]) rec->prjNum = atol((char*) dbrow[4]); else rec->prjNum = 0;
			if (dbrow[5]) rec->bvrRefWznmMVersion = atoll((char*) dbrow[5]); else rec->bvrRefWznmMVersion = 0;
			if (dbrow[6]) rec->refRLocale = atoll((char*) dbrow[6]); else rec->refRLocale = 0;
			if (dbrow[7]) rec->refWznmMLocale = atoll((char*) dbrow[7]); else rec->refWznmMLocale = 0;
			if (dbrow[8]) rec->Major = atoi((char*) dbrow[8]); else rec->Major = 0;
			if (dbrow[9]) rec->Minor = atoi((char*) dbrow[9]); else rec->Minor = 0;
			if (dbrow[10]) rec->Sub = atoi((char*) dbrow[10]); else rec->Sub = 0;
			if (dbrow[11]) rec->refJState = atoll((char*) dbrow[11]); else rec->refJState = 0;
			if (dbrow[12]) rec->ixVState = atol((char*) dbrow[12]); else rec->ixVState = 0;
			if (dbrow[13]) rec->ixWDbmstype = atol((char*) dbrow[13]); else rec->ixWDbmstype = 0;
			if (dbrow[14]) rec->ixWOption = atol((char*) dbrow[14]); else rec->ixWOption = 0;
			if (dbrow[15]) rec->refJ = atoll((char*) dbrow[15]); else rec->refJ = 0;
			if (dbrow[16]) rec->About1.assign(dbrow[16], dblengths[16]); else rec->About1 = "";
			if (dbrow[17]) rec->About2.assign(dbrow[17], dblengths[17]); else rec->About2 = "";
			if (dbrow[18]) rec->About3.assign(dbrow[18], dblengths[18]); else rec->About3 = "";
			if (dbrow[19]) rec->Comment.assign(dbrow[19], dblengths[19]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMVersion::insertRec(
			WznmMVersion* rec
		) {
	unsigned long l[19]; my_bool n[19]; my_bool e[19];

	l[15] = rec->About1.length();
	l[16] = rec->About2.length();
	l[17] = rec->About3.length();
	l[18] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->prjRefWznmMProject,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->prjNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->bvrRefWznmMVersion,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refRLocale,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMLocale,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Major,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Minor,&(l[8]),&(n[8]),&(e[8])),
		bindUsmallint(&rec->Sub,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refJState,&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->ixVState,&(l[11]),&(n[11]),&(e[11])),
		bindUint(&rec->ixWDbmstype,&(l[12]),&(n[12]),&(e[12])),
		bindUint(&rec->ixWOption,&(l[13]),&(n[13]),&(e[13])),
		bindUbigint(&rec->refJ,&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->About1.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindCstring((char*) (rec->About2.c_str()),&(l[16]),&(n[16]),&(e[16])),
		bindCstring((char*) (rec->About3.c_str()),&(l[17]),&(n[17]),&(e[17])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[18]),&(n[18]),&(e[18]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMVersion::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMVersion::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMVersion::insertRst(
			ListWznmMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMVersion::updateRec(
			WznmMVersion* rec
		) {
	unsigned long l[20]; my_bool n[20]; my_bool e[20];

	l[15] = rec->About1.length();
	l[16] = rec->About2.length();
	l[17] = rec->About3.length();
	l[18] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->prjRefWznmMProject,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->prjNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->bvrRefWznmMVersion,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refRLocale,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMLocale,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Major,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Minor,&(l[8]),&(n[8]),&(e[8])),
		bindUsmallint(&rec->Sub,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refJState,&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->ixVState,&(l[11]),&(n[11]),&(e[11])),
		bindUint(&rec->ixWDbmstype,&(l[12]),&(n[12]),&(e[12])),
		bindUint(&rec->ixWOption,&(l[13]),&(n[13]),&(e[13])),
		bindUbigint(&rec->refJ,&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->About1.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindCstring((char*) (rec->About2.c_str()),&(l[16]),&(n[16]),&(e[16])),
		bindCstring((char*) (rec->About3.c_str()),&(l[17]),&(n[17]),&(e[17])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[18]),&(n[18]),&(e[18])),
		bindUbigint(&rec->ref,&(l[19]),&(n[19]),&(e[19]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMVersion::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMVersion::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMVersion::updateRst(
			ListWznmMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMVersion::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMVersion::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMVersion::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMVersion::loadRecByRef(
			ubigint ref
			, WznmMVersion** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMVersion WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMVersion::loadRefsByPrj(
			ubigint prjRefWznmMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMVersion WHERE prjRefWznmMProject = " + to_string(prjRefWznmMProject) + "", append, refs);
};

ubigint MyTblWznmMVersion::loadRstByPrj(
			ubigint prjRefWznmMProject
			, const bool append
			, ListWznmMVersion& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, prjRefWznmMProject, prjNum, bvrRefWznmMVersion, refRLocale, refWznmMLocale, Major, Minor, Sub, refJState, ixVState, ixWDbmstype, ixWOption, refJ, About1, About2, About3, Comment FROM TblWznmMVersion WHERE prjRefWznmMProject = " + to_string(prjRefWznmMProject) + " ORDER BY prjNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMVersion
 ******************************************************************************/

PgTblWznmMVersion::PgTblWznmMVersion() :
			TblWznmMVersion()
			, PgTable()
		{
};

PgTblWznmMVersion::~PgTblWznmMVersion() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMVersion::initStatements() {
	createStatement("TblWznmMVersion_insertRec", "INSERT INTO TblWznmMVersion (grp, own, prjRefWznmMProject, prjNum, bvrRefWznmMVersion, refRLocale, refWznmMLocale, Major, Minor, Sub, refJState, ixVState, ixWDbmstype, ixWOption, refJ, About1, About2, About3, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16,$17,$18,$19) RETURNING ref", 19);
	createStatement("TblWznmMVersion_updateRec", "UPDATE TblWznmMVersion SET grp = $1, own = $2, prjRefWznmMProject = $3, prjNum = $4, bvrRefWznmMVersion = $5, refRLocale = $6, refWznmMLocale = $7, Major = $8, Minor = $9, Sub = $10, refJState = $11, ixVState = $12, ixWDbmstype = $13, ixWOption = $14, refJ = $15, About1 = $16, About2 = $17, About3 = $18, Comment = $19 WHERE ref = $20", 20);
	createStatement("TblWznmMVersion_removeRecByRef", "DELETE FROM TblWznmMVersion WHERE ref = $1", 1);

	createStatement("TblWznmMVersion_loadRecByRef", "SELECT ref, grp, own, prjRefWznmMProject, prjNum, bvrRefWznmMVersion, refRLocale, refWznmMLocale, Major, Minor, Sub, refJState, ixVState, ixWDbmstype, ixWOption, refJ, About1, About2, About3, Comment FROM TblWznmMVersion WHERE ref = $1", 1);
	createStatement("TblWznmMVersion_loadRefsByPrj", "SELECT ref FROM TblWznmMVersion WHERE prjRefWznmMProject = $1", 1);
	createStatement("TblWznmMVersion_loadRstByPrj", "SELECT ref, grp, own, prjRefWznmMProject, prjNum, bvrRefWznmMVersion, refRLocale, refWznmMLocale, Major, Minor, Sub, refJState, ixVState, ixWDbmstype, ixWOption, refJ, About1, About2, About3, Comment FROM TblWznmMVersion WHERE prjRefWznmMProject = $1 ORDER BY prjNum ASC", 1);
};

bool PgTblWznmMVersion::loadRec(
			PGresult* res
			, WznmMVersion** rec
		) {
	char* ptr;

	WznmMVersion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMVersion();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "prjrefwznmmproject"),
			PQfnumber(res, "prjnum"),
			PQfnumber(res, "bvrrefwznmmversion"),
			PQfnumber(res, "refrlocale"),
			PQfnumber(res, "refwznmmlocale"),
			PQfnumber(res, "major"),
			PQfnumber(res, "minor"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwdbmstype"),
			PQfnumber(res, "ixwoption"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "about1"),
			PQfnumber(res, "about2"),
			PQfnumber(res, "about3"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->prjRefWznmMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->prjNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->bvrRefWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refRLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Major = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Minor = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Sub = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->ixWDbmstype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->ixWOption = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->About1.assign(ptr, PQgetlength(res, 0, fnum[16]));
		ptr = PQgetvalue(res, 0, fnum[17]); _rec->About2.assign(ptr, PQgetlength(res, 0, fnum[17]));
		ptr = PQgetvalue(res, 0, fnum[18]); _rec->About3.assign(ptr, PQgetlength(res, 0, fnum[18]));
		ptr = PQgetvalue(res, 0, fnum[19]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[19]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMVersion::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMVersion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMVersion* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "prjrefwznmmproject"),
			PQfnumber(res, "prjnum"),
			PQfnumber(res, "bvrrefwznmmversion"),
			PQfnumber(res, "refrlocale"),
			PQfnumber(res, "refwznmmlocale"),
			PQfnumber(res, "major"),
			PQfnumber(res, "minor"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwdbmstype"),
			PQfnumber(res, "ixwoption"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "about1"),
			PQfnumber(res, "about2"),
			PQfnumber(res, "about3"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMVersion();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->prjRefWznmMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->prjNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->bvrRefWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refRLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Major = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Minor = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Sub = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->ixWDbmstype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->ixWOption = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[15]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[16]); rec->About1.assign(ptr, PQgetlength(res, numread, fnum[16]));
			ptr = PQgetvalue(res, numread, fnum[17]); rec->About2.assign(ptr, PQgetlength(res, numread, fnum[17]));
			ptr = PQgetvalue(res, numread, fnum[18]); rec->About3.assign(ptr, PQgetlength(res, numread, fnum[18]));
			ptr = PQgetvalue(res, numread, fnum[19]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[19]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMVersion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMVersion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVersion::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMVersion::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMVersion& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVersion::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMVersion::loadRecBySQL(
			const string& sqlstr
			, WznmMVersion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVersion::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMVersion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVersion::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMVersion::insertRec(
			WznmMVersion* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _prjRefWznmMProject = htonl64(rec->prjRefWznmMProject);
	uint _prjNum = htonl(rec->prjNum);
	ubigint _bvrRefWznmMVersion = htonl64(rec->bvrRefWznmMVersion);
	ubigint _refRLocale = htonl64(rec->refRLocale);
	ubigint _refWznmMLocale = htonl64(rec->refWznmMLocale);
	usmallint _Major = htons(rec->Major);
	usmallint _Minor = htons(rec->Minor);
	usmallint _Sub = htons(rec->Sub);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWDbmstype = htonl(rec->ixWDbmstype);
	uint _ixWOption = htonl(rec->ixWOption);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_prjRefWznmMProject,
		(char*) &_prjNum,
		(char*) &_bvrRefWznmMVersion,
		(char*) &_refRLocale,
		(char*) &_refWznmMLocale,
		(char*) &_Major,
		(char*) &_Minor,
		(char*) &_Sub,
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixWDbmstype,
		(char*) &_ixWOption,
		(char*) &_refJ,
		rec->About1.c_str(),
		rec->About2.c_str(),
		rec->About3.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMVersion_insertRec", 19, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMVersion::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMVersion::insertRst(
			ListWznmMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMVersion::updateRec(
			WznmMVersion* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _prjRefWznmMProject = htonl64(rec->prjRefWznmMProject);
	uint _prjNum = htonl(rec->prjNum);
	ubigint _bvrRefWznmMVersion = htonl64(rec->bvrRefWznmMVersion);
	ubigint _refRLocale = htonl64(rec->refRLocale);
	ubigint _refWznmMLocale = htonl64(rec->refWznmMLocale);
	usmallint _Major = htons(rec->Major);
	usmallint _Minor = htons(rec->Minor);
	usmallint _Sub = htons(rec->Sub);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWDbmstype = htonl(rec->ixWDbmstype);
	uint _ixWOption = htonl(rec->ixWOption);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_prjRefWznmMProject,
		(char*) &_prjNum,
		(char*) &_bvrRefWznmMVersion,
		(char*) &_refRLocale,
		(char*) &_refWznmMLocale,
		(char*) &_Major,
		(char*) &_Minor,
		(char*) &_Sub,
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixWDbmstype,
		(char*) &_ixWOption,
		(char*) &_refJ,
		rec->About1.c_str(),
		rec->About2.c_str(),
		rec->About3.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMVersion_updateRec", 20, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMVersion::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMVersion::updateRst(
			ListWznmMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMVersion::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMVersion_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMVersion::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMVersion::loadRecByRef(
			ubigint ref
			, WznmMVersion** rec
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

	return loadRecByStmt("TblWznmMVersion_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMVersion::loadRefsByPrj(
			ubigint prjRefWznmMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _prjRefWznmMProject = htonl64(prjRefWznmMProject);

	const char* vals[] = {
		(char*) &_prjRefWznmMProject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMVersion_loadRefsByPrj", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMVersion::loadRstByPrj(
			ubigint prjRefWznmMProject
			, const bool append
			, ListWznmMVersion& rst
		) {
	ubigint _prjRefWznmMProject = htonl64(prjRefWznmMProject);

	const char* vals[] = {
		(char*) &_prjRefWznmMProject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMVersion_loadRstByPrj", 1, vals, l, f, append, rst);
};

#endif

