/**
	* \file WznmQJobJob1NStage.h
	* Dbs and XML wrapper for table TblWznmQJobJob1NStage (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQJOBJOB1NSTAGE_H
#define WZNMQJOBJOB1NSTAGE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQJobJob1NStage: record of TblWznmQJobJob1NStage
	*/
class WznmQJobJob1NStage {

public:
	WznmQJobJob1NStage(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint jobNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint jobNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQJobJob1NStage: recordset of TblWznmQJobJob1NStage
	*/
class ListWznmQJobJob1NStage {

public:
	ListWznmQJobJob1NStage();
	ListWznmQJobJob1NStage(const ListWznmQJobJob1NStage& src);
	~ListWznmQJobJob1NStage();

	void clear();
	unsigned int size() const;
	void append(WznmQJobJob1NStage* rec);

	ListWznmQJobJob1NStage& operator=(const ListWznmQJobJob1NStage& src);

public:
	std::vector<WznmQJobJob1NStage*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQJobJob1NStage: C++ wrapper for table TblWznmQJobJob1NStage
	*/
class TblWznmQJobJob1NStage {

public:
	TblWznmQJobJob1NStage();
	virtual ~TblWznmQJobJob1NStage();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQJobJob1NStage** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobJob1NStage& rst);

	virtual Sbecore::ubigint insertRec(WznmQJobJob1NStage* rec);
	Sbecore::ubigint insertNewRec(WznmQJobJob1NStage** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint jobNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQJobJob1NStage& rst, WznmQJobJob1NStage** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint jobNum = 0);
	virtual void insertRst(ListWznmQJobJob1NStage& rst);
	virtual void updateRec(WznmQJobJob1NStage* rec);
	virtual void updateRst(ListWznmQJobJob1NStage& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQJobJob1NStage** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobJob1NStage& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQJobJob1NStage: C++ wrapper for table TblWznmQJobJob1NStage (MySQL database)
	*/
class MyTblWznmQJobJob1NStage : public TblWznmQJobJob1NStage, public Sbecore::MyTable {

public:
	MyTblWznmQJobJob1NStage();
	~MyTblWznmQJobJob1NStage();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobJob1NStage** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobJob1NStage& rst);

	Sbecore::ubigint insertRec(WznmQJobJob1NStage* rec);
	void insertRst(ListWznmQJobJob1NStage& rst);
	void updateRec(WznmQJobJob1NStage* rec);
	void updateRst(ListWznmQJobJob1NStage& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobJob1NStage** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobJob1NStage& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQJobJob1NStage: C++ wrapper for table TblWznmQJobJob1NStage (PgSQL database)
	*/
class PgTblWznmQJobJob1NStage : public TblWznmQJobJob1NStage, public Sbecore::PgTable {

public:
	PgTblWznmQJobJob1NStage();
	~PgTblWznmQJobJob1NStage();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQJobJob1NStage** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQJobJob1NStage& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQJobJob1NStage** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQJobJob1NStage& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQJobJob1NStage** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQJobJob1NStage& rst);

	Sbecore::ubigint insertRec(WznmQJobJob1NStage* rec);
	void insertRst(ListWznmQJobJob1NStage& rst);
	void updateRec(WznmQJobJob1NStage* rec);
	void updateRst(ListWznmQJobJob1NStage& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQJobJob1NStage** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQJobJob1NStage& rst);
};
#endif

#endif

