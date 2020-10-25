/**
	* \file WznmQOpxSqkMNStub.h
	* Dbs and XML wrapper for table TblWznmQOpxSqkMNStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQOPXSQKMNSTUB_H
#define WZNMQOPXSQKMNSTUB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpxSqkMNStub: record of TblWznmQOpxSqkMNStub
	*/
class WznmQOpxSqkMNStub {

public:
	WznmQOpxSqkMNStub(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQOpxSqkMNStub: recordset of TblWznmQOpxSqkMNStub
	*/
class ListWznmQOpxSqkMNStub {

public:
	ListWznmQOpxSqkMNStub();
	ListWznmQOpxSqkMNStub(const ListWznmQOpxSqkMNStub& src);
	~ListWznmQOpxSqkMNStub();

	void clear();
	unsigned int size() const;
	void append(WznmQOpxSqkMNStub* rec);

	ListWznmQOpxSqkMNStub& operator=(const ListWznmQOpxSqkMNStub& src);

public:
	std::vector<WznmQOpxSqkMNStub*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpxSqkMNStub: C++ wrapper for table TblWznmQOpxSqkMNStub
	*/
class TblWznmQOpxSqkMNStub {

public:
	TblWznmQOpxSqkMNStub();
	virtual ~TblWznmQOpxSqkMNStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpxSqkMNStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxSqkMNStub& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpxSqkMNStub* rec);
	Sbecore::ubigint insertNewRec(WznmQOpxSqkMNStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpxSqkMNStub& rst, WznmQOpxSqkMNStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQOpxSqkMNStub& rst);
	virtual void updateRec(WznmQOpxSqkMNStub* rec);
	virtual void updateRst(ListWznmQOpxSqkMNStub& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxSqkMNStub** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxSqkMNStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpxSqkMNStub: C++ wrapper for table TblWznmQOpxSqkMNStub (MySQL database)
	*/
class MyTblWznmQOpxSqkMNStub : public TblWznmQOpxSqkMNStub, public Sbecore::MyTable {

public:
	MyTblWznmQOpxSqkMNStub();
	~MyTblWznmQOpxSqkMNStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpxSqkMNStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxSqkMNStub& rst);

	Sbecore::ubigint insertRec(WznmQOpxSqkMNStub* rec);
	void insertRst(ListWznmQOpxSqkMNStub& rst);
	void updateRec(WznmQOpxSqkMNStub* rec);
	void updateRst(ListWznmQOpxSqkMNStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxSqkMNStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxSqkMNStub& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpxSqkMNStub: C++ wrapper for table TblWznmQOpxSqkMNStub (PgSQL database)
	*/
class PgTblWznmQOpxSqkMNStub : public TblWznmQOpxSqkMNStub, public Sbecore::PgTable {

public:
	PgTblWznmQOpxSqkMNStub();
	~PgTblWznmQOpxSqkMNStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpxSqkMNStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpxSqkMNStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpxSqkMNStub** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpxSqkMNStub& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpxSqkMNStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxSqkMNStub& rst);

	Sbecore::ubigint insertRec(WznmQOpxSqkMNStub* rec);
	void insertRst(ListWznmQOpxSqkMNStub& rst);
	void updateRec(WznmQOpxSqkMNStub* rec);
	void updateRst(ListWznmQOpxSqkMNStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxSqkMNStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxSqkMNStub& rst);
};
#endif

#endif

