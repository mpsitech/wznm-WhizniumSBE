/**
	* \file WznmQSbsPst1NQuerymod.h
	* Dbs and XML wrapper for table TblWznmQSbsPst1NQuerymod (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSBSPST1NQUERYMOD_H
#define WZNMQSBSPST1NQUERYMOD_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSbsPst1NQuerymod: record of TblWznmQSbsPst1NQuerymod
	*/
class WznmQSbsPst1NQuerymod {

public:
	WznmQSbsPst1NQuerymod(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQSbsPst1NQuerymod: recordset of TblWznmQSbsPst1NQuerymod
	*/
class ListWznmQSbsPst1NQuerymod {

public:
	ListWznmQSbsPst1NQuerymod();
	ListWznmQSbsPst1NQuerymod(const ListWznmQSbsPst1NQuerymod& src);
	~ListWznmQSbsPst1NQuerymod();

	void clear();
	unsigned int size() const;
	void append(WznmQSbsPst1NQuerymod* rec);

	ListWznmQSbsPst1NQuerymod& operator=(const ListWznmQSbsPst1NQuerymod& src);

public:
	std::vector<WznmQSbsPst1NQuerymod*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSbsPst1NQuerymod: C++ wrapper for table TblWznmQSbsPst1NQuerymod
	*/
class TblWznmQSbsPst1NQuerymod {

public:
	TblWznmQSbsPst1NQuerymod();
	virtual ~TblWznmQSbsPst1NQuerymod();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSbsPst1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsPst1NQuerymod& rst);

	virtual Sbecore::ubigint insertRec(WznmQSbsPst1NQuerymod* rec);
	Sbecore::ubigint insertNewRec(WznmQSbsPst1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSbsPst1NQuerymod& rst, WznmQSbsPst1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQSbsPst1NQuerymod& rst);
	virtual void updateRec(WznmQSbsPst1NQuerymod* rec);
	virtual void updateRst(ListWznmQSbsPst1NQuerymod& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsPst1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsPst1NQuerymod& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSbsPst1NQuerymod: C++ wrapper for table TblWznmQSbsPst1NQuerymod (MySQL database)
	*/
class MyTblWznmQSbsPst1NQuerymod : public TblWznmQSbsPst1NQuerymod, public Sbecore::MyTable {

public:
	MyTblWznmQSbsPst1NQuerymod();
	~MyTblWznmQSbsPst1NQuerymod();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsPst1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsPst1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQSbsPst1NQuerymod* rec);
	void insertRst(ListWznmQSbsPst1NQuerymod& rst);
	void updateRec(WznmQSbsPst1NQuerymod* rec);
	void updateRst(ListWznmQSbsPst1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsPst1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsPst1NQuerymod& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSbsPst1NQuerymod: C++ wrapper for table TblWznmQSbsPst1NQuerymod (PgSQL database)
	*/
class PgTblWznmQSbsPst1NQuerymod : public TblWznmQSbsPst1NQuerymod, public Sbecore::PgTable {

public:
	PgTblWznmQSbsPst1NQuerymod();
	~PgTblWznmQSbsPst1NQuerymod();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSbsPst1NQuerymod** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSbsPst1NQuerymod& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSbsPst1NQuerymod** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSbsPst1NQuerymod& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsPst1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsPst1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQSbsPst1NQuerymod* rec);
	void insertRst(ListWznmQSbsPst1NQuerymod& rst);
	void updateRec(WznmQSbsPst1NQuerymod* rec);
	void updateRst(ListWznmQSbsPst1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsPst1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsPst1NQuerymod& rst);
};
#endif

#endif

