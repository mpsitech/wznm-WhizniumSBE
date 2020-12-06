/**
	* \file WznmMOppack.h
	* database access for table TblWznmMOppack (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMOPPACK_H
#define WZNMMOPPACK_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMOppackBasetype TblWznmMOppack::VecVBasetype

/**
	* WznmMOppack: record of TblWznmMOppack
	*/
class WznmMOppack {

public:
	WznmMOppack(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint refWznmMSquawk = 0, const std::string sref = "", const std::string Title = "", const bool Shrdat = false, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmMVersion;
	Sbecore::ubigint refWznmMSquawk;
	std::string sref;
	std::string Title;
	bool Shrdat;
	std::string Comment;

public:
	bool operator==(const WznmMOppack& comp);
	bool operator!=(const WznmMOppack& comp);
};

/**
	* ListWznmMOppack: recordset of TblWznmMOppack
	*/
class ListWznmMOppack {

public:
	ListWznmMOppack();
	ListWznmMOppack(const ListWznmMOppack& src);
	~ListWznmMOppack();

	void clear();
	unsigned int size() const;
	void append(WznmMOppack* rec);

	WznmMOppack* operator[](const Sbecore::uint ix);
	ListWznmMOppack& operator=(const ListWznmMOppack& src);
	bool operator==(const ListWznmMOppack& comp);
	bool operator!=(const ListWznmMOppack& comp);

public:
	std::vector<WznmMOppack*> nodes;
};

/**
	* TblWznmMOppack: C++ wrapper for table TblWznmMOppack
	*/
class TblWznmMOppack {

public:
	/**
		* VecVBasetype (full: VecWznmVMOppackBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint CUST = 1;
		static const Sbecore::uint STAT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMOppack();
	virtual ~TblWznmMOppack();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMOppack** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMOppack& rst);

	virtual Sbecore::ubigint insertRec(WznmMOppack* rec);
	Sbecore::ubigint insertNewRec(WznmMOppack** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint refWznmMSquawk = 0, const std::string sref = "", const std::string Title = "", const bool Shrdat = false, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMOppack& rst, WznmMOppack** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint refWznmMSquawk = 0, const std::string sref = "", const std::string Title = "", const bool Shrdat = false, const std::string Comment = "");
	virtual void insertRst(ListWznmMOppack& rst, bool transact = false);
	virtual void updateRec(WznmMOppack* rec);
	virtual void updateRst(ListWznmMOppack& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMOppack** rec);
	virtual bool loadRecBySqk(Sbecore::ubigint refWznmMSquawk, WznmMOppack** rec);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMOppack& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMOppack& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMOppack: C++ wrapper for table TblWznmMOppack (MySQL database)
	*/
class MyTblWznmMOppack : public TblWznmMOppack, public Sbecore::MyTable {

public:
	MyTblWznmMOppack();
	~MyTblWznmMOppack();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMOppack& rst);

	Sbecore::ubigint insertRec(WznmMOppack* rec);
	void insertRst(ListWznmMOppack& rst, bool transact = false);
	void updateRec(WznmMOppack* rec);
	void updateRst(ListWznmMOppack& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMOppack** rec);
	bool loadRecBySqk(Sbecore::ubigint refWznmMSquawk, WznmMOppack** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMOppack& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMOppack: C++ wrapper for table TblWznmMOppack (PgSQL database)
	*/
class PgTblWznmMOppack : public TblWznmMOppack, public Sbecore::PgTable {

public:
	PgTblWznmMOppack();
	~PgTblWznmMOppack();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMOppack** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMOppack& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMOppack** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMOppack& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMOppack** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMOppack& rst);

	Sbecore::ubigint insertRec(WznmMOppack* rec);
	void insertRst(ListWznmMOppack& rst, bool transact = false);
	void updateRec(WznmMOppack* rec);
	void updateRst(ListWznmMOppack& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMOppack** rec);
	bool loadRecBySqk(Sbecore::ubigint refWznmMSquawk, WznmMOppack** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMOppack& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
