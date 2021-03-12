/**
	* \file WznmMVersion.h
	* database access for table TblWznmMVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMVERSION_H
#define WZNMMVERSION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMVersionState TblWznmMVersion::VecVState
#define VecWznmWMVersionDbmstype TblWznmMVersion::VecWDbmstype
#define VecWznmWMVersionOption TblWznmMVersion::VecWOption

/**
	* WznmMVersion: record of TblWznmMVersion
	*/
class WznmMVersion {

public:
	WznmMVersion(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint prjRefWznmMProject = 0, const Sbecore::uint prjNum = 0, const Sbecore::ubigint bvrRefWznmMVersion = 0, const Sbecore::ubigint refRLocale = 0, const Sbecore::ubigint refWznmMLocale = 0, const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWDbmstype = 0, const Sbecore::uint ixWOption = 0, const Sbecore::ubigint refJ = 0, const std::string About1 = "", const std::string About2 = "", const std::string About3 = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint prjRefWznmMProject;
	Sbecore::uint prjNum;
	Sbecore::ubigint bvrRefWznmMVersion;
	Sbecore::ubigint refRLocale;
	Sbecore::ubigint refWznmMLocale;
	Sbecore::usmallint Major;
	Sbecore::usmallint Minor;
	Sbecore::usmallint Sub;
	Sbecore::ubigint refJState;
	Sbecore::uint ixVState;
	Sbecore::uint ixWDbmstype;
	Sbecore::uint ixWOption;
	Sbecore::ubigint refJ;
	std::string About1;
	std::string About2;
	std::string About3;
	std::string Comment;

public:
	bool operator==(const WznmMVersion& comp);
	bool operator!=(const WznmMVersion& comp);
};

/**
	* ListWznmMVersion: recordset of TblWznmMVersion
	*/
class ListWznmMVersion {

public:
	ListWznmMVersion();
	ListWznmMVersion(const ListWznmMVersion& src);
	~ListWznmMVersion();

	void clear();
	unsigned int size() const;
	void append(WznmMVersion* rec);

	WznmMVersion* operator[](const Sbecore::uint ix);
	ListWznmMVersion& operator=(const ListWznmMVersion& src);
	bool operator==(const ListWznmMVersion& comp);
	bool operator!=(const ListWznmMVersion& comp);

public:
	std::vector<WznmMVersion*> nodes;
};

/**
	* TblWznmMVersion: C++ wrapper for table TblWznmMVersion
	*/
class TblWznmMVersion {

public:
	/**
		* VecVState (full: VecWznmVMVersionState)
		*/
	class VecVState {

	public:
		static const Sbecore::uint NEWCRE = 1;
		static const Sbecore::uint NEWIMP = 2;
		static const Sbecore::uint DSNDEPLOY = 3;
		static const Sbecore::uint DSNGLOBAL = 4;
		static const Sbecore::uint DSNDBSTR = 5;
		static const Sbecore::uint DSNBSCUI = 6;
		static const Sbecore::uint DSNIMPEXP = 7;
		static const Sbecore::uint DSNOPPACK = 8;
		static const Sbecore::uint DSNCUSTJOB = 9;
		static const Sbecore::uint DSNGENUI = 10;
		static const Sbecore::uint DSNCUSTUI = 11;
		static const Sbecore::uint DSNGENJTR = 12;
		static const Sbecore::uint DSNCUSTJTR = 13;
		static const Sbecore::uint READY = 14;
		static const Sbecore::uint ABANDON = 15;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecWDbmstype (full: VecWznmWMVersionDbmstype)
		*/
	class VecWDbmstype {

	public:
		static const Sbecore::uint MARARIA = 1;
		static const Sbecore::uint MARINNO = 2;
		static const Sbecore::uint MYINNO = 4;
		static const Sbecore::uint MYISAM = 8;
		static const Sbecore::uint PG = 16;
		static const Sbecore::uint LITE = 32;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecWOption (full: VecWznmWMVersionOption)
		*/
	class VecWOption {

	public:
		static const Sbecore::uint ACCGRPREG = 1;
		static const Sbecore::uint ACCNOGOALL = 2;
		static const Sbecore::uint APIMON = 4;
		static const Sbecore::uint DBSMON = 8;
		static const Sbecore::uint DDSPUB = 16;
		static const Sbecore::uint UASRV = 32;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

public:
	TblWznmMVersion();
	virtual ~TblWznmMVersion();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMVersion** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMVersion& rst);

	virtual Sbecore::ubigint insertRec(WznmMVersion* rec);
	Sbecore::ubigint insertNewRec(WznmMVersion** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint prjRefWznmMProject = 0, const Sbecore::uint prjNum = 0, const Sbecore::ubigint bvrRefWznmMVersion = 0, const Sbecore::ubigint refRLocale = 0, const Sbecore::ubigint refWznmMLocale = 0, const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWDbmstype = 0, const Sbecore::uint ixWOption = 0, const Sbecore::ubigint refJ = 0, const std::string About1 = "", const std::string About2 = "", const std::string About3 = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMVersion& rst, WznmMVersion** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint prjRefWznmMProject = 0, const Sbecore::uint prjNum = 0, const Sbecore::ubigint bvrRefWznmMVersion = 0, const Sbecore::ubigint refRLocale = 0, const Sbecore::ubigint refWznmMLocale = 0, const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWDbmstype = 0, const Sbecore::uint ixWOption = 0, const Sbecore::ubigint refJ = 0, const std::string About1 = "", const std::string About2 = "", const std::string About3 = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMVersion& rst, bool transact = false);
	virtual void updateRec(WznmMVersion* rec);
	virtual void updateRst(ListWznmMVersion& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMVersion** rec);
	virtual Sbecore::ubigint loadRefsByPrj(Sbecore::ubigint prjRefWznmMProject, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPrj(Sbecore::ubigint prjRefWznmMProject, const bool append, ListWznmMVersion& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMVersion& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMVersion: C++ wrapper for table TblWznmMVersion (MySQL database)
	*/
class MyTblWznmMVersion : public TblWznmMVersion, public Sbecore::MyTable {

public:
	MyTblWznmMVersion();
	~MyTblWznmMVersion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMVersion& rst);

	Sbecore::ubigint insertRec(WznmMVersion* rec);
	void insertRst(ListWznmMVersion& rst, bool transact = false);
	void updateRec(WznmMVersion* rec);
	void updateRst(ListWznmMVersion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMVersion** rec);
	Sbecore::ubigint loadRefsByPrj(Sbecore::ubigint prjRefWznmMProject, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrj(Sbecore::ubigint prjRefWznmMProject, const bool append, ListWznmMVersion& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMVersion: C++ wrapper for table TblWznmMVersion (PgSQL database)
	*/
class PgTblWznmMVersion : public TblWznmMVersion, public Sbecore::PgTable {

public:
	PgTblWznmMVersion();
	~PgTblWznmMVersion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMVersion** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMVersion& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMVersion** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMVersion& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMVersion** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMVersion& rst);

	Sbecore::ubigint insertRec(WznmMVersion* rec);
	void insertRst(ListWznmMVersion& rst, bool transact = false);
	void updateRec(WznmMVersion* rec);
	void updateRst(ListWznmMVersion& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMVersion** rec);
	Sbecore::ubigint loadRefsByPrj(Sbecore::ubigint prjRefWznmMProject, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrj(Sbecore::ubigint prjRefWznmMProject, const bool append, ListWznmMVersion& rst);
};
#endif

#endif
