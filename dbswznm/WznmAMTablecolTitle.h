/**
	* \file WznmAMTablecolTitle.h
	* database access for table TblWznmAMTablecolTitle (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMTABLECOLTITLE_H
#define WZNMAMTABLECOLTITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVAMTablecolTitleType TblWznmAMTablecolTitle::VecVType

/**
	* WznmAMTablecolTitle: record of TblWznmAMTablecolTitle
	*/
class WznmAMTablecolTitle {

public:
	WznmAMTablecolTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMTablecol = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMTablecol;
	Sbecore::uint x1IxVType;
	Sbecore::ubigint x2RefWznmMLocale;
	std::string Title;

public:
	bool operator==(const WznmAMTablecolTitle& comp);
	bool operator!=(const WznmAMTablecolTitle& comp);
};

/**
	* ListWznmAMTablecolTitle: recordset of TblWznmAMTablecolTitle
	*/
class ListWznmAMTablecolTitle {

public:
	ListWznmAMTablecolTitle();
	ListWznmAMTablecolTitle(const ListWznmAMTablecolTitle& src);
	~ListWznmAMTablecolTitle();

	void clear();
	unsigned int size() const;
	void append(WznmAMTablecolTitle* rec);

	WznmAMTablecolTitle* operator[](const Sbecore::uint ix);
	ListWznmAMTablecolTitle& operator=(const ListWznmAMTablecolTitle& src);
	bool operator==(const ListWznmAMTablecolTitle& comp);
	bool operator!=(const ListWznmAMTablecolTitle& comp);

public:
	std::vector<WznmAMTablecolTitle*> nodes;
};

/**
	* TblWznmAMTablecolTitle: C++ wrapper for table TblWznmAMTablecolTitle
	*/
class TblWznmAMTablecolTitle {

public:
	/**
		* VecVType (full: VecWznmVAMTablecolTitleType)
		*/
	class VecVType {

	public:
		static const Sbecore::uint SHORT = 1;
		static const Sbecore::uint FULL = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmAMTablecolTitle();
	virtual ~TblWznmAMTablecolTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMTablecolTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMTablecolTitle& rst);

	virtual Sbecore::ubigint insertRec(WznmAMTablecolTitle* rec);
	Sbecore::ubigint insertNewRec(WznmAMTablecolTitle** rec = NULL, const Sbecore::ubigint refWznmMTablecol = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMTablecolTitle& rst, WznmAMTablecolTitle** rec = NULL, const Sbecore::ubigint refWznmMTablecol = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string Title = "");
	virtual void insertRst(ListWznmAMTablecolTitle& rst, bool transact = false);
	virtual void updateRec(WznmAMTablecolTitle* rec);
	virtual void updateRst(ListWznmAMTablecolTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMTablecolTitle** rec);
	virtual Sbecore::ubigint loadRefsByTco(Sbecore::ubigint refWznmMTablecol, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByTco(Sbecore::ubigint refWznmMTablecol, const bool append, ListWznmAMTablecolTitle& rst);
	virtual bool loadTitByTcoTypLoc(Sbecore::ubigint refWznmMTablecol, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMTablecolTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMTablecolTitle: C++ wrapper for table TblWznmAMTablecolTitle (MySQL database)
	*/
class MyTblWznmAMTablecolTitle : public TblWznmAMTablecolTitle, public Sbecore::MyTable {

public:
	MyTblWznmAMTablecolTitle();
	~MyTblWznmAMTablecolTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMTablecolTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMTablecolTitle& rst);

	Sbecore::ubigint insertRec(WznmAMTablecolTitle* rec);
	void insertRst(ListWznmAMTablecolTitle& rst, bool transact = false);
	void updateRec(WznmAMTablecolTitle* rec);
	void updateRst(ListWznmAMTablecolTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMTablecolTitle** rec);
	Sbecore::ubigint loadRefsByTco(Sbecore::ubigint refWznmMTablecol, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTco(Sbecore::ubigint refWznmMTablecol, const bool append, ListWznmAMTablecolTitle& rst);
	bool loadTitByTcoTypLoc(Sbecore::ubigint refWznmMTablecol, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMTablecolTitle: C++ wrapper for table TblWznmAMTablecolTitle (PgSQL database)
	*/
class PgTblWznmAMTablecolTitle : public TblWznmAMTablecolTitle, public Sbecore::PgTable {

public:
	PgTblWznmAMTablecolTitle();
	~PgTblWznmAMTablecolTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMTablecolTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMTablecolTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMTablecolTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMTablecolTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMTablecolTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMTablecolTitle& rst);

	Sbecore::ubigint insertRec(WznmAMTablecolTitle* rec);
	void insertRst(ListWznmAMTablecolTitle& rst, bool transact = false);
	void updateRec(WznmAMTablecolTitle* rec);
	void updateRst(ListWznmAMTablecolTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMTablecolTitle** rec);
	Sbecore::ubigint loadRefsByTco(Sbecore::ubigint refWznmMTablecol, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByTco(Sbecore::ubigint refWznmMTablecol, const bool append, ListWznmAMTablecolTitle& rst);
	bool loadTitByTcoTypLoc(Sbecore::ubigint refWznmMTablecol, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
};
#endif

#endif
