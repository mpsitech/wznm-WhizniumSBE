/**
	* \file WznmQCarHk1NControl.h
	* Dbs and XML wrapper for table TblWznmQCarHk1NControl (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMQCARHK1NCONTROL_H
#define WZNMQCARHK1NCONTROL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCarHk1NControl: record of TblWznmQCarHk1NControl
	*/
class WznmQCarHk1NControl {

public:
	WznmQCarHk1NControl(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);

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
	* ListWznmQCarHk1NControl: recordset of TblWznmQCarHk1NControl
	*/
class ListWznmQCarHk1NControl {

public:
	ListWznmQCarHk1NControl();
	ListWznmQCarHk1NControl(const ListWznmQCarHk1NControl& src);
	~ListWznmQCarHk1NControl();

	void clear();
	unsigned int size() const;
	void append(WznmQCarHk1NControl* rec);

	ListWznmQCarHk1NControl& operator=(const ListWznmQCarHk1NControl& src);

public:
	std::vector<WznmQCarHk1NControl*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCarHk1NControl: C++ wrapper for table TblWznmQCarHk1NControl
	*/
class TblWznmQCarHk1NControl {

public:
	TblWznmQCarHk1NControl();
	virtual ~TblWznmQCarHk1NControl();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCarHk1NControl** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCarHk1NControl& rst);

	virtual Sbecore::ubigint insertRec(WznmQCarHk1NControl* rec);
	Sbecore::ubigint insertNewRec(WznmQCarHk1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQCarHk1NControl& rst, WznmQCarHk1NControl** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint hkNum = 0);
	virtual void insertRst(ListWznmQCarHk1NControl& rst);
	virtual void updateRec(WznmQCarHk1NControl* rec);
	virtual void updateRst(ListWznmQCarHk1NControl& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCarHk1NControl** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCarHk1NControl& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCarHk1NControl: C++ wrapper for table TblWznmQCarHk1NControl (MySQL database)
	*/
class MyTblWznmQCarHk1NControl : public TblWznmQCarHk1NControl, public Sbecore::MyTable {

public:
	MyTblWznmQCarHk1NControl();
	~MyTblWznmQCarHk1NControl();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCarHk1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCarHk1NControl& rst);

	Sbecore::ubigint insertRec(WznmQCarHk1NControl* rec);
	void insertRst(ListWznmQCarHk1NControl& rst);
	void updateRec(WznmQCarHk1NControl* rec);
	void updateRst(ListWznmQCarHk1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCarHk1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCarHk1NControl& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCarHk1NControl: C++ wrapper for table TblWznmQCarHk1NControl (PgSQL database)
	*/
class PgTblWznmQCarHk1NControl : public TblWznmQCarHk1NControl, public Sbecore::PgTable {

public:
	PgTblWznmQCarHk1NControl();
	~PgTblWznmQCarHk1NControl();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCarHk1NControl** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCarHk1NControl& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCarHk1NControl** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCarHk1NControl& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCarHk1NControl** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCarHk1NControl& rst);

	Sbecore::ubigint insertRec(WznmQCarHk1NControl* rec);
	void insertRst(ListWznmQCarHk1NControl& rst);
	void updateRec(WznmQCarHk1NControl* rec);
	void updateRst(ListWznmQCarHk1NControl& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCarHk1NControl** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCarHk1NControl& rst);
};
#endif

#endif

