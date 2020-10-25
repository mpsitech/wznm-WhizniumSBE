/**
	* \file IexWznmDbs.cpp
	* data blocks and readers/writers for import/export complex IexWznmDbs (implementation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#include "IexWznmDbs.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWznmDbs::VecVIme
 ******************************************************************************/

uint IexWznmDbs::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamrelationtitle") return IMEIAMRELATIONTITLE;
	if (s == "imeiamsubsettitle") return IMEIAMSUBSETTITLE;
	if (s == "imeiamtablecoltitle") return IMEIAMTABLECOLTITLE;
	if (s == "imeiamtableloadfct") return IMEIAMTABLELOADFCT;
	if (s == "imeiamtabletitle") return IMEIAMTABLETITLE;
	if (s == "imeiamvectortitle1") return IMEIAMVECTORTITLE1;
	if (s == "imeiamvectortitle2") return IMEIAMVECTORTITLE2;
	if (s == "imeicrelation") return IMEICRELATION;
	if (s == "imeijmvectoritem1") return IMEIJMVECTORITEM1;
	if (s == "imeijmvectoritem2") return IMEIJMVECTORITEM2;
	if (s == "imeimcheck") return IMEIMCHECK;
	if (s == "imeimrelation") return IMEIMRELATION;
	if (s == "imeimstub") return IMEIMSTUB;
	if (s == "imeimsubset") return IMEIMSUBSET;
	if (s == "imeimtable") return IMEIMTABLE;
	if (s == "imeimtablecol") return IMEIMTABLECOL;
	if (s == "imeimvector1") return IMEIMVECTOR1;
	if (s == "imeimvector2") return IMEIMVECTOR2;
	if (s == "imeimvectoritem1") return IMEIMVECTORITEM1;
	if (s == "imeimvectoritem2") return IMEIMVECTORITEM2;
	if (s == "imeirmstubmstub") return IMEIRMSTUBMSTUB;
	if (s == "imeirmsubsetmsubset") return IMEIRMSUBSETMSUBSET;
	if (s == "imeirmtablemvector1") return IMEIRMTABLEMVECTOR1;
	if (s == "imeirmtablemvector2") return IMEIRMTABLEMVECTOR2;

	return(0);
};

string IexWznmDbs::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMRELATIONTITLE) return("ImeIAMRelationTitle");
	if (ix == IMEIAMSUBSETTITLE) return("ImeIAMSubsetTitle");
	if (ix == IMEIAMTABLECOLTITLE) return("ImeIAMTablecolTitle");
	if (ix == IMEIAMTABLELOADFCT) return("ImeIAMTableLoadfct");
	if (ix == IMEIAMTABLETITLE) return("ImeIAMTableTitle");
	if (ix == IMEIAMVECTORTITLE1) return("ImeIAMVectorTitle1");
	if (ix == IMEIAMVECTORTITLE2) return("ImeIAMVectorTitle2");
	if (ix == IMEICRELATION) return("ImeICRelation");
	if (ix == IMEIJMVECTORITEM1) return("ImeIJMVectoritem1");
	if (ix == IMEIJMVECTORITEM2) return("ImeIJMVectoritem2");
	if (ix == IMEIMCHECK) return("ImeIMCheck");
	if (ix == IMEIMRELATION) return("ImeIMRelation");
	if (ix == IMEIMSTUB) return("ImeIMStub");
	if (ix == IMEIMSUBSET) return("ImeIMSubset");
	if (ix == IMEIMTABLE) return("ImeIMTable");
	if (ix == IMEIMTABLECOL) return("ImeIMTablecol");
	if (ix == IMEIMVECTOR1) return("ImeIMVector1");
	if (ix == IMEIMVECTOR2) return("ImeIMVector2");
	if (ix == IMEIMVECTORITEM1) return("ImeIMVectoritem1");
	if (ix == IMEIMVECTORITEM2) return("ImeIMVectoritem2");
	if (ix == IMEIRMSTUBMSTUB) return("ImeIRMStubMStub");
	if (ix == IMEIRMSUBSETMSUBSET) return("ImeIRMSubsetMSubset");
	if (ix == IMEIRMTABLEMVECTOR1) return("ImeIRMTableMVector1");
	if (ix == IMEIRMTABLEMVECTOR2) return("ImeIRMTableMVector2");

	return("");
};

/******************************************************************************
 class IexWznmDbs::ImeitemICRelation
 ******************************************************************************/

IexWznmDbs::ImeitemICRelation::ImeitemICRelation(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWznmDbs::ImeitemICRelation::ImeitemICRelation(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemICRelation()
		{
};

void IexWznmDbs::ImeitemICRelation::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICRelation::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICRelation"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemICRelation::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICRelation::VecWIel::IREF;
	};
};

void IexWznmDbs::ImeitemICRelation::writeTxt(
			fstream& outfile
		) {
	outfile << iref << endl;
};

void IexWznmDbs::ImeitemICRelation::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICRelation","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeICRelation::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeICRelation::VecWIel::getIx(
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

void IexWznmDbs::ImeICRelation::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeICRelation::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeICRelation
 ******************************************************************************/

IexWznmDbs::ImeICRelation::ImeICRelation() {
};

IexWznmDbs::ImeICRelation::~ImeICRelation() {
	clear();
};

void IexWznmDbs::ImeICRelation::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeICRelation::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemICRelation* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmDbs::ImeitemICRelation();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICRelation"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICRELATION) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICRelation"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICRelation"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeICRelation::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemICRelation* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICRelation");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICRelation", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICRelation";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemICRelation();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeICRelation::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeICRelation." << StrMod::replaceChar(ImeICRelation::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeICRelation.end" << endl;
	};
};

void IexWznmDbs::ImeICRelation::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICRelation");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIAMRelationTitle
 ******************************************************************************/

IexWznmDbs::ImeitemIAMRelationTitle::ImeitemIAMRelationTitle(
			const uint x1IxVType
			, const string& srefX2RefWznmMLocale
			, const string& Title
		) : WznmAMRelationTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxVType = x1IxVType;
	this->srefX2RefWznmMLocale = srefX2RefWznmMLocale;
	this->Title = Title;
};

IexWznmDbs::ImeitemIAMRelationTitle::ImeitemIAMRelationTitle(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMRelationTitle()
		{
	WznmAMRelationTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamrelationtitle->loadRecByRef(ref, &rec)) {
		refWznmMRelation = rec->refWznmMRelation;
		x1IxVType = rec->x1IxVType;
		x2RefWznmMLocale = rec->x2RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIAMRelationTitle::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxVType = txtrd.fields[0]; ixWIelValid += ImeIAMRelationTitle::VecWIel::SREFX1IXVTYPE;};
	if (txtrd.fields.size() > 1) {srefX2RefWznmMLocale = txtrd.fields[1]; ixWIelValid += ImeIAMRelationTitle::VecWIel::SREFX2REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIAMRelationTitle::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMRelationTitle"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIAMRelationTitle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxVType", "typ", srefX1IxVType)) ixWIelValid += ImeIAMRelationTitle::VecWIel::SREFX1IXVTYPE;
		if (extractStringUclc(docctx, basexpath, "srefX2RefWznmMLocale", "loc", srefX2RefWznmMLocale)) ixWIelValid += ImeIAMRelationTitle::VecWIel::SREFX2REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAMRelationTitle::VecWIel::TITLE;
	};
};

void IexWznmDbs::ImeitemIAMRelationTitle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVAMRelationTitleType::getSref(x1IxVType) << "\t" << srefX2RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmDbs::ImeitemIAMRelationTitle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","loc","tit"};
	else tags = {"ImeitemIAMRelationTitle","srefX1IxVType","srefX2RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVAMRelationTitleType::getSref(x1IxVType));
		writeString(wr, tags[2], srefX2RefWznmMLocale);
		writeString(wr, tags[3], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIAMRelationTitle::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIAMRelationTitle::VecWIel::getIx(
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

void IexWznmDbs::ImeIAMRelationTitle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIAMRelationTitle::VecWIel::getSrefs(
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
 class IexWznmDbs::ImeIAMRelationTitle
 ******************************************************************************/

IexWznmDbs::ImeIAMRelationTitle::ImeIAMRelationTitle() {
};

IexWznmDbs::ImeIAMRelationTitle::~ImeIAMRelationTitle() {
	clear();
};

void IexWznmDbs::ImeIAMRelationTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIAMRelationTitle::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIAMRelationTitle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmDbs::ImeitemIAMRelationTitle();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMRelationTitle"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMRelationTitle"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMRELATIONTITLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMRelationTitle"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMRelationTitle"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIAMRelationTitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIAMRelationTitle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMRelationTitle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMRelationTitle", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMRelationTitle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIAMRelationTitle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIAMRelationTitle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMRelationTitle." << StrMod::replaceChar(ImeIAMRelationTitle::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMRelationTitle.end" << endl;
	};
};

void IexWznmDbs::ImeIAMRelationTitle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMRelationTitle");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIMRelation
 ******************************************************************************/

IexWznmDbs::ImeitemIMRelation::ImeitemIMRelation(
			const ubigint iref
			, const uint ixVBasetype
			, const ubigint irefRefWznmCRelation
			, const ubigint irefSupRefWznmMRelation
			, const uint supIxVSubrole
			, const string& srefFrRefWznmMTable
			, const string& srefFrsRefWznmMSubset
			, const string& srefToRefWznmMTable
			, const string& srefTosRefWznmMSubset
			, const string& srefRefWznmMTable
			, const string& Prefix
			, const string& srefsKOption
		) : WznmMRelation() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->ixVBasetype = ixVBasetype;
	this->irefRefWznmCRelation = irefRefWznmCRelation;
	this->irefSupRefWznmMRelation = irefSupRefWznmMRelation;
	this->supIxVSubrole = supIxVSubrole;
	this->srefFrRefWznmMTable = srefFrRefWznmMTable;
	this->srefFrsRefWznmMSubset = srefFrsRefWznmMSubset;
	this->srefToRefWznmMTable = srefToRefWznmMTable;
	this->srefTosRefWznmMSubset = srefTosRefWznmMSubset;
	this->srefRefWznmMTable = srefRefWznmMTable;
	this->Prefix = Prefix;
	this->srefsKOption = srefsKOption;
};

IexWznmDbs::ImeitemIMRelation::ImeitemIMRelation(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMRelation()
		{
	WznmMRelation* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmrelation->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmCRelation = rec->refWznmCRelation;
		refWznmMVersion = rec->refWznmMVersion;
		supRefWznmMRelation = rec->supRefWznmMRelation;
		supIxVSubrole = rec->supIxVSubrole;
		frRefWznmMTable = rec->frRefWznmMTable;
		frsRefWznmMSubset = rec->frsRefWznmMSubset;
		toRefWznmMTable = rec->toRefWznmMTable;
		tosRefWznmMSubset = rec->tosRefWznmMSubset;
		refWznmMTable = rec->refWznmMTable;
		Prefix = rec->Prefix;
		srefsKOption = rec->srefsKOption;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIMRelation::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMRelation::VecWIel::IREF;};
	if (txtrd.fields.size() > 1) {srefIxVBasetype = txtrd.fields[1]; ixWIelValid += ImeIMRelation::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 2) {irefRefWznmCRelation = atoll(txtrd.fields[2].c_str()); ixWIelValid += ImeIMRelation::VecWIel::IREFREFWZNMCRELATION;};
	if (txtrd.fields.size() > 3) {irefSupRefWznmMRelation = atoll(txtrd.fields[3].c_str()); ixWIelValid += ImeIMRelation::VecWIel::IREFSUPREFWZNMMRELATION;};
	if (txtrd.fields.size() > 4) {srefSupIxVSubrole = txtrd.fields[4]; ixWIelValid += ImeIMRelation::VecWIel::SREFSUPIXVSUBROLE;};
	if (txtrd.fields.size() > 5) {srefFrRefWznmMTable = txtrd.fields[5]; ixWIelValid += ImeIMRelation::VecWIel::SREFFRREFWZNMMTABLE;};
	if (txtrd.fields.size() > 6) {srefFrsRefWznmMSubset = txtrd.fields[6]; ixWIelValid += ImeIMRelation::VecWIel::SREFFRSREFWZNMMSUBSET;};
	if (txtrd.fields.size() > 7) {srefToRefWznmMTable = txtrd.fields[7]; ixWIelValid += ImeIMRelation::VecWIel::SREFTOREFWZNMMTABLE;};
	if (txtrd.fields.size() > 8) {srefTosRefWznmMSubset = txtrd.fields[8]; ixWIelValid += ImeIMRelation::VecWIel::SREFTOSREFWZNMMSUBSET;};
	if (txtrd.fields.size() > 9) {srefRefWznmMTable = txtrd.fields[9]; ixWIelValid += ImeIMRelation::VecWIel::SREFREFWZNMMTABLE;};
	if (txtrd.fields.size() > 10) {Prefix = txtrd.fields[10]; ixWIelValid += ImeIMRelation::VecWIel::PREFIX;};
	if (txtrd.fields.size() > 11) {srefsKOption = txtrd.fields[11]; ixWIelValid += ImeIMRelation::VecWIel::SREFSKOPTION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMRELATIONTITLE)) {
					imeiamrelationtitle.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRelation"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIMRelation::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMRelation::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMRelation::VecWIel::SREFIXVBASETYPE;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmCRelation", "clu", irefRefWznmCRelation)) ixWIelValid += ImeIMRelation::VecWIel::IREFREFWZNMCRELATION;
		if (extractUbigintUclc(docctx, basexpath, "irefSupRefWznmMRelation", "sup", irefSupRefWznmMRelation)) ixWIelValid += ImeIMRelation::VecWIel::IREFSUPREFWZNMMRELATION;
		if (extractStringUclc(docctx, basexpath, "srefSupIxVSubrole", "srl", srefSupIxVSubrole)) ixWIelValid += ImeIMRelation::VecWIel::SREFSUPIXVSUBROLE;
		if (extractStringUclc(docctx, basexpath, "srefFrRefWznmMTable", "frt", srefFrRefWznmMTable)) ixWIelValid += ImeIMRelation::VecWIel::SREFFRREFWZNMMTABLE;
		if (extractStringUclc(docctx, basexpath, "srefFrsRefWznmMSubset", "frs", srefFrsRefWznmMSubset)) ixWIelValid += ImeIMRelation::VecWIel::SREFFRSREFWZNMMSUBSET;
		if (extractStringUclc(docctx, basexpath, "srefToRefWznmMTable", "tot", srefToRefWznmMTable)) ixWIelValid += ImeIMRelation::VecWIel::SREFTOREFWZNMMTABLE;
		if (extractStringUclc(docctx, basexpath, "srefTosRefWznmMSubset", "tos", srefTosRefWznmMSubset)) ixWIelValid += ImeIMRelation::VecWIel::SREFTOSREFWZNMMSUBSET;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMTable", "tbl", srefRefWznmMTable)) ixWIelValid += ImeIMRelation::VecWIel::SREFREFWZNMMTABLE;
		if (extractStringUclc(docctx, basexpath, "Prefix", "pfx", Prefix)) ixWIelValid += ImeIMRelation::VecWIel::PREFIX;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMRelation::VecWIel::SREFSKOPTION;
		imeiamrelationtitle.readXML(docctx, basexpath);
	};
};

void IexWznmDbs::ImeitemIMRelation::writeTxt(
			fstream& outfile
		) {
	outfile << iref << "\t" << VecWznmVMRelationBasetype::getSref(ixVBasetype) << "\t" << irefRefWznmCRelation << "\t" << irefSupRefWznmMRelation << "\t" << VecWznmVMRelationSupSubrole::getSref(supIxVSubrole) << "\t" << srefFrRefWznmMTable << "\t" << srefFrsRefWznmMSubset << "\t" << srefToRefWznmMTable << "\t" << srefTosRefWznmMSubset << "\t" << srefRefWznmMTable << "\t" << Prefix << "\t" << srefsKOption << endl;
	imeiamrelationtitle.writeTxt(outfile);
};

void IexWznmDbs::ImeitemIMRelation::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","typ","clu","sup","srl","frt","frs","tot","tos","tbl","pfx","opt"};
	else tags = {"ImeitemIMRelation","iref","srefIxVBasetype","irefRefWznmCRelation","irefSupRefWznmMRelation","srefSupIxVSubrole","srefFrRefWznmMTable","srefFrsRefWznmMSubset","srefToRefWznmMTable","srefTosRefWznmMSubset","srefRefWznmMTable","Prefix","srefsKOption"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeString(wr, tags[2], VecWznmVMRelationBasetype::getSref(ixVBasetype));
		writeUbigint(wr, tags[3], irefRefWznmCRelation);
		writeUbigint(wr, tags[4], irefSupRefWznmMRelation);
		writeString(wr, tags[5], VecWznmVMRelationSupSubrole::getSref(supIxVSubrole));
		writeString(wr, tags[6], srefFrRefWznmMTable);
		writeString(wr, tags[7], srefFrsRefWznmMSubset);
		writeString(wr, tags[8], srefToRefWznmMTable);
		writeString(wr, tags[9], srefTosRefWznmMSubset);
		writeString(wr, tags[10], srefRefWznmMTable);
		writeString(wr, tags[11], Prefix);
		writeString(wr, tags[12], srefsKOption);
		imeiamrelationtitle.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIMRelation::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIMRelation::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "irefrefwznmcrelation") ix |= IREFREFWZNMCRELATION;
		else if (ss[i] == "irefsuprefwznmmrelation") ix |= IREFSUPREFWZNMMRELATION;
		else if (ss[i] == "srefsupixvsubrole") ix |= SREFSUPIXVSUBROLE;
		else if (ss[i] == "sreffrrefwznmmtable") ix |= SREFFRREFWZNMMTABLE;
		else if (ss[i] == "sreffrsrefwznmmsubset") ix |= SREFFRSREFWZNMMSUBSET;
		else if (ss[i] == "sreftorefwznmmtable") ix |= SREFTOREFWZNMMTABLE;
		else if (ss[i] == "sreftosrefwznmmsubset") ix |= SREFTOSREFWZNMMSUBSET;
		else if (ss[i] == "srefrefwznmmtable") ix |= SREFREFWZNMMTABLE;
		else if (ss[i] == "prefix") ix |= PREFIX;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
	};

	return(ix);
};

void IexWznmDbs::ImeIMRelation::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIMRelation::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & IREFREFWZNMCRELATION) ss.push_back("irefRefWznmCRelation");
	if (ix & IREFSUPREFWZNMMRELATION) ss.push_back("irefSupRefWznmMRelation");
	if (ix & SREFSUPIXVSUBROLE) ss.push_back("srefSupIxVSubrole");
	if (ix & SREFFRREFWZNMMTABLE) ss.push_back("srefFrRefWznmMTable");
	if (ix & SREFFRSREFWZNMMSUBSET) ss.push_back("srefFrsRefWznmMSubset");
	if (ix & SREFTOREFWZNMMTABLE) ss.push_back("srefToRefWznmMTable");
	if (ix & SREFTOSREFWZNMMSUBSET) ss.push_back("srefTosRefWznmMSubset");
	if (ix & SREFREFWZNMMTABLE) ss.push_back("srefRefWznmMTable");
	if (ix & PREFIX) ss.push_back("Prefix");
	if (ix & SREFSKOPTION) ss.push_back("srefsKOption");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeIMRelation
 ******************************************************************************/

IexWznmDbs::ImeIMRelation::ImeIMRelation() {
};

IexWznmDbs::ImeIMRelation::~ImeIMRelation() {
	clear();
};

void IexWznmDbs::ImeIMRelation::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIMRelation::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIMRelation* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmDbs::ImeitemIMRelation();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRelation"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMRELATION) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRelation"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRelation"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIMRelation::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIMRelation* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMRelation");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMRelation", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMRelation";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIMRelation();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIMRelation::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMRelation." << StrMod::replaceChar(ImeIMRelation::VecWIel::getSrefs(4095), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMRelation.end" << endl;
	};
};

void IexWznmDbs::ImeIMRelation::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMRelation");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIMStub
 ******************************************************************************/

IexWznmDbs::ImeitemIMStub::ImeitemIMStub(
			const uint ixVBasetype
			, const string& srefRefWznmMTable
			, const string& srefRefWznmMSubset
			, const string& sref
			, const bool Hierarch
			, const string& srefRefWznmMTablecol
			, const bool Localized
			, const string& Example
		) : WznmMStub() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->srefRefWznmMTable = srefRefWznmMTable;
	this->srefRefWznmMSubset = srefRefWznmMSubset;
	this->sref = sref;
	this->Hierarch = Hierarch;
	this->srefRefWznmMTablecol = srefRefWznmMTablecol;
	this->Localized = Localized;
	this->Example = Example;
};

IexWznmDbs::ImeitemIMStub::ImeitemIMStub(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMStub()
		{
	WznmMStub* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmstub->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMTable = rec->refWznmMTable;
		refWznmMSubset = rec->refWznmMSubset;
		sref = rec->sref;
		Hierarch = rec->Hierarch;
		refWznmMTablecol = rec->refWznmMTablecol;
		Localized = rec->Localized;
		Example = rec->Example;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIMStub::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMStub::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {srefRefWznmMTable = txtrd.fields[1]; ixWIelValid += ImeIMStub::VecWIel::SREFREFWZNMMTABLE;};
	if (txtrd.fields.size() > 2) {srefRefWznmMSubset = txtrd.fields[2]; ixWIelValid += ImeIMStub::VecWIel::SREFREFWZNMMSUBSET;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIMStub::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {Hierarch = (txtrd.fields[4] == "true"); ixWIelValid += ImeIMStub::VecWIel::HIERARCH;};
	if (txtrd.fields.size() > 5) {srefRefWznmMTablecol = txtrd.fields[5]; ixWIelValid += ImeIMStub::VecWIel::SREFREFWZNMMTABLECOL;};
	if (txtrd.fields.size() > 6) {Localized = (txtrd.fields[6] == "true"); ixWIelValid += ImeIMStub::VecWIel::LOCALIZED;};
	if (txtrd.fields.size() > 7) {Example = txtrd.fields[7]; ixWIelValid += ImeIMStub::VecWIel::EXAMPLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMStub"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIMStub::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMStub::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMTable", "tbl", srefRefWznmMTable)) ixWIelValid += ImeIMStub::VecWIel::SREFREFWZNMMTABLE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMSubset", "sbs", srefRefWznmMSubset)) ixWIelValid += ImeIMStub::VecWIel::SREFREFWZNMMSUBSET;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMStub::VecWIel::SREF;
		if (extractBoolUclc(docctx, basexpath, "Hierarch", "hrc", Hierarch)) ixWIelValid += ImeIMStub::VecWIel::HIERARCH;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMTablecol", "tco", srefRefWznmMTablecol)) ixWIelValid += ImeIMStub::VecWIel::SREFREFWZNMMTABLECOL;
		if (extractBoolUclc(docctx, basexpath, "Localized", "lcl", Localized)) ixWIelValid += ImeIMStub::VecWIel::LOCALIZED;
		if (extractStringUclc(docctx, basexpath, "Example", "exa", Example)) ixWIelValid += ImeIMStub::VecWIel::EXAMPLE;
	};
};

void IexWznmDbs::ImeitemIMStub::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmVMStubBasetype::getSref(ixVBasetype) << "\t" << srefRefWznmMTable << "\t" << srefRefWznmMSubset << "\t" << sref << "\t" << StrMod::boolToString(Hierarch) << "\t" << srefRefWznmMTablecol << "\t" << StrMod::boolToString(Localized) << "\t" << Example << endl;
};

void IexWznmDbs::ImeitemIMStub::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","tbl","sbs","srf","hrc","tco","lcl","exa"};
	else tags = {"ImeitemIMStub","srefIxVBasetype","srefRefWznmMTable","srefRefWznmMSubset","sref","Hierarch","srefRefWznmMTablecol","Localized","Example"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMStubBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], srefRefWznmMTable);
		writeString(wr, tags[3], srefRefWznmMSubset);
		writeString(wr, tags[4], sref);
		writeBool(wr, tags[5], Hierarch);
		writeString(wr, tags[6], srefRefWznmMTablecol);
		writeBool(wr, tags[7], Localized);
		writeString(wr, tags[8], Example);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIMStub::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIMStub::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefrefwznmmtable") ix |= SREFREFWZNMMTABLE;
		else if (ss[i] == "srefrefwznmmsubset") ix |= SREFREFWZNMMSUBSET;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "hierarch") ix |= HIERARCH;
		else if (ss[i] == "srefrefwznmmtablecol") ix |= SREFREFWZNMMTABLECOL;
		else if (ss[i] == "localized") ix |= LOCALIZED;
		else if (ss[i] == "example") ix |= EXAMPLE;
	};

	return(ix);
};

void IexWznmDbs::ImeIMStub::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*EXAMPLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIMStub::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFREFWZNMMTABLE) ss.push_back("srefRefWznmMTable");
	if (ix & SREFREFWZNMMSUBSET) ss.push_back("srefRefWznmMSubset");
	if (ix & SREF) ss.push_back("sref");
	if (ix & HIERARCH) ss.push_back("Hierarch");
	if (ix & SREFREFWZNMMTABLECOL) ss.push_back("srefRefWznmMTablecol");
	if (ix & LOCALIZED) ss.push_back("Localized");
	if (ix & EXAMPLE) ss.push_back("Example");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeIMStub
 ******************************************************************************/

IexWznmDbs::ImeIMStub::ImeIMStub() {
};

IexWznmDbs::ImeIMStub::~ImeIMStub() {
	clear();
};

void IexWznmDbs::ImeIMStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIMStub::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIMStub* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmDbs::ImeitemIMStub();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMStub"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSTUB) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMStub"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMStub"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIMStub::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIMStub* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMStub");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMStub", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMStub";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIMStub();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIMStub::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMStub." << StrMod::replaceChar(ImeIMStub::VecWIel::getSrefs(255), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMStub.end" << endl;
	};
};

void IexWznmDbs::ImeIMStub::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMStub");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIAMTableLoadfct
 ******************************************************************************/

IexWznmDbs::ImeitemIAMTableLoadfct::ImeitemIAMTableLoadfct(
			const uint ixVLoadtype
			, const string& Fctname
			, const string& ldSrefWznmMTablecol
			, const string& lbySrefsWznmMTablecol
			, const string& ordSrefsWznmMTablecol
			, const uint ixVLimtype
		) : WznmAMTableLoadfct() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVLoadtype = ixVLoadtype;
	this->Fctname = Fctname;
	this->ldSrefWznmMTablecol = ldSrefWznmMTablecol;
	this->lbySrefsWznmMTablecol = lbySrefsWznmMTablecol;
	this->ordSrefsWznmMTablecol = ordSrefsWznmMTablecol;
	this->ixVLimtype = ixVLimtype;
};

IexWznmDbs::ImeitemIAMTableLoadfct::ImeitemIAMTableLoadfct(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMTableLoadfct()
		{
	WznmAMTableLoadfct* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamtableloadfct->loadRecByRef(ref, &rec)) {
		refWznmMTable = rec->refWznmMTable;
		ixVLoadtype = rec->ixVLoadtype;
		Fctname = rec->Fctname;
		ldSrefWznmMTablecol = rec->ldSrefWznmMTablecol;
		lbySrefsWznmMTablecol = rec->lbySrefsWznmMTablecol;
		ordSrefsWznmMTablecol = rec->ordSrefsWznmMTablecol;
		ixVLimtype = rec->ixVLimtype;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIAMTableLoadfct::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVLoadtype = txtrd.fields[0]; ixWIelValid += ImeIAMTableLoadfct::VecWIel::SREFIXVLOADTYPE;};
	if (txtrd.fields.size() > 1) {Fctname = txtrd.fields[1]; ixWIelValid += ImeIAMTableLoadfct::VecWIel::FCTNAME;};
	if (txtrd.fields.size() > 2) {ldSrefWznmMTablecol = txtrd.fields[2]; ixWIelValid += ImeIAMTableLoadfct::VecWIel::LDSREFWZNMMTABLECOL;};
	if (txtrd.fields.size() > 3) {lbySrefsWznmMTablecol = txtrd.fields[3]; ixWIelValid += ImeIAMTableLoadfct::VecWIel::LBYSREFSWZNMMTABLECOL;};
	if (txtrd.fields.size() > 4) {ordSrefsWznmMTablecol = txtrd.fields[4]; ixWIelValid += ImeIAMTableLoadfct::VecWIel::ORDSREFSWZNMMTABLECOL;};
	if (txtrd.fields.size() > 5) {srefIxVLimtype = txtrd.fields[5]; ixWIelValid += ImeIAMTableLoadfct::VecWIel::SREFIXVLIMTYPE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMTableLoadfct"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIAMTableLoadfct::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVLoadtype", "lot", srefIxVLoadtype)) ixWIelValid += ImeIAMTableLoadfct::VecWIel::SREFIXVLOADTYPE;
		if (extractStringUclc(docctx, basexpath, "Fctname", "fna", Fctname)) ixWIelValid += ImeIAMTableLoadfct::VecWIel::FCTNAME;
		if (extractStringUclc(docctx, basexpath, "ldSrefWznmMTablecol", "ldx", ldSrefWznmMTablecol)) ixWIelValid += ImeIAMTableLoadfct::VecWIel::LDSREFWZNMMTABLECOL;
		if (extractStringUclc(docctx, basexpath, "lbySrefsWznmMTablecol", "lby", lbySrefsWznmMTablecol)) ixWIelValid += ImeIAMTableLoadfct::VecWIel::LBYSREFSWZNMMTABLECOL;
		if (extractStringUclc(docctx, basexpath, "ordSrefsWznmMTablecol", "ord", ordSrefsWznmMTablecol)) ixWIelValid += ImeIAMTableLoadfct::VecWIel::ORDSREFSWZNMMTABLECOL;
		if (extractStringUclc(docctx, basexpath, "srefIxVLimtype", "lit", srefIxVLimtype)) ixWIelValid += ImeIAMTableLoadfct::VecWIel::SREFIXVLIMTYPE;
	};
};

void IexWznmDbs::ImeitemIAMTableLoadfct::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVAMTableLoadfctLoadtype::getSref(ixVLoadtype) << "\t" << Fctname << "\t" << ldSrefWznmMTablecol << "\t" << lbySrefsWznmMTablecol << "\t" << ordSrefsWznmMTablecol << "\t" << VecWznmVAMTableLoadfctLimtype::getSref(ixVLimtype) << endl;
};

void IexWznmDbs::ImeitemIAMTableLoadfct::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lot","fna","ldx","lby","ord","lit"};
	else tags = {"ImeitemIAMTableLoadfct","srefIxVLoadtype","Fctname","ldSrefWznmMTablecol","lbySrefsWznmMTablecol","ordSrefsWznmMTablecol","srefIxVLimtype"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVAMTableLoadfctLoadtype::getSref(ixVLoadtype));
		writeString(wr, tags[2], Fctname);
		writeString(wr, tags[3], ldSrefWznmMTablecol);
		writeString(wr, tags[4], lbySrefsWznmMTablecol);
		writeString(wr, tags[5], ordSrefsWznmMTablecol);
		writeString(wr, tags[6], VecWznmVAMTableLoadfctLimtype::getSref(ixVLimtype));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIAMTableLoadfct::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIAMTableLoadfct::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvloadtype") ix |= SREFIXVLOADTYPE;
		else if (ss[i] == "fctname") ix |= FCTNAME;
		else if (ss[i] == "ldsrefwznmmtablecol") ix |= LDSREFWZNMMTABLECOL;
		else if (ss[i] == "lbysrefswznmmtablecol") ix |= LBYSREFSWZNMMTABLECOL;
		else if (ss[i] == "ordsrefswznmmtablecol") ix |= ORDSREFSWZNMMTABLECOL;
		else if (ss[i] == "srefixvlimtype") ix |= SREFIXVLIMTYPE;
	};

	return(ix);
};

void IexWznmDbs::ImeIAMTableLoadfct::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVLIMTYPE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIAMTableLoadfct::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVLOADTYPE) ss.push_back("srefIxVLoadtype");
	if (ix & FCTNAME) ss.push_back("Fctname");
	if (ix & LDSREFWZNMMTABLECOL) ss.push_back("ldSrefWznmMTablecol");
	if (ix & LBYSREFSWZNMMTABLECOL) ss.push_back("lbySrefsWznmMTablecol");
	if (ix & ORDSREFSWZNMMTABLECOL) ss.push_back("ordSrefsWznmMTablecol");
	if (ix & SREFIXVLIMTYPE) ss.push_back("srefIxVLimtype");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeIAMTableLoadfct
 ******************************************************************************/

IexWznmDbs::ImeIAMTableLoadfct::ImeIAMTableLoadfct() {
};

IexWznmDbs::ImeIAMTableLoadfct::~ImeIAMTableLoadfct() {
	clear();
};

void IexWznmDbs::ImeIAMTableLoadfct::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIAMTableLoadfct::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIAMTableLoadfct* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmDbs::ImeitemIAMTableLoadfct();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMTableLoadfct"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMTableLoadfct"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMTABLELOADFCT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMTableLoadfct"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMTableLoadfct"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIAMTableLoadfct::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIAMTableLoadfct* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMTableLoadfct");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMTableLoadfct", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMTableLoadfct";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIAMTableLoadfct();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIAMTableLoadfct::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMTableLoadfct." << StrMod::replaceChar(ImeIAMTableLoadfct::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMTableLoadfct.end" << endl;
	};
};

void IexWznmDbs::ImeIAMTableLoadfct::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMTableLoadfct");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIAMTableTitle
 ******************************************************************************/

IexWznmDbs::ImeitemIAMTableTitle::ImeitemIAMTableTitle(
			const uint x1IxVType
			, const string& srefX2RefWznmMLocale
			, const uint ixWznmVGender
			, const string& Title
		) : WznmAMTableTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxVType = x1IxVType;
	this->srefX2RefWznmMLocale = srefX2RefWznmMLocale;
	this->ixWznmVGender = ixWznmVGender;
	this->Title = Title;
};

IexWznmDbs::ImeitemIAMTableTitle::ImeitemIAMTableTitle(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMTableTitle()
		{
	WznmAMTableTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamtabletitle->loadRecByRef(ref, &rec)) {
		refWznmMTable = rec->refWznmMTable;
		x1IxVType = rec->x1IxVType;
		x2RefWznmMLocale = rec->x2RefWznmMLocale;
		ixWznmVGender = rec->ixWznmVGender;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIAMTableTitle::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxVType = txtrd.fields[0]; ixWIelValid += ImeIAMTableTitle::VecWIel::SREFX1IXVTYPE;};
	if (txtrd.fields.size() > 1) {srefX2RefWznmMLocale = txtrd.fields[1]; ixWIelValid += ImeIAMTableTitle::VecWIel::SREFX2REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 2) {srefIxWznmVGender = txtrd.fields[2]; ixWIelValid += ImeIAMTableTitle::VecWIel::SREFIXWZNMVGENDER;};
	if (txtrd.fields.size() > 3) {Title = txtrd.fields[3]; ixWIelValid += ImeIAMTableTitle::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMTableTitle"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIAMTableTitle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxVType", "typ", srefX1IxVType)) ixWIelValid += ImeIAMTableTitle::VecWIel::SREFX1IXVTYPE;
		if (extractStringUclc(docctx, basexpath, "srefX2RefWznmMLocale", "loc", srefX2RefWznmMLocale)) ixWIelValid += ImeIAMTableTitle::VecWIel::SREFX2REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVGender", "gnd", srefIxWznmVGender)) ixWIelValid += ImeIAMTableTitle::VecWIel::SREFIXWZNMVGENDER;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAMTableTitle::VecWIel::TITLE;
	};
};

void IexWznmDbs::ImeitemIAMTableTitle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVAMTableTitleType::getSref(x1IxVType) << "\t" << srefX2RefWznmMLocale << "\t" << VecWznmVGender::getSref(ixWznmVGender) << "\t" << Title << endl;
};

void IexWznmDbs::ImeitemIAMTableTitle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","loc","gnd","tit"};
	else tags = {"ImeitemIAMTableTitle","srefX1IxVType","srefX2RefWznmMLocale","srefIxWznmVGender","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVAMTableTitleType::getSref(x1IxVType));
		writeString(wr, tags[2], srefX2RefWznmMLocale);
		writeString(wr, tags[3], VecWznmVGender::getSref(ixWznmVGender));
		writeString(wr, tags[4], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIAMTableTitle::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIAMTableTitle::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixvtype") ix |= SREFX1IXVTYPE;
		else if (ss[i] == "srefx2refwznmmlocale") ix |= SREFX2REFWZNMMLOCALE;
		else if (ss[i] == "srefixwznmvgender") ix |= SREFIXWZNMVGENDER;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmDbs::ImeIAMTableTitle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIAMTableTitle::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXVTYPE) ss.push_back("srefX1IxVType");
	if (ix & SREFX2REFWZNMMLOCALE) ss.push_back("srefX2RefWznmMLocale");
	if (ix & SREFIXWZNMVGENDER) ss.push_back("srefIxWznmVGender");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeIAMTableTitle
 ******************************************************************************/

IexWznmDbs::ImeIAMTableTitle::ImeIAMTableTitle() {
};

IexWznmDbs::ImeIAMTableTitle::~ImeIAMTableTitle() {
	clear();
};

void IexWznmDbs::ImeIAMTableTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIAMTableTitle::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIAMTableTitle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmDbs::ImeitemIAMTableTitle();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMTableTitle"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMTableTitle"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMTABLETITLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMTableTitle"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMTableTitle"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIAMTableTitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIAMTableTitle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMTableTitle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMTableTitle", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMTableTitle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIAMTableTitle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIAMTableTitle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMTableTitle." << StrMod::replaceChar(ImeIAMTableTitle::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMTableTitle.end" << endl;
	};
};

void IexWznmDbs::ImeIAMTableTitle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMTableTitle");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIMCheck
 ******************************************************************************/

IexWznmDbs::ImeitemIMCheck::ImeitemIMCheck(
			const uint ixVBasetype
			, const string& srefRefWznmMTablecol
			, const string& sref
			, const string& Comment
		) : WznmMCheck() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->srefRefWznmMTablecol = srefRefWznmMTablecol;
	this->sref = sref;
	this->Comment = Comment;
};

IexWznmDbs::ImeitemIMCheck::ImeitemIMCheck(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMCheck()
		{
	WznmMCheck* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmcheck->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMTable = rec->refWznmMTable;
		refWznmMTablecol = rec->refWznmMTablecol;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIMCheck::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMCheck::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {srefRefWznmMTablecol = txtrd.fields[1]; ixWIelValid += ImeIMCheck::VecWIel::SREFREFWZNMMTABLECOL;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMCheck::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMCheck::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCheck"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIMCheck::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMCheck::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMTablecol", "tco", srefRefWznmMTablecol)) ixWIelValid += ImeIMCheck::VecWIel::SREFREFWZNMMTABLECOL;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCheck::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMCheck::VecWIel::COMMENT;
	};
};

void IexWznmDbs::ImeitemIMCheck::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVMCheckBasetype::getSref(ixVBasetype) << "\t" << srefRefWznmMTablecol << "\t" << sref << "\t" << Comment << endl;
};

void IexWznmDbs::ImeitemIMCheck::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","tco","srf","cmt"};
	else tags = {"ImeitemIMCheck","srefIxVBasetype","srefRefWznmMTablecol","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMCheckBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], srefRefWznmMTablecol);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIMCheck::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIMCheck::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefrefwznmmtablecol") ix |= SREFREFWZNMMTABLECOL;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmDbs::ImeIMCheck::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIMCheck::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFREFWZNMMTABLECOL) ss.push_back("srefRefWznmMTablecol");
	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeIMCheck
 ******************************************************************************/

IexWznmDbs::ImeIMCheck::ImeIMCheck() {
};

IexWznmDbs::ImeIMCheck::~ImeIMCheck() {
	clear();
};

void IexWznmDbs::ImeIMCheck::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIMCheck::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIMCheck* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmDbs::ImeitemIMCheck();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCheck"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCheck"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCHECK) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCheck"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCheck"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIMCheck::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIMCheck* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMCheck");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMCheck", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMCheck";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIMCheck();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIMCheck::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMCheck." << StrMod::replaceChar(ImeIMCheck::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMCheck.end" << endl;
	};
};

void IexWznmDbs::ImeIMCheck::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMCheck");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIAMSubsetTitle
 ******************************************************************************/

IexWznmDbs::ImeitemIAMSubsetTitle::ImeitemIAMSubsetTitle(
			const uint x1IxVType
			, const string& srefX2RefWznmMLocale
			, const uint ixWznmVGender
			, const string& Title
		) : WznmAMSubsetTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxVType = x1IxVType;
	this->srefX2RefWznmMLocale = srefX2RefWznmMLocale;
	this->ixWznmVGender = ixWznmVGender;
	this->Title = Title;
};

IexWznmDbs::ImeitemIAMSubsetTitle::ImeitemIAMSubsetTitle(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMSubsetTitle()
		{
	WznmAMSubsetTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamsubsettitle->loadRecByRef(ref, &rec)) {
		refWznmMSubset = rec->refWznmMSubset;
		x1IxVType = rec->x1IxVType;
		x2RefWznmMLocale = rec->x2RefWznmMLocale;
		ixWznmVGender = rec->ixWznmVGender;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIAMSubsetTitle::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxVType = txtrd.fields[0]; ixWIelValid += ImeIAMSubsetTitle::VecWIel::SREFX1IXVTYPE;};
	if (txtrd.fields.size() > 1) {srefX2RefWznmMLocale = txtrd.fields[1]; ixWIelValid += ImeIAMSubsetTitle::VecWIel::SREFX2REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 2) {srefIxWznmVGender = txtrd.fields[2]; ixWIelValid += ImeIAMSubsetTitle::VecWIel::SREFIXWZNMVGENDER;};
	if (txtrd.fields.size() > 3) {Title = txtrd.fields[3]; ixWIelValid += ImeIAMSubsetTitle::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMSubsetTitle"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIAMSubsetTitle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxVType", "typ", srefX1IxVType)) ixWIelValid += ImeIAMSubsetTitle::VecWIel::SREFX1IXVTYPE;
		if (extractStringUclc(docctx, basexpath, "srefX2RefWznmMLocale", "loc", srefX2RefWznmMLocale)) ixWIelValid += ImeIAMSubsetTitle::VecWIel::SREFX2REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "srefIxWznmVGender", "gnd", srefIxWznmVGender)) ixWIelValid += ImeIAMSubsetTitle::VecWIel::SREFIXWZNMVGENDER;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAMSubsetTitle::VecWIel::TITLE;
	};
};

void IexWznmDbs::ImeitemIAMSubsetTitle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVAMSubsetTitleType::getSref(x1IxVType) << "\t" << srefX2RefWznmMLocale << "\t" << VecWznmVGender::getSref(ixWznmVGender) << "\t" << Title << endl;
};

void IexWznmDbs::ImeitemIAMSubsetTitle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","loc","gnd","tit"};
	else tags = {"ImeitemIAMSubsetTitle","srefX1IxVType","srefX2RefWznmMLocale","srefIxWznmVGender","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVAMSubsetTitleType::getSref(x1IxVType));
		writeString(wr, tags[2], srefX2RefWznmMLocale);
		writeString(wr, tags[3], VecWznmVGender::getSref(ixWznmVGender));
		writeString(wr, tags[4], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIAMSubsetTitle::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIAMSubsetTitle::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixvtype") ix |= SREFX1IXVTYPE;
		else if (ss[i] == "srefx2refwznmmlocale") ix |= SREFX2REFWZNMMLOCALE;
		else if (ss[i] == "srefixwznmvgender") ix |= SREFIXWZNMVGENDER;
		else if (ss[i] == "title") ix |= TITLE;
	};

	return(ix);
};

void IexWznmDbs::ImeIAMSubsetTitle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIAMSubsetTitle::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXVTYPE) ss.push_back("srefX1IxVType");
	if (ix & SREFX2REFWZNMMLOCALE) ss.push_back("srefX2RefWznmMLocale");
	if (ix & SREFIXWZNMVGENDER) ss.push_back("srefIxWznmVGender");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeIAMSubsetTitle
 ******************************************************************************/

IexWznmDbs::ImeIAMSubsetTitle::ImeIAMSubsetTitle() {
};

IexWznmDbs::ImeIAMSubsetTitle::~ImeIAMSubsetTitle() {
	clear();
};

void IexWznmDbs::ImeIAMSubsetTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIAMSubsetTitle::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIAMSubsetTitle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmDbs::ImeitemIAMSubsetTitle();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMSubsetTitle"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMSubsetTitle"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMSUBSETTITLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMSubsetTitle"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMSubsetTitle"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIAMSubsetTitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIAMSubsetTitle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMSubsetTitle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMSubsetTitle", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMSubsetTitle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIAMSubsetTitle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIAMSubsetTitle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMSubsetTitle." << StrMod::replaceChar(ImeIAMSubsetTitle::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMSubsetTitle.end" << endl;
	};
};

void IexWznmDbs::ImeIAMSubsetTitle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMSubsetTitle");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIRMSubsetMSubset
 ******************************************************************************/

IexWznmDbs::ImeitemIRMSubsetMSubset::ImeitemIRMSubsetMSubset(
			const string& srefBsbRefWznmMSubset
			, const uint ixVReltype
		) : WznmRMSubsetMSubset() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefBsbRefWznmMSubset = srefBsbRefWznmMSubset;
	this->ixVReltype = ixVReltype;
};

IexWznmDbs::ImeitemIRMSubsetMSubset::ImeitemIRMSubsetMSubset(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMSubsetMSubset()
		{
	WznmRMSubsetMSubset* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmsubsetmsubset->loadRecByRef(ref, &rec)) {
		asbRefWznmMSubset = rec->asbRefWznmMSubset;
		bsbRefWznmMSubset = rec->bsbRefWznmMSubset;
		ixVReltype = rec->ixVReltype;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIRMSubsetMSubset::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefBsbRefWznmMSubset = txtrd.fields[0]; ixWIelValid += ImeIRMSubsetMSubset::VecWIel::SREFBSBREFWZNMMSUBSET;};
	if (txtrd.fields.size() > 1) {srefIxVReltype = txtrd.fields[1]; ixWIelValid += ImeIRMSubsetMSubset::VecWIel::SREFIXVRELTYPE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMSubsetMSubset"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIRMSubsetMSubset::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefBsbRefWznmMSubset", "sbs", srefBsbRefWznmMSubset)) ixWIelValid += ImeIRMSubsetMSubset::VecWIel::SREFBSBREFWZNMMSUBSET;
		if (extractStringUclc(docctx, basexpath, "srefIxVReltype", "rty", srefIxVReltype)) ixWIelValid += ImeIRMSubsetMSubset::VecWIel::SREFIXVRELTYPE;
	};
};

void IexWznmDbs::ImeitemIRMSubsetMSubset::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefBsbRefWznmMSubset << "\t" << VecWznmVRMSubsetMSubsetReltype::getSref(ixVReltype) << endl;
};

void IexWznmDbs::ImeitemIRMSubsetMSubset::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sbs","rty"};
	else tags = {"ImeitemIRMSubsetMSubset","srefBsbRefWznmMSubset","srefIxVReltype"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefBsbRefWznmMSubset);
		writeString(wr, tags[2], VecWznmVRMSubsetMSubsetReltype::getSref(ixVReltype));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIRMSubsetMSubset::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIRMSubsetMSubset::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefbsbrefwznmmsubset") ix |= SREFBSBREFWZNMMSUBSET;
		else if (ss[i] == "srefixvreltype") ix |= SREFIXVRELTYPE;
	};

	return(ix);
};

void IexWznmDbs::ImeIRMSubsetMSubset::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVRELTYPE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIRMSubsetMSubset::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFBSBREFWZNMMSUBSET) ss.push_back("srefBsbRefWznmMSubset");
	if (ix & SREFIXVRELTYPE) ss.push_back("srefIxVReltype");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeIRMSubsetMSubset
 ******************************************************************************/

IexWznmDbs::ImeIRMSubsetMSubset::ImeIRMSubsetMSubset() {
};

IexWznmDbs::ImeIRMSubsetMSubset::~ImeIRMSubsetMSubset() {
	clear();
};

void IexWznmDbs::ImeIRMSubsetMSubset::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIRMSubsetMSubset::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIRMSubsetMSubset* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmDbs::ImeitemIRMSubsetMSubset();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMSubsetMSubset"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMSubsetMSubset"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMSUBSETMSUBSET) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMSubsetMSubset"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMSubsetMSubset"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIRMSubsetMSubset::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIRMSubsetMSubset* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMSubsetMSubset");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMSubsetMSubset", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMSubsetMSubset";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIRMSubsetMSubset();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIRMSubsetMSubset::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIRMSubsetMSubset." << StrMod::replaceChar(ImeIRMSubsetMSubset::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIRMSubsetMSubset.end" << endl;
	};
};

void IexWznmDbs::ImeIRMSubsetMSubset::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMSubsetMSubset");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIMSubset
 ******************************************************************************/

IexWznmDbs::ImeitemIMSubset::ImeitemIMSubset(
			const string& sref
			, const string& Short
			, const string& Cond
			, const string& Comment
		) : WznmMSubset() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Short = Short;
	this->Cond = Cond;
	this->Comment = Comment;
};

IexWznmDbs::ImeitemIMSubset::ImeitemIMSubset(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMSubset()
		{
	WznmMSubset* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmsubset->loadRecByRef(ref, &rec)) {
		refWznmMTable = rec->refWznmMTable;
		sref = rec->sref;
		Short = rec->Short;
		Cond = rec->Cond;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIMSubset::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMSubset::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Short = txtrd.fields[1]; ixWIelValid += ImeIMSubset::VecWIel::SHORT;};
	if (txtrd.fields.size() > 2) {Cond = txtrd.fields[2]; ixWIelValid += ImeIMSubset::VecWIel::COND;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMSubset::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMSUBSETTITLE)) {
					imeiamsubsettitle.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIRMSUBSETMSUBSET)) {
					imeirmsubsetmsubset.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSubset"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIMSubset::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMSubset::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Short", "sho", Short)) ixWIelValid += ImeIMSubset::VecWIel::SHORT;
		if (extractStringUclc(docctx, basexpath, "Cond", "cnd", Cond)) ixWIelValid += ImeIMSubset::VecWIel::COND;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMSubset::VecWIel::COMMENT;
		imeiamsubsettitle.readXML(docctx, basexpath);
		imeirmsubsetmsubset.readXML(docctx, basexpath);
	};
};

void IexWznmDbs::ImeitemIMSubset::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << Short << "\t" << Cond << "\t" << Comment << endl;
	imeiamsubsettitle.writeTxt(outfile);
	imeirmsubsetmsubset.writeTxt(outfile);
};

void IexWznmDbs::ImeitemIMSubset::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","sho","cnd","cmt"};
	else tags = {"ImeitemIMSubset","sref","Short","Cond","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Short);
		writeString(wr, tags[3], Cond);
		writeString(wr, tags[4], Comment);
		imeiamsubsettitle.writeXML(wr, shorttags);
		imeirmsubsetmsubset.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIMSubset::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIMSubset::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "short") ix |= SHORT;
		else if (ss[i] == "cond") ix |= COND;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmDbs::ImeIMSubset::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIMSubset::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SHORT) ss.push_back("Short");
	if (ix & COND) ss.push_back("Cond");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeIMSubset
 ******************************************************************************/

IexWznmDbs::ImeIMSubset::ImeIMSubset() {
};

IexWznmDbs::ImeIMSubset::~ImeIMSubset() {
	clear();
};

void IexWznmDbs::ImeIMSubset::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIMSubset::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIMSubset* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmDbs::ImeitemIMSubset();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSubset"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSubset"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSUBSET) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSubset"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSubset"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIMSubset::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIMSubset* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSubset");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSubset", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSubset";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIMSubset();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIMSubset::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMSubset." << StrMod::replaceChar(ImeIMSubset::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMSubset.end" << endl;
	};
};

void IexWznmDbs::ImeIMSubset::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSubset");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIAMTablecolTitle
 ******************************************************************************/

IexWznmDbs::ImeitemIAMTablecolTitle::ImeitemIAMTablecolTitle(
			const uint x1IxVType
			, const string& srefX2RefWznmMLocale
			, const string& Title
		) : WznmAMTablecolTitle() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxVType = x1IxVType;
	this->srefX2RefWznmMLocale = srefX2RefWznmMLocale;
	this->Title = Title;
};

IexWznmDbs::ImeitemIAMTablecolTitle::ImeitemIAMTablecolTitle(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMTablecolTitle()
		{
	WznmAMTablecolTitle* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmamtablecoltitle->loadRecByRef(ref, &rec)) {
		refWznmMTablecol = rec->refWznmMTablecol;
		x1IxVType = rec->x1IxVType;
		x2RefWznmMLocale = rec->x2RefWznmMLocale;
		Title = rec->Title;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIAMTablecolTitle::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxVType = txtrd.fields[0]; ixWIelValid += ImeIAMTablecolTitle::VecWIel::SREFX1IXVTYPE;};
	if (txtrd.fields.size() > 1) {srefX2RefWznmMLocale = txtrd.fields[1]; ixWIelValid += ImeIAMTablecolTitle::VecWIel::SREFX2REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIAMTablecolTitle::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMTablecolTitle"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIAMTablecolTitle::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxVType", "typ", srefX1IxVType)) ixWIelValid += ImeIAMTablecolTitle::VecWIel::SREFX1IXVTYPE;
		if (extractStringUclc(docctx, basexpath, "srefX2RefWznmMLocale", "loc", srefX2RefWznmMLocale)) ixWIelValid += ImeIAMTablecolTitle::VecWIel::SREFX2REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAMTablecolTitle::VecWIel::TITLE;
	};
};

void IexWznmDbs::ImeitemIAMTablecolTitle::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVAMTablecolTitleType::getSref(x1IxVType) << "\t" << srefX2RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmDbs::ImeitemIAMTablecolTitle::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","loc","tit"};
	else tags = {"ImeitemIAMTablecolTitle","srefX1IxVType","srefX2RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVAMTablecolTitleType::getSref(x1IxVType));
		writeString(wr, tags[2], srefX2RefWznmMLocale);
		writeString(wr, tags[3], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIAMTablecolTitle::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIAMTablecolTitle::VecWIel::getIx(
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

void IexWznmDbs::ImeIAMTablecolTitle::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIAMTablecolTitle::VecWIel::getSrefs(
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
 class IexWznmDbs::ImeIAMTablecolTitle
 ******************************************************************************/

IexWznmDbs::ImeIAMTablecolTitle::ImeIAMTablecolTitle() {
};

IexWznmDbs::ImeIAMTablecolTitle::~ImeIAMTablecolTitle() {
	clear();
};

void IexWznmDbs::ImeIAMTablecolTitle::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIAMTablecolTitle::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIAMTablecolTitle* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmDbs::ImeitemIAMTablecolTitle();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMTablecolTitle"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMTablecolTitle"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMTABLECOLTITLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMTablecolTitle"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMTablecolTitle"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIAMTablecolTitle::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIAMTablecolTitle* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMTablecolTitle");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMTablecolTitle", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMTablecolTitle";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIAMTablecolTitle();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIAMTablecolTitle::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMTablecolTitle." << StrMod::replaceChar(ImeIAMTablecolTitle::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMTablecolTitle.end" << endl;
	};
};

void IexWznmDbs::ImeIAMTablecolTitle::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMTablecolTitle");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIMTablecol
 ******************************************************************************/

IexWznmDbs::ImeitemIMTablecol::ImeitemIMTablecol(
			const uint ixVBasetype
			, const string& srefRefWznmMSubset
			, const ubigint irefRefWznmMRelation
			, const uint fctIxVTbl
			, const string& srefFctUref
			, const string& sref
			, const string& Short
			, const uint ixVSubtype
			, const uint ixVAxisfct
			, const string& srefsKOption
			, const bool Principal
			, const bool Eponymous
		) : WznmMTablecol() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->srefRefWznmMSubset = srefRefWznmMSubset;
	this->irefRefWznmMRelation = irefRefWznmMRelation;
	this->fctIxVTbl = fctIxVTbl;
	this->srefFctUref = srefFctUref;
	this->sref = sref;
	this->Short = Short;
	this->ixVSubtype = ixVSubtype;
	this->ixVAxisfct = ixVAxisfct;
	this->srefsKOption = srefsKOption;
	this->Principal = Principal;
	this->Eponymous = Eponymous;
};

IexWznmDbs::ImeitemIMTablecol::ImeitemIMTablecol(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMTablecol()
		{
	WznmMTablecol* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmtablecol->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		tblRefWznmMTable = rec->tblRefWznmMTable;
		tblNum = rec->tblNum;
		refWznmMSubset = rec->refWznmMSubset;
		refWznmMRelation = rec->refWznmMRelation;
		fctIxVTbl = rec->fctIxVTbl;
		fctUref = rec->fctUref;
		sref = rec->sref;
		Short = rec->Short;
		ixVSubtype = rec->ixVSubtype;
		ixVAxisfct = rec->ixVAxisfct;
		srefsKOption = rec->srefsKOption;
		Principal = rec->Principal;
		Eponymous = rec->Eponymous;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIMTablecol::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMTablecol::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {srefRefWznmMSubset = txtrd.fields[1]; ixWIelValid += ImeIMTablecol::VecWIel::SREFREFWZNMMSUBSET;};
	if (txtrd.fields.size() > 2) {irefRefWznmMRelation = atoll(txtrd.fields[2].c_str()); ixWIelValid += ImeIMTablecol::VecWIel::IREFREFWZNMMRELATION;};
	if (txtrd.fields.size() > 3) {srefFctIxVTbl = txtrd.fields[3]; ixWIelValid += ImeIMTablecol::VecWIel::SREFFCTIXVTBL;};
	if (txtrd.fields.size() > 4) {srefFctUref = txtrd.fields[4]; ixWIelValid += ImeIMTablecol::VecWIel::SREFFCTUREF;};
	if (txtrd.fields.size() > 5) {sref = txtrd.fields[5]; ixWIelValid += ImeIMTablecol::VecWIel::SREF;};
	if (txtrd.fields.size() > 6) {Short = txtrd.fields[6]; ixWIelValid += ImeIMTablecol::VecWIel::SHORT;};
	if (txtrd.fields.size() > 7) {srefIxVSubtype = txtrd.fields[7]; ixWIelValid += ImeIMTablecol::VecWIel::SREFIXVSUBTYPE;};
	if (txtrd.fields.size() > 8) {srefIxVAxisfct = txtrd.fields[8]; ixWIelValid += ImeIMTablecol::VecWIel::SREFIXVAXISFCT;};
	if (txtrd.fields.size() > 9) {srefsKOption = txtrd.fields[9]; ixWIelValid += ImeIMTablecol::VecWIel::SREFSKOPTION;};
	if (txtrd.fields.size() > 10) {Principal = (txtrd.fields[10] == "true"); ixWIelValid += ImeIMTablecol::VecWIel::PRINCIPAL;};
	if (txtrd.fields.size() > 11) {Eponymous = (txtrd.fields[11] == "true"); ixWIelValid += ImeIMTablecol::VecWIel::EPONYMOUS;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMTABLECOLTITLE)) {
					imeiamtablecoltitle.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMTablecol"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIMTablecol::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMTablecol::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMSubset", "sbs", srefRefWznmMSubset)) ixWIelValid += ImeIMTablecol::VecWIel::SREFREFWZNMMSUBSET;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWznmMRelation", "rel", irefRefWznmMRelation)) ixWIelValid += ImeIMTablecol::VecWIel::IREFREFWZNMMRELATION;
		if (extractStringUclc(docctx, basexpath, "srefFctIxVTbl", "fct", srefFctIxVTbl)) ixWIelValid += ImeIMTablecol::VecWIel::SREFFCTIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefFctUref", "fcu", srefFctUref)) ixWIelValid += ImeIMTablecol::VecWIel::SREFFCTUREF;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMTablecol::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Short", "sho", Short)) ixWIelValid += ImeIMTablecol::VecWIel::SHORT;
		if (extractStringUclc(docctx, basexpath, "srefIxVSubtype", "sty", srefIxVSubtype)) ixWIelValid += ImeIMTablecol::VecWIel::SREFIXVSUBTYPE;
		if (extractStringUclc(docctx, basexpath, "srefIxVAxisfct", "axf", srefIxVAxisfct)) ixWIelValid += ImeIMTablecol::VecWIel::SREFIXVAXISFCT;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMTablecol::VecWIel::SREFSKOPTION;
		if (extractBoolUclc(docctx, basexpath, "Principal", "pnc", Principal)) ixWIelValid += ImeIMTablecol::VecWIel::PRINCIPAL;
		if (extractBoolUclc(docctx, basexpath, "Eponymous", "epo", Eponymous)) ixWIelValid += ImeIMTablecol::VecWIel::EPONYMOUS;
		imeiamtablecoltitle.readXML(docctx, basexpath);
	};
};

void IexWznmDbs::ImeitemIMTablecol::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVMTablecolBasetype::getSref(ixVBasetype) << "\t" << srefRefWznmMSubset << "\t" << irefRefWznmMRelation << "\t" << VecWznmVMTablecolFctTbl::getSref(fctIxVTbl) << "\t" << srefFctUref << "\t" << sref << "\t" << Short << "\t" << VecWznmVMTablecolSubtype::getSref(ixVSubtype) << "\t" << VecWznmVMTablecolAxisfct::getSref(ixVAxisfct) << "\t" << srefsKOption << "\t" << StrMod::boolToString(Principal) << "\t" << StrMod::boolToString(Eponymous) << endl;
	imeiamtablecoltitle.writeTxt(outfile);
};

void IexWznmDbs::ImeitemIMTablecol::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","sbs","rel","fct","fcu","srf","sho","sty","axf","opt","pnc","epo"};
	else tags = {"ImeitemIMTablecol","srefIxVBasetype","srefRefWznmMSubset","irefRefWznmMRelation","srefFctIxVTbl","srefFctUref","sref","Short","srefIxVSubtype","srefIxVAxisfct","srefsKOption","Principal","Eponymous"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMTablecolBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], srefRefWznmMSubset);
		writeUbigint(wr, tags[3], irefRefWznmMRelation);
		writeString(wr, tags[4], VecWznmVMTablecolFctTbl::getSref(fctIxVTbl));
		writeString(wr, tags[5], srefFctUref);
		writeString(wr, tags[6], sref);
		writeString(wr, tags[7], Short);
		writeString(wr, tags[8], VecWznmVMTablecolSubtype::getSref(ixVSubtype));
		writeString(wr, tags[9], VecWznmVMTablecolAxisfct::getSref(ixVAxisfct));
		writeString(wr, tags[10], srefsKOption);
		writeBool(wr, tags[11], Principal);
		writeBool(wr, tags[12], Eponymous);
		imeiamtablecoltitle.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIMTablecol::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIMTablecol::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefrefwznmmsubset") ix |= SREFREFWZNMMSUBSET;
		else if (ss[i] == "irefrefwznmmrelation") ix |= IREFREFWZNMMRELATION;
		else if (ss[i] == "sreffctixvtbl") ix |= SREFFCTIXVTBL;
		else if (ss[i] == "sreffcturef") ix |= SREFFCTUREF;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "short") ix |= SHORT;
		else if (ss[i] == "srefixvsubtype") ix |= SREFIXVSUBTYPE;
		else if (ss[i] == "srefixvaxisfct") ix |= SREFIXVAXISFCT;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
		else if (ss[i] == "principal") ix |= PRINCIPAL;
		else if (ss[i] == "eponymous") ix |= EPONYMOUS;
	};

	return(ix);
};

void IexWznmDbs::ImeIMTablecol::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*EPONYMOUS); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIMTablecol::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFREFWZNMMSUBSET) ss.push_back("srefRefWznmMSubset");
	if (ix & IREFREFWZNMMRELATION) ss.push_back("irefRefWznmMRelation");
	if (ix & SREFFCTIXVTBL) ss.push_back("srefFctIxVTbl");
	if (ix & SREFFCTUREF) ss.push_back("srefFctUref");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SHORT) ss.push_back("Short");
	if (ix & SREFIXVSUBTYPE) ss.push_back("srefIxVSubtype");
	if (ix & SREFIXVAXISFCT) ss.push_back("srefIxVAxisfct");
	if (ix & SREFSKOPTION) ss.push_back("srefsKOption");
	if (ix & PRINCIPAL) ss.push_back("Principal");
	if (ix & EPONYMOUS) ss.push_back("Eponymous");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeIMTablecol
 ******************************************************************************/

IexWznmDbs::ImeIMTablecol::ImeIMTablecol() {
};

IexWznmDbs::ImeIMTablecol::~ImeIMTablecol() {
	clear();
};

void IexWznmDbs::ImeIMTablecol::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIMTablecol::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIMTablecol* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmDbs::ImeitemIMTablecol();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMTablecol"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMTablecol"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMTABLECOL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMTablecol"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMTablecol"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIMTablecol::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIMTablecol* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMTablecol");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMTablecol", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMTablecol";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIMTablecol();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIMTablecol::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMTablecol." << StrMod::replaceChar(ImeIMTablecol::VecWIel::getSrefs(4095), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMTablecol.end" << endl;
	};
};

void IexWznmDbs::ImeIMTablecol::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMTablecol");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIAMVectorTitle2
 ******************************************************************************/

IexWznmDbs::ImeitemIAMVectorTitle2::ImeitemIAMVectorTitle2(
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

IexWznmDbs::ImeitemIAMVectorTitle2::ImeitemIAMVectorTitle2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMVectorTitle2()
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

void IexWznmDbs::ImeitemIAMVectorTitle2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxVType = txtrd.fields[0]; ixWIelValid += ImeIAMVectorTitle2::VecWIel::SREFX1IXVTYPE;};
	if (txtrd.fields.size() > 1) {srefX2RefWznmMLocale = txtrd.fields[1]; ixWIelValid += ImeIAMVectorTitle2::VecWIel::SREFX2REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIAMVectorTitle2::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMVectorTitle2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIAMVectorTitle2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxVType", "typ", srefX1IxVType)) ixWIelValid += ImeIAMVectorTitle2::VecWIel::SREFX1IXVTYPE;
		if (extractStringUclc(docctx, basexpath, "srefX2RefWznmMLocale", "loc", srefX2RefWznmMLocale)) ixWIelValid += ImeIAMVectorTitle2::VecWIel::SREFX2REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAMVectorTitle2::VecWIel::TITLE;
	};
};

void IexWznmDbs::ImeitemIAMVectorTitle2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWznmVAMVectorTitleType::getSref(x1IxVType) << "\t" << srefX2RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmDbs::ImeitemIAMVectorTitle2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","loc","tit"};
	else tags = {"ImeitemIAMVectorTitle2","srefX1IxVType","srefX2RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVAMVectorTitleType::getSref(x1IxVType));
		writeString(wr, tags[2], srefX2RefWznmMLocale);
		writeString(wr, tags[3], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIAMVectorTitle2::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIAMVectorTitle2::VecWIel::getIx(
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

void IexWznmDbs::ImeIAMVectorTitle2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIAMVectorTitle2::VecWIel::getSrefs(
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
 class IexWznmDbs::ImeIAMVectorTitle2
 ******************************************************************************/

IexWznmDbs::ImeIAMVectorTitle2::ImeIAMVectorTitle2() {
};

IexWznmDbs::ImeIAMVectorTitle2::~ImeIAMVectorTitle2() {
	clear();
};

void IexWznmDbs::ImeIAMVectorTitle2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIAMVectorTitle2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIAMVectorTitle2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmDbs::ImeitemIAMVectorTitle2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMVectorTitle2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMVectorTitle2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMVECTORTITLE2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMVectorTitle2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMVectorTitle2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIAMVectorTitle2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIAMVectorTitle2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMVectorTitle2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMVectorTitle2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMVectorTitle2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIAMVectorTitle2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIAMVectorTitle2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMVectorTitle2." << StrMod::replaceChar(ImeIAMVectorTitle2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMVectorTitle2.end" << endl;
	};
};

void IexWznmDbs::ImeIAMVectorTitle2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMVectorTitle2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIJMVectoritem2
 ******************************************************************************/

IexWznmDbs::ImeitemIJMVectoritem2::ImeitemIJMVectoritem2(
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

IexWznmDbs::ImeitemIJMVectoritem2::ImeitemIJMVectoritem2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMVectoritem2()
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

void IexWznmDbs::ImeitemIJMVectoritem2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMVectoritem2::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMVectoritem2::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIJMVectoritem2::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMVectoritem2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIJMVectoritem2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMVectoritem2::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMVectoritem2::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJMVectoritem2::VecWIel::COMMENT;
	};
};

void IexWznmDbs::ImeitemIJMVectoritem2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefX1RefWznmMLocale << "\t" << Title << "\t" << Comment << endl;
};

void IexWznmDbs::ImeitemIJMVectoritem2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit","cmt"};
	else tags = {"ImeitemIJMVectoritem2","srefX1RefWznmMLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIJMVectoritem2::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIJMVectoritem2::VecWIel::getIx(
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

void IexWznmDbs::ImeIJMVectoritem2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIJMVectoritem2::VecWIel::getSrefs(
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
 class IexWznmDbs::ImeIJMVectoritem2
 ******************************************************************************/

IexWznmDbs::ImeIJMVectoritem2::ImeIJMVectoritem2() {
};

IexWznmDbs::ImeIJMVectoritem2::~ImeIJMVectoritem2() {
	clear();
};

void IexWznmDbs::ImeIJMVectoritem2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIJMVectoritem2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIJMVectoritem2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWznmDbs::ImeitemIJMVectoritem2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVectoritem2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMVectoritem2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMVECTORITEM2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVectoritem2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVectoritem2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIJMVectoritem2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIJMVectoritem2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMVectoritem2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMVectoritem2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMVectoritem2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIJMVectoritem2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIJMVectoritem2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMVectoritem2." << StrMod::replaceChar(ImeIJMVectoritem2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMVectoritem2.end" << endl;
	};
};

void IexWznmDbs::ImeIJMVectoritem2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMVectoritem2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIMVectoritem2
 ******************************************************************************/

IexWznmDbs::ImeitemIMVectoritem2::ImeitemIMVectoritem2(
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

IexWznmDbs::ImeitemIMVectoritem2::ImeitemIMVectoritem2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMVectoritem2()
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

void IexWznmDbs::ImeitemIMVectoritem2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMVectoritem2::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Avail = txtrd.fields[1]; ixWIelValid += ImeIMVectoritem2::VecWIel::AVAIL;};
	if (txtrd.fields.size() > 2) {Implied = txtrd.fields[2]; ixWIelValid += ImeIMVectoritem2::VecWIel::IMPLIED;};
	if (txtrd.fields.size() > 3) {Title = txtrd.fields[3]; ixWIelValid += ImeIMVectoritem2::VecWIel::TITLE;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMVectoritem2::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMVECTORITEM2)) {
					imeijmvectoritem2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVectoritem2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIMVectoritem2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVectoritem2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIMVectoritem2::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIMVectoritem2::VecWIel::IMPLIED;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMVectoritem2::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVectoritem2::VecWIel::COMMENT;
		imeijmvectoritem2.readXML(docctx, basexpath);
	};
};

void IexWznmDbs::ImeitemIMVectoritem2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << Avail << "\t" << Implied << "\t" << Title << "\t" << Comment << endl;
	imeijmvectoritem2.writeTxt(outfile);
};

void IexWznmDbs::ImeitemIMVectoritem2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","avl","imp","tit","cmt"};
	else tags = {"ImeitemIMVectoritem2","sref","Avail","Implied","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Avail);
		writeString(wr, tags[3], Implied);
		writeString(wr, tags[4], Title);
		writeString(wr, tags[5], Comment);
		imeijmvectoritem2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIMVectoritem2::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIMVectoritem2::VecWIel::getIx(
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

void IexWznmDbs::ImeIMVectoritem2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIMVectoritem2::VecWIel::getSrefs(
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
 class IexWznmDbs::ImeIMVectoritem2
 ******************************************************************************/

IexWznmDbs::ImeIMVectoritem2::ImeIMVectoritem2() {
};

IexWznmDbs::ImeIMVectoritem2::~ImeIMVectoritem2() {
	clear();
};

void IexWznmDbs::ImeIMVectoritem2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIMVectoritem2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIMVectoritem2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmDbs::ImeitemIMVectoritem2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVectoritem2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTORITEM2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIMVectoritem2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIMVectoritem2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVectoritem2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVectoritem2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVectoritem2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIMVectoritem2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIMVectoritem2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMVectoritem2." << StrMod::replaceChar(ImeIMVectoritem2::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMVectoritem2.end" << endl;
	};
};

void IexWznmDbs::ImeIMVectoritem2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVectoritem2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIRMTableMVector2
 ******************************************************************************/

IexWznmDbs::ImeitemIRMTableMVector2::ImeitemIRMTableMVector2(
			const string& srefRefWznmMTable
			, const string& srefRefWznmMSubset
		) : WznmRMTableMVector() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMTable = srefRefWznmMTable;
	this->srefRefWznmMSubset = srefRefWznmMSubset;
};

IexWznmDbs::ImeitemIRMTableMVector2::ImeitemIRMTableMVector2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMTableMVector2()
		{
	WznmRMTableMVector* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmtablemvector->loadRecByRef(ref, &rec)) {
		refWznmMTable = rec->refWznmMTable;
		refWznmMSubset = rec->refWznmMSubset;
		refWznmMVector = rec->refWznmMVector;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIRMTableMVector2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMTable = txtrd.fields[0]; ixWIelValid += ImeIRMTableMVector2::VecWIel::SREFREFWZNMMTABLE;};
	if (txtrd.fields.size() > 1) {srefRefWznmMSubset = txtrd.fields[1]; ixWIelValid += ImeIRMTableMVector2::VecWIel::SREFREFWZNMMSUBSET;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMTableMVector2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIRMTableMVector2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMTable", "tbl", srefRefWznmMTable)) ixWIelValid += ImeIRMTableMVector2::VecWIel::SREFREFWZNMMTABLE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMSubset", "sbs", srefRefWznmMSubset)) ixWIelValid += ImeIRMTableMVector2::VecWIel::SREFREFWZNMMSUBSET;
	};
};

void IexWznmDbs::ImeitemIRMTableMVector2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefRefWznmMTable << "\t" << srefRefWznmMSubset << endl;
};

void IexWznmDbs::ImeitemIRMTableMVector2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tbl","sbs"};
	else tags = {"ImeitemIRMTableMVector2","srefRefWznmMTable","srefRefWznmMSubset"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMTable);
		writeString(wr, tags[2], srefRefWznmMSubset);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIRMTableMVector2::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIRMTableMVector2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwznmmtable") ix |= SREFREFWZNMMTABLE;
		else if (ss[i] == "srefrefwznmmsubset") ix |= SREFREFWZNMMSUBSET;
	};

	return(ix);
};

void IexWznmDbs::ImeIRMTableMVector2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMSUBSET); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIRMTableMVector2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMTABLE) ss.push_back("srefRefWznmMTable");
	if (ix & SREFREFWZNMMSUBSET) ss.push_back("srefRefWznmMSubset");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeIRMTableMVector2
 ******************************************************************************/

IexWznmDbs::ImeIRMTableMVector2::ImeIRMTableMVector2() {
};

IexWznmDbs::ImeIRMTableMVector2::~ImeIRMTableMVector2() {
	clear();
};

void IexWznmDbs::ImeIRMTableMVector2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIRMTableMVector2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIRMTableMVector2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmDbs::ImeitemIRMTableMVector2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMTableMVector2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMTableMVector2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMTABLEMVECTOR2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMTableMVector2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMTableMVector2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIRMTableMVector2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIRMTableMVector2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMTableMVector2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMTableMVector2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMTableMVector2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIRMTableMVector2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIRMTableMVector2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIRMTableMVector2." << StrMod::replaceChar(ImeIRMTableMVector2::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIRMTableMVector2.end" << endl;
	};
};

void IexWznmDbs::ImeIRMTableMVector2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMTableMVector2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIMVector2
 ******************************************************************************/

IexWznmDbs::ImeitemIMVector2::ImeitemIMVector2(
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

IexWznmDbs::ImeitemIMVector2::ImeitemIMVector2(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMVector2()
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

void IexWznmDbs::ImeitemIMVector2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMVector2::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMVector2::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {osrefWznmKTaggrp = txtrd.fields[2]; ixWIelValid += ImeIMVector2::VecWIel::OSREFWZNMKTAGGRP;};
	if (txtrd.fields.size() > 3) {srefsKOption = txtrd.fields[3]; ixWIelValid += ImeIMVector2::VecWIel::SREFSKOPTION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMVECTORTITLE2)) {
					imeiamvectortitle2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMVECTORITEM2)) {
					imeimvectoritem2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIRMTABLEMVECTOR2)) {
					imeirmtablemvector2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIMVector2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMVector2::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVector2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "osrefWznmKTaggrp", "tgr", osrefWznmKTaggrp)) ixWIelValid += ImeIMVector2::VecWIel::OSREFWZNMKTAGGRP;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMVector2::VecWIel::SREFSKOPTION;
		imeiamvectortitle2.readXML(docctx, basexpath);
		imeimvectoritem2.readXML(docctx, basexpath);
		imeirmtablemvector2.readXML(docctx, basexpath);
	};
};

void IexWznmDbs::ImeitemIMVector2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVMVectorBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << osrefWznmKTaggrp << "\t" << srefsKOption << endl;
	imeiamvectortitle2.writeTxt(outfile);
	imeimvectoritem2.writeTxt(outfile);
	imeirmtablemvector2.writeTxt(outfile);
};

void IexWznmDbs::ImeitemIMVector2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","srf","tgr","opt"};
	else tags = {"ImeitemIMVector2","srefIxVBasetype","sref","osrefWznmKTaggrp","srefsKOption"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMVectorBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], osrefWznmKTaggrp);
		writeString(wr, tags[4], srefsKOption);
		imeiamvectortitle2.writeXML(wr, shorttags);
		imeimvectoritem2.writeXML(wr, shorttags);
		imeirmtablemvector2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIMVector2::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIMVector2::VecWIel::getIx(
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

void IexWznmDbs::ImeIMVector2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIMVector2::VecWIel::getSrefs(
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
 class IexWznmDbs::ImeIMVector2
 ******************************************************************************/

IexWznmDbs::ImeIMVector2::ImeIMVector2() {
};

IexWznmDbs::ImeIMVector2::~ImeIMVector2() {
	clear();
};

void IexWznmDbs::ImeIMVector2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIMVector2::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIMVector2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmDbs::ImeitemIMVector2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTOR2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIMVector2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIMVector2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVector2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVector2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVector2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIMVector2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIMVector2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMVector2." << StrMod::replaceChar(ImeIMVector2::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMVector2.end" << endl;
	};
};

void IexWznmDbs::ImeIMVector2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVector2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIMTable
 ******************************************************************************/

IexWznmDbs::ImeitemIMTable::ImeitemIMTable(
			const uint ixVBasetype
			, const uint refIxVTbl
			, const ubigint irefRefUref
			, const string& sref
			, const string& Short
			, const string& unqSrefsWznmMTablecol
			, const string& Comment
		) : WznmMTable() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->refIxVTbl = refIxVTbl;
	this->irefRefUref = irefRefUref;
	this->sref = sref;
	this->Short = Short;
	this->unqSrefsWznmMTablecol = unqSrefsWznmMTablecol;
	this->Comment = Comment;
};

IexWznmDbs::ImeitemIMTable::ImeitemIMTable(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMTable()
		{
	WznmMTable* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmmtable->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWznmMVersion = rec->refWznmMVersion;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		sref = rec->sref;
		Short = rec->Short;
		unqSrefsWznmMTablecol = rec->unqSrefsWznmMTablecol;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIMTable::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMTable::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {srefRefIxVTbl = txtrd.fields[1]; ixWIelValid += ImeIMTable::VecWIel::SREFREFIXVTBL;};
	if (txtrd.fields.size() > 2) {irefRefUref = atoll(txtrd.fields[2].c_str()); ixWIelValid += ImeIMTable::VecWIel::IREFREFUREF;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIMTable::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {Short = txtrd.fields[4]; ixWIelValid += ImeIMTable::VecWIel::SHORT;};
	if (txtrd.fields.size() > 5) {unqSrefsWznmMTablecol = txtrd.fields[5]; ixWIelValid += ImeIMTable::VecWIel::UNQSREFSWZNMMTABLECOL;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMTable::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMTABLELOADFCT)) {
					imeiamtableloadfct.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMTABLETITLE)) {
					imeiamtabletitle.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMCHECK)) {
					imeimcheck.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMSUBSET)) {
					imeimsubset.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMTABLECOL)) {
					imeimtablecol.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMVECTOR2)) {
					imeimvector2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMTable"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIMTable::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMTable::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl)) ixWIelValid += ImeIMTable::VecWIel::SREFREFIXVTBL;
		if (extractUbigintUclc(docctx, basexpath, "irefRefUref", "reu", irefRefUref)) ixWIelValid += ImeIMTable::VecWIel::IREFREFUREF;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMTable::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Short", "sho", Short)) ixWIelValid += ImeIMTable::VecWIel::SHORT;
		if (extractStringUclc(docctx, basexpath, "unqSrefsWznmMTablecol", "unq", unqSrefsWznmMTablecol)) ixWIelValid += ImeIMTable::VecWIel::UNQSREFSWZNMMTABLECOL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMTable::VecWIel::COMMENT;
		imeiamtableloadfct.readXML(docctx, basexpath);
		imeiamtabletitle.readXML(docctx, basexpath);
		imeimcheck.readXML(docctx, basexpath);
		imeimsubset.readXML(docctx, basexpath);
		imeimtablecol.readXML(docctx, basexpath);
		imeimvector2.readXML(docctx, basexpath);
	};
};

void IexWznmDbs::ImeitemIMTable::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmVMTableBasetype::getSref(ixVBasetype) << "\t" << VecWznmVMTableRefTbl::getSref(refIxVTbl) << "\t" << irefRefUref << "\t" << sref << "\t" << Short << "\t" << unqSrefsWznmMTablecol << "\t" << Comment << endl;
	imeiamtableloadfct.writeTxt(outfile);
	imeiamtabletitle.writeTxt(outfile);
	imeimcheck.writeTxt(outfile);
	imeimsubset.writeTxt(outfile);
	imeimtablecol.writeTxt(outfile);
	imeimvector2.writeTxt(outfile);
};

void IexWznmDbs::ImeitemIMTable::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","ret","reu","srf","sho","unq","cmt"};
	else tags = {"ImeitemIMTable","srefIxVBasetype","srefRefIxVTbl","irefRefUref","sref","Short","unqSrefsWznmMTablecol","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMTableBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], VecWznmVMTableRefTbl::getSref(refIxVTbl));
		writeUbigint(wr, tags[3], irefRefUref);
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], Short);
		writeString(wr, tags[6], unqSrefsWznmMTablecol);
		writeString(wr, tags[7], Comment);
		imeiamtableloadfct.writeXML(wr, shorttags);
		imeiamtabletitle.writeXML(wr, shorttags);
		imeimcheck.writeXML(wr, shorttags);
		imeimsubset.writeXML(wr, shorttags);
		imeimtablecol.writeXML(wr, shorttags);
		imeimvector2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIMTable::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIMTable::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefrefixvtbl") ix |= SREFREFIXVTBL;
		else if (ss[i] == "irefrefuref") ix |= IREFREFUREF;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "short") ix |= SHORT;
		else if (ss[i] == "unqsrefswznmmtablecol") ix |= UNQSREFSWZNMMTABLECOL;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWznmDbs::ImeIMTable::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIMTable::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFREFIXVTBL) ss.push_back("srefRefIxVTbl");
	if (ix & IREFREFUREF) ss.push_back("irefRefUref");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SHORT) ss.push_back("Short");
	if (ix & UNQSREFSWZNMMTABLECOL) ss.push_back("unqSrefsWznmMTablecol");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeIMTable
 ******************************************************************************/

IexWznmDbs::ImeIMTable::ImeIMTable() {
};

IexWznmDbs::ImeIMTable::~ImeIMTable() {
	clear();
};

void IexWznmDbs::ImeIMTable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIMTable::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIMTable* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmDbs::ImeitemIMTable();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMTable"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMTABLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMTable"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMTable"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIMTable::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIMTable* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMTable");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMTable", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMTable";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIMTable();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIMTable::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMTable." << StrMod::replaceChar(ImeIMTable::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMTable.end" << endl;
	};
};

void IexWznmDbs::ImeIMTable::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMTable");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIAMVectorTitle1
 ******************************************************************************/

IexWznmDbs::ImeitemIAMVectorTitle1::ImeitemIAMVectorTitle1(
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

IexWznmDbs::ImeitemIAMVectorTitle1::ImeitemIAMVectorTitle1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIAMVectorTitle1()
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

void IexWznmDbs::ImeitemIAMVectorTitle1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxVType = txtrd.fields[0]; ixWIelValid += ImeIAMVectorTitle1::VecWIel::SREFX1IXVTYPE;};
	if (txtrd.fields.size() > 1) {srefX2RefWznmMLocale = txtrd.fields[1]; ixWIelValid += ImeIAMVectorTitle1::VecWIel::SREFX2REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIAMVectorTitle1::VecWIel::TITLE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMVectorTitle1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIAMVectorTitle1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxVType", "typ", srefX1IxVType)) ixWIelValid += ImeIAMVectorTitle1::VecWIel::SREFX1IXVTYPE;
		if (extractStringUclc(docctx, basexpath, "srefX2RefWznmMLocale", "loc", srefX2RefWznmMLocale)) ixWIelValid += ImeIAMVectorTitle1::VecWIel::SREFX2REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAMVectorTitle1::VecWIel::TITLE;
	};
};

void IexWznmDbs::ImeitemIAMVectorTitle1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWznmVAMVectorTitleType::getSref(x1IxVType) << "\t" << srefX2RefWznmMLocale << "\t" << Title << endl;
};

void IexWznmDbs::ImeitemIAMVectorTitle1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","loc","tit"};
	else tags = {"ImeitemIAMVectorTitle1","srefX1IxVType","srefX2RefWznmMLocale","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVAMVectorTitleType::getSref(x1IxVType));
		writeString(wr, tags[2], srefX2RefWznmMLocale);
		writeString(wr, tags[3], Title);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIAMVectorTitle1::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIAMVectorTitle1::VecWIel::getIx(
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

void IexWznmDbs::ImeIAMVectorTitle1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*TITLE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIAMVectorTitle1::VecWIel::getSrefs(
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
 class IexWznmDbs::ImeIAMVectorTitle1
 ******************************************************************************/

IexWznmDbs::ImeIAMVectorTitle1::ImeIAMVectorTitle1() {
};

IexWznmDbs::ImeIAMVectorTitle1::~ImeIAMVectorTitle1() {
	clear();
};

void IexWznmDbs::ImeIAMVectorTitle1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIAMVectorTitle1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIAMVectorTitle1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmDbs::ImeitemIAMVectorTitle1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMVectorTitle1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMVectorTitle1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMVECTORTITLE1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMVectorTitle1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMVectorTitle1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIAMVectorTitle1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIAMVectorTitle1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMVectorTitle1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMVectorTitle1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMVectorTitle1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIAMVectorTitle1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIAMVectorTitle1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMVectorTitle1." << StrMod::replaceChar(ImeIAMVectorTitle1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMVectorTitle1.end" << endl;
	};
};

void IexWznmDbs::ImeIAMVectorTitle1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMVectorTitle1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIJMVectoritem1
 ******************************************************************************/

IexWznmDbs::ImeitemIJMVectoritem1::ImeitemIJMVectoritem1(
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

IexWznmDbs::ImeitemIJMVectoritem1::ImeitemIJMVectoritem1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIJMVectoritem1()
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

void IexWznmDbs::ImeitemIJMVectoritem1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWznmMLocale = txtrd.fields[0]; ixWIelValid += ImeIJMVectoritem1::VecWIel::SREFX1REFWZNMMLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJMVectoritem1::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIJMVectoritem1::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMVectoritem1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIJMVectoritem1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWznmMLocale", "loc", srefX1RefWznmMLocale)) ixWIelValid += ImeIJMVectoritem1::VecWIel::SREFX1REFWZNMMLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJMVectoritem1::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJMVectoritem1::VecWIel::COMMENT;
	};
};

void IexWznmDbs::ImeitemIJMVectoritem1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefX1RefWznmMLocale << "\t" << Title << "\t" << Comment << endl;
};

void IexWznmDbs::ImeitemIJMVectoritem1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","loc","tit","cmt"};
	else tags = {"ImeitemIJMVectoritem1","srefX1RefWznmMLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWznmMLocale);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIJMVectoritem1::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIJMVectoritem1::VecWIel::getIx(
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

void IexWznmDbs::ImeIJMVectoritem1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIJMVectoritem1::VecWIel::getSrefs(
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
 class IexWznmDbs::ImeIJMVectoritem1
 ******************************************************************************/

IexWznmDbs::ImeIJMVectoritem1::ImeIJMVectoritem1() {
};

IexWznmDbs::ImeIJMVectoritem1::~ImeIJMVectoritem1() {
	clear();
};

void IexWznmDbs::ImeIJMVectoritem1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIJMVectoritem1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIJMVectoritem1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWznmDbs::ImeitemIJMVectoritem1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVectoritem1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMVectoritem1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMVECTORITEM1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVectoritem1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVectoritem1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIJMVectoritem1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIJMVectoritem1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMVectoritem1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMVectoritem1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMVectoritem1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIJMVectoritem1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIJMVectoritem1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMVectoritem1." << StrMod::replaceChar(ImeIJMVectoritem1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMVectoritem1.end" << endl;
	};
};

void IexWznmDbs::ImeIJMVectoritem1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMVectoritem1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIMVectoritem1
 ******************************************************************************/

IexWznmDbs::ImeitemIMVectoritem1::ImeitemIMVectoritem1(
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

IexWznmDbs::ImeitemIMVectoritem1::ImeitemIMVectoritem1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMVectoritem1()
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

void IexWznmDbs::ImeitemIMVectoritem1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMVectoritem1::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Avail = txtrd.fields[1]; ixWIelValid += ImeIMVectoritem1::VecWIel::AVAIL;};
	if (txtrd.fields.size() > 2) {Implied = txtrd.fields[2]; ixWIelValid += ImeIMVectoritem1::VecWIel::IMPLIED;};
	if (txtrd.fields.size() > 3) {Title = txtrd.fields[3]; ixWIelValid += ImeIMVectoritem1::VecWIel::TITLE;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMVectoritem1::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMVECTORITEM1)) {
					imeijmvectoritem1.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVectoritem1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIMVectoritem1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVectoritem1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIMVectoritem1::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIMVectoritem1::VecWIel::IMPLIED;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMVectoritem1::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVectoritem1::VecWIel::COMMENT;
		imeijmvectoritem1.readXML(docctx, basexpath);
	};
};

void IexWznmDbs::ImeitemIMVectoritem1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << Avail << "\t" << Implied << "\t" << Title << "\t" << Comment << endl;
	imeijmvectoritem1.writeTxt(outfile);
};

void IexWznmDbs::ImeitemIMVectoritem1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","avl","imp","tit","cmt"};
	else tags = {"ImeitemIMVectoritem1","sref","Avail","Implied","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Avail);
		writeString(wr, tags[3], Implied);
		writeString(wr, tags[4], Title);
		writeString(wr, tags[5], Comment);
		imeijmvectoritem1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIMVectoritem1::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIMVectoritem1::VecWIel::getIx(
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

void IexWznmDbs::ImeIMVectoritem1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIMVectoritem1::VecWIel::getSrefs(
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
 class IexWznmDbs::ImeIMVectoritem1
 ******************************************************************************/

IexWznmDbs::ImeIMVectoritem1::ImeIMVectoritem1() {
};

IexWznmDbs::ImeIMVectoritem1::~ImeIMVectoritem1() {
	clear();
};

void IexWznmDbs::ImeIMVectoritem1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIMVectoritem1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIMVectoritem1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmDbs::ImeitemIMVectoritem1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVectoritem1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTORITEM1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIMVectoritem1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIMVectoritem1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVectoritem1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVectoritem1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVectoritem1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIMVectoritem1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIMVectoritem1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMVectoritem1." << StrMod::replaceChar(ImeIMVectoritem1::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMVectoritem1.end" << endl;
	};
};

void IexWznmDbs::ImeIMVectoritem1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVectoritem1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIRMTableMVector1
 ******************************************************************************/

IexWznmDbs::ImeitemIRMTableMVector1::ImeitemIRMTableMVector1(
			const string& srefRefWznmMTable
			, const string& srefRefWznmMSubset
		) : WznmRMTableMVector() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWznmMTable = srefRefWznmMTable;
	this->srefRefWznmMSubset = srefRefWznmMSubset;
};

IexWznmDbs::ImeitemIRMTableMVector1::ImeitemIRMTableMVector1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMTableMVector1()
		{
	WznmRMTableMVector* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmtablemvector->loadRecByRef(ref, &rec)) {
		refWznmMTable = rec->refWznmMTable;
		refWznmMSubset = rec->refWznmMSubset;
		refWznmMVector = rec->refWznmMVector;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIRMTableMVector1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWznmMTable = txtrd.fields[0]; ixWIelValid += ImeIRMTableMVector1::VecWIel::SREFREFWZNMMTABLE;};
	if (txtrd.fields.size() > 1) {srefRefWznmMSubset = txtrd.fields[1]; ixWIelValid += ImeIRMTableMVector1::VecWIel::SREFREFWZNMMSUBSET;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMTableMVector1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIRMTableMVector1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMTable", "tbl", srefRefWznmMTable)) ixWIelValid += ImeIRMTableMVector1::VecWIel::SREFREFWZNMMTABLE;
		if (extractStringUclc(docctx, basexpath, "srefRefWznmMSubset", "sbs", srefRefWznmMSubset)) ixWIelValid += ImeIRMTableMVector1::VecWIel::SREFREFWZNMMSUBSET;
	};
};

void IexWznmDbs::ImeitemIRMTableMVector1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefRefWznmMTable << "\t" << srefRefWznmMSubset << endl;
};

void IexWznmDbs::ImeitemIRMTableMVector1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tbl","sbs"};
	else tags = {"ImeitemIRMTableMVector1","srefRefWznmMTable","srefRefWznmMSubset"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWznmMTable);
		writeString(wr, tags[2], srefRefWznmMSubset);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIRMTableMVector1::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIRMTableMVector1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwznmmtable") ix |= SREFREFWZNMMTABLE;
		else if (ss[i] == "srefrefwznmmsubset") ix |= SREFREFWZNMMSUBSET;
	};

	return(ix);
};

void IexWznmDbs::ImeIRMTableMVector1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWZNMMSUBSET); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIRMTableMVector1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWZNMMTABLE) ss.push_back("srefRefWznmMTable");
	if (ix & SREFREFWZNMMSUBSET) ss.push_back("srefRefWznmMSubset");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeIRMTableMVector1
 ******************************************************************************/

IexWznmDbs::ImeIRMTableMVector1::ImeIRMTableMVector1() {
};

IexWznmDbs::ImeIRMTableMVector1::~ImeIRMTableMVector1() {
	clear();
};

void IexWznmDbs::ImeIRMTableMVector1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIRMTableMVector1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIRMTableMVector1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWznmDbs::ImeitemIRMTableMVector1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMTableMVector1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMTableMVector1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMTABLEMVECTOR1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMTableMVector1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMTableMVector1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIRMTableMVector1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIRMTableMVector1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMTableMVector1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMTableMVector1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMTableMVector1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIRMTableMVector1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIRMTableMVector1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMTableMVector1." << StrMod::replaceChar(ImeIRMTableMVector1::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMTableMVector1.end" << endl;
	};
};

void IexWznmDbs::ImeIRMTableMVector1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMTableMVector1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIMVector1
 ******************************************************************************/

IexWznmDbs::ImeitemIMVector1::ImeitemIMVector1(
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

IexWznmDbs::ImeitemIMVector1::ImeitemIMVector1(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIMVector1()
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

void IexWznmDbs::ImeitemIMVector1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMVector1::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMVector1::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {osrefWznmKTaggrp = txtrd.fields[2]; ixWIelValid += ImeIMVector1::VecWIel::OSREFWZNMKTAGGRP;};
	if (txtrd.fields.size() > 3) {srefsKOption = txtrd.fields[3]; ixWIelValid += ImeIMVector1::VecWIel::SREFSKOPTION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMVECTORTITLE1)) {
					imeiamvectortitle1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMVECTORITEM1)) {
					imeimvectoritem1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMTABLEMVECTOR1)) {
					imeirmtablemvector1.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIMVector1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMVector1::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVector1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "osrefWznmKTaggrp", "tgr", osrefWznmKTaggrp)) ixWIelValid += ImeIMVector1::VecWIel::OSREFWZNMKTAGGRP;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMVector1::VecWIel::SREFSKOPTION;
		imeiamvectortitle1.readXML(docctx, basexpath);
		imeimvectoritem1.readXML(docctx, basexpath);
		imeirmtablemvector1.readXML(docctx, basexpath);
	};
};

void IexWznmDbs::ImeitemIMVector1::writeTxt(
			fstream& outfile
		) {
	outfile << VecWznmVMVectorBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << osrefWznmKTaggrp << "\t" << srefsKOption << endl;
	imeiamvectortitle1.writeTxt(outfile);
	imeimvectoritem1.writeTxt(outfile);
	imeirmtablemvector1.writeTxt(outfile);
};

void IexWznmDbs::ImeitemIMVector1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","srf","tgr","opt"};
	else tags = {"ImeitemIMVector1","srefIxVBasetype","sref","osrefWznmKTaggrp","srefsKOption"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWznmVMVectorBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], osrefWznmKTaggrp);
		writeString(wr, tags[4], srefsKOption);
		imeiamvectortitle1.writeXML(wr, shorttags);
		imeimvectoritem1.writeXML(wr, shorttags);
		imeirmtablemvector1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIMVector1::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIMVector1::VecWIel::getIx(
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

void IexWznmDbs::ImeIMVector1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIMVector1::VecWIel::getSrefs(
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
 class IexWznmDbs::ImeIMVector1
 ******************************************************************************/

IexWznmDbs::ImeIMVector1::ImeIMVector1() {
};

IexWznmDbs::ImeIMVector1::~ImeIMVector1() {
	clear();
};

void IexWznmDbs::ImeIMVector1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIMVector1::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIMVector1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmDbs::ImeitemIMVector1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTOR1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIMVector1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIMVector1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVector1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVector1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVector1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIMVector1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIMVector1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMVector1." << StrMod::replaceChar(ImeIMVector1::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMVector1.end" << endl;
	};
};

void IexWznmDbs::ImeIMVector1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVector1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWznmDbs::ImeitemIRMStubMStub
 ******************************************************************************/

IexWznmDbs::ImeitemIRMStubMStub::ImeitemIRMStubMStub(
			const string& srefSupRefWznmMStub
			, const string& srefSubRefWznmMStub
		) : WznmRMStubMStub() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefSupRefWznmMStub = srefSupRefWznmMStub;
	this->srefSubRefWznmMStub = srefSubRefWznmMStub;
};

IexWznmDbs::ImeitemIRMStubMStub::ImeitemIRMStubMStub(
			DbsWznm* dbswznm
			, const ubigint ref
		) :
			ImeitemIRMStubMStub()
		{
	WznmRMStubMStub* rec = NULL;

	this->ref = ref;

	if (dbswznm->tblwznmrmstubmstub->loadRecByRef(ref, &rec)) {
		supRefWznmMStub = rec->supRefWznmMStub;
		subRefWznmMStub = rec->subRefWznmMStub;

		delete rec;
	};
};

void IexWznmDbs::ImeitemIRMStubMStub::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefSupRefWznmMStub = txtrd.fields[0]; ixWIelValid += ImeIRMStubMStub::VecWIel::SREFSUPREFWZNMMSTUB;};
	if (txtrd.fields.size() > 1) {srefSubRefWznmMStub = txtrd.fields[1]; ixWIelValid += ImeIRMStubMStub::VecWIel::SREFSUBREFWZNMMSTUB;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMStubMStub"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWznmDbs::ImeitemIRMStubMStub::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefSupRefWznmMStub", "sup", srefSupRefWznmMStub)) ixWIelValid += ImeIRMStubMStub::VecWIel::SREFSUPREFWZNMMSTUB;
		if (extractStringUclc(docctx, basexpath, "srefSubRefWznmMStub", "sub", srefSubRefWznmMStub)) ixWIelValid += ImeIRMStubMStub::VecWIel::SREFSUBREFWZNMMSTUB;
	};
};

void IexWznmDbs::ImeitemIRMStubMStub::writeTxt(
			fstream& outfile
		) {
	outfile << srefSupRefWznmMStub << "\t" << srefSubRefWznmMStub << endl;
};

void IexWznmDbs::ImeitemIRMStubMStub::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sup","sub"};
	else tags = {"ImeitemIRMStubMStub","srefSupRefWznmMStub","srefSubRefWznmMStub"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefSupRefWznmMStub);
		writeString(wr, tags[2], srefSubRefWznmMStub);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWznmDbs::ImeIRMStubMStub::VecWIel
 ******************************************************************************/

uint IexWznmDbs::ImeIRMStubMStub::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefsuprefwznmmstub") ix |= SREFSUPREFWZNMMSTUB;
		else if (ss[i] == "srefsubrefwznmmstub") ix |= SREFSUBREFWZNMMSTUB;
	};

	return(ix);
};

void IexWznmDbs::ImeIRMStubMStub::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSUBREFWZNMMSTUB); i *= 2) if (ix & i) ics.insert(i);
};

string IexWznmDbs::ImeIRMStubMStub::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFSUPREFWZNMMSTUB) ss.push_back("srefSupRefWznmMStub");
	if (ix & SREFSUBREFWZNMMSTUB) ss.push_back("srefSubRefWznmMStub");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWznmDbs::ImeIRMStubMStub
 ******************************************************************************/

IexWznmDbs::ImeIRMStubMStub::ImeIRMStubMStub() {
};

IexWznmDbs::ImeIRMStubMStub::~ImeIRMStubMStub() {
	clear();
};

void IexWznmDbs::ImeIRMStubMStub::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWznmDbs::ImeIRMStubMStub::readTxt(
			Txtrd& txtrd
		) {
	IexWznmDbs::ImeitemIRMStubMStub* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWznmDbs::ImeitemIRMStubMStub();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMStubMStub"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMSTUBMSTUB) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMStubMStub"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMStubMStub"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWznmDbs::ImeIRMStubMStub::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWznmDbs::ImeitemIRMStubMStub* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMStubMStub");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMStubMStub", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMStubMStub";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWznmDbs::ImeitemIRMStubMStub();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWznmDbs::ImeIRMStubMStub::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIRMStubMStub." << StrMod::replaceChar(ImeIRMStubMStub::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIRMStubMStub.end" << endl;
	};
};

void IexWznmDbs::ImeIRMStubMStub::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMStubMStub");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWznmDbs
 ******************************************************************************/

void IexWznmDbs::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, ImeICRelation& imeicrelation
			, ImeIMRelation& imeimrelation
			, ImeIMStub& imeimstub
			, ImeIMTable& imeimtable
			, ImeIMVector1& imeimvector1
			, ImeIRMStubMStub& imeirmstubmstub
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeicrelation, imeimrelation, imeimstub, imeimtable, imeimvector1, imeirmstubmstub);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, "IexWznmDbs", Version("0.9.23"), VecVIme::getIx);
			readTxt(rd, imeicrelation, imeimrelation, imeimstub, imeimtable, imeimvector1, imeirmstubmstub);
	};
};

void IexWznmDbs::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeICRelation& imeicrelation
			, ImeIMRelation& imeimrelation
			, ImeIMStub& imeimstub
			, ImeIMTable& imeimtable
			, ImeIMVector1& imeimvector1
			, ImeIRMStubMStub& imeirmstubmstub
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeicrelation, imeimrelation, imeimstub, imeimtable, imeimvector1, imeirmstubmstub);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeicrelation, imeimrelation, imeimstub, imeimtable, imeimvector1, imeirmstubmstub);
		txtfile.close();
	};
};

void IexWznmDbs::readTxt(
			Txtrd& txtrd
			, ImeICRelation& imeicrelation
			, ImeIMRelation& imeimrelation
			, ImeIMStub& imeimstub
			, ImeIMTable& imeimtable
			, ImeIMVector1& imeimvector1
			, ImeIRMStubMStub& imeirmstubmstub
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEICRELATION)) imeicrelation.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMRELATION)) imeimrelation.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMSTUB)) imeimstub.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMTABLE)) imeimtable.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMVECTOR1)) imeimvector1.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIRMSTUBMSTUB)) imeirmstubmstub.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWznmDbs::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeICRelation& imeicrelation
			, ImeIMRelation& imeimrelation
			, ImeIMStub& imeimstub
			, ImeIMTable& imeimtable
			, ImeIMVector1& imeimvector1
			, ImeIRMStubMStub& imeirmstubmstub
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWznmDbs")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("0.9.23")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","0.9.23"}});
		};

		// look for XML sub-blocks
		imeicrelation.readXML(docctx, basexpath);
		imeimrelation.readXML(docctx, basexpath);
		imeimstub.readXML(docctx, basexpath);
		imeimtable.readXML(docctx, basexpath);
		imeimvector1.readXML(docctx, basexpath);
		imeirmstubmstub.readXML(docctx, basexpath);

	} else {
		imeicrelation = ImeICRelation();
		imeimrelation = ImeIMRelation();
		imeimstub = ImeIMStub();
		imeimtable = ImeIMTable();
		imeimvector1 = ImeIMVector1();
		imeirmstubmstub = ImeIRMStubMStub();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWznmDbs"}});
	};
};

void IexWznmDbs::writeTxt(
			fstream& outfile
			, ImeICRelation& imeicrelation
			, ImeIMRelation& imeimrelation
			, ImeIMStub& imeimstub
			, ImeIMTable& imeimtable
			, ImeIMVector1& imeimvector1
			, ImeIRMStubMStub& imeirmstubmstub
		) {
	outfile << "IexWznmDbs v" WZNM_VERSION << endl;

	imeicrelation.writeTxt(outfile);
	imeimrelation.writeTxt(outfile);
	imeimstub.writeTxt(outfile);
	imeimtable.writeTxt(outfile);
	imeimvector1.writeTxt(outfile);
	imeirmstubmstub.writeTxt(outfile);
};

void IexWznmDbs::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeICRelation& imeicrelation
			, ImeIMRelation& imeimrelation
			, ImeIMStub& imeimstub
			, ImeIMTable& imeimtable
			, ImeIMVector1& imeimvector1
			, ImeIRMStubMStub& imeirmstubmstub
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWznmDbs");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WZNM_VERSION);

		imeicrelation.writeXML(wr, shorttags);
		imeimrelation.writeXML(wr, shorttags);
		imeimstub.writeXML(wr, shorttags);
		imeimtable.writeXML(wr, shorttags);
		imeimvector1.writeXML(wr, shorttags);
		imeirmstubmstub.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWznmDbs::icsWznmVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMRELATIONTITLE,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMSUBSETTITLE,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMTABLECOLTITLE,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMTABLELOADFCT,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMTABLETITLE,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMVECTORTITLE1,VecWznmVIop::INS},{(uint)VecVIme::IMEIAMVECTORTITLE2,VecWznmVIop::INS},{(uint)VecVIme::IMEICRELATION,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMVECTORITEM1,VecWznmVIop::INS},{(uint)VecVIme::IMEIJMVECTORITEM2,VecWznmVIop::INS},{(uint)VecVIme::IMEIMCHECK,VecWznmVIop::INS},{(uint)VecVIme::IMEIMRELATION,VecWznmVIop::INS},{(uint)VecVIme::IMEIMSTUB,VecWznmVIop::INS},{(uint)VecVIme::IMEIMSUBSET,VecWznmVIop::INS},{(uint)VecVIme::IMEIMTABLE,VecWznmVIop::INS},{(uint)VecVIme::IMEIMTABLECOL,VecWznmVIop::INS},{(uint)VecVIme::IMEIMVECTOR1,VecWznmVIop::INS},{(uint)VecVIme::IMEIMVECTOR2,VecWznmVIop::INS},{(uint)VecVIme::IMEIMVECTORITEM1,VecWznmVIop::INS},{(uint)VecVIme::IMEIMVECTORITEM2,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMSTUBMSTUB,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMSUBSETMSUBSET,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMTABLEMVECTOR1,VecWznmVIop::INS},{(uint)VecVIme::IMEIRMTABLEMVECTOR2,VecWznmVIop::INS}};
};

uint IexWznmDbs::getIxWznmVIop(
			const map<uint,uint>& icsWznmVIop
			, const uint ixVIme
			, uint& ixWznmVIop
		) {
	ixWznmVIop = 0;

	auto it = icsWznmVIop.find(ixVIme);
	if (it != icsWznmVIop.end()) ixWznmVIop = it->second;

	return ixWznmVIop;
};

