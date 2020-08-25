/**
	* \file WznmMSquawk.h
	* database access for table TblWznmMSquawk (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMMSQUAWK_H
#define WZNMMSQUAWK_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMSquawkRefTbl TblWznmMSquawk::VecVRefTbl

/**
	* WznmMSquawk: record of TblWznmMSquawk
	*/
class WznmMSquawk {

public:
	WznmMSquawk(const Sbecore::ubigint ref = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const std::string Example = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::ubigint refJTitle;
	std::string Title;
	std::string Example;

public:
	bool operator==(const WznmMSquawk& comp);
	bool operator!=(const WznmMSquawk& comp);
};

/**
	* ListWznmMSquawk: recordset of TblWznmMSquawk
	*/
class ListWznmMSquawk {

public:
	ListWznmMSquawk();
	ListWznmMSquawk(const ListWznmMSquawk& src);
	~ListWznmMSquawk();

	void clear();
	unsigned int size() const;
	void append(WznmMSquawk* rec);

	WznmMSquawk* operator[](const Sbecore::uint ix);
	ListWznmMSquawk& operator=(const ListWznmMSquawk& src);
	bool operator==(const ListWznmMSquawk& comp);
	bool operator!=(const ListWznmMSquawk& comp);

public:
	std::vector<WznmMSquawk*> nodes;
};

/**
	* TblWznmMSquawk: C++ wrapper for table TblWznmMSquawk
	*/
class TblWznmMSquawk {

public:
	/**
		* VecVRefTbl (full: VecWznmVMSquawkRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint OPK = 1;
		static const Sbecore::uint OPX = 2;
		static const Sbecore::uint SGE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMSquawk();
	virtual ~TblWznmMSquawk();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMSquawk** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSquawk& rst);

	virtual Sbecore::ubigint insertRec(WznmMSquawk* rec);
	Sbecore::ubigint insertNewRec(WznmMSquawk** rec = NULL, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const std::string Example = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMSquawk& rst, WznmMSquawk** rec = NULL, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const std::string Example = "");
	virtual void insertRst(ListWznmMSquawk& rst, bool transact = false);
	virtual void updateRec(WznmMSquawk* rec);
	virtual void updateRst(ListWznmMSquawk& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMSquawk** rec);
	virtual bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMSquawk** rec);
	virtual Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMSquawk& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMSquawk: C++ wrapper for table TblWznmMSquawk (MySQL database)
	*/
class MyTblWznmMSquawk : public TblWznmMSquawk, public Sbecore::MyTable {

public:
	MyTblWznmMSquawk();
	~MyTblWznmMSquawk();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMSquawk** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSquawk& rst);

	Sbecore::ubigint insertRec(WznmMSquawk* rec);
	void insertRst(ListWznmMSquawk& rst, bool transact = false);
	void updateRec(WznmMSquawk* rec);
	void updateRst(ListWznmMSquawk& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMSquawk** rec);
	bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMSquawk** rec);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMSquawk: C++ wrapper for table TblWznmMSquawk (PgSQL database)
	*/
class PgTblWznmMSquawk : public TblWznmMSquawk, public Sbecore::PgTable {

public:
	PgTblWznmMSquawk();
	~PgTblWznmMSquawk();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMSquawk** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMSquawk& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMSquawk** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMSquawk** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSquawk& rst);

	Sbecore::ubigint insertRec(WznmMSquawk* rec);
	void insertRst(ListWznmMSquawk& rst, bool transact = false);
	void updateRec(WznmMSquawk* rec);
	void updateRst(ListWznmMSquawk& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMSquawk** rec);
	bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMSquawk** rec);
	Sbecore::ubigint loadRefsByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif

