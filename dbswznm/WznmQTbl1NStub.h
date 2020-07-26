/**
	* \file WznmQTbl1NStub.h
	* Dbs and XML wrapper for table TblWznmQTbl1NStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQTBL1NSTUB_H
#define WZNMQTBL1NSTUB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTbl1NStub: record of TblWznmQTbl1NStub
	*/
class WznmQTbl1NStub {

public:
	WznmQTbl1NStub(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTbl1NStub: recordset of TblWznmQTbl1NStub
	*/
class ListWznmQTbl1NStub {

public:
	ListWznmQTbl1NStub();
	ListWznmQTbl1NStub(const ListWznmQTbl1NStub& src);
	~ListWznmQTbl1NStub();

	void clear();
	unsigned int size() const;
	void append(WznmQTbl1NStub* rec);

	ListWznmQTbl1NStub& operator=(const ListWznmQTbl1NStub& src);

public:
	std::vector<WznmQTbl1NStub*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTbl1NStub: C++ wrapper for table TblWznmQTbl1NStub
	*/
class TblWznmQTbl1NStub {

public:
	TblWznmQTbl1NStub();
	virtual ~TblWznmQTbl1NStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTbl1NStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTbl1NStub& rst);

	virtual Sbecore::ubigint insertRec(WznmQTbl1NStub* rec);
	Sbecore::ubigint insertNewRec(WznmQTbl1NStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTbl1NStub& rst, WznmQTbl1NStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTbl1NStub& rst);
	virtual void updateRec(WznmQTbl1NStub* rec);
	virtual void updateRst(ListWznmQTbl1NStub& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTbl1NStub** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTbl1NStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTbl1NStub: C++ wrapper for table TblWznmQTbl1NStub (MySQL database)
	*/
class MyTblWznmQTbl1NStub : public TblWznmQTbl1NStub, public Sbecore::MyTable {

public:
	MyTblWznmQTbl1NStub();
	~MyTblWznmQTbl1NStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTbl1NStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTbl1NStub& rst);

	Sbecore::ubigint insertRec(WznmQTbl1NStub* rec);
	void insertRst(ListWznmQTbl1NStub& rst);
	void updateRec(WznmQTbl1NStub* rec);
	void updateRst(ListWznmQTbl1NStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTbl1NStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTbl1NStub& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTbl1NStub: C++ wrapper for table TblWznmQTbl1NStub (PgSQL database)
	*/
class PgTblWznmQTbl1NStub : public TblWznmQTbl1NStub, public Sbecore::PgTable {

public:
	PgTblWznmQTbl1NStub();
	~PgTblWznmQTbl1NStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTbl1NStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTbl1NStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTbl1NStub** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTbl1NStub& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTbl1NStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTbl1NStub& rst);

	Sbecore::ubigint insertRec(WznmQTbl1NStub* rec);
	void insertRst(ListWznmQTbl1NStub& rst);
	void updateRec(WznmQTbl1NStub* rec);
	void updateRst(ListWznmQTbl1NStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTbl1NStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTbl1NStub& rst);
};
#endif

#endif

