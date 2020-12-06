/**
	* \file WznmMSequence.h
	* database access for table TblWznmMSequence (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMSEQUENCE_H
#define WZNMMSEQUENCE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMSequence: record of TblWznmMSequence
	*/
class WznmMSequence {

public:
	WznmMSequence(const Sbecore::ubigint ref = 0, const Sbecore::ubigint appRefWznmMApp = 0, const Sbecore::uint appNum = 0, const std::string sref = "", const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint appRefWznmMApp;
	Sbecore::uint appNum;
	std::string sref;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WznmMSequence& comp);
	bool operator!=(const WznmMSequence& comp);
};

/**
	* ListWznmMSequence: recordset of TblWznmMSequence
	*/
class ListWznmMSequence {

public:
	ListWznmMSequence();
	ListWznmMSequence(const ListWznmMSequence& src);
	~ListWznmMSequence();

	void clear();
	unsigned int size() const;
	void append(WznmMSequence* rec);

	WznmMSequence* operator[](const Sbecore::uint ix);
	ListWznmMSequence& operator=(const ListWznmMSequence& src);
	bool operator==(const ListWznmMSequence& comp);
	bool operator!=(const ListWznmMSequence& comp);

public:
	std::vector<WznmMSequence*> nodes;
};

/**
	* TblWznmMSequence: C++ wrapper for table TblWznmMSequence
	*/
class TblWznmMSequence {

public:

public:
	TblWznmMSequence();
	virtual ~TblWznmMSequence();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMSequence** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSequence& rst);

	virtual Sbecore::ubigint insertRec(WznmMSequence* rec);
	Sbecore::ubigint insertNewRec(WznmMSequence** rec = NULL, const Sbecore::ubigint appRefWznmMApp = 0, const Sbecore::uint appNum = 0, const std::string sref = "", const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMSequence& rst, WznmMSequence** rec = NULL, const Sbecore::ubigint appRefWznmMApp = 0, const Sbecore::uint appNum = 0, const std::string sref = "", const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMSequence& rst, bool transact = false);
	virtual void updateRec(WznmMSequence* rec);
	virtual void updateRst(ListWznmMSequence& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMSequence** rec);
	virtual Sbecore::ubigint loadRstByApp(Sbecore::ubigint appRefWznmMApp, const bool append, ListWznmMSequence& rst);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMSequence& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMSequence: C++ wrapper for table TblWznmMSequence (MySQL database)
	*/
class MyTblWznmMSequence : public TblWznmMSequence, public Sbecore::MyTable {

public:
	MyTblWznmMSequence();
	~MyTblWznmMSequence();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMSequence** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSequence& rst);

	Sbecore::ubigint insertRec(WznmMSequence* rec);
	void insertRst(ListWznmMSequence& rst, bool transact = false);
	void updateRec(WznmMSequence* rec);
	void updateRst(ListWznmMSequence& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMSequence** rec);
	Sbecore::ubigint loadRstByApp(Sbecore::ubigint appRefWznmMApp, const bool append, ListWznmMSequence& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMSequence: C++ wrapper for table TblWznmMSequence (PgSQL database)
	*/
class PgTblWznmMSequence : public TblWznmMSequence, public Sbecore::PgTable {

public:
	PgTblWznmMSequence();
	~PgTblWznmMSequence();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMSequence** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMSequence& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMSequence** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMSequence& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMSequence** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSequence& rst);

	Sbecore::ubigint insertRec(WznmMSequence* rec);
	void insertRst(ListWznmMSequence& rst, bool transact = false);
	void updateRec(WznmMSequence* rec);
	void updateRst(ListWznmMSequence& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMSequence** rec);
	Sbecore::ubigint loadRstByApp(Sbecore::ubigint appRefWznmMApp, const bool append, ListWznmMSequence& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif
