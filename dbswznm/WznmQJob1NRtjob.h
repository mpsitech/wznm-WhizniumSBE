/**
	* \file WznmQJob1NRtjob.h
	* Dbs and XML wrapper for table TblWznmQJob1NRtjob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOB1NRTJOB_H
#define WZNMQJOB1NRTJOB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQJob1NRtjob: record of TblWznmQJob1NRtjob
	*/
class WznmQJob1NRtjob {

public:
	WznmQJob1NRtjob(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQJob1NRtjob: recordset of TblWznmQJob1NRtjob
	*/
class ListWznmQJob1NRtjob {

public:
	ListWznmQJob1NRtjob();
	ListWznmQJob1NRtjob(const ListWznmQJob1NRtjob& src);
	~ListWznmQJob1NRtjob();

	void clear();
	unsigned int size() const;
	void append(WznmQJob1NRtjob* rec);

	ListWznmQJob1NRtjob& operator=(const ListWznmQJob1NRtjob& src);

public:
	std::vector<WznmQJob1NRtjob*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQJob1NRtjob: C++ wrapper for table TblWznmQJob1NRtjob
	*/
class TblWznmQJob1NRtjob {

public:
	TblWznmQJob1NRtjob();
	virtual ~TblWznmQJob1NRtjob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQJob1NRtjob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJob1NRtjob& rst);

	virtual Sbecore::ubigint insertRec(WznmQJob1NRtjob* rec);
	Sbecore::ubigint insertNewRec(WznmQJob1NRtjob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQJob1NRtjob& rst, WznmQJob1NRtjob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQJob1NRtjob& rst);
	virtual void updateRec(WznmQJob1NRtjob* rec);
	virtual void updateRst(ListWznmQJob1NRtjob& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQJob1NRtjob** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJob1NRtjob& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQJob1NRtjob: C++ wrapper for table TblWznmQJob1NRtjob (MySQL database)
	*/
class MyTblWznmQJob1NRtjob : public TblWznmQJob1NRtjob, public Sbecore::MyTable {

public:
	MyTblWznmQJob1NRtjob();
	~MyTblWznmQJob1NRtjob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJob1NRtjob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJob1NRtjob& rst);

	Sbecore::ubigint insertRec(WznmQJob1NRtjob* rec);
	void insertRst(ListWznmQJob1NRtjob& rst);
	void updateRec(WznmQJob1NRtjob* rec);
	void updateRst(ListWznmQJob1NRtjob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJob1NRtjob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJob1NRtjob& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQJob1NRtjob: C++ wrapper for table TblWznmQJob1NRtjob (PgSQL database)
	*/
class PgTblWznmQJob1NRtjob : public TblWznmQJob1NRtjob, public Sbecore::PgTable {

public:
	PgTblWznmQJob1NRtjob();
	~PgTblWznmQJob1NRtjob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQJob1NRtjob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQJob1NRtjob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQJob1NRtjob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQJob1NRtjob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJob1NRtjob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJob1NRtjob& rst);

	Sbecore::ubigint insertRec(WznmQJob1NRtjob* rec);
	void insertRst(ListWznmQJob1NRtjob& rst);
	void updateRec(WznmQJob1NRtjob* rec);
	void updateRst(ListWznmQJob1NRtjob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJob1NRtjob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJob1NRtjob& rst);
};
#endif

#endif

