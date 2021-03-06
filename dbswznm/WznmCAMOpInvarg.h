/**
	* \file WznmCAMOpInvarg.h
	* Dbs and XML wrapper for table TblWznmCAMOpInvarg (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZNMCAMOPINVARG_H
#define WZNMCAMOPINVARG_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWznmCAMOpInvarg: C++ wrapper for table TblWznmCAMOpInvarg
	*/
class TblWznmCAMOpInvarg {

public:
	TblWznmCAMOpInvarg();
	virtual ~TblWznmCAMOpInvarg();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWznmCAMOpInvarg: C++ wrapper for table TblWznmCAMOpInvarg (MySQL database)
	*/
class MyTblWznmCAMOpInvarg : public TblWznmCAMOpInvarg, public Sbecore::MyTable {

public:
	MyTblWznmCAMOpInvarg();
	~MyTblWznmCAMOpInvarg();

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
	* PgTblWznmCAMOpInvarg: C++ wrapper for table TblWznmCAMOpInvarg (PgSQL database)
	*/
class PgTblWznmCAMOpInvarg : public TblWznmCAMOpInvarg, public Sbecore::PgTable {

public:
	PgTblWznmCAMOpInvarg();
	~PgTblWznmCAMOpInvarg();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif
