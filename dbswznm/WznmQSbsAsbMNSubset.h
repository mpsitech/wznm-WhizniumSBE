/**
	* \file WznmQSbsAsbMNSubset.h
	* Dbs and XML wrapper for table TblWznmQSbsAsbMNSubset (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSBSASBMNSUBSET_H
#define WZNMQSBSASBMNSUBSET_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSbsAsbMNSubset: record of TblWznmQSbsAsbMNSubset
	*/
class WznmQSbsAsbMNSubset {

public:
	WznmQSbsAsbMNSubset(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixVReltype = 0, const std::string srefIxVReltype = "", const std::string titIxVReltype = "");

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
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSbsAsbMNSubset: recordset of TblWznmQSbsAsbMNSubset
	*/
class ListWznmQSbsAsbMNSubset {

public:
	ListWznmQSbsAsbMNSubset();
	ListWznmQSbsAsbMNSubset(const ListWznmQSbsAsbMNSubset& src);
	~ListWznmQSbsAsbMNSubset();

	void clear();
	unsigned int size() const;
	void append(WznmQSbsAsbMNSubset* rec);

	ListWznmQSbsAsbMNSubset& operator=(const ListWznmQSbsAsbMNSubset& src);

public:
	std::vector<WznmQSbsAsbMNSubset*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSbsAsbMNSubset: C++ wrapper for table TblWznmQSbsAsbMNSubset
	*/
class TblWznmQSbsAsbMNSubset {

public:
	TblWznmQSbsAsbMNSubset();
	virtual ~TblWznmQSbsAsbMNSubset();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSbsAsbMNSubset** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsAsbMNSubset& rst);

	virtual Sbecore::ubigint insertRec(WznmQSbsAsbMNSubset* rec);
	Sbecore::ubigint insertNewRec(WznmQSbsAsbMNSubset** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixVReltype = 0, const std::string srefIxVReltype = "", const std::string titIxVReltype = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSbsAsbMNSubset& rst, WznmQSbsAsbMNSubset** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint ixVReltype = 0, const std::string srefIxVReltype = "", const std::string titIxVReltype = "");
	virtual void insertRst(ListWznmQSbsAsbMNSubset& rst);
	virtual void updateRec(WznmQSbsAsbMNSubset* rec);
	virtual void updateRst(ListWznmQSbsAsbMNSubset& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsAsbMNSubset** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsAsbMNSubset& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSbsAsbMNSubset: C++ wrapper for table TblWznmQSbsAsbMNSubset (MySQL database)
	*/
class MyTblWznmQSbsAsbMNSubset : public TblWznmQSbsAsbMNSubset, public Sbecore::MyTable {

public:
	MyTblWznmQSbsAsbMNSubset();
	~MyTblWznmQSbsAsbMNSubset();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsAsbMNSubset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsAsbMNSubset& rst);

	Sbecore::ubigint insertRec(WznmQSbsAsbMNSubset* rec);
	void insertRst(ListWznmQSbsAsbMNSubset& rst);
	void updateRec(WznmQSbsAsbMNSubset* rec);
	void updateRst(ListWznmQSbsAsbMNSubset& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsAsbMNSubset** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsAsbMNSubset& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSbsAsbMNSubset: C++ wrapper for table TblWznmQSbsAsbMNSubset (PgSQL database)
	*/
class PgTblWznmQSbsAsbMNSubset : public TblWznmQSbsAsbMNSubset, public Sbecore::PgTable {

public:
	PgTblWznmQSbsAsbMNSubset();
	~PgTblWznmQSbsAsbMNSubset();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSbsAsbMNSubset** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSbsAsbMNSubset& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSbsAsbMNSubset** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSbsAsbMNSubset& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsAsbMNSubset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsAsbMNSubset& rst);

	Sbecore::ubigint insertRec(WznmQSbsAsbMNSubset* rec);
	void insertRst(ListWznmQSbsAsbMNSubset& rst);
	void updateRec(WznmQSbsAsbMNSubset* rec);
	void updateRst(ListWznmQSbsAsbMNSubset& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsAsbMNSubset** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsAsbMNSubset& rst);
};
#endif

#endif
