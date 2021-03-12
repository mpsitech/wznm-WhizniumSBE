/**
	* \file WznmMControl.h
	* database access for table TblWznmMControl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMCONTROL_H
#define WZNMMCONTROL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMControlBasetype TblWznmMControl::VecVBasetype
#define VecWznmVMControlHkSection TblWznmMControl::VecVHkSection
#define VecWznmVMControlHkTbl TblWznmMControl::VecVHkTbl
#define VecWznmVMControlRefTbl TblWznmMControl::VecVRefTbl
#define VecWznmVMControlScope TblWznmMControl::VecVScope
#define VecWznmVMControlSubtype TblWznmMControl::VecVSubtype
#define VecWznmWMControlSubset TblWznmMControl::VecWSubset

/**
	* WznmMControl: record of TblWznmMControl
	*/
class WznmMControl {

public:
	WznmMControl(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmCControl = 0, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const Sbecore::uint hkNum = 0, const Sbecore::uint hkIxVSection = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint supRefWznmMControl = 0, const Sbecore::usmallint supLvl = 0, const Sbecore::uint supNum = 0, const Sbecore::uint ixVScope = 0, const Sbecore::ubigint refWznmMFeed = 0, const std::string sref = "", const Sbecore::uint ixVSubtype = 0, const std::string srefsWznmMTag = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const Sbecore::ubigint refJ = 0, const Sbecore::ubigint stdRefWznmMStub = 0, const Sbecore::ubigint shoRefWznmMStub = 0, const std::string Avail = "", const std::string Active = "", const std::string srefsKOption = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmCControl;
	Sbecore::uint hkIxVTbl;
	Sbecore::ubigint hkUref;
	Sbecore::uint hkNum;
	Sbecore::uint hkIxVSection;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::ubigint supRefWznmMControl;
	Sbecore::usmallint supLvl;
	Sbecore::uint supNum;
	Sbecore::uint ixVScope;
	Sbecore::ubigint refWznmMFeed;
	std::string sref;
	Sbecore::uint ixVSubtype;
	std::string srefsWznmMTag;
	Sbecore::ubigint refJTitle;
	std::string Title;
	Sbecore::ubigint refJ;
	Sbecore::ubigint stdRefWznmMStub;
	Sbecore::ubigint shoRefWznmMStub;
	std::string Avail;
	std::string Active;
	std::string srefsKOption;

public:
	bool operator==(const WznmMControl& comp);
	bool operator!=(const WznmMControl& comp);
};

/**
	* ListWznmMControl: recordset of TblWznmMControl
	*/
class ListWznmMControl {

public:
	ListWznmMControl();
	ListWznmMControl(const ListWznmMControl& src);
	~ListWznmMControl();

	void clear();
	unsigned int size() const;
	void append(WznmMControl* rec);

	WznmMControl* operator[](const Sbecore::uint ix);
	ListWznmMControl& operator=(const ListWznmMControl& src);
	bool operator==(const ListWznmMControl& comp);
	bool operator!=(const ListWznmMControl& comp);

public:
	std::vector<WznmMControl*> nodes;
};

/**
	* TblWznmMControl: C++ wrapper for table TblWznmMControl
	*/
class TblWznmMControl {

public:
	/**
		* VecVBasetype (full: VecWznmVMControlBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint ALR = 1;
		static const Sbecore::uint BUT = 2;
		static const Sbecore::uint CHK = 3;
		static const Sbecore::uint CPT = 4;
		static const Sbecore::uint CSI = 5;
		static const Sbecore::uint CUS = 6;
		static const Sbecore::uint DIT = 7;
		static const Sbecore::uint DLD = 8;
		static const Sbecore::uint DSE = 9;
		static const Sbecore::uint HDG = 10;
		static const Sbecore::uint HSB = 11;
		static const Sbecore::uint LSB = 12;
		static const Sbecore::uint LST = 13;
		static const Sbecore::uint MCB = 14;
		static const Sbecore::uint MEN = 15;
		static const Sbecore::uint MIT = 16;
		static const Sbecore::uint MSP = 17;
		static const Sbecore::uint MRL = 18;
		static const Sbecore::uint MTX = 19;
		static const Sbecore::uint PUP = 20;
		static const Sbecore::uint RBU = 21;
		static const Sbecore::uint SEP = 22;
		static const Sbecore::uint SGE = 23;
		static const Sbecore::uint SLD = 24;
		static const Sbecore::uint SPC = 25;
		static const Sbecore::uint TBL = 26;
		static const Sbecore::uint TCO = 27;
		static const Sbecore::uint TOS = 28;
		static const Sbecore::uint TRS = 29;
		static const Sbecore::uint TSB = 30;
		static const Sbecore::uint TXF = 31;
		static const Sbecore::uint TXT = 32;
		static const Sbecore::uint UPD = 33;
		static const Sbecore::uint ULD = 34;
		static const Sbecore::uint VSB = 35;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVHkSection (full: VecWznmVMControlHkSection)
		*/
	class VecVHkSection {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint MBAR = 2;
		static const Sbecore::uint SIDE = 3;
		static const Sbecore::uint HDR = 4;
		static const Sbecore::uint HDRDETD = 5;
		static const Sbecore::uint HDRREGD = 6;
		static const Sbecore::uint CONT = 7;
		static const Sbecore::uint CONTDETD = 8;
		static const Sbecore::uint CONTREGD = 9;
		static const Sbecore::uint TBL = 10;
		static const Sbecore::uint FTR = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVHkTbl (full: VecWznmVMControlHkTbl)
		*/
	class VecVHkTbl {

	public:
		static const Sbecore::uint CAR = 1;
		static const Sbecore::uint DLG = 2;
		static const Sbecore::uint PNL = 3;
		static const Sbecore::uint VER = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVRefTbl (full: VecWznmVMControlRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint DLG = 2;
		static const Sbecore::uint QCO = 3;
		static const Sbecore::uint REL = 4;
		static const Sbecore::uint TBL = 5;
		static const Sbecore::uint TCO = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVScope (full: VecWznmVMControlScope)
		*/
	class VecVScope {

	public:
		static const Sbecore::uint APP = 1;
		static const Sbecore::uint SHR = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVSubtype (full: VecWznmVMControlSubtype)
		*/
	class VecVSubtype {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint DITSTD = 2;
		static const Sbecore::uint DITARR = 3;
		static const Sbecore::uint DITDLD = 4;
		static const Sbecore::uint DITULD = 5;
		static const Sbecore::uint DITPRG = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecWSubset (full: VecWznmWMControlSubset)
		*/
	class VecWSubset {

	public:
		static const Sbecore::uint SBSWZNMBMCONTROLCAI = 1;
		static const Sbecore::uint SBSWZNMBMCONTROLCFB = 2;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);
	};

public:
	TblWznmMControl();
	virtual ~TblWznmMControl();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMControl** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMControl& rst);

	virtual Sbecore::ubigint insertRec(WznmMControl* rec);
	Sbecore::ubigint insertNewRec(WznmMControl** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmCControl = 0, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const Sbecore::uint hkNum = 0, const Sbecore::uint hkIxVSection = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint supRefWznmMControl = 0, const Sbecore::usmallint supLvl = 0, const Sbecore::uint supNum = 0, const Sbecore::uint ixVScope = 0, const Sbecore::ubigint refWznmMFeed = 0, const std::string sref = "", const Sbecore::uint ixVSubtype = 0, const std::string srefsWznmMTag = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const Sbecore::ubigint refJ = 0, const Sbecore::ubigint stdRefWznmMStub = 0, const Sbecore::ubigint shoRefWznmMStub = 0, const std::string Avail = "", const std::string Active = "", const std::string srefsKOption = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMControl& rst, WznmMControl** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmCControl = 0, const Sbecore::uint hkIxVTbl = 0, const Sbecore::ubigint hkUref = 0, const Sbecore::uint hkNum = 0, const Sbecore::uint hkIxVSection = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint supRefWznmMControl = 0, const Sbecore::usmallint supLvl = 0, const Sbecore::uint supNum = 0, const Sbecore::uint ixVScope = 0, const Sbecore::ubigint refWznmMFeed = 0, const std::string sref = "", const Sbecore::uint ixVSubtype = 0, const std::string srefsWznmMTag = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const Sbecore::ubigint refJ = 0, const Sbecore::ubigint stdRefWznmMStub = 0, const Sbecore::ubigint shoRefWznmMStub = 0, const std::string Avail = "", const std::string Active = "", const std::string srefsKOption = "");
	virtual void insertRst(ListWznmMControl& rst, bool transact = false);
	virtual void updateRec(WznmMControl* rec);
	virtual void updateRst(ListWznmMControl& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMControl** rec);
	virtual bool confirmByRef(Sbecore::ubigint ref);
	virtual bool loadRecByFed(Sbecore::ubigint refWznmMFeed, WznmMControl** rec);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCControl, const bool append, ListWznmMControl& rst);
	virtual Sbecore::ubigint loadRstByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, ListWznmMControl& rst);
	virtual Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWznmMControl, const bool append, ListWznmMControl& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	virtual bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWznmMControl);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMControl& rst);
	Sbecore::ubigint loadHrefsup(Sbecore::ubigint ref, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadHrefsdown(Sbecore::ubigint ref, const bool append, std::vector<Sbecore::ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
	Sbecore::ubigint loadHrstup(Sbecore::ubigint ref, ListWznmMControl& rst);
	Sbecore::ubigint loadHrstdown(Sbecore::ubigint ref, const bool append, ListWznmMControl& rst, unsigned int firstix = 0, unsigned int lastix = 0);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMControl: C++ wrapper for table TblWznmMControl (MySQL database)
	*/
class MyTblWznmMControl : public TblWznmMControl, public Sbecore::MyTable {

public:
	MyTblWznmMControl();
	~MyTblWznmMControl();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMControl& rst);

	Sbecore::ubigint insertRec(WznmMControl* rec);
	void insertRst(ListWznmMControl& rst, bool transact = false);
	void updateRec(WznmMControl* rec);
	void updateRst(ListWznmMControl& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMControl** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	bool loadRecByFed(Sbecore::ubigint refWznmMFeed, WznmMControl** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCControl, const bool append, ListWznmMControl& rst);
	Sbecore::ubigint loadRstByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, ListWznmMControl& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWznmMControl, const bool append, ListWznmMControl& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWznmMControl);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMControl: C++ wrapper for table TblWznmMControl (PgSQL database)
	*/
class PgTblWznmMControl : public TblWznmMControl, public Sbecore::PgTable {

public:
	PgTblWznmMControl();
	~PgTblWznmMControl();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMControl** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMControl& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMControl** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMControl& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMControl& rst);

	Sbecore::ubigint insertRec(WznmMControl* rec);
	void insertRst(ListWznmMControl& rst, bool transact = false);
	void updateRec(WznmMControl* rec);
	void updateRst(ListWznmMControl& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMControl** rec);
	bool confirmByRef(Sbecore::ubigint ref);
	bool loadRecByFed(Sbecore::ubigint refWznmMFeed, WznmMControl** rec);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRefsBySup(Sbecore::ubigint supRefWznmMControl, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCControl, const bool append, ListWznmMControl& rst);
	Sbecore::ubigint loadRstByHktHku(Sbecore::uint hkIxVTbl, Sbecore::ubigint hkUref, const bool append, ListWznmMControl& rst);
	Sbecore::ubigint loadRstBySup(Sbecore::ubigint supRefWznmMControl, const bool append, ListWznmMControl& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	bool loadSupByRef(Sbecore::ubigint ref, Sbecore::ubigint& supRefWznmMControl);
};
#endif

#endif
