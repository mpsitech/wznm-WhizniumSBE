/**
	* \file WznmMStub.h
	* database access for table TblWznmMStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMMSTUB_H
#define WZNMMSTUB_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMStubBasetype TblWznmMStub::VecVBasetype

/**
	* WznmMStub: record of TblWznmMStub
	*/
class WznmMStub {

public:
	WznmMStub(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMSubset = 0, const std::string sref = "", const bool Hierarch = false, const Sbecore::ubigint refWznmMTablecol = 0, const bool Localized = false, const std::string Example = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmMTable;
	Sbecore::ubigint refWznmMSubset;
	std::string sref;
	bool Hierarch;
	Sbecore::ubigint refWznmMTablecol;
	bool Localized;
	std::string Example;

public:
	bool operator==(const WznmMStub& comp);
	bool operator!=(const WznmMStub& comp);
};

/**
	* ListWznmMStub: recordset of TblWznmMStub
	*/
class ListWznmMStub {

public:
	ListWznmMStub();
	ListWznmMStub(const ListWznmMStub& src);
	~ListWznmMStub();

	void clear();
	unsigned int size() const;
	void append(WznmMStub* rec);

	WznmMStub* operator[](const Sbecore::uint ix);
	ListWznmMStub& operator=(const ListWznmMStub& src);
	bool operator==(const ListWznmMStub& comp);
	bool operator!=(const ListWznmMStub& comp);

public:
	std::vector<WznmMStub*> nodes;
};

/**
	* TblWznmMStub: C++ wrapper for table TblWznmMStub
	*/
class TblWznmMStub {

public:
	/**
		* VecVBasetype (full: VecWznmVMStubBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint TCO = 1;
		static const Sbecore::uint CUST = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMStub();
	virtual ~TblWznmMStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMStub& rst);

	virtual Sbecore::ubigint insertRec(WznmMStub* rec);
	Sbecore::ubigint insertNewRec(WznmMStub** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMSubset = 0, const std::string sref = "", const bool Hierarch = false, const Sbecore::ubigint refWznmMTablecol = 0, const bool Localized = false, const std::string Example = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMStub& rst, WznmMStub** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint refWznmMSubset = 0, const std::string sref = "", const bool Hierarch = false, const Sbecore::ubigint refWznmMTablecol = 0, const bool Localized = false, const std::string Example = "");
	virtual void insertRst(ListWznmMStub& rst, bool transact = false);
	virtual void updateRec(WznmMStub* rec);
	virtual void updateRst(ListWznmMStub& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMStub** rec);
	virtual Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmMStub& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMStub: C++ wrapper for table TblWznmMStub (MySQL database)
	*/
class MyTblWznmMStub : public TblWznmMStub, public Sbecore::MyTable {

public:
	MyTblWznmMStub();
	~MyTblWznmMStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMStub& rst);

	Sbecore::ubigint insertRec(WznmMStub* rec);
	void insertRst(ListWznmMStub& rst, bool transact = false);
	void updateRec(WznmMStub* rec);
	void updateRst(ListWznmMStub& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMStub** rec);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmMStub& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMStub: C++ wrapper for table TblWznmMStub (PgSQL database)
	*/
class PgTblWznmMStub : public TblWznmMStub, public Sbecore::PgTable {

public:
	PgTblWznmMStub();
	~PgTblWznmMStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMStub** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMStub& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMStub& rst);

	Sbecore::ubigint insertRec(WznmMStub* rec);
	void insertRst(ListWznmMStub& rst, bool transact = false);
	void updateRec(WznmMStub* rec);
	void updateRst(ListWznmMStub& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMStub** rec);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmMStub& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

