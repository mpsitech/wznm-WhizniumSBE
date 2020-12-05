/**
	* \file WznmMRelation.h
	* database access for table TblWznmMRelation (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMRELATION_H
#define WZNMMRELATION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMRelationBasetype TblWznmMRelation::VecVBasetype
#define VecWznmVMRelationSupSubrole TblWznmMRelation::VecVSupSubrole

/**
	* WznmMRelation: record of TblWznmMRelation
	*/
class WznmMRelation {

public:
	WznmMRelation(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmCRelation = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint supRefWznmMRelation = 0, const Sbecore::uint supIxVSubrole = 0, const Sbecore::ubigint frRefWznmMTable = 0, const Sbecore::ubigint frsRefWznmMSubset = 0, const Sbecore::ubigint toRefWznmMTable = 0, const Sbecore::ubigint tosRefWznmMSubset = 0, const Sbecore::ubigint refWznmMTable = 0, const std::string Prefix = "", const std::string srefsKOption = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmCRelation;
	Sbecore::ubigint refWznmMVersion;
	Sbecore::ubigint supRefWznmMRelation;
	Sbecore::uint supIxVSubrole;
	Sbecore::ubigint frRefWznmMTable;
	Sbecore::ubigint frsRefWznmMSubset;
	Sbecore::ubigint toRefWznmMTable;
	Sbecore::ubigint tosRefWznmMSubset;
	Sbecore::ubigint refWznmMTable;
	std::string Prefix;
	std::string srefsKOption;

public:
	bool operator==(const WznmMRelation& comp);
	bool operator!=(const WznmMRelation& comp);
};

/**
	* ListWznmMRelation: recordset of TblWznmMRelation
	*/
class ListWznmMRelation {

public:
	ListWznmMRelation();
	ListWznmMRelation(const ListWznmMRelation& src);
	~ListWznmMRelation();

	void clear();
	unsigned int size() const;
	void append(WznmMRelation* rec);

	WznmMRelation* operator[](const Sbecore::uint ix);
	ListWznmMRelation& operator=(const ListWznmMRelation& src);
	bool operator==(const ListWznmMRelation& comp);
	bool operator!=(const ListWznmMRelation& comp);

public:
	std::vector<WznmMRelation*> nodes;
};

/**
	* TblWznmMRelation: C++ wrapper for table TblWznmMRelation
	*/
class TblWznmMRelation {

public:
	/**
		* VecVBasetype (full: VecWznmVMRelationBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint GRP = 1;
		static const Sbecore::uint OWN = 2;
		static const Sbecore::uint _11 = 3;
		static const Sbecore::uint _1N = 4;
		static const Sbecore::uint _1NPREF = 5;
		static const Sbecore::uint _1NSUB1N = 6;
		static const Sbecore::uint MN = 7;
		static const Sbecore::uint MNSUBMN = 8;
		static const Sbecore::uint MNPREF = 9;
		static const Sbecore::uint DRV = 10;
		static const Sbecore::uint DRVSUB = 11;
		static const Sbecore::uint DRVUSUB = 12;
		static const Sbecore::uint INC = 13;
		static const Sbecore::uint J = 14;
		static const Sbecore::uint JPREF = 15;
		static const Sbecore::uint CLUST = 16;
		static const Sbecore::uint AUX = 17;
		static const Sbecore::uint AUXPREF = 18;
		static const Sbecore::uint H1N = 19;
		static const Sbecore::uint U1N = 20;
		static const Sbecore::uint U1NSUB = 21;
		static const Sbecore::uint U1NSUBPREF = 22;
		static const Sbecore::uint U1NSUBINC = 23;
		static const Sbecore::uint U1NSUB11 = 24;
		static const Sbecore::uint UMN = 25;
		static const Sbecore::uint UM1N = 26;
		static const Sbecore::uint A1N = 27;
		static const Sbecore::uint AU1N = 28;
		static const Sbecore::uint AU1NSUB = 29;
		static const Sbecore::uint AS1N = 30;
		static const Sbecore::uint ASMN = 31;
		static const Sbecore::uint LU1N = 32;
		static const Sbecore::uint LU1NSUB = 33;
		static const Sbecore::uint LU1NLSUB = 34;
		static const Sbecore::uint L1NOP = 35;
		static const Sbecore::uint L1NOPPR = 36;
		static const Sbecore::uint L1N = 37;
		static const Sbecore::uint LMN = 38;
		static const Sbecore::uint LMNOP = 39;
		static const Sbecore::uint LMNOPPR = 40;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVSupSubrole (full: VecWznmVMRelationSupSubrole)
		*/
	class VecVSupSubrole {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint FROM1N = 2;
		static const Sbecore::uint TO1N = 3;
		static const Sbecore::uint SUBMN = 4;
		static const Sbecore::uint PREF = 5;
		static const Sbecore::uint FROMPREF = 6;
		static const Sbecore::uint TOPREF = 7;
		static const Sbecore::uint R1N = 8;
		static const Sbecore::uint MN1N = 9;
		static const Sbecore::uint MOD = 10;
		static const Sbecore::uint SUB = 11;
		static const Sbecore::uint SUBL = 12;
		static const Sbecore::uint SUBINC = 13;
		static const Sbecore::uint SUB11 = 14;
		static const Sbecore::uint SUB1N = 15;
		static const Sbecore::uint PR1 = 16;
		static const Sbecore::uint PR2 = 17;
		static const Sbecore::uint OP = 18;
		static const Sbecore::uint TOUM1N = 19;
		static const Sbecore::uint SPEC = 20;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMRelation();
	virtual ~TblWznmMRelation();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMRelation** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRelation& rst);

	virtual Sbecore::ubigint insertRec(WznmMRelation* rec);
	Sbecore::ubigint insertNewRec(WznmMRelation** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmCRelation = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint supRefWznmMRelation = 0, const Sbecore::uint supIxVSubrole = 0, const Sbecore::ubigint frRefWznmMTable = 0, const Sbecore::ubigint frsRefWznmMSubset = 0, const Sbecore::ubigint toRefWznmMTable = 0, const Sbecore::ubigint tosRefWznmMSubset = 0, const Sbecore::ubigint refWznmMTable = 0, const std::string Prefix = "", const std::string srefsKOption = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMRelation& rst, WznmMRelation** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmCRelation = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint supRefWznmMRelation = 0, const Sbecore::uint supIxVSubrole = 0, const Sbecore::ubigint frRefWznmMTable = 0, const Sbecore::ubigint frsRefWznmMSubset = 0, const Sbecore::ubigint toRefWznmMTable = 0, const Sbecore::ubigint tosRefWznmMSubset = 0, const Sbecore::ubigint refWznmMTable = 0, const std::string Prefix = "", const std::string srefsKOption = "");
	virtual void insertRst(ListWznmMRelation& rst, bool transact = false);
	virtual void updateRec(WznmMRelation* rec);
	virtual void updateRst(ListWznmMRelation& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMRelation** rec);
	virtual bool loadRecByTbl(Sbecore::ubigint refWznmMTable, WznmMRelation** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCRelation, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCRelation, const bool append, ListWznmMRelation& rst);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMRelation& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMRelation& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMRelation: C++ wrapper for table TblWznmMRelation (MySQL database)
	*/
class MyTblWznmMRelation : public TblWznmMRelation, public Sbecore::MyTable {

public:
	MyTblWznmMRelation();
	~MyTblWznmMRelation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRelation& rst);

	Sbecore::ubigint insertRec(WznmMRelation* rec);
	void insertRst(ListWznmMRelation& rst, bool transact = false);
	void updateRec(WznmMRelation* rec);
	void updateRst(ListWznmMRelation& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMRelation** rec);
	bool loadRecByTbl(Sbecore::ubigint refWznmMTable, WznmMRelation** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCRelation, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCRelation, const bool append, ListWznmMRelation& rst);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMRelation& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMRelation: C++ wrapper for table TblWznmMRelation (PgSQL database)
	*/
class PgTblWznmMRelation : public TblWznmMRelation, public Sbecore::PgTable {

public:
	PgTblWznmMRelation();
	~PgTblWznmMRelation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMRelation** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMRelation& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMRelation** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMRelation& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMRelation** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMRelation& rst);

	Sbecore::ubigint insertRec(WznmMRelation* rec);
	void insertRst(ListWznmMRelation& rst, bool transact = false);
	void updateRec(WznmMRelation* rec);
	void updateRst(ListWznmMRelation& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMRelation** rec);
	bool loadRecByTbl(Sbecore::ubigint refWznmMTable, WznmMRelation** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCRelation, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCRelation, const bool append, ListWznmMRelation& rst);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMRelation& rst);
};
#endif

#endif

