/**
	* \file WznmAMVectorTitle.h
	* database access for table TblWznmAMVectorTitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMAMVECTORTITLE_H
#define WZNMAMVECTORTITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVAMVectorTitleType TblWznmAMVectorTitle::VecVType

/**
	* WznmAMVectorTitle: record of TblWznmAMVectorTitle
	*/
class WznmAMVectorTitle {

public:
	WznmAMVectorTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMVector;
	Sbecore::uint x1IxVType;
	Sbecore::ubigint x2RefWznmMLocale;
	std::string Title;

public:
	bool operator==(const WznmAMVectorTitle& comp);
	bool operator!=(const WznmAMVectorTitle& comp);
};

/**
	* ListWznmAMVectorTitle: recordset of TblWznmAMVectorTitle
	*/
class ListWznmAMVectorTitle {

public:
	ListWznmAMVectorTitle();
	ListWznmAMVectorTitle(const ListWznmAMVectorTitle& src);
	~ListWznmAMVectorTitle();

	void clear();
	unsigned int size() const;
	void append(WznmAMVectorTitle* rec);

	WznmAMVectorTitle* operator[](const Sbecore::uint ix);
	ListWznmAMVectorTitle& operator=(const ListWznmAMVectorTitle& src);
	bool operator==(const ListWznmAMVectorTitle& comp);
	bool operator!=(const ListWznmAMVectorTitle& comp);

public:
	std::vector<WznmAMVectorTitle*> nodes;
};

/**
	* TblWznmAMVectorTitle: C++ wrapper for table TblWznmAMVectorTitle
	*/
class TblWznmAMVectorTitle {

public:
	/**
		* VecVType (full: VecWznmVAMVectorTitleType)
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
	TblWznmAMVectorTitle();
	virtual ~TblWznmAMVectorTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMVectorTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMVectorTitle& rst);

	virtual Sbecore::ubigint insertRec(WznmAMVectorTitle* rec);
	Sbecore::ubigint insertNewRec(WznmAMVectorTitle** rec = NULL, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMVectorTitle& rst, WznmAMVectorTitle** rec = NULL, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::uint x1IxVType = 0, const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string Title = "");
	virtual void insertRst(ListWznmAMVectorTitle& rst, bool transact = false);
	virtual void updateRec(WznmAMVectorTitle* rec);
	virtual void updateRst(ListWznmAMVectorTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMVectorTitle** rec);
	virtual Sbecore::ubigint loadRefsByVec(Sbecore::ubigint refWznmMVector, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByVec(Sbecore::ubigint refWznmMVector, const bool append, ListWznmAMVectorTitle& rst);
	virtual bool loadTitByVecTypLoc(Sbecore::ubigint refWznmMVector, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMVectorTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMVectorTitle: C++ wrapper for table TblWznmAMVectorTitle (MySQL database)
	*/
class MyTblWznmAMVectorTitle : public TblWznmAMVectorTitle, public Sbecore::MyTable {

public:
	MyTblWznmAMVectorTitle();
	~MyTblWznmAMVectorTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMVectorTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMVectorTitle& rst);

	Sbecore::ubigint insertRec(WznmAMVectorTitle* rec);
	void insertRst(ListWznmAMVectorTitle& rst, bool transact = false);
	void updateRec(WznmAMVectorTitle* rec);
	void updateRst(ListWznmAMVectorTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMVectorTitle** rec);
	Sbecore::ubigint loadRefsByVec(Sbecore::ubigint refWznmMVector, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVec(Sbecore::ubigint refWznmMVector, const bool append, ListWznmAMVectorTitle& rst);
	bool loadTitByVecTypLoc(Sbecore::ubigint refWznmMVector, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMVectorTitle: C++ wrapper for table TblWznmAMVectorTitle (PgSQL database)
	*/
class PgTblWznmAMVectorTitle : public TblWznmAMVectorTitle, public Sbecore::PgTable {

public:
	PgTblWznmAMVectorTitle();
	~PgTblWznmAMVectorTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMVectorTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMVectorTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMVectorTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMVectorTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMVectorTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMVectorTitle& rst);

	Sbecore::ubigint insertRec(WznmAMVectorTitle* rec);
	void insertRst(ListWznmAMVectorTitle& rst, bool transact = false);
	void updateRec(WznmAMVectorTitle* rec);
	void updateRst(ListWznmAMVectorTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMVectorTitle** rec);
	Sbecore::ubigint loadRefsByVec(Sbecore::ubigint refWznmMVector, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVec(Sbecore::ubigint refWznmMVector, const bool append, ListWznmAMVectorTitle& rst);
	bool loadTitByVecTypLoc(Sbecore::ubigint refWznmMVector, Sbecore::uint x1IxVType, Sbecore::ubigint x2RefWznmMLocale, std::string& Title);
};
#endif

#endif

