/**
	* \file WznmQConSup1NControl.h
	* Dbs and XML wrapper for table TblWznmQConSup1NControl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCONSUP1NCONTROL_H
#define WZNMQCONSUP1NCONTROL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQConSup1NControl: record of TblWznmQConSup1NControl
	*/
class WznmQConSup1NControl {

public:
	WznmQConSup1NControl(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint supNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint supNum;

public:
	void writeJSON(Json::Value& sup, bool jnumattr = false, bool shorttags = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQConSup1NControl: recordset of TblWznmQConSup1NControl
	*/
class ListWznmQConSup1NControl {

public:
	ListWznmQConSup1NControl();
	ListWznmQConSup1NControl(const ListWznmQConSup1NControl& src);
	~ListWznmQConSup1NControl();

	void clear();
	unsigned int size() const;
	void append(WznmQConSup1NControl* rec);

	ListWznmQConSup1NControl& operator=(const ListWznmQConSup1NControl& src);

public:
	std::vector<WznmQConSup1NControl*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQConSup1NControl: C++ wrapper for table TblWznmQConSup1NControl
	*/
class TblWznmQConSup1NControl {

public:
	TblWznmQConSup1NControl();
	virtual ~TblWznmQConSup1NControl();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQConSup1NControl** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQConSup1NControl& rst);

	virtual Sbecore::ubigint insertRec(WznmQConSup1NControl* rec);
	Sbecore::ubigint insertNewRec(WznmQConSup1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint supNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQConSup1NControl& rst, WznmQConSup1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint supNum = 0);
	virtual void insertRst(ListWznmQConSup1NControl& rst);
	virtual void updateRec(WznmQConSup1NControl* rec);
	virtual void updateRst(ListWznmQConSup1NControl& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQConSup1NControl** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQConSup1NControl& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQConSup1NControl: C++ wrapper for table TblWznmQConSup1NControl (MySQL database)
	*/
class MyTblWznmQConSup1NControl : public TblWznmQConSup1NControl, public Sbecore::MyTable {

public:
	MyTblWznmQConSup1NControl();
	~MyTblWznmQConSup1NControl();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQConSup1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQConSup1NControl& rst);

	Sbecore::ubigint insertRec(WznmQConSup1NControl* rec);
	void insertRst(ListWznmQConSup1NControl& rst);
	void updateRec(WznmQConSup1NControl* rec);
	void updateRst(ListWznmQConSup1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQConSup1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQConSup1NControl& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQConSup1NControl: C++ wrapper for table TblWznmQConSup1NControl (PgSQL database)
	*/
class PgTblWznmQConSup1NControl : public TblWznmQConSup1NControl, public Sbecore::PgTable {

public:
	PgTblWznmQConSup1NControl();
	~PgTblWznmQConSup1NControl();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQConSup1NControl** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQConSup1NControl& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQConSup1NControl** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQConSup1NControl& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQConSup1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQConSup1NControl& rst);

	Sbecore::ubigint insertRec(WznmQConSup1NControl* rec);
	void insertRst(ListWznmQConSup1NControl& rst);
	void updateRec(WznmQConSup1NControl* rec);
	void updateRst(ListWznmQConSup1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQConSup1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQConSup1NControl& rst);
};
#endif

#endif
