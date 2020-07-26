/**
	* \file WznmQLibRef1NFile.h
	* Dbs and XML wrapper for table TblWznmQLibRef1NFile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMQLIBREF1NFILE_H
#define WZNMQLIBREF1NFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQLibRef1NFile: record of TblWznmQLibRef1NFile
	*/
class WznmQLibRef1NFile {

public:
	WznmQLibRef1NFile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQLibRef1NFile: recordset of TblWznmQLibRef1NFile
	*/
class ListWznmQLibRef1NFile {

public:
	ListWznmQLibRef1NFile();
	ListWznmQLibRef1NFile(const ListWznmQLibRef1NFile& src);
	~ListWznmQLibRef1NFile();

	void clear();
	unsigned int size() const;
	void append(WznmQLibRef1NFile* rec);

	ListWznmQLibRef1NFile& operator=(const ListWznmQLibRef1NFile& src);

public:
	std::vector<WznmQLibRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQLibRef1NFile: C++ wrapper for table TblWznmQLibRef1NFile
	*/
class TblWznmQLibRef1NFile {

public:
	TblWznmQLibRef1NFile();
	virtual ~TblWznmQLibRef1NFile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQLibRef1NFile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibRef1NFile& rst);

	virtual Sbecore::ubigint insertRec(WznmQLibRef1NFile* rec);
	Sbecore::ubigint insertNewRec(WznmQLibRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQLibRef1NFile& rst, WznmQLibRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQLibRef1NFile& rst);
	virtual void updateRec(WznmQLibRef1NFile* rec);
	virtual void updateRst(ListWznmQLibRef1NFile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQLibRef1NFile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibRef1NFile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQLibRef1NFile: C++ wrapper for table TblWznmQLibRef1NFile (MySQL database)
	*/
class MyTblWznmQLibRef1NFile : public TblWznmQLibRef1NFile, public Sbecore::MyTable {

public:
	MyTblWznmQLibRef1NFile();
	~MyTblWznmQLibRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLibRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibRef1NFile& rst);

	Sbecore::ubigint insertRec(WznmQLibRef1NFile* rec);
	void insertRst(ListWznmQLibRef1NFile& rst);
	void updateRec(WznmQLibRef1NFile* rec);
	void updateRst(ListWznmQLibRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLibRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibRef1NFile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQLibRef1NFile: C++ wrapper for table TblWznmQLibRef1NFile (PgSQL database)
	*/
class PgTblWznmQLibRef1NFile : public TblWznmQLibRef1NFile, public Sbecore::PgTable {

public:
	PgTblWznmQLibRef1NFile();
	~PgTblWznmQLibRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQLibRef1NFile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQLibRef1NFile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQLibRef1NFile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQLibRef1NFile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQLibRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQLibRef1NFile& rst);

	Sbecore::ubigint insertRec(WznmQLibRef1NFile* rec);
	void insertRst(ListWznmQLibRef1NFile& rst);
	void updateRec(WznmQLibRef1NFile* rec);
	void updateRst(ListWznmQLibRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQLibRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQLibRef1NFile& rst);
};
#endif

#endif

