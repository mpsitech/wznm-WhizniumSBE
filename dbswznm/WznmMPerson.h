/**
	* \file WznmMPerson.h
	* database access for table TblWznmMPerson (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMPERSON_H
#define WZNMMPERSON_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMPersonSex TblWznmMPerson::VecVSex
#define VecWznmWMPersonDerivate TblWznmMPerson::VecWDerivate

/**
	* WznmMPerson: record of TblWznmMPerson
	*/
class WznmMPerson {

public:
	WznmMPerson(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::uint ixWDerivate;
	Sbecore::uint ixVSex;
	std::string Title;
	std::string Firstname;
	Sbecore::ubigint refJLastname;
	std::string Lastname;
	Sbecore::ubigint telRefADetail;
	std::string telVal;
	Sbecore::ubigint emlRefADetail;
	std::string emlVal;
	std::string Salutation;

public:
	bool operator==(const WznmMPerson& comp);
	bool operator!=(const WznmMPerson& comp);
};

/**
	* ListWznmMPerson: recordset of TblWznmMPerson
	*/
class ListWznmMPerson {

public:
	ListWznmMPerson();
	ListWznmMPerson(const ListWznmMPerson& src);
	~ListWznmMPerson();

	void clear();
	unsigned int size() const;
	void append(WznmMPerson* rec);

	WznmMPerson* operator[](const Sbecore::uint ix);
	ListWznmMPerson& operator=(const ListWznmMPerson& src);
	bool operator==(const ListWznmMPerson& comp);
	bool operator!=(const ListWznmMPerson& comp);

public:
	std::vector<WznmMPerson*> nodes;
};

/**
	* TblWznmMPerson: C++ wrapper for table TblWznmMPerson
	*/
class TblWznmMPerson {

public:
	/**
		* VecVSex (full: VecWznmVMPersonSex)
		*/
	class VecVSex {

	public:
		static const Sbecore::uint F = 1;
		static const Sbecore::uint M = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWDerivate (full: VecWznmWMPersonDerivate)
		*/
	class VecWDerivate {

	public:
		static const Sbecore::uint USR = 1;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMPerson();
	virtual ~TblWznmMPerson();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMPerson** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMPerson& rst);

	virtual Sbecore::ubigint insertRec(WznmMPerson* rec);
	Sbecore::ubigint insertNewRec(WznmMPerson** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMPerson& rst, WznmMPerson** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixWDerivate = 0, const Sbecore::uint ixVSex = 0, const std::string Title = "", const std::string Firstname = "", const Sbecore::ubigint refJLastname = 0, const std::string Lastname = "", const Sbecore::ubigint telRefADetail = 0, const std::string telVal = "", const Sbecore::ubigint emlRefADetail = 0, const std::string emlVal = "", const std::string Salutation = "");
	virtual void insertRst(ListWznmMPerson& rst, bool transact = false);
	virtual void updateRec(WznmMPerson* rec);
	virtual void updateRst(ListWznmMPerson& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMPerson** rec);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMPerson& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMPerson: C++ wrapper for table TblWznmMPerson (MySQL database)
	*/
class MyTblWznmMPerson : public TblWznmMPerson, public Sbecore::MyTable {

public:
	MyTblWznmMPerson();
	~MyTblWznmMPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMPerson& rst);

	Sbecore::ubigint insertRec(WznmMPerson* rec);
	void insertRst(ListWznmMPerson& rst, bool transact = false);
	void updateRec(WznmMPerson* rec);
	void updateRst(ListWznmMPerson& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMPerson** rec);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMPerson: C++ wrapper for table TblWznmMPerson (PgSQL database)
	*/
class PgTblWznmMPerson : public TblWznmMPerson, public Sbecore::PgTable {

public:
	PgTblWznmMPerson();
	~PgTblWznmMPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMPerson** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMPerson& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMPerson** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMPerson** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMPerson& rst);

	Sbecore::ubigint insertRec(WznmMPerson* rec);
	void insertRst(ListWznmMPerson& rst, bool transact = false);
	void updateRec(WznmMPerson* rec);
	void updateRst(ListWznmMPerson& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMPerson** rec);
};
#endif

#endif

