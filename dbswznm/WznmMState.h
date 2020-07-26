/**
	* \file WznmMState.h
	* database access for table TblWznmMState (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMMSTATE_H
#define WZNMMSTATE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMStateAction TblWznmMState::VecVAction

/**
	* WznmMState: record of TblWznmMState
	*/
class WznmMState {

public:
	WznmMState(const Sbecore::ubigint ref = 0, const Sbecore::ubigint seqRefWznmMSequence = 0, const Sbecore::uint seqNum = 0, const std::string sref = "", const Sbecore::uint eacIxVAction = 0, const Sbecore::ubigint erjRefWznmMRtjob = 0, const Sbecore::ubigint eveRefWznmMVector = 0, const Sbecore::ubigint eviRefWznmMVectoritem = 0, const Sbecore::ubigint esnRefWznmMState = 0, const Sbecore::uint lacIxVAction = 0, const bool Custstep = false, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint seqRefWznmMSequence;
	Sbecore::uint seqNum;
	std::string sref;
	Sbecore::uint eacIxVAction;
	Sbecore::ubigint erjRefWznmMRtjob;
	Sbecore::ubigint eveRefWznmMVector;
	Sbecore::ubigint eviRefWznmMVectoritem;
	Sbecore::ubigint esnRefWznmMState;
	Sbecore::uint lacIxVAction;
	bool Custstep;
	std::string Comment;

public:
	bool operator==(const WznmMState& comp);
	bool operator!=(const WznmMState& comp);
};

/**
	* ListWznmMState: recordset of TblWznmMState
	*/
class ListWznmMState {

public:
	ListWznmMState();
	ListWznmMState(const ListWznmMState& src);
	~ListWznmMState();

	void clear();
	unsigned int size() const;
	void append(WznmMState* rec);

	WznmMState* operator[](const Sbecore::uint ix);
	ListWznmMState& operator=(const ListWznmMState& src);
	bool operator==(const ListWznmMState& comp);
	bool operator!=(const ListWznmMState& comp);

public:
	std::vector<WznmMState*> nodes;
};

/**
	* TblWznmMState: C++ wrapper for table TblWznmMState
	*/
class TblWznmMState {

public:
	/**
		* VecVAction (full: VecWznmVMStateAction)
		*/
	class VecVAction {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint LOGIN = 2;
		static const Sbecore::uint INIT = 3;
		static const Sbecore::uint DO = 4;
		static const Sbecore::uint STEP = 5;
		static const Sbecore::uint CUST = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMState();
	virtual ~TblWznmMState();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMState** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMState& rst);

	virtual Sbecore::ubigint insertRec(WznmMState* rec);
	Sbecore::ubigint insertNewRec(WznmMState** rec = NULL, const Sbecore::ubigint seqRefWznmMSequence = 0, const Sbecore::uint seqNum = 0, const std::string sref = "", const Sbecore::uint eacIxVAction = 0, const Sbecore::ubigint erjRefWznmMRtjob = 0, const Sbecore::ubigint eveRefWznmMVector = 0, const Sbecore::ubigint eviRefWznmMVectoritem = 0, const Sbecore::ubigint esnRefWznmMState = 0, const Sbecore::uint lacIxVAction = 0, const bool Custstep = false, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMState& rst, WznmMState** rec = NULL, const Sbecore::ubigint seqRefWznmMSequence = 0, const Sbecore::uint seqNum = 0, const std::string sref = "", const Sbecore::uint eacIxVAction = 0, const Sbecore::ubigint erjRefWznmMRtjob = 0, const Sbecore::ubigint eveRefWznmMVector = 0, const Sbecore::ubigint eviRefWznmMVectoritem = 0, const Sbecore::ubigint esnRefWznmMState = 0, const Sbecore::uint lacIxVAction = 0, const bool Custstep = false, const std::string Comment = "");
	virtual void insertRst(ListWznmMState& rst, bool transact = false);
	virtual void updateRec(WznmMState* rec);
	virtual void updateRst(ListWznmMState& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMState** rec);
	virtual Sbecore::ubigint loadRefsBySeq(Sbecore::ubigint seqRefWznmMSequence, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstBySeq(Sbecore::ubigint seqRefWznmMSequence, const bool append, ListWznmMState& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMState& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMState: C++ wrapper for table TblWznmMState (MySQL database)
	*/
class MyTblWznmMState : public TblWznmMState, public Sbecore::MyTable {

public:
	MyTblWznmMState();
	~MyTblWznmMState();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMState& rst);

	Sbecore::ubigint insertRec(WznmMState* rec);
	void insertRst(ListWznmMState& rst, bool transact = false);
	void updateRec(WznmMState* rec);
	void updateRst(ListWznmMState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMState** rec);
	Sbecore::ubigint loadRefsBySeq(Sbecore::ubigint seqRefWznmMSequence, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySeq(Sbecore::ubigint seqRefWznmMSequence, const bool append, ListWznmMState& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMState: C++ wrapper for table TblWznmMState (PgSQL database)
	*/
class PgTblWznmMState : public TblWznmMState, public Sbecore::PgTable {

public:
	PgTblWznmMState();
	~PgTblWznmMState();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMState** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMState& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMState** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMState& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMState** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMState& rst);

	Sbecore::ubigint insertRec(WznmMState* rec);
	void insertRst(ListWznmMState& rst, bool transact = false);
	void updateRec(WznmMState* rec);
	void updateRst(ListWznmMState& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMState** rec);
	Sbecore::ubigint loadRefsBySeq(Sbecore::ubigint seqRefWznmMSequence, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySeq(Sbecore::ubigint seqRefWznmMSequence, const bool append, ListWznmMState& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

