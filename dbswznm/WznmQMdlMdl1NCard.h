/**
	* \file WznmQMdlMdl1NCard.h
	* Dbs and XML wrapper for table TblWznmQMdlMdl1NCard (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQMDLMDL1NCARD_H
#define WZNMQMDLMDL1NCARD_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQMdlMdl1NCard: record of TblWznmQMdlMdl1NCard
	*/
class WznmQMdlMdl1NCard {

public:
	WznmQMdlMdl1NCard(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint mdlNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQMdlMdl1NCard: recordset of TblWznmQMdlMdl1NCard
	*/
class ListWznmQMdlMdl1NCard {

public:
	ListWznmQMdlMdl1NCard();
	ListWznmQMdlMdl1NCard(const ListWznmQMdlMdl1NCard& src);
	~ListWznmQMdlMdl1NCard();

	void clear();
	unsigned int size() const;
	void append(WznmQMdlMdl1NCard* rec);

	ListWznmQMdlMdl1NCard& operator=(const ListWznmQMdlMdl1NCard& src);

public:
	std::vector<WznmQMdlMdl1NCard*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQMdlMdl1NCard: C++ wrapper for table TblWznmQMdlMdl1NCard
	*/
class TblWznmQMdlMdl1NCard {

public:
	TblWznmQMdlMdl1NCard();
	virtual ~TblWznmQMdlMdl1NCard();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQMdlMdl1NCard** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMdlMdl1NCard& rst);

	virtual Sbecore::ubigint insertRec(WznmQMdlMdl1NCard* rec);
	Sbecore::ubigint insertNewRec(WznmQMdlMdl1NCard** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQMdlMdl1NCard& rst, WznmQMdlMdl1NCard** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint mdlNum = 0);
	virtual void insertRst(ListWznmQMdlMdl1NCard& rst);
	virtual void updateRec(WznmQMdlMdl1NCard* rec);
	virtual void updateRst(ListWznmQMdlMdl1NCard& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQMdlMdl1NCard** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMdlMdl1NCard& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQMdlMdl1NCard: C++ wrapper for table TblWznmQMdlMdl1NCard (MySQL database)
	*/
class MyTblWznmQMdlMdl1NCard : public TblWznmQMdlMdl1NCard, public Sbecore::MyTable {

public:
	MyTblWznmQMdlMdl1NCard();
	~MyTblWznmQMdlMdl1NCard();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMdlMdl1NCard** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMdlMdl1NCard& rst);

	Sbecore::ubigint insertRec(WznmQMdlMdl1NCard* rec);
	void insertRst(ListWznmQMdlMdl1NCard& rst);
	void updateRec(WznmQMdlMdl1NCard* rec);
	void updateRst(ListWznmQMdlMdl1NCard& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMdlMdl1NCard** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMdlMdl1NCard& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQMdlMdl1NCard: C++ wrapper for table TblWznmQMdlMdl1NCard (PgSQL database)
	*/
class PgTblWznmQMdlMdl1NCard : public TblWznmQMdlMdl1NCard, public Sbecore::PgTable {

public:
	PgTblWznmQMdlMdl1NCard();
	~PgTblWznmQMdlMdl1NCard();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQMdlMdl1NCard** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQMdlMdl1NCard& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQMdlMdl1NCard** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQMdlMdl1NCard& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQMdlMdl1NCard** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQMdlMdl1NCard& rst);

	Sbecore::ubigint insertRec(WznmQMdlMdl1NCard* rec);
	void insertRst(ListWznmQMdlMdl1NCard& rst);
	void updateRec(WznmQMdlMdl1NCard* rec);
	void updateRst(ListWznmQMdlMdl1NCard& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQMdlMdl1NCard** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQMdlMdl1NCard& rst);
};
#endif

#endif

