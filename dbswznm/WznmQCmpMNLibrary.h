/**
	* \file WznmQCmpMNLibrary.h
	* Dbs and XML wrapper for table TblWznmQCmpMNLibrary (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQCMPMNLIBRARY_H
#define WZNMQCMPMNLIBRARY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCmpMNLibrary: record of TblWznmQCmpMNLibrary
	*/
class WznmQCmpMNLibrary {

public:
	WznmQCmpMNLibrary(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQCmpMNLibrary: recordset of TblWznmQCmpMNLibrary
	*/
class ListWznmQCmpMNLibrary {

public:
	ListWznmQCmpMNLibrary();
	ListWznmQCmpMNLibrary(const ListWznmQCmpMNLibrary& src);
	~ListWznmQCmpMNLibrary();

	void clear();
	unsigned int size() const;
	void append(WznmQCmpMNLibrary* rec);

	ListWznmQCmpMNLibrary& operator=(const ListWznmQCmpMNLibrary& src);

public:
	std::vector<WznmQCmpMNLibrary*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCmpMNLibrary: C++ wrapper for table TblWznmQCmpMNLibrary
	*/
class TblWznmQCmpMNLibrary {

public:
	TblWznmQCmpMNLibrary();
	virtual ~TblWznmQCmpMNLibrary();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCmpMNLibrary** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCmpMNLibrary& rst);

	virtual Sbecore::ubigint insertRec(WznmQCmpMNLibrary* rec);
	Sbecore::ubigint insertNewRec(WznmQCmpMNLibrary** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQCmpMNLibrary& rst, WznmQCmpMNLibrary** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQCmpMNLibrary& rst);
	virtual void updateRec(WznmQCmpMNLibrary* rec);
	virtual void updateRst(ListWznmQCmpMNLibrary& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCmpMNLibrary** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCmpMNLibrary& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCmpMNLibrary: C++ wrapper for table TblWznmQCmpMNLibrary (MySQL database)
	*/
class MyTblWznmQCmpMNLibrary : public TblWznmQCmpMNLibrary, public Sbecore::MyTable {

public:
	MyTblWznmQCmpMNLibrary();
	~MyTblWznmQCmpMNLibrary();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCmpMNLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCmpMNLibrary& rst);

	Sbecore::ubigint insertRec(WznmQCmpMNLibrary* rec);
	void insertRst(ListWznmQCmpMNLibrary& rst);
	void updateRec(WznmQCmpMNLibrary* rec);
	void updateRst(ListWznmQCmpMNLibrary& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCmpMNLibrary** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCmpMNLibrary& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCmpMNLibrary: C++ wrapper for table TblWznmQCmpMNLibrary (PgSQL database)
	*/
class PgTblWznmQCmpMNLibrary : public TblWznmQCmpMNLibrary, public Sbecore::PgTable {

public:
	PgTblWznmQCmpMNLibrary();
	~PgTblWznmQCmpMNLibrary();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCmpMNLibrary** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCmpMNLibrary& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCmpMNLibrary** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCmpMNLibrary& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCmpMNLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCmpMNLibrary& rst);

	Sbecore::ubigint insertRec(WznmQCmpMNLibrary* rec);
	void insertRst(ListWznmQCmpMNLibrary& rst);
	void updateRec(WznmQCmpMNLibrary* rec);
	void updateRst(ListWznmQCmpMNLibrary& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCmpMNLibrary** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCmpMNLibrary& rst);
};
#endif

#endif

