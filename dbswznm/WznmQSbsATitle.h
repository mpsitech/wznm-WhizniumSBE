/**
	* \file WznmQSbsATitle.h
	* Dbs and XML wrapper for table TblWznmQSbsATitle (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSBSATITLE_H
#define WZNMQSBSATITLE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSbsATitle: record of TblWznmQSbsATitle
	*/
class WznmQSbsATitle {

public:
	WznmQSbsATitle(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const Sbecore::uint ixWznmVGender = 0, const std::string srefIxWznmVGender = "", const std::string titIxWznmVGender = "", const std::string Title = "");

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
	Sbecore::uint ixWznmVGender;
	std::string srefIxWznmVGender;
	std::string titIxWznmVGender;
	std::string Title;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSbsATitle: recordset of TblWznmQSbsATitle
	*/
class ListWznmQSbsATitle {

public:
	ListWznmQSbsATitle();
	ListWznmQSbsATitle(const ListWznmQSbsATitle& src);
	~ListWznmQSbsATitle();

	void clear();
	unsigned int size() const;
	void append(WznmQSbsATitle* rec);

	ListWznmQSbsATitle& operator=(const ListWznmQSbsATitle& src);

public:
	std::vector<WznmQSbsATitle*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSbsATitle: C++ wrapper for table TblWznmQSbsATitle
	*/
class TblWznmQSbsATitle {

public:
	TblWznmQSbsATitle();
	virtual ~TblWznmQSbsATitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSbsATitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsATitle& rst);

	virtual Sbecore::ubigint insertRec(WznmQSbsATitle* rec);
	Sbecore::ubigint insertNewRec(WznmQSbsATitle** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const Sbecore::uint ixWznmVGender = 0, const std::string srefIxWznmVGender = "", const std::string titIxWznmVGender = "", const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSbsATitle& rst, WznmQSbsATitle** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const Sbecore::uint ixWznmVGender = 0, const std::string srefIxWznmVGender = "", const std::string titIxWznmVGender = "", const std::string Title = "");
	virtual void insertRst(ListWznmQSbsATitle& rst);
	virtual void updateRec(WznmQSbsATitle* rec);
	virtual void updateRst(ListWznmQSbsATitle& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsATitle** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsATitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSbsATitle: C++ wrapper for table TblWznmQSbsATitle (MySQL database)
	*/
class MyTblWznmQSbsATitle : public TblWznmQSbsATitle, public Sbecore::MyTable {

public:
	MyTblWznmQSbsATitle();
	~MyTblWznmQSbsATitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsATitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsATitle& rst);

	Sbecore::ubigint insertRec(WznmQSbsATitle* rec);
	void insertRst(ListWznmQSbsATitle& rst);
	void updateRec(WznmQSbsATitle* rec);
	void updateRst(ListWznmQSbsATitle& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsATitle** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsATitle& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSbsATitle: C++ wrapper for table TblWznmQSbsATitle (PgSQL database)
	*/
class PgTblWznmQSbsATitle : public TblWznmQSbsATitle, public Sbecore::PgTable {

public:
	PgTblWznmQSbsATitle();
	~PgTblWznmQSbsATitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSbsATitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSbsATitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSbsATitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSbsATitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSbsATitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSbsATitle& rst);

	Sbecore::ubigint insertRec(WznmQSbsATitle* rec);
	void insertRst(ListWznmQSbsATitle& rst);
	void updateRec(WznmQSbsATitle* rec);
	void updateRst(ListWznmQSbsATitle& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSbsATitle** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSbsATitle& rst);
};
#endif

#endif
