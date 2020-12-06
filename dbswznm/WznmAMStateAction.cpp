/**
	* \file WznmAMStateAction.cpp
	* database access for table TblWznmAMStateAction (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WznmAMStateAction.h"

#include "WznmAMStateAction_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WznmAMStateAction
 ******************************************************************************/

WznmAMStateAction::WznmAMStateAction(
			const ubigint ref
			, const ubigint steRefWznmMState
			, const uint steNum
			, const uint ixVSection
			, const uint ixVType
			, const ubigint refWznmMRtjob
			, const ubigint refWznmMVector
			, const ubigint refWznmMVectoritem
			, const ubigint snxRefWznmMState
			, const ubigint refWznmMSequence
			, const string tr1SrefATrig
			, const string Ip1
			, const string tr2SrefATrig
			, const string Ip2
			, const string tr3SrefATrig
			, const string Ip3
			, const string tr4SrefATrig
			, const string Ip4
		) {

	this->ref = ref;
	this->steRefWznmMState = steRefWznmMState;
	this->steNum = steNum;
	this->ixVSection = ixVSection;
	this->ixVType = ixVType;
	this->refWznmMRtjob = refWznmMRtjob;
	this->refWznmMVector = refWznmMVector;
	this->refWznmMVectoritem = refWznmMVectoritem;
	this->snxRefWznmMState = snxRefWznmMState;
	this->refWznmMSequence = refWznmMSequence;
	this->tr1SrefATrig = tr1SrefATrig;
	this->Ip1 = Ip1;
	this->tr2SrefATrig = tr2SrefATrig;
	this->Ip2 = Ip2;
	this->tr3SrefATrig = tr3SrefATrig;
	this->Ip3 = Ip3;
	this->tr4SrefATrig = tr4SrefATrig;
	this->Ip4 = Ip4;
};

bool WznmAMStateAction::operator==(
			const WznmAMStateAction& comp
		) {
	return false;
};

bool WznmAMStateAction::operator!=(
			const WznmAMStateAction& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWznmAMStateAction
 ******************************************************************************/

ListWznmAMStateAction::ListWznmAMStateAction() {
};

ListWznmAMStateAction::ListWznmAMStateAction(
			const ListWznmAMStateAction& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmAMStateAction(*(src.nodes[i]));
};

ListWznmAMStateAction::~ListWznmAMStateAction() {
	clear();
};

void ListWznmAMStateAction::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmAMStateAction::size() const {
	return(nodes.size());
};

void ListWznmAMStateAction::append(
			WznmAMStateAction* rec
		) {
	nodes.push_back(rec);
};

WznmAMStateAction* ListWznmAMStateAction::operator[](
			const uint ix
		) {
	WznmAMStateAction* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWznmAMStateAction& ListWznmAMStateAction::operator=(
			const ListWznmAMStateAction& src
		) {
	WznmAMStateAction* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmAMStateAction(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWznmAMStateAction::operator==(
			const ListWznmAMStateAction& comp
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

bool ListWznmAMStateAction::operator!=(
			const ListWznmAMStateAction& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWznmAMStateAction
 ******************************************************************************/

TblWznmAMStateAction::TblWznmAMStateAction() {
};

TblWznmAMStateAction::~TblWznmAMStateAction() {
};

bool TblWznmAMStateAction::loadRecBySQL(
			const string& sqlstr
			, WznmAMStateAction** rec
		) {
	return false;
};

ubigint TblWznmAMStateAction::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMStateAction& rst
		) {
	return 0;
};

ubigint TblWznmAMStateAction::insertRec(
			WznmAMStateAction* rec
		) {
	return 0;
};

ubigint TblWznmAMStateAction::insertNewRec(
			WznmAMStateAction** rec
			, const ubigint steRefWznmMState
			, const uint steNum
			, const uint ixVSection
			, const uint ixVType
			, const ubigint refWznmMRtjob
			, const ubigint refWznmMVector
			, const ubigint refWznmMVectoritem
			, const ubigint snxRefWznmMState
			, const ubigint refWznmMSequence
			, const string tr1SrefATrig
			, const string Ip1
			, const string tr2SrefATrig
			, const string Ip2
			, const string tr3SrefATrig
			, const string Ip3
			, const string tr4SrefATrig
			, const string Ip4
		) {
	ubigint retval = 0;
	WznmAMStateAction* _rec = NULL;

	_rec = new WznmAMStateAction(0, steRefWznmMState, steNum, ixVSection, ixVType, refWznmMRtjob, refWznmMVector, refWznmMVectoritem, snxRefWznmMState, refWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmAMStateAction::appendNewRecToRst(
			ListWznmAMStateAction& rst
			, WznmAMStateAction** rec
			, const ubigint steRefWznmMState
			, const uint steNum
			, const uint ixVSection
			, const uint ixVType
			, const ubigint refWznmMRtjob
			, const ubigint refWznmMVector
			, const ubigint refWznmMVectoritem
			, const ubigint snxRefWznmMState
			, const ubigint refWznmMSequence
			, const string tr1SrefATrig
			, const string Ip1
			, const string tr2SrefATrig
			, const string Ip2
			, const string tr3SrefATrig
			, const string Ip3
			, const string tr4SrefATrig
			, const string Ip4
		) {
	ubigint retval = 0;
	WznmAMStateAction* _rec = NULL;

	retval = insertNewRec(&_rec, steRefWznmMState, steNum, ixVSection, ixVType, refWznmMRtjob, refWznmMVector, refWznmMVectoritem, snxRefWznmMState, refWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmAMStateAction::insertRst(
			ListWznmAMStateAction& rst
			, bool transact
		) {
};

void TblWznmAMStateAction::updateRec(
			WznmAMStateAction* rec
		) {
};

void TblWznmAMStateAction::updateRst(
			ListWznmAMStateAction& rst
			, bool transact
		) {
};

void TblWznmAMStateAction::removeRecByRef(
			ubigint ref
		) {
};

bool TblWznmAMStateAction::loadRecByRef(
			ubigint ref
			, WznmAMStateAction** rec
		) {
	return false;
};

ubigint TblWznmAMStateAction::loadRefsBySte(
			ubigint steRefWznmMState
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWznmAMStateAction::loadRstBySte(
			ubigint steRefWznmMState
			, const bool append
			, ListWznmAMStateAction& rst
		) {
	return 0;
};

ubigint TblWznmAMStateAction::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWznmAMStateAction& rst
		) {
	ubigint numload = 0;
	WznmAMStateAction* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmAMStateAction
 ******************************************************************************/

MyTblWznmAMStateAction::MyTblWznmAMStateAction() :
			TblWznmAMStateAction()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWznmAMStateAction::~MyTblWznmAMStateAction() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWznmAMStateAction::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmAMStateAction (steRefWznmMState, steNum, ixVSection, ixVType, refWznmMRtjob, refWznmMVector, refWznmMVectoritem, snxRefWznmMState, refWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmAMStateAction SET steRefWznmMState = ?, steNum = ?, ixVSection = ?, ixVType = ?, refWznmMRtjob = ?, refWznmMVector = ?, refWznmMVectoritem = ?, snxRefWznmMState = ?, refWznmMSequence = ?, tr1SrefATrig = ?, Ip1 = ?, tr2SrefATrig = ?, Ip2 = ?, tr3SrefATrig = ?, Ip3 = ?, tr4SrefATrig = ?, Ip4 = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWznmAMStateAction WHERE ref = ?", false);
};

bool MyTblWznmAMStateAction::loadRecBySQL(
			const string& sqlstr
			, WznmAMStateAction** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmAMStateAction* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMStateAction::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMStateAction::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmAMStateAction();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->steRefWznmMState = atoll((char*) dbrow[1]); else _rec->steRefWznmMState = 0;
		if (dbrow[2]) _rec->steNum = atol((char*) dbrow[2]); else _rec->steNum = 0;
		if (dbrow[3]) _rec->ixVSection = atol((char*) dbrow[3]); else _rec->ixVSection = 0;
		if (dbrow[4]) _rec->ixVType = atol((char*) dbrow[4]); else _rec->ixVType = 0;
		if (dbrow[5]) _rec->refWznmMRtjob = atoll((char*) dbrow[5]); else _rec->refWznmMRtjob = 0;
		if (dbrow[6]) _rec->refWznmMVector = atoll((char*) dbrow[6]); else _rec->refWznmMVector = 0;
		if (dbrow[7]) _rec->refWznmMVectoritem = atoll((char*) dbrow[7]); else _rec->refWznmMVectoritem = 0;
		if (dbrow[8]) _rec->snxRefWznmMState = atoll((char*) dbrow[8]); else _rec->snxRefWznmMState = 0;
		if (dbrow[9]) _rec->refWznmMSequence = atoll((char*) dbrow[9]); else _rec->refWznmMSequence = 0;
		if (dbrow[10]) _rec->tr1SrefATrig.assign(dbrow[10], dblengths[10]); else _rec->tr1SrefATrig = "";
		if (dbrow[11]) _rec->Ip1.assign(dbrow[11], dblengths[11]); else _rec->Ip1 = "";
		if (dbrow[12]) _rec->tr2SrefATrig.assign(dbrow[12], dblengths[12]); else _rec->tr2SrefATrig = "";
		if (dbrow[13]) _rec->Ip2.assign(dbrow[13], dblengths[13]); else _rec->Ip2 = "";
		if (dbrow[14]) _rec->tr3SrefATrig.assign(dbrow[14], dblengths[14]); else _rec->tr3SrefATrig = "";
		if (dbrow[15]) _rec->Ip3.assign(dbrow[15], dblengths[15]); else _rec->Ip3 = "";
		if (dbrow[16]) _rec->tr4SrefATrig.assign(dbrow[16], dblengths[16]); else _rec->tr4SrefATrig = "";
		if (dbrow[17]) _rec->Ip4.assign(dbrow[17], dblengths[17]); else _rec->Ip4 = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmAMStateAction::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMStateAction& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmAMStateAction* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmAMStateAction::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmAMStateAction::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmAMStateAction();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->steRefWznmMState = atoll((char*) dbrow[1]); else rec->steRefWznmMState = 0;
			if (dbrow[2]) rec->steNum = atol((char*) dbrow[2]); else rec->steNum = 0;
			if (dbrow[3]) rec->ixVSection = atol((char*) dbrow[3]); else rec->ixVSection = 0;
			if (dbrow[4]) rec->ixVType = atol((char*) dbrow[4]); else rec->ixVType = 0;
			if (dbrow[5]) rec->refWznmMRtjob = atoll((char*) dbrow[5]); else rec->refWznmMRtjob = 0;
			if (dbrow[6]) rec->refWznmMVector = atoll((char*) dbrow[6]); else rec->refWznmMVector = 0;
			if (dbrow[7]) rec->refWznmMVectoritem = atoll((char*) dbrow[7]); else rec->refWznmMVectoritem = 0;
			if (dbrow[8]) rec->snxRefWznmMState = atoll((char*) dbrow[8]); else rec->snxRefWznmMState = 0;
			if (dbrow[9]) rec->refWznmMSequence = atoll((char*) dbrow[9]); else rec->refWznmMSequence = 0;
			if (dbrow[10]) rec->tr1SrefATrig.assign(dbrow[10], dblengths[10]); else rec->tr1SrefATrig = "";
			if (dbrow[11]) rec->Ip1.assign(dbrow[11], dblengths[11]); else rec->Ip1 = "";
			if (dbrow[12]) rec->tr2SrefATrig.assign(dbrow[12], dblengths[12]); else rec->tr2SrefATrig = "";
			if (dbrow[13]) rec->Ip2.assign(dbrow[13], dblengths[13]); else rec->Ip2 = "";
			if (dbrow[14]) rec->tr3SrefATrig.assign(dbrow[14], dblengths[14]); else rec->tr3SrefATrig = "";
			if (dbrow[15]) rec->Ip3.assign(dbrow[15], dblengths[15]); else rec->Ip3 = "";
			if (dbrow[16]) rec->tr4SrefATrig.assign(dbrow[16], dblengths[16]); else rec->tr4SrefATrig = "";
			if (dbrow[17]) rec->Ip4.assign(dbrow[17], dblengths[17]); else rec->Ip4 = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmAMStateAction::insertRec(
			WznmAMStateAction* rec
		) {
	unsigned long l[17]; my_bool n[17]; my_bool e[17];

	l[9] = rec->tr1SrefATrig.length();
	l[10] = rec->Ip1.length();
	l[11] = rec->tr2SrefATrig.length();
	l[12] = rec->Ip2.length();
	l[13] = rec->tr3SrefATrig.length();
	l[14] = rec->Ip3.length();
	l[15] = rec->tr4SrefATrig.length();
	l[16] = rec->Ip4.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->steRefWznmMState,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->steNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVSection,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVType,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMRtjob,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVector,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->snxRefWznmMState,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMSequence,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->tr1SrefATrig.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Ip1.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->tr2SrefATrig.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Ip2.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->tr3SrefATrig.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->Ip3.c_str()),&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->tr4SrefATrig.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindCstring((char*) (rec->Ip4.c_str()),&(l[16]),&(n[16]),&(e[16]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmAMStateAction::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmAMStateAction::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWznmAMStateAction::insertRst(
			ListWznmAMStateAction& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWznmAMStateAction::updateRec(
			WznmAMStateAction* rec
		) {
	unsigned long l[18]; my_bool n[18]; my_bool e[18];

	l[9] = rec->tr1SrefATrig.length();
	l[10] = rec->Ip1.length();
	l[11] = rec->tr2SrefATrig.length();
	l[12] = rec->Ip2.length();
	l[13] = rec->tr3SrefATrig.length();
	l[14] = rec->Ip3.length();
	l[15] = rec->tr4SrefATrig.length();
	l[16] = rec->Ip4.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->steRefWznmMState,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->steNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVSection,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVType,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWznmMRtjob,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWznmMVector,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWznmMVectoritem,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->snxRefWznmMState,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWznmMSequence,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->tr1SrefATrig.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Ip1.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->tr2SrefATrig.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Ip2.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->tr3SrefATrig.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->Ip3.c_str()),&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->tr4SrefATrig.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindCstring((char*) (rec->Ip4.c_str()),&(l[16]),&(n[16]),&(e[16])),
		bindUbigint(&rec->ref,&(l[17]),&(n[17]),&(e[17]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmAMStateAction::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmAMStateAction::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmAMStateAction::updateRst(
			ListWznmAMStateAction& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmAMStateAction::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWznmAMStateAction::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWznmAMStateAction::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmAMStateAction::loadRecByRef(
			ubigint ref
			, WznmAMStateAction** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmAMStateAction WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWznmAMStateAction::loadRefsBySte(
			ubigint steRefWznmMState
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWznmAMStateAction WHERE steRefWznmMState = " + to_string(steRefWznmMState) + "", append, refs);
};

ubigint MyTblWznmAMStateAction::loadRstBySte(
			ubigint steRefWznmMState
			, const bool append
			, ListWznmAMStateAction& rst
		) {
	return loadRstBySQL("SELECT ref, steRefWznmMState, steNum, ixVSection, ixVType, refWznmMRtjob, refWznmMVector, refWznmMVectoritem, snxRefWznmMState, refWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4 FROM TblWznmAMStateAction WHERE steRefWznmMState = " + to_string(steRefWznmMState) + " ORDER BY steNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmAMStateAction
 ******************************************************************************/

PgTblWznmAMStateAction::PgTblWznmAMStateAction() :
			TblWznmAMStateAction()
			, PgTable()
		{
};

PgTblWznmAMStateAction::~PgTblWznmAMStateAction() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWznmAMStateAction::initStatements() {
	createStatement("TblWznmAMStateAction_insertRec", "INSERT INTO TblWznmAMStateAction (steRefWznmMState, steNum, ixVSection, ixVType, refWznmMRtjob, refWznmMVector, refWznmMVectoritem, snxRefWznmMState, refWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16,$17) RETURNING ref", 17);
	createStatement("TblWznmAMStateAction_updateRec", "UPDATE TblWznmAMStateAction SET steRefWznmMState = $1, steNum = $2, ixVSection = $3, ixVType = $4, refWznmMRtjob = $5, refWznmMVector = $6, refWznmMVectoritem = $7, snxRefWznmMState = $8, refWznmMSequence = $9, tr1SrefATrig = $10, Ip1 = $11, tr2SrefATrig = $12, Ip2 = $13, tr3SrefATrig = $14, Ip3 = $15, tr4SrefATrig = $16, Ip4 = $17 WHERE ref = $18", 18);
	createStatement("TblWznmAMStateAction_removeRecByRef", "DELETE FROM TblWznmAMStateAction WHERE ref = $1", 1);

	createStatement("TblWznmAMStateAction_loadRecByRef", "SELECT ref, steRefWznmMState, steNum, ixVSection, ixVType, refWznmMRtjob, refWznmMVector, refWznmMVectoritem, snxRefWznmMState, refWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4 FROM TblWznmAMStateAction WHERE ref = $1", 1);
	createStatement("TblWznmAMStateAction_loadRefsBySte", "SELECT ref FROM TblWznmAMStateAction WHERE steRefWznmMState = $1", 1);
	createStatement("TblWznmAMStateAction_loadRstBySte", "SELECT ref, steRefWznmMState, steNum, ixVSection, ixVType, refWznmMRtjob, refWznmMVector, refWznmMVectoritem, snxRefWznmMState, refWznmMSequence, tr1SrefATrig, Ip1, tr2SrefATrig, Ip2, tr3SrefATrig, Ip3, tr4SrefATrig, Ip4 FROM TblWznmAMStateAction WHERE steRefWznmMState = $1 ORDER BY steNum ASC", 1);
};

bool PgTblWznmAMStateAction::loadRec(
			PGresult* res
			, WznmAMStateAction** rec
		) {
	char* ptr;

	WznmAMStateAction* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmAMStateAction();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sterefwznmmstate"),
			PQfnumber(res, "stenum"),
			PQfnumber(res, "ixvsection"),
			PQfnumber(res, "ixvtype"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "snxrefwznmmstate"),
			PQfnumber(res, "refwznmmsequence"),
			PQfnumber(res, "tr1srefatrig"),
			PQfnumber(res, "ip1"),
			PQfnumber(res, "tr2srefatrig"),
			PQfnumber(res, "ip2"),
			PQfnumber(res, "tr3srefatrig"),
			PQfnumber(res, "ip3"),
			PQfnumber(res, "tr4srefatrig"),
			PQfnumber(res, "ip4")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->steRefWznmMState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->steNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVSection = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVType = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWznmMRtjob = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWznmMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWznmMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->snxRefWznmMState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refWznmMSequence = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->tr1SrefATrig.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Ip1.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->tr2SrefATrig.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Ip2.assign(ptr, PQgetlength(res, 0, fnum[13]));
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->tr3SrefATrig.assign(ptr, PQgetlength(res, 0, fnum[14]));
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->Ip3.assign(ptr, PQgetlength(res, 0, fnum[15]));
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->tr4SrefATrig.assign(ptr, PQgetlength(res, 0, fnum[16]));
		ptr = PQgetvalue(res, 0, fnum[17]); _rec->Ip4.assign(ptr, PQgetlength(res, 0, fnum[17]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmAMStateAction::loadRst(
			PGresult* res
			, const bool append
			, ListWznmAMStateAction& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmAMStateAction* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sterefwznmmstate"),
			PQfnumber(res, "stenum"),
			PQfnumber(res, "ixvsection"),
			PQfnumber(res, "ixvtype"),
			PQfnumber(res, "refwznmmrtjob"),
			PQfnumber(res, "refwznmmvector"),
			PQfnumber(res, "refwznmmvectoritem"),
			PQfnumber(res, "snxrefwznmmstate"),
			PQfnumber(res, "refwznmmsequence"),
			PQfnumber(res, "tr1srefatrig"),
			PQfnumber(res, "ip1"),
			PQfnumber(res, "tr2srefatrig"),
			PQfnumber(res, "ip2"),
			PQfnumber(res, "tr3srefatrig"),
			PQfnumber(res, "ip3"),
			PQfnumber(res, "tr4srefatrig"),
			PQfnumber(res, "ip4")
		};

		while (numread < numrow) {
			rec = new WznmAMStateAction();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->steRefWznmMState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->steNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVSection = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVType = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWznmMRtjob = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWznmMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWznmMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->snxRefWznmMState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refWznmMSequence = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->tr1SrefATrig.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Ip1.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->tr2SrefATrig.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Ip2.assign(ptr, PQgetlength(res, numread, fnum[13]));
			ptr = PQgetvalue(res, numread, fnum[14]); rec->tr3SrefATrig.assign(ptr, PQgetlength(res, numread, fnum[14]));
			ptr = PQgetvalue(res, numread, fnum[15]); rec->Ip3.assign(ptr, PQgetlength(res, numread, fnum[15]));
			ptr = PQgetvalue(res, numread, fnum[16]); rec->tr4SrefATrig.assign(ptr, PQgetlength(res, numread, fnum[16]));
			ptr = PQgetvalue(res, numread, fnum[17]); rec->Ip4.assign(ptr, PQgetlength(res, numread, fnum[17]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmAMStateAction::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmAMStateAction** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateAction::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMStateAction::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmAMStateAction& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateAction::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmAMStateAction::loadRecBySQL(
			const string& sqlstr
			, WznmAMStateAction** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateAction::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmAMStateAction::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmAMStateAction& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateAction::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmAMStateAction::insertRec(
			WznmAMStateAction* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _steRefWznmMState = htonl64(rec->steRefWznmMState);
	uint _steNum = htonl(rec->steNum);
	uint _ixVSection = htonl(rec->ixVSection);
	uint _ixVType = htonl(rec->ixVType);
	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _snxRefWznmMState = htonl64(rec->snxRefWznmMState);
	ubigint _refWznmMSequence = htonl64(rec->refWznmMSequence);

	const char* vals[] = {
		(char*) &_steRefWznmMState,
		(char*) &_steNum,
		(char*) &_ixVSection,
		(char*) &_ixVType,
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMVector,
		(char*) &_refWznmMVectoritem,
		(char*) &_snxRefWznmMState,
		(char*) &_refWznmMSequence,
		rec->tr1SrefATrig.c_str(),
		rec->Ip1.c_str(),
		rec->tr2SrefATrig.c_str(),
		rec->Ip2.c_str(),
		rec->tr3SrefATrig.c_str(),
		rec->Ip3.c_str(),
		rec->tr4SrefATrig.c_str(),
		rec->Ip4.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmAMStateAction_insertRec", 17, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmAMStateAction::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWznmAMStateAction::insertRst(
			ListWznmAMStateAction& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmAMStateAction::updateRec(
			WznmAMStateAction* rec
		) {
	PGresult* res;

	ubigint _steRefWznmMState = htonl64(rec->steRefWznmMState);
	uint _steNum = htonl(rec->steNum);
	uint _ixVSection = htonl(rec->ixVSection);
	uint _ixVType = htonl(rec->ixVType);
	ubigint _refWznmMRtjob = htonl64(rec->refWznmMRtjob);
	ubigint _refWznmMVector = htonl64(rec->refWznmMVector);
	ubigint _refWznmMVectoritem = htonl64(rec->refWznmMVectoritem);
	ubigint _snxRefWznmMState = htonl64(rec->snxRefWznmMState);
	ubigint _refWznmMSequence = htonl64(rec->refWznmMSequence);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_steRefWznmMState,
		(char*) &_steNum,
		(char*) &_ixVSection,
		(char*) &_ixVType,
		(char*) &_refWznmMRtjob,
		(char*) &_refWznmMVector,
		(char*) &_refWznmMVectoritem,
		(char*) &_snxRefWznmMState,
		(char*) &_refWznmMSequence,
		rec->tr1SrefATrig.c_str(),
		rec->Ip1.c_str(),
		rec->tr2SrefATrig.c_str(),
		rec->Ip2.c_str(),
		rec->tr3SrefATrig.c_str(),
		rec->Ip3.c_str(),
		rec->tr4SrefATrig.c_str(),
		rec->Ip4.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmAMStateAction_updateRec", 18, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMStateAction::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmAMStateAction::updateRst(
			ListWznmAMStateAction& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmAMStateAction::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWznmAMStateAction_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmAMStateAction::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmAMStateAction::loadRecByRef(
			ubigint ref
			, WznmAMStateAction** rec
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

	return loadRecByStmt("TblWznmAMStateAction_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWznmAMStateAction::loadRefsBySte(
			ubigint steRefWznmMState
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _steRefWznmMState = htonl64(steRefWznmMState);

	const char* vals[] = {
		(char*) &_steRefWznmMState
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWznmAMStateAction_loadRefsBySte", 1, vals, l, f, append, refs);
};

ubigint PgTblWznmAMStateAction::loadRstBySte(
			ubigint steRefWznmMState
			, const bool append
			, ListWznmAMStateAction& rst
		) {
	ubigint _steRefWznmMState = htonl64(steRefWznmMState);

	const char* vals[] = {
		(char*) &_steRefWznmMState
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmAMStateAction_loadRstBySte", 1, vals, l, f, append, rst);
};

#endif
