/**
	* \file WznmMTable.h
	* database access for table TblWznmMTable (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMTABLE_H
#define WZNMMTABLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMTableBasetype TblWznmMTable::VecVBasetype
#define VecWznmVMTableRefTbl TblWznmMTable::VecVRefTbl
#define VecWznmWMTableSubset TblWznmMTable::VecWSubset

/**
	* WznmMTable: record of TblWznmMTable
	*/
class WznmMTable {

public:
	WznmMTable(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint refWznmMCard = 0, const std::string sref = "", const std::string Short = "", const std::string unqSrefsWznmMTablecol = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmMVersion;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::ubigint refWznmMPreset;
	Sbecore::ubigint refWznmMCard;
	std::string sref;
	std::string Short;
	std::string unqSrefsWznmMTablecol;
	std::string Comment;

public:
	bool operator==(const WznmMTable& comp);
	bool operator!=(const WznmMTable& comp);
};

/**
	* ListWznmMTable: recordset of TblWznmMTable
	*/
class ListWznmMTable {

public:
	ListWznmMTable();
	ListWznmMTable(const ListWznmMTable& src);
	~ListWznmMTable();

	void clear();
	unsigned int size() const;
	void append(WznmMTable* rec);

	WznmMTable* operator[](const Sbecore::uint ix);
	ListWznmMTable& operator=(const ListWznmMTable& src);
	bool operator==(const ListWznmMTable& comp);
	bool operator!=(const ListWznmMTable& comp);

public:
	std::vector<WznmMTable*> nodes;
};

/**
	* TblWznmMTable: C++ wrapper for table TblWznmMTable
	*/
class TblWznmMTable {

public:
	/**
		* VecVBasetype (full: VecWznmVMTableBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint MAIN = 1;
		static const Sbecore::uint AUX = 2;
		static const Sbecore::uint REL = 3;
		static const Sbecore::uint JUMP = 4;
		static const Sbecore::uint CLUST = 5;
		static const Sbecore::uint LIST = 6;
		static const Sbecore::uint OPR = 7;
		static const Sbecore::uint SUB1N = 8;
		static const Sbecore::uint SUBMN = 9;
		static const Sbecore::uint QRY = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVRefTbl (full: VecWznmVMTableRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint QRY = 2;
		static const Sbecore::uint REL = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecWSubset (full: VecWznmWMTableSubset)
		*/
	class VecWSubset {

	public:
		static const Sbecore::uint SBSWZNMBMTABLEMTB = 1;
		static const Sbecore::uint SBSWZNMBMTABLEQTB = 2;
		static const Sbecore::uint SBSWZNMBMTABLERLT = 4;
		static const Sbecore::uint SBSWZNMBMTABLESTT = 8;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);
	};

public:
	TblWznmMTable();
	virtual ~TblWznmMTable();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMTable** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMTable& rst);

	virtual Sbecore::ubigint insertRec(WznmMTable* rec);
	Sbecore::ubigint insertNewRec(WznmMTable** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint refWznmMCard = 0, const std::string sref = "", const std::string Short = "", const std::string unqSrefsWznmMTablecol = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMTable& rst, WznmMTable** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint refWznmMCard = 0, const std::string sref = "", const std::string Short = "", const std::string unqSrefsWznmMTablecol = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMTable& rst, bool transact = false);
	virtual void updateRec(WznmMTable* rec);
	virtual void updateRst(ListWznmMTable& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMTable** rec);
	virtual bool loadRecByCar(Sbecore::ubigint refWznmMCard, WznmMTable** rec);
	virtual bool loadRecByPst(Sbecore::ubigint refWznmMPreset, WznmMTable** rec);
	virtual bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMTable** rec);
	virtual bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMTable& rst);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMTable& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMTable& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMTable: C++ wrapper for table TblWznmMTable (MySQL database)
	*/
class MyTblWznmMTable : public TblWznmMTable, public Sbecore::MyTable {

public:
	MyTblWznmMTable();
	~MyTblWznmMTable();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMTable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMTable& rst);

	Sbecore::ubigint insertRec(WznmMTable* rec);
	void insertRst(ListWznmMTable& rst, bool transact = false);
	void updateRec(WznmMTable* rec);
	void updateRst(ListWznmMTable& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMTable** rec);
	bool loadRecByCar(Sbecore::ubigint refWznmMCard, WznmMTable** rec);
	bool loadRecByPst(Sbecore::ubigint refWznmMPreset, WznmMTable** rec);
	bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMTable** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMTable& rst);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMTable& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMTable: C++ wrapper for table TblWznmMTable (PgSQL database)
	*/
class PgTblWznmMTable : public TblWznmMTable, public Sbecore::PgTable {

public:
	PgTblWznmMTable();
	~PgTblWznmMTable();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMTable** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMTable& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMTable** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMTable& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMTable** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMTable& rst);

	Sbecore::ubigint insertRec(WznmMTable* rec);
	void insertRst(ListWznmMTable& rst, bool transact = false);
	void updateRec(WznmMTable* rec);
	void updateRst(ListWznmMTable& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMTable** rec);
	bool loadRecByCar(Sbecore::ubigint refWznmMCard, WznmMTable** rec);
	bool loadRecByPst(Sbecore::ubigint refWznmMPreset, WznmMTable** rec);
	bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMTable** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByVer(Sbecore::ubigint refWznmMVersion, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMTable& rst);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMTable& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
