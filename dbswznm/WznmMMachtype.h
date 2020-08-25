/**
	* \file WznmMMachtype.h
	* database access for table TblWznmMMachtype (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMMMACHTYPE_H
#define WZNMMMACHTYPE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMMachtypeArch TblWznmMMachtype::VecVArch

/**
	* WznmMMachtype: record of TblWznmMMachtype
	*/
class WznmMMachtype {

public:
	WznmMMachtype(const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVArch = 0, const std::string srefKOs = "", const Sbecore::ubigint cchRefWznmMMachine = 0, const std::string srefKPkgmgr = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVArch;
	std::string srefKOs;
	Sbecore::ubigint cchRefWznmMMachine;
	std::string srefKPkgmgr;
	std::string Comment;

public:
	bool operator==(const WznmMMachtype& comp);
	bool operator!=(const WznmMMachtype& comp);
};

/**
	* ListWznmMMachtype: recordset of TblWznmMMachtype
	*/
class ListWznmMMachtype {

public:
	ListWznmMMachtype();
	ListWznmMMachtype(const ListWznmMMachtype& src);
	~ListWznmMMachtype();

	void clear();
	unsigned int size() const;
	void append(WznmMMachtype* rec);

	WznmMMachtype* operator[](const Sbecore::uint ix);
	ListWznmMMachtype& operator=(const ListWznmMMachtype& src);
	bool operator==(const ListWznmMMachtype& comp);
	bool operator!=(const ListWznmMMachtype& comp);

public:
	std::vector<WznmMMachtype*> nodes;
};

/**
	* TblWznmMMachtype: C++ wrapper for table TblWznmMMachtype
	*/
class TblWznmMMachtype {

public:
	/**
		* VecVArch (full: VecWznmVMMachtypeArch)
		*/
	class VecVArch {

	public:
		static const Sbecore::uint ARMV7 = 1;
		static const Sbecore::uint ARMV8 = 2;
		static const Sbecore::uint X86_64 = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMMachtype();
	virtual ~TblWznmMMachtype();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMMachtype** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMMachtype& rst);

	virtual Sbecore::ubigint insertRec(WznmMMachtype* rec);
	Sbecore::ubigint insertNewRec(WznmMMachtype** rec = NULL, const std::string sref = "", const Sbecore::uint ixVArch = 0, const std::string srefKOs = "", const Sbecore::ubigint cchRefWznmMMachine = 0, const std::string srefKPkgmgr = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMMachtype& rst, WznmMMachtype** rec = NULL, const std::string sref = "", const Sbecore::uint ixVArch = 0, const std::string srefKOs = "", const Sbecore::ubigint cchRefWznmMMachine = 0, const std::string srefKPkgmgr = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMMachtype& rst, bool transact = false);
	virtual void updateRec(WznmMMachtype* rec);
	virtual void updateRst(ListWznmMMachtype& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMMachtype** rec);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMMachtype& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMMachtype: C++ wrapper for table TblWznmMMachtype (MySQL database)
	*/
class MyTblWznmMMachtype : public TblWznmMMachtype, public Sbecore::MyTable {

public:
	MyTblWznmMMachtype();
	~MyTblWznmMMachtype();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMMachtype** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMMachtype& rst);

	Sbecore::ubigint insertRec(WznmMMachtype* rec);
	void insertRst(ListWznmMMachtype& rst, bool transact = false);
	void updateRec(WznmMMachtype* rec);
	void updateRst(ListWznmMMachtype& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMMachtype** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMMachtype: C++ wrapper for table TblWznmMMachtype (PgSQL database)
	*/
class PgTblWznmMMachtype : public TblWznmMMachtype, public Sbecore::PgTable {

public:
	PgTblWznmMMachtype();
	~PgTblWznmMMachtype();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMMachtype** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMMachtype& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMMachtype** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMMachtype** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMMachtype& rst);

	Sbecore::ubigint insertRec(WznmMMachtype* rec);
	void insertRst(ListWznmMMachtype& rst, bool transact = false);
	void updateRec(WznmMMachtype* rec);
	void updateRst(ListWznmMMachtype& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMMachtype** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

