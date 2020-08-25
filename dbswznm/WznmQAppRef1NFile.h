/**
	* \file WznmQAppRef1NFile.h
	* Dbs and XML wrapper for table TblWznmQAppRef1NFile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMQAPPREF1NFILE_H
#define WZNMQAPPREF1NFILE_H

#include <sbecore/Xmlio.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* WznmQAppRef1NFile: record of TblWznmQAppRef1NFile
	*/
class WznmQAppRef1NFile {

public:
	WznmQAppRef1NFile(const Sbecore::ubigint qref = 0, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");

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
	* ListWznmQAppRef1NFile: recordset of TblWznmQAppRef1NFile
	*/
class ListWznmQAppRef1NFile {

public:
	ListWznmQAppRef1NFile();
	ListWznmQAppRef1NFile(const ListWznmQAppRef1NFile& src);
	~ListWznmQAppRef1NFile();

	void clear();
	unsigned int size() const;
	void append(WznmQAppRef1NFile* rec);

	ListWznmQAppRef1NFile& operator=(const ListWznmQAppRef1NFile& src);

public:
	std::vector<WznmQAppRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, std::string difftag = "");
};

/**
	* TblWznmQAppRef1NFile: C++ wrapper for table TblWznmQAppRef1NFile
	*/
class TblWznmQAppRef1NFile {

public:
	TblWznmQAppRef1NFile();
	virtual ~TblWznmQAppRef1NFile();

public:
	virtual bool loadRecBySQL(const std::string& sqlstr, WznmQAppRef1NFile** rec);
	virtual Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQAppRef1NFile& rst);

	virtual Sbecore::ubigint insertRec(WznmQAppRef1NFile* rec);
	Sbecore::ubigint insertNewRec(WznmQAppRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	Sbecore::ubigint appendNewRecToRst(ListWznmQAppRef1NFile& rst, WznmQAppRef1NFile** rec = NULL, const Sbecore::ubigint jref = 0, const Sbecore::uint jnum = 0, const Sbecore::ubigint ref = 0, const std::string stubRef = "");
	virtual void insertRst(ListWznmQAppRef1NFile& rst);
	virtual void updateRec(WznmQAppRef1NFile* rec);
	virtual void updateRst(ListWznmQAppRef1NFile& rst);
	virtual void removeRecByQref(Sbecore::ubigint qref);
	virtual void removeRstByJref(Sbecore::ubigint jref);

	virtual bool loadRecByQref(Sbecore::ubigint qref, WznmQAppRef1NFile** rec);
	virtual Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQAppRef1NFile& rst);
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyWznmQAppRef1NFile: C++ wrapper for table TblWznmQAppRef1NFile (MySQL database)
	*/
class MyTblWznmQAppRef1NFile : public TblWznmQAppRef1NFile, public Sbecore::MyTable {

public:
	MyTblWznmQAppRef1NFile();
	~MyTblWznmQAppRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQAppRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQAppRef1NFile& rst);

	Sbecore::ubigint insertRec(WznmQAppRef1NFile* rec);
	void insertRst(ListWznmQAppRef1NFile& rst);
	void updateRec(WznmQAppRef1NFile* rec);
	void updateRst(ListWznmQAppRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQAppRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQAppRef1NFile& rst);
};
#endif

#if defined(SBECORE_PG)
/**
	* PgWznmQAppRef1NFile: C++ wrapper for table TblWznmQAppRef1NFile (PgSQL database)
	*/
class PgTblWznmQAppRef1NFile : public TblWznmQAppRef1NFile, public Sbecore::PgTable {

public:
	PgTblWznmQAppRef1NFile();
	~PgTblWznmQAppRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, WznmQAppRef1NFile** rec);
	Sbecore::ubigint loadRst(PGresult* res, const bool append, ListWznmQAppRef1NFile& rst);
	bool loadRecByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, WznmQAppRef1NFile** rec);
	Sbecore::ubigint loadRstByStmt(const std::string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListWznmQAppRef1NFile& rst);

public:
	bool loadRecBySQL(const std::string& sqlstr, WznmQAppRef1NFile** rec);
	Sbecore::ubigint loadRstBySQL(const std::string& sqlstr, const bool append, ListWznmQAppRef1NFile& rst);

	Sbecore::ubigint insertRec(WznmQAppRef1NFile* rec);
	void insertRst(ListWznmQAppRef1NFile& rst);
	void updateRec(WznmQAppRef1NFile* rec);
	void updateRst(ListWznmQAppRef1NFile& rst);
	void removeRecByQref(Sbecore::ubigint qref);
	void removeRstByJref(Sbecore::ubigint jref);

	bool loadRecByQref(Sbecore::ubigint qref, WznmQAppRef1NFile** rec);
	Sbecore::ubigint loadRstByJref(Sbecore::ubigint jref, const bool append, ListWznmQAppRef1NFile& rst);
};
#endif

#endif

