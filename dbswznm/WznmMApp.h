/**
	* \file WznmMApp.h
	* database access for table TblWznmMApp (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMMAPP_H
#define WZNMMAPP_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMAppTarget TblWznmMApp::VecVTarget

/**
	* WznmMApp: record of TblWznmMApp
	*/
class WznmMApp {

public:
	WznmMApp(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixVTarget = 0, const Sbecore::ubigint verRefWznmMVersion = 0, const Sbecore::uint verNum = 0, const std::string Short = "", const std::string Title = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::uint ixVTarget;
	Sbecore::ubigint verRefWznmMVersion;
	Sbecore::uint verNum;
	std::string Short;
	std::string Title;
	std::string Comment;

public:
	bool operator==(const WznmMApp& comp);
	bool operator!=(const WznmMApp& comp);
};

/**
	* ListWznmMApp: recordset of TblWznmMApp
	*/
class ListWznmMApp {

public:
	ListWznmMApp();
	ListWznmMApp(const ListWznmMApp& src);
	~ListWznmMApp();

	void clear();
	unsigned int size() const;
	void append(WznmMApp* rec);

	WznmMApp* operator[](const Sbecore::uint ix);
	ListWznmMApp& operator=(const ListWznmMApp& src);
	bool operator==(const ListWznmMApp& comp);
	bool operator!=(const ListWznmMApp& comp);

public:
	std::vector<WznmMApp*> nodes;
};

/**
	* TblWznmMApp: C++ wrapper for table TblWznmMApp
	*/
class TblWznmMApp {

public:
	/**
		* VecVTarget (full: VecWznmVMAppTarget)
		*/
	class VecVTarget {

	public:
		static const Sbecore::uint COCOA_OBJC = 1;
		static const Sbecore::uint DOTNET_CPPCLI = 2;
		static const Sbecore::uint JAVA = 3;
		static const Sbecore::uint JS = 4;
		static const Sbecore::uint POSIX_CPP = 5;
		static const Sbecore::uint WINRT_CPP = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMApp();
	virtual ~TblWznmMApp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMApp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMApp& rst);

	virtual Sbecore::ubigint insertRec(WznmMApp* rec);
	Sbecore::ubigint insertNewRec(WznmMApp** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixVTarget = 0, const Sbecore::ubigint verRefWznmMVersion = 0, const Sbecore::uint verNum = 0, const std::string Short = "", const std::string Title = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMApp& rst, WznmMApp** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::uint ixVTarget = 0, const Sbecore::ubigint verRefWznmMVersion = 0, const Sbecore::uint verNum = 0, const std::string Short = "", const std::string Title = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMApp& rst, bool transact = false);
	virtual void updateRec(WznmMApp* rec);
	virtual void updateRst(ListWznmMApp& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMApp** rec);
	virtual Sbecore::ubigint loadRstByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, ListWznmMApp& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMApp& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMApp: C++ wrapper for table TblWznmMApp (MySQL database)
	*/
class MyTblWznmMApp : public TblWznmMApp, public Sbecore::MyTable {

public:
	MyTblWznmMApp();
	~MyTblWznmMApp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMApp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMApp& rst);

	Sbecore::ubigint insertRec(WznmMApp* rec);
	void insertRst(ListWznmMApp& rst, bool transact = false);
	void updateRec(WznmMApp* rec);
	void updateRst(ListWznmMApp& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMApp** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, ListWznmMApp& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMApp: C++ wrapper for table TblWznmMApp (PgSQL database)
	*/
class PgTblWznmMApp : public TblWznmMApp, public Sbecore::PgTable {

public:
	PgTblWznmMApp();
	~PgTblWznmMApp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMApp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMApp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMApp** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMApp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMApp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMApp& rst);

	Sbecore::ubigint insertRec(WznmMApp* rec);
	void insertRst(ListWznmMApp& rst, bool transact = false);
	void updateRec(WznmMApp* rec);
	void updateRst(ListWznmMApp& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMApp** rec);
	Sbecore::ubigint loadRstByVer(Sbecore::ubigint verRefWznmMVersion, const bool append, ListWznmMApp& rst);
};
#endif

#endif

