/**
	* \file WznmQIexRef1NDialog.h
	* Dbs and XML wrapper for table TblWznmQIexRef1NDialog (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQIEXREF1NDIALOG_H
#define WZNMQIEXREF1NDIALOG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQIexRef1NDialog: record of TblWznmQIexRef1NDialog
	*/
class WznmQIexRef1NDialog {

public:
	WznmQIexRef1NDialog(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQIexRef1NDialog: recordset of TblWznmQIexRef1NDialog
	*/
class ListWznmQIexRef1NDialog {

public:
	ListWznmQIexRef1NDialog();
	ListWznmQIexRef1NDialog(const ListWznmQIexRef1NDialog& src);
	~ListWznmQIexRef1NDialog();

	void clear();
	unsigned int size() const;
	void append(WznmQIexRef1NDialog* rec);

	ListWznmQIexRef1NDialog& operator=(const ListWznmQIexRef1NDialog& src);

public:
	std::vector<WznmQIexRef1NDialog*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQIexRef1NDialog: C++ wrapper for table TblWznmQIexRef1NDialog
	*/
class TblWznmQIexRef1NDialog {

public:
	TblWznmQIexRef1NDialog();
	virtual ~TblWznmQIexRef1NDialog();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQIexRef1NDialog** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIexRef1NDialog& rst);

	virtual Sbecore::ubigint insertRec(WznmQIexRef1NDialog* rec);
	Sbecore::ubigint insertNewRec(WznmQIexRef1NDialog** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQIexRef1NDialog& rst, WznmQIexRef1NDialog** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQIexRef1NDialog& rst);
	virtual void updateRec(WznmQIexRef1NDialog* rec);
	virtual void updateRst(ListWznmQIexRef1NDialog& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQIexRef1NDialog** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIexRef1NDialog& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQIexRef1NDialog: C++ wrapper for table TblWznmQIexRef1NDialog (MySQL database)
	*/
class MyTblWznmQIexRef1NDialog : public TblWznmQIexRef1NDialog, public Sbecore::MyTable {

public:
	MyTblWznmQIexRef1NDialog();
	~MyTblWznmQIexRef1NDialog();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQIexRef1NDialog** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIexRef1NDialog& rst);

	Sbecore::ubigint insertRec(WznmQIexRef1NDialog* rec);
	void insertRst(ListWznmQIexRef1NDialog& rst);
	void updateRec(WznmQIexRef1NDialog* rec);
	void updateRst(ListWznmQIexRef1NDialog& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQIexRef1NDialog** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIexRef1NDialog& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQIexRef1NDialog: C++ wrapper for table TblWznmQIexRef1NDialog (PgSQL database)
	*/
class PgTblWznmQIexRef1NDialog : public TblWznmQIexRef1NDialog, public Sbecore::PgTable {

public:
	PgTblWznmQIexRef1NDialog();
	~PgTblWznmQIexRef1NDialog();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQIexRef1NDialog** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQIexRef1NDialog& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQIexRef1NDialog** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQIexRef1NDialog& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQIexRef1NDialog** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQIexRef1NDialog& rst);

	Sbecore::ubigint insertRec(WznmQIexRef1NDialog* rec);
	void insertRst(ListWznmQIexRef1NDialog& rst);
	void updateRec(WznmQIexRef1NDialog* rec);
	void updateRst(ListWznmQIexRef1NDialog& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQIexRef1NDialog** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQIexRef1NDialog& rst);
};
#endif

#endif

