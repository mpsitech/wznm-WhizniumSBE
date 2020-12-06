/**
	* \file WznmQVer1NCall.h
	* Dbs and XML wrapper for table TblWznmQVer1NCall (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVER1NCALL_H
#define WZNMQVER1NCALL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVer1NCall: record of TblWznmQVer1NCall
	*/
class WznmQVer1NCall {

public:
	WznmQVer1NCall(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVer1NCall: recordset of TblWznmQVer1NCall
	*/
class ListWznmQVer1NCall {

public:
	ListWznmQVer1NCall();
	ListWznmQVer1NCall(const ListWznmQVer1NCall& src);
	~ListWznmQVer1NCall();

	void clear();
	unsigned int size() const;
	void append(WznmQVer1NCall* rec);

	ListWznmQVer1NCall& operator=(const ListWznmQVer1NCall& src);

public:
	std::vector<WznmQVer1NCall*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVer1NCall: C++ wrapper for table TblWznmQVer1NCall
	*/
class TblWznmQVer1NCall {

public:
	TblWznmQVer1NCall();
	virtual ~TblWznmQVer1NCall();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NCall** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NCall& rst);

	virtual Sbecore::ubigint insertRec(WznmQVer1NCall* rec);
	Sbecore::ubigint insertNewRec(WznmQVer1NCall** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVer1NCall& rst, WznmQVer1NCall** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVer1NCall& rst);
	virtual void updateRec(WznmQVer1NCall* rec);
	virtual void updateRst(ListWznmQVer1NCall& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NCall** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NCall& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVer1NCall: C++ wrapper for table TblWznmQVer1NCall (MySQL database)
	*/
class MyTblWznmQVer1NCall : public TblWznmQVer1NCall, public Sbecore::MyTable {

public:
	MyTblWznmQVer1NCall();
	~MyTblWznmQVer1NCall();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NCall& rst);

	Sbecore::ubigint insertRec(WznmQVer1NCall* rec);
	void insertRst(ListWznmQVer1NCall& rst);
	void updateRec(WznmQVer1NCall* rec);
	void updateRst(ListWznmQVer1NCall& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NCall** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NCall& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVer1NCall: C++ wrapper for table TblWznmQVer1NCall (PgSQL database)
	*/
class PgTblWznmQVer1NCall : public TblWznmQVer1NCall, public Sbecore::PgTable {

public:
	PgTblWznmQVer1NCall();
	~PgTblWznmQVer1NCall();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVer1NCall** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVer1NCall& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVer1NCall** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVer1NCall& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NCall& rst);

	Sbecore::ubigint insertRec(WznmQVer1NCall* rec);
	void insertRst(ListWznmQVer1NCall& rst);
	void updateRec(WznmQVer1NCall* rec);
	void updateRst(ListWznmQVer1NCall& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NCall** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NCall& rst);
};
#endif

#endif
