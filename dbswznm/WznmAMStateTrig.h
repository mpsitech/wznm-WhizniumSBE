/**
	* \file WznmAMStateTrig.h
	* database access for table TblWznmAMStateTrig (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMAMSTATETRIG_H
#define WZNMAMSTATETRIG_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVAMStateTrigType TblWznmAMStateTrig::VecVType

/**
	* WznmAMStateTrig: record of TblWznmAMStateTrig
	*/
class WznmAMStateTrig {

public:
	WznmAMStateTrig(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMState = 0, const std::string sref = "", const Sbecore::uint ixVType = 0, const Sbecore::ubigint refWznmMEvent = 0, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::ubigint refWznmMVectoritem = 0, const std::string xsref = "", const Sbecore::ubigint refWznmMRtdpch = 0, const std::string srefsMask = "", const std::string Cond = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMState;
	std::string sref;
	Sbecore::uint ixVType;
	Sbecore::ubigint refWznmMEvent;
	Sbecore::ubigint refWznmMRtjob;
	Sbecore::ubigint refWznmMVectoritem;
	std::string xsref;
	Sbecore::ubigint refWznmMRtdpch;
	std::string srefsMask;
	std::string Cond;

public:
	bool operator==(const WznmAMStateTrig& comp);
	bool operator!=(const WznmAMStateTrig& comp);
};

/**
	* ListWznmAMStateTrig: recordset of TblWznmAMStateTrig
	*/
class ListWznmAMStateTrig {

public:
	ListWznmAMStateTrig();
	ListWznmAMStateTrig(const ListWznmAMStateTrig& src);
	~ListWznmAMStateTrig();

	void clear();
	unsigned int size() const;
	void append(WznmAMStateTrig* rec);

	WznmAMStateTrig* operator[](const Sbecore::uint ix);
	ListWznmAMStateTrig& operator=(const ListWznmAMStateTrig& src);
	bool operator==(const ListWznmAMStateTrig& comp);
	bool operator!=(const ListWznmAMStateTrig& comp);

public:
	std::vector<WznmAMStateTrig*> nodes;
};

/**
	* TblWznmAMStateTrig: C++ wrapper for table TblWznmAMStateTrig
	*/
class TblWznmAMStateTrig {

public:
	/**
		* VecVType (full: VecWznmVAMStateTrigType)
		*/
	class VecVType {

	public:
		static const Sbecore::uint EVT = 1;
		static const Sbecore::uint SGEEQ = 2;
		static const Sbecore::uint JOBEX = 3;
		static const Sbecore::uint JOBNEX = 4;
		static const Sbecore::uint CONFACC = 5;
		static const Sbecore::uint CONFDNY = 6;
		static const Sbecore::uint DPCHRCV = 7;
		static const Sbecore::uint CUST = 8;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmAMStateTrig();
	virtual ~TblWznmAMStateTrig();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmAMStateTrig** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMStateTrig& rst);

	virtual Sbecore::ubigint insertRec(WznmAMStateTrig* rec);
	Sbecore::ubigint insertNewRec(WznmAMStateTrig** rec = NULL, const Sbecore::ubigint refWznmMState = 0, const std::string sref = "", const Sbecore::uint ixVType = 0, const Sbecore::ubigint refWznmMEvent = 0, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::ubigint refWznmMVectoritem = 0, const std::string xsref = "", const Sbecore::ubigint refWznmMRtdpch = 0, const std::string srefsMask = "", const std::string Cond = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmAMStateTrig& rst, WznmAMStateTrig** rec = NULL, const Sbecore::ubigint refWznmMState = 0, const std::string sref = "", const Sbecore::uint ixVType = 0, const Sbecore::ubigint refWznmMEvent = 0, const Sbecore::ubigint refWznmMRtjob = 0, const Sbecore::ubigint refWznmMVectoritem = 0, const std::string xsref = "", const Sbecore::ubigint refWznmMRtdpch = 0, const std::string srefsMask = "", const std::string Cond = "");
	virtual void insertRst(ListWznmAMStateTrig& rst, bool transact = false);
	virtual void updateRec(WznmAMStateTrig* rec);
	virtual void updateRst(ListWznmAMStateTrig& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmAMStateTrig** rec);
	virtual Sbecore::ubigint loadRefsBySte(Sbecore::ubigint refWznmMState, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstBySte(Sbecore::ubigint refWznmMState, const bool append, ListWznmAMStateTrig& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmAMStateTrig& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmAMStateTrig: C++ wrapper for table TblWznmAMStateTrig (MySQL database)
	*/
class MyTblWznmAMStateTrig : public TblWznmAMStateTrig, public Sbecore::MyTable {

public:
	MyTblWznmAMStateTrig();
	~MyTblWznmAMStateTrig();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMStateTrig** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMStateTrig& rst);

	Sbecore::ubigint insertRec(WznmAMStateTrig* rec);
	void insertRst(ListWznmAMStateTrig& rst, bool transact = false);
	void updateRec(WznmAMStateTrig* rec);
	void updateRst(ListWznmAMStateTrig& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMStateTrig** rec);
	Sbecore::ubigint loadRefsBySte(Sbecore::ubigint refWznmMState, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySte(Sbecore::ubigint refWznmMState, const bool append, ListWznmAMStateTrig& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmAMStateTrig: C++ wrapper for table TblWznmAMStateTrig (PgSQL database)
	*/
class PgTblWznmAMStateTrig : public TblWznmAMStateTrig, public Sbecore::PgTable {

public:
	PgTblWznmAMStateTrig();
	~PgTblWznmAMStateTrig();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmAMStateTrig** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmAMStateTrig& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmAMStateTrig** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmAMStateTrig& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmAMStateTrig** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmAMStateTrig& rst);

	Sbecore::ubigint insertRec(WznmAMStateTrig* rec);
	void insertRst(ListWznmAMStateTrig& rst, bool transact = false);
	void updateRec(WznmAMStateTrig* rec);
	void updateRst(ListWznmAMStateTrig& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmAMStateTrig** rec);
	Sbecore::ubigint loadRefsBySte(Sbecore::ubigint refWznmMState, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstBySte(Sbecore::ubigint refWznmMState, const bool append, ListWznmAMStateTrig& rst);
};
#endif

#endif

