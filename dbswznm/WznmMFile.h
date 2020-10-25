/**
	* \file WznmMFile.h
	* database access for table TblWznmMFile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMFILE_H
#define WZNMMFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include <sbecore/Xmlio.h>

#define VecWznmVMFileRefTbl TblWznmMFile::VecVRefTbl

/**
	* WznmMFile: record of TblWznmMFile
	*/
class WznmMFile {

public:
	WznmMFile(const Sbecore::ubigint ref = 0, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWznmCFile = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string osrefKContent = "", const Sbecore::uint Archived = 0, const std::string Filename = "", const std::string Archivename = "", const std::string srefKMimetype = "", const Sbecore::uint Size = 0, const std::string Comment = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint grp;
	Sbecore::ubigint own;
	Sbecore::ubigint refWznmCFile;
	Sbecore::uint refIxVTbl;
	Sbecore::ubigint refUref;
	std::string osrefKContent;
	Sbecore::uint Archived;
	std::string Filename;
	std::string Archivename;
	std::string srefKMimetype;
	Sbecore::uint Size;
	std::string Comment;

public:
	bool operator==(const WznmMFile& comp);
	bool operator!=(const WznmMFile& comp);
};

/**
	* ListWznmMFile: recordset of TblWznmMFile
	*/
class ListWznmMFile {

public:
	ListWznmMFile();
	ListWznmMFile(const ListWznmMFile& src);
	~ListWznmMFile();

	void clear();
	unsigned int size() const;
	void append(WznmMFile* rec);

	WznmMFile* operator[](const Sbecore::uint ix);
	ListWznmMFile& operator=(const ListWznmMFile& src);
	bool operator==(const ListWznmMFile& comp);
	bool operator!=(const ListWznmMFile& comp);

public:
	std::vector<WznmMFile*> nodes;
};

/**
	* TblWznmMFile: C++ wrapper for table TblWznmMFile
	*/
class TblWznmMFile {

public:
	/**
		* VecVRefTbl (full: VecWznmVMFileRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint APP = 2;
		static const Sbecore::uint LIB = 3;
		static const Sbecore::uint VER = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	};

public:
	TblWznmMFile();
	virtual ~TblWznmMFile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMFile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMFile& rst);

	virtual Sbecore::ubigint insertRec(WznmMFile* rec);
	Sbecore::ubigint insertNewRec(WznmMFile** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWznmCFile = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string osrefKContent = "", const Sbecore::uint Archived = 0, const std::string Filename = "", const std::string Archivename = "", const std::string srefKMimetype = "", const Sbecore::uint Size = 0, const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMFile& rst, WznmMFile** rec = NULL, const Sbecore::ubigint grp = 0, const Sbecore::ubigint own = 0, const Sbecore::ubigint refWznmCFile = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint refUref = 0, const std::string osrefKContent = "", const Sbecore::uint Archived = 0, const std::string Filename = "", const std::string Archivename = "", const std::string srefKMimetype = "", const Sbecore::uint Size = 0, const std::string Comment = "");
	virtual void insertRst(ListWznmMFile& rst, bool transact = false);
	virtual void updateRec(WznmMFile* rec);
	virtual void updateRst(ListWznmMFile& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMFile** rec);
	virtual bool loadFnmByRef(Sbecore::ubigint ref, std::string& Filename);
	virtual Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCFile, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCFile, const bool append, ListWznmMFile& rst);
	virtual Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWznmMFile& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMFile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMFile: C++ wrapper for table TblWznmMFile (MySQL database)
	*/
class MyTblWznmMFile : public TblWznmMFile, public Sbecore::MyTable {

public:
	MyTblWznmMFile();
	~MyTblWznmMFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMFile& rst);

	Sbecore::ubigint insertRec(WznmMFile* rec);
	void insertRst(ListWznmMFile& rst, bool transact = false);
	void updateRec(WznmMFile* rec);
	void updateRst(ListWznmMFile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMFile** rec);
	bool loadFnmByRef(Sbecore::ubigint ref, std::string& Filename);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCFile, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCFile, const bool append, ListWznmMFile& rst);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWznmMFile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMFile: C++ wrapper for table TblWznmMFile (PgSQL database)
	*/
class PgTblWznmMFile : public TblWznmMFile, public Sbecore::PgTable {

public:
	PgTblWznmMFile();
	~PgTblWznmMFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMFile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMFile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMFile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMFile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMFile& rst);

	Sbecore::ubigint insertRec(WznmMFile* rec);
	void insertRst(ListWznmMFile& rst, bool transact = false);
	void updateRec(WznmMFile* rec);
	void updateRst(ListWznmMFile& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMFile** rec);
	bool loadFnmByRef(Sbecore::ubigint ref, std::string& Filename);
	Sbecore::ubigint loadRefsByClu(Sbecore::ubigint refWznmCFile, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByClu(Sbecore::ubigint refWznmCFile, const bool append, ListWznmMFile& rst);
	Sbecore::ubigint loadRstByRetReu(Sbecore::uint refIxVTbl, Sbecore::ubigint refUref, const bool append, ListWznmMFile& rst);
};
#endif

#endif

