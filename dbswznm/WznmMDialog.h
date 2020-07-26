/**
	* \file WznmMDialog.h
	* database access for table TblWznmMDialog (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMMDIALOG_H
#define WZNMMDIALOG_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMDialogBasetype TblWznmMDialog::VecVBasetype
#define VecWznmVMDialogRefTbl TblWznmMDialog::VecVRefTbl

/**
	* WznmMDialog: record of TblWznmMDialog
	*/
class WznmMDialog {

public:
	WznmMDialog(const Sbecore::ubigint ref = 0, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMCard = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::uint ixVBasetype;
	Sbecore::ubigint refWznmMCard;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	Sbecore::ubigint refWznmMJob;
	std::string sref;
	std::string Comment;

public:
	bool operator==(const WznmMDialog& comp);
	bool operator!=(const WznmMDialog& comp);
};

/**
	* ListWznmMDialog: recordset of TblWznmMDialog
	*/
class ListWznmMDialog {

public:
	ListWznmMDialog();
	ListWznmMDialog(const ListWznmMDialog& src);
	~ListWznmMDialog();

	void clear();
	unsigned int size() const;
	void append(WznmMDialog* rec);

	WznmMDialog* operator[](const Sbecore::uint ix);
	ListWznmMDialog& operator=(const ListWznmMDialog& src);
	bool operator==(const ListWznmMDialog& comp);
	bool operator!=(const ListWznmMDialog& comp);

public:
	std::vector<WznmMDialog*> nodes;
};

/**
	* TblWznmMDialog: C++ wrapper for table TblWznmMDialog
	*/
class TblWznmMDialog {

public:
	/**
		* VecVBasetype (full: VecWznmVMDialogBasetype)
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint NEW = 1;
		static const Sbecore::uint SELECT = 2;
		static const Sbecore::uint FILTER = 3;
		static const Sbecore::uint MNREL = 4;
		static const Sbecore::uint MNNEW = 5;
		static const Sbecore::uint IMPORT = 6;
		static const Sbecore::uint EXPORT = 7;
		static const Sbecore::uint JUMP = 8;
		static const Sbecore::uint RIGHTS = 9;
		static const Sbecore::uint REPORT = 10;
		static const Sbecore::uint CUST = 11;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecVRefTbl (full: VecWznmVMDialogRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint TBL = 2;
		static const Sbecore::uint REL = 3;
		static const Sbecore::uint IEX = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMDialog();
	virtual ~TblWznmMDialog();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMDialog** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMDialog& rst);

	virtual Sbecore::ubigint insertRec(WznmMDialog* rec);
	Sbecore::ubigint insertNewRec(WznmMDialog** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMCard = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMDialog& rst, WznmMDialog** rec = NULL, const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint refWznmMCard = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const Sbecore::ubigint refWznmMJob = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWznmMDialog& rst, bool transact = false);
	virtual void updateRec(WznmMDialog* rec);
	virtual void updateRst(ListWznmMDialog& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMDialog** rec);
	virtual bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMDialog** rec);
	virtual Sbecore::ubigint loadRefsByCar(Sbecore::ubigint refWznmMCard, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByCar(Sbecore::ubigint refWznmMCard, const bool append, ListWznmMDialog& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMDialog& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMDialog: C++ wrapper for table TblWznmMDialog (MySQL database)
	*/
class MyTblWznmMDialog : public TblWznmMDialog, public Sbecore::MyTable {

public:
	MyTblWznmMDialog();
	~MyTblWznmMDialog();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMDialog** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMDialog& rst);

	Sbecore::ubigint insertRec(WznmMDialog* rec);
	void insertRst(ListWznmMDialog& rst, bool transact = false);
	void updateRec(WznmMDialog* rec);
	void updateRst(ListWznmMDialog& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMDialog** rec);
	bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMDialog** rec);
	Sbecore::ubigint loadRefsByCar(Sbecore::ubigint refWznmMCard, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCar(Sbecore::ubigint refWznmMCard, const bool append, ListWznmMDialog& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMDialog: C++ wrapper for table TblWznmMDialog (PgSQL database)
	*/
class PgTblWznmMDialog : public TblWznmMDialog, public Sbecore::PgTable {

public:
	PgTblWznmMDialog();
	~PgTblWznmMDialog();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMDialog** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMDialog& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMDialog** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMDialog& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMDialog** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMDialog& rst);

	Sbecore::ubigint insertRec(WznmMDialog* rec);
	void insertRst(ListWznmMDialog& rst, bool transact = false);
	void updateRec(WznmMDialog* rec);
	void updateRst(ListWznmMDialog& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMDialog** rec);
	bool loadRecByJob(Sbecore::ubigint refWznmMJob, WznmMDialog** rec);
	Sbecore::ubigint loadRefsByCar(Sbecore::ubigint refWznmMCard, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByCar(Sbecore::ubigint refWznmMCard, const bool append, ListWznmMDialog& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

