/**
	* \file WznmQChkRef1NCall.h
	* Dbs and XML wrapper for table TblWznmQChkRef1NCall (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQCHKREF1NCALL_H
#define WZNMQCHKREF1NCALL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQChkRef1NCall: record of TblWznmQChkRef1NCall
	*/
class WznmQChkRef1NCall {

public:
	WznmQChkRef1NCall(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQChkRef1NCall: recordset of TblWznmQChkRef1NCall
	*/
class ListWznmQChkRef1NCall {

public:
	ListWznmQChkRef1NCall();
	ListWznmQChkRef1NCall(const ListWznmQChkRef1NCall& src);
	~ListWznmQChkRef1NCall();

	void clear();
	unsigned int size() const;
	void append(WznmQChkRef1NCall* rec);

	ListWznmQChkRef1NCall& operator=(const ListWznmQChkRef1NCall& src);

public:
	std::vector<WznmQChkRef1NCall*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQChkRef1NCall: C++ wrapper for table TblWznmQChkRef1NCall
	*/
class TblWznmQChkRef1NCall {

public:
	TblWznmQChkRef1NCall();
	virtual ~TblWznmQChkRef1NCall();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQChkRef1NCall** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQChkRef1NCall& rst);

	virtual Sbecore::ubigint insertRec(WznmQChkRef1NCall* rec);
	Sbecore::ubigint insertNewRec(WznmQChkRef1NCall** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQChkRef1NCall& rst, WznmQChkRef1NCall** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQChkRef1NCall& rst);
	virtual void updateRec(WznmQChkRef1NCall* rec);
	virtual void updateRst(ListWznmQChkRef1NCall& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQChkRef1NCall** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQChkRef1NCall& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQChkRef1NCall: C++ wrapper for table TblWznmQChkRef1NCall (MySQL database)
	*/
class MyTblWznmQChkRef1NCall : public TblWznmQChkRef1NCall, public Sbecore::MyTable {

public:
	MyTblWznmQChkRef1NCall();
	~MyTblWznmQChkRef1NCall();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQChkRef1NCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQChkRef1NCall& rst);

	Sbecore::ubigint insertRec(WznmQChkRef1NCall* rec);
	void insertRst(ListWznmQChkRef1NCall& rst);
	void updateRec(WznmQChkRef1NCall* rec);
	void updateRst(ListWznmQChkRef1NCall& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQChkRef1NCall** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQChkRef1NCall& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQChkRef1NCall: C++ wrapper for table TblWznmQChkRef1NCall (PgSQL database)
	*/
class PgTblWznmQChkRef1NCall : public TblWznmQChkRef1NCall, public Sbecore::PgTable {

public:
	PgTblWznmQChkRef1NCall();
	~PgTblWznmQChkRef1NCall();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQChkRef1NCall** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQChkRef1NCall& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQChkRef1NCall** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQChkRef1NCall& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQChkRef1NCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQChkRef1NCall& rst);

	Sbecore::ubigint insertRec(WznmQChkRef1NCall* rec);
	void insertRst(ListWznmQChkRef1NCall& rst);
	void updateRec(WznmQChkRef1NCall* rec);
	void updateRst(ListWznmQChkRef1NCall& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQChkRef1NCall** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQChkRef1NCall& rst);
};
#endif

#endif

