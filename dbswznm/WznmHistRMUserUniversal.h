/**
	* \file WznmHistRMUserUniversal.h
	* database access for table TblWznmHistRMUserUniversal (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMHISTRMUSERUNIVERSAL_H
#define WZNMHISTRMUSERUNIVERSAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmHistRMUserUniversal: record of TblWznmHistRMUserUniversal
	*/
class WznmHistRMUserUniversal {

public:
	WznmHistRMUserUniversal(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWznmVCard = 0, const Sbecore::uint ixWznmVPreset = 0, const Sbecore::uint preIxWznmVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMUser;
	Sbecore::uint unvIxWznmVMaintable;
	Sbecore::ubigint unvUref;
	Sbecore::uint ixWznmVCard;
	Sbecore::uint ixWznmVPreset;
	Sbecore::uint preIxWznmVMaintable;
	Sbecore::ubigint preUref;
	Sbecore::uint start;

public:
	bool operator==(const WznmHistRMUserUniversal& comp);
	bool operator!=(const WznmHistRMUserUniversal& comp);
};

/**
	* ListWznmHistRMUserUniversal: recordset of TblWznmHistRMUserUniversal
	*/
class ListWznmHistRMUserUniversal {

public:
	ListWznmHistRMUserUniversal();
	ListWznmHistRMUserUniversal(const ListWznmHistRMUserUniversal& src);
	~ListWznmHistRMUserUniversal();

	void clear();
	unsigned int size() const;
	void append(WznmHistRMUserUniversal* rec);

	WznmHistRMUserUniversal* operator[](const Sbecore::uint ix);
	ListWznmHistRMUserUniversal& operator=(const ListWznmHistRMUserUniversal& src);
	bool operator==(const ListWznmHistRMUserUniversal& comp);
	bool operator!=(const ListWznmHistRMUserUniversal& comp);

public:
	std::vector<WznmHistRMUserUniversal*> nodes;
};

/**
	* TblWznmHistRMUserUniversal: C++ wrapper for table TblWznmHistRMUserUniversal
	*/
class TblWznmHistRMUserUniversal {

public:

public:
	TblWznmHistRMUserUniversal();
	virtual ~TblWznmHistRMUserUniversal();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmHistRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmHistRMUserUniversal& rst);

	virtual Sbecore::ubigint insertRec(WznmHistRMUserUniversal* rec);
	Sbecore::ubigint insertNewRec(WznmHistRMUserUniversal** rec = NULL, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWznmVCard = 0, const Sbecore::uint ixWznmVPreset = 0, const Sbecore::uint preIxWznmVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmHistRMUserUniversal& rst, WznmHistRMUserUniversal** rec = NULL, const Sbecore::ubigint refWznmMUser = 0, const Sbecore::uint unvIxWznmVMaintable = 0, const Sbecore::ubigint unvUref = 0, const Sbecore::uint ixWznmVCard = 0, const Sbecore::uint ixWznmVPreset = 0, const Sbecore::uint preIxWznmVMaintable = 0, const Sbecore::ubigint preUref = 0, const Sbecore::uint start = 0);
	virtual void insertRst(ListWznmHistRMUserUniversal& rst, bool transact = false);
	virtual void updateRec(WznmHistRMUserUniversal* rec);
	virtual void updateRst(ListWznmHistRMUserUniversal& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmHistRMUserUniversal** rec);
	virtual bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refWznmMUser, Sbecore::uint unvIxWznmVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixWznmVCard, WznmHistRMUserUniversal** rec);
	virtual Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refWznmMUser, Sbecore::uint unvIxWznmVMaintable, Sbecore::uint ixWznmVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	virtual Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refWznmMUser, Sbecore::uint ixWznmVCard, const bool append, ListWznmHistRMUserUniversal& rst);
	virtual bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmHistRMUserUniversal& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmHistRMUserUniversal: C++ wrapper for table TblWznmHistRMUserUniversal (MySQL database)
	*/
class MyTblWznmHistRMUserUniversal : public TblWznmHistRMUserUniversal, public Sbecore::MyTable {

public:
	MyTblWznmHistRMUserUniversal();
	~MyTblWznmHistRMUserUniversal();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmHistRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WznmHistRMUserUniversal* rec);
	void insertRst(ListWznmHistRMUserUniversal& rst, bool transact = false);
	void updateRec(WznmHistRMUserUniversal* rec);
	void updateRst(ListWznmHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmHistRMUserUniversal** rec);
	bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refWznmMUser, Sbecore::uint unvIxWznmVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixWznmVCard, WznmHistRMUserUniversal** rec);
	Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refWznmMUser, Sbecore::uint unvIxWznmVMaintable, Sbecore::uint ixWznmVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refWznmMUser, Sbecore::uint ixWznmVCard, const bool append, ListWznmHistRMUserUniversal& rst);
	bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmHistRMUserUniversal: C++ wrapper for table TblWznmHistRMUserUniversal (PgSQL database)
	*/
class PgTblWznmHistRMUserUniversal : public TblWznmHistRMUserUniversal, public Sbecore::PgTable {

public:
	PgTblWznmHistRMUserUniversal();
	~PgTblWznmHistRMUserUniversal();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmHistRMUserUniversal** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmHistRMUserUniversal& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmHistRMUserUniversal& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmHistRMUserUniversal** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmHistRMUserUniversal& rst);

	Sbecore::ubigint insertRec(WznmHistRMUserUniversal* rec);
	void insertRst(ListWznmHistRMUserUniversal& rst, bool transact = false);
	void updateRec(WznmHistRMUserUniversal* rec);
	void updateRst(ListWznmHistRMUserUniversal& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmHistRMUserUniversal** rec);
	bool loadRecByUsrMtbUnvCrd(Sbecore::ubigint refWznmMUser, Sbecore::uint unvIxWznmVMaintable, Sbecore::ubigint unvUref, Sbecore::uint ixWznmVCard, WznmHistRMUserUniversal** rec);
	Sbecore::ubigint loadRefsByUsrMtbCrd(Sbecore::ubigint refWznmMUser, Sbecore::uint unvIxWznmVMaintable, Sbecore::uint ixWznmVCard, const bool append, std::vector<Sbecore::ubigint>& refs, Sbecore::ubigint limit = 0, Sbecore::ubigint offset = 0);
	Sbecore::ubigint loadRstByUsrCrd(Sbecore::ubigint refWznmMUser, Sbecore::uint ixWznmVCard, const bool append, ListWznmHistRMUserUniversal& rst);
	bool loadUnuByRef(Sbecore::ubigint ref, Sbecore::ubigint& unvUref);
};
#endif

#endif

