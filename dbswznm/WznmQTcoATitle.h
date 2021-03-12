/**
	* \file WznmQTcoATitle.h
	* Dbs and XML wrapper for table TblWznmQTcoATitle (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQTCOATITLE_H
#define WZNMQTCOATITLE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTcoATitle: record of TblWznmQTcoATitle
	*/
class WznmQTcoATitle {

public:
	WznmQTcoATitle(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const std::string Title = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint x1IxVType;
	std::string srefX1IxVType;
	std::string titX1IxVType;
	Sbecore::ubigint x2RefWznmMLocale;
	std::string stubX2RefWznmMLocale;
	std::string Title;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQTcoATitle: recordset of TblWznmQTcoATitle
	*/
class ListWznmQTcoATitle {

public:
	ListWznmQTcoATitle();
	ListWznmQTcoATitle(const ListWznmQTcoATitle& src);
	~ListWznmQTcoATitle();

	void clear();
	unsigned int size() const;
	void append(WznmQTcoATitle* rec);

	ListWznmQTcoATitle& operator=(const ListWznmQTcoATitle& src);

public:
	std::vector<WznmQTcoATitle*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTcoATitle: C++ wrapper for table TblWznmQTcoATitle
	*/
class TblWznmQTcoATitle {

public:
	TblWznmQTcoATitle();
	virtual ~TblWznmQTcoATitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTcoATitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTcoATitle& rst);

	virtual Sbecore::ubigint insertRec(WznmQTcoATitle* rec);
	Sbecore::ubigint insertNewRec(WznmQTcoATitle** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTcoATitle& rst, WznmQTcoATitle** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const std::string Title = "");
	virtual void insertRst(ListWznmQTcoATitle& rst);
	virtual void updateRec(WznmQTcoATitle* rec);
	virtual void updateRst(ListWznmQTcoATitle& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTcoATitle** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTcoATitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTcoATitle: C++ wrapper for table TblWznmQTcoATitle (MySQL database)
	*/
class MyTblWznmQTcoATitle : public TblWznmQTcoATitle, public Sbecore::MyTable {

public:
	MyTblWznmQTcoATitle();
	~MyTblWznmQTcoATitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTcoATitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTcoATitle& rst);

	Sbecore::ubigint insertRec(WznmQTcoATitle* rec);
	void insertRst(ListWznmQTcoATitle& rst);
	void updateRec(WznmQTcoATitle* rec);
	void updateRst(ListWznmQTcoATitle& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTcoATitle** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTcoATitle& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTcoATitle: C++ wrapper for table TblWznmQTcoATitle (PgSQL database)
	*/
class PgTblWznmQTcoATitle : public TblWznmQTcoATitle, public Sbecore::PgTable {

public:
	PgTblWznmQTcoATitle();
	~PgTblWznmQTcoATitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTcoATitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTcoATitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTcoATitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTcoATitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTcoATitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTcoATitle& rst);

	Sbecore::ubigint insertRec(WznmQTcoATitle* rec);
	void insertRst(ListWznmQTcoATitle& rst);
	void updateRec(WznmQTcoATitle* rec);
	void updateRst(ListWznmQTcoATitle& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTcoATitle** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTcoATitle& rst);
};
#endif

#endif
