/**
	* \file WznmQVecATitle.h
	* Dbs and XML wrapper for table TblWznmQVecATitle (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQVECATITLE_H
#define WZNMQVECATITLE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVecATitle: record of TblWznmQVecATitle
	*/
class WznmQVecATitle {

public:
	WznmQVecATitle(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const std::string Title = "");

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
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQVecATitle: recordset of TblWznmQVecATitle
	*/
class ListWznmQVecATitle {

public:
	ListWznmQVecATitle();
	ListWznmQVecATitle(const ListWznmQVecATitle& src);
	~ListWznmQVecATitle();

	void clear();
	unsigned int size() const;
	void append(WznmQVecATitle* rec);

	ListWznmQVecATitle& operator=(const ListWznmQVecATitle& src);

public:
	std::vector<WznmQVecATitle*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVecATitle: C++ wrapper for table TblWznmQVecATitle
	*/
class TblWznmQVecATitle {

public:
	TblWznmQVecATitle();
	virtual ~TblWznmQVecATitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVecATitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecATitle& rst);

	virtual Sbecore::ubigint insertRec(WznmQVecATitle* rec);
	Sbecore::ubigint insertNewRec(WznmQVecATitle** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVecATitle& rst, WznmQVecATitle** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const std::string Title = "");
	virtual void insertRst(ListWznmQVecATitle& rst);
	virtual void updateRec(WznmQVecATitle* rec);
	virtual void updateRst(ListWznmQVecATitle& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVecATitle** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecATitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVecATitle: C++ wrapper for table TblWznmQVecATitle (MySQL database)
	*/
class MyTblWznmQVecATitle : public TblWznmQVecATitle, public Sbecore::MyTable {

public:
	MyTblWznmQVecATitle();
	~MyTblWznmQVecATitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecATitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecATitle& rst);

	Sbecore::ubigint insertRec(WznmQVecATitle* rec);
	void insertRst(ListWznmQVecATitle& rst);
	void updateRec(WznmQVecATitle* rec);
	void updateRst(ListWznmQVecATitle& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecATitle** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecATitle& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVecATitle: C++ wrapper for table TblWznmQVecATitle (PgSQL database)
	*/
class PgTblWznmQVecATitle : public TblWznmQVecATitle, public Sbecore::PgTable {

public:
	PgTblWznmQVecATitle();
	~PgTblWznmQVecATitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVecATitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVecATitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVecATitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVecATitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVecATitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVecATitle& rst);

	Sbecore::ubigint insertRec(WznmQVecATitle* rec);
	void insertRst(ListWznmQVecATitle& rst);
	void updateRec(WznmQVecATitle* rec);
	void updateRst(ListWznmQVecATitle& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVecATitle** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVecATitle& rst);
};
#endif

#endif

