/**
	* \file WznmQOpk1NOp.h
	* Dbs and XML wrapper for table TblWznmQOpk1NOp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQOPK1NOP_H
#define WZNMQOPK1NOP_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQOpk1NOp: record of TblWznmQOpk1NOp
	*/
class WznmQOpk1NOp {

public:
	WznmQOpk1NOp(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQOpk1NOp: recordset of TblWznmQOpk1NOp
	*/
class ListWznmQOpk1NOp {

public:
	ListWznmQOpk1NOp();
	ListWznmQOpk1NOp(const ListWznmQOpk1NOp& src);
	~ListWznmQOpk1NOp();

	void clear();
	unsigned int size() const;
	void append(WznmQOpk1NOp* rec);

	ListWznmQOpk1NOp& operator=(const ListWznmQOpk1NOp& src);

public:
	std::vector<WznmQOpk1NOp*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQOpk1NOp: C++ wrapper for table TblWznmQOpk1NOp
	*/
class TblWznmQOpk1NOp {

public:
	TblWznmQOpk1NOp();
	virtual ~TblWznmQOpk1NOp();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQOpk1NOp** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpk1NOp& rst);

	virtual Sbecore::ubigint insertRec(WznmQOpk1NOp* rec);
	Sbecore::ubigint insertNewRec(WznmQOpk1NOp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQOpk1NOp& rst, WznmQOpk1NOp** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQOpk1NOp& rst);
	virtual void updateRec(WznmQOpk1NOp* rec);
	virtual void updateRst(ListWznmQOpk1NOp& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQOpk1NOp** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpk1NOp& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQOpk1NOp: C++ wrapper for table TblWznmQOpk1NOp (MySQL database)
	*/
class MyTblWznmQOpk1NOp : public TblWznmQOpk1NOp, public Sbecore::MyTable {

public:
	MyTblWznmQOpk1NOp();
	~MyTblWznmQOpk1NOp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpk1NOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpk1NOp& rst);

	Sbecore::ubigint insertRec(WznmQOpk1NOp* rec);
	void insertRst(ListWznmQOpk1NOp& rst);
	void updateRec(WznmQOpk1NOp* rec);
	void updateRst(ListWznmQOpk1NOp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpk1NOp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpk1NOp& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQOpk1NOp: C++ wrapper for table TblWznmQOpk1NOp (PgSQL database)
	*/
class PgTblWznmQOpk1NOp : public TblWznmQOpk1NOp, public Sbecore::PgTable {

public:
	PgTblWznmQOpk1NOp();
	~PgTblWznmQOpk1NOp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQOpk1NOp** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQOpk1NOp& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQOpk1NOp** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQOpk1NOp& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQOpk1NOp** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQOpk1NOp& rst);

	Sbecore::ubigint insertRec(WznmQOpk1NOp* rec);
	void insertRst(ListWznmQOpk1NOp& rst);
	void updateRec(WznmQOpk1NOp* rec);
	void updateRst(ListWznmQOpk1NOp& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQOpk1NOp** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQOpk1NOp& rst);
};
#endif

#endif
