/**
	* \file WznmMRtblock.h
	* database access for table TblWznmMRtblock (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMRTBLOCK_H
#define WZNMMRTBLOCK_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMRtblockRefTbl TblWznmMRtblock::VecVRefTbl

/**
	* WznmMRtblock: record of TblWznmMRtblock
	*/
class WznmMRtblock {

public:
	WznmMRtblock(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string sref = "", const std::string srcSrefsWznmAMBlockItem = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMRtjob;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	std::string sref;
	std::string srcSrefsWznmAMBlockItem;

public:
	bool operator==(const WznmMRtblock& comp);
	bool operator!=(const WznmMRtblock& comp);
};

/**
	* ListWznmMRtblock: recordset of TblWznmMRtblock
	*/
class ListWznmMRtblock {

public:
	ListWznmMRtblock();
	ListWznmMRtblock(const ListWznmMRtblock& src);
	~ListWznmMRtblock();

	void clear();
	unsigned int size() const;
	void append(WznmMRtblock* rec);

	WznmMRtblock* operator[](const Sbecore::uint ix);
	ListWznmMRtblock& operator=(const ListWznmMRtblock& src);
	bool operator==(const ListWznmMRtblock& comp);
	bool operator!=(const ListWznmMRtblock& comp);

public:
	std::vector<WznmMRtblock*> nodes;
};

/**
	* TblWznmMRtblock: C++ wrapper for table TblWznmMRtblock
	*/
class TblWznmMRtblock {

public:
	/**
		* VecVRefTbl (full: VecWznmVMRtblockRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint BLK = 1;
		static const Sbecore::uint FED = 2;
		static const Sbecore::uint TBL = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMRtblock();
	virtual ~TblWznmMRtblock();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMRtblock** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRtblock& rst);

	virtual Sbecore::ubigint insertRec(WznmMRtblock* rec);
	Sbecore::ubigint insertNewRec(WznmMRtblock** rec = NULL, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string sref = "", const std::string srcSrefsWznmAMBlockItem = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMRtblock& rst, WznmMRtblock** rec = NULL, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string sref = "", const std::string srcSrefsWznmAMBlockItem = "");
	virtual void insertRst(ListWznmMRtblock& rst, bool transact = false);
	virtual void updateRec(WznmMRtblock* rec);
	virtual void updateRst(ListWznmMRtblock& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMRtblock** rec);
	virtual Sbecore::ubigint loadRefsByRtj(Sbecore::ubigint refWznmMRtjob, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByRtj(Sbecore::ubigint refWznmMRtjob, const bool append, ListWznmMRtblock& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMRtblock& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMRtblock: C++ wrapper for table TblWznmMRtblock (MySQL database)
	*/
class MyTblWznmMRtblock : public TblWznmMRtblock, public Sbecore::MyTable {

public:
	MyTblWznmMRtblock();
	~MyTblWznmMRtblock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMRtblock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRtblock& rst);

	Sbecore::ubigint insertRec(WznmMRtblock* rec);
	void insertRst(ListWznmMRtblock& rst, bool transact = false);
	void updateRec(WznmMRtblock* rec);
	void updateRst(ListWznmMRtblock& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMRtblock** rec);
	Sbecore::ubigint loadRefsByRtj(Sbecore::ubigint refWznmMRtjob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRtj(Sbecore::ubigint refWznmMRtjob, const bool append, ListWznmMRtblock& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMRtblock: C++ wrapper for table TblWznmMRtblock (PgSQL database)
	*/
class PgTblWznmMRtblock : public TblWznmMRtblock, public Sbecore::PgTable {

public:
	PgTblWznmMRtblock();
	~PgTblWznmMRtblock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMRtblock** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMRtblock& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMRtblock** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMRtblock& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMRtblock** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRtblock& rst);

	Sbecore::ubigint insertRec(WznmMRtblock* rec);
	void insertRst(ListWznmMRtblock& rst, bool transact = false);
	void updateRec(WznmMRtblock* rec);
	void updateRst(ListWznmMRtblock& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMRtblock** rec);
	Sbecore::ubigint loadRefsByRtj(Sbecore::ubigint refWznmMRtjob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRtj(Sbecore::ubigint refWznmMRtjob, const bool append, ListWznmMRtblock& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

