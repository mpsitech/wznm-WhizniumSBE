/**
	* \file WznmQSbs1NStub.h
	* Dbs and XML wrapper for table TblWznmQSbs1NStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSBS1NSTUB_H
#define WZNMQSBS1NSTUB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSbs1NStub: record of TblWznmQSbs1NStub
	*/
class WznmQSbs1NStub {

public:
	WznmQSbs1NStub(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQSbs1NStub: recordset of TblWznmQSbs1NStub
	*/
class ListWznmQSbs1NStub {

public:
	ListWznmQSbs1NStub();
	ListWznmQSbs1NStub(const ListWznmQSbs1NStub& src);
	~ListWznmQSbs1NStub();

	void clear();
	unsigned int size() const;
	void append(WznmQSbs1NStub* rec);

	ListWznmQSbs1NStub& operator=(const ListWznmQSbs1NStub& src);

public:
	std::vector<WznmQSbs1NStub*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSbs1NStub: C++ wrapper for table TblWznmQSbs1NStub
	*/
class TblWznmQSbs1NStub {

public:
	TblWznmQSbs1NStub();
	virtual ~TblWznmQSbs1NStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSbs1NStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbs1NStub& rst);

	virtual Sbecore::ubigint insertRec(WznmQSbs1NStub* rec);
	Sbecore::ubigint insertNewRec(WznmQSbs1NStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSbs1NStub& rst, WznmQSbs1NStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQSbs1NStub& rst);
	virtual void updateRec(WznmQSbs1NStub* rec);
	virtual void updateRst(ListWznmQSbs1NStub& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSbs1NStub** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbs1NStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSbs1NStub: C++ wrapper for table TblWznmQSbs1NStub (MySQL database)
	*/
class MyTblWznmQSbs1NStub : public TblWznmQSbs1NStub, public Sbecore::MyTable {

public:
	MyTblWznmQSbs1NStub();
	~MyTblWznmQSbs1NStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbs1NStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbs1NStub& rst);

	Sbecore::ubigint insertRec(WznmQSbs1NStub* rec);
	void insertRst(ListWznmQSbs1NStub& rst);
	void updateRec(WznmQSbs1NStub* rec);
	void updateRst(ListWznmQSbs1NStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbs1NStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbs1NStub& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSbs1NStub: C++ wrapper for table TblWznmQSbs1NStub (PgSQL database)
	*/
class PgTblWznmQSbs1NStub : public TblWznmQSbs1NStub, public Sbecore::PgTable {

public:
	PgTblWznmQSbs1NStub();
	~PgTblWznmQSbs1NStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSbs1NStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSbs1NStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSbs1NStub** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSbs1NStub& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbs1NStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbs1NStub& rst);

	Sbecore::ubigint insertRec(WznmQSbs1NStub* rec);
	void insertRst(ListWznmQSbs1NStub& rst);
	void updateRec(WznmQSbs1NStub* rec);
	void updateRst(ListWznmQSbs1NStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbs1NStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbs1NStub& rst);
};
#endif

#endif

