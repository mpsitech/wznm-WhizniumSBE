/**
	* \file WznmJAVKeylistKey.h
	* database access for table TblWznmJAVKeylistKey (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMJAVKEYLISTKEY_H
#define WZNMJAVKEYLISTKEY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJAVKeylistKey: record of TblWznmJAVKeylistKey
	*/
class WznmJAVKeylistKey {

public:
	WznmJAVKeylistKey(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmAVKeylistKey = 0, const Sbecore::uint x1IxWznmVLocale = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmAVKeylistKey;
	Sbecore::uint x1IxWznmVLocale;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WznmJAVKeylistKey& comp);
	bool operator!=(const WznmJAVKeylistKey& comp);
};

/**
	* ListWznmJAVKeylistKey: recordset of TblWznmJAVKeylistKey
	*/
class ListWznmJAVKeylistKey {

public:
	ListWznmJAVKeylistKey();
	ListWznmJAVKeylistKey(const ListWznmJAVKeylistKey& src);
	~ListWznmJAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(WznmJAVKeylistKey* rec);

	WznmJAVKeylistKey* operator[](const Sbecore::uint ix);
	ListWznmJAVKeylistKey& operator=(const ListWznmJAVKeylistKey& src);
	bool operator==(const ListWznmJAVKeylistKey& comp);
	bool operator!=(const ListWznmJAVKeylistKey& comp);

public:
	std::vector<WznmJAVKeylistKey*> nodes;
};

/**
	* TblWznmJAVKeylistKey: C++ wrapper for table TblWznmJAVKeylistKey
	*/
class TblWznmJAVKeylistKey {

public:

public:
	TblWznmJAVKeylistKey();
	virtual ~TblWznmJAVKeylistKey();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJAVKeylistKey& rst);

	virtual Sbecore::ubigint insertRec(WznmJAVKeylistKey* rec);
	Sbecore::ubigint insertNewRec(WznmJAVKeylistKey** rec = NULL, const Sbecore::ubigint refWznmAVKeylistKey = 0, const Sbecore::uint x1IxWznmVLocale = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJAVKeylistKey& rst, WznmJAVKeylistKey** rec = NULL, const Sbecore::ubigint refWznmAVKeylistKey = 0, const Sbecore::uint x1IxWznmVLocale = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWznmJAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(WznmJAVKeylistKey* rec);
	virtual void updateRst(ListWznmJAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJAVKeylistKey** rec);
	virtual bool loadRecByKlkLcl(Sbecore::ubigint refWznmAVKeylistKey, Sbecore::uint x1IxWznmVLocale, WznmJAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refWznmAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refWznmAVKeylistKey, const bool append, ListWznmJAVKeylistKey& rst);
	virtual bool loadTitByKlkLcl(Sbecore::ubigint refWznmAVKeylistKey, Sbecore::uint x1IxWznmVLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJAVKeylistKey& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJAVKeylistKey: C++ wrapper for table TblWznmJAVKeylistKey (MySQL database)
	*/
class MyTblWznmJAVKeylistKey : public TblWznmJAVKeylistKey, public Sbecore::MyTable {

public:
	MyTblWznmJAVKeylistKey();
	~MyTblWznmJAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WznmJAVKeylistKey* rec);
	void insertRst(ListWznmJAVKeylistKey& rst, bool transact = false);
	void updateRec(WznmJAVKeylistKey* rec);
	void updateRst(ListWznmJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJAVKeylistKey** rec);
	bool loadRecByKlkLcl(Sbecore::ubigint refWznmAVKeylistKey, Sbecore::uint x1IxWznmVLocale, WznmJAVKeylistKey** rec);
	Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refWznmAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refWznmAVKeylistKey, const bool append, ListWznmJAVKeylistKey& rst);
	bool loadTitByKlkLcl(Sbecore::ubigint refWznmAVKeylistKey, Sbecore::uint x1IxWznmVLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJAVKeylistKey: C++ wrapper for table TblWznmJAVKeylistKey (PgSQL database)
	*/
class PgTblWznmJAVKeylistKey : public TblWznmJAVKeylistKey, public Sbecore::PgTable {

public:
	PgTblWznmJAVKeylistKey();
	~PgTblWznmJAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJAVKeylistKey** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJAVKeylistKey& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJAVKeylistKey** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJAVKeylistKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WznmJAVKeylistKey* rec);
	void insertRst(ListWznmJAVKeylistKey& rst, bool transact = false);
	void updateRec(WznmJAVKeylistKey* rec);
	void updateRst(ListWznmJAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJAVKeylistKey** rec);
	bool loadRecByKlkLcl(Sbecore::ubigint refWznmAVKeylistKey, Sbecore::uint x1IxWznmVLocale, WznmJAVKeylistKey** rec);
	Sbecore::ubigint loadRefsByKlk(Sbecore::ubigint refWznmAVKeylistKey, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKlk(Sbecore::ubigint refWznmAVKeylistKey, const bool append, ListWznmJAVKeylistKey& rst);
	bool loadTitByKlkLcl(Sbecore::ubigint refWznmAVKeylistKey, Sbecore::uint x1IxWznmVLocale, std::string& Title);
};
#endif

#endif

