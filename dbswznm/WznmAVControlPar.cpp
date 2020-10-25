/**
	* \file WznmAVControlPar.cpp
	* database access for table TblWznmAVControlPar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmAVControlPar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAVControlPar
 ******************************************************************************/

WznmAVControlPar::WznmAVControlPar(
			const ubigint ref
			, const uint ixWznmVControl
			, const ubigint x1RefWznmMUser
			, const uint x2IxWznmVLocale
			, const string Par
			, const string Val
		) {

	this->ref = ref;
	this->ixWznmVControl = ixWznmVControl;
	this->x1RefWznmMUser = x1RefWznmMUser;
	this->x2IxWznmVLocale = x2IxWznmVLocale;
	this->Par = Par;
	this->Val = Val;
};

bool WznmAVControlPar::operator==(
			const WznmAVControlPar& comp
		) {
	return false;
};

bool WznmAVControlPar::operator!=(
			const WznmAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAVControlPar
 ******************************************************************************/

ListWznmAVControlPar::ListWznmAVControlPar() {
};

ListWznmAVControlPar::ListWznmAVControlPar(
			const ListWznmAVControlPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAVControlPar(*(src.nodes[i]));
};

ListWznmAVControlPar::~ListWznmAVControlPar() {
	clear();
};

void ListWznmAVControlPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAVControlPar::size() const {
	return(nodes.size());
};

void ListWznmAVControlPar::append(
			WznmAVControlPar* rec
		) {
	nodes.push_back(rec);
};

WznmAVControlPar* ListWznmAVControlPar::operator[](
			const uint ix
		) {
	WznmAVControlPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAVControlPar& ListWznmAVControlPar::operator=(
			const ListWznmAVControlPar& src
		) {
	WznmAVControlPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAVControlPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAVControlPar::operator==(
			const ListWznmAVControlPar& comp
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

bool ListWznmAVControlPar::operator!=(
			const ListWznmAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAVControlPar
 ******************************************************************************/

TblWznmAVControlPar::TblWznmAVControlPar() {
};

TblWznmAVControlPar::~TblWznmAVControlPar() {
};

bool TblWznmAVControlPar::loadRecBySQL(
			const string& sqlstr
			, WznmAVControlPar** rec
		) {
	return false;
};

ubigint TblWznmAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAVControlPar& rst
		) {
	return 0;
};

ubigint TblWznmAVControlPar::insertRec(
			WznmAVControlPar* rec
		) {
	return 0;
};

ubigint TblWznmAVControlPar::insertNewRec(
			WznmAVControlPar** rec
			, const uint ixWznmVControl
			, const ubigint x1RefWznmMUser
			, const uint x2IxWznmVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	WznmAVControlPar* _rec = NULL;

	_rec = new WznmAVControlPar(0, ixWznmVControl, x1RefWznmMUser, x2IxWznmVLocale, Par, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAVControlPar::appendNewRecToRst(
			ListWznmAVControlPar& rst
			, WznmAVControlPar** rec
			, const uint ixWznmVControl
			, const ubigint x1RefWznmMUser
			, const uint x2IxWznmVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	WznmAVControlPar* _rec = NULL;

	retval = insertNewRec(&_rec, ixWznmVControl, x1RefWznmMUser, x2IxWznmVLocale, Par, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAVControlPar::insertRst(
			ListWznmAVControlPar& rst
			, bool transact
		) {
};

void TblWznmAVControlPar::updateRec(
			WznmAVControlPar* rec
		) {
};

void TblWznmAVControlPar::updateRst(
			ListWznmAVControlPar& rst
			, bool transact
		) {
};

void TblWznmAVControlPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAVControlPar::loadRecByRef(
			ubigint ref
			, WznmAVControlPar** rec
		) {
	return false;
};

ubigint TblWznmAVControlPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAVControlPar& rst
		) {
	ubigint numload = 0;
	WznmAVControlPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAVControlPar
 ******************************************************************************/

MyTblWznmAVControlPar::MyTblWznmAVControlPar() :
			TblWznmAVControlPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAVControlPar::~MyTblWznmAVControlPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAVControlPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAVControlPar (ixWznmVControl, x1RefWznmMUser, x2IxWznmVLocale, Par, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAVControlPar SET ixWznmVControl = ?, x1RefWznmMUser = ?, x2IxWznmVLocale = ?, Par = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAVControlPar WHERE ref = ?", false);
};

bool MyTblWznmAVControlPar::loadRecBySQL(
			const string& sqlstr
			, WznmAVControlPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAVControlPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAVControlPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAVControlPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAVControlPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixWznmVControl = atol((char*) dbrow[1]); else _rec->ixWznmVControl = 0;
		if (dbrow[2]) _rec->x1RefWznmMUser = atoll((char*) dbrow[2]); else _rec->x1RefWznmMUser = 0;
		if (dbrow[3]) _rec->x2IxWznmVLocale = atol((char*) dbrow[3]); else _rec->x2IxWznmVLocale = 0;
		if (dbrow[4]) _rec->Par.assign(dbrow[4], dblengths[4]); else _rec->Par = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAVControlPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAVControlPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAVControlPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAVControlPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAVControlPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixWznmVControl = atol((char*) dbrow[1]); else rec->ixWznmVControl = 0;
			if (dbrow[2]) rec->x1RefWznmMUser = atoll((char*) dbrow[2]); else rec->x1RefWznmMUser = 0;
			if (dbrow[3]) rec->x2IxWznmVLocale = atol((char*) dbrow[3]); else rec->x2IxWznmVLocale = 0;
			if (dbrow[4]) rec->Par.assign(dbrow[4], dblengths[4]); else rec->Par = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAVControlPar::insertRec(
			WznmAVControlPar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixWznmVControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMUser,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxWznmVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAVControlPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAVControlPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAVControlPar::insertRst(
			ListWznmAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAVControlPar::updateRec(
			WznmAVControlPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixWznmVControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWznmMUser,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxWznmVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAVControlPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAVControlPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAVControlPar::updateRst(
			ListWznmAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAVControlPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAVControlPar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAVControlPar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAVControlPar::loadRecByRef(
			ubigint ref
			, WznmAVControlPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAVControlPar WHERE ref = " + to_string(ref), rec);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAVControlPar
 ******************************************************************************/

PgTblWznmAVControlPar::PgTblWznmAVControlPar() :
			TblWznmAVControlPar()
			, PgTable()
		{
};

PgTblWznmAVControlPar::~PgTblWznmAVControlPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAVControlPar::initStatements() {
	createStatement("TblWznmAVControlPar_insertRec", "INSERT INTO TblWznmAVControlPar (ixWznmVControl, x1RefWznmMUser, x2IxWznmVLocale, Par, Val) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWznmAVControlPar_updateRec", "UPDATE TblWznmAVControlPar SET ixWznmVControl = $1, x1RefWznmMUser = $2, x2IxWznmVLocale = $3, Par = $4, Val = $5 WHERE ref = $6", 6);
	createStatement("TblWznmAVControlPar_removeRecByRef", "DELETE FROM TblWznmAVControlPar WHERE ref = $1", 1);

	createStatement("TblWznmAVControlPar_loadRecByRef", "SELECT ref, ixWznmVControl, x1RefWznmMUser, x2IxWznmVLocale, Par, Val FROM TblWznmAVControlPar WHERE ref = $1", 1);
};

bool PgTblWznmAVControlPar::loadRec(
			PGresult* res
			, WznmAVControlPar** rec
		) {
	char* ptr;

	WznmAVControlPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAVControlPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixwznmvcontrol"),
			PQfnumber(res, "x1refwznmmuser"),
			PQfnumber(res, "x2ixwznmvlocale"),
			PQfnumber(res, "par"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixWznmVControl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWznmMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2IxWznmVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Par.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAVControlPar::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAVControlPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAVControlPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixwznmvcontrol"),
			PQfnumber(res, "x1refwznmmuser"),
			PQfnumber(res, "x2ixwznmvlocale"),
			PQfnumber(res, "par"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WznmAVControlPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixWznmVControl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWznmMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2IxWznmVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Par.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAVControlPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAVControlPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVControlPar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmAVControlPar::loadRecBySQL(
			const string& sqlstr
			, WznmAVControlPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVControlPar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAVControlPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVControlPar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAVControlPar::insertRec(
			WznmAVControlPar* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixWznmVControl = htonl(rec->ixWznmVControl);
	ubigint _x1RefWznmMUser = htonl64(rec->x1RefWznmMUser);
	uint _x2IxWznmVLocale = htonl(rec->x2IxWznmVLocale);

	const char* vals[] = {
		(char*) &_ixWznmVControl,
		(char*) &_x1RefWznmMUser,
		(char*) &_x2IxWznmVLocale,
		rec->Par.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmAVControlPar_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAVControlPar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAVControlPar::insertRst(
			ListWznmAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAVControlPar::updateRec(
			WznmAVControlPar* rec
		) {
	PGresult* res;

	uint _ixWznmVControl = htonl(rec->ixWznmVControl);
	ubigint _x1RefWznmMUser = htonl64(rec->x1RefWznmMUser);
	uint _x2IxWznmVLocale = htonl(rec->x2IxWznmVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixWznmVControl,
		(char*) &_x1RefWznmMUser,
		(char*) &_x2IxWznmVLocale,
		rec->Par.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAVControlPar_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAVControlPar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAVControlPar::updateRst(
			ListWznmAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAVControlPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAVControlPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAVControlPar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAVControlPar::loadRecByRef(
			ubigint ref
			, WznmAVControlPar** rec
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

	return loadRecByStmt("TblWznmAVControlPar_loadRecByRef", 1, vals, l, f, rec);
};

#endif

