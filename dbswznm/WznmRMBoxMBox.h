/**
	* \file WznmRMBoxMBox.h
	* database access for table TblWznmRMBoxMBox (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

#ifndef WZNMRMBOXMBOX_H
#define WZNMRMBOXMBOX_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmRMBoxMBox: record of TblWznmRMBoxMBox
	*/
class WznmRMBoxMBox {

public:
	WznmRMBoxMBox(const Sbecore::ubigint ref = 0, const Sbecore::ubigint orgRefWznmMBox = 0, const Sbecore::ubigint dstRefWznmMBox = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0);

public:
	Sbecore::ubigint ref;
	Sbecore::ubigint orgRefWznmMBox;
	Sbecore::ubigint dstRefWznmMBox;
	Sbecore::utinyint orgClk;
	Sbecore::utinyint dstClk;
	Sbecore::utinyint Weight;

public:
	bool operator==(const WznmRMBoxMBox& comp);
	bool operator!=(const WznmRMBoxMBox& comp);
};

/**
	* ListWznmRMBoxMBox: recordset of TblWznmRMBoxMBox
	*/
class ListWznmRMBoxMBox {

public:
	ListWznmRMBoxMBox();
	ListWznmRMBoxMBox(const ListWznmRMBoxMBox& src);
	~ListWznmRMBoxMBox();

	void clear();
	unsigned int size() const;
	void append(WznmRMBoxMBox* rec);

	WznmRMBoxMBox* operator[](const Sbecore::uint ix);
	ListWznmRMBoxMBox& operator=(const ListWznmRMBoxMBox& src);
	bool operator==(const ListWznmRMBoxMBox& comp);
	bool operator!=(const ListWznmRMBoxMBox& comp);

public:
	std::vector<WznmRMBoxMBox*> nodes;
};

/**
	* TblWznmRMBoxMBox: C++ wrapper for table TblWznmRMBoxMBox
	*/
class TblWznmRMBoxMBox {

public:

public:
	TblWznmRMBoxMBox();
	virtual ~TblWznmRMBoxMBox();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmRMBoxMBox** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMBoxMBox& rst);

	virtual Sbecore::ubigint insertRec(WznmRMBoxMBox* rec);
	Sbecore::ubigint insertNewRec(WznmRMBoxMBox** rec = NULL, const Sbecore::ubigint orgRefWznmMBox = 0, const Sbecore::ubigint dstRefWznmMBox = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmRMBoxMBox& rst, WznmRMBoxMBox** rec = NULL, const Sbecore::ubigint orgRefWznmMBox = 0, const Sbecore::ubigint dstRefWznmMBox = 0, const Sbecore::utinyint orgClk = 0, const Sbecore::utinyint dstClk = 0, const Sbecore::utinyint Weight = 0);
	virtual void insertRst(ListWznmRMBoxMBox& rst, bool transact = false);
	virtual void updateRec(WznmRMBoxMBox* rec);
	virtual void updateRst(ListWznmRMBoxMBox& rst, bool transact = false);
	virtual void removeRecByRef(Sbecore::ubigint ref);

	virtual bool loadRecByRef(Sbecore::ubigint ref, WznmRMBoxMBox** rec);
	virtual Sbecore::ubigint loadRefsByOrg(Sbecore::ubigint orgRefWznmMBox, const bool append, std::vector<Sbecore::ubigint>& refs);
	virtual Sbecore::ubigint loadRstByDst(Sbecore::ubigint dstRefWznmMBox, const bool append, ListWznmRMBoxMBox& rst);
	virtual Sbecore::ubigint loadRstByOrg(Sbecore::ubigint orgRefWznmMBox, const bool append, ListWznmRMBoxMBox& rst);
	Sbecore::ubigint loadRstByRefs(std::vector<Sbecore::ubigint>& refs, const bool append, ListWznmRMBoxMBox& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmRMBoxMBox: C++ wrapper for table TblWznmRMBoxMBox (MySQL database)
	*/
class MyTblWznmRMBoxMBox : public TblWznmRMBoxMBox, public Sbecore::MyTable {

public:
	MyTblWznmRMBoxMBox();
	~MyTblWznmRMBoxMBox();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMBoxMBox** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMBoxMBox& rst);

	Sbecore::ubigint insertRec(WznmRMBoxMBox* rec);
	void insertRst(ListWznmRMBoxMBox& rst, bool transact = false);
	void updateRec(WznmRMBoxMBox* rec);
	void updateRst(ListWznmRMBoxMBox& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMBoxMBox** rec);
	Sbecore::ubigint loadRefsByOrg(Sbecore::ubigint orgRefWznmMBox, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByDst(Sbecore::ubigint dstRefWznmMBox, const bool append, ListWznmRMBoxMBox& rst);
	Sbecore::ubigint loadRstByOrg(Sbecore::ubigint orgRefWznmMBox, const bool append, ListWznmRMBoxMBox& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmRMBoxMBox: C++ wrapper for table TblWznmRMBoxMBox (PgSQL database)
	*/
class PgTblWznmRMBoxMBox : public TblWznmRMBoxMBox, public Sbecore::PgTable {

public:
	PgTblWznmRMBoxMBox();
	~PgTblWznmRMBoxMBox();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmRMBoxMBox** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmRMBoxMBox& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmRMBoxMBox** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmRMBoxMBox& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmRMBoxMBox** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmRMBoxMBox& rst);

	Sbecore::ubigint insertRec(WznmRMBoxMBox* rec);
	void insertRst(ListWznmRMBoxMBox& rst, bool transact = false);
	void updateRec(WznmRMBoxMBox* rec);
	void updateRst(ListWznmRMBoxMBox& rst, bool transact = false);
	void removeRecByRef(Sbecore::ubigint ref);

	bool loadRecByRef(Sbecore::ubigint ref, WznmRMBoxMBox** rec);
	Sbecore::ubigint loadRefsByOrg(Sbecore::ubigint orgRefWznmMBox, const bool append, std::vector<Sbecore::ubigint>& refs);
	Sbecore::ubigint loadRstByDst(Sbecore::ubigint dstRefWznmMBox, const bool append, ListWznmRMBoxMBox& rst);
	Sbecore::ubigint loadRstByOrg(Sbecore::ubigint orgRefWznmMBox, const bool append, ListWznmRMBoxMBox& rst);
};
#endif

#endif
