/**
	* \file WznmMUser.h
	* database access for table TblWznmMUser (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMMUSER_H
#define WZNMMUSER_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMUserState TblWznmMUser::VecVState

/**
	* WznmMUser: record of TblWznmMUser
	*/
class WznmMUser {

public:
	WznmMUser(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refWznmMUsergroup = 0, const Sbecore::ubigint refWznmMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWznmVLocale = 0, const Sbecore::uint ixWznmVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refRUsergroup;
	Sbecore::ubigint refWznmMUsergroup;
	Sbecore::ubigint refWznmMPerson;
	std::string sref;
	Sbecore::ubigint refJState;
	Sbecore::uint ixVState;
	Sbecore::uint ixWznmVLocale;
	Sbecore::uint ixWznmVUserlevel;
	std::string Password;
	std::string Fullkey;
	std::string Comment;

public:
	bool operator==(const WznmMUser& comp);
	bool operator!=(const WznmMUser& comp);
};

/**
	* ListWznmMUser: recordset of TblWznmMUser
	*/
class ListWznmMUser {

public:
	ListWznmMUser();
	ListWznmMUser(const ListWznmMUser& src);
	~ListWznmMUser();

	void clear();
	unsigned int size() const;
	void append(WznmMUser* rec);

	WznmMUser* operator[](const Sbecore::uint ix);
	ListWznmMUser& operator=(const ListWznmMUser& src);
	bool operator==(const ListWznmMUser& comp);
	bool operator!=(const ListWznmMUser& comp);

public:
	std::vector<WznmMUser*> nodes;
};

/**
	* TblWznmMUser: C++ wrapper for table TblWznmMUser
	*/
class TblWznmMUser {

public:
	/**
		* VecVState (full: VecWznmVMUserState)
		*/
	class VecVState {

	public:
		static const Sbecore::uint ACT = 1;
		static const Sbecore::uint DSG = 2;
		static const Sbecore::uint DUE = 3;
		static const Sbecore::uint EXP = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

public:
	TblWznmMUser();
	virtual ~TblWznmMUser();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMUser** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMUser& rst);

	virtual Sbecore::ubigint insertRec(WznmMUser* rec);
	Sbecore::ubigint insertNewRec(WznmMUser** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refWznmMUsergroup = 0, const Sbecore::ubigint refWznmMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWznmVLocale = 0, const Sbecore::uint ixWznmVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMUser& rst, WznmMUser** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refRUsergroup = 0, const Sbecore::ubigint refWznmMUsergroup = 0, const Sbecore::ubigint refWznmMPerson = 0, const std::string sref = "", const Sbecore::ubigint refJState = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWznmVLocale = 0, const Sbecore::uint ixWznmVUserlevel = 0, const std::string Password = "", const std::string Fullkey = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMUser& rst, bool transact = false);
	virtual void updateRec(WznmMUser* rec);
	virtual void updateRst(ListWznmMUser& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMUser** rec);
	virtual bool loadRecBySrfPwd(std::string sref, std::string Password, WznmMUser** rec);
	virtual bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	virtual Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWznmMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMUser& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMUser: C++ wrapper for table TblWznmMUser (MySQL database)
	*/
class MyTblWznmMUser : public TblWznmMUser, public Sbecore::MyTable {

public:
	MyTblWznmMUser();
	~MyTblWznmMUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMUser& rst);

	Sbecore::ubigint insertRec(WznmMUser* rec);
	void insertRst(ListWznmMUser& rst, bool transact = false);
	void updateRec(WznmMUser* rec);
	void updateRst(ListWznmMUser& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMUser** rec);
	bool loadRecBySrfPwd(std::string sref, std::string Password, WznmMUser** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWznmMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMUser: C++ wrapper for table TblWznmMUser (PgSQL database)
	*/
class PgTblWznmMUser : public TblWznmMUser, public Sbecore::PgTable {

public:
	PgTblWznmMUser();
	~PgTblWznmMUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMUser** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMUser& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMUser** rec);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMUser** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMUser& rst);

	Sbecore::ubigint insertRec(WznmMUser* rec);
	void insertRst(ListWznmMUser& rst, bool transact = false);
	void updateRec(WznmMUser* rec);
	void updateRst(ListWznmMUser& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMUser** rec);
	bool loadRecBySrfPwd(std::string sref, std::string Password, WznmMUser** rec);
	bool loadRefBySrf(std::string sref, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsByUsg(Sbecore::ubigint refWznmMUsergroup, const bool append, std::vector<Sbecore::ubigint>& refs);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif
