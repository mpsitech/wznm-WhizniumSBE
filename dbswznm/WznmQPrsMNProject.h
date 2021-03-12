/**
	* \file WznmQPrsMNProject.h
	* Dbs and XML wrapper for table TblWznmQPrsMNProject (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQPRSMNPROJECT_H
#define WZNMQPRSMNPROJECT_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQPrsMNProject: record of TblWznmQPrsMNProject
	*/
class WznmQPrsMNProject {

public:
	WznmQPrsMNProject(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint mref;
	std::string stubMref;
	Sbecore::ubigint ref;
	Sbecore::uint x1Startd;
	std::string ftmX1Startd;
	Sbecore::uint x1Stopd;
	std::string ftmX1Stopd;
	std::string srefKFunction;
	std::string titSrefKFunction;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQPrsMNProject: recordset of TblWznmQPrsMNProject
	*/
class ListWznmQPrsMNProject {

public:
	ListWznmQPrsMNProject();
	ListWznmQPrsMNProject(const ListWznmQPrsMNProject& src);
	~ListWznmQPrsMNProject();

	void clear();
	unsigned int size() const;
	void append(WznmQPrsMNProject* rec);

	ListWznmQPrsMNProject& operator=(const ListWznmQPrsMNProject& src);

public:
	std::vector<WznmQPrsMNProject*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQPrsMNProject: C++ wrapper for table TblWznmQPrsMNProject
	*/
class TblWznmQPrsMNProject {

public:
	TblWznmQPrsMNProject();
	virtual ~TblWznmQPrsMNProject();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQPrsMNProject** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrsMNProject& rst);

	virtual Sbecore::ubigint insertRec(WznmQPrsMNProject* rec);
	Sbecore::ubigint insertNewRec(WznmQPrsMNProject** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQPrsMNProject& rst, WznmQPrsMNProject** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint mref = 0, const std::string stubMref = "", const Sbecore::ubigint ref = 0, const Sbecore::uint x1Startd = 0, const std::string ftmX1Startd = "", const Sbecore::uint x1Stopd = 0, const std::string ftmX1Stopd = "", const std::string srefKFunction = "", const std::string titSrefKFunction = "");
	virtual void insertRst(ListWznmQPrsMNProject& rst);
	virtual void updateRec(WznmQPrsMNProject* rec);
	virtual void updateRst(ListWznmQPrsMNProject& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQPrsMNProject** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrsMNProject& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQPrsMNProject: C++ wrapper for table TblWznmQPrsMNProject (MySQL database)
	*/
class MyTblWznmQPrsMNProject : public TblWznmQPrsMNProject, public Sbecore::MyTable {

public:
	MyTblWznmQPrsMNProject();
	~MyTblWznmQPrsMNProject();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrsMNProject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrsMNProject& rst);

	Sbecore::ubigint insertRec(WznmQPrsMNProject* rec);
	void insertRst(ListWznmQPrsMNProject& rst);
	void updateRec(WznmQPrsMNProject* rec);
	void updateRst(ListWznmQPrsMNProject& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrsMNProject** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrsMNProject& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQPrsMNProject: C++ wrapper for table TblWznmQPrsMNProject (PgSQL database)
	*/
class PgTblWznmQPrsMNProject : public TblWznmQPrsMNProject, public Sbecore::PgTable {

public:
	PgTblWznmQPrsMNProject();
	~PgTblWznmQPrsMNProject();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQPrsMNProject** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQPrsMNProject& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQPrsMNProject** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQPrsMNProject& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPrsMNProject** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPrsMNProject& rst);

	Sbecore::ubigint insertRec(WznmQPrsMNProject* rec);
	void insertRst(ListWznmQPrsMNProject& rst);
	void updateRec(WznmQPrsMNProject* rec);
	void updateRst(ListWznmQPrsMNProject& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPrsMNProject** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPrsMNProject& rst);
};
#endif

#endif
