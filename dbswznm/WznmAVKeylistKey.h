/**
	* \file WznmAVKeylistKey.h
	* database access for table TblWznmAVKeylistKey (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMAVKEYLISTKEY_H
#define WZNMAVKEYLISTKEY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAVKeylistKey: record of TblWznmAVKeylistKey
	*/
class WznmAVKeylistKey {

public:
	WznmAVKeylistKey(const Sbecore::ubigint ref = 0, const Sbecore::uint klsIxWznmVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxWznmVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint klsIxWznmVKeylist;
	Sbecore::uint klsNum;
	Sbecore::uint x1IxWznmVMaintable;
	Sbecore::ubigint x1Uref;
	bool Fixed;
	std::string sref;
	std::string Avail;
	std::string Implied;
	Sbecore::ubigint refJ;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WznmAVKeylistKey& comp);
	bool operator!=(const WznmAVKeylistKey& comp);
};

/**
	* ListWznmAVKeylistKey: recordset of TblWznmAVKeylistKey
	*/
class ListWznmAVKeylistKey {

public:
	ListWznmAVKeylistKey();
	ListWznmAVKeylistKey(const ListWznmAVKeylistKey& src);
	~ListWznmAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(WznmAVKeylistKey* rec);

	WznmAVKeylistKey* operator[](const Sbecore::uint ix);
	ListWznmAVKeylistKey& operator=(const ListWznmAVKeylistKey& src);
	bool operator==(const ListWznmAVKeylistKey& comp);
	bool operator!=(const ListWznmAVKeylistKey& comp);

public:
	std::vector<WznmAVKeylistKey*> nodes;
};

/**
	* TblWznmAVKeylistKey: C++ wrapper for table TblWznmAVKeylistKey
	*/
class TblWznmAVKeylistKey {

public:

public:
	TblWznmAVKeylistKey();
	virtual ~TblWznmAVKeylistKey();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAVKeylistKey** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAVKeylistKey& rst);

	virtual Sbecore::ubigint insertRec(WznmAVKeylistKey* rec);
	Sbecore::ubigint insertNewRec(WznmAVKeylistKey** rec = NULL, const Sbecore::uint klsIxWznmVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxWznmVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAVKeylistKey& rst, WznmAVKeylistKey** rec = NULL, const Sbecore::uint klsIxWznmVKeylist = 0, const Sbecore::uint klsNum = 0, const Sbecore::uint x1IxWznmVMaintable = 0, const Sbecore::ubigint x1Uref = 0, const bool Fixed = false, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWznmAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(WznmAVKeylistKey* rec);
	virtual void updateRst(ListWznmAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAVKeylistKey** rec);
	virtual bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxWznmVKeylist, Sbecore::uint x1IxWznmVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	virtual bool loadRefByKlsSrf(Sbecore::uint klsIxWznmVKeylist, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByMtbUrf(Sbecore::uint x1IxWznmVMaintable, Sbecore::ubigint x1Uref, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxWznmVKeylist, const bool append, ListWznmAVKeylistKey& rst);
	virtual Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxWznmVKeylist, Sbecore::uint x1IxWznmVMaintable, Sbecore::ubigint x1Uref, const bool append, ListWznmAVKeylistKey& rst);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAVKeylistKey& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAVKeylistKey: C++ wrapper for table TblWznmAVKeylistKey (MySQL database)
	*/
class MyTblWznmAVKeylistKey : public TblWznmAVKeylistKey, public Sbecore::MyTable {

public:
	MyTblWznmAVKeylistKey();
	~MyTblWznmAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WznmAVKeylistKey* rec);
	void insertRst(ListWznmAVKeylistKey& rst, bool transact = false);
	void updateRec(WznmAVKeylistKey* rec);
	void updateRst(ListWznmAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxWznmVKeylist, Sbecore::uint x1IxWznmVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	bool loadRefByKlsSrf(Sbecore::uint klsIxWznmVKeylist, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByMtbUrf(Sbecore::uint x1IxWznmVMaintable, Sbecore::ubigint x1Uref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxWznmVKeylist, const bool append, ListWznmAVKeylistKey& rst);
	Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxWznmVKeylist, Sbecore::uint x1IxWznmVMaintable, Sbecore::ubigint x1Uref, const bool append, ListWznmAVKeylistKey& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAVKeylistKey: C++ wrapper for table TblWznmAVKeylistKey (PgSQL database)
	*/
class PgTblWznmAVKeylistKey : public TblWznmAVKeylistKey, public Sbecore::PgTable {

public:
	PgTblWznmAVKeylistKey();
	~PgTblWznmAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAVKeylistKey** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAVKeylistKey& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAVKeylistKey** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAVKeylistKey& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAVKeylistKey** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAVKeylistKey& rst);

	Sbecore::ubigint insertRec(WznmAVKeylistKey* rec);
	void insertRst(ListWznmAVKeylistKey& rst, bool transact = false);
	void updateRec(WznmAVKeylistKey* rec);
	void updateRst(ListWznmAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(Sbecore::uint klsIxWznmVKeylist, Sbecore::uint x1IxWznmVMaintable, Sbecore::ubigint x1Uref, std::string sref, Sbecore::ubigint& ref);
	bool loadRefByKlsSrf(Sbecore::uint klsIxWznmVKeylist, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByMtbUrf(Sbecore::uint x1IxWznmVMaintable, Sbecore::ubigint x1Uref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByKls(Sbecore::uint klsIxWznmVKeylist, const bool append, ListWznmAVKeylistKey& rst);
	Sbecore::ubigint loadRstByKlsMtbUrf(Sbecore::uint klsIxWznmVKeylist, Sbecore::uint x1IxWznmVMaintable, Sbecore::ubigint x1Uref, const bool append, ListWznmAVKeylistKey& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif

