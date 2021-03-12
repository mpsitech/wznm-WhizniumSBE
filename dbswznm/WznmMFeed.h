/**
	* \file WznmMFeed.h
	* database access for table TblWznmMFeed (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMFEED_H
#define WZNMMFEED_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMFeedSrcTbl TblWznmMFeed::VecVSrcTbl

/**
	* WznmMFeed: record of TblWznmMFeed
	*/
class WznmMFeed {

public:
	WznmMFeed(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMControl = 0, const Sbecore::uint srcIxVTbl = 0, const Sbecore::ubigint srcUref = 0, const std::string sref = "", const std::string srefsWznmMVectoritem = "", const std::string srefsWznmMTag = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMControl;
	Sbecore::uint srcIxVTbl;
	Sbecore::ubigint srcUref;
	std::string sref;
	std::string srefsWznmMVectoritem;
	std::string srefsWznmMTag;
	std::string Comment;

public:
	bool operator==(const WznmMFeed& comp);
	bool operator!=(const WznmMFeed& comp);
};

/**
	* ListWznmMFeed: recordset of TblWznmMFeed
	*/
class ListWznmMFeed {

public:
	ListWznmMFeed();
	ListWznmMFeed(const ListWznmMFeed& src);
	~ListWznmMFeed();

	void clear();
	unsigned int size() const;
	void append(WznmMFeed* rec);

	WznmMFeed* operator[](const Sbecore::uint ix);
	ListWznmMFeed& operator=(const ListWznmMFeed& src);
	bool operator==(const ListWznmMFeed& comp);
	bool operator!=(const ListWznmMFeed& comp);

public:
	std::vector<WznmMFeed*> nodes;
};

/**
	* TblWznmMFeed: C++ wrapper for table TblWznmMFeed
	*/
class TblWznmMFeed {

public:
	/**
		* VecVSrcTbl (full: VecWznmVMFeedSrcTbl)
		*/
	class VecVSrcTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint VEC = 2;
		static const Sbecore::uint TBL = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

public:
	TblWznmMFeed();
	virtual ~TblWznmMFeed();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMFeed** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMFeed& rst);

	virtual Sbecore::ubigint insertRec(WznmMFeed* rec);
	Sbecore::ubigint insertNewRec(WznmMFeed** rec = NULL, const Sbecore::ubigint refWznmMControl = 0, const Sbecore::uint srcIxVTbl = 0, const Sbecore::ubigint srcUref = 0, const std::string sref = "", const std::string srefsWznmMVectoritem = "", const std::string srefsWznmMTag = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMFeed& rst, WznmMFeed** rec = NULL, const Sbecore::ubigint refWznmMControl = 0, const Sbecore::uint srcIxVTbl = 0, const Sbecore::ubigint srcUref = 0, const std::string sref = "", const std::string srefsWznmMVectoritem = "", const std::string srefsWznmMTag = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMFeed& rst, bool transact = false);
	virtual void updateRec(WznmMFeed* rec);
	virtual void updateRst(ListWznmMFeed& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMFeed** rec);
	virtual bool loadRecByCon(Sbecore::ubigint refWznmMControl, WznmMFeed** rec);
	virtual Sbecore::ubigint loadRefsByCon(Sbecore::ubigint refWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMFeed& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMFeed: C++ wrapper for table TblWznmMFeed (MySQL database)
	*/
class MyTblWznmMFeed : public TblWznmMFeed, public Sbecore::MyTable {

public:
	MyTblWznmMFeed();
	~MyTblWznmMFeed();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMFeed** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMFeed& rst);

	Sbecore::ubigint insertRec(WznmMFeed* rec);
	void insertRst(ListWznmMFeed& rst, bool transact = false);
	void updateRec(WznmMFeed* rec);
	void updateRst(ListWznmMFeed& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMFeed** rec);
	bool loadRecByCon(Sbecore::ubigint refWznmMControl, WznmMFeed** rec);
	Sbecore::ubigint loadRefsByCon(Sbecore::ubigint refWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMFeed: C++ wrapper for table TblWznmMFeed (PgSQL database)
	*/
class PgTblWznmMFeed : public TblWznmMFeed, public Sbecore::PgTable {

public:
	PgTblWznmMFeed();
	~PgTblWznmMFeed();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMFeed** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMFeed& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMFeed** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMFeed** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMFeed& rst);

	Sbecore::ubigint insertRec(WznmMFeed* rec);
	void insertRst(ListWznmMFeed& rst, bool transact = false);
	void updateRec(WznmMFeed* rec);
	void updateRst(ListWznmMFeed& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMFeed** rec);
	bool loadRecByCon(Sbecore::ubigint refWznmMControl, WznmMFeed** rec);
	Sbecore::ubigint loadRefsByCon(Sbecore::ubigint refWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
