/**
	* \file SessWznm_blks.cpp
	* job handler for job SessWznm (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class SessWznm::StatShr
 ******************************************************************************/

SessWznm::StatShr::StatShr(
			const ubigint jrefCrdnav
		) :
			Block()
		{
	this->jrefCrdnav = jrefCrdnav;

	mask = {JREFCRDNAV};
};

void SessWznm::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrSessWznm";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrSessWznm";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefCrdnav", Scr::scramble(jrefCrdnav));
	xmlTextWriterEndElement(wr);
};

set<uint> SessWznm::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefCrdnav == comp->jrefCrdnav) insert(items, JREFCRDNAV);

	return(items);
};

set<uint> SessWznm::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFCRDNAV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class SessWznm::DpchEngData
 ******************************************************************************/

SessWznm::DpchEngData::DpchEngData(
			const ubigint jref
			, Feed* feedFEnsSec
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWznm(VecWznmVDpch::DPCHENGSESSWZNMDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, FEEDFENSSEC, STATSHR};
	else this->mask = mask;

	if (find(this->mask, FEEDFENSSEC) && feedFEnsSec) this->feedFEnsSec = *feedFEnsSec;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string SessWznm::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(FEEDFENSSEC)) ss.push_back("feedFEnsSec");
	if (has(STATSHR)) ss.push_back("statshr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void SessWznm::DpchEngData::merge(
			DpchEngWznm* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(FEEDFENSSEC)) {feedFEnsSec = src->feedFEnsSec; add(FEEDFENSSEC);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
};

void SessWznm::DpchEngData::writeXML(
			const uint ixWznmVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngSessWznmData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wznm");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(FEEDFENSSEC)) feedFEnsSec.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

