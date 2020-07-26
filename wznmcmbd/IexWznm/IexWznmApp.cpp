/**
	* \file IexWznmApp.cpp
	* data blocks and readers/writers for import/export complex IexWznmApp (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
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

	if (s == "imeiamstatestep") return IMEIAMSTATESTEP;
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
	if (ix == IMEIAMSTATESTEP) return("ImeIAMStateStep");
	if (ix == IMEIMRTBLOCK) return("ImeIMRtblock");
	if (ix == IMEIMRTDPCH) return("ImeIMRtdpch");
	if (ix == IMEIMRTJOB) return("ImeIMRtjob");
	if (ix == IMEIMSEQUENCE) return("ImeIMSequence");
	if (ix == IMEIMSTATE) return("ImeIMState");

	return("");
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
 class IexWznmApp::ImeitemIAMStateStep
 ******************************************************************************/

IexWznmApp::ImeitemIAMStateStep::ImeitemIAMStateStep(
			const string& srefSnxRefWznmMState
			, const uint ixVTrigger
			, const ubigint irefRefWznmMRtjob
			, const string& srefRefWznmMVectoritem
			, const string& xsref
			, const string& srefRefWznmMRtdpch
			, const string& srefsMask
			, const string& Cond
			, const bool Custcode
		) : WznmAMStateStep() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefSnxRefWznmMState = srefSnxRefWznmMState;
	this->ixVTrigger = ixVTrigger;
	this->irefRefWznmMRtjob = irefRefWznmMRtjob;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
	this->xsref = xsref;
	this->srefRefWznmMRtdpch = srefRefWznmMRtdpch;
	this->srefsMask = srefsMask;
	this->Cond = Cond;
	this->Custcode = Custcode;
};

IexWznmApp::ImeitemIAMStateStep::ImeitemIAMStateStep(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMStateStep()
		{
	WznmAMStateStep* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamstatestep->loadRecByRef(ref, &rec)) {
		refWznmMState = rec->refWznmMState;
		snxRefWznmMState = rec->snxRefWznmMState;
		ixVTrigger = rec->ixVTrigger;
		refWznmMRtjob = rec->refWznmMRtjob;
		refWznmMVectoritem = rec->refWznmMVectoritem;
		xsref = rec->xsref;
		refWznmMRtdpch = rec->refWznmMRtdpch;
		srefsMask = rec->srefsMask;
		Cond = rec->Cond;
		Custcode = rec->Custcode;

		delete rec;
	};
};

void IexWznmApp::ImeitemIAMStateStep::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefSnxRefWznmMState = txtrd.fields[0]; ixWIelValid += ImeIAMStateStep::VecWIel::SREFSNXREFWZNMMSTATE;};
	if (txtrd.fields.size() > 1) {srefIxVTrigger = txtrd.fields[1]; ixWIelValid += ImeIAMStateStep::VecWIel::SREFIXVTRIGGER;};
	if (txtrd.fields.size() > 2) {irefRefWznmMRtjob = atoll(txtrd.fields[2].c_str()); ixWIelValid += ImeIAMStateStep::VecWIel::IREFREFWZNMMRTJOB;};
	if (txtrd.fields.size() > 3) {srefRefWznmMVectoritem = txtrd.fields[3]; ixWIelValid += ImeIAMStateStep::VecWIel::SREFREFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 4) {xsref = txtrd.fields[4]; ixWIelValid += ImeIAMStateStep::VecWIel::XSREF;};
	if (txtrd.fields.size() > 5) {srefRefWznmMRtdpch = txtrd.fields[5]; ixWIelValid += ImeIAMStateStep::VecWIel::SREFREFWZNMMRTDPCH;};
	if (txtrd.fields.size() > 6) {srefsMask = txtrd.fields[6]; ixWIelValid += ImeIAMStateStep::VecWIel::SREFSMASK;};
	if (txtrd.fields.size() > 7) {Cond = txtrd.fields[7]; ixWIelValid += ImeIAMStateStep::VecWIel::COND;};
	if (txtrd.fields.size() > 8) {Custcode = (txtrd.fields[8] == "true"); ixWIelValid += ImeIAMStateStep::VecWIel::CUSTCODE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMStateStep"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmApp::ImeitemIAMStateStep::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefSnxRefWznmMState", "snx", srefSnxRefWznmMState)) ixWIelValid += ImeIAMStateStep::VecWIel::SREFSNXREFWZNMMSTATE;
		if (extractStringUclc(docctx, basexpath, "srefIxVTrigger", "trg", srefIxVTrigger)) ixWIelValid += ImeIAMStateStep::VecWIel::SREFIXVTRIGGER;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmMRtjob", "rtj", irefRefWznmMRtjob)) ixWIelValid += ImeIAMStateStep::VecWIel::IREFREFWZNMMRTJOB;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIAMStateStep::VecWIel::SREFREFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "xsref", "xsr", xsref)) ixWIelValid += ImeIAMStateStep::VecWIel::XSREF;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMRtdpch", "rtd", srefRefWznmMRtdpch)) ixWIelValid += ImeIAMStateStep::VecWIel::SREFREFWZNMMRTDPCH;
		if (extractStringUclc(docctx, basexpath, "srefsMask", "msk", srefsMask)) ixWIelValid += ImeIAMStateStep::VecWIel::SREFSMASK;
		if (extractStringUclc(docctx, basexpath, "Cond", "cnd", Cond)) ixWIelValid += ImeIAMStateStep::VecWIel::COND;
		if (extractBoolUclc(docctx, basexpath, "Custcode", "ccd", Custcode)) ixWIelValid += ImeIAMStateStep::VecWIel::CUSTCODE;
	};
};

void IexWznmApp::ImeitemIAMStateStep::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefSnxRefWznmMState << "\t" << VecWznmVAMStateStepTrigger::getSref(ixVTrigger) << "\t" << irefRefWznmMRtjob << "\t" << srefRefWznmMVectoritem << "\t" << xsref << "\t" << srefRefWznmMRtdpch << "\t" << srefsMask << "\t" << Cond << "\t" << StrMod::boolToString(Custcode) << endl;
};

void IexWznmApp::ImeitemIAMStateStep::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","snx","trg","rtj","vit","xsr","rtd","msk","cnd","ccd"};
	else tags = {"ImeitemIAMStateStep","srefSnxRefWznmMState","srefIxVTrigger","irefRefWznmMRtjob","srefRefWznmMVectoritem","xsref","srefRefWznmMRtdpch","srefsMask","Cond","Custcode"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefSnxRefWznmMState);
		writeString(wr, tags[2], VecWznmVAMStateStepTrigger::getSref(ixVTrigger));
		writeUbigint(wr, tags[3], irefRefWznmMRtjob);
		writeString(wr, tags[4], srefRefWznmMVectoritem);
		writeString(wr, tags[5], xsref);
		writeString(wr, tags[6], srefRefWznmMRtdpch);
		writeString(wr, tags[7], srefsMask);
		writeString(wr, tags[8], Cond);
		writeBool(wr, tags[9], Custcode);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmApp::ImeIAMStateStep::VecWIel
 ******************************************************************************/

uint IexWznmApp::ImeIAMStateStep::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefsnxrefwznmmstate") ix |= SREFSNXREFWZNMMSTATE;
		else if (ss[i] == "srefixvtrigger") ix |= SREFIXVTRIGGER;
		else if (ss[i] == "irefrefwznmmrtjob") ix |= IREFREFWZNMMRTJOB;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
		else if (ss[i] == "xsref") ix |= XSREF;
		else if (ss[i] == "srefrefwznmmrtdpch") ix |= SREFREFWZNMMRTDPCH;
		else if (ss[i] == "srefsmask") ix |= SREFSMASK;
		else if (ss[i] == "cond") ix |= COND;
		else if (ss[i] == "custcode") ix |= CUSTCODE;
	};

	return(ix);
};

void IexWznmApp::ImeIAMStateStep::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*CUSTCODE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmApp::ImeIAMStateStep::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFSNXREFWZNMMSTATE) ss.push_back("srefSnxRefWznmMState");
	if (ix & SREFIXVTRIGGER) ss.push_back("srefIxVTrigger");
	if (ix & IREFREFWZNMMRTJOB) ss.push_back("irefRefWznmMRtjob");
	if (ix & SREFREFWZNMMVECTORITEM) ss.push_back("srefRefWznmMVectoritem");
	if (ix & XSREF) ss.push_back("xsref");
	if (ix & SREFREFWZNMMRTDPCH) ss.push_back("srefRefWznmMRtdpch");
	if (ix & SREFSMASK) ss.push_back("srefsMask");
	if (ix & COND) ss.push_back("Cond");
	if (ix & CUSTCODE) ss.push_back("Custcode");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmApp::ImeIAMStateStep
 ******************************************************************************/

IexWznmApp::ImeIAMStateStep::ImeIAMStateStep() {
};

IexWznmApp::ImeIAMStateStep::~ImeIAMStateStep() {
	clear();
};

void IexWznmApp::ImeIAMStateStep::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmApp::ImeIAMStateStep::readTxt(
			Txtrd& txtrd
		) {
	IexWznmApp::ImeitemIAMStateStep* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmApp::ImeitemIAMStateStep();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMStateStep"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMStateStep"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMSTATESTEP) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMStateStep"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMStateStep"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmApp::ImeIAMStateStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmApp::ImeitemIAMStateStep* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMStateStep");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMStateStep", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMStateStep";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmApp::ImeitemIAMStateStep();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmApp::ImeIAMStateStep::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMStateStep." << StrMod::replaceChar(ImeIAMStateStep::VecWIel::getSrefs(511), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMStateStep.end" << endl;
	};
};

void IexWznmApp::ImeIAMStateStep::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMStateStep");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmApp::ImeitemIMState
 ******************************************************************************/

IexWznmApp::ImeitemIMState::ImeitemIMState(
			const string& sref
			, const uint eacIxVAction
			, const ubigint irefErjRefWznmMRtjob
			, const string& srefEveRefWznmMVector
			, const string& srefEviRefWznmMVectoritem
			, const string& srefEsnRefWznmMState
			, const uint lacIxVAction
			, const bool Custstep
			, const string& Comment
		) : WznmMState() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->eacIxVAction = eacIxVAction;
	this->irefErjRefWznmMRtjob = irefErjRefWznmMRtjob;
	this->srefEveRefWznmMVector = srefEveRefWznmMVector;
	this->srefEviRefWznmMVectoritem = srefEviRefWznmMVectoritem;
	this->srefEsnRefWznmMState = srefEsnRefWznmMState;
	this->lacIxVAction = lacIxVAction;
	this->Custstep = Custstep;
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
		eacIxVAction = rec->eacIxVAction;
		erjRefWznmMRtjob = rec->erjRefWznmMRtjob;
		eveRefWznmMVector = rec->eveRefWznmMVector;
		eviRefWznmMVectoritem = rec->eviRefWznmMVectoritem;
		esnRefWznmMState = rec->esnRefWznmMState;
		lacIxVAction = rec->lacIxVAction;
		Custstep = rec->Custstep;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmApp::ImeitemIMState::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMState::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefEacIxVAction = txtrd.fields[1]; ixWIelValid += ImeIMState::VecWIel::SREFEACIXVACTION;};
	if (txtrd.fields.size() > 2) {irefErjRefWznmMRtjob = atoll(txtrd.fields[2].c_str()); ixWIelValid += ImeIMState::VecWIel::IREFERJREFWZNMMRTJOB;};
	if (txtrd.fields.size() > 3) {srefEveRefWznmMVector = txtrd.fields[3]; ixWIelValid += ImeIMState::VecWIel::SREFEVEREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 4) {srefEviRefWznmMVectoritem = txtrd.fields[4]; ixWIelValid += ImeIMState::VecWIel::SREFEVIREFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 5) {srefEsnRefWznmMState = txtrd.fields[5]; ixWIelValid += ImeIMState::VecWIel::SREFESNREFWZNMMSTATE;};
	if (txtrd.fields.size() > 6) {srefLacIxVAction = txtrd.fields[6]; ixWIelValid += ImeIMState::VecWIel::SREFLACIXVACTION;};
	if (txtrd.fields.size() > 7) {Custstep = (txtrd.fields[7] == "true"); ixWIelValid += ImeIMState::VecWIel::CUSTSTEP;};
	if (txtrd.fields.size() > 8) {Comment = txtrd.fields[8]; ixWIelValid += ImeIMState::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMSTATESTEP)) {
					imeiamstatestep.readTxt(txtrd);
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
		if (extractStringUclc(docctx, basexpath, "srefEacIxVAction", "eac", srefEacIxVAction)) ixWIelValid += ImeIMState::VecWIel::SREFEACIXVACTION;
		if (extractUbigintUclc(docctx, basexpath, "irefErjRefWznmMRtjob", "erj", irefErjRefWznmMRtjob)) ixWIelValid += ImeIMState::VecWIel::IREFERJREFWZNMMRTJOB;
		if (extractStringUclc(docctx, basexpath, "srefEveRefWznmMVector", "eve", srefEveRefWznmMVector)) ixWIelValid += ImeIMState::VecWIel::SREFEVEREFWZNMMVECTOR;
		if (extractStringUclc(docctx, basexpath, "srefEviRefWznmMVectoritem", "evi", srefEviRefWznmMVectoritem)) ixWIelValid += ImeIMState::VecWIel::SREFEVIREFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "srefEsnRefWznmMState", "esn", srefEsnRefWznmMState)) ixWIelValid += ImeIMState::VecWIel::SREFESNREFWZNMMSTATE;
		if (extractStringUclc(docctx, basexpath, "srefLacIxVAction", "lac", srefLacIxVAction)) ixWIelValid += ImeIMState::VecWIel::SREFLACIXVACTION;
		if (extractBoolUclc(docctx, basexpath, "Custstep", "cst", Custstep)) ixWIelValid += ImeIMState::VecWIel::CUSTSTEP;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMState::VecWIel::COMMENT;
		imeiamstatestep.readXML(docctx, basexpath);
	};
};

void IexWznmApp::ImeitemIMState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << VecWznmVMStateAction::getSref(eacIxVAction) << "\t" << irefErjRefWznmMRtjob << "\t" << srefEveRefWznmMVector << "\t" << srefEviRefWznmMVectoritem << "\t" << srefEsnRefWznmMState << "\t" << VecWznmVMStateAction::getSref(lacIxVAction) << "\t" << StrMod::boolToString(Custstep) << "\t" << Comment << endl;
	imeiamstatestep.writeTxt(outfile);
};

void IexWznmApp::ImeitemIMState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","eac","erj","eve","evi","esn","lac","cst","cmt"};
	else tags = {"ImeitemIMState","sref","srefEacIxVAction","irefErjRefWznmMRtjob","srefEveRefWznmMVector","srefEviRefWznmMVectoritem","srefEsnRefWznmMState","srefLacIxVAction","Custstep","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecWznmVMStateAction::getSref(eacIxVAction));
		writeUbigint(wr, tags[3], irefErjRefWznmMRtjob);
		writeString(wr, tags[4], srefEveRefWznmMVector);
		writeString(wr, tags[5], srefEviRefWznmMVectoritem);
		writeString(wr, tags[6], srefEsnRefWznmMState);
		writeString(wr, tags[7], VecWznmVMStateAction::getSref(lacIxVAction));
		writeBool(wr, tags[8], Custstep);
		writeString(wr, tags[9], Comment);
		imeiamstatestep.writeXML(wr, shorttags);
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
		else if (ss[i] == "srefeacixvaction") ix |= SREFEACIXVACTION;
		else if (ss[i] == "ireferjrefwznmmrtjob") ix |= IREFERJREFWZNMMRTJOB;
		else if (ss[i] == "srefeverefwznmmvector") ix |= SREFEVEREFWZNMMVECTOR;
		else if (ss[i] == "srefevirefwznmmvectoritem") ix |= SREFEVIREFWZNMMVECTORITEM;
		else if (ss[i] == "srefesnrefwznmmstate") ix |= SREFESNREFWZNMMSTATE;
		else if (ss[i] == "sreflacixvaction") ix |= SREFLACIXVACTION;
		else if (ss[i] == "custstep") ix |= CUSTSTEP;
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
	if (ix & SREFEACIXVACTION) ss.push_back("srefEacIxVAction");
	if (ix & IREFERJREFWZNMMRTJOB) ss.push_back("irefErjRefWznmMRtjob");
	if (ix & SREFEVEREFWZNMMVECTOR) ss.push_back("srefEveRefWznmMVector");
	if (ix & SREFEVIREFWZNMMVECTORITEM) ss.push_back("srefEviRefWznmMVectoritem");
	if (ix & SREFESNREFWZNMMSTATE) ss.push_back("srefEsnRefWznmMState");
	if (ix & SREFLACIXVACTION) ss.push_back("srefLacIxVAction");
	if (ix & CUSTSTEP) ss.push_back("Custstep");
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
		outfile << "\tImeIMState." << StrMod::replaceChar(ImeIMState::VecWIel::getSrefs(511), ';', '\t') << endl;
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
			, ImeIMRtjob& imeimrtjob
			, ImeIMSequence& imeimsequence
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimrtjob, imeimsequence);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, "IexWznmApp", Version(""), VecVIme::getIx);
			readTxt(rd, imeimrtjob, imeimsequence);
	};
};

void IexWznmApp::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMRtjob& imeimrtjob
			, ImeIMSequence& imeimsequence
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimrtjob, imeimsequence);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimrtjob, imeimsequence);
		txtfile.close();
	};
};

void IexWznmApp::readTxt(
			Txtrd& txtrd
			, ImeIMRtjob& imeimrtjob
			, ImeIMSequence& imeimsequence
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMRTJOB)) imeimrtjob.readTxt(txtrd);
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
			, ImeIMRtjob& imeimrtjob
			, ImeIMSequence& imeimsequence
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmApp")) {

		// look for XML sub-blocks
		imeimrtjob.readXML(docctx, basexpath);
		imeimsequence.readXML(docctx, basexpath);

	} else {
		imeimrtjob = ImeIMRtjob();
		imeimsequence = ImeIMSequence();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmApp"}});
	};
};

void IexWznmApp::writeTxt(
			fstream& outfile
			, ImeIMRtjob& imeimrtjob
			, ImeIMSequence& imeimsequence
		) {
	outfile << "IexWznmApp v" WZNM_VERSION << endl;

	imeimrtjob.writeTxt(outfile);
	imeimsequence.writeTxt(outfile);
};

void IexWznmApp::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMRtjob& imeimrtjob
			, ImeIMSequence& imeimsequence
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmApp");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeimrtjob.writeXML(wr, shorttags);
		imeimsequence.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmApp::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMSTATESTEP,VecWznmVIop::INS},{(uint)VecVIme::IMEIMRTBLOCK,VecWznmVIop::INS},{(uint)VecVIme::IMEIMRTDPCH,VecWznmVIop::INS},{(uint)VecVIme::IMEIMRTJOB,VecWznmVIop::INS},{(uint)VecVIme::IMEIMSEQUENCE,VecWznmVIop::INS},{(uint)VecVIme::IMEIMSTATE,VecWznmVIop::INS}};
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

