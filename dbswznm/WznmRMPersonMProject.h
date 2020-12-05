/**
	* \file WznmRMPersonMProject.h
	* database access for table TblWznmRMPersonMProject (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMRMPERSONMPROJECT_H
#define WZNMRMPERSONMPROJECT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMPersonMProject: record of TblWznmRMPersonMProject
	*/
class WznmRMPersonMProject {

public:
	WznmRMPersonMProject(const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const Sbecore::uint x1Stopd = 0, const Sbecore::ubigint refWznmMPerson = 0, const Sbecore::ubigint refWznmMProject = 0, const std::string srefKFunction = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint x1Startd;
	Sbecore::uint x1Stopd;
	Sbecore::ubigint refWznmMPerson;
	Sbecore::ubigint refWznmMProject;
	std::string srefKFunction;

public:
	bool operator==(const WznmRMPersonMProject& comp);
	bool operator!=(const WznmRMPersonMProject& comp);
};

/**
	* ListWznmRMPersonMProject: recordset of TblWznmRMPersonMProject
	*/
class ListWznmRMPersonMProject {

public:
	ListWznmRMPersonMProject();
	ListWznmRMPersonMProject(const ListWznmRMPersonMProject& src);
	~ListWznmRMPersonMProject();

	void clear();
	unsigned int size() const;
	void append(WznmRMPersonMProject* rec);

	WznmRMPersonMProject* operator[](const Sbecore::uint ix);
	ListWznmRMPersonMProject& operator=(const ListWznmRMPersonMProject& src);
	bool operator==(const ListWznmRMPersonMProject& comp);
	bool operator!=(const ListWznmRMPersonMProject& comp);

public:
	std::vector<WznmRMPersonMProject*> nodes;
};

/**
	* TblWznmRMPersonMProject: C++ wrapper for table TblWznmRMPersonMProject
	*/
class TblWznmRMPersonMProject {

public:

public:
	TblWznmRMPersonMProject();
	virtual ~TblWznmRMPersonMProject();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMPersonMProject** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMPersonMProject& rst);

	virtual Sbecore::ubigint insertRec(WznmRMPersonMProject* rec);
	Sbecore::ubigint insertNewRec(WznmRMPersonMProject** rec = NULL, const Sbecore::uint x1Startd = 0, const Sbecore::uint x1Stopd = 0, const Sbecore::ubigint refWznmMPerson = 0, const Sbecore::ubigint refWznmMProject = 0, const std::string srefKFunction = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmRMPersonMProject& rst, WznmRMPersonMProject** rec = NULL, const Sbecore::uint x1Startd = 0, const Sbecore::uint x1Stopd = 0, const Sbecore::ubigint refWznmMPerson = 0, const Sbecore::ubigint refWznmMProject = 0, const std::string srefKFunction = "");
	virtual void insertRst(ListWznmRMPersonMProject& rst, bool transact = false);
	virtual void updateRec(WznmRMPersonMProject* rec);
	virtual void updateRst(ListWznmRMPersonMProject& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMPersonMProject** rec);
	virtual Sbecore::ubigint loadRefsByPrj(Sbecore::ubigint refWznmMProject, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByPrj(Sbecore::ubigint refWznmMProject, const bool append, ListWznmRMPersonMProject& rst);
	virtual Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWznmMPerson, const bool append, ListWznmRMPersonMProject& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMPersonMProject& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMPersonMProject: C++ wrapper for table TblWznmRMPersonMProject (MySQL database)
	*/
class MyTblWznmRMPersonMProject : public TblWznmRMPersonMProject, public Sbecore::MyTable {

public:
	MyTblWznmRMPersonMProject();
	~MyTblWznmRMPersonMProject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMPersonMProject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMPersonMProject& rst);

	Sbecore::ubigint insertRec(WznmRMPersonMProject* rec);
	void insertRst(ListWznmRMPersonMProject& rst, bool transact = false);
	void updateRec(WznmRMPersonMProject* rec);
	void updateRst(ListWznmRMPersonMProject& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMPersonMProject** rec);
	Sbecore::ubigint loadRefsByPrj(Sbecore::ubigint refWznmMProject, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrj(Sbecore::ubigint refWznmMProject, const bool append, ListWznmRMPersonMProject& rst);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWznmMPerson, const bool append, ListWznmRMPersonMProject& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMPersonMProject: C++ wrapper for table TblWznmRMPersonMProject (PgSQL database)
	*/
class PgTblWznmRMPersonMProject : public TblWznmRMPersonMProject, public Sbecore::PgTable {

public:
	PgTblWznmRMPersonMProject();
	~PgTblWznmRMPersonMProject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMPersonMProject** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMPersonMProject& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMPersonMProject** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmRMPersonMProject& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMPersonMProject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMPersonMProject& rst);

	Sbecore::ubigint insertRec(WznmRMPersonMProject* rec);
	void insertRst(ListWznmRMPersonMProject& rst, bool transact = false);
	void updateRec(WznmRMPersonMProject* rec);
	void updateRst(ListWznmRMPersonMProject& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMPersonMProject** rec);
	Sbecore::ubigint loadRefsByPrj(Sbecore::ubigint refWznmMProject, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByPrj(Sbecore::ubigint refWznmMProject, const bool append, ListWznmRMPersonMProject& rst);
	Sbecore::ubigint loadRstByPrs(Sbecore::ubigint refWznmMPerson, const bool append, ListWznmRMPersonMProject& rst);
};
#endif

#endif

