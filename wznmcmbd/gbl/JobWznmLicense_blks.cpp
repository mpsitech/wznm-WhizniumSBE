/**
	* \file JobWznmLicense_blks.cpp
	* job handler for job JobWznmLicense (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWznmLicense::VecVSge
 ******************************************************************************/

uint JobWznmLicense::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "conn") return CONN;
	if (s == "conerr") return CONERR;
	if (s == "auth") return AUTH;
	if (s == "auterr") return AUTERR;
	if (s == "sync") return SYNC;
	if (s == "sncerr") return SNCERR;

	return(0);
};

string JobWznmLicense::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CONN) return("conn");
	if (ix == CONERR) return("conerr");
	if (ix == AUTH) return("auth");
	if (ix == AUTERR) return("auterr");
	if (ix == SYNC) return("sync");
	if (ix == SNCERR) return("sncerr");

	return("");
};

void JobWznmLicense::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 7; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWznmLicense::Stg
 ******************************************************************************/

JobWznmLicense::Stg::Stg(
			const string& engip
			, const uint engport
			, const string& username
			, const string& password
			, const string& licenseBase
			, const string& licenseUa
			, const string& licenseDds
			, const string& lastAttempt
			, const string& lastSuccess
			, const string& lastSync
		) :
			Block()
			, engip(engip)
			, engport(engport)
			, username(username)
			, password(password)
			, licenseBase(licenseBase)
			, licenseUa(licenseUa)
			, licenseDds(licenseDds)
			, lastAttempt(lastAttempt)
			, lastSuccess(lastSuccess)
			, lastSync(lastSync)
		{
	mask = {ENGIP, ENGPORT, USERNAME, PASSWORD, LICENSEBASE, LICENSEUA, LICENSEDDS, LASTATTEMPT, LASTSUCCESS, LASTSYNC};
};

bool JobWznmLicense::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWznmLicense");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWznmLicense";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engip", engip)) add(ENGIP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engport", engport)) add(ENGPORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "licenseBase", licenseBase)) add(LICENSEBASE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "licenseUa", licenseUa)) add(LICENSEUA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "licenseDds", licenseDds)) add(LICENSEDDS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "lastAttempt", lastAttempt)) add(LASTATTEMPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "lastSuccess", lastSuccess)) add(LASTSUCCESS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "lastSync", lastSync)) add(LASTSYNC);
	};

	return basefound;
};

void JobWznmLicense::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWznmLicense";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWznmLicense";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "engip", engip);
		writeUintAttr(wr, itemtag, "sref", "engport", engport);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "licenseBase", licenseBase);
		writeStringAttr(wr, itemtag, "sref", "licenseUa", licenseUa);
		writeStringAttr(wr, itemtag, "sref", "licenseDds", licenseDds);
		writeStringAttr(wr, itemtag, "sref", "lastAttempt", lastAttempt);
		writeStringAttr(wr, itemtag, "sref", "lastSuccess", lastSuccess);
		writeStringAttr(wr, itemtag, "sref", "lastSync", lastSync);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWznmLicense::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (engip == comp->engip) insert(items, ENGIP);
	if (engport == comp->engport) insert(items, ENGPORT);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (licenseBase == comp->licenseBase) insert(items, LICENSEBASE);
	if (licenseUa == comp->licenseUa) insert(items, LICENSEUA);
	if (licenseDds == comp->licenseDds) insert(items, LICENSEDDS);
	if (lastAttempt == comp->lastAttempt) insert(items, LASTATTEMPT);
	if (lastSuccess == comp->lastSuccess) insert(items, LASTSUCCESS);
	if (lastSync == comp->lastSync) insert(items, LASTSYNC);

	return(items);
};

set<uint> JobWznmLicense::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ENGIP, ENGPORT, USERNAME, PASSWORD, LICENSEBASE, LICENSEUA, LICENSEDDS, LASTATTEMPT, LASTSUCCESS, LASTSYNC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
