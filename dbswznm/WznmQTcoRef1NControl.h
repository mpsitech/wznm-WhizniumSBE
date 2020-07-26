/**
	* \file WznmQTcoRef1NControl.h
	* Dbs and XML wrapper for table TblWznmQTcoRef1NControl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQTCOREF1NCONTROL_H
#define WZNMQTCOREF1NCONTROL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQTcoRef1NControl: record of TblWznmQTcoRef1NControl
	*/
class WznmQTcoRef1NControl {

public:
	WznmQTcoRef1NControl(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQTcoRef1NControl: recordset of TblWznmQTcoRef1NControl
	*/
class ListWznmQTcoRef1NControl {

public:
	ListWznmQTcoRef1NControl();
	ListWznmQTcoRef1NControl(const ListWznmQTcoRef1NControl& src);
	~ListWznmQTcoRef1NControl();

	void clear();
	unsigned int size() const;
	void append(WznmQTcoRef1NControl* rec);

	ListWznmQTcoRef1NControl& operator=(const ListWznmQTcoRef1NControl& src);

public:
	std::vector<WznmQTcoRef1NControl*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQTcoRef1NControl: C++ wrapper for table TblWznmQTcoRef1NControl
	*/
class TblWznmQTcoRef1NControl {

public:
	TblWznmQTcoRef1NControl();
	virtual ~TblWznmQTcoRef1NControl();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQTcoRef1NControl** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTcoRef1NControl& rst);

	virtual Sbecore::ubigint insertRec(WznmQTcoRef1NControl* rec);
	Sbecore::ubigint insertNewRec(WznmQTcoRef1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQTcoRef1NControl& rst, WznmQTcoRef1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQTcoRef1NControl& rst);
	virtual void updateRec(WznmQTcoRef1NControl* rec);
	virtual void updateRst(ListWznmQTcoRef1NControl& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQTcoRef1NControl** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTcoRef1NControl& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQTcoRef1NControl: C++ wrapper for table TblWznmQTcoRef1NControl (MySQL database)
	*/
class MyTblWznmQTcoRef1NControl : public TblWznmQTcoRef1NControl, public Sbecore::MyTable {

public:
	MyTblWznmQTcoRef1NControl();
	~MyTblWznmQTcoRef1NControl();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTcoRef1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTcoRef1NControl& rst);

	Sbecore::ubigint insertRec(WznmQTcoRef1NControl* rec);
	void insertRst(ListWznmQTcoRef1NControl& rst);
	void updateRec(WznmQTcoRef1NControl* rec);
	void updateRst(ListWznmQTcoRef1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTcoRef1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTcoRef1NControl& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQTcoRef1NControl: C++ wrapper for table TblWznmQTcoRef1NControl (PgSQL database)
	*/
class PgTblWznmQTcoRef1NControl : public TblWznmQTcoRef1NControl, public Sbecore::PgTable {

public:
	PgTblWznmQTcoRef1NControl();
	~PgTblWznmQTcoRef1NControl();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQTcoRef1NControl** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQTcoRef1NControl& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQTcoRef1NControl** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQTcoRef1NControl& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQTcoRef1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQTcoRef1NControl& rst);

	Sbecore::ubigint insertRec(WznmQTcoRef1NControl* rec);
	void insertRst(ListWznmQTcoRef1NControl& rst);
	void updateRec(WznmQTcoRef1NControl* rec);
	void updateRst(ListWznmQTcoRef1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQTcoRef1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQTcoRef1NControl& rst);
};
#endif

#endif

