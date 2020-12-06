/**
	* \file WznmMImpexpcol.h
	* database access for table TblWznmMImpexpcol (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMIMPEXPCOL_H
#define WZNMMIMPEXPCOL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMImpexpcolBasetype TblWznmMImpexpcol::VecVBasetype
#define VecWznmVMImpexpcolConvtype TblWznmMImpexpcol::VecVConvtype
#define VecWznmWMImpexpcolOccurrence TblWznmMImpexpcol::VecWOccurrence

/**
	* WznmMImpexpcol: record of TblWznmMImpexpcol
	*/
class WznmMImpexpcol {

public:
	WznmMImpexpcol(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint ixWOccurrence = 0, const Sbecore::ubigint imeRefWznmMImpexp = 0, const Sbecore::uint imeNum = 0, const Sbecore::ubigint refWznmMTablecol = 0, const std::string sref = "", const std::string Short = "", const Sbecore::ubigint refWznmMImpexp = 0, const Sbecore::uint ixVConvtype = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint refJStub = 0, const Sbecore::ubigint refWznmMStub = 0, const Sbecore::ubigint refWznmMVectoritem = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::uint ixWOccurrence;
	Sbecore::ubigint imeRefWznmMImpexp;
	Sbecore::uint imeNum;
	Sbecore::ubigint refWznmMTablecol;
	std::string sref;
	std::string Short;
	Sbecore::ubigint refWznmMImpexp;
	Sbecore::uint ixVConvtype;
	std::string Defval;
	Sbecore::ubigint refWznmMPreset;
	Sbecore::ubigint refJStub;
	Sbecore::ubigint refWznmMStub;
	Sbecore::ubigint refWznmMVectoritem;

public:
	bool operator==(const WznmMImpexpcol& comp);
	bool operator!=(const WznmMImpexpcol& comp);
};

/**
	* ListWznmMImpexpcol: recordset of TblWznmMImpexpcol
	*/
class ListWznmMImpexpcol {

public:
	ListWznmMImpexpcol();
	ListWznmMImpexpcol(const ListWznmMImpexpcol& src);
	~ListWznmMImpexpcol();

	void clear();
	unsigned int size() const;
	void append(WznmMImpexpcol* rec);

	WznmMImpexpcol* operator[](const Sbecore::uint ix);
	ListWznmMImpexpcol& operator=(const ListWznmMImpexpcol& src);
	bool operator==(const ListWznmMImpexpcol& comp);
	bool operator!=(const ListWznmMImpexpcol& comp);

public:
	std::vector<WznmMImpexpcol*> nodes;
};

/**
	* TblWznmMImpexpcol: C++ wrapper for table TblWznmMImpexpcol
	*/
class TblWznmMImpexpcol {

public:
	/**
		* VecVBasetype (full: VecWznmVMImpexpcolBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint IOP = 1;
		static const Sbecore::uint IDIREF = 2;
		static const Sbecore::uint IREF = 3;
		static const Sbecore::uint TBL = 4;
		static const Sbecore::uint TSREF = 5;
		static const Sbecore::uint THSREF = 6;
		static const Sbecore::uint THINT = 7;
		static const Sbecore::uint VSREF = 8;
		static const Sbecore::uint FTM = 9;
		static const Sbecore::uint IARG = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVConvtype (full: VecWznmVMImpexpcolConvtype)
		*/
	class VecVConvtype {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint PREVIMP = 2;
		static const Sbecore::uint CUST = 3;
		static const Sbecore::uint CUSTSQL = 4;
		static const Sbecore::uint RST = 5;
		static const Sbecore::uint IMPPP = 6;
		static const Sbecore::uint CUSTSQLPP = 7;
		static const Sbecore::uint IXSREF = 8;
		static const Sbecore::uint INCR = 9;
		static const Sbecore::uint INVFTM = 10;
		static const Sbecore::uint SUP = 11;
		static const Sbecore::uint SUB = 12;
		static const Sbecore::uint PRESET = 13;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWOccurrence (full: VecWznmWMImpexpcolOccurrence)
		*/
	class VecWOccurrence {

	public:
		static const Sbecore::uint FIL = 1;
		static const Sbecore::uint TBL = 2;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMImpexpcol();
	virtual ~TblWznmMImpexpcol();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMImpexpcol** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMImpexpcol& rst);

	virtual Sbecore::ubigint insertRec(WznmMImpexpcol* rec);
	Sbecore::ubigint insertNewRec(WznmMImpexpcol** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint ixWOccurrence = 0, const Sbecore::ubigint imeRefWznmMImpexp = 0, const Sbecore::uint imeNum = 0, const Sbecore::ubigint refWznmMTablecol = 0, const std::string sref = "", const std::string Short = "", const Sbecore::ubigint refWznmMImpexp = 0, const Sbecore::uint ixVConvtype = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint refJStub = 0, const Sbecore::ubigint refWznmMStub = 0, const Sbecore::ubigint refWznmMVectoritem = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmMImpexpcol& rst, WznmMImpexpcol** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::uint ixWOccurrence = 0, const Sbecore::ubigint imeRefWznmMImpexp = 0, const Sbecore::uint imeNum = 0, const Sbecore::ubigint refWznmMTablecol = 0, const std::string sref = "", const std::string Short = "", const Sbecore::ubigint refWznmMImpexp = 0, const Sbecore::uint ixVConvtype = 0, const std::string Defval = "", const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint refJStub = 0, const Sbecore::ubigint refWznmMStub = 0, const Sbecore::ubigint refWznmMVectoritem = 0);
	virtual void insertRst(ListWznmMImpexpcol& rst, bool transact = false);
	virtual void updateRec(WznmMImpexpcol* rec);
	virtual void updateRst(ListWznmMImpexpcol& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMImpexpcol** rec);
	virtual Sbecore::ubigint loadRefsByIme(Sbecore::ubigint imeRefWznmMImpexp, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByIme(Sbecore::ubigint imeRefWznmMImpexp, const bool append, ListWznmMImpexpcol& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMImpexpcol& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMImpexpcol: C++ wrapper for table TblWznmMImpexpcol (MySQL database)
	*/
class MyTblWznmMImpexpcol : public TblWznmMImpexpcol, public Sbecore::MyTable {

public:
	MyTblWznmMImpexpcol();
	~MyTblWznmMImpexpcol();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMImpexpcol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMImpexpcol& rst);

	Sbecore::ubigint insertRec(WznmMImpexpcol* rec);
	void insertRst(ListWznmMImpexpcol& rst, bool transact = false);
	void updateRec(WznmMImpexpcol* rec);
	void updateRst(ListWznmMImpexpcol& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMImpexpcol** rec);
	Sbecore::ubigint loadRefsByIme(Sbecore::ubigint imeRefWznmMImpexp, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByIme(Sbecore::ubigint imeRefWznmMImpexp, const bool append, ListWznmMImpexpcol& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMImpexpcol: C++ wrapper for table TblWznmMImpexpcol (PgSQL database)
	*/
class PgTblWznmMImpexpcol : public TblWznmMImpexpcol, public Sbecore::PgTable {

public:
	PgTblWznmMImpexpcol();
	~PgTblWznmMImpexpcol();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMImpexpcol** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMImpexpcol& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMImpexpcol** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMImpexpcol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMImpexpcol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMImpexpcol& rst);

	Sbecore::ubigint insertRec(WznmMImpexpcol* rec);
	void insertRst(ListWznmMImpexpcol& rst, bool transact = false);
	void updateRec(WznmMImpexpcol* rec);
	void updateRst(ListWznmMImpexpcol& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMImpexpcol** rec);
	Sbecore::ubigint loadRefsByIme(Sbecore::ubigint imeRefWznmMImpexp, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByIme(Sbecore::ubigint imeRefWznmMImpexp, const bool append, ListWznmMImpexpcol& rst);
};
#endif

#endif
