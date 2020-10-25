/**
	* \file WznmMTag.h
	* database access for table TblWznmMTag (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMMTAG_H
#define WZNMMTAG_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmMTag: record of TblWznmMTag
	*/
class WznmMTag {

public:
	WznmMTag(const Sbecore::ubigint ref = 0, const Sbecore::ubigint refWznmMCapability = 0, const std::string sref = "", const std::string osrefWznmKTaggrp = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "");

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint refWznmMCapability;
	std::string sref;
	std::string osrefWznmKTaggrp;
	Sbecore::ubigint refJTitle;
	std::string Title;

public:
	bool operator==(const WznmMTag& comp);
	bool operator!=(const WznmMTag& comp);
};

/**
	* ListWznmMTag: recordset of TblWznmMTag
	*/
class ListWznmMTag {

public:
	ListWznmMTag();
	ListWznmMTag(const ListWznmMTag& src);
	~ListWznmMTag();

	void clear();
	unsigned int size() const;
	void append(WznmMTag* rec);

	WznmMTag* operator[](const Sbecore::uint ix);
	ListWznmMTag& operator=(const ListWznmMTag& src);
	bool operator==(const ListWznmMTag& comp);
	bool operator!=(const ListWznmMTag& comp);

public:
	std::vector<WznmMTag*> nodes;
};

/**
	* TblWznmMTag: C++ wrapper for table TblWznmMTag
	*/
class TblWznmMTag {

public:

public:
	TblWznmMTag();
	virtual ~TblWznmMTag();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmMTag** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMTag& rst);

	virtual Sbecore::ubigint insertRec(WznmMTag* rec);
	Sbecore::ubigint insertNewRec(WznmMTag** rec = NULL, const Sbecore::ubigint refWznmMCapability = 0, const std::string sref = "", const std::string osrefWznmKTaggrp = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmMTag& rst, WznmMTag** rec = NULL, const Sbecore::ubigint refWznmMCapability = 0, const std::string sref = "", const std::string osrefWznmKTaggrp = "", const Sbecore::ubigint refJTitle = 0, const std::string Title = "");
	virtual void insertRst(ListWznmMTag& rst, bool transact = false);
	virtual void updateRec(WznmMTag* rec);
	virtual void updateRst(ListWznmMTag& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmMTag** rec);
	virtual bool loadRecBySrfGrp(std::string sref, std::string osrefWznmKTaggrp, WznmMTag** rec);
	virtual Sbecore::ubigint loadRefsByCpb(Sbecore::ubigint refWznmMCapability, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByGrp(std::string osrefWznmKTaggrp, const bool append, ListWznmMTag& rst);
	virtual bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmMTag& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmMTag: C++ wrapper for table TblWznmMTag (MySQL database)
	*/
class MyTblWznmMTag : public TblWznmMTag, public Sbecore::MyTable {

public:
	MyTblWznmMTag();
	~MyTblWznmMTag();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMTag** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMTag& rst);

	Sbecore::ubigint insertRec(WznmMTag* rec);
	void insertRst(ListWznmMTag& rst, bool transact = false);
	void updateRec(WznmMTag* rec);
	void updateRst(ListWznmMTag& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMTag** rec);
	bool loadRecBySrfGrp(std::string sref, std::string osrefWznmKTaggrp, WznmMTag** rec);
	Sbecore::ubigint loadRefsByCpb(Sbecore::ubigint refWznmMCapability, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByGrp(std::string osrefWznmKTaggrp, const bool append, ListWznmMTag& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmMTag: C++ wrapper for table TblWznmMTag (PgSQL database)
	*/
class PgTblWznmMTag : public TblWznmMTag, public Sbecore::PgTable {

public:
	PgTblWznmMTag();
	~PgTblWznmMTag();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmMTag** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmMTag& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmMTag** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmMTag& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmMTag** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmMTag& rst);

	Sbecore::ubigint insertRec(WznmMTag* rec);
	void insertRst(ListWznmMTag& rst, bool transact = false);
	void updateRec(WznmMTag* rec);
	void updateRst(ListWznmMTag& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmMTag** rec);
	bool loadRecBySrfGrp(std::string sref, std::string osrefWznmKTaggrp, WznmMTag** rec);
	Sbecore::ubigint loadRefsByCpb(Sbecore::ubigint refWznmMCapability, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByGrp(std::string osrefWznmKTaggrp, const bool append, ListWznmMTag& rst);
	bool loadSrfByRef(Sbecore::ubigint ref, std::string& sref);
};
#endif

#endif

