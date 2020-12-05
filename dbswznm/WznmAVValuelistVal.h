/**
	* \file WznmAVValuelistVal.h
	* database access for table TblWznmAVValuelistVal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAVVALUELISTVAL_H
#define WZNMAVVALUELISTVAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAVValuelistVal: record of TblWznmAVValuelistVal
	*/
class WznmAVValuelistVal {

public:
	WznmAVValuelistVal(const Sbecore::ubigint ref = 0, const Sbecore::uint vlsIxWznmVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxWznmVLocale = 0, const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint vlsIxWznmVValuelist;
	Sbecore::uint vlsNum;
	Sbecore::uint x1IxWznmVLocale;
	std::string Val;

public:
	bool operator==(const WznmAVValuelistVal& comp);
	bool operator!=(const WznmAVValuelistVal& comp);
};

/**
	* ListWznmAVValuelistVal: recordset of TblWznmAVValuelistVal
	*/
class ListWznmAVValuelistVal {

public:
	ListWznmAVValuelistVal();
	ListWznmAVValuelistVal(const ListWznmAVValuelistVal& src);
	~ListWznmAVValuelistVal();

	void clear();
	unsigned int size() const;
	void append(WznmAVValuelistVal* rec);

	WznmAVValuelistVal* operator[](const Sbecore::uint ix);
	ListWznmAVValuelistVal& operator=(const ListWznmAVValuelistVal& src);
	bool operator==(const ListWznmAVValuelistVal& comp);
	bool operator!=(const ListWznmAVValuelistVal& comp);

public:
	std::vector<WznmAVValuelistVal*> nodes;
};

/**
	* TblWznmAVValuelistVal: C++ wrapper for table TblWznmAVValuelistVal
	*/
class TblWznmAVValuelistVal {

public:

public:
	TblWznmAVValuelistVal();
	virtual ~TblWznmAVValuelistVal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAVValuelistVal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAVValuelistVal& rst);

	virtual Sbecore::ubigint insertRec(WznmAVValuelistVal* rec);
	Sbecore::ubigint insertNewRec(WznmAVValuelistVal** rec = NULL, const Sbecore::uint vlsIxWznmVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxWznmVLocale = 0, const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAVValuelistVal& rst, WznmAVValuelistVal** rec = NULL, const Sbecore::uint vlsIxWznmVValuelist = 0, const Sbecore::uint vlsNum = 0, const Sbecore::uint x1IxWznmVLocale = 0, const std::string Val = "");
	virtual void insertRst(ListWznmAVValuelistVal& rst, bool transact = false);
	virtual void updateRec(WznmAVValuelistVal* rec);
	virtual void updateRst(ListWznmAVValuelistVal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAVValuelistVal** rec);
	virtual Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxWznmVValuelist, Sbecore::uint x1IxWznmVLocale, const bool append, ListWznmAVValuelistVal& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAVValuelistVal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAVValuelistVal: C++ wrapper for table TblWznmAVValuelistVal (MySQL database)
	*/
class MyTblWznmAVValuelistVal : public TblWznmAVValuelistVal, public Sbecore::MyTable {

public:
	MyTblWznmAVValuelistVal();
	~MyTblWznmAVValuelistVal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAVValuelistVal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAVValuelistVal& rst);

	Sbecore::ubigint insertRec(WznmAVValuelistVal* rec);
	void insertRst(ListWznmAVValuelistVal& rst, bool transact = false);
	void updateRec(WznmAVValuelistVal* rec);
	void updateRst(ListWznmAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAVValuelistVal** rec);
	Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxWznmVValuelist, Sbecore::uint x1IxWznmVLocale, const bool append, ListWznmAVValuelistVal& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAVValuelistVal: C++ wrapper for table TblWznmAVValuelistVal (PgSQL database)
	*/
class PgTblWznmAVValuelistVal : public TblWznmAVValuelistVal, public Sbecore::PgTable {

public:
	PgTblWznmAVValuelistVal();
	~PgTblWznmAVValuelistVal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAVValuelistVal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAVValuelistVal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAVValuelistVal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAVValuelistVal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAVValuelistVal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAVValuelistVal& rst);

	Sbecore::ubigint insertRec(WznmAVValuelistVal* rec);
	void insertRst(ListWznmAVValuelistVal& rst, bool transact = false);
	void updateRec(WznmAVValuelistVal* rec);
	void updateRst(ListWznmAVValuelistVal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAVValuelistVal** rec);
	Sbecore::ubigint loadRstByVlsLcl(Sbecore::uint vlsIxWznmVValuelist, Sbecore::uint x1IxWznmVLocale, const bool append, ListWznmAVValuelistVal& rst);
};
#endif

#endif

