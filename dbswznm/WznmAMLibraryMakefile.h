/**
	* \file WznmAMLibraryMakefile.h
	* database access for table TblWznmAMLibraryMakefile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMAMLIBRARYMAKEFILE_H
#define WZNMAMLIBRARYMAKEFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVAMLibraryMakefileRefTbl TblWznmAMLibraryMakefile::VecVRefTbl

/**
	* WznmAMLibraryMakefile: record of TblWznmAMLibraryMakefile
	*/
class WznmAMLibraryMakefile {

public:
	WznmAMLibraryMakefile(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMLibrary = 0, const Sbecore::uint x1RefIxVTbl = 0, const Sbecore::ubigint x1RefUref = 0, const std::string x2SrefKTag = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMLibrary;
	Sbecore::uint x1RefIxVTbl;
	Sbecore::ubigint x1RefUref;
	std::string x2SrefKTag;
	std::string Val;

public:
	bool operator==(const WznmAMLibraryMakefile& comp);
	bool operator!=(const WznmAMLibraryMakefile& comp);
};

/**
	* ListWznmAMLibraryMakefile: recordset of TblWznmAMLibraryMakefile
	*/
class ListWznmAMLibraryMakefile {

public:
	ListWznmAMLibraryMakefile();
	ListWznmAMLibraryMakefile(const ListWznmAMLibraryMakefile& src);
	~ListWznmAMLibraryMakefile();

	void clear();
	unsigned int size() const;
	void append(WznmAMLibraryMakefile* rec);

	WznmAMLibraryMakefile* operator[](const Sbecore::uint ix);
	ListWznmAMLibraryMakefile& operator=(const ListWznmAMLibraryMakefile& src);
	bool operator==(const ListWznmAMLibraryMakefile& comp);
	bool operator!=(const ListWznmAMLibraryMakefile& comp);

public:
	std::vector<WznmAMLibraryMakefile*> nodes;
};

/**
	* TblWznmAMLibraryMakefile: C++ wrapper for table TblWznmAMLibraryMakefile
	*/
class TblWznmAMLibraryMakefile {

public:
	/**
		* VecVRefTbl (full: VecWznmVAMLibraryMakefileRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint MCH = 2;
		static const Sbecore::uint MTY = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmAMLibraryMakefile();
	virtual ~TblWznmAMLibraryMakefile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMLibraryMakefile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMLibraryMakefile& rst);

	virtual Sbecore::ubigint insertRec(WznmAMLibraryMakefile* rec);
	Sbecore::ubigint insertNewRec(WznmAMLibraryMakefile** rec = NULL, const Sbecore::ubigint refWznmMLibrary = 0, const Sbecore::uint x1RefIxVTbl = 0, const Sbecore::ubigint x1RefUref = 0, const std::string x2SrefKTag = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMLibraryMakefile& rst, WznmAMLibraryMakefile** rec = NULL, const Sbecore::ubigint refWznmMLibrary = 0, const Sbecore::uint x1RefIxVTbl = 0, const Sbecore::ubigint x1RefUref = 0, const std::string x2SrefKTag = "", const std::string Val = "");
	virtual void insertRst(ListWznmAMLibraryMakefile& rst, bool transact = false);
	virtual void updateRec(WznmAMLibraryMakefile* rec);
	virtual void updateRst(ListWznmAMLibraryMakefile& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMLibraryMakefile** rec);
	virtual Sbecore::ubigint loadRefsByLib(Sbecore::ubigint refWznmMLibrary, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByLib(Sbecore::ubigint refWznmMLibrary, const bool append, ListWznmAMLibraryMakefile& rst);
	virtual Sbecore::ubigint loadRstByLibRetReu(Sbecore::ubigint refWznmMLibrary, Sbecore::uint x1RefIxVTbl, Sbecore::ubigint x1RefUref, const bool append, ListWznmAMLibraryMakefile& rst);
	virtual bool loadValByLibRetReuTag(Sbecore::ubigint refWznmMLibrary, Sbecore::uint x1RefIxVTbl, Sbecore::ubigint x1RefUref, std::string x2SrefKTag, std::string& Val);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMLibraryMakefile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMLibraryMakefile: C++ wrapper for table TblWznmAMLibraryMakefile (MySQL database)
	*/
class MyTblWznmAMLibraryMakefile : public TblWznmAMLibraryMakefile, public Sbecore::MyTable {

public:
	MyTblWznmAMLibraryMakefile();
	~MyTblWznmAMLibraryMakefile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMLibraryMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMLibraryMakefile& rst);

	Sbecore::ubigint insertRec(WznmAMLibraryMakefile* rec);
	void insertRst(ListWznmAMLibraryMakefile& rst, bool transact = false);
	void updateRec(WznmAMLibraryMakefile* rec);
	void updateRst(ListWznmAMLibraryMakefile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMLibraryMakefile** rec);
	Sbecore::ubigint loadRefsByLib(Sbecore::ubigint refWznmMLibrary, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByLib(Sbecore::ubigint refWznmMLibrary, const bool append, ListWznmAMLibraryMakefile& rst);
	Sbecore::ubigint loadRstByLibRetReu(Sbecore::ubigint refWznmMLibrary, Sbecore::uint x1RefIxVTbl, Sbecore::ubigint x1RefUref, const bool append, ListWznmAMLibraryMakefile& rst);
	bool loadValByLibRetReuTag(Sbecore::ubigint refWznmMLibrary, Sbecore::uint x1RefIxVTbl, Sbecore::ubigint x1RefUref, std::string x2SrefKTag, std::string& Val);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMLibraryMakefile: C++ wrapper for table TblWznmAMLibraryMakefile (PgSQL database)
	*/
class PgTblWznmAMLibraryMakefile : public TblWznmAMLibraryMakefile, public Sbecore::PgTable {

public:
	PgTblWznmAMLibraryMakefile();
	~PgTblWznmAMLibraryMakefile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMLibraryMakefile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMLibraryMakefile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMLibraryMakefile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMLibraryMakefile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMLibraryMakefile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMLibraryMakefile& rst);

	Sbecore::ubigint insertRec(WznmAMLibraryMakefile* rec);
	void insertRst(ListWznmAMLibraryMakefile& rst, bool transact = false);
	void updateRec(WznmAMLibraryMakefile* rec);
	void updateRst(ListWznmAMLibraryMakefile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMLibraryMakefile** rec);
	Sbecore::ubigint loadRefsByLib(Sbecore::ubigint refWznmMLibrary, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByLib(Sbecore::ubigint refWznmMLibrary, const bool append, ListWznmAMLibraryMakefile& rst);
	Sbecore::ubigint loadRstByLibRetReu(Sbecore::ubigint refWznmMLibrary, Sbecore::uint x1RefIxVTbl, Sbecore::ubigint x1RefUref, const bool append, ListWznmAMLibraryMakefile& rst);
	bool loadValByLibRetReuTag(Sbecore::ubigint refWznmMLibrary, Sbecore::uint x1RefIxVTbl, Sbecore::ubigint x1RefUref, std::string x2SrefKTag, std::string& Val);
};
#endif

#endif

