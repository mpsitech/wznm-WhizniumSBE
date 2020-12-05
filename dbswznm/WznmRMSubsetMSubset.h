/**
	* \file WznmRMSubsetMSubset.h
	* database access for table TblWznmRMSubsetMSubset (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMRMSUBSETMSUBSET_H
#define WZNMRMSUBSETMSUBSET_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVRMSubsetMSubsetReltype TblWznmRMSubsetMSubset::VecVReltype

/**
	* WznmRMSubsetMSubset: record of TblWznmRMSubsetMSubset
	*/
class WznmRMSubsetMSubset {

public:
	WznmRMSubsetMSubset(const Sbecore::ubigint ref = 0, const Sbecore::ubigint asbRefWznmMSubset = 0, const Sbecore::ubigint bsbRefWznmMSubset = 0, const Sbecore::uint ixVReltype = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint asbRefWznmMSubset;
	Sbecore::ubigint bsbRefWznmMSubset;
	Sbecore::uint ixVReltype;

public:
	bool operator==(const WznmRMSubsetMSubset& comp);
	bool operator!=(const WznmRMSubsetMSubset& comp);
};

/**
	* ListWznmRMSubsetMSubset: recordset of TblWznmRMSubsetMSubset
	*/
class ListWznmRMSubsetMSubset {

public:
	ListWznmRMSubsetMSubset();
	ListWznmRMSubsetMSubset(const ListWznmRMSubsetMSubset& src);
	~ListWznmRMSubsetMSubset();

	void clear();
	unsigned int size() const;
	void append(WznmRMSubsetMSubset* rec);

	WznmRMSubsetMSubset* operator[](const Sbecore::uint ix);
	ListWznmRMSubsetMSubset& operator=(const ListWznmRMSubsetMSubset& src);
	bool operator==(const ListWznmRMSubsetMSubset& comp);
	bool operator!=(const ListWznmRMSubsetMSubset& comp);

public:
	std::vector<WznmRMSubsetMSubset*> nodes;
};

/**
	* TblWznmRMSubsetMSubset: C++ wrapper for table TblWznmRMSubsetMSubset
	*/
class TblWznmRMSubsetMSubset {

public:
	/**
		* VecVReltype (full: VecWznmVRMSubsetMSubsetReltype)
		*/
	class VecVReltype {

	public:
		static const Sbecore::uint AINB = 1;
		static const Sbecore::uint BINA = 2;
		static const Sbecore::uint COMPL = 3;
		static const Sbecore::uint DISJ = 4;
		static const Sbecore::uint XSEC = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmRMSubsetMSubset();
	virtual ~TblWznmRMSubsetMSubset();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMSubsetMSubset** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMSubsetMSubset& rst);

	virtual Sbecore::ubigint insertRec(WznmRMSubsetMSubset* rec);
	Sbecore::ubigint insertNewRec(WznmRMSubsetMSubset** rec = NULL, const Sbecore::ubigint asbRefWznmMSubset = 0, const Sbecore::ubigint bsbRefWznmMSubset = 0, const Sbecore::uint ixVReltype = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMSubsetMSubset& rst, WznmRMSubsetMSubset** rec = NULL, const Sbecore::ubigint asbRefWznmMSubset = 0, const Sbecore::ubigint bsbRefWznmMSubset = 0, const Sbecore::uint ixVReltype = 0);
	virtual void insertRst(ListWznmRMSubsetMSubset& rst, bool transact = false);
	virtual void updateRec(WznmRMSubsetMSubset* rec);
	virtual void updateRst(ListWznmRMSubsetMSubset& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMSubsetMSubset** rec);
	virtual Sbecore::ubigint loadRefsByAsb(Sbecore::ubigint asbRefWznmMSubset, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByAsb(Sbecore::ubigint asbRefWznmMSubset, const bool append, ListWznmRMSubsetMSubset& rst);
	virtual Sbecore::ubigint loadRstByBsb(Sbecore::ubigint bsbRefWznmMSubset, const bool append, ListWznmRMSubsetMSubset& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMSubsetMSubset& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMSubsetMSubset: C++ wrapper for table TblWznmRMSubsetMSubset (MySQL database)
	*/
class MyTblWznmRMSubsetMSubset : public TblWznmRMSubsetMSubset, public Sbecore::MyTable {

public:
	MyTblWznmRMSubsetMSubset();
	~MyTblWznmRMSubsetMSubset();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMSubsetMSubset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMSubsetMSubset& rst);

	Sbecore::ubigint insertRec(WznmRMSubsetMSubset* rec);
	void insertRst(ListWznmRMSubsetMSubset& rst, bool transact = false);
	void updateRec(WznmRMSubsetMSubset* rec);
	void updateRst(ListWznmRMSubsetMSubset& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMSubsetMSubset** rec);
	Sbecore::ubigint loadRefsByAsb(Sbecore::ubigint asbRefWznmMSubset, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByAsb(Sbecore::ubigint asbRefWznmMSubset, const bool append, ListWznmRMSubsetMSubset& rst);
	Sbecore::ubigint loadRstByBsb(Sbecore::ubigint bsbRefWznmMSubset, const bool append, ListWznmRMSubsetMSubset& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMSubsetMSubset: C++ wrapper for table TblWznmRMSubsetMSubset (PgSQL database)
	*/
class PgTblWznmRMSubsetMSubset : public TblWznmRMSubsetMSubset, public Sbecore::PgTable {

public:
	PgTblWznmRMSubsetMSubset();
	~PgTblWznmRMSubsetMSubset();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMSubsetMSubset** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMSubsetMSubset& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMSubsetMSubset** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmRMSubsetMSubset& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMSubsetMSubset** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMSubsetMSubset& rst);

	Sbecore::ubigint insertRec(WznmRMSubsetMSubset* rec);
	void insertRst(ListWznmRMSubsetMSubset& rst, bool transact = false);
	void updateRec(WznmRMSubsetMSubset* rec);
	void updateRst(ListWznmRMSubsetMSubset& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMSubsetMSubset** rec);
	Sbecore::ubigint loadRefsByAsb(Sbecore::ubigint asbRefWznmMSubset, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByAsb(Sbecore::ubigint asbRefWznmMSubset, const bool append, ListWznmRMSubsetMSubset& rst);
	Sbecore::ubigint loadRstByBsb(Sbecore::ubigint bsbRefWznmMSubset, const bool append, ListWznmRMSubsetMSubset& rst);
};
#endif

#endif

