/**
	* \file WznmQJobSupMNJob.h
	* Dbs and XML wrapper for table TblWznmQJobSupMNJob (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOBSUPMNJOB_H
#define WZNMQJOBSUPMNJOB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQJobSupMNJob: record of TblWznmQJobSupMNJob
	*/
class WznmQJobSupMNJob {

public:
	WznmQJobSupMNJob(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const std::string Short = "", const bool Multi = false, const std::string yesnoMulti = "", const Sbecore::uint ixVConstract = 0, const std::string srefIxVConstract = "", const std::string titIxVConstract = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	std::string Short;
	bool Multi;
	std::string yesnoMulti;
	Sbecore::uint ixVConstract;
	std::string srefIxVConstract;
	std::string titIxVConstract;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQJobSupMNJob: recordset of TblWznmQJobSupMNJob
	*/
class ListWznmQJobSupMNJob {

public:
	ListWznmQJobSupMNJob();
	ListWznmQJobSupMNJob(const ListWznmQJobSupMNJob& src);
	~ListWznmQJobSupMNJob();

	void clear();
	unsigned int size() const;
	void append(WznmQJobSupMNJob* rec);

	ListWznmQJobSupMNJob& operator=(const ListWznmQJobSupMNJob& src);

public:
	std::vector<WznmQJobSupMNJob*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQJobSupMNJob: C++ wrapper for table TblWznmQJobSupMNJob
	*/
class TblWznmQJobSupMNJob {

public:
	TblWznmQJobSupMNJob();
	virtual ~TblWznmQJobSupMNJob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQJobSupMNJob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobSupMNJob& rst);

	virtual Sbecore::ubigint insertRec(WznmQJobSupMNJob* rec);
	Sbecore::ubigint insertNewRec(WznmQJobSupMNJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const std::string Short = "", const bool Multi = false, const std::string yesnoMulti = "", const Sbecore::uint ixVConstract = 0, const std::string srefIxVConstract = "", const std::string titIxVConstract = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQJobSupMNJob& rst, WznmQJobSupMNJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const std::string Short = "", const bool Multi = false, const std::string yesnoMulti = "", const Sbecore::uint ixVConstract = 0, const std::string srefIxVConstract = "", const std::string titIxVConstract = "");
	virtual void insertRst(ListWznmQJobSupMNJob& rst);
	virtual void updateRec(WznmQJobSupMNJob* rec);
	virtual void updateRst(ListWznmQJobSupMNJob& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQJobSupMNJob** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobSupMNJob& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQJobSupMNJob: C++ wrapper for table TblWznmQJobSupMNJob (MySQL database)
	*/
class MyTblWznmQJobSupMNJob : public TblWznmQJobSupMNJob, public Sbecore::MyTable {

public:
	MyTblWznmQJobSupMNJob();
	~MyTblWznmQJobSupMNJob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobSupMNJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobSupMNJob& rst);

	Sbecore::ubigint insertRec(WznmQJobSupMNJob* rec);
	void insertRst(ListWznmQJobSupMNJob& rst);
	void updateRec(WznmQJobSupMNJob* rec);
	void updateRst(ListWznmQJobSupMNJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobSupMNJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobSupMNJob& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQJobSupMNJob: C++ wrapper for table TblWznmQJobSupMNJob (PgSQL database)
	*/
class PgTblWznmQJobSupMNJob : public TblWznmQJobSupMNJob, public Sbecore::PgTable {

public:
	PgTblWznmQJobSupMNJob();
	~PgTblWznmQJobSupMNJob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQJobSupMNJob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQJobSupMNJob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQJobSupMNJob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQJobSupMNJob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobSupMNJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobSupMNJob& rst);

	Sbecore::ubigint insertRec(WznmQJobSupMNJob* rec);
	void insertRst(ListWznmQJobSupMNJob& rst);
	void updateRec(WznmQJobSupMNJob* rec);
	void updateRst(ListWznmQJobSupMNJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobSupMNJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobSupMNJob& rst);
};
#endif

#endif
