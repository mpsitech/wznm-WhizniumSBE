/**
	* \file WznmMLibrary.h
	* database access for table TblWznmMLibrary (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMLIBRARY_H
#define WZNMMLIBRARY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMLibrary: record of TblWznmMLibrary
	*/
class WznmMLibrary {

public:
	WznmMLibrary(const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Title = "", const std::string Version = "", const std::string srefKLictype = "", const std::string depSrefsWznmMLibrary = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	std::string sref;
	std::string Title;
	std::string Version;
	std::string srefKLictype;
	std::string depSrefsWznmMLibrary;
	std::string Comment;

public:
	bool operator==(const WznmMLibrary& comp);
	bool operator!=(const WznmMLibrary& comp);
};

/**
	* ListWznmMLibrary: recordset of TblWznmMLibrary
	*/
class ListWznmMLibrary {

public:
	ListWznmMLibrary();
	ListWznmMLibrary(const ListWznmMLibrary& src);
	~ListWznmMLibrary();

	void clear();
	unsigned int size() const;
	void append(WznmMLibrary* rec);

	WznmMLibrary* operator[](const Sbecore::uint ix);
	ListWznmMLibrary& operator=(const ListWznmMLibrary& src);
	bool operator==(const ListWznmMLibrary& comp);
	bool operator!=(const ListWznmMLibrary& comp);

public:
	std::vector<WznmMLibrary*> nodes;
};

/**
	* TblWznmMLibrary: C++ wrapper for table TblWznmMLibrary
	*/
class TblWznmMLibrary {

public:

public:
	TblWznmMLibrary();
	virtual ~TblWznmMLibrary();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMLibrary** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMLibrary& rst);

	virtual Sbecore::ubigint insertRec(WznmMLibrary* rec);
	Sbecore::ubigint insertNewRec(WznmMLibrary** rec = NULL, const std::string sref = "", const std::string Title = "", const std::string Version = "", const std::string srefKLictype = "", const std::string depSrefsWznmMLibrary = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMLibrary& rst, WznmMLibrary** rec = NULL, const std::string sref = "", const std::string Title = "", const std::string Version = "", const std::string srefKLictype = "", const std::string depSrefsWznmMLibrary = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMLibrary& rst, bool transact = false);
	virtual void updateRec(WznmMLibrary* rec);
	virtual void updateRst(ListWznmMLibrary& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMLibrary** rec);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMLibrary& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMLibrary: C++ wrapper for table TblWznmMLibrary (MySQL database)
	*/
class MyTblWznmMLibrary : public TblWznmMLibrary, public Sbecore::MyTable {

public:
	MyTblWznmMLibrary();
	~MyTblWznmMLibrary();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMLibrary& rst);

	Sbecore::ubigint insertRec(WznmMLibrary* rec);
	void insertRst(ListWznmMLibrary& rst, bool transact = false);
	void updateRec(WznmMLibrary* rec);
	void updateRst(ListWznmMLibrary& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMLibrary** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMLibrary: C++ wrapper for table TblWznmMLibrary (PgSQL database)
	*/
class PgTblWznmMLibrary : public TblWznmMLibrary, public Sbecore::PgTable {

public:
	PgTblWznmMLibrary();
	~PgTblWznmMLibrary();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMLibrary** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMLibrary& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMLibrary** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMLibrary& rst);

	Sbecore::ubigint insertRec(WznmMLibrary* rec);
	void insertRst(ListWznmMLibrary& rst, bool transact = false);
	void updateRec(WznmMLibrary* rec);
	void updateRst(ListWznmMLibrary& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMLibrary** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

