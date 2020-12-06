/**
	* \file WznmQCtpTpl1NCapability.h
	* Dbs and XML wrapper for table TblWznmQCtpTpl1NCapability (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCTPTPL1NCAPABILITY_H
#define WZNMQCTPTPL1NCAPABILITY_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCtpTpl1NCapability: record of TblWznmQCtpTpl1NCapability
	*/
class WznmQCtpTpl1NCapability {

public:
	WznmQCtpTpl1NCapability(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQCtpTpl1NCapability: recordset of TblWznmQCtpTpl1NCapability
	*/
class ListWznmQCtpTpl1NCapability {

public:
	ListWznmQCtpTpl1NCapability();
	ListWznmQCtpTpl1NCapability(const ListWznmQCtpTpl1NCapability& src);
	~ListWznmQCtpTpl1NCapability();

	void clear();
	unsigned int size() const;
	void append(WznmQCtpTpl1NCapability* rec);

	ListWznmQCtpTpl1NCapability& operator=(const ListWznmQCtpTpl1NCapability& src);

public:
	std::vector<WznmQCtpTpl1NCapability*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCtpTpl1NCapability: C++ wrapper for table TblWznmQCtpTpl1NCapability
	*/
class TblWznmQCtpTpl1NCapability {

public:
	TblWznmQCtpTpl1NCapability();
	virtual ~TblWznmQCtpTpl1NCapability();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCtpTpl1NCapability** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpTpl1NCapability& rst);

	virtual Sbecore::ubigint insertRec(WznmQCtpTpl1NCapability* rec);
	Sbecore::ubigint insertNewRec(WznmQCtpTpl1NCapability** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQCtpTpl1NCapability& rst, WznmQCtpTpl1NCapability** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQCtpTpl1NCapability& rst);
	virtual void updateRec(WznmQCtpTpl1NCapability* rec);
	virtual void updateRst(ListWznmQCtpTpl1NCapability& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpTpl1NCapability** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpTpl1NCapability& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCtpTpl1NCapability: C++ wrapper for table TblWznmQCtpTpl1NCapability (MySQL database)
	*/
class MyTblWznmQCtpTpl1NCapability : public TblWznmQCtpTpl1NCapability, public Sbecore::MyTable {

public:
	MyTblWznmQCtpTpl1NCapability();
	~MyTblWznmQCtpTpl1NCapability();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCtpTpl1NCapability** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpTpl1NCapability& rst);

	Sbecore::ubigint insertRec(WznmQCtpTpl1NCapability* rec);
	void insertRst(ListWznmQCtpTpl1NCapability& rst);
	void updateRec(WznmQCtpTpl1NCapability* rec);
	void updateRst(ListWznmQCtpTpl1NCapability& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpTpl1NCapability** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpTpl1NCapability& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCtpTpl1NCapability: C++ wrapper for table TblWznmQCtpTpl1NCapability (PgSQL database)
	*/
class PgTblWznmQCtpTpl1NCapability : public TblWznmQCtpTpl1NCapability, public Sbecore::PgTable {

public:
	PgTblWznmQCtpTpl1NCapability();
	~PgTblWznmQCtpTpl1NCapability();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCtpTpl1NCapability** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCtpTpl1NCapability& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCtpTpl1NCapability** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCtpTpl1NCapability& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCtpTpl1NCapability** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCtpTpl1NCapability& rst);

	Sbecore::ubigint insertRec(WznmQCtpTpl1NCapability* rec);
	void insertRst(ListWznmQCtpTpl1NCapability& rst);
	void updateRec(WznmQCtpTpl1NCapability* rec);
	void updateRst(ListWznmQCtpTpl1NCapability& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCtpTpl1NCapability** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCtpTpl1NCapability& rst);
};
#endif

#endif
