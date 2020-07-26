/**
	* \file WznmAMTableLoadfct.h
	* database access for table TblWznmAMTableLoadfct (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMAMTABLELOADFCT_H
#define WZNMAMTABLELOADFCT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVAMTableLoadfctLimtype TblWznmAMTableLoadfct::VecVLimtype
#define VecWznmVAMTableLoadfctLoadtype TblWznmAMTableLoadfct::VecVLoadtype

/**
	* WznmAMTableLoadfct: record of TblWznmAMTableLoadfct
	*/
class WznmAMTableLoadfct {

public:
	WznmAMTableLoadfct(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::uint ixVLoadtype = 0, const std::string Fctname = "", const std::string ldSrefWznmMTablecol = "", const std::string lbySrefsWznmMTablecol = "", const std::string ordSrefsWznmMTablecol = "", const Sbecore::uint ixVLimtype = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMTable;
	Sbecore::uint ixVLoadtype;
	std::string Fctname;
	std::string ldSrefWznmMTablecol;
	std::string lbySrefsWznmMTablecol;
	std::string ordSrefsWznmMTablecol;
	Sbecore::uint ixVLimtype;

public:
	bool operator==(const WznmAMTableLoadfct& comp);
	bool operator!=(const WznmAMTableLoadfct& comp);
};

/**
	* ListWznmAMTableLoadfct: recordset of TblWznmAMTableLoadfct
	*/
class ListWznmAMTableLoadfct {

public:
	ListWznmAMTableLoadfct();
	ListWznmAMTableLoadfct(const ListWznmAMTableLoadfct& src);
	~ListWznmAMTableLoadfct();

	void clear();
	unsigned int size() const;
	void append(WznmAMTableLoadfct* rec);

	WznmAMTableLoadfct* operator[](const Sbecore::uint ix);
	ListWznmAMTableLoadfct& operator=(const ListWznmAMTableLoadfct& src);
	bool operator==(const ListWznmAMTableLoadfct& comp);
	bool operator!=(const ListWznmAMTableLoadfct& comp);

public:
	std::vector<WznmAMTableLoadfct*> nodes;
};

/**
	* TblWznmAMTableLoadfct: C++ wrapper for table TblWznmAMTableLoadfct
	*/
class TblWznmAMTableLoadfct {

public:
	/**
		* VecVLimtype (full: VecWznmVAMTableLoadfctLimtype)
		*/
	class VecVLimtype {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint FIRST = 2;
		static const Sbecore::uint LIMOFS = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVLoadtype (full: VecWznmVAMTableLoadfctLoadtype)
		*/
	class VecVLoadtype {

	public:
		static const Sbecore::uint CONFIRM = 1;
		static const Sbecore::uint COUNT = 2;
		static const Sbecore::uint REF = 3;
		static const Sbecore::uint REFS = 4;
		static const Sbecore::uint REC = 5;
		static const Sbecore::uint RST = 6;
		static const Sbecore::uint STRING = 7;
		static const Sbecore::uint UINT = 8;
		static const Sbecore::uint HREFSUP = 9;
		static const Sbecore::uint HREFSDOWN = 10;
		static const Sbecore::uint HRSTUP = 11;
		static const Sbecore::uint HRSTDOWN = 12;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmAMTableLoadfct();
	virtual ~TblWznmAMTableLoadfct();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMTableLoadfct** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMTableLoadfct& rst);

	virtual Sbecore::ubigint insertRec(WznmAMTableLoadfct* rec);
	Sbecore::ubigint insertNewRec(WznmAMTableLoadfct** rec = NULL, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::uint ixVLoadtype = 0, const std::string Fctname = "", const std::string ldSrefWznmMTablecol = "", const std::string lbySrefsWznmMTablecol = "", const std::string ordSrefsWznmMTablecol = "", const Sbecore::uint ixVLimtype = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmAMTableLoadfct& rst, WznmAMTableLoadfct** rec = NULL, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::uint ixVLoadtype = 0, const std::string Fctname = "", const std::string ldSrefWznmMTablecol = "", const std::string lbySrefsWznmMTablecol = "", const std::string ordSrefsWznmMTablecol = "", const Sbecore::uint ixVLimtype = 0);
	virtual void insertRst(ListWznmAMTableLoadfct& rst, bool transact = false);
	virtual void updateRec(WznmAMTableLoadfct* rec);
	virtual void updateRst(ListWznmAMTableLoadfct& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMTableLoadfct** rec);
	virtual Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmAMTableLoadfct& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMTableLoadfct& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMTableLoadfct: C++ wrapper for table TblWznmAMTableLoadfct (MySQL database)
	*/
class MyTblWznmAMTableLoadfct : public TblWznmAMTableLoadfct, public Sbecore::MyTable {

public:
	MyTblWznmAMTableLoadfct();
	~MyTblWznmAMTableLoadfct();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMTableLoadfct** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMTableLoadfct& rst);

	Sbecore::ubigint insertRec(WznmAMTableLoadfct* rec);
	void insertRst(ListWznmAMTableLoadfct& rst, bool transact = false);
	void updateRec(WznmAMTableLoadfct* rec);
	void updateRst(ListWznmAMTableLoadfct& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMTableLoadfct** rec);
	Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmAMTableLoadfct& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMTableLoadfct: C++ wrapper for table TblWznmAMTableLoadfct (PgSQL database)
	*/
class PgTblWznmAMTableLoadfct : public TblWznmAMTableLoadfct, public Sbecore::PgTable {

public:
	PgTblWznmAMTableLoadfct();
	~PgTblWznmAMTableLoadfct();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMTableLoadfct** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMTableLoadfct& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMTableLoadfct** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMTableLoadfct& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMTableLoadfct** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMTableLoadfct& rst);

	Sbecore::ubigint insertRec(WznmAMTableLoadfct* rec);
	void insertRst(ListWznmAMTableLoadfct& rst, bool transact = false);
	void updateRec(WznmAMTableLoadfct* rec);
	void updateRst(ListWznmAMTableLoadfct& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMTableLoadfct** rec);
	Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmAMTableLoadfct& rst);
};
#endif

#endif

