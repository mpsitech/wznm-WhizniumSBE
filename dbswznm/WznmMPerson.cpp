/**
	* \file WznmMPerson.cpp
	* database access for table TblWznmMPerson (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmMPerson.h"

#include "WznmMPerson_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmMPerson
 ******************************************************************************/

WznmMPerson::WznmMPerson(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const uint ixWDerivate
			, const uint ixVSex
			, const string Title
			, const string Firstname
			, const ubigint refJLastname
			, const string Lastname
			, const ubigint telRefADetail
			, const string telVal
			, const ubigint emlRefADetail
			, const string emlVal
			, const string Salutation
		) :
			ref(ref)
			, grp(grp)
			, own(own)
			, ixWDerivate(ixWDerivate)
			, ixVSex(ixVSex)
			, Title(Title)
			, Firstname(Firstname)
			, refJLastname(refJLastname)
			, Lastname(Lastname)
			, telRefADetail(telRefADetail)
			, telVal(telVal)
			, emlRefADetail(emlRefADetail)
			, emlVal(emlVal)
			, Salutation(Salutation)
		{
};

bool WznmMPerson::operator==(
			const WznmMPerson& comp
		) {
	return false;
};

bool WznmMPerson::operator!=(
			const WznmMPerson& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmMPerson
 ******************************************************************************/

ListWznmMPerson::ListWznmMPerson() {
};

ListWznmMPerson::ListWznmMPerson(
			const ListWznmMPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmMPerson(*(src.nodes[i]));
};

ListWznmMPerson::~ListWznmMPerson() {
	clear();
};

void ListWznmMPerson::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmMPerson::size() const {
	return(nodes.size());
};

void ListWznmMPerson::append(
			WznmMPerson* rec
		) {
	nodes.push_back(rec);
};

WznmMPerson* ListWznmMPerson::operator[](
			const uint ix
		) {
	WznmMPerson* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmMPerson& ListWznmMPerson::operator=(
			const ListWznmMPerson& src
		) {
	WznmMPerson* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmMPerson(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmMPerson::operator==(
			const ListWznmMPerson& comp
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

bool ListWznmMPerson::operator!=(
			const ListWznmMPerson& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmMPerson
 ******************************************************************************/

TblWznmMPerson::TblWznmMPerson() {
};

TblWznmMPerson::~TblWznmMPerson() {
};

bool TblWznmMPerson::loadRecBySQL(
			const string& sqlstr
			, WznmMPerson** rec
		) {
	return false;
};

ubigint TblWznmMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMPerson& rst
		) {
	return 0;
};

ubigint TblWznmMPerson::insertRec(
			WznmMPerson* rec
		) {
	return 0;
};

ubigint TblWznmMPerson::insertNewRec(
			WznmMPerson** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixWDerivate
			, const uint ixVSex
			, const string Title
			, const string Firstname
			, const ubigint refJLastname
			, const string Lastname
			, const ubigint telRefADetail
			, const string telVal
			, const ubigint emlRefADetail
			, const string emlVal
			, const string Salutation
		) {
	ubigint retval = 0;
	WznmMPerson* _rec = NULL;

	_rec = new WznmMPerson(0, grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, telVal, emlRefADetail, emlVal, Salutation);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmMPerson::appendNewRecToRst(
			ListWznmMPerson& rst
			, WznmMPerson** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixWDerivate
			, const uint ixVSex
			, const string Title
			, const string Firstname
			, const ubigint refJLastname
			, const string Lastname
			, const ubigint telRefADetail
			, const string telVal
			, const ubigint emlRefADetail
			, const string emlVal
			, const string Salutation
		) {
	ubigint retval = 0;
	WznmMPerson* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, telVal, emlRefADetail, emlVal, Salutation);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmMPerson::insertRst(
			ListWznmMPerson& rst
			, bool transact
		) {
};

void TblWznmMPerson::updateRec(
			WznmMPerson* rec
		) {
};

void TblWznmMPerson::updateRst(
			ListWznmMPerson& rst
			, bool transact
		) {
};

void TblWznmMPerson::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmMPerson::loadRecByRef(
			ubigint ref
			, WznmMPerson** rec
		) {
	return false;
};

ubigint TblWznmMPerson::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmMPerson& rst
		) {
	ubigint numload = 0;
	WznmMPerson* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmMPerson
 ******************************************************************************/

MyTblWznmMPerson::MyTblWznmMPerson() :
			TblWznmMPerson()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmMPerson::~MyTblWznmMPerson() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmMPerson::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmMPerson (grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, telVal, emlRefADetail, emlVal, Salutation) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmMPerson SET grp = ?, own = ?, ixWDerivate = ?, ixVSex = ?, Title = ?, Firstname = ?, refJLastname = ?, Lastname = ?, telRefADetail = ?, telVal = ?, emlRefADetail = ?, emlVal = ?, Salutation = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmMPerson WHERE ref = ?", false);
};

bool MyTblWznmMPerson::loadRecBySQL(
			const string& sqlstr
			, WznmMPerson** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmMPerson* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMPerson::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMPerson::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmMPerson();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->ixWDerivate = atol((char*) dbrow[3]); else _rec->ixWDerivate = 0;
		if (dbrow[4]) _rec->ixVSex = atol((char*) dbrow[4]); else _rec->ixVSex = 0;
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->Firstname.assign(dbrow[6], dblengths[6]); else _rec->Firstname = "";
		if (dbrow[7]) _rec->refJLastname = atoll((char*) dbrow[7]); else _rec->refJLastname = 0;
		if (dbrow[8]) _rec->Lastname.assign(dbrow[8], dblengths[8]); else _rec->Lastname = "";
		if (dbrow[9]) _rec->telRefADetail = atoll((char*) dbrow[9]); else _rec->telRefADetail = 0;
		if (dbrow[10]) _rec->telVal.assign(dbrow[10], dblengths[10]); else _rec->telVal = "";
		if (dbrow[11]) _rec->emlRefADetail = atoll((char*) dbrow[11]); else _rec->emlRefADetail = 0;
		if (dbrow[12]) _rec->emlVal.assign(dbrow[12], dblengths[12]); else _rec->emlVal = "";
		if (dbrow[13]) _rec->Salutation.assign(dbrow[13], dblengths[13]); else _rec->Salutation = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMPerson& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmMPerson* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmMPerson::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmMPerson::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmMPerson();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->ixWDerivate = atol((char*) dbrow[3]); else rec->ixWDerivate = 0;
			if (dbrow[4]) rec->ixVSex = atol((char*) dbrow[4]); else rec->ixVSex = 0;
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->Firstname.assign(dbrow[6], dblengths[6]); else rec->Firstname = "";
			if (dbrow[7]) rec->refJLastname = atoll((char*) dbrow[7]); else rec->refJLastname = 0;
			if (dbrow[8]) rec->Lastname.assign(dbrow[8], dblengths[8]); else rec->Lastname = "";
			if (dbrow[9]) rec->telRefADetail = atoll((char*) dbrow[9]); else rec->telRefADetail = 0;
			if (dbrow[10]) rec->telVal.assign(dbrow[10], dblengths[10]); else rec->telVal = "";
			if (dbrow[11]) rec->emlRefADetail = atoll((char*) dbrow[11]); else rec->emlRefADetail = 0;
			if (dbrow[12]) rec->emlVal.assign(dbrow[12], dblengths[12]); else rec->emlVal = "";
			if (dbrow[13]) rec->Salutation.assign(dbrow[13], dblengths[13]); else rec->Salutation = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmMPerson::insertRec(
			WznmMPerson* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[4] = rec->Title.length();
	l[5] = rec->Firstname.length();
	l[7] = rec->Lastname.length();
	l[9] = rec->telVal.length();
	l[11] = rec->emlVal.length();
	l[12] = rec->Salutation.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWDerivate,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVSex,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJLastname,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->telRefADetail,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->telVal.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->emlRefADetail,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->emlVal.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Salutation.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmMPerson::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmMPerson::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmMPerson::insertRst(
			ListWznmMPerson& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmMPerson::updateRec(
			WznmMPerson* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[4] = rec->Title.length();
	l[5] = rec->Firstname.length();
	l[7] = rec->Lastname.length();
	l[9] = rec->telVal.length();
	l[11] = rec->emlVal.length();
	l[12] = rec->Salutation.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWDerivate,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVSex,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJLastname,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->telRefADetail,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->telVal.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->emlRefADetail,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->emlVal.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Salutation.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmMPerson::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmMPerson::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmMPerson::updateRst(
			ListWznmMPerson& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmMPerson::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmMPerson::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmMPerson::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmMPerson::loadRecByRef(
			ubigint ref
			, WznmMPerson** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmMPerson WHERE ref = " + to_string(ref), rec);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmMPerson
 ******************************************************************************/

PgTblWznmMPerson::PgTblWznmMPerson() :
			TblWznmMPerson()
			, PgTable()
		{
};

PgTblWznmMPerson::~PgTblWznmMPerson() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmMPerson::initStatements() {
	createStatement("TblWznmMPerson_insertRec", "INSERT INTO TblWznmMPerson (grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, telVal, emlRefADetail, emlVal, Salutation) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING ref", 13);
	createStatement("TblWznmMPerson_updateRec", "UPDATE TblWznmMPerson SET grp = $1, own = $2, ixWDerivate = $3, ixVSex = $4, Title = $5, Firstname = $6, refJLastname = $7, Lastname = $8, telRefADetail = $9, telVal = $10, emlRefADetail = $11, emlVal = $12, Salutation = $13 WHERE ref = $14", 14);
	createStatement("TblWznmMPerson_removeRecByRef", "DELETE FROM TblWznmMPerson WHERE ref = $1", 1);

	createStatement("TblWznmMPerson_loadRecByRef", "SELECT ref, grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, telVal, emlRefADetail, emlVal, Salutation FROM TblWznmMPerson WHERE ref = $1", 1);
};

bool PgTblWznmMPerson::loadRec(
			PGresult* res
			, WznmMPerson** rec
		) {
	char* ptr;

	WznmMPerson* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmMPerson();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixwderivate"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "refjlastname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "telrefadetail"),
			PQfnumber(res, "telval"),
			PQfnumber(res, "emlrefadetail"),
			PQfnumber(res, "emlval"),
			PQfnumber(res, "salutation")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixWDerivate = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVSex = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Firstname.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJLastname = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->telRefADetail = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->telVal.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->emlRefADetail = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->emlVal.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Salutation.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmMPerson::loadRst(
			PGresult* res
			, const bool append
			, ListWznmMPerson& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmMPerson* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixwderivate"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "refjlastname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "telrefadetail"),
			PQfnumber(res, "telval"),
			PQfnumber(res, "emlrefadetail"),
			PQfnumber(res, "emlval"),
			PQfnumber(res, "salutation")
		};

		while (numread < numrow) {
			rec = new WznmMPerson();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixWDerivate = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVSex = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Firstname.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJLastname = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->telRefADetail = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->telVal.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->emlRefADetail = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->emlVal.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Salutation.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmMPerson::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmMPerson** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPerson::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWznmMPerson::loadRecBySQL(
			const string& sqlstr
			, WznmMPerson** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPerson::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmMPerson& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPerson::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmMPerson::insertRec(
			WznmMPerson* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixWDerivate = htonl(rec->ixWDerivate);
	uint _ixVSex = htonl(rec->ixVSex);
	ubigint _refJLastname = htonl64(rec->refJLastname);
	ubigint _telRefADetail = htonl64(rec->telRefADetail);
	ubigint _emlRefADetail = htonl64(rec->emlRefADetail);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixWDerivate,
		(char*) &_ixVSex,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		(char*) &_refJLastname,
		rec->Lastname.c_str(),
		(char*) &_telRefADetail,
		rec->telVal.c_str(),
		(char*) &_emlRefADetail,
		rec->emlVal.c_str(),
		rec->Salutation.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmMPerson_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmMPerson::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmMPerson::insertRst(
			ListWznmMPerson& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmMPerson::updateRec(
			WznmMPerson* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixWDerivate = htonl(rec->ixWDerivate);
	uint _ixVSex = htonl(rec->ixVSex);
	ubigint _refJLastname = htonl64(rec->refJLastname);
	ubigint _telRefADetail = htonl64(rec->telRefADetail);
	ubigint _emlRefADetail = htonl64(rec->emlRefADetail);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixWDerivate,
		(char*) &_ixVSex,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		(char*) &_refJLastname,
		rec->Lastname.c_str(),
		(char*) &_telRefADetail,
		rec->telVal.c_str(),
		(char*) &_emlRefADetail,
		rec->emlVal.c_str(),
		rec->Salutation.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmMPerson_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMPerson::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmMPerson::updateRst(
			ListWznmMPerson& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmMPerson::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmMPerson_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmMPerson::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmMPerson::loadRecByRef(
			ubigint ref
			, WznmMPerson** rec
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

	return loadRecByStmt("TblWznmMPerson_loadRecByRef", 1, vals, l, f, rec);
};

#endif
