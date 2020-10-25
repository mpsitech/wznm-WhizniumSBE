/**
	* \file WznmQTco1NCheck.h
	* Dbs and XML wrapper for table TblWznmQTco1NCheck (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQTCO1NCHECK_H
#define WZNMQTCO1NCHECK_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTco1NCheck: record of TblWznmQTco1NCheck
	*/
class WznmQTco1NCheck {

public:
	WznmQTco1NCheck(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTco1NCheck: recordset of TblWznmQTco1NCheck
	*/
class ListWznmQTco1NCheck {

public:
	ListWznmQTco1NCheck();
	ListWznmQTco1NCheck(const ListWznmQTco1NCheck& src);
	~ListWznmQTco1NCheck();

	void clear();
	unsigned int size() const;
	void append(WznmQTco1NCheck* rec);

	ListWznmQTco1NCheck& operator=(const ListWznmQTco1NCheck& src);

public:
	std::vector<WznmQTco1NCheck*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTco1NCheck: C++ wrapper for table TblWznmQTco1NCheck
	*/
class TblWznmQTco1NCheck {

public:
	TblWznmQTco1NCheck();
	virtual ~TblWznmQTco1NCheck();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTco1NCheck** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTco1NCheck& rst);

	virtual Sbecore::ubigint insertRec(WznmQTco1NCheck* rec);
	Sbecore::ubigint insertNewRec(WznmQTco1NCheck** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTco1NCheck& rst, WznmQTco1NCheck** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTco1NCheck& rst);
	virtual void updateRec(WznmQTco1NCheck* rec);
	virtual void updateRst(ListWznmQTco1NCheck& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTco1NCheck** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTco1NCheck& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTco1NCheck: C++ wrapper for table TblWznmQTco1NCheck (MySQL database)
	*/
class MyTblWznmQTco1NCheck : public TblWznmQTco1NCheck, public Sbecore::MyTable {

public:
	MyTblWznmQTco1NCheck();
	~MyTblWznmQTco1NCheck();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTco1NCheck** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTco1NCheck& rst);

	Sbecore::ubigint insertRec(WznmQTco1NCheck* rec);
	void insertRst(ListWznmQTco1NCheck& rst);
	void updateRec(WznmQTco1NCheck* rec);
	void updateRst(ListWznmQTco1NCheck& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTco1NCheck** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTco1NCheck& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTco1NCheck: C++ wrapper for table TblWznmQTco1NCheck (PgSQL database)
	*/
class PgTblWznmQTco1NCheck : public TblWznmQTco1NCheck, public Sbecore::PgTable {

public:
	PgTblWznmQTco1NCheck();
	~PgTblWznmQTco1NCheck();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTco1NCheck** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTco1NCheck& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTco1NCheck** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTco1NCheck& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTco1NCheck** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTco1NCheck& rst);

	Sbecore::ubigint insertRec(WznmQTco1NCheck* rec);
	void insertRst(ListWznmQTco1NCheck& rst);
	void updateRec(WznmQTco1NCheck* rec);
	void updateRst(ListWznmQTco1NCheck& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTco1NCheck** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTco1NCheck& rst);
};
#endif

#endif

