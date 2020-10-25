/**
	* \file WznmMStage.h
	* database access for table TblWznmMStage (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMSTAGE_H
#define WZNMMSTAGE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMStageBasetype TblWznmMStage::VecVBasetype

/**
	* WznmMStage: record of TblWznmMStage
	*/
class WznmMStage {

public:
	WznmMStage(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint jobRefWznmMJob = 0, const Sbecore::uint jobNum = 0, const Sbecore::ubigint refWznmMSquawk = 0, const std::string sref = "", const Sbecore::uint Monitvl = 0, const Sbecore::ubigint snxRefWznmMStage = 0, const Sbecore::ubigint fnxRefWznmMStage = 0, const Sbecore::ubigint enxRefWznmMStage = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint jobRefWznmMJob;
	Sbecore::uint jobNum;
	Sbecore::ubigint refWznmMSquawk;
	std::string sref;
	Sbecore::uint Monitvl;
	Sbecore::ubigint snxRefWznmMStage;
	Sbecore::ubigint fnxRefWznmMStage;
	Sbecore::ubigint enxRefWznmMStage;
	std::string Comment;

public:
	bool operator==(const WznmMStage& comp);
	bool operator!=(const WznmMStage& comp);
};

/**
	* ListWznmMStage: recordset of TblWznmMStage
	*/
class ListWznmMStage {

public:
	ListWznmMStage();
	ListWznmMStage(const ListWznmMStage& src);
	~ListWznmMStage();

	void clear();
	unsigned int size() const;
	void append(WznmMStage* rec);

	WznmMStage* operator[](const Sbecore::uint ix);
	ListWznmMStage& operator=(const ListWznmMStage& src);
	bool operator==(const ListWznmMStage& comp);
	bool operator!=(const ListWznmMStage& comp);

public:
	std::vector<WznmMStage*> nodes;
};

/**
	* TblWznmMStage: C++ wrapper for table TblWznmMStage
	*/
class TblWznmMStage {

public:
	/**
		* VecVBasetype (full: VecWznmVMStageBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint ALR = 1;
		static const Sbecore::uint ERR = 2;
		static const Sbecore::uint IMMCB = 3;
		static const Sbecore::uint OPP = 4;
		static const Sbecore::uint OPIW = 5;
		static const Sbecore::uint OPPIW = 6;
		static const Sbecore::uint OTHER = 7;
		static const Sbecore::uint OTHWC = 8;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMStage();
	virtual ~TblWznmMStage();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMStage** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMStage& rst);

	virtual Sbecore::ubigint insertRec(WznmMStage* rec);
	Sbecore::ubigint insertNewRec(WznmMStage** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint jobRefWznmMJob = 0, const Sbecore::uint jobNum = 0, const Sbecore::ubigint refWznmMSquawk = 0, const std::string sref = "", const Sbecore::uint Monitvl = 0, const Sbecore::ubigint snxRefWznmMStage = 0, const Sbecore::ubigint fnxRefWznmMStage = 0, const Sbecore::ubigint enxRefWznmMStage = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMStage& rst, WznmMStage** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint jobRefWznmMJob = 0, const Sbecore::uint jobNum = 0, const Sbecore::ubigint refWznmMSquawk = 0, const std::string sref = "", const Sbecore::uint Monitvl = 0, const Sbecore::ubigint snxRefWznmMStage = 0, const Sbecore::ubigint fnxRefWznmMStage = 0, const Sbecore::ubigint enxRefWznmMStage = 0, const std::string Comment = "");
	virtual void insertRst(ListWznmMStage& rst, bool transact = false);
	virtual void updateRec(WznmMStage* rec);
	virtual void updateRst(ListWznmMStage& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMStage** rec);
	virtual bool loadRecBySqk(Sbecore::ubigint refWznmMSquawk, WznmMStage** rec);
	virtual Sbecore::ubigint loadRefsByJob(Sbecore::ubigint jobRefWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByJob(Sbecore::ubigint jobRefWznmMJob, const bool append, ListWznmMStage& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMStage& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMStage: C++ wrapper for table TblWznmMStage (MySQL database)
	*/
class MyTblWznmMStage : public TblWznmMStage, public Sbecore::MyTable {

public:
	MyTblWznmMStage();
	~MyTblWznmMStage();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMStage** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMStage& rst);

	Sbecore::ubigint insertRec(WznmMStage* rec);
	void insertRst(ListWznmMStage& rst, bool transact = false);
	void updateRec(WznmMStage* rec);
	void updateRst(ListWznmMStage& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMStage** rec);
	bool loadRecBySqk(Sbecore::ubigint refWznmMSquawk, WznmMStage** rec);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint jobRefWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint jobRefWznmMJob, const bool append, ListWznmMStage& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMStage: C++ wrapper for table TblWznmMStage (PgSQL database)
	*/
class PgTblWznmMStage : public TblWznmMStage, public Sbecore::PgTable {

public:
	PgTblWznmMStage();
	~PgTblWznmMStage();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMStage** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMStage& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMStage** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMStage& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMStage** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMStage& rst);

	Sbecore::ubigint insertRec(WznmMStage* rec);
	void insertRst(ListWznmMStage& rst, bool transact = false);
	void updateRec(WznmMStage* rec);
	void updateRst(ListWznmMStage& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMStage** rec);
	bool loadRecBySqk(Sbecore::ubigint refWznmMSquawk, WznmMStage** rec);
	Sbecore::ubigint loadRefsByJob(Sbecore::ubigint jobRefWznmMJob, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByJob(Sbecore::ubigint jobRefWznmMJob, const bool append, ListWznmMStage& rst);
};
#endif

#endif

