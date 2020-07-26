/**
	* \file WznmAMRelationTitle.h
	* database access for table TblWznmAMRelationTitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMAMRELATIONTITLE_H
#define WZNMAMRELATIONTITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVAMRelationTitleType TblWznmAMRelationTitle::VecVType

/**
	* WznmAMRelationTitle: record of TblWznmAMRelationTitle
	*/
class WznmAMRelationTitle {

public:
	WznmAMRelationTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMRelation = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMRelation;
	Sbecore::uint x1IxVType;
	Sbecore::ubigint x2RefWznmMLocale;
	std::string Title;

public:
	bool operator==(const WznmAMRelationTitle& comp);
	bool operator!=(const WznmAMRelationTitle& comp);
};

/**
	* ListWznmAMRelationTitle: recordset of TblWznmAMRelationTitle
	*/
class ListWznmAMRelationTitle {

public:
	ListWznmAMRelationTitle();
	ListWznmAMRelationTitle(const ListWznmAMRelationTitle& src);
	~ListWznmAMRelationTitle();

	void clear();
	unsigned int size() const;
	void append(WznmAMRelationTitle* rec);

	WznmAMRelationTitle* operator[](const Sbecore::uint ix);
	ListWznmAMRelationTitle& operator=(const ListWznmAMRelationTitle& src);
	bool operator==(const ListWznmAMRelationTitle& comp);
	bool operator!=(const ListWznmAMRelationTitle& comp);

public:
	std::vector<WznmAMRelationTitle*> nodes;
};

/**
	* TblWznmAMRelationTitle: C++ wrapper for table TblWznmAMRelationTitle
	*/
class TblWznmAMRelationTitle {

public:
	/**
		* VecVType (full: VecWznmVAMRelationTitleType)
		*/
	class VecVType {

	public:
		static const Sbecore::uint FROMSNGSHORT = 1;
		static const Sbecore::uint FROMSNGFULL = 2;
		static const Sbecore::uint TOSNGSHORT = 3;
		static const Sbecore::uint TOSNGFULL = 4;
		static const Sbecore::uint FROMPLSHORT = 5;
		static const Sbecore::uint FROMPLFULL = 6;
		static const Sbecore::uint TOPLSHORT = 7;
		static const Sbecore::uint TOPLFULL = 8;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmAMRelationTitle();
	virtual ~TblWznmAMRelationTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMRelationTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMRelationTitle& rst);

	virtual Sbecore::ubigint insertRec(WznmAMRelationTitle* rec);
	Sbecore::ubigint insertNewRec(WznmAMRelationTitle** rec = NULL, const Sbecore::ubigint refWznmMRelation = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMRelationTitle& rst, WznmAMRelationTitle** rec = NULL, const Sbecore::ubigint refWznmMRelation = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string Title = "");
	virtual void insertRst(ListWznmAMRelationTitle& rst, bool transact = false);
	virtual void updateRec(WznmAMRelationTitle* rec);
	virtual void updateRst(ListWznmAMRelationTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMRelationTitle** rec);
	virtual Sbecore::ubigint loadRefsByRel(Sbecore::ubigint refWznmMRelation, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByRel(Sbecore::ubigint refWznmMRelation, const bool append, ListWznmAMRelationTitle& rst);
	virtual bool loadTitByRelTypLoc(Sbecore::ubigint refWznmMRelation, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMRelationTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMRelationTitle: C++ wrapper for table TblWznmAMRelationTitle (MySQL database)
	*/
class MyTblWznmAMRelationTitle : public TblWznmAMRelationTitle, public Sbecore::MyTable {

public:
	MyTblWznmAMRelationTitle();
	~MyTblWznmAMRelationTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMRelationTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMRelationTitle& rst);

	Sbecore::ubigint insertRec(WznmAMRelationTitle* rec);
	void insertRst(ListWznmAMRelationTitle& rst, bool transact = false);
	void updateRec(WznmAMRelationTitle* rec);
	void updateRst(ListWznmAMRelationTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMRelationTitle** rec);
	Sbecore::ubigint loadRefsByRel(Sbecore::ubigint refWznmMRelation, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRel(Sbecore::ubigint refWznmMRelation, const bool append, ListWznmAMRelationTitle& rst);
	bool loadTitByRelTypLoc(Sbecore::ubigint refWznmMRelation, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMRelationTitle: C++ wrapper for table TblWznmAMRelationTitle (PgSQL database)
	*/
class PgTblWznmAMRelationTitle : public TblWznmAMRelationTitle, public Sbecore::PgTable {

public:
	PgTblWznmAMRelationTitle();
	~PgTblWznmAMRelationTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMRelationTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMRelationTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMRelationTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMRelationTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMRelationTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMRelationTitle& rst);

	Sbecore::ubigint insertRec(WznmAMRelationTitle* rec);
	void insertRst(ListWznmAMRelationTitle& rst, bool transact = false);
	void updateRec(WznmAMRelationTitle* rec);
	void updateRst(ListWznmAMRelationTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMRelationTitle** rec);
	Sbecore::ubigint loadRefsByRel(Sbecore::ubigint refWznmMRelation, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRel(Sbecore::ubigint refWznmMRelation, const bool append, ListWznmAMRelationTitle& rst);
	bool loadTitByRelTypLoc(Sbecore::ubigint refWznmMRelation, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
};
#endif

#endif

