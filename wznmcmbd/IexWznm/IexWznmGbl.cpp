/**
	* \file IexWznmGbl.cpp
	* data blocks and readers/writers for import/export complex IexWznmGbl (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "IexWznmGbl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWznmGbl::VecVIme
 ******************************************************************************/

uint IexWznmGbl::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamblockitem") return IMEIAMBLOCKITEM;
	if (s == "imeiamcapabilitypar") return IMEIAMCAPABILITYPAR;
	if (s == "imeiamvectortitle") return IMEIAMVECTORTITLE;
	if (s == "imeicamblockitem") return IMEICAMBLOCKITEM;
	if (s == "imeijamblockitem") return IMEIJAMBLOCKITEM;
	if (s == "imeijmerrortitle") return IMEIJMERRORTITLE;
	if (s == "imeijmvectoritem") return IMEIJMVECTORITEM;
	if (s == "imeimblock") return IMEIMBLOCK;
	if (s == "imeimcapability") return IMEIMCAPABILITY;
	if (s == "imeimerror") return IMEIMERROR;
	if (s == "imeimvector") return IMEIMVECTOR;
	if (s == "imeimvectoritem") return IMEIMVECTORITEM;

	return(0);
};

string IexWznmGbl::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMBLOCKITEM) return("ImeIAMBlockItem");
	if (ix == IMEIAMCAPABILITYPAR) return("ImeIAMCapabilityPar");
	if (ix == IMEIAMVECTORTITLE) return("ImeIAMVectorTitle");
	if (ix == IMEICAMBLOCKITEM) return("ImeICAMBlockItem");
	if (ix == IMEIJAMBLOCKITEM) return("ImeIJAMBlockItem");
	if (ix == IMEIJMERRORTITLE) return("ImeIJMErrorTitle");
	if (ix == IMEIJMVECTORITEM) return("ImeIJMVectoritem");
	if (ix == IMEIMBLOCK) return("ImeIMBlock");
	if (ix == IMEIMCAPABILITY) return("ImeIMCapability");
	if (ix == IMEIMERROR) return("ImeIMError");
	if (ix == IMEIMVECTOR) return("ImeIMVector");
	if (ix == IMEIMVECTORITEM) return("ImeIMVectoritem");

	return("");
};

/******************************************************************************
 class IexWznmGbl::ImeitemIJAMBlockItem
 ******************************************************************************/

IexWznmGbl::ImeitemIJAMBlockItem::ImeitemIJAMBlockItem(
			const string& srefX1RefWznmMRelease
			, const string& Defval
		) : WznmJAMBlockItem() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMRelease = srefX1RefWznmMRelease;
	this->Defval = Defval;
};

IexWznmGbl::ImeitemIJAMBlockItem::ImeitemIJAMBlockItem(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJAMBlockItem()
		{
	WznmJAMBlockItem* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjamblockitem->loadRecByRef(ref, &rec)) {
		refWznmAMBlockItem = rec->refWznmAMBlockItem;
		x1RefWznmMRelease = rec->x1RefWznmMRelease;
		Defval = rec->Defval;

		delete rec;
	};
};

void IexWznmGbl::ImeitemIJAMBlockItem::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMRelease = txtrd.fields[0]; ixWIelValid += ImeIJAMBlockItem::VecWIel::SREFX1REFWZNMMRELEASE;};
	if (txtrd.fields.size() > 1) {Defval = txtrd.fields[1]; ixWIelValid += ImeIJAMBlockItem::VecWIel::DEFVAL;};

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

void IexWznmGbl::ImeitemIJAMBlockItem::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMRelease", "rls", srefX1RefWznmMRelease)) ixWIelValid += ImeIJAMBlockItem::VecWIel::SREFX1REFWZNMMRELEASE;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIJAMBlockItem::VecWIel::DEFVAL;
	};
};

void IexWznmGbl::ImeitemIJAMBlockItem::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefX1RefWznmMRelease << "\t" << Defval << endl;
};

void IexWznmGbl::ImeitemIJAMBlockItem::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","rls","dfv"};
	else tags = {"ImeitemIJAMBlockItem","srefX1RefWznmMRelease","Defval"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMRelease);
		writeString(wr, tags[2], Defval);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmGbl::ImeIJAMBlockItem::VecWIel
 ******************************************************************************/

uint IexWznmGbl::ImeIJAMBlockItem::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1refwznmmrelease") ix |= SREFX1REFWZNMMRELEASE;
		else if (ss[i] == "defval") ix |= DEFVAL;
	};

	return(ix);
};

void IexWznmGbl::ImeIJAMBlockItem::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*DEFVAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmGbl::ImeIJAMBlockItem::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1REFWZNMMRELEASE) ss.push_back("srefX1RefWznmMRelease");
	if (ix & DEFVAL) ss.push_back("Defval");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmGbl::ImeIJAMBlockItem
 ******************************************************************************/

IexWznmGbl::ImeIJAMBlockItem::ImeIJAMBlockItem() {
};

IexWznmGbl::ImeIJAMBlockItem::~ImeIJAMBlockItem() {
	clear();
};

void IexWznmGbl::ImeIJAMBlockItem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmGbl::ImeIJAMBlockItem::readTxt(
			Txtrd& txtrd
		) {
	IexWznmGbl::ImeitemIJAMBlockItem* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmGbl::ImeitemIJAMBlockItem();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
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

void IexWznmGbl::ImeIJAMBlockItem::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmGbl::ImeitemIJAMBlockItem* ii = NULL;

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

			ii = new IexWznmGbl::ImeitemIJAMBlockItem();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmGbl::ImeIJAMBlockItem::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJAMBlockItem." << StrMod::replaceChar(ImeIJAMBlockItem::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJAMBlockItem.end" << endl;
	};
};

void IexWznmGbl::ImeIJAMBlockItem::writeXML(
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
 class IexWznmGbl::ImeitemIAMBlockItem
 ******************************************************************************/

IexWznmGbl::ImeitemIAMBlockItem::ImeitemIAMBlockItem(
			const ubigint irefRefWznmCAMBlockItem
			, const uint ixVBasetype
			, const string& sref
			, const uint ixWznmVVartype
			, const string& Defval
			, const string& Comment
		) : WznmAMBlockItem() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWznmCAMBlockItem = irefRefWznmCAMBlockItem;
	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->Defval = Defval;
	this->Comment = Comment;
};

IexWznmGbl::ImeitemIAMBlockItem::ImeitemIAMBlockItem(
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
		refJ = rec->refJ;
		Defval = rec->Defval;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmGbl::ImeitemIAMBlockItem::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWznmCAMBlockItem = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIAMBlockItem::VecWIel::IREFREFWZNMCAMBLOCKITEM;};
	if (txtrd.fields.size() > 1) {srefIxVBasetype = txtrd.fields[1]; ixWIelValid += ImeIAMBlockItem::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIAMBlockItem::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {srefIxWznmVVartype = txtrd.fields[3]; ixWIelValid += ImeIAMBlockItem::VecWIel::SREFIXWZNMVVARTYPE;};
	if (txtrd.fields.size() > 4) {Defval = txtrd.fields[4]; ixWIelValid += ImeIAMBlockItem::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIAMBlockItem::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJAMBLOCKITEM)) {
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

void IexWznmGbl::ImeitemIAMBlockItem::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCAMBlockItem", "clu", irefRefWznmCAMBlockItem)) ixWIelValid += ImeIAMBlockItem::VecWIel::IREFREFWZNMCAMBLOCKITEM;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIAMBlockItem::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMBlockItem::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype)) ixWIelValid += ImeIAMBlockItem::VecWIel::SREFIXWZNMVVARTYPE;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIAMBlockItem::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMBlockItem::VecWIel::COMMENT;
		imeijamblockitem.readXML(docctx, basexpath);
	};
};

void IexWznmGbl::ImeitemIAMBlockItem::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << irefRefWznmCAMBlockItem << "\t" << VecWznmVAMBlockItemBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << VecWznmVVartype::getSref(ixWznmVVartype) << "\t" << Defval << "\t" << Comment << endl;
	imeijamblockitem.writeTxt(outfile);
};

void IexWznmGbl::ImeitemIAMBlockItem::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","typ","srf","vty","dfv","cmt"};
	else tags = {"ImeitemIAMBlockItem","irefRefWznmCAMBlockItem","srefIxVBasetype","sref","srefIxWznmVVartype","Defval","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWznmCAMBlockItem);
		writeString(wr, tags[2], VecWznmVAMBlockItemBasetype::getSref(ixVBasetype));
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], VecWznmVVartype::getSref(ixWznmVVartype));
		writeString(wr, tags[5], Defval);
		writeString(wr, tags[6], Comment);
		imeijamblockitem.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmGbl::ImeIAMBlockItem::VecWIel
 ******************************************************************************/

uint IexWznmGbl::ImeIAMBlockItem::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwznmcamblockitem") ix |= IREFREFWZNMCAMBLOCKITEM;
		else if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmvvartype") ix |= SREFIXWZNMVVARTYPE;
		else if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmGbl::ImeIAMBlockItem::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmGbl::ImeIAMBlockItem::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWZNMCAMBLOCKITEM) ss.push_back("irefRefWznmCAMBlockItem");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXWZNMVVARTYPE) ss.push_back("srefIxWznmVVartype");
	if (ix & DEFVAL) ss.push_back("Defval");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmGbl::ImeIAMBlockItem
 ******************************************************************************/

IexWznmGbl::ImeIAMBlockItem::ImeIAMBlockItem() {
};

IexWznmGbl::ImeIAMBlockItem::~ImeIAMBlockItem() {
	clear();
};

void IexWznmGbl::ImeIAMBlockItem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmGbl::ImeIAMBlockItem::readTxt(
			Txtrd& txtrd
		) {
	IexWznmGbl::ImeitemIAMBlockItem* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmGbl::ImeitemIAMBlockItem();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
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

void IexWznmGbl::ImeIAMBlockItem::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmGbl::ImeitemIAMBlockItem* ii = NULL;

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

			ii = new IexWznmGbl::ImeitemIAMBlockItem();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmGbl::ImeIAMBlockItem::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMBlockItem." << StrMod::replaceChar(ImeIAMBlockItem::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMBlockItem.end" << endl;
	};
};

void IexWznmGbl::ImeIAMBlockItem::writeXML(
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
 class IexWznmGbl::ImeitemICAMBlockItem
 ******************************************************************************/

IexWznmGbl::ImeitemICAMBlockItem::ImeitemICAMBlockItem(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmGbl::ImeitemICAMBlockItem::ImeitemICAMBlockItem(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICAMBlockItem()
		{
};

void IexWznmGbl::ImeitemICAMBlockItem::readTxt(
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

void IexWznmGbl::ImeitemICAMBlockItem::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICAMBlockItem::VecWIel::IREF;
	};
};

void IexWznmGbl::ImeitemICAMBlockItem::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << iref << endl;
};

void IexWznmGbl::ImeitemICAMBlockItem::writeXML(
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
 class IexWznmGbl::ImeICAMBlockItem::VecWIel
 ******************************************************************************/

uint IexWznmGbl::ImeICAMBlockItem::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWznmGbl::ImeICAMBlockItem::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmGbl::ImeICAMBlockItem::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmGbl::ImeICAMBlockItem
 ******************************************************************************/

IexWznmGbl::ImeICAMBlockItem::ImeICAMBlockItem() {
};

IexWznmGbl::ImeICAMBlockItem::~ImeICAMBlockItem() {
	clear();
};

void IexWznmGbl::ImeICAMBlockItem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmGbl::ImeICAMBlockItem::readTxt(
			Txtrd& txtrd
		) {
	IexWznmGbl::ImeitemICAMBlockItem* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmGbl::ImeitemICAMBlockItem();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
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

void IexWznmGbl::ImeICAMBlockItem::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmGbl::ImeitemICAMBlockItem* ii = NULL;

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

			ii = new IexWznmGbl::ImeitemICAMBlockItem();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmGbl::ImeICAMBlockItem::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeICAMBlockItem." << StrMod::replaceChar(ImeICAMBlockItem::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeICAMBlockItem.end" << endl;
	};
};

void IexWznmGbl::ImeICAMBlockItem::writeXML(
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
 class IexWznmGbl::ImeitemIMBlock
 ******************************************************************************/

IexWznmGbl::ImeitemIMBlock::ImeitemIMBlock(
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

IexWznmGbl::ImeitemIMBlock::ImeitemIMBlock(
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
		reaIxWznmWScope = rec->reaIxWznmWScope;
		wriIxWznmWScope = rec->wriIxWznmWScope;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmGbl::ImeitemIMBlock::readTxt(
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
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMBLOCKITEM)) {
					imeiamblockitem.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEICAMBLOCKITEM)) {
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

void IexWznmGbl::ImeitemIMBlock::readXML(
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

void IexWznmGbl::ImeitemIMBlock::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmWScope::getSrefs(reaIxWznmWScope) << "\t" << VecWznmWScope::getSrefs(wriIxWznmWScope) << "\t" << sref << "\t" << Comment << endl;
	imeiamblockitem.writeTxt(outfile);
	imeicamblockitem.writeTxt(outfile);
};

void IexWznmGbl::ImeitemIMBlock::writeXML(
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
 class IexWznmGbl::ImeIMBlock::VecWIel
 ******************************************************************************/

uint IexWznmGbl::ImeIMBlock::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefsreaixwznmwscope") ix |= SREFSREAIXWZNMWSCOPE;
		else if (ss[i] == "srefswriixwznmwscope") ix |= SREFSWRIIXWZNMWSCOPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmGbl::ImeIMBlock::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmGbl::ImeIMBlock::VecWIel::getSrefs(
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
 class IexWznmGbl::ImeIMBlock
 ******************************************************************************/

IexWznmGbl::ImeIMBlock::ImeIMBlock() {
};

IexWznmGbl::ImeIMBlock::~ImeIMBlock() {
	clear();
};

void IexWznmGbl::ImeIMBlock::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmGbl::ImeIMBlock::readTxt(
			Txtrd& txtrd
		) {
	IexWznmGbl::ImeitemIMBlock* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmGbl::ImeitemIMBlock();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

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

void IexWznmGbl::ImeIMBlock::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmGbl::ImeitemIMBlock* ii = NULL;

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

			ii = new IexWznmGbl::ImeitemIMBlock();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmGbl::ImeIMBlock::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMBlock." << StrMod::replaceChar(ImeIMBlock::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMBlock.end" << endl;
	};
};

void IexWznmGbl::ImeIMBlock::writeXML(
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
 class IexWznmGbl::ImeitemIAMCapabilityPar
 ******************************************************************************/

IexWznmGbl::ImeitemIAMCapabilityPar::ImeitemIAMCapabilityPar(
			const string& x1SrefKKey
			, const string& Val
		) : WznmAMCapabilityPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

IexWznmGbl::ImeitemIAMCapabilityPar::ImeitemIAMCapabilityPar(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMCapabilityPar()
		{
	WznmAMCapabilityPar* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamcapabilitypar->loadRecByRef(ref, &rec)) {
		cpbRefWznmMCapability = rec->cpbRefWznmMCapability;
		cpbNum = rec->cpbNum;
		x1SrefKKey = rec->x1SrefKKey;
		Val = rec->Val;

		delete rec;
	};
};

void IexWznmGbl::ImeitemIAMCapabilityPar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {x1SrefKKey = txtrd.fields[0]; ixWIelValid += ImeIAMCapabilityPar::VecWIel::X1SREFKKEY;};
	if (txtrd.fields.size() > 1) {Val = txtrd.fields[1]; ixWIelValid += ImeIAMCapabilityPar::VecWIel::VAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCapabilityPar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmGbl::ImeitemIAMCapabilityPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMCapabilityPar::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMCapabilityPar::VecWIel::VAL;
	};
};

void IexWznmGbl::ImeitemIAMCapabilityPar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x1SrefKKey << "\t" << Val << endl;
};

void IexWznmGbl::ImeitemIAMCapabilityPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","key","val"};
	else tags = {"ImeitemIAMCapabilityPar","x1SrefKKey","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKKey);
		writeString(wr, tags[2], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmGbl::ImeIAMCapabilityPar::VecWIel
 ******************************************************************************/

uint IexWznmGbl::ImeIAMCapabilityPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "x1srefkkey") ix |= X1SREFKKEY;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWznmGbl::ImeIAMCapabilityPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmGbl::ImeIAMCapabilityPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1SREFKKEY) ss.push_back("x1SrefKKey");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmGbl::ImeIAMCapabilityPar
 ******************************************************************************/

IexWznmGbl::ImeIAMCapabilityPar::ImeIAMCapabilityPar() {
};

IexWznmGbl::ImeIAMCapabilityPar::~ImeIAMCapabilityPar() {
	clear();
};

void IexWznmGbl::ImeIAMCapabilityPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmGbl::ImeIAMCapabilityPar::readTxt(
			Txtrd& txtrd
		) {
	IexWznmGbl::ImeitemIAMCapabilityPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmGbl::ImeitemIAMCapabilityPar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCapabilityPar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCapabilityPar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMCAPABILITYPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCapabilityPar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCapabilityPar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmGbl::ImeIAMCapabilityPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmGbl::ImeitemIAMCapabilityPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMCapabilityPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMCapabilityPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMCapabilityPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmGbl::ImeitemIAMCapabilityPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmGbl::ImeIAMCapabilityPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMCapabilityPar." << StrMod::replaceChar(ImeIAMCapabilityPar::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMCapabilityPar.end" << endl;
	};
};

void IexWznmGbl::ImeIAMCapabilityPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMCapabilityPar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmGbl::ImeitemIMCapability
 ******************************************************************************/

IexWznmGbl::ImeitemIMCapability::ImeitemIMCapability(
			const string& srefTplRefWznmMCapability
			, const string& sref
			, const string& Title
		) : WznmMCapability() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefTplRefWznmMCapability = srefTplRefWznmMCapability;
	this->sref = sref;
	this->Title = Title;
};

IexWznmGbl::ImeitemIMCapability::ImeitemIMCapability(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMCapability()
		{
	WznmMCapability* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmcapability->loadRecByRef(ref, &rec)) {
		refWznmMVersion = rec->refWznmMVersion;
		tplRefWznmMCapability = rec->tplRefWznmMCapability;
		sref = rec->sref;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmGbl::ImeitemIMCapability::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefTplRefWznmMCapability = txtrd.fields[0]; ixWIelValid += ImeIMCapability::VecWIel::SREFTPLREFWZNMMCAPABILITY;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMCapability::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIMCapability::VecWIel::TITLE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMCAPABILITYPAR)) {
					imeiamcapabilitypar.readTxt(txtrd);
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

void IexWznmGbl::ImeitemIMCapability::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefTplRefWznmMCapability", "tpl", srefTplRefWznmMCapability)) ixWIelValid += ImeIMCapability::VecWIel::SREFTPLREFWZNMMCAPABILITY;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCapability::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMCapability::VecWIel::TITLE;
		imeiamcapabilitypar.readXML(docctx, basexpath);
	};
};

void IexWznmGbl::ImeitemIMCapability::writeTxt(
			fstream& outfile
		) {
	outfile << srefTplRefWznmMCapability << "\t" << sref << "\t" << Title << endl;
	imeiamcapabilitypar.writeTxt(outfile);
};

void IexWznmGbl::ImeitemIMCapability::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tpl","srf","tit"};
	else tags = {"ImeitemIMCapability","srefTplRefWznmMCapability","sref","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefTplRefWznmMCapability);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Title);
		imeiamcapabilitypar.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmGbl::ImeIMCapability::VecWIel
 ******************************************************************************/

uint IexWznmGbl::ImeIMCapability::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sreftplrefwznmmcapability") ix |= SREFTPLREFWZNMMCAPABILITY;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmGbl::ImeIMCapability::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmGbl::ImeIMCapability::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFTPLREFWZNMMCAPABILITY) ss.push_back("srefTplRefWznmMCapability");
	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmGbl::ImeIMCapability
 ******************************************************************************/

IexWznmGbl::ImeIMCapability::ImeIMCapability() {
};

IexWznmGbl::ImeIMCapability::~ImeIMCapability() {
	clear();
};

void IexWznmGbl::ImeIMCapability::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmGbl::ImeIMCapability::readTxt(
			Txtrd& txtrd
		) {
	IexWznmGbl::ImeitemIMCapability* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmGbl::ImeitemIMCapability();
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

void IexWznmGbl::ImeIMCapability::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmGbl::ImeitemIMCapability* ii = NULL;

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

			ii = new IexWznmGbl::ImeitemIMCapability();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmGbl::ImeIMCapability::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMCapability." << StrMod::replaceChar(ImeIMCapability::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMCapability.end" << endl;
	};
};

void IexWznmGbl::ImeIMCapability::writeXML(
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
 class IexWznmGbl::ImeitemIJMErrorTitle
 ******************************************************************************/

IexWznmGbl::ImeitemIJMErrorTitle::ImeitemIJMErrorTitle(
			const string& srefX1RefWznmMLocale
			, const string& Title
		) : WznmJMErrorTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
};

IexWznmGbl::ImeitemIJMErrorTitle::ImeitemIJMErrorTitle(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMErrorTitle()
		{
	WznmJMErrorTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmerrortitle->loadRecByRef(ref, &rec)) {
		refWznmMError = rec->refWznmMError;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmGbl::ImeitemIJMErrorTitle::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMErrorTitle::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMErrorTitle::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMErrorTitle"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmGbl::ImeitemIJMErrorTitle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMErrorTitle::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMErrorTitle::VecWIel::TITLE;
	};
};

void IexWznmGbl::ImeitemIJMErrorTitle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefX1RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmGbl::ImeitemIJMErrorTitle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit"};
	else tags = {"ImeitemIJMErrorTitle","srefX1RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmGbl::ImeIJMErrorTitle::VecWIel
 ******************************************************************************/

uint IexWznmGbl::ImeIJMErrorTitle::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1refwznmmlocale") ix |= SREFX1REFWZNMMLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmGbl::ImeIJMErrorTitle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmGbl::ImeIJMErrorTitle::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1REFWZNMMLOCALE) ss.push_back("srefX1RefWznmMLocale");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmGbl::ImeIJMErrorTitle
 ******************************************************************************/

IexWznmGbl::ImeIJMErrorTitle::ImeIJMErrorTitle() {
};

IexWznmGbl::ImeIJMErrorTitle::~ImeIJMErrorTitle() {
	clear();
};

void IexWznmGbl::ImeIJMErrorTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmGbl::ImeIJMErrorTitle::readTxt(
			Txtrd& txtrd
		) {
	IexWznmGbl::ImeitemIJMErrorTitle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmGbl::ImeitemIJMErrorTitle();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMErrorTitle"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMErrorTitle"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMERRORTITLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMErrorTitle"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMErrorTitle"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmGbl::ImeIJMErrorTitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmGbl::ImeitemIJMErrorTitle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMErrorTitle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMErrorTitle", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMErrorTitle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmGbl::ImeitemIJMErrorTitle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmGbl::ImeIJMErrorTitle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJMErrorTitle." << StrMod::replaceChar(ImeIJMErrorTitle::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIJMErrorTitle.end" << endl;
	};
};

void IexWznmGbl::ImeIJMErrorTitle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMErrorTitle");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmGbl::ImeitemIMError
 ******************************************************************************/

IexWznmGbl::ImeitemIMError::ImeitemIMError(
			const string& sref
			, const string& Title
		) : WznmMError() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Title = Title;
};

IexWznmGbl::ImeitemIMError::ImeitemIMError(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMError()
		{
	WznmMError* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmerror->loadRecByRef(ref, &rec)) {
		verRefWznmMVersion = rec->verRefWznmMVersion;
		verNum = rec->verNum;
		sref = rec->sref;
		refJTitle = rec->refJTitle;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmGbl::ImeitemIMError::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMError::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMError::VecWIel::TITLE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJMERRORTITLE)) {
					imeijmerrortitle.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMError"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmGbl::ImeitemIMError::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMError::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMError::VecWIel::TITLE;
		imeijmerrortitle.readXML(docctx, basexpath);
	};
};

void IexWznmGbl::ImeitemIMError::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Title << endl;
	imeijmerrortitle.writeTxt(outfile);
};

void IexWznmGbl::ImeitemIMError::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit"};
	else tags = {"ImeitemIMError","sref","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		imeijmerrortitle.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmGbl::ImeIMError::VecWIel
 ******************************************************************************/

uint IexWznmGbl::ImeIMError::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmGbl::ImeIMError::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmGbl::ImeIMError::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmGbl::ImeIMError
 ******************************************************************************/

IexWznmGbl::ImeIMError::ImeIMError() {
};

IexWznmGbl::ImeIMError::~ImeIMError() {
	clear();
};

void IexWznmGbl::ImeIMError::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmGbl::ImeIMError::readTxt(
			Txtrd& txtrd
		) {
	IexWznmGbl::ImeitemIMError* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmGbl::ImeitemIMError();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMError"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMERROR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMError"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMError"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmGbl::ImeIMError::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmGbl::ImeitemIMError* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMError");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMError", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMError";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmGbl::ImeitemIMError();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmGbl::ImeIMError::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMError." << StrMod::replaceChar(ImeIMError::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMError.end" << endl;
	};
};

void IexWznmGbl::ImeIMError::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMError");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmGbl::ImeitemIAMVectorTitle
 ******************************************************************************/

IexWznmGbl::ImeitemIAMVectorTitle::ImeitemIAMVectorTitle(
			const uint x1IxVType
			, const string& srefX2RefWznmMLocale
			, const string& Title
		) : WznmAMVectorTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxVType = x1IxVType;
	this->srefX2RefWznmMLocale = srefX2RefWznmMLocale;
	this->Title = Title;
};

IexWznmGbl::ImeitemIAMVectorTitle::ImeitemIAMVectorTitle(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMVectorTitle()
		{
	WznmAMVectorTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamvectortitle->loadRecByRef(ref, &rec)) {
		refWznmMVector = rec->refWznmMVector;
		x1IxVType = rec->x1IxVType;
		x2RefWznmMLocale = rec->x2RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmGbl::ImeitemIAMVectorTitle::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxVType = txtrd.fields[0]; ixWIelValid += ImeIAMVectorTitle::VecWIel::SREFX1IXVTYPE;};
	if (txtrd.fields.size() > 1) {srefX2RefWznmMLocale = txtrd.fields[1]; ixWIelValid += ImeIAMVectorTitle::VecWIel::SREFX2REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIAMVectorTitle::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMVectorTitle"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmGbl::ImeitemIAMVectorTitle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxVType", "typ", srefX1IxVType)) ixWIelValid += ImeIAMVectorTitle::VecWIel::SREFX1IXVTYPE;
		if (extractStringUclc(docctx, basexpath, "srefX2RefWznmMLocale", "loc", srefX2RefWznmMLocale)) ixWIelValid += ImeIAMVectorTitle::VecWIel::SREFX2REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAMVectorTitle::VecWIel::TITLE;
	};
};

void IexWznmGbl::ImeitemIAMVectorTitle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVAMVectorTitleType::getSref(x1IxVType) << "\t" << srefX2RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmGbl::ImeitemIAMVectorTitle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","loc","tit"};
	else tags = {"ImeitemIAMVectorTitle","srefX1IxVType","srefX2RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVAMVectorTitleType::getSref(x1IxVType));
		writeString(wr, tags[2], srefX2RefWznmMLocale);
		writeString(wr, tags[3], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmGbl::ImeIAMVectorTitle::VecWIel
 ******************************************************************************/

uint IexWznmGbl::ImeIAMVectorTitle::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixvtype") ix |= SREFX1IXVTYPE;
		else if (ss[i] == "srefx2refwznmmlocale") ix |= SREFX2REFWZNMMLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmGbl::ImeIAMVectorTitle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmGbl::ImeIAMVectorTitle::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXVTYPE) ss.push_back("srefX1IxVType");
	if (ix & SREFX2REFWZNMMLOCALE) ss.push_back("srefX2RefWznmMLocale");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmGbl::ImeIAMVectorTitle
 ******************************************************************************/

IexWznmGbl::ImeIAMVectorTitle::ImeIAMVectorTitle() {
};

IexWznmGbl::ImeIAMVectorTitle::~ImeIAMVectorTitle() {
	clear();
};

void IexWznmGbl::ImeIAMVectorTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmGbl::ImeIAMVectorTitle::readTxt(
			Txtrd& txtrd
		) {
	IexWznmGbl::ImeitemIAMVectorTitle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmGbl::ImeitemIAMVectorTitle();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMVectorTitle"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMVectorTitle"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMVECTORTITLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMVectorTitle"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMVectorTitle"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmGbl::ImeIAMVectorTitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmGbl::ImeitemIAMVectorTitle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMVectorTitle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMVectorTitle", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMVectorTitle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmGbl::ImeitemIAMVectorTitle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmGbl::ImeIAMVectorTitle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMVectorTitle." << StrMod::replaceChar(ImeIAMVectorTitle::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMVectorTitle.end" << endl;
	};
};

void IexWznmGbl::ImeIAMVectorTitle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMVectorTitle");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmGbl::ImeitemIJMVectoritem
 ******************************************************************************/

IexWznmGbl::ImeitemIJMVectoritem::ImeitemIJMVectoritem(
			const string& srefX1RefWznmMLocale
			, const string& Title
			, const string& Comment
		) : WznmJMVectoritem() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexWznmGbl::ImeitemIJMVectoritem::ImeitemIJMVectoritem(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMVectoritem()
		{
	WznmJMVectoritem* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmvectoritem->loadRecByRef(ref, &rec)) {
		refWznmMVectoritem = rec->refWznmMVectoritem;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmGbl::ImeitemIJMVectoritem::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMVectoritem::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMVectoritem::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIJMVectoritem::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMVectoritem"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmGbl::ImeitemIJMVectoritem::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMVectoritem::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMVectoritem::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJMVectoritem::VecWIel::COMMENT;
	};
};

void IexWznmGbl::ImeitemIJMVectoritem::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefX1RefWznmMLocale << "\t" << Title << "\t" << Comment << endl;
};

void IexWznmGbl::ImeitemIJMVectoritem::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit","cmt"};
	else tags = {"ImeitemIJMVectoritem","srefX1RefWznmMLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmGbl::ImeIJMVectoritem::VecWIel
 ******************************************************************************/

uint IexWznmGbl::ImeIJMVectoritem::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1refwznmmlocale") ix |= SREFX1REFWZNMMLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmGbl::ImeIJMVectoritem::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmGbl::ImeIJMVectoritem::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1REFWZNMMLOCALE) ss.push_back("srefX1RefWznmMLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmGbl::ImeIJMVectoritem
 ******************************************************************************/

IexWznmGbl::ImeIJMVectoritem::ImeIJMVectoritem() {
};

IexWznmGbl::ImeIJMVectoritem::~ImeIJMVectoritem() {
	clear();
};

void IexWznmGbl::ImeIJMVectoritem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmGbl::ImeIJMVectoritem::readTxt(
			Txtrd& txtrd
		) {
	IexWznmGbl::ImeitemIJMVectoritem* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmGbl::ImeitemIJMVectoritem();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVectoritem"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMVectoritem"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMVECTORITEM) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVectoritem"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVectoritem"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmGbl::ImeIJMVectoritem::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmGbl::ImeitemIJMVectoritem* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMVectoritem");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMVectoritem", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMVectoritem";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmGbl::ImeitemIJMVectoritem();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmGbl::ImeIJMVectoritem::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMVectoritem." << StrMod::replaceChar(ImeIJMVectoritem::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMVectoritem.end" << endl;
	};
};

void IexWznmGbl::ImeIJMVectoritem::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMVectoritem");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmGbl::ImeitemIMVectoritem
 ******************************************************************************/

IexWznmGbl::ImeitemIMVectoritem::ImeitemIMVectoritem(
			const string& sref
			, const string& Avail
			, const string& Implied
			, const string& Title
			, const string& Comment
		) : WznmMVectoritem() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->Title = Title;
	this->Comment = Comment;
};

IexWznmGbl::ImeitemIMVectoritem::ImeitemIMVectoritem(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMVectoritem()
		{
	WznmMVectoritem* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmvectoritem->loadRecByRef(ref, &rec)) {
		vecRefWznmMVector = rec->vecRefWznmMVector;
		vecNum = rec->vecNum;
		sref = rec->sref;
		Avail = rec->Avail;
		Implied = rec->Implied;
		refJ = rec->refJ;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmGbl::ImeitemIMVectoritem::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMVectoritem::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Avail = txtrd.fields[1]; ixWIelValid += ImeIMVectoritem::VecWIel::AVAIL;};
	if (txtrd.fields.size() > 2) {Implied = txtrd.fields[2]; ixWIelValid += ImeIMVectoritem::VecWIel::IMPLIED;};
	if (txtrd.fields.size() > 3) {Title = txtrd.fields[3]; ixWIelValid += ImeIMVectoritem::VecWIel::TITLE;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMVectoritem::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMVECTORITEM)) {
					imeijmvectoritem.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVectoritem"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmGbl::ImeitemIMVectoritem::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVectoritem::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIMVectoritem::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIMVectoritem::VecWIel::IMPLIED;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMVectoritem::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVectoritem::VecWIel::COMMENT;
		imeijmvectoritem.readXML(docctx, basexpath);
	};
};

void IexWznmGbl::ImeitemIMVectoritem::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << Avail << "\t" << Implied << "\t" << Title << "\t" << Comment << endl;
	imeijmvectoritem.writeTxt(outfile);
};

void IexWznmGbl::ImeitemIMVectoritem::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","avl","imp","tit","cmt"};
	else tags = {"ImeitemIMVectoritem","sref","Avail","Implied","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Avail);
		writeString(wr, tags[3], Implied);
		writeString(wr, tags[4], Title);
		writeString(wr, tags[5], Comment);
		imeijmvectoritem.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmGbl::ImeIMVectoritem::VecWIel
 ******************************************************************************/

uint IexWznmGbl::ImeIMVectoritem::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "avail") ix |= AVAIL;
		else if (ss[i] == "implied") ix |= IMPLIED;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmGbl::ImeIMVectoritem::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmGbl::ImeIMVectoritem::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & IMPLIED) ss.push_back("Implied");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmGbl::ImeIMVectoritem
 ******************************************************************************/

IexWznmGbl::ImeIMVectoritem::ImeIMVectoritem() {
};

IexWznmGbl::ImeIMVectoritem::~ImeIMVectoritem() {
	clear();
};

void IexWznmGbl::ImeIMVectoritem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmGbl::ImeIMVectoritem::readTxt(
			Txtrd& txtrd
		) {
	IexWznmGbl::ImeitemIMVectoritem* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmGbl::ImeitemIMVectoritem();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVectoritem"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTORITEM) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmGbl::ImeIMVectoritem::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmGbl::ImeitemIMVectoritem* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVectoritem");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVectoritem", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVectoritem";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmGbl::ImeitemIMVectoritem();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmGbl::ImeIMVectoritem::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMVectoritem." << StrMod::replaceChar(ImeIMVectoritem::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMVectoritem.end" << endl;
	};
};

void IexWznmGbl::ImeIMVectoritem::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVectoritem");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmGbl::ImeitemIMVector
 ******************************************************************************/

IexWznmGbl::ImeitemIMVector::ImeitemIMVector(
			const uint ixVBasetype
			, const string& sref
			, const string& osrefWznmKTaggrp
			, const string& srefsKOption
		) : WznmMVector() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->osrefWznmKTaggrp = osrefWznmKTaggrp;
	this->srefsKOption = srefsKOption;
};

IexWznmGbl::ImeitemIMVector::ImeitemIMVector(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMVector()
		{
	WznmMVector* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmvector->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMVersion = rec->refWznmMVersion;
		hkIxVTbl = rec->hkIxVTbl;
		sref = rec->sref;
		osrefWznmKTaggrp = rec->osrefWznmKTaggrp;
		srefsKOption = rec->srefsKOption;

		delete rec;
	};
};

void IexWznmGbl::ImeitemIMVector::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMVector::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMVector::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {osrefWznmKTaggrp = txtrd.fields[2]; ixWIelValid += ImeIMVector::VecWIel::OSREFWZNMKTAGGRP;};
	if (txtrd.fields.size() > 3) {srefsKOption = txtrd.fields[3]; ixWIelValid += ImeIMVector::VecWIel::SREFSKOPTION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMVECTORTITLE)) {
					imeiamvectortitle.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMVECTORITEM)) {
					imeimvectoritem.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmGbl::ImeitemIMVector::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMVector::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVector::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "osrefWznmKTaggrp", "tgr", osrefWznmKTaggrp)) ixWIelValid += ImeIMVector::VecWIel::OSREFWZNMKTAGGRP;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMVector::VecWIel::SREFSKOPTION;
		imeiamvectortitle.readXML(docctx, basexpath);
		imeimvectoritem.readXML(docctx, basexpath);
	};
};

void IexWznmGbl::ImeitemIMVector::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmVMVectorBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << osrefWznmKTaggrp << "\t" << srefsKOption << endl;
	imeiamvectortitle.writeTxt(outfile);
	imeimvectoritem.writeTxt(outfile);
};

void IexWznmGbl::ImeitemIMVector::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","srf","tgr","opt"};
	else tags = {"ImeitemIMVector","srefIxVBasetype","sref","osrefWznmKTaggrp","srefsKOption"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMVectorBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], osrefWznmKTaggrp);
		writeString(wr, tags[4], srefsKOption);
		imeiamvectortitle.writeXML(wr, shorttags);
		imeimvectoritem.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmGbl::ImeIMVector::VecWIel
 ******************************************************************************/

uint IexWznmGbl::ImeIMVector::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "osrefwznmktaggrp") ix |= OSREFWZNMKTAGGRP;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
	};

	return(ix);
};

void IexWznmGbl::ImeIMVector::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmGbl::ImeIMVector::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & OSREFWZNMKTAGGRP) ss.push_back("osrefWznmKTaggrp");
	if (ix & SREFSKOPTION) ss.push_back("srefsKOption");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmGbl::ImeIMVector
 ******************************************************************************/

IexWznmGbl::ImeIMVector::ImeIMVector() {
};

IexWznmGbl::ImeIMVector::~ImeIMVector() {
	clear();
};

void IexWznmGbl::ImeIMVector::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmGbl::ImeIMVector::readTxt(
			Txtrd& txtrd
		) {
	IexWznmGbl::ImeitemIMVector* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmGbl::ImeitemIMVector();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTOR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmGbl::ImeIMVector::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmGbl::ImeitemIMVector* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVector");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVector", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVector";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmGbl::ImeitemIMVector();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmGbl::ImeIMVector::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMVector." << StrMod::replaceChar(ImeIMVector::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMVector.end" << endl;
	};
};

void IexWznmGbl::ImeIMVector::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVector");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWznmGbl
 ******************************************************************************/

void IexWznmGbl::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, ImeIMBlock& imeimblock
			, ImeIMCapability& imeimcapability
			, ImeIMError& imeimerror
			, ImeIMVector& imeimvector
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimblock, imeimcapability, imeimerror, imeimvector);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, "IexWznmGbl", Version("0.9.29"), VecVIme::getIx);
			readTxt(rd, imeimblock, imeimcapability, imeimerror, imeimvector);
	};
};

void IexWznmGbl::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMBlock& imeimblock
			, ImeIMCapability& imeimcapability
			, ImeIMError& imeimerror
			, ImeIMVector& imeimvector
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimblock, imeimcapability, imeimerror, imeimvector);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimblock, imeimcapability, imeimerror, imeimvector);
		txtfile.close();
	};
};

void IexWznmGbl::readTxt(
			Txtrd& txtrd
			, ImeIMBlock& imeimblock
			, ImeIMCapability& imeimcapability
			, ImeIMError& imeimerror
			, ImeIMVector& imeimvector
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMBLOCK)) imeimblock.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMCAPABILITY)) imeimcapability.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMERROR)) imeimerror.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMVECTOR)) imeimvector.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWznmGbl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMBlock& imeimblock
			, ImeIMCapability& imeimcapability
			, ImeIMError& imeimerror
			, ImeIMVector& imeimvector
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmGbl")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("0.9.29")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","0.9.29"}});
		};

		// look for XML sub-blocks
		imeimblock.readXML(docctx, basexpath);
		imeimcapability.readXML(docctx, basexpath);
		imeimerror.readXML(docctx, basexpath);
		imeimvector.readXML(docctx, basexpath);

	} else {
		imeimblock = ImeIMBlock();
		imeimcapability = ImeIMCapability();
		imeimerror = ImeIMError();
		imeimvector = ImeIMVector();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmGbl"}});
	};
};

void IexWznmGbl::writeTxt(
			fstream& outfile
			, ImeIMBlock& imeimblock
			, ImeIMCapability& imeimcapability
			, ImeIMError& imeimerror
			, ImeIMVector& imeimvector
		) {
	outfile << "IexWznmGbl v" WZNM_VERSION << endl;

	imeimblock.writeTxt(outfile);
	imeimcapability.writeTxt(outfile);
	imeimerror.writeTxt(outfile);
	imeimvector.writeTxt(outfile);
};

void IexWznmGbl::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMBlock& imeimblock
			, ImeIMCapability& imeimcapability
			, ImeIMError& imeimerror
			, ImeIMVector& imeimvector
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmGbl");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeimblock.writeXML(wr, shorttags);
		imeimcapability.writeXML(wr, shorttags);
		imeimerror.writeXML(wr, shorttags);
		imeimvector.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmGbl::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMBLOCKITEM,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMCAPABILITYPAR,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMVECTORTITLE,VecWznmVIop::INS},{(uint)VecVIme::IMEICAMBLOCKITEM,VecWznmVIop::INS},{(uint)VecVIme::IMEIJAMBLOCKITEM,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMERRORTITLE,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMVECTORITEM,VecWznmVIop::INS},{(uint)VecVIme::IMEIMBLOCK,VecWznmVIop::INS},{(uint)VecVIme::IMEIMCAPABILITY,VecWznmVIop::INS},{(uint)VecVIme::IMEIMERROR,VecWznmVIop::INS},{(uint)VecVIme::IMEIMVECTOR,VecWznmVIop::INS},{(uint)VecVIme::IMEIMVECTORITEM,VecWznmVIop::INS}};
};

uint IexWznmGbl::getIxWznmVIop(
			const map<uint,uint>& icsWznmVIop
			, const uint ixVIme
			, uint& ixWznmVIop
		) {
	ixWznmVIop = 0;

	auto it = icsWznmVIop.find(ixVIme);
	if (it != icsWznmVIop.end()) ixWznmVIop = it->second;

	return ixWznmVIop;
};

