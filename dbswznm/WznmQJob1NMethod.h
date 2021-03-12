/**
	* \file WznmQJob1NMethod.h
	* Dbs and XML wrapper for table TblWznmQJob1NMethod (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOB1NMETHOD_H
#define WZNMQJOB1NMETHOD_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQJob1NMethod: record of TblWznmQJob1NMethod
	*/
class WznmQJob1NMethod {

public:
	WznmQJob1NMethod(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQJob1NMethod: recordset of TblWznmQJob1NMethod
	*/
class ListWznmQJob1NMethod {

public:
	ListWznmQJob1NMethod();
	ListWznmQJob1NMethod(const ListWznmQJob1NMethod& src);
	~ListWznmQJob1NMethod();

	void clear();
	unsigned int size() const;
	void append(WznmQJob1NMethod* rec);

	ListWznmQJob1NMethod& operator=(const ListWznmQJob1NMethod& src);

public:
	std::vector<WznmQJob1NMethod*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQJob1NMethod: C++ wrapper for table TblWznmQJob1NMethod
	*/
class TblWznmQJob1NMethod {

public:
	TblWznmQJob1NMethod();
	virtual ~TblWznmQJob1NMethod();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQJob1NMethod** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJob1NMethod& rst);

	virtual Sbecore::ubigint insertRec(WznmQJob1NMethod* rec);
	Sbecore::ubigint insertNewRec(WznmQJob1NMethod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQJob1NMethod& rst, WznmQJob1NMethod** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQJob1NMethod& rst);
	virtual void updateRec(WznmQJob1NMethod* rec);
	virtual void updateRst(ListWznmQJob1NMethod& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQJob1NMethod** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJob1NMethod& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQJob1NMethod: C++ wrapper for table TblWznmQJob1NMethod (MySQL database)
	*/
class MyTblWznmQJob1NMethod : public TblWznmQJob1NMethod, public Sbecore::MyTable {

public:
	MyTblWznmQJob1NMethod();
	~MyTblWznmQJob1NMethod();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJob1NMethod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJob1NMethod& rst);

	Sbecore::ubigint insertRec(WznmQJob1NMethod* rec);
	void insertRst(ListWznmQJob1NMethod& rst);
	void updateRec(WznmQJob1NMethod* rec);
	void updateRst(ListWznmQJob1NMethod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJob1NMethod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJob1NMethod& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQJob1NMethod: C++ wrapper for table TblWznmQJob1NMethod (PgSQL database)
	*/
class PgTblWznmQJob1NMethod : public TblWznmQJob1NMethod, public Sbecore::PgTable {

public:
	PgTblWznmQJob1NMethod();
	~PgTblWznmQJob1NMethod();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQJob1NMethod** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQJob1NMethod& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQJob1NMethod** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQJob1NMethod& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJob1NMethod** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJob1NMethod& rst);

	Sbecore::ubigint insertRec(WznmQJob1NMethod* rec);
	void insertRst(ListWznmQJob1NMethod& rst);
	void updateRec(WznmQJob1NMethod* rec);
	void updateRst(ListWznmQJob1NMethod& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJob1NMethod** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJob1NMethod& rst);
};
#endif

#endif
