/**
	* \file WznmQSbs1NTablecol.h
	* Dbs and XML wrapper for table TblWznmQSbs1NTablecol (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSBS1NTABLECOL_H
#define WZNMQSBS1NTABLECOL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSbs1NTablecol: record of TblWznmQSbs1NTablecol
	*/
class WznmQSbs1NTablecol {

public:
	WznmQSbs1NTablecol(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSbs1NTablecol: recordset of TblWznmQSbs1NTablecol
	*/
class ListWznmQSbs1NTablecol {

public:
	ListWznmQSbs1NTablecol();
	ListWznmQSbs1NTablecol(const ListWznmQSbs1NTablecol& src);
	~ListWznmQSbs1NTablecol();

	void clear();
	unsigned int size() const;
	void append(WznmQSbs1NTablecol* rec);

	ListWznmQSbs1NTablecol& operator=(const ListWznmQSbs1NTablecol& src);

public:
	std::vector<WznmQSbs1NTablecol*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSbs1NTablecol: C++ wrapper for table TblWznmQSbs1NTablecol
	*/
class TblWznmQSbs1NTablecol {

public:
	TblWznmQSbs1NTablecol();
	virtual ~TblWznmQSbs1NTablecol();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSbs1NTablecol** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbs1NTablecol& rst);

	virtual Sbecore::ubigint insertRec(WznmQSbs1NTablecol* rec);
	Sbecore::ubigint insertNewRec(WznmQSbs1NTablecol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSbs1NTablecol& rst, WznmQSbs1NTablecol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQSbs1NTablecol& rst);
	virtual void updateRec(WznmQSbs1NTablecol* rec);
	virtual void updateRst(ListWznmQSbs1NTablecol& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSbs1NTablecol** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbs1NTablecol& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSbs1NTablecol: C++ wrapper for table TblWznmQSbs1NTablecol (MySQL database)
	*/
class MyTblWznmQSbs1NTablecol : public TblWznmQSbs1NTablecol, public Sbecore::MyTable {

public:
	MyTblWznmQSbs1NTablecol();
	~MyTblWznmQSbs1NTablecol();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbs1NTablecol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbs1NTablecol& rst);

	Sbecore::ubigint insertRec(WznmQSbs1NTablecol* rec);
	void insertRst(ListWznmQSbs1NTablecol& rst);
	void updateRec(WznmQSbs1NTablecol* rec);
	void updateRst(ListWznmQSbs1NTablecol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbs1NTablecol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbs1NTablecol& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSbs1NTablecol: C++ wrapper for table TblWznmQSbs1NTablecol (PgSQL database)
	*/
class PgTblWznmQSbs1NTablecol : public TblWznmQSbs1NTablecol, public Sbecore::PgTable {

public:
	PgTblWznmQSbs1NTablecol();
	~PgTblWznmQSbs1NTablecol();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSbs1NTablecol** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSbs1NTablecol& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSbs1NTablecol** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSbs1NTablecol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbs1NTablecol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbs1NTablecol& rst);

	Sbecore::ubigint insertRec(WznmQSbs1NTablecol* rec);
	void insertRst(ListWznmQSbs1NTablecol& rst);
	void updateRec(WznmQSbs1NTablecol* rec);
	void updateRst(ListWznmQSbs1NTablecol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbs1NTablecol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbs1NTablecol& rst);
};
#endif

#endif

