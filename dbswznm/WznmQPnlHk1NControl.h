/**
	* \file WznmQPnlHk1NControl.h
	* Dbs and XML wrapper for table TblWznmQPnlHk1NControl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQPNLHK1NCONTROL_H
#define WZNMQPNLHK1NCONTROL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQPnlHk1NControl: record of TblWznmQPnlHk1NControl
	*/
class WznmQPnlHk1NControl {

public:
	WznmQPnlHk1NControl(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint hkNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQPnlHk1NControl: recordset of TblWznmQPnlHk1NControl
	*/
class ListWznmQPnlHk1NControl {

public:
	ListWznmQPnlHk1NControl();
	ListWznmQPnlHk1NControl(const ListWznmQPnlHk1NControl& src);
	~ListWznmQPnlHk1NControl();

	void clear();
	unsigned int size() const;
	void append(WznmQPnlHk1NControl* rec);

	ListWznmQPnlHk1NControl& operator=(const ListWznmQPnlHk1NControl& src);

public:
	std::vector<WznmQPnlHk1NControl*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQPnlHk1NControl: C++ wrapper for table TblWznmQPnlHk1NControl
	*/
class TblWznmQPnlHk1NControl {

public:
	TblWznmQPnlHk1NControl();
	virtual ~TblWznmQPnlHk1NControl();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQPnlHk1NControl** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPnlHk1NControl& rst);

	virtual Sbecore::ubigint insertRec(WznmQPnlHk1NControl* rec);
	Sbecore::ubigint insertNewRec(WznmQPnlHk1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQPnlHk1NControl& rst, WznmQPnlHk1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);
	virtual void insertRst(ListWznmQPnlHk1NControl& rst);
	virtual void updateRec(WznmQPnlHk1NControl* rec);
	virtual void updateRst(ListWznmQPnlHk1NControl& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQPnlHk1NControl** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPnlHk1NControl& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQPnlHk1NControl: C++ wrapper for table TblWznmQPnlHk1NControl (MySQL database)
	*/
class MyTblWznmQPnlHk1NControl : public TblWznmQPnlHk1NControl, public Sbecore::MyTable {

public:
	MyTblWznmQPnlHk1NControl();
	~MyTblWznmQPnlHk1NControl();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPnlHk1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPnlHk1NControl& rst);

	Sbecore::ubigint insertRec(WznmQPnlHk1NControl* rec);
	void insertRst(ListWznmQPnlHk1NControl& rst);
	void updateRec(WznmQPnlHk1NControl* rec);
	void updateRst(ListWznmQPnlHk1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPnlHk1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPnlHk1NControl& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQPnlHk1NControl: C++ wrapper for table TblWznmQPnlHk1NControl (PgSQL database)
	*/
class PgTblWznmQPnlHk1NControl : public TblWznmQPnlHk1NControl, public Sbecore::PgTable {

public:
	PgTblWznmQPnlHk1NControl();
	~PgTblWznmQPnlHk1NControl();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQPnlHk1NControl** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQPnlHk1NControl& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQPnlHk1NControl** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQPnlHk1NControl& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQPnlHk1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQPnlHk1NControl& rst);

	Sbecore::ubigint insertRec(WznmQPnlHk1NControl* rec);
	void insertRst(ListWznmQPnlHk1NControl& rst);
	void updateRec(WznmQPnlHk1NControl* rec);
	void updateRst(ListWznmQPnlHk1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQPnlHk1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQPnlHk1NControl& rst);
};
#endif

#endif

