/**
	* \file WznmQTblRef1NCall.h
	* Dbs and XML wrapper for table TblWznmQTblRef1NCall (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQTBLREF1NCALL_H
#define WZNMQTBLREF1NCALL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblRef1NCall: record of TblWznmQTblRef1NCall
	*/
class WznmQTblRef1NCall {

public:
	WznmQTblRef1NCall(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTblRef1NCall: recordset of TblWznmQTblRef1NCall
	*/
class ListWznmQTblRef1NCall {

public:
	ListWznmQTblRef1NCall();
	ListWznmQTblRef1NCall(const ListWznmQTblRef1NCall& src);
	~ListWznmQTblRef1NCall();

	void clear();
	unsigned int size() const;
	void append(WznmQTblRef1NCall* rec);

	ListWznmQTblRef1NCall& operator=(const ListWznmQTblRef1NCall& src);

public:
	std::vector<WznmQTblRef1NCall*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblRef1NCall: C++ wrapper for table TblWznmQTblRef1NCall
	*/
class TblWznmQTblRef1NCall {

public:
	TblWznmQTblRef1NCall();
	virtual ~TblWznmQTblRef1NCall();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NCall** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NCall& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblRef1NCall* rec);
	Sbecore::ubigint insertNewRec(WznmQTblRef1NCall** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblRef1NCall& rst, WznmQTblRef1NCall** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTblRef1NCall& rst);
	virtual void updateRec(WznmQTblRef1NCall* rec);
	virtual void updateRst(ListWznmQTblRef1NCall& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NCall** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NCall& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblRef1NCall: C++ wrapper for table TblWznmQTblRef1NCall (MySQL database)
	*/
class MyTblWznmQTblRef1NCall : public TblWznmQTblRef1NCall, public Sbecore::MyTable {

public:
	MyTblWznmQTblRef1NCall();
	~MyTblWznmQTblRef1NCall();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NCall& rst);

	Sbecore::ubigint insertRec(WznmQTblRef1NCall* rec);
	void insertRst(ListWznmQTblRef1NCall& rst);
	void updateRec(WznmQTblRef1NCall* rec);
	void updateRst(ListWznmQTblRef1NCall& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NCall** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NCall& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblRef1NCall: C++ wrapper for table TblWznmQTblRef1NCall (PgSQL database)
	*/
class PgTblWznmQTblRef1NCall : public TblWznmQTblRef1NCall, public Sbecore::PgTable {

public:
	PgTblWznmQTblRef1NCall();
	~PgTblWznmQTblRef1NCall();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblRef1NCall** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblRef1NCall& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblRef1NCall** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblRef1NCall& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblRef1NCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblRef1NCall& rst);

	Sbecore::ubigint insertRec(WznmQTblRef1NCall* rec);
	void insertRst(ListWznmQTblRef1NCall& rst);
	void updateRec(WznmQTblRef1NCall* rec);
	void updateRst(ListWznmQTblRef1NCall& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblRef1NCall** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblRef1NCall& rst);
};
#endif

#endif

