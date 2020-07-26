/**
	* \file WznmMLocale.h
	* database access for table TblWznmMLocale (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMMLOCALE_H
#define WZNMMLOCALE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMLocale: record of TblWznmMLocale
	*/
class WznmMLocale {

public:
	WznmMLocale(const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::ubigint refJTitle;
	std::string Title;

public:
	bool operator==(const WznmMLocale& comp);
	bool operator!=(const WznmMLocale& comp);
};

/**
	* ListWznmMLocale: recordset of TblWznmMLocale
	*/
class ListWznmMLocale {

public:
	ListWznmMLocale();
	ListWznmMLocale(const ListWznmMLocale& src);
	~ListWznmMLocale();

	void clear();
	unsigned int size() const;
	void append(WznmMLocale* rec);

	WznmMLocale* operator[](const Sbecore::uint ix);
	ListWznmMLocale& operator=(const ListWznmMLocale& src);
	bool operator==(const ListWznmMLocale& comp);
	bool operator!=(const ListWznmMLocale& comp);

public:
	std::vector<WznmMLocale*> nodes;
};

/**
	* TblWznmMLocale: C++ wrapper for table TblWznmMLocale
	*/
class TblWznmMLocale {

public:

public:
	TblWznmMLocale();
	virtual ~TblWznmMLocale();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMLocale** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMLocale& rst);

	virtual Sbecore::ubigint insertRec(WznmMLocale* rec);
	Sbecore::ubigint insertNewRec(WznmMLocale** rec = NULL, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMLocale& rst, WznmMLocale** rec = NULL, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "");
	virtual void insertRst(ListWznmMLocale& rst, bool transact = false);
	virtual void updateRec(WznmMLocale* rec);
	virtual void updateRst(ListWznmMLocale& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMLocale** rec);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMLocale& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMLocale: C++ wrapper for table TblWznmMLocale (MySQL database)
	*/
class MyTblWznmMLocale : public TblWznmMLocale, public Sbecore::MyTable {

public:
	MyTblWznmMLocale();
	~MyTblWznmMLocale();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMLocale** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMLocale& rst);

	Sbecore::ubigint insertRec(WznmMLocale* rec);
	void insertRst(ListWznmMLocale& rst, bool transact = false);
	void updateRec(WznmMLocale* rec);
	void updateRst(ListWznmMLocale& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMLocale** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMLocale: C++ wrapper for table TblWznmMLocale (PgSQL database)
	*/
class PgTblWznmMLocale : public TblWznmMLocale, public Sbecore::PgTable {

public:
	PgTblWznmMLocale();
	~PgTblWznmMLocale();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMLocale** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMLocale& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMLocale** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMLocale** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMLocale& rst);

	Sbecore::ubigint insertRec(WznmMLocale* rec);
	void insertRst(ListWznmMLocale& rst, bool transact = false);
	void updateRec(WznmMLocale* rec);
	void updateRst(ListWznmMLocale& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMLocale** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

