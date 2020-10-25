/**
	* \file WznmAMStateTrig_vecs.cpp
	* database access for table TblWznmAMStateTrig (implementation of vectors)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWznmAMStateTrig::VecVType
 ******************************************************************************/

uint TblWznmAMStateTrig::VecVType::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "evt") return EVT;
	if (s == "sgeeq") return SGEEQ;
	if (s == "jobex") return JOBEX;
	if (s == "jobnex") return JOBNEX;
	if (s == "confacc") return CONFACC;
	if (s == "confdny") return CONFDNY;
	if (s == "dpchrcv") return DPCHRCV;
	if (s == "cust") return CUST;

	return(0);
};

string TblWznmAMStateTrig::VecVType::getSref(
			const uint ix
		) {
	if (ix == EVT) return("evt");
	if (ix == SGEEQ) return("sgeeq");
	if (ix == JOBEX) return("jobex");
	if (ix == JOBNEX) return("jobnex");
	if (ix == CONFACC) return("confacc");
	if (ix == CONFDNY) return("confdny");
	if (ix == DPCHRCV) return("dpchrcv");
	if (ix == CUST) return("cust");

	return("");
};

string TblWznmAMStateTrig::VecVType::getTitle(
			const uint ix
			, const uint ixWznmVLocale
		) {
	if (ixWznmVLocale == 1) {
		if (ix == EVT) return("local event");
		if (ix == SGEEQ) return("stage equals");
		if (ix == JOBEX) return("job exists");
		if (ix == JOBNEX) return("job doesn't exist");
		if (ix == CONFACC) return("confirmation received");
		if (ix == CONFDNY) return("denial received");
		if (ix == DPCHRCV) return("dispatch received");
		if (ix == CUST) return("custom condition");
		return(getSref(ix));
	};

	return("");
};

void TblWznmAMStateTrig::VecVType::fillFeed(
			const uint ixWznmVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 8; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWznmVLocale));
};

