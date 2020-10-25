/**
	* \file WznmJAMBlockItem.h
	* database access for table TblWznmJAMBlockItem (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMJAMBLOCKITEM_H
#define WZNMJAMBLOCKITEM_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJAMBlockItem: record of TblWznmJAMBlockItem
	*/
class WznmJAMBlockItem {

public:
	WznmJAMBlockItem(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmAMBlockItem = 0, const Sbecore::ubigint x1RefWznmMRelease = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmAMBlockItem;
	Sbecore::ubigint x1RefWznmMRelease;
	std::string Defval;
	Sbecore::ubigint refWznmMVectoritem;

public:
	bool operator==(const WznmJAMBlockItem& comp);
	bool operator!=(const WznmJAMBlockItem& comp);
};

/**
	* ListWznmJAMBlockItem: recordset of TblWznmJAMBlockItem
	*/
class ListWznmJAMBlockItem {

public:
	ListWznmJAMBlockItem();
	ListWznmJAMBlockItem(const ListWznmJAMBlockItem& src);
	~ListWznmJAMBlockItem();

	void clear();
	unsigned int size() const;
	void append(WznmJAMBlockItem* rec);

	WznmJAMBlockItem* operator[](const Sbecore::uint ix);
	ListWznmJAMBlockItem& operator=(const ListWznmJAMBlockItem& src);
	bool operator==(const ListWznmJAMBlockItem& comp);
	bool operator!=(const ListWznmJAMBlockItem& comp);

public:
	std::vector<WznmJAMBlockItem*> nodes;
};

/**
	* TblWznmJAMBlockItem: C++ wrapper for table TblWznmJAMBlockItem
	*/
class TblWznmJAMBlockItem {

public:

public:
	TblWznmJAMBlockItem();
	virtual ~TblWznmJAMBlockItem();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJAMBlockItem** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJAMBlockItem& rst);

	virtual Sbecore::ubigint insertRec(WznmJAMBlockItem* rec);
	Sbecore::ubigint insertNewRec(WznmJAMBlockItem** rec = NULL, const Sbecore::ubigint refWznmAMBlockItem = 0, const Sbecore::ubigint x1RefWznmMRelease = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmJAMBlockItem& rst, WznmJAMBlockItem** rec = NULL, const Sbecore::ubigint refWznmAMBlockItem = 0, const Sbecore::ubigint x1RefWznmMRelease = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0);
	virtual void insertRst(ListWznmJAMBlockItem& rst, bool transact = false);
	virtual void updateRec(WznmJAMBlockItem* rec);
	virtual void updateRst(ListWznmJAMBlockItem& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJAMBlockItem** rec);
	virtual bool loadDfvByBitRls(Sbecore::ubigint refWznmAMBlockItem, Sbecore::ubigint x1RefWznmMRelease, std::string& Defval);
	virtual bool loadRecByBitRls(Sbecore::ubigint refWznmAMBlockItem, Sbecore::ubigint x1RefWznmMRelease, WznmJAMBlockItem** rec);
	virtual Sbecore::ubigint loadRefsByBit(Sbecore::ubigint refWznmAMBlockItem, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByBit(Sbecore::ubigint refWznmAMBlockItem, const bool append, ListWznmJAMBlockItem& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJAMBlockItem& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJAMBlockItem: C++ wrapper for table TblWznmJAMBlockItem (MySQL database)
	*/
class MyTblWznmJAMBlockItem : public TblWznmJAMBlockItem, public Sbecore::MyTable {

public:
	MyTblWznmJAMBlockItem();
	~MyTblWznmJAMBlockItem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJAMBlockItem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJAMBlockItem& rst);

	Sbecore::ubigint insertRec(WznmJAMBlockItem* rec);
	void insertRst(ListWznmJAMBlockItem& rst, bool transact = false);
	void updateRec(WznmJAMBlockItem* rec);
	void updateRst(ListWznmJAMBlockItem& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJAMBlockItem** rec);
	bool loadDfvByBitRls(Sbecore::ubigint refWznmAMBlockItem, Sbecore::ubigint x1RefWznmMRelease, std::string& Defval);
	bool loadRecByBitRls(Sbecore::ubigint refWznmAMBlockItem, Sbecore::ubigint x1RefWznmMRelease, WznmJAMBlockItem** rec);
	Sbecore::ubigint loadRefsByBit(Sbecore::ubigint refWznmAMBlockItem, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByBit(Sbecore::ubigint refWznmAMBlockItem, const bool append, ListWznmJAMBlockItem& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJAMBlockItem: C++ wrapper for table TblWznmJAMBlockItem (PgSQL database)
	*/
class PgTblWznmJAMBlockItem : public TblWznmJAMBlockItem, public Sbecore::PgTable {

public:
	PgTblWznmJAMBlockItem();
	~PgTblWznmJAMBlockItem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJAMBlockItem** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJAMBlockItem& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJAMBlockItem** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJAMBlockItem& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJAMBlockItem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJAMBlockItem& rst);

	Sbecore::ubigint insertRec(WznmJAMBlockItem* rec);
	void insertRst(ListWznmJAMBlockItem& rst, bool transact = false);
	void updateRec(WznmJAMBlockItem* rec);
	void updateRst(ListWznmJAMBlockItem& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJAMBlockItem** rec);
	bool loadDfvByBitRls(Sbecore::ubigint refWznmAMBlockItem, Sbecore::ubigint x1RefWznmMRelease, std::string& Defval);
	bool loadRecByBitRls(Sbecore::ubigint refWznmAMBlockItem, Sbecore::ubigint x1RefWznmMRelease, WznmJAMBlockItem** rec);
	Sbecore::ubigint loadRefsByBit(Sbecore::ubigint refWznmAMBlockItem, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByBit(Sbecore::ubigint refWznmAMBlockItem, const bool append, ListWznmJAMBlockItem& rst);
};
#endif

#endif

