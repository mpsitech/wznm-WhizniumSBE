/**
	* \file WznmQQry1NQuerymod.h
	* Dbs and XML wrapper for table TblWznmQQry1NQuerymod (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQQRY1NQUERYMOD_H
#define WZNMQQRY1NQUERYMOD_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQQry1NQuerymod: record of TblWznmQQry1NQuerymod
	*/
class WznmQQry1NQuerymod {

public:
	WznmQQry1NQuerymod(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint qryNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint qryNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQQry1NQuerymod: recordset of TblWznmQQry1NQuerymod
	*/
class ListWznmQQry1NQuerymod {

public:
	ListWznmQQry1NQuerymod();
	ListWznmQQry1NQuerymod(const ListWznmQQry1NQuerymod& src);
	~ListWznmQQry1NQuerymod();

	void clear();
	unsigned int size() const;
	void append(WznmQQry1NQuerymod* rec);

	ListWznmQQry1NQuerymod& operator=(const ListWznmQQry1NQuerymod& src);

public:
	std::vector<WznmQQry1NQuerymod*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQQry1NQuerymod: C++ wrapper for table TblWznmQQry1NQuerymod
	*/
class TblWznmQQry1NQuerymod {

public:
	TblWznmQQry1NQuerymod();
	virtual ~TblWznmQQry1NQuerymod();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQQry1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQry1NQuerymod& rst);

	virtual Sbecore::ubigint insertRec(WznmQQry1NQuerymod* rec);
	Sbecore::ubigint insertNewRec(WznmQQry1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint qryNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQQry1NQuerymod& rst, WznmQQry1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint qryNum = 0);
	virtual void insertRst(ListWznmQQry1NQuerymod& rst);
	virtual void updateRec(WznmQQry1NQuerymod* rec);
	virtual void updateRst(ListWznmQQry1NQuerymod& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQQry1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQry1NQuerymod& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQQry1NQuerymod: C++ wrapper for table TblWznmQQry1NQuerymod (MySQL database)
	*/
class MyTblWznmQQry1NQuerymod : public TblWznmQQry1NQuerymod, public Sbecore::MyTable {

public:
	MyTblWznmQQry1NQuerymod();
	~MyTblWznmQQry1NQuerymod();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQry1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQry1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQQry1NQuerymod* rec);
	void insertRst(ListWznmQQry1NQuerymod& rst);
	void updateRec(WznmQQry1NQuerymod* rec);
	void updateRst(ListWznmQQry1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQry1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQry1NQuerymod& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQQry1NQuerymod: C++ wrapper for table TblWznmQQry1NQuerymod (PgSQL database)
	*/
class PgTblWznmQQry1NQuerymod : public TblWznmQQry1NQuerymod, public Sbecore::PgTable {

public:
	PgTblWznmQQry1NQuerymod();
	~PgTblWznmQQry1NQuerymod();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQQry1NQuerymod** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQQry1NQuerymod& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQQry1NQuerymod** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQQry1NQuerymod& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQry1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQry1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQQry1NQuerymod* rec);
	void insertRst(ListWznmQQry1NQuerymod& rst);
	void updateRec(WznmQQry1NQuerymod* rec);
	void updateRst(ListWznmQQry1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQry1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQry1NQuerymod& rst);
};
#endif

#endif

