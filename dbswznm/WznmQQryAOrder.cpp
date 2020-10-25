/**
	* \file WznmQQryAOrder.cpp
	* Dbs and XML wrapper for table TblWznmQQryAOrder (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "WznmQQryAOrder.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WznmQQryAOrder
 ******************************************************************************/

WznmQQryAOrder::WznmQQryAOrder(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Short
			, const string srefsWznmMTablecol
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Short = Short;
	this->srefsWznmMTablecol = srefsWznmMTablecol;
};

void WznmQQryAOrder::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WznmQQryAOrder";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "sho", Short);
		writeString(wr, "tco", srefsWznmMTablecol);
	} else {
		writeString(wr, "Short", Short);
		writeString(wr, "srefsWznmMTablecol", srefsWznmMTablecol);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWznmQQryAOrder
 ******************************************************************************/

ListWznmQQryAOrder::ListWznmQQryAOrder() {
};

ListWznmQQryAOrder::ListWznmQQryAOrder(
			const ListWznmQQryAOrder& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WznmQQryAOrder(*(src.nodes[i]));
};

ListWznmQQryAOrder::~ListWznmQQryAOrder() {
	clear();
};

void ListWznmQQryAOrder::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWznmQQryAOrder::size() const {
	return(nodes.size());
};

void ListWznmQQryAOrder::append(
			WznmQQryAOrder* rec
		) {
	nodes.push_back(rec);
};

ListWznmQQryAOrder& ListWznmQQryAOrder::operator=(
			const ListWznmQQryAOrder& src
		) {
	WznmQQryAOrder* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WznmQQryAOrder(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWznmQQryAOrder::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWznmQQryAOrder";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWznmQQryAOrder
 ******************************************************************************/

TblWznmQQryAOrder::TblWznmQQryAOrder() {
};

TblWznmQQryAOrder::~TblWznmQQryAOrder() {
};

bool TblWznmQQryAOrder::loadRecBySQL(
			const string& sqlstr
			, WznmQQryAOrder** rec
		) {
	return false;
};

ubigint TblWznmQQryAOrder::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryAOrder& rst
		) {
	return 0;
};

ubigint TblWznmQQryAOrder::insertRec(
			WznmQQryAOrder* rec
		) {
	return 0;
};

ubigint TblWznmQQryAOrder::insertNewRec(
			WznmQQryAOrder** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Short
			, const string srefsWznmMTablecol
		) {
	ubigint retval = 0;
	WznmQQryAOrder* _rec = NULL;

	_rec = new WznmQQryAOrder(0, jref, jnum, ref, Short, srefsWznmMTablecol);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWznmQQryAOrder::appendNewRecToRst(
			ListWznmQQryAOrder& rst
			, WznmQQryAOrder** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Short
			, const string srefsWznmMTablecol
		) {
	ubigint retval = 0;
	WznmQQryAOrder* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Short, srefsWznmMTablecol);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWznmQQryAOrder::insertRst(
			ListWznmQQryAOrder& rst
		) {
};

void TblWznmQQryAOrder::updateRec(
			WznmQQryAOrder* rec
		) {
};

void TblWznmQQryAOrder::updateRst(
			ListWznmQQryAOrder& rst
		) {
};

void TblWznmQQryAOrder::removeRecByQref(
			ubigint qref
		) {
};

void TblWznmQQryAOrder::removeRstByJref(
			ubigint jref
		) {
};

bool TblWznmQQryAOrder::loadRecByQref(
			ubigint qref
			, WznmQQryAOrder** rec
		) {
	return false;
};

ubigint TblWznmQQryAOrder::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryAOrder& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWznmQQryAOrder
 ******************************************************************************/

MyTblWznmQQryAOrder::MyTblWznmQQryAOrder() :
			TblWznmQQryAOrder()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWznmQQryAOrder::~MyTblWznmQQryAOrder() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWznmQQryAOrder::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWznmQQryAOrder (jref, jnum, ref, Short, srefsWznmMTablecol) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWznmQQryAOrder SET jref = ?, jnum = ?, ref = ?, Short = ?, srefsWznmMTablecol = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWznmQQryAOrder WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWznmQQryAOrder WHERE jref = ?", false);
};

bool MyTblWznmQQryAOrder::loadRecBySQL(
			const string& sqlstr
			, WznmQQryAOrder** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WznmQQryAOrder* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQryAOrder::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQryAOrder::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WznmQQryAOrder();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Short.assign(dbrow[4], dblengths[4]); else _rec->Short = "";
		if (dbrow[5]) _rec->srefsWznmMTablecol.assign(dbrow[5], dblengths[5]); else _rec->srefsWznmMTablecol = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWznmQQryAOrder::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryAOrder& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WznmQQryAOrder* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWznmQQryAOrder::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWznmQQryAOrder::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WznmQQryAOrder();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Short.assign(dbrow[4], dblengths[4]); else rec->Short = "";
			if (dbrow[5]) rec->srefsWznmMTablecol.assign(dbrow[5], dblengths[5]); else rec->srefsWznmMTablecol = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWznmQQryAOrder::insertRec(
			WznmQQryAOrder* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Short.length();
	l[4] = rec->srefsWznmMTablecol.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Short.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefsWznmMTablecol.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWznmQQryAOrder::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWznmQQryAOrder::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWznmQQryAOrder::insertRst(
			ListWznmQQryAOrder& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWznmQQryAOrder::updateRec(
			WznmQQryAOrder* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->Short.length();
	l[4] = rec->srefsWznmMTablecol.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Short.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefsWznmMTablecol.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWznmQQryAOrder::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWznmQQryAOrder::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQryAOrder::updateRst(
			ListWznmQQryAOrder& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWznmQQryAOrder::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWznmQQryAOrder::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWznmQQryAOrder::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWznmQQryAOrder::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWznmQQryAOrder::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWznmQQryAOrder::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWznmQQryAOrder::loadRecByQref(
			ubigint qref
			, WznmQQryAOrder** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWznmQQryAOrder WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWznmQQryAOrder::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryAOrder& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWznmQQryAOrder WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWznmQQryAOrder
 ******************************************************************************/

PgTblWznmQQryAOrder::PgTblWznmQQryAOrder() :
			TblWznmQQryAOrder()
			, PgTable()
		{
};

PgTblWznmQQryAOrder::~PgTblWznmQQryAOrder() {
};

void PgTblWznmQQryAOrder::initStatements() {
	createStatement("TblWznmQQryAOrder_insertRec", "INSERT INTO TblWznmQQryAOrder (jref, jnum, ref, Short, srefsWznmMTablecol) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5);
	createStatement("TblWznmQQryAOrder_updateRec", "UPDATE TblWznmQQryAOrder SET jref = $1, jnum = $2, ref = $3, Short = $4, srefsWznmMTablecol = $5 WHERE qref = $6", 6);
	createStatement("TblWznmQQryAOrder_removeRecByQref", "DELETE FROM TblWznmQQryAOrder WHERE qref = $1", 1);
	createStatement("TblWznmQQryAOrder_removeRstByJref", "DELETE FROM TblWznmQQryAOrder WHERE jref = $1", 1);

	createStatement("TblWznmQQryAOrder_loadRecByQref", "SELECT qref, jref, jnum, ref, Short, srefsWznmMTablecol FROM TblWznmQQryAOrder WHERE qref = $1", 1);
	createStatement("TblWznmQQryAOrder_loadRstByJref", "SELECT qref, jref, jnum, ref, Short, srefsWznmMTablecol FROM TblWznmQQryAOrder WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWznmQQryAOrder::loadRec(
			PGresult* res
			, WznmQQryAOrder** rec
		) {
	char* ptr;

	WznmQQryAOrder* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WznmQQryAOrder();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "srefswznmmtablecol")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefsWznmMTablecol.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWznmQQryAOrder::loadRst(
			PGresult* res
			, const bool append
			, ListWznmQQryAOrder& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WznmQQryAOrder* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "short"),
			PQfnumber(res, "srefswznmmtablecol")
		};

		while (numread < numrow) {
			rec = new WznmQQryAOrder();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefsWznmMTablecol.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWznmQQryAOrder::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WznmQQryAOrder** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryAOrder::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQryAOrder::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWznmQQryAOrder& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryAOrder::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWznmQQryAOrder::loadRecBySQL(
			const string& sqlstr
			, WznmQQryAOrder** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQryAOrder::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWznmQQryAOrder::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWznmQQryAOrder& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWznmQQryAOrder::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWznmQQryAOrder::insertRec(
			WznmQQryAOrder* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Short.c_str(),
		rec->srefsWznmMTablecol.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWznmQQryAOrder_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWznmQQryAOrder::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWznmQQryAOrder::insertRst(
			ListWznmQQryAOrder& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWznmQQryAOrder::updateRec(
			WznmQQryAOrder* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Short.c_str(),
		rec->srefsWznmMTablecol.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWznmQQryAOrder_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryAOrder::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQryAOrder::updateRst(
			ListWznmQQryAOrder& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWznmQQryAOrder::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWznmQQryAOrder_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryAOrder::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWznmQQryAOrder::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWznmQQryAOrder_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWznmQQryAOrder::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWznmQQryAOrder::loadRecByQref(
			ubigint qref
			, WznmQQryAOrder** rec
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

	return loadRecByStmt("TblWznmQQryAOrder_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWznmQQryAOrder::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWznmQQryAOrder& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWznmQQryAOrder_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

