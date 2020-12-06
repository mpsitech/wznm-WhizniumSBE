/**
	* \file WznmQAppApp1NSequence.h
	* Dbs and XML wrapper for table TblWznmQAppApp1NSequence (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQAPPAPP1NSEQUENCE_H
#define WZNMQAPPAPP1NSEQUENCE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQAppApp1NSequence: record of TblWznmQAppApp1NSequence
	*/
class WznmQAppApp1NSequence {

public:
	WznmQAppApp1NSequence(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint appNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint appNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQAppApp1NSequence: recordset of TblWznmQAppApp1NSequence
	*/
class ListWznmQAppApp1NSequence {

public:
	ListWznmQAppApp1NSequence();
	ListWznmQAppApp1NSequence(const ListWznmQAppApp1NSequence& src);
	~ListWznmQAppApp1NSequence();

	void clear();
	unsigned int size() const;
	void append(WznmQAppApp1NSequence* rec);

	ListWznmQAppApp1NSequence& operator=(const ListWznmQAppApp1NSequence& src);

public:
	std::vector<WznmQAppApp1NSequence*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQAppApp1NSequence: C++ wrapper for table TblWznmQAppApp1NSequence
	*/
class TblWznmQAppApp1NSequence {

public:
	TblWznmQAppApp1NSequence();
	virtual ~TblWznmQAppApp1NSequence();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQAppApp1NSequence** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQAppApp1NSequence& rst);

	virtual Sbecore::ubigint insertRec(WznmQAppApp1NSequence* rec);
	Sbecore::ubigint insertNewRec(WznmQAppApp1NSequence** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint appNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQAppApp1NSequence& rst, WznmQAppApp1NSequence** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint appNum = 0);
	virtual void insertRst(ListWznmQAppApp1NSequence& rst);
	virtual void updateRec(WznmQAppApp1NSequence* rec);
	virtual void updateRst(ListWznmQAppApp1NSequence& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQAppApp1NSequence** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQAppApp1NSequence& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQAppApp1NSequence: C++ wrapper for table TblWznmQAppApp1NSequence (MySQL database)
	*/
class MyTblWznmQAppApp1NSequence : public TblWznmQAppApp1NSequence, public Sbecore::MyTable {

public:
	MyTblWznmQAppApp1NSequence();
	~MyTblWznmQAppApp1NSequence();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQAppApp1NSequence** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQAppApp1NSequence& rst);

	Sbecore::ubigint insertRec(WznmQAppApp1NSequence* rec);
	void insertRst(ListWznmQAppApp1NSequence& rst);
	void updateRec(WznmQAppApp1NSequence* rec);
	void updateRst(ListWznmQAppApp1NSequence& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQAppApp1NSequence** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQAppApp1NSequence& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQAppApp1NSequence: C++ wrapper for table TblWznmQAppApp1NSequence (PgSQL database)
	*/
class PgTblWznmQAppApp1NSequence : public TblWznmQAppApp1NSequence, public Sbecore::PgTable {

public:
	PgTblWznmQAppApp1NSequence();
	~PgTblWznmQAppApp1NSequence();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQAppApp1NSequence** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQAppApp1NSequence& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQAppApp1NSequence** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQAppApp1NSequence& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQAppApp1NSequence** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQAppApp1NSequence& rst);

	Sbecore::ubigint insertRec(WznmQAppApp1NSequence* rec);
	void insertRst(ListWznmQAppApp1NSequence& rst);
	void updateRec(WznmQAppApp1NSequence* rec);
	void updateRst(ListWznmQAppApp1NSequence& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQAppApp1NSequence** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQAppApp1NSequence& rst);
};
#endif

#endif
