/**
	* \file WznmQTbl1NSubset.h
	* Dbs and XML wrapper for table TblWznmQTbl1NSubset (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQTBL1NSUBSET_H
#define WZNMQTBL1NSUBSET_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTbl1NSubset: record of TblWznmQTbl1NSubset
	*/
class WznmQTbl1NSubset {

public:
	WznmQTbl1NSubset(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTbl1NSubset: recordset of TblWznmQTbl1NSubset
	*/
class ListWznmQTbl1NSubset {

public:
	ListWznmQTbl1NSubset();
	ListWznmQTbl1NSubset(const ListWznmQTbl1NSubset& src);
	~ListWznmQTbl1NSubset();

	void clear();
	unsigned int size() const;
	void append(WznmQTbl1NSubset* rec);

	ListWznmQTbl1NSubset& operator=(const ListWznmQTbl1NSubset& src);

public:
	std::vector<WznmQTbl1NSubset*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTbl1NSubset: C++ wrapper for table TblWznmQTbl1NSubset
	*/
class TblWznmQTbl1NSubset {

public:
	TblWznmQTbl1NSubset();
	virtual ~TblWznmQTbl1NSubset();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTbl1NSubset** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTbl1NSubset& rst);

	virtual Sbecore::ubigint insertRec(WznmQTbl1NSubset* rec);
	Sbecore::ubigint insertNewRec(WznmQTbl1NSubset** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTbl1NSubset& rst, WznmQTbl1NSubset** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTbl1NSubset& rst);
	virtual void updateRec(WznmQTbl1NSubset* rec);
	virtual void updateRst(ListWznmQTbl1NSubset& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTbl1NSubset** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTbl1NSubset& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTbl1NSubset: C++ wrapper for table TblWznmQTbl1NSubset (MySQL database)
	*/
class MyTblWznmQTbl1NSubset : public TblWznmQTbl1NSubset, public Sbecore::MyTable {

public:
	MyTblWznmQTbl1NSubset();
	~MyTblWznmQTbl1NSubset();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTbl1NSubset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTbl1NSubset& rst);

	Sbecore::ubigint insertRec(WznmQTbl1NSubset* rec);
	void insertRst(ListWznmQTbl1NSubset& rst);
	void updateRec(WznmQTbl1NSubset* rec);
	void updateRst(ListWznmQTbl1NSubset& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTbl1NSubset** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTbl1NSubset& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTbl1NSubset: C++ wrapper for table TblWznmQTbl1NSubset (PgSQL database)
	*/
class PgTblWznmQTbl1NSubset : public TblWznmQTbl1NSubset, public Sbecore::PgTable {

public:
	PgTblWznmQTbl1NSubset();
	~PgTblWznmQTbl1NSubset();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTbl1NSubset** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTbl1NSubset& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTbl1NSubset** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTbl1NSubset& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTbl1NSubset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTbl1NSubset& rst);

	Sbecore::ubigint insertRec(WznmQTbl1NSubset* rec);
	void insertRst(ListWznmQTbl1NSubset& rst);
	void updateRec(WznmQTbl1NSubset* rec);
	void updateRst(ListWznmQTbl1NSubset& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTbl1NSubset** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTbl1NSubset& rst);
};
#endif

#endif

