/**
	* \file WznmCAMOppackInvarg.h
	* Dbs and XML wrapper for table TblWznmCAMOppackInvarg (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef WZNMCAMOPPACKINVARG_H
#define WZNMCAMOPPACKINVARG_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWznmCAMOppackInvarg: C++ wrapper for table TblWznmCAMOppackInvarg
	*/
class TblWznmCAMOppackInvarg {

public:
	TblWznmCAMOppackInvarg();
	virtual ~TblWznmCAMOppackInvarg();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWznmCAMOppackInvarg: C++ wrapper for table TblWznmCAMOppackInvarg (MySQL database)
	*/
class MyTblWznmCAMOppackInvarg : public TblWznmCAMOppackInvarg, public Sbecore::MyTable {

public:
	MyTblWznmCAMOppackInvarg();
	~MyTblWznmCAMOppackInvarg();

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
	* PgTblWznmCAMOppackInvarg: C++ wrapper for table TblWznmCAMOppackInvarg (PgSQL database)
	*/
class PgTblWznmCAMOppackInvarg : public TblWznmCAMOppackInvarg, public Sbecore::PgTable {

public:
	PgTblWznmCAMOppackInvarg();
	~PgTblWznmCAMOppackInvarg();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif

