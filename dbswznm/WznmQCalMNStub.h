/**
	* \file WznmQCalMNStub.h
	* Dbs and XML wrapper for table TblWznmQCalMNStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCALMNSTUB_H
#define WZNMQCALMNSTUB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCalMNStub: record of TblWznmQCalMNStub
	*/
class WznmQCalMNStub {

public:
	WznmQCalMNStub(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQCalMNStub: recordset of TblWznmQCalMNStub
	*/
class ListWznmQCalMNStub {

public:
	ListWznmQCalMNStub();
	ListWznmQCalMNStub(const ListWznmQCalMNStub& src);
	~ListWznmQCalMNStub();

	void clear();
	unsigned int size() const;
	void append(WznmQCalMNStub* rec);

	ListWznmQCalMNStub& operator=(const ListWznmQCalMNStub& src);

public:
	std::vector<WznmQCalMNStub*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCalMNStub: C++ wrapper for table TblWznmQCalMNStub
	*/
class TblWznmQCalMNStub {

public:
	TblWznmQCalMNStub();
	virtual ~TblWznmQCalMNStub();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCalMNStub** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCalMNStub& rst);

	virtual Sbecore::ubigint insertRec(WznmQCalMNStub* rec);
	Sbecore::ubigint insertNewRec(WznmQCalMNStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQCalMNStub& rst, WznmQCalMNStub** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQCalMNStub& rst);
	virtual void updateRec(WznmQCalMNStub* rec);
	virtual void updateRst(ListWznmQCalMNStub& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCalMNStub** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCalMNStub& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCalMNStub: C++ wrapper for table TblWznmQCalMNStub (MySQL database)
	*/
class MyTblWznmQCalMNStub : public TblWznmQCalMNStub, public Sbecore::MyTable {

public:
	MyTblWznmQCalMNStub();
	~MyTblWznmQCalMNStub();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCalMNStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCalMNStub& rst);

	Sbecore::ubigint insertRec(WznmQCalMNStub* rec);
	void insertRst(ListWznmQCalMNStub& rst);
	void updateRec(WznmQCalMNStub* rec);
	void updateRst(ListWznmQCalMNStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCalMNStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCalMNStub& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCalMNStub: C++ wrapper for table TblWznmQCalMNStub (PgSQL database)
	*/
class PgTblWznmQCalMNStub : public TblWznmQCalMNStub, public Sbecore::PgTable {

public:
	PgTblWznmQCalMNStub();
	~PgTblWznmQCalMNStub();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCalMNStub** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCalMNStub& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCalMNStub** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCalMNStub& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCalMNStub** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCalMNStub& rst);

	Sbecore::ubigint insertRec(WznmQCalMNStub* rec);
	void insertRst(ListWznmQCalMNStub& rst);
	void updateRec(WznmQCalMNStub* rec);
	void updateRst(ListWznmQCalMNStub& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCalMNStub** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCalMNStub& rst);
};
#endif

#endif
