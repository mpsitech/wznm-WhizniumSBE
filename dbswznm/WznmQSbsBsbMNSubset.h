/**
	* \file WznmQSbsBsbMNSubset.h
	* Dbs and XML wrapper for table TblWznmQSbsBsbMNSubset (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSBSBSBMNSUBSET_H
#define WZNMQSBSBSBMNSUBSET_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSbsBsbMNSubset: record of TblWznmQSbsBsbMNSubset
	*/
class WznmQSbsBsbMNSubset {

public:
	WznmQSbsBsbMNSubset(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixVReltype = 0, const std::string srefIxVReltype = "", const std::string titIxVReltype = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint ixVReltype;
	std::string srefIxVReltype;
	std::string titIxVReltype;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSbsBsbMNSubset: recordset of TblWznmQSbsBsbMNSubset
	*/
class ListWznmQSbsBsbMNSubset {

public:
	ListWznmQSbsBsbMNSubset();
	ListWznmQSbsBsbMNSubset(const ListWznmQSbsBsbMNSubset& src);
	~ListWznmQSbsBsbMNSubset();

	void clear();
	unsigned int size() const;
	void append(WznmQSbsBsbMNSubset* rec);

	ListWznmQSbsBsbMNSubset& operator=(const ListWznmQSbsBsbMNSubset& src);

public:
	std::vector<WznmQSbsBsbMNSubset*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSbsBsbMNSubset: C++ wrapper for table TblWznmQSbsBsbMNSubset
	*/
class TblWznmQSbsBsbMNSubset {

public:
	TblWznmQSbsBsbMNSubset();
	virtual ~TblWznmQSbsBsbMNSubset();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSbsBsbMNSubset** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsBsbMNSubset& rst);

	virtual Sbecore::ubigint insertRec(WznmQSbsBsbMNSubset* rec);
	Sbecore::ubigint insertNewRec(WznmQSbsBsbMNSubset** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixVReltype = 0, const std::string srefIxVReltype = "", const std::string titIxVReltype = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSbsBsbMNSubset& rst, WznmQSbsBsbMNSubset** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixVReltype = 0, const std::string srefIxVReltype = "", const std::string titIxVReltype = "");
	virtual void insertRst(ListWznmQSbsBsbMNSubset& rst);
	virtual void updateRec(WznmQSbsBsbMNSubset* rec);
	virtual void updateRst(ListWznmQSbsBsbMNSubset& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsBsbMNSubset** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsBsbMNSubset& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSbsBsbMNSubset: C++ wrapper for table TblWznmQSbsBsbMNSubset (MySQL database)
	*/
class MyTblWznmQSbsBsbMNSubset : public TblWznmQSbsBsbMNSubset, public Sbecore::MyTable {

public:
	MyTblWznmQSbsBsbMNSubset();
	~MyTblWznmQSbsBsbMNSubset();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsBsbMNSubset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsBsbMNSubset& rst);

	Sbecore::ubigint insertRec(WznmQSbsBsbMNSubset* rec);
	void insertRst(ListWznmQSbsBsbMNSubset& rst);
	void updateRec(WznmQSbsBsbMNSubset* rec);
	void updateRst(ListWznmQSbsBsbMNSubset& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsBsbMNSubset** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsBsbMNSubset& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSbsBsbMNSubset: C++ wrapper for table TblWznmQSbsBsbMNSubset (PgSQL database)
	*/
class PgTblWznmQSbsBsbMNSubset : public TblWznmQSbsBsbMNSubset, public Sbecore::PgTable {

public:
	PgTblWznmQSbsBsbMNSubset();
	~PgTblWznmQSbsBsbMNSubset();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSbsBsbMNSubset** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSbsBsbMNSubset& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSbsBsbMNSubset** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSbsBsbMNSubset& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsBsbMNSubset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsBsbMNSubset& rst);

	Sbecore::ubigint insertRec(WznmQSbsBsbMNSubset* rec);
	void insertRst(ListWznmQSbsBsbMNSubset& rst);
	void updateRec(WznmQSbsBsbMNSubset* rec);
	void updateRst(ListWznmQSbsBsbMNSubset& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsBsbMNSubset** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsBsbMNSubset& rst);
};
#endif

#endif

