/**
	* \file WznmQTblATitle.h
	* Dbs and XML wrapper for table TblWznmQTblATitle (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQTBLATITLE_H
#define WZNMQTBLATITLE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTblATitle: record of TblWznmQTblATitle
	*/
class WznmQTblATitle {

public:
	WznmQTblATitle(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const Sbecore::uint ixWznmVGender = 0, const std::string srefIxWznmVGender = "", const std::string titIxWznmVGender = "", const std::string Title = "");

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
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQTblATitle: recordset of TblWznmQTblATitle
	*/
class ListWznmQTblATitle {

public:
	ListWznmQTblATitle();
	ListWznmQTblATitle(const ListWznmQTblATitle& src);
	~ListWznmQTblATitle();

	void clear();
	unsigned int size() const;
	void append(WznmQTblATitle* rec);

	ListWznmQTblATitle& operator=(const ListWznmQTblATitle& src);

public:
	std::vector<WznmQTblATitle*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTblATitle: C++ wrapper for table TblWznmQTblATitle
	*/
class TblWznmQTblATitle {

public:
	TblWznmQTblATitle();
	virtual ~TblWznmQTblATitle();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTblATitle** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblATitle& rst);

	virtual Sbecore::ubigint insertRec(WznmQTblATitle* rec);
	Sbecore::ubigint insertNewRec(WznmQTblATitle** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const Sbecore::uint ixWznmVGender = 0, const std::string srefIxWznmVGender = "", const std::string titIxWznmVGender = "", const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTblATitle& rst, WznmQTblATitle** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint x1IxVType = 0, const std::string srefX1IxVType = "", const std::string titX1IxVType = "", const Sbecore::ubigint x2RefWznmMLocale = 0, const std::string stubX2RefWznmMLocale = "", const Sbecore::uint ixWznmVGender = 0, const std::string srefIxWznmVGender = "", const std::string titIxWznmVGender = "", const std::string Title = "");
	virtual void insertRst(ListWznmQTblATitle& rst);
	virtual void updateRec(WznmQTblATitle* rec);
	virtual void updateRst(ListWznmQTblATitle& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTblATitle** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblATitle& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTblATitle: C++ wrapper for table TblWznmQTblATitle (MySQL database)
	*/
class MyTblWznmQTblATitle : public TblWznmQTblATitle, public Sbecore::MyTable {

public:
	MyTblWznmQTblATitle();
	~MyTblWznmQTblATitle();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblATitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblATitle& rst);

	Sbecore::ubigint insertRec(WznmQTblATitle* rec);
	void insertRst(ListWznmQTblATitle& rst);
	void updateRec(WznmQTblATitle* rec);
	void updateRst(ListWznmQTblATitle& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblATitle** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblATitle& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTblATitle: C++ wrapper for table TblWznmQTblATitle (PgSQL database)
	*/
class PgTblWznmQTblATitle : public TblWznmQTblATitle, public Sbecore::PgTable {

public:
	PgTblWznmQTblATitle();
	~PgTblWznmQTblATitle();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTblATitle** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTblATitle& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTblATitle** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTblATitle& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTblATitle** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTblATitle& rst);

	Sbecore::ubigint insertRec(WznmQTblATitle* rec);
	void insertRst(ListWznmQTblATitle& rst);
	void updateRec(WznmQTblATitle* rec);
	void updateRst(ListWznmQTblATitle& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTblATitle** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTblATitle& rst);
};
#endif

#endif

