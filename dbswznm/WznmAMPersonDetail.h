/**
	* \file WznmAMPersonDetail.h
	* database access for table TblWznmAMPersonDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMPERSONDETAIL_H
#define WZNMAMPERSONDETAIL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAMPersonDetail: record of TblWznmAMPersonDetail
	*/
class WznmAMPersonDetail {

public:
	WznmAMPersonDetail(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMPerson;
	std::string x1SrefKType;
	std::string Val;

public:
	bool operator==(const WznmAMPersonDetail& comp);
	bool operator!=(const WznmAMPersonDetail& comp);
};

/**
	* ListWznmAMPersonDetail: recordset of TblWznmAMPersonDetail
	*/
class ListWznmAMPersonDetail {

public:
	ListWznmAMPersonDetail();
	ListWznmAMPersonDetail(const ListWznmAMPersonDetail& src);
	~ListWznmAMPersonDetail();

	void clear();
	unsigned int size() const;
	void append(WznmAMPersonDetail* rec);

	WznmAMPersonDetail* operator[](const Sbecore::uint ix);
	ListWznmAMPersonDetail& operator=(const ListWznmAMPersonDetail& src);
	bool operator==(const ListWznmAMPersonDetail& comp);
	bool operator!=(const ListWznmAMPersonDetail& comp);

public:
	std::vector<WznmAMPersonDetail*> nodes;
};

/**
	* TblWznmAMPersonDetail: C++ wrapper for table TblWznmAMPersonDetail
	*/
class TblWznmAMPersonDetail {

public:

public:
	TblWznmAMPersonDetail();
	virtual ~TblWznmAMPersonDetail();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMPersonDetail** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMPersonDetail& rst);

	virtual Sbecore::ubigint insertRec(WznmAMPersonDetail* rec);
	Sbecore::ubigint insertNewRec(WznmAMPersonDetail** rec = NULL, const Sbecore::ubigint refWznmMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMPersonDetail& rst, WznmAMPersonDetail** rec = NULL, const Sbecore::ubigint refWznmMPerson = 0, const std::string x1SrefKType = "", const std::string Val = "");
	virtual void insertRst(ListWznmAMPersonDetail& rst, bool transact = false);
	virtual void updateRec(WznmAMPersonDetail* rec);
	virtual void updateRst(ListWznmAMPersonDetail& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMPersonDetail** rec);
	virtual Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWznmMPerson, const bool append, ListWznmAMPersonDetail& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMPersonDetail& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMPersonDetail: C++ wrapper for table TblWznmAMPersonDetail (MySQL database)
	*/
class MyTblWznmAMPersonDetail : public TblWznmAMPersonDetail, public Sbecore::MyTable {

public:
	MyTblWznmAMPersonDetail();
	~MyTblWznmAMPersonDetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMPersonDetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMPersonDetail& rst);

	Sbecore::ubigint insertRec(WznmAMPersonDetail* rec);
	void insertRst(ListWznmAMPersonDetail& rst, bool transact = false);
	void updateRec(WznmAMPersonDetail* rec);
	void updateRst(ListWznmAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMPersonDetail** rec);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWznmMPerson, const bool append, ListWznmAMPersonDetail& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMPersonDetail: C++ wrapper for table TblWznmAMPersonDetail (PgSQL database)
	*/
class PgTblWznmAMPersonDetail : public TblWznmAMPersonDetail, public Sbecore::PgTable {

public:
	PgTblWznmAMPersonDetail();
	~PgTblWznmAMPersonDetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMPersonDetail** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMPersonDetail& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMPersonDetail** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMPersonDetail& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMPersonDetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMPersonDetail& rst);

	Sbecore::ubigint insertRec(WznmAMPersonDetail* rec);
	void insertRst(ListWznmAMPersonDetail& rst, bool transact = false);
	void updateRec(WznmAMPersonDetail* rec);
	void updateRst(ListWznmAMPersonDetail& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMPersonDetail** rec);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWznmMPerson, const bool append, ListWznmAMPersonDetail& rst);
};
#endif

#endif
