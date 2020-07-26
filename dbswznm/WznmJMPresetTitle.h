/**
	* \file WznmJMPresetTitle.h
	* database access for table TblWznmJMPresetTitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMJMPRESETTITLE_H
#define WZNMJMPRESETTITLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMPresetTitle: record of TblWznmJMPresetTitle
	*/
class WznmJMPresetTitle {

public:
	WznmJMPresetTitle(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMPreset;
	Sbecore::ubigint x1RefWznmMLocale;
	std::string Title;

public:
	bool operator==(const WznmJMPresetTitle& comp);
	bool operator!=(const WznmJMPresetTitle& comp);
};

/**
	* ListWznmJMPresetTitle: recordset of TblWznmJMPresetTitle
	*/
class ListWznmJMPresetTitle {

public:
	ListWznmJMPresetTitle();
	ListWznmJMPresetTitle(const ListWznmJMPresetTitle& src);
	~ListWznmJMPresetTitle();

	void clear();
	unsigned int size() const;
	void append(WznmJMPresetTitle* rec);

	WznmJMPresetTitle* operator[](const Sbecore::uint ix);
	ListWznmJMPresetTitle& operator=(const ListWznmJMPresetTitle& src);
	bool operator==(const ListWznmJMPresetTitle& comp);
	bool operator!=(const ListWznmJMPresetTitle& comp);

public:
	std::vector<WznmJMPresetTitle*> nodes;
};

/**
	* TblWznmJMPresetTitle: C++ wrapper for table TblWznmJMPresetTitle
	*/
class TblWznmJMPresetTitle {

public:

public:
	TblWznmJMPresetTitle();
	virtual ~TblWznmJMPresetTitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMPresetTitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMPresetTitle& rst);

	virtual Sbecore::ubigint insertRec(WznmJMPresetTitle* rec);
	Sbecore::ubigint insertNewRec(WznmJMPresetTitle** rec = NULL, const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmJMPresetTitle& rst, WznmJMPresetTitle** rec = NULL, const Sbecore::ubigint refWznmMPreset = 0, const Sbecore::ubigint x1RefWznmMLocale = 0, const std::string Title = "");
	virtual void insertRst(ListWznmJMPresetTitle& rst, bool transact = false);
	virtual void updateRec(WznmJMPresetTitle* rec);
	virtual void updateRst(ListWznmJMPresetTitle& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMPresetTitle** rec);
	virtual bool loadRecByPstLoc(Sbecore::ubigint refWznmMPreset, Sbecore::ubigint x1RefWznmMLocale, WznmJMPresetTitle** rec);
	virtual Sbecore::ubigint loadRefsByPst(Sbecore::ubigint refWznmMPreset, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPst(Sbecore::ubigint refWznmMPreset, const bool append, ListWznmJMPresetTitle& rst);
	virtual bool loadTitByPstLoc(Sbecore::ubigint refWznmMPreset, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMPresetTitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMPresetTitle: C++ wrapper for table TblWznmJMPresetTitle (MySQL database)
	*/
class MyTblWznmJMPresetTitle : public TblWznmJMPresetTitle, public Sbecore::MyTable {

public:
	MyTblWznmJMPresetTitle();
	~MyTblWznmJMPresetTitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMPresetTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMPresetTitle& rst);

	Sbecore::ubigint insertRec(WznmJMPresetTitle* rec);
	void insertRst(ListWznmJMPresetTitle& rst, bool transact = false);
	void updateRec(WznmJMPresetTitle* rec);
	void updateRst(ListWznmJMPresetTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMPresetTitle** rec);
	bool loadRecByPstLoc(Sbecore::ubigint refWznmMPreset, Sbecore::ubigint x1RefWznmMLocale, WznmJMPresetTitle** rec);
	Sbecore::ubigint loadRefsByPst(Sbecore::ubigint refWznmMPreset, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPst(Sbecore::ubigint refWznmMPreset, const bool append, ListWznmJMPresetTitle& rst);
	bool loadTitByPstLoc(Sbecore::ubigint refWznmMPreset, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMPresetTitle: C++ wrapper for table TblWznmJMPresetTitle (PgSQL database)
	*/
class PgTblWznmJMPresetTitle : public TblWznmJMPresetTitle, public Sbecore::PgTable {

public:
	PgTblWznmJMPresetTitle();
	~PgTblWznmJMPresetTitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMPresetTitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMPresetTitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMPresetTitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMPresetTitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMPresetTitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMPresetTitle& rst);

	Sbecore::ubigint insertRec(WznmJMPresetTitle* rec);
	void insertRst(ListWznmJMPresetTitle& rst, bool transact = false);
	void updateRec(WznmJMPresetTitle* rec);
	void updateRst(ListWznmJMPresetTitle& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMPresetTitle** rec);
	bool loadRecByPstLoc(Sbecore::ubigint refWznmMPreset, Sbecore::ubigint x1RefWznmMLocale, WznmJMPresetTitle** rec);
	Sbecore::ubigint loadRefsByPst(Sbecore::ubigint refWznmMPreset, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPst(Sbecore::ubigint refWznmMPreset, const bool append, ListWznmJMPresetTitle& rst);
	bool loadTitByPstLoc(Sbecore::ubigint refWznmMPreset, Sbecore::ubigint x1RefWznmMLocale, std::string& Title);
};
#endif

#endif

