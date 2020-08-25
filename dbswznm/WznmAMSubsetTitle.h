/**
	* \file WznmAMSubsetTitle.h
	* database access for table TblWznmAMSubsetTitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMAMSUBSETTITLE_H
#define WZNMAMSUBSETTITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVAMSubsetTitleType TblWznmAMSubsetTitle::VecVType

/**
	* WznmAMSubsetTitle: record of TblWznmAMSubsetTitle
	*/
class WznmAMSubsetTitle {

public:
	WznmAMSubsetTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMSubset = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const Sbecore::uint ixWznmVGender = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMSubset;
	Sbecore::uint x1IxVType;
	Sbecore::ubigint x2RefWznmMLocale;
	Sbecore::uint ixWznmVGender;
	std::string Title;

public:
	bool operator==(const WznmAMSubsetTitle& comp);
	bool operator!=(const WznmAMSubsetTitle& comp);
};

/**
	* ListWznmAMSubsetTitle: recordset of TblWznmAMSubsetTitle
	*/
class ListWznmAMSubsetTitle {

public:
	ListWznmAMSubsetTitle();
	ListWznmAMSubsetTitle(const ListWznmAMSubsetTitle& src);
	~ListWznmAMSubsetTitle();

	void clear();
	unsigned int size() const;
	void append(WznmAMSubsetTitle* rec);

	WznmAMSubsetTitle* operator[](const Sbecore::uint ix);
	ListWznmAMSubsetTitle& operator=(const ListWznmAMSubsetTitle& src);
	bool operator==(const ListWznmAMSubsetTitle& comp);
	bool operator!=(const ListWznmAMSubsetTitle& comp);

public:
	std::vector<WznmAMSubsetTitle*> nodes;
};

/**
	* TblWznmAMSubsetTitle: C++ wrapper for table TblWznmAMSubsetTitle
	*/
class TblWznmAMSubsetTitle {

public:
	/**
		* VecVType (full: VecWznmVAMSubsetTitleType)
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
	TblWznmAMSubsetTitle();
	virtual ~TblWznmAMSubsetTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMSubsetTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMSubsetTitle& rst);

	virtual Sbecore::ubigint insertRec(WznmAMSubsetTitle* rec);
	Sbecore::ubigint insertNewRec(WznmAMSubsetTitle** rec = NULL, const Sbecore::ubigint refWznmMSubset = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const Sbecore::uint ixWznmVGender = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMSubsetTitle& rst, WznmAMSubsetTitle** rec = NULL, const Sbecore::ubigint refWznmMSubset = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const Sbecore::uint ixWznmVGender = 0, const std::string Title = "");
	virtual void insertRst(ListWznmAMSubsetTitle& rst, bool transact = false);
	virtual void updateRec(WznmAMSubsetTitle* rec);
	virtual void updateRst(ListWznmAMSubsetTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMSubsetTitle** rec);
	virtual Sbecore::ubigint loadRefsBySbs(Sbecore::ubigint refWznmMSubset, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstBySbs(Sbecore::ubigint refWznmMSubset, const bool append, ListWznmAMSubsetTitle& rst);
	virtual bool loadTitBySbsTypLoc(Sbecore::ubigint refWznmMSubset, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMSubsetTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMSubsetTitle: C++ wrapper for table TblWznmAMSubsetTitle (MySQL database)
	*/
class MyTblWznmAMSubsetTitle : public TblWznmAMSubsetTitle, public Sbecore::MyTable {

public:
	MyTblWznmAMSubsetTitle();
	~MyTblWznmAMSubsetTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMSubsetTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMSubsetTitle& rst);

	Sbecore::ubigint insertRec(WznmAMSubsetTitle* rec);
	void insertRst(ListWznmAMSubsetTitle& rst, bool transact = false);
	void updateRec(WznmAMSubsetTitle* rec);
	void updateRst(ListWznmAMSubsetTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMSubsetTitle** rec);
	Sbecore::ubigint loadRefsBySbs(Sbecore::ubigint refWznmMSubset, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySbs(Sbecore::ubigint refWznmMSubset, const bool append, ListWznmAMSubsetTitle& rst);
	bool loadTitBySbsTypLoc(Sbecore::ubigint refWznmMSubset, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMSubsetTitle: C++ wrapper for table TblWznmAMSubsetTitle (PgSQL database)
	*/
class PgTblWznmAMSubsetTitle : public TblWznmAMSubsetTitle, public Sbecore::PgTable {

public:
	PgTblWznmAMSubsetTitle();
	~PgTblWznmAMSubsetTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMSubsetTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMSubsetTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMSubsetTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMSubsetTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMSubsetTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMSubsetTitle& rst);

	Sbecore::ubigint insertRec(WznmAMSubsetTitle* rec);
	void insertRst(ListWznmAMSubsetTitle& rst, bool transact = false);
	void updateRec(WznmAMSubsetTitle* rec);
	void updateRst(ListWznmAMSubsetTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMSubsetTitle** rec);
	Sbecore::ubigint loadRefsBySbs(Sbecore::ubigint refWznmMSubset, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySbs(Sbecore::ubigint refWznmMSubset, const bool append, ListWznmAMSubsetTitle& rst);
	bool loadTitBySbsTypLoc(Sbecore::ubigint refWznmMSubset, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
};
#endif

#endif

