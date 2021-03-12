/**
	* \file WznmQPst1NQuerymod.h
	* Dbs and XML wrapper for table TblWznmQPst1NQuerymod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPST1NQUERYMOD_H
#define WZNMQPST1NQUERYMOD_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQPst1NQuerymod: record of TblWznmQPst1NQuerymod
	*/
class WznmQPst1NQuerymod {

public:
	WznmQPst1NQuerymod(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQPst1NQuerymod: recordset of TblWznmQPst1NQuerymod
	*/
class ListWznmQPst1NQuerymod {

public:
	ListWznmQPst1NQuerymod();
	ListWznmQPst1NQuerymod(const ListWznmQPst1NQuerymod& src);
	~ListWznmQPst1NQuerymod();

	void clear();
	unsigned int size() const;
	void append(WznmQPst1NQuerymod* rec);

	ListWznmQPst1NQuerymod& operator=(const ListWznmQPst1NQuerymod& src);

public:
	std::vector<WznmQPst1NQuerymod*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQPst1NQuerymod: C++ wrapper for table TblWznmQPst1NQuerymod
	*/
class TblWznmQPst1NQuerymod {

public:
	TblWznmQPst1NQuerymod();
	virtual ~TblWznmQPst1NQuerymod();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQPst1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPst1NQuerymod& rst);

	virtual Sbecore::ubigint insertRec(WznmQPst1NQuerymod* rec);
	Sbecore::ubigint insertNewRec(WznmQPst1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQPst1NQuerymod& rst, WznmQPst1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQPst1NQuerymod& rst);
	virtual void updateRec(WznmQPst1NQuerymod* rec);
	virtual void updateRst(ListWznmQPst1NQuerymod& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQPst1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPst1NQuerymod& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQPst1NQuerymod: C++ wrapper for table TblWznmQPst1NQuerymod (MySQL database)
	*/
class MyTblWznmQPst1NQuerymod : public TblWznmQPst1NQuerymod, public Sbecore::MyTable {

public:
	MyTblWznmQPst1NQuerymod();
	~MyTblWznmQPst1NQuerymod();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPst1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPst1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQPst1NQuerymod* rec);
	void insertRst(ListWznmQPst1NQuerymod& rst);
	void updateRec(WznmQPst1NQuerymod* rec);
	void updateRst(ListWznmQPst1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPst1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPst1NQuerymod& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQPst1NQuerymod: C++ wrapper for table TblWznmQPst1NQuerymod (PgSQL database)
	*/
class PgTblWznmQPst1NQuerymod : public TblWznmQPst1NQuerymod, public Sbecore::PgTable {

public:
	PgTblWznmQPst1NQuerymod();
	~PgTblWznmQPst1NQuerymod();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQPst1NQuerymod** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQPst1NQuerymod& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQPst1NQuerymod** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQPst1NQuerymod& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPst1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPst1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQPst1NQuerymod* rec);
	void insertRst(ListWznmQPst1NQuerymod& rst);
	void updateRec(WznmQPst1NQuerymod* rec);
	void updateRst(ListWznmQPst1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPst1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPst1NQuerymod& rst);
};
#endif

#endif
