/**
	* \file WznmMCheck.h
	* database access for table TblWznmMCheck (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMCHECK_H
#define WZNMMCHECK_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMCheckBasetype TblWznmMCheck::VecVBasetype

/**
	* WznmMCheck: record of TblWznmMCheck
	*/
class WznmMCheck {

public:
	WznmMCheck(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMTablecol = 0, const Sbecore::ubigint refWznmMCall = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmMTable;
	Sbecore::ubigint refWznmMTablecol;
	Sbecore::ubigint refWznmMCall;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WznmMCheck& comp);
	bool operator!=(const WznmMCheck& comp);
};

/**
	* ListWznmMCheck: recordset of TblWznmMCheck
	*/
class ListWznmMCheck {

public:
	ListWznmMCheck();
	ListWznmMCheck(const ListWznmMCheck& src);
	~ListWznmMCheck();

	void clear();
	unsigned int size() const;
	void append(WznmMCheck* rec);

	WznmMCheck* operator[](const Sbecore::uint ix);
	ListWznmMCheck& operator=(const ListWznmMCheck& src);
	bool operator==(const ListWznmMCheck& comp);
	bool operator!=(const ListWznmMCheck& comp);

public:
	std::vector<WznmMCheck*> nodes;
};

/**
	* TblWznmMCheck: C++ wrapper for table TblWznmMCheck
	*/
class TblWznmMCheck {

public:
	/**
		* VecVBasetype (full: VecWznmVMCheckBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint EQ = 1;
		static const Sbecore::uint INCL = 2;
		static const Sbecore::uint LEAF = 3;
		static const Sbecore::uint SBS = 4;
		static const Sbecore::uint CUST = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMCheck();
	virtual ~TblWznmMCheck();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMCheck** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMCheck& rst);

	virtual Sbecore::ubigint insertRec(WznmMCheck* rec);
	Sbecore::ubigint insertNewRec(WznmMCheck** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMTablecol = 0, const Sbecore::ubigint refWznmMCall = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMCheck& rst, WznmMCheck** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMTablecol = 0, const Sbecore::ubigint refWznmMCall = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMCheck& rst, bool transact = false);
	virtual void updateRec(WznmMCheck* rec);
	virtual void updateRst(ListWznmMCheck& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMCheck** rec);
	virtual Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmMCheck& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMCheck& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMCheck: C++ wrapper for table TblWznmMCheck (MySQL database)
	*/
class MyTblWznmMCheck : public TblWznmMCheck, public Sbecore::MyTable {

public:
	MyTblWznmMCheck();
	~MyTblWznmMCheck();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMCheck** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMCheck& rst);

	Sbecore::ubigint insertRec(WznmMCheck* rec);
	void insertRst(ListWznmMCheck& rst, bool transact = false);
	void updateRec(WznmMCheck* rec);
	void updateRst(ListWznmMCheck& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMCheck** rec);
	Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmMCheck& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMCheck: C++ wrapper for table TblWznmMCheck (PgSQL database)
	*/
class PgTblWznmMCheck : public TblWznmMCheck, public Sbecore::PgTable {

public:
	PgTblWznmMCheck();
	~PgTblWznmMCheck();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMCheck** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMCheck& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMCheck** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMCheck& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMCheck** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMCheck& rst);

	Sbecore::ubigint insertRec(WznmMCheck* rec);
	void insertRst(ListWznmMCheck& rst, bool transact = false);
	void updateRec(WznmMCheck* rec);
	void updateRst(ListWznmMCheck& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMCheck** rec);
	Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmMCheck& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
