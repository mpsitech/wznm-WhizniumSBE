/**
	* \file WznmQTblFct1NTablecol.h
	* Dbs and XML wrapper for table TblWznmQTblFct1NTablecol (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQTBLFCT1NTABLECOL_H
#define WZNMQTBLFCT1NTABLECOL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblFct1NTablecol: record of TblWznmQTblFct1NTablecol
	*/
class WznmQTblFct1NTablecol {

public:
	WznmQTblFct1NTablecol(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTblFct1NTablecol: recordset of TblWznmQTblFct1NTablecol
	*/
class ListWznmQTblFct1NTablecol {

public:
	ListWznmQTblFct1NTablecol();
	ListWznmQTblFct1NTablecol(const ListWznmQTblFct1NTablecol& src);
	~ListWznmQTblFct1NTablecol();

	void clear();
	unsigned int size() const;
	void append(WznmQTblFct1NTablecol* rec);

	ListWznmQTblFct1NTablecol& operator=(const ListWznmQTblFct1NTablecol& src);

public:
	std::vector<WznmQTblFct1NTablecol*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblFct1NTablecol: C++ wrapper for table TblWznmQTblFct1NTablecol
	*/
class TblWznmQTblFct1NTablecol {

public:
	TblWznmQTblFct1NTablecol();
	virtual ~TblWznmQTblFct1NTablecol();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblFct1NTablecol** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblFct1NTablecol& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblFct1NTablecol* rec);
	Sbecore::ubigint insertNewRec(WznmQTblFct1NTablecol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblFct1NTablecol& rst, WznmQTblFct1NTablecol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTblFct1NTablecol& rst);
	virtual void updateRec(WznmQTblFct1NTablecol* rec);
	virtual void updateRst(ListWznmQTblFct1NTablecol& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblFct1NTablecol** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblFct1NTablecol& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblFct1NTablecol: C++ wrapper for table TblWznmQTblFct1NTablecol (MySQL database)
	*/
class MyTblWznmQTblFct1NTablecol : public TblWznmQTblFct1NTablecol, public Sbecore::MyTable {

public:
	MyTblWznmQTblFct1NTablecol();
	~MyTblWznmQTblFct1NTablecol();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblFct1NTablecol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblFct1NTablecol& rst);

	Sbecore::ubigint insertRec(WznmQTblFct1NTablecol* rec);
	void insertRst(ListWznmQTblFct1NTablecol& rst);
	void updateRec(WznmQTblFct1NTablecol* rec);
	void updateRst(ListWznmQTblFct1NTablecol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblFct1NTablecol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblFct1NTablecol& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblFct1NTablecol: C++ wrapper for table TblWznmQTblFct1NTablecol (PgSQL database)
	*/
class PgTblWznmQTblFct1NTablecol : public TblWznmQTblFct1NTablecol, public Sbecore::PgTable {

public:
	PgTblWznmQTblFct1NTablecol();
	~PgTblWznmQTblFct1NTablecol();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblFct1NTablecol** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblFct1NTablecol& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblFct1NTablecol** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblFct1NTablecol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblFct1NTablecol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblFct1NTablecol& rst);

	Sbecore::ubigint insertRec(WznmQTblFct1NTablecol* rec);
	void insertRst(ListWznmQTblFct1NTablecol& rst);
	void updateRec(WznmQTblFct1NTablecol* rec);
	void updateRst(ListWznmQTblFct1NTablecol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblFct1NTablecol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblFct1NTablecol& rst);
};
#endif

#endif

