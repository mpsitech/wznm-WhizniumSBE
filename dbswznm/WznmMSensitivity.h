/**
	* \file WznmMSensitivity.h
	* database access for table TblWznmMSensitivity (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMSENSITIVITY_H
#define WZNMMSENSITIVITY_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMSensitivityAction TblWznmMSensitivity::VecVAction
#define VecWznmVMSensitivityBasetype TblWznmMSensitivity::VecVBasetype
#define VecWznmVMSensitivityJactype TblWznmMSensitivity::VecVJactype
#define VecWznmVMSensitivityJobmask TblWznmMSensitivity::VecVJobmask

/**
	* WznmMSensitivity: record of TblWznmMSensitivity
	*/
class WznmMSensitivity {

public:
	WznmMSensitivity(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMJob = 0, const Sbecore::ubigint refWznmMStage = 0, const Sbecore::ubigint refWznmMCall = 0, const Sbecore::uint ixVJactype = 0, const Sbecore::uint ixVJobmask = 0, const std::string Jobshort = "", const std::string Argpatt = "", const Sbecore::ubigint refWznmMControl = 0, const std::string Srefmask = "", const Sbecore::uint ixVAction = 0, const Sbecore::ubigint csgRefWznmMStage = 0, const bool Custcode = false);

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmMJob;
	Sbecore::ubigint refWznmMStage;
	Sbecore::ubigint refWznmMCall;
	Sbecore::uint ixVJactype;
	Sbecore::uint ixVJobmask;
	std::string Jobshort;
	std::string Argpatt;
	Sbecore::ubigint refWznmMControl;
	std::string Srefmask;
	Sbecore::uint ixVAction;
	Sbecore::ubigint csgRefWznmMStage;
	bool Custcode;

public:
	bool operator==(const WznmMSensitivity& comp);
	bool operator!=(const WznmMSensitivity& comp);
};

/**
	* ListWznmMSensitivity: recordset of TblWznmMSensitivity
	*/
class ListWznmMSensitivity {

public:
	ListWznmMSensitivity();
	ListWznmMSensitivity(const ListWznmMSensitivity& src);
	~ListWznmMSensitivity();

	void clear();
	unsigned int size() const;
	void append(WznmMSensitivity* rec);

	WznmMSensitivity* operator[](const Sbecore::uint ix);
	ListWznmMSensitivity& operator=(const ListWznmMSensitivity& src);
	bool operator==(const ListWznmMSensitivity& comp);
	bool operator!=(const ListWznmMSensitivity& comp);

public:
	std::vector<WznmMSensitivity*> nodes;
};

/**
	* TblWznmMSensitivity: C++ wrapper for table TblWznmMSensitivity
	*/
class TblWznmMSensitivity {

public:
	/**
		* VecVAction (full: VecWznmVMSensitivityAction)
		*/
	class VecVAction {

	public:
		static const Sbecore::uint CHGSGE = 1;
		static const Sbecore::uint CHGSGESNX = 2;
		static const Sbecore::uint CHGSGEFNX = 3;
		static const Sbecore::uint UPDMON = 4;
		static const Sbecore::uint CUST = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVBasetype (full: VecWznmVMSensitivityBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint CAL = 1;
		static const Sbecore::uint CON = 2;
		static const Sbecore::uint ULD = 3;
		static const Sbecore::uint DLD = 4;
		static const Sbecore::uint TMR = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVJactype (full: VecWznmVMSensitivityJactype)
		*/
	class VecVJactype {

	public:
		static const Sbecore::uint LOCK = 1;
		static const Sbecore::uint TRY = 2;
		static const Sbecore::uint WEAK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVJobmask (full: VecWznmVMSensitivityJobmask)
		*/
	class VecVJobmask {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint ALL = 2;
		static const Sbecore::uint IMM = 3;
		static const Sbecore::uint SELF = 4;
		static const Sbecore::uint SPEC = 5;
		static const Sbecore::uint TREE = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

public:
	TblWznmMSensitivity();
	virtual ~TblWznmMSensitivity();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMSensitivity** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSensitivity& rst);

	virtual Sbecore::ubigint insertRec(WznmMSensitivity* rec);
	Sbecore::ubigint insertNewRec(WznmMSensitivity** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMJob = 0, const Sbecore::ubigint refWznmMStage = 0, const Sbecore::ubigint refWznmMCall = 0, const Sbecore::uint ixVJactype = 0, const Sbecore::uint ixVJobmask = 0, const std::string Jobshort = "", const std::string Argpatt = "", const Sbecore::ubigint refWznmMControl = 0, const std::string Srefmask = "", const Sbecore::uint ixVAction = 0, const Sbecore::ubigint csgRefWznmMStage = 0, const bool Custcode = false);
	Sbecore::ubigint appendNewRecToRst(ListWznmMSensitivity& rst, WznmMSensitivity** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMJob = 0, const Sbecore::ubigint refWznmMStage = 0, const Sbecore::ubigint refWznmMCall = 0, const Sbecore::uint ixVJactype = 0, const Sbecore::uint ixVJobmask = 0, const std::string Jobshort = "", const std::string Argpatt = "", const Sbecore::ubigint refWznmMControl = 0, const std::string Srefmask = "", const Sbecore::uint ixVAction = 0, const Sbecore::ubigint csgRefWznmMStage = 0, const bool Custcode = false);
	virtual void insertRst(ListWznmMSensitivity& rst, bool transact = false);
	virtual void updateRec(WznmMSensitivity* rec);
	virtual void updateRst(ListWznmMSensitivity& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMSensitivity** rec);
	virtual Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsBySge(Sbecore::ubigint refWznmMStage, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMSensitivity& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMSensitivity: C++ wrapper for table TblWznmMSensitivity (MySQL database)
	*/
class MyTblWznmMSensitivity : public TblWznmMSensitivity, public Sbecore::MyTable {

public:
	MyTblWznmMSensitivity();
	~MyTblWznmMSensitivity();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSensitivity& rst);

	Sbecore::ubigint insertRec(WznmMSensitivity* rec);
	void insertRst(ListWznmMSensitivity& rst, bool transact = false);
	void updateRec(WznmMSensitivity* rec);
	void updateRst(ListWznmMSensitivity& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMSensitivity** rec);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsBySge(Sbecore::ubigint refWznmMStage, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMSensitivity: C++ wrapper for table TblWznmMSensitivity (PgSQL database)
	*/
class PgTblWznmMSensitivity : public TblWznmMSensitivity, public Sbecore::PgTable {

public:
	PgTblWznmMSensitivity();
	~PgTblWznmMSensitivity();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMSensitivity** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMSensitivity& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMSensitivity** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMSensitivity** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMSensitivity& rst);

	Sbecore::ubigint insertRec(WznmMSensitivity* rec);
	void insertRst(ListWznmMSensitivity& rst, bool transact = false);
	void updateRec(WznmMSensitivity* rec);
	void updateRst(ListWznmMSensitivity& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMSensitivity** rec);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint refWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsBySge(Sbecore::ubigint refWznmMStage, const bool append, std::vector<Sbecore::ubigint>& refs);
};
#endif

#endif
