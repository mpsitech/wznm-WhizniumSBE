/**
	* \file WznmMUsergroup.h
	* database access for table TblWznmMUsergroup (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMUSERGROUP_H
#define WZNMMUSERGROUP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMUsergroup: record of TblWznmMUsergroup
	*/
class WznmMUsergroup {

public:
	WznmMUsergroup(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WznmMUsergroup& comp);
	bool operator!=(const WznmMUsergroup& comp);
};

/**
	* ListWznmMUsergroup: recordset of TblWznmMUsergroup
	*/
class ListWznmMUsergroup {

public:
	ListWznmMUsergroup();
	ListWznmMUsergroup(const ListWznmMUsergroup& src);
	~ListWznmMUsergroup();

	void clear();
	unsigned int size() const;
	void append(WznmMUsergroup* rec);

	WznmMUsergroup* operator[](const Sbecore::uint ix);
	ListWznmMUsergroup& operator=(const ListWznmMUsergroup& src);
	bool operator==(const ListWznmMUsergroup& comp);
	bool operator!=(const ListWznmMUsergroup& comp);

public:
	std::vector<WznmMUsergroup*> nodes;
};

/**
	* TblWznmMUsergroup: C++ wrapper for table TblWznmMUsergroup
	*/
class TblWznmMUsergroup {

public:

public:
	TblWznmMUsergroup();
	virtual ~TblWznmMUsergroup();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMUsergroup** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMUsergroup& rst);

	virtual Sbecore::ubigint insertRec(WznmMUsergroup* rec);
	Sbecore::ubigint insertNewRec(WznmMUsergroup** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMUsergroup& rst, WznmMUsergroup** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMUsergroup& rst, bool transact = false);
	virtual void updateRec(WznmMUsergroup* rec);
	virtual void updateRst(ListWznmMUsergroup& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMUsergroup** rec);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMUsergroup& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMUsergroup: C++ wrapper for table TblWznmMUsergroup (MySQL database)
	*/
class MyTblWznmMUsergroup : public TblWznmMUsergroup, public Sbecore::MyTable {

public:
	MyTblWznmMUsergroup();
	~MyTblWznmMUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMUsergroup& rst);

	Sbecore::ubigint insertRec(WznmMUsergroup* rec);
	void insertRst(ListWznmMUsergroup& rst, bool transact = false);
	void updateRec(WznmMUsergroup* rec);
	void updateRst(ListWznmMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMUsergroup** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMUsergroup: C++ wrapper for table TblWznmMUsergroup (PgSQL database)
	*/
class PgTblWznmMUsergroup : public TblWznmMUsergroup, public Sbecore::PgTable {

public:
	PgTblWznmMUsergroup();
	~PgTblWznmMUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMUsergroup** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMUsergroup& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMUsergroup** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMUsergroup** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMUsergroup& rst);

	Sbecore::ubigint insertRec(WznmMUsergroup* rec);
	void insertRst(ListWznmMUsergroup& rst, bool transact = false);
	void updateRec(WznmMUsergroup* rec);
	void updateRst(ListWznmMUsergroup& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMUsergroup** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

