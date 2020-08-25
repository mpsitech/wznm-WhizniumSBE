/**
	* \file WznmCAMOpRetval.h
	* Dbs and XML wrapper for table TblWznmCAMOpRetval (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMCAMOPRETVAL_H
#define WZNMCAMOPRETVAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWznmCAMOpRetval: C++ wrapper for table TblWznmCAMOpRetval
	*/
class TblWznmCAMOpRetval {

public:
	TblWznmCAMOpRetval();
	virtual ~TblWznmCAMOpRetval();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWznmCAMOpRetval: C++ wrapper for table TblWznmCAMOpRetval (MySQL database)
	*/
class MyTblWznmCAMOpRetval : public TblWznmCAMOpRetval, public Sbecore::MyTable {

public:
	MyTblWznmCAMOpRetval();
	~MyTblWznmCAMOpRetval();

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
	* PgTblWznmCAMOpRetval: C++ wrapper for table TblWznmCAMOpRetval (PgSQL database)
	*/
class PgTblWznmCAMOpRetval : public TblWznmCAMOpRetval, public Sbecore::PgTable {

public:
	PgTblWznmCAMOpRetval();
	~PgTblWznmCAMOpRetval();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif

