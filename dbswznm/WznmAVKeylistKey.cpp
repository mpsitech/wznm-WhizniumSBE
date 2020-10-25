/**
	* \file WznmAVKeylistKey.cpp
	* database access for table TblWznmAVKeylistKey (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmAVKeylistKey.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAVKeylistKey
 ******************************************************************************/

WznmAVKeylistKey::WznmAVKeylistKey(
			const ubigint ref
			, const uint klsIxWznmVKeylist
			, const uint klsNum
			, const uint x1IxWznmVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->klsIxWznmVKeylist = klsIxWznmVKeylist;
	this->klsNum = klsNum;
	this->x1IxWznmVMaintable = x1IxWznmVMaintable;
	this->x1Uref = x1Uref;
	this->Fixed = Fixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

bool WznmAVKeylistKey::operator==(
			const WznmAVKeylistKey& comp
		) {
	return false;
};

bool WznmAVKeylistKey::operator!=(
			const WznmAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAVKeylistKey
 ******************************************************************************/

ListWznmAVKeylistKey::ListWznmAVKeylistKey() {
};

ListWznmAVKeylistKey::ListWznmAVKeylistKey(
			const ListWznmAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAVKeylistKey(*(src.nodes[i]));
};

ListWznmAVKeylistKey::~ListWznmAVKeylistKey() {
	clear();
};

void ListWznmAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAVKeylistKey::size() const {
	return(nodes.size());
};

void ListWznmAVKeylistKey::append(
			WznmAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

WznmAVKeylistKey* ListWznmAVKeylistKey::operator[](
			const uint ix
		) {
	WznmAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAVKeylistKey& ListWznmAVKeylistKey::operator=(
			const ListWznmAVKeylistKey& src
		) {
	WznmAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAVKeylistKey::operator==(
			const ListWznmAVKeylistKey& comp
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

bool ListWznmAVKeylistKey::operator!=(
			const ListWznmAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAVKeylistKey
 ******************************************************************************/

TblWznmAVKeylistKey::TblWznmAVKeylistKey() {
};

TblWznmAVKeylistKey::~TblWznmAVKeylistKey() {
};

bool TblWznmAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WznmAVKeylistKey** rec
		) {
	return false;
};

ubigint TblWznmAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblWznmAVKeylistKey::insertRec(
			WznmAVKeylistKey* rec
		) {
	return 0;
};

ubigint TblWznmAVKeylistKey::insertNewRec(
			WznmAVKeylistKey** rec
			, const uint klsIxWznmVKeylist
			, const uint klsNum
			, const uint x1IxWznmVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAVKeylistKey* _rec = NULL;

	_rec = new WznmAVKeylistKey(0, klsIxWznmVKeylist, klsNum, x1IxWznmVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAVKeylistKey::appendNewRecToRst(
			ListWznmAVKeylistKey& rst
			, WznmAVKeylistKey** rec
			, const uint klsIxWznmVKeylist
			, const uint klsNum
			, const uint x1IxWznmVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WznmAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, klsIxWznmVKeylist, klsNum, x1IxWznmVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAVKeylistKey::insertRst(
			ListWznmAVKeylistKey& rst
			, bool transact
		) {
};

void TblWznmAVKeylistKey::updateRec(
			WznmAVKeylistKey* rec
		) {
};

void TblWznmAVKeylistKey::updateRst(
			ListWznmAVKeylistKey& rst
			, bool transact
		) {
};

void TblWznmAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAVKeylistKey::loadRecByRef(
			ubigint ref
			, WznmAVKeylistKey** rec
		) {
	return false;
};

bool TblWznmAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxWznmVKeylist
			, uint x1IxWznmVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return false;
};

bool TblWznmAVKeylistKey::loadRefByKlsSrf(
			uint klsIxWznmVKeylist
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWznmAVKeylistKey::loadRefsByMtbUrf(
			uint x1IxWznmVMaintable
			, ubigint x1Uref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAVKeylistKey::loadRstByKls(
			uint klsIxWznmVKeylist
			, const bool append
			, ListWznmAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblWznmAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxWznmVKeylist
			, uint x1IxWznmVMaintable
			, ubigint x1Uref
			, const bool append
			, ListWznmAVKeylistKey& rst
		) {
	return 0;
};

bool TblWznmAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblWznmAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAVKeylistKey& rst
		) {
	ubigint numload = 0;
	WznmAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAVKeylistKey
 ******************************************************************************/

MyTblWznmAVKeylistKey::MyTblWznmAVKeylistKey() :
			TblWznmAVKeylistKey()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAVKeylistKey::~MyTblWznmAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAVKeylistKey (klsIxWznmVKeylist, klsNum, x1IxWznmVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAVKeylistKey SET klsIxWznmVKeylist = ?, klsNum = ?, x1IxWznmVMaintable = ?, x1Uref = ?, Fixed = ?, sref = ?, Avail = ?, Implied = ?, refJ = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAVKeylistKey WHERE ref = ?", false);
};

bool MyTblWznmAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WznmAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAVKeylistKey::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAVKeylistKey::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->klsIxWznmVKeylist = atol((char*) dbrow[1]); else _rec->klsIxWznmVKeylist = 0;
		if (dbrow[2]) _rec->klsNum = atol((char*) dbrow[2]); else _rec->klsNum = 0;
		if (dbrow[3]) _rec->x1IxWznmVMaintable = atol((char*) dbrow[3]); else _rec->x1IxWznmVMaintable = 0;
		if (dbrow[4]) _rec->x1Uref = atoll((char*) dbrow[4]); else _rec->x1Uref = 0;
		if (dbrow[5]) _rec->Fixed = (atoi((char*) dbrow[5]) != 0); else _rec->Fixed = false;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Avail.assign(dbrow[7], dblengths[7]); else _rec->Avail = "";
		if (dbrow[8]) _rec->Implied.assign(dbrow[8], dblengths[8]); else _rec->Implied = "";
		if (dbrow[9]) _rec->refJ = atoll((char*) dbrow[9]); else _rec->refJ = 0;
		if (dbrow[10]) _rec->Title.assign(dbrow[10], dblengths[10]); else _rec->Title = "";
		if (dbrow[11]) _rec->Comment.assign(dbrow[11], dblengths[11]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAVKeylistKey::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAVKeylistKey::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->klsIxWznmVKeylist = atol((char*) dbrow[1]); else rec->klsIxWznmVKeylist = 0;
			if (dbrow[2]) rec->klsNum = atol((char*) dbrow[2]); else rec->klsNum = 0;
			if (dbrow[3]) rec->x1IxWznmVMaintable = atol((char*) dbrow[3]); else rec->x1IxWznmVMaintable = 0;
			if (dbrow[4]) rec->x1Uref = atoll((char*) dbrow[4]); else rec->x1Uref = 0;
			if (dbrow[5]) rec->Fixed = (atoi((char*) dbrow[5]) != 0); else rec->Fixed = false;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Avail.assign(dbrow[7], dblengths[7]); else rec->Avail = "";
			if (dbrow[8]) rec->Implied.assign(dbrow[8], dblengths[8]); else rec->Implied = "";
			if (dbrow[9]) rec->refJ = atoll((char*) dbrow[9]); else rec->refJ = 0;
			if (dbrow[10]) rec->Title.assign(dbrow[10], dblengths[10]); else rec->Title = "";
			if (dbrow[11]) rec->Comment.assign(dbrow[11], dblengths[11]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAVKeylistKey::insertRec(
			WznmAVKeylistKey* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxWznmVKeylist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWznmVMaintable,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAVKeylistKey::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAVKeylistKey::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAVKeylistKey::insertRst(
			ListWznmAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAVKeylistKey::updateRec(
			WznmAVKeylistKey* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxWznmVKeylist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWznmVMaintable,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAVKeylistKey::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAVKeylistKey::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAVKeylistKey::updateRst(
			ListWznmAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAVKeylistKey::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAVKeylistKey::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAVKeylistKey::loadRecByRef(
			ubigint ref
			, WznmAVKeylistKey** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblWznmAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxWznmVKeylist
			, uint x1IxWznmVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmAVKeylistKey WHERE klsIxWznmVKeylist = " + to_string(klsIxWznmVKeylist) + " AND x1IxWznmVMaintable = " + to_string(x1IxWznmVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " AND sref = '" + sref + "'", ref);
};

bool MyTblWznmAVKeylistKey::loadRefByKlsSrf(
			uint klsIxWznmVKeylist
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWznmAVKeylistKey WHERE klsIxWznmVKeylist = " + to_string(klsIxWznmVKeylist) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWznmAVKeylistKey::loadRefsByMtbUrf(
			uint x1IxWznmVMaintable
			, ubigint x1Uref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAVKeylistKey WHERE x1IxWznmVMaintable = " + to_string(x1IxWznmVMaintable) + " AND x1Uref = " + to_string(x1Uref) + "", append, refs);
};

ubigint MyTblWznmAVKeylistKey::loadRstByKls(
			uint klsIxWznmVKeylist
			, const bool append
			, ListWznmAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxWznmVKeylist, klsNum, x1IxWznmVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWznmAVKeylistKey WHERE klsIxWznmVKeylist = " + to_string(klsIxWznmVKeylist) + " ORDER BY klsNum ASC", append, rst);
};

ubigint MyTblWznmAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxWznmVKeylist
			, uint x1IxWznmVMaintable
			, ubigint x1Uref
			, const bool append
			, ListWznmAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxWznmVKeylist, klsNum, x1IxWznmVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWznmAVKeylistKey WHERE klsIxWznmVKeylist = " + to_string(klsIxWznmVKeylist) + " AND x1IxWznmVMaintable = " + to_string(x1IxWznmVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " ORDER BY klsNum ASC", append, rst);
};

bool MyTblWznmAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWznmAVKeylistKey WHERE ref = " + to_string(ref) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAVKeylistKey
 ******************************************************************************/

PgTblWznmAVKeylistKey::PgTblWznmAVKeylistKey() :
			TblWznmAVKeylistKey()
			, PgTable()
		{
};

PgTblWznmAVKeylistKey::~PgTblWznmAVKeylistKey() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAVKeylistKey::initStatements() {
	createStatement("TblWznmAVKeylistKey_insertRec", "INSERT INTO TblWznmAVKeylistKey (klsIxWznmVKeylist, klsNum, x1IxWznmVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING ref", 11);
	createStatement("TblWznmAVKeylistKey_updateRec", "UPDATE TblWznmAVKeylistKey SET klsIxWznmVKeylist = $1, klsNum = $2, x1IxWznmVMaintable = $3, x1Uref = $4, Fixed = $5, sref = $6, Avail = $7, Implied = $8, refJ = $9, Title = $10, Comment = $11 WHERE ref = $12", 12);
	createStatement("TblWznmAVKeylistKey_removeRecByRef", "DELETE FROM TblWznmAVKeylistKey WHERE ref = $1", 1);

	createStatement("TblWznmAVKeylistKey_loadRecByRef", "SELECT ref, klsIxWznmVKeylist, klsNum, x1IxWznmVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWznmAVKeylistKey WHERE ref = $1", 1);
	createStatement("TblWznmAVKeylistKey_loadRefByKlsMtbUrfSrf", "SELECT ref FROM TblWznmAVKeylistKey WHERE klsIxWznmVKeylist = $1 AND x1IxWznmVMaintable = $2 AND x1Uref = $3 AND sref = $4", 4);
	createStatement("TblWznmAVKeylistKey_loadRefByKlsSrf", "SELECT ref FROM TblWznmAVKeylistKey WHERE klsIxWznmVKeylist = $1 AND sref = $2", 2);
	createStatement("TblWznmAVKeylistKey_loadRefsByMtbUrf", "SELECT ref FROM TblWznmAVKeylistKey WHERE x1IxWznmVMaintable = $1 AND x1Uref = $2", 2);
	createStatement("TblWznmAVKeylistKey_loadRstByKls", "SELECT ref, klsIxWznmVKeylist, klsNum, x1IxWznmVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWznmAVKeylistKey WHERE klsIxWznmVKeylist = $1 ORDER BY klsNum ASC", 1);
	createStatement("TblWznmAVKeylistKey_loadRstByKlsMtbUrf", "SELECT ref, klsIxWznmVKeylist, klsNum, x1IxWznmVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWznmAVKeylistKey WHERE klsIxWznmVKeylist = $1 AND x1IxWznmVMaintable = $2 AND x1Uref = $3 ORDER BY klsNum ASC", 3);
	createStatement("TblWznmAVKeylistKey_loadTitByRef", "SELECT Title FROM TblWznmAVKeylistKey WHERE ref = $1", 1);
};

bool PgTblWznmAVKeylistKey::loadRec(
			PGresult* res
			, WznmAVKeylistKey** rec
		) {
	char* ptr;

	WznmAVKeylistKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAVKeylistKey();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsixwznmvkeylist"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "x1ixwznmvmaintable"),
			PQfnumber(res, "x1uref"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->klsIxWznmVKeylist = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->klsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1IxWznmVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1Uref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Fixed = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Implied.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAVKeylistKey::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAVKeylistKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAVKeylistKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsixwznmvkeylist"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "x1ixwznmvmaintable"),
			PQfnumber(res, "x1uref"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmAVKeylistKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->klsIxWznmVKeylist = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->klsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1IxWznmVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1Uref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Fixed = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Implied.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAVKeylistKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVKeylistKey::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAVKeylistKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVKeylistKey::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WznmAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVKeylistKey::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVKeylistKey::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAVKeylistKey::insertRec(
			WznmAVKeylistKey* rec
		) {
	PGresult* res;
	char* ptr;

	uint _klsIxWznmVKeylist = htonl(rec->klsIxWznmVKeylist);
	uint _klsNum = htonl(rec->klsNum);
	uint _x1IxWznmVMaintable = htonl(rec->x1IxWznmVMaintable);
	ubigint _x1Uref = htonl64(rec->x1Uref);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_klsIxWznmVKeylist,
		(char*) &_klsNum,
		(char*) &_x1IxWznmVMaintable,
		(char*) &_x1Uref,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmAVKeylistKey_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVKeylistKey::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAVKeylistKey::insertRst(
			ListWznmAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAVKeylistKey::updateRec(
			WznmAVKeylistKey* rec
		) {
	PGresult* res;

	uint _klsIxWznmVKeylist = htonl(rec->klsIxWznmVKeylist);
	uint _klsNum = htonl(rec->klsNum);
	uint _x1IxWznmVMaintable = htonl(rec->x1IxWznmVMaintable);
	ubigint _x1Uref = htonl64(rec->x1Uref);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_klsIxWznmVKeylist,
		(char*) &_klsNum,
		(char*) &_x1IxWznmVMaintable,
		(char*) &_x1Uref,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAVKeylistKey_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAVKeylistKey::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAVKeylistKey::updateRst(
			ListWznmAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAVKeylistKey::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAVKeylistKey_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAVKeylistKey::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAVKeylistKey::loadRecByRef(
			ubigint ref
			, WznmAVKeylistKey** rec
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

	return loadRecByStmt("TblWznmAVKeylistKey_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWznmAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxWznmVKeylist
			, uint x1IxWznmVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	uint _klsIxWznmVKeylist = htonl(klsIxWznmVKeylist);
	uint _x1IxWznmVMaintable = htonl(x1IxWznmVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_klsIxWznmVKeylist,
		(char*) &_x1IxWznmVMaintable,
		(char*) &_x1Uref,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,1,0};

	return loadRefByStmt("TblWznmAVKeylistKey_loadRefByKlsMtbUrfSrf", 4, vals, l, f, ref);
};

bool PgTblWznmAVKeylistKey::loadRefByKlsSrf(
			uint klsIxWznmVKeylist
			, string sref
			, ubigint& ref
		) {
	uint _klsIxWznmVKeylist = htonl(klsIxWznmVKeylist);

	const char* vals[] = {
		(char*) &_klsIxWznmVKeylist,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		0
	};
	const int f[] = {1,0};

	return loadRefByStmt("TblWznmAVKeylistKey_loadRefByKlsSrf", 2, vals, l, f, ref);
};

ubigint PgTblWznmAVKeylistKey::loadRefsByMtbUrf(
			uint x1IxWznmVMaintable
			, ubigint x1Uref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _x1IxWznmVMaintable = htonl(x1IxWznmVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_x1IxWznmVMaintable,
		(char*) &_x1Uref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblWznmAVKeylistKey_loadRefsByMtbUrf", 2, vals, l, f, append, refs);
};

ubigint PgTblWznmAVKeylistKey::loadRstByKls(
			uint klsIxWznmVKeylist
			, const bool append
			, ListWznmAVKeylistKey& rst
		) {
	uint _klsIxWznmVKeylist = htonl(klsIxWznmVKeylist);

	const char* vals[] = {
		(char*) &_klsIxWznmVKeylist
	};
	const int l[] = {
		sizeof(uint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAVKeylistKey_loadRstByKls", 1, vals, l, f, append, rst);
};

ubigint PgTblWznmAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxWznmVKeylist
			, uint x1IxWznmVMaintable
			, ubigint x1Uref
			, const bool append
			, ListWznmAVKeylistKey& rst
		) {
	uint _klsIxWznmVKeylist = htonl(klsIxWznmVKeylist);
	uint _x1IxWznmVMaintable = htonl(x1IxWznmVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_klsIxWznmVKeylist,
		(char*) &_x1IxWznmVMaintable,
		(char*) &_x1Uref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRstByStmt("TblWznmAVKeylistKey_loadRstByKlsMtbUrf", 3, vals, l, f, append, rst);
};

bool PgTblWznmAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWznmAVKeylistKey_loadTitByRef", 1, vals, l, f, Title);
};

#endif

