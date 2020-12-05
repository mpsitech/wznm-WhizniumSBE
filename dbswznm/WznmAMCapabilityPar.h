/**
	* \file WznmAMCapabilityPar.h
	* database access for table TblWznmAMCapabilityPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMCAPABILITYPAR_H
#define WZNMAMCAPABILITYPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMCapabilityPar: record of TblWznmAMCapabilityPar
	*/
class WznmAMCapabilityPar {

public:
	WznmAMCapabilityPar(const Sbecore::ubigint ref = 0, const Sbecore::ubigint cpbRefWznmMCapability = 0, const Sbecore::uint cpbNum = 0, const std::string x1SrefKKey = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint cpbRefWznmMCapability;
	Sbecore::uint cpbNum;
	std::string x1SrefKKey;
	std::string Val;

public:
	bool operator==(const WznmAMCapabilityPar& comp);
	bool operator!=(const WznmAMCapabilityPar& comp);
};

/**
	* ListWznmAMCapabilityPar: recordset of TblWznmAMCapabilityPar
	*/
class ListWznmAMCapabilityPar {

public:
	ListWznmAMCapabilityPar();
	ListWznmAMCapabilityPar(const ListWznmAMCapabilityPar& src);
	~ListWznmAMCapabilityPar();

	void clear();
	unsigned int size() const;
	void append(WznmAMCapabilityPar* rec);

	WznmAMCapabilityPar* operator[](const Sbecore::uint ix);
	ListWznmAMCapabilityPar& operator=(const ListWznmAMCapabilityPar& src);
	bool operator==(const ListWznmAMCapabilityPar& comp);
	bool operator!=(const ListWznmAMCapabilityPar& comp);

public:
	std::vector<WznmAMCapabilityPar*> nodes;
};

/**
	* TblWznmAMCapabilityPar: C++ wrapper for table TblWznmAMCapabilityPar
	*/
class TblWznmAMCapabilityPar {

public:

public:
	TblWznmAMCapabilityPar();
	virtual ~TblWznmAMCapabilityPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMCapabilityPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMCapabilityPar& rst);

	virtual Sbecore::ubigint insertRec(WznmAMCapabilityPar* rec);
	Sbecore::ubigint insertNewRec(WznmAMCapabilityPar** rec = NULL, const Sbecore::ubigint cpbRefWznmMCapability = 0, const Sbecore::uint cpbNum = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMCapabilityPar& rst, WznmAMCapabilityPar** rec = NULL, const Sbecore::ubigint cpbRefWznmMCapability = 0, const Sbecore::uint cpbNum = 0, const std::string x1SrefKKey = "", const std::string Val = "");
	virtual void insertRst(ListWznmAMCapabilityPar& rst, bool transact = false);
	virtual void updateRec(WznmAMCapabilityPar* rec);
	virtual void updateRst(ListWznmAMCapabilityPar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMCapabilityPar** rec);
	virtual Sbecore::ubigint loadRefsByCpb(Sbecore::ubigint cpbRefWznmMCapability, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCpb(Sbecore::ubigint cpbRefWznmMCapability, const bool append, ListWznmAMCapabilityPar& rst);
	virtual bool loadValByCpbKey(Sbecore::ubigint cpbRefWznmMCapability, std::string x1SrefKKey, std::string& Val);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMCapabilityPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMCapabilityPar: C++ wrapper for table TblWznmAMCapabilityPar (MySQL database)
	*/
class MyTblWznmAMCapabilityPar : public TblWznmAMCapabilityPar, public Sbecore::MyTable {

public:
	MyTblWznmAMCapabilityPar();
	~MyTblWznmAMCapabilityPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMCapabilityPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMCapabilityPar& rst);

	Sbecore::ubigint insertRec(WznmAMCapabilityPar* rec);
	void insertRst(ListWznmAMCapabilityPar& rst, bool transact = false);
	void updateRec(WznmAMCapabilityPar* rec);
	void updateRst(ListWznmAMCapabilityPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMCapabilityPar** rec);
	Sbecore::ubigint loadRefsByCpb(Sbecore::ubigint cpbRefWznmMCapability, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCpb(Sbecore::ubigint cpbRefWznmMCapability, const bool append, ListWznmAMCapabilityPar& rst);
	bool loadValByCpbKey(Sbecore::ubigint cpbRefWznmMCapability, std::string x1SrefKKey, std::string& Val);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMCapabilityPar: C++ wrapper for table TblWznmAMCapabilityPar (PgSQL database)
	*/
class PgTblWznmAMCapabilityPar : public TblWznmAMCapabilityPar, public Sbecore::PgTable {

public:
	PgTblWznmAMCapabilityPar();
	~PgTblWznmAMCapabilityPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMCapabilityPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMCapabilityPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMCapabilityPar** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMCapabilityPar& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMCapabilityPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMCapabilityPar& rst);

	Sbecore::ubigint insertRec(WznmAMCapabilityPar* rec);
	void insertRst(ListWznmAMCapabilityPar& rst, bool transact = false);
	void updateRec(WznmAMCapabilityPar* rec);
	void updateRst(ListWznmAMCapabilityPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMCapabilityPar** rec);
	Sbecore::ubigint loadRefsByCpb(Sbecore::ubigint cpbRefWznmMCapability, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCpb(Sbecore::ubigint cpbRefWznmMCapability, const bool append, ListWznmAMCapabilityPar& rst);
	bool loadValByCpbKey(Sbecore::ubigint cpbRefWznmMCapability, std::string x1SrefKKey, std::string& Val);
};
#endif

#endif

