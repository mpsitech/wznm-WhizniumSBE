/**
	* \file WznmMProject.h
	* database access for table TblWznmMProject (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMPROJECT_H
#define WZNMMPROJECT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMProject: record of TblWznmMProject
	*/
class WznmMProject {

public:
	WznmMProject(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string Short = "", const std::string Title = "", const std::string Giturl = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refWznmMVersion;
	std::string Short;
	std::string Title;
	std::string Giturl;
	std::string Comment;

public:
	bool operator==(const WznmMProject& comp);
	bool operator!=(const WznmMProject& comp);
};

/**
	* ListWznmMProject: recordset of TblWznmMProject
	*/
class ListWznmMProject {

public:
	ListWznmMProject();
	ListWznmMProject(const ListWznmMProject& src);
	~ListWznmMProject();

	void clear();
	unsigned int size() const;
	void append(WznmMProject* rec);

	WznmMProject* operator[](const Sbecore::uint ix);
	ListWznmMProject& operator=(const ListWznmMProject& src);
	bool operator==(const ListWznmMProject& comp);
	bool operator!=(const ListWznmMProject& comp);

public:
	std::vector<WznmMProject*> nodes;
};

/**
	* TblWznmMProject: C++ wrapper for table TblWznmMProject
	*/
class TblWznmMProject {

public:

public:
	TblWznmMProject();
	virtual ~TblWznmMProject();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMProject** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMProject& rst);

	virtual Sbecore::ubigint insertRec(WznmMProject* rec);
	Sbecore::ubigint insertNewRec(WznmMProject** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string Short = "", const std::string Title = "", const std::string Giturl = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMProject& rst, WznmMProject** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string Short = "", const std::string Title = "", const std::string Giturl = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMProject& rst, bool transact = false);
	virtual void updateRec(WznmMProject* rec);
	virtual void updateRst(ListWznmMProject& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMProject** rec);
	virtual bool loadShoByRef(Sbecore::ubigint ref, std::string& Short);
	virtual bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMProject& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMProject: C++ wrapper for table TblWznmMProject (MySQL database)
	*/
class MyTblWznmMProject : public TblWznmMProject, public Sbecore::MyTable {

public:
	MyTblWznmMProject();
	~MyTblWznmMProject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMProject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMProject& rst);

	Sbecore::ubigint insertRec(WznmMProject* rec);
	void insertRst(ListWznmMProject& rst, bool transact = false);
	void updateRec(WznmMProject* rec);
	void updateRst(ListWznmMProject& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMProject** rec);
	bool loadShoByRef(Sbecore::ubigint ref, std::string& Short);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMProject: C++ wrapper for table TblWznmMProject (PgSQL database)
	*/
class PgTblWznmMProject : public TblWznmMProject, public Sbecore::PgTable {

public:
	PgTblWznmMProject();
	~PgTblWznmMProject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMProject** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMProject& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMProject** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMProject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMProject& rst);

	Sbecore::ubigint insertRec(WznmMProject* rec);
	void insertRst(ListWznmMProject& rst, bool transact = false);
	void updateRec(WznmMProject* rec);
	void updateRst(ListWznmMProject& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMProject** rec);
	bool loadShoByRef(Sbecore::ubigint ref, std::string& Short);
	bool loadTitByRef(Sbecore::ubigint ref, std::string& Title);
};
#endif

#endif

