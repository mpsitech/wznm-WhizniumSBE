/**
	* \file WznmMSheet.h
	* database access for table TblWznmMSheet (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMMSHEET_H
#define WZNMMSHEET_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMSheet: record of TblWznmMSheet
	*/
class WznmMSheet {

public:
	WznmMSheet(const Sbecore::ubigint ref = 0, const Sbecore::ubigint visRefWznmMVisual = 0, const Sbecore::uint visNum = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint visRefWznmMVisual;
	Sbecore::uint visNum;
	std::string Title;

public:
	bool operator==(const WznmMSheet& comp);
	bool operator!=(const WznmMSheet& comp);
};

/**
	* ListWznmMSheet: recordset of TblWznmMSheet
	*/
class ListWznmMSheet {

public:
	ListWznmMSheet();
	ListWznmMSheet(const ListWznmMSheet& src);
	~ListWznmMSheet();

	void clear();
	unsigned int size() const;
	void append(WznmMSheet* rec);

	WznmMSheet* operator[](const Sbecore::uint ix);
	ListWznmMSheet& operator=(const ListWznmMSheet& src);
	bool operator==(const ListWznmMSheet& comp);
	bool operator!=(const ListWznmMSheet& comp);

public:
	std::vector<WznmMSheet*> nodes;
};

/**
	* TblWznmMSheet: C++ wrapper for table TblWznmMSheet
	*/
class TblWznmMSheet {

public:

public:
	TblWznmMSheet();
	virtual ~TblWznmMSheet();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMSheet** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSheet& rst);

	virtual Sbecore::ubigint insertRec(WznmMSheet* rec);
	Sbecore::ubigint insertNewRec(WznmMSheet** rec = NULL, const Sbecore::ubigint visRefWznmMVisual = 0, const Sbecore::uint visNum = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMSheet& rst, WznmMSheet** rec = NULL, const Sbecore::ubigint visRefWznmMVisual = 0, const Sbecore::uint visNum = 0, const std::string Title = "");
	virtual void insertRst(ListWznmMSheet& rst, bool transact = false);
	virtual void updateRec(WznmMSheet* rec);
	virtual void updateRst(ListWznmMSheet& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMSheet** rec);
	virtual Sbecore::ubigint loadRstByVis(Sbecore::ubigint visRefWznmMVisual, const bool append, ListWznmMSheet& rst);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMSheet& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMSheet: C++ wrapper for table TblWznmMSheet (MySQL database)
	*/
class MyTblWznmMSheet : public TblWznmMSheet, public Sbecore::MyTable {

public:
	MyTblWznmMSheet();
	~MyTblWznmMSheet();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMSheet** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSheet& rst);

	Sbecore::ubigint insertRec(WznmMSheet* rec);
	void insertRst(ListWznmMSheet& rst, bool transact = false);
	void updateRec(WznmMSheet* rec);
	void updateRst(ListWznmMSheet& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMSheet** rec);
	Sbecore::ubigint loadRstByVis(Sbecore::ubigint visRefWznmMVisual, const bool append, ListWznmMSheet& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMSheet: C++ wrapper for table TblWznmMSheet (PgSQL database)
	*/
class PgTblWznmMSheet : public TblWznmMSheet, public Sbecore::PgTable {

public:
	PgTblWznmMSheet();
	~PgTblWznmMSheet();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMSheet** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMSheet& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMSheet** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMSheet& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMSheet** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSheet& rst);

	Sbecore::ubigint insertRec(WznmMSheet* rec);
	void insertRst(ListWznmMSheet& rst, bool transact = false);
	void updateRec(WznmMSheet* rec);
	void updateRst(ListWznmMSheet& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMSheet** rec);
	Sbecore::ubigint loadRstByVis(Sbecore::ubigint visRefWznmMVisual, const bool append, ListWznmMSheet& rst);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif
