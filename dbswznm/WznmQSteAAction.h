/**
	* \file WznmQSteAAction.h
	* Dbs and XML wrapper for table TblWznmQSteAAction (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQSTEAACTION_H
#define WZNMQSTEAACTION_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQSteAAction: record of TblWznmQSteAAction
	*/
class WznmQSteAAction {

public:
	WznmQSteAAction(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint steNum = 0, const Sbecore::uint ixVSection = 0, const std::string srefIxVSection = "", const std::string titIxVSection = "", const Sbecore::uint ixVType = 0, const std::string srefIxVType = "", const std::string titIxVType = "", const Sbecore::ubigint refWznmMRtjob = 0, const std::string stubRefWznmMRtjob = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const Sbecore::ubigint snxRefWznmMState = 0, const std::string stubSnxRefWznmMState = "", const Sbecore::ubigint refWznmMSequence = 0, const std::string stubRefWznmMSequence = "", const std::string tr1SrefATrig = "", const std::string Ip1 = "", const std::string tr2SrefATrig = "", const std::string Ip2 = "", const std::string tr3SrefATrig = "", const std::string Ip3 = "", const std::string tr4SrefATrig = "", const std::string Ip4 = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	Sbecore::uint steNum;
	Sbecore::uint ixVSection;
	std::string srefIxVSection;
	std::string titIxVSection;
	Sbecore::uint ixVType;
	std::string srefIxVType;
	std::string titIxVType;
	Sbecore::ubigint refWznmMRtjob;
	std::string stubRefWznmMRtjob;
	Sbecore::ubigint refWznmMVector;
	std::string stubRefWznmMVector;
	Sbecore::ubigint refWznmMVectoritem;
	std::string stubRefWznmMVectoritem;
	Sbecore::ubigint snxRefWznmMState;
	std::string stubSnxRefWznmMState;
	Sbecore::ubigint refWznmMSequence;
	std::string stubRefWznmMSequence;
	std::string tr1SrefATrig;
	std::string Ip1;
	std::string tr2SrefATrig;
	std::string Ip2;
	std::string tr3SrefATrig;
	std::string Ip3;
	std::string tr4SrefATrig;
	std::string Ip4;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQSteAAction: recordset of TblWznmQSteAAction
	*/
class ListWznmQSteAAction {

public:
	ListWznmQSteAAction();
	ListWznmQSteAAction(const ListWznmQSteAAction& src);
	~ListWznmQSteAAction();

	void clear();
	unsigned int size() const;
	void append(WznmQSteAAction* rec);

	ListWznmQSteAAction& operator=(const ListWznmQSteAAction& src);

public:
	std::vector<WznmQSteAAction*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQSteAAction: C++ wrapper for table TblWznmQSteAAction
	*/
class TblWznmQSteAAction {

public:
	TblWznmQSteAAction();
	virtual ~TblWznmQSteAAction();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQSteAAction** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSteAAction& rst);

	virtual Sbecore::ubigint insertRec(WznmQSteAAction* rec);
	Sbecore::ubigint insertNewRec(WznmQSteAAction** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint steNum = 0, const Sbecore::uint ixVSection = 0, const std::string srefIxVSection = "", const std::string titIxVSection = "", const Sbecore::uint ixVType = 0, const std::string srefIxVType = "", const std::string titIxVType = "", const Sbecore::ubigint refWznmMRtjob = 0, const std::string stubRefWznmMRtjob = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const Sbecore::ubigint snxRefWznmMState = 0, const std::string stubSnxRefWznmMState = "", const Sbecore::ubigint refWznmMSequence = 0, const std::string stubRefWznmMSequence = "", const std::string tr1SrefATrig = "", const std::string Ip1 = "", const std::string tr2SrefATrig = "", const std::string Ip2 = "", const std::string tr3SrefATrig = "", const std::string Ip3 = "", const std::string tr4SrefATrig = "", const std::string Ip4 = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQSteAAction& rst, WznmQSteAAction** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const Sbecore::uint steNum = 0, const Sbecore::uint ixVSection = 0, const std::string srefIxVSection = "", const std::string titIxVSection = "", const Sbecore::uint ixVType = 0, const std::string srefIxVType = "", const std::string titIxVType = "", const Sbecore::ubigint refWznmMRtjob = 0, const std::string stubRefWznmMRtjob = "", const Sbecore::ubigint refWznmMVector = 0, const std::string stubRefWznmMVector = "", const Sbecore::ubigint refWznmMVectoritem = 0, const std::string stubRefWznmMVectoritem = "", const Sbecore::ubigint snxRefWznmMState = 0, const std::string stubSnxRefWznmMState = "", const Sbecore::ubigint refWznmMSequence = 0, const std::string stubRefWznmMSequence = "", const std::string tr1SrefATrig = "", const std::string Ip1 = "", const std::string tr2SrefATrig = "", const std::string Ip2 = "", const std::string tr3SrefATrig = "", const std::string Ip3 = "", const std::string tr4SrefATrig = "", const std::string Ip4 = "");
	virtual void insertRst(ListWznmQSteAAction& rst);
	virtual void updateRec(WznmQSteAAction* rec);
	virtual void updateRst(ListWznmQSteAAction& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQSteAAction** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSteAAction& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQSteAAction: C++ wrapper for table TblWznmQSteAAction (MySQL database)
	*/
class MyTblWznmQSteAAction : public TblWznmQSteAAction, public Sbecore::MyTable {

public:
	MyTblWznmQSteAAction();
	~MyTblWznmQSteAAction();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSteAAction** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSteAAction& rst);

	Sbecore::ubigint insertRec(WznmQSteAAction* rec);
	void insertRst(ListWznmQSteAAction& rst);
	void updateRec(WznmQSteAAction* rec);
	void updateRst(ListWznmQSteAAction& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSteAAction** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSteAAction& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQSteAAction: C++ wrapper for table TblWznmQSteAAction (PgSQL database)
	*/
class PgTblWznmQSteAAction : public TblWznmQSteAAction, public Sbecore::PgTable {

public:
	PgTblWznmQSteAAction();
	~PgTblWznmQSteAAction();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQSteAAction** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQSteAAction& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQSteAAction** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQSteAAction& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQSteAAction** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQSteAAction& rst);

	Sbecore::ubigint insertRec(WznmQSteAAction* rec);
	void insertRst(ListWznmQSteAAction& rst);
	void updateRec(WznmQSteAAction* rec);
	void updateRst(ListWznmQSteAAction& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQSteAAction** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQSteAAction& rst);
};
#endif

#endif

