/**
	* \file WznmQStbMNCall.h
	* Dbs and XML wrapper for table TblWznmQStbMNCall (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSTBMNCALL_H
#define WZNMQSTBMNCALL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQStbMNCall: record of TblWznmQStbMNCall
	*/
class WznmQStbMNCall {

public:
	WznmQStbMNCall(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQStbMNCall: recordset of TblWznmQStbMNCall
	*/
class ListWznmQStbMNCall {

public:
	ListWznmQStbMNCall();
	ListWznmQStbMNCall(const ListWznmQStbMNCall& src);
	~ListWznmQStbMNCall();

	void clear();
	unsigned int size() const;
	void append(WznmQStbMNCall* rec);

	ListWznmQStbMNCall& operator=(const ListWznmQStbMNCall& src);

public:
	std::vector<WznmQStbMNCall*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQStbMNCall: C++ wrapper for table TblWznmQStbMNCall
	*/
class TblWznmQStbMNCall {

public:
	TblWznmQStbMNCall();
	virtual ~TblWznmQStbMNCall();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQStbMNCall** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbMNCall& rst);

	virtual Sbecore::ubigint insertRec(WznmQStbMNCall* rec);
	Sbecore::ubigint insertNewRec(WznmQStbMNCall** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQStbMNCall& rst, WznmQStbMNCall** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQStbMNCall& rst);
	virtual void updateRec(WznmQStbMNCall* rec);
	virtual void updateRst(ListWznmQStbMNCall& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQStbMNCall** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbMNCall& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQStbMNCall: C++ wrapper for table TblWznmQStbMNCall (MySQL database)
	*/
class MyTblWznmQStbMNCall : public TblWznmQStbMNCall, public Sbecore::MyTable {

public:
	MyTblWznmQStbMNCall();
	~MyTblWznmQStbMNCall();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQStbMNCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbMNCall& rst);

	Sbecore::ubigint insertRec(WznmQStbMNCall* rec);
	void insertRst(ListWznmQStbMNCall& rst);
	void updateRec(WznmQStbMNCall* rec);
	void updateRst(ListWznmQStbMNCall& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQStbMNCall** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbMNCall& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQStbMNCall: C++ wrapper for table TblWznmQStbMNCall (PgSQL database)
	*/
class PgTblWznmQStbMNCall : public TblWznmQStbMNCall, public Sbecore::PgTable {

public:
	PgTblWznmQStbMNCall();
	~PgTblWznmQStbMNCall();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQStbMNCall** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQStbMNCall& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQStbMNCall** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQStbMNCall& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQStbMNCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQStbMNCall& rst);

	Sbecore::ubigint insertRec(WznmQStbMNCall* rec);
	void insertRst(ListWznmQStbMNCall& rst);
	void updateRec(WznmQStbMNCall* rec);
	void updateRst(ListWznmQStbMNCall& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQStbMNCall** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQStbMNCall& rst);
};
#endif

#endif

