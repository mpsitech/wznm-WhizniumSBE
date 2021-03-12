/**
	* \file WznmQJobACmd.h
	* Dbs and XML wrapper for table TblWznmQJobACmd (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQJOBACMD_H
#define WZNMQJOBACMD_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQJobACmd: record of TblWznmQJobACmd
	*/
class WznmQJobACmd {

public:
	WznmQJobACmd(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Comment = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string sref;
	std::string Comment;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQJobACmd: recordset of TblWznmQJobACmd
	*/
class ListWznmQJobACmd {

public:
	ListWznmQJobACmd();
	ListWznmQJobACmd(const ListWznmQJobACmd& src);
	~ListWznmQJobACmd();

	void clear();
	unsigned int size() const;
	void append(WznmQJobACmd* rec);

	ListWznmQJobACmd& operator=(const ListWznmQJobACmd& src);

public:
	std::vector<WznmQJobACmd*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQJobACmd: C++ wrapper for table TblWznmQJobACmd
	*/
class TblWznmQJobACmd {

public:
	TblWznmQJobACmd();
	virtual ~TblWznmQJobACmd();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQJobACmd** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobACmd& rst);

	virtual Sbecore::ubigint insertRec(WznmQJobACmd* rec);
	Sbecore::ubigint insertNewRec(WznmQJobACmd** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Comment = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQJobACmd& rst, WznmQJobACmd** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string sref = "", const std::string Comment = "");
	virtual void insertRst(ListWznmQJobACmd& rst);
	virtual void updateRec(WznmQJobACmd* rec);
	virtual void updateRst(ListWznmQJobACmd& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQJobACmd** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobACmd& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQJobACmd: C++ wrapper for table TblWznmQJobACmd (MySQL database)
	*/
class MyTblWznmQJobACmd : public TblWznmQJobACmd, public Sbecore::MyTable {

public:
	MyTblWznmQJobACmd();
	~MyTblWznmQJobACmd();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobACmd** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobACmd& rst);

	Sbecore::ubigint insertRec(WznmQJobACmd* rec);
	void insertRst(ListWznmQJobACmd& rst);
	void updateRec(WznmQJobACmd* rec);
	void updateRst(ListWznmQJobACmd& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobACmd** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobACmd& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQJobACmd: C++ wrapper for table TblWznmQJobACmd (PgSQL database)
	*/
class PgTblWznmQJobACmd : public TblWznmQJobACmd, public Sbecore::PgTable {

public:
	PgTblWznmQJobACmd();
	~PgTblWznmQJobACmd();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQJobACmd** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQJobACmd& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQJobACmd** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQJobACmd& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobACmd** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobACmd& rst);

	Sbecore::ubigint insertRec(WznmQJobACmd* rec);
	void insertRst(ListWznmQJobACmd& rst);
	void updateRec(WznmQJobACmd* rec);
	void updateRst(ListWznmQJobACmd& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobACmd** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobACmd& rst);
};
#endif

#endif
