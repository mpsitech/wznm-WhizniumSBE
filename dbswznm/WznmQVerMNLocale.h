/**
	* \file WznmQVerMNLocale.h
	* Dbs and XML wrapper for table TblWznmQVerMNLocale (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVERMNLOCALE_H
#define WZNMQVERMNLOCALE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVerMNLocale: record of TblWznmQVerMNLocale
	*/
class WznmQVerMNLocale {

public:
	WznmQVerMNLocale(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQVerMNLocale: recordset of TblWznmQVerMNLocale
	*/
class ListWznmQVerMNLocale {

public:
	ListWznmQVerMNLocale();
	ListWznmQVerMNLocale(const ListWznmQVerMNLocale& src);
	~ListWznmQVerMNLocale();

	void clear();
	unsigned int size() const;
	void append(WznmQVerMNLocale* rec);

	ListWznmQVerMNLocale& operator=(const ListWznmQVerMNLocale& src);

public:
	std::vector<WznmQVerMNLocale*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVerMNLocale: C++ wrapper for table TblWznmQVerMNLocale
	*/
class TblWznmQVerMNLocale {

public:
	TblWznmQVerMNLocale();
	virtual ~TblWznmQVerMNLocale();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVerMNLocale** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerMNLocale& rst);

	virtual Sbecore::ubigint insertRec(WznmQVerMNLocale* rec);
	Sbecore::ubigint insertNewRec(WznmQVerMNLocale** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQVerMNLocale& rst, WznmQVerMNLocale** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQVerMNLocale& rst);
	virtual void updateRec(WznmQVerMNLocale* rec);
	virtual void updateRst(ListWznmQVerMNLocale& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVerMNLocale** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerMNLocale& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVerMNLocale: C++ wrapper for table TblWznmQVerMNLocale (MySQL database)
	*/
class MyTblWznmQVerMNLocale : public TblWznmQVerMNLocale, public Sbecore::MyTable {

public:
	MyTblWznmQVerMNLocale();
	~MyTblWznmQVerMNLocale();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerMNLocale** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerMNLocale& rst);

	Sbecore::ubigint insertRec(WznmQVerMNLocale* rec);
	void insertRst(ListWznmQVerMNLocale& rst);
	void updateRec(WznmQVerMNLocale* rec);
	void updateRst(ListWznmQVerMNLocale& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerMNLocale** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerMNLocale& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVerMNLocale: C++ wrapper for table TblWznmQVerMNLocale (PgSQL database)
	*/
class PgTblWznmQVerMNLocale : public TblWznmQVerMNLocale, public Sbecore::PgTable {

public:
	PgTblWznmQVerMNLocale();
	~PgTblWznmQVerMNLocale();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVerMNLocale** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVerMNLocale& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVerMNLocale** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVerMNLocale& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerMNLocale** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerMNLocale& rst);

	Sbecore::ubigint insertRec(WznmQVerMNLocale* rec);
	void insertRst(ListWznmQVerMNLocale& rst);
	void updateRec(WznmQVerMNLocale* rec);
	void updateRst(ListWznmQVerMNLocale& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerMNLocale** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerMNLocale& rst);
};
#endif

#endif

