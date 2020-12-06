/**
	* \file WznmAMTableTitle.h
	* database access for table TblWznmAMTableTitle (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMTABLETITLE_H
#define WZNMAMTABLETITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVAMTableTitleType TblWznmAMTableTitle::VecVType

/**
	* WznmAMTableTitle: record of TblWznmAMTableTitle
	*/
class WznmAMTableTitle {

public:
	WznmAMTableTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const Sbecore::uint ixWznmVGender = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMTable;
	Sbecore::uint x1IxVType;
	Sbecore::ubigint x2RefWznmMLocale;
	Sbecore::uint ixWznmVGender;
	std::string Title;

public:
	bool operator==(const WznmAMTableTitle& comp);
	bool operator!=(const WznmAMTableTitle& comp);
};

/**
	* ListWznmAMTableTitle: recordset of TblWznmAMTableTitle
	*/
class ListWznmAMTableTitle {

public:
	ListWznmAMTableTitle();
	ListWznmAMTableTitle(const ListWznmAMTableTitle& src);
	~ListWznmAMTableTitle();

	void clear();
	unsigned int size() const;
	void append(WznmAMTableTitle* rec);

	WznmAMTableTitle* operator[](const Sbecore::uint ix);
	ListWznmAMTableTitle& operator=(const ListWznmAMTableTitle& src);
	bool operator==(const ListWznmAMTableTitle& comp);
	bool operator!=(const ListWznmAMTableTitle& comp);

public:
	std::vector<WznmAMTableTitle*> nodes;
};

/**
	* TblWznmAMTableTitle: C++ wrapper for table TblWznmAMTableTitle
	*/
class TblWznmAMTableTitle {

public:
	/**
		* VecVType (full: VecWznmVAMTableTitleType)
		*/
	class VecVType {

	public:
		static const Sbecore::uint SNGSHORT = 1;
		static const Sbecore::uint SNGFULL = 2;
		static const Sbecore::uint PLFULL = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmAMTableTitle();
	virtual ~TblWznmAMTableTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMTableTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMTableTitle& rst);

	virtual Sbecore::ubigint insertRec(WznmAMTableTitle* rec);
	Sbecore::ubigint insertNewRec(WznmAMTableTitle** rec = NULL, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const Sbecore::uint ixWznmVGender = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMTableTitle& rst, WznmAMTableTitle** rec = NULL, const Sbecore::ubigint refWznmMTable = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const Sbecore::uint ixWznmVGender = 0, const std::string Title = "");
	virtual void insertRst(ListWznmAMTableTitle& rst, bool transact = false);
	virtual void updateRec(WznmAMTableTitle* rec);
	virtual void updateRst(ListWznmAMTableTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMTableTitle** rec);
	virtual Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmAMTableTitle& rst);
	virtual bool loadTitByTblTypLoc(Sbecore::ubigint refWznmMTable, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMTableTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMTableTitle: C++ wrapper for table TblWznmAMTableTitle (MySQL database)
	*/
class MyTblWznmAMTableTitle : public TblWznmAMTableTitle, public Sbecore::MyTable {

public:
	MyTblWznmAMTableTitle();
	~MyTblWznmAMTableTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMTableTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMTableTitle& rst);

	Sbecore::ubigint insertRec(WznmAMTableTitle* rec);
	void insertRst(ListWznmAMTableTitle& rst, bool transact = false);
	void updateRec(WznmAMTableTitle* rec);
	void updateRst(ListWznmAMTableTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMTableTitle** rec);
	Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmAMTableTitle& rst);
	bool loadTitByTblTypLoc(Sbecore::ubigint refWznmMTable, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMTableTitle: C++ wrapper for table TblWznmAMTableTitle (PgSQL database)
	*/
class PgTblWznmAMTableTitle : public TblWznmAMTableTitle, public Sbecore::PgTable {

public:
	PgTblWznmAMTableTitle();
	~PgTblWznmAMTableTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMTableTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMTableTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMTableTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMTableTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMTableTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMTableTitle& rst);

	Sbecore::ubigint insertRec(WznmAMTableTitle* rec);
	void insertRst(ListWznmAMTableTitle& rst, bool transact = false);
	void updateRec(WznmAMTableTitle* rec);
	void updateRst(ListWznmAMTableTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMTableTitle** rec);
	Sbecore::ubigint loadRefsByTbl(Sbecore::ubigint refWznmMTable, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTbl(Sbecore::ubigint refWznmMTable, const bool append, ListWznmAMTableTitle& rst);
	bool loadTitByTblTypLoc(Sbecore::ubigint refWznmMTable, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
};
#endif

#endif
