/**
	* \file WznmMImpexpcplx.h
	* database access for table TblWznmMImpexpcplx (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMIMPEXPCPLX_H
#define WZNMMIMPEXPCPLX_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMImpexpcplx: record of TblWznmMImpexpcplx
	*/
class WznmMImpexpcplx {

public:
	WznmMImpexpcplx(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const std::string Short = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const std::string Minversion = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMVersion;
	Sbecore::ubigint refWznmMJob;
	std::string sref;
	std::string Short;
	Sbecore::ubigint refJTitle;
	std::string Title;
	std::string Minversion;
	std::string Comment;

public:
	bool operator==(const WznmMImpexpcplx& comp);
	bool operator!=(const WznmMImpexpcplx& comp);
};

/**
	* ListWznmMImpexpcplx: recordset of TblWznmMImpexpcplx
	*/
class ListWznmMImpexpcplx {

public:
	ListWznmMImpexpcplx();
	ListWznmMImpexpcplx(const ListWznmMImpexpcplx& src);
	~ListWznmMImpexpcplx();

	void clear();
	unsigned int size() const;
	void append(WznmMImpexpcplx* rec);

	WznmMImpexpcplx* operator[](const Sbecore::uint ix);
	ListWznmMImpexpcplx& operator=(const ListWznmMImpexpcplx& src);
	bool operator==(const ListWznmMImpexpcplx& comp);
	bool operator!=(const ListWznmMImpexpcplx& comp);

public:
	std::vector<WznmMImpexpcplx*> nodes;
};

/**
	* TblWznmMImpexpcplx: C++ wrapper for table TblWznmMImpexpcplx
	*/
class TblWznmMImpexpcplx {

public:

public:
	TblWznmMImpexpcplx();
	virtual ~TblWznmMImpexpcplx();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMImpexpcplx** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMImpexpcplx& rst);

	virtual Sbecore::ubigint insertRec(WznmMImpexpcplx* rec);
	Sbecore::ubigint insertNewRec(WznmMImpexpcplx** rec = NULL, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const std::string Short = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const std::string Minversion = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMImpexpcplx& rst, WznmMImpexpcplx** rec = NULL, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const std::string Short = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const std::string Minversion = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMImpexpcplx& rst, bool transact = false);
	virtual void updateRec(WznmMImpexpcplx* rec);
	virtual void updateRst(ListWznmMImpexpcplx& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMImpexpcplx** rec);
	virtual bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMImpexpcplx** rec);
	virtual bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMImpexpcplx& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMImpexpcplx& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMImpexpcplx: C++ wrapper for table TblWznmMImpexpcplx (MySQL database)
	*/
class MyTblWznmMImpexpcplx : public TblWznmMImpexpcplx, public Sbecore::MyTable {

public:
	MyTblWznmMImpexpcplx();
	~MyTblWznmMImpexpcplx();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMImpexpcplx** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMImpexpcplx& rst);

	Sbecore::ubigint insertRec(WznmMImpexpcplx* rec);
	void insertRst(ListWznmMImpexpcplx& rst, bool transact = false);
	void updateRec(WznmMImpexpcplx* rec);
	void updateRst(ListWznmMImpexpcplx& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMImpexpcplx** rec);
	bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMImpexpcplx** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMImpexpcplx& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMImpexpcplx: C++ wrapper for table TblWznmMImpexpcplx (PgSQL database)
	*/
class PgTblWznmMImpexpcplx : public TblWznmMImpexpcplx, public Sbecore::PgTable {

public:
	PgTblWznmMImpexpcplx();
	~PgTblWznmMImpexpcplx();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMImpexpcplx** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMImpexpcplx& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMImpexpcplx** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMImpexpcplx& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMImpexpcplx** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMImpexpcplx& rst);

	Sbecore::ubigint insertRec(WznmMImpexpcplx* rec);
	void insertRst(ListWznmMImpexpcplx& rst, bool transact = false);
	void updateRec(WznmMImpexpcplx* rec);
	void updateRst(ListWznmMImpexpcplx& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMImpexpcplx** rec);
	bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMImpexpcplx** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMImpexpcplx& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

