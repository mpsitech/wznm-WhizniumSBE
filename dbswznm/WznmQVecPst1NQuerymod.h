/**
	* \file WznmQVecPst1NQuerymod.h
	* Dbs and XML wrapper for table TblWznmQVecPst1NQuerymod (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQVECPST1NQUERYMOD_H
#define WZNMQVECPST1NQUERYMOD_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVecPst1NQuerymod: record of TblWznmQVecPst1NQuerymod
	*/
class WznmQVecPst1NQuerymod {

public:
	WznmQVecPst1NQuerymod(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVecPst1NQuerymod: recordset of TblWznmQVecPst1NQuerymod
	*/
class ListWznmQVecPst1NQuerymod {

public:
	ListWznmQVecPst1NQuerymod();
	ListWznmQVecPst1NQuerymod(const ListWznmQVecPst1NQuerymod& src);
	~ListWznmQVecPst1NQuerymod();

	void clear();
	unsigned int size() const;
	void append(WznmQVecPst1NQuerymod* rec);

	ListWznmQVecPst1NQuerymod& operator=(const ListWznmQVecPst1NQuerymod& src);

public:
	std::vector<WznmQVecPst1NQuerymod*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVecPst1NQuerymod: C++ wrapper for table TblWznmQVecPst1NQuerymod
	*/
class TblWznmQVecPst1NQuerymod {

public:
	TblWznmQVecPst1NQuerymod();
	virtual ~TblWznmQVecPst1NQuerymod();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVecPst1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecPst1NQuerymod& rst);

	virtual Sbecore::ubigint insertRec(WznmQVecPst1NQuerymod* rec);
	Sbecore::ubigint insertNewRec(WznmQVecPst1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVecPst1NQuerymod& rst, WznmQVecPst1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVecPst1NQuerymod& rst);
	virtual void updateRec(WznmQVecPst1NQuerymod* rec);
	virtual void updateRst(ListWznmQVecPst1NQuerymod& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVecPst1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecPst1NQuerymod& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVecPst1NQuerymod: C++ wrapper for table TblWznmQVecPst1NQuerymod (MySQL database)
	*/
class MyTblWznmQVecPst1NQuerymod : public TblWznmQVecPst1NQuerymod, public Sbecore::MyTable {

public:
	MyTblWznmQVecPst1NQuerymod();
	~MyTblWznmQVecPst1NQuerymod();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecPst1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecPst1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQVecPst1NQuerymod* rec);
	void insertRst(ListWznmQVecPst1NQuerymod& rst);
	void updateRec(WznmQVecPst1NQuerymod* rec);
	void updateRst(ListWznmQVecPst1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecPst1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecPst1NQuerymod& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVecPst1NQuerymod: C++ wrapper for table TblWznmQVecPst1NQuerymod (PgSQL database)
	*/
class PgTblWznmQVecPst1NQuerymod : public TblWznmQVecPst1NQuerymod, public Sbecore::PgTable {

public:
	PgTblWznmQVecPst1NQuerymod();
	~PgTblWznmQVecPst1NQuerymod();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVecPst1NQuerymod** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVecPst1NQuerymod& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVecPst1NQuerymod** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVecPst1NQuerymod& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecPst1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecPst1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQVecPst1NQuerymod* rec);
	void insertRst(ListWznmQVecPst1NQuerymod& rst);
	void updateRec(WznmQVecPst1NQuerymod* rec);
	void updateRst(ListWznmQVecPst1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecPst1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecPst1NQuerymod& rst);
};
#endif

#endif

