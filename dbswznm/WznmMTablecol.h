/**
	* \file WznmMTablecol.h
	* database access for table TblWznmMTablecol (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMTABLECOL_H
#define WZNMMTABLECOL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMTablecolAxisfct TblWznmMTablecol::VecVAxisfct
#define VecWznmVMTablecolBasetype TblWznmMTablecol::VecVBasetype
#define VecWznmVMTablecolFctTbl TblWznmMTablecol::VecVFctTbl
#define VecWznmVMTablecolSubtype TblWznmMTablecol::VecVSubtype
#define VecWznmWMTablecolSubset TblWznmMTablecol::VecWSubset

/**
	* WznmMTablecol: record of TblWznmMTablecol
	*/
class WznmMTablecol {

public:
	WznmMTablecol(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint tblRefWznmMTable = 0, const Sbecore::uint tblNum = 0, const Sbecore::ubigint refWznmMSubset = 0, const Sbecore::ubigint refWznmMRelation = 0, const Sbecore::uint fctIxVTbl = 0, const Sbecore::ubigint fctUref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVSubtype = 0, const Sbecore::uint ixVAxisfct = 0, const std::string srefsKOption = "", const bool Principal = false, const bool Eponymous = false);

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint tblRefWznmMTable;
	Sbecore::uint tblNum;
	Sbecore::ubigint refWznmMSubset;
	Sbecore::ubigint refWznmMRelation;
	Sbecore::uint fctIxVTbl;
	Sbecore::ubigint fctUref;
	std::string sref;
	std::string Short;
	Sbecore::uint ixVSubtype;
	Sbecore::uint ixVAxisfct;
	std::string srefsKOption;
	bool Principal;
	bool Eponymous;

public:
	bool operator==(const WznmMTablecol& comp);
	bool operator!=(const WznmMTablecol& comp);
};

/**
	* ListWznmMTablecol: recordset of TblWznmMTablecol
	*/
class ListWznmMTablecol {

public:
	ListWznmMTablecol();
	ListWznmMTablecol(const ListWznmMTablecol& src);
	~ListWznmMTablecol();

	void clear();
	unsigned int size() const;
	void append(WznmMTablecol* rec);

	WznmMTablecol* operator[](const Sbecore::uint ix);
	ListWznmMTablecol& operator=(const ListWznmMTablecol& src);
	bool operator==(const ListWznmMTablecol& comp);
	bool operator!=(const ListWznmMTablecol& comp);

public:
	std::vector<WznmMTablecol*> nodes;
};

/**
	* TblWznmMTablecol: C++ wrapper for table TblWznmMTablecol
	*/
class TblWznmMTablecol {

public:
	/**
		* VecVAxisfct (full: VecWznmVMTablecolAxisfct)
		*/
	class VecVAxisfct {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint PT = 2;
		static const Sbecore::uint SPT = 3;
		static const Sbecore::uint EPT = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVBasetype (full: VecWznmVMTablecolBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint IDREF = 1;
		static const Sbecore::uint IDSREF = 2;
		static const Sbecore::uint KLREF = 3;
		static const Sbecore::uint TBLREF = 4;
		static const Sbecore::uint TBLSREF = 5;
		static const Sbecore::uint VECREF = 6;
		static const Sbecore::uint UVSREF = 7;
		static const Sbecore::uint GRP = 8;
		static const Sbecore::uint OWN = 9;
		static const Sbecore::uint ENUM = 10;
		static const Sbecore::uint LVL = 11;
		static const Sbecore::uint INTVAL = 12;
		static const Sbecore::uint DBLVAL = 13;
		static const Sbecore::uint BOOLVAL = 14;
		static const Sbecore::uint TXTVAL = 15;
		static const Sbecore::uint TIMEVAL = 16;
		static const Sbecore::uint EXPR = 17;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVFctTbl (full: VecWznmVMTablecolFctTbl)
		*/
	class VecVFctTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint TBL = 2;
		static const Sbecore::uint VEC = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVSubtype (full: VecWznmVMTablecolSubtype)
		*/
	class VecVSubtype {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint KLREFOPT = 2;
		static const Sbecore::uint KLREFSNG = 3;
		static const Sbecore::uint KLREFMULT = 4;
		static const Sbecore::uint TREFSPEC = 5;
		static const Sbecore::uint TREFUNIV = 6;
		static const Sbecore::uint TREFMIN = 7;
		static const Sbecore::uint TREFCLU = 8;
		static const Sbecore::uint TSREFSNG = 9;
		static const Sbecore::uint TSREFMULT = 10;
		static const Sbecore::uint VREFLIN = 11;
		static const Sbecore::uint VREFAND = 12;
		static const Sbecore::uint ENAUTO = 13;
		static const Sbecore::uint ENSPEC = 14;
		static const Sbecore::uint TINYINT = 15;
		static const Sbecore::uint UTINYINT = 16;
		static const Sbecore::uint SMALLINT = 17;
		static const Sbecore::uint USMALLINT = 18;
		static const Sbecore::uint INT = 19;
		static const Sbecore::uint UINT = 20;
		static const Sbecore::uint BIGINT = 21;
		static const Sbecore::uint UBIGINT = 22;
		static const Sbecore::uint TXT5 = 23;
		static const Sbecore::uint TXT10 = 24;
		static const Sbecore::uint TXT30 = 25;
		static const Sbecore::uint TXT50 = 26;
		static const Sbecore::uint TXT100 = 27;
		static const Sbecore::uint TXT192 = 28;
		static const Sbecore::uint TXTLONG = 29;
		static const Sbecore::uint TXTBASE64 = 30;
		static const Sbecore::uint TMDATE = 31;
		static const Sbecore::uint TMTIME = 32;
		static const Sbecore::uint TMSTAMP = 33;
		static const Sbecore::uint TMUSTAMP = 34;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecWSubset (full: VecWznmWMTablecolSubset)
		*/
	class VecWSubset {

	public:
		static const Sbecore::uint SBSWZNMBMTABLECOLSTC = 1;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);
	};

public:
	TblWznmMTablecol();
	virtual ~TblWznmMTablecol();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMTablecol** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMTablecol& rst);

	virtual Sbecore::ubigint insertRec(WznmMTablecol* rec);
	Sbecore::ubigint insertNewRec(WznmMTablecol** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint tblRefWznmMTable = 0, const Sbecore::uint tblNum = 0, const Sbecore::ubigint refWznmMSubset = 0, const Sbecore::ubigint refWznmMRelation = 0, const Sbecore::uint fctIxVTbl = 0, const Sbecore::ubigint fctUref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVSubtype = 0, const Sbecore::uint ixVAxisfct = 0, const std::string srefsKOption = "", const bool Principal = false, const bool Eponymous = false);
	Sbecore::ubigint appendNewRecToRst(ListWznmMTablecol& rst, WznmMTablecol** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint tblRefWznmMTable = 0, const Sbecore::uint tblNum = 0, const Sbecore::ubigint refWznmMSubset = 0, const Sbecore::ubigint refWznmMRelation = 0, const Sbecore::uint fctIxVTbl = 0, const Sbecore::ubigint fctUref = 0, const std::string sref = "", const std::string Short = "", const Sbecore::uint ixVSubtype = 0, const Sbecore::uint ixVAxisfct = 0, const std::string srefsKOption = "", const bool Principal = false, const bool Eponymous = false);
	virtual void insertRst(ListWznmMTablecol& rst, bool transact = false);
	virtual void updateRec(WznmMTablecol* rec);
	virtual void updateRst(ListWznmMTablecol& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMTablecol** rec);
	virtual bool loadRefByTblSrf(Sbecore::ubigint tblRefWznmMTable, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint tblRefWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByTbl(Sbecore::ubigint tblRefWznmMTable, const bool append, ListWznmMTablecol& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMTablecol& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMTablecol: C++ wrapper for table TblWznmMTablecol (MySQL database)
	*/
class MyTblWznmMTablecol : public TblWznmMTablecol, public Sbecore::MyTable {

public:
	MyTblWznmMTablecol();
	~MyTblWznmMTablecol();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMTablecol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMTablecol& rst);

	Sbecore::ubigint insertRec(WznmMTablecol* rec);
	void insertRst(ListWznmMTablecol& rst, bool transact = false);
	void updateRec(WznmMTablecol* rec);
	void updateRst(ListWznmMTablecol& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMTablecol** rec);
	bool loadRefByTblSrf(Sbecore::ubigint tblRefWznmMTable, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint tblRefWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint tblRefWznmMTable, const bool append, ListWznmMTablecol& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMTablecol: C++ wrapper for table TblWznmMTablecol (PgSQL database)
	*/
class PgTblWznmMTablecol : public TblWznmMTablecol, public Sbecore::PgTable {

public:
	PgTblWznmMTablecol();
	~PgTblWznmMTablecol();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMTablecol** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMTablecol& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMTablecol** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMTablecol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMTablecol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMTablecol& rst);

	Sbecore::ubigint insertRec(WznmMTablecol* rec);
	void insertRst(ListWznmMTablecol& rst, bool transact = false);
	void updateRec(WznmMTablecol* rec);
	void updateRst(ListWznmMTablecol& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMTablecol** rec);
	bool loadRefByTblSrf(Sbecore::ubigint tblRefWznmMTable, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint tblRefWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint tblRefWznmMTable, const bool append, ListWznmMTablecol& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
