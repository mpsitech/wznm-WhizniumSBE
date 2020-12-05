/**
	* \file WznmQOpkMNJob.h
	* Dbs and XML wrapper for table TblWznmQOpkMNJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPKMNJOB_H
#define WZNMQOPKMNJOB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpkMNJob: record of TblWznmQOpkMNJob
	*/
class WznmQOpkMNJob {

public:
	WznmQOpkMNJob(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQOpkMNJob: recordset of TblWznmQOpkMNJob
	*/
class ListWznmQOpkMNJob {

public:
	ListWznmQOpkMNJob();
	ListWznmQOpkMNJob(const ListWznmQOpkMNJob& src);
	~ListWznmQOpkMNJob();

	void clear();
	unsigned int size() const;
	void append(WznmQOpkMNJob* rec);

	ListWznmQOpkMNJob& operator=(const ListWznmQOpkMNJob& src);

public:
	std::vector<WznmQOpkMNJob*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpkMNJob: C++ wrapper for table TblWznmQOpkMNJob
	*/
class TblWznmQOpkMNJob {

public:
	TblWznmQOpkMNJob();
	virtual ~TblWznmQOpkMNJob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpkMNJob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkMNJob& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpkMNJob* rec);
	Sbecore::ubigint insertNewRec(WznmQOpkMNJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpkMNJob& rst, WznmQOpkMNJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQOpkMNJob& rst);
	virtual void updateRec(WznmQOpkMNJob* rec);
	virtual void updateRst(ListWznmQOpkMNJob& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkMNJob** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkMNJob& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpkMNJob: C++ wrapper for table TblWznmQOpkMNJob (MySQL database)
	*/
class MyTblWznmQOpkMNJob : public TblWznmQOpkMNJob, public Sbecore::MyTable {

public:
	MyTblWznmQOpkMNJob();
	~MyTblWznmQOpkMNJob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkMNJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkMNJob& rst);

	Sbecore::ubigint insertRec(WznmQOpkMNJob* rec);
	void insertRst(ListWznmQOpkMNJob& rst);
	void updateRec(WznmQOpkMNJob* rec);
	void updateRst(ListWznmQOpkMNJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkMNJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkMNJob& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpkMNJob: C++ wrapper for table TblWznmQOpkMNJob (PgSQL database)
	*/
class PgTblWznmQOpkMNJob : public TblWznmQOpkMNJob, public Sbecore::PgTable {

public:
	PgTblWznmQOpkMNJob();
	~PgTblWznmQOpkMNJob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpkMNJob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpkMNJob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpkMNJob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpkMNJob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpkMNJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpkMNJob& rst);

	Sbecore::ubigint insertRec(WznmQOpkMNJob* rec);
	void insertRst(ListWznmQOpkMNJob& rst);
	void updateRec(WznmQOpkMNJob* rec);
	void updateRst(ListWznmQOpkMNJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpkMNJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpkMNJob& rst);
};
#endif

#endif

