/**
	* \file WznmMVisual.h
	* database access for table TblWznmMVisual (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMMVISUAL_H
#define WZNMMVISUAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMVisualBasetype TblWznmMVisual::VecVBasetype

/**
	* WznmMVisual: record of TblWznmMVisual
	*/
class WznmMVisual {

public:
	WznmMVisual(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint verRefWznmMVersion = 0, const Sbecore::uint verNum = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint verRefWznmMVersion;
	Sbecore::uint verNum;
	std::string Comment;

public:
	bool operator==(const WznmMVisual& comp);
	bool operator!=(const WznmMVisual& comp);
};

/**
	* ListWznmMVisual: recordset of TblWznmMVisual
	*/
class ListWznmMVisual {

public:
	ListWznmMVisual();
	ListWznmMVisual(const ListWznmMVisual& src);
	~ListWznmMVisual();

	void clear();
	unsigned int size() const;
	void append(WznmMVisual* rec);

	WznmMVisual* operator[](const Sbecore::uint ix);
	ListWznmMVisual& operator=(const ListWznmMVisual& src);
	bool operator==(const ListWznmMVisual& comp);
	bool operator!=(const ListWznmMVisual& comp);

public:
	std::vector<WznmMVisual*> nodes;
};

/**
	* TblWznmMVisual: C++ wrapper for table TblWznmMVisual
	*/
class TblWznmMVisual {

public:
	/**
		* VecVBasetype (full: VecWznmVMVisualBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint DBSTR = 1;
		static const Sbecore::uint IMPEXP = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

public:
	TblWznmMVisual();
	virtual ~TblWznmMVisual();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMVisual** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMVisual& rst);

	virtual Sbecore::ubigint insertRec(WznmMVisual* rec);
	Sbecore::ubigint insertNewRec(WznmMVisual** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint verRefWznmMVersion = 0, const Sbecore::uint verNum = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMVisual& rst, WznmMVisual** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint verRefWznmMVersion = 0, const Sbecore::uint verNum = 0, const std::string Comment = "");
	virtual void insertRst(ListWznmMVisual& rst, bool transact = false);
	virtual void updateRec(WznmMVisual* rec);
	virtual void updateRst(ListWznmMVisual& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMVisual** rec);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, ListWznmMVisual& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMVisual& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMVisual: C++ wrapper for table TblWznmMVisual (MySQL database)
	*/
class MyTblWznmMVisual : public TblWznmMVisual, public Sbecore::MyTable {

public:
	MyTblWznmMVisual();
	~MyTblWznmMVisual();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMVisual** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMVisual& rst);

	Sbecore::ubigint insertRec(WznmMVisual* rec);
	void insertRst(ListWznmMVisual& rst, bool transact = false);
	void updateRec(WznmMVisual* rec);
	void updateRst(ListWznmMVisual& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMVisual** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, ListWznmMVisual& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMVisual: C++ wrapper for table TblWznmMVisual (PgSQL database)
	*/
class PgTblWznmMVisual : public TblWznmMVisual, public Sbecore::PgTable {

public:
	PgTblWznmMVisual();
	~PgTblWznmMVisual();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMVisual** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMVisual& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMVisual** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMVisual& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMVisual** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMVisual& rst);

	Sbecore::ubigint insertRec(WznmMVisual* rec);
	void insertRst(ListWznmMVisual& rst, bool transact = false);
	void updateRec(WznmMVisual* rec);
	void updateRst(ListWznmMVisual& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMVisual** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, ListWznmMVisual& rst);
};
#endif

#endif
