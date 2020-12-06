/**
	* \file WznmMVector.h
	* database access for table TblWznmMVector (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMVECTOR_H
#define WZNMMVECTOR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMVectorBasetype TblWznmMVector::VecVBasetype
#define VecWznmVMVectorHkTbl TblWznmMVector::VecVHkTbl
#define VecWznmWMVectorSubset TblWznmMVector::VecWSubset

/**
	* WznmMVector: record of TblWznmMVector
	*/
class WznmMVector {

public:
	WznmMVector(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const Sbecore::ubigint refWznmMPreset = 0, const std::string sref = "", const std::string osrefWznmKTaggrp = "", const std::string srefsKOption = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmMVersion;
	Sbecore::uint hkIxVTbl;
	Sbecore::ubigint hkUref;
	Sbecore::ubigint refWznmMPreset;
	std::string sref;
	std::string osrefWznmKTaggrp;
	std::string srefsKOption;

public:
	bool operator==(const WznmMVector& comp);
	bool operator!=(const WznmMVector& comp);
};

/**
	* ListWznmMVector: recordset of TblWznmMVector
	*/
class ListWznmMVector {

public:
	ListWznmMVector();
	ListWznmMVector(const ListWznmMVector& src);
	~ListWznmMVector();

	void clear();
	unsigned int size() const;
	void append(WznmMVector* rec);

	WznmMVector* operator[](const Sbecore::uint ix);
	ListWznmMVector& operator=(const ListWznmMVector& src);
	bool operator==(const ListWznmMVector& comp);
	bool operator!=(const ListWznmMVector& comp);

public:
	std::vector<WznmMVector*> nodes;
};

/**
	* TblWznmMVector: C++ wrapper for table TblWznmMVector
	*/
class TblWznmMVector {

public:
	/**
		* VecVBasetype (full: VecWznmVMVectorBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint LIN = 1;
		static const Sbecore::uint OR = 2;
		static const Sbecore::uint KLST = 3;
		static const Sbecore::uint VLST = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVHkTbl (full: VecWznmVMVectorHkTbl)
		*/
	class VecVHkTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint IEX = 2;
		static const Sbecore::uint IME = 3;
		static const Sbecore::uint JOB = 4;
		static const Sbecore::uint TBL = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWSubset (full: VecWznmWMVectorSubset)
		*/
	class VecWSubset {

	public:
		static const Sbecore::uint SBSWZNMBMVECTORKLS = 1;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);
	};

public:
	TblWznmMVector();
	virtual ~TblWznmMVector();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMVector** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMVector& rst);

	virtual Sbecore::ubigint insertRec(WznmMVector* rec);
	Sbecore::ubigint insertNewRec(WznmMVector** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const Sbecore::ubigint refWznmMPreset = 0, const std::string sref = "", const std::string osrefWznmKTaggrp = "", const std::string srefsKOption = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMVector& rst, WznmMVector** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const Sbecore::ubigint refWznmMPreset = 0, const std::string sref = "", const std::string osrefWznmKTaggrp = "", const std::string srefsKOption = "");
	virtual void insertRst(ListWznmMVector& rst, bool transact = false);
	virtual void updateRec(WznmMVector* rec);
	virtual void updateRst(ListWznmMVector& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMVector** rec);
	virtual bool loadRecByPst(Sbecore::ubigint refWznmMPreset, WznmMVector** rec);
	virtual bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMVector& rst);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMVector& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMVector& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMVector: C++ wrapper for table TblWznmMVector (MySQL database)
	*/
class MyTblWznmMVector : public TblWznmMVector, public Sbecore::MyTable {

public:
	MyTblWznmMVector();
	~MyTblWznmMVector();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMVector& rst);

	Sbecore::ubigint insertRec(WznmMVector* rec);
	void insertRst(ListWznmMVector& rst, bool transact = false);
	void updateRec(WznmMVector* rec);
	void updateRst(ListWznmMVector& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMVector** rec);
	bool loadRecByPst(Sbecore::ubigint refWznmMPreset, WznmMVector** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMVector& rst);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMVector& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMVector: C++ wrapper for table TblWznmMVector (PgSQL database)
	*/
class PgTblWznmMVector : public TblWznmMVector, public Sbecore::PgTable {

public:
	PgTblWznmMVector();
	~PgTblWznmMVector();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMVector** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMVector& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMVector** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMVector& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMVector** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMVector& rst);

	Sbecore::ubigint insertRec(WznmMVector* rec);
	void insertRst(ListWznmMVector& rst, bool transact = false);
	void updateRec(WznmMVector* rec);
	void updateRst(ListWznmMVector& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMVector** rec);
	bool loadRecByPst(Sbecore::ubigint refWznmMPreset, WznmMVector** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMVector& rst);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMVector& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
