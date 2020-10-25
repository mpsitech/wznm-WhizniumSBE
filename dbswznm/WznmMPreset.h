/**
	* \file WznmMPreset.h
	* database access for table TblWznmMPreset (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMPRESET_H
#define WZNMMPRESET_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMPresetRefTbl TblWznmMPreset::VecVRefTbl
#define VecWznmVMPresetScope TblWznmMPreset::VecVScope

/**
	* WznmMPreset: record of TblWznmMPreset
	*/
class WznmMPreset {

public:
	WznmMPreset(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint ixVScope = 0, const std::string sref = "", const Sbecore::uint ixWznmWArgtype = 0, const Sbecore::ubigint refJTitle = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMVersion;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::uint ixVScope;
	std::string sref;
	Sbecore::uint ixWznmWArgtype;
	Sbecore::ubigint refJTitle;
	std::string Title;

public:
	bool operator==(const WznmMPreset& comp);
	bool operator!=(const WznmMPreset& comp);
};

/**
	* ListWznmMPreset: recordset of TblWznmMPreset
	*/
class ListWznmMPreset {

public:
	ListWznmMPreset();
	ListWznmMPreset(const ListWznmMPreset& src);
	~ListWznmMPreset();

	void clear();
	unsigned int size() const;
	void append(WznmMPreset* rec);

	WznmMPreset* operator[](const Sbecore::uint ix);
	ListWznmMPreset& operator=(const ListWznmMPreset& src);
	bool operator==(const ListWznmMPreset& comp);
	bool operator!=(const ListWznmMPreset& comp);

public:
	std::vector<WznmMPreset*> nodes;
};

/**
	* TblWznmMPreset: C++ wrapper for table TblWznmMPreset
	*/
class TblWznmMPreset {

public:
	/**
		* VecVRefTbl (full: VecWznmVMPresetRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint TBL = 2;
		static const Sbecore::uint SBS = 3;
		static const Sbecore::uint VEC = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVScope (full: VecWznmVMPresetScope)
		*/
	class VecVScope {

	public:
		static const Sbecore::uint SYS = 1;
		static const Sbecore::uint SESS = 2;
		static const Sbecore::uint CAR = 3;
		static const Sbecore::uint PNLREC = 4;
		static const Sbecore::uint PNL = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMPreset();
	virtual ~TblWznmMPreset();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMPreset** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMPreset& rst);

	virtual Sbecore::ubigint insertRec(WznmMPreset* rec);
	Sbecore::ubigint insertNewRec(WznmMPreset** rec = NULL, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint ixVScope = 0, const std::string sref = "", const Sbecore::uint ixWznmWArgtype = 0, const Sbecore::ubigint refJTitle = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMPreset& rst, WznmMPreset** rec = NULL, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint ixVScope = 0, const std::string sref = "", const Sbecore::uint ixWznmWArgtype = 0, const Sbecore::ubigint refJTitle = 0, const std::string Title = "");
	virtual void insertRst(ListWznmMPreset& rst, bool transact = false);
	virtual void updateRec(WznmMPreset* rec);
	virtual void updateRst(ListWznmMPreset& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMPreset** rec);
	virtual bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMPreset** rec);
	virtual bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMPreset& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMPreset& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMPreset: C++ wrapper for table TblWznmMPreset (MySQL database)
	*/
class MyTblWznmMPreset : public TblWznmMPreset, public Sbecore::MyTable {

public:
	MyTblWznmMPreset();
	~MyTblWznmMPreset();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMPreset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMPreset& rst);

	Sbecore::ubigint insertRec(WznmMPreset* rec);
	void insertRst(ListWznmMPreset& rst, bool transact = false);
	void updateRec(WznmMPreset* rec);
	void updateRst(ListWznmMPreset& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMPreset** rec);
	bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMPreset** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMPreset& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMPreset: C++ wrapper for table TblWznmMPreset (PgSQL database)
	*/
class PgTblWznmMPreset : public TblWznmMPreset, public Sbecore::PgTable {

public:
	PgTblWznmMPreset();
	~PgTblWznmMPreset();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMPreset** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMPreset& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMPreset** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMPreset& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMPreset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMPreset& rst);

	Sbecore::ubigint insertRec(WznmMPreset* rec);
	void insertRst(ListWznmMPreset& rst, bool transact = false);
	void updateRec(WznmMPreset* rec);
	void updateRst(ListWznmMPreset& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMPreset** rec);
	bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMPreset** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMPreset& rst);
};
#endif

#endif

