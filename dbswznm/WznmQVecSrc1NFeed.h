/**
	* \file WznmQVecSrc1NFeed.h
	* Dbs and XML wrapper for table TblWznmQVecSrc1NFeed (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVECSRC1NFEED_H
#define WZNMQVECSRC1NFEED_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVecSrc1NFeed: record of TblWznmQVecSrc1NFeed
	*/
class WznmQVecSrc1NFeed {

public:
	WznmQVecSrc1NFeed(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVecSrc1NFeed: recordset of TblWznmQVecSrc1NFeed
	*/
class ListWznmQVecSrc1NFeed {

public:
	ListWznmQVecSrc1NFeed();
	ListWznmQVecSrc1NFeed(const ListWznmQVecSrc1NFeed& src);
	~ListWznmQVecSrc1NFeed();

	void clear();
	unsigned int size() const;
	void append(WznmQVecSrc1NFeed* rec);

	ListWznmQVecSrc1NFeed& operator=(const ListWznmQVecSrc1NFeed& src);

public:
	std::vector<WznmQVecSrc1NFeed*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVecSrc1NFeed: C++ wrapper for table TblWznmQVecSrc1NFeed
	*/
class TblWznmQVecSrc1NFeed {

public:
	TblWznmQVecSrc1NFeed();
	virtual ~TblWznmQVecSrc1NFeed();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVecSrc1NFeed** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecSrc1NFeed& rst);

	virtual Sbecore::ubigint insertRec(WznmQVecSrc1NFeed* rec);
	Sbecore::ubigint insertNewRec(WznmQVecSrc1NFeed** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVecSrc1NFeed& rst, WznmQVecSrc1NFeed** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVecSrc1NFeed& rst);
	virtual void updateRec(WznmQVecSrc1NFeed* rec);
	virtual void updateRst(ListWznmQVecSrc1NFeed& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVecSrc1NFeed** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecSrc1NFeed& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVecSrc1NFeed: C++ wrapper for table TblWznmQVecSrc1NFeed (MySQL database)
	*/
class MyTblWznmQVecSrc1NFeed : public TblWznmQVecSrc1NFeed, public Sbecore::MyTable {

public:
	MyTblWznmQVecSrc1NFeed();
	~MyTblWznmQVecSrc1NFeed();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecSrc1NFeed** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecSrc1NFeed& rst);

	Sbecore::ubigint insertRec(WznmQVecSrc1NFeed* rec);
	void insertRst(ListWznmQVecSrc1NFeed& rst);
	void updateRec(WznmQVecSrc1NFeed* rec);
	void updateRst(ListWznmQVecSrc1NFeed& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecSrc1NFeed** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecSrc1NFeed& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVecSrc1NFeed: C++ wrapper for table TblWznmQVecSrc1NFeed (PgSQL database)
	*/
class PgTblWznmQVecSrc1NFeed : public TblWznmQVecSrc1NFeed, public Sbecore::PgTable {

public:
	PgTblWznmQVecSrc1NFeed();
	~PgTblWznmQVecSrc1NFeed();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVecSrc1NFeed** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVecSrc1NFeed& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVecSrc1NFeed** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVecSrc1NFeed& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecSrc1NFeed** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecSrc1NFeed& rst);

	Sbecore::ubigint insertRec(WznmQVecSrc1NFeed* rec);
	void insertRst(ListWznmQVecSrc1NFeed& rst);
	void updateRec(WznmQVecSrc1NFeed* rec);
	void updateRst(ListWznmQVecSrc1NFeed& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecSrc1NFeed** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecSrc1NFeed& rst);
};
#endif

#endif

