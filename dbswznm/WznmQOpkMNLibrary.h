/**
	* \file WznmQOpkMNLibrary.h
	* Dbs and XML wrapper for table TblWznmQOpkMNLibrary (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPKMNLIBRARY_H
#define WZNMQOPKMNLIBRARY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpkMNLibrary: record of TblWznmQOpkMNLibrary
	*/
class WznmQOpkMNLibrary {

public:
	WznmQOpkMNLibrary(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQOpkMNLibrary: recordset of TblWznmQOpkMNLibrary
	*/
class ListWznmQOpkMNLibrary {

public:
	ListWznmQOpkMNLibrary();
	ListWznmQOpkMNLibrary(const ListWznmQOpkMNLibrary& src);
	~ListWznmQOpkMNLibrary();

	void clear();
	unsigned int size() const;
	void append(WznmQOpkMNLibrary* rec);

	ListWznmQOpkMNLibrary& operator=(const ListWznmQOpkMNLibrary& src);

public:
	std::vector<WznmQOpkMNLibrary*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpkMNLibrary: C++ wrapper for table TblWznmQOpkMNLibrary
	*/
class TblWznmQOpkMNLibrary {

public:
	TblWznmQOpkMNLibrary();
	virtual ~TblWznmQOpkMNLibrary();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpkMNLibrary** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkMNLibrary& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpkMNLibrary* rec);
	Sbecore::ubigint insertNewRec(WznmQOpkMNLibrary** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpkMNLibrary& rst, WznmQOpkMNLibrary** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQOpkMNLibrary& rst);
	virtual void updateRec(WznmQOpkMNLibrary* rec);
	virtual void updateRst(ListWznmQOpkMNLibrary& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkMNLibrary** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkMNLibrary& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpkMNLibrary: C++ wrapper for table TblWznmQOpkMNLibrary (MySQL database)
	*/
class MyTblWznmQOpkMNLibrary : public TblWznmQOpkMNLibrary, public Sbecore::MyTable {

public:
	MyTblWznmQOpkMNLibrary();
	~MyTblWznmQOpkMNLibrary();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkMNLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkMNLibrary& rst);

	Sbecore::ubigint insertRec(WznmQOpkMNLibrary* rec);
	void insertRst(ListWznmQOpkMNLibrary& rst);
	void updateRec(WznmQOpkMNLibrary* rec);
	void updateRst(ListWznmQOpkMNLibrary& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkMNLibrary** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkMNLibrary& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpkMNLibrary: C++ wrapper for table TblWznmQOpkMNLibrary (PgSQL database)
	*/
class PgTblWznmQOpkMNLibrary : public TblWznmQOpkMNLibrary, public Sbecore::PgTable {

public:
	PgTblWznmQOpkMNLibrary();
	~PgTblWznmQOpkMNLibrary();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpkMNLibrary** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpkMNLibrary& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpkMNLibrary** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpkMNLibrary& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkMNLibrary** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkMNLibrary& rst);

	Sbecore::ubigint insertRec(WznmQOpkMNLibrary* rec);
	void insertRst(ListWznmQOpkMNLibrary& rst);
	void updateRec(WznmQOpkMNLibrary* rec);
	void updateRst(ListWznmQOpkMNLibrary& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkMNLibrary** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkMNLibrary& rst);
};
#endif

#endif
