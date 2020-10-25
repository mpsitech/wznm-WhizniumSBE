/**
	* \file WznmMJob.h
	* database access for table TblWznmMJob (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMJOB_H
#define WZNMMJOB_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMJobBasetype TblWznmMJob::VecVBasetype
#define VecWznmVMJobRefTbl TblWznmMJob::VecVRefTbl

/**
	* WznmMJob: record of TblWznmMJob
	*/
class WznmMJob {

public:
	WznmMJob(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string sref = "", const bool Global = false, const bool Clisrv = false, const bool Shrdat = false, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmMVersion;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	std::string sref;
	bool Global;
	bool Clisrv;
	bool Shrdat;
	std::string Comment;

public:
	bool operator==(const WznmMJob& comp);
	bool operator!=(const WznmMJob& comp);
};

/**
	* ListWznmMJob: recordset of TblWznmMJob
	*/
class ListWznmMJob {

public:
	ListWznmMJob();
	ListWznmMJob(const ListWznmMJob& src);
	~ListWznmMJob();

	void clear();
	unsigned int size() const;
	void append(WznmMJob* rec);

	WznmMJob* operator[](const Sbecore::uint ix);
	ListWznmMJob& operator=(const ListWznmMJob& src);
	bool operator==(const ListWznmMJob& comp);
	bool operator!=(const ListWznmMJob& comp);

public:
	std::vector<WznmMJob*> nodes;
};

/**
	* TblWznmMJob: C++ wrapper for table TblWznmMJob
	*/
class TblWznmMJob {

public:
	/**
		* VecVBasetype (full: VecWznmVMJobBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint ROOT = 1;
		static const Sbecore::uint CRD = 2;
		static const Sbecore::uint DLG = 3;
		static const Sbecore::uint PNL = 4;
		static const Sbecore::uint QRY = 5;
		static const Sbecore::uint SESS = 6;
		static const Sbecore::uint IEX = 7;
		static const Sbecore::uint CUST = 8;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVRefTbl (full: VecWznmVMJobRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint CAR = 2;
		static const Sbecore::uint DLG = 3;
		static const Sbecore::uint PNL = 4;
		static const Sbecore::uint QRY = 5;
		static const Sbecore::uint IEX = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMJob();
	virtual ~TblWznmMJob();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMJob** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMJob& rst);

	virtual Sbecore::ubigint insertRec(WznmMJob* rec);
	Sbecore::ubigint insertNewRec(WznmMJob** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string sref = "", const bool Global = false, const bool Clisrv = false, const bool Shrdat = false, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMJob& rst, WznmMJob** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string sref = "", const bool Global = false, const bool Clisrv = false, const bool Shrdat = false, const std::string Comment = "");
	virtual void insertRst(ListWznmMJob& rst, bool transact = false);
	virtual void updateRec(WznmMJob* rec);
	virtual void updateRst(ListWznmMJob& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMJob** rec);
	virtual bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMJob** rec);
	virtual bool loadRefByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, Sbecore::ubigint& ref);
	virtual bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMJob& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMJob& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMJob: C++ wrapper for table TblWznmMJob (MySQL database)
	*/
class MyTblWznmMJob : public TblWznmMJob, public Sbecore::MyTable {

public:
	MyTblWznmMJob();
	~MyTblWznmMJob();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMJob& rst);

	Sbecore::ubigint insertRec(WznmMJob* rec);
	void insertRst(ListWznmMJob& rst, bool transact = false);
	void updateRec(WznmMJob* rec);
	void updateRst(ListWznmMJob& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMJob** rec);
	bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMJob** rec);
	bool loadRefByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, Sbecore::ubigint& ref);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMJob& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMJob: C++ wrapper for table TblWznmMJob (PgSQL database)
	*/
class PgTblWznmMJob : public TblWznmMJob, public Sbecore::PgTable {

public:
	PgTblWznmMJob();
	~PgTblWznmMJob();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMJob** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMJob& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMJob** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMJob& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMJob** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMJob& rst);

	Sbecore::ubigint insertRec(WznmMJob* rec);
	void insertRst(ListWznmMJob& rst, bool transact = false);
	void updateRec(WznmMJob* rec);
	void updateRst(ListWznmMJob& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMJob** rec);
	bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMJob** rec);
	bool loadRefByTypVer(Sbecore::uint ixVBasetype, Sbecore::ubigint refWznmMVersion, Sbecore::ubigint& ref);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMJob& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

