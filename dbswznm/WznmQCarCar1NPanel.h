/**
	* \file WznmQCarCar1NPanel.h
	* Dbs and XML wrapper for table TblWznmQCarCar1NPanel (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQCARCAR1NPANEL_H
#define WZNMQCARCAR1NPANEL_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQCarCar1NPanel: record of TblWznmQCarCar1NPanel
	*/
class WznmQCarCar1NPanel {

public:
	WznmQCarCar1NPanel(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint carNum = 0);

public:
	Sbecore::ubigint qref;
	Sbecore::ubigint jref;
	Sbecore::uint jnum;
	Sbecore::ubigint ref;
	std::string stubRef;
	Sbecore::uint carNum;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
	* ListWznmQCarCar1NPanel: recordset of TblWznmQCarCar1NPanel
	*/
class ListWznmQCarCar1NPanel {

public:
	ListWznmQCarCar1NPanel();
	ListWznmQCarCar1NPanel(const ListWznmQCarCar1NPanel& src);
	~ListWznmQCarCar1NPanel();

	void clear();
	unsigned int size() const;
	void append(WznmQCarCar1NPanel* rec);

	ListWznmQCarCar1NPanel& operator=(const ListWznmQCarCar1NPanel& src);

public:
	std::vector<WznmQCarCar1NPanel*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQCarCar1NPanel: C++ wrapper for table TblWznmQCarCar1NPanel
	*/
class TblWznmQCarCar1NPanel {

public:
	TblWznmQCarCar1NPanel();
	virtual ~TblWznmQCarCar1NPanel();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQCarCar1NPanel** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCarCar1NPanel& rst);

	virtual Sbecore::ubigint insertRec(WznmQCarCar1NPanel* rec);
	Sbecore::ubigint insertNewRec(WznmQCarCar1NPanel** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint carNum = 0);
	Sbecore::ubigint appendNewRecToRst(ListWznmQCarCar1NPanel& rst, WznmQCarCar1NPanel** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "", const Sbecore::uint carNum = 0);
	virtual void insertRst(ListWznmQCarCar1NPanel& rst);
	virtual void updateRec(WznmQCarCar1NPanel* rec);
	virtual void updateRst(ListWznmQCarCar1NPanel& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQCarCar1NPanel** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCarCar1NPanel& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQCarCar1NPanel: C++ wrapper for table TblWznmQCarCar1NPanel (MySQL database)
	*/
class MyTblWznmQCarCar1NPanel : public TblWznmQCarCar1NPanel, public Sbecore::MyTable {

public:
	MyTblWznmQCarCar1NPanel();
	~MyTblWznmQCarCar1NPanel();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCarCar1NPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCarCar1NPanel& rst);

	Sbecore::ubigint insertRec(WznmQCarCar1NPanel* rec);
	void insertRst(ListWznmQCarCar1NPanel& rst);
	void updateRec(WznmQCarCar1NPanel* rec);
	void updateRst(ListWznmQCarCar1NPanel& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCarCar1NPanel** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCarCar1NPanel& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQCarCar1NPanel: C++ wrapper for table TblWznmQCarCar1NPanel (PgSQL database)
	*/
class PgTblWznmQCarCar1NPanel : public TblWznmQCarCar1NPanel, public Sbecore::PgTable {

public:
	PgTblWznmQCarCar1NPanel();
	~PgTblWznmQCarCar1NPanel();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQCarCar1NPanel** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQCarCar1NPanel& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQCarCar1NPanel** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQCarCar1NPanel& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQCarCar1NPanel** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQCarCar1NPanel& rst);

	Sbecore::ubigint insertRec(WznmQCarCar1NPanel* rec);
	void insertRst(ListWznmQCarCar1NPanel& rst);
	void updateRec(WznmQCarCar1NPanel* rec);
	void updateRst(ListWznmQCarCar1NPanel& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQCarCar1NPanel** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQCarCar1NPanel& rst);
};
#endif

#endif

