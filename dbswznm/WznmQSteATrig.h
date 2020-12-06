/**
	* \file WznmQSteATrig.h
	* Dbs and XML wrapper for table TblWznmQSteATrig (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQSTEATRIG_H
#define WZNMQSTEATRIG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSteATrig: record of TblWznmQSteATrig
	*/
class WznmQSteATrig {

public:
	WznmQSteATrig(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVType = 0, const std::string srefIxVType = "", const std::string titIxVType = "", const Sbecore::ubigint refWznmMEvent = 0, const std::string stubRefWznmMEvent = "", const Sbecore::ubigint refWznmMRtjob = 0, const std::string stubRefWznmMRtjob = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string xsref = "", const Sbecore::ubigint refWznmMRtdpch = 0, const std::string stubRefWznmMRtdpch = "", const std::string srefsMask = "", const std::string Cond = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	Sbecore::uint ixVType;
	std::string srefIxVType;
	std::string titIxVType;
	Sbecore::ubigint refWznmMEvent;
	std::string stubRefWznmMEvent;
	Sbecore::ubigint refWznmMRtjob;
	std::string stubRefWznmMRtjob;
	Sbecore::ubigint refWznmMVectoritem;
	std::string stubRefWznmMVectoritem;
	std::string xsref;
	Sbecore::ubigint refWznmMRtdpch;
	std::string stubRefWznmMRtdpch;
	std::string srefsMask;
	std::string Cond;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSteATrig: recordset of TblWznmQSteATrig
	*/
class ListWznmQSteATrig {

public:
	ListWznmQSteATrig();
	ListWznmQSteATrig(const ListWznmQSteATrig& src);
	~ListWznmQSteATrig();

	void clear();
	unsigned int size() const;
	void append(WznmQSteATrig* rec);

	ListWznmQSteATrig& operator=(const ListWznmQSteATrig& src);

public:
	std::vector<WznmQSteATrig*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSteATrig: C++ wrapper for table TblWznmQSteATrig
	*/
class TblWznmQSteATrig {

public:
	TblWznmQSteATrig();
	virtual ~TblWznmQSteATrig();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSteATrig** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSteATrig& rst);

	virtual Sbecore::ubigint insertRec(WznmQSteATrig* rec);
	Sbecore::ubigint insertNewRec(WznmQSteATrig** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVType = 0, const std::string srefIxVType = "", const std::string titIxVType = "", const Sbecore::ubigint refWznmMEvent = 0, const std::string stubRefWznmMEvent = "", const Sbecore::ubigint refWznmMRtjob = 0, const std::string stubRefWznmMRtjob = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string xsref = "", const Sbecore::ubigint refWznmMRtdpch = 0, const std::string stubRefWznmMRtdpch = "", const std::string srefsMask = "", const std::string Cond = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSteATrig& rst, WznmQSteATrig** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const Sbecore::uint ixVType = 0, const std::string srefIxVType = "", const std::string titIxVType = "", const Sbecore::ubigint refWznmMEvent = 0, const std::string stubRefWznmMEvent = "", const Sbecore::ubigint refWznmMRtjob = 0, const std::string stubRefWznmMRtjob = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string xsref = "", const Sbecore::ubigint refWznmMRtdpch = 0, const std::string stubRefWznmMRtdpch = "", const std::string srefsMask = "", const std::string Cond = "");
	virtual void insertRst(ListWznmQSteATrig& rst);
	virtual void updateRec(WznmQSteATrig* rec);
	virtual void updateRst(ListWznmQSteATrig& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSteATrig** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSteATrig& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSteATrig: C++ wrapper for table TblWznmQSteATrig (MySQL database)
	*/
class MyTblWznmQSteATrig : public TblWznmQSteATrig, public Sbecore::MyTable {

public:
	MyTblWznmQSteATrig();
	~MyTblWznmQSteATrig();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSteATrig** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSteATrig& rst);

	Sbecore::ubigint insertRec(WznmQSteATrig* rec);
	void insertRst(ListWznmQSteATrig& rst);
	void updateRec(WznmQSteATrig* rec);
	void updateRst(ListWznmQSteATrig& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSteATrig** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSteATrig& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSteATrig: C++ wrapper for table TblWznmQSteATrig (PgSQL database)
	*/
class PgTblWznmQSteATrig : public TblWznmQSteATrig, public Sbecore::PgTable {

public:
	PgTblWznmQSteATrig();
	~PgTblWznmQSteATrig();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSteATrig** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSteATrig& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSteATrig** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSteATrig& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSteATrig** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSteATrig& rst);

	Sbecore::ubigint insertRec(WznmQSteATrig* rec);
	void insertRst(ListWznmQSteATrig& rst);
	void updateRec(WznmQSteATrig* rec);
	void updateRst(ListWznmQSteATrig& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSteATrig** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSteATrig& rst);
};
#endif

#endif
