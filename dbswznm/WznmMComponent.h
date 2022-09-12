/**
	* \file WznmMComponent.h
	* database access for table TblWznmMComponent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMCOMPONENT_H
#define WZNMMCOMPONENT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMComponentBasetype TblWznmMComponent::VecVBasetype
#define VecWznmWMComponentSubset TblWznmMComponent::VecWSubset

/**
	* WznmMComponent: record of TblWznmMComponent
	*/
class WznmMComponent {

public:
	WznmMComponent(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string sref = "", const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmMVersion;
	std::string sref;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WznmMComponent& comp);
	bool operator!=(const WznmMComponent& comp);
};

/**
	* ListWznmMComponent: recordset of TblWznmMComponent
	*/
class ListWznmMComponent {

public:
	ListWznmMComponent();
	ListWznmMComponent(const ListWznmMComponent& src);
	~ListWznmMComponent();

	void clear();
	unsigned int size() const;
	void append(WznmMComponent* rec);

	WznmMComponent* operator[](const Sbecore::uint ix);
	ListWznmMComponent& operator=(const ListWznmMComponent& src);
	bool operator==(const ListWznmMComponent& comp);
	bool operator!=(const ListWznmMComponent& comp);

public:
	std::vector<WznmMComponent*> nodes;
};

/**
	* TblWznmMComponent: C++ wrapper for table TblWznmMComponent
	*/
class TblWznmMComponent {

public:
	/**
		* VecVBasetype (full: VecWznmVMComponentBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint ENG = 1;
		static const Sbecore::uint OPENG = 2;
		static const Sbecore::uint CMBENG = 3;
		static const Sbecore::uint DBS = 4;
		static const Sbecore::uint VUEAPP = 5;
		static const Sbecore::uint WEBAPP = 6;
		static const Sbecore::uint API = 7;
		static const Sbecore::uint CSAPI = 8;
		static const Sbecore::uint JAPI = 9;
		static const Sbecore::uint PYAPI = 10;
		static const Sbecore::uint SWAPI = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecWSubset (full: VecWznmWMComponentSubset)
		*/
	class VecWSubset {

	public:
		static const Sbecore::uint SBSWZNMBMCOMPONENTCCP = 1;
		static const Sbecore::uint SBSWZNMBMCOMPONENTOEN = 2;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);
	};

public:
	TblWznmMComponent();
	virtual ~TblWznmMComponent();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMComponent** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMComponent& rst);

	virtual Sbecore::ubigint insertRec(WznmMComponent* rec);
	Sbecore::ubigint insertNewRec(WznmMComponent** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string sref = "", const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMComponent& rst, WznmMComponent** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMVersion = 0, const std::string sref = "", const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMComponent& rst, bool transact = false);
	virtual void updateRec(WznmMComponent* rec);
	virtual void updateRst(ListWznmMComponent& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMComponent** rec);
	virtual bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMComponent& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMComponent& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMComponent: C++ wrapper for table TblWznmMComponent (MySQL database)
	*/
class MyTblWznmMComponent : public TblWznmMComponent, public Sbecore::MyTable {

public:
	MyTblWznmMComponent();
	~MyTblWznmMComponent();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMComponent& rst);

	Sbecore::ubigint insertRec(WznmMComponent* rec);
	void insertRst(ListWznmMComponent& rst, bool transact = false);
	void updateRec(WznmMComponent* rec);
	void updateRst(ListWznmMComponent& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMComponent** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMComponent& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMComponent: C++ wrapper for table TblWznmMComponent (PgSQL database)
	*/
class PgTblWznmMComponent : public TblWznmMComponent, public Sbecore::PgTable {

public:
	PgTblWznmMComponent();
	~PgTblWznmMComponent();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMComponent** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMComponent& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMComponent** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMComponent& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMComponent** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMComponent& rst);

	Sbecore::ubigint insertRec(WznmMComponent* rec);
	void insertRst(ListWznmMComponent& rst, bool transact = false);
	void updateRec(WznmMComponent* rec);
	void updateRst(ListWznmMComponent& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMComponent** rec);
	bool loadRefByVerSrf(Sbecore::ubigint refWznmMVersion, std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint refWznmMVersion, const bool append, ListWznmMComponent& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
