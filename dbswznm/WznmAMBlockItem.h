/**
	* \file WznmAMBlockItem.h
	* database access for table TblWznmAMBlockItem (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMAMBLOCKITEM_H
#define WZNMAMBLOCKITEM_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVAMBlockItemBasetype TblWznmAMBlockItem::VecVBasetype

/**
	* WznmAMBlockItem: record of TblWznmAMBlockItem
	*/
class WznmAMBlockItem {

public:
	WznmAMBlockItem(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmCAMBlockItem = 0, const Sbecore::ubigint blkRefWznmMBlock = 0, const Sbecore::uint blkNum = 0, const Sbecore::uint ixVBasetype = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMControl = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::ubigint refWznmMFeed = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMBlock = 0, const Sbecore::ubigint refJ = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmCAMBlockItem;
	Sbecore::ubigint blkRefWznmMBlock;
	Sbecore::uint blkNum;
	Sbecore::uint ixVBasetype;
	std::string sref;
	Sbecore::uint ixWznmVVartype;
	Sbecore::ubigint refWznmMControl;
	Sbecore::ubigint refWznmMVector;
	Sbecore::ubigint refWznmMFeed;
	Sbecore::ubigint refWznmMTable;
	Sbecore::ubigint refWznmMBlock;
	Sbecore::ubigint refJ;
	std::string Defval;
	Sbecore::ubigint refWznmMVectoritem;
	std::string Comment;

public:
	bool operator==(const WznmAMBlockItem& comp);
	bool operator!=(const WznmAMBlockItem& comp);
};

/**
	* ListWznmAMBlockItem: recordset of TblWznmAMBlockItem
	*/
class ListWznmAMBlockItem {

public:
	ListWznmAMBlockItem();
	ListWznmAMBlockItem(const ListWznmAMBlockItem& src);
	~ListWznmAMBlockItem();

	void clear();
	unsigned int size() const;
	void append(WznmAMBlockItem* rec);

	WznmAMBlockItem* operator[](const Sbecore::uint ix);
	ListWznmAMBlockItem& operator=(const ListWznmAMBlockItem& src);
	bool operator==(const ListWznmAMBlockItem& comp);
	bool operator!=(const ListWznmAMBlockItem& comp);

public:
	std::vector<WznmAMBlockItem*> nodes;
};

/**
	* TblWznmAMBlockItem: C++ wrapper for table TblWznmAMBlockItem
	*/
class TblWznmAMBlockItem {

public:
	/**
		* VecVBasetype (full: VecWznmVAMBlockItemBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint VAR = 1;
		static const Sbecore::uint CONPAR = 2;
		static const Sbecore::uint CONTIT = 3;
		static const Sbecore::uint FEED = 4;
		static const Sbecore::uint RST = 5;
		static const Sbecore::uint SUB = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmAMBlockItem();
	virtual ~TblWznmAMBlockItem();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMBlockItem** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMBlockItem& rst);

	virtual Sbecore::ubigint insertRec(WznmAMBlockItem* rec);
	Sbecore::ubigint insertNewRec(WznmAMBlockItem** rec = NULL, const Sbecore::ubigint refWznmCAMBlockItem = 0, const Sbecore::ubigint blkRefWznmMBlock = 0, const Sbecore::uint blkNum = 0, const Sbecore::uint ixVBasetype = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMControl = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::ubigint refWznmMFeed = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMBlock = 0, const Sbecore::ubigint refJ = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMBlockItem& rst, WznmAMBlockItem** rec = NULL, const Sbecore::ubigint refWznmCAMBlockItem = 0, const Sbecore::ubigint blkRefWznmMBlock = 0, const Sbecore::uint blkNum = 0, const Sbecore::uint ixVBasetype = 0, const std::string sref = "", const Sbecore::uint ixWznmVVartype = 0, const Sbecore::ubigint refWznmMControl = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::ubigint refWznmMFeed = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMBlock = 0, const Sbecore::ubigint refJ = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string Comment = "");
	virtual void insertRst(ListWznmAMBlockItem& rst, bool transact = false);
	virtual void updateRec(WznmAMBlockItem* rec);
	virtual void updateRst(ListWznmAMBlockItem& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMBlockItem** rec);
	virtual Sbecore::ubigint loadRefsByBlk(Sbecore::ubigint blkRefWznmMBlock, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMBlockItem, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByBlk(Sbecore::ubigint blkRefWznmMBlock, const bool append, ListWznmAMBlockItem& rst);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMBlockItem, const bool append, ListWznmAMBlockItem& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMBlockItem& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMBlockItem: C++ wrapper for table TblWznmAMBlockItem (MySQL database)
	*/
class MyTblWznmAMBlockItem : public TblWznmAMBlockItem, public Sbecore::MyTable {

public:
	MyTblWznmAMBlockItem();
	~MyTblWznmAMBlockItem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMBlockItem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMBlockItem& rst);

	Sbecore::ubigint insertRec(WznmAMBlockItem* rec);
	void insertRst(ListWznmAMBlockItem& rst, bool transact = false);
	void updateRec(WznmAMBlockItem* rec);
	void updateRst(ListWznmAMBlockItem& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMBlockItem** rec);
	Sbecore::ubigint loadRefsByBlk(Sbecore::ubigint blkRefWznmMBlock, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMBlockItem, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByBlk(Sbecore::ubigint blkRefWznmMBlock, const bool append, ListWznmAMBlockItem& rst);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMBlockItem, const bool append, ListWznmAMBlockItem& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMBlockItem: C++ wrapper for table TblWznmAMBlockItem (PgSQL database)
	*/
class PgTblWznmAMBlockItem : public TblWznmAMBlockItem, public Sbecore::PgTable {

public:
	PgTblWznmAMBlockItem();
	~PgTblWznmAMBlockItem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMBlockItem** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMBlockItem& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMBlockItem** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMBlockItem& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMBlockItem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMBlockItem& rst);

	Sbecore::ubigint insertRec(WznmAMBlockItem* rec);
	void insertRst(ListWznmAMBlockItem& rst, bool transact = false);
	void updateRec(WznmAMBlockItem* rec);
	void updateRst(ListWznmAMBlockItem& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMBlockItem** rec);
	Sbecore::ubigint loadRefsByBlk(Sbecore::ubigint blkRefWznmMBlock, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCAMBlockItem, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByBlk(Sbecore::ubigint blkRefWznmMBlock, const bool append, ListWznmAMBlockItem& rst);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCAMBlockItem, const bool append, ListWznmAMBlockItem& rst);
};
#endif

#endif

