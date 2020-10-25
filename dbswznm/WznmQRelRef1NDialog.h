/**
	* \file WznmQRelRef1NDialog.h
	* Dbs and XML wrapper for table TblWznmQRelRef1NDialog (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQRELREF1NDIALOG_H
#define WZNMQRELREF1NDIALOG_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQRelRef1NDialog: record of TblWznmQRelRef1NDialog
	*/
class WznmQRelRef1NDialog {

public:
	WznmQRelRef1NDialog(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQRelRef1NDialog: recordset of TblWznmQRelRef1NDialog
	*/
class ListWznmQRelRef1NDialog {

public:
	ListWznmQRelRef1NDialog();
	ListWznmQRelRef1NDialog(const ListWznmQRelRef1NDialog& src);
	~ListWznmQRelRef1NDialog();

	void clear();
	unsigned int size() const;
	void append(WznmQRelRef1NDialog* rec);

	ListWznmQRelRef1NDialog& operator=(const ListWznmQRelRef1NDialog& src);

public:
	std::vector<WznmQRelRef1NDialog*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQRelRef1NDialog: C++ wrapper for table TblWznmQRelRef1NDialog
	*/
class TblWznmQRelRef1NDialog {

public:
	TblWznmQRelRef1NDialog();
	virtual ~TblWznmQRelRef1NDialog();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQRelRef1NDialog** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelRef1NDialog& rst);

	virtual Sbecore::ubigint insertRec(WznmQRelRef1NDialog* rec);
	Sbecore::ubigint insertNewRec(WznmQRelRef1NDialog** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQRelRef1NDialog& rst, WznmQRelRef1NDialog** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQRelRef1NDialog& rst);
	virtual void updateRec(WznmQRelRef1NDialog* rec);
	virtual void updateRst(ListWznmQRelRef1NDialog& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQRelRef1NDialog** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelRef1NDialog& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQRelRef1NDialog: C++ wrapper for table TblWznmQRelRef1NDialog (MySQL database)
	*/
class MyTblWznmQRelRef1NDialog : public TblWznmQRelRef1NDialog, public Sbecore::MyTable {

public:
	MyTblWznmQRelRef1NDialog();
	~MyTblWznmQRelRef1NDialog();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRelRef1NDialog** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelRef1NDialog& rst);

	Sbecore::ubigint insertRec(WznmQRelRef1NDialog* rec);
	void insertRst(ListWznmQRelRef1NDialog& rst);
	void updateRec(WznmQRelRef1NDialog* rec);
	void updateRst(ListWznmQRelRef1NDialog& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRelRef1NDialog** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelRef1NDialog& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQRelRef1NDialog: C++ wrapper for table TblWznmQRelRef1NDialog (PgSQL database)
	*/
class PgTblWznmQRelRef1NDialog : public TblWznmQRelRef1NDialog, public Sbecore::PgTable {

public:
	PgTblWznmQRelRef1NDialog();
	~PgTblWznmQRelRef1NDialog();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQRelRef1NDialog** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQRelRef1NDialog& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQRelRef1NDialog** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQRelRef1NDialog& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQRelRef1NDialog** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQRelRef1NDialog& rst);

	Sbecore::ubigint insertRec(WznmQRelRef1NDialog* rec);
	void insertRst(ListWznmQRelRef1NDialog& rst);
	void updateRec(WznmQRelRef1NDialog* rec);
	void updateRst(ListWznmQRelRef1NDialog& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQRelRef1NDialog** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQRelRef1NDialog& rst);
};
#endif

#endif

