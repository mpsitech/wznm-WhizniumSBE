/**
	* \file WznmAVControlPar.h
	* database access for table TblWznmAVControlPar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAVCONTROLPAR_H
#define WZNMAVCONTROLPAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmAVControlPar: record of TblWznmAVControlPar
	*/
class WznmAVControlPar {

public:
	WznmAVControlPar(const Sbecore::ubigint ref = 0, const Sbecore::uint ixWznmVControl = 0, const Sbecore::ubigint x1RefWznmMUser = 0, const Sbecore::uint x2IxWznmVLocale = 0, const std::string Par = "", const std::string Val = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixWznmVControl;
	Sbecore::ubigint x1RefWznmMUser;
	Sbecore::uint x2IxWznmVLocale;
	std::string Par;
	std::string Val;

public:
	bool operator==(const WznmAVControlPar& comp);
	bool operator!=(const WznmAVControlPar& comp);
};

/**
	* ListWznmAVControlPar: recordset of TblWznmAVControlPar
	*/
class ListWznmAVControlPar {

public:
	ListWznmAVControlPar();
	ListWznmAVControlPar(const ListWznmAVControlPar& src);
	~ListWznmAVControlPar();

	void clear();
	unsigned int size() const;
	void append(WznmAVControlPar* rec);

	WznmAVControlPar* operator[](const Sbecore::uint ix);
	ListWznmAVControlPar& operator=(const ListWznmAVControlPar& src);
	bool operator==(const ListWznmAVControlPar& comp);
	bool operator!=(const ListWznmAVControlPar& comp);

public:
	std::vector<WznmAVControlPar*> nodes;
};

/**
	* TblWznmAVControlPar: C++ wrapper for table TblWznmAVControlPar
	*/
class TblWznmAVControlPar {

public:

public:
	TblWznmAVControlPar();
	virtual ~TblWznmAVControlPar();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAVControlPar** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAVControlPar& rst);

	virtual Sbecore::ubigint insertRec(WznmAVControlPar* rec);
	Sbecore::ubigint insertNewRec(WznmAVControlPar** rec = NULL, const Sbecore::uint ixWznmVControl = 0, const Sbecore::ubigint x1RefWznmMUser = 0, const Sbecore::uint x2IxWznmVLocale = 0, const std::string Par = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAVControlPar& rst, WznmAVControlPar** rec = NULL, const Sbecore::uint ixWznmVControl = 0, const Sbecore::ubigint x1RefWznmMUser = 0, const Sbecore::uint x2IxWznmVLocale = 0, const std::string Par = "", const std::string Val = "");
	virtual void insertRst(ListWznmAVControlPar& rst, bool transact = false);
	virtual void updateRec(WznmAVControlPar* rec);
	virtual void updateRst(ListWznmAVControlPar& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAVControlPar** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAVControlPar& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAVControlPar: C++ wrapper for table TblWznmAVControlPar (MySQL database)
	*/
class MyTblWznmAVControlPar : public TblWznmAVControlPar, public Sbecore::MyTable {

public:
	MyTblWznmAVControlPar();
	~MyTblWznmAVControlPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAVControlPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAVControlPar& rst);

	Sbecore::ubigint insertRec(WznmAVControlPar* rec);
	void insertRst(ListWznmAVControlPar& rst, bool transact = false);
	void updateRec(WznmAVControlPar* rec);
	void updateRst(ListWznmAVControlPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAVControlPar** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAVControlPar: C++ wrapper for table TblWznmAVControlPar (PgSQL database)
	*/
class PgTblWznmAVControlPar : public TblWznmAVControlPar, public Sbecore::PgTable {

public:
	PgTblWznmAVControlPar();
	~PgTblWznmAVControlPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAVControlPar** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAVControlPar& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAVControlPar** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAVControlPar** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAVControlPar& rst);

	Sbecore::ubigint insertRec(WznmAVControlPar* rec);
	void insertRst(ListWznmAVControlPar& rst, bool transact = false);
	void updateRec(WznmAVControlPar* rec);
	void updateRst(ListWznmAVControlPar& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAVControlPar** rec);
};
#endif

#endif
