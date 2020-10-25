/**
	* \file WznmQVerList.cpp
	* Dbs and XML wrapper for table TblWznmQVerList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQVerList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQVerList
 ******************************************************************************/

WznmQVerList::WznmQVerList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint prjRefWznmMProject
			, const string stubPrjRefWznmMProject
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint bvrRefWznmMVersion
			, const string stubBvrRefWznmMVersion
			, const ubigint refWznmMLocale
			, const string stubRefWznmMLocale
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWDbmstype
			, const string srefsIxWDbmstype
			, const string titsIxWDbmstype
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->prjRefWznmMProject = prjRefWznmMProject;
	this->stubPrjRefWznmMProject = stubPrjRefWznmMProject;
	this->Major = Major;
	this->Minor = Minor;
	this->Sub = Sub;
	this->bvrRefWznmMVersion = bvrRefWznmMVersion;
	this->stubBvrRefWznmMVersion = stubBvrRefWznmMVersion;
	this->refWznmMLocale = refWznmMLocale;
	this->stubRefWznmMLocale = stubRefWznmMLocale;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->ixWDbmstype = ixWDbmstype;
	this->srefsIxWDbmstype = srefsIxWDbmstype;
	this->titsIxWDbmstype = titsIxWDbmstype;
};

void WznmQVerList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQVerList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "prj", stubPrjRefWznmMProject);
		writeUint(wr, "maj", Major);
		writeUint(wr, "min", Minor);
		writeUint(wr, "sub", Sub);
		writeString(wr, "bvr", stubBvrRefWznmMVersion);
		writeString(wr, "loc", stubRefWznmMLocale);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
		writeString(wr, "dty", srefsIxWDbmstype);
		writeString(wr, "dty2", titsIxWDbmstype);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "stubPrjRefWznmMProject", stubPrjRefWznmMProject);
		writeUint(wr, "Major", Major);
		writeUint(wr, "Minor", Minor);
		writeUint(wr, "Sub", Sub);
		writeString(wr, "stubBvrRefWznmMVersion", stubBvrRefWznmMVersion);
		writeString(wr, "stubRefWznmMLocale", stubRefWznmMLocale);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
		writeString(wr, "srefsIxWDbmstype", srefsIxWDbmstype);
		writeString(wr, "titsIxWDbmstype", titsIxWDbmstype);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQVerList
 ******************************************************************************/

ListWznmQVerList::ListWznmQVerList() {
};

ListWznmQVerList::ListWznmQVerList(
			const ListWznmQVerList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQVerList(*(src.nodes[i]));
};

ListWznmQVerList::~ListWznmQVerList() {
	clear();
};

void ListWznmQVerList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQVerList::size() const {
	return(nodes.size());
};

void ListWznmQVerList::append(
			WznmQVerList* rec
		) {
	nodes.push_back(rec);
};

ListWznmQVerList& ListWznmQVerList::operator=(
			const ListWznmQVerList& src
		) {
	WznmQVerList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQVerList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQVerList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQVerList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQVerList
 ******************************************************************************/

TblWznmQVerList::TblWznmQVerList() {
};

TblWznmQVerList::~TblWznmQVerList() {
};

bool TblWznmQVerList::loadRecBySQL(
			const string& sqlstr
			, WznmQVerList** rec
		) {
	return false;
};

ubigint TblWznmQVerList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVerList& rst
		) {
	return 0;
};

ubigint TblWznmQVerList::insertRec(
			WznmQVerList* rec
		) {
	return 0;
};

ubigint TblWznmQVerList::insertNewRec(
			WznmQVerList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint prjRefWznmMProject
			, const string stubPrjRefWznmMProject
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint bvrRefWznmMVersion
			, const string stubBvrRefWznmMVersion
			, const ubigint refWznmMLocale
			, const string stubRefWznmMLocale
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWDbmstype
			, const string srefsIxWDbmstype
			, const string titsIxWDbmstype
		) {
	ubigint retval = 0;
	WznmQVerList* _rec = NULL;

	_rec = new WznmQVerList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, prjRefWznmMProject, stubPrjRefWznmMProject, Major, Minor, Sub, bvrRefWznmMVersion, stubBvrRefWznmMVersion, refWznmMLocale, stubRefWznmMLocale, ixVState, srefIxVState, titIxVState, ixWDbmstype, srefsIxWDbmstype, titsIxWDbmstype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQVerList::appendNewRecToRst(
			ListWznmQVerList& rst
			, WznmQVerList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint prjRefWznmMProject
			, const string stubPrjRefWznmMProject
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint bvrRefWznmMVersion
			, const string stubBvrRefWznmMVersion
			, const ubigint refWznmMLocale
			, const string stubRefWznmMLocale
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWDbmstype
			, const string srefsIxWDbmstype
			, const string titsIxWDbmstype
		) {
	ubigint retval = 0;
	WznmQVerList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, prjRefWznmMProject, stubPrjRefWznmMProject, Major, Minor, Sub, bvrRefWznmMVersion, stubBvrRefWznmMVersion, refWznmMLocale, stubRefWznmMLocale, ixVState, srefIxVState, titIxVState, ixWDbmstype, srefsIxWDbmstype, titsIxWDbmstype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQVerList::insertRst(
			ListWznmQVerList& rst
		) {
};

void TblWznmQVerList::updateRec(
			WznmQVerList* rec
		) {
};

void TblWznmQVerList::updateRst(
			ListWznmQVerList& rst
		) {
};

void TblWznmQVerList::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQVerList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQVerList::loadRecByQref(
			ubigint qref
			, WznmQVerList** rec
		) {
	return false;
};

ubigint TblWznmQVerList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVerList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQVerList
 ******************************************************************************/

MyTblWznmQVerList::MyTblWznmQVerList() :
			TblWznmQVerList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQVerList::~MyTblWznmQVerList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQVerList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQVerList (jref, jnum, ref, grp, own, prjRefWznmMProject, Major, Minor, Sub, bvrRefWznmMVersion, refWznmMLocale, ixVState, ixWDbmstype) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQVerList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, prjRefWznmMProject = ?, Major = ?, Minor = ?, Sub = ?, bvrRefWznmMVersion = ?, refWznmMLocale = ?, ixVState = ?, ixWDbmstype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQVerList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQVerList WHERE jref = ?", false);
};

bool MyTblWznmQVerList::loadRecBySQL(
			const string& sqlstr
			, WznmQVerList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQVerList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVerList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVerList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WznmQVerList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->prjRefWznmMProject = atoll((char*) dbrow[6]); else _rec->prjRefWznmMProject = 0;
		if (dbrow[7]) _rec->Major = atoi((char*) dbrow[7]); else _rec->Major = 0;
		if (dbrow[8]) _rec->Minor = atoi((char*) dbrow[8]); else _rec->Minor = 0;
		if (dbrow[9]) _rec->Sub = atoi((char*) dbrow[9]); else _rec->Sub = 0;
		if (dbrow[10]) _rec->bvrRefWznmMVersion = atoll((char*) dbrow[10]); else _rec->bvrRefWznmMVersion = 0;
		if (dbrow[11]) _rec->refWznmMLocale = atoll((char*) dbrow[11]); else _rec->refWznmMLocale = 0;
		if (dbrow[12]) _rec->ixVState = atol((char*) dbrow[12]); else _rec->ixVState = 0;
		if (dbrow[13]) _rec->ixWDbmstype = atol((char*) dbrow[13]); else _rec->ixWDbmstype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQVerList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVerList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQVerList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQVerList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQVerList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WznmQVerList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->prjRefWznmMProject = atoll((char*) dbrow[6]); else rec->prjRefWznmMProject = 0;
			if (dbrow[7]) rec->Major = atoi((char*) dbrow[7]); else rec->Major = 0;
			if (dbrow[8]) rec->Minor = atoi((char*) dbrow[8]); else rec->Minor = 0;
			if (dbrow[9]) rec->Sub = atoi((char*) dbrow[9]); else rec->Sub = 0;
			if (dbrow[10]) rec->bvrRefWznmMVersion = atoll((char*) dbrow[10]); else rec->bvrRefWznmMVersion = 0;
			if (dbrow[11]) rec->refWznmMLocale = atoll((char*) dbrow[11]); else rec->refWznmMLocale = 0;
			if (dbrow[12]) rec->ixVState = atol((char*) dbrow[12]); else rec->ixVState = 0;
			if (dbrow[13]) rec->ixWDbmstype = atol((char*) dbrow[13]); else rec->ixWDbmstype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQVerList::insertRec(
			WznmQVerList* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->prjRefWznmMProject,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->Major,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Minor,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Sub,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->bvrRefWznmMVersion,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWznmMLocale,&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->ixVState,&(l[11]),&(n[11]),&(e[11])),
		bindUint(&rec->ixWDbmstype,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQVerList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQVerList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQVerList::insertRst(
			ListWznmQVerList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQVerList::updateRec(
			WznmQVerList* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->prjRefWznmMProject,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->Major,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Minor,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Sub,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->bvrRefWznmMVersion,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWznmMLocale,&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->ixVState,&(l[11]),&(n[11]),&(e[11])),
		bindUint(&rec->ixWDbmstype,&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->qref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQVerList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQVerList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVerList::updateRst(
			ListWznmQVerList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQVerList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQVerList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQVerList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQVerList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQVerList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQVerList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQVerList::loadRecByQref(
			ubigint qref
			, WznmQVerList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQVerList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQVerList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVerList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQVerList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQVerList
 ******************************************************************************/

PgTblWznmQVerList::PgTblWznmQVerList() :
			TblWznmQVerList()
			, PgTable()
		{
};

PgTblWznmQVerList::~PgTblWznmQVerList() {
};

void PgTblWznmQVerList::initStatements() {
	createStatement("TblWznmQVerList_insertRec", "INSERT INTO TblWznmQVerList (jref, jnum, ref, grp, own, prjRefWznmMProject, Major, Minor, Sub, bvrRefWznmMVersion, refWznmMLocale, ixVState, ixWDbmstype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING qref", 13);
	createStatement("TblWznmQVerList_updateRec", "UPDATE TblWznmQVerList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, prjRefWznmMProject = $6, Major = $7, Minor = $8, Sub = $9, bvrRefWznmMVersion = $10, refWznmMLocale = $11, ixVState = $12, ixWDbmstype = $13 WHERE qref = $14", 14);
	createStatement("TblWznmQVerList_removeRecByQref", "DELETE FROM TblWznmQVerList WHERE qref = $1", 1);
	createStatement("TblWznmQVerList_removeRstByJref", "DELETE FROM TblWznmQVerList WHERE jref = $1", 1);

	createStatement("TblWznmQVerList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, prjRefWznmMProject, Major, Minor, Sub, bvrRefWznmMVersion, refWznmMLocale, ixVState, ixWDbmstype FROM TblWznmQVerList WHERE qref = $1", 1);
	createStatement("TblWznmQVerList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, prjRefWznmMProject, Major, Minor, Sub, bvrRefWznmMVersion, refWznmMLocale, ixVState, ixWDbmstype FROM TblWznmQVerList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQVerList::loadRec(
			PGresult* res
			, WznmQVerList** rec
		) {
	char* ptr;

	WznmQVerList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQVerList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "prjrefwznmmproject"),
			PQfnumber(res, "major"),
			PQfnumber(res, "minor"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "bvrrefwznmmversion"),
			PQfnumber(res, "refwznmmlocale"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwdbmstype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->prjRefWznmMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Major = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Minor = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Sub = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->bvrRefWznmMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->refWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->ixWDbmstype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQVerList::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQVerList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQVerList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "prjrefwznmmproject"),
			PQfnumber(res, "major"),
			PQfnumber(res, "minor"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "bvrrefwznmmversion"),
			PQfnumber(res, "refwznmmlocale"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwdbmstype")
		};

		while (numread < numrow) {
			rec = new WznmQVerList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->prjRefWznmMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Major = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Minor = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Sub = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->bvrRefWznmMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->refWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->ixWDbmstype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQVerList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQVerList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVerList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVerList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQVerList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVerList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQVerList::loadRecBySQL(
			const string& sqlstr
			, WznmQVerList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVerList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQVerList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQVerList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQVerList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQVerList::insertRec(
			WznmQVerList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _prjRefWznmMProject = htonl64(rec->prjRefWznmMProject);
	usmallint _Major = htons(rec->Major);
	usmallint _Minor = htons(rec->Minor);
	usmallint _Sub = htons(rec->Sub);
	ubigint _bvrRefWznmMVersion = htonl64(rec->bvrRefWznmMVersion);
	ubigint _refWznmMLocale = htonl64(rec->refWznmMLocale);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWDbmstype = htonl(rec->ixWDbmstype);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_prjRefWznmMProject,
		(char*) &_Major,
		(char*) &_Minor,
		(char*) &_Sub,
		(char*) &_bvrRefWznmMVersion,
		(char*) &_refWznmMLocale,
		(char*) &_ixVState,
		(char*) &_ixWDbmstype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQVerList_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQVerList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQVerList::insertRst(
			ListWznmQVerList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQVerList::updateRec(
			WznmQVerList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _prjRefWznmMProject = htonl64(rec->prjRefWznmMProject);
	usmallint _Major = htons(rec->Major);
	usmallint _Minor = htons(rec->Minor);
	usmallint _Sub = htons(rec->Sub);
	ubigint _bvrRefWznmMVersion = htonl64(rec->bvrRefWznmMVersion);
	ubigint _refWznmMLocale = htonl64(rec->refWznmMLocale);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWDbmstype = htonl(rec->ixWDbmstype);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_prjRefWznmMProject,
		(char*) &_Major,
		(char*) &_Minor,
		(char*) &_Sub,
		(char*) &_bvrRefWznmMVersion,
		(char*) &_refWznmMLocale,
		(char*) &_ixVState,
		(char*) &_ixWDbmstype,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWznmQVerList_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVerList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVerList::updateRst(
			ListWznmQVerList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQVerList::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWznmQVerList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVerList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQVerList::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWznmQVerList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQVerList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQVerList::loadRecByQref(
			ubigint qref
			, WznmQVerList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWznmQVerList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQVerList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQVerList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQVerList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

