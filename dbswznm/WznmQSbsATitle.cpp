/**
	* \file WznmQSbsATitle.cpp
	* Dbs and XML wrapper for table TblWznmQSbsATitle (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WznmQSbsATitle.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQSbsATitle
 ******************************************************************************/

WznmQSbsATitle::WznmQSbsATitle(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxVType
			, const string srefX1IxVType
			, const string titX1IxVType
			, const ubigint x2RefWznmMLocale
			, const string stubX2RefWznmMLocale
			, const uint ixWznmVGender
			, const string srefIxWznmVGender
			, const string titIxWznmVGender
			, const string Title
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1IxVType = x1IxVType;
	this->srefX1IxVType = srefX1IxVType;
	this->titX1IxVType = titX1IxVType;
	this->x2RefWznmMLocale = x2RefWznmMLocale;
	this->stubX2RefWznmMLocale = stubX2RefWznmMLocale;
	this->ixWznmVGender = ixWznmVGender;
	this->srefIxWznmVGender = srefIxWznmVGender;
	this->titIxWznmVGender = titIxWznmVGender;
	this->Title = Title;
};

void WznmQSbsATitle::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQSbsATitle";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "typ", srefX1IxVType);
		writeString(wr, "typ2", titX1IxVType);
		writeString(wr, "loc", stubX2RefWznmMLocale);
		writeString(wr, "gnd", srefIxWznmVGender);
		writeString(wr, "gnd2", titIxWznmVGender);
		writeString(wr, "tit", Title);
	} else {
		writeString(wr, "srefX1IxVType", srefX1IxVType);
		writeString(wr, "titX1IxVType", titX1IxVType);
		writeString(wr, "stubX2RefWznmMLocale", stubX2RefWznmMLocale);
		writeString(wr, "srefIxWznmVGender", srefIxWznmVGender);
		writeString(wr, "titIxWznmVGender", titIxWznmVGender);
		writeString(wr, "Title", Title);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQSbsATitle
 ******************************************************************************/

ListWznmQSbsATitle::ListWznmQSbsATitle() {
};

ListWznmQSbsATitle::ListWznmQSbsATitle(
			const ListWznmQSbsATitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQSbsATitle(*(src.nodes[i]));
};

ListWznmQSbsATitle::~ListWznmQSbsATitle() {
	clear();
};

void ListWznmQSbsATitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQSbsATitle::size() const {
	return(nodes.size());
};

void ListWznmQSbsATitle::append(
			WznmQSbsATitle* rec
		) {
	nodes.push_back(rec);
};

ListWznmQSbsATitle& ListWznmQSbsATitle::operator=(
			const ListWznmQSbsATitle& src
		) {
	WznmQSbsATitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQSbsATitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQSbsATitle::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQSbsATitle";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQSbsATitle
 ******************************************************************************/

TblWznmQSbsATitle::TblWznmQSbsATitle() {
};

TblWznmQSbsATitle::~TblWznmQSbsATitle() {
};

bool TblWznmQSbsATitle::loadRecBySQL(
			const string& sqlstr
			, WznmQSbsATitle** rec
		) {
	return false;
};

ubigint TblWznmQSbsATitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSbsATitle& rst
		) {
	return 0;
};

ubigint TblWznmQSbsATitle::insertRec(
			WznmQSbsATitle* rec
		) {
	return 0;
};

ubigint TblWznmQSbsATitle::insertNewRec(
			WznmQSbsATitle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxVType
			, const string srefX1IxVType
			, const string titX1IxVType
			, const ubigint x2RefWznmMLocale
			, const string stubX2RefWznmMLocale
			, const uint ixWznmVGender
			, const string srefIxWznmVGender
			, const string titIxWznmVGender
			, const string Title
		) {
	ubigint retval = 0;
	WznmQSbsATitle* _rec = NULL;

	_rec = new WznmQSbsATitle(0, jref, jnum, ref, x1IxVType, srefX1IxVType, titX1IxVType, x2RefWznmMLocale, stubX2RefWznmMLocale, ixWznmVGender, srefIxWznmVGender, titIxWznmVGender, Title);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQSbsATitle::appendNewRecToRst(
			ListWznmQSbsATitle& rst
			, WznmQSbsATitle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxVType
			, const string srefX1IxVType
			, const string titX1IxVType
			, const ubigint x2RefWznmMLocale
			, const string stubX2RefWznmMLocale
			, const uint ixWznmVGender
			, const string srefIxWznmVGender
			, const string titIxWznmVGender
			, const string Title
		) {
	ubigint retval = 0;
	WznmQSbsATitle* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxVType, srefX1IxVType, titX1IxVType, x2RefWznmMLocale, stubX2RefWznmMLocale, ixWznmVGender, srefIxWznmVGender, titIxWznmVGender, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQSbsATitle::insertRst(
			ListWznmQSbsATitle& rst
		) {
};

void TblWznmQSbsATitle::updateRec(
			WznmQSbsATitle* rec
		) {
};

void TblWznmQSbsATitle::updateRst(
			ListWznmQSbsATitle& rst
		) {
};

void TblWznmQSbsATitle::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQSbsATitle::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQSbsATitle::loadRecByQref(
			ubigint qref
			, WznmQSbsATitle** rec
		) {
	return false;
};

ubigint TblWznmQSbsATitle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSbsATitle& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQSbsATitle
 ******************************************************************************/

MyTblWznmQSbsATitle::MyTblWznmQSbsATitle() :
			TblWznmQSbsATitle()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQSbsATitle::~MyTblWznmQSbsATitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQSbsATitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQSbsATitle (jref, jnum, ref, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQSbsATitle SET jref = ?, jnum = ?, ref = ?, x1IxVType = ?, x2RefWznmMLocale = ?, ixWznmVGender = ?, Title = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQSbsATitle WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQSbsATitle WHERE jref = ?", false);
};

bool MyTblWznmQSbsATitle::loadRecBySQL(
			const string& sqlstr
			, WznmQSbsATitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQSbsATitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSbsATitle::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSbsATitle::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQSbsATitle();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1IxVType = atol((char*) dbrow[4]); else _rec->x1IxVType = 0;
		if (dbrow[5]) _rec->x2RefWznmMLocale = atoll((char*) dbrow[5]); else _rec->x2RefWznmMLocale = 0;
		if (dbrow[6]) _rec->ixWznmVGender = atol((char*) dbrow[6]); else _rec->ixWznmVGender = 0;
		if (dbrow[7]) _rec->Title.assign(dbrow[7], dblengths[7]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQSbsATitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSbsATitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQSbsATitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQSbsATitle::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQSbsATitle::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQSbsATitle();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1IxVType = atol((char*) dbrow[4]); else rec->x1IxVType = 0;
			if (dbrow[5]) rec->x2RefWznmMLocale = atoll((char*) dbrow[5]); else rec->x2RefWznmMLocale = 0;
			if (dbrow[6]) rec->ixWznmVGender = atol((char*) dbrow[6]); else rec->ixWznmVGender = 0;
			if (dbrow[7]) rec->Title.assign(dbrow[7], dblengths[7]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQSbsATitle::insertRec(
			WznmQSbsATitle* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[6] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxVType,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVGender,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQSbsATitle::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQSbsATitle::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQSbsATitle::insertRst(
			ListWznmQSbsATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQSbsATitle::updateRec(
			WznmQSbsATitle* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[6] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxVType,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x2RefWznmMLocale,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWznmVGender,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQSbsATitle::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQSbsATitle::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSbsATitle::updateRst(
			ListWznmQSbsATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQSbsATitle::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQSbsATitle::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQSbsATitle::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQSbsATitle::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQSbsATitle::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQSbsATitle::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQSbsATitle::loadRecByQref(
			ubigint qref
			, WznmQSbsATitle** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQSbsATitle WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQSbsATitle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSbsATitle& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQSbsATitle WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQSbsATitle
 ******************************************************************************/

PgTblWznmQSbsATitle::PgTblWznmQSbsATitle() :
			TblWznmQSbsATitle()
			, PgTable()
		{
};

PgTblWznmQSbsATitle::~PgTblWznmQSbsATitle() {
};

void PgTblWznmQSbsATitle::initStatements() {
	createStatement("TblWznmQSbsATitle_insertRec", "INSERT INTO TblWznmQSbsATitle (jref, jnum, ref, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWznmQSbsATitle_updateRec", "UPDATE TblWznmQSbsATitle SET jref = $1, jnum = $2, ref = $3, x1IxVType = $4, x2RefWznmMLocale = $5, ixWznmVGender = $6, Title = $7 WHERE qref = $8", 8);
	createStatement("TblWznmQSbsATitle_removeRecByQref", "DELETE FROM TblWznmQSbsATitle WHERE qref = $1", 1);
	createStatement("TblWznmQSbsATitle_removeRstByJref", "DELETE FROM TblWznmQSbsATitle WHERE jref = $1", 1);

	createStatement("TblWznmQSbsATitle_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title FROM TblWznmQSbsATitle WHERE qref = $1", 1);
	createStatement("TblWznmQSbsATitle_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxVType, x2RefWznmMLocale, ixWznmVGender, Title FROM TblWznmQSbsATitle WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQSbsATitle::loadRec(
			PGresult* res
			, WznmQSbsATitle** rec
		) {
	char* ptr;

	WznmQSbsATitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQSbsATitle();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "ixwznmvgender"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1IxVType = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2RefWznmMLocale = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixWznmVGender = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQSbsATitle::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQSbsATitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQSbsATitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixvtype"),
			PQfnumber(res, "x2refwznmmlocale"),
			PQfnumber(res, "ixwznmvgender"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new WznmQSbsATitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1IxVType = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2RefWznmMLocale = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWznmVGender = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQSbsATitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQSbsATitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSbsATitle::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSbsATitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQSbsATitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSbsATitle::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQSbsATitle::loadRecBySQL(
			const string& sqlstr
			, WznmQSbsATitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSbsATitle::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQSbsATitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQSbsATitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQSbsATitle::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQSbsATitle::insertRec(
			WznmQSbsATitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	uint _ixWznmVGender = htonl(rec->ixWznmVGender);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale,
		(char*) &_ixWznmVGender,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWznmQSbsATitle_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQSbsATitle::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQSbsATitle::insertRst(
			ListWznmQSbsATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQSbsATitle::updateRec(
			WznmQSbsATitle* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxVType = htonl(rec->x1IxVType);
	ubigint _x2RefWznmMLocale = htonl64(rec->x2RefWznmMLocale);
	uint _ixWznmVGender = htonl(rec->ixWznmVGender);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxVType,
		(char*) &_x2RefWznmMLocale,
		(char*) &_ixWznmVGender,
		rec->Title.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQSbsATitle_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSbsATitle::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSbsATitle::updateRst(
			ListWznmQSbsATitle& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQSbsATitle::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQSbsATitle_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSbsATitle::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQSbsATitle::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQSbsATitle_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQSbsATitle::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQSbsATitle::loadRecByQref(
			ubigint qref
			, WznmQSbsATitle** rec
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

	return loadRecByStmt("TblWznmQSbsATitle_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQSbsATitle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQSbsATitle& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQSbsATitle_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

