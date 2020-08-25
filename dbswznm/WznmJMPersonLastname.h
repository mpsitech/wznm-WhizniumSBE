/**
	* \file WznmJMPersonLastname.h
	* database access for table TblWznmJMPersonLastname (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMJMPERSONLASTNAME_H
#define WZNMJMPERSONLASTNAME_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMPersonLastname: record of TblWznmJMPersonLastname
	*/
class WznmJMPersonLastname {

public:
	WznmJMPersonLastname(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMPerson;
	Sbecore::uint x1Startd;
	std::string Lastname;

public:
	bool operator==(const WznmJMPersonLastname& comp);
	bool operator!=(const WznmJMPersonLastname& comp);
};

/**
	* ListWznmJMPersonLastname: recordset of TblWznmJMPersonLastname
	*/
class ListWznmJMPersonLastname {

public:
	ListWznmJMPersonLastname();
	ListWznmJMPersonLastname(const ListWznmJMPersonLastname& src);
	~ListWznmJMPersonLastname();

	void clear();
	unsigned int size() const;
	void append(WznmJMPersonLastname* rec);

	WznmJMPersonLastname* operator[](const Sbecore::uint ix);
	ListWznmJMPersonLastname& operator=(const ListWznmJMPersonLastname& src);
	bool operator==(const ListWznmJMPersonLastname& comp);
	bool operator!=(const ListWznmJMPersonLastname& comp);

public:
	std::vector<WznmJMPersonLastname*> nodes;
};

/**
	* TblWznmJMPersonLastname: C++ wrapper for table TblWznmJMPersonLastname
	*/
class TblWznmJMPersonLastname {

public:

public:
	TblWznmJMPersonLastname();
	virtual ~TblWznmJMPersonLastname();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMPersonLastname** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMPersonLastname& rst);

	virtual Sbecore::ubigint insertRec(WznmJMPersonLastname* rec);
	Sbecore::ubigint insertNewRec(WznmJMPersonLastname** rec = NULL, const Sbecore::ubigint refWznmMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJMPersonLastname& rst, WznmJMPersonLastname** rec = NULL, const Sbecore::ubigint refWznmMPerson = 0, const Sbecore::uint x1Startd = 0, const std::string Lastname = "");
	virtual void insertRst(ListWznmJMPersonLastname& rst, bool transact = false);
	virtual void updateRec(WznmJMPersonLastname* rec);
	virtual void updateRst(ListWznmJMPersonLastname& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMPersonLastname** rec);
	virtual bool loadRecByPrsSta(Sbecore::ubigint refWznmMPerson, Sbecore::uint x1Startd, WznmJMPersonLastname** rec);
	virtual Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refWznmMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWznmMPerson, const bool append, ListWznmJMPersonLastname& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMPersonLastname& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMPersonLastname: C++ wrapper for table TblWznmJMPersonLastname (MySQL database)
	*/
class MyTblWznmJMPersonLastname : public TblWznmJMPersonLastname, public Sbecore::MyTable {

public:
	MyTblWznmJMPersonLastname();
	~MyTblWznmJMPersonLastname();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMPersonLastname** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMPersonLastname& rst);

	Sbecore::ubigint insertRec(WznmJMPersonLastname* rec);
	void insertRst(ListWznmJMPersonLastname& rst, bool transact = false);
	void updateRec(WznmJMPersonLastname* rec);
	void updateRst(ListWznmJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMPersonLastname** rec);
	bool loadRecByPrsSta(Sbecore::ubigint refWznmMPerson, Sbecore::uint x1Startd, WznmJMPersonLastname** rec);
	Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refWznmMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWznmMPerson, const bool append, ListWznmJMPersonLastname& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMPersonLastname: C++ wrapper for table TblWznmJMPersonLastname (PgSQL database)
	*/
class PgTblWznmJMPersonLastname : public TblWznmJMPersonLastname, public Sbecore::PgTable {

public:
	PgTblWznmJMPersonLastname();
	~PgTblWznmJMPersonLastname();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMPersonLastname** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMPersonLastname& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMPersonLastname** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMPersonLastname& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMPersonLastname** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMPersonLastname& rst);

	Sbecore::ubigint insertRec(WznmJMPersonLastname* rec);
	void insertRst(ListWznmJMPersonLastname& rst, bool transact = false);
	void updateRec(WznmJMPersonLastname* rec);
	void updateRst(ListWznmJMPersonLastname& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMPersonLastname** rec);
	bool loadRecByPrsSta(Sbecore::ubigint refWznmMPerson, Sbecore::uint x1Startd, WznmJMPersonLastname** rec);
	Sbecore::ubigint loadRefsByPrs(Sbecore::ubigint refWznmMPerson, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWznmMPerson, const bool append, ListWznmJMPersonLastname& rst);
};
#endif

#endif

