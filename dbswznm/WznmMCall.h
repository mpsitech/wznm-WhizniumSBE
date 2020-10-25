/**
	* \file WznmMCall.h
	* database access for table TblWznmMCall (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMCALL_H
#define WZNMMCALL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMCallBasetype TblWznmMCall::VecVBasetype
#define VecWznmVMCallRefTbl TblWznmMCall::VecVRefTbl
#define VecWznmWMCallSubset TblWznmMCall::VecWSubset

/**
	* WznmMCall: record of TblWznmMCall
	*/
class WznmMCall {

public:
	WznmMCall(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint invIxWznmWArgtype = 0, const Sbecore::uint retIxWznmWArgtype = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmMVersion;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::uint invIxWznmWArgtype;
	Sbecore::uint retIxWznmWArgtype;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WznmMCall& comp);
	bool operator!=(const WznmMCall& comp);
};

/**
	* ListWznmMCall: recordset of TblWznmMCall
	*/
class ListWznmMCall {

public:
	ListWznmMCall();
	ListWznmMCall(const ListWznmMCall& src);
	~ListWznmMCall();

	void clear();
	unsigned int size() const;
	void append(WznmMCall* rec);

	WznmMCall* operator[](const Sbecore::uint ix);
	ListWznmMCall& operator=(const ListWznmMCall& src);
	bool operator==(const ListWznmMCall& comp);
	bool operator!=(const ListWznmMCall& comp);

public:
	std::vector<WznmMCall*> nodes;
};

/**
	* TblWznmMCall: C++ wrapper for table TblWznmMCall
	*/
class TblWznmMCall {

public:
	/**
		* VecVBasetype (full: VecWznmVMCallBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint CHK = 1;
		static const Sbecore::uint EVT = 2;
		static const Sbecore::uint PSTSET = 3;
		static const Sbecore::uint RECUPD = 4;
		static const Sbecore::uint TBLMOD = 5;
		static const Sbecore::uint OTHER = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVRefTbl (full: VecWznmVMCallRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint CHK = 2;
		static const Sbecore::uint TBL = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWSubset (full: VecWznmWMCallSubset)
		*/
	class VecWSubset {

	public:
		static const Sbecore::uint SBSWZNMBMCALLCDC = 1;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);
	};

public:
	TblWznmMCall();
	virtual ~TblWznmMCall();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMCall** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMCall& rst);

	virtual Sbecore::ubigint insertRec(WznmMCall* rec);
	Sbecore::ubigint insertNewRec(WznmMCall** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint invIxWznmWArgtype = 0, const Sbecore::uint retIxWznmWArgtype = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMCall& rst, WznmMCall** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::uint invIxWznmWArgtype = 0, const Sbecore::uint retIxWznmWArgtype = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMCall& rst, bool transact = false);
	virtual void updateRec(WznmMCall* rec);
	virtual void updateRst(ListWznmMCall& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMCall** rec);
	virtual bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMCall& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMCall& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMCall: C++ wrapper for table TblWznmMCall (MySQL database)
	*/
class MyTblWznmMCall : public TblWznmMCall, public Sbecore::MyTable {

public:
	MyTblWznmMCall();
	~MyTblWznmMCall();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMCall& rst);

	Sbecore::ubigint insertRec(WznmMCall* rec);
	void insertRst(ListWznmMCall& rst, bool transact = false);
	void updateRec(WznmMCall* rec);
	void updateRst(ListWznmMCall& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMCall** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMCall& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMCall: C++ wrapper for table TblWznmMCall (PgSQL database)
	*/
class PgTblWznmMCall : public TblWznmMCall, public Sbecore::PgTable {

public:
	PgTblWznmMCall();
	~PgTblWznmMCall();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMCall** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMCall& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMCall** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMCall& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMCall** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMCall& rst);

	Sbecore::ubigint insertRec(WznmMCall* rec);
	void insertRst(ListWznmMCall& rst, bool transact = false);
	void updateRec(WznmMCall* rec);
	void updateRst(ListWznmMCall& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMCall** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMCall& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

