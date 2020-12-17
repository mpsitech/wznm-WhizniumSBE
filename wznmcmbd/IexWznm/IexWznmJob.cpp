/**
	* \file IexWznmJob.cpp
	* data blocks and readers/writers for import/export complex IexWznmJob (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#include "IexWznmJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWznmJob::VecVIme
 ******************************************************************************/

uint IexWznmJob::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamblockitem") return IMEIAMBLOCKITEM;
	if (s == "imeicamblockitem") return IMEICAMBLOCKITEM;
	if (s == "imeijamblockitem") return IMEIJAMBLOCKITEM;
	if (s == "imeimblock") return IMEIMBLOCK;
	if (s == "imeimcapability") return IMEIMCAPABILITY;
	if (s == "imeimjob") return IMEIMJOB;
	if (s == "imeirmcapabilityuniversal") return IMEIRMCAPABILITYUNIVERSAL;

	return(0);
};

string IexWznmJob::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMBLOCKITEM) return("ImeIAMBlockItem");
	if (ix == IMEICAMBLOCKITEM) return("ImeICAMBlockItem");
	if (ix == IMEIJAMBLOCKITEM) return("ImeIJAMBlockItem");
	if (ix == IMEIMBLOCK) return("ImeIMBlock");
	if (ix == IMEIMCAPABILITY) return("ImeIMCapability");
	if (ix == IMEIMJOB) return("ImeIMJob");
	if (ix == IMEIRMCAPABILITYUNIVERSAL) return("ImeIRMCapabilityUniversal");

	return("");
};

/******************************************************************************
 class IexWznmJob::ImeitemIRMCapabilityUniversal
 ******************************************************************************/

IexWznmJob::ImeitemIRMCapabilityUniversal::ImeitemIRMCapabilityUniversal(
			const string& srefUnvUref
			, const string& srefKKey
		) : WznmRMCapabilityUniversal() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefUnvUref = srefUnvUref;
	this->srefKKey = srefKKey;
};

IexWznmJob::ImeitemIRMCapabilityUniversal::ImeitemIRMCapabilityUniversal(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMCapabilityUniversal()
		{
	WznmRMCapabilityUniversal* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmcapabilityuniversal->loadRecByRef(ref, &rec)) {
		refWznmMCapability = rec->refWznmMCapability;
		unvUref = rec->unvUref;
		srefKKey = rec->srefKKey;

		delete rec;
	};
};

void IexWznmJob::ImeitemIRMCapabilityUniversal::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefUnvUref = txtrd.fields[0]; ixWIelValid += ImeIRMCapabilityUniversal::VecWIel::SREFUNVUREF;};
	if (txtrd.fields.size() > 1) {srefKKey = txtrd.fields[1]; ixWIelValid += ImeIRMCapabilityUniversal::VecWIel::SREFKKEY;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMCapabilityUniversal"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJob::ImeitemIRMCapabilityUniversal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefUnvUref", "unv", srefUnvUref)) ixWIelValid += ImeIRMCapabilityUniversal::VecWIel::SREFUNVUREF;
		if (extractStringUclc(docctx, basexpath, "srefKKey", "key", srefKKey)) ixWIelValid += ImeIRMCapabilityUniversal::VecWIel::SREFKKEY;
	};
};

void IexWznmJob::ImeitemIRMCapabilityUniversal::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefUnvUref << "\t" << srefKKey << endl;
};

void IexWznmJob::ImeitemIRMCapabilityUniversal::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","unv","key"};
	else tags = {"ImeitemIRMCapabilityUniversal","srefUnvUref","srefKKey"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefUnvUref);
		writeString(wr, tags[2], srefKKey);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJob::ImeIRMCapabilityUniversal::VecWIel
 ******************************************************************************/

uint IexWznmJob::ImeIRMCapabilityUniversal::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefunvuref") ix |= SREFUNVUREF;
		else if (ss[i] == "srefkkey") ix |= SREFKKEY;
	};

	return(ix);
};

void IexWznmJob::ImeIRMCapabilityUniversal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFKKEY); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJob::ImeIRMCapabilityUniversal::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFUNVUREF) ss.push_back("srefUnvUref");
	if (ix & SREFKKEY) ss.push_back("srefKKey");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJob::ImeIRMCapabilityUniversal
 ******************************************************************************/

IexWznmJob::ImeIRMCapabilityUniversal::ImeIRMCapabilityUniversal() {
};

IexWznmJob::ImeIRMCapabilityUniversal::~ImeIRMCapabilityUniversal() {
	clear();
};

void IexWznmJob::ImeIRMCapabilityUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJob::ImeIRMCapabilityUniversal::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJob::ImeitemIRMCapabilityUniversal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJob::ImeitemIRMCapabilityUniversal();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCapabilityUniversal"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMCapabilityUniversal"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMCAPABILITYUNIVERSAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCapabilityUniversal"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCapabilityUniversal"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJob::ImeIRMCapabilityUniversal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJob::ImeitemIRMCapabilityUniversal* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMCapabilityUniversal");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMCapabilityUniversal", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMCapabilityUniversal";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJob::ImeitemIRMCapabilityUniversal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJob::ImeIRMCapabilityUniversal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMCapabilityUniversal." << StrMod::replaceChar(ImeIRMCapabilityUniversal::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMCapabilityUniversal.end" << endl;
	};
};

void IexWznmJob::ImeIRMCapabilityUniversal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMCapabilityUniversal");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJob::ImeitemIMCapability
 ******************************************************************************/

IexWznmJob::ImeitemIMCapability::ImeitemIMCapability(
			const string& sref
		) : WznmMCapability() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
};

IexWznmJob::ImeitemIMCapability::ImeitemIMCapability(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMCapability()
		{
	WznmMCapability* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmcapability->loadRecByRef(ref, &rec)) {
		sref = rec->sref;

		delete rec;
	};
};

void IexWznmJob::ImeitemIMCapability::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMCapability::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMCAPABILITYUNIVERSAL)) {
					imeirmcapabilityuniversal.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCapability"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJob::ImeitemIMCapability::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCapability::VecWIel::SREF;
		imeirmcapabilityuniversal.readXML(docctx, basexpath);
	};
};

void IexWznmJob::ImeitemIMCapability::writeTxt(
			fstream& outfile
		) {
	outfile << sref << endl;
	imeirmcapabilityuniversal.writeTxt(outfile);
};

void IexWznmJob::ImeitemIMCapability::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf"};
	else tags = {"ImeitemIMCapability","sref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		imeirmcapabilityuniversal.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJob::ImeIMCapability::VecWIel
 ******************************************************************************/

uint IexWznmJob::ImeIMCapability::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
	};

	return(ix);
};

void IexWznmJob::ImeIMCapability::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJob::ImeIMCapability::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJob::ImeIMCapability
 ******************************************************************************/

IexWznmJob::ImeIMCapability::ImeIMCapability() {
};

IexWznmJob::ImeIMCapability::~ImeIMCapability() {
	clear();
};

void IexWznmJob::ImeIMCapability::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJob::ImeIMCapability::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJob::ImeitemIMCapability* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmJob::ImeitemIMCapability();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCapability"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCAPABILITY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCapability"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCapability"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJob::ImeIMCapability::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJob::ImeitemIMCapability* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMCapability");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMCapability", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMCapability";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJob::ImeitemIMCapability();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJob::ImeIMCapability::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMCapability." << StrMod::replaceChar(ImeIMCapability::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMCapability.end" << endl;
	};
};

void IexWznmJob::ImeIMCapability::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMCapability");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJob::ImeitemIJAMBlockItem
 ******************************************************************************/

IexWznmJob::ImeitemIJAMBlockItem::ImeitemIJAMBlockItem(
			const string& Defval
			, const string& srefRefWznmMVectoritem
		) : WznmJAMBlockItem() {
	lineno = 0;
	ixWIelValid = 0;

	this->Defval = Defval;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
};

IexWznmJob::ImeitemIJAMBlockItem::ImeitemIJAMBlockItem(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJAMBlockItem()
		{
	WznmJAMBlockItem* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjamblockitem->loadRecByRef(ref, &rec)) {
		refWznmAMBlockItem = rec->refWznmAMBlockItem;
		Defval = rec->Defval;
		refWznmMVectoritem = rec->refWznmMVectoritem;

		delete rec;
	};
};

void IexWznmJob::ImeitemIJAMBlockItem::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Defval = txtrd.fields[0]; ixWIelValid += ImeIJAMBlockItem::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 1) {srefRefWznmMVectoritem = txtrd.fields[1]; ixWIelValid += ImeIJAMBlockItem::VecWIel::SREFREFWZNMMVECTORITEM;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAMBlockItem"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJob::ImeitemIJAMBlockItem::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIJAMBlockItem::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIJAMBlockItem::VecWIel::SREFREFWZNMMVECTORITEM;
	};
};

void IexWznmJob::ImeitemIJAMBlockItem::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << Defval << "\t" << srefRefWznmMVectoritem << endl;
};

void IexWznmJob::ImeitemIJAMBlockItem::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","dfv","vit"};
	else tags = {"ImeitemIJAMBlockItem","Defval","srefRefWznmMVectoritem"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Defval);
		writeString(wr, tags[2], srefRefWznmMVectoritem);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJob::ImeIJAMBlockItem::VecWIel
 ******************************************************************************/

uint IexWznmJob::ImeIJAMBlockItem::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
	};

	return(ix);
};

void IexWznmJob::ImeIJAMBlockItem::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMVECTORITEM); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJob::ImeIJAMBlockItem::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & DEFVAL) ss.push_back("Defval");
	if (ix & SREFREFWZNMMVECTORITEM) ss.push_back("srefRefWznmMVectoritem");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJob::ImeIJAMBlockItem
 ******************************************************************************/

IexWznmJob::ImeIJAMBlockItem::ImeIJAMBlockItem() {
};

IexWznmJob::ImeIJAMBlockItem::~ImeIJAMBlockItem() {
	clear();
};

void IexWznmJob::ImeIJAMBlockItem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJob::ImeIJAMBlockItem::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJob::ImeitemIJAMBlockItem* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmJob::ImeitemIJAMBlockItem();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAMBlockItem"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAMBlockItem"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJAMBLOCKITEM) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAMBlockItem"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAMBlockItem"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJob::ImeIJAMBlockItem::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJob::ImeitemIJAMBlockItem* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAMBlockItem");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAMBlockItem", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAMBlockItem";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJob::ImeitemIJAMBlockItem();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJob::ImeIJAMBlockItem::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJAMBlockItem." << StrMod::replaceChar(ImeIJAMBlockItem::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJAMBlockItem.end" << endl;
	};
};

void IexWznmJob::ImeIJAMBlockItem::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAMBlockItem");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJob::ImeitemIAMBlockItem
 ******************************************************************************/

IexWznmJob::ImeitemIAMBlockItem::ImeitemIAMBlockItem(
			const ubigint irefRefWznmCAMBlockItem
			, const uint ixVBasetype
			, const string& sref
			, const uint ixWznmVVartype
			, const string& srefRefWznmMVector
			, const string& Defval
			, const string& srefRefWznmMVectoritem
			, const string& Comment
		) : WznmAMBlockItem() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWznmCAMBlockItem = irefRefWznmCAMBlockItem;
	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->Defval = Defval;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
	this->Comment = Comment;
};

IexWznmJob::ImeitemIAMBlockItem::ImeitemIAMBlockItem(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMBlockItem()
		{
	WznmAMBlockItem* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamblockitem->loadRecByRef(ref, &rec)) {
		refWznmCAMBlockItem = rec->refWznmCAMBlockItem;
		blkRefWznmMBlock = rec->blkRefWznmMBlock;
		blkNum = rec->blkNum;
		ixVBasetype = rec->ixVBasetype;
		sref = rec->sref;
		ixWznmVVartype = rec->ixWznmVVartype;
		refWznmMVector = rec->refWznmMVector;
		refJ = rec->refJ;
		Defval = rec->Defval;
		refWznmMVectoritem = rec->refWznmMVectoritem;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmJob::ImeitemIAMBlockItem::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWznmCAMBlockItem = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIAMBlockItem::VecWIel::IREFREFWZNMCAMBLOCKITEM;};
	if (txtrd.fields.size() > 1) {srefIxVBasetype = txtrd.fields[1]; ixWIelValid += ImeIAMBlockItem::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIAMBlockItem::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {srefIxWznmVVartype = txtrd.fields[3]; ixWIelValid += ImeIAMBlockItem::VecWIel::SREFIXWZNMVVARTYPE;};
	if (txtrd.fields.size() > 4) {srefRefWznmMVector = txtrd.fields[4]; ixWIelValid += ImeIAMBlockItem::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 5) {Defval = txtrd.fields[5]; ixWIelValid += ImeIAMBlockItem::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 6) {srefRefWznmMVectoritem = txtrd.fields[6]; ixWIelValid += ImeIAMBlockItem::VecWIel::SREFREFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 7) {Comment = txtrd.fields[7]; ixWIelValid += ImeIAMBlockItem::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJAMBLOCKITEM)) {
					imeijamblockitem.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMBlockItem"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJob::ImeitemIAMBlockItem::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCAMBlockItem", "clu", irefRefWznmCAMBlockItem)) ixWIelValid += ImeIAMBlockItem::VecWIel::IREFREFWZNMCAMBLOCKITEM;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIAMBlockItem::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMBlockItem::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype)) ixWIelValid += ImeIAMBlockItem::VecWIel::SREFIXWZNMVVARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMBlockItem::VecWIel::SREFREFWZNMMVECTOR;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIAMBlockItem::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIAMBlockItem::VecWIel::SREFREFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMBlockItem::VecWIel::COMMENT;
		imeijamblockitem.readXML(docctx, basexpath);
	};
};

void IexWznmJob::ImeitemIAMBlockItem::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << irefRefWznmCAMBlockItem << "\t" << VecWznmVAMBlockItemBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << VecWznmVVartype::getSref(ixWznmVVartype) << "\t" << srefRefWznmMVector << "\t" << Defval << "\t" << srefRefWznmMVectoritem << "\t" << Comment << endl;
	imeijamblockitem.writeTxt(outfile);
};

void IexWznmJob::ImeitemIAMBlockItem::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","typ","srf","vty","vec","dfv","vit","cmt"};
	else tags = {"ImeitemIAMBlockItem","irefRefWznmCAMBlockItem","srefIxVBasetype","sref","srefIxWznmVVartype","srefRefWznmMVector","Defval","srefRefWznmMVectoritem","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWznmCAMBlockItem);
		writeString(wr, tags[2], VecWznmVAMBlockItemBasetype::getSref(ixVBasetype));
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], VecWznmVVartype::getSref(ixWznmVVartype));
		writeString(wr, tags[5], srefRefWznmMVector);
		writeString(wr, tags[6], Defval);
		writeString(wr, tags[7], srefRefWznmMVectoritem);
		writeString(wr, tags[8], Comment);
		imeijamblockitem.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJob::ImeIAMBlockItem::VecWIel
 ******************************************************************************/

uint IexWznmJob::ImeIAMBlockItem::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwznmcamblockitem") ix |= IREFREFWZNMCAMBLOCKITEM;
		else if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmvvartype") ix |= SREFIXWZNMVVARTYPE;
		else if (ss[i] == "srefrefwznmmvector") ix |= SREFREFWZNMMVECTOR;
		else if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmJob::ImeIAMBlockItem::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJob::ImeIAMBlockItem::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWZNMCAMBLOCKITEM) ss.push_back("irefRefWznmCAMBlockItem");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXWZNMVVARTYPE) ss.push_back("srefIxWznmVVartype");
	if (ix & SREFREFWZNMMVECTOR) ss.push_back("srefRefWznmMVector");
	if (ix & DEFVAL) ss.push_back("Defval");
	if (ix & SREFREFWZNMMVECTORITEM) ss.push_back("srefRefWznmMVectoritem");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJob::ImeIAMBlockItem
 ******************************************************************************/

IexWznmJob::ImeIAMBlockItem::ImeIAMBlockItem() {
};

IexWznmJob::ImeIAMBlockItem::~ImeIAMBlockItem() {
	clear();
};

void IexWznmJob::ImeIAMBlockItem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJob::ImeIAMBlockItem::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJob::ImeitemIAMBlockItem* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmJob::ImeitemIAMBlockItem();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMBlockItem"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMBlockItem"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMBLOCKITEM) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMBlockItem"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMBlockItem"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJob::ImeIAMBlockItem::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJob::ImeitemIAMBlockItem* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMBlockItem");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMBlockItem", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMBlockItem";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJob::ImeitemIAMBlockItem();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJob::ImeIAMBlockItem::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMBlockItem." << StrMod::replaceChar(ImeIAMBlockItem::VecWIel::getSrefs(255), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMBlockItem.end" << endl;
	};
};

void IexWznmJob::ImeIAMBlockItem::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMBlockItem");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJob::ImeitemICAMBlockItem
 ******************************************************************************/

IexWznmJob::ImeitemICAMBlockItem::ImeitemICAMBlockItem(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmJob::ImeitemICAMBlockItem::ImeitemICAMBlockItem(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICAMBlockItem()
		{
};

void IexWznmJob::ImeitemICAMBlockItem::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICAMBlockItem::VecWIel::IREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMBlockItem"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJob::ImeitemICAMBlockItem::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICAMBlockItem::VecWIel::IREF;
	};
};

void IexWznmJob::ImeitemICAMBlockItem::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWznmJob::ImeitemICAMBlockItem::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICAMBlockItem","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJob::ImeICAMBlockItem::VecWIel
 ******************************************************************************/

uint IexWznmJob::ImeICAMBlockItem::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWznmJob::ImeICAMBlockItem::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJob::ImeICAMBlockItem::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJob::ImeICAMBlockItem
 ******************************************************************************/

IexWznmJob::ImeICAMBlockItem::ImeICAMBlockItem() {
};

IexWznmJob::ImeICAMBlockItem::~ImeICAMBlockItem() {
	clear();
};

void IexWznmJob::ImeICAMBlockItem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJob::ImeICAMBlockItem::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJob::ImeitemICAMBlockItem* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmJob::ImeitemICAMBlockItem();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMBlockItem"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMBlockItem"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICAMBLOCKITEM) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMBlockItem"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMBlockItem"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJob::ImeICAMBlockItem::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJob::ImeitemICAMBlockItem* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICAMBlockItem");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICAMBlockItem", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICAMBlockItem";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJob::ImeitemICAMBlockItem();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJob::ImeICAMBlockItem::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICAMBlockItem." << StrMod::replaceChar(ImeICAMBlockItem::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICAMBlockItem.end" << endl;
	};
};

void IexWznmJob::ImeICAMBlockItem::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICAMBlockItem");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJob::ImeitemIMBlock
 ******************************************************************************/

IexWznmJob::ImeitemIMBlock::ImeitemIMBlock(
			const uint reaIxWznmWScope
			, const uint wriIxWznmWScope
			, const string& sref
			, const string& Comment
		) : WznmMBlock() {
	lineno = 0;
	ixWIelValid = 0;

	this->reaIxWznmWScope = reaIxWznmWScope;
	this->wriIxWznmWScope = wriIxWznmWScope;
	this->sref = sref;
	this->Comment = Comment;
};

IexWznmJob::ImeitemIMBlock::ImeitemIMBlock(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMBlock()
		{
	WznmMBlock* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmblock->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMVersion = rec->refWznmMVersion;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		reaIxWznmWScope = rec->reaIxWznmWScope;
		wriIxWznmWScope = rec->wriIxWznmWScope;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmJob::ImeitemIMBlock::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefsReaIxWznmWScope = txtrd.fields[0]; ixWIelValid += ImeIMBlock::VecWIel::SREFSREAIXWZNMWSCOPE;};
	if (txtrd.fields.size() > 1) {srefsWriIxWznmWScope = txtrd.fields[1]; ixWIelValid += ImeIMBlock::VecWIel::SREFSWRIIXWZNMWSCOPE;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMBlock::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMBlock::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMBLOCKITEM)) {
					imeiamblockitem.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEICAMBLOCKITEM)) {
					imeicamblockitem.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMBlock"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJob::ImeitemIMBlock::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefsReaIxWznmWScope", "rsc", srefsReaIxWznmWScope)) ixWIelValid += ImeIMBlock::VecWIel::SREFSREAIXWZNMWSCOPE;
		if (extractStringUclc(docctx, basexpath, "srefsWriIxWznmWScope", "wsc", srefsWriIxWznmWScope)) ixWIelValid += ImeIMBlock::VecWIel::SREFSWRIIXWZNMWSCOPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMBlock::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMBlock::VecWIel::COMMENT;
		imeiamblockitem.readXML(docctx, basexpath);
		imeicamblockitem.readXML(docctx, basexpath);
	};
};

void IexWznmJob::ImeitemIMBlock::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmWScope::getSrefs(reaIxWznmWScope) << "\t" << VecWznmWScope::getSrefs(wriIxWznmWScope) << "\t" << sref << "\t" << Comment << endl;
	imeiamblockitem.writeTxt(outfile);
	imeicamblockitem.writeTxt(outfile);
};

void IexWznmJob::ImeitemIMBlock::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","rsc","wsc","srf","cmt"};
	else tags = {"ImeitemIMBlock","srefsReaIxWznmWScope","srefsWriIxWznmWScope","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmWScope::getSrefs(reaIxWznmWScope));
		writeString(wr, tags[2], VecWznmWScope::getSrefs(wriIxWznmWScope));
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], Comment);
		imeiamblockitem.writeXML(wr, shorttags);
		imeicamblockitem.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJob::ImeIMBlock::VecWIel
 ******************************************************************************/

uint IexWznmJob::ImeIMBlock::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefsreaixwznmwscope") ix |= SREFSREAIXWZNMWSCOPE;
		else if (ss[i] == "srefswriixwznmwscope") ix |= SREFSWRIIXWZNMWSCOPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmJob::ImeIMBlock::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJob::ImeIMBlock::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFSREAIXWZNMWSCOPE) ss.push_back("srefsReaIxWznmWScope");
	if (ix & SREFSWRIIXWZNMWSCOPE) ss.push_back("srefsWriIxWznmWScope");
	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJob::ImeIMBlock
 ******************************************************************************/

IexWznmJob::ImeIMBlock::ImeIMBlock() {
};

IexWznmJob::ImeIMBlock::~ImeIMBlock() {
	clear();
};

void IexWznmJob::ImeIMBlock::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJob::ImeIMBlock::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJob::ImeitemIMBlock* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJob::ImeitemIMBlock();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBlock"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMBlock"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMBLOCK) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBlock"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBlock"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJob::ImeIMBlock::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJob::ImeitemIMBlock* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMBlock");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMBlock", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMBlock";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJob::ImeitemIMBlock();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJob::ImeIMBlock::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMBlock." << StrMod::replaceChar(ImeIMBlock::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMBlock.end" << endl;
	};
};

void IexWznmJob::ImeIMBlock::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMBlock");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJob::ImeitemIMJob
 ******************************************************************************/

IexWznmJob::ImeitemIMJob::ImeitemIMJob(
			const string& sref
			, const bool Clisrv
			, const bool Shrdat
			, const string& Comment
		) : WznmMJob() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Clisrv = Clisrv;
	this->Shrdat = Shrdat;
	this->Comment = Comment;
};

IexWznmJob::ImeitemIMJob::ImeitemIMJob(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMJob()
		{
	WznmMJob* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmjob->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMVersion = rec->refWznmMVersion;
		refIxVTbl = rec->refIxVTbl;
		sref = rec->sref;
		Clisrv = rec->Clisrv;
		Shrdat = rec->Shrdat;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmJob::ImeitemIMJob::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMJob::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Clisrv = (txtrd.fields[1] == "true"); ixWIelValid += ImeIMJob::VecWIel::CLISRV;};
	if (txtrd.fields.size() > 2) {Shrdat = (txtrd.fields[2] == "true"); ixWIelValid += ImeIMJob::VecWIel::SHRDAT;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMJob::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMBLOCK)) {
					imeimblock.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMJob"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJob::ImeitemIMJob::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMJob::VecWIel::SREF;
		if (extractBoolUclc(docctx, basexpath, "Clisrv", "cls", Clisrv)) ixWIelValid += ImeIMJob::VecWIel::CLISRV;
		if (extractBoolUclc(docctx, basexpath, "Shrdat", "shd", Shrdat)) ixWIelValid += ImeIMJob::VecWIel::SHRDAT;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMJob::VecWIel::COMMENT;
		imeimblock.readXML(docctx, basexpath);
	};
};

void IexWznmJob::ImeitemIMJob::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << StrMod::boolToString(Clisrv) << "\t" << StrMod::boolToString(Shrdat) << "\t" << Comment << endl;
	imeimblock.writeTxt(outfile);
};

void IexWznmJob::ImeitemIMJob::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cls","shd","cmt"};
	else tags = {"ImeitemIMJob","sref","Clisrv","Shrdat","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeBool(wr, tags[2], Clisrv);
		writeBool(wr, tags[3], Shrdat);
		writeString(wr, tags[4], Comment);
		imeimblock.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJob::ImeIMJob::VecWIel
 ******************************************************************************/

uint IexWznmJob::ImeIMJob::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "clisrv") ix |= CLISRV;
		else if (ss[i] == "shrdat") ix |= SHRDAT;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmJob::ImeIMJob::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJob::ImeIMJob::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & CLISRV) ss.push_back("Clisrv");
	if (ix & SHRDAT) ss.push_back("Shrdat");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJob::ImeIMJob
 ******************************************************************************/

IexWznmJob::ImeIMJob::ImeIMJob() {
};

IexWznmJob::ImeIMJob::~ImeIMJob() {
	clear();
};

void IexWznmJob::ImeIMJob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJob::ImeIMJob::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJob::ImeitemIMJob* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmJob::ImeitemIMJob();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMJob"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMJOB) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMJob"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMJob"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJob::ImeIMJob::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJob::ImeitemIMJob* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMJob");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMJob", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMJob";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJob::ImeitemIMJob();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJob::ImeIMJob::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMJob." << StrMod::replaceChar(ImeIMJob::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMJob.end" << endl;
	};
};

void IexWznmJob::ImeIMJob::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMJob");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWznmJob
 ******************************************************************************/

void IexWznmJob::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIMCapability& imeimcapability
			, ImeIMJob& imeimjob
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimcapability, imeimjob);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexWznmJob", Version("0.9.29"), VecVIme::getIx);
			readTxt(rd, imeimcapability, imeimjob);
	};
};

void IexWznmJob::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMCapability& imeimcapability
			, ImeIMJob& imeimjob
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimcapability, imeimjob);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimcapability, imeimjob);
		txtfile.close();
	};
};

void IexWznmJob::readTxt(
			Txtrd& txtrd
			, ImeIMCapability& imeimcapability
			, ImeIMJob& imeimjob
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMCAPABILITY)) imeimcapability.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMJOB)) imeimjob.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWznmJob::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMCapability& imeimcapability
			, ImeIMJob& imeimjob
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmJob")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("0.9.29")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","0.9.29"}});
		};

		// look for XML sub-blocks
		imeimcapability.readXML(docctx, basexpath);
		imeimjob.readXML(docctx, basexpath);

	} else {
		imeimcapability = ImeIMCapability();
		imeimjob = ImeIMJob();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmJob"}});
	};
};

void IexWznmJob::writeTxt(
			fstream& outfile
			, ImeIMCapability& imeimcapability
			, ImeIMJob& imeimjob
		) {
	outfile << "IexWznmJob v" WZNM_VERSION << endl;

	imeimcapability.writeTxt(outfile);
	imeimjob.writeTxt(outfile);
};

void IexWznmJob::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMCapability& imeimcapability
			, ImeIMJob& imeimjob
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmJob");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeimcapability.writeXML(wr, shorttags);
		imeimjob.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmJob::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMBLOCKITEM,VecWznmVIop::INS},{(uint)VecVIme::IMEICAMBLOCKITEM,VecWznmVIop::INS},{(uint)VecVIme::IMEIJAMBLOCKITEM,VecWznmVIop::INS},{(uint)VecVIme::IMEIMBLOCK,VecWznmVIop::INS},{(uint)VecVIme::IMEIMJOB,VecWznmVIop::INS}};
};

uint IexWznmJob::getIxWznmVIop(
			const map<uint,uint>& icsWznmVIop
			, const uint ixVIme
			, uint& ixWznmVIop
		) {
	ixWznmVIop = 0;

	auto it = icsWznmVIop.find(ixVIme);
	if (it != icsWznmVIop.end()) ixWznmVIop = it->second;

	return ixWznmVIop;
};
