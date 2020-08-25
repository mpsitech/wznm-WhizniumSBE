/**
	* \file WznmQVer1NJob.h
	* Dbs and XML wrapper for table TblWznmQVer1NJob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQVER1NJOB_H
#define WZNMQVER1NJOB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVer1NJob: record of TblWznmQVer1NJob
	*/
class WznmQVer1NJob {

public:
	WznmQVer1NJob(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVer1NJob: recordset of TblWznmQVer1NJob
	*/
class ListWznmQVer1NJob {

public:
	ListWznmQVer1NJob();
	ListWznmQVer1NJob(const ListWznmQVer1NJob& src);
	~ListWznmQVer1NJob();

	void clear();
	unsigned int size() const;
	void append(WznmQVer1NJob* rec);

	ListWznmQVer1NJob& operator=(const ListWznmQVer1NJob& src);

public:
	std::vector<WznmQVer1NJob*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVer1NJob: C++ wrapper for table TblWznmQVer1NJob
	*/
class TblWznmQVer1NJob {

public:
	TblWznmQVer1NJob();
	virtual ~TblWznmQVer1NJob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NJob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NJob& rst);

	virtual Sbecore::ubigint insertRec(WznmQVer1NJob* rec);
	Sbecore::ubigint insertNewRec(WznmQVer1NJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVer1NJob& rst, WznmQVer1NJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVer1NJob& rst);
	virtual void updateRec(WznmQVer1NJob* rec);
	virtual void updateRst(ListWznmQVer1NJob& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NJob** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NJob& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVer1NJob: C++ wrapper for table TblWznmQVer1NJob (MySQL database)
	*/
class MyTblWznmQVer1NJob : public TblWznmQVer1NJob, public Sbecore::MyTable {

public:
	MyTblWznmQVer1NJob();
	~MyTblWznmQVer1NJob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NJob& rst);

	Sbecore::ubigint insertRec(WznmQVer1NJob* rec);
	void insertRst(ListWznmQVer1NJob& rst);
	void updateRec(WznmQVer1NJob* rec);
	void updateRst(ListWznmQVer1NJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NJob& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVer1NJob: C++ wrapper for table TblWznmQVer1NJob (PgSQL database)
	*/
class PgTblWznmQVer1NJob : public TblWznmQVer1NJob, public Sbecore::PgTable {

public:
	PgTblWznmQVer1NJob();
	~PgTblWznmQVer1NJob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVer1NJob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVer1NJob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVer1NJob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVer1NJob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVer1NJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVer1NJob& rst);

	Sbecore::ubigint insertRec(WznmQVer1NJob* rec);
	void insertRst(ListWznmQVer1NJob& rst);
	void updateRec(WznmQVer1NJob* rec);
	void updateRst(ListWznmQVer1NJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVer1NJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVer1NJob& rst);
};
#endif

#endif

