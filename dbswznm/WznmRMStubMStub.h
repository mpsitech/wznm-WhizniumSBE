/**
	* \file WznmRMStubMStub.h
	* database access for table TblWznmRMStubMStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMRMSTUBMSTUB_H
#define WZNMRMSTUBMSTUB_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMStubMStub: record of TblWznmRMStubMStub
	*/
class WznmRMStubMStub {

public:
	WznmRMStubMStub(const Sbecore::ubigint ref = 0, const Sbecore::ubigint supRefWznmMStub = 0, const Sbecore::ubigint subRefWznmMStub = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint supRefWznmMStub;
	Sbecore::ubigint subRefWznmMStub;

public:
	bool operator==(const WznmRMStubMStub& comp);
	bool operator!=(const WznmRMStubMStub& comp);
};

/**
	* ListWznmRMStubMStub: recordset of TblWznmRMStubMStub
	*/
class ListWznmRMStubMStub {

public:
	ListWznmRMStubMStub();
	ListWznmRMStubMStub(const ListWznmRMStubMStub& src);
	~ListWznmRMStubMStub();

	void clear();
	unsigned int size() const;
	void append(WznmRMStubMStub* rec);

	WznmRMStubMStub* operator[](const Sbecore::uint ix);
	ListWznmRMStubMStub& operator=(const ListWznmRMStubMStub& src);
	bool operator==(const ListWznmRMStubMStub& comp);
	bool operator!=(const ListWznmRMStubMStub& comp);

public:
	std::vector<WznmRMStubMStub*> nodes;
};

/**
	* TblWznmRMStubMStub: C++ wrapper for table TblWznmRMStubMStub
	*/
class TblWznmRMStubMStub {

public:

public:
	TblWznmRMStubMStub();
	virtual ~TblWznmRMStubMStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMStubMStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMStubMStub& rst);

	virtual Sbecore::ubigint insertRec(WznmRMStubMStub* rec);
	Sbecore::ubigint insertNewRec(WznmRMStubMStub** rec = NULL, const Sbecore::ubigint supRefWznmMStub = 0, const Sbecore::ubigint subRefWznmMStub = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMStubMStub& rst, WznmRMStubMStub** rec = NULL, const Sbecore::ubigint supRefWznmMStub = 0, const Sbecore::ubigint subRefWznmMStub = 0);
	virtual void insertRst(ListWznmRMStubMStub& rst, bool transact = false);
	virtual void updateRec(WznmRMStubMStub* rec);
	virtual void updateRst(ListWznmRMStubMStub& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMStubMStub** rec);
	virtual Sbecore::ubigint loadSubsBySup(Sbecore::ubigint supRefWznmMStub, const bool append, std::vector<Sbecore::ubigint>& subRefWznmMStubs);
	virtual Sbecore::ubigint loadSupsBySub(Sbecore::ubigint subRefWznmMStub, const bool append, std::vector<Sbecore::ubigint>& supRefWznmMStubs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMStubMStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMStubMStub: C++ wrapper for table TblWznmRMStubMStub (MySQL database)
	*/
class MyTblWznmRMStubMStub : public TblWznmRMStubMStub, public Sbecore::MyTable {

public:
	MyTblWznmRMStubMStub();
	~MyTblWznmRMStubMStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMStubMStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMStubMStub& rst);

	Sbecore::ubigint insertRec(WznmRMStubMStub* rec);
	void insertRst(ListWznmRMStubMStub& rst, bool transact = false);
	void updateRec(WznmRMStubMStub* rec);
	void updateRst(ListWznmRMStubMStub& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMStubMStub** rec);
	Sbecore::ubigint loadSubsBySup(Sbecore::ubigint supRefWznmMStub, const bool append, std::vector<Sbecore::ubigint>& subRefWznmMStubs);
	Sbecore::ubigint loadSupsBySub(Sbecore::ubigint subRefWznmMStub, const bool append, std::vector<Sbecore::ubigint>& supRefWznmMStubs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMStubMStub: C++ wrapper for table TblWznmRMStubMStub (PgSQL database)
	*/
class PgTblWznmRMStubMStub : public TblWznmRMStubMStub, public Sbecore::PgTable {

public:
	PgTblWznmRMStubMStub();
	~PgTblWznmRMStubMStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMStubMStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMStubMStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMStubMStub** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMStubMStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMStubMStub& rst);

	Sbecore::ubigint insertRec(WznmRMStubMStub* rec);
	void insertRst(ListWznmRMStubMStub& rst, bool transact = false);
	void updateRec(WznmRMStubMStub* rec);
	void updateRst(ListWznmRMStubMStub& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMStubMStub** rec);
	Sbecore::ubigint loadSubsBySup(Sbecore::ubigint supRefWznmMStub, const bool append, std::vector<Sbecore::ubigint>& subRefWznmMStubs);
	Sbecore::ubigint loadSupsBySub(Sbecore::ubigint subRefWznmMStub, const bool append, std::vector<Sbecore::ubigint>& supRefWznmMStubs);
};
#endif

#endif

