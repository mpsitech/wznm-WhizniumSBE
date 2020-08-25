/**
	* \file WznmMPanel.h
	* database access for table TblWznmMPanel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMMPANEL_H
#define WZNMMPANEL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMPanelBasetype TblWznmMPanel::VecVBasetype
#define VecWznmVMPanelRefTbl TblWznmMPanel::VecVRefTbl

/**
	* WznmMPanel: record of TblWznmMPanel
	*/
class WznmMPanel {

public:
	WznmMPanel(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint carRefWznmMCard = 0, const Sbecore::uint carNum = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const bool Detach = false, const std::string Avail = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint carRefWznmMCard;
	Sbecore::uint carNum;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::ubigint refWznmMJob;
	std::string sref;
	bool Detach;
	std::string Avail;
	std::string Comment;

public:
	bool operator==(const WznmMPanel& comp);
	bool operator!=(const WznmMPanel& comp);
};

/**
	* ListWznmMPanel: recordset of TblWznmMPanel
	*/
class ListWznmMPanel {

public:
	ListWznmMPanel();
	ListWznmMPanel(const ListWznmMPanel& src);
	~ListWznmMPanel();

	void clear();
	unsigned int size() const;
	void append(WznmMPanel* rec);

	WznmMPanel* operator[](const Sbecore::uint ix);
	ListWznmMPanel& operator=(const ListWznmMPanel& src);
	bool operator==(const ListWznmMPanel& comp);
	bool operator!=(const ListWznmMPanel& comp);

public:
	std::vector<WznmMPanel*> nodes;
};

/**
	* TblWznmMPanel: C++ wrapper for table TblWznmMPanel
	*/
class TblWznmMPanel {

public:
	/**
		* VecVBasetype (full: VecWznmVMPanelBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint HEADBAR = 1;
		static const Sbecore::uint HEADLINE = 2;
		static const Sbecore::uint FORM = 3;
		static const Sbecore::uint LIST = 4;
		static const Sbecore::uint REC = 5;
		static const Sbecore::uint RECFORM = 6;
		static const Sbecore::uint RECLIST = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVRefTbl (full: VecWznmVMPanelRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint MDL = 2;
		static const Sbecore::uint TBL = 3;
		static const Sbecore::uint REL = 4;
		static const Sbecore::uint VEC = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMPanel();
	virtual ~TblWznmMPanel();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMPanel** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMPanel& rst);

	virtual Sbecore::ubigint insertRec(WznmMPanel* rec);
	Sbecore::ubigint insertNewRec(WznmMPanel** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint carRefWznmMCard = 0, const Sbecore::uint carNum = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const bool Detach = false, const std::string Avail = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMPanel& rst, WznmMPanel** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint carRefWznmMCard = 0, const Sbecore::uint carNum = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const bool Detach = false, const std::string Avail = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMPanel& rst, bool transact = false);
	virtual void updateRec(WznmMPanel* rec);
	virtual void updateRst(ListWznmMPanel& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMPanel** rec);
	virtual bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMPanel** rec);
	virtual Sbecore::ubigint loadRefsByCar(Sbecore::ubigint carRefWznmMCard, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCar(Sbecore::ubigint carRefWznmMCard, const bool append, ListWznmMPanel& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMPanel& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMPanel: C++ wrapper for table TblWznmMPanel (MySQL database)
	*/
class MyTblWznmMPanel : public TblWznmMPanel, public Sbecore::MyTable {

public:
	MyTblWznmMPanel();
	~MyTblWznmMPanel();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMPanel& rst);

	Sbecore::ubigint insertRec(WznmMPanel* rec);
	void insertRst(ListWznmMPanel& rst, bool transact = false);
	void updateRec(WznmMPanel* rec);
	void updateRst(ListWznmMPanel& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMPanel** rec);
	bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMPanel** rec);
	Sbecore::ubigint loadRefsByCar(Sbecore::ubigint carRefWznmMCard, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCar(Sbecore::ubigint carRefWznmMCard, const bool append, ListWznmMPanel& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMPanel: C++ wrapper for table TblWznmMPanel (PgSQL database)
	*/
class PgTblWznmMPanel : public TblWznmMPanel, public Sbecore::PgTable {

public:
	PgTblWznmMPanel();
	~PgTblWznmMPanel();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMPanel** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMPanel& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMPanel** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMPanel& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMPanel& rst);

	Sbecore::ubigint insertRec(WznmMPanel* rec);
	void insertRst(ListWznmMPanel& rst, bool transact = false);
	void updateRec(WznmMPanel* rec);
	void updateRst(ListWznmMPanel& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMPanel** rec);
	bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMPanel** rec);
	Sbecore::ubigint loadRefsByCar(Sbecore::ubigint carRefWznmMCard, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCar(Sbecore::ubigint carRefWznmMCard, const bool append, ListWznmMPanel& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

