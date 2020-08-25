/**
	* \file WznmQTblPst1NQuerymod.h
	* Dbs and XML wrapper for table TblWznmQTblPst1NQuerymod (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQTBLPST1NQUERYMOD_H
#define WZNMQTBLPST1NQUERYMOD_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblPst1NQuerymod: record of TblWznmQTblPst1NQuerymod
	*/
class WznmQTblPst1NQuerymod {

public:
	WznmQTblPst1NQuerymod(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTblPst1NQuerymod: recordset of TblWznmQTblPst1NQuerymod
	*/
class ListWznmQTblPst1NQuerymod {

public:
	ListWznmQTblPst1NQuerymod();
	ListWznmQTblPst1NQuerymod(const ListWznmQTblPst1NQuerymod& src);
	~ListWznmQTblPst1NQuerymod();

	void clear();
	unsigned int size() const;
	void append(WznmQTblPst1NQuerymod* rec);

	ListWznmQTblPst1NQuerymod& operator=(const ListWznmQTblPst1NQuerymod& src);

public:
	std::vector<WznmQTblPst1NQuerymod*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblPst1NQuerymod: C++ wrapper for table TblWznmQTblPst1NQuerymod
	*/
class TblWznmQTblPst1NQuerymod {

public:
	TblWznmQTblPst1NQuerymod();
	virtual ~TblWznmQTblPst1NQuerymod();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblPst1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblPst1NQuerymod& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblPst1NQuerymod* rec);
	Sbecore::ubigint insertNewRec(WznmQTblPst1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblPst1NQuerymod& rst, WznmQTblPst1NQuerymod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTblPst1NQuerymod& rst);
	virtual void updateRec(WznmQTblPst1NQuerymod* rec);
	virtual void updateRst(ListWznmQTblPst1NQuerymod& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblPst1NQuerymod** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblPst1NQuerymod& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblPst1NQuerymod: C++ wrapper for table TblWznmQTblPst1NQuerymod (MySQL database)
	*/
class MyTblWznmQTblPst1NQuerymod : public TblWznmQTblPst1NQuerymod, public Sbecore::MyTable {

public:
	MyTblWznmQTblPst1NQuerymod();
	~MyTblWznmQTblPst1NQuerymod();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblPst1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblPst1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQTblPst1NQuerymod* rec);
	void insertRst(ListWznmQTblPst1NQuerymod& rst);
	void updateRec(WznmQTblPst1NQuerymod* rec);
	void updateRst(ListWznmQTblPst1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblPst1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblPst1NQuerymod& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblPst1NQuerymod: C++ wrapper for table TblWznmQTblPst1NQuerymod (PgSQL database)
	*/
class PgTblWznmQTblPst1NQuerymod : public TblWznmQTblPst1NQuerymod, public Sbecore::PgTable {

public:
	PgTblWznmQTblPst1NQuerymod();
	~PgTblWznmQTblPst1NQuerymod();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblPst1NQuerymod** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblPst1NQuerymod& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblPst1NQuerymod** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblPst1NQuerymod& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblPst1NQuerymod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblPst1NQuerymod& rst);

	Sbecore::ubigint insertRec(WznmQTblPst1NQuerymod* rec);
	void insertRst(ListWznmQTblPst1NQuerymod& rst);
	void updateRec(WznmQTblPst1NQuerymod* rec);
	void updateRst(ListWznmQTblPst1NQuerymod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblPst1NQuerymod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblPst1NQuerymod& rst);
};
#endif

#endif

