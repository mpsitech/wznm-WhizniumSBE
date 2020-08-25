/**
	* \file WznmQTblSrc1NFeed.h
	* Dbs and XML wrapper for table TblWznmQTblSrc1NFeed (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQTBLSRC1NFEED_H
#define WZNMQTBLSRC1NFEED_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblSrc1NFeed: record of TblWznmQTblSrc1NFeed
	*/
class WznmQTblSrc1NFeed {

public:
	WznmQTblSrc1NFeed(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTblSrc1NFeed: recordset of TblWznmQTblSrc1NFeed
	*/
class ListWznmQTblSrc1NFeed {

public:
	ListWznmQTblSrc1NFeed();
	ListWznmQTblSrc1NFeed(const ListWznmQTblSrc1NFeed& src);
	~ListWznmQTblSrc1NFeed();

	void clear();
	unsigned int size() const;
	void append(WznmQTblSrc1NFeed* rec);

	ListWznmQTblSrc1NFeed& operator=(const ListWznmQTblSrc1NFeed& src);

public:
	std::vector<WznmQTblSrc1NFeed*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblSrc1NFeed: C++ wrapper for table TblWznmQTblSrc1NFeed
	*/
class TblWznmQTblSrc1NFeed {

public:
	TblWznmQTblSrc1NFeed();
	virtual ~TblWznmQTblSrc1NFeed();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblSrc1NFeed** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblSrc1NFeed& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblSrc1NFeed* rec);
	Sbecore::ubigint insertNewRec(WznmQTblSrc1NFeed** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblSrc1NFeed& rst, WznmQTblSrc1NFeed** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTblSrc1NFeed& rst);
	virtual void updateRec(WznmQTblSrc1NFeed* rec);
	virtual void updateRst(ListWznmQTblSrc1NFeed& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblSrc1NFeed** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblSrc1NFeed& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblSrc1NFeed: C++ wrapper for table TblWznmQTblSrc1NFeed (MySQL database)
	*/
class MyTblWznmQTblSrc1NFeed : public TblWznmQTblSrc1NFeed, public Sbecore::MyTable {

public:
	MyTblWznmQTblSrc1NFeed();
	~MyTblWznmQTblSrc1NFeed();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblSrc1NFeed** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblSrc1NFeed& rst);

	Sbecore::ubigint insertRec(WznmQTblSrc1NFeed* rec);
	void insertRst(ListWznmQTblSrc1NFeed& rst);
	void updateRec(WznmQTblSrc1NFeed* rec);
	void updateRst(ListWznmQTblSrc1NFeed& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblSrc1NFeed** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblSrc1NFeed& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblSrc1NFeed: C++ wrapper for table TblWznmQTblSrc1NFeed (PgSQL database)
	*/
class PgTblWznmQTblSrc1NFeed : public TblWznmQTblSrc1NFeed, public Sbecore::PgTable {

public:
	PgTblWznmQTblSrc1NFeed();
	~PgTblWznmQTblSrc1NFeed();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblSrc1NFeed** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblSrc1NFeed& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblSrc1NFeed** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblSrc1NFeed& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblSrc1NFeed** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblSrc1NFeed& rst);

	Sbecore::ubigint insertRec(WznmQTblSrc1NFeed* rec);
	void insertRst(ListWznmQTblSrc1NFeed& rst);
	void updateRec(WznmQTblSrc1NFeed* rec);
	void updateRst(ListWznmQTblSrc1NFeed& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblSrc1NFeed** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblSrc1NFeed& rst);
};
#endif

#endif

