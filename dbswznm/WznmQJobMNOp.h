/**
	* \file WznmQJobMNOp.h
	* Dbs and XML wrapper for table TblWznmQJobMNOp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOBMNOP_H
#define WZNMQJOBMNOP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQJobMNOp: record of TblWznmQJobMNOp
	*/
class WznmQJobMNOp {

public:
	WznmQJobMNOp(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);

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
	* ListWznmQJobMNOp: recordset of TblWznmQJobMNOp
	*/
class ListWznmQJobMNOp {

public:
	ListWznmQJobMNOp();
	ListWznmQJobMNOp(const ListWznmQJobMNOp& src);
	~ListWznmQJobMNOp();

	void clear();
	unsigned int size() const;
	void append(WznmQJobMNOp* rec);

	ListWznmQJobMNOp& operator=(const ListWznmQJobMNOp& src);

public:
	std::vector<WznmQJobMNOp*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQJobMNOp: C++ wrapper for table TblWznmQJobMNOp
	*/
class TblWznmQJobMNOp {

public:
	TblWznmQJobMNOp();
	virtual ~TblWznmQJobMNOp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQJobMNOp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobMNOp& rst);

	virtual Sbecore::ubigint insertRec(WznmQJobMNOp* rec);
	Sbecore::ubigint insertNewRec(WznmQJobMNOp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQJobMNOp& rst, WznmQJobMNOp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0);
	virtual void insertRst(ListWznmQJobMNOp& rst);
	virtual void updateRec(WznmQJobMNOp* rec);
	virtual void updateRst(ListWznmQJobMNOp& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQJobMNOp** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobMNOp& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQJobMNOp: C++ wrapper for table TblWznmQJobMNOp (MySQL database)
	*/
class MyTblWznmQJobMNOp : public TblWznmQJobMNOp, public Sbecore::MyTable {

public:
	MyTblWznmQJobMNOp();
	~MyTblWznmQJobMNOp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobMNOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobMNOp& rst);

	Sbecore::ubigint insertRec(WznmQJobMNOp* rec);
	void insertRst(ListWznmQJobMNOp& rst);
	void updateRec(WznmQJobMNOp* rec);
	void updateRst(ListWznmQJobMNOp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobMNOp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobMNOp& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQJobMNOp: C++ wrapper for table TblWznmQJobMNOp (PgSQL database)
	*/
class PgTblWznmQJobMNOp : public TblWznmQJobMNOp, public Sbecore::PgTable {

public:
	PgTblWznmQJobMNOp();
	~PgTblWznmQJobMNOp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQJobMNOp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQJobMNOp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQJobMNOp** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQJobMNOp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobMNOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobMNOp& rst);

	Sbecore::ubigint insertRec(WznmQJobMNOp* rec);
	void insertRst(ListWznmQJobMNOp& rst);
	void updateRec(WznmQJobMNOp* rec);
	void updateRst(ListWznmQJobMNOp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobMNOp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobMNOp& rst);
};
#endif

#endif
