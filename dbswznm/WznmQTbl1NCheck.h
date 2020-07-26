/**
	* \file WznmQTbl1NCheck.h
	* Dbs and XML wrapper for table TblWznmQTbl1NCheck (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQTBL1NCHECK_H
#define WZNMQTBL1NCHECK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTbl1NCheck: record of TblWznmQTbl1NCheck
	*/
class WznmQTbl1NCheck {

public:
	WznmQTbl1NCheck(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTbl1NCheck: recordset of TblWznmQTbl1NCheck
	*/
class ListWznmQTbl1NCheck {

public:
	ListWznmQTbl1NCheck();
	ListWznmQTbl1NCheck(const ListWznmQTbl1NCheck& src);
	~ListWznmQTbl1NCheck();

	void clear();
	unsigned int size() const;
	void append(WznmQTbl1NCheck* rec);

	ListWznmQTbl1NCheck& operator=(const ListWznmQTbl1NCheck& src);

public:
	std::vector<WznmQTbl1NCheck*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTbl1NCheck: C++ wrapper for table TblWznmQTbl1NCheck
	*/
class TblWznmQTbl1NCheck {

public:
	TblWznmQTbl1NCheck();
	virtual ~TblWznmQTbl1NCheck();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTbl1NCheck** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTbl1NCheck& rst);

	virtual Sbecore::ubigint insertRec(WznmQTbl1NCheck* rec);
	Sbecore::ubigint insertNewRec(WznmQTbl1NCheck** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTbl1NCheck& rst, WznmQTbl1NCheck** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTbl1NCheck& rst);
	virtual void updateRec(WznmQTbl1NCheck* rec);
	virtual void updateRst(ListWznmQTbl1NCheck& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTbl1NCheck** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTbl1NCheck& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTbl1NCheck: C++ wrapper for table TblWznmQTbl1NCheck (MySQL database)
	*/
class MyTblWznmQTbl1NCheck : public TblWznmQTbl1NCheck, public Sbecore::MyTable {

public:
	MyTblWznmQTbl1NCheck();
	~MyTblWznmQTbl1NCheck();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTbl1NCheck** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTbl1NCheck& rst);

	Sbecore::ubigint insertRec(WznmQTbl1NCheck* rec);
	void insertRst(ListWznmQTbl1NCheck& rst);
	void updateRec(WznmQTbl1NCheck* rec);
	void updateRst(ListWznmQTbl1NCheck& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTbl1NCheck** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTbl1NCheck& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTbl1NCheck: C++ wrapper for table TblWznmQTbl1NCheck (PgSQL database)
	*/
class PgTblWznmQTbl1NCheck : public TblWznmQTbl1NCheck, public Sbecore::PgTable {

public:
	PgTblWznmQTbl1NCheck();
	~PgTblWznmQTbl1NCheck();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTbl1NCheck** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTbl1NCheck& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTbl1NCheck** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTbl1NCheck& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTbl1NCheck** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTbl1NCheck& rst);

	Sbecore::ubigint insertRec(WznmQTbl1NCheck* rec);
	void insertRst(ListWznmQTbl1NCheck& rst);
	void updateRec(WznmQTbl1NCheck* rec);
	void updateRst(ListWznmQTbl1NCheck& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTbl1NCheck** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTbl1NCheck& rst);
};
#endif

#endif

