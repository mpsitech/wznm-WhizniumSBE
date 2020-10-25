/**
	* \file WznmQJobSubMNJob.h
	* Dbs and XML wrapper for table TblWznmQJobSubMNJob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQJOBSUBMNJOB_H
#define WZNMQJOBSUBMNJOB_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQJobSubMNJob: record of TblWznmQJobSubMNJob
	*/
class WznmQJobSubMNJob {

public:
	WznmQJobSubMNJob(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const std::string Short = "", const bool Multi = false, const std::string yesnoMulti = "", const Sbecore::uint ixVConstract = 0, const std::string srefIxVConstract = "", const std::string titIxVConstract = "");

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
	* ListWznmQJobSubMNJob: recordset of TblWznmQJobSubMNJob
	*/
class ListWznmQJobSubMNJob {

public:
	ListWznmQJobSubMNJob();
	ListWznmQJobSubMNJob(const ListWznmQJobSubMNJob& src);
	~ListWznmQJobSubMNJob();

	void clear();
	unsigned int size() const;
	void append(WznmQJobSubMNJob* rec);

	ListWznmQJobSubMNJob& operator=(const ListWznmQJobSubMNJob& src);

public:
	std::vector<WznmQJobSubMNJob*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQJobSubMNJob: C++ wrapper for table TblWznmQJobSubMNJob
	*/
class TblWznmQJobSubMNJob {

public:
	TblWznmQJobSubMNJob();
	virtual ~TblWznmQJobSubMNJob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQJobSubMNJob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobSubMNJob& rst);

	virtual Sbecore::ubigint insertRec(WznmQJobSubMNJob* rec);
	Sbecore::ubigint insertNewRec(WznmQJobSubMNJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const std::string Short = "", const bool Multi = false, const std::string yesnoMulti = "", const Sbecore::uint ixVConstract = 0, const std::string srefIxVConstract = "", const std::string titIxVConstract = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQJobSubMNJob& rst, WznmQJobSubMNJob** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const std::string Short = "", const bool Multi = false, const std::string yesnoMulti = "", const Sbecore::uint ixVConstract = 0, const std::string srefIxVConstract = "", const std::string titIxVConstract = "");
	virtual void insertRst(ListWznmQJobSubMNJob& rst);
	virtual void updateRec(WznmQJobSubMNJob* rec);
	virtual void updateRst(ListWznmQJobSubMNJob& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQJobSubMNJob** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobSubMNJob& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQJobSubMNJob: C++ wrapper for table TblWznmQJobSubMNJob (MySQL database)
	*/
class MyTblWznmQJobSubMNJob : public TblWznmQJobSubMNJob, public Sbecore::MyTable {

public:
	MyTblWznmQJobSubMNJob();
	~MyTblWznmQJobSubMNJob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobSubMNJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobSubMNJob& rst);

	Sbecore::ubigint insertRec(WznmQJobSubMNJob* rec);
	void insertRst(ListWznmQJobSubMNJob& rst);
	void updateRec(WznmQJobSubMNJob* rec);
	void updateRst(ListWznmQJobSubMNJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobSubMNJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobSubMNJob& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQJobSubMNJob: C++ wrapper for table TblWznmQJobSubMNJob (PgSQL database)
	*/
class PgTblWznmQJobSubMNJob : public TblWznmQJobSubMNJob, public Sbecore::PgTable {

public:
	PgTblWznmQJobSubMNJob();
	~PgTblWznmQJobSubMNJob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQJobSubMNJob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQJobSubMNJob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQJobSubMNJob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQJobSubMNJob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobSubMNJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobSubMNJob& rst);

	Sbecore::ubigint insertRec(WznmQJobSubMNJob* rec);
	void insertRst(ListWznmQJobSubMNJob& rst);
	void updateRec(WznmQJobSubMNJob* rec);
	void updateRst(ListWznmQJobSubMNJob& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobSubMNJob** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobSubMNJob& rst);
};
#endif

#endif

