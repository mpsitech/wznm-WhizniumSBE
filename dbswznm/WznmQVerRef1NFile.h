/**
	* \file WznmQVerRef1NFile.h
	* Dbs and XML wrapper for table TblWznmQVerRef1NFile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMQVERREF1NFILE_H
#define WZNMQVERREF1NFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQVerRef1NFile: record of TblWznmQVerRef1NFile
	*/
class WznmQVerRef1NFile {

public:
	WznmQVerRef1NFile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQVerRef1NFile: recordset of TblWznmQVerRef1NFile
	*/
class ListWznmQVerRef1NFile {

public:
	ListWznmQVerRef1NFile();
	ListWznmQVerRef1NFile(const ListWznmQVerRef1NFile& src);
	~ListWznmQVerRef1NFile();

	void clear();
	unsigned int size() const;
	void append(WznmQVerRef1NFile* rec);

	ListWznmQVerRef1NFile& operator=(const ListWznmQVerRef1NFile& src);

public:
	std::vector<WznmQVerRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQVerRef1NFile: C++ wrapper for table TblWznmQVerRef1NFile
	*/
class TblWznmQVerRef1NFile {

public:
	TblWznmQVerRef1NFile();
	virtual ~TblWznmQVerRef1NFile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQVerRef1NFile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerRef1NFile& rst);

	virtual Sbecore::ubigint insertRec(WznmQVerRef1NFile* rec);
	Sbecore::ubigint insertNewRec(WznmQVerRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQVerRef1NFile& rst, WznmQVerRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQVerRef1NFile& rst);
	virtual void updateRec(WznmQVerRef1NFile* rec);
	virtual void updateRst(ListWznmQVerRef1NFile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQVerRef1NFile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerRef1NFile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQVerRef1NFile: C++ wrapper for table TblWznmQVerRef1NFile (MySQL database)
	*/
class MyTblWznmQVerRef1NFile : public TblWznmQVerRef1NFile, public Sbecore::MyTable {

public:
	MyTblWznmQVerRef1NFile();
	~MyTblWznmQVerRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerRef1NFile& rst);

	Sbecore::ubigint insertRec(WznmQVerRef1NFile* rec);
	void insertRst(ListWznmQVerRef1NFile& rst);
	void updateRec(WznmQVerRef1NFile* rec);
	void updateRst(ListWznmQVerRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerRef1NFile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQVerRef1NFile: C++ wrapper for table TblWznmQVerRef1NFile (PgSQL database)
	*/
class PgTblWznmQVerRef1NFile : public TblWznmQVerRef1NFile, public Sbecore::PgTable {

public:
	PgTblWznmQVerRef1NFile();
	~PgTblWznmQVerRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQVerRef1NFile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQVerRef1NFile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQVerRef1NFile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQVerRef1NFile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQVerRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQVerRef1NFile& rst);

	Sbecore::ubigint insertRec(WznmQVerRef1NFile* rec);
	void insertRst(ListWznmQVerRef1NFile& rst);
	void updateRec(WznmQVerRef1NFile* rec);
	void updateRst(ListWznmQVerRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQVerRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQVerRef1NFile& rst);
};
#endif

#endif

