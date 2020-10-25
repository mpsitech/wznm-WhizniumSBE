/**
	* \file IexWznmJtr.cpp
	* data blocks and readers/writers for import/export complex IexWznmJtr (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "IexWznmJtr.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWznmJtr::VecVIme
 ******************************************************************************/

uint IexWznmJtr::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamblockitem1") return IMEIAMBLOCKITEM1;
	if (s == "imeiamblockitem2") return IMEIAMBLOCKITEM2;
	if (s == "imeiamjobcmd") return IMEIAMJOBCMD;
	if (s == "imeiamjobvar") return IMEIAMJOBVAR;
	if (s == "imeiammethodinvpar") return IMEIAMMETHODINVPAR;
	if (s == "imeiammethodretpar") return IMEIAMMETHODRETPAR;
	if (s == "imeicamblockitem1") return IMEICAMBLOCKITEM1;
	if (s == "imeicamblockitem2") return IMEICAMBLOCKITEM2;
	if (s == "imeicamjobvar") return IMEICAMJOBVAR;
	if (s == "imeijamblockitem1") return IMEIJAMBLOCKITEM1;
	if (s == "imeijamblockitem2") return IMEIJAMBLOCKITEM2;
	if (s == "imeijmsquawktitle") return IMEIJMSQUAWKTITLE;
	if (s == "imeijmvectoritem") return IMEIJMVECTORITEM;
	if (s == "imeimblock1") return IMEIMBLOCK1;
	if (s == "imeimblock2") return IMEIMBLOCK2;
	if (s == "imeimcall") return IMEIMCALL;
	if (s == "imeimjob") return IMEIMJOB;
	if (s == "imeimmethod") return IMEIMMETHOD;
	if (s == "imeimsensitivity1") return IMEIMSENSITIVITY1;
	if (s == "imeimsensitivity2") return IMEIMSENSITIVITY2;
	if (s == "imeimsquawk") return IMEIMSQUAWK;
	if (s == "imeimstage") return IMEIMSTAGE;
	if (s == "imeimvector") return IMEIMVECTOR;
	if (s == "imeimvectoritem") return IMEIMVECTORITEM;
	if (s == "imeirmcallmstub") return IMEIRMCALLMSTUB;
	if (s == "imeirmjobmjob") return IMEIRMJOBMJOB;
	if (s == "imeirmjobmop") return IMEIRMJOBMOP;
	if (s == "imeirmjobmoppack") return IMEIRMJOBMOPPACK;
	if (s == "imeirmsquawkmstub") return IMEIRMSQUAWKMSTUB;

	return(0);
};

string IexWznmJtr::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMBLOCKITEM1) return("ImeIAMBlockItem1");
	if (ix == IMEIAMBLOCKITEM2) return("ImeIAMBlockItem2");
	if (ix == IMEIAMJOBCMD) return("ImeIAMJobCmd");
	if (ix == IMEIAMJOBVAR) return("ImeIAMJobVar");
	if (ix == IMEIAMMETHODINVPAR) return("ImeIAMMethodInvpar");
	if (ix == IMEIAMMETHODRETPAR) return("ImeIAMMethodRetpar");
	if (ix == IMEICAMBLOCKITEM1) return("ImeICAMBlockItem1");
	if (ix == IMEICAMBLOCKITEM2) return("ImeICAMBlockItem2");
	if (ix == IMEICAMJOBVAR) return("ImeICAMJobVar");
	if (ix == IMEIJAMBLOCKITEM1) return("ImeIJAMBlockItem1");
	if (ix == IMEIJAMBLOCKITEM2) return("ImeIJAMBlockItem2");
	if (ix == IMEIJMSQUAWKTITLE) return("ImeIJMSquawkTitle");
	if (ix == IMEIJMVECTORITEM) return("ImeIJMVectoritem");
	if (ix == IMEIMBLOCK1) return("ImeIMBlock1");
	if (ix == IMEIMBLOCK2) return("ImeIMBlock2");
	if (ix == IMEIMCALL) return("ImeIMCall");
	if (ix == IMEIMJOB) return("ImeIMJob");
	if (ix == IMEIMMETHOD) return("ImeIMMethod");
	if (ix == IMEIMSENSITIVITY1) return("ImeIMSensitivity1");
	if (ix == IMEIMSENSITIVITY2) return("ImeIMSensitivity2");
	if (ix == IMEIMSQUAWK) return("ImeIMSquawk");
	if (ix == IMEIMSTAGE) return("ImeIMStage");
	if (ix == IMEIMVECTOR) return("ImeIMVector");
	if (ix == IMEIMVECTORITEM) return("ImeIMVectoritem");
	if (ix == IMEIRMCALLMSTUB) return("ImeIRMCallMStub");
	if (ix == IMEIRMJOBMJOB) return("ImeIRMJobMJob");
	if (ix == IMEIRMJOBMOP) return("ImeIRMJobMOp");
	if (ix == IMEIRMJOBMOPPACK) return("ImeIRMJobMOppack");
	if (ix == IMEIRMSQUAWKMSTUB) return("ImeIRMSquawkMStub");

	return("");
};

/******************************************************************************
 class IexWznmJtr::ImeitemIJAMBlockItem2
 ******************************************************************************/

IexWznmJtr::ImeitemIJAMBlockItem2::ImeitemIJAMBlockItem2(
			const string& Defval
			, const string& srefRefWznmMVectoritem
		) : WznmJAMBlockItem() {
	lineno = 0;
	ixWIelValid = 0;

	this->Defval = Defval;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
};

IexWznmJtr::ImeitemIJAMBlockItem2::ImeitemIJAMBlockItem2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJAMBlockItem2()
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

void IexWznmJtr::ImeitemIJAMBlockItem2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Defval = txtrd.fields[0]; ixWIelValid += ImeIJAMBlockItem2::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 1) {srefRefWznmMVectoritem = txtrd.fields[1]; ixWIelValid += ImeIJAMBlockItem2::VecWIel::SREFREFWZNMMVECTORITEM;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAMBlockItem2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIJAMBlockItem2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIJAMBlockItem2::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIJAMBlockItem2::VecWIel::SREFREFWZNMMVECTORITEM;
	};
};

void IexWznmJtr::ImeitemIJAMBlockItem2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << Defval << "\t" << srefRefWznmMVectoritem << endl;
};

void IexWznmJtr::ImeitemIJAMBlockItem2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","dfv","vit"};
	else tags = {"ImeitemIJAMBlockItem2","Defval","srefRefWznmMVectoritem"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Defval);
		writeString(wr, tags[2], srefRefWznmMVectoritem);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIJAMBlockItem2::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIJAMBlockItem2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
	};

	return(ix);
};

void IexWznmJtr::ImeIJAMBlockItem2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMVECTORITEM); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIJAMBlockItem2::VecWIel::getSrefs(
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
 class IexWznmJtr::ImeIJAMBlockItem2
 ******************************************************************************/

IexWznmJtr::ImeIJAMBlockItem2::ImeIJAMBlockItem2() {
};

IexWznmJtr::ImeIJAMBlockItem2::~ImeIJAMBlockItem2() {
	clear();
};

void IexWznmJtr::ImeIJAMBlockItem2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIJAMBlockItem2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIJAMBlockItem2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmJtr::ImeitemIJAMBlockItem2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAMBlockItem2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAMBlockItem2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJAMBLOCKITEM2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAMBlockItem2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAMBlockItem2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIJAMBlockItem2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIJAMBlockItem2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAMBlockItem2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAMBlockItem2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAMBlockItem2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIJAMBlockItem2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIJAMBlockItem2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJAMBlockItem2." << StrMod::replaceChar(ImeIJAMBlockItem2::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJAMBlockItem2.end" << endl;
	};
};

void IexWznmJtr::ImeIJAMBlockItem2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAMBlockItem2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIAMBlockItem2
 ******************************************************************************/

IexWznmJtr::ImeitemIAMBlockItem2::ImeitemIAMBlockItem2(
			const uint ixWznmVIop
			, const ubigint irefRefWznmCAMBlockItem
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

	this->ixWznmVIop = ixWznmVIop;
	this->irefRefWznmCAMBlockItem = irefRefWznmCAMBlockItem;
	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->Defval = Defval;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
	this->Comment = Comment;
};

IexWznmJtr::ImeitemIAMBlockItem2::ImeitemIAMBlockItem2(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIAMBlockItem2(ixWznmVIop)
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

void IexWznmJtr::ImeitemIAMBlockItem2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {irefRefWznmCAMBlockItem = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIAMBlockItem2::VecWIel::IREFREFWZNMCAMBLOCKITEM;};
	if (txtrd.fields.size() > 2) {srefIxVBasetype = txtrd.fields[2]; ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIAMBlockItem2::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {srefIxWznmVVartype = txtrd.fields[4]; ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFIXWZNMVVARTYPE;};
	if (txtrd.fields.size() > 5) {srefRefWznmMVector = txtrd.fields[5]; ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 6) {Defval = txtrd.fields[6]; ixWIelValid += ImeIAMBlockItem2::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 7) {srefRefWznmMVectoritem = txtrd.fields[7]; ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFREFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 8) {Comment = txtrd.fields[8]; ixWIelValid += ImeIAMBlockItem2::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJAMBLOCKITEM2)) {
					imeijamblockitem2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMBlockItem2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIAMBlockItem2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFIXWZNMVIOP;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCAMBlockItem", "clu", irefRefWznmCAMBlockItem)) ixWIelValid += ImeIAMBlockItem2::VecWIel::IREFREFWZNMCAMBLOCKITEM;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMBlockItem2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype)) ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFIXWZNMVVARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFREFWZNMMVECTOR;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIAMBlockItem2::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFREFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMBlockItem2::VecWIel::COMMENT;
		imeijamblockitem2.readXML(docctx, basexpath);
	};
};

void IexWznmJtr::ImeitemIAMBlockItem2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVIop::getSref(ixWznmVIop) << "\t" << irefRefWznmCAMBlockItem << "\t" << VecWznmVAMBlockItemBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << VecWznmVVartype::getSref(ixWznmVVartype) << "\t" << srefRefWznmMVector << "\t" << Defval << "\t" << srefRefWznmMVectoritem << "\t" << Comment << endl;
	imeijamblockitem2.writeTxt(outfile);
};

void IexWznmJtr::ImeitemIAMBlockItem2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","clu","typ","srf","vty","vec","dfv","vit","cmt"};
	else tags = {"ImeitemIAMBlockItem2","srefIxWznmVIop","irefRefWznmCAMBlockItem","srefIxVBasetype","sref","srefIxWznmVVartype","srefRefWznmMVector","Defval","srefRefWznmMVectoritem","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeUbigint(wr, tags[2], irefRefWznmCAMBlockItem);
		writeString(wr, tags[3], VecWznmVAMBlockItemBasetype::getSref(ixVBasetype));
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], VecWznmVVartype::getSref(ixWznmVVartype));
		writeString(wr, tags[6], srefRefWznmMVector);
		writeString(wr, tags[7], Defval);
		writeString(wr, tags[8], srefRefWznmMVectoritem);
		writeString(wr, tags[9], Comment);
		imeijamblockitem2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIAMBlockItem2::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIAMBlockItem2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "irefrefwznmcamblockitem") ix |= IREFREFWZNMCAMBLOCKITEM;
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

void IexWznmJtr::ImeIAMBlockItem2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIAMBlockItem2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
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
 class IexWznmJtr::ImeIAMBlockItem2
 ******************************************************************************/

IexWznmJtr::ImeIAMBlockItem2::ImeIAMBlockItem2() {
};

IexWznmJtr::ImeIAMBlockItem2::~ImeIAMBlockItem2() {
	clear();
};

void IexWznmJtr::ImeIAMBlockItem2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIAMBlockItem2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIAMBlockItem2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJtr::ImeitemIAMBlockItem2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMBlockItem2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMBlockItem2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMBLOCKITEM2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMBlockItem2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMBlockItem2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIAMBlockItem2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIAMBlockItem2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMBlockItem2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMBlockItem2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMBlockItem2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIAMBlockItem2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIAMBlockItem2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMBlockItem2." << StrMod::replaceChar(ImeIAMBlockItem2::VecWIel::getSrefs(511), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMBlockItem2.end" << endl;
	};
};

void IexWznmJtr::ImeIAMBlockItem2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMBlockItem2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemICAMBlockItem2
 ******************************************************************************/

IexWznmJtr::ImeitemICAMBlockItem2::ImeitemICAMBlockItem2(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmJtr::ImeitemICAMBlockItem2::ImeitemICAMBlockItem2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICAMBlockItem2()
		{
};

void IexWznmJtr::ImeitemICAMBlockItem2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICAMBlockItem2::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMBlockItem2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemICAMBlockItem2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICAMBlockItem2::VecWIel::IREF;
	};
};

void IexWznmJtr::ImeitemICAMBlockItem2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << iref << endl;
};

void IexWznmJtr::ImeitemICAMBlockItem2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICAMBlockItem2","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeICAMBlockItem2::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeICAMBlockItem2::VecWIel::getIx(
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

void IexWznmJtr::ImeICAMBlockItem2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeICAMBlockItem2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeICAMBlockItem2
 ******************************************************************************/

IexWznmJtr::ImeICAMBlockItem2::ImeICAMBlockItem2() {
};

IexWznmJtr::ImeICAMBlockItem2::~ImeICAMBlockItem2() {
	clear();
};

void IexWznmJtr::ImeICAMBlockItem2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeICAMBlockItem2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemICAMBlockItem2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJtr::ImeitemICAMBlockItem2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMBlockItem2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMBlockItem2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICAMBLOCKITEM2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMBlockItem2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMBlockItem2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeICAMBlockItem2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemICAMBlockItem2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICAMBlockItem2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICAMBlockItem2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICAMBlockItem2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemICAMBlockItem2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeICAMBlockItem2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeICAMBlockItem2." << StrMod::replaceChar(ImeICAMBlockItem2::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeICAMBlockItem2.end" << endl;
	};
};

void IexWznmJtr::ImeICAMBlockItem2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICAMBlockItem2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIMBlock2
 ******************************************************************************/

IexWznmJtr::ImeitemIMBlock2::ImeitemIMBlock2(
			const string& sref
		) : WznmMBlock() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
};

IexWznmJtr::ImeitemIMBlock2::ImeitemIMBlock2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMBlock2()
		{
	WznmMBlock* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmblock->loadRecByRef(ref, &rec)) {
		sref = rec->sref;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIMBlock2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMBlock2::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMBLOCKITEM2)) {
					imeiamblockitem2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEICAMBLOCKITEM2)) {
					imeicamblockitem2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMBlock2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIMBlock2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMBlock2::VecWIel::SREF;
		imeiamblockitem2.readXML(docctx, basexpath);
		imeicamblockitem2.readXML(docctx, basexpath);
	};
};

void IexWznmJtr::ImeitemIMBlock2::writeTxt(
			fstream& outfile
		) {
	outfile << sref << endl;
	imeiamblockitem2.writeTxt(outfile);
	imeicamblockitem2.writeTxt(outfile);
};

void IexWznmJtr::ImeitemIMBlock2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf"};
	else tags = {"ImeitemIMBlock2","sref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		imeiamblockitem2.writeXML(wr, shorttags);
		imeicamblockitem2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIMBlock2::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIMBlock2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
	};

	return(ix);
};

void IexWznmJtr::ImeIMBlock2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIMBlock2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIMBlock2
 ******************************************************************************/

IexWznmJtr::ImeIMBlock2::ImeIMBlock2() {
};

IexWznmJtr::ImeIMBlock2::~ImeIMBlock2() {
	clear();
};

void IexWznmJtr::ImeIMBlock2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIMBlock2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIMBlock2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmJtr::ImeitemIMBlock2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMBlock2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMBLOCK2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBlock2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBlock2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIMBlock2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIMBlock2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMBlock2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMBlock2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMBlock2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIMBlock2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIMBlock2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMBlock2." << StrMod::replaceChar(ImeIMBlock2::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMBlock2.end" << endl;
	};
};

void IexWznmJtr::ImeIMBlock2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMBlock2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIMCall
 ******************************************************************************/

IexWznmJtr::ImeitemIMCall::ImeitemIMCall(
			const uint ixVBasetype
			, const uint invIxWznmWArgtype
			, const uint retIxWznmWArgtype
			, const string& sref
			, const string& Comment
		) : WznmMCall() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->invIxWznmWArgtype = invIxWznmWArgtype;
	this->retIxWznmWArgtype = retIxWznmWArgtype;
	this->sref = sref;
	this->Comment = Comment;
};

IexWznmJtr::ImeitemIMCall::ImeitemIMCall(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMCall()
		{
	WznmMCall* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmcall->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMVersion = rec->refWznmMVersion;
		refIxVTbl = rec->refIxVTbl;
		invIxWznmWArgtype = rec->invIxWznmWArgtype;
		retIxWznmWArgtype = rec->retIxWznmWArgtype;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIMCall::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMCall::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {srefsInvIxWznmWArgtype = txtrd.fields[1]; ixWIelValid += ImeIMCall::VecWIel::SREFSINVIXWZNMWARGTYPE;};
	if (txtrd.fields.size() > 2) {srefsRetIxWznmWArgtype = txtrd.fields[2]; ixWIelValid += ImeIMCall::VecWIel::SREFSRETIXWZNMWARGTYPE;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIMCall::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMCall::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCall"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIMCall::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMCall::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefsInvIxWznmWArgtype", "inv", srefsInvIxWznmWArgtype)) ixWIelValid += ImeIMCall::VecWIel::SREFSINVIXWZNMWARGTYPE;
		if (extractStringUclc(docctx, basexpath, "srefsRetIxWznmWArgtype", "ret", srefsRetIxWznmWArgtype)) ixWIelValid += ImeIMCall::VecWIel::SREFSRETIXWZNMWARGTYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCall::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMCall::VecWIel::COMMENT;
	};
};

void IexWznmJtr::ImeitemIMCall::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmVMCallBasetype::getSref(ixVBasetype) << "\t" << VecWznmWArgtype::getSrefs(invIxWznmWArgtype) << "\t" << VecWznmWArgtype::getSrefs(retIxWznmWArgtype) << "\t" << sref << "\t" << Comment << endl;
};

void IexWznmJtr::ImeitemIMCall::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","inv","ret","srf","cmt"};
	else tags = {"ImeitemIMCall","srefIxVBasetype","srefsInvIxWznmWArgtype","srefsRetIxWznmWArgtype","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMCallBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], VecWznmWArgtype::getSrefs(invIxWznmWArgtype));
		writeString(wr, tags[3], VecWznmWArgtype::getSrefs(retIxWznmWArgtype));
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIMCall::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIMCall::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefsinvixwznmwargtype") ix |= SREFSINVIXWZNMWARGTYPE;
		else if (ss[i] == "srefsretixwznmwargtype") ix |= SREFSRETIXWZNMWARGTYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmJtr::ImeIMCall::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIMCall::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFSINVIXWZNMWARGTYPE) ss.push_back("srefsInvIxWznmWArgtype");
	if (ix & SREFSRETIXWZNMWARGTYPE) ss.push_back("srefsRetIxWznmWArgtype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIMCall
 ******************************************************************************/

IexWznmJtr::ImeIMCall::ImeIMCall() {
};

IexWznmJtr::ImeIMCall::~ImeIMCall() {
	clear();
};

void IexWznmJtr::ImeIMCall::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIMCall::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIMCall* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmJtr::ImeitemIMCall();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCall"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCALL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCall"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCall"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIMCall::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIMCall* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMCall");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMCall", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMCall";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIMCall();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIMCall::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMCall." << StrMod::replaceChar(ImeIMCall::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMCall.end" << endl;
	};
};

void IexWznmJtr::ImeIMCall::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMCall");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIAMJobCmd
 ******************************************************************************/

IexWznmJtr::ImeitemIAMJobCmd::ImeitemIAMJobCmd(
			const string& sref
			, const string& Comment
		) : WznmAMJobCmd() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexWznmJtr::ImeitemIAMJobCmd::ImeitemIAMJobCmd(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMJobCmd()
		{
	WznmAMJobCmd* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamjobcmd->loadRecByRef(ref, &rec)) {
		refWznmMJob = rec->refWznmMJob;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIAMJobCmd::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMJobCmd::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIAMJobCmd::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMJobCmd"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIAMJobCmd::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMJobCmd::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMJobCmd::VecWIel::COMMENT;
	};
};

void IexWznmJtr::ImeitemIAMJobCmd::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << Comment << endl;
};

void IexWznmJtr::ImeitemIAMJobCmd::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIAMJobCmd","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIAMJobCmd::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIAMJobCmd::VecWIel::getIx(
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

void IexWznmJtr::ImeIAMJobCmd::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIAMJobCmd::VecWIel::getSrefs(
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
 class IexWznmJtr::ImeIAMJobCmd
 ******************************************************************************/

IexWznmJtr::ImeIAMJobCmd::ImeIAMJobCmd() {
};

IexWznmJtr::ImeIAMJobCmd::~ImeIAMJobCmd() {
	clear();
};

void IexWznmJtr::ImeIAMJobCmd::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIAMJobCmd::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIAMJobCmd* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJtr::ImeitemIAMJobCmd();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMJobCmd"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMJobCmd"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMJOBCMD) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMJobCmd"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMJobCmd"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIAMJobCmd::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIAMJobCmd* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMJobCmd");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMJobCmd", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMJobCmd";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIAMJobCmd();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIAMJobCmd::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMJobCmd." << StrMod::replaceChar(ImeIAMJobCmd::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMJobCmd.end" << endl;
	};
};

void IexWznmJtr::ImeIAMJobCmd::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMJobCmd");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIAMJobVar
 ******************************************************************************/

IexWznmJtr::ImeitemIAMJobVar::ImeitemIAMJobVar(
			const ubigint irefRefWznmCAMJobVar
			, const string& sref
			, const uint ixWznmVVartype
			, const string& srefRefWznmMVector
			, const uint Length
			, const bool Shr
			, const string& Comment
		) : WznmAMJobVar() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWznmCAMJobVar = irefRefWznmCAMJobVar;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->Length = Length;
	this->Shr = Shr;
	this->Comment = Comment;
};

IexWznmJtr::ImeitemIAMJobVar::ImeitemIAMJobVar(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMJobVar()
		{
	WznmAMJobVar* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamjobvar->loadRecByRef(ref, &rec)) {
		refWznmCAMJobVar = rec->refWznmCAMJobVar;
		jobRefWznmMJob = rec->jobRefWznmMJob;
		jobNum = rec->jobNum;
		sref = rec->sref;
		ixWznmVVartype = rec->ixWznmVVartype;
		refWznmMVector = rec->refWznmMVector;
		Length = rec->Length;
		Shr = rec->Shr;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIAMJobVar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWznmCAMJobVar = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIAMJobVar::VecWIel::IREFREFWZNMCAMJOBVAR;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAMJobVar::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefIxWznmVVartype = txtrd.fields[2]; ixWIelValid += ImeIAMJobVar::VecWIel::SREFIXWZNMVVARTYPE;};
	if (txtrd.fields.size() > 3) {srefRefWznmMVector = txtrd.fields[3]; ixWIelValid += ImeIAMJobVar::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 4) {Length = atol(txtrd.fields[4].c_str()); ixWIelValid += ImeIAMJobVar::VecWIel::LENGTH;};
	if (txtrd.fields.size() > 5) {Shr = (txtrd.fields[5] == "true"); ixWIelValid += ImeIAMJobVar::VecWIel::SHR;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIAMJobVar::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMJobVar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIAMJobVar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCAMJobVar", "clu", irefRefWznmCAMJobVar)) ixWIelValid += ImeIAMJobVar::VecWIel::IREFREFWZNMCAMJOBVAR;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMJobVar::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype)) ixWIelValid += ImeIAMJobVar::VecWIel::SREFIXWZNMVVARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMJobVar::VecWIel::SREFREFWZNMMVECTOR;
		if (extractUintUclc(docctx, basexpath, "Length", "len", Length)) ixWIelValid += ImeIAMJobVar::VecWIel::LENGTH;
		if (extractBoolUclc(docctx, basexpath, "Shr", "shr", Shr)) ixWIelValid += ImeIAMJobVar::VecWIel::SHR;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMJobVar::VecWIel::COMMENT;
	};
};

void IexWznmJtr::ImeitemIAMJobVar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << irefRefWznmCAMJobVar << "\t" << sref << "\t" << VecWznmVVartype::getSref(ixWznmVVartype) << "\t" << srefRefWznmMVector << "\t" << Length << "\t" << StrMod::boolToString(Shr) << "\t" << Comment << endl;
};

void IexWznmJtr::ImeitemIAMJobVar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","srf","vty","vec","len","shr","cmt"};
	else tags = {"ImeitemIAMJobVar","irefRefWznmCAMJobVar","sref","srefIxWznmVVartype","srefRefWznmMVector","Length","Shr","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWznmCAMJobVar);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], VecWznmVVartype::getSref(ixWznmVVartype));
		writeString(wr, tags[4], srefRefWznmMVector);
		writeUint(wr, tags[5], Length);
		writeBool(wr, tags[6], Shr);
		writeString(wr, tags[7], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIAMJobVar::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIAMJobVar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwznmcamjobvar") ix |= IREFREFWZNMCAMJOBVAR;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmvvartype") ix |= SREFIXWZNMVVARTYPE;
		else if (ss[i] == "srefrefwznmmvector") ix |= SREFREFWZNMMVECTOR;
		else if (ss[i] == "length") ix |= LENGTH;
		else if (ss[i] == "shr") ix |= SHR;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmJtr::ImeIAMJobVar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIAMJobVar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWZNMCAMJOBVAR) ss.push_back("irefRefWznmCAMJobVar");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXWZNMVVARTYPE) ss.push_back("srefIxWznmVVartype");
	if (ix & SREFREFWZNMMVECTOR) ss.push_back("srefRefWznmMVector");
	if (ix & LENGTH) ss.push_back("Length");
	if (ix & SHR) ss.push_back("Shr");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIAMJobVar
 ******************************************************************************/

IexWznmJtr::ImeIAMJobVar::ImeIAMJobVar() {
};

IexWznmJtr::ImeIAMJobVar::~ImeIAMJobVar() {
	clear();
};

void IexWznmJtr::ImeIAMJobVar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIAMJobVar::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIAMJobVar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJtr::ImeitemIAMJobVar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMJobVar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMJobVar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMJOBVAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMJobVar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMJobVar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIAMJobVar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIAMJobVar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMJobVar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMJobVar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMJobVar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIAMJobVar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIAMJobVar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMJobVar." << StrMod::replaceChar(ImeIAMJobVar::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMJobVar.end" << endl;
	};
};

void IexWznmJtr::ImeIAMJobVar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMJobVar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemICAMJobVar
 ******************************************************************************/

IexWznmJtr::ImeitemICAMJobVar::ImeitemICAMJobVar(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmJtr::ImeitemICAMJobVar::ImeitemICAMJobVar(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICAMJobVar()
		{
};

void IexWznmJtr::ImeitemICAMJobVar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICAMJobVar::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMJobVar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemICAMJobVar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICAMJobVar::VecWIel::IREF;
	};
};

void IexWznmJtr::ImeitemICAMJobVar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << iref << endl;
};

void IexWznmJtr::ImeitemICAMJobVar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICAMJobVar","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeICAMJobVar::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeICAMJobVar::VecWIel::getIx(
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

void IexWznmJtr::ImeICAMJobVar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeICAMJobVar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeICAMJobVar
 ******************************************************************************/

IexWznmJtr::ImeICAMJobVar::ImeICAMJobVar() {
};

IexWznmJtr::ImeICAMJobVar::~ImeICAMJobVar() {
	clear();
};

void IexWznmJtr::ImeICAMJobVar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeICAMJobVar::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemICAMJobVar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJtr::ImeitemICAMJobVar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMJobVar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMJobVar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICAMJOBVAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMJobVar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMJobVar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeICAMJobVar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemICAMJobVar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICAMJobVar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICAMJobVar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICAMJobVar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemICAMJobVar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeICAMJobVar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeICAMJobVar." << StrMod::replaceChar(ImeICAMJobVar::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeICAMJobVar.end" << endl;
	};
};

void IexWznmJtr::ImeICAMJobVar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICAMJobVar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIJAMBlockItem1
 ******************************************************************************/

IexWznmJtr::ImeitemIJAMBlockItem1::ImeitemIJAMBlockItem1(
			const string& Defval
			, const string& srefRefWznmMVectoritem
		) : WznmJAMBlockItem() {
	lineno = 0;
	ixWIelValid = 0;

	this->Defval = Defval;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
};

IexWznmJtr::ImeitemIJAMBlockItem1::ImeitemIJAMBlockItem1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJAMBlockItem1()
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

void IexWznmJtr::ImeitemIJAMBlockItem1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Defval = txtrd.fields[0]; ixWIelValid += ImeIJAMBlockItem1::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 1) {srefRefWznmMVectoritem = txtrd.fields[1]; ixWIelValid += ImeIJAMBlockItem1::VecWIel::SREFREFWZNMMVECTORITEM;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAMBlockItem1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIJAMBlockItem1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIJAMBlockItem1::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIJAMBlockItem1::VecWIel::SREFREFWZNMMVECTORITEM;
	};
};

void IexWznmJtr::ImeitemIJAMBlockItem1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << Defval << "\t" << srefRefWznmMVectoritem << endl;
};

void IexWznmJtr::ImeitemIJAMBlockItem1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","dfv","vit"};
	else tags = {"ImeitemIJAMBlockItem1","Defval","srefRefWznmMVectoritem"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Defval);
		writeString(wr, tags[2], srefRefWznmMVectoritem);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIJAMBlockItem1::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIJAMBlockItem1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
	};

	return(ix);
};

void IexWznmJtr::ImeIJAMBlockItem1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMVECTORITEM); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIJAMBlockItem1::VecWIel::getSrefs(
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
 class IexWznmJtr::ImeIJAMBlockItem1
 ******************************************************************************/

IexWznmJtr::ImeIJAMBlockItem1::ImeIJAMBlockItem1() {
};

IexWznmJtr::ImeIJAMBlockItem1::~ImeIJAMBlockItem1() {
	clear();
};

void IexWznmJtr::ImeIJAMBlockItem1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIJAMBlockItem1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIJAMBlockItem1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmJtr::ImeitemIJAMBlockItem1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAMBlockItem1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAMBlockItem1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJAMBLOCKITEM1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAMBlockItem1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAMBlockItem1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIJAMBlockItem1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIJAMBlockItem1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAMBlockItem1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAMBlockItem1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAMBlockItem1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIJAMBlockItem1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIJAMBlockItem1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJAMBlockItem1." << StrMod::replaceChar(ImeIJAMBlockItem1::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJAMBlockItem1.end" << endl;
	};
};

void IexWznmJtr::ImeIJAMBlockItem1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAMBlockItem1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIAMBlockItem1
 ******************************************************************************/

IexWznmJtr::ImeitemIAMBlockItem1::ImeitemIAMBlockItem1(
			const uint ixWznmVIop
			, const ubigint irefRefWznmCAMBlockItem
			, const uint ixVBasetype
			, const string& sref
			, const uint ixWznmVVartype
			, const string& srefRefWznmMControl
			, const string& srefRefWznmMVector
			, const string& srefRefWznmMFeed
			, const string& srefRefWznmMTable
			, const string& srefRefWznmMBlock
			, const string& Defval
			, const string& srefRefWznmMVectoritem
			, const string& Comment
		) : WznmAMBlockItem() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->irefRefWznmCAMBlockItem = irefRefWznmCAMBlockItem;
	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefRefWznmMControl = srefRefWznmMControl;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->srefRefWznmMFeed = srefRefWznmMFeed;
	this->srefRefWznmMTable = srefRefWznmMTable;
	this->srefRefWznmMBlock = srefRefWznmMBlock;
	this->Defval = Defval;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
	this->Comment = Comment;
};

IexWznmJtr::ImeitemIAMBlockItem1::ImeitemIAMBlockItem1(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIAMBlockItem1(ixWznmVIop)
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
		refWznmMControl = rec->refWznmMControl;
		refWznmMVector = rec->refWznmMVector;
		refWznmMFeed = rec->refWznmMFeed;
		refWznmMTable = rec->refWznmMTable;
		refWznmMBlock = rec->refWznmMBlock;
		refJ = rec->refJ;
		Defval = rec->Defval;
		refWznmMVectoritem = rec->refWznmMVectoritem;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIAMBlockItem1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {irefRefWznmCAMBlockItem = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIAMBlockItem1::VecWIel::IREFREFWZNMCAMBLOCKITEM;};
	if (txtrd.fields.size() > 2) {srefIxVBasetype = txtrd.fields[2]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {srefIxWznmVVartype = txtrd.fields[4]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFIXWZNMVVARTYPE;};
	if (txtrd.fields.size() > 5) {srefRefWznmMControl = txtrd.fields[5]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMCONTROL;};
	if (txtrd.fields.size() > 6) {srefRefWznmMVector = txtrd.fields[6]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 7) {srefRefWznmMFeed = txtrd.fields[7]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMFEED;};
	if (txtrd.fields.size() > 8) {srefRefWznmMTable = txtrd.fields[8]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMTABLE;};
	if (txtrd.fields.size() > 9) {srefRefWznmMBlock = txtrd.fields[9]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMBLOCK;};
	if (txtrd.fields.size() > 10) {Defval = txtrd.fields[10]; ixWIelValid += ImeIAMBlockItem1::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 11) {srefRefWznmMVectoritem = txtrd.fields[11]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 12) {Comment = txtrd.fields[12]; ixWIelValid += ImeIAMBlockItem1::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJAMBLOCKITEM1)) {
					imeijamblockitem1.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMBlockItem1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIAMBlockItem1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFIXWZNMVIOP;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCAMBlockItem", "clu", irefRefWznmCAMBlockItem)) ixWIelValid += ImeIAMBlockItem1::VecWIel::IREFREFWZNMCAMBLOCKITEM;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFIXWZNMVVARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMControl", "con", srefRefWznmMControl)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMCONTROL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMVECTOR;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMFeed", "fed", srefRefWznmMFeed)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMFEED;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMTable", "tbl", srefRefWznmMTable)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMTABLE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMBlock", "bl2", srefRefWznmMBlock)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMBLOCK;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIAMBlockItem1::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMBlockItem1::VecWIel::COMMENT;
		imeijamblockitem1.readXML(docctx, basexpath);
	};
};

void IexWznmJtr::ImeitemIAMBlockItem1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVIop::getSref(ixWznmVIop) << "\t" << irefRefWznmCAMBlockItem << "\t" << VecWznmVAMBlockItemBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << VecWznmVVartype::getSref(ixWznmVVartype) << "\t" << srefRefWznmMControl << "\t" << srefRefWznmMVector << "\t" << srefRefWznmMFeed << "\t" << srefRefWznmMTable << "\t" << srefRefWznmMBlock << "\t" << Defval << "\t" << srefRefWznmMVectoritem << "\t" << Comment << endl;
	imeijamblockitem1.writeTxt(outfile);
};

void IexWznmJtr::ImeitemIAMBlockItem1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","clu","typ","srf","vty","con","vec","fed","tbl","bl2","dfv","vit","cmt"};
	else tags = {"ImeitemIAMBlockItem1","srefIxWznmVIop","irefRefWznmCAMBlockItem","srefIxVBasetype","sref","srefIxWznmVVartype","srefRefWznmMControl","srefRefWznmMVector","srefRefWznmMFeed","srefRefWznmMTable","srefRefWznmMBlock","Defval","srefRefWznmMVectoritem","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeUbigint(wr, tags[2], irefRefWznmCAMBlockItem);
		writeString(wr, tags[3], VecWznmVAMBlockItemBasetype::getSref(ixVBasetype));
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], VecWznmVVartype::getSref(ixWznmVVartype));
		writeString(wr, tags[6], srefRefWznmMControl);
		writeString(wr, tags[7], srefRefWznmMVector);
		writeString(wr, tags[8], srefRefWznmMFeed);
		writeString(wr, tags[9], srefRefWznmMTable);
		writeString(wr, tags[10], srefRefWznmMBlock);
		writeString(wr, tags[11], Defval);
		writeString(wr, tags[12], srefRefWznmMVectoritem);
		writeString(wr, tags[13], Comment);
		imeijamblockitem1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIAMBlockItem1::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIAMBlockItem1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "irefrefwznmcamblockitem") ix |= IREFREFWZNMCAMBLOCKITEM;
		else if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmvvartype") ix |= SREFIXWZNMVVARTYPE;
		else if (ss[i] == "srefrefwznmmcontrol") ix |= SREFREFWZNMMCONTROL;
		else if (ss[i] == "srefrefwznmmvector") ix |= SREFREFWZNMMVECTOR;
		else if (ss[i] == "srefrefwznmmfeed") ix |= SREFREFWZNMMFEED;
		else if (ss[i] == "srefrefwznmmtable") ix |= SREFREFWZNMMTABLE;
		else if (ss[i] == "srefrefwznmmblock") ix |= SREFREFWZNMMBLOCK;
		else if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmJtr::ImeIAMBlockItem1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIAMBlockItem1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & IREFREFWZNMCAMBLOCKITEM) ss.push_back("irefRefWznmCAMBlockItem");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXWZNMVVARTYPE) ss.push_back("srefIxWznmVVartype");
	if (ix & SREFREFWZNMMCONTROL) ss.push_back("srefRefWznmMControl");
	if (ix & SREFREFWZNMMVECTOR) ss.push_back("srefRefWznmMVector");
	if (ix & SREFREFWZNMMFEED) ss.push_back("srefRefWznmMFeed");
	if (ix & SREFREFWZNMMTABLE) ss.push_back("srefRefWznmMTable");
	if (ix & SREFREFWZNMMBLOCK) ss.push_back("srefRefWznmMBlock");
	if (ix & DEFVAL) ss.push_back("Defval");
	if (ix & SREFREFWZNMMVECTORITEM) ss.push_back("srefRefWznmMVectoritem");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIAMBlockItem1
 ******************************************************************************/

IexWznmJtr::ImeIAMBlockItem1::ImeIAMBlockItem1() {
};

IexWznmJtr::ImeIAMBlockItem1::~ImeIAMBlockItem1() {
	clear();
};

void IexWznmJtr::ImeIAMBlockItem1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIAMBlockItem1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIAMBlockItem1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmJtr::ImeitemIAMBlockItem1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMBlockItem1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMBlockItem1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMBLOCKITEM1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMBlockItem1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMBlockItem1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIAMBlockItem1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIAMBlockItem1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMBlockItem1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMBlockItem1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMBlockItem1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIAMBlockItem1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIAMBlockItem1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMBlockItem1." << StrMod::replaceChar(ImeIAMBlockItem1::VecWIel::getSrefs(8191), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMBlockItem1.end" << endl;
	};
};

void IexWznmJtr::ImeIAMBlockItem1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMBlockItem1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemICAMBlockItem1
 ******************************************************************************/

IexWznmJtr::ImeitemICAMBlockItem1::ImeitemICAMBlockItem1(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmJtr::ImeitemICAMBlockItem1::ImeitemICAMBlockItem1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICAMBlockItem1()
		{
};

void IexWznmJtr::ImeitemICAMBlockItem1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICAMBlockItem1::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMBlockItem1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemICAMBlockItem1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICAMBlockItem1::VecWIel::IREF;
	};
};

void IexWznmJtr::ImeitemICAMBlockItem1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWznmJtr::ImeitemICAMBlockItem1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICAMBlockItem1","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeICAMBlockItem1::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeICAMBlockItem1::VecWIel::getIx(
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

void IexWznmJtr::ImeICAMBlockItem1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeICAMBlockItem1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeICAMBlockItem1
 ******************************************************************************/

IexWznmJtr::ImeICAMBlockItem1::ImeICAMBlockItem1() {
};

IexWznmJtr::ImeICAMBlockItem1::~ImeICAMBlockItem1() {
	clear();
};

void IexWznmJtr::ImeICAMBlockItem1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeICAMBlockItem1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemICAMBlockItem1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmJtr::ImeitemICAMBlockItem1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMBlockItem1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMBlockItem1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICAMBLOCKITEM1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMBlockItem1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMBlockItem1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeICAMBlockItem1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemICAMBlockItem1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICAMBlockItem1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICAMBlockItem1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICAMBlockItem1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemICAMBlockItem1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeICAMBlockItem1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICAMBlockItem1." << StrMod::replaceChar(ImeICAMBlockItem1::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICAMBlockItem1.end" << endl;
	};
};

void IexWznmJtr::ImeICAMBlockItem1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICAMBlockItem1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIMBlock1
 ******************************************************************************/

IexWznmJtr::ImeitemIMBlock1::ImeitemIMBlock1(
			const uint ixWznmVIop
			, const uint ixVBasetype
			, const uint reaIxWznmWScope
			, const uint wriIxWznmWScope
			, const string& sref
			, const string& Comment
		) : WznmMBlock() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->ixVBasetype = ixVBasetype;
	this->reaIxWznmWScope = reaIxWznmWScope;
	this->wriIxWznmWScope = wriIxWznmWScope;
	this->sref = sref;
	this->Comment = Comment;
};

IexWznmJtr::ImeitemIMBlock1::ImeitemIMBlock1(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIMBlock1(ixWznmVIop)
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

void IexWznmJtr::ImeitemIMBlock1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIMBlock1::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {srefIxVBasetype = txtrd.fields[1]; ixWIelValid += ImeIMBlock1::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 2) {srefsReaIxWznmWScope = txtrd.fields[2]; ixWIelValid += ImeIMBlock1::VecWIel::SREFSREAIXWZNMWSCOPE;};
	if (txtrd.fields.size() > 3) {srefsWriIxWznmWScope = txtrd.fields[3]; ixWIelValid += ImeIMBlock1::VecWIel::SREFSWRIIXWZNMWSCOPE;};
	if (txtrd.fields.size() > 4) {sref = txtrd.fields[4]; ixWIelValid += ImeIMBlock1::VecWIel::SREF;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIMBlock1::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMBLOCKITEM1)) {
					imeiamblockitem1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEICAMBLOCKITEM1)) {
					imeicamblockitem1.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMBlock1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIMBlock1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIMBlock1::VecWIel::SREFIXWZNMVIOP;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMBlock1::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefsReaIxWznmWScope", "rsc", srefsReaIxWznmWScope)) ixWIelValid += ImeIMBlock1::VecWIel::SREFSREAIXWZNMWSCOPE;
		if (extractStringUclc(docctx, basexpath, "srefsWriIxWznmWScope", "wsc", srefsWriIxWznmWScope)) ixWIelValid += ImeIMBlock1::VecWIel::SREFSWRIIXWZNMWSCOPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMBlock1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMBlock1::VecWIel::COMMENT;
		imeiamblockitem1.readXML(docctx, basexpath);
		imeicamblockitem1.readXML(docctx, basexpath);
	};
};

void IexWznmJtr::ImeitemIMBlock1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVIop::getSref(ixWznmVIop) << "\t" << VecWznmVMBlockBasetype::getSref(ixVBasetype) << "\t" << VecWznmWScope::getSrefs(reaIxWznmWScope) << "\t" << VecWznmWScope::getSrefs(wriIxWznmWScope) << "\t" << sref << "\t" << Comment << endl;
	imeiamblockitem1.writeTxt(outfile);
	imeicamblockitem1.writeTxt(outfile);
};

void IexWznmJtr::ImeitemIMBlock1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","typ","rsc","wsc","srf","cmt"};
	else tags = {"ImeitemIMBlock1","srefIxWznmVIop","srefIxVBasetype","srefsReaIxWznmWScope","srefsWriIxWznmWScope","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeString(wr, tags[2], VecWznmVMBlockBasetype::getSref(ixVBasetype));
		writeString(wr, tags[3], VecWznmWScope::getSrefs(reaIxWznmWScope));
		writeString(wr, tags[4], VecWznmWScope::getSrefs(wriIxWznmWScope));
		writeString(wr, tags[5], sref);
		writeString(wr, tags[6], Comment);
		imeiamblockitem1.writeXML(wr, shorttags);
		imeicamblockitem1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIMBlock1::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIMBlock1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefsreaixwznmwscope") ix |= SREFSREAIXWZNMWSCOPE;
		else if (ss[i] == "srefswriixwznmwscope") ix |= SREFSWRIIXWZNMWSCOPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmJtr::ImeIMBlock1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIMBlock1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFSREAIXWZNMWSCOPE) ss.push_back("srefsReaIxWznmWScope");
	if (ix & SREFSWRIIXWZNMWSCOPE) ss.push_back("srefsWriIxWznmWScope");
	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIMBlock1
 ******************************************************************************/

IexWznmJtr::ImeIMBlock1::ImeIMBlock1() {
};

IexWznmJtr::ImeIMBlock1::~ImeIMBlock1() {
	clear();
};

void IexWznmJtr::ImeIMBlock1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIMBlock1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIMBlock1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJtr::ImeitemIMBlock1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBlock1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMBlock1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMBLOCK1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBlock1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBlock1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIMBlock1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIMBlock1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMBlock1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMBlock1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMBlock1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIMBlock1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIMBlock1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMBlock1." << StrMod::replaceChar(ImeIMBlock1::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMBlock1.end" << endl;
	};
};

void IexWznmJtr::ImeIMBlock1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMBlock1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIAMMethodInvpar
 ******************************************************************************/

IexWznmJtr::ImeitemIAMMethodInvpar::ImeitemIAMMethodInvpar(
			const string& sref
			, const uint ixWznmVVartype
			, const string& srefRefWznmMVector
			, const uint Length
			, const string& Comment
		) : WznmAMMethodInvpar() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->Length = Length;
	this->Comment = Comment;
};

IexWznmJtr::ImeitemIAMMethodInvpar::ImeitemIAMMethodInvpar(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMMethodInvpar()
		{
	WznmAMMethodInvpar* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmammethodinvpar->loadRecByRef(ref, &rec)) {
		mtdRefWznmMMethod = rec->mtdRefWznmMMethod;
		mtdNum = rec->mtdNum;
		sref = rec->sref;
		ixWznmVVartype = rec->ixWznmVVartype;
		refWznmMVector = rec->refWznmMVector;
		Length = rec->Length;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIAMMethodInvpar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMMethodInvpar::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxWznmVVartype = txtrd.fields[1]; ixWIelValid += ImeIAMMethodInvpar::VecWIel::SREFIXWZNMVVARTYPE;};
	if (txtrd.fields.size() > 2) {srefRefWznmMVector = txtrd.fields[2]; ixWIelValid += ImeIAMMethodInvpar::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 3) {Length = atol(txtrd.fields[3].c_str()); ixWIelValid += ImeIAMMethodInvpar::VecWIel::LENGTH;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIAMMethodInvpar::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMMethodInvpar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIAMMethodInvpar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMMethodInvpar::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype)) ixWIelValid += ImeIAMMethodInvpar::VecWIel::SREFIXWZNMVVARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMMethodInvpar::VecWIel::SREFREFWZNMMVECTOR;
		if (extractUintUclc(docctx, basexpath, "Length", "len", Length)) ixWIelValid += ImeIAMMethodInvpar::VecWIel::LENGTH;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMMethodInvpar::VecWIel::COMMENT;
	};
};

void IexWznmJtr::ImeitemIAMMethodInvpar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << VecWznmVVartype::getSref(ixWznmVVartype) << "\t" << srefRefWznmMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWznmJtr::ImeitemIAMMethodInvpar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","vty","vec","len","cmt"};
	else tags = {"ImeitemIAMMethodInvpar","sref","srefIxWznmVVartype","srefRefWznmMVector","Length","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecWznmVVartype::getSref(ixWznmVVartype));
		writeString(wr, tags[3], srefRefWznmMVector);
		writeUint(wr, tags[4], Length);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIAMMethodInvpar::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIAMMethodInvpar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmvvartype") ix |= SREFIXWZNMVVARTYPE;
		else if (ss[i] == "srefrefwznmmvector") ix |= SREFREFWZNMMVECTOR;
		else if (ss[i] == "length") ix |= LENGTH;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmJtr::ImeIAMMethodInvpar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIAMMethodInvpar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXWZNMVVARTYPE) ss.push_back("srefIxWznmVVartype");
	if (ix & SREFREFWZNMMVECTOR) ss.push_back("srefRefWznmMVector");
	if (ix & LENGTH) ss.push_back("Length");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIAMMethodInvpar
 ******************************************************************************/

IexWznmJtr::ImeIAMMethodInvpar::ImeIAMMethodInvpar() {
};

IexWznmJtr::ImeIAMMethodInvpar::~ImeIAMMethodInvpar() {
	clear();
};

void IexWznmJtr::ImeIAMMethodInvpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIAMMethodInvpar::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIAMMethodInvpar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmJtr::ImeitemIAMMethodInvpar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMethodInvpar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMMethodInvpar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMMETHODINVPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMethodInvpar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMethodInvpar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIAMMethodInvpar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIAMMethodInvpar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMMethodInvpar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMMethodInvpar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMMethodInvpar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIAMMethodInvpar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIAMMethodInvpar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMMethodInvpar." << StrMod::replaceChar(ImeIAMMethodInvpar::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMMethodInvpar.end" << endl;
	};
};

void IexWznmJtr::ImeIAMMethodInvpar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMMethodInvpar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIAMMethodRetpar
 ******************************************************************************/

IexWznmJtr::ImeitemIAMMethodRetpar::ImeitemIAMMethodRetpar(
			const string& sref
			, const uint ixWznmVVartype
			, const string& srefRefWznmMVector
			, const uint Length
			, const string& Comment
		) : WznmAMMethodRetpar() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->Length = Length;
	this->Comment = Comment;
};

IexWznmJtr::ImeitemIAMMethodRetpar::ImeitemIAMMethodRetpar(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMMethodRetpar()
		{
	WznmAMMethodRetpar* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmammethodretpar->loadRecByRef(ref, &rec)) {
		mtdRefWznmMMethod = rec->mtdRefWznmMMethod;
		mtdNum = rec->mtdNum;
		sref = rec->sref;
		ixWznmVVartype = rec->ixWznmVVartype;
		refWznmMVector = rec->refWznmMVector;
		Length = rec->Length;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIAMMethodRetpar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMMethodRetpar::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxWznmVVartype = txtrd.fields[1]; ixWIelValid += ImeIAMMethodRetpar::VecWIel::SREFIXWZNMVVARTYPE;};
	if (txtrd.fields.size() > 2) {srefRefWznmMVector = txtrd.fields[2]; ixWIelValid += ImeIAMMethodRetpar::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 3) {Length = atol(txtrd.fields[3].c_str()); ixWIelValid += ImeIAMMethodRetpar::VecWIel::LENGTH;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIAMMethodRetpar::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMMethodRetpar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIAMMethodRetpar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMMethodRetpar::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype)) ixWIelValid += ImeIAMMethodRetpar::VecWIel::SREFIXWZNMVVARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMMethodRetpar::VecWIel::SREFREFWZNMMVECTOR;
		if (extractUintUclc(docctx, basexpath, "Length", "len", Length)) ixWIelValid += ImeIAMMethodRetpar::VecWIel::LENGTH;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMMethodRetpar::VecWIel::COMMENT;
	};
};

void IexWznmJtr::ImeitemIAMMethodRetpar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << VecWznmVVartype::getSref(ixWznmVVartype) << "\t" << srefRefWznmMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWznmJtr::ImeitemIAMMethodRetpar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","vty","vec","len","cmt"};
	else tags = {"ImeitemIAMMethodRetpar","sref","srefIxWznmVVartype","srefRefWznmMVector","Length","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecWznmVVartype::getSref(ixWznmVVartype));
		writeString(wr, tags[3], srefRefWznmMVector);
		writeUint(wr, tags[4], Length);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIAMMethodRetpar::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIAMMethodRetpar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmvvartype") ix |= SREFIXWZNMVVARTYPE;
		else if (ss[i] == "srefrefwznmmvector") ix |= SREFREFWZNMMVECTOR;
		else if (ss[i] == "length") ix |= LENGTH;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmJtr::ImeIAMMethodRetpar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIAMMethodRetpar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXWZNMVVARTYPE) ss.push_back("srefIxWznmVVartype");
	if (ix & SREFREFWZNMMVECTOR) ss.push_back("srefRefWznmMVector");
	if (ix & LENGTH) ss.push_back("Length");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIAMMethodRetpar
 ******************************************************************************/

IexWznmJtr::ImeIAMMethodRetpar::ImeIAMMethodRetpar() {
};

IexWznmJtr::ImeIAMMethodRetpar::~ImeIAMMethodRetpar() {
	clear();
};

void IexWznmJtr::ImeIAMMethodRetpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIAMMethodRetpar::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIAMMethodRetpar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmJtr::ImeitemIAMMethodRetpar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMethodRetpar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMMethodRetpar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMMETHODRETPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMethodRetpar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMethodRetpar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIAMMethodRetpar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIAMMethodRetpar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMMethodRetpar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMMethodRetpar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMMethodRetpar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIAMMethodRetpar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIAMMethodRetpar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMMethodRetpar." << StrMod::replaceChar(ImeIAMMethodRetpar::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMMethodRetpar.end" << endl;
	};
};

void IexWznmJtr::ImeIAMMethodRetpar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMMethodRetpar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIMMethod
 ******************************************************************************/

IexWznmJtr::ImeitemIMMethod::ImeitemIMMethod(
			const string& sref
			, const bool Execsrv
			, const string& Comment
		) : WznmMMethod() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Execsrv = Execsrv;
	this->Comment = Comment;
};

IexWznmJtr::ImeitemIMMethod::ImeitemIMMethod(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMMethod()
		{
	WznmMMethod* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmmethod->loadRecByRef(ref, &rec)) {
		refWznmMJob = rec->refWznmMJob;
		sref = rec->sref;
		Execsrv = rec->Execsrv;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIMMethod::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMMethod::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Execsrv = (txtrd.fields[1] == "true"); ixWIelValid += ImeIMMethod::VecWIel::EXECSRV;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMMethod::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMMETHODINVPAR)) {
					imeiammethodinvpar.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMMETHODRETPAR)) {
					imeiammethodretpar.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMMethod"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIMMethod::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMMethod::VecWIel::SREF;
		if (extractBoolUclc(docctx, basexpath, "Execsrv", "exs", Execsrv)) ixWIelValid += ImeIMMethod::VecWIel::EXECSRV;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMMethod::VecWIel::COMMENT;
		imeiammethodinvpar.readXML(docctx, basexpath);
		imeiammethodretpar.readXML(docctx, basexpath);
	};
};

void IexWznmJtr::ImeitemIMMethod::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << StrMod::boolToString(Execsrv) << "\t" << Comment << endl;
	imeiammethodinvpar.writeTxt(outfile);
	imeiammethodretpar.writeTxt(outfile);
};

void IexWznmJtr::ImeitemIMMethod::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","exs","cmt"};
	else tags = {"ImeitemIMMethod","sref","Execsrv","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeBool(wr, tags[2], Execsrv);
		writeString(wr, tags[3], Comment);
		imeiammethodinvpar.writeXML(wr, shorttags);
		imeiammethodretpar.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIMMethod::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIMMethod::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "execsrv") ix |= EXECSRV;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmJtr::ImeIMMethod::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIMMethod::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & EXECSRV) ss.push_back("Execsrv");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIMMethod
 ******************************************************************************/

IexWznmJtr::ImeIMMethod::ImeIMMethod() {
};

IexWznmJtr::ImeIMMethod::~ImeIMMethod() {
	clear();
};

void IexWznmJtr::ImeIMMethod::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIMMethod::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIMMethod* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJtr::ImeitemIMMethod();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMMethod"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMMethod"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMMETHOD) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMMethod"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMMethod"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIMMethod::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIMMethod* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMMethod");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMMethod", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMMethod";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIMMethod();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIMMethod::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMMethod." << StrMod::replaceChar(ImeIMMethod::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMMethod.end" << endl;
	};
};

void IexWznmJtr::ImeIMMethod::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMMethod");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIMSensitivity1
 ******************************************************************************/

IexWznmJtr::ImeitemIMSensitivity1::ImeitemIMSensitivity1(
			const uint ixVBasetype
			, const string& srefRefWznmMCall
			, const uint ixVJactype
			, const uint ixVJobmask
			, const string& Jobshort
			, const string& Argpatt
			, const string& srefRefWznmMControl
			, const string& Srefmask
			, const uint ixVAction
			, const string& srefCsgRefWznmMStage
			, const bool Custcode
		) : WznmMSensitivity() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->srefRefWznmMCall = srefRefWznmMCall;
	this->ixVJactype = ixVJactype;
	this->ixVJobmask = ixVJobmask;
	this->Jobshort = Jobshort;
	this->Argpatt = Argpatt;
	this->srefRefWznmMControl = srefRefWznmMControl;
	this->Srefmask = Srefmask;
	this->ixVAction = ixVAction;
	this->srefCsgRefWznmMStage = srefCsgRefWznmMStage;
	this->Custcode = Custcode;
};

IexWznmJtr::ImeitemIMSensitivity1::ImeitemIMSensitivity1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMSensitivity1()
		{
	WznmMSensitivity* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmsensitivity->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMJob = rec->refWznmMJob;
		refWznmMCall = rec->refWznmMCall;
		ixVJactype = rec->ixVJactype;
		ixVJobmask = rec->ixVJobmask;
		Jobshort = rec->Jobshort;
		Argpatt = rec->Argpatt;
		refWznmMControl = rec->refWznmMControl;
		Srefmask = rec->Srefmask;
		ixVAction = rec->ixVAction;
		csgRefWznmMStage = rec->csgRefWznmMStage;
		Custcode = rec->Custcode;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIMSensitivity1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMSensitivity1::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {srefRefWznmMCall = txtrd.fields[1]; ixWIelValid += ImeIMSensitivity1::VecWIel::SREFREFWZNMMCALL;};
	if (txtrd.fields.size() > 2) {srefIxVJactype = txtrd.fields[2]; ixWIelValid += ImeIMSensitivity1::VecWIel::SREFIXVJACTYPE;};
	if (txtrd.fields.size() > 3) {srefIxVJobmask = txtrd.fields[3]; ixWIelValid += ImeIMSensitivity1::VecWIel::SREFIXVJOBMASK;};
	if (txtrd.fields.size() > 4) {Jobshort = txtrd.fields[4]; ixWIelValid += ImeIMSensitivity1::VecWIel::JOBSHORT;};
	if (txtrd.fields.size() > 5) {Argpatt = txtrd.fields[5]; ixWIelValid += ImeIMSensitivity1::VecWIel::ARGPATT;};
	if (txtrd.fields.size() > 6) {srefRefWznmMControl = txtrd.fields[6]; ixWIelValid += ImeIMSensitivity1::VecWIel::SREFREFWZNMMCONTROL;};
	if (txtrd.fields.size() > 7) {Srefmask = txtrd.fields[7]; ixWIelValid += ImeIMSensitivity1::VecWIel::SREFMASK;};
	if (txtrd.fields.size() > 8) {srefIxVAction = txtrd.fields[8]; ixWIelValid += ImeIMSensitivity1::VecWIel::SREFIXVACTION;};
	if (txtrd.fields.size() > 9) {srefCsgRefWznmMStage = txtrd.fields[9]; ixWIelValid += ImeIMSensitivity1::VecWIel::SREFCSGREFWZNMMSTAGE;};
	if (txtrd.fields.size() > 10) {Custcode = (txtrd.fields[10] == "true"); ixWIelValid += ImeIMSensitivity1::VecWIel::CUSTCODE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSensitivity1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIMSensitivity1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMSensitivity1::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMCall", "cal", srefRefWznmMCall)) ixWIelValid += ImeIMSensitivity1::VecWIel::SREFREFWZNMMCALL;
		if (extractStringUclc(docctx, basexpath, "srefIxVJactype", "jat", srefIxVJactype)) ixWIelValid += ImeIMSensitivity1::VecWIel::SREFIXVJACTYPE;
		if (extractStringUclc(docctx, basexpath, "srefIxVJobmask", "jms", srefIxVJobmask)) ixWIelValid += ImeIMSensitivity1::VecWIel::SREFIXVJOBMASK;
		if (extractStringUclc(docctx, basexpath, "Jobshort", "jsh", Jobshort)) ixWIelValid += ImeIMSensitivity1::VecWIel::JOBSHORT;
		if (extractStringUclc(docctx, basexpath, "Argpatt", "apt", Argpatt)) ixWIelValid += ImeIMSensitivity1::VecWIel::ARGPATT;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMControl", "con", srefRefWznmMControl)) ixWIelValid += ImeIMSensitivity1::VecWIel::SREFREFWZNMMCONTROL;
		if (extractStringUclc(docctx, basexpath, "Srefmask", "srm", Srefmask)) ixWIelValid += ImeIMSensitivity1::VecWIel::SREFMASK;
		if (extractStringUclc(docctx, basexpath, "srefIxVAction", "act", srefIxVAction)) ixWIelValid += ImeIMSensitivity1::VecWIel::SREFIXVACTION;
		if (extractStringUclc(docctx, basexpath, "srefCsgRefWznmMStage", "con", srefCsgRefWznmMStage)) ixWIelValid += ImeIMSensitivity1::VecWIel::SREFCSGREFWZNMMSTAGE;
		if (extractBoolUclc(docctx, basexpath, "Custcode", "ccd", Custcode)) ixWIelValid += ImeIMSensitivity1::VecWIel::CUSTCODE;
	};
};

void IexWznmJtr::ImeitemIMSensitivity1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVMSensitivityBasetype::getSref(ixVBasetype) << "\t" << srefRefWznmMCall << "\t" << VecWznmVMSensitivityJactype::getSref(ixVJactype) << "\t" << VecWznmVMSensitivityJobmask::getSref(ixVJobmask) << "\t" << Jobshort << "\t" << Argpatt << "\t" << srefRefWznmMControl << "\t" << Srefmask << "\t" << VecWznmVMSensitivityAction::getSref(ixVAction) << "\t" << srefCsgRefWznmMStage << "\t" << StrMod::boolToString(Custcode) << endl;
};

void IexWznmJtr::ImeitemIMSensitivity1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","cal","jat","jms","jsh","apt","con","srm","act","con","ccd"};
	else tags = {"ImeitemIMSensitivity1","srefIxVBasetype","srefRefWznmMCall","srefIxVJactype","srefIxVJobmask","Jobshort","Argpatt","srefRefWznmMControl","Srefmask","srefIxVAction","srefCsgRefWznmMStage","Custcode"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMSensitivityBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], srefRefWznmMCall);
		writeString(wr, tags[3], VecWznmVMSensitivityJactype::getSref(ixVJactype));
		writeString(wr, tags[4], VecWznmVMSensitivityJobmask::getSref(ixVJobmask));
		writeString(wr, tags[5], Jobshort);
		writeString(wr, tags[6], Argpatt);
		writeString(wr, tags[7], srefRefWznmMControl);
		writeString(wr, tags[8], Srefmask);
		writeString(wr, tags[9], VecWznmVMSensitivityAction::getSref(ixVAction));
		writeString(wr, tags[10], srefCsgRefWznmMStage);
		writeBool(wr, tags[11], Custcode);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIMSensitivity1::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIMSensitivity1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefrefwznmmcall") ix |= SREFREFWZNMMCALL;
		else if (ss[i] == "srefixvjactype") ix |= SREFIXVJACTYPE;
		else if (ss[i] == "srefixvjobmask") ix |= SREFIXVJOBMASK;
		else if (ss[i] == "jobshort") ix |= JOBSHORT;
		else if (ss[i] == "argpatt") ix |= ARGPATT;
		else if (ss[i] == "srefrefwznmmcontrol") ix |= SREFREFWZNMMCONTROL;
		else if (ss[i] == "srefmask") ix |= SREFMASK;
		else if (ss[i] == "srefixvaction") ix |= SREFIXVACTION;
		else if (ss[i] == "srefcsgrefwznmmstage") ix |= SREFCSGREFWZNMMSTAGE;
		else if (ss[i] == "custcode") ix |= CUSTCODE;
	};

	return(ix);
};

void IexWznmJtr::ImeIMSensitivity1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*CUSTCODE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIMSensitivity1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFREFWZNMMCALL) ss.push_back("srefRefWznmMCall");
	if (ix & SREFIXVJACTYPE) ss.push_back("srefIxVJactype");
	if (ix & SREFIXVJOBMASK) ss.push_back("srefIxVJobmask");
	if (ix & JOBSHORT) ss.push_back("Jobshort");
	if (ix & ARGPATT) ss.push_back("Argpatt");
	if (ix & SREFREFWZNMMCONTROL) ss.push_back("srefRefWznmMControl");
	if (ix & SREFMASK) ss.push_back("Srefmask");
	if (ix & SREFIXVACTION) ss.push_back("srefIxVAction");
	if (ix & SREFCSGREFWZNMMSTAGE) ss.push_back("srefCsgRefWznmMStage");
	if (ix & CUSTCODE) ss.push_back("Custcode");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIMSensitivity1
 ******************************************************************************/

IexWznmJtr::ImeIMSensitivity1::ImeIMSensitivity1() {
};

IexWznmJtr::ImeIMSensitivity1::~ImeIMSensitivity1() {
	clear();
};

void IexWznmJtr::ImeIMSensitivity1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIMSensitivity1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIMSensitivity1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJtr::ImeitemIMSensitivity1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSensitivity1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSensitivity1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSENSITIVITY1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSensitivity1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSensitivity1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIMSensitivity1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIMSensitivity1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSensitivity1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSensitivity1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSensitivity1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIMSensitivity1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIMSensitivity1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMSensitivity1." << StrMod::replaceChar(ImeIMSensitivity1::VecWIel::getSrefs(2047), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMSensitivity1.end" << endl;
	};
};

void IexWznmJtr::ImeIMSensitivity1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSensitivity1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIMSensitivity2
 ******************************************************************************/

IexWznmJtr::ImeitemIMSensitivity2::ImeitemIMSensitivity2(
			const uint ixVBasetype
			, const string& srefRefWznmMCall
			, const uint ixVJactype
			, const uint ixVJobmask
			, const string& Jobshort
			, const string& Argpatt
			, const string& srefRefWznmMControl
			, const string& Srefmask
			, const uint ixVAction
			, const string& srefCsgRefWznmMStage
			, const bool Custcode
		) : WznmMSensitivity() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->srefRefWznmMCall = srefRefWznmMCall;
	this->ixVJactype = ixVJactype;
	this->ixVJobmask = ixVJobmask;
	this->Jobshort = Jobshort;
	this->Argpatt = Argpatt;
	this->srefRefWznmMControl = srefRefWznmMControl;
	this->Srefmask = Srefmask;
	this->ixVAction = ixVAction;
	this->srefCsgRefWznmMStage = srefCsgRefWznmMStage;
	this->Custcode = Custcode;
};

IexWznmJtr::ImeitemIMSensitivity2::ImeitemIMSensitivity2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMSensitivity2()
		{
	WznmMSensitivity* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmsensitivity->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMJob = rec->refWznmMJob;
		refWznmMStage = rec->refWznmMStage;
		refWznmMCall = rec->refWznmMCall;
		ixVJactype = rec->ixVJactype;
		ixVJobmask = rec->ixVJobmask;
		Jobshort = rec->Jobshort;
		Argpatt = rec->Argpatt;
		refWznmMControl = rec->refWznmMControl;
		Srefmask = rec->Srefmask;
		ixVAction = rec->ixVAction;
		csgRefWznmMStage = rec->csgRefWznmMStage;
		Custcode = rec->Custcode;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIMSensitivity2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMSensitivity2::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {srefRefWznmMCall = txtrd.fields[1]; ixWIelValid += ImeIMSensitivity2::VecWIel::SREFREFWZNMMCALL;};
	if (txtrd.fields.size() > 2) {srefIxVJactype = txtrd.fields[2]; ixWIelValid += ImeIMSensitivity2::VecWIel::SREFIXVJACTYPE;};
	if (txtrd.fields.size() > 3) {srefIxVJobmask = txtrd.fields[3]; ixWIelValid += ImeIMSensitivity2::VecWIel::SREFIXVJOBMASK;};
	if (txtrd.fields.size() > 4) {Jobshort = txtrd.fields[4]; ixWIelValid += ImeIMSensitivity2::VecWIel::JOBSHORT;};
	if (txtrd.fields.size() > 5) {Argpatt = txtrd.fields[5]; ixWIelValid += ImeIMSensitivity2::VecWIel::ARGPATT;};
	if (txtrd.fields.size() > 6) {srefRefWznmMControl = txtrd.fields[6]; ixWIelValid += ImeIMSensitivity2::VecWIel::SREFREFWZNMMCONTROL;};
	if (txtrd.fields.size() > 7) {Srefmask = txtrd.fields[7]; ixWIelValid += ImeIMSensitivity2::VecWIel::SREFMASK;};
	if (txtrd.fields.size() > 8) {srefIxVAction = txtrd.fields[8]; ixWIelValid += ImeIMSensitivity2::VecWIel::SREFIXVACTION;};
	if (txtrd.fields.size() > 9) {srefCsgRefWznmMStage = txtrd.fields[9]; ixWIelValid += ImeIMSensitivity2::VecWIel::SREFCSGREFWZNMMSTAGE;};
	if (txtrd.fields.size() > 10) {Custcode = (txtrd.fields[10] == "true"); ixWIelValid += ImeIMSensitivity2::VecWIel::CUSTCODE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSensitivity2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIMSensitivity2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMSensitivity2::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMCall", "cal", srefRefWznmMCall)) ixWIelValid += ImeIMSensitivity2::VecWIel::SREFREFWZNMMCALL;
		if (extractStringUclc(docctx, basexpath, "srefIxVJactype", "jat", srefIxVJactype)) ixWIelValid += ImeIMSensitivity2::VecWIel::SREFIXVJACTYPE;
		if (extractStringUclc(docctx, basexpath, "srefIxVJobmask", "jms", srefIxVJobmask)) ixWIelValid += ImeIMSensitivity2::VecWIel::SREFIXVJOBMASK;
		if (extractStringUclc(docctx, basexpath, "Jobshort", "jsh", Jobshort)) ixWIelValid += ImeIMSensitivity2::VecWIel::JOBSHORT;
		if (extractStringUclc(docctx, basexpath, "Argpatt", "apt", Argpatt)) ixWIelValid += ImeIMSensitivity2::VecWIel::ARGPATT;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMControl", "con", srefRefWznmMControl)) ixWIelValid += ImeIMSensitivity2::VecWIel::SREFREFWZNMMCONTROL;
		if (extractStringUclc(docctx, basexpath, "Srefmask", "srm", Srefmask)) ixWIelValid += ImeIMSensitivity2::VecWIel::SREFMASK;
		if (extractStringUclc(docctx, basexpath, "srefIxVAction", "act", srefIxVAction)) ixWIelValid += ImeIMSensitivity2::VecWIel::SREFIXVACTION;
		if (extractStringUclc(docctx, basexpath, "srefCsgRefWznmMStage", "con", srefCsgRefWznmMStage)) ixWIelValid += ImeIMSensitivity2::VecWIel::SREFCSGREFWZNMMSTAGE;
		if (extractBoolUclc(docctx, basexpath, "Custcode", "ccd", Custcode)) ixWIelValid += ImeIMSensitivity2::VecWIel::CUSTCODE;
	};
};

void IexWznmJtr::ImeitemIMSensitivity2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVMSensitivityBasetype::getSref(ixVBasetype) << "\t" << srefRefWznmMCall << "\t" << VecWznmVMSensitivityJactype::getSref(ixVJactype) << "\t" << VecWznmVMSensitivityJobmask::getSref(ixVJobmask) << "\t" << Jobshort << "\t" << Argpatt << "\t" << srefRefWznmMControl << "\t" << Srefmask << "\t" << VecWznmVMSensitivityAction::getSref(ixVAction) << "\t" << srefCsgRefWznmMStage << "\t" << StrMod::boolToString(Custcode) << endl;
};

void IexWznmJtr::ImeitemIMSensitivity2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","cal","jat","jms","jsh","apt","con","srm","act","con","ccd"};
	else tags = {"ImeitemIMSensitivity2","srefIxVBasetype","srefRefWznmMCall","srefIxVJactype","srefIxVJobmask","Jobshort","Argpatt","srefRefWznmMControl","Srefmask","srefIxVAction","srefCsgRefWznmMStage","Custcode"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMSensitivityBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], srefRefWznmMCall);
		writeString(wr, tags[3], VecWznmVMSensitivityJactype::getSref(ixVJactype));
		writeString(wr, tags[4], VecWznmVMSensitivityJobmask::getSref(ixVJobmask));
		writeString(wr, tags[5], Jobshort);
		writeString(wr, tags[6], Argpatt);
		writeString(wr, tags[7], srefRefWznmMControl);
		writeString(wr, tags[8], Srefmask);
		writeString(wr, tags[9], VecWznmVMSensitivityAction::getSref(ixVAction));
		writeString(wr, tags[10], srefCsgRefWznmMStage);
		writeBool(wr, tags[11], Custcode);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIMSensitivity2::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIMSensitivity2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefrefwznmmcall") ix |= SREFREFWZNMMCALL;
		else if (ss[i] == "srefixvjactype") ix |= SREFIXVJACTYPE;
		else if (ss[i] == "srefixvjobmask") ix |= SREFIXVJOBMASK;
		else if (ss[i] == "jobshort") ix |= JOBSHORT;
		else if (ss[i] == "argpatt") ix |= ARGPATT;
		else if (ss[i] == "srefrefwznmmcontrol") ix |= SREFREFWZNMMCONTROL;
		else if (ss[i] == "srefmask") ix |= SREFMASK;
		else if (ss[i] == "srefixvaction") ix |= SREFIXVACTION;
		else if (ss[i] == "srefcsgrefwznmmstage") ix |= SREFCSGREFWZNMMSTAGE;
		else if (ss[i] == "custcode") ix |= CUSTCODE;
	};

	return(ix);
};

void IexWznmJtr::ImeIMSensitivity2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*CUSTCODE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIMSensitivity2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFREFWZNMMCALL) ss.push_back("srefRefWznmMCall");
	if (ix & SREFIXVJACTYPE) ss.push_back("srefIxVJactype");
	if (ix & SREFIXVJOBMASK) ss.push_back("srefIxVJobmask");
	if (ix & JOBSHORT) ss.push_back("Jobshort");
	if (ix & ARGPATT) ss.push_back("Argpatt");
	if (ix & SREFREFWZNMMCONTROL) ss.push_back("srefRefWznmMControl");
	if (ix & SREFMASK) ss.push_back("Srefmask");
	if (ix & SREFIXVACTION) ss.push_back("srefIxVAction");
	if (ix & SREFCSGREFWZNMMSTAGE) ss.push_back("srefCsgRefWznmMStage");
	if (ix & CUSTCODE) ss.push_back("Custcode");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIMSensitivity2
 ******************************************************************************/

IexWznmJtr::ImeIMSensitivity2::ImeIMSensitivity2() {
};

IexWznmJtr::ImeIMSensitivity2::~ImeIMSensitivity2() {
	clear();
};

void IexWznmJtr::ImeIMSensitivity2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIMSensitivity2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIMSensitivity2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmJtr::ImeitemIMSensitivity2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSensitivity2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSensitivity2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSENSITIVITY2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSensitivity2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSensitivity2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIMSensitivity2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIMSensitivity2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSensitivity2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSensitivity2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSensitivity2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIMSensitivity2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIMSensitivity2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMSensitivity2." << StrMod::replaceChar(ImeIMSensitivity2::VecWIel::getSrefs(2047), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMSensitivity2.end" << endl;
	};
};

void IexWznmJtr::ImeIMSensitivity2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSensitivity2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIJMSquawkTitle
 ******************************************************************************/

IexWznmJtr::ImeitemIJMSquawkTitle::ImeitemIJMSquawkTitle(
			const string& srefX1RefWznmMLocale
			, const string& Title
		) : WznmJMSquawkTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
};

IexWznmJtr::ImeitemIJMSquawkTitle::ImeitemIJMSquawkTitle(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMSquawkTitle()
		{
	WznmJMSquawkTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmjmsquawktitle->loadRecByRef(ref, &rec)) {
		refWznmMSquawk = rec->refWznmMSquawk;
		x1RefWznmMLocale = rec->x1RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIJMSquawkTitle::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMSquawkTitle::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMSquawkTitle::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMSquawkTitle"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIJMSquawkTitle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMSquawkTitle::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMSquawkTitle::VecWIel::TITLE;
	};
};

void IexWznmJtr::ImeitemIJMSquawkTitle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefX1RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmJtr::ImeitemIJMSquawkTitle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit"};
	else tags = {"ImeitemIJMSquawkTitle","srefX1RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIJMSquawkTitle::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIJMSquawkTitle::VecWIel::getIx(
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

void IexWznmJtr::ImeIJMSquawkTitle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIJMSquawkTitle::VecWIel::getSrefs(
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
 class IexWznmJtr::ImeIJMSquawkTitle
 ******************************************************************************/

IexWznmJtr::ImeIJMSquawkTitle::ImeIJMSquawkTitle() {
};

IexWznmJtr::ImeIJMSquawkTitle::~ImeIJMSquawkTitle() {
	clear();
};

void IexWznmJtr::ImeIJMSquawkTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIJMSquawkTitle::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIJMSquawkTitle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmJtr::ImeitemIJMSquawkTitle();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMSquawkTitle"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMSquawkTitle"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMSQUAWKTITLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMSquawkTitle"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMSquawkTitle"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIJMSquawkTitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIJMSquawkTitle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMSquawkTitle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMSquawkTitle", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMSquawkTitle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIJMSquawkTitle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIJMSquawkTitle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMSquawkTitle." << StrMod::replaceChar(ImeIJMSquawkTitle::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMSquawkTitle.end" << endl;
	};
};

void IexWznmJtr::ImeIJMSquawkTitle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMSquawkTitle");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIRMSquawkMStub
 ******************************************************************************/

IexWznmJtr::ImeitemIRMSquawkMStub::ImeitemIRMSquawkMStub(
			const string& srefRefWznmMStub
		) : WznmRMSquawkMStub() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMStub = srefRefWznmMStub;
};

IexWznmJtr::ImeitemIRMSquawkMStub::ImeitemIRMSquawkMStub(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMSquawkMStub()
		{
	WznmRMSquawkMStub* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmsquawkmstub->loadRecByRef(ref, &rec)) {
		refWznmMSquawk = rec->refWznmMSquawk;
		refWznmMStub = rec->refWznmMStub;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIRMSquawkMStub::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMStub = txtrd.fields[0]; ixWIelValid += ImeIRMSquawkMStub::VecWIel::SREFREFWZNMMSTUB;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMSquawkMStub"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIRMSquawkMStub::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMStub", "stb", srefRefWznmMStub)) ixWIelValid += ImeIRMSquawkMStub::VecWIel::SREFREFWZNMMSTUB;
	};
};

void IexWznmJtr::ImeitemIRMSquawkMStub::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefRefWznmMStub << endl;
};

void IexWznmJtr::ImeitemIRMSquawkMStub::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","stb"};
	else tags = {"ImeitemIRMSquawkMStub","srefRefWznmMStub"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMStub);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIRMSquawkMStub::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIRMSquawkMStub::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwznmmstub") ix |= SREFREFWZNMMSTUB;
	};

	return(ix);
};

void IexWznmJtr::ImeIRMSquawkMStub::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMSTUB); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIRMSquawkMStub::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMSTUB) ss.push_back("srefRefWznmMStub");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIRMSquawkMStub
 ******************************************************************************/

IexWznmJtr::ImeIRMSquawkMStub::ImeIRMSquawkMStub() {
};

IexWznmJtr::ImeIRMSquawkMStub::~ImeIRMSquawkMStub() {
	clear();
};

void IexWznmJtr::ImeIRMSquawkMStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIRMSquawkMStub::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIRMSquawkMStub* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmJtr::ImeitemIRMSquawkMStub();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMSquawkMStub"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMSquawkMStub"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMSQUAWKMSTUB) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMSquawkMStub"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMSquawkMStub"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIRMSquawkMStub::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIRMSquawkMStub* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMSquawkMStub");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMSquawkMStub", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMSquawkMStub";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIRMSquawkMStub();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIRMSquawkMStub::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIRMSquawkMStub." << StrMod::replaceChar(ImeIRMSquawkMStub::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIRMSquawkMStub.end" << endl;
	};
};

void IexWznmJtr::ImeIRMSquawkMStub::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMSquawkMStub");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIMSquawk
 ******************************************************************************/

IexWznmJtr::ImeitemIMSquawk::ImeitemIMSquawk(
			const string& Title
			, const string& Example
		) : WznmMSquawk() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
	this->Example = Example;
};

IexWznmJtr::ImeitemIMSquawk::ImeitemIMSquawk(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMSquawk()
		{
	WznmMSquawk* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmsquawk->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		refJTitle = rec->refJTitle;
		Title = rec->Title;
		Example = rec->Example;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIMSquawk::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Title = txtrd.fields[0]; ixWIelValid += ImeIMSquawk::VecWIel::TITLE;};
	if (txtrd.fields.size() > 1) {Example = txtrd.fields[1]; ixWIelValid += ImeIMSquawk::VecWIel::EXAMPLE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMSQUAWKTITLE)) {
					imeijmsquawktitle.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIRMSQUAWKMSTUB)) {
					imeirmsquawkmstub.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSquawk"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIMSquawk::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMSquawk::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Example", "exa", Example)) ixWIelValid += ImeIMSquawk::VecWIel::EXAMPLE;
		imeijmsquawktitle.readXML(docctx, basexpath);
		imeirmsquawkmstub.readXML(docctx, basexpath);
	};
};

void IexWznmJtr::ImeitemIMSquawk::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << Title << "\t" << Example << endl;
	imeijmsquawktitle.writeTxt(outfile);
	imeirmsquawkmstub.writeTxt(outfile);
};

void IexWznmJtr::ImeitemIMSquawk::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tit","exa"};
	else tags = {"ImeitemIMSquawk","Title","Example"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Title);
		writeString(wr, tags[2], Example);
		imeijmsquawktitle.writeXML(wr, shorttags);
		imeirmsquawkmstub.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIMSquawk::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIMSquawk::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "example") ix |= EXAMPLE;
	};

	return(ix);
};

void IexWznmJtr::ImeIMSquawk::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*EXAMPLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIMSquawk::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & TITLE) ss.push_back("Title");
	if (ix & EXAMPLE) ss.push_back("Example");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIMSquawk
 ******************************************************************************/

IexWznmJtr::ImeIMSquawk::ImeIMSquawk() {
};

IexWznmJtr::ImeIMSquawk::~ImeIMSquawk() {
	clear();
};

void IexWznmJtr::ImeIMSquawk::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIMSquawk::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIMSquawk* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmJtr::ImeitemIMSquawk();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSquawk"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSquawk"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSQUAWK) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSquawk"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSquawk"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIMSquawk::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIMSquawk* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSquawk");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSquawk", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSquawk";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIMSquawk();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIMSquawk::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMSquawk." << StrMod::replaceChar(ImeIMSquawk::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMSquawk.end" << endl;
	};
};

void IexWznmJtr::ImeIMSquawk::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSquawk");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIMStage
 ******************************************************************************/

IexWznmJtr::ImeitemIMStage::ImeitemIMStage(
			const uint ixVBasetype
			, const string& sref
			, const uint Monitvl
			, const string& srefSnxRefWznmMStage
			, const string& srefFnxRefWznmMStage
			, const string& srefEnxRefWznmMStage
			, const string& Comment
		) : WznmMStage() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->Monitvl = Monitvl;
	this->srefSnxRefWznmMStage = srefSnxRefWznmMStage;
	this->srefFnxRefWznmMStage = srefFnxRefWznmMStage;
	this->srefEnxRefWznmMStage = srefEnxRefWznmMStage;
	this->Comment = Comment;
};

IexWznmJtr::ImeitemIMStage::ImeitemIMStage(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMStage()
		{
	WznmMStage* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmstage->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		jobRefWznmMJob = rec->jobRefWznmMJob;
		jobNum = rec->jobNum;
		refWznmMSquawk = rec->refWznmMSquawk;
		sref = rec->sref;
		Monitvl = rec->Monitvl;
		snxRefWznmMStage = rec->snxRefWznmMStage;
		fnxRefWznmMStage = rec->fnxRefWznmMStage;
		enxRefWznmMStage = rec->enxRefWznmMStage;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIMStage::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMStage::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMStage::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Monitvl = atol(txtrd.fields[2].c_str()); ixWIelValid += ImeIMStage::VecWIel::MONITVL;};
	if (txtrd.fields.size() > 3) {srefSnxRefWznmMStage = txtrd.fields[3]; ixWIelValid += ImeIMStage::VecWIel::SREFSNXREFWZNMMSTAGE;};
	if (txtrd.fields.size() > 4) {srefFnxRefWznmMStage = txtrd.fields[4]; ixWIelValid += ImeIMStage::VecWIel::SREFFNXREFWZNMMSTAGE;};
	if (txtrd.fields.size() > 5) {srefEnxRefWznmMStage = txtrd.fields[5]; ixWIelValid += ImeIMStage::VecWIel::SREFENXREFWZNMMSTAGE;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMStage::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMSENSITIVITY2)) {
					imeimsensitivity2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMSQUAWK)) {
					imeimsquawk.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMStage"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIMStage::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMStage::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMStage::VecWIel::SREF;
		if (extractUintUclc(docctx, basexpath, "Monitvl", "mon", Monitvl)) ixWIelValid += ImeIMStage::VecWIel::MONITVL;
		if (extractStringUclc(docctx, basexpath, "srefSnxRefWznmMStage", "snx", srefSnxRefWznmMStage)) ixWIelValid += ImeIMStage::VecWIel::SREFSNXREFWZNMMSTAGE;
		if (extractStringUclc(docctx, basexpath, "srefFnxRefWznmMStage", "fnx", srefFnxRefWznmMStage)) ixWIelValid += ImeIMStage::VecWIel::SREFFNXREFWZNMMSTAGE;
		if (extractStringUclc(docctx, basexpath, "srefEnxRefWznmMStage", "enx", srefEnxRefWznmMStage)) ixWIelValid += ImeIMStage::VecWIel::SREFENXREFWZNMMSTAGE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMStage::VecWIel::COMMENT;
		imeimsensitivity2.readXML(docctx, basexpath);
		imeimsquawk.readXML(docctx, basexpath);
	};
};

void IexWznmJtr::ImeitemIMStage::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVMStageBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << Monitvl << "\t" << srefSnxRefWznmMStage << "\t" << srefFnxRefWznmMStage << "\t" << srefEnxRefWznmMStage << "\t" << Comment << endl;
	imeimsensitivity2.writeTxt(outfile);
	imeimsquawk.writeTxt(outfile);
};

void IexWznmJtr::ImeitemIMStage::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","srf","mon","snx","fnx","enx","cmt"};
	else tags = {"ImeitemIMStage","srefIxVBasetype","sref","Monitvl","srefSnxRefWznmMStage","srefFnxRefWznmMStage","srefEnxRefWznmMStage","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMStageBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], sref);
		writeUint(wr, tags[3], Monitvl);
		writeString(wr, tags[4], srefSnxRefWznmMStage);
		writeString(wr, tags[5], srefFnxRefWznmMStage);
		writeString(wr, tags[6], srefEnxRefWznmMStage);
		writeString(wr, tags[7], Comment);
		imeimsensitivity2.writeXML(wr, shorttags);
		imeimsquawk.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIMStage::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIMStage::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "monitvl") ix |= MONITVL;
		else if (ss[i] == "srefsnxrefwznmmstage") ix |= SREFSNXREFWZNMMSTAGE;
		else if (ss[i] == "sreffnxrefwznmmstage") ix |= SREFFNXREFWZNMMSTAGE;
		else if (ss[i] == "srefenxrefwznmmstage") ix |= SREFENXREFWZNMMSTAGE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmJtr::ImeIMStage::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIMStage::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & MONITVL) ss.push_back("Monitvl");
	if (ix & SREFSNXREFWZNMMSTAGE) ss.push_back("srefSnxRefWznmMStage");
	if (ix & SREFFNXREFWZNMMSTAGE) ss.push_back("srefFnxRefWznmMStage");
	if (ix & SREFENXREFWZNMMSTAGE) ss.push_back("srefEnxRefWznmMStage");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIMStage
 ******************************************************************************/

IexWznmJtr::ImeIMStage::ImeIMStage() {
};

IexWznmJtr::ImeIMStage::~ImeIMStage() {
	clear();
};

void IexWznmJtr::ImeIMStage::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIMStage::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIMStage* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJtr::ImeitemIMStage();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMStage"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMStage"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSTAGE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMStage"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMStage"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIMStage::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIMStage* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMStage");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMStage", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMStage";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIMStage();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIMStage::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMStage." << StrMod::replaceChar(ImeIMStage::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMStage.end" << endl;
	};
};

void IexWznmJtr::ImeIMStage::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMStage");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIJMVectoritem
 ******************************************************************************/

IexWznmJtr::ImeitemIJMVectoritem::ImeitemIJMVectoritem(
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

IexWznmJtr::ImeitemIJMVectoritem::ImeitemIJMVectoritem(
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

void IexWznmJtr::ImeitemIJMVectoritem::readTxt(
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

void IexWznmJtr::ImeitemIJMVectoritem::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMVectoritem::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMVectoritem::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJMVectoritem::VecWIel::COMMENT;
	};
};

void IexWznmJtr::ImeitemIJMVectoritem::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefX1RefWznmMLocale << "\t" << Title << "\t" << Comment << endl;
};

void IexWznmJtr::ImeitemIJMVectoritem::writeXML(
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
 class IexWznmJtr::ImeIJMVectoritem::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIJMVectoritem::VecWIel::getIx(
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

void IexWznmJtr::ImeIJMVectoritem::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIJMVectoritem::VecWIel::getSrefs(
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
 class IexWznmJtr::ImeIJMVectoritem
 ******************************************************************************/

IexWznmJtr::ImeIJMVectoritem::ImeIJMVectoritem() {
};

IexWznmJtr::ImeIJMVectoritem::~ImeIJMVectoritem() {
	clear();
};

void IexWznmJtr::ImeIJMVectoritem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIJMVectoritem::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIJMVectoritem* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmJtr::ImeitemIJMVectoritem();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
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

void IexWznmJtr::ImeIJMVectoritem::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIJMVectoritem* ii = NULL;

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

			ii = new IexWznmJtr::ImeitemIJMVectoritem();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIJMVectoritem::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMVectoritem." << StrMod::replaceChar(ImeIJMVectoritem::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMVectoritem.end" << endl;
	};
};

void IexWznmJtr::ImeIJMVectoritem::writeXML(
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
 class IexWznmJtr::ImeitemIMVectoritem
 ******************************************************************************/

IexWznmJtr::ImeitemIMVectoritem::ImeitemIMVectoritem(
			const string& sref
			, const string& Title
			, const string& Comment
		) : WznmMVectoritem() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Title = Title;
	this->Comment = Comment;
};

IexWznmJtr::ImeitemIMVectoritem::ImeitemIMVectoritem(
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
		refJ = rec->refJ;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIMVectoritem::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMVectoritem::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMVectoritem::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMVectoritem::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMVECTORITEM)) {
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

void IexWznmJtr::ImeitemIMVectoritem::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVectoritem::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMVectoritem::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVectoritem::VecWIel::COMMENT;
		imeijmvectoritem.readXML(docctx, basexpath);
	};
};

void IexWznmJtr::ImeitemIMVectoritem::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << Title << "\t" << Comment << endl;
	imeijmvectoritem.writeTxt(outfile);
};

void IexWznmJtr::ImeitemIMVectoritem::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit","cmt"};
	else tags = {"ImeitemIMVectoritem","sref","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
		imeijmvectoritem.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIMVectoritem::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIMVectoritem::VecWIel::getIx(
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

void IexWznmJtr::ImeIMVectoritem::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIMVectoritem::VecWIel::getSrefs(
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
 class IexWznmJtr::ImeIMVectoritem
 ******************************************************************************/

IexWznmJtr::ImeIMVectoritem::ImeIMVectoritem() {
};

IexWznmJtr::ImeIMVectoritem::~ImeIMVectoritem() {
	clear();
};

void IexWznmJtr::ImeIMVectoritem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIMVectoritem::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIMVectoritem* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmJtr::ImeitemIMVectoritem();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
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

void IexWznmJtr::ImeIMVectoritem::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIMVectoritem* ii = NULL;

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

			ii = new IexWznmJtr::ImeitemIMVectoritem();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIMVectoritem::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMVectoritem." << StrMod::replaceChar(ImeIMVectoritem::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMVectoritem.end" << endl;
	};
};

void IexWznmJtr::ImeIMVectoritem::writeXML(
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
 class IexWznmJtr::ImeitemIMVector
 ******************************************************************************/

IexWznmJtr::ImeitemIMVector::ImeitemIMVector(
			const uint ixWznmVIop
			, const uint ixVBasetype
			, const string& sref
			, const string& osrefWznmKTaggrp
			, const string& srefsKOption
		) : WznmMVector() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWznmVIop = ixWznmVIop;
	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->osrefWznmKTaggrp = osrefWznmKTaggrp;
	this->srefsKOption = srefsKOption;
};

IexWznmJtr::ImeitemIMVector::ImeitemIMVector(
			DbsWznm* dbswznm
			, const uint ixWznmVIop
			, const ubigint ref
		) :
			ImeitemIMVector(ixWznmVIop)
		{
	WznmMVector* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmvector->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMVersion = rec->refWznmMVersion;
		hkIxVTbl = rec->hkIxVTbl;
		hkUref = rec->hkUref;
		sref = rec->sref;
		osrefWznmKTaggrp = rec->osrefWznmKTaggrp;
		srefsKOption = rec->srefsKOption;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIMVector::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWznmVIop = txtrd.fields[0]; ixWIelValid += ImeIMVector::VecWIel::SREFIXWZNMVIOP;};
	if (txtrd.fields.size() > 1) {srefIxVBasetype = txtrd.fields[1]; ixWIelValid += ImeIMVector::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMVector::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {osrefWznmKTaggrp = txtrd.fields[3]; ixWIelValid += ImeIMVector::VecWIel::OSREFWZNMKTAGGRP;};
	if (txtrd.fields.size() > 4) {srefsKOption = txtrd.fields[4]; ixWIelValid += ImeIMVector::VecWIel::SREFSKOPTION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMVECTORITEM)) {
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

void IexWznmJtr::ImeitemIMVector::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVIop", "iop", srefIxWznmVIop)) ixWIelValid += ImeIMVector::VecWIel::SREFIXWZNMVIOP;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMVector::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVector::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "osrefWznmKTaggrp", "tgr", osrefWznmKTaggrp)) ixWIelValid += ImeIMVector::VecWIel::OSREFWZNMKTAGGRP;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMVector::VecWIel::SREFSKOPTION;
		imeimvectoritem.readXML(docctx, basexpath);
	};
};

void IexWznmJtr::ImeitemIMVector::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVIop::getSref(ixWznmVIop) << "\t" << VecWznmVMVectorBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << osrefWznmKTaggrp << "\t" << srefsKOption << endl;
	imeimvectoritem.writeTxt(outfile);
};

void IexWznmJtr::ImeitemIMVector::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","typ","srf","tgr","opt"};
	else tags = {"ImeitemIMVector","srefIxWznmVIop","srefIxVBasetype","sref","osrefWznmKTaggrp","srefsKOption"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVIop::getSref(ixWznmVIop));
		writeString(wr, tags[2], VecWznmVMVectorBasetype::getSref(ixVBasetype));
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], osrefWznmKTaggrp);
		writeString(wr, tags[5], srefsKOption);
		imeimvectoritem.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIMVector::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIMVector::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwznmviop") ix |= SREFIXWZNMVIOP;
		else if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "osrefwznmktaggrp") ix |= OSREFWZNMKTAGGRP;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
	};

	return(ix);
};

void IexWznmJtr::ImeIMVector::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIMVector::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWZNMVIOP) ss.push_back("srefIxWznmVIop");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & OSREFWZNMKTAGGRP) ss.push_back("osrefWznmKTaggrp");
	if (ix & SREFSKOPTION) ss.push_back("srefsKOption");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIMVector
 ******************************************************************************/

IexWznmJtr::ImeIMVector::ImeIMVector() {
};

IexWznmJtr::ImeIMVector::~ImeIMVector() {
	clear();
};

void IexWznmJtr::ImeIMVector::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIMVector::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIMVector* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJtr::ImeitemIMVector();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector"}, {"lineno",to_string(txtrd.linecnt)}});

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

void IexWznmJtr::ImeIMVector::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIMVector* ii = NULL;

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

			ii = new IexWznmJtr::ImeitemIMVector();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIMVector::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMVector." << StrMod::replaceChar(ImeIMVector::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMVector.end" << endl;
	};
};

void IexWznmJtr::ImeIMVector::writeXML(
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
 class IexWznmJtr::ImeitemIRMJobMJob
 ******************************************************************************/

IexWznmJtr::ImeitemIRMJobMJob::ImeitemIRMJobMJob(
			const string& srefSubRefWznmMJob
			, const string& Short
			, const bool Multi
			, const uint ixVConstract
		) : WznmRMJobMJob() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefSubRefWznmMJob = srefSubRefWznmMJob;
	this->Short = Short;
	this->Multi = Multi;
	this->ixVConstract = ixVConstract;
};

IexWznmJtr::ImeitemIRMJobMJob::ImeitemIRMJobMJob(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMJobMJob()
		{
	WznmRMJobMJob* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmjobmjob->loadRecByRef(ref, &rec)) {
		supRefWznmMJob = rec->supRefWznmMJob;
		subRefWznmMJob = rec->subRefWznmMJob;
		Short = rec->Short;
		Multi = rec->Multi;
		ixVConstract = rec->ixVConstract;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIRMJobMJob::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefSubRefWznmMJob = txtrd.fields[0]; ixWIelValid += ImeIRMJobMJob::VecWIel::SREFSUBREFWZNMMJOB;};
	if (txtrd.fields.size() > 1) {Short = txtrd.fields[1]; ixWIelValid += ImeIRMJobMJob::VecWIel::SHORT;};
	if (txtrd.fields.size() > 2) {Multi = (txtrd.fields[2] == "true"); ixWIelValid += ImeIRMJobMJob::VecWIel::MULTI;};
	if (txtrd.fields.size() > 3) {srefIxVConstract = txtrd.fields[3]; ixWIelValid += ImeIRMJobMJob::VecWIel::SREFIXVCONSTRACT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMJobMJob"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIRMJobMJob::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefSubRefWznmMJob", "sub", srefSubRefWznmMJob)) ixWIelValid += ImeIRMJobMJob::VecWIel::SREFSUBREFWZNMMJOB;
		if (extractStringUclc(docctx, basexpath, "Short", "sho", Short)) ixWIelValid += ImeIRMJobMJob::VecWIel::SHORT;
		if (extractBoolUclc(docctx, basexpath, "Multi", "mlt", Multi)) ixWIelValid += ImeIRMJobMJob::VecWIel::MULTI;
		if (extractStringUclc(docctx, basexpath, "srefIxVConstract", "csa", srefIxVConstract)) ixWIelValid += ImeIRMJobMJob::VecWIel::SREFIXVCONSTRACT;
	};
};

void IexWznmJtr::ImeitemIRMJobMJob::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefSubRefWznmMJob << "\t" << Short << "\t" << StrMod::boolToString(Multi) << "\t" << VecWznmVRMJobMJobConstract::getSref(ixVConstract) << endl;
};

void IexWznmJtr::ImeitemIRMJobMJob::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sub","sho","mlt","csa"};
	else tags = {"ImeitemIRMJobMJob","srefSubRefWznmMJob","Short","Multi","srefIxVConstract"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefSubRefWznmMJob);
		writeString(wr, tags[2], Short);
		writeBool(wr, tags[3], Multi);
		writeString(wr, tags[4], VecWznmVRMJobMJobConstract::getSref(ixVConstract));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIRMJobMJob::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIRMJobMJob::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefsubrefwznmmjob") ix |= SREFSUBREFWZNMMJOB;
		else if (ss[i] == "short") ix |= SHORT;
		else if (ss[i] == "multi") ix |= MULTI;
		else if (ss[i] == "srefixvconstract") ix |= SREFIXVCONSTRACT;
	};

	return(ix);
};

void IexWznmJtr::ImeIRMJobMJob::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVCONSTRACT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIRMJobMJob::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFSUBREFWZNMMJOB) ss.push_back("srefSubRefWznmMJob");
	if (ix & SHORT) ss.push_back("Short");
	if (ix & MULTI) ss.push_back("Multi");
	if (ix & SREFIXVCONSTRACT) ss.push_back("srefIxVConstract");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIRMJobMJob
 ******************************************************************************/

IexWznmJtr::ImeIRMJobMJob::ImeIRMJobMJob() {
};

IexWznmJtr::ImeIRMJobMJob::~ImeIRMJobMJob() {
	clear();
};

void IexWznmJtr::ImeIRMJobMJob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIRMJobMJob::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIRMJobMJob* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJtr::ImeitemIRMJobMJob();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMJobMJob"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMJobMJob"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMJOBMJOB) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMJobMJob"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMJobMJob"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIRMJobMJob::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIRMJobMJob* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMJobMJob");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMJobMJob", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMJobMJob";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIRMJobMJob();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIRMJobMJob::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMJobMJob." << StrMod::replaceChar(ImeIRMJobMJob::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMJobMJob.end" << endl;
	};
};

void IexWznmJtr::ImeIRMJobMJob::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMJobMJob");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIRMJobMOp
 ******************************************************************************/

IexWznmJtr::ImeitemIRMJobMOp::ImeitemIRMJobMOp(
			const string& srefRefWznmMOp
		) : WznmRMJobMOp() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMOp = srefRefWznmMOp;
};

IexWznmJtr::ImeitemIRMJobMOp::ImeitemIRMJobMOp(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMJobMOp()
		{
	WznmRMJobMOp* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmjobmop->loadRecByRef(ref, &rec)) {
		refWznmMJob = rec->refWznmMJob;
		refWznmMOp = rec->refWznmMOp;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIRMJobMOp::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMOp = txtrd.fields[0]; ixWIelValid += ImeIRMJobMOp::VecWIel::SREFREFWZNMMOP;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMJobMOp"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIRMJobMOp::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMOp", "opx", srefRefWznmMOp)) ixWIelValid += ImeIRMJobMOp::VecWIel::SREFREFWZNMMOP;
	};
};

void IexWznmJtr::ImeitemIRMJobMOp::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefRefWznmMOp << endl;
};

void IexWznmJtr::ImeitemIRMJobMOp::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","opx"};
	else tags = {"ImeitemIRMJobMOp","srefRefWznmMOp"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMOp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIRMJobMOp::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIRMJobMOp::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwznmmop") ix |= SREFREFWZNMMOP;
	};

	return(ix);
};

void IexWznmJtr::ImeIRMJobMOp::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMOP); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIRMJobMOp::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMOP) ss.push_back("srefRefWznmMOp");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIRMJobMOp
 ******************************************************************************/

IexWznmJtr::ImeIRMJobMOp::ImeIRMJobMOp() {
};

IexWznmJtr::ImeIRMJobMOp::~ImeIRMJobMOp() {
	clear();
};

void IexWznmJtr::ImeIRMJobMOp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIRMJobMOp::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIRMJobMOp* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJtr::ImeitemIRMJobMOp();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMJobMOp"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMJobMOp"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMJOBMOP) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMJobMOp"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMJobMOp"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIRMJobMOp::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIRMJobMOp* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMJobMOp");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMJobMOp", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMJobMOp";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIRMJobMOp();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIRMJobMOp::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMJobMOp." << StrMod::replaceChar(ImeIRMJobMOp::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMJobMOp.end" << endl;
	};
};

void IexWznmJtr::ImeIRMJobMOp::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMJobMOp");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIRMJobMOppack
 ******************************************************************************/

IexWznmJtr::ImeitemIRMJobMOppack::ImeitemIRMJobMOppack(
			const string& srefRefWznmMOppack
		) : WznmRMJobMOppack() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMOppack = srefRefWznmMOppack;
};

IexWznmJtr::ImeitemIRMJobMOppack::ImeitemIRMJobMOppack(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMJobMOppack()
		{
	WznmRMJobMOppack* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmjobmoppack->loadRecByRef(ref, &rec)) {
		refWznmMJob = rec->refWznmMJob;
		refWznmMOppack = rec->refWznmMOppack;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIRMJobMOppack::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMOppack = txtrd.fields[0]; ixWIelValid += ImeIRMJobMOppack::VecWIel::SREFREFWZNMMOPPACK;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMJobMOppack"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIRMJobMOppack::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMOppack", "opk", srefRefWznmMOppack)) ixWIelValid += ImeIRMJobMOppack::VecWIel::SREFREFWZNMMOPPACK;
	};
};

void IexWznmJtr::ImeitemIRMJobMOppack::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefRefWznmMOppack << endl;
};

void IexWznmJtr::ImeitemIRMJobMOppack::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","opk"};
	else tags = {"ImeitemIRMJobMOppack","srefRefWznmMOppack"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMOppack);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIRMJobMOppack::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIRMJobMOppack::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwznmmoppack") ix |= SREFREFWZNMMOPPACK;
	};

	return(ix);
};

void IexWznmJtr::ImeIRMJobMOppack::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMOPPACK); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIRMJobMOppack::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMOPPACK) ss.push_back("srefRefWznmMOppack");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIRMJobMOppack
 ******************************************************************************/

IexWznmJtr::ImeIRMJobMOppack::ImeIRMJobMOppack() {
};

IexWznmJtr::ImeIRMJobMOppack::~ImeIRMJobMOppack() {
	clear();
};

void IexWznmJtr::ImeIRMJobMOppack::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIRMJobMOppack::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIRMJobMOppack* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmJtr::ImeitemIRMJobMOppack();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMJobMOppack"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMJobMOppack"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMJOBMOPPACK) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMJobMOppack"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMJobMOppack"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIRMJobMOppack::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIRMJobMOppack* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMJobMOppack");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMJobMOppack", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMJobMOppack";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIRMJobMOppack();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIRMJobMOppack::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMJobMOppack." << StrMod::replaceChar(ImeIRMJobMOppack::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMJobMOppack.end" << endl;
	};
};

void IexWznmJtr::ImeIRMJobMOppack::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMJobMOppack");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmJtr::ImeitemIMJob
 ******************************************************************************/

IexWznmJtr::ImeitemIMJob::ImeitemIMJob(
			const string& sref
		) : WznmMJob() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
};

IexWznmJtr::ImeitemIMJob::ImeitemIMJob(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMJob()
		{
	WznmMJob* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmjob->loadRecByRef(ref, &rec)) {
		sref = rec->sref;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIMJob::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMJob::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMJOBCMD)) {
					imeiamjobcmd.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMJOBVAR)) {
					imeiamjobvar.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEICAMJOBVAR)) {
					imeicamjobvar.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMBLOCK1)) {
					imeimblock1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMMETHOD)) {
					imeimmethod.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMSENSITIVITY1)) {
					imeimsensitivity1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMSTAGE)) {
					imeimstage.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMVECTOR)) {
					imeimvector.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMJOBMJOB)) {
					imeirmjobmjob.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMJOBMOP)) {
					imeirmjobmop.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMJOBMOPPACK)) {
					imeirmjobmoppack.readTxt(txtrd);
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

void IexWznmJtr::ImeitemIMJob::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMJob::VecWIel::SREF;
		imeiamjobcmd.readXML(docctx, basexpath);
		imeiamjobvar.readXML(docctx, basexpath);
		imeicamjobvar.readXML(docctx, basexpath);
		imeimblock1.readXML(docctx, basexpath);
		imeimmethod.readXML(docctx, basexpath);
		imeimsensitivity1.readXML(docctx, basexpath);
		imeimstage.readXML(docctx, basexpath);
		imeimvector.readXML(docctx, basexpath);
		imeirmjobmjob.readXML(docctx, basexpath);
		imeirmjobmop.readXML(docctx, basexpath);
		imeirmjobmoppack.readXML(docctx, basexpath);
	};
};

void IexWznmJtr::ImeitemIMJob::writeTxt(
			fstream& outfile
		) {
	outfile << sref << endl;
	imeiamjobcmd.writeTxt(outfile);
	imeiamjobvar.writeTxt(outfile);
	imeicamjobvar.writeTxt(outfile);
	imeimblock1.writeTxt(outfile);
	imeimmethod.writeTxt(outfile);
	imeimsensitivity1.writeTxt(outfile);
	imeimstage.writeTxt(outfile);
	imeimvector.writeTxt(outfile);
	imeirmjobmjob.writeTxt(outfile);
	imeirmjobmop.writeTxt(outfile);
	imeirmjobmoppack.writeTxt(outfile);
};

void IexWznmJtr::ImeitemIMJob::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf"};
	else tags = {"ImeitemIMJob","sref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		imeiamjobcmd.writeXML(wr, shorttags);
		imeiamjobvar.writeXML(wr, shorttags);
		imeicamjobvar.writeXML(wr, shorttags);
		imeimblock1.writeXML(wr, shorttags);
		imeimmethod.writeXML(wr, shorttags);
		imeimsensitivity1.writeXML(wr, shorttags);
		imeimstage.writeXML(wr, shorttags);
		imeimvector.writeXML(wr, shorttags);
		imeirmjobmjob.writeXML(wr, shorttags);
		imeirmjobmop.writeXML(wr, shorttags);
		imeirmjobmoppack.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIMJob::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIMJob::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
	};

	return(ix);
};

void IexWznmJtr::ImeIMJob::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIMJob::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIMJob
 ******************************************************************************/

IexWznmJtr::ImeIMJob::ImeIMJob() {
};

IexWznmJtr::ImeIMJob::~ImeIMJob() {
	clear();
};

void IexWznmJtr::ImeIMJob::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIMJob::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIMJob* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmJtr::ImeitemIMJob();
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

void IexWznmJtr::ImeIMJob::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIMJob* ii = NULL;

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

			ii = new IexWznmJtr::ImeitemIMJob();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIMJob::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMJob." << StrMod::replaceChar(ImeIMJob::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMJob.end" << endl;
	};
};

void IexWznmJtr::ImeIMJob::writeXML(
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
 class IexWznmJtr::ImeitemIRMCallMStub
 ******************************************************************************/

IexWznmJtr::ImeitemIRMCallMStub::ImeitemIRMCallMStub(
			const string& srefRefWznmMCall
			, const string& srefRefWznmMStub
		) : WznmRMCallMStub() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMCall = srefRefWznmMCall;
	this->srefRefWznmMStub = srefRefWznmMStub;
};

IexWznmJtr::ImeitemIRMCallMStub::ImeitemIRMCallMStub(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMCallMStub()
		{
	WznmRMCallMStub* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmcallmstub->loadRecByRef(ref, &rec)) {
		refWznmMCall = rec->refWznmMCall;
		refWznmMStub = rec->refWznmMStub;

		delete rec;
	};
};

void IexWznmJtr::ImeitemIRMCallMStub::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMCall = txtrd.fields[0]; ixWIelValid += ImeIRMCallMStub::VecWIel::SREFREFWZNMMCALL;};
	if (txtrd.fields.size() > 1) {srefRefWznmMStub = txtrd.fields[1]; ixWIelValid += ImeIRMCallMStub::VecWIel::SREFREFWZNMMSTUB;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMCallMStub"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmJtr::ImeitemIRMCallMStub::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMCall", "cal", srefRefWznmMCall)) ixWIelValid += ImeIRMCallMStub::VecWIel::SREFREFWZNMMCALL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMStub", "stb", srefRefWznmMStub)) ixWIelValid += ImeIRMCallMStub::VecWIel::SREFREFWZNMMSTUB;
	};
};

void IexWznmJtr::ImeitemIRMCallMStub::writeTxt(
			fstream& outfile
		) {
	outfile << srefRefWznmMCall << "\t" << srefRefWznmMStub << endl;
};

void IexWznmJtr::ImeitemIRMCallMStub::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cal","stb"};
	else tags = {"ImeitemIRMCallMStub","srefRefWznmMCall","srefRefWznmMStub"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMCall);
		writeString(wr, tags[2], srefRefWznmMStub);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmJtr::ImeIRMCallMStub::VecWIel
 ******************************************************************************/

uint IexWznmJtr::ImeIRMCallMStub::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwznmmcall") ix |= SREFREFWZNMMCALL;
		else if (ss[i] == "srefrefwznmmstub") ix |= SREFREFWZNMMSTUB;
	};

	return(ix);
};

void IexWznmJtr::ImeIRMCallMStub::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMSTUB); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmJtr::ImeIRMCallMStub::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMCALL) ss.push_back("srefRefWznmMCall");
	if (ix & SREFREFWZNMMSTUB) ss.push_back("srefRefWznmMStub");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmJtr::ImeIRMCallMStub
 ******************************************************************************/

IexWznmJtr::ImeIRMCallMStub::ImeIRMCallMStub() {
};

IexWznmJtr::ImeIRMCallMStub::~ImeIRMCallMStub() {
	clear();
};

void IexWznmJtr::ImeIRMCallMStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmJtr::ImeIRMCallMStub::readTxt(
			Txtrd& txtrd
		) {
	IexWznmJtr::ImeitemIRMCallMStub* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmJtr::ImeitemIRMCallMStub();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMCallMStub"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMCALLMSTUB) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCallMStub"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCallMStub"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmJtr::ImeIRMCallMStub::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmJtr::ImeitemIRMCallMStub* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMCallMStub");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMCallMStub", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMCallMStub";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmJtr::ImeitemIRMCallMStub();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmJtr::ImeIRMCallMStub::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIRMCallMStub." << StrMod::replaceChar(ImeIRMCallMStub::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIRMCallMStub.end" << endl;
	};
};

void IexWznmJtr::ImeIRMCallMStub::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMCallMStub");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWznmJtr
 ******************************************************************************/

void IexWznmJtr::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, ImeIMBlock2& imeimblock2
			, ImeIMCall& imeimcall
			, ImeIMJob& imeimjob
			, ImeIRMCallMStub& imeirmcallmstub
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimblock2, imeimcall, imeimjob, imeirmcallmstub);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, "IexWznmJtr", Version("0.9.29"), VecVIme::getIx);
			readTxt(rd, imeimblock2, imeimcall, imeimjob, imeirmcallmstub);
	};
};

void IexWznmJtr::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMBlock2& imeimblock2
			, ImeIMCall& imeimcall
			, ImeIMJob& imeimjob
			, ImeIRMCallMStub& imeirmcallmstub
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimblock2, imeimcall, imeimjob, imeirmcallmstub);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimblock2, imeimcall, imeimjob, imeirmcallmstub);
		txtfile.close();
	};
};

void IexWznmJtr::readTxt(
			Txtrd& txtrd
			, ImeIMBlock2& imeimblock2
			, ImeIMCall& imeimcall
			, ImeIMJob& imeimjob
			, ImeIRMCallMStub& imeirmcallmstub
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMBLOCK2)) imeimblock2.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMCALL)) imeimcall.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMJOB)) imeimjob.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIRMCALLMSTUB)) imeirmcallmstub.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWznmJtr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMBlock2& imeimblock2
			, ImeIMCall& imeimcall
			, ImeIMJob& imeimjob
			, ImeIRMCallMStub& imeirmcallmstub
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmJtr")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("0.9.29")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","0.9.29"}});
		};

		// look for XML sub-blocks
		imeimblock2.readXML(docctx, basexpath);
		imeimcall.readXML(docctx, basexpath);
		imeimjob.readXML(docctx, basexpath);
		imeirmcallmstub.readXML(docctx, basexpath);

	} else {
		imeimblock2 = ImeIMBlock2();
		imeimcall = ImeIMCall();
		imeimjob = ImeIMJob();
		imeirmcallmstub = ImeIRMCallMStub();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmJtr"}});
	};
};

void IexWznmJtr::writeTxt(
			fstream& outfile
			, ImeIMBlock2& imeimblock2
			, ImeIMCall& imeimcall
			, ImeIMJob& imeimjob
			, ImeIRMCallMStub& imeirmcallmstub
		) {
	outfile << "IexWznmJtr v" WZNM_VERSION << endl;

	imeimblock2.writeTxt(outfile);
	imeimcall.writeTxt(outfile);
	imeimjob.writeTxt(outfile);
	imeirmcallmstub.writeTxt(outfile);
};

void IexWznmJtr::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMBlock2& imeimblock2
			, ImeIMCall& imeimcall
			, ImeIMJob& imeimjob
			, ImeIRMCallMStub& imeirmcallmstub
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmJtr");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeimblock2.writeXML(wr, shorttags);
		imeimcall.writeXML(wr, shorttags);
		imeimjob.writeXML(wr, shorttags);
		imeirmcallmstub.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmJtr::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMBLOCKITEM1,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMBLOCKITEM2,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMJOBCMD,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMJOBVAR,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMMETHODINVPAR,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMMETHODRETPAR,VecWznmVIop::INS},{(uint)VecVIme::IMEICAMBLOCKITEM1,VecWznmVIop::INS},{(uint)VecVIme::IMEICAMBLOCKITEM2,VecWznmVIop::INS},{(uint)VecVIme::IMEICAMJOBVAR,VecWznmVIop::INS},{(uint)VecVIme::IMEIJAMBLOCKITEM1,VecWznmVIop::INS},{(uint)VecVIme::IMEIJAMBLOCKITEM2,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMSQUAWKTITLE,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMVECTORITEM,VecWznmVIop::INS},{(uint)VecVIme::IMEIMBLOCK1,VecWznmVIop::INS},{(uint)VecVIme::IMEIMCALL,VecWznmVIop::INS},{(uint)VecVIme::IMEIMMETHOD,VecWznmVIop::INS},{(uint)VecVIme::IMEIMSENSITIVITY1,VecWznmVIop::INS},{(uint)VecVIme::IMEIMSENSITIVITY2,VecWznmVIop::INS},{(uint)VecVIme::IMEIMSQUAWK,VecWznmVIop::INS},{(uint)VecVIme::IMEIMSTAGE,VecWznmVIop::RETRUPDINS},{(uint)VecVIme::IMEIMVECTOR,VecWznmVIop::INS},{(uint)VecVIme::IMEIMVECTORITEM,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMCALLMSTUB,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMJOBMJOB,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMJOBMOP,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMJOBMOPPACK,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMSQUAWKMSTUB,VecWznmVIop::INS}};
};

uint IexWznmJtr::getIxWznmVIop(
			const map<uint,uint>& icsWznmVIop
			, const uint ixVIme
			, uint& ixWznmVIop
		) {
	ixWznmVIop = 0;

	auto it = icsWznmVIop.find(ixVIme);
	if (it != icsWznmVIop.end()) ixWznmVIop = it->second;

	return ixWznmVIop;
};

