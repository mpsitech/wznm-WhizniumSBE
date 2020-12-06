/**
	* \file WznmRMCapabilityUniversal.h
	* database access for table TblWznmRMCapabilityUniversal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMRMCAPABILITYUNIVERSAL_H
#define WZNMRMCAPABILITYUNIVERSAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMCapabilityUniversal: record of TblWznmRMCapabilityUniversal
	*/
class WznmRMCapabilityUniversal {

public:
	WznmRMCapabilityUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMCapability = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const std::string srefKKey = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMCapability;
	Sbecore::uint unvIxWznmVMaintable;
	Sbecore::ubigint unvUref;
	std::string srefKKey;

public:
	bool operator==(const WznmRMCapabilityUniversal& comp);
	bool operator!=(const WznmRMCapabilityUniversal& comp);
};

/**
	* ListWznmRMCapabilityUniversal: recordset of TblWznmRMCapabilityUniversal
	*/
class ListWznmRMCapabilityUniversal {

public:
	ListWznmRMCapabilityUniversal();
	ListWznmRMCapabilityUniversal(const ListWznmRMCapabilityUniversal& src);
	~ListWznmRMCapabilityUniversal();

	void clear();
	unsigned int size() const;
	void append(WznmRMCapabilityUniversal* rec);

	WznmRMCapabilityUniversal* operator[](const Sbecore::uint ix);
	ListWznmRMCapabilityUniversal& operator=(const ListWznmRMCapabilityUniversal& src);
	bool operator==(const ListWznmRMCapabilityUniversal& comp);
	bool operator!=(const ListWznmRMCapabilityUniversal& comp);

public:
	std::vector<WznmRMCapabilityUniversal*> nodes;
};

/**
	* TblWznmRMCapabilityUniversal: C++ wrapper for table TblWznmRMCapabilityUniversal
	*/
class TblWznmRMCapabilityUniversal {

public:

public:
	TblWznmRMCapabilityUniversal();
	virtual ~TblWznmRMCapabilityUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMCapabilityUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMCapabilityUniversal& rst);

	virtual Sbecore::ubigint insertRec(WznmRMCapabilityUniversal* rec);
	Sbecore::ubigint insertNewRec(WznmRMCapabilityUniversal** rec = NULL, const Sbecore::ubigint refWznmMCapability = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const std::string srefKKey = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmRMCapabilityUniversal& rst, WznmRMCapabilityUniversal** rec = NULL, const Sbecore::ubigint refWznmMCapability = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const std::string srefKKey = "");
	virtual void insertRst(ListWznmRMCapabilityUniversal& rst, bool transact = false);
	virtual void updateRec(WznmRMCapabilityUniversal* rec);
	virtual void updateRst(ListWznmRMCapabilityUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMCapabilityUniversal** rec);
	virtual Sbecore::ubigint loadRefsByCpb(Sbecore::ubigint refWznmMCapability, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMCapabilityUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMCapabilityUniversal: C++ wrapper for table TblWznmRMCapabilityUniversal (MySQL database)
	*/
class MyTblWznmRMCapabilityUniversal : public TblWznmRMCapabilityUniversal, public Sbecore::MyTable {

public:
	MyTblWznmRMCapabilityUniversal();
	~MyTblWznmRMCapabilityUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMCapabilityUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMCapabilityUniversal& rst);

	Sbecore::ubigint insertRec(WznmRMCapabilityUniversal* rec);
	void insertRst(ListWznmRMCapabilityUniversal& rst, bool transact = false);
	void updateRec(WznmRMCapabilityUniversal* rec);
	void updateRst(ListWznmRMCapabilityUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMCapabilityUniversal** rec);
	Sbecore::ubigint loadRefsByCpb(Sbecore::ubigint refWznmMCapability, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMCapabilityUniversal: C++ wrapper for table TblWznmRMCapabilityUniversal (PgSQL database)
	*/
class PgTblWznmRMCapabilityUniversal : public TblWznmRMCapabilityUniversal, public Sbecore::PgTable {

public:
	PgTblWznmRMCapabilityUniversal();
	~PgTblWznmRMCapabilityUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMCapabilityUniversal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMCapabilityUniversal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMCapabilityUniversal** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMCapabilityUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMCapabilityUniversal& rst);

	Sbecore::ubigint insertRec(WznmRMCapabilityUniversal* rec);
	void insertRst(ListWznmRMCapabilityUniversal& rst, bool transact = false);
	void updateRec(WznmRMCapabilityUniversal* rec);
	void updateRst(ListWznmRMCapabilityUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMCapabilityUniversal** rec);
	Sbecore::ubigint loadRefsByCpb(Sbecore::ubigint refWznmMCapability, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif
