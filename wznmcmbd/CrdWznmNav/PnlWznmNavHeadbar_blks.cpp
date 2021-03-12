/**
	* \file PnlWznmNavHeadbar_blks.cpp
	* job handler for job PnlWznmNavHeadbar (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWznmNavHeadbar::StatShr
 ******************************************************************************/

PnlWznmNavHeadbar::StatShr::StatShr(
			const bool MenCrdAvail
		) :
			Block()
		{
	this->MenCrdAvail = MenCrdAvail;

	mask = {MENCRDAVAIL};
};

void PnlWznmNavHeadbar::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["MenCrdAvail"] = MenCrdAvail;
};

void PnlWznmNavHeadbar::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWznmNavHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWznmNavHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "MenCrdAvail", MenCrdAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWznmNavHeadbar::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (MenCrdAvail == comp->MenCrdAvail) insert(items, MENCRDAVAIL);

	return(items);
};

set<uint> PnlWznmNavHeadbar::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {MENCRDAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWznmNavHeadbar::StgInf
 ******************************************************************************/

void PnlWznmNavHeadbar::StgInf::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StgInfWznmNavHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["MenAppCptwidth"] = "120";
		me["MenAppWidth"] = "204";
		me["MenSesCptwidth"] = "66";
		me["MenSesWidth"] = "323";
		me["MenCrdCptwidth"] = "100";
		me["MenCrdWidth"] = "197";
	};
};

void PnlWznmNavHeadbar::StgInf::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgInfWznmNavHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemInfWznmNavHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenAppCptwidth", "120");
			writeStringAttr(wr, itemtag, "sref", "MenAppWidth", "204");
			writeStringAttr(wr, itemtag, "sref", "MenSesCptwidth", "66");
			writeStringAttr(wr, itemtag, "sref", "MenSesWidth", "323");
			writeStringAttr(wr, itemtag, "sref", "MenCrdCptwidth", "100");
			writeStringAttr(wr, itemtag, "sref", "MenCrdWidth", "197");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavHeadbar::Tag
 ******************************************************************************/

void PnlWznmNavHeadbar::Tag::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavHeadbar";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWznmVLocale == VecWznmVLocale::ENUS) {
		me["MenApp"] = "WhizniumSBE";
	};
	me["MenSes"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::SESS, ixWznmVLocale));
	me["MenCrd"] = StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::NAV, ixWznmVLocale));
};

void PnlWznmNavHeadbar::Tag::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWznmNavHeadbar";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWznmNavHeadbar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MenApp", "WhizniumSBE");
		};
		writeStringAttr(wr, itemtag, "sref", "MenSes", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::SESS, ixWznmVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MenCrd", StrMod::cap(VecWznmVTag::getTitle(VecWznmVTag::NAV, ixWznmVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWznmNavHeadbar::DpchEngData
 ******************************************************************************/

PnlWznmNavHeadbar::DpchEngData::DpchEngData(
			const ubigint jref
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGWZNMNAVHEADBARDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, STATSHR, STGINF, TAG};
	else this->mask = mask;

	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWznmNavHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWznmNavHeadbar::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(STGINF)) add(STGINF);
	if (src->has(TAG)) add(TAG);
};

void PnlWznmNavHeadbar::DpchEngData::writeJSON(
			const uint ixWznmVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWznmNavHeadbarData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(STGINF)) StgInf::writeJSON(ixWznmVLocale, me);
	if (has(TAG)) Tag::writeJSON(ixWznmVLocale, me);
};

void PnlWznmNavHeadbar::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWznmNavHeadbarData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(STGINF)) StgInf::writeXML(ixWznmVLocale, wr);
		if (has(TAG)) Tag::writeXML(ixWznmVLocale, wr);
	xmlTextWriterEndElement(wr);
};
