/**
	* \file WznmCtpWrstkit.h
	* Wznm operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WZNMCTPWRSTKIT_H
#define WZNMCTPWRSTKIT_H

#include "WznmCtpWrstkit_blks.h"

// IP include.cust --- IBEGIN
#include "IexWznmBui.h"
#include "IexWznmDbs.h"
#include "IexWznmIex.h"
// IP include.cust --- IEND

namespace WznmCtpWrstkit {

	// IP cust --- IBEGIN
	void addIJMModules(DbsWznm* dbswznm, IexWznmBui::ImeitemIMModule* mdl, const std::string& sref, const std::string& osrefWznmKTaggrp, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	void addIAMTableTitles(DbsWznm* dbswznm, IexWznmDbs::ImeitemIMTable* tbl, const std::string& sref, const Sbecore::uint ixVType, const std::string& osrefWznmKTaggrp, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	void addIAMTablecolTitles(DbsWznm* dbswznm, IexWznmDbs::ImeitemIMTablecol* tco, const std::string& sref, const Sbecore::uint ixVType, const std::string& osrefWznmKTaggrp, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	void addIAMVectorTitles(DbsWznm* dbswznm, IexWznmDbs::ImeitemIMVector2* vec, const std::string& sref, const Sbecore::uint ixVType, const std::string& osrefWznmKTaggrp, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	void addIJMVectoritems(DbsWznm* dbswznm, IexWznmDbs::ImeitemIMVectoritem2* vit, const std::string& sref, const std::string& osrefWznmKTaggrp, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	void addIAMRelationTitles(DbsWznm* dbswznm, IexWznmDbs::ImeitemIMRelation* rel, const std::string& sref, const Sbecore::uint ixVType, const std::string& osrefWznmKTaggrp, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	void addIJMImpexpcplxTitles(DbsWznm* dbswznm, IexWznmIex::ImeitemIMImpexpcplx* iex, const std::string& sref, const Sbecore::ubigint refLcl, const std::vector<Sbecore::ubigint>& refsLcl, ListWznmMLocale& lcls);
	// IP cust --- IEND
};

#endif
