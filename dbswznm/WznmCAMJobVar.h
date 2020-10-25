/**
	* \file WznmCAMJobVar.h
	* Dbs and XML wrapper for table TblWznmCAMJobVar (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef WZNMCAMJOBVAR_H
#define WZNMCAMJOBVAR_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWznmCAMJobVar: C++ wrapper for table TblWznmCAMJobVar
	*/
class TblWznmCAMJobVar {

public:
	TblWznmCAMJobVar();
	virtual ~TblWznmCAMJobVar();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWznmCAMJobVar: C++ wrapper for table TblWznmCAMJobVar (MySQL database)
	*/
class MyTblWznmCAMJobVar : public TblWznmCAMJobVar, public Sbecore::MyTable {

public:
	MyTblWznmCAMJobVar();
	~MyTblWznmCAMJobVar();

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
	* PgTblWznmCAMJobVar: C++ wrapper for table TblWznmCAMJobVar (PgSQL database)
	*/
class PgTblWznmCAMJobVar : public TblWznmCAMJobVar, public Sbecore::PgTable {

public:
	PgTblWznmCAMJobVar();
	~PgTblWznmCAMJobVar();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif

