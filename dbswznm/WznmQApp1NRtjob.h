/**
	* \file WznmQApp1NRtjob.h
	* Dbs and XML wrapper for table TblWznmQApp1NRtjob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQAPP1NRTJOB_H
#define WZNMQAPP1NRTJOB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQApp1NRtjob: record of TblWznmQApp1NRtjob
	*/
class WznmQApp1NRtjob {

public:
	WznmQApp1NRtjob(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQApp1NRtjob: recordset of TblWznmQApp1NRtjob
	*/
class ListWznmQApp1NRtjob {

public:
	ListWznmQApp1NRtjob();
	ListWznmQApp1NRtjob(const ListWznmQApp1NRtjob& src);
	~ListWznmQApp1NRtjob();

	void clear();
	unsigned int size() const;
	void append(WznmQApp1NRtjob* rec);

	ListWznmQApp1NRtjob& operator=(const ListWznmQApp1NRtjob& src);

public:
	std::vector<WznmQApp1NRtjob*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQApp1NRtjob: C++ wrapper for table TblWznmQApp1NRtjob
	*/
class TblWznmQApp1NRtjob {

public:
	TblWznmQApp1NRtjob();
	virtual ~TblWznmQApp1NRtjob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQApp1NRtjob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQApp1NRtjob& rst);

	virtual Sbecore::ubigint insertRec(WznmQApp1NRtjob* rec);
	Sbecore::ubigint insertNewRec(WznmQApp1NRtjob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQApp1NRtjob& rst, WznmQApp1NRtjob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQApp1NRtjob& rst);
	virtual void updateRec(WznmQApp1NRtjob* rec);
	virtual void updateRst(ListWznmQApp1NRtjob& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQApp1NRtjob** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQApp1NRtjob& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQApp1NRtjob: C++ wrapper for table TblWznmQApp1NRtjob (MySQL database)
	*/
class MyTblWznmQApp1NRtjob : public TblWznmQApp1NRtjob, public Sbecore::MyTable {

public:
	MyTblWznmQApp1NRtjob();
	~MyTblWznmQApp1NRtjob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQApp1NRtjob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQApp1NRtjob& rst);

	Sbecore::ubigint insertRec(WznmQApp1NRtjob* rec);
	void insertRst(ListWznmQApp1NRtjob& rst);
	void updateRec(WznmQApp1NRtjob* rec);
	void updateRst(ListWznmQApp1NRtjob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQApp1NRtjob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQApp1NRtjob& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQApp1NRtjob: C++ wrapper for table TblWznmQApp1NRtjob (PgSQL database)
	*/
class PgTblWznmQApp1NRtjob : public TblWznmQApp1NRtjob, public Sbecore::PgTable {

public:
	PgTblWznmQApp1NRtjob();
	~PgTblWznmQApp1NRtjob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQApp1NRtjob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQApp1NRtjob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQApp1NRtjob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQApp1NRtjob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQApp1NRtjob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQApp1NRtjob& rst);

	Sbecore::ubigint insertRec(WznmQApp1NRtjob* rec);
	void insertRst(ListWznmQApp1NRtjob& rst);
	void updateRec(WznmQApp1NRtjob* rec);
	void updateRst(ListWznmQApp1NRtjob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQApp1NRtjob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQApp1NRtjob& rst);
};
#endif

#endif

