/**
	* \file WznmQTco1NImpexpcol.h
	* Dbs and XML wrapper for table TblWznmQTco1NImpexpcol (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQTCO1NIMPEXPCOL_H
#define WZNMQTCO1NIMPEXPCOL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTco1NImpexpcol: record of TblWznmQTco1NImpexpcol
	*/
class WznmQTco1NImpexpcol {

public:
	WznmQTco1NImpexpcol(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTco1NImpexpcol: recordset of TblWznmQTco1NImpexpcol
	*/
class ListWznmQTco1NImpexpcol {

public:
	ListWznmQTco1NImpexpcol();
	ListWznmQTco1NImpexpcol(const ListWznmQTco1NImpexpcol& src);
	~ListWznmQTco1NImpexpcol();

	void clear();
	unsigned int size() const;
	void append(WznmQTco1NImpexpcol* rec);

	ListWznmQTco1NImpexpcol& operator=(const ListWznmQTco1NImpexpcol& src);

public:
	std::vector<WznmQTco1NImpexpcol*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTco1NImpexpcol: C++ wrapper for table TblWznmQTco1NImpexpcol
	*/
class TblWznmQTco1NImpexpcol {

public:
	TblWznmQTco1NImpexpcol();
	virtual ~TblWznmQTco1NImpexpcol();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTco1NImpexpcol** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTco1NImpexpcol& rst);

	virtual Sbecore::ubigint insertRec(WznmQTco1NImpexpcol* rec);
	Sbecore::ubigint insertNewRec(WznmQTco1NImpexpcol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTco1NImpexpcol& rst, WznmQTco1NImpexpcol** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTco1NImpexpcol& rst);
	virtual void updateRec(WznmQTco1NImpexpcol* rec);
	virtual void updateRst(ListWznmQTco1NImpexpcol& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTco1NImpexpcol** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTco1NImpexpcol& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTco1NImpexpcol: C++ wrapper for table TblWznmQTco1NImpexpcol (MySQL database)
	*/
class MyTblWznmQTco1NImpexpcol : public TblWznmQTco1NImpexpcol, public Sbecore::MyTable {

public:
	MyTblWznmQTco1NImpexpcol();
	~MyTblWznmQTco1NImpexpcol();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTco1NImpexpcol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTco1NImpexpcol& rst);

	Sbecore::ubigint insertRec(WznmQTco1NImpexpcol* rec);
	void insertRst(ListWznmQTco1NImpexpcol& rst);
	void updateRec(WznmQTco1NImpexpcol* rec);
	void updateRst(ListWznmQTco1NImpexpcol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTco1NImpexpcol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTco1NImpexpcol& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTco1NImpexpcol: C++ wrapper for table TblWznmQTco1NImpexpcol (PgSQL database)
	*/
class PgTblWznmQTco1NImpexpcol : public TblWznmQTco1NImpexpcol, public Sbecore::PgTable {

public:
	PgTblWznmQTco1NImpexpcol();
	~PgTblWznmQTco1NImpexpcol();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTco1NImpexpcol** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTco1NImpexpcol& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTco1NImpexpcol** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTco1NImpexpcol& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTco1NImpexpcol** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTco1NImpexpcol& rst);

	Sbecore::ubigint insertRec(WznmQTco1NImpexpcol* rec);
	void insertRst(ListWznmQTco1NImpexpcol& rst);
	void updateRec(WznmQTco1NImpexpcol* rec);
	void updateRst(ListWznmQTco1NImpexpcol& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTco1NImpexpcol** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTco1NImpexpcol& rst);
};
#endif

#endif

