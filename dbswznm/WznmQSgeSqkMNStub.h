/**
	* \file WznmQSgeSqkMNStub.h
	* Dbs and XML wrapper for table TblWznmQSgeSqkMNStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSGESQKMNSTUB_H
#define WZNMQSGESQKMNSTUB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSgeSqkMNStub: record of TblWznmQSgeSqkMNStub
	*/
class WznmQSgeSqkMNStub {

public:
	WznmQSgeSqkMNStub(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQSgeSqkMNStub: recordset of TblWznmQSgeSqkMNStub
	*/
class ListWznmQSgeSqkMNStub {

public:
	ListWznmQSgeSqkMNStub();
	ListWznmQSgeSqkMNStub(const ListWznmQSgeSqkMNStub& src);
	~ListWznmQSgeSqkMNStub();

	void clear();
	unsigned int size() const;
	void append(WznmQSgeSqkMNStub* rec);

	ListWznmQSgeSqkMNStub& operator=(const ListWznmQSgeSqkMNStub& src);

public:
	std::vector<WznmQSgeSqkMNStub*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSgeSqkMNStub: C++ wrapper for table TblWznmQSgeSqkMNStub
	*/
class TblWznmQSgeSqkMNStub {

public:
	TblWznmQSgeSqkMNStub();
	virtual ~TblWznmQSgeSqkMNStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSgeSqkMNStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSgeSqkMNStub& rst);

	virtual Sbecore::ubigint insertRec(WznmQSgeSqkMNStub* rec);
	Sbecore::ubigint insertNewRec(WznmQSgeSqkMNStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQSgeSqkMNStub& rst, WznmQSgeSqkMNStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQSgeSqkMNStub& rst);
	virtual void updateRec(WznmQSgeSqkMNStub* rec);
	virtual void updateRst(ListWznmQSgeSqkMNStub& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSgeSqkMNStub** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSgeSqkMNStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSgeSqkMNStub: C++ wrapper for table TblWznmQSgeSqkMNStub (MySQL database)
	*/
class MyTblWznmQSgeSqkMNStub : public TblWznmQSgeSqkMNStub, public Sbecore::MyTable {

public:
	MyTblWznmQSgeSqkMNStub();
	~MyTblWznmQSgeSqkMNStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSgeSqkMNStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSgeSqkMNStub& rst);

	Sbecore::ubigint insertRec(WznmQSgeSqkMNStub* rec);
	void insertRst(ListWznmQSgeSqkMNStub& rst);
	void updateRec(WznmQSgeSqkMNStub* rec);
	void updateRst(ListWznmQSgeSqkMNStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSgeSqkMNStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSgeSqkMNStub& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSgeSqkMNStub: C++ wrapper for table TblWznmQSgeSqkMNStub (PgSQL database)
	*/
class PgTblWznmQSgeSqkMNStub : public TblWznmQSgeSqkMNStub, public Sbecore::PgTable {

public:
	PgTblWznmQSgeSqkMNStub();
	~PgTblWznmQSgeSqkMNStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSgeSqkMNStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSgeSqkMNStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSgeSqkMNStub** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSgeSqkMNStub& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSgeSqkMNStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSgeSqkMNStub& rst);

	Sbecore::ubigint insertRec(WznmQSgeSqkMNStub* rec);
	void insertRst(ListWznmQSgeSqkMNStub& rst);
	void updateRec(WznmQSgeSqkMNStub* rec);
	void updateRst(ListWznmQSgeSqkMNStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSgeSqkMNStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSgeSqkMNStub& rst);
};
#endif

#endif
