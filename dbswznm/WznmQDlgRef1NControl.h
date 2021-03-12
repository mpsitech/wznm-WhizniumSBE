/**
	* \file WznmQDlgRef1NControl.h
	* Dbs and XML wrapper for table TblWznmQDlgRef1NControl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQDLGREF1NCONTROL_H
#define WZNMQDLGREF1NCONTROL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQDlgRef1NControl: record of TblWznmQDlgRef1NControl
	*/
class WznmQDlgRef1NControl {

public:
	WznmQDlgRef1NControl(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQDlgRef1NControl: recordset of TblWznmQDlgRef1NControl
	*/
class ListWznmQDlgRef1NControl {

public:
	ListWznmQDlgRef1NControl();
	ListWznmQDlgRef1NControl(const ListWznmQDlgRef1NControl& src);
	~ListWznmQDlgRef1NControl();

	void clear();
	unsigned int size() const;
	void append(WznmQDlgRef1NControl* rec);

	ListWznmQDlgRef1NControl& operator=(const ListWznmQDlgRef1NControl& src);

public:
	std::vector<WznmQDlgRef1NControl*> nodes;

public:
	void writeJSON(Json::Value& sup, std::string difftag = "");
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQDlgRef1NControl: C++ wrapper for table TblWznmQDlgRef1NControl
	*/
class TblWznmQDlgRef1NControl {

public:
	TblWznmQDlgRef1NControl();
	virtual ~TblWznmQDlgRef1NControl();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQDlgRef1NControl** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQDlgRef1NControl& rst);

	virtual Sbecore::ubigint insertRec(WznmQDlgRef1NControl* rec);
	Sbecore::ubigint insertNewRec(WznmQDlgRef1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQDlgRef1NControl& rst, WznmQDlgRef1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQDlgRef1NControl& rst);
	virtual void updateRec(WznmQDlgRef1NControl* rec);
	virtual void updateRst(ListWznmQDlgRef1NControl& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQDlgRef1NControl** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQDlgRef1NControl& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQDlgRef1NControl: C++ wrapper for table TblWznmQDlgRef1NControl (MySQL database)
	*/
class MyTblWznmQDlgRef1NControl : public TblWznmQDlgRef1NControl, public Sbecore::MyTable {

public:
	MyTblWznmQDlgRef1NControl();
	~MyTblWznmQDlgRef1NControl();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQDlgRef1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQDlgRef1NControl& rst);

	Sbecore::ubigint insertRec(WznmQDlgRef1NControl* rec);
	void insertRst(ListWznmQDlgRef1NControl& rst);
	void updateRec(WznmQDlgRef1NControl* rec);
	void updateRst(ListWznmQDlgRef1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQDlgRef1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQDlgRef1NControl& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQDlgRef1NControl: C++ wrapper for table TblWznmQDlgRef1NControl (PgSQL database)
	*/
class PgTblWznmQDlgRef1NControl : public TblWznmQDlgRef1NControl, public Sbecore::PgTable {

public:
	PgTblWznmQDlgRef1NControl();
	~PgTblWznmQDlgRef1NControl();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQDlgRef1NControl** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQDlgRef1NControl& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQDlgRef1NControl** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQDlgRef1NControl& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQDlgRef1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQDlgRef1NControl& rst);

	Sbecore::ubigint insertRec(WznmQDlgRef1NControl* rec);
	void insertRst(ListWznmQDlgRef1NControl& rst);
	void updateRec(WznmQDlgRef1NControl* rec);
	void updateRst(ListWznmQDlgRef1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQDlgRef1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQDlgRef1NControl& rst);
};
#endif

#endif
