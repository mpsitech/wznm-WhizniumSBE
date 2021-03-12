/**
	* \file WznmQTblRef1NQuerymod.h
	* Dbs and XML wrapper for table TblWznmQTblRef1NQuerymod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTBLREF1NQUERYMOD_H
#define WZNMQTBLREF1NQUERYMOD_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblRef1NQuerymod: record of TblWznmQTblRef1NQuerymod
	*/
class WznmQTblRef1NQuerymod {

public:
	WznmQTblRef1NQuerymod(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQTblRef1NQuerymod: recordset of TblWznmQTblRef1NQuerymod
	*/
class ListWznmQTblRef1NQuerymod {

public:
	ListWznmQTblRef1NQuerymod();
	ListWznmQTblRef1NQuerymod(const ListWznmQTblRef1NQuerymod& src);
	~ListWznmQTblRef1NQuerymod();

	void clear();
	unsigned int size() const;
	void append(WznmQTblRef1NQuerymod* rec);

	ListWznmQTblRef1NQuerymod& operator=(const ListWznmQTblRef1NQuerymod& src);

public:
	std::vector<WznmQTblRef1NQuerymod*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblRef1NQuerymod: C++ wrapper for table TblWznmQTblRef1NQuerymod
	*/
class TblWznmQTblRef1NQuerymod {

public:
	TblWznmQTblRef1NQuerymod();
	virtual ~TblWznmQTblRef1NQuerymod();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NQuerymod& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblRef1NQuerymod* rec);
	Sbecore::ubigint insertNewRec(WznmQTblRef1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblRef1NQuerymod& rst, WznmQTblRef1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTblRef1NQuerymod& rst);
	virtual void updateRec(WznmQTblRef1NQuerymod* rec);
	virtual void updateRst(ListWznmQTblRef1NQuerymod& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NQuerymod& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblRef1NQuerymod: C++ wrapper for table TblWznmQTblRef1NQuerymod (MySQL database)
	*/
class MyTblWznmQTblRef1NQuerymod : public TblWznmQTblRef1NQuerymod, public Sbecore::MyTable {

public:
	MyTblWznmQTblRef1NQuerymod();
	~MyTblWznmQTblRef1NQuerymod();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQTblRef1NQuerymod* rec);
	void insertRst(ListWznmQTblRef1NQuerymod& rst);
	void updateRec(WznmQTblRef1NQuerymod* rec);
	void updateRst(ListWznmQTblRef1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NQuerymod& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblRef1NQuerymod: C++ wrapper for table TblWznmQTblRef1NQuerymod (PgSQL database)
	*/
class PgTblWznmQTblRef1NQuerymod : public TblWznmQTblRef1NQuerymod, public Sbecore::PgTable {

public:
	PgTblWznmQTblRef1NQuerymod();
	~PgTblWznmQTblRef1NQuerymod();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblRef1NQuerymod** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblRef1NQuerymod& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblRef1NQuerymod** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblRef1NQuerymod& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQTblRef1NQuerymod* rec);
	void insertRst(ListWznmQTblRef1NQuerymod& rst);
	void updateRec(WznmQTblRef1NQuerymod* rec);
	void updateRst(ListWznmQTblRef1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NQuerymod& rst);
};
#endif

#endif
