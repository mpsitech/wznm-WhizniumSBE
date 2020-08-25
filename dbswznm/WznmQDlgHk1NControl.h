/**
	* \file WznmQDlgHk1NControl.h
	* Dbs and XML wrapper for table TblWznmQDlgHk1NControl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQDLGHK1NCONTROL_H
#define WZNMQDLGHK1NCONTROL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQDlgHk1NControl: record of TblWznmQDlgHk1NControl
	*/
class WznmQDlgHk1NControl {

public:
	WznmQDlgHk1NControl(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);

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
	* ListWznmQDlgHk1NControl: recordset of TblWznmQDlgHk1NControl
	*/
class ListWznmQDlgHk1NControl {

public:
	ListWznmQDlgHk1NControl();
	ListWznmQDlgHk1NControl(const ListWznmQDlgHk1NControl& src);
	~ListWznmQDlgHk1NControl();

	void clear();
	unsigned int size() const;
	void append(WznmQDlgHk1NControl* rec);

	ListWznmQDlgHk1NControl& operator=(const ListWznmQDlgHk1NControl& src);

public:
	std::vector<WznmQDlgHk1NControl*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQDlgHk1NControl: C++ wrapper for table TblWznmQDlgHk1NControl
	*/
class TblWznmQDlgHk1NControl {

public:
	TblWznmQDlgHk1NControl();
	virtual ~TblWznmQDlgHk1NControl();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQDlgHk1NControl** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQDlgHk1NControl& rst);

	virtual Sbecore::ubigint insertRec(WznmQDlgHk1NControl* rec);
	Sbecore::ubigint insertNewRec(WznmQDlgHk1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQDlgHk1NControl& rst, WznmQDlgHk1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);
	virtual void insertRst(ListWznmQDlgHk1NControl& rst);
	virtual void updateRec(WznmQDlgHk1NControl* rec);
	virtual void updateRst(ListWznmQDlgHk1NControl& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQDlgHk1NControl** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQDlgHk1NControl& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQDlgHk1NControl: C++ wrapper for table TblWznmQDlgHk1NControl (MySQL database)
	*/
class MyTblWznmQDlgHk1NControl : public TblWznmQDlgHk1NControl, public Sbecore::MyTable {

public:
	MyTblWznmQDlgHk1NControl();
	~MyTblWznmQDlgHk1NControl();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQDlgHk1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQDlgHk1NControl& rst);

	Sbecore::ubigint insertRec(WznmQDlgHk1NControl* rec);
	void insertRst(ListWznmQDlgHk1NControl& rst);
	void updateRec(WznmQDlgHk1NControl* rec);
	void updateRst(ListWznmQDlgHk1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQDlgHk1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQDlgHk1NControl& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQDlgHk1NControl: C++ wrapper for table TblWznmQDlgHk1NControl (PgSQL database)
	*/
class PgTblWznmQDlgHk1NControl : public TblWznmQDlgHk1NControl, public Sbecore::PgTable {

public:
	PgTblWznmQDlgHk1NControl();
	~PgTblWznmQDlgHk1NControl();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQDlgHk1NControl** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQDlgHk1NControl& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQDlgHk1NControl** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQDlgHk1NControl& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQDlgHk1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQDlgHk1NControl& rst);

	Sbecore::ubigint insertRec(WznmQDlgHk1NControl* rec);
	void insertRst(ListWznmQDlgHk1NControl& rst);
	void updateRec(WznmQDlgHk1NControl* rec);
	void updateRst(ListWznmQDlgHk1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQDlgHk1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQDlgHk1NControl& rst);
};
#endif

#endif

