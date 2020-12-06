/**
	* \file WznmMQuery.h
	* database access for table TblWznmMQuery (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMQUERY_H
#define WZNMMQUERY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMQueryBasetype TblWznmMQuery::VecVBasetype
#define VecWznmVMQuerySupSubrole TblWznmMQuery::VecVSupSubrole

/**
	* WznmMQuery: record of TblWznmMQuery
	*/
class WznmMQuery {

public:
	WznmMQuery(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint supRefWznmMQuery = 0, const Sbecore::uint supIxVSubrole = 0, const Sbecore::ubigint refRTable = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint qtbRefWznmMTable = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const bool Limofs = false, const Sbecore::ubigint inoRefAOrder = 0, const std::string inoSrefsWznmMTablecol = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmMVersion;
	Sbecore::ubigint supRefWznmMQuery;
	Sbecore::uint supIxVSubrole;
	Sbecore::ubigint refRTable;
	Sbecore::ubigint refWznmMTable;
	Sbecore::ubigint qtbRefWznmMTable;
	Sbecore::ubigint refWznmMJob;
	std::string sref;
	bool Limofs;
	Sbecore::ubigint inoRefAOrder;
	std::string inoSrefsWznmMTablecol;
	std::string Comment;

public:
	bool operator==(const WznmMQuery& comp);
	bool operator!=(const WznmMQuery& comp);
};

/**
	* ListWznmMQuery: recordset of TblWznmMQuery
	*/
class ListWznmMQuery {

public:
	ListWznmMQuery();
	ListWznmMQuery(const ListWznmMQuery& src);
	~ListWznmMQuery();

	void clear();
	unsigned int size() const;
	void append(WznmMQuery* rec);

	WznmMQuery* operator[](const Sbecore::uint ix);
	ListWznmMQuery& operator=(const ListWznmMQuery& src);
	bool operator==(const ListWznmMQuery& comp);
	bool operator!=(const ListWznmMQuery& comp);

public:
	std::vector<WznmMQuery*> nodes;
};

/**
	* TblWznmMQuery: C++ wrapper for table TblWznmMQuery
	*/
class TblWznmMQuery {

public:
	/**
		* VecVBasetype (full: VecWznmVMQueryBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint STD = 1;
		static const Sbecore::uint MULTBRA = 2;
		static const Sbecore::uint LIST = 3;
		static const Sbecore::uint OOLIST = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVSupSubrole (full: VecWznmVMQuerySupSubrole)
		*/
	class VecVSupSubrole {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint OPR = 2;
		static const Sbecore::uint LREF = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMQuery();
	virtual ~TblWznmMQuery();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMQuery** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMQuery& rst);

	virtual Sbecore::ubigint insertRec(WznmMQuery* rec);
	Sbecore::ubigint insertNewRec(WznmMQuery** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint supRefWznmMQuery = 0, const Sbecore::uint supIxVSubrole = 0, const Sbecore::ubigint refRTable = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint qtbRefWznmMTable = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const bool Limofs = false, const Sbecore::ubigint inoRefAOrder = 0, const std::string inoSrefsWznmMTablecol = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMQuery& rst, WznmMQuery** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint supRefWznmMQuery = 0, const Sbecore::uint supIxVSubrole = 0, const Sbecore::ubigint refRTable = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::ubigint qtbRefWznmMTable = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const bool Limofs = false, const Sbecore::ubigint inoRefAOrder = 0, const std::string inoSrefsWznmMTablecol = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMQuery& rst, bool transact = false);
	virtual void updateRec(WznmMQuery* rec);
	virtual void updateRst(ListWznmMQuery& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMQuery** rec);
	virtual bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMQuery** rec);
	virtual bool loadRecByQtb(Sbecore::ubigint qtbRefWznmMTable, WznmMQuery** rec);
	virtual bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMQuery& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMQuery& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMQuery: C++ wrapper for table TblWznmMQuery (MySQL database)
	*/
class MyTblWznmMQuery : public TblWznmMQuery, public Sbecore::MyTable {

public:
	MyTblWznmMQuery();
	~MyTblWznmMQuery();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMQuery& rst);

	Sbecore::ubigint insertRec(WznmMQuery* rec);
	void insertRst(ListWznmMQuery& rst, bool transact = false);
	void updateRec(WznmMQuery* rec);
	void updateRst(ListWznmMQuery& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMQuery** rec);
	bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMQuery** rec);
	bool loadRecByQtb(Sbecore::ubigint qtbRefWznmMTable, WznmMQuery** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMQuery& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMQuery: C++ wrapper for table TblWznmMQuery (PgSQL database)
	*/
class PgTblWznmMQuery : public TblWznmMQuery, public Sbecore::PgTable {

public:
	PgTblWznmMQuery();
	~PgTblWznmMQuery();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMQuery** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMQuery& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMQuery** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMQuery& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMQuery** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMQuery& rst);

	Sbecore::ubigint insertRec(WznmMQuery* rec);
	void insertRst(ListWznmMQuery& rst, bool transact = false);
	void updateRec(WznmMQuery* rec);
	void updateRst(ListWznmMQuery& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMQuery** rec);
	bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMQuery** rec);
	bool loadRecByQtb(Sbecore::ubigint qtbRefWznmMTable, WznmMQuery** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMQuery& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
