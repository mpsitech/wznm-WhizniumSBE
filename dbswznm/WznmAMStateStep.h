/**
	* \file WznmAMStateStep.h
	* database access for table TblWznmAMStateStep (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMAMSTATESTEP_H
#define WZNMAMSTATESTEP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVAMStateStepTrigger TblWznmAMStateStep::VecVTrigger

/**
	* WznmAMStateStep: record of TblWznmAMStateStep
	*/
class WznmAMStateStep {

public:
	WznmAMStateStep(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMState = 0, const Sbecore::ubigint snxRefWznmMState = 0, const Sbecore::uint ixVTrigger = 0, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::ubigint refWznmMVectoritem = 0, const std::string xsref = "", const Sbecore::ubigint refWznmMRtdpch = 0, const std::string srefsMask = "", const std::string Cond = "", const bool Custcode = false);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMState;
	Sbecore::ubigint snxRefWznmMState;
	Sbecore::uint ixVTrigger;
	Sbecore::ubigint refWznmMRtjob;
	Sbecore::ubigint refWznmMVectoritem;
	std::string xsref;
	Sbecore::ubigint refWznmMRtdpch;
	std::string srefsMask;
	std::string Cond;
	bool Custcode;

public:
	bool operator==(const WznmAMStateStep& comp);
	bool operator!=(const WznmAMStateStep& comp);
};

/**
	* ListWznmAMStateStep: recordset of TblWznmAMStateStep
	*/
class ListWznmAMStateStep {

public:
	ListWznmAMStateStep();
	ListWznmAMStateStep(const ListWznmAMStateStep& src);
	~ListWznmAMStateStep();

	void clear();
	unsigned int size() const;
	void append(WznmAMStateStep* rec);

	WznmAMStateStep* operator[](const Sbecore::uint ix);
	ListWznmAMStateStep& operator=(const ListWznmAMStateStep& src);
	bool operator==(const ListWznmAMStateStep& comp);
	bool operator!=(const ListWznmAMStateStep& comp);

public:
	std::vector<WznmAMStateStep*> nodes;
};

/**
	* TblWznmAMStateStep: C++ wrapper for table TblWznmAMStateStep
	*/
class TblWznmAMStateStep {

public:
	/**
		* VecVTrigger (full: VecWznmVAMStateStepTrigger)
		*/
	class VecVTrigger {

	public:
		static const Sbecore::uint SGEEQ = 1;
		static const Sbecore::uint JOBEX = 2;
		static const Sbecore::uint JOBNEX = 3;
		static const Sbecore::uint CONFACC = 4;
		static const Sbecore::uint CONFDNY = 5;
		static const Sbecore::uint DPCHRCV = 6;
		static const Sbecore::uint CUST = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmAMStateStep();
	virtual ~TblWznmAMStateStep();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMStateStep** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMStateStep& rst);

	virtual Sbecore::ubigint insertRec(WznmAMStateStep* rec);
	Sbecore::ubigint insertNewRec(WznmAMStateStep** rec = NULL, const Sbecore::ubigint refWznmMState = 0, const Sbecore::ubigint snxRefWznmMState = 0, const Sbecore::uint ixVTrigger = 0, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::ubigint refWznmMVectoritem = 0, const std::string xsref = "", const Sbecore::ubigint refWznmMRtdpch = 0, const std::string srefsMask = "", const std::string Cond = "", const bool Custcode = false);
	Sbecore::ubigint appendNewRecToRst(ListWznmAMStateStep& rst, WznmAMStateStep** rec = NULL, const Sbecore::ubigint refWznmMState = 0, const Sbecore::ubigint snxRefWznmMState = 0, const Sbecore::uint ixVTrigger = 0, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::ubigint refWznmMVectoritem = 0, const std::string xsref = "", const Sbecore::ubigint refWznmMRtdpch = 0, const std::string srefsMask = "", const std::string Cond = "", const bool Custcode = false);
	virtual void insertRst(ListWznmAMStateStep& rst, bool transact = false);
	virtual void updateRec(WznmAMStateStep* rec);
	virtual void updateRst(ListWznmAMStateStep& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMStateStep** rec);
	virtual Sbecore::ubigint loadRefsBySte(Sbecore::ubigint refWznmMState, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstBySte(Sbecore::ubigint refWznmMState, const bool append, ListWznmAMStateStep& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMStateStep& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMStateStep: C++ wrapper for table TblWznmAMStateStep (MySQL database)
	*/
class MyTblWznmAMStateStep : public TblWznmAMStateStep, public Sbecore::MyTable {

public:
	MyTblWznmAMStateStep();
	~MyTblWznmAMStateStep();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMStateStep** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMStateStep& rst);

	Sbecore::ubigint insertRec(WznmAMStateStep* rec);
	void insertRst(ListWznmAMStateStep& rst, bool transact = false);
	void updateRec(WznmAMStateStep* rec);
	void updateRst(ListWznmAMStateStep& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMStateStep** rec);
	Sbecore::ubigint loadRefsBySte(Sbecore::ubigint refWznmMState, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySte(Sbecore::ubigint refWznmMState, const bool append, ListWznmAMStateStep& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMStateStep: C++ wrapper for table TblWznmAMStateStep (PgSQL database)
	*/
class PgTblWznmAMStateStep : public TblWznmAMStateStep, public Sbecore::PgTable {

public:
	PgTblWznmAMStateStep();
	~PgTblWznmAMStateStep();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMStateStep** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMStateStep& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMStateStep** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMStateStep& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMStateStep** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMStateStep& rst);

	Sbecore::ubigint insertRec(WznmAMStateStep* rec);
	void insertRst(ListWznmAMStateStep& rst, bool transact = false);
	void updateRec(WznmAMStateStep* rec);
	void updateRst(ListWznmAMStateStep& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMStateStep** rec);
	Sbecore::ubigint loadRefsBySte(Sbecore::ubigint refWznmMState, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySte(Sbecore::ubigint refWznmMState, const bool append, ListWznmAMStateStep& rst);
};
#endif

#endif

