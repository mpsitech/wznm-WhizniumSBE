/**
	* \file IexWznmApp.cpp
	* data blocks and readers/writers for import/export complex IexWznmApp (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "IexWznmApp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWznmApp::VecVIme
 ******************************************************************************/

uint IexWznmApp::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamstateaction") return IMEIAMSTATEACTION;
	if (s == "imeiamstatetrig") return IMEIAMSTATETRIG;
	if (s == "imeijamstatetrigcond") return IMEIJAMSTATETRIGCOND;
	if (s == "imeimevent") return IMEIMEVENT;
	if (s == "imeimrtblock") return IMEIMRTBLOCK;
	if (s == "imeimrtdpch") return IMEIMRTDPCH;
	if (s == "imeimrtjob") return IMEIMRTJOB;
	if (s == "imeimsequence") return IMEIMSEQUENCE;
	if (s == "imeimstate") return IMEIMSTATE;

	return(0);
};

string IexWznmApp::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMSTATEACTION) return("ImeIAMStateAction");
	if (ix == IMEIAMSTATETRIG) return("ImeIAMStateTrig");
	if (ix == IMEIJAMSTATETRIGCOND) return("ImeIJAMStateTrigCond");
	if (ix == IMEIMEVENT) return("ImeIMEvent");
	if (ix == IMEIMRTBLOCK) return("ImeIMRtblock");
	if (ix == IMEIMRTDPCH) return("ImeIMRtdpch");
	if (ix == IMEIMRTJOB) return("ImeIMRtjob");
	if (ix == IMEIMSEQUENCE) return("ImeIMSequence");
	if (ix == IMEIMSTATE) return("ImeIMState");

	return("");
};

/******************************************************************************
 class IexWznmApp::ImeitemIMEvent
 ******************************************************************************/

IexWznmApp::ImeitemIMEvent::ImeitemIMEvent(
			const string& sref
			, const string& Comment
		) : WznmMEvent() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexWznmApp::ImeitemIMEvent::ImeitemIMEvent(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMEvent()
		{
	WznmMEvent* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmevent->loadRecByRef(ref, &rec)) {
		refWznmMApp = rec->refWznmMApp;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmApp::ImeitemIMEvent::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMEvent::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIMEvent::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMEvent"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmApp::ImeitemIMEvent::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMEvent::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMEvent::VecWIel::COMMENT;
	};
};

void IexWznmApp::ImeitemIMEvent::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Comment << endl;
};

void IexWznmApp::ImeitemIMEvent::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMEvent","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmApp::ImeIMEvent::VecWIel
 ******************************************************************************/

uint IexWznmApp::ImeIMEvent::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmApp::ImeIMEvent::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmApp::ImeIMEvent::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmApp::ImeIMEvent
 ******************************************************************************/

IexWznmApp::ImeIMEvent::ImeIMEvent() {
};

IexWznmApp::ImeIMEvent::~ImeIMEvent() {
	clear();
};

void IexWznmApp::ImeIMEvent::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmApp::ImeIMEvent::readTxt(
			Txtrd& txtrd
		) {
	IexWznmApp::ImeitemIMEvent* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmApp::ImeitemIMEvent();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMEvent"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMEVENT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMEvent"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMEvent"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmApp::ImeIMEvent::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmApp::ImeitemIMEvent* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMEvent");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMEvent", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMEvent";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmApp::ImeitemIMEvent();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmApp::ImeIMEvent::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMEvent." << StrMod::replaceChar(ImeIMEvent::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMEvent.end" << endl;
	};
};

void IexWznmApp::ImeIMEvent::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMEvent");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmApp::ImeitemIMRtblock
 ******************************************************************************/

IexWznmApp::ImeitemIMRtblock::ImeitemIMRtblock(
			const uint refIxVTbl
			, const string& srefRefUref
			, const string& sref
			, const string& srcSrefsWznmAMBlockItem
		) : WznmMRtblock() {
	lineno = 0;
	ixWIelValid = 0;

	this->refIxVTbl = refIxVTbl;
	this->srefRefUref = srefRefUref;
	this->sref = sref;
	this->srcSrefsWznmAMBlockItem = srcSrefsWznmAMBlockItem;
};

IexWznmApp::ImeitemIMRtblock::ImeitemIMRtblock(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMRtblock()
		{
	WznmMRtblock* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmrtblock->loadRecByRef(ref, &rec)) {
		refWznmMRtjob = rec->refWznmMRtjob;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		sref = rec->sref;
		srcSrefsWznmAMBlockItem = rec->srcSrefsWznmAMBlockItem;

		delete rec;
	};
};

void IexWznmApp::ImeitemIMRtblock::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefIxVTbl = txtrd.fields[0]; ixWIelValid += ImeIMRtblock::VecWIel::SREFREFIXVTBL;};
	if (txtrd.fields.size() > 1) {srefRefUref = txtrd.fields[1]; ixWIelValid += ImeIMRtblock::VecWIel::SREFREFUREF;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMRtblock::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {srcSrefsWznmAMBlockItem = txtrd.fields[3]; ixWIelValid += ImeIMRtblock::VecWIel::SRCSREFSWZNMAMBLOCKITEM;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRtblock"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmApp::ImeitemIMRtblock::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl)) ixWIelValid += ImeIMRtblock::VecWIel::SREFREFIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefRefUref", "reu", srefRefUref)) ixWIelValid += ImeIMRtblock::VecWIel::SREFREFUREF;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMRtblock::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srcSrefsWznmAMBlockItem", "src", srcSrefsWznmAMBlockItem)) ixWIelValid += ImeIMRtblock::VecWIel::SRCSREFSWZNMAMBLOCKITEM;
	};
};

void IexWznmApp::ImeitemIMRtblock::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVMRtblockRefTbl::getSref(refIxVTbl) << "\t" << srefRefUref << "\t" << sref << "\t" << srcSrefsWznmAMBlockItem << endl;
};

void IexWznmApp::ImeitemIMRtblock::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ret","reu","srf","src"};
	else tags = {"ImeitemIMRtblock","srefRefIxVTbl","srefRefUref","sref","srcSrefsWznmAMBlockItem"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMRtblockRefTbl::getSref(refIxVTbl));
		writeString(wr, tags[2], srefRefUref);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], srcSrefsWznmAMBlockItem);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmApp::ImeIMRtblock::VecWIel
 ******************************************************************************/

uint IexWznmApp::ImeIMRtblock::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefixvtbl") ix |= SREFREFIXVTBL;
		else if (ss[i] == "srefrefuref") ix |= SREFREFUREF;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srcsrefswznmamblockitem") ix |= SRCSREFSWZNMAMBLOCKITEM;
	};

	return(ix);
};

void IexWznmApp::ImeIMRtblock::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SRCSREFSWZNMAMBLOCKITEM); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmApp::ImeIMRtblock::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFIXVTBL) ss.push_back("srefRefIxVTbl");
	if (ix & SREFREFUREF) ss.push_back("srefRefUref");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SRCSREFSWZNMAMBLOCKITEM) ss.push_back("srcSrefsWznmAMBlockItem");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmApp::ImeIMRtblock
 ******************************************************************************/

IexWznmApp::ImeIMRtblock::ImeIMRtblock() {
};

IexWznmApp::ImeIMRtblock::~ImeIMRtblock() {
	clear();
};

void IexWznmApp::ImeIMRtblock::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmApp::ImeIMRtblock::readTxt(
			Txtrd& txtrd
		) {
	IexWznmApp::ImeitemIMRtblock* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmApp::ImeitemIMRtblock();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRtblock"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRtblock"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMRTBLOCK) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRtblock"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRtblock"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmApp::ImeIMRtblock::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmApp::ImeitemIMRtblock* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMRtblock");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMRtblock", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMRtblock";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmApp::ImeitemIMRtblock();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmApp::ImeIMRtblock::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMRtblock." << StrMod::replaceChar(ImeIMRtblock::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMRtblock.end" << endl;
	};
};

void IexWznmApp::ImeIMRtblock::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMRtblock");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmApp::ImeitemIMRtdpch
 ******************************************************************************/

IexWznmApp::ImeitemIMRtdpch::ImeitemIMRtdpch(
			const string& srefRefWznmMBlock
			, const string& sref
			, const bool Merge
		) : WznmMRtdpch() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMBlock = srefRefWznmMBlock;
	this->sref = sref;
	this->Merge = Merge;
};

IexWznmApp::ImeitemIMRtdpch::ImeitemIMRtdpch(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMRtdpch()
		{
	WznmMRtdpch* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmrtdpch->loadRecByRef(ref, &rec)) {
		refWznmMRtjob = rec->refWznmMRtjob;
		refWznmMBlock = rec->refWznmMBlock;
		sref = rec->sref;
		Merge = rec->Merge;

		delete rec;
	};
};

void IexWznmApp::ImeitemIMRtdpch::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMBlock = txtrd.fields[0]; ixWIelValid += ImeIMRtdpch::VecWIel::SREFREFWZNMMBLOCK;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMRtdpch::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Merge = (txtrd.fields[2] == "true"); ixWIelValid += ImeIMRtdpch::VecWIel::MERGE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRtdpch"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmApp::ImeitemIMRtdpch::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMBlock", "job", srefRefWznmMBlock)) ixWIelValid += ImeIMRtdpch::VecWIel::SREFREFWZNMMBLOCK;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMRtdpch::VecWIel::SREF;
		if (extractBoolUclc(docctx, basexpath, "Merge", "mrg", Merge)) ixWIelValid += ImeIMRtdpch::VecWIel::MERGE;
	};
};

void IexWznmApp::ImeitemIMRtdpch::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefRefWznmMBlock << "\t" << sref << "\t" << StrMod::boolToString(Merge) << endl;
};

void IexWznmApp::ImeitemIMRtdpch::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","job","srf","mrg"};
	else tags = {"ImeitemIMRtdpch","srefRefWznmMBlock","sref","Merge"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMBlock);
		writeString(wr, tags[2], sref);
		writeBool(wr, tags[3], Merge);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmApp::ImeIMRtdpch::VecWIel
 ******************************************************************************/

uint IexWznmApp::ImeIMRtdpch::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwznmmblock") ix |= SREFREFWZNMMBLOCK;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "merge") ix |= MERGE;
	};

	return(ix);
};

void IexWznmApp::ImeIMRtdpch::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*MERGE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmApp::ImeIMRtdpch::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMBLOCK) ss.push_back("srefRefWznmMBlock");
	if (ix & SREF) ss.push_back("sref");
	if (ix & MERGE) ss.push_back("Merge");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmApp::ImeIMRtdpch
 ******************************************************************************/

IexWznmApp::ImeIMRtdpch::ImeIMRtdpch() {
};

IexWznmApp::ImeIMRtdpch::~ImeIMRtdpch() {
	clear();
};

void IexWznmApp::ImeIMRtdpch::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmApp::ImeIMRtdpch::readTxt(
			Txtrd& txtrd
		) {
	IexWznmApp::ImeitemIMRtdpch* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmApp::ImeitemIMRtdpch();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRtdpch"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRtdpch"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMRTDPCH) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRtdpch"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRtdpch"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmApp::ImeIMRtdpch::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmApp::ImeitemIMRtdpch* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMRtdpch");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMRtdpch", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMRtdpch";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmApp::ImeitemIMRtdpch();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmApp::ImeIMRtdpch::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMRtdpch." << StrMod::replaceChar(ImeIMRtdpch::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMRtdpch.end" << endl;
	};
};

void IexWznmApp::ImeIMRtdpch::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMRtdpch");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmApp::ImeitemIMRtjob
 ******************************************************************************/

IexWznmApp::ImeitemIMRtjob::ImeitemIMRtjob(
			const ubigint iref
			, const ubigint irefSupRefWznmMRtjob
			, const string& srefRefWznmMJob
			, const string& sref
			, const string& Comment
		) : WznmMRtjob() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->irefSupRefWznmMRtjob = irefSupRefWznmMRtjob;
	this->srefRefWznmMJob = srefRefWznmMJob;
	this->sref = sref;
	this->Comment = Comment;
};

IexWznmApp::ImeitemIMRtjob::ImeitemIMRtjob(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMRtjob()
		{
	WznmMRtjob* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmrtjob->loadRecByRef(ref, &rec)) {
		refWznmMApp = rec->refWznmMApp;
		supRefWznmMRtjob = rec->supRefWznmMRtjob;
		refWznmMJob = rec->refWznmMJob;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmApp::ImeitemIMRtjob::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMRtjob::VecWIel::IREF;};
	if (txtrd.fields.size() > 1) {irefSupRefWznmMRtjob = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIMRtjob::VecWIel::IREFSUPREFWZNMMRTJOB;};
	if (txtrd.fields.size() > 2) {srefRefWznmMJob = txtrd.fields[2]; ixWIelValid += ImeIMRtjob::VecWIel::SREFREFWZNMMJOB;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIMRtjob::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMRtjob::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMRTBLOCK)) {
					imeimrtblock.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMRTDPCH)) {
					imeimrtdpch.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRtjob"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmApp::ImeitemIMRtjob::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMRtjob::VecWIel::IREF;
		if (extractUbigintUclc(docctx, basexpath, "irefSupRefWznmMRtjob", "sup", irefSupRefWznmMRtjob)) ixWIelValid += ImeIMRtjob::VecWIel::IREFSUPREFWZNMMRTJOB;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMJob", "job", srefRefWznmMJob)) ixWIelValid += ImeIMRtjob::VecWIel::SREFREFWZNMMJOB;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMRtjob::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMRtjob::VecWIel::COMMENT;
		imeimrtblock.readXML(docctx, basexpath);
		imeimrtdpch.readXML(docctx, basexpath);
	};
};

void IexWznmApp::ImeitemIMRtjob::writeTxt(
			fstream& outfile
		) {
	outfile << iref << "\t" << irefSupRefWznmMRtjob << "\t" << srefRefWznmMJob << "\t" << sref << "\t" << Comment << endl;
	imeimrtblock.writeTxt(outfile);
	imeimrtdpch.writeTxt(outfile);
};

void IexWznmApp::ImeitemIMRtjob::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","sup","job","srf","cmt"};
	else tags = {"ImeitemIMRtjob","iref","irefSupRefWznmMRtjob","srefRefWznmMJob","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeUbigint(wr, tags[2], irefSupRefWznmMRtjob);
		writeString(wr, tags[3], srefRefWznmMJob);
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], Comment);
		imeimrtblock.writeXML(wr, shorttags);
		imeimrtdpch.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmApp::ImeIMRtjob::VecWIel
 ******************************************************************************/

uint IexWznmApp::ImeIMRtjob::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "irefsuprefwznmmrtjob") ix |= IREFSUPREFWZNMMRTJOB;
		else if (ss[i] == "srefrefwznmmjob") ix |= SREFREFWZNMMJOB;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmApp::ImeIMRtjob::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmApp::ImeIMRtjob::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & IREFSUPREFWZNMMRTJOB) ss.push_back("irefSupRefWznmMRtjob");
	if (ix & SREFREFWZNMMJOB) ss.push_back("srefRefWznmMJob");
	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmApp::ImeIMRtjob
 ******************************************************************************/

IexWznmApp::ImeIMRtjob::ImeIMRtjob() {
};

IexWznmApp::ImeIMRtjob::~ImeIMRtjob() {
	clear();
};

void IexWznmApp::ImeIMRtjob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmApp::ImeIMRtjob::readTxt(
			Txtrd& txtrd
		) {
	IexWznmApp::ImeitemIMRtjob* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmApp::ImeitemIMRtjob();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRtjob"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMRTJOB) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRtjob"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRtjob"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmApp::ImeIMRtjob::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmApp::ImeitemIMRtjob* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMRtjob");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMRtjob", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMRtjob";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmApp::ImeitemIMRtjob();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmApp::ImeIMRtjob::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMRtjob." << StrMod::replaceChar(ImeIMRtjob::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMRtjob.end" << endl;
	};
};

void IexWznmApp::ImeIMRtjob::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMRtjob");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmApp::ImeitemIAMStateAction
 ******************************************************************************/

IexWznmApp::ImeitemIAMStateAction::ImeitemIAMStateAction(
			const uint ixVSection
			, const uint ixVType
			, const ubigint irefRefWznmMRtjob
			, const string& srefRefWznmMVector
			, const string& srefRefWznmMVectoritem
			, const string& srefSnxRefWznmMState
			, const string& srefRefWznmMSequence
			, const string& tr1SrefATrig
			, const string& Ip1
			, const string& tr2SrefATrig
			, const string& Ip2
			, const string& tr3SrefATrig
			, const string& Ip3
			, const string& tr4SrefATrig
			, const string& Ip4
		) : WznmAMStateAction() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVSection = ixVSection;
	this->ixVType = ixVType;
	this->irefRefWznmMRtjob = irefRefWznmMRtjob;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
	this->srefSnxRefWznmMState = srefSnxRefWznmMState;
	this->srefRefWznmMSequence = srefRefWznmMSequence;
	this->tr1SrefATrig = tr1SrefATrig;
	this->Ip1 = Ip1;
	this->tr2SrefATrig = tr2SrefATrig;
	this->Ip2 = Ip2;
	this->tr3SrefATrig = tr3SrefATrig;
	this->Ip3 = Ip3;
	this->tr4SrefATrig = tr4SrefATrig;
	this->Ip4 = Ip4;
};

IexWznmApp::ImeitemIAMStateAction::ImeitemIAMStateAction(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMStateAction()
		{
	WznmAMStateAction* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamstateaction->loadRecByRef(ref, &rec)) {
		steRefWznmMState = rec->steRefWznmMState;
		steNum = rec->steNum;
		ixVSection = rec->ixVSection;
		ixVType = rec->ixVType;
		refWznmMRtjob = rec->refWznmMRtjob;
		refWznmMVector = rec->refWznmMVector;
		refWznmMVectoritem = rec->refWznmMVectoritem;
		snxRefWznmMState = rec->snxRefWznmMState;
		refWznmMSequence = rec->refWznmMSequence;
		tr1SrefATrig = rec->tr1SrefATrig;
		Ip1 = rec->Ip1;
		tr2SrefATrig = rec->tr2SrefATrig;
		Ip2 = rec->Ip2;
		tr3SrefATrig = rec->tr3SrefATrig;
		Ip3 = rec->Ip3;
		tr4SrefATrig = rec->tr4SrefATrig;
		Ip4 = rec->Ip4;

		delete rec;
	};
};

void IexWznmApp::ImeitemIAMStateAction::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVSection = txtrd.fields[0]; ixWIelValid += ImeIAMStateAction::VecWIel::SREFIXVSECTION;};
	if (txtrd.fields.size() > 1) {srefIxVType = txtrd.fields[1]; ixWIelValid += ImeIAMStateAction::VecWIel::SREFIXVTYPE;};
	if (txtrd.fields.size() > 2) {irefRefWznmMRtjob = atoll(txtrd.fields[2].c_str()); ixWIelValid += ImeIAMStateAction::VecWIel::IREFREFWZNMMRTJOB;};
	if (txtrd.fields.size() > 3) {srefRefWznmMVector = txtrd.fields[3]; ixWIelValid += ImeIAMStateAction::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 4) {srefRefWznmMVectoritem = txtrd.fields[4]; ixWIelValid += ImeIAMStateAction::VecWIel::SREFREFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 5) {srefSnxRefWznmMState = txtrd.fields[5]; ixWIelValid += ImeIAMStateAction::VecWIel::SREFSNXREFWZNMMSTATE;};
	if (txtrd.fields.size() > 6) {srefRefWznmMSequence = txtrd.fields[6]; ixWIelValid += ImeIAMStateAction::VecWIel::SREFREFWZNMMSEQUENCE;};
	if (txtrd.fields.size() > 7) {tr1SrefATrig = txtrd.fields[7]; ixWIelValid += ImeIAMStateAction::VecWIel::TR1SREFATRIG;};
	if (txtrd.fields.size() > 8) {Ip1 = txtrd.fields[8]; ixWIelValid += ImeIAMStateAction::VecWIel::IP1;};
	if (txtrd.fields.size() > 9) {tr2SrefATrig = txtrd.fields[9]; ixWIelValid += ImeIAMStateAction::VecWIel::TR2SREFATRIG;};
	if (txtrd.fields.size() > 10) {Ip2 = txtrd.fields[10]; ixWIelValid += ImeIAMStateAction::VecWIel::IP2;};
	if (txtrd.fields.size() > 11) {tr3SrefATrig = txtrd.fields[11]; ixWIelValid += ImeIAMStateAction::VecWIel::TR3SREFATRIG;};
	if (txtrd.fields.size() > 12) {Ip3 = txtrd.fields[12]; ixWIelValid += ImeIAMStateAction::VecWIel::IP3;};
	if (txtrd.fields.size() > 13) {tr4SrefATrig = txtrd.fields[13]; ixWIelValid += ImeIAMStateAction::VecWIel::TR4SREFATRIG;};
	if (txtrd.fields.size() > 14) {Ip4 = txtrd.fields[14]; ixWIelValid += ImeIAMStateAction::VecWIel::IP4;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMStateAction"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmApp::ImeitemIAMStateAction::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVSection", "sct", srefIxVSection)) ixWIelValid += ImeIAMStateAction::VecWIel::SREFIXVSECTION;
		if (extractStringUclc(docctx, basexpath, "srefIxVType", "typ", srefIxVType)) ixWIelValid += ImeIAMStateAction::VecWIel::SREFIXVTYPE;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmMRtjob", "rtj", irefRefWznmMRtjob)) ixWIelValid += ImeIAMStateAction::VecWIel::IREFREFWZNMMRTJOB;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMStateAction::VecWIel::SREFREFWZNMMVECTOR;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIAMStateAction::VecWIel::SREFREFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "srefSnxRefWznmMState", "snx", srefSnxRefWznmMState)) ixWIelValid += ImeIAMStateAction::VecWIel::SREFSNXREFWZNMMSTATE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMSequence", "seq", srefRefWznmMSequence)) ixWIelValid += ImeIAMStateAction::VecWIel::SREFREFWZNMMSEQUENCE;
		if (extractStringUclc(docctx, basexpath, "tr1SrefATrig", "tr1", tr1SrefATrig)) ixWIelValid += ImeIAMStateAction::VecWIel::TR1SREFATRIG;
		if (extractStringUclc(docctx, basexpath, "Ip1", "ip1", Ip1)) ixWIelValid += ImeIAMStateAction::VecWIel::IP1;
		if (extractStringUclc(docctx, basexpath, "tr2SrefATrig", "tr2", tr2SrefATrig)) ixWIelValid += ImeIAMStateAction::VecWIel::TR2SREFATRIG;
		if (extractStringUclc(docctx, basexpath, "Ip2", "ip2", Ip2)) ixWIelValid += ImeIAMStateAction::VecWIel::IP2;
		if (extractStringUclc(docctx, basexpath, "tr3SrefATrig", "tr3", tr3SrefATrig)) ixWIelValid += ImeIAMStateAction::VecWIel::TR3SREFATRIG;
		if (extractStringUclc(docctx, basexpath, "Ip3", "ip3", Ip3)) ixWIelValid += ImeIAMStateAction::VecWIel::IP3;
		if (extractStringUclc(docctx, basexpath, "tr4SrefATrig", "tr4", tr4SrefATrig)) ixWIelValid += ImeIAMStateAction::VecWIel::TR4SREFATRIG;
		if (extractStringUclc(docctx, basexpath, "Ip4", "ip4", Ip4)) ixWIelValid += ImeIAMStateAction::VecWIel::IP4;
	};
};

void IexWznmApp::ImeitemIAMStateAction::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVAMStateActionSection::getSref(ixVSection) << "\t" << VecWznmVAMStateActionType::getSref(ixVType) << "\t" << irefRefWznmMRtjob << "\t" << srefRefWznmMVector << "\t" << srefRefWznmMVectoritem << "\t" << srefSnxRefWznmMState << "\t" << srefRefWznmMSequence << "\t" << tr1SrefATrig << "\t" << Ip1 << "\t" << tr2SrefATrig << "\t" << Ip2 << "\t" << tr3SrefATrig << "\t" << Ip3 << "\t" << tr4SrefATrig << "\t" << Ip4 << endl;
};

void IexWznmApp::ImeitemIAMStateAction::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sct","typ","rtj","vec","vit","snx","seq","tr1","ip1","tr2","ip2","tr3","ip3","tr4","ip4"};
	else tags = {"ImeitemIAMStateAction","srefIxVSection","srefIxVType","irefRefWznmMRtjob","srefRefWznmMVector","srefRefWznmMVectoritem","srefSnxRefWznmMState","srefRefWznmMSequence","tr1SrefATrig","Ip1","tr2SrefATrig","Ip2","tr3SrefATrig","Ip3","tr4SrefATrig","Ip4"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVAMStateActionSection::getSref(ixVSection));
		writeString(wr, tags[2], VecWznmVAMStateActionType::getSref(ixVType));
		writeUbigint(wr, tags[3], irefRefWznmMRtjob);
		writeString(wr, tags[4], srefRefWznmMVector);
		writeString(wr, tags[5], srefRefWznmMVectoritem);
		writeString(wr, tags[6], srefSnxRefWznmMState);
		writeString(wr, tags[7], srefRefWznmMSequence);
		writeString(wr, tags[8], tr1SrefATrig);
		writeString(wr, tags[9], Ip1);
		writeString(wr, tags[10], tr2SrefATrig);
		writeString(wr, tags[11], Ip2);
		writeString(wr, tags[12], tr3SrefATrig);
		writeString(wr, tags[13], Ip3);
		writeString(wr, tags[14], tr4SrefATrig);
		writeString(wr, tags[15], Ip4);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmApp::ImeIAMStateAction::VecWIel
 ******************************************************************************/

uint IexWznmApp::ImeIAMStateAction::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvsection") ix |= SREFIXVSECTION;
		else if (ss[i] == "srefixvtype") ix |= SREFIXVTYPE;
		else if (ss[i] == "irefrefwznmmrtjob") ix |= IREFREFWZNMMRTJOB;
		else if (ss[i] == "srefrefwznmmvector") ix |= SREFREFWZNMMVECTOR;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
		else if (ss[i] == "srefsnxrefwznmmstate") ix |= SREFSNXREFWZNMMSTATE;
		else if (ss[i] == "srefrefwznmmsequence") ix |= SREFREFWZNMMSEQUENCE;
		else if (ss[i] == "tr1srefatrig") ix |= TR1SREFATRIG;
		else if (ss[i] == "ip1") ix |= IP1;
		else if (ss[i] == "tr2srefatrig") ix |= TR2SREFATRIG;
		else if (ss[i] == "ip2") ix |= IP2;
		else if (ss[i] == "tr3srefatrig") ix |= TR3SREFATRIG;
		else if (ss[i] == "ip3") ix |= IP3;
		else if (ss[i] == "tr4srefatrig") ix |= TR4SREFATRIG;
		else if (ss[i] == "ip4") ix |= IP4;
	};

	return(ix);
};

void IexWznmApp::ImeIAMStateAction::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IP4); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmApp::ImeIAMStateAction::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSECTION) ss.push_back("srefIxVSection");
	if (ix & SREFIXVTYPE) ss.push_back("srefIxVType");
	if (ix & IREFREFWZNMMRTJOB) ss.push_back("irefRefWznmMRtjob");
	if (ix & SREFREFWZNMMVECTOR) ss.push_back("srefRefWznmMVector");
	if (ix & SREFREFWZNMMVECTORITEM) ss.push_back("srefRefWznmMVectoritem");
	if (ix & SREFSNXREFWZNMMSTATE) ss.push_back("srefSnxRefWznmMState");
	if (ix & SREFREFWZNMMSEQUENCE) ss.push_back("srefRefWznmMSequence");
	if (ix & TR1SREFATRIG) ss.push_back("tr1SrefATrig");
	if (ix & IP1) ss.push_back("Ip1");
	if (ix & TR2SREFATRIG) ss.push_back("tr2SrefATrig");
	if (ix & IP2) ss.push_back("Ip2");
	if (ix & TR3SREFATRIG) ss.push_back("tr3SrefATrig");
	if (ix & IP3) ss.push_back("Ip3");
	if (ix & TR4SREFATRIG) ss.push_back("tr4SrefATrig");
	if (ix & IP4) ss.push_back("Ip4");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmApp::ImeIAMStateAction
 ******************************************************************************/

IexWznmApp::ImeIAMStateAction::ImeIAMStateAction() {
};

IexWznmApp::ImeIAMStateAction::~ImeIAMStateAction() {
	clear();
};

void IexWznmApp::ImeIAMStateAction::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmApp::ImeIAMStateAction::readTxt(
			Txtrd& txtrd
		) {
	IexWznmApp::ImeitemIAMStateAction* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmApp::ImeitemIAMStateAction();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMStateAction"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMStateAction"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMSTATEACTION) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMStateAction"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMStateAction"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmApp::ImeIAMStateAction::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmApp::ImeitemIAMStateAction* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMStateAction");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMStateAction", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMStateAction";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmApp::ImeitemIAMStateAction();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmApp::ImeIAMStateAction::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMStateAction." << StrMod::replaceChar(ImeIAMStateAction::VecWIel::getSrefs(32767), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMStateAction.end" << endl;
	};
};

void IexWznmApp::ImeIAMStateAction::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMStateAction");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmApp::ImeitemIJAMStateTrigCond
 ******************************************************************************/

IexWznmApp::ImeitemIJAMStateTrigCond::ImeitemIJAMStateTrigCond(
			const uint x1IxWznmVApptarget
			, const string& Cond
		) : WznmJAMStateTrigCond() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWznmVApptarget = x1IxWznmVApptarget;
	this->Cond = Cond;
};

IexWznmApp::ImeitemIJAMStateTrigCond::ImeitemIJAMStateTrigCond(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJAMStateTrigCond()
		{
	WznmJAMStateTrigCond* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjamstatetrigcond->loadRecByRef(ref, &rec)) {
		refWznmAMStateTrig = rec->refWznmAMStateTrig;
		x1IxWznmVApptarget = rec->x1IxWznmVApptarget;
		Cond = rec->Cond;

		delete rec;
	};
};

void IexWznmApp::ImeitemIJAMStateTrigCond::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWznmVApptarget = txtrd.fields[0]; ixWIelValid += ImeIJAMStateTrigCond::VecWIel::SREFX1IXWZNMVAPPTARGET;};
	if (txtrd.fields.size() > 1) {Cond = txtrd.fields[1]; ixWIelValid += ImeIJAMStateTrigCond::VecWIel::COND;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAMStateTrigCond"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmApp::ImeitemIJAMStateTrigCond::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWznmVApptarget", "trg", srefX1IxWznmVApptarget)) ixWIelValid += ImeIJAMStateTrigCond::VecWIel::SREFX1IXWZNMVAPPTARGET;
		if (extractStringUclc(docctx, basexpath, "Cond", "cnd", Cond)) ixWIelValid += ImeIJAMStateTrigCond::VecWIel::COND;
	};
};

void IexWznmApp::ImeitemIJAMStateTrigCond::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << VecWznmVApptarget::getSref(x1IxWznmVApptarget) << "\t" << Cond << endl;
};

void IexWznmApp::ImeitemIJAMStateTrigCond::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","trg","cnd"};
	else tags = {"ImeitemIJAMStateTrigCond","srefX1IxWznmVApptarget","Cond"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVApptarget::getSref(x1IxWznmVApptarget));
		writeString(wr, tags[2], Cond);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmApp::ImeIJAMStateTrigCond::VecWIel
 ******************************************************************************/

uint IexWznmApp::ImeIJAMStateTrigCond::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwznmvapptarget") ix |= SREFX1IXWZNMVAPPTARGET;
		else if (ss[i] == "cond") ix |= COND;
	};

	return(ix);
};

void IexWznmApp::ImeIJAMStateTrigCond::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COND); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmApp::ImeIJAMStateTrigCond::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWZNMVAPPTARGET) ss.push_back("srefX1IxWznmVApptarget");
	if (ix & COND) ss.push_back("Cond");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmApp::ImeIJAMStateTrigCond
 ******************************************************************************/

IexWznmApp::ImeIJAMStateTrigCond::ImeIJAMStateTrigCond() {
};

IexWznmApp::ImeIJAMStateTrigCond::~ImeIJAMStateTrigCond() {
	clear();
};

void IexWznmApp::ImeIJAMStateTrigCond::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmApp::ImeIJAMStateTrigCond::readTxt(
			Txtrd& txtrd
		) {
	IexWznmApp::ImeitemIJAMStateTrigCond* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmApp::ImeitemIJAMStateTrigCond();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAMStateTrigCond"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAMStateTrigCond"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJAMSTATETRIGCOND) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAMStateTrigCond"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAMStateTrigCond"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmApp::ImeIJAMStateTrigCond::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmApp::ImeitemIJAMStateTrigCond* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAMStateTrigCond");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAMStateTrigCond", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAMStateTrigCond";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmApp::ImeitemIJAMStateTrigCond();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmApp::ImeIJAMStateTrigCond::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJAMStateTrigCond." << StrMod::replaceChar(ImeIJAMStateTrigCond::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJAMStateTrigCond.end" << endl;
	};
};

void IexWznmApp::ImeIJAMStateTrigCond::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAMStateTrigCond");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmApp::ImeitemIAMStateTrig
 ******************************************************************************/

IexWznmApp::ImeitemIAMStateTrig::ImeitemIAMStateTrig(
			const string& sref
			, const uint ixVType
			, const string& srefRefWznmMEvent
			, const ubigint irefRefWznmMRtjob
			, const string& srefRefWznmMVectoritem
			, const string& xsref
			, const string& srefRefWznmMRtdpch
			, const string& srefsMask
			, const string& Cond
		) : WznmAMStateTrig() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixVType = ixVType;
	this->srefRefWznmMEvent = srefRefWznmMEvent;
	this->irefRefWznmMRtjob = irefRefWznmMRtjob;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
	this->xsref = xsref;
	this->srefRefWznmMRtdpch = srefRefWznmMRtdpch;
	this->srefsMask = srefsMask;
	this->Cond = Cond;
};

IexWznmApp::ImeitemIAMStateTrig::ImeitemIAMStateTrig(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMStateTrig()
		{
	WznmAMStateTrig* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamstatetrig->loadRecByRef(ref, &rec)) {
		refWznmMState = rec->refWznmMState;
		sref = rec->sref;
		ixVType = rec->ixVType;
		refWznmMEvent = rec->refWznmMEvent;
		refWznmMRtjob = rec->refWznmMRtjob;
		refWznmMVectoritem = rec->refWznmMVectoritem;
		xsref = rec->xsref;
		refWznmMRtdpch = rec->refWznmMRtdpch;
		srefsMask = rec->srefsMask;
		Cond = rec->Cond;

		delete rec;
	};
};

void IexWznmApp::ImeitemIAMStateTrig::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMStateTrig::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxVType = txtrd.fields[1]; ixWIelValid += ImeIAMStateTrig::VecWIel::SREFIXVTYPE;};
	if (txtrd.fields.size() > 2) {srefRefWznmMEvent = txtrd.fields[2]; ixWIelValid += ImeIAMStateTrig::VecWIel::SREFREFWZNMMEVENT;};
	if (txtrd.fields.size() > 3) {irefRefWznmMRtjob = atoll(txtrd.fields[3].c_str()); ixWIelValid += ImeIAMStateTrig::VecWIel::IREFREFWZNMMRTJOB;};
	if (txtrd.fields.size() > 4) {srefRefWznmMVectoritem = txtrd.fields[4]; ixWIelValid += ImeIAMStateTrig::VecWIel::SREFREFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 5) {xsref = txtrd.fields[5]; ixWIelValid += ImeIAMStateTrig::VecWIel::XSREF;};
	if (txtrd.fields.size() > 6) {srefRefWznmMRtdpch = txtrd.fields[6]; ixWIelValid += ImeIAMStateTrig::VecWIel::SREFREFWZNMMRTDPCH;};
	if (txtrd.fields.size() > 7) {srefsMask = txtrd.fields[7]; ixWIelValid += ImeIAMStateTrig::VecWIel::SREFSMASK;};
	if (txtrd.fields.size() > 8) {Cond = txtrd.fields[8]; ixWIelValid += ImeIAMStateTrig::VecWIel::COND;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJAMSTATETRIGCOND)) {
					imeijamstatetrigcond.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMStateTrig"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmApp::ImeitemIAMStateTrig::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMStateTrig::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVType", "typ", srefIxVType)) ixWIelValid += ImeIAMStateTrig::VecWIel::SREFIXVTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMEvent", "evt", srefRefWznmMEvent)) ixWIelValid += ImeIAMStateTrig::VecWIel::SREFREFWZNMMEVENT;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmMRtjob", "rtj", irefRefWznmMRtjob)) ixWIelValid += ImeIAMStateTrig::VecWIel::IREFREFWZNMMRTJOB;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIAMStateTrig::VecWIel::SREFREFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "xsref", "xsr", xsref)) ixWIelValid += ImeIAMStateTrig::VecWIel::XSREF;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMRtdpch", "rtd", srefRefWznmMRtdpch)) ixWIelValid += ImeIAMStateTrig::VecWIel::SREFREFWZNMMRTDPCH;
		if (extractStringUclc(docctx, basexpath, "srefsMask", "msk", srefsMask)) ixWIelValid += ImeIAMStateTrig::VecWIel::SREFSMASK;
		if (extractStringUclc(docctx, basexpath, "Cond", "cnd", Cond)) ixWIelValid += ImeIAMStateTrig::VecWIel::COND;
		imeijamstatetrigcond.readXML(docctx, basexpath);
	};
};

void IexWznmApp::ImeitemIAMStateTrig::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << VecWznmVAMStateTrigType::getSref(ixVType) << "\t" << srefRefWznmMEvent << "\t" << irefRefWznmMRtjob << "\t" << srefRefWznmMVectoritem << "\t" << xsref << "\t" << srefRefWznmMRtdpch << "\t" << srefsMask << "\t" << Cond << endl;
	imeijamstatetrigcond.writeTxt(outfile);
};

void IexWznmApp::ImeitemIAMStateTrig::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","typ","evt","rtj","vit","xsr","rtd","msk","cnd"};
	else tags = {"ImeitemIAMStateTrig","sref","srefIxVType","srefRefWznmMEvent","irefRefWznmMRtjob","srefRefWznmMVectoritem","xsref","srefRefWznmMRtdpch","srefsMask","Cond"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecWznmVAMStateTrigType::getSref(ixVType));
		writeString(wr, tags[3], srefRefWznmMEvent);
		writeUbigint(wr, tags[4], irefRefWznmMRtjob);
		writeString(wr, tags[5], srefRefWznmMVectoritem);
		writeString(wr, tags[6], xsref);
		writeString(wr, tags[7], srefRefWznmMRtdpch);
		writeString(wr, tags[8], srefsMask);
		writeString(wr, tags[9], Cond);
		imeijamstatetrigcond.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmApp::ImeIAMStateTrig::VecWIel
 ******************************************************************************/

uint IexWznmApp::ImeIAMStateTrig::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvtype") ix |= SREFIXVTYPE;
		else if (ss[i] == "srefrefwznmmevent") ix |= SREFREFWZNMMEVENT;
		else if (ss[i] == "irefrefwznmmrtjob") ix |= IREFREFWZNMMRTJOB;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
		else if (ss[i] == "xsref") ix |= XSREF;
		else if (ss[i] == "srefrefwznmmrtdpch") ix |= SREFREFWZNMMRTDPCH;
		else if (ss[i] == "srefsmask") ix |= SREFSMASK;
		else if (ss[i] == "cond") ix |= COND;
	};

	return(ix);
};

void IexWznmApp::ImeIAMStateTrig::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COND); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmApp::ImeIAMStateTrig::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVTYPE) ss.push_back("srefIxVType");
	if (ix & SREFREFWZNMMEVENT) ss.push_back("srefRefWznmMEvent");
	if (ix & IREFREFWZNMMRTJOB) ss.push_back("irefRefWznmMRtjob");
	if (ix & SREFREFWZNMMVECTORITEM) ss.push_back("srefRefWznmMVectoritem");
	if (ix & XSREF) ss.push_back("xsref");
	if (ix & SREFREFWZNMMRTDPCH) ss.push_back("srefRefWznmMRtdpch");
	if (ix & SREFSMASK) ss.push_back("srefsMask");
	if (ix & COND) ss.push_back("Cond");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmApp::ImeIAMStateTrig
 ******************************************************************************/

IexWznmApp::ImeIAMStateTrig::ImeIAMStateTrig() {
};

IexWznmApp::ImeIAMStateTrig::~ImeIAMStateTrig() {
	clear();
};

void IexWznmApp::ImeIAMStateTrig::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmApp::ImeIAMStateTrig::readTxt(
			Txtrd& txtrd
		) {
	IexWznmApp::ImeitemIAMStateTrig* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmApp::ImeitemIAMStateTrig();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMStateTrig"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMStateTrig"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMSTATETRIG) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMStateTrig"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMStateTrig"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmApp::ImeIAMStateTrig::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmApp::ImeitemIAMStateTrig* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMStateTrig");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMStateTrig", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMStateTrig";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmApp::ImeitemIAMStateTrig();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmApp::ImeIAMStateTrig::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMStateTrig." << StrMod::replaceChar(ImeIAMStateTrig::VecWIel::getSrefs(511), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMStateTrig.end" << endl;
	};
};

void IexWznmApp::ImeIAMStateTrig::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMStateTrig");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmApp::ImeitemIMState
 ******************************************************************************/

IexWznmApp::ImeitemIMState::ImeitemIMState(
			const string& sref
			, const string& Comment
		) : WznmMState() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexWznmApp::ImeitemIMState::ImeitemIMState(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMState()
		{
	WznmMState* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmstate->loadRecByRef(ref, &rec)) {
		seqRefWznmMSequence = rec->seqRefWznmMSequence;
		seqNum = rec->seqNum;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmApp::ImeitemIMState::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMState::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIMState::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMSTATEACTION)) {
					imeiamstateaction.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMSTATETRIG)) {
					imeiamstatetrig.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMState"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmApp::ImeitemIMState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMState::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMState::VecWIel::COMMENT;
		imeiamstateaction.readXML(docctx, basexpath);
		imeiamstatetrig.readXML(docctx, basexpath);
	};
};

void IexWznmApp::ImeitemIMState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << Comment << endl;
	imeiamstateaction.writeTxt(outfile);
	imeiamstatetrig.writeTxt(outfile);
};

void IexWznmApp::ImeitemIMState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMState","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
		imeiamstateaction.writeXML(wr, shorttags);
		imeiamstatetrig.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmApp::ImeIMState::VecWIel
 ******************************************************************************/

uint IexWznmApp::ImeIMState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmApp::ImeIMState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmApp::ImeIMState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmApp::ImeIMState
 ******************************************************************************/

IexWznmApp::ImeIMState::ImeIMState() {
};

IexWznmApp::ImeIMState::~ImeIMState() {
	clear();
};

void IexWznmApp::ImeIMState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmApp::ImeIMState::readTxt(
			Txtrd& txtrd
		) {
	IexWznmApp::ImeitemIMState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmApp::ImeitemIMState();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMState"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMState"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSTATE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMState"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMState"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmApp::ImeIMState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmApp::ImeitemIMState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMState", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmApp::ImeitemIMState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmApp::ImeIMState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMState." << StrMod::replaceChar(ImeIMState::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMState.end" << endl;
	};
};

void IexWznmApp::ImeIMState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMState");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmApp::ImeitemIMSequence
 ******************************************************************************/

IexWznmApp::ImeitemIMSequence::ImeitemIMSequence(
			const string& sref
			, const string& Title
			, const string& Comment
		) : WznmMSequence() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Title = Title;
	this->Comment = Comment;
};

IexWznmApp::ImeitemIMSequence::ImeitemIMSequence(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMSequence()
		{
	WznmMSequence* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmsequence->loadRecByRef(ref, &rec)) {
		appRefWznmMApp = rec->appRefWznmMApp;
		sref = rec->sref;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmApp::ImeitemIMSequence::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMSequence::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMSequence::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMSequence::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMSTATE)) {
					imeimstate.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSequence"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmApp::ImeitemIMSequence::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMSequence::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMSequence::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMSequence::VecWIel::COMMENT;
		imeimstate.readXML(docctx, basexpath);
	};
};

void IexWznmApp::ImeitemIMSequence::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Title << "\t" << Comment << endl;
	imeimstate.writeTxt(outfile);
};

void IexWznmApp::ImeitemIMSequence::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit","cmt"};
	else tags = {"ImeitemIMSequence","sref","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
		imeimstate.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmApp::ImeIMSequence::VecWIel
 ******************************************************************************/

uint IexWznmApp::ImeIMSequence::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmApp::ImeIMSequence::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmApp::ImeIMSequence::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmApp::ImeIMSequence
 ******************************************************************************/

IexWznmApp::ImeIMSequence::ImeIMSequence() {
};

IexWznmApp::ImeIMSequence::~ImeIMSequence() {
	clear();
};

void IexWznmApp::ImeIMSequence::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmApp::ImeIMSequence::readTxt(
			Txtrd& txtrd
		) {
	IexWznmApp::ImeitemIMSequence* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmApp::ImeitemIMSequence();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSequence"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSEQUENCE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSequence"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSequence"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmApp::ImeIMSequence::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmApp::ImeitemIMSequence* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSequence");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSequence", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSequence";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmApp::ImeitemIMSequence();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmApp::ImeIMSequence::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMSequence." << StrMod::replaceChar(ImeIMSequence::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMSequence.end" << endl;
	};
};

void IexWznmApp::ImeIMSequence::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSequence");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWznmApp
 ******************************************************************************/

void IexWznmApp::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, ImeIMEvent& imeimevent
			, ImeIMRtjob& imeimrtjob
			, ImeIMSequence& imeimsequence
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimevent, imeimrtjob, imeimsequence);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, "IexWznmApp", Version("1.0.2"), VecVIme::getIx);
			readTxt(rd, imeimevent, imeimrtjob, imeimsequence);
	};
};

void IexWznmApp::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMEvent& imeimevent
			, ImeIMRtjob& imeimrtjob
			, ImeIMSequence& imeimsequence
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimevent, imeimrtjob, imeimsequence);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimevent, imeimrtjob, imeimsequence);
		txtfile.close();
	};
};

void IexWznmApp::readTxt(
			Txtrd& txtrd
			, ImeIMEvent& imeimevent
			, ImeIMRtjob& imeimrtjob
			, ImeIMSequence& imeimsequence
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMEVENT)) imeimevent.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMRTJOB)) imeimrtjob.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMSEQUENCE)) imeimsequence.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWznmApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMEvent& imeimevent
			, ImeIMRtjob& imeimrtjob
			, ImeIMSequence& imeimsequence
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmApp")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("1.0.2")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","1.0.2"}});
		};

		// look for XML sub-blocks
		imeimevent.readXML(docctx, basexpath);
		imeimrtjob.readXML(docctx, basexpath);
		imeimsequence.readXML(docctx, basexpath);

	} else {
		imeimevent = ImeIMEvent();
		imeimrtjob = ImeIMRtjob();
		imeimsequence = ImeIMSequence();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmApp"}});
	};
};

void IexWznmApp::writeTxt(
			fstream& outfile
			, ImeIMEvent& imeimevent
			, ImeIMRtjob& imeimrtjob
			, ImeIMSequence& imeimsequence
		) {
	outfile << "IexWznmApp v" WZNM_VERSION << endl;

	imeimevent.writeTxt(outfile);
	imeimrtjob.writeTxt(outfile);
	imeimsequence.writeTxt(outfile);
};

void IexWznmApp::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMEvent& imeimevent
			, ImeIMRtjob& imeimrtjob
			, ImeIMSequence& imeimsequence
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmApp");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeimevent.writeXML(wr, shorttags);
		imeimrtjob.writeXML(wr, shorttags);
		imeimsequence.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmApp::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMSTATEACTION,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMSTATETRIG,VecWznmVIop::INS},{(uint)VecVIme::IMEIJAMSTATETRIGCOND,VecWznmVIop::INS},{(uint)VecVIme::IMEIMEVENT,VecWznmVIop::INS},{(uint)VecVIme::IMEIMRTBLOCK,VecWznmVIop::INS},{(uint)VecVIme::IMEIMRTDPCH,VecWznmVIop::INS},{(uint)VecVIme::IMEIMRTJOB,VecWznmVIop::INS},{(uint)VecVIme::IMEIMSEQUENCE,VecWznmVIop::INS},{(uint)VecVIme::IMEIMSTATE,VecWznmVIop::INS}};
};

uint IexWznmApp::getIxWznmVIop(
			const map<uint,uint>& icsWznmVIop
			, const uint ixVIme
			, uint& ixWznmVIop
		) {
	ixWznmVIop = 0;

	auto it = icsWznmVIop.find(ixVIme);
	if (it != icsWznmVIop.end()) ixWznmVIop = it->second;

	return ixWznmVIop;
};

