/**
	* \file WznmMBlock.h
	* database access for table TblWznmMBlock (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMBLOCK_H
#define WZNMMBLOCK_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMBlockBasetype TblWznmMBlock::VecVBasetype
#define VecWznmVMBlockRefTbl TblWznmMBlock::VecVRefTbl

/**
	* WznmMBlock: record of TblWznmMBlock
	*/
class WznmMBlock {

public:
	WznmMBlock(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint reaIxWznmWScope = 0, const Sbecore::uint wriIxWznmWScope = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmMVersion;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::uint reaIxWznmWScope;
	Sbecore::uint wriIxWznmWScope;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WznmMBlock& comp);
	bool operator!=(const WznmMBlock& comp);
};

/**
	* ListWznmMBlock: recordset of TblWznmMBlock
	*/
class ListWznmMBlock {

public:
	ListWznmMBlock();
	ListWznmMBlock(const ListWznmMBlock& src);
	~ListWznmMBlock();

	void clear();
	unsigned int size() const;
	void append(WznmMBlock* rec);

	WznmMBlock* operator[](const Sbecore::uint ix);
	ListWznmMBlock& operator=(const ListWznmMBlock& src);
	bool operator==(const ListWznmMBlock& comp);
	bool operator!=(const ListWznmMBlock& comp);

public:
	std::vector<WznmMBlock*> nodes;
};

/**
	* TblWznmMBlock: C++ wrapper for table TblWznmMBlock
	*/
class TblWznmMBlock {

public:
	/**
		* VecVBasetype (full: VecWznmVMBlockBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint CONT = 1;
		static const Sbecore::uint DPCH = 2;
		static const Sbecore::uint STAT = 3;
		static const Sbecore::uint STG = 4;
		static const Sbecore::uint TAG = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVRefTbl (full: VecWznmVMBlockRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint JOB = 2;
		static const Sbecore::uint OPX = 3;
		static const Sbecore::uint OPK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMBlock();
	virtual ~TblWznmMBlock();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMBlock** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMBlock& rst);

	virtual Sbecore::ubigint insertRec(WznmMBlock* rec);
	Sbecore::ubigint insertNewRec(WznmMBlock** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint reaIxWznmWScope = 0, const Sbecore::uint wriIxWznmWScope = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMBlock& rst, WznmMBlock** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint reaIxWznmWScope = 0, const Sbecore::uint wriIxWznmWScope = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMBlock& rst, bool transact = false);
	virtual void updateRec(WznmMBlock* rec);
	virtual void updateRst(ListWznmMBlock& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMBlock** rec);
	virtual Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWznmMBlock& rst);
	virtual Sbecore::ubigint loadRstByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMBlock& rst);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMBlock& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMBlock& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMBlock: C++ wrapper for table TblWznmMBlock (MySQL database)
	*/
class MyTblWznmMBlock : public TblWznmMBlock, public Sbecore::MyTable {

public:
	MyTblWznmMBlock();
	~MyTblWznmMBlock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMBlock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMBlock& rst);

	Sbecore::ubigint insertRec(WznmMBlock* rec);
	void insertRst(ListWznmMBlock& rst, bool transact = false);
	void updateRec(WznmMBlock* rec);
	void updateRst(ListWznmMBlock& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMBlock** rec);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWznmMBlock& rst);
	Sbecore::ubigint loadRstByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMBlock& rst);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMBlock& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMBlock: C++ wrapper for table TblWznmMBlock (PgSQL database)
	*/
class PgTblWznmMBlock : public TblWznmMBlock, public Sbecore::PgTable {

public:
	PgTblWznmMBlock();
	~PgTblWznmMBlock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMBlock** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMBlock& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMBlock** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMBlock& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMBlock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMBlock& rst);

	Sbecore::ubigint insertRec(WznmMBlock* rec);
	void insertRst(ListWznmMBlock& rst, bool transact = false);
	void updateRec(WznmMBlock* rec);
	void updateRst(ListWznmMBlock& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMBlock** rec);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWznmMBlock& rst);
	Sbecore::ubigint loadRstByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMBlock& rst);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMBlock& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

