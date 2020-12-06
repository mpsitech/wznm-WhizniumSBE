/**
	* \file WznmMImpexp.h
	* database access for table TblWznmMImpexp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMIMPEXP_H
#define WZNMMIMPEXP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmWMImpexpIop TblWznmMImpexp::VecWIop

/**
	* WznmMImpexp: record of TblWznmMImpexp
	*/
class WznmMImpexp {

public:
	WznmMImpexp(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMImpexpcplx = 0, const Sbecore::ubigint supRefWznmMImpexp = 0, const Sbecore::usmallint supLvl = 0, const Sbecore::ubigint refWznmMTable = 0, const std::string sref = "", const Sbecore::uint ixWIop = 0, const std::string rtrSrefsWznmMImpexpcol = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMImpexpcplx;
	Sbecore::ubigint supRefWznmMImpexp;
	Sbecore::usmallint supLvl;
	Sbecore::ubigint refWznmMTable;
	std::string sref;
	Sbecore::uint ixWIop;
	std::string rtrSrefsWznmMImpexpcol;
	std::string Comment;

public:
	bool operator==(const WznmMImpexp& comp);
	bool operator!=(const WznmMImpexp& comp);
};

/**
	* ListWznmMImpexp: recordset of TblWznmMImpexp
	*/
class ListWznmMImpexp {

public:
	ListWznmMImpexp();
	ListWznmMImpexp(const ListWznmMImpexp& src);
	~ListWznmMImpexp();

	void clear();
	unsigned int size() const;
	void append(WznmMImpexp* rec);

	WznmMImpexp* operator[](const Sbecore::uint ix);
	ListWznmMImpexp& operator=(const ListWznmMImpexp& src);
	bool operator==(const ListWznmMImpexp& comp);
	bool operator!=(const ListWznmMImpexp& comp);

public:
	std::vector<WznmMImpexp*> nodes;
};

/**
	* TblWznmMImpexp: C++ wrapper for table TblWznmMImpexp
	*/
class TblWznmMImpexp {

public:
	/**
		* VecWIop (full: VecWznmWMImpexpIop)
		*/
	class VecWIop {

	public:
		static const Sbecore::uint INS = 1;
		static const Sbecore::uint RETR = 2;
		static const Sbecore::uint RETRUPD = 4;
		static const Sbecore::uint RETRINS = 8;
		static const Sbecore::uint RETRUPDINS = 16;
		static const Sbecore::uint RMV = 32;
		static const Sbecore::uint CUST = 64;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMImpexp();
	virtual ~TblWznmMImpexp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMImpexp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMImpexp& rst);

	virtual Sbecore::ubigint insertRec(WznmMImpexp* rec);
	Sbecore::ubigint insertNewRec(WznmMImpexp** rec = NULL, const Sbecore::ubigint refWznmMImpexpcplx = 0, const Sbecore::ubigint supRefWznmMImpexp = 0, const Sbecore::usmallint supLvl = 0, const Sbecore::ubigint refWznmMTable = 0, const std::string sref = "", const Sbecore::uint ixWIop = 0, const std::string rtrSrefsWznmMImpexpcol = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMImpexp& rst, WznmMImpexp** rec = NULL, const Sbecore::ubigint refWznmMImpexpcplx = 0, const Sbecore::ubigint supRefWznmMImpexp = 0, const Sbecore::usmallint supLvl = 0, const Sbecore::ubigint refWznmMTable = 0, const std::string sref = "", const Sbecore::uint ixWIop = 0, const std::string rtrSrefsWznmMImpexpcol = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMImpexp& rst, bool transact = false);
	virtual void updateRec(WznmMImpexp* rec);
	virtual void updateRst(ListWznmMImpexp& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMImpexp** rec);
	virtual bool confirmByRef(Sbecore::ubigint ref);
	virtual Sbecore::ubigint loadRefsByIex(Sbecore::ubigint refWznmMImpexpcplx, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWznmMImpexp, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByIex(Sbecore::ubigint refWznmMImpexpcplx, const bool append, ListWznmMImpexp& rst);
	virtual Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWznmMImpexp, const bool append, ListWznmMImpexp& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	virtual bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWznmMImpexp);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMImpexp& rst);
	Sbecore::ubigint loadHrefsup(Sbecore::ubigint ref, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadHrefsdown(Sbecore::ubigint ref, const bool append, std::vector<Sbecore::ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
	Sbecore::ubigint loadHrstup(Sbecore::ubigint ref, ListWznmMImpexp& rst);
	Sbecore::ubigint loadHrstdown(Sbecore::ubigint ref, const bool append, ListWznmMImpexp& rst, unsigned int firstix = 0, unsigned int lastix = 0);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMImpexp: C++ wrapper for table TblWznmMImpexp (MySQL database)
	*/
class MyTblWznmMImpexp : public TblWznmMImpexp, public Sbecore::MyTable {

public:
	MyTblWznmMImpexp();
	~MyTblWznmMImpexp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMImpexp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMImpexp& rst);

	Sbecore::ubigint insertRec(WznmMImpexp* rec);
	void insertRst(ListWznmMImpexp& rst, bool transact = false);
	void updateRec(WznmMImpexp* rec);
	void updateRst(ListWznmMImpexp& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMImpexp** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	Sbecore::ubigint loadRefsByIex(Sbecore::ubigint refWznmMImpexpcplx, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWznmMImpexp, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByIex(Sbecore::ubigint refWznmMImpexpcplx, const bool append, ListWznmMImpexp& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWznmMImpexp, const bool append, ListWznmMImpexp& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWznmMImpexp);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMImpexp: C++ wrapper for table TblWznmMImpexp (PgSQL database)
	*/
class PgTblWznmMImpexp : public TblWznmMImpexp, public Sbecore::PgTable {

public:
	PgTblWznmMImpexp();
	~PgTblWznmMImpexp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMImpexp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMImpexp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMImpexp** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMImpexp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMImpexp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMImpexp& rst);

	Sbecore::ubigint insertRec(WznmMImpexp* rec);
	void insertRst(ListWznmMImpexp& rst, bool transact = false);
	void updateRec(WznmMImpexp* rec);
	void updateRst(ListWznmMImpexp& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMImpexp** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	Sbecore::ubigint loadRefsByIex(Sbecore::ubigint refWznmMImpexpcplx, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWznmMImpexp, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByIex(Sbecore::ubigint refWznmMImpexpcplx, const bool append, ListWznmMImpexp& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWznmMImpexp, const bool append, ListWznmMImpexp& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWznmMImpexp);
};
#endif

#endif
