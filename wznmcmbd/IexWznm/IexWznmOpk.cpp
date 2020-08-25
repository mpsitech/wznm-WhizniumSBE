/**
	* \file IexWznmOpk.cpp
	* data blocks and readers/writers for import/export complex IexWznmOpk (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "IexWznmOpk.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWznmOpk::VecVIme
 ******************************************************************************/

uint IexWznmOpk::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamblockitem1") return IMEIAMBLOCKITEM1;
	if (s == "imeiamblockitem2") return IMEIAMBLOCKITEM2;
	if (s == "imeiamopinvarg") return IMEIAMOPINVARG;
	if (s == "imeiamoppackinvarg") return IMEIAMOPPACKINVARG;
	if (s == "imeiamoppackretval") return IMEIAMOPPACKRETVAL;
	if (s == "imeiamopretval") return IMEIAMOPRETVAL;
	if (s == "imeicamblockitem1") return IMEICAMBLOCKITEM1;
	if (s == "imeicamblockitem2") return IMEICAMBLOCKITEM2;
	if (s == "imeicamopinvarg") return IMEICAMOPINVARG;
	if (s == "imeicamoppackinvarg") return IMEICAMOPPACKINVARG;
	if (s == "imeicamoppackretval") return IMEICAMOPPACKRETVAL;
	if (s == "imeicamopretval") return IMEICAMOPRETVAL;
	if (s == "imeijamblockitem1") return IMEIJAMBLOCKITEM1;
	if (s == "imeijamblockitem2") return IMEIJAMBLOCKITEM2;
	if (s == "imeijmsquawktitle1") return IMEIJMSQUAWKTITLE1;
	if (s == "imeijmsquawktitle2") return IMEIJMSQUAWKTITLE2;
	if (s == "imeimblock1") return IMEIMBLOCK1;
	if (s == "imeimblock2") return IMEIMBLOCK2;
	if (s == "imeimop") return IMEIMOP;
	if (s == "imeimoppack") return IMEIMOPPACK;
	if (s == "imeimsquawk1") return IMEIMSQUAWK1;
	if (s == "imeimsquawk2") return IMEIMSQUAWK2;
	if (s == "imeirmcomponentmoppack") return IMEIRMCOMPONENTMOPPACK;
	if (s == "imeirmlibrarymoppack") return IMEIRMLIBRARYMOPPACK;
	if (s == "imeirmsquawkmstub1") return IMEIRMSQUAWKMSTUB1;
	if (s == "imeirmsquawkmstub2") return IMEIRMSQUAWKMSTUB2;

	return(0);
};

string IexWznmOpk::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMBLOCKITEM1) return("ImeIAMBlockItem1");
	if (ix == IMEIAMBLOCKITEM2) return("ImeIAMBlockItem2");
	if (ix == IMEIAMOPINVARG) return("ImeIAMOpInvarg");
	if (ix == IMEIAMOPPACKINVARG) return("ImeIAMOppackInvarg");
	if (ix == IMEIAMOPPACKRETVAL) return("ImeIAMOppackRetval");
	if (ix == IMEIAMOPRETVAL) return("ImeIAMOpRetval");
	if (ix == IMEICAMBLOCKITEM1) return("ImeICAMBlockItem1");
	if (ix == IMEICAMBLOCKITEM2) return("ImeICAMBlockItem2");
	if (ix == IMEICAMOPINVARG) return("ImeICAMOpInvarg");
	if (ix == IMEICAMOPPACKINVARG) return("ImeICAMOppackInvarg");
	if (ix == IMEICAMOPPACKRETVAL) return("ImeICAMOppackRetval");
	if (ix == IMEICAMOPRETVAL) return("ImeICAMOpRetval");
	if (ix == IMEIJAMBLOCKITEM1) return("ImeIJAMBlockItem1");
	if (ix == IMEIJAMBLOCKITEM2) return("ImeIJAMBlockItem2");
	if (ix == IMEIJMSQUAWKTITLE1) return("ImeIJMSquawkTitle1");
	if (ix == IMEIJMSQUAWKTITLE2) return("ImeIJMSquawkTitle2");
	if (ix == IMEIMBLOCK1) return("ImeIMBlock1");
	if (ix == IMEIMBLOCK2) return("ImeIMBlock2");
	if (ix == IMEIMOP) return("ImeIMOp");
	if (ix == IMEIMOPPACK) return("ImeIMOppack");
	if (ix == IMEIMSQUAWK1) return("ImeIMSquawk1");
	if (ix == IMEIMSQUAWK2) return("ImeIMSquawk2");
	if (ix == IMEIRMCOMPONENTMOPPACK) return("ImeIRMComponentMOppack");
	if (ix == IMEIRMLIBRARYMOPPACK) return("ImeIRMLibraryMOppack");
	if (ix == IMEIRMSQUAWKMSTUB1) return("ImeIRMSquawkMStub1");
	if (ix == IMEIRMSQUAWKMSTUB2) return("ImeIRMSquawkMStub2");

	return("");
};

/******************************************************************************
 class IexWznmOpk::ImeitemIAMOppackInvarg
 ******************************************************************************/

IexWznmOpk::ImeitemIAMOppackInvarg::ImeitemIAMOppackInvarg(
			const ubigint irefRefWznmCAMOppackInvarg
			, const string& sref
			, const uint ixWznmVVartype
			, const string& srefRefWznmMVector
			, const string& Defval
			, const string& srefRefWznmMVectoritem
			, const string& Comment
		) : WznmAMOppackInvarg() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWznmCAMOppackInvarg = irefRefWznmCAMOppackInvarg;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->Defval = Defval;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
	this->Comment = Comment;
};

IexWznmOpk::ImeitemIAMOppackInvarg::ImeitemIAMOppackInvarg(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMOppackInvarg()
		{
	WznmAMOppackInvarg* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamoppackinvarg->loadRecByRef(ref, &rec)) {
		refWznmCAMOppackInvarg = rec->refWznmCAMOppackInvarg;
		opkRefWznmMOppack = rec->opkRefWznmMOppack;
		opkNum = rec->opkNum;
		sref = rec->sref;
		ixWznmVVartype = rec->ixWznmVVartype;
		refWznmMVector = rec->refWznmMVector;
		Defval = rec->Defval;
		refWznmMVectoritem = rec->refWznmMVectoritem;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmOpk::ImeitemIAMOppackInvarg::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWznmCAMOppackInvarg = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIAMOppackInvarg::VecWIel::IREFREFWZNMCAMOPPACKINVARG;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAMOppackInvarg::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefIxWznmVVartype = txtrd.fields[2]; ixWIelValid += ImeIAMOppackInvarg::VecWIel::SREFIXWZNMVVARTYPE;};
	if (txtrd.fields.size() > 3) {srefRefWznmMVector = txtrd.fields[3]; ixWIelValid += ImeIAMOppackInvarg::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 4) {Defval = txtrd.fields[4]; ixWIelValid += ImeIAMOppackInvarg::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 5) {srefRefWznmMVectoritem = txtrd.fields[5]; ixWIelValid += ImeIAMOppackInvarg::VecWIel::SREFREFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIAMOppackInvarg::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMOppackInvarg"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIAMOppackInvarg::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCAMOppackInvarg", "clu", irefRefWznmCAMOppackInvarg)) ixWIelValid += ImeIAMOppackInvarg::VecWIel::IREFREFWZNMCAMOPPACKINVARG;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMOppackInvarg::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype)) ixWIelValid += ImeIAMOppackInvarg::VecWIel::SREFIXWZNMVVARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMOppackInvarg::VecWIel::SREFREFWZNMMVECTOR;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIAMOppackInvarg::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIAMOppackInvarg::VecWIel::SREFREFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMOppackInvarg::VecWIel::COMMENT;
	};
};

void IexWznmOpk::ImeitemIAMOppackInvarg::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << irefRefWznmCAMOppackInvarg << "\t" << sref << "\t" << VecWznmVVartype::getSref(ixWznmVVartype) << "\t" << srefRefWznmMVector << "\t" << Defval << "\t" << srefRefWznmMVectoritem << "\t" << Comment << endl;
};

void IexWznmOpk::ImeitemIAMOppackInvarg::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","srf","vty","vec","dfv","vit","cmt"};
	else tags = {"ImeitemIAMOppackInvarg","irefRefWznmCAMOppackInvarg","sref","srefIxWznmVVartype","srefRefWznmMVector","Defval","srefRefWznmMVectoritem","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWznmCAMOppackInvarg);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], VecWznmVVartype::getSref(ixWznmVVartype));
		writeString(wr, tags[4], srefRefWznmMVector);
		writeString(wr, tags[5], Defval);
		writeString(wr, tags[6], srefRefWznmMVectoritem);
		writeString(wr, tags[7], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIAMOppackInvarg::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIAMOppackInvarg::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwznmcamoppackinvarg") ix |= IREFREFWZNMCAMOPPACKINVARG;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmvvartype") ix |= SREFIXWZNMVVARTYPE;
		else if (ss[i] == "srefrefwznmmvector") ix |= SREFREFWZNMMVECTOR;
		else if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmOpk::ImeIAMOppackInvarg::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIAMOppackInvarg::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWZNMCAMOPPACKINVARG) ss.push_back("irefRefWznmCAMOppackInvarg");
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
 class IexWznmOpk::ImeIAMOppackInvarg
 ******************************************************************************/

IexWznmOpk::ImeIAMOppackInvarg::ImeIAMOppackInvarg() {
};

IexWznmOpk::ImeIAMOppackInvarg::~ImeIAMOppackInvarg() {
	clear();
};

void IexWznmOpk::ImeIAMOppackInvarg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIAMOppackInvarg::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIAMOppackInvarg* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmOpk::ImeitemIAMOppackInvarg();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMOppackInvarg"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMOppackInvarg"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMOPPACKINVARG) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMOppackInvarg"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMOppackInvarg"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIAMOppackInvarg::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIAMOppackInvarg* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMOppackInvarg");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMOppackInvarg", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMOppackInvarg";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIAMOppackInvarg();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIAMOppackInvarg::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMOppackInvarg." << StrMod::replaceChar(ImeIAMOppackInvarg::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMOppackInvarg.end" << endl;
	};
};

void IexWznmOpk::ImeIAMOppackInvarg::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMOppackInvarg");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemIAMOppackRetval
 ******************************************************************************/

IexWznmOpk::ImeitemIAMOppackRetval::ImeitemIAMOppackRetval(
			const ubigint irefRefWznmCAMOppackRetval
			, const string& sref
			, const uint ixWznmVVartype
			, const string& srefRefWznmMVector
			, const string& Comment
		) : WznmAMOppackRetval() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWznmCAMOppackRetval = irefRefWznmCAMOppackRetval;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->Comment = Comment;
};

IexWznmOpk::ImeitemIAMOppackRetval::ImeitemIAMOppackRetval(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMOppackRetval()
		{
	WznmAMOppackRetval* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamoppackretval->loadRecByRef(ref, &rec)) {
		refWznmCAMOppackRetval = rec->refWznmCAMOppackRetval;
		opkRefWznmMOppack = rec->opkRefWznmMOppack;
		opkNum = rec->opkNum;
		sref = rec->sref;
		ixWznmVVartype = rec->ixWznmVVartype;
		refWznmMVector = rec->refWznmMVector;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmOpk::ImeitemIAMOppackRetval::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWznmCAMOppackRetval = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIAMOppackRetval::VecWIel::IREFREFWZNMCAMOPPACKRETVAL;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAMOppackRetval::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefIxWznmVVartype = txtrd.fields[2]; ixWIelValid += ImeIAMOppackRetval::VecWIel::SREFIXWZNMVVARTYPE;};
	if (txtrd.fields.size() > 3) {srefRefWznmMVector = txtrd.fields[3]; ixWIelValid += ImeIAMOppackRetval::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIAMOppackRetval::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMOppackRetval"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIAMOppackRetval::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCAMOppackRetval", "clu", irefRefWznmCAMOppackRetval)) ixWIelValid += ImeIAMOppackRetval::VecWIel::IREFREFWZNMCAMOPPACKRETVAL;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMOppackRetval::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype)) ixWIelValid += ImeIAMOppackRetval::VecWIel::SREFIXWZNMVVARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMOppackRetval::VecWIel::SREFREFWZNMMVECTOR;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMOppackRetval::VecWIel::COMMENT;
	};
};

void IexWznmOpk::ImeitemIAMOppackRetval::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << irefRefWznmCAMOppackRetval << "\t" << sref << "\t" << VecWznmVVartype::getSref(ixWznmVVartype) << "\t" << srefRefWznmMVector << "\t" << Comment << endl;
};

void IexWznmOpk::ImeitemIAMOppackRetval::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","srf","vty","vec","cmt"};
	else tags = {"ImeitemIAMOppackRetval","irefRefWznmCAMOppackRetval","sref","srefIxWznmVVartype","srefRefWznmMVector","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWznmCAMOppackRetval);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], VecWznmVVartype::getSref(ixWznmVVartype));
		writeString(wr, tags[4], srefRefWznmMVector);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIAMOppackRetval::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIAMOppackRetval::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwznmcamoppackretval") ix |= IREFREFWZNMCAMOPPACKRETVAL;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmvvartype") ix |= SREFIXWZNMVVARTYPE;
		else if (ss[i] == "srefrefwznmmvector") ix |= SREFREFWZNMMVECTOR;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmOpk::ImeIAMOppackRetval::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIAMOppackRetval::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWZNMCAMOPPACKRETVAL) ss.push_back("irefRefWznmCAMOppackRetval");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXWZNMVVARTYPE) ss.push_back("srefIxWznmVVartype");
	if (ix & SREFREFWZNMMVECTOR) ss.push_back("srefRefWznmMVector");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeIAMOppackRetval
 ******************************************************************************/

IexWznmOpk::ImeIAMOppackRetval::ImeIAMOppackRetval() {
};

IexWznmOpk::ImeIAMOppackRetval::~ImeIAMOppackRetval() {
	clear();
};

void IexWznmOpk::ImeIAMOppackRetval::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIAMOppackRetval::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIAMOppackRetval* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmOpk::ImeitemIAMOppackRetval();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMOppackRetval"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMOppackRetval"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMOPPACKRETVAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMOppackRetval"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMOppackRetval"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIAMOppackRetval::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIAMOppackRetval* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMOppackRetval");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMOppackRetval", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMOppackRetval";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIAMOppackRetval();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIAMOppackRetval::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMOppackRetval." << StrMod::replaceChar(ImeIAMOppackRetval::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMOppackRetval.end" << endl;
	};
};

void IexWznmOpk::ImeIAMOppackRetval::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMOppackRetval");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemICAMOppackInvarg
 ******************************************************************************/

IexWznmOpk::ImeitemICAMOppackInvarg::ImeitemICAMOppackInvarg(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmOpk::ImeitemICAMOppackInvarg::ImeitemICAMOppackInvarg(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICAMOppackInvarg()
		{
};

void IexWznmOpk::ImeitemICAMOppackInvarg::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICAMOppackInvarg::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMOppackInvarg"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemICAMOppackInvarg::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICAMOppackInvarg::VecWIel::IREF;
	};
};

void IexWznmOpk::ImeitemICAMOppackInvarg::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << iref << endl;
};

void IexWznmOpk::ImeitemICAMOppackInvarg::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICAMOppackInvarg","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeICAMOppackInvarg::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeICAMOppackInvarg::VecWIel::getIx(
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

void IexWznmOpk::ImeICAMOppackInvarg::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeICAMOppackInvarg::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeICAMOppackInvarg
 ******************************************************************************/

IexWznmOpk::ImeICAMOppackInvarg::ImeICAMOppackInvarg() {
};

IexWznmOpk::ImeICAMOppackInvarg::~ImeICAMOppackInvarg() {
	clear();
};

void IexWznmOpk::ImeICAMOppackInvarg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeICAMOppackInvarg::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemICAMOppackInvarg* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmOpk::ImeitemICAMOppackInvarg();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMOppackInvarg"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMOppackInvarg"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICAMOPPACKINVARG) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMOppackInvarg"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMOppackInvarg"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeICAMOppackInvarg::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemICAMOppackInvarg* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICAMOppackInvarg");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICAMOppackInvarg", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICAMOppackInvarg";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemICAMOppackInvarg();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeICAMOppackInvarg::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeICAMOppackInvarg." << StrMod::replaceChar(ImeICAMOppackInvarg::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeICAMOppackInvarg.end" << endl;
	};
};

void IexWznmOpk::ImeICAMOppackInvarg::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICAMOppackInvarg");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemICAMOppackRetval
 ******************************************************************************/

IexWznmOpk::ImeitemICAMOppackRetval::ImeitemICAMOppackRetval(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmOpk::ImeitemICAMOppackRetval::ImeitemICAMOppackRetval(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICAMOppackRetval()
		{
};

void IexWznmOpk::ImeitemICAMOppackRetval::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICAMOppackRetval::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMOppackRetval"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemICAMOppackRetval::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICAMOppackRetval::VecWIel::IREF;
	};
};

void IexWznmOpk::ImeitemICAMOppackRetval::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << iref << endl;
};

void IexWznmOpk::ImeitemICAMOppackRetval::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICAMOppackRetval","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeICAMOppackRetval::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeICAMOppackRetval::VecWIel::getIx(
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

void IexWznmOpk::ImeICAMOppackRetval::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeICAMOppackRetval::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeICAMOppackRetval
 ******************************************************************************/

IexWznmOpk::ImeICAMOppackRetval::ImeICAMOppackRetval() {
};

IexWznmOpk::ImeICAMOppackRetval::~ImeICAMOppackRetval() {
	clear();
};

void IexWznmOpk::ImeICAMOppackRetval::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeICAMOppackRetval::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemICAMOppackRetval* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmOpk::ImeitemICAMOppackRetval();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMOppackRetval"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMOppackRetval"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICAMOPPACKRETVAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMOppackRetval"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMOppackRetval"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeICAMOppackRetval::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemICAMOppackRetval* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICAMOppackRetval");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICAMOppackRetval", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICAMOppackRetval";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemICAMOppackRetval();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeICAMOppackRetval::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeICAMOppackRetval." << StrMod::replaceChar(ImeICAMOppackRetval::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeICAMOppackRetval.end" << endl;
	};
};

void IexWznmOpk::ImeICAMOppackRetval::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICAMOppackRetval");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemIJAMBlockItem1
 ******************************************************************************/

IexWznmOpk::ImeitemIJAMBlockItem1::ImeitemIJAMBlockItem1(
			const string& Defval
			, const string& srefRefWznmMVectoritem
		) : WznmJAMBlockItem() {
	lineno = 0;
	ixWIelValid = 0;

	this->Defval = Defval;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
};

IexWznmOpk::ImeitemIJAMBlockItem1::ImeitemIJAMBlockItem1(
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

void IexWznmOpk::ImeitemIJAMBlockItem1::readTxt(
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

void IexWznmOpk::ImeitemIJAMBlockItem1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIJAMBlockItem1::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIJAMBlockItem1::VecWIel::SREFREFWZNMMVECTORITEM;
	};
};

void IexWznmOpk::ImeitemIJAMBlockItem1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << Defval << "\t" << srefRefWznmMVectoritem << endl;
};

void IexWznmOpk::ImeitemIJAMBlockItem1::writeXML(
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
 class IexWznmOpk::ImeIJAMBlockItem1::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIJAMBlockItem1::VecWIel::getIx(
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

void IexWznmOpk::ImeIJAMBlockItem1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMVECTORITEM); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIJAMBlockItem1::VecWIel::getSrefs(
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
 class IexWznmOpk::ImeIJAMBlockItem1
 ******************************************************************************/

IexWznmOpk::ImeIJAMBlockItem1::ImeIJAMBlockItem1() {
};

IexWznmOpk::ImeIJAMBlockItem1::~ImeIJAMBlockItem1() {
	clear();
};

void IexWznmOpk::ImeIJAMBlockItem1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIJAMBlockItem1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIJAMBlockItem1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmOpk::ImeitemIJAMBlockItem1();
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

void IexWznmOpk::ImeIJAMBlockItem1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIJAMBlockItem1* ii = NULL;

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

			ii = new IexWznmOpk::ImeitemIJAMBlockItem1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIJAMBlockItem1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJAMBlockItem1." << StrMod::replaceChar(ImeIJAMBlockItem1::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJAMBlockItem1.end" << endl;
	};
};

void IexWznmOpk::ImeIJAMBlockItem1::writeXML(
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
 class IexWznmOpk::ImeitemIAMBlockItem1
 ******************************************************************************/

IexWznmOpk::ImeitemIAMBlockItem1::ImeitemIAMBlockItem1(
			const ubigint irefRefWznmCAMBlockItem
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
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->Defval = Defval;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
	this->Comment = Comment;
};

IexWznmOpk::ImeitemIAMBlockItem1::ImeitemIAMBlockItem1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMBlockItem1()
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

void IexWznmOpk::ImeitemIAMBlockItem1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWznmCAMBlockItem = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIAMBlockItem1::VecWIel::IREFREFWZNMCAMBLOCKITEM;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefIxWznmVVartype = txtrd.fields[2]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFIXWZNMVVARTYPE;};
	if (txtrd.fields.size() > 3) {srefRefWznmMVector = txtrd.fields[3]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 4) {Defval = txtrd.fields[4]; ixWIelValid += ImeIAMBlockItem1::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 5) {srefRefWznmMVectoritem = txtrd.fields[5]; ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIAMBlockItem1::VecWIel::COMMENT;};

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

void IexWznmOpk::ImeitemIAMBlockItem1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCAMBlockItem", "clu", irefRefWznmCAMBlockItem)) ixWIelValid += ImeIAMBlockItem1::VecWIel::IREFREFWZNMCAMBLOCKITEM;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFIXWZNMVVARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMVECTOR;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIAMBlockItem1::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIAMBlockItem1::VecWIel::SREFREFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMBlockItem1::VecWIel::COMMENT;
		imeijamblockitem1.readXML(docctx, basexpath);
	};
};

void IexWznmOpk::ImeitemIAMBlockItem1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << irefRefWznmCAMBlockItem << "\t" << sref << "\t" << VecWznmVVartype::getSref(ixWznmVVartype) << "\t" << srefRefWznmMVector << "\t" << Defval << "\t" << srefRefWznmMVectoritem << "\t" << Comment << endl;
	imeijamblockitem1.writeTxt(outfile);
};

void IexWznmOpk::ImeitemIAMBlockItem1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","srf","vty","vec","dfv","vit","cmt"};
	else tags = {"ImeitemIAMBlockItem1","irefRefWznmCAMBlockItem","sref","srefIxWznmVVartype","srefRefWznmMVector","Defval","srefRefWznmMVectoritem","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWznmCAMBlockItem);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], VecWznmVVartype::getSref(ixWznmVVartype));
		writeString(wr, tags[4], srefRefWznmMVector);
		writeString(wr, tags[5], Defval);
		writeString(wr, tags[6], srefRefWznmMVectoritem);
		writeString(wr, tags[7], Comment);
		imeijamblockitem1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIAMBlockItem1::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIAMBlockItem1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwznmcamblockitem") ix |= IREFREFWZNMCAMBLOCKITEM;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmvvartype") ix |= SREFIXWZNMVVARTYPE;
		else if (ss[i] == "srefrefwznmmvector") ix |= SREFREFWZNMMVECTOR;
		else if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmOpk::ImeIAMBlockItem1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIAMBlockItem1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWZNMCAMBLOCKITEM) ss.push_back("irefRefWznmCAMBlockItem");
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
 class IexWznmOpk::ImeIAMBlockItem1
 ******************************************************************************/

IexWznmOpk::ImeIAMBlockItem1::ImeIAMBlockItem1() {
};

IexWznmOpk::ImeIAMBlockItem1::~ImeIAMBlockItem1() {
	clear();
};

void IexWznmOpk::ImeIAMBlockItem1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIAMBlockItem1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIAMBlockItem1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmOpk::ImeitemIAMBlockItem1();
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

void IexWznmOpk::ImeIAMBlockItem1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIAMBlockItem1* ii = NULL;

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

			ii = new IexWznmOpk::ImeitemIAMBlockItem1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIAMBlockItem1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMBlockItem1." << StrMod::replaceChar(ImeIAMBlockItem1::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMBlockItem1.end" << endl;
	};
};

void IexWznmOpk::ImeIAMBlockItem1::writeXML(
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
 class IexWznmOpk::ImeitemICAMBlockItem1
 ******************************************************************************/

IexWznmOpk::ImeitemICAMBlockItem1::ImeitemICAMBlockItem1(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmOpk::ImeitemICAMBlockItem1::ImeitemICAMBlockItem1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICAMBlockItem1()
		{
};

void IexWznmOpk::ImeitemICAMBlockItem1::readTxt(
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

void IexWznmOpk::ImeitemICAMBlockItem1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICAMBlockItem1::VecWIel::IREF;
	};
};

void IexWznmOpk::ImeitemICAMBlockItem1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWznmOpk::ImeitemICAMBlockItem1::writeXML(
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
 class IexWznmOpk::ImeICAMBlockItem1::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeICAMBlockItem1::VecWIel::getIx(
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

void IexWznmOpk::ImeICAMBlockItem1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeICAMBlockItem1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeICAMBlockItem1
 ******************************************************************************/

IexWznmOpk::ImeICAMBlockItem1::ImeICAMBlockItem1() {
};

IexWznmOpk::ImeICAMBlockItem1::~ImeICAMBlockItem1() {
	clear();
};

void IexWznmOpk::ImeICAMBlockItem1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeICAMBlockItem1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemICAMBlockItem1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmOpk::ImeitemICAMBlockItem1();
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

void IexWznmOpk::ImeICAMBlockItem1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemICAMBlockItem1* ii = NULL;

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

			ii = new IexWznmOpk::ImeitemICAMBlockItem1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeICAMBlockItem1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICAMBlockItem1." << StrMod::replaceChar(ImeICAMBlockItem1::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICAMBlockItem1.end" << endl;
	};
};

void IexWznmOpk::ImeICAMBlockItem1::writeXML(
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
 class IexWznmOpk::ImeitemIMBlock1
 ******************************************************************************/

IexWznmOpk::ImeitemIMBlock1::ImeitemIMBlock1(
			const string& sref
			, const string& Comment
		) : WznmMBlock() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexWznmOpk::ImeitemIMBlock1::ImeitemIMBlock1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMBlock1()
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

void IexWznmOpk::ImeitemIMBlock1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMBlock1::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIMBlock1::VecWIel::COMMENT;};

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

void IexWznmOpk::ImeitemIMBlock1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMBlock1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMBlock1::VecWIel::COMMENT;
		imeiamblockitem1.readXML(docctx, basexpath);
		imeicamblockitem1.readXML(docctx, basexpath);
	};
};

void IexWznmOpk::ImeitemIMBlock1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << Comment << endl;
	imeiamblockitem1.writeTxt(outfile);
	imeicamblockitem1.writeTxt(outfile);
};

void IexWznmOpk::ImeitemIMBlock1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMBlock1","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
		imeiamblockitem1.writeXML(wr, shorttags);
		imeicamblockitem1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIMBlock1::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIMBlock1::VecWIel::getIx(
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

void IexWznmOpk::ImeIMBlock1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIMBlock1::VecWIel::getSrefs(
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
 class IexWznmOpk::ImeIMBlock1
 ******************************************************************************/

IexWznmOpk::ImeIMBlock1::ImeIMBlock1() {
};

IexWznmOpk::ImeIMBlock1::~ImeIMBlock1() {
	clear();
};

void IexWznmOpk::ImeIMBlock1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIMBlock1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIMBlock1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmOpk::ImeitemIMBlock1();
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

void IexWznmOpk::ImeIMBlock1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIMBlock1* ii = NULL;

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

			ii = new IexWznmOpk::ImeitemIMBlock1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIMBlock1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMBlock1." << StrMod::replaceChar(ImeIMBlock1::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMBlock1.end" << endl;
	};
};

void IexWznmOpk::ImeIMBlock1::writeXML(
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
 class IexWznmOpk::ImeitemIAMOpInvarg
 ******************************************************************************/

IexWznmOpk::ImeitemIAMOpInvarg::ImeitemIAMOpInvarg(
			const ubigint irefRefWznmCAMOpInvarg
			, const string& sref
			, const uint ixWznmVVartype
			, const string& srefRefWznmMVector
			, const string& Defval
			, const string& srefRefWznmMVectoritem
			, const string& Comment
		) : WznmAMOpInvarg() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWznmCAMOpInvarg = irefRefWznmCAMOpInvarg;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->Defval = Defval;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
	this->Comment = Comment;
};

IexWznmOpk::ImeitemIAMOpInvarg::ImeitemIAMOpInvarg(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMOpInvarg()
		{
	WznmAMOpInvarg* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamopinvarg->loadRecByRef(ref, &rec)) {
		refWznmCAMOpInvarg = rec->refWznmCAMOpInvarg;
		opxRefWznmMOp = rec->opxRefWznmMOp;
		opxNum = rec->opxNum;
		sref = rec->sref;
		ixWznmVVartype = rec->ixWznmVVartype;
		refWznmMVector = rec->refWznmMVector;
		Defval = rec->Defval;
		refWznmMVectoritem = rec->refWznmMVectoritem;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmOpk::ImeitemIAMOpInvarg::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWznmCAMOpInvarg = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIAMOpInvarg::VecWIel::IREFREFWZNMCAMOPINVARG;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAMOpInvarg::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefIxWznmVVartype = txtrd.fields[2]; ixWIelValid += ImeIAMOpInvarg::VecWIel::SREFIXWZNMVVARTYPE;};
	if (txtrd.fields.size() > 3) {srefRefWznmMVector = txtrd.fields[3]; ixWIelValid += ImeIAMOpInvarg::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 4) {Defval = txtrd.fields[4]; ixWIelValid += ImeIAMOpInvarg::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 5) {srefRefWznmMVectoritem = txtrd.fields[5]; ixWIelValid += ImeIAMOpInvarg::VecWIel::SREFREFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIAMOpInvarg::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMOpInvarg"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIAMOpInvarg::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCAMOpInvarg", "clu", irefRefWznmCAMOpInvarg)) ixWIelValid += ImeIAMOpInvarg::VecWIel::IREFREFWZNMCAMOPINVARG;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMOpInvarg::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype)) ixWIelValid += ImeIAMOpInvarg::VecWIel::SREFIXWZNMVVARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMOpInvarg::VecWIel::SREFREFWZNMMVECTOR;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIAMOpInvarg::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIAMOpInvarg::VecWIel::SREFREFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMOpInvarg::VecWIel::COMMENT;
	};
};

void IexWznmOpk::ImeitemIAMOpInvarg::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << irefRefWznmCAMOpInvarg << "\t" << sref << "\t" << VecWznmVVartype::getSref(ixWznmVVartype) << "\t" << srefRefWznmMVector << "\t" << Defval << "\t" << srefRefWznmMVectoritem << "\t" << Comment << endl;
};

void IexWznmOpk::ImeitemIAMOpInvarg::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","srf","vty","vec","dfv","vit","cmt"};
	else tags = {"ImeitemIAMOpInvarg","irefRefWznmCAMOpInvarg","sref","srefIxWznmVVartype","srefRefWznmMVector","Defval","srefRefWznmMVectoritem","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWznmCAMOpInvarg);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], VecWznmVVartype::getSref(ixWznmVVartype));
		writeString(wr, tags[4], srefRefWznmMVector);
		writeString(wr, tags[5], Defval);
		writeString(wr, tags[6], srefRefWznmMVectoritem);
		writeString(wr, tags[7], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIAMOpInvarg::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIAMOpInvarg::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwznmcamopinvarg") ix |= IREFREFWZNMCAMOPINVARG;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmvvartype") ix |= SREFIXWZNMVVARTYPE;
		else if (ss[i] == "srefrefwznmmvector") ix |= SREFREFWZNMMVECTOR;
		else if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmOpk::ImeIAMOpInvarg::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIAMOpInvarg::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWZNMCAMOPINVARG) ss.push_back("irefRefWznmCAMOpInvarg");
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
 class IexWznmOpk::ImeIAMOpInvarg
 ******************************************************************************/

IexWznmOpk::ImeIAMOpInvarg::ImeIAMOpInvarg() {
};

IexWznmOpk::ImeIAMOpInvarg::~ImeIAMOpInvarg() {
	clear();
};

void IexWznmOpk::ImeIAMOpInvarg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIAMOpInvarg::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIAMOpInvarg* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmOpk::ImeitemIAMOpInvarg();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMOpInvarg"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMOpInvarg"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMOPINVARG) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMOpInvarg"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMOpInvarg"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIAMOpInvarg::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIAMOpInvarg* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMOpInvarg");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMOpInvarg", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMOpInvarg";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIAMOpInvarg();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIAMOpInvarg::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMOpInvarg." << StrMod::replaceChar(ImeIAMOpInvarg::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMOpInvarg.end" << endl;
	};
};

void IexWznmOpk::ImeIAMOpInvarg::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMOpInvarg");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemIAMOpRetval
 ******************************************************************************/

IexWznmOpk::ImeitemIAMOpRetval::ImeitemIAMOpRetval(
			const ubigint irefRefWznmCAMOpRetval
			, const string& sref
			, const uint ixWznmVVartype
			, const string& srefRefWznmMVector
			, const string& Comment
		) : WznmAMOpRetval() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWznmCAMOpRetval = irefRefWznmCAMOpRetval;
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->Comment = Comment;
};

IexWznmOpk::ImeitemIAMOpRetval::ImeitemIAMOpRetval(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMOpRetval()
		{
	WznmAMOpRetval* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamopretval->loadRecByRef(ref, &rec)) {
		refWznmCAMOpRetval = rec->refWznmCAMOpRetval;
		opxRefWznmMOp = rec->opxRefWznmMOp;
		opxNum = rec->opxNum;
		sref = rec->sref;
		ixWznmVVartype = rec->ixWznmVVartype;
		refWznmMVector = rec->refWznmMVector;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmOpk::ImeitemIAMOpRetval::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWznmCAMOpRetval = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIAMOpRetval::VecWIel::IREFREFWZNMCAMOPRETVAL;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAMOpRetval::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefIxWznmVVartype = txtrd.fields[2]; ixWIelValid += ImeIAMOpRetval::VecWIel::SREFIXWZNMVVARTYPE;};
	if (txtrd.fields.size() > 3) {srefRefWznmMVector = txtrd.fields[3]; ixWIelValid += ImeIAMOpRetval::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIAMOpRetval::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMOpRetval"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIAMOpRetval::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCAMOpRetval", "clu", irefRefWznmCAMOpRetval)) ixWIelValid += ImeIAMOpRetval::VecWIel::IREFREFWZNMCAMOPRETVAL;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMOpRetval::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype)) ixWIelValid += ImeIAMOpRetval::VecWIel::SREFIXWZNMVVARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMOpRetval::VecWIel::SREFREFWZNMMVECTOR;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMOpRetval::VecWIel::COMMENT;
	};
};

void IexWznmOpk::ImeitemIAMOpRetval::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << irefRefWznmCAMOpRetval << "\t" << sref << "\t" << VecWznmVVartype::getSref(ixWznmVVartype) << "\t" << srefRefWznmMVector << "\t" << Comment << endl;
};

void IexWznmOpk::ImeitemIAMOpRetval::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","srf","vty","vec","cmt"};
	else tags = {"ImeitemIAMOpRetval","irefRefWznmCAMOpRetval","sref","srefIxWznmVVartype","srefRefWznmMVector","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWznmCAMOpRetval);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], VecWznmVVartype::getSref(ixWznmVVartype));
		writeString(wr, tags[4], srefRefWznmMVector);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIAMOpRetval::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIAMOpRetval::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwznmcamopretval") ix |= IREFREFWZNMCAMOPRETVAL;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmvvartype") ix |= SREFIXWZNMVVARTYPE;
		else if (ss[i] == "srefrefwznmmvector") ix |= SREFREFWZNMMVECTOR;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmOpk::ImeIAMOpRetval::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIAMOpRetval::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWZNMCAMOPRETVAL) ss.push_back("irefRefWznmCAMOpRetval");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXWZNMVVARTYPE) ss.push_back("srefIxWznmVVartype");
	if (ix & SREFREFWZNMMVECTOR) ss.push_back("srefRefWznmMVector");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeIAMOpRetval
 ******************************************************************************/

IexWznmOpk::ImeIAMOpRetval::ImeIAMOpRetval() {
};

IexWznmOpk::ImeIAMOpRetval::~ImeIAMOpRetval() {
	clear();
};

void IexWznmOpk::ImeIAMOpRetval::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIAMOpRetval::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIAMOpRetval* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmOpk::ImeitemIAMOpRetval();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMOpRetval"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMOpRetval"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMOPRETVAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMOpRetval"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMOpRetval"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIAMOpRetval::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIAMOpRetval* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMOpRetval");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMOpRetval", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMOpRetval";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIAMOpRetval();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIAMOpRetval::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMOpRetval." << StrMod::replaceChar(ImeIAMOpRetval::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMOpRetval.end" << endl;
	};
};

void IexWznmOpk::ImeIAMOpRetval::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMOpRetval");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemICAMOpInvarg
 ******************************************************************************/

IexWznmOpk::ImeitemICAMOpInvarg::ImeitemICAMOpInvarg(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmOpk::ImeitemICAMOpInvarg::ImeitemICAMOpInvarg(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICAMOpInvarg()
		{
};

void IexWznmOpk::ImeitemICAMOpInvarg::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICAMOpInvarg::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMOpInvarg"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemICAMOpInvarg::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICAMOpInvarg::VecWIel::IREF;
	};
};

void IexWznmOpk::ImeitemICAMOpInvarg::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWznmOpk::ImeitemICAMOpInvarg::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICAMOpInvarg","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeICAMOpInvarg::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeICAMOpInvarg::VecWIel::getIx(
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

void IexWznmOpk::ImeICAMOpInvarg::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeICAMOpInvarg::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeICAMOpInvarg
 ******************************************************************************/

IexWznmOpk::ImeICAMOpInvarg::ImeICAMOpInvarg() {
};

IexWznmOpk::ImeICAMOpInvarg::~ImeICAMOpInvarg() {
	clear();
};

void IexWznmOpk::ImeICAMOpInvarg::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeICAMOpInvarg::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemICAMOpInvarg* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmOpk::ImeitemICAMOpInvarg();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMOpInvarg"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMOpInvarg"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICAMOPINVARG) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMOpInvarg"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMOpInvarg"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeICAMOpInvarg::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemICAMOpInvarg* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICAMOpInvarg");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICAMOpInvarg", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICAMOpInvarg";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemICAMOpInvarg();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeICAMOpInvarg::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICAMOpInvarg." << StrMod::replaceChar(ImeICAMOpInvarg::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICAMOpInvarg.end" << endl;
	};
};

void IexWznmOpk::ImeICAMOpInvarg::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICAMOpInvarg");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemICAMOpRetval
 ******************************************************************************/

IexWznmOpk::ImeitemICAMOpRetval::ImeitemICAMOpRetval(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmOpk::ImeitemICAMOpRetval::ImeitemICAMOpRetval(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICAMOpRetval()
		{
};

void IexWznmOpk::ImeitemICAMOpRetval::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICAMOpRetval::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMOpRetval"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemICAMOpRetval::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICAMOpRetval::VecWIel::IREF;
	};
};

void IexWznmOpk::ImeitemICAMOpRetval::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWznmOpk::ImeitemICAMOpRetval::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICAMOpRetval","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeICAMOpRetval::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeICAMOpRetval::VecWIel::getIx(
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

void IexWznmOpk::ImeICAMOpRetval::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeICAMOpRetval::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeICAMOpRetval
 ******************************************************************************/

IexWznmOpk::ImeICAMOpRetval::ImeICAMOpRetval() {
};

IexWznmOpk::ImeICAMOpRetval::~ImeICAMOpRetval() {
	clear();
};

void IexWznmOpk::ImeICAMOpRetval::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeICAMOpRetval::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemICAMOpRetval* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmOpk::ImeitemICAMOpRetval();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMOpRetval"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICAMOpRetval"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICAMOPRETVAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMOpRetval"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICAMOpRetval"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeICAMOpRetval::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemICAMOpRetval* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICAMOpRetval");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICAMOpRetval", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICAMOpRetval";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemICAMOpRetval();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeICAMOpRetval::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICAMOpRetval." << StrMod::replaceChar(ImeICAMOpRetval::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICAMOpRetval.end" << endl;
	};
};

void IexWznmOpk::ImeICAMOpRetval::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICAMOpRetval");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemIJAMBlockItem2
 ******************************************************************************/

IexWznmOpk::ImeitemIJAMBlockItem2::ImeitemIJAMBlockItem2(
			const string& Defval
			, const string& srefRefWznmMVectoritem
		) : WznmJAMBlockItem() {
	lineno = 0;
	ixWIelValid = 0;

	this->Defval = Defval;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
};

IexWznmOpk::ImeitemIJAMBlockItem2::ImeitemIJAMBlockItem2(
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

void IexWznmOpk::ImeitemIJAMBlockItem2::readTxt(
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

void IexWznmOpk::ImeitemIJAMBlockItem2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIJAMBlockItem2::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIJAMBlockItem2::VecWIel::SREFREFWZNMMVECTORITEM;
	};
};

void IexWznmOpk::ImeitemIJAMBlockItem2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << Defval << "\t" << srefRefWznmMVectoritem << endl;
};

void IexWznmOpk::ImeitemIJAMBlockItem2::writeXML(
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
 class IexWznmOpk::ImeIJAMBlockItem2::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIJAMBlockItem2::VecWIel::getIx(
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

void IexWznmOpk::ImeIJAMBlockItem2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMVECTORITEM); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIJAMBlockItem2::VecWIel::getSrefs(
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
 class IexWznmOpk::ImeIJAMBlockItem2
 ******************************************************************************/

IexWznmOpk::ImeIJAMBlockItem2::ImeIJAMBlockItem2() {
};

IexWznmOpk::ImeIJAMBlockItem2::~ImeIJAMBlockItem2() {
	clear();
};

void IexWznmOpk::ImeIJAMBlockItem2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIJAMBlockItem2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIJAMBlockItem2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWznmOpk::ImeitemIJAMBlockItem2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 4) {
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

void IexWznmOpk::ImeIJAMBlockItem2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIJAMBlockItem2* ii = NULL;

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

			ii = new IexWznmOpk::ImeitemIJAMBlockItem2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIJAMBlockItem2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIJAMBlockItem2." << StrMod::replaceChar(ImeIJAMBlockItem2::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIJAMBlockItem2.end" << endl;
	};
};

void IexWznmOpk::ImeIJAMBlockItem2::writeXML(
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
 class IexWznmOpk::ImeitemIAMBlockItem2
 ******************************************************************************/

IexWznmOpk::ImeitemIAMBlockItem2::ImeitemIAMBlockItem2(
			const ubigint irefRefWznmCAMBlockItem
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
	this->sref = sref;
	this->ixWznmVVartype = ixWznmVVartype;
	this->srefRefWznmMVector = srefRefWznmMVector;
	this->Defval = Defval;
	this->srefRefWznmMVectoritem = srefRefWznmMVectoritem;
	this->Comment = Comment;
};

IexWznmOpk::ImeitemIAMBlockItem2::ImeitemIAMBlockItem2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMBlockItem2()
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

void IexWznmOpk::ImeitemIAMBlockItem2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWznmCAMBlockItem = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIAMBlockItem2::VecWIel::IREFREFWZNMCAMBLOCKITEM;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAMBlockItem2::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefIxWznmVVartype = txtrd.fields[2]; ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFIXWZNMVVARTYPE;};
	if (txtrd.fields.size() > 3) {srefRefWznmMVector = txtrd.fields[3]; ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFREFWZNMMVECTOR;};
	if (txtrd.fields.size() > 4) {Defval = txtrd.fields[4]; ixWIelValid += ImeIAMBlockItem2::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 5) {srefRefWznmMVectoritem = txtrd.fields[5]; ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFREFWZNMMVECTORITEM;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIAMBlockItem2::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIJAMBLOCKITEM2)) {
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

void IexWznmOpk::ImeitemIAMBlockItem2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCAMBlockItem", "clu", irefRefWznmCAMBlockItem)) ixWIelValid += ImeIAMBlockItem2::VecWIel::IREFREFWZNMCAMBLOCKITEM;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMBlockItem2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVVartype", "vty", srefIxWznmVVartype)) ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFIXWZNMVVARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVector", "vec", srefRefWznmMVector)) ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFREFWZNMMVECTOR;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIAMBlockItem2::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMVectoritem", "vit", srefRefWznmMVectoritem)) ixWIelValid += ImeIAMBlockItem2::VecWIel::SREFREFWZNMMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMBlockItem2::VecWIel::COMMENT;
		imeijamblockitem2.readXML(docctx, basexpath);
	};
};

void IexWznmOpk::ImeitemIAMBlockItem2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << irefRefWznmCAMBlockItem << "\t" << sref << "\t" << VecWznmVVartype::getSref(ixWznmVVartype) << "\t" << srefRefWznmMVector << "\t" << Defval << "\t" << srefRefWznmMVectoritem << "\t" << Comment << endl;
	imeijamblockitem2.writeTxt(outfile);
};

void IexWznmOpk::ImeitemIAMBlockItem2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","srf","vty","vec","dfv","vit","cmt"};
	else tags = {"ImeitemIAMBlockItem2","irefRefWznmCAMBlockItem","sref","srefIxWznmVVartype","srefRefWznmMVector","Defval","srefRefWznmMVectoritem","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWznmCAMBlockItem);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], VecWznmVVartype::getSref(ixWznmVVartype));
		writeString(wr, tags[4], srefRefWznmMVector);
		writeString(wr, tags[5], Defval);
		writeString(wr, tags[6], srefRefWznmMVectoritem);
		writeString(wr, tags[7], Comment);
		imeijamblockitem2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIAMBlockItem2::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIAMBlockItem2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwznmcamblockitem") ix |= IREFREFWZNMCAMBLOCKITEM;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwznmvvartype") ix |= SREFIXWZNMVVARTYPE;
		else if (ss[i] == "srefrefwznmmvector") ix |= SREFREFWZNMMVECTOR;
		else if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "srefrefwznmmvectoritem") ix |= SREFREFWZNMMVECTORITEM;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmOpk::ImeIAMBlockItem2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIAMBlockItem2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWZNMCAMBLOCKITEM) ss.push_back("irefRefWznmCAMBlockItem");
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
 class IexWznmOpk::ImeIAMBlockItem2
 ******************************************************************************/

IexWznmOpk::ImeIAMBlockItem2::ImeIAMBlockItem2() {
};

IexWznmOpk::ImeIAMBlockItem2::~ImeIAMBlockItem2() {
	clear();
};

void IexWznmOpk::ImeIAMBlockItem2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIAMBlockItem2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIAMBlockItem2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmOpk::ImeitemIAMBlockItem2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
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

void IexWznmOpk::ImeIAMBlockItem2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIAMBlockItem2* ii = NULL;

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

			ii = new IexWznmOpk::ImeitemIAMBlockItem2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIAMBlockItem2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAMBlockItem2." << StrMod::replaceChar(ImeIAMBlockItem2::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIAMBlockItem2.end" << endl;
	};
};

void IexWznmOpk::ImeIAMBlockItem2::writeXML(
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
 class IexWznmOpk::ImeitemICAMBlockItem2
 ******************************************************************************/

IexWznmOpk::ImeitemICAMBlockItem2::ImeitemICAMBlockItem2(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmOpk::ImeitemICAMBlockItem2::ImeitemICAMBlockItem2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICAMBlockItem2()
		{
};

void IexWznmOpk::ImeitemICAMBlockItem2::readTxt(
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

void IexWznmOpk::ImeitemICAMBlockItem2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICAMBlockItem2::VecWIel::IREF;
	};
};

void IexWznmOpk::ImeitemICAMBlockItem2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << iref << endl;
};

void IexWznmOpk::ImeitemICAMBlockItem2::writeXML(
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
 class IexWznmOpk::ImeICAMBlockItem2::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeICAMBlockItem2::VecWIel::getIx(
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

void IexWznmOpk::ImeICAMBlockItem2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeICAMBlockItem2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeICAMBlockItem2
 ******************************************************************************/

IexWznmOpk::ImeICAMBlockItem2::ImeICAMBlockItem2() {
};

IexWznmOpk::ImeICAMBlockItem2::~ImeICAMBlockItem2() {
	clear();
};

void IexWznmOpk::ImeICAMBlockItem2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeICAMBlockItem2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemICAMBlockItem2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmOpk::ImeitemICAMBlockItem2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
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

void IexWznmOpk::ImeICAMBlockItem2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemICAMBlockItem2* ii = NULL;

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

			ii = new IexWznmOpk::ImeitemICAMBlockItem2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeICAMBlockItem2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeICAMBlockItem2." << StrMod::replaceChar(ImeICAMBlockItem2::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeICAMBlockItem2.end" << endl;
	};
};

void IexWznmOpk::ImeICAMBlockItem2::writeXML(
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
 class IexWznmOpk::ImeitemIMBlock2
 ******************************************************************************/

IexWznmOpk::ImeitemIMBlock2::ImeitemIMBlock2(
			const string& sref
			, const string& Comment
		) : WznmMBlock() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexWznmOpk::ImeitemIMBlock2::ImeitemIMBlock2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMBlock2()
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

void IexWznmOpk::ImeitemIMBlock2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMBlock2::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIMBlock2::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIAMBLOCKITEM2)) {
					imeiamblockitem2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEICAMBLOCKITEM2)) {
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

void IexWznmOpk::ImeitemIMBlock2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMBlock2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMBlock2::VecWIel::COMMENT;
		imeiamblockitem2.readXML(docctx, basexpath);
		imeicamblockitem2.readXML(docctx, basexpath);
	};
};

void IexWznmOpk::ImeitemIMBlock2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << Comment << endl;
	imeiamblockitem2.writeTxt(outfile);
	imeicamblockitem2.writeTxt(outfile);
};

void IexWznmOpk::ImeitemIMBlock2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMBlock2","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
		imeiamblockitem2.writeXML(wr, shorttags);
		imeicamblockitem2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIMBlock2::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIMBlock2::VecWIel::getIx(
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

void IexWznmOpk::ImeIMBlock2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIMBlock2::VecWIel::getSrefs(
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
 class IexWznmOpk::ImeIMBlock2
 ******************************************************************************/

IexWznmOpk::ImeIMBlock2::ImeIMBlock2() {
};

IexWznmOpk::ImeIMBlock2::~ImeIMBlock2() {
	clear();
};

void IexWznmOpk::ImeIMBlock2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIMBlock2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIMBlock2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmOpk::ImeitemIMBlock2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBlock2"}, {"lineno",to_string(txtrd.linecnt)}});

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

void IexWznmOpk::ImeIMBlock2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIMBlock2* ii = NULL;

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

			ii = new IexWznmOpk::ImeitemIMBlock2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIMBlock2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMBlock2." << StrMod::replaceChar(ImeIMBlock2::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMBlock2.end" << endl;
	};
};

void IexWznmOpk::ImeIMBlock2::writeXML(
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
 class IexWznmOpk::ImeitemIJMSquawkTitle2
 ******************************************************************************/

IexWznmOpk::ImeitemIJMSquawkTitle2::ImeitemIJMSquawkTitle2(
			const string& srefX1RefWznmMLocale
			, const string& Title
		) : WznmJMSquawkTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
};

IexWznmOpk::ImeitemIJMSquawkTitle2::ImeitemIJMSquawkTitle2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMSquawkTitle2()
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

void IexWznmOpk::ImeitemIJMSquawkTitle2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMSquawkTitle2::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMSquawkTitle2::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMSquawkTitle2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIJMSquawkTitle2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMSquawkTitle2::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMSquawkTitle2::VecWIel::TITLE;
	};
};

void IexWznmOpk::ImeitemIJMSquawkTitle2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefX1RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmOpk::ImeitemIJMSquawkTitle2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit"};
	else tags = {"ImeitemIJMSquawkTitle2","srefX1RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIJMSquawkTitle2::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIJMSquawkTitle2::VecWIel::getIx(
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

void IexWznmOpk::ImeIJMSquawkTitle2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIJMSquawkTitle2::VecWIel::getSrefs(
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
 class IexWznmOpk::ImeIJMSquawkTitle2
 ******************************************************************************/

IexWznmOpk::ImeIJMSquawkTitle2::ImeIJMSquawkTitle2() {
};

IexWznmOpk::ImeIJMSquawkTitle2::~ImeIJMSquawkTitle2() {
	clear();
};

void IexWznmOpk::ImeIJMSquawkTitle2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIJMSquawkTitle2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIJMSquawkTitle2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmOpk::ImeitemIJMSquawkTitle2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMSquawkTitle2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMSquawkTitle2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMSQUAWKTITLE2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMSquawkTitle2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMSquawkTitle2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIJMSquawkTitle2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIJMSquawkTitle2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMSquawkTitle2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMSquawkTitle2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMSquawkTitle2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIJMSquawkTitle2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIJMSquawkTitle2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMSquawkTitle2." << StrMod::replaceChar(ImeIJMSquawkTitle2::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMSquawkTitle2.end" << endl;
	};
};

void IexWznmOpk::ImeIJMSquawkTitle2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMSquawkTitle2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemIRMSquawkMStub2
 ******************************************************************************/

IexWznmOpk::ImeitemIRMSquawkMStub2::ImeitemIRMSquawkMStub2(
			const string& srefRefWznmMStub
		) : WznmRMSquawkMStub() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMStub = srefRefWznmMStub;
};

IexWznmOpk::ImeitemIRMSquawkMStub2::ImeitemIRMSquawkMStub2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMSquawkMStub2()
		{
	WznmRMSquawkMStub* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmsquawkmstub->loadRecByRef(ref, &rec)) {
		refWznmMSquawk = rec->refWznmMSquawk;
		refWznmMStub = rec->refWznmMStub;

		delete rec;
	};
};

void IexWznmOpk::ImeitemIRMSquawkMStub2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMStub = txtrd.fields[0]; ixWIelValid += ImeIRMSquawkMStub2::VecWIel::SREFREFWZNMMSTUB;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMSquawkMStub2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIRMSquawkMStub2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMStub", "stb", srefRefWznmMStub)) ixWIelValid += ImeIRMSquawkMStub2::VecWIel::SREFREFWZNMMSTUB;
	};
};

void IexWznmOpk::ImeitemIRMSquawkMStub2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefRefWznmMStub << endl;
};

void IexWznmOpk::ImeitemIRMSquawkMStub2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","stb"};
	else tags = {"ImeitemIRMSquawkMStub2","srefRefWznmMStub"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMStub);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIRMSquawkMStub2::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIRMSquawkMStub2::VecWIel::getIx(
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

void IexWznmOpk::ImeIRMSquawkMStub2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMSTUB); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIRMSquawkMStub2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMSTUB) ss.push_back("srefRefWznmMStub");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeIRMSquawkMStub2
 ******************************************************************************/

IexWznmOpk::ImeIRMSquawkMStub2::ImeIRMSquawkMStub2() {
};

IexWznmOpk::ImeIRMSquawkMStub2::~ImeIRMSquawkMStub2() {
	clear();
};

void IexWznmOpk::ImeIRMSquawkMStub2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIRMSquawkMStub2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIRMSquawkMStub2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmOpk::ImeitemIRMSquawkMStub2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMSquawkMStub2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMSquawkMStub2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMSQUAWKMSTUB2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMSquawkMStub2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMSquawkMStub2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIRMSquawkMStub2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIRMSquawkMStub2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMSquawkMStub2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMSquawkMStub2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMSquawkMStub2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIRMSquawkMStub2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIRMSquawkMStub2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIRMSquawkMStub2." << StrMod::replaceChar(ImeIRMSquawkMStub2::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIRMSquawkMStub2.end" << endl;
	};
};

void IexWznmOpk::ImeIRMSquawkMStub2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMSquawkMStub2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemIMSquawk2
 ******************************************************************************/

IexWznmOpk::ImeitemIMSquawk2::ImeitemIMSquawk2(
			const string& Title
			, const string& Example
		) : WznmMSquawk() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
	this->Example = Example;
};

IexWznmOpk::ImeitemIMSquawk2::ImeitemIMSquawk2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMSquawk2()
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

void IexWznmOpk::ImeitemIMSquawk2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Title = txtrd.fields[0]; ixWIelValid += ImeIMSquawk2::VecWIel::TITLE;};
	if (txtrd.fields.size() > 1) {Example = txtrd.fields[1]; ixWIelValid += ImeIMSquawk2::VecWIel::EXAMPLE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMSQUAWKTITLE2)) {
					imeijmsquawktitle2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIRMSQUAWKMSTUB2)) {
					imeirmsquawkmstub2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSquawk2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIMSquawk2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMSquawk2::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Example", "exa", Example)) ixWIelValid += ImeIMSquawk2::VecWIel::EXAMPLE;
		imeijmsquawktitle2.readXML(docctx, basexpath);
		imeirmsquawkmstub2.readXML(docctx, basexpath);
	};
};

void IexWznmOpk::ImeitemIMSquawk2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << Title << "\t" << Example << endl;
	imeijmsquawktitle2.writeTxt(outfile);
	imeirmsquawkmstub2.writeTxt(outfile);
};

void IexWznmOpk::ImeitemIMSquawk2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tit","exa"};
	else tags = {"ImeitemIMSquawk2","Title","Example"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Title);
		writeString(wr, tags[2], Example);
		imeijmsquawktitle2.writeXML(wr, shorttags);
		imeirmsquawkmstub2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIMSquawk2::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIMSquawk2::VecWIel::getIx(
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

void IexWznmOpk::ImeIMSquawk2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*EXAMPLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIMSquawk2::VecWIel::getSrefs(
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
 class IexWznmOpk::ImeIMSquawk2
 ******************************************************************************/

IexWznmOpk::ImeIMSquawk2::ImeIMSquawk2() {
};

IexWznmOpk::ImeIMSquawk2::~ImeIMSquawk2() {
	clear();
};

void IexWznmOpk::ImeIMSquawk2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIMSquawk2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIMSquawk2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmOpk::ImeitemIMSquawk2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSquawk2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSquawk2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSQUAWK2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSquawk2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSquawk2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIMSquawk2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIMSquawk2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSquawk2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSquawk2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSquawk2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIMSquawk2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIMSquawk2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMSquawk2." << StrMod::replaceChar(ImeIMSquawk2::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMSquawk2.end" << endl;
	};
};

void IexWznmOpk::ImeIMSquawk2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSquawk2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemIMOp
 ******************************************************************************/

IexWznmOpk::ImeitemIMOp::ImeitemIMOp(
			const string& sref
			, const bool Shrdat
			, const string& Comment
		) : WznmMOp() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Shrdat = Shrdat;
	this->Comment = Comment;
};

IexWznmOpk::ImeitemIMOp::ImeitemIMOp(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMOp()
		{
	WznmMOp* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmop->loadRecByRef(ref, &rec)) {
		refWznmMOppack = rec->refWznmMOppack;
		refWznmMSquawk = rec->refWznmMSquawk;
		sref = rec->sref;
		Shrdat = rec->Shrdat;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmOpk::ImeitemIMOp::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMOp::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Shrdat = (txtrd.fields[1] == "true"); ixWIelValid += ImeIMOp::VecWIel::SHRDAT;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMOp::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMOPINVARG)) {
					imeiamopinvarg.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMOPRETVAL)) {
					imeiamopretval.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEICAMOPINVARG)) {
					imeicamopinvarg.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEICAMOPRETVAL)) {
					imeicamopretval.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMBLOCK2)) {
					imeimblock2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMSQUAWK2)) {
					imeimsquawk2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMOp"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIMOp::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMOp::VecWIel::SREF;
		if (extractBoolUclc(docctx, basexpath, "Shrdat", "shd", Shrdat)) ixWIelValid += ImeIMOp::VecWIel::SHRDAT;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMOp::VecWIel::COMMENT;
		imeiamopinvarg.readXML(docctx, basexpath);
		imeiamopretval.readXML(docctx, basexpath);
		imeicamopinvarg.readXML(docctx, basexpath);
		imeicamopretval.readXML(docctx, basexpath);
		imeimblock2.readXML(docctx, basexpath);
		imeimsquawk2.readXML(docctx, basexpath);
	};
};

void IexWznmOpk::ImeitemIMOp::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << StrMod::boolToString(Shrdat) << "\t" << Comment << endl;
	imeiamopinvarg.writeTxt(outfile);
	imeiamopretval.writeTxt(outfile);
	imeicamopinvarg.writeTxt(outfile);
	imeicamopretval.writeTxt(outfile);
	imeimblock2.writeTxt(outfile);
	imeimsquawk2.writeTxt(outfile);
};

void IexWznmOpk::ImeitemIMOp::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","shd","cmt"};
	else tags = {"ImeitemIMOp","sref","Shrdat","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeBool(wr, tags[2], Shrdat);
		writeString(wr, tags[3], Comment);
		imeiamopinvarg.writeXML(wr, shorttags);
		imeiamopretval.writeXML(wr, shorttags);
		imeicamopinvarg.writeXML(wr, shorttags);
		imeicamopretval.writeXML(wr, shorttags);
		imeimblock2.writeXML(wr, shorttags);
		imeimsquawk2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIMOp::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIMOp::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "shrdat") ix |= SHRDAT;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmOpk::ImeIMOp::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIMOp::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SHRDAT) ss.push_back("Shrdat");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeIMOp
 ******************************************************************************/

IexWznmOpk::ImeIMOp::ImeIMOp() {
};

IexWznmOpk::ImeIMOp::~ImeIMOp() {
	clear();
};

void IexWznmOpk::ImeIMOp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIMOp::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIMOp* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmOpk::ImeitemIMOp();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMOp"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMOp"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMOP) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMOp"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMOp"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIMOp::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIMOp* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMOp");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMOp", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMOp";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIMOp();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIMOp::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMOp." << StrMod::replaceChar(ImeIMOp::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMOp.end" << endl;
	};
};

void IexWznmOpk::ImeIMOp::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMOp");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemIJMSquawkTitle1
 ******************************************************************************/

IexWznmOpk::ImeitemIJMSquawkTitle1::ImeitemIJMSquawkTitle1(
			const string& srefX1RefWznmMLocale
			, const string& Title
		) : WznmJMSquawkTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWznmMLocale = srefX1RefWznmMLocale;
	this->Title = Title;
};

IexWznmOpk::ImeitemIJMSquawkTitle1::ImeitemIJMSquawkTitle1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMSquawkTitle1()
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

void IexWznmOpk::ImeitemIJMSquawkTitle1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMSquawkTitle1::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMSquawkTitle1::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMSquawkTitle1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIJMSquawkTitle1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMSquawkTitle1::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMSquawkTitle1::VecWIel::TITLE;
	};
};

void IexWznmOpk::ImeitemIJMSquawkTitle1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefX1RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmOpk::ImeitemIJMSquawkTitle1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit"};
	else tags = {"ImeitemIJMSquawkTitle1","srefX1RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIJMSquawkTitle1::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIJMSquawkTitle1::VecWIel::getIx(
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

void IexWznmOpk::ImeIJMSquawkTitle1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIJMSquawkTitle1::VecWIel::getSrefs(
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
 class IexWznmOpk::ImeIJMSquawkTitle1
 ******************************************************************************/

IexWznmOpk::ImeIJMSquawkTitle1::ImeIJMSquawkTitle1() {
};

IexWznmOpk::ImeIJMSquawkTitle1::~ImeIJMSquawkTitle1() {
	clear();
};

void IexWznmOpk::ImeIJMSquawkTitle1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIJMSquawkTitle1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIJMSquawkTitle1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmOpk::ImeitemIJMSquawkTitle1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMSquawkTitle1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMSquawkTitle1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMSQUAWKTITLE1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMSquawkTitle1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMSquawkTitle1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIJMSquawkTitle1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIJMSquawkTitle1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMSquawkTitle1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMSquawkTitle1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMSquawkTitle1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIJMSquawkTitle1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIJMSquawkTitle1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMSquawkTitle1." << StrMod::replaceChar(ImeIJMSquawkTitle1::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMSquawkTitle1.end" << endl;
	};
};

void IexWznmOpk::ImeIJMSquawkTitle1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMSquawkTitle1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemIRMSquawkMStub1
 ******************************************************************************/

IexWznmOpk::ImeitemIRMSquawkMStub1::ImeitemIRMSquawkMStub1(
			const string& srefRefWznmMStub
		) : WznmRMSquawkMStub() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMStub = srefRefWznmMStub;
};

IexWznmOpk::ImeitemIRMSquawkMStub1::ImeitemIRMSquawkMStub1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMSquawkMStub1()
		{
	WznmRMSquawkMStub* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmsquawkmstub->loadRecByRef(ref, &rec)) {
		refWznmMSquawk = rec->refWznmMSquawk;
		refWznmMStub = rec->refWznmMStub;

		delete rec;
	};
};

void IexWznmOpk::ImeitemIRMSquawkMStub1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMStub = txtrd.fields[0]; ixWIelValid += ImeIRMSquawkMStub1::VecWIel::SREFREFWZNMMSTUB;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMSquawkMStub1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIRMSquawkMStub1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMStub", "stb", srefRefWznmMStub)) ixWIelValid += ImeIRMSquawkMStub1::VecWIel::SREFREFWZNMMSTUB;
	};
};

void IexWznmOpk::ImeitemIRMSquawkMStub1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefRefWznmMStub << endl;
};

void IexWznmOpk::ImeitemIRMSquawkMStub1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","stb"};
	else tags = {"ImeitemIRMSquawkMStub1","srefRefWznmMStub"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMStub);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIRMSquawkMStub1::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIRMSquawkMStub1::VecWIel::getIx(
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

void IexWznmOpk::ImeIRMSquawkMStub1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMSTUB); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIRMSquawkMStub1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMSTUB) ss.push_back("srefRefWznmMStub");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeIRMSquawkMStub1
 ******************************************************************************/

IexWznmOpk::ImeIRMSquawkMStub1::ImeIRMSquawkMStub1() {
};

IexWznmOpk::ImeIRMSquawkMStub1::~ImeIRMSquawkMStub1() {
	clear();
};

void IexWznmOpk::ImeIRMSquawkMStub1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIRMSquawkMStub1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIRMSquawkMStub1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmOpk::ImeitemIRMSquawkMStub1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMSquawkMStub1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMSquawkMStub1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMSQUAWKMSTUB1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMSquawkMStub1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMSquawkMStub1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIRMSquawkMStub1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIRMSquawkMStub1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMSquawkMStub1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMSquawkMStub1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMSquawkMStub1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIRMSquawkMStub1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIRMSquawkMStub1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIRMSquawkMStub1." << StrMod::replaceChar(ImeIRMSquawkMStub1::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIRMSquawkMStub1.end" << endl;
	};
};

void IexWznmOpk::ImeIRMSquawkMStub1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMSquawkMStub1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemIMSquawk1
 ******************************************************************************/

IexWznmOpk::ImeitemIMSquawk1::ImeitemIMSquawk1(
			const string& Title
			, const string& Example
		) : WznmMSquawk() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
	this->Example = Example;
};

IexWznmOpk::ImeitemIMSquawk1::ImeitemIMSquawk1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMSquawk1()
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

void IexWznmOpk::ImeitemIMSquawk1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Title = txtrd.fields[0]; ixWIelValid += ImeIMSquawk1::VecWIel::TITLE;};
	if (txtrd.fields.size() > 1) {Example = txtrd.fields[1]; ixWIelValid += ImeIMSquawk1::VecWIel::EXAMPLE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMSQUAWKTITLE1)) {
					imeijmsquawktitle1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIRMSQUAWKMSTUB1)) {
					imeirmsquawkmstub1.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSquawk1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIMSquawk1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMSquawk1::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Example", "exa", Example)) ixWIelValid += ImeIMSquawk1::VecWIel::EXAMPLE;
		imeijmsquawktitle1.readXML(docctx, basexpath);
		imeirmsquawkmstub1.readXML(docctx, basexpath);
	};
};

void IexWznmOpk::ImeitemIMSquawk1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << Title << "\t" << Example << endl;
	imeijmsquawktitle1.writeTxt(outfile);
	imeirmsquawkmstub1.writeTxt(outfile);
};

void IexWznmOpk::ImeitemIMSquawk1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tit","exa"};
	else tags = {"ImeitemIMSquawk1","Title","Example"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Title);
		writeString(wr, tags[2], Example);
		imeijmsquawktitle1.writeXML(wr, shorttags);
		imeirmsquawkmstub1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIMSquawk1::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIMSquawk1::VecWIel::getIx(
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

void IexWznmOpk::ImeIMSquawk1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*EXAMPLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIMSquawk1::VecWIel::getSrefs(
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
 class IexWznmOpk::ImeIMSquawk1
 ******************************************************************************/

IexWznmOpk::ImeIMSquawk1::ImeIMSquawk1() {
};

IexWznmOpk::ImeIMSquawk1::~ImeIMSquawk1() {
	clear();
};

void IexWznmOpk::ImeIMSquawk1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIMSquawk1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIMSquawk1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmOpk::ImeitemIMSquawk1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSquawk1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSquawk1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSQUAWK1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSquawk1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSquawk1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIMSquawk1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIMSquawk1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSquawk1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSquawk1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSquawk1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIMSquawk1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIMSquawk1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMSquawk1." << StrMod::replaceChar(ImeIMSquawk1::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMSquawk1.end" << endl;
	};
};

void IexWznmOpk::ImeIMSquawk1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSquawk1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemIRMComponentMOppack
 ******************************************************************************/

IexWznmOpk::ImeitemIRMComponentMOppack::ImeitemIRMComponentMOppack(
			const string& srefRefWznmMComponent
		) : WznmRMComponentMOppack() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMComponent = srefRefWznmMComponent;
};

IexWznmOpk::ImeitemIRMComponentMOppack::ImeitemIRMComponentMOppack(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMComponentMOppack()
		{
	WznmRMComponentMOppack* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmcomponentmoppack->loadRecByRef(ref, &rec)) {
		refWznmMComponent = rec->refWznmMComponent;
		refWznmMOppack = rec->refWznmMOppack;

		delete rec;
	};
};

void IexWznmOpk::ImeitemIRMComponentMOppack::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMComponent = txtrd.fields[0]; ixWIelValid += ImeIRMComponentMOppack::VecWIel::SREFREFWZNMMCOMPONENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMComponentMOppack"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIRMComponentMOppack::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMComponent", "cmp", srefRefWznmMComponent)) ixWIelValid += ImeIRMComponentMOppack::VecWIel::SREFREFWZNMMCOMPONENT;
	};
};

void IexWznmOpk::ImeitemIRMComponentMOppack::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefRefWznmMComponent << endl;
};

void IexWznmOpk::ImeitemIRMComponentMOppack::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cmp"};
	else tags = {"ImeitemIRMComponentMOppack","srefRefWznmMComponent"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMComponent);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIRMComponentMOppack::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIRMComponentMOppack::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwznmmcomponent") ix |= SREFREFWZNMMCOMPONENT;
	};

	return(ix);
};

void IexWznmOpk::ImeIRMComponentMOppack::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMCOMPONENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIRMComponentMOppack::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMCOMPONENT) ss.push_back("srefRefWznmMComponent");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeIRMComponentMOppack
 ******************************************************************************/

IexWznmOpk::ImeIRMComponentMOppack::ImeIRMComponentMOppack() {
};

IexWznmOpk::ImeIRMComponentMOppack::~ImeIRMComponentMOppack() {
	clear();
};

void IexWznmOpk::ImeIRMComponentMOppack::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIRMComponentMOppack::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIRMComponentMOppack* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmOpk::ImeitemIRMComponentMOppack();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMComponentMOppack"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMComponentMOppack"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMCOMPONENTMOPPACK) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMComponentMOppack"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMComponentMOppack"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIRMComponentMOppack::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIRMComponentMOppack* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMComponentMOppack");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMComponentMOppack", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMComponentMOppack";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIRMComponentMOppack();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIRMComponentMOppack::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMComponentMOppack." << StrMod::replaceChar(ImeIRMComponentMOppack::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMComponentMOppack.end" << endl;
	};
};

void IexWznmOpk::ImeIRMComponentMOppack::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMComponentMOppack");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemIRMLibraryMOppack
 ******************************************************************************/

IexWznmOpk::ImeitemIRMLibraryMOppack::ImeitemIRMLibraryMOppack(
			const string& srefRefWznmMLibrary
		) : WznmRMLibraryMOppack() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMLibrary = srefRefWznmMLibrary;
};

IexWznmOpk::ImeitemIRMLibraryMOppack::ImeitemIRMLibraryMOppack(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMLibraryMOppack()
		{
	WznmRMLibraryMOppack* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmlibrarymoppack->loadRecByRef(ref, &rec)) {
		refWznmMLibrary = rec->refWznmMLibrary;
		refWznmMOppack = rec->refWznmMOppack;

		delete rec;
	};
};

void IexWznmOpk::ImeitemIRMLibraryMOppack::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMLibrary = txtrd.fields[0]; ixWIelValid += ImeIRMLibraryMOppack::VecWIel::SREFREFWZNMMLIBRARY;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMLibraryMOppack"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIRMLibraryMOppack::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMLibrary", "lib", srefRefWznmMLibrary)) ixWIelValid += ImeIRMLibraryMOppack::VecWIel::SREFREFWZNMMLIBRARY;
	};
};

void IexWznmOpk::ImeitemIRMLibraryMOppack::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefRefWznmMLibrary << endl;
};

void IexWznmOpk::ImeitemIRMLibraryMOppack::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lib"};
	else tags = {"ImeitemIRMLibraryMOppack","srefRefWznmMLibrary"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMLibrary);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIRMLibraryMOppack::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIRMLibraryMOppack::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwznmmlibrary") ix |= SREFREFWZNMMLIBRARY;
	};

	return(ix);
};

void IexWznmOpk::ImeIRMLibraryMOppack::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMLIBRARY); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIRMLibraryMOppack::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMLIBRARY) ss.push_back("srefRefWznmMLibrary");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeIRMLibraryMOppack
 ******************************************************************************/

IexWznmOpk::ImeIRMLibraryMOppack::ImeIRMLibraryMOppack() {
};

IexWznmOpk::ImeIRMLibraryMOppack::~ImeIRMLibraryMOppack() {
	clear();
};

void IexWznmOpk::ImeIRMLibraryMOppack::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIRMLibraryMOppack::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIRMLibraryMOppack* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmOpk::ImeitemIRMLibraryMOppack();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMLibraryMOppack"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMLibraryMOppack"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMLIBRARYMOPPACK) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMLibraryMOppack"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMLibraryMOppack"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIRMLibraryMOppack::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIRMLibraryMOppack* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMLibraryMOppack");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMLibraryMOppack", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMLibraryMOppack";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIRMLibraryMOppack();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIRMLibraryMOppack::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMLibraryMOppack." << StrMod::replaceChar(ImeIRMLibraryMOppack::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMLibraryMOppack.end" << endl;
	};
};

void IexWznmOpk::ImeIRMLibraryMOppack::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMLibraryMOppack");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmOpk::ImeitemIMOppack
 ******************************************************************************/

IexWznmOpk::ImeitemIMOppack::ImeitemIMOppack(
			const uint ixVBasetype
			, const string& sref
			, const string& Title
			, const bool Shrdat
			, const string& Comment
		) : WznmMOppack() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->Title = Title;
	this->Shrdat = Shrdat;
	this->Comment = Comment;
};

IexWznmOpk::ImeitemIMOppack::ImeitemIMOppack(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMOppack()
		{
	WznmMOppack* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmoppack->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMVersion = rec->refWznmMVersion;
		refWznmMSquawk = rec->refWznmMSquawk;
		sref = rec->sref;
		Title = rec->Title;
		Shrdat = rec->Shrdat;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmOpk::ImeitemIMOppack::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMOppack::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMOppack::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIMOppack::VecWIel::TITLE;};
	if (txtrd.fields.size() > 3) {Shrdat = (txtrd.fields[3] == "true"); ixWIelValid += ImeIMOppack::VecWIel::SHRDAT;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMOppack::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMOPPACKINVARG)) {
					imeiamoppackinvarg.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMOPPACKRETVAL)) {
					imeiamoppackretval.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEICAMOPPACKINVARG)) {
					imeicamoppackinvarg.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEICAMOPPACKRETVAL)) {
					imeicamoppackretval.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMBLOCK1)) {
					imeimblock1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMOP)) {
					imeimop.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMSQUAWK1)) {
					imeimsquawk1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMCOMPONENTMOPPACK)) {
					imeirmcomponentmoppack.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMLIBRARYMOPPACK)) {
					imeirmlibrarymoppack.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMOppack"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmOpk::ImeitemIMOppack::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMOppack::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMOppack::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMOppack::VecWIel::TITLE;
		if (extractBoolUclc(docctx, basexpath, "Shrdat", "shd", Shrdat)) ixWIelValid += ImeIMOppack::VecWIel::SHRDAT;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMOppack::VecWIel::COMMENT;
		imeiamoppackinvarg.readXML(docctx, basexpath);
		imeiamoppackretval.readXML(docctx, basexpath);
		imeicamoppackinvarg.readXML(docctx, basexpath);
		imeicamoppackretval.readXML(docctx, basexpath);
		imeimblock1.readXML(docctx, basexpath);
		imeimop.readXML(docctx, basexpath);
		imeimsquawk1.readXML(docctx, basexpath);
		imeirmcomponentmoppack.readXML(docctx, basexpath);
		imeirmlibrarymoppack.readXML(docctx, basexpath);
	};
};

void IexWznmOpk::ImeitemIMOppack::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmVMOppackBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << Title << "\t" << StrMod::boolToString(Shrdat) << "\t" << Comment << endl;
	imeiamoppackinvarg.writeTxt(outfile);
	imeiamoppackretval.writeTxt(outfile);
	imeicamoppackinvarg.writeTxt(outfile);
	imeicamoppackretval.writeTxt(outfile);
	imeimblock1.writeTxt(outfile);
	imeimop.writeTxt(outfile);
	imeimsquawk1.writeTxt(outfile);
	imeirmcomponentmoppack.writeTxt(outfile);
	imeirmlibrarymoppack.writeTxt(outfile);
};

void IexWznmOpk::ImeitemIMOppack::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","srf","tit","shd","cmt"};
	else tags = {"ImeitemIMOppack","srefIxVBasetype","sref","Title","Shrdat","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMOppackBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Title);
		writeBool(wr, tags[4], Shrdat);
		writeString(wr, tags[5], Comment);
		imeiamoppackinvarg.writeXML(wr, shorttags);
		imeiamoppackretval.writeXML(wr, shorttags);
		imeicamoppackinvarg.writeXML(wr, shorttags);
		imeicamoppackretval.writeXML(wr, shorttags);
		imeimblock1.writeXML(wr, shorttags);
		imeimop.writeXML(wr, shorttags);
		imeimsquawk1.writeXML(wr, shorttags);
		imeirmcomponentmoppack.writeXML(wr, shorttags);
		imeirmlibrarymoppack.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmOpk::ImeIMOppack::VecWIel
 ******************************************************************************/

uint IexWznmOpk::ImeIMOppack::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "shrdat") ix |= SHRDAT;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmOpk::ImeIMOppack::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmOpk::ImeIMOppack::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & SHRDAT) ss.push_back("Shrdat");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmOpk::ImeIMOppack
 ******************************************************************************/

IexWznmOpk::ImeIMOppack::ImeIMOppack() {
};

IexWznmOpk::ImeIMOppack::~ImeIMOppack() {
	clear();
};

void IexWznmOpk::ImeIMOppack::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmOpk::ImeIMOppack::readTxt(
			Txtrd& txtrd
		) {
	IexWznmOpk::ImeitemIMOppack* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmOpk::ImeitemIMOppack();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMOppack"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMOPPACK) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMOppack"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMOppack"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmOpk::ImeIMOppack::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmOpk::ImeitemIMOppack* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMOppack");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMOppack", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMOppack";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmOpk::ImeitemIMOppack();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmOpk::ImeIMOppack::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMOppack." << StrMod::replaceChar(ImeIMOppack::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMOppack.end" << endl;
	};
};

void IexWznmOpk::ImeIMOppack::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMOppack");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWznmOpk
 ******************************************************************************/

void IexWznmOpk::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, ImeIMOppack& imeimoppack
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimoppack);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, "IexWznmOpk", Version("0.9.23"), VecVIme::getIx);
			readTxt(rd, imeimoppack);
	};
};

void IexWznmOpk::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMOppack& imeimoppack
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimoppack);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimoppack);
		txtfile.close();
	};
};

void IexWznmOpk::readTxt(
			Txtrd& txtrd
			, ImeIMOppack& imeimoppack
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMOPPACK)) imeimoppack.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWznmOpk::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMOppack& imeimoppack
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmOpk")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("0.9.23")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","0.9.23"}});
		};

		// look for XML sub-blocks
		imeimoppack.readXML(docctx, basexpath);

	} else {
		imeimoppack = ImeIMOppack();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmOpk"}});
	};
};

void IexWznmOpk::writeTxt(
			fstream& outfile
			, ImeIMOppack& imeimoppack
		) {
	outfile << "IexWznmOpk v" WZNM_VERSION << endl;

	imeimoppack.writeTxt(outfile);
};

void IexWznmOpk::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMOppack& imeimoppack
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmOpk");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeimoppack.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmOpk::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMBLOCKITEM1,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMBLOCKITEM2,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMOPINVARG,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMOPPACKINVARG,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMOPPACKRETVAL,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMOPRETVAL,VecWznmVIop::INS},{(uint)VecVIme::IMEICAMBLOCKITEM1,VecWznmVIop::INS},{(uint)VecVIme::IMEICAMBLOCKITEM2,VecWznmVIop::INS},{(uint)VecVIme::IMEICAMOPINVARG,VecWznmVIop::INS},{(uint)VecVIme::IMEICAMOPPACKINVARG,VecWznmVIop::INS},{(uint)VecVIme::IMEICAMOPPACKRETVAL,VecWznmVIop::INS},{(uint)VecVIme::IMEICAMOPRETVAL,VecWznmVIop::INS},{(uint)VecVIme::IMEIJAMBLOCKITEM1,VecWznmVIop::INS},{(uint)VecVIme::IMEIJAMBLOCKITEM2,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMSQUAWKTITLE1,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMSQUAWKTITLE2,VecWznmVIop::INS},{(uint)VecVIme::IMEIMBLOCK1,VecWznmVIop::INS},{(uint)VecVIme::IMEIMBLOCK2,VecWznmVIop::INS},{(uint)VecVIme::IMEIMOP,VecWznmVIop::INS},{(uint)VecVIme::IMEIMOPPACK,VecWznmVIop::INS},{(uint)VecVIme::IMEIMSQUAWK1,VecWznmVIop::INS},{(uint)VecVIme::IMEIMSQUAWK2,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMCOMPONENTMOPPACK,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMLIBRARYMOPPACK,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMSQUAWKMSTUB1,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMSQUAWKMSTUB2,VecWznmVIop::INS}};
};

uint IexWznmOpk::getIxWznmVIop(
			const map<uint,uint>& icsWznmVIop
			, const uint ixVIme
			, uint& ixWznmVIop
		) {
	ixWznmVIop = 0;

	auto it = icsWznmVIop.find(ixVIme);
	if (it != icsWznmVIop.end()) ixWznmVIop = it->second;

	return ixWznmVIop;
};

