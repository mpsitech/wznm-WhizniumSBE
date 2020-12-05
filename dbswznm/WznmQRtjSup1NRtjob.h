/**
	* \file WznmQRtjSup1NRtjob.h
	* Dbs and XML wrapper for table TblWznmQRtjSup1NRtjob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQRTJSUP1NRTJOB_H
#define WZNMQRTJSUP1NRTJOB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQRtjSup1NRtjob: record of TblWznmQRtjSup1NRtjob
	*/
class WznmQRtjSup1NRtjob {

public:
	WznmQRtjSup1NRtjob(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQRtjSup1NRtjob: recordset of TblWznmQRtjSup1NRtjob
	*/
class ListWznmQRtjSup1NRtjob {

public:
	ListWznmQRtjSup1NRtjob();
	ListWznmQRtjSup1NRtjob(const ListWznmQRtjSup1NRtjob& src);
	~ListWznmQRtjSup1NRtjob();

	void clear();
	unsigned int size() const;
	void append(WznmQRtjSup1NRtjob* rec);

	ListWznmQRtjSup1NRtjob& operator=(const ListWznmQRtjSup1NRtjob& src);

public:
	std::vector<WznmQRtjSup1NRtjob*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQRtjSup1NRtjob: C++ wrapper for table TblWznmQRtjSup1NRtjob
	*/
class TblWznmQRtjSup1NRtjob {

public:
	TblWznmQRtjSup1NRtjob();
	virtual ~TblWznmQRtjSup1NRtjob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQRtjSup1NRtjob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRtjSup1NRtjob& rst);

	virtual Sbecore::ubigint insertRec(WznmQRtjSup1NRtjob* rec);
	Sbecore::ubigint insertNewRec(WznmQRtjSup1NRtjob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQRtjSup1NRtjob& rst, WznmQRtjSup1NRtjob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQRtjSup1NRtjob& rst);
	virtual void updateRec(WznmQRtjSup1NRtjob* rec);
	virtual void updateRst(ListWznmQRtjSup1NRtjob& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQRtjSup1NRtjob** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRtjSup1NRtjob& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQRtjSup1NRtjob: C++ wrapper for table TblWznmQRtjSup1NRtjob (MySQL database)
	*/
class MyTblWznmQRtjSup1NRtjob : public TblWznmQRtjSup1NRtjob, public Sbecore::MyTable {

public:
	MyTblWznmQRtjSup1NRtjob();
	~MyTblWznmQRtjSup1NRtjob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRtjSup1NRtjob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRtjSup1NRtjob& rst);

	Sbecore::ubigint insertRec(WznmQRtjSup1NRtjob* rec);
	void insertRst(ListWznmQRtjSup1NRtjob& rst);
	void updateRec(WznmQRtjSup1NRtjob* rec);
	void updateRst(ListWznmQRtjSup1NRtjob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRtjSup1NRtjob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRtjSup1NRtjob& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQRtjSup1NRtjob: C++ wrapper for table TblWznmQRtjSup1NRtjob (PgSQL database)
	*/
class PgTblWznmQRtjSup1NRtjob : public TblWznmQRtjSup1NRtjob, public Sbecore::PgTable {

public:
	PgTblWznmQRtjSup1NRtjob();
	~PgTblWznmQRtjSup1NRtjob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQRtjSup1NRtjob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQRtjSup1NRtjob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQRtjSup1NRtjob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQRtjSup1NRtjob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRtjSup1NRtjob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRtjSup1NRtjob& rst);

	Sbecore::ubigint insertRec(WznmQRtjSup1NRtjob* rec);
	void insertRst(ListWznmQRtjSup1NRtjob& rst);
	void updateRec(WznmQRtjSup1NRtjob* rec);
	void updateRst(ListWznmQRtjSup1NRtjob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRtjSup1NRtjob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRtjSup1NRtjob& rst);
};
#endif

#endif

