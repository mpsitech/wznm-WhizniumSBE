/**
	* \file WznmQQcoRef1NControl.h
	* Dbs and XML wrapper for table TblWznmQQcoRef1NControl (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQQCOREF1NCONTROL_H
#define WZNMQQCOREF1NCONTROL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQQcoRef1NControl: record of TblWznmQQcoRef1NControl
	*/
class WznmQQcoRef1NControl {

public:
	WznmQQcoRef1NControl(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQQcoRef1NControl: recordset of TblWznmQQcoRef1NControl
	*/
class ListWznmQQcoRef1NControl {

public:
	ListWznmQQcoRef1NControl();
	ListWznmQQcoRef1NControl(const ListWznmQQcoRef1NControl& src);
	~ListWznmQQcoRef1NControl();

	void clear();
	unsigned int size() const;
	void append(WznmQQcoRef1NControl* rec);

	ListWznmQQcoRef1NControl& operator=(const ListWznmQQcoRef1NControl& src);

public:
	std::vector<WznmQQcoRef1NControl*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQQcoRef1NControl: C++ wrapper for table TblWznmQQcoRef1NControl
	*/
class TblWznmQQcoRef1NControl {

public:
	TblWznmQQcoRef1NControl();
	virtual ~TblWznmQQcoRef1NControl();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQQcoRef1NControl** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQcoRef1NControl& rst);

	virtual Sbecore::ubigint insertRec(WznmQQcoRef1NControl* rec);
	Sbecore::ubigint insertNewRec(WznmQQcoRef1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQQcoRef1NControl& rst, WznmQQcoRef1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQQcoRef1NControl& rst);
	virtual void updateRec(WznmQQcoRef1NControl* rec);
	virtual void updateRst(ListWznmQQcoRef1NControl& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQQcoRef1NControl** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQcoRef1NControl& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQQcoRef1NControl: C++ wrapper for table TblWznmQQcoRef1NControl (MySQL database)
	*/
class MyTblWznmQQcoRef1NControl : public TblWznmQQcoRef1NControl, public Sbecore::MyTable {

public:
	MyTblWznmQQcoRef1NControl();
	~MyTblWznmQQcoRef1NControl();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQcoRef1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQcoRef1NControl& rst);

	Sbecore::ubigint insertRec(WznmQQcoRef1NControl* rec);
	void insertRst(ListWznmQQcoRef1NControl& rst);
	void updateRec(WznmQQcoRef1NControl* rec);
	void updateRst(ListWznmQQcoRef1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQcoRef1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQcoRef1NControl& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQQcoRef1NControl: C++ wrapper for table TblWznmQQcoRef1NControl (PgSQL database)
	*/
class PgTblWznmQQcoRef1NControl : public TblWznmQQcoRef1NControl, public Sbecore::PgTable {

public:
	PgTblWznmQQcoRef1NControl();
	~PgTblWznmQQcoRef1NControl();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQQcoRef1NControl** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQQcoRef1NControl& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQQcoRef1NControl** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQQcoRef1NControl& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQQcoRef1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQQcoRef1NControl& rst);

	Sbecore::ubigint insertRec(WznmQQcoRef1NControl* rec);
	void insertRst(ListWznmQQcoRef1NControl& rst);
	void updateRec(WznmQQcoRef1NControl* rec);
	void updateRst(ListWznmQQcoRef1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQQcoRef1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQQcoRef1NControl& rst);
};
#endif

#endif

