/**
	* \file WznmMQuerycol.h
	* database access for table TblWznmMQuerycol (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMQUERYCOL_H
#define WZNMMQUERYCOL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMQuerycolBasetype TblWznmMQuerycol::VecVBasetype
#define VecWznmWMQuerycolOccurrence TblWznmMQuerycol::VecWOccurrence

/**
	* WznmMQuerycol: record of TblWznmMQuerycol
	*/
class WznmMQuerycol {

public:
	WznmMQuerycol(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint ixWOccurrence = 0, const Sbecore::ubigint qryRefWznmMQuery = 0, const Sbecore::uint qryNum = 0, const Sbecore::ubigint refWznmMTablecol = 0, const std::string sref = "", const std::string Short = "", const Sbecore::ubigint refWznmMStub = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::uint ixWOccurrence;
	Sbecore::ubigint qryRefWznmMQuery;
	Sbecore::uint qryNum;
	Sbecore::ubigint refWznmMTablecol;
	std::string sref;
	std::string Short;
	Sbecore::ubigint refWznmMStub;

public:
	bool operator==(const WznmMQuerycol& comp);
	bool operator!=(const WznmMQuerycol& comp);
};

/**
	* ListWznmMQuerycol: recordset of TblWznmMQuerycol
	*/
class ListWznmMQuerycol {

public:
	ListWznmMQuerycol();
	ListWznmMQuerycol(const ListWznmMQuerycol& src);
	~ListWznmMQuerycol();

	void clear();
	unsigned int size() const;
	void append(WznmMQuerycol* rec);

	WznmMQuerycol* operator[](const Sbecore::uint ix);
	ListWznmMQuerycol& operator=(const ListWznmMQuerycol& src);
	bool operator==(const ListWznmMQuerycol& comp);
	bool operator!=(const ListWznmMQuerycol& comp);

public:
	std::vector<WznmMQuerycol*> nodes;
};

/**
	* TblWznmMQuerycol: C++ wrapper for table TblWznmMQuerycol
	*/
class TblWznmMQuerycol {

public:
	/**
		* VecVBasetype (full: VecWznmVMQuerycolBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint TBL = 1;
		static const Sbecore::uint STUB = 2;
		static const Sbecore::uint HSTUB = 3;
		static const Sbecore::uint USTUB = 4;
		static const Sbecore::uint STUBS = 5;
		static const Sbecore::uint VSREF = 6;
		static const Sbecore::uint VSREFS = 7;
		static const Sbecore::uint VTIT = 8;
		static const Sbecore::uint VTITS = 9;
		static const Sbecore::uint YESNO = 10;
		static const Sbecore::uint FTMDATE = 11;
		static const Sbecore::uint FTMTIME = 12;
		static const Sbecore::uint FTMSTAMP = 13;
		static const Sbecore::uint FTMUSTAMP = 14;
		static const Sbecore::uint QIDREF = 15;
		static const Sbecore::uint QWR = 16;
		static const Sbecore::uint QJREF = 17;
		static const Sbecore::uint QJENUM = 18;
		static const Sbecore::uint INTVAL = 19;
		static const Sbecore::uint DBLVAL = 20;
		static const Sbecore::uint BOOLVAL = 21;
		static const Sbecore::uint TXTVAL = 22;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWOccurrence (full: VecWznmWMQuerycolOccurrence)
		*/
	class VecWOccurrence {

	public:
		static const Sbecore::uint QTB = 1;
		static const Sbecore::uint XML = 2;
		static const Sbecore::uint BTB = 4;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMQuerycol();
	virtual ~TblWznmMQuerycol();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMQuerycol** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMQuerycol& rst);

	virtual Sbecore::ubigint insertRec(WznmMQuerycol* rec);
	Sbecore::ubigint insertNewRec(WznmMQuerycol** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint ixWOccurrence = 0, const Sbecore::ubigint qryRefWznmMQuery = 0, const Sbecore::uint qryNum = 0, const Sbecore::ubigint refWznmMTablecol = 0, const std::string sref = "", const std::string Short = "", const Sbecore::ubigint refWznmMStub = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmMQuerycol& rst, WznmMQuerycol** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint ixWOccurrence = 0, const Sbecore::ubigint qryRefWznmMQuery = 0, const Sbecore::uint qryNum = 0, const Sbecore::ubigint refWznmMTablecol = 0, const std::string sref = "", const std::string Short = "", const Sbecore::ubigint refWznmMStub = 0);
	virtual void insertRst(ListWznmMQuerycol& rst, bool transact = false);
	virtual void updateRec(WznmMQuerycol* rec);
	virtual void updateRst(ListWznmMQuerycol& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMQuerycol** rec);
	virtual Sbecore::ubigint loadRefsByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, ListWznmMQuerycol& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMQuerycol& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMQuerycol: C++ wrapper for table TblWznmMQuerycol (MySQL database)
	*/
class MyTblWznmMQuerycol : public TblWznmMQuerycol, public Sbecore::MyTable {

public:
	MyTblWznmMQuerycol();
	~MyTblWznmMQuerycol();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMQuerycol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMQuerycol& rst);

	Sbecore::ubigint insertRec(WznmMQuerycol* rec);
	void insertRst(ListWznmMQuerycol& rst, bool transact = false);
	void updateRec(WznmMQuerycol* rec);
	void updateRst(ListWznmMQuerycol& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMQuerycol** rec);
	Sbecore::ubigint loadRefsByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, ListWznmMQuerycol& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMQuerycol: C++ wrapper for table TblWznmMQuerycol (PgSQL database)
	*/
class PgTblWznmMQuerycol : public TblWznmMQuerycol, public Sbecore::PgTable {

public:
	PgTblWznmMQuerycol();
	~PgTblWznmMQuerycol();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMQuerycol** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMQuerycol& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMQuerycol** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMQuerycol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMQuerycol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMQuerycol& rst);

	Sbecore::ubigint insertRec(WznmMQuerycol* rec);
	void insertRst(ListWznmMQuerycol& rst, bool transact = false);
	void updateRec(WznmMQuerycol* rec);
	void updateRst(ListWznmMQuerycol& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMQuerycol** rec);
	Sbecore::ubigint loadRefsByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, ListWznmMQuerycol& rst);
};
#endif

#endif

