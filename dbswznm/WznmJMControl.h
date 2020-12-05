/**
	* \file WznmJMControl.h
	* database access for table TblWznmJMControl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMJMCONTROL_H
#define WZNMJMCONTROL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmJMControl: record of TblWznmJMControl
	*/
class WznmJMControl {

public:
	WznmJMControl(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMControl = 0, const Sbecore::ubigint x1RefWznmMVectoritem = 0, const Sbecore::ubigint x2RefWznmMPreset = 0, const Sbecore::ubigint stdRefWznmMStub = 0, const Sbecore::ubigint shoRefWznmMStub = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMControl;
	Sbecore::ubigint x1RefWznmMVectoritem;
	Sbecore::ubigint x2RefWznmMPreset;
	Sbecore::ubigint stdRefWznmMStub;
	Sbecore::ubigint shoRefWznmMStub;

public:
	bool operator==(const WznmJMControl& comp);
	bool operator!=(const WznmJMControl& comp);
};

/**
	* ListWznmJMControl: recordset of TblWznmJMControl
	*/
class ListWznmJMControl {

public:
	ListWznmJMControl();
	ListWznmJMControl(const ListWznmJMControl& src);
	~ListWznmJMControl();

	void clear();
	unsigned int size() const;
	void append(WznmJMControl* rec);

	WznmJMControl* operator[](const Sbecore::uint ix);
	ListWznmJMControl& operator=(const ListWznmJMControl& src);
	bool operator==(const ListWznmJMControl& comp);
	bool operator!=(const ListWznmJMControl& comp);

public:
	std::vector<WznmJMControl*> nodes;
};

/**
	* TblWznmJMControl: C++ wrapper for table TblWznmJMControl
	*/
class TblWznmJMControl {

public:

public:
	TblWznmJMControl();
	virtual ~TblWznmJMControl();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmJMControl** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMControl& rst);

	virtual Sbecore::ubigint insertRec(WznmJMControl* rec);
	Sbecore::ubigint insertNewRec(WznmJMControl** rec = NULL, const Sbecore::ubigint refWznmMControl = 0, const Sbecore::ubigint x1RefWznmMVectoritem = 0, const Sbecore::ubigint x2RefWznmMPreset = 0, const Sbecore::ubigint stdRefWznmMStub = 0, const Sbecore::ubigint shoRefWznmMStub = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmJMControl& rst, WznmJMControl** rec = NULL, const Sbecore::ubigint refWznmMControl = 0, const Sbecore::ubigint x1RefWznmMVectoritem = 0, const Sbecore::ubigint x2RefWznmMPreset = 0, const Sbecore::ubigint stdRefWznmMStub = 0, const Sbecore::ubigint shoRefWznmMStub = 0);
	virtual void insertRst(ListWznmJMControl& rst, bool transact = false);
	virtual void updateRec(WznmJMControl* rec);
	virtual void updateRst(ListWznmJMControl& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmJMControl** rec);
	virtual bool loadRecByConVit(Sbecore::ubigint refWznmMControl, Sbecore::ubigint x1RefWznmMVectoritem, WznmJMControl** rec);
	virtual Sbecore::ubigint loadRefsByCon(Sbecore::ubigint refWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCon(Sbecore::ubigint refWznmMControl, const bool append, ListWznmJMControl& rst);
	virtual bool loadStsByConVit(Sbecore::ubigint refWznmMControl, Sbecore::ubigint x1RefWznmMVectoritem, Sbecore::ubigint& stdRefWznmMStub);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmJMControl& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmJMControl: C++ wrapper for table TblWznmJMControl (MySQL database)
	*/
class MyTblWznmJMControl : public TblWznmJMControl, public Sbecore::MyTable {

public:
	MyTblWznmJMControl();
	~MyTblWznmJMControl();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMControl& rst);

	Sbecore::ubigint insertRec(WznmJMControl* rec);
	void insertRst(ListWznmJMControl& rst, bool transact = false);
	void updateRec(WznmJMControl* rec);
	void updateRst(ListWznmJMControl& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMControl** rec);
	bool loadRecByConVit(Sbecore::ubigint refWznmMControl, Sbecore::ubigint x1RefWznmMVectoritem, WznmJMControl** rec);
	Sbecore::ubigint loadRefsByCon(Sbecore::ubigint refWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refWznmMControl, const bool append, ListWznmJMControl& rst);
	bool loadStsByConVit(Sbecore::ubigint refWznmMControl, Sbecore::ubigint x1RefWznmMVectoritem, Sbecore::ubigint& stdRefWznmMStub);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmJMControl: C++ wrapper for table TblWznmJMControl (PgSQL database)
	*/
class PgTblWznmJMControl : public TblWznmJMControl, public Sbecore::PgTable {

public:
	PgTblWznmJMControl();
	~PgTblWznmJMControl();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmJMControl** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmJMControl& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmJMControl** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmJMControl& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmJMControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmJMControl& rst);

	Sbecore::ubigint insertRec(WznmJMControl* rec);
	void insertRst(ListWznmJMControl& rst, bool transact = false);
	void updateRec(WznmJMControl* rec);
	void updateRst(ListWznmJMControl& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmJMControl** rec);
	bool loadRecByConVit(Sbecore::ubigint refWznmMControl, Sbecore::ubigint x1RefWznmMVectoritem, WznmJMControl** rec);
	Sbecore::ubigint loadRefsByCon(Sbecore::ubigint refWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCon(Sbecore::ubigint refWznmMControl, const bool append, ListWznmJMControl& rst);
	bool loadStsByConVit(Sbecore::ubigint refWznmMControl, Sbecore::ubigint x1RefWznmMVectoritem, Sbecore::ubigint& stdRefWznmMStub);
};
#endif

#endif

