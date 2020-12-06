/**
	* \file WznmMVectoritem.h
	* database access for table TblWznmMVectoritem (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMVECTORITEM_H
#define WZNMMVECTORITEM_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMVectoritem: record of TblWznmMVectoritem
	*/
class WznmMVectoritem {

public:
	WznmMVectoritem(const Sbecore::ubigint ref = 0, const Sbecore::ubigint vecRefWznmMVector = 0, const Sbecore::uint vecNum = 0, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint vecRefWznmMVector;
	Sbecore::uint vecNum;
	std::string sref;
	std::string Avail;
	std::string Implied;
	Sbecore::ubigint refJ;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WznmMVectoritem& comp);
	bool operator!=(const WznmMVectoritem& comp);
};

/**
	* ListWznmMVectoritem: recordset of TblWznmMVectoritem
	*/
class ListWznmMVectoritem {

public:
	ListWznmMVectoritem();
	ListWznmMVectoritem(const ListWznmMVectoritem& src);
	~ListWznmMVectoritem();

	void clear();
	unsigned int size() const;
	void append(WznmMVectoritem* rec);

	WznmMVectoritem* operator[](const Sbecore::uint ix);
	ListWznmMVectoritem& operator=(const ListWznmMVectoritem& src);
	bool operator==(const ListWznmMVectoritem& comp);
	bool operator!=(const ListWznmMVectoritem& comp);

public:
	std::vector<WznmMVectoritem*> nodes;
};

/**
	* TblWznmMVectoritem: C++ wrapper for table TblWznmMVectoritem
	*/
class TblWznmMVectoritem {

public:

public:
	TblWznmMVectoritem();
	virtual ~TblWznmMVectoritem();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMVectoritem** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMVectoritem& rst);

	virtual Sbecore::ubigint insertRec(WznmMVectoritem* rec);
	Sbecore::ubigint insertNewRec(WznmMVectoritem** rec = NULL, const Sbecore::ubigint vecRefWznmMVector = 0, const Sbecore::uint vecNum = 0, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMVectoritem& rst, WznmMVectoritem** rec = NULL, const Sbecore::ubigint vecRefWznmMVector = 0, const Sbecore::uint vecNum = 0, const std::string sref = "", const std::string Avail = "", const std::string Implied = "", const Sbecore::ubigint refJ = 0, const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMVectoritem& rst, bool transact = false);
	virtual void updateRec(WznmMVectoritem* rec);
	virtual void updateRst(ListWznmMVectoritem& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMVectoritem** rec);
	virtual Sbecore::ubigint loadRefsByVec(Sbecore::ubigint vecRefWznmMVector, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByVec(Sbecore::ubigint vecRefWznmMVector, const bool append, ListWznmMVectoritem& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMVectoritem& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMVectoritem: C++ wrapper for table TblWznmMVectoritem (MySQL database)
	*/
class MyTblWznmMVectoritem : public TblWznmMVectoritem, public Sbecore::MyTable {

public:
	MyTblWznmMVectoritem();
	~MyTblWznmMVectoritem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMVectoritem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMVectoritem& rst);

	Sbecore::ubigint insertRec(WznmMVectoritem* rec);
	void insertRst(ListWznmMVectoritem& rst, bool transact = false);
	void updateRec(WznmMVectoritem* rec);
	void updateRst(ListWznmMVectoritem& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMVectoritem** rec);
	Sbecore::ubigint loadRefsByVec(Sbecore::ubigint vecRefWznmMVector, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVec(Sbecore::ubigint vecRefWznmMVector, const bool append, ListWznmMVectoritem& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMVectoritem: C++ wrapper for table TblWznmMVectoritem (PgSQL database)
	*/
class PgTblWznmMVectoritem : public TblWznmMVectoritem, public Sbecore::PgTable {

public:
	PgTblWznmMVectoritem();
	~PgTblWznmMVectoritem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMVectoritem** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMVectoritem& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMVectoritem** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMVectoritem& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMVectoritem** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMVectoritem& rst);

	Sbecore::ubigint insertRec(WznmMVectoritem* rec);
	void insertRst(ListWznmMVectoritem& rst, bool transact = false);
	void updateRec(WznmMVectoritem* rec);
	void updateRst(ListWznmMVectoritem& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMVectoritem** rec);
	Sbecore::ubigint loadRefsByVec(Sbecore::ubigint vecRefWznmMVector, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByVec(Sbecore::ubigint vecRefWznmMVector, const bool append, ListWznmMVectoritem& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
