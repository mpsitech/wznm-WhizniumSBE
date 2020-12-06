/**
	* \file WznmQPrsADetail.h
	* Dbs and XML wrapper for table TblWznmQPrsADetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPRSADETAIL_H
#define WZNMQPRSADETAIL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQPrsADetail: record of TblWznmQPrsADetail
	*/
class WznmQPrsADetail {

public:
	WznmQPrsADetail(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string x1SrefKType;
	std::string titX1SrefKType;
	std::string Val;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQPrsADetail: recordset of TblWznmQPrsADetail
	*/
class ListWznmQPrsADetail {

public:
	ListWznmQPrsADetail();
	ListWznmQPrsADetail(const ListWznmQPrsADetail& src);
	~ListWznmQPrsADetail();

	void clear();
	unsigned int size() const;
	void append(WznmQPrsADetail* rec);

	ListWznmQPrsADetail& operator=(const ListWznmQPrsADetail& src);

public:
	std::vector<WznmQPrsADetail*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQPrsADetail: C++ wrapper for table TblWznmQPrsADetail
	*/
class TblWznmQPrsADetail {

public:
	TblWznmQPrsADetail();
	virtual ~TblWznmQPrsADetail();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQPrsADetail** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrsADetail& rst);

	virtual Sbecore::ubigint insertRec(WznmQPrsADetail* rec);
	Sbecore::ubigint insertNewRec(WznmQPrsADetail** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQPrsADetail& rst, WznmQPrsADetail** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string x1SrefKType = "", const std::string titX1SrefKType = "", const std::string Val = "");
	virtual void insertRst(ListWznmQPrsADetail& rst);
	virtual void updateRec(WznmQPrsADetail* rec);
	virtual void updateRst(ListWznmQPrsADetail& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQPrsADetail** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrsADetail& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQPrsADetail: C++ wrapper for table TblWznmQPrsADetail (MySQL database)
	*/
class MyTblWznmQPrsADetail : public TblWznmQPrsADetail, public Sbecore::MyTable {

public:
	MyTblWznmQPrsADetail();
	~MyTblWznmQPrsADetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrsADetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrsADetail& rst);

	Sbecore::ubigint insertRec(WznmQPrsADetail* rec);
	void insertRst(ListWznmQPrsADetail& rst);
	void updateRec(WznmQPrsADetail* rec);
	void updateRst(ListWznmQPrsADetail& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrsADetail** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrsADetail& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQPrsADetail: C++ wrapper for table TblWznmQPrsADetail (PgSQL database)
	*/
class PgTblWznmQPrsADetail : public TblWznmQPrsADetail, public Sbecore::PgTable {

public:
	PgTblWznmQPrsADetail();
	~PgTblWznmQPrsADetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQPrsADetail** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQPrsADetail& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQPrsADetail** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQPrsADetail& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrsADetail** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrsADetail& rst);

	Sbecore::ubigint insertRec(WznmQPrsADetail* rec);
	void insertRst(ListWznmQPrsADetail& rst);
	void updateRec(WznmQPrsADetail* rec);
	void updateRst(ListWznmQPrsADetail& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrsADetail** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrsADetail& rst);
};
#endif

#endif
