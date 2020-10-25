/**
	* \file WznmQTblTbl1NTablecol.h
	* Dbs and XML wrapper for table TblWznmQTblTbl1NTablecol (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQTBLTBL1NTABLECOL_H
#define WZNMQTBLTBL1NTABLECOL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblTbl1NTablecol: record of TblWznmQTblTbl1NTablecol
	*/
class WznmQTblTbl1NTablecol {

public:
	WznmQTblTbl1NTablecol(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint tblNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint tblNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQTblTbl1NTablecol: recordset of TblWznmQTblTbl1NTablecol
	*/
class ListWznmQTblTbl1NTablecol {

public:
	ListWznmQTblTbl1NTablecol();
	ListWznmQTblTbl1NTablecol(const ListWznmQTblTbl1NTablecol& src);
	~ListWznmQTblTbl1NTablecol();

	void clear();
	unsigned int size() const;
	void append(WznmQTblTbl1NTablecol* rec);

	ListWznmQTblTbl1NTablecol& operator=(const ListWznmQTblTbl1NTablecol& src);

public:
	std::vector<WznmQTblTbl1NTablecol*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblTbl1NTablecol: C++ wrapper for table TblWznmQTblTbl1NTablecol
	*/
class TblWznmQTblTbl1NTablecol {

public:
	TblWznmQTblTbl1NTablecol();
	virtual ~TblWznmQTblTbl1NTablecol();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblTbl1NTablecol** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblTbl1NTablecol& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblTbl1NTablecol* rec);
	Sbecore::ubigint insertNewRec(WznmQTblTbl1NTablecol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint tblNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblTbl1NTablecol& rst, WznmQTblTbl1NTablecol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint tblNum = 0);
	virtual void insertRst(ListWznmQTblTbl1NTablecol& rst);
	virtual void updateRec(WznmQTblTbl1NTablecol* rec);
	virtual void updateRst(ListWznmQTblTbl1NTablecol& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblTbl1NTablecol** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblTbl1NTablecol& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblTbl1NTablecol: C++ wrapper for table TblWznmQTblTbl1NTablecol (MySQL database)
	*/
class MyTblWznmQTblTbl1NTablecol : public TblWznmQTblTbl1NTablecol, public Sbecore::MyTable {

public:
	MyTblWznmQTblTbl1NTablecol();
	~MyTblWznmQTblTbl1NTablecol();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblTbl1NTablecol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblTbl1NTablecol& rst);

	Sbecore::ubigint insertRec(WznmQTblTbl1NTablecol* rec);
	void insertRst(ListWznmQTblTbl1NTablecol& rst);
	void updateRec(WznmQTblTbl1NTablecol* rec);
	void updateRst(ListWznmQTblTbl1NTablecol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblTbl1NTablecol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblTbl1NTablecol& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblTbl1NTablecol: C++ wrapper for table TblWznmQTblTbl1NTablecol (PgSQL database)
	*/
class PgTblWznmQTblTbl1NTablecol : public TblWznmQTblTbl1NTablecol, public Sbecore::PgTable {

public:
	PgTblWznmQTblTbl1NTablecol();
	~PgTblWznmQTblTbl1NTablecol();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblTbl1NTablecol** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblTbl1NTablecol& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblTbl1NTablecol** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblTbl1NTablecol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblTbl1NTablecol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblTbl1NTablecol& rst);

	Sbecore::ubigint insertRec(WznmQTblTbl1NTablecol* rec);
	void insertRst(ListWznmQTblTbl1NTablecol& rst);
	void updateRec(WznmQTblTbl1NTablecol* rec);
	void updateRst(ListWznmQTblTbl1NTablecol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblTbl1NTablecol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblTbl1NTablecol& rst);
};
#endif

#endif

