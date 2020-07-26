/**
	* \file WznmCFile.h
	* Dbs and XML wrapper for table TblWznmCFile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WZNMCFILE_H
#define WZNMCFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWznmCFile: C++ wrapper for table TblWznmCFile
	*/
class TblWznmCFile {

public:
	TblWznmCFile();
	virtual ~TblWznmCFile();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWznmCFile: C++ wrapper for table TblWznmCFile (MySQL database)
	*/
class MyTblWznmCFile : public TblWznmCFile, public Sbecore::MyTable {

public:
	MyTblWznmCFile();
	~MyTblWznmCFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtGetNewRef;

public:
	Sbecore::ubigint getNewRef();
};
#endif

#if defined(SBECORE_PG)
/**
	* PgTblWznmCFile: C++ wrapper for table TblWznmCFile (PgSQL database)
	*/
class PgTblWznmCFile : public TblWznmCFile, public Sbecore::PgTable {

public:
	PgTblWznmCFile();
	~PgTblWznmCFile();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif

