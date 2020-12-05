/**
	* \file WznmMCard.h
	* database access for table TblWznmMCard (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMCARD_H
#define WZNMMCARD_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMCardRefTbl TblWznmMCard::VecVRefTbl

/**
	* WznmMCard: record of TblWznmMCard
	*/
class WznmMCard {

public:
	WznmMCard(const Sbecore::ubigint ref = 0, const Sbecore::ubigint mdlRefWznmMModule = 0, const Sbecore::uint mdlNum = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const std::string Avail = "", const std::string Active = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint mdlRefWznmMModule;
	Sbecore::uint mdlNum;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::ubigint refWznmMJob;
	std::string sref;
	Sbecore::ubigint refJTitle;
	std::string Title;
	std::string Avail;
	std::string Active;

public:
	bool operator==(const WznmMCard& comp);
	bool operator!=(const WznmMCard& comp);
};

/**
	* ListWznmMCard: recordset of TblWznmMCard
	*/
class ListWznmMCard {

public:
	ListWznmMCard();
	ListWznmMCard(const ListWznmMCard& src);
	~ListWznmMCard();

	void clear();
	unsigned int size() const;
	void append(WznmMCard* rec);

	WznmMCard* operator[](const Sbecore::uint ix);
	ListWznmMCard& operator=(const ListWznmMCard& src);
	bool operator==(const ListWznmMCard& comp);
	bool operator!=(const ListWznmMCard& comp);

public:
	std::vector<WznmMCard*> nodes;
};

/**
	* TblWznmMCard: C++ wrapper for table TblWznmMCard
	*/
class TblWznmMCard {

public:
	/**
		* VecVRefTbl (full: VecWznmVMCardRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint TBL = 2;
		static const Sbecore::uint SBS = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMCard();
	virtual ~TblWznmMCard();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMCard** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMCard& rst);

	virtual Sbecore::ubigint insertRec(WznmMCard* rec);
	Sbecore::ubigint insertNewRec(WznmMCard** rec = NULL, const Sbecore::ubigint mdlRefWznmMModule = 0, const Sbecore::uint mdlNum = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const std::string Avail = "", const std::string Active = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMCard& rst, WznmMCard** rec = NULL, const Sbecore::ubigint mdlRefWznmMModule = 0, const Sbecore::uint mdlNum = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "", const std::string Avail = "", const std::string Active = "");
	virtual void insertRst(ListWznmMCard& rst, bool transact = false);
	virtual void updateRec(WznmMCard* rec);
	virtual void updateRst(ListWznmMCard& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMCard** rec);
	virtual bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMCard** rec);
	virtual bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMCard** rec);
	virtual Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWznmMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWznmMModule, const bool append, ListWznmMCard& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMCard& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMCard: C++ wrapper for table TblWznmMCard (MySQL database)
	*/
class MyTblWznmMCard : public TblWznmMCard, public Sbecore::MyTable {

public:
	MyTblWznmMCard();
	~MyTblWznmMCard();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMCard** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMCard& rst);

	Sbecore::ubigint insertRec(WznmMCard* rec);
	void insertRst(ListWznmMCard& rst, bool transact = false);
	void updateRec(WznmMCard* rec);
	void updateRst(ListWznmMCard& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMCard** rec);
	bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMCard** rec);
	bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMCard** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWznmMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWznmMModule, const bool append, ListWznmMCard& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMCard: C++ wrapper for table TblWznmMCard (PgSQL database)
	*/
class PgTblWznmMCard : public TblWznmMCard, public Sbecore::PgTable {

public:
	PgTblWznmMCard();
	~PgTblWznmMCard();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMCard** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMCard& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMCard** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMCard& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMCard** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMCard& rst);

	Sbecore::ubigint insertRec(WznmMCard* rec);
	void insertRst(ListWznmMCard& rst, bool transact = false);
	void updateRec(WznmMCard* rec);
	void updateRst(ListWznmMCard& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMCard** rec);
	bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMCard** rec);
	bool loadRecByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, WznmMCard** rec);
	Sbecore::ubigint loadRefsByMdl(Sbecore::ubigint mdlRefWznmMModule, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByMdl(Sbecore::ubigint mdlRefWznmMModule, const bool append, ListWznmMCard& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

