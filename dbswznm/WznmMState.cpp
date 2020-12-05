/**
	* \file WznmMState.cpp
	* database access for table TblWznmMState (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMState.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMState
 ******************************************************************************/

WznmMState::WznmMState(
			const ubigint ref
			, const ubigint seqRefWznmMSequence
			, const uint seqNum
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->seqRefWznmMSequence = seqRefWznmMSequence;
	this->seqNum = seqNum;
	this->sref = sref;
	this->Comment = Comment;
};

bool WznmMState::operator==(
			const WznmMState& comp
		) {
	return false;
};

bool WznmMState::operator!=(
			const WznmMState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMState
 ******************************************************************************/

ListWznmMState::ListWznmMState() {
};

ListWznmMState::ListWznmMState(
			const ListWznmMState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMState(*(src.nodes[i]));
};

ListWznmMState::~ListWznmMState() {
	clear();
};

void ListWznmMState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMState::size() const {
	return(nodes.size());
};

void ListWznmMState::append(
			WznmMState* rec
		) {
	nodes.push_back(rec);
};

WznmMState* ListWznmMState::operator[](
			const uint ix
		) {
	WznmMState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMState& ListWznmMState::operator=(
			const ListWznmMState& src
		) {
	WznmMState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMState::operator==(
			const ListWznmMState& comp
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

bool ListWznmMState::operator!=(
			const ListWznmMState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMState
 ******************************************************************************/

TblWznmMState::TblWznmMState() {
};

TblWznmMState::~TblWznmMState() {
};

bool TblWznmMState::loadRecBySQL(
			const string& sqlstr
			, WznmMState** rec
		) {
	return false;
};

ubigint TblWznmMState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMState& rst
		) {
	return 0;
};

ubigint TblWznmMState::insertRec(
			WznmMState* rec
		) {
	return 0;
};

ubigint TblWznmMState::insertNewRec(
			WznmMState** rec
			, const ubigint seqRefWznmMSequence
			, const uint seqNum
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMState* _rec = NULL;

	_rec = new WznmMState(0, seqRefWznmMSequence, seqNum, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMState::appendNewRecToRst(
			ListWznmMState& rst
			, WznmMState** rec
			, const ubigint seqRefWznmMSequence
			, const uint seqNum
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WznmMState* _rec = NULL;

	retval = insertNewRec(&_rec, seqRefWznmMSequence, seqNum, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMState::insertRst(
			ListWznmMState& rst
			, bool transact
		) {
};

void TblWznmMState::updateRec(
			WznmMState* rec
		) {
};

void TblWznmMState::updateRst(
			ListWznmMState& rst
			, bool transact
		) {
};

void TblWznmMState::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMState::loadRecByRef(
			ubigint ref
			, WznmMState** rec
		) {
	return false;
};

ubigint TblWznmMState::loadRefsBySeq(
			ubigint seqRefWznmMSequence
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmMState::loadRstBySeq(
			ubigint seqRefWznmMSequence
			, const bool append
			, ListWznmMState& rst
		) {
	return 0;
};

bool TblWznmMState::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWznmMState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMState& rst
		) {
	ubigint numload = 0;
	WznmMState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMState
 ******************************************************************************/

MyTblWznmMState::MyTblWznmMState() :
			TblWznmMState()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMState::~MyTblWznmMState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMState (seqRefWznmMSequence, seqNum, sref, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMState SET seqRefWznmMSequence = ?, seqNum = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMState WHERE ref = ?", false);
};

bool MyTblWznmMState::loadRecBySQL(
			const string& sqlstr
			, WznmMState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMState::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMState::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->seqRefWznmMSequence = atoll((char*) dbrow[1]); else _rec->seqRefWznmMSequence = 0;
		if (dbrow[2]) _rec->seqNum = atol((char*) dbrow[2]); else _rec->seqNum = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMState::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMState::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->seqRefWznmMSequence = atoll((char*) dbrow[1]); else rec->seqRefWznmMSequence = 0;
			if (dbrow[2]) rec->seqNum = atol((char*) dbrow[2]); else rec->seqNum = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMState::insertRec(
			WznmMState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->seqRefWznmMSequence,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->seqNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMState::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMState::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMState::insertRst(
			ListWznmMState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMState::updateRec(
			WznmMState* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->seqRefWznmMSequence,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->seqNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMState::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMState::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMState::updateRst(
			ListWznmMState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMState::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMState::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMState::loadRecByRef(
			ubigint ref
			, WznmMState** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMState WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmMState::loadRefsBySeq(
			ubigint seqRefWznmMSequence
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmMState WHERE seqRefWznmMSequence = " + to_string(seqRefWznmMSequence) + "", append, refs);
};

ubigint MyTblWznmMState::loadRstBySeq(
			ubigint seqRefWznmMSequence
			, const bool append
			, ListWznmMState& rst
		) {
	return loadRstBySQL("SELECT ref, seqRefWznmMSequence, seqNum, sref, Comment FROM TblWznmMState WHERE seqRefWznmMSequence = " + to_string(seqRefWznmMSequence) + " ORDER BY seqNum ASC", append, rst);
};

bool MyTblWznmMState::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWznmMState WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMState
 ******************************************************************************/

PgTblWznmMState::PgTblWznmMState() :
			TblWznmMState()
			, PgTable()
		{
};

PgTblWznmMState::~PgTblWznmMState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMState::initStatements() {
	createStatement("TblWznmMState_insertRec", "INSERT INTO TblWznmMState (seqRefWznmMSequence, seqNum, sref, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWznmMState_updateRec", "UPDATE TblWznmMState SET seqRefWznmMSequence = $1, seqNum = $2, sref = $3, Comment = $4 WHERE ref = $5", 5);
	createStatement("TblWznmMState_removeRecByRef", "DELETE FROM TblWznmMState WHERE ref = $1", 1);

	createStatement("TblWznmMState_loadRecByRef", "SELECT ref, seqRefWznmMSequence, seqNum, sref, Comment FROM TblWznmMState WHERE ref = $1", 1);
	createStatement("TblWznmMState_loadRefsBySeq", "SELECT ref FROM TblWznmMState WHERE seqRefWznmMSequence = $1", 1);
	createStatement("TblWznmMState_loadRstBySeq", "SELECT ref, seqRefWznmMSequence, seqNum, sref, Comment FROM TblWznmMState WHERE seqRefWznmMSequence = $1 ORDER BY seqNum ASC", 1);
	createStatement("TblWznmMState_loadSrfByRef", "SELECT sref FROM TblWznmMState WHERE ref = $1", 1);
};

bool PgTblWznmMState::loadRec(
			PGresult* res
			, WznmMState** rec
		) {
	char* ptr;

	WznmMState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "seqrefwznmmsequence"),
			PQfnumber(res, "seqnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->seqRefWznmMSequence = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->seqNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMState::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "seqrefwznmmsequence"),
			PQfnumber(res, "seqnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WznmMState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->seqRefWznmMSequence = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->seqNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMState::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmMState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMState::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmMState::loadRecBySQL(
			const string& sqlstr
			, WznmMState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMState::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMState::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMState::insertRec(
			WznmMState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _seqRefWznmMSequence = htonl64(rec->seqRefWznmMSequence);
	uint _seqNum = htonl(rec->seqNum);

	const char* vals[] = {
		(char*) &_seqRefWznmMSequence,
		(char*) &_seqNum,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMState_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMState::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMState::insertRst(
			ListWznmMState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMState::updateRec(
			WznmMState* rec
		) {
	PGresult* res;

	ubigint _seqRefWznmMSequence = htonl64(rec->seqRefWznmMSequence);
	uint _seqNum = htonl(rec->seqNum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_seqRefWznmMSequence,
		(char*) &_seqNum,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMState_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMState::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMState::updateRst(
			ListWznmMState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMState::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMState::loadRecByRef(
			ubigint ref
			, WznmMState** rec
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

	return loadRecByStmt("TblWznmMState_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmMState::loadRefsBySeq(
			ubigint seqRefWznmMSequence
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _seqRefWznmMSequence = htonl64(seqRefWznmMSequence);

	const char* vals[] = {
		(char*) &_seqRefWznmMSequence
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmMState_loadRefsBySeq", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmMState::loadRstBySeq(
			ubigint seqRefWznmMSequence
			, const bool append
			, ListWznmMState& rst
		) {
	ubigint _seqRefWznmMSequence = htonl64(seqRefWznmMSequence);

	const char* vals[] = {
		(char*) &_seqRefWznmMSequence
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmMState_loadRstBySeq", 1, vals, l, f, append, rst);
};

bool PgTblWznmMState::loadSrfByRef(
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

	return loadStringByStmt("TblWznmMState_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

