/**
	* \file WznmQRelRef1NControl.h
	* Dbs and XML wrapper for table TblWznmQRelRef1NControl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQRELREF1NCONTROL_H
#define WZNMQRELREF1NCONTROL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQRelRef1NControl: record of TblWznmQRelRef1NControl
	*/
class WznmQRelRef1NControl {

public:
	WznmQRelRef1NControl(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQRelRef1NControl: recordset of TblWznmQRelRef1NControl
	*/
class ListWznmQRelRef1NControl {

public:
	ListWznmQRelRef1NControl();
	ListWznmQRelRef1NControl(const ListWznmQRelRef1NControl& src);
	~ListWznmQRelRef1NControl();

	void clear();
	unsigned int size() const;
	void append(WznmQRelRef1NControl* rec);

	ListWznmQRelRef1NControl& operator=(const ListWznmQRelRef1NControl& src);

public:
	std::vector<WznmQRelRef1NControl*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQRelRef1NControl: C++ wrapper for table TblWznmQRelRef1NControl
	*/
class TblWznmQRelRef1NControl {

public:
	TblWznmQRelRef1NControl();
	virtual ~TblWznmQRelRef1NControl();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQRelRef1NControl** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelRef1NControl& rst);

	virtual Sbecore::ubigint insertRec(WznmQRelRef1NControl* rec);
	Sbecore::ubigint insertNewRec(WznmQRelRef1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQRelRef1NControl& rst, WznmQRelRef1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQRelRef1NControl& rst);
	virtual void updateRec(WznmQRelRef1NControl* rec);
	virtual void updateRst(ListWznmQRelRef1NControl& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQRelRef1NControl** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelRef1NControl& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQRelRef1NControl: C++ wrapper for table TblWznmQRelRef1NControl (MySQL database)
	*/
class MyTblWznmQRelRef1NControl : public TblWznmQRelRef1NControl, public Sbecore::MyTable {

public:
	MyTblWznmQRelRef1NControl();
	~MyTblWznmQRelRef1NControl();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRelRef1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelRef1NControl& rst);

	Sbecore::ubigint insertRec(WznmQRelRef1NControl* rec);
	void insertRst(ListWznmQRelRef1NControl& rst);
	void updateRec(WznmQRelRef1NControl* rec);
	void updateRst(ListWznmQRelRef1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRelRef1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelRef1NControl& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQRelRef1NControl: C++ wrapper for table TblWznmQRelRef1NControl (PgSQL database)
	*/
class PgTblWznmQRelRef1NControl : public TblWznmQRelRef1NControl, public Sbecore::PgTable {

public:
	PgTblWznmQRelRef1NControl();
	~PgTblWznmQRelRef1NControl();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQRelRef1NControl** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQRelRef1NControl& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQRelRef1NControl** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQRelRef1NControl& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRelRef1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelRef1NControl& rst);

	Sbecore::ubigint insertRec(WznmQRelRef1NControl* rec);
	void insertRst(ListWznmQRelRef1NControl& rst);
	void updateRec(WznmQRelRef1NControl* rec);
	void updateRst(ListWznmQRelRef1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRelRef1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelRef1NControl& rst);
};
#endif

#endif

