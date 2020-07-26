/**
	* \file WznmQSteAStep.h
	* Dbs and XML wrapper for table TblWznmQSteAStep (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQSTEASTEP_H
#define WZNMQSTEASTEP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSteAStep: record of TblWznmQSteAStep
	*/
class WznmQSteAStep {

public:
	WznmQSteAStep(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint snxRefWznmMState = 0, const std::string stubSnxRefWznmMState = "", const Sbecore::uint ixVTrigger = 0, const std::string srefIxVTrigger = "", const std::string titIxVTrigger = "", const Sbecore::ubigint refWznmMRtjob = 0, const std::string stubRefWznmMRtjob = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string xsref = "", const Sbecore::ubigint refWznmMRtdpch = 0, const std::string stubRefWznmMRtdpch = "", const std::string srefsMask = "", const std::string Cond = "", const bool Custcode = false, const std::string yesnoCustcode = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::ubigint snxRefWznmMState;
	std::string stubSnxRefWznmMState;
	Sbecore::uint ixVTrigger;
	std::string srefIxVTrigger;
	std::string titIxVTrigger;
	Sbecore::ubigint refWznmMRtjob;
	std::string stubRefWznmMRtjob;
	Sbecore::ubigint refWznmMVectoritem;
	std::string stubRefWznmMVectoritem;
	std::string xsref;
	Sbecore::ubigint refWznmMRtdpch;
	std::string stubRefWznmMRtdpch;
	std::string srefsMask;
	std::string Cond;
	bool Custcode;
	std::string yesnoCustcode;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSteAStep: recordset of TblWznmQSteAStep
	*/
class ListWznmQSteAStep {

public:
	ListWznmQSteAStep();
	ListWznmQSteAStep(const ListWznmQSteAStep& src);
	~ListWznmQSteAStep();

	void clear();
	unsigned int size() const;
	void append(WznmQSteAStep* rec);

	ListWznmQSteAStep& operator=(const ListWznmQSteAStep& src);

public:
	std::vector<WznmQSteAStep*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSteAStep: C++ wrapper for table TblWznmQSteAStep
	*/
class TblWznmQSteAStep {

public:
	TblWznmQSteAStep();
	virtual ~TblWznmQSteAStep();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSteAStep** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSteAStep& rst);

	virtual Sbecore::ubigint insertRec(WznmQSteAStep* rec);
	Sbecore::ubigint insertNewRec(WznmQSteAStep** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint snxRefWznmMState = 0, const std::string stubSnxRefWznmMState = "", const Sbecore::uint ixVTrigger = 0, const std::string srefIxVTrigger = "", const std::string titIxVTrigger = "", const Sbecore::ubigint refWznmMRtjob = 0, const std::string stubRefWznmMRtjob = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string xsref = "", const Sbecore::ubigint refWznmMRtdpch = 0, const std::string stubRefWznmMRtdpch = "", const std::string srefsMask = "", const std::string Cond = "", const bool Custcode = false, const std::string yesnoCustcode = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSteAStep& rst, WznmQSteAStep** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::ubigint snxRefWznmMState = 0, const std::string stubSnxRefWznmMState = "", const Sbecore::uint ixVTrigger = 0, const std::string srefIxVTrigger = "", const std::string titIxVTrigger = "", const Sbecore::ubigint refWznmMRtjob = 0, const std::string stubRefWznmMRtjob = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const std::string xsref = "", const Sbecore::ubigint refWznmMRtdpch = 0, const std::string stubRefWznmMRtdpch = "", const std::string srefsMask = "", const std::string Cond = "", const bool Custcode = false, const std::string yesnoCustcode = "");
	virtual void insertRst(ListWznmQSteAStep& rst);
	virtual void updateRec(WznmQSteAStep* rec);
	virtual void updateRst(ListWznmQSteAStep& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSteAStep** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSteAStep& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSteAStep: C++ wrapper for table TblWznmQSteAStep (MySQL database)
	*/
class MyTblWznmQSteAStep : public TblWznmQSteAStep, public Sbecore::MyTable {

public:
	MyTblWznmQSteAStep();
	~MyTblWznmQSteAStep();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSteAStep** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSteAStep& rst);

	Sbecore::ubigint insertRec(WznmQSteAStep* rec);
	void insertRst(ListWznmQSteAStep& rst);
	void updateRec(WznmQSteAStep* rec);
	void updateRst(ListWznmQSteAStep& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSteAStep** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSteAStep& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSteAStep: C++ wrapper for table TblWznmQSteAStep (PgSQL database)
	*/
class PgTblWznmQSteAStep : public TblWznmQSteAStep, public Sbecore::PgTable {

public:
	PgTblWznmQSteAStep();
	~PgTblWznmQSteAStep();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSteAStep** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSteAStep& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSteAStep** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSteAStep& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSteAStep** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSteAStep& rst);

	Sbecore::ubigint insertRec(WznmQSteAStep* rec);
	void insertRst(ListWznmQSteAStep& rst);
	void updateRec(WznmQSteAStep* rec);
	void updateRst(ListWznmQSteAStep& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSteAStep** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSteAStep& rst);
};
#endif

#endif

