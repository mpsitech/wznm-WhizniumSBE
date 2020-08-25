/**
	* \file WznmQRelATitle.h
	* Dbs and XML wrapper for table TblWznmQRelATitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQRELATITLE_H
#define WZNMQRELATITLE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQRelATitle: record of TblWznmQRelATitle
	*/
class WznmQRelATitle {

public:
	WznmQRelATitle(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const std::string Title = "");

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
	* ListWznmQRelATitle: recordset of TblWznmQRelATitle
	*/
class ListWznmQRelATitle {

public:
	ListWznmQRelATitle();
	ListWznmQRelATitle(const ListWznmQRelATitle& src);
	~ListWznmQRelATitle();

	void clear();
	unsigned int size() const;
	void append(WznmQRelATitle* rec);

	ListWznmQRelATitle& operator=(const ListWznmQRelATitle& src);

public:
	std::vector<WznmQRelATitle*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQRelATitle: C++ wrapper for table TblWznmQRelATitle
	*/
class TblWznmQRelATitle {

public:
	TblWznmQRelATitle();
	virtual ~TblWznmQRelATitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQRelATitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelATitle& rst);

	virtual Sbecore::ubigint insertRec(WznmQRelATitle* rec);
	Sbecore::ubigint insertNewRec(WznmQRelATitle** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQRelATitle& rst, WznmQRelATitle** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const std::string Title = "");
	virtual void insertRst(ListWznmQRelATitle& rst);
	virtual void updateRec(WznmQRelATitle* rec);
	virtual void updateRst(ListWznmQRelATitle& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQRelATitle** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelATitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQRelATitle: C++ wrapper for table TblWznmQRelATitle (MySQL database)
	*/
class MyTblWznmQRelATitle : public TblWznmQRelATitle, public Sbecore::MyTable {

public:
	MyTblWznmQRelATitle();
	~MyTblWznmQRelATitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRelATitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelATitle& rst);

	Sbecore::ubigint insertRec(WznmQRelATitle* rec);
	void insertRst(ListWznmQRelATitle& rst);
	void updateRec(WznmQRelATitle* rec);
	void updateRst(ListWznmQRelATitle& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRelATitle** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelATitle& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQRelATitle: C++ wrapper for table TblWznmQRelATitle (PgSQL database)
	*/
class PgTblWznmQRelATitle : public TblWznmQRelATitle, public Sbecore::PgTable {

public:
	PgTblWznmQRelATitle();
	~PgTblWznmQRelATitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQRelATitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQRelATitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQRelATitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQRelATitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRelATitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelATitle& rst);

	Sbecore::ubigint insertRec(WznmQRelATitle* rec);
	void insertRst(ListWznmQRelATitle& rst);
	void updateRec(WznmQRelATitle* rec);
	void updateRst(ListWznmQRelATitle& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRelATitle** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelATitle& rst);
};
#endif

#endif

