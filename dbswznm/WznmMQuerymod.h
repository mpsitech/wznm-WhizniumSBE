/**
	* \file WznmMQuerymod.h
	* database access for table TblWznmMQuerymod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMQUERYMOD_H
#define WZNMMQUERYMOD_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMQuerymodBasetype TblWznmMQuerymod::VecVBasetype
#define VecWznmVMQuerymodRefTbl TblWznmMQuerymod::VecVRefTbl

/**
	* WznmMQuerymod: record of TblWznmMQuerymod
	*/
class WznmMQuerymod {

public:
	WznmMQuerymod(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint qryRefWznmMQuery = 0, const Sbecore::uint qryNum = 0, const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string Avail = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint qryRefWznmMQuery;
	Sbecore::uint qryNum;
	Sbecore::ubigint refWznmMPreset;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	std::string Avail;

public:
	bool operator==(const WznmMQuerymod& comp);
	bool operator!=(const WznmMQuerymod& comp);
};

/**
	* ListWznmMQuerymod: recordset of TblWznmMQuerymod
	*/
class ListWznmMQuerymod {

public:
	ListWznmMQuerymod();
	ListWznmMQuerymod(const ListWznmMQuerymod& src);
	~ListWznmMQuerymod();

	void clear();
	unsigned int size() const;
	void append(WznmMQuerymod* rec);

	WznmMQuerymod* operator[](const Sbecore::uint ix);
	ListWznmMQuerymod& operator=(const ListWznmMQuerymod& src);
	bool operator==(const ListWznmMQuerymod& comp);
	bool operator!=(const ListWznmMQuerymod& comp);

public:
	std::vector<WznmMQuerymod*> nodes;
};

/**
	* TblWznmMQuerymod: C++ wrapper for table TblWznmMQuerymod
	*/
class TblWznmMQuerymod {

public:
	/**
		* VecVBasetype (full: VecWznmVMQuerymodBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint BRA = 1;
		static const Sbecore::uint EXBRA = 2;
		static const Sbecore::uint FILT = 3;
		static const Sbecore::uint JOVR = 4;
		static const Sbecore::uint STOVR = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVRefTbl (full: VecWznmVMQuerymodRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint TCO = 2;
		static const Sbecore::uint TBL = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMQuerymod();
	virtual ~TblWznmMQuerymod();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMQuerymod** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMQuerymod& rst);

	virtual Sbecore::ubigint insertRec(WznmMQuerymod* rec);
	Sbecore::ubigint insertNewRec(WznmMQuerymod** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint qryRefWznmMQuery = 0, const Sbecore::uint qryNum = 0, const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string Avail = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMQuerymod& rst, WznmMQuerymod** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint qryRefWznmMQuery = 0, const Sbecore::uint qryNum = 0, const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string Avail = "");
	virtual void insertRst(ListWznmMQuerymod& rst, bool transact = false);
	virtual void updateRec(WznmMQuerymod* rec);
	virtual void updateRst(ListWznmMQuerymod& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMQuerymod** rec);
	virtual Sbecore::ubigint loadRefsByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, ListWznmMQuerymod& rst);
	virtual Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWznmMQuerymod& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMQuerymod& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMQuerymod: C++ wrapper for table TblWznmMQuerymod (MySQL database)
	*/
class MyTblWznmMQuerymod : public TblWznmMQuerymod, public Sbecore::MyTable {

public:
	MyTblWznmMQuerymod();
	~MyTblWznmMQuerymod();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMQuerymod& rst);

	Sbecore::ubigint insertRec(WznmMQuerymod* rec);
	void insertRst(ListWznmMQuerymod& rst, bool transact = false);
	void updateRec(WznmMQuerymod* rec);
	void updateRst(ListWznmMQuerymod& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMQuerymod** rec);
	Sbecore::ubigint loadRefsByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, ListWznmMQuerymod& rst);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWznmMQuerymod& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMQuerymod: C++ wrapper for table TblWznmMQuerymod (PgSQL database)
	*/
class PgTblWznmMQuerymod : public TblWznmMQuerymod, public Sbecore::PgTable {

public:
	PgTblWznmMQuerymod();
	~PgTblWznmMQuerymod();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMQuerymod** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMQuerymod& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMQuerymod** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMQuerymod& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMQuerymod& rst);

	Sbecore::ubigint insertRec(WznmMQuerymod* rec);
	void insertRst(ListWznmMQuerymod& rst, bool transact = false);
	void updateRec(WznmMQuerymod* rec);
	void updateRst(ListWznmMQuerymod& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMQuerymod** rec);
	Sbecore::ubigint loadRefsByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByQry(Sbecore::ubigint qryRefWznmMQuery, const bool append, ListWznmMQuerymod& rst);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWznmMQuerymod& rst);
};
#endif

#endif
