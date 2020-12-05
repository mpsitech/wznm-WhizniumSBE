/**
	* \file WznmQTcoRef1NQuerymod.h
	* Dbs and XML wrapper for table TblWznmQTcoRef1NQuerymod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTCOREF1NQUERYMOD_H
#define WZNMQTCOREF1NQUERYMOD_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTcoRef1NQuerymod: record of TblWznmQTcoRef1NQuerymod
	*/
class WznmQTcoRef1NQuerymod {

public:
	WznmQTcoRef1NQuerymod(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQTcoRef1NQuerymod: recordset of TblWznmQTcoRef1NQuerymod
	*/
class ListWznmQTcoRef1NQuerymod {

public:
	ListWznmQTcoRef1NQuerymod();
	ListWznmQTcoRef1NQuerymod(const ListWznmQTcoRef1NQuerymod& src);
	~ListWznmQTcoRef1NQuerymod();

	void clear();
	unsigned int size() const;
	void append(WznmQTcoRef1NQuerymod* rec);

	ListWznmQTcoRef1NQuerymod& operator=(const ListWznmQTcoRef1NQuerymod& src);

public:
	std::vector<WznmQTcoRef1NQuerymod*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTcoRef1NQuerymod: C++ wrapper for table TblWznmQTcoRef1NQuerymod
	*/
class TblWznmQTcoRef1NQuerymod {

public:
	TblWznmQTcoRef1NQuerymod();
	virtual ~TblWznmQTcoRef1NQuerymod();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTcoRef1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTcoRef1NQuerymod& rst);

	virtual Sbecore::ubigint insertRec(WznmQTcoRef1NQuerymod* rec);
	Sbecore::ubigint insertNewRec(WznmQTcoRef1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTcoRef1NQuerymod& rst, WznmQTcoRef1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTcoRef1NQuerymod& rst);
	virtual void updateRec(WznmQTcoRef1NQuerymod* rec);
	virtual void updateRst(ListWznmQTcoRef1NQuerymod& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTcoRef1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTcoRef1NQuerymod& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTcoRef1NQuerymod: C++ wrapper for table TblWznmQTcoRef1NQuerymod (MySQL database)
	*/
class MyTblWznmQTcoRef1NQuerymod : public TblWznmQTcoRef1NQuerymod, public Sbecore::MyTable {

public:
	MyTblWznmQTcoRef1NQuerymod();
	~MyTblWznmQTcoRef1NQuerymod();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTcoRef1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTcoRef1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQTcoRef1NQuerymod* rec);
	void insertRst(ListWznmQTcoRef1NQuerymod& rst);
	void updateRec(WznmQTcoRef1NQuerymod* rec);
	void updateRst(ListWznmQTcoRef1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTcoRef1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTcoRef1NQuerymod& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTcoRef1NQuerymod: C++ wrapper for table TblWznmQTcoRef1NQuerymod (PgSQL database)
	*/
class PgTblWznmQTcoRef1NQuerymod : public TblWznmQTcoRef1NQuerymod, public Sbecore::PgTable {

public:
	PgTblWznmQTcoRef1NQuerymod();
	~PgTblWznmQTcoRef1NQuerymod();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTcoRef1NQuerymod** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTcoRef1NQuerymod& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTcoRef1NQuerymod** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTcoRef1NQuerymod& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTcoRef1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTcoRef1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQTcoRef1NQuerymod* rec);
	void insertRst(ListWznmQTcoRef1NQuerymod& rst);
	void updateRec(WznmQTcoRef1NQuerymod* rec);
	void updateRst(ListWznmQTcoRef1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTcoRef1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTcoRef1NQuerymod& rst);
};
#endif

#endif

