/**
	* \file WznmQOpkSqkMNStub.h
	* Dbs and XML wrapper for table TblWznmQOpkSqkMNStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQOPKSQKMNSTUB_H
#define WZNMQOPKSQKMNSTUB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpkSqkMNStub: record of TblWznmQOpkSqkMNStub
	*/
class WznmQOpkSqkMNStub {

public:
	WznmQOpkSqkMNStub(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQOpkSqkMNStub: recordset of TblWznmQOpkSqkMNStub
	*/
class ListWznmQOpkSqkMNStub {

public:
	ListWznmQOpkSqkMNStub();
	ListWznmQOpkSqkMNStub(const ListWznmQOpkSqkMNStub& src);
	~ListWznmQOpkSqkMNStub();

	void clear();
	unsigned int size() const;
	void append(WznmQOpkSqkMNStub* rec);

	ListWznmQOpkSqkMNStub& operator=(const ListWznmQOpkSqkMNStub& src);

public:
	std::vector<WznmQOpkSqkMNStub*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpkSqkMNStub: C++ wrapper for table TblWznmQOpkSqkMNStub
	*/
class TblWznmQOpkSqkMNStub {

public:
	TblWznmQOpkSqkMNStub();
	virtual ~TblWznmQOpkSqkMNStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpkSqkMNStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkSqkMNStub& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpkSqkMNStub* rec);
	Sbecore::ubigint insertNewRec(WznmQOpkSqkMNStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpkSqkMNStub& rst, WznmQOpkSqkMNStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQOpkSqkMNStub& rst);
	virtual void updateRec(WznmQOpkSqkMNStub* rec);
	virtual void updateRst(ListWznmQOpkSqkMNStub& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkSqkMNStub** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkSqkMNStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpkSqkMNStub: C++ wrapper for table TblWznmQOpkSqkMNStub (MySQL database)
	*/
class MyTblWznmQOpkSqkMNStub : public TblWznmQOpkSqkMNStub, public Sbecore::MyTable {

public:
	MyTblWznmQOpkSqkMNStub();
	~MyTblWznmQOpkSqkMNStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkSqkMNStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkSqkMNStub& rst);

	Sbecore::ubigint insertRec(WznmQOpkSqkMNStub* rec);
	void insertRst(ListWznmQOpkSqkMNStub& rst);
	void updateRec(WznmQOpkSqkMNStub* rec);
	void updateRst(ListWznmQOpkSqkMNStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkSqkMNStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkSqkMNStub& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpkSqkMNStub: C++ wrapper for table TblWznmQOpkSqkMNStub (PgSQL database)
	*/
class PgTblWznmQOpkSqkMNStub : public TblWznmQOpkSqkMNStub, public Sbecore::PgTable {

public:
	PgTblWznmQOpkSqkMNStub();
	~PgTblWznmQOpkSqkMNStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpkSqkMNStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpkSqkMNStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpkSqkMNStub** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpkSqkMNStub& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkSqkMNStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkSqkMNStub& rst);

	Sbecore::ubigint insertRec(WznmQOpkSqkMNStub* rec);
	void insertRst(ListWznmQOpkSqkMNStub& rst);
	void updateRec(WznmQOpkSqkMNStub* rec);
	void updateRst(ListWznmQOpkSqkMNStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkSqkMNStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkSqkMNStub& rst);
};
#endif

#endif

