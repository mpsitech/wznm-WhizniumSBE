/**
	* \file WznmQOpxMNJob.h
	* Dbs and XML wrapper for table TblWznmQOpxMNJob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQOPXMNJOB_H
#define WZNMQOPXMNJOB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpxMNJob: record of TblWznmQOpxMNJob
	*/
class WznmQOpxMNJob {

public:
	WznmQOpxMNJob(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQOpxMNJob: recordset of TblWznmQOpxMNJob
	*/
class ListWznmQOpxMNJob {

public:
	ListWznmQOpxMNJob();
	ListWznmQOpxMNJob(const ListWznmQOpxMNJob& src);
	~ListWznmQOpxMNJob();

	void clear();
	unsigned int size() const;
	void append(WznmQOpxMNJob* rec);

	ListWznmQOpxMNJob& operator=(const ListWznmQOpxMNJob& src);

public:
	std::vector<WznmQOpxMNJob*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpxMNJob: C++ wrapper for table TblWznmQOpxMNJob
	*/
class TblWznmQOpxMNJob {

public:
	TblWznmQOpxMNJob();
	virtual ~TblWznmQOpxMNJob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpxMNJob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxMNJob& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpxMNJob* rec);
	Sbecore::ubigint insertNewRec(WznmQOpxMNJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpxMNJob& rst, WznmQOpxMNJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQOpxMNJob& rst);
	virtual void updateRec(WznmQOpxMNJob* rec);
	virtual void updateRst(ListWznmQOpxMNJob& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxMNJob** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxMNJob& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpxMNJob: C++ wrapper for table TblWznmQOpxMNJob (MySQL database)
	*/
class MyTblWznmQOpxMNJob : public TblWznmQOpxMNJob, public Sbecore::MyTable {

public:
	MyTblWznmQOpxMNJob();
	~MyTblWznmQOpxMNJob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpxMNJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxMNJob& rst);

	Sbecore::ubigint insertRec(WznmQOpxMNJob* rec);
	void insertRst(ListWznmQOpxMNJob& rst);
	void updateRec(WznmQOpxMNJob* rec);
	void updateRst(ListWznmQOpxMNJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxMNJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxMNJob& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpxMNJob: C++ wrapper for table TblWznmQOpxMNJob (PgSQL database)
	*/
class PgTblWznmQOpxMNJob : public TblWznmQOpxMNJob, public Sbecore::PgTable {

public:
	PgTblWznmQOpxMNJob();
	~PgTblWznmQOpxMNJob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpxMNJob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpxMNJob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpxMNJob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpxMNJob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpxMNJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpxMNJob& rst);

	Sbecore::ubigint insertRec(WznmQOpxMNJob* rec);
	void insertRst(ListWznmQOpxMNJob& rst);
	void updateRec(WznmQOpxMNJob* rec);
	void updateRst(ListWznmQOpxMNJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpxMNJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpxMNJob& rst);
};
#endif

#endif

