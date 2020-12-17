/**
	* \file WznmAMStateAction.h
	* database access for table TblWznmAMStateAction (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMAMSTATEACTION_H
#define WZNMAMSTATEACTION_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVAMStateActionSection TblWznmAMStateAction::VecVSection
#define VecWznmVAMStateActionType TblWznmAMStateAction::VecVType

/**
	* WznmAMStateAction: record of TblWznmAMStateAction
	*/
class WznmAMStateAction {

public:
	WznmAMStateAction(const Sbecore::ubigint ref = 0, const Sbecore::ubigint steRefWznmMState = 0, const Sbecore::uint steNum = 0, const Sbecore::uint ixVSection = 0, const Sbecore::uint ixVType = 0, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::ubigint refWznmMVectoritem = 0, const Sbecore::ubigint snxRefWznmMState = 0, const Sbecore::ubigint refWznmMSequence = 0, const std::string tr1SrefATrig = "", const std::string Ip1 = "", const std::string tr2SrefATrig = "", const std::string Ip2 = "", const std::string tr3SrefATrig = "", const std::string Ip3 = "", const std::string tr4SrefATrig = "", const std::string Ip4 = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint steRefWznmMState;
	Sbecore::uint steNum;
	Sbecore::uint ixVSection;
	Sbecore::uint ixVType;
	Sbecore::ubigint refWznmMRtjob;
	Sbecore::ubigint refWznmMVector;
	Sbecore::ubigint refWznmMVectoritem;
	Sbecore::ubigint snxRefWznmMState;
	Sbecore::ubigint refWznmMSequence;
	std::string tr1SrefATrig;
	std::string Ip1;
	std::string tr2SrefATrig;
	std::string Ip2;
	std::string tr3SrefATrig;
	std::string Ip3;
	std::string tr4SrefATrig;
	std::string Ip4;

public:
	bool operator==(const WznmAMStateAction& comp);
	bool operator!=(const WznmAMStateAction& comp);
};

/**
	* ListWznmAMStateAction: recordset of TblWznmAMStateAction
	*/
class ListWznmAMStateAction {

public:
	ListWznmAMStateAction();
	ListWznmAMStateAction(const ListWznmAMStateAction& src);
	~ListWznmAMStateAction();

	void clear();
	unsigned int size() const;
	void append(WznmAMStateAction* rec);

	WznmAMStateAction* operator[](const Sbecore::uint ix);
	ListWznmAMStateAction& operator=(const ListWznmAMStateAction& src);
	bool operator==(const ListWznmAMStateAction& comp);
	bool operator!=(const ListWznmAMStateAction& comp);

public:
	std::vector<WznmAMStateAction*> nodes;
};

/**
	* TblWznmAMStateAction: C++ wrapper for table TblWznmAMStateAction
	*/
class TblWznmAMStateAction {

public:
	/**
		* VecVSection (full: VecWznmVAMStateActionSection)
		*/
	class VecVSection {

	public:
		static const Sbecore::uint ENT = 1;
		static const Sbecore::uint REENT = 2;
		static const Sbecore::uint LVE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVType (full: VecWznmVAMStateActionType)
		*/
	class VecVType {

	public:
		static const Sbecore::uint LOGIN = 1;
		static const Sbecore::uint INIT = 2;
		static const Sbecore::uint DO = 3;
		static const Sbecore::uint STEP = 4;
		static const Sbecore::uint CSJSTEP = 5;
		static const Sbecore::uint CSJNTFSTEP = 6;
		static const Sbecore::uint STEPSEQ = 7;
		static const Sbecore::uint SUBSEQ = 8;
		static const Sbecore::uint RETSEQ = 9;
		static const Sbecore::uint BREAK = 10;
		static const Sbecore::uint CUST = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmAMStateAction();
	virtual ~TblWznmAMStateAction();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMStateAction** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMStateAction& rst);

	virtual Sbecore::ubigint insertRec(WznmAMStateAction* rec);
	Sbecore::ubigint insertNewRec(WznmAMStateAction** rec = NULL, const Sbecore::ubigint steRefWznmMState = 0, const Sbecore::uint steNum = 0, const Sbecore::uint ixVSection = 0, const Sbecore::uint ixVType = 0, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::ubigint refWznmMVectoritem = 0, const Sbecore::ubigint snxRefWznmMState = 0, const Sbecore::ubigint refWznmMSequence = 0, const std::string tr1SrefATrig = "", const std::string Ip1 = "", const std::string tr2SrefATrig = "", const std::string Ip2 = "", const std::string tr3SrefATrig = "", const std::string Ip3 = "", const std::string tr4SrefATrig = "", const std::string Ip4 = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMStateAction& rst, WznmAMStateAction** rec = NULL, const Sbecore::ubigint steRefWznmMState = 0, const Sbecore::uint steNum = 0, const Sbecore::uint ixVSection = 0, const Sbecore::uint ixVType = 0, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::ubigint refWznmMVector = 0, const Sbecore::ubigint refWznmMVectoritem = 0, const Sbecore::ubigint snxRefWznmMState = 0, const Sbecore::ubigint refWznmMSequence = 0, const std::string tr1SrefATrig = "", const std::string Ip1 = "", const std::string tr2SrefATrig = "", const std::string Ip2 = "", const std::string tr3SrefATrig = "", const std::string Ip3 = "", const std::string tr4SrefATrig = "", const std::string Ip4 = "");
	virtual void insertRst(ListWznmAMStateAction& rst, bool transact = false);
	virtual void updateRec(WznmAMStateAction* rec);
	virtual void updateRst(ListWznmAMStateAction& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMStateAction** rec);
	virtual Sbecore::ubigint loadRefsBySte(Sbecore::ubigint steRefWznmMState, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstBySte(Sbecore::ubigint steRefWznmMState, const bool append, ListWznmAMStateAction& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMStateAction& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMStateAction: C++ wrapper for table TblWznmAMStateAction (MySQL database)
	*/
class MyTblWznmAMStateAction : public TblWznmAMStateAction, public Sbecore::MyTable {

public:
	MyTblWznmAMStateAction();
	~MyTblWznmAMStateAction();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMStateAction** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMStateAction& rst);

	Sbecore::ubigint insertRec(WznmAMStateAction* rec);
	void insertRst(ListWznmAMStateAction& rst, bool transact = false);
	void updateRec(WznmAMStateAction* rec);
	void updateRst(ListWznmAMStateAction& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMStateAction** rec);
	Sbecore::ubigint loadRefsBySte(Sbecore::ubigint steRefWznmMState, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySte(Sbecore::ubigint steRefWznmMState, const bool append, ListWznmAMStateAction& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMStateAction: C++ wrapper for table TblWznmAMStateAction (PgSQL database)
	*/
class PgTblWznmAMStateAction : public TblWznmAMStateAction, public Sbecore::PgTable {

public:
	PgTblWznmAMStateAction();
	~PgTblWznmAMStateAction();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMStateAction** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMStateAction& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMStateAction** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMStateAction& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMStateAction** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMStateAction& rst);

	Sbecore::ubigint insertRec(WznmAMStateAction* rec);
	void insertRst(ListWznmAMStateAction& rst, bool transact = false);
	void updateRec(WznmAMStateAction* rec);
	void updateRst(ListWznmAMStateAction& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMStateAction** rec);
	Sbecore::ubigint loadRefsBySte(Sbecore::ubigint steRefWznmMState, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySte(Sbecore::ubigint steRefWznmMState, const bool append, ListWznmAMStateAction& rst);
};
#endif

#endif
