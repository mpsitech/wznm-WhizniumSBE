/**
	* \file WznmWrsrv.cpp
	* Wznm operation pack global code (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrsrv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrsrv
 ******************************************************************************/

// IP cust --- IBEGIN
void WznmWrsrv::writeBlkcontH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, always cmbeng/eng and app

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	ubigint refC;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	outfile << "\t/**" << endl;
	outfile << "\t  * " << subsref << " (full: " << blk->sref << ")" << endl;
	outfile << "\t  */" << endl;
	outfile << "\tclass " << subsref << " : public Sbecore::Block {" << endl;
	outfile << endl;

	outfile << "\tpublic:" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		outfile << "\t\tstatic const Sbecore::uint " << StrMod::uc(bit->sref) << " = " << (i+1) << ";" << endl;
	};
	outfile << endl;

	// constructor
	outfile << "\tpublic:" << endl;
	outfile << "\t\t" << subsref << "(";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		wrBitvarConstrH(dbswznm, outfile, job, bit);
	};
	outfile << ");" << endl;
	outfile << endl;

	outfile << "\tpublic:" << endl;
	refC = 0;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if ((i != 0) && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
		wrVarDeclH(outfile, bit->ixWznmVVartype, bit->sref, 1);
		refC = bit->refWznmCAMBlockItem;
	};
	outfile << endl;
	
	outfile << "\tpublic:" << endl;
	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) {
		outfile << "\t\tbool readJSON(Json::Value& sup, bool addbasetag = false);" << endl;
		outfile << "\t\tbool readXML(xmlXPathContext* docctx, std::string basexpath = \"\", bool addbasetag = false);" << endl;
	};

	outfile << "\t\tvoid writeJSON(Json::Value& sup, std::string difftag = \"\");" << endl;
	outfile << "\t\tvoid writeXML(xmlTextWriter* wr, std::string difftag = \"\", bool shorttags = true);" << endl;
	outfile << "\t\tstd::set<Sbecore::uint> comm(const " << subsref << "* comp);" << endl;
	outfile << "\t\tstd::set<Sbecore::uint> diff(const " << subsref << "* comp);" << endl;
	outfile << "\t};" << endl;
	outfile << endl;
};

void WznmWrsrv::writeBlkcontCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, always cmbeng/eng and app

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	outfile << "/******************************************************************************" << endl;
	outfile << " class " << job->sref << "::" << subsref << endl;
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	// constructor
	outfile << job->sref << "::" << subsref << "::" << subsref << "(" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		outfile << "\t\t\t";
		if (i != 0) outfile << ", ";

		wrBitvarConstrhdrCpp(outfile, bit);
	};
	outfile << "\t\t) :" << endl;
	outfile << "\t\t\tBlock()" << endl;
	outfile << "\t\t{" << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarConstrCpp(outfile, bit);
	};
	outfile << endl;

	outfile << "\tmask = {";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << StrMod::uc(bit->sref);
	};
	outfile << "};" << endl;

	outfile << "};" << endl;
	outfile << endl;

	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) {
		// readJSON
		outfile << "bool " << job->sref << "::" << subsref << "::readJSON(" << endl;
		outfile << "\t\t\tJson::Value& sup" << endl;
		outfile << "\t\t\t, bool addbasetag" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tclear();" << endl;
		outfile << endl;

		outfile << "\tbool basefound;" << endl;
		outfile << endl;

		outfile << "\tJson::Value& me = sup;" << endl;
		outfile << "\tif (addbasetag) me = sup[\"" << blk->sref << "\"];" << endl;
		outfile << endl;

		outfile << "\tbasefound = (me != Json::nullValue);" << endl;
		outfile << endl;

		outfile << "\tif (basefound) {" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarReadjsonCpp(dbswznm, outfile, job, bit);
		};
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\treturn basefound;" << endl;
		outfile << "};" << endl;
		outfile << endl;

		// readXML
		outfile << "bool " << job->sref << "::" << subsref << "::readXML(" << endl;
		outfile << "\t\t\txmlXPathContext* docctx" << endl;
		outfile << "\t\t\t, string basexpath" << endl;
		outfile << "\t\t\t, bool addbasetag" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tclear();" << endl;
		outfile << endl;

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];
			if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\tstring sref" << StrMod::cap(bit->sref) << ";" << endl;
		};
		outfile << endl;

		outfile << "\tbool basefound;" << endl;
		outfile << endl;

		outfile << "\tif (addbasetag)" << endl;
		outfile << "\t\tbasefound = checkUclcXPaths(docctx, basexpath, basexpath, \"" << blk->sref << "\");" << endl;
		outfile << "\telse" << endl;
		outfile << "\t\tbasefound = checkXPath(docctx, basexpath);" << endl;
		outfile << endl;

		outfile << "\tstring itemtag = \"Contitem" << blk->sref.substr(4) << "\";" << endl;
		outfile << endl;

		outfile << "\tif (basefound) {" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarReadxmlCpp(dbswznm, outfile, job, bit, true, "Ci");
		};
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\treturn basefound;" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	// writeJSON
	outfile << "void " << job->sref << "::" << subsref << "::writeJSON(" << endl;
	outfile << "\t\t\tJson::Value& sup" << endl;
	outfile << "\t\t\t, string difftag" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tif (difftag.length() == 0) difftag = \"" << blk->sref << "\";" << endl;
	outfile << endl;

	outfile << "\tJson::Value& me = sup[difftag] = Json::Value(Json::objectValue);" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarWritejsonCpp(dbswznm, outfile, job, bit, false);
	};
	outfile << "};" << endl;
	outfile << endl;

	// writeXML
	outfile << "void " << job->sref << "::" << subsref << "::writeXML(" << endl;
	outfile << "\t\t\txmlTextWriter* wr" << endl;
	outfile << "\t\t\t, string difftag" << endl;
	outfile << "\t\t\t, bool shorttags" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tif (difftag.length() == 0) difftag = \"" << blk->sref << "\";" << endl;
	outfile << endl;

	outfile << "\tstring itemtag;" << endl;
	outfile << "\tif (shorttags) itemtag = \"Ci\";" << endl;
	outfile << "\telse itemtag = \"Contitem" << blk->sref.substr(4) << "\";" << endl;
	outfile << endl;

	outfile << "\txmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarWritexmlCpp(dbswznm, outfile, job, bit, false, true);
	};
	outfile << "\txmlTextWriterEndElement(wr);" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// comm
	outfile << "set<uint> " << job->sref << "::" << subsref << "::comm(" << endl;
	outfile << "\t\t\tconst " << subsref << "* comp" << endl;
	outfile << "\t\t) {" << endl;

	outfile << "\tset<uint> items;" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarCompareCpp(outfile, bit);
	};
	outfile << endl;

	outfile << "\treturn(items);" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// diff
	outfile << "set<uint> " << job->sref << "::" << subsref << "::diff(" << endl;
	outfile << "\t\t\tconst " << subsref << "* comp" << endl;
	outfile << "\t\t) {" << endl;

	outfile << "\tset<uint> commitems;" << endl;
	outfile << "\tset<uint> diffitems;" << endl;
	outfile << endl;

	outfile << "\tcommitems = comm(comp);" << endl;
	outfile << endl;

	outfile << "\tdiffitems = {";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		
		if (i != 0) outfile << ", ";
		outfile << StrMod::uc(bit->sref);
	};
	outfile << "};" << endl;
	outfile << "\tfor (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);" << endl;
	outfile << endl;

	outfile << "\treturn(diffitems);" << endl;
	outfile << "};" << endl;
	outfile << endl;
};

void WznmWrsrv::writeBlkdpchH(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// sub-block of job for engine <-> app, stand-alone for engine <-> op engine

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	WznmMTable* tbl = NULL;
	WznmMBlock* subblk = NULL;

	unsigned int ix;

	ubigint refC;

	bool first;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	if ((blk->reaIxWznmWScope & VecWznmWScope::APP) || (blk->wriIxWznmWScope & VecWznmWScope::APP)) {
		// engine <-> app dispatches (DpchApp and DpchEng)
		outfile << "\t/**" << endl;
		outfile << "\t\t* " << subsref << " (full: " << blk->sref << ")" << endl;
		outfile << "\t\t*/" << endl;

		if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
			outfile << "\tclass " << subsref << " : public DpchEng" << Prjshort << " {" << endl;
		} else {
			outfile << "\tclass " << subsref << " : public DpchApp" << Prjshort << " {" << endl;
		};
		outfile << endl;
	
		outfile << "\tpublic:" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			outfile << "\t\tstatic const Sbecore::uint " << StrMod::uc(bit->sref) << " = " << (i+1) << ";" << endl;
		};
		if (blk->reaIxWznmWScope & VecWznmWScope::APP) outfile << "\t\tstatic const Sbecore::uint ALL = " << (bits.nodes.size()+1) << ";" << endl;
		outfile << endl;

		// constructor
		outfile << "\tpublic:" << endl;
		if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
			outfile << "\t\t" << subsref << "(const Sbecore::ubigint jref = 0";

			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];

				if (bit->sref != "jref") {
					if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
						outfile << ", ";
						wrBitvarWritexmlH(dbswznm, outfile, job, bit);
					} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
						outfile << ", Sbecore::Feed* " << bit->sref << " = NULL";
					} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
						if (dbswznm->tblwznmmtable->loadRecByRef(bit->refWznmMTable, &tbl)) {
							outfile << ", List" << tbl->sref.substr(3) << "* " << bit->sref << " = NULL";
							delete tbl;
						};
					} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
						if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
							if (!isStatic(subblk)) outfile << ", " << getBlkclass(dbswznm, job, subblk) << "* " << StrMod::lc(bit->sref) << " = NULL";
							delete subblk;
						};					
					};
				};
			};

			outfile << ", const std::set<Sbecore::uint>& mask = {NONE});" << endl;

		} else {
			outfile << "\t\t" << subsref << "();" << endl;
		};
		outfile << endl;

		// variables
		outfile << "\tpublic:" << endl;
		refC = 0;
		first = true;
		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];

			if (bit->sref != "jref") {
				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
					if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
					wrVarDeclH(outfile, bit->ixWznmVVartype, bit->sref, 1);
					refC = bit->refWznmCAMBlockItem;
					first = false;

				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
					if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
					outfile << "\t\tSbecore::Feed " << bit->sref << ";" << endl;
					refC = bit->refWznmCAMBlockItem;
					first = false;

				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
					if (dbswznm->tblwznmmtable->loadRecByRef(bit->refWznmMTable, &tbl)) {
						if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
						outfile << "\t\tList" << tbl->sref.substr(3) << " " << bit->sref << ";" << endl;
						refC = bit->refWznmCAMBlockItem;
						first = false;

						delete tbl;
					};
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						if (!isStatic(subblk)) {
							if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
							outfile << "\t\t" << getBlkclass(dbswznm, job, subblk) << " " << StrMod::lc(bit->sref) << ";" << endl;
							refC = bit->refWznmCAMBlockItem;
							first = false;
						};

						delete subblk;
					};
				};
			};
		};
		outfile << endl;

		outfile << "\tpublic:" << endl;
		outfile << "\t\tstd::string getSrefsMask();" << endl;
		if (blk->reaIxWznmWScope & VecWznmWScope::APP) outfile << "\t\tvoid merge(DpchEng" << Prjshort << "* dpcheng);" << endl;
		outfile << endl;

		if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) {
			outfile << "\t\tvoid readJSON(Json::Value& sup, bool addbasetag = false);" << endl;
			outfile << "\t\tvoid readXML(xmlXPathContext* docctx, std::string basexpath = \"\", bool addbasetag = false);" << endl;
		};
		if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
			outfile << "\t\tvoid writeJSON(const Sbecore::uint ix" << Prjshort << "VLocale, Json::Value& sup);" << endl;
			outfile << "\t\tvoid writeXML(const Sbecore::uint ix" << Prjshort << "VLocale, xmlTextWriter* wr);" << endl;
		};
		outfile << "\t};" << endl;
		outfile << endl;

	} else if ((blk->reaIxWznmWScope & VecWznmWScope::OPENG) || (blk->wriIxWznmWScope & VecWznmWScope::OPENG)) {
		// engine <-> op engine dispatches (DpchInv and DpchRet); variables only
		outfile << "/**" << endl;
		outfile << "\t* " << blk->sref << endl;
		outfile << "\t*/" << endl;
		if (blk->reaIxWznmWScope & VecWznmWScope::OPENG) {
			outfile << "class " << blk->sref << " : public DpchInv" << Prjshort << " {" << endl;
		} else {
			outfile << "class " << blk->sref << " : public DpchRet" << Prjshort << " {" << endl;
		};
		outfile << endl;

		outfile << "public:" << endl;
		outfile << "\tstatic const Sbecore::uint SCROREF = 1;" << endl;
		outfile << "\tstatic const Sbecore::uint OREF = 1;" << endl;
		outfile << "\tstatic const Sbecore::uint SCRJREF = 2;" << endl;
		outfile << "\tstatic const Sbecore::uint JREF = 2;" << endl;

		if (blk->reaIxWznmWScope & VecWznmWScope::OPENG) ix = 3;
		else {
			outfile << "\tstatic const Sbecore::uint IXOPVOPRES = 3;" << endl;
			outfile << "\tstatic const Sbecore::uint PDONE = 4;" << endl;
			ix = 5;
		};

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];

			if ((bit->sref != "oref") && (bit->sref != "jref") && (bit->sref != "ixOpVOpres") && (bit->sref != "pdone")) {
				outfile << "\tstatic const Sbecore::uint " << StrMod::uc(bit->sref) << " = " << ix << ";" << endl;
				ix++;
			};
		};
		outfile << endl;

		outfile << "public:" << endl;
		outfile << "\t" << blk->sref << "(";

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];

			if (j != 0) outfile << ", ";
			wrBitvarConstrH(dbswznm, outfile, job, bit, (blk->reaIxWznmWScope & VecWznmWScope::ENG));
		};
		outfile << ");" << endl;
		outfile << endl;

		outfile << "public:" << endl;
		refC = 0;
		first = true;
		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];

			if ((bit->sref != "oref") && (bit->sref != "jref") && (bit->sref != "ixOpVOpres") && (bit->sref != "pdone")) {
				if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
				wrVarDeclH(outfile, bit->ixWznmVVartype, bit->sref, 0);
				refC = bit->refWznmCAMBlockItem;
				first = false;
			};
		};
		outfile << endl;

		outfile << "public:" << endl;
		if (blk->reaIxWznmWScope & VecWznmWScope::OPENG) {
			outfile << "\tvoid readXML(xmlXPathContext* docctx, std::string basexpath = \"\", bool addbasetag = false);" << endl;
			outfile << "\tvoid writeXML(xmlTextWriter* wr);" << endl;
		} else {
			outfile << "\tvoid readXML(xmlXPathContext* docctx, std::string basexpath = \"\", bool addbasetag = false);" << endl;
			outfile << "\tvoid writeXML(xmlTextWriter* wr);" << endl;
		};
		outfile << "};" << endl;
		outfile << endl;
	};
};

void WznmWrsrv::writeBlkdpchCpp(
			DbsWznm* dbswznm
			, const string& orgweb
			, const string& Prjshort
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// sub-block of job for engine <-> app, stand-alone for engine <-> op engine

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	WznmMTable* tbl = NULL;
	WznmMBlock* subblk = NULL;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	if ((blk->reaIxWznmWScope & VecWznmWScope::APP) || (blk->wriIxWznmWScope & VecWznmWScope::APP)) {
		// engine <-> app dispatches (DpchApp and DpchEng)
		outfile << "/******************************************************************************" << endl;
		outfile << " class " << job->sref << "::" << subsref << endl;
		outfile << " ******************************************************************************/" << endl;
		outfile << endl;

		// constructor
		if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
			outfile << job->sref << "::" << subsref << "::" << subsref << "(" << endl;
			outfile << "\t\t\tconst ubigint jref" << endl;

			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];

				if (bit->sref != "jref") {
					if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
						outfile << "\t\t\t, ";
						wrBitvarWritexmlhdrCpp(outfile, bit);
					} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
						outfile << "\t\t\t, Feed* " << bit->sref << endl;
					} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
						if (dbswznm->tblwznmmtable->loadRecByRef(bit->refWznmMTable, &tbl)) {
							outfile << "\t\t\t, List" << tbl->sref.substr(3) << "* " << bit->sref << endl;
							delete tbl;
						};
					} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
						if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
							if (!isStatic(subblk)) outfile << "\t\t\t, " << getBlkclass(dbswznm, job, subblk) << "* " << StrMod::lc(bit->sref) << endl;
							delete subblk;
						};					
					};
				};
			};

			outfile << "\t\t\t, const set<uint>& mask" << endl;
			outfile << "\t\t) :" << endl;
			outfile << "\t\t\tDpchEng" << Prjshort << "(Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << ", jref)" << endl;
			outfile << "\t\t{" << endl;

			outfile << "\tif (find(mask, ALL)) this->mask = {";
			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];

				if (i != 0) outfile << ", ";
				outfile << StrMod::uc(bit->sref);
			};
			outfile << "};" << endl;
			outfile << "\telse this->mask = mask;" << endl;
			outfile << endl;

			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];

				if (bit->sref != "jref") {
					if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
						wrBitvarConstrCpp(outfile, bit);
					} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
						outfile << "\tif (find(this->mask, " << StrMod::uc(bit->sref) << ") && " << bit->sref << ") this->" << bit->sref << " = *" << bit->sref << ";" << endl;
					} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
						outfile << "\tif (find(this->mask, " << StrMod::uc(bit->sref) << ") && " << bit->sref << ") this->" << bit->sref << " = *" << bit->sref << ";" << endl;
					} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
						if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
							if (!isStatic(subblk)) outfile << "\tif (find(this->mask, " << StrMod::uc(bit->sref) << ") && " << bit->sref << ") this->" << bit->sref << " = *" << bit->sref << ";" << endl;
							delete subblk;
						};					
					};
				};
			};

			outfile << "};" << endl;

		} else {
			outfile << job->sref << "::" << subsref << "::" << subsref << "() :" << endl;
			outfile << "\t\t\tDpchApp" << Prjshort << "(Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << ")" << endl;
			outfile << "\t\t{" << endl;

			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];

				if (bit->sref != "jref") {
					if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
						if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) {
							outfile << "\t" << bit->sref << " = false;" << endl;
						} else if ((bit->ixWznmVVartype == VecWznmVVartype::FLOAT) || (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE)) {
							outfile << "\t" << bit->sref << " = 0.0;" << endl;
						} else if ((bit->ixWznmVVartype == VecWznmVVartype::STRING) || (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) || (bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC)
									|| (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) || (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) || (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC)
									|| (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) || (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) || (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT)
									|| (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) || (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) || (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC)) {
						} else {
							// TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, VECSREF, SCRREF
							outfile << "\t" << bit->sref << " = 0;" << endl;
						};
					};
				};
			};

			outfile << "};" << endl;
		};
		outfile << endl;

		// getSrefsMask
		outfile << "string " << job->sref << "::" << subsref << "::getSrefsMask() {" << endl;
		outfile << "\tvector<string> ss;" << endl;
		outfile << "\tstring srefs;" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			outfile << "\tif (has(" << StrMod::uc(bit->sref) << ")) ss.push_back(\"" << bit->sref << "\");" << endl;
		};
		outfile << endl;

		outfile << "\tStrMod::vectorToString(ss, srefs);" << endl;
		outfile << endl;

		outfile << "\treturn(srefs);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
			// merge
			outfile << "void " << job->sref << "::" << subsref << "::merge(" << endl;
			outfile << "\t\t\tDpchEng" << Prjshort << "* dpcheng" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\t" << subsref << "* src = (" << subsref << "*) dpcheng;" << endl;
			outfile << endl;

			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];

				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
					outfile << "\tif (src->has(" << StrMod::uc(bit->sref) << ")) {" << bit->sref << " = src->" << bit->sref << "; add(" << StrMod::uc(bit->sref) << ");};" << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
					outfile << "\tif (src->has(" << StrMod::uc(bit->sref) << ")) {" << bit->sref << " = src->" << bit->sref << "; add(" << StrMod::uc(bit->sref) << ");};" << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
					outfile << "\tif (src->has(" << StrMod::uc(bit->sref) << ")) {" << bit->sref << " = src->" << bit->sref << "; add(" << StrMod::uc(bit->sref) << ");};" << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						if (isStatic(subblk)) {
							outfile << "\tif (src->has(" << StrMod::uc(bit->sref) << ")) add(" << StrMod::uc(bit->sref) << ");" << endl;
						} else {
							outfile << "\tif (src->has(" << StrMod::uc(bit->sref) << ")) {" << bit->sref << " = src->" << bit->sref << "; add(" << StrMod::uc(bit->sref) << ");};" << endl;
						};
						delete subblk;
					};					
				};
			};

			outfile << "};" << endl;
			outfile << endl;
		};

		if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) {
			// readJSON
			outfile << "void " << job->sref << "::" << subsref << "::readJSON(" << endl;
			outfile << "\t\t\tJson::Value& sup" << endl;
			outfile << "\t\t\t, bool addbasetag" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\tclear();" << endl;
			outfile << endl;

			outfile << "\tbool basefound;" << endl;
			outfile << endl;

			outfile << "\tJson::Value& me = sup;" << endl;
			outfile << "\tif (addbasetag) me = sup[\"" << blk->sref << "\"];" << endl;
			outfile << endl;

			outfile << "\tbasefound = (me != Json::nullValue);" << endl;
			outfile << endl;

			outfile << "\tif (basefound) {" << endl;
			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];

				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
					wrBitvarReadjsonCpp(dbswznm, outfile, job, bit);
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					outfile << "\t\tif (" << StrMod::lc(bit->sref) << ".readJSON(me, true)) add(" << StrMod::uc(bit->sref) << ");" << endl;
				};
			};
			outfile << "\t} else {" << endl;
			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];

				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						outfile << "\t\t" << StrMod::lc(bit->sref) << " = " << getBlkclass(dbswznm, job, subblk) << "();" << endl;
						delete subblk;
					};
				};
			};
			outfile << "\t};" << endl;
			outfile << "};" << endl;
			outfile << endl;

			// readXML
			outfile << "void " << job->sref << "::" << subsref << "::readXML(" << endl;
			outfile << "\t\t\txmlXPathContext* docctx" << endl;
			outfile << "\t\t\t, string basexpath" << endl;
			outfile << "\t\t\t, bool addbasetag" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\tclear();" << endl;
			outfile << endl;

			for (unsigned int j = 0; j < bits.nodes.size(); j++) {
				bit = bits.nodes[j];

				if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\tstring sref" << StrMod::cap(bit->sref) << ";" << endl;
				else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "\tstring scr" << StrMod::cap(bit->sref) << ";" << endl;
			};
			outfile << endl;

			outfile << "\tbool basefound;" << endl;
			outfile << endl;

			outfile << "\tif (addbasetag)" << endl;
			outfile << "\t\tbasefound = checkUclcXPaths(docctx, basexpath, basexpath, \"" << blk->sref << "\");" << endl;
			outfile << "\telse" << endl;
			outfile << "\t\tbasefound = checkXPath(docctx, basexpath);" << endl;
			outfile << endl;

			outfile << "\tif (basefound) {" << endl;
			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];

				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
					wrBitvarReadxmlCpp(dbswznm, outfile, job, bit, false, "");
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					outfile << "\t\tif (" << StrMod::lc(bit->sref) << ".readXML(docctx, basexpath, true)) add(" << StrMod::uc(bit->sref) << ");" << endl;
				};
			};
			outfile << "\t} else {" << endl;
			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];

				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						outfile << "\t\t" << StrMod::lc(bit->sref) << " = " << getBlkclass(dbswznm, job, subblk) << "();" << endl;
						delete subblk;
					};
				};
			};
			outfile << "\t};" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};

		if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
			// writeJSON
			outfile << "void " << job->sref << "::" << subsref << "::writeJSON(" << endl;
			outfile << "\t\t\tconst uint ix" << Prjshort << "VLocale" << endl;
			outfile << "\t\t\t, Json::Value& sup" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\tJson::Value& me = sup[\"" << blk->sref << "\"] = Json::Value(Json::objectValue);" << endl;
			outfile << endl;
			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];

				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
					wrBitvarWritejsonCpp(dbswznm, outfile, job, bit, true);
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
					outfile << "\tif (has(" << StrMod::uc(bit->sref) << ")) " << bit->sref << ".writeJSON(me);" << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
					outfile << "\tif (has(" << StrMod::uc(bit->sref) << ")) " << bit->sref << ".writeJSON(me);" << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						if (isStatic(subblk)) {
							if (subblk->sref.substr(0, 4+3) == "StatApp") {
								outfile << "\tif (has(" << StrMod::uc(bit->sref) << ")) " << getBlkclass(dbswznm, job, subblk) << "::writeJSON(me);" << endl;
							} else {
								outfile << "\tif (has(" << StrMod::uc(bit->sref) << ")) " << getBlkclass(dbswznm, job, subblk) << "::writeJSON(ix" << Prjshort << "VLocale, me);" << endl;
							};
						} else {
							outfile << "\tif (has(" << StrMod::uc(bit->sref) << ")) " << StrMod::lc(bit->sref) << ".writeJSON(me);" << endl;
						};
						delete subblk;
					};
				};
			};
			outfile << "};" << endl;
			outfile << endl;

			// writeXML
			outfile << "void " << job->sref << "::" << subsref << "::writeXML(" << endl;
			outfile << "\t\t\tconst uint ix" << Prjshort << "VLocale" << endl;
			outfile << "\t\t\t, xmlTextWriter* wr" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\txmlTextWriterStartElement(wr, BAD_CAST \"" << blk->sref << "\");" << endl;
			outfile << "\txmlTextWriterWriteAttribute(wr, BAD_CAST \"xmlns\", BAD_CAST \"" << orgweb << "/" << StrMod::lc(Prjshort) << "\");" << endl;
			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];

				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
					wrBitvarWritexmlCpp(dbswznm, outfile, job, bit, true, false);
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
					outfile << "\t\tif (has(" << StrMod::uc(bit->sref) << ")) " << bit->sref << ".writeXML(wr);" << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
					outfile << "\t\tif (has(" << StrMod::uc(bit->sref) << ")) " << bit->sref << ".writeXML(wr);" << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						if (isStatic(subblk)) {
							if (subblk->sref.substr(0, 4+3) == "StatApp") {
								outfile << "\t\tif (has(" << StrMod::uc(bit->sref) << ")) " << getBlkclass(dbswznm, job, subblk) << "::writeXML(wr);" << endl;
							} else {
								outfile << "\t\tif (has(" << StrMod::uc(bit->sref) << ")) " << getBlkclass(dbswznm, job, subblk) << "::writeXML(ix" << Prjshort << "VLocale, wr);" << endl;
							};
						} else {
							outfile << "\t\tif (has(" << StrMod::uc(bit->sref) << ")) " << StrMod::lc(bit->sref) << ".writeXML(wr);" << endl;
						};
						delete subblk;
					};
				};
			};
			outfile << "\txmlTextWriterEndElement(wr);" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};

	} else if ((blk->reaIxWznmWScope & VecWznmWScope::OPENG) || (blk->wriIxWznmWScope & VecWznmWScope::OPENG)) {
		// engine <-> op engine dispatches (DpchInv and DpchRet); variables only
		outfile << "/******************************************************************************" << endl;
		outfile << " class " << blk->sref << endl;
		outfile << " ******************************************************************************/" << endl;
		outfile << endl;

		// -- constructor
		outfile << blk->sref << "::" << blk->sref << "(" << endl;

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];

			outfile << "\t\t\t";
			if (j != 0) outfile << ", ";

			wrBitvarConstrhdrCpp(outfile, bit, (blk->reaIxWznmWScope & VecWznmWScope::ENG));
		};

		if (blk->reaIxWznmWScope & VecWznmWScope::OPENG) {
			outfile << "\t\t) :" << endl;
			outfile << "\t\t\tDpchInv" << Prjshort << "(Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << ", oref, jref)" << endl;
			outfile << "\t\t{" << endl;
		} else {
			outfile << "\t\t) :" << endl;
			outfile << "\t\t\tDpchRet" << Prjshort << "(Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << ", scrOref, scrJref, ixOpVOpres, pdone)" << endl;
			outfile << "\t\t{" << endl;
		};

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];
			if ((bit->sref != "oref") && (bit->sref != "jref") && (bit->sref != "ixOpVOpres") && (bit->sref != "pdone")) wrBitvarConstrCpp(outfile, bit);
		};

		outfile << "};" << endl;
		outfile << endl;

		// -- readXML
		outfile << "void " << blk->sref << "::readXML(" << endl;
		outfile << "\t\t\txmlXPathContext* docctx" << endl;
		outfile << "\t\t\t, string basexpath" << endl;
		outfile << "\t\t\t, bool addbasetag" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tclear();" << endl;
		outfile << endl;

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];
			if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\tstring sref" << StrMod::cap(bit->sref) << ";" << endl;
		};
		outfile << endl;

		outfile << "\tbool basefound;" << endl;
		outfile << endl;

		outfile << "\tif (addbasetag)" << endl;
		outfile << "\t\tbasefound = checkUclcXPaths(docctx, basexpath, basexpath, \"" << blk->sref << "\");" << endl;
		outfile << "\telse" << endl;
		outfile << "\t\tbasefound = checkXPath(docctx, basexpath);" << endl;
		outfile << endl;

		outfile << "\tif (basefound) {" << endl;
		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];
			wrBitvarReadxmlCpp(dbswznm, outfile, NULL, bit, false, "", (blk->reaIxWznmWScope & VecWznmWScope::OPENG));
		};
		outfile << "\t};" << endl;
		outfile << "};" << endl;
		outfile << endl;

		// -- writeXML
		outfile << "void " << blk->sref << "::writeXML(" << endl;
		outfile << "\t\t\txmlTextWriter* wr" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\txmlTextWriterStartElement(wr, BAD_CAST \"" << blk->sref << "\");" << endl;
		outfile << "\txmlTextWriterWriteAttribute(wr, BAD_CAST \"xmlns\", BAD_CAST \"" << orgweb << "/" << StrMod::lc(Prjshort) << "\");" << endl;
		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];
			wrBitvarWritexmlCpp(dbswznm, outfile, job, bit, false, false, (blk->wriIxWznmWScope & VecWznmWScope::OPENG));
		};
		outfile << "\txmlTextWriterEndElement(wr);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};
};

void WznmWrsrv::writeBlkstatH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, eng or app or both

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	ubigint refC;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	if (blk->sref.substr(0, 4+3) != "StatApp") {
		// StatShr
		outfile << "\t/**" << endl;
		outfile << "\t\t* " << subsref << " (full: " << blk->sref << ")" << endl;
		outfile << "\t\t*/" << endl;
		outfile << "\tclass " << subsref << " : public Sbecore::Block {" << endl;
		outfile << endl;

		outfile << "\tpublic:" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			outfile << "\t\tstatic const Sbecore::uint " << StrMod::uc(bit->sref) << " = " << (i+1) << ";" << endl;
		};
		outfile << endl;

		// constructor
		outfile << "\tpublic:" << endl;
		outfile << "\t\t" << subsref << "(";
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (i != 0) outfile << ", ";
			wrBitvarConstrH(dbswznm, outfile, job, bit);
		};
		outfile << ");" << endl;
		outfile << endl;

		outfile << "\tpublic:" << endl;
		refC = 0;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if ((i != 0) && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
			wrVarDeclH(outfile, bit->ixWznmVVartype, bit->sref, 1);
			refC = bit->refWznmCAMBlockItem;
		};
		outfile << endl;

		outfile << "\tpublic:" << endl;
		outfile << "\t\tvoid writeJSON(Json::Value& sup, std::string difftag = \"\");" << endl;
		outfile << "\t\tvoid writeXML(xmlTextWriter* wr, std::string difftag = \"\", bool shorttags = true);" << endl;
		outfile << "\t\tstd::set<Sbecore::uint> comm(const " << subsref << "* comp);" << endl;
		outfile << "\t\tstd::set<Sbecore::uint> diff(const " << subsref << "* comp);" << endl;
		outfile <<  "\t};" << endl;
		outfile << endl;

	} else {
		// StatApp
		outfile << "\t/**" << endl;
		outfile << "\t\t* " << subsref << " (full: " << blk->sref << ")" << endl;
		outfile << "\t\t*/" << endl;
		outfile << "\tclass " << subsref << " {" << endl;
		outfile << endl;

		outfile << "\tpublic:" << endl;

		outfile << "\t\tstatic void writeJSON(Json::Value& sup, std::string difftag = \"\"";
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			outfile << ", ";
			wrBitvarWritexmlH(dbswznm, outfile, job, bit);
		};
		outfile << ");" << endl;

		outfile << "\t\tstatic void writeXML(xmlTextWriter* wr, std::string difftag = \"\", bool shorttags = true";
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			outfile << ", ";
			wrBitvarWritexmlH(dbswznm, outfile, job, bit);
		};
		outfile << ");" << endl;

		outfile << "\t};" << endl;
		outfile << endl;
	};
};

void WznmWrsrv::writeBlkstatCpp(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, eng or web or both

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	outfile << "/******************************************************************************" << endl;
	outfile << " class " << job->sref << "::" << subsref << endl;
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	if (blk->sref.substr(0, 4+3) != "StatApp") {
		// - StatShr

		// constructor
		outfile << job->sref << "::" << subsref << "::" << subsref << "(" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			outfile << "\t\t\t";
			if (i != 0) outfile << ", ";

			wrBitvarConstrhdrCpp(outfile, bit);
		};
		outfile << "\t\t) :" << endl;
		outfile << "\t\t\tBlock()" << endl;
		outfile << "\t\t{" << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarConstrCpp(outfile, bit);
		};
		outfile << endl;

		outfile << "\tmask = {";
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (i != 0) outfile << ", ";
			outfile << StrMod::uc(bit->sref);
		};
		outfile << "};" << endl;

		outfile << "};" << endl;
		outfile << endl;

		// writeJSON
		outfile << "void " << job->sref << "::" << subsref << "::writeJSON(" << endl;
		outfile << "\t\t\tJson::Value& sup" << endl;
		outfile << "\t\t\t, string difftag" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tif (difftag.length() == 0) difftag = \"" << blk->sref << "\";" << endl;
		outfile << endl;

		outfile << "\tJson::Value& me = sup[difftag] = Json::Value(Json::objectValue);" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarWritejsonCpp(dbswznm, outfile, job, bit, false);
		};
		outfile << "};" << endl;
		outfile << endl;

		// writeXML
		outfile << "void " << job->sref << "::" << subsref << "::writeXML(" << endl;
		outfile << "\t\t\txmlTextWriter* wr" << endl;
		outfile << "\t\t\t, string difftag" << endl;
		outfile << "\t\t\t, bool shorttags" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tif (difftag.length() == 0) difftag = \"" << blk->sref << "\";" << endl;
		outfile << endl;

		outfile << "\tstring itemtag;" << endl;
		outfile << "\tif (shorttags) itemtag = \"Si\";" << endl;
		outfile << "\telse itemtag = \"Statitem" << blk->sref.substr(4) << "\";" << endl;
		outfile << endl;

		outfile << "\txmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarWritexmlCpp(dbswznm, outfile, job, bit, false, true);
		};
		outfile << "\txmlTextWriterEndElement(wr);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		// compare
		outfile << "set<uint> " << job->sref << "::" << subsref << "::comm(" << endl;
		outfile << "\t\t\tconst " << subsref << "* comp" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tset<uint> items;" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarCompareCpp(outfile, bit);
		};
		outfile << endl;

		outfile << "\treturn(items);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		// diff
		outfile << "set<uint> " << job->sref << "::" << subsref << "::diff(" << endl;
		outfile << "\t\t\tconst " << subsref << "* comp" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tset<uint> commitems;" << endl;
		outfile << "\tset<uint> diffitems;" << endl;
		outfile << endl;

		outfile << "\tcommitems = comm(comp);" << endl;
		outfile << endl;

		outfile << "\tdiffitems = {";
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			
			if (i != 0) outfile << ", ";
			outfile << StrMod::uc(bit->sref);
		};
		outfile << "};" << endl;
		outfile << "\tfor (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);" << endl;
		outfile << endl;

		outfile << "\treturn(diffitems);" << endl;
		outfile << "};" << endl;
		outfile << endl;

	} else {
		// - StatApp

		// writeJSON
		outfile << "void " << job->sref << "::" << subsref << "::writeJSON(" << endl;
		outfile << "\t\t\tJson::Value& sup" << endl;
		outfile << "\t\t\t, string difftag" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			outfile << "\t\t\t, ";
			wrBitvarWritexmlhdrCpp(outfile, bit);
		};
		outfile << "\t\t) {" << endl;
		outfile << "\tif (difftag.length() == 0) difftag = \"" << blk->sref << "\";" << endl;
		outfile << endl;

		outfile << "\tJson::Value& me = sup[difftag] = Json::Value(Json::objectValue);" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarWritejsonCpp(dbswznm, outfile, job, bit, false);
		};
		outfile << "};" << endl;
		outfile << endl;

		// writeXML
		outfile << "void " << job->sref << "::" << subsref << "::writeXML(" << endl;
		outfile << "\t\t\txmlTextWriter* wr" << endl;
		outfile << "\t\t\t, string difftag" << endl;
		outfile << "\t\t\t, bool shorttags" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			outfile << "\t\t\t, ";
			wrBitvarWritexmlhdrCpp(outfile, bit);
		};
		outfile << "\t\t) {" << endl;
		outfile << "\tif (difftag.length() == 0) difftag = \"" << blk->sref << "\";" << endl;
		outfile << endl;

		outfile << "\tstring itemtag;" << endl;
		outfile << "\tif (shorttags) itemtag = \"Si\";" << endl;
		outfile << "\telse itemtag = \"Statitem" << blk->sref.substr(4) << "\";" << endl;
		outfile << endl;

		outfile << "\txmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarWritexmlCpp(dbswznm, outfile, job, bit, false, true);
		};
		outfile << "\txmlTextWriterEndElement(wr);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};
};

void WznmWrsrv::writeBlkstgH(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const bool subclass
			, const string& subsref
		) {
	// optionally sub-block of job, any combination of app/cmbeng/eng/openg

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	ubigint refC;

	string pre;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	if (blk->sref.substr(0, 3+3) != "StgInf") {
		// everything that is not app-only

		if (subclass) pre = "\t";
		else pre = "";

		outfile << pre << "/**" << endl;
		if (subclass) {
			outfile << pre << "\t* " << subsref << " (full: " << blk->sref << ")" << endl;
			outfile << pre << "\t*/" << endl;
			outfile << pre << "class " << subsref << " : public Sbecore::Block {" << endl;
		} else {
			outfile << "\t* " << blk->sref << endl;
			outfile << "\t*/" << endl;
			outfile << "class " << blk->sref << " : public Sbecore::Block {" << endl;
		};
		outfile << endl;

		outfile << pre << "public:" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			outfile << pre << "\tstatic const Sbecore::uint " << StrMod::uc(bit->sref) << " = " << (i+1) << ";" << endl;
		};
		outfile << endl;

		// constructor
		outfile << pre << "public:" << endl;
		if (subclass) {
			outfile << pre << "\t" << subsref << "(";
		} else {
			outfile << pre << "\t" << blk->sref << "(";
		};
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (i != 0) outfile << ", ";
			wrBitvarConstrH(dbswznm, outfile, job, bit);
		};
		outfile << ");" << endl;
		outfile << endl;

		outfile << pre << "public:" << endl;
		refC = 0;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if ((i != 0) && (bit->refWznmCAMBlockItem != refC)) outfile << endl;

			if (subclass) wrVarDeclH(outfile, bit->ixWznmVVartype, bit->sref, 1);
			else wrVarDeclH(outfile, bit->ixWznmVVartype, bit->sref, 0);

			refC = bit->refWznmCAMBlockItem;
		};
		outfile << endl;

		outfile << pre << "public:" << endl;
		if (blk->wriIxWznmWScope & VecWznmWScope::APP) outfile << pre << "\tbool readJSON(Json::Value& sup, bool addbasetag = false);" << endl;
		outfile << pre << "\tbool readXML(xmlXPathContext* docctx, std::string basexpath = \"\", bool addbasetag = false);" << endl;
		if (blk->reaIxWznmWScope & VecWznmWScope::APP) outfile << pre << "\tvoid writeJSON(Json::Value& sup, std::string difftag = \"\");" << endl;
		outfile << pre << "\tvoid writeXML(xmlTextWriter* wr, std::string difftag = \"\", bool shorttags = true);" << endl;
		if (subclass) {
			outfile << "\t\tstd::set<Sbecore::uint> comm(const " << subsref << "* comp);" << endl;
			outfile << "\t\tstd::set<Sbecore::uint> diff(const " << subsref << "* comp);" << endl;
		} else {
			outfile << "\tstd::set<Sbecore::uint> comm(const " << blk->sref << "* comp);" << endl;
			outfile << "\tstd::set<Sbecore::uint> diff(const " << blk->sref << "* comp);" << endl;
		};
		outfile << pre << "};" << endl;
		outfile << endl;

	} else {
		// app-only version, always sub-block
		outfile << "\t/**" << endl;
		outfile << "\t\t* " << subsref << " (full: " << blk->sref << ")" << endl;
		outfile << "\t\t*/" << endl;
		outfile << "\tclass " << subsref << " {" << endl;
		outfile << endl;

		outfile << "\tpublic:" << endl;
		outfile << "\t\tstatic void writeJSON(const Sbecore::uint ix" << Prjshort << "VLocale, Json::Value& sup, std::string difftag = \"\");" << endl;
		outfile << "\t\tstatic void writeXML(const Sbecore::uint ix" << Prjshort << "VLocale, xmlTextWriter* wr, std::string difftag = \"\", bool shorttags = true);" << endl;
		outfile << "\t};" << endl;
		outfile << endl;
	};
};

void WznmWrsrv::writeBlkstgCpp(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const bool subclass
			, const string& supsref
			, const string& subsref
		) {
	// optionally sub-block of job, any combination of eng/openg/web

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	WznmMControl* con = NULL;

	vector<ubigint> refsLcl;
	ubigint refLcl;

	ListWznmMLocale lcls;
	WznmMLocale* lcl = NULL;

	string s, s2;

	string indent;

	bool found;

	Wznm::getVerlcls(dbswznm, blk->refWznmMVersion, refLcl, refsLcl, lcls);

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	outfile << "/******************************************************************************" << endl;
	if (subclass) {
		outfile << " class " << supsref << "::" << subsref << endl;
	} else {
		outfile << " class " << blk->sref << endl;
	};
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	if (blk->sref.substr(0, 3+3) != "StgInf") {
		// everything that is not app-only

		// constructor
		if (subclass) {
			outfile << supsref << "::" << subsref << "::" << subsref << "(" << endl;
		} else {
			outfile << blk->sref << "::" << blk->sref << "(" << endl;
		};
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			outfile << "\t\t\t";
			if (i != 0) outfile << ", ";

			wrBitvarConstrhdrCpp(outfile, bit);
		};
		outfile << "\t\t) :" << endl;
		outfile << "\t\t\tBlock()" << endl;
		outfile << "\t\t{" << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarConstrCpp(outfile, bit);
		};

		outfile << "\tmask = {";
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (i != 0) outfile << ", ";
			outfile << StrMod::uc(bit->sref);
		};
		outfile << "};" << endl;

		outfile << "};" << endl;
		outfile << endl;

		if (blk->wriIxWznmWScope & VecWznmWScope::APP) {
			// readJSON
			outfile << "bool " << supsref << "::" << subsref << "::readJSON(" << endl;
			outfile << "\t\t\tJson::Value& sup" << endl;
			outfile << "\t\t\t, bool addbasetag" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\tclear();" << endl;
			outfile << endl;

			outfile << "\tbool basefound;" << endl;
			outfile << endl;

			outfile << "\tJson::Value& me = sup;" << endl;
			outfile << "\tif (addbasetag) me = sup[\"" << blk->sref << "\"];" << endl;
			outfile << endl;

			outfile << "\tbasefound = (me != Json::nullValue);" << endl;
			outfile << endl;

			outfile << "\tif (basefound) {" << endl;
			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];
				wrBitvarReadjsonCpp(dbswznm, outfile, job, bit);
			};
			outfile << "\t};" << endl;
			outfile << endl;

			outfile << "\treturn basefound;" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};

		// readXML
		if (subclass) {
			outfile << "bool " << supsref << "::" << subsref << "::readXML(" << endl;
		} else {
			outfile << "bool " << blk->sref << "::readXML(" << endl;
		};
		outfile << "\t\t\txmlXPathContext* docctx" << endl;
		outfile << "\t\t\t, string basexpath" << endl;
		outfile << "\t\t\t, bool addbasetag" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tclear();" << endl;
		outfile << endl;

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];
			if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\tstring sref" << StrMod::cap(bit->sref) << ";" << endl;
		};
		outfile << endl;

		outfile << "\tbool basefound;" << endl;
		outfile << endl;

		outfile << "\tif (addbasetag)" << endl;
		outfile << "\t\tbasefound = checkUclcXPaths(docctx, basexpath, basexpath, \"" << blk->sref << "\");" << endl;
		outfile << "\telse" << endl;
		outfile << "\t\tbasefound = checkXPath(docctx, basexpath);" << endl;
		outfile << endl;

		outfile << "\tstring itemtag = \"Stgitem" << blk->sref.substr(3) << "\";" << endl;
		outfile << endl;

		outfile << "\tif (basefound) {" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarReadxmlCpp(dbswznm, outfile, job, bit, true, "Si");
		};
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\treturn basefound;" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
			// writeJSON
			outfile << "void " << supsref << "::" << subsref << "::writeJSON(" << endl;
			outfile << "\t\t\tJson::Value& sup" << endl;
			outfile << "\t\t\t, string difftag" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\tif (difftag.length() == 0) difftag = \"" << blk->sref << "\";" << endl;
			outfile << endl;

			outfile << "\tJson::Value& me = sup[difftag] = Json::Value(Json::objectValue);" << endl;
			outfile << endl;

			for (unsigned int i = 0; i < bits.nodes.size(); i++) {
				bit = bits.nodes[i];
				wrBitvarWritejsonCpp(dbswznm, outfile, job, bit, false);
			};
			outfile << "};" << endl;
			outfile << endl;
		};

		// writeXML
		if (subclass) {
			outfile << "void " << supsref << "::" << subsref << "::writeXML(" << endl;
		} else {
			outfile << "void " << blk->sref << "::writeXML(" << endl;
		};
		outfile << "\t\t\txmlTextWriter* wr" << endl;
		outfile << "\t\t\t, string difftag" << endl;
		outfile << "\t\t\t, bool shorttags" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tif (difftag.length() == 0) difftag = \"" << blk->sref << "\";" << endl;
		outfile << endl;

		outfile << "\tstring itemtag;" << endl;
		outfile << "\tif (shorttags) itemtag = \"Si\";" << endl;
		outfile << "\telse itemtag = \"Stgitem" << blk->sref.substr(3) << "\";" << endl;
		outfile << endl;

		outfile << "\txmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarWritexmlCpp(dbswznm, outfile, job, bit, false, true);
		};
		outfile << "\txmlTextWriterEndElement(wr);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		// comm
		if (subclass) {
			outfile << "set<uint> " << supsref << "::" << subsref << "::comm(" << endl;
			outfile << "\t\t\tconst " << subsref << "* comp" << endl;
		} else {
			outfile << "set<uint> " << blk->sref << "::comm(" << endl;
			outfile << "\t\t\tconst " << blk->sref << "* comp" << endl;
		};
		outfile << "\t\t) {" << endl;

		outfile << "\tset<uint> items;" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarCompareCpp(outfile, bit);
		};
		outfile << endl;

		outfile << "\treturn(items);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		// diff
		if (subclass) {
			outfile << "set<uint> " << supsref << "::" << subsref << "::diff(" << endl;
			outfile << "\t\t\tconst " << subsref << "* comp" << endl;
		} else {
			outfile << "set<uint> " << blk->sref << "::diff(" << endl;
			outfile << "\t\t\tconst " << blk->sref << "* comp" << endl;
		};
		outfile << "\t\t) {" << endl;

		outfile << "\tset<uint> commitems;" << endl;
		outfile << "\tset<uint> diffitems;" << endl;
		outfile << endl;

		outfile << "\tcommitems = comm(comp);" << endl;
		outfile << endl;

		outfile << "\tdiffitems = {";
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			
			if (i != 0) outfile << ", ";
			outfile << StrMod::uc(bit->sref);
		};
		outfile << "};" << endl;
		outfile << "\tfor (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);" << endl;
		outfile << endl;

		outfile << "\treturn(diffitems);" << endl;
		outfile << "};" << endl;
		outfile << endl;

	} else {
		// app-only version, always sub-block

		for (unsigned int k = 0; k < 2; k++) {
			if (k == 0) indent = "\t";
			else indent = "\t\t";

			if (k == 0) {
				// writeJSON
				outfile << "void " << supsref << "::" << subsref << "::writeJSON(" << endl;
				outfile << "\t\t\tconst uint ix" << Prjshort << "VLocale" << endl;
				outfile << "\t\t\t, Json::Value& sup" << endl;
				outfile << "\t\t\t, string difftag" << endl;
				outfile << "\t\t) {" << endl;
				outfile << "\tif (difftag.length() == 0) difftag = \"" << blk->sref << "\";" << endl;
				outfile << endl;

				outfile << "\tJson::Value& me = sup[difftag] = Json::Value(Json::objectValue);" << endl;
				outfile << endl;

			} else {
				// writeXML
				outfile << "void " << supsref << "::" << subsref << "::writeXML(" << endl;
				outfile << "\t\t\tconst uint ix" << Prjshort << "VLocale" << endl;
				outfile << "\t\t\t, xmlTextWriter* wr" << endl;
				outfile << "\t\t\t, string difftag" << endl;
				outfile << "\t\t\t, bool shorttags" << endl;
				outfile << "\t\t) {" << endl;
				outfile << "\tif (difftag.length() == 0) difftag = \"" << blk->sref << "\";" << endl;
				outfile << endl;

				outfile << "\tstring itemtag;" << endl;
				outfile << "\tif (shorttags) itemtag = \"Si\";" << endl;
				outfile << "\telse itemtag = \"Stgitem" << blk->sref.substr(3) << "\";" << endl;
				outfile << endl;

				outfile << "\txmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());" << endl;
			};

			// control parameters only

			// output by locale
			for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
				lcl = lcls.nodes[i];

				outfile << indent;
				if (i != 0) outfile << "} else ";
				outfile << "if (ix" << Prjshort << "VLocale == Vec" << Prjshort << "VLocale::" << StrMod::uc(lcl->sref) << ") {" << endl;

				for (unsigned int j = 0; j < bits.nodes.size(); j++) {
					bit = bits.nodes[j];

					if (dbswznm->tblwznmmcontrol->loadRecByRef(bit->refWznmMControl, &con)) {
						// isolate parameter sref
						if (bit->sref.length() > con->sref.length()) {
							s = StrMod::lc(bit->sref.substr(con->sref.length()));

							found = true;
							if (!dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, s, lcl->ref, s2)) {
								if (!dbswznm->tblwznmamcontrolpar->loadValByConKeyLoc(con->ref, s, 0, s2)) found = false;
							};

							if (found) {
								if (k == 0) outfile << indent << "\tme[\"" << bit->sref << "\"] = \"" << StrMod::esc(s2) << "\";" << endl;
								else outfile << indent << "\twriteStringAttr(wr, itemtag, \"sref\", \"" << bit->sref << "\", \"" << StrMod::esc(s2) << "\");" << endl;
							} else {
								if (k == 0) outfile << indent << "\tme[\"" << bit->sref << "\"] = \"" << StrMod::esc(bit->Defval) << "\";" << endl;
								else outfile << indent << "\twriteStringAttr(wr, itemtag, \"sref\", \"" << bit->sref << "\", \"" << StrMod::esc(bit->Defval) << "\");" << endl;
							};
						};
						delete con;
					};
				};
			};
			if (lcls.nodes.size() > 0) outfile << indent << "};" << endl;

			if (k == 1) outfile << "\txmlTextWriterEndElement(wr);" << endl;

			outfile << "};" << endl;
			outfile << endl;
		};
	};
};

void WznmWrsrv::writeBlktagH(
			const string& Prjshort
			, fstream& outfile
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, always app
	outfile << "\t/**" << endl;
	outfile << "\t\t* " << subsref << " (full: " << blk->sref << ")" << endl;
	outfile << "\t\t*/" << endl;
	outfile << "\tclass " << subsref << " {" << endl;
	outfile << endl;

	outfile << "\tpublic:" << endl;
	outfile << "\t\tstatic void writeJSON(const Sbecore::uint ix" << Prjshort << "VLocale, Json::Value& sup, std::string difftag = \"\");" << endl;
	outfile << "\t\tstatic void writeXML(const Sbecore::uint ix" << Prjshort << "VLocale, xmlTextWriter* wr, std::string difftag = \"\", bool shorttags = true);" << endl;
	outfile << "\t};" << endl;
	outfile << endl;
};

void WznmWrsrv::writeBlktagCpp(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, always app, control titles only

	vector<ubigint> refsWith;
	vector<bool> capsWith;
	vector<bool> dddsWith;
	vector<ubigint> refsWithout;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	vector<ubigint> refsLcl;
	ubigint refLcl;

	ListWznmMLocale lcls;
	WznmMLocale* lcl = NULL;

	WznmMControl* con = NULL;

	vector<string> ss;
	string s;

	string indent;

	unsigned int ix;

	bool found;

	bool cap, ddd;

	Wznm::getVerlcls(dbswznm, blk->refWznmMVersion, refLcl, refsLcl, lcls);

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	outfile << "/******************************************************************************" << endl;
	outfile << " class " << job->sref << "::" << subsref << endl;
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	for (unsigned int k = 0; k < 2; k++) {
		if (k == 0) indent = "\t";
		else indent = "\t\t";

		if (k == 0) {
			// writeJSON
			outfile << "void " << job->sref << "::" << subsref << "::writeJSON(" << endl;
			outfile << "\t\t\tconst uint ix" << Prjshort << "VLocale" << endl;
			outfile << "\t\t\t, Json::Value& sup" << endl;
			outfile << "\t\t\t, string difftag" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\tif (difftag.length() == 0) difftag = \"" << blk->sref << "\";" << endl;
			outfile << endl;

			outfile << "\tJson::Value& me = sup[difftag] = Json::Value(Json::objectValue);" << endl;
			outfile << endl;

		} else {
			// writeXML
			outfile << "void " << job->sref << "::" << subsref << "::writeXML(" << endl;
			outfile << "\t\t\tconst uint ix" << Prjshort << "VLocale" << endl;
			outfile << "\t\t\t, xmlTextWriter* wr" << endl;
			outfile << "\t\t\t, string difftag" << endl;
			outfile << "\t\t\t, bool shorttags" << endl;
			outfile << "\t\t) {" << endl;
			outfile << "\tif (difftag.length() == 0) difftag = \"" << blk->sref << "\";" << endl;
			outfile << endl;

			outfile << "\tstring itemtag;" << endl;
			outfile << "\tif (shorttags) itemtag = \"Ti\";" << endl;
			outfile << "\telse itemtag = \"Tagitem" << blk->sref.substr(3) << "\";" << endl;
			outfile << endl;

			outfile << "\txmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());" << endl;
		};

		// sort control titles by with/without tag
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::CONTIT) {
				if (dbswznm->tblwznmmcontrol->loadRecByRef(bit->refWznmMControl, &con)) {
					if (con->srefsWznmMTag.length() == 0) refsWithout.push_back(bit->ref);
					else {
						refsWith.push_back(bit->ref);
						capsWith.push_back(StrMod::srefInSrefs(con->srefsKOption, "cap"));
						dddsWith.push_back(StrMod::srefInSrefs(con->srefsKOption, "ddd"));
					};

					delete con;
				};
			};
		};

		// output by locale for control titles without tag
		for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
			lcl = lcls.nodes[i];

			outfile << indent;
			if (i != 0) outfile << "} else ";
			outfile << "if (ix" << Prjshort << "VLocale == Vec" << Prjshort << "VLocale::" << StrMod::uc(lcl->sref) << ") {" << endl;

			for (unsigned int j = 0; j < bits.nodes.size(); j++) {
				bit = bits.nodes[j];

				found = false;
				for (unsigned int k = 0; k < refsWithout.size(); k++) {
					if (refsWithout[k] == bit->ref) {
						found = true;
						break;
					};
				};

				if (found) {
					// copy localized control title
					if (!dbswznm->tblwznmjmcontroltitle->loadTitByConLoc(bit->refWznmMControl, lcl->ref, s))
								dbswznm->loadStringBySQL("SELECT Title FROM TblWznmMControl WHERE ref = " + to_string(bit->refWznmMControl), s);

					if (k == 0) outfile << indent << "\tme[\"" << bit->sref << "\"] = \"" << StrMod::esc(s) << "\";" << endl;
					else outfile << indent << "\twriteStringAttr(wr, itemtag, \"sref\", \"" << bit->sref << "\", \"" << StrMod::esc(s) << "\");" << endl;
				};
			};
		};
		if (lcls.nodes.size() > 0) outfile << indent << "};" << endl;

		// output using the tag vector
		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];

			found = false;
			for (unsigned int k = 0; k < refsWith.size(); k++) {
				if (refsWith[k] == bit->ref) {
					cap = capsWith[k];
					ddd = dddsWith[k];

					found = true;
					break;
				};
			};

			if (found) {
				if (dbswznm->tblwznmmcontrol->loadRecByRef(bit->refWznmMControl, &con)) {
					if (bit->sref.length() > con->sref.length()) {
						ix = atoi(bit->sref.substr(con->sref.length()).c_str());
						if (ix >= 1) ix--;
					} else {
						ix = 0;
					};

					StrMod::srefsToVector(con->srefsWznmMTag, ss);
					if (ss.size() > ix) {
						if (k == 0) outfile << indent << "me[\"" << bit->sref << "\"] = ";
						else outfile << indent << "writeStringAttr(wr, itemtag, \"sref\", \"" << bit->sref << "\", ";

						if (cap) outfile << "StrMod::cap(";
						outfile << "Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::" << StrMod::uc(ss[ix]) << ", ix" << Prjshort << "VLocale)";
						if (cap) outfile << ")";
						if (ddd) outfile << " + \" ...\"";

						if (k == 0) outfile << ";" << endl;
						else outfile << ");" << endl;
					};

					delete con;
				};
			};
		};

		if (k == 1) outfile << "\txmlTextWriterEndElement(wr);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};
};

void WznmWrsrv::writeVecH(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMVector* vec
			, const bool subclass
			, const string& subsref
			, const unsigned int subil
		) {
	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	string indent;
	string pre;

	unsigned int ix;

	bool lin, noloc, notit, cmt, apdfed, filfed;

	lin = (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN);
	noloc = StrMod::srefInSrefs(vec->srefsKOption, "noloc");
	notit = StrMod::srefInSrefs(vec->srefsKOption, "notit");
	cmt = StrMod::srefInSrefs(vec->srefsKOption, "cmt");
	apdfed = StrMod::srefInSrefs(vec->srefsKOption, "apdfed");
	filfed = StrMod::srefInSrefs(vec->srefsKOption, "filfed");

	dbswznm->tblwznmmvectoritem->loadRstByVec(vec->ref, false, vits);

	if (subclass) for (unsigned int i = 0; i < subil; i++) indent += "\t";

	if (subclass) {
		outfile << indent << "/**" << endl;
		outfile << indent << "\t* " << subsref << " (full: " << vec->sref << ")" << endl;
		outfile << indent << "\t*/" << endl;

		outfile << indent << "class " << subsref << " {" << endl;
		outfile << endl;
		outfile << indent << "public:" << endl;

		ix = 1;
		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			outfile << indent << "\tstatic const Sbecore::uint " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << " = " << ix << ";" << endl;

			if (lin) ix++;
			else ix *= 2;
		};
		outfile << endl;

	} else {
		outfile << "/**" << endl;
		outfile << "\t* " << vec->sref << endl;
		outfile << "\t*/" << endl;

		outfile << "namespace " << vec->sref << " {" << endl;

		ix = 1;
		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			outfile << "\tconst Sbecore::uint " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << " = " << ix << ";" << endl;

			if (lin) ix++;
			else ix *= 2;
		};
		outfile << endl;
	};

	if (subclass) pre = indent + "\tstatic ";
	else pre = "\t";

	if (lin) {
		outfile << pre << "Sbecore::uint getIx(const std::string& sref);" << endl;
	} else {
		outfile << pre << "Sbecore::uint getIx(const std::string& srefs);" << endl;
		outfile << pre << "void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);" << endl;
	};
	if (lin) {
		outfile << pre << "std::string getSref(const Sbecore::uint ix);" << endl;
	} else {
		outfile << pre << "std::string getSrefs(const Sbecore::uint ix);" << endl;
	};

	if (!notit || cmt) {
		outfile << endl;
		if (!notit) {
			// getTitle
			outfile << pre << "std::string getTitle(const Sbecore::uint ix";
			if (!noloc) outfile << ", const Sbecore::uint ix" << Prjshort << "VLocale";
			outfile << ");" << endl;
		};
		if (cmt) {
			// getComment
			outfile << pre << "std::string getComment(const Sbecore::uint ix";
			if (!noloc) outfile << ", const Sbecore::uint ix" << Prjshort << "VLocale";
			outfile << ");" << endl;
		};
	};

	if (apdfed || filfed) {
		outfile << endl;
		if (apdfed) {
			outfile << pre << "void appendToFeed(const Sbecore::uint ix";
			if (!noloc) outfile << ", const Sbecore::uint ix" << Prjshort << "VLocale";
			outfile << ", Sbecore::Feed& feed);" << endl;
		};
		if (filfed) {
			outfile << pre << "void fillFeed(";
			if (!noloc) outfile << "const Sbecore::uint ix" << Prjshort << "VLocale, ";
			outfile << "Sbecore::Feed& feed);" << endl;
		};
	};

	if (subclass) outfile << indent;
	outfile << "};" << endl;

	outfile << endl;
};

void WznmWrsrv::writeVecCpp(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMVector* vec
			, const bool subclass
			, const string& supsref
			, const string& subsref
			, ubigint refLcl
			, const vector<ubigint>& refsLcl
		) {
	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	unsigned int ix;
	string val;

	bool lin, noloc, notit, cmt, apdfed, filfed;

	lin = (vec->ixVBasetype == VecWznmVMVectorBasetype::LIN);
	noloc = StrMod::srefInSrefs(vec->srefsKOption, "noloc");
	notit = StrMod::srefInSrefs(vec->srefsKOption, "notit");
	cmt = StrMod::srefInSrefs(vec->srefsKOption, "cmt");
	apdfed = StrMod::srefInSrefs(vec->srefsKOption, "apdfed");
	filfed = StrMod::srefInSrefs(vec->srefsKOption, "filfed");

	dbswznm->tblwznmmvectoritem->loadRstByVec(vec->ref, false, vits);

	outfile << "/******************************************************************************" << endl;
	if (subclass) outfile << " class " << supsref << "::" << subsref << endl;
	else outfile << " namespace " << vec->sref << endl;
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	if (lin) {
		// getIx
		if (subclass) outfile << "uint " << supsref << "::" << subsref << "::getIx(" << endl;
		else outfile << "uint " << vec->sref << "::getIx(" << endl;
		outfile << "\t\t\tconst string& sref" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tstring s = StrMod::lc(sref);" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			outfile << "\tif (s == \"" << StrMod::lc(vit->sref) << "\") return " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ";" << endl;
		};
		outfile << endl;

		outfile << "\treturn(0);" << endl;
		outfile << "};" << endl;
		outfile << endl;

	} else {
		// getIx
		if (subclass) outfile << "uint " << supsref << "::" << subsref << "::getIx(" << endl;
		else outfile << "uint " << vec->sref << "::getIx(" << endl;
		outfile << "\t\t\tconst string& srefs" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tuint ix = 0;" << endl;
		outfile << endl;

		outfile << "\tvector<string> ss;" << endl;
		outfile << "\tStrMod::srefsToVector(StrMod::lc(srefs), ss);" << endl;
		outfile << endl;

		outfile << "\tfor (unsigned int i = 0; i < ss.size(); i++) {" << endl;
		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			outfile << "\t\t";
			if (i != 0) outfile << "else ";
			outfile << "if (ss[i] == \"" << StrMod::lc(vit->sref) << "\") ix |= " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ";" << endl;
		};
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\treturn(ix);" << endl;
		outfile << "};" << endl;
		outfile << endl;

		// getIcs
		if (subclass) outfile << "void " << supsref << "::" << subsref << "::getIcs(" << endl;
		else outfile << "void " << vec->sref << "::getIcs(" << endl;
		outfile << "\t\t\tconst uint ix" << endl;
		outfile << "\t\t\t, set<uint>& ics" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tics.clear();" << endl;
		if (vits.nodes.size() == 0) {
			outfile << "\tfor (unsigned int i = 1; false;) if (ix & i) ics.insert(i);" << endl;
		} else {
			outfile << "\tfor (unsigned int i = 1; i < (2*" << StrMod::uc(StrMod::dotToUsc(vits.nodes[vits.nodes.size()-1]->sref)) << "); i *= 2) if (ix & i) ics.insert(i);" << endl;
		};
		outfile << "};" << endl;
		outfile << endl;
	};

	if (lin) {
		// getSref
		if (subclass) outfile << "string " << supsref << "::" << subsref << "::getSref(" << endl;
		else outfile << "string " << vec->sref << "::getSref(" << endl;
		outfile << "\t\t\tconst uint ix" << endl;
		outfile << "\t\t) {" << endl;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			outfile << "\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << vit->sref << "\");" << endl;
		};
		outfile << endl;

		outfile << "\treturn(\"\");" << endl;
		outfile << "};" << endl;
		outfile << endl;

	} else {
		// getSrefs
		if (subclass) outfile << "string " << supsref << "::" << subsref << "::getSrefs(" << endl;
		else outfile << "string " << vec->sref << "::getSrefs(" << endl;
		outfile << "\t\t\tconst uint ix" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tvector<string> ss;" << endl;
		outfile << "\tstring srefs;" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			outfile << "\tif (ix & " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") ss.push_back(\"" << vit->sref << "\");" << endl;
		};
		outfile << endl;

		outfile << "\tStrMod::vectorToString(ss, srefs);" << endl;
		outfile << endl;

		outfile << "\treturn(srefs);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	// getTitle
	if (!notit) {
		if (subclass) outfile << "string " << supsref << "::" << subsref << "::getTitle(" << endl;
		else outfile << "string " << vec->sref << "::getTitle(" << endl;
		outfile << "\t\t\tconst uint ix" << endl;
		if (!noloc) outfile << "\t\t\t, const uint ix" << Prjshort << "VLocale" << endl;
		outfile << "\t\t) {" << endl;

		if (!noloc) {
			// localized version: ixXxxxVLocale == 1 default locale, other locales refsLcl
			outfile << "\tif (ix" << Prjshort << "VLocale == 1) {" << endl;
			for (unsigned int i = 0; i < vits.nodes.size(); i++) {
				vit = vits.nodes[i];

				if (!dbswznm->loadStringBySQL("SELECT Title FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = " + to_string(vit->ref) + " AND x1RefWznmMLocale = " + to_string(refLcl), val)) val = vit->Title;

				if (val.length() != 0) outfile << "\t\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << StrMod::esc(val) << "\");" << endl;
			};

			if (lin) outfile << "\t\treturn(getSref(ix));" << endl;
			else outfile << "\t\treturn(getSrefs(ix));" << endl;

			ix = 2;
			for (unsigned int i = 0; i < refsLcl.size(); i++) {
				if (refsLcl[i] != refLcl) {
					outfile << "\t} else if (ix" << Prjshort << "VLocale == " << ix << ") {" << endl;
					for (unsigned int j = 0; j < vits.nodes.size(); j++) {
						vit = vits.nodes[j];

						if (!dbswznm->loadStringBySQL("SELECT Title FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = " + to_string(vit->ref) + " AND x1RefWznmMLocale = " + to_string(refsLcl[i]), val)) val = "";

						if (val.length() != 0) outfile << "\t\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << StrMod::esc(val) << "\");" << endl;
					};

					outfile << "\t\treturn(getTitle(ix, 1));" << endl;
					ix++;
				};
			};

			outfile << "\t};" << endl;

		} else {
			// non-localized version
			for (unsigned int i = 0; i < vits.nodes.size(); i++) {
				vit = vits.nodes[i];
				if (vit->Title.length() != 0) outfile << "\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << StrMod::esc(vit->Title) << "\");" << endl;
			};

			if (lin) outfile << "\treturn(getSref(ix));" << endl;
			else outfile << "\treturn(getSrefs(ix));" << endl;
		};

		outfile << endl;
		outfile << "\treturn(\"\");" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	// getComment
	if (cmt) {
		if (subclass) outfile << "string " << supsref << "::" << subsref << "::getComment(" << endl;
		else outfile << "string " << vec->sref << "::getComment(" << endl;
		outfile << "\t\t\tconst uint ix" << endl;
		if (!noloc) outfile << "\t\t\t, const uint ix" << Prjshort << "VLocale" << endl;
		outfile << "\t\t) {" << endl;

		if (!noloc) {
			// localized version: ixXxxxVLocale == 1 default locale, other locales refsLcl
			outfile << "\tif (ix" << Prjshort << "VLocale == 1) {" << endl;
			for (unsigned int i = 0; i < vits.nodes.size(); i++) {
				vit = vits.nodes[i];

				if (!dbswznm->loadStringBySQL("SELECT Comment FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = " + to_string(vit->ref) + " AND x1RefWznmMLocale = " + to_string(refLcl), val)) val = vit->Comment;

				if (val.length() != 0) outfile << "\t\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << StrMod::esc(val) << "\");" << endl;
			};

			ix = 2;
			for (unsigned int i = 0; i < refsLcl.size(); i++) {
				if (refsLcl[i] != refLcl) {
					outfile << "\t} else if (ix" << Prjshort << "VLocale == " << ix << ") {" << endl;
					for (unsigned int j = 0; j < vits.nodes.size(); j++) {
						vit = vits.nodes[j];

						if (!dbswznm->loadStringBySQL("SELECT Comment FROM TblWznmJMVectoritem WHERE refWznmMVectoritem = " + to_string(vit->ref) + " AND x1RefWznmMLocale = " + to_string(refsLcl[i]), val)) val = "";

						if (val.length() != 0) outfile << "\t\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << StrMod::esc(val) << "\");" << endl;
					};

					ix++;
				};
			};

			outfile << "\t};" << endl;

		} else {
			// non-localized version
			for (unsigned int i = 0; i < vits.nodes.size(); i++) {
				vit = vits.nodes[i];
				if (vit->Comment.length() != 0) outfile << "\tif (ix == " << StrMod::uc(StrMod::dotToUsc(vit->sref)) << ") return(\"" << StrMod::esc(vit->Comment) << "\");" << endl;
			};
		};

		outfile << endl;
		outfile << "\treturn(\"\");" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	// appendToFeed
	if (apdfed) {
		if (subclass) outfile << "void " << supsref << "::" << subsref << "::appendToFeed(" << endl;
		else outfile << "void " << vec->sref << "::appendToFeed(" << endl;
		outfile << "\t\t\tconst uint ix" << endl;
		if (!noloc) outfile << "\t\t\t, const uint ix" << Prjshort << "VLocale" << endl;
		outfile << "\t\t\t, Feed& feed" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tfeed.appendIxSrefTitles(ix";
		if (lin) outfile << ", getSref(ix)";
		else outfile << ", getSrefs(ix)";
		if (!notit) {
			outfile << ", getTitle(ix";
			if (!noloc) outfile << ", ix" << Prjshort << "VLocale";
			outfile << ")";
		} else {
			if (lin) outfile << ", getSref(ix)";
			else outfile << ", getSrefs(ix)";
		};
		outfile << ");" << endl;

		outfile << "};" << endl;
		outfile << endl;
	};

	// fillFeed
	if (filfed) {
		if (subclass) outfile << "void " << supsref << "::" << subsref << "::fillFeed(" << endl;
		else outfile << "void " << vec->sref << "::fillFeed(" << endl;
		if (!noloc) {
			outfile << "\t\t\tconst uint ix" << Prjshort << "VLocale" << endl;
			outfile << "\t\t\t, Feed& feed" << endl;
		} else {
			outfile << "\t\t\tFeed& feed" << endl;
		};
		outfile << "\t\t) {" << endl;

		outfile << "\tfeed.clear();" << endl;
		outfile << endl;

		if (lin) {
			outfile << "\tfor (unsigned int i = 1; i <= " << vits.nodes.size() << "; i++) ";
		} else {
			if (vits.nodes.size() == 0) {
				outfile << "\tfor (unsigned int i = 1; false;) ";
			} else {
				outfile << "\tfor (unsigned int i = 1; i <= " << StrMod::uc(StrMod::dotToUsc(vits.nodes[vits.nodes.size()-1]->sref)) << "; i *= 2) ";
			};
		};

		outfile << "feed.appendIxSrefTitles(i";
		if (lin) outfile << ", getSref(i)";
		else outfile << ", getSrefs(i)";
		if (!notit) {
			outfile << ", getTitle(i";
			if (!noloc) outfile << ", ix" << Prjshort << "VLocale";
			outfile << ")";
		} else {
			if (lin) outfile << ", getSref(i)";
			else outfile << ", getSrefs(i)";
		};
		outfile << ");" << endl;

		outfile << "};" << endl;
		outfile << endl;
	};
};

void WznmWrsrv::wrBitvarConstrH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmAMBlockItem* bit
			, const bool scrsimple
		) {
	WznmMVector* vec = NULL;

	string s;

	if (bit->ixWznmVVartype == VecWznmVVartype::VOID) {
		outfile << "const void " << bit->sref << " = 0";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) {
		outfile << "const bool " << bit->sref << " = ";
		if (bit->Defval.length() == 0) outfile << "false"; else outfile << bit->Defval;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::INT) {
		outfile << "const int " << bit->sref << " = ";
		if (bit->Defval.length() == 0) outfile << "0"; else outfile << bit->Defval;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOAT) {
		outfile << "const float " << bit->sref << " = ";
		if (bit->Defval.length() == 0) outfile << "0.0"; else outfile << bit->Defval;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE) {
		outfile << "const double " << bit->sref << " = ";
		if (bit->Defval.length() == 0) outfile << "0.0"; else outfile << bit->Defval;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRING) {
		outfile << "const std::string& " << bit->sref << " = \"" << StrMod::esc(bit->Defval) << "\"";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) {
		outfile << "const std::vector<bool>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) {
		outfile << "const std::vector<Sbecore::utinyint>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) {
		outfile << "const std::vector<Sbecore::usmallint>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) {
		outfile << "const std::vector<int>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC) {
		outfile << "const std::vector<Sbecore::uint>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) {
		outfile << "const std::vector<Sbecore::ubigint>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) {
		outfile << "const std::vector<float>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) {
		outfile << "const Sbecore::Floatmat& " << bit->sref << " = Sbecore::Floatmat()";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) {
		outfile << "const std::vector<double>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) {
		outfile << "const Sbecore::Doublemat& " << bit->sref << " = Sbecore::Doublemat()";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) {
		outfile << "const std::vector<std::string>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
		outfile << "const Sbecore::uint " << bit->sref << " = ";
		if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
			if (dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMVectoritem WHERE ref = " + to_string(bit->refWznmMVectoritem), s)) {
				outfile << getVecclass(dbswznm, job, vec) << "::" << StrMod::uc(s);
			} else {
				outfile << "0";
			};
			delete vec;

		} else {
			outfile << "0";
		};
	} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
		if (scrsimple) outfile << "const std::string& scr" << StrMod::cap(bit->sref) << " = \"\"";
		else outfile << "const Sbecore::ubigint " << bit->sref << " = 0";
	} else {
		// TINYINT, UTINYINT, SMALLINT, USMALLINT, UINT, BIGINT, UBIGINT
		outfile << "const Sbecore::" << VecWznmVVartype::getSref(bit->ixWznmVVartype) << " " << bit->sref << " = ";
		if (bit->Defval.length() == 0) outfile << "0"; else outfile << bit->Defval;
	};
};

void WznmWrsrv::wrVarDeclH(
			fstream& outfile
			, const uint ixWznmVVartype
			, const string& sref
			, const unsigned int il
		) {
	outfile << "\t";
	for (unsigned int i = 0; i < il; i++) outfile << "\t";

	if (ixWznmVVartype == VecWznmVVartype::VOID) outfile << "void";
	else if (ixWznmVVartype == VecWznmVVartype::BOOLEAN) outfile << "bool";
	else if (ixWznmVVartype == VecWznmVVartype::INT) outfile << "int";
	else if (ixWznmVVartype == VecWznmVVartype::FLOAT) outfile << "float";
	else if (ixWznmVVartype == VecWznmVVartype::DOUBLE) outfile << "double";
	else if (ixWznmVVartype == VecWznmVVartype::STRING) outfile << "std::string";
	else if (ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) outfile << "std::vector<bool>";
	else if (ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) outfile << "std::vector<Sbecore::utinyint>";
	else if (ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) outfile << "std::vector<Sbecore::smallint>";
	else if (ixWznmVVartype == VecWznmVVartype::INTVEC) outfile << "std::vector<int>";
	else if (ixWznmVVartype == VecWznmVVartype::UINTVEC) outfile << "std::vector<Sbecore::uint>";
	else if (ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) outfile << "std::vector<Sbecore::ubigint>";
	else if (ixWznmVVartype == VecWznmVVartype::FLOATVEC) outfile << "std::vector<float>";
	else if (ixWznmVVartype == VecWznmVVartype::FLOATMAT) outfile << "Sbecore::Floatmat";
	else if (ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) outfile << "std::vector<double>";
	else if (ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) outfile << "Sbecore::Doublemat";
	else if (ixWznmVVartype == VecWznmVVartype::STRINGVEC) outfile << "std::vector<std::string>";
	else if (ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "Sbecore::uint";
	else if (ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "Sbecore::ubigint";
	else {
		// TINYINT, UTINYINT, SMALLINT, USMALLINT, UINT, BIGINT, UBIGINT
		outfile << "Sbecore::" << VecWznmVVartype::getSref(ixWznmVVartype);
	};

	outfile << " " << sref << ";" << endl;
};

void WznmWrsrv::wrBitvarConstrhdrCpp(
			fstream& outfile
			, WznmAMBlockItem* bit
			, const bool scrsimple
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) {
		outfile << "const bool " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRING) {
		outfile << "const string& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) {
		outfile << "const vector<bool>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) {
		outfile << "const vector<utinyint>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) {
		outfile << "const vector<usmallint>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) {
		outfile << "const vector<int>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC) {
		outfile << "const vector<uint>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) {
		outfile << "const vector<ubigint>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) {
		outfile << "const vector<float>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) {
		outfile << "const Floatmat& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) {
		outfile << "const vector<double>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) {
		outfile << "const Doublemat& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) {
		outfile << "const vector<string>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
		outfile << "const uint " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
		if (scrsimple) outfile << "const string& scr" << StrMod::cap(bit->sref) << endl;
		else outfile << "const ubigint " << bit->sref << endl;
	} else {
		// VOID, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, FLOAT, DOUBLE
		outfile << "const " << VecWznmVVartype::getSref(bit->ixWznmVVartype) << " " << bit->sref << endl;
	};
};

void WznmWrsrv::wrBitvarConstrCpp(
			fstream& outfile
			, WznmAMBlockItem* bit
		) {
	outfile << "\tthis->" << bit->sref << " = " << bit->sref << ";" << endl;
};

void WznmWrsrv::wrBitvarReadjsonCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmAMBlockItem* bit
		) {
	WznmMVector* vec = NULL;

	string s;

	if ((bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) || (bit->ixWznmVVartype == VecWznmVVartype::TINYINT) || (bit->ixWznmVVartype == VecWznmVVartype::UTINYINT) || (bit->ixWznmVVartype == VecWznmVVartype::SMALLINT)
				|| (bit->ixWznmVVartype == VecWznmVVartype::USMALLINT) || (bit->ixWznmVVartype == VecWznmVVartype::INT) || (bit->ixWznmVVartype == VecWznmVVartype::UINT) || (bit->ixWznmVVartype == VecWznmVVartype::BIGINT)
				|| (bit->ixWznmVVartype == VecWznmVVartype::UBIGINT) || (bit->ixWznmVVartype == VecWznmVVartype::FLOAT) || (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE) || (bit->ixWznmVVartype == VecWznmVVartype::STRING)) {

		outfile << "\t\tif (me.isMember(\"" << bit->sref << "\")) {" << bit->sref << " = me[\"" << bit->sref << "\"].";

		if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) outfile << "asBool";
		else if ((bit->ixWznmVVartype == VecWznmVVartype::TINYINT) || (bit->ixWznmVVartype == VecWznmVVartype::SMALLINT) || (bit->ixWznmVVartype == VecWznmVVartype::INT)) outfile << "asInt";
		else if ((bit->ixWznmVVartype == VecWznmVVartype::UTINYINT) || (bit->ixWznmVVartype == VecWznmVVartype::USMALLINT) || (bit->ixWznmVVartype == VecWznmVVartype::UINT)) outfile << "asUInt";
		else if (bit->ixWznmVVartype == VecWznmVVartype::BIGINT) outfile << "asInt64";
		else if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINT) outfile << "asUInt64";
		else if (bit->ixWznmVVartype == VecWznmVVartype::FLOAT) outfile << "asFloat";
		else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE) outfile << "asDouble";
		else if (bit->ixWznmVVartype == VecWznmVVartype::STRING) outfile << "asString";

		outfile << "(); add(" << StrMod::uc(bit->sref) << ");};" << endl;

	} else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
		outfile << "\t\tif (me.isMember(\"sref" << StrMod::cap(bit->sref) << "\")) {" << bit->sref << " = ";
		if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
			outfile << getVecclass(dbswznm, job, vec);
			delete vec;
		} else outfile << "Vec" << bit->sref.substr(2);
		outfile << "::getIx(me[\"sref" << StrMod::cap(bit->sref) << "\"].asString()); add(" << StrMod::uc(bit->sref) << ");};" << endl;

	} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
		outfile << "\t\tif (me.isMember(\"scr" << StrMod::cap(bit->sref) << "\")) {" << bit->sref << " = Scr::descramble(me[\"scr" << StrMod::cap(bit->sref) << "\"].asString()); add(" << StrMod::uc(bit->sref) << ");};" << endl;

	} else {
		// VOID, BOOLEANVEC, UTINYINTVEC, USMALLINTVEC, INTVEC, UINTVEC, UBIGINTVEC, FLOATVEC, FLOATMAT, DOUBLEVEC, DOUBLEMAT, STRINGVEC
		if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) s = "Boolvec";
		else s = StrMod::cap(VecWznmVVartype::getSref(bit->ixWznmVVartype));

		outfile << "\t\tif (Jsonio::extract" << s << "(me, \"" << bit->sref << "\", " << bit->sref << ")) add(" << StrMod::uc(bit->sref) << ");" << endl;
	};
};

void WznmWrsrv::wrBitvarReadxmlCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmAMBlockItem* bit
			, const bool attr
			, const string& shorttag
			, const bool scrsimple
		) {
	WznmMVector* vec = NULL;

	if (attr) {
		if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) {
			outfile << "\t\tif (extractBoolAttrUclc(docctx, basexpath, itemtag, \"" << shorttag << "\", \"sref\", \"" << bit->sref << "\", " << bit->sref << ")) add(" << StrMod::uc(bit->sref) << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) {
			outfile << "\t\tif (extractBoolvecAttrUclc(docctx, basexpath, itemtag, \"" << shorttag << "\", \"sref\", \"" << bit->sref << "\", " << bit->sref << ")) add(" << StrMod::uc(bit->sref) << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) {
			outfile << "\t\tif (extractFloatmatAttrUclc(docctx, basexpath, itemtag, \"" << shorttag << "\", \"sref\", \"" << bit->sref << "\", " << bit->sref << ")) add(" << StrMod::uc(bit->sref) << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) {
			outfile << "\t\tif (extractDoublematAttrUclc(docctx, basexpath, itemtag, \"" << shorttag << "\", \"sref\", \"" << bit->sref << "\", " << bit->sref << ")) add(" << StrMod::uc(bit->sref) << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
			outfile << "\t\tif (extractStringAttrUclc(docctx, basexpath, itemtag, \"" << shorttag << "\", \"sref\", \"sref" << StrMod::cap(bit->sref) << "\", sref" << StrMod::cap(bit->sref) << ")) {" << endl;
			if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
				outfile << "\t\t\t" << bit->sref << " = " << getVecclass(dbswznm, job, vec) << "::getIx(sref" << StrMod::cap(bit->sref) << ");" << endl;
				delete vec;
			} else {
				outfile << "\t\t\t" << bit->sref << " = Vec" << bit->sref.substr(2) << "::getIx(sref" << StrMod::cap(bit->sref)  << ");" << endl;
			};
			outfile << "\t\t\tadd(" << StrMod::uc(bit->sref) << ");" << endl;
			outfile << "\t\t};" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			if (scrsimple) {
				outfile << "\t\tif (extractStringAttrUclc(docctx, basexpath, itemtag, \"" << shorttag << "\", \"sref\", \"scr" << StrMod::cap(bit->sref) << "\", scr" << StrMod::cap(bit->sref) << ")) add(SCR" << StrMod::uc(bit->sref) << ");" << endl;
			} else {
				outfile << "\t\tif (extractStringAttrUclc(docctx, basexpath, itemtag, \"" << shorttag << "\", \"sref\", \"scr" << StrMod::cap(bit->sref) << "\", scr" << StrMod::cap(bit->sref) << ")) {" << endl;
				outfile << "\t\t\t" << bit->sref << " = Scr::descramble(scr" << StrMod::cap(bit->sref) << ");" << endl;
				outfile << "\t\t\tadd(" << StrMod::uc(bit->sref) << ");" << endl;
				outfile << "\t\t};" << endl;
			};
		} else {
			// VOID, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, FLOAT, DOUBLE, STRING, UTINYINTVEC, USMALLINTVEC, INTVEC, UINTVEC, UBIGINTVEC, FLOATVEC, DOUBLEVEC, STRINGVEC
			outfile << "\t\tif (extract" << StrMod::cap(VecWznmVVartype::getSref(bit->ixWznmVVartype)) << "AttrUclc(docctx, basexpath, itemtag, \"" << shorttag << "\", \"sref\", \"" << bit->sref << "\", " << bit->sref << ")) add(" << StrMod::uc(bit->sref) << ");" << endl;
		};

	} else {
		if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) {
			outfile << "\t\tif (extractBoolUclc(docctx, basexpath, \"" << bit->sref << "\", \"\", " << bit->sref << ")) add(" << StrMod::uc(bit->sref) << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) {
			outfile << "\t\tif (extractBoolvecUclc(docctx, basexpath, \"" << bit->sref << "\", \"\", " << bit->sref << ")) add(" << StrMod::uc(bit->sref) << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) {
			outfile << "\t\tif (extractFloatmatUclc(docctx, basexpath, \"" << bit->sref << "\", \"\", " << bit->sref << ")) add(" << StrMod::uc(bit->sref) << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) {
			outfile << "\t\tif (extractDoublematUclc(docctx, basexpath, \"" << bit->sref << "\", \"\", " << bit->sref << ")) add(" << StrMod::uc(bit->sref) << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
			outfile << "\t\tif (extractStringUclc(docctx, basexpath, \"sref" << StrMod::cap(bit->sref) << "\", \"\", sref" << StrMod::cap(bit->sref) << ")) {" << endl;
			if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
				outfile << "\t\t\t" << bit->sref << " = " << getVecclass(dbswznm, job, vec) << "::getIx(sref" << StrMod::cap(bit->sref)  << ");" << endl;
				delete vec;
			} else {
				outfile << "\t\t\t" << bit->sref << " = Vec" << bit->sref.substr(2) << "::getIx(sref" << StrMod::cap(bit->sref)  << ");" << endl;
			};
			outfile << "\t\t\tadd(" << StrMod::uc(bit->sref) << ");" << endl;
			outfile << "\t\t};" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			if (scrsimple) {
				outfile << "\t\tif (extractStringUclc(docctx, basexpath, \"scr" << StrMod::cap(bit->sref) << "\", \"\", scr" << StrMod::cap(bit->sref) << ")) add(SCR" << StrMod::uc(bit->sref) << ");" << endl;
			} else {
				outfile << "\t\tif (extractStringUclc(docctx, basexpath, \"scr" << StrMod::cap(bit->sref) << "\", \"\", scr" << StrMod::cap(bit->sref) << ")) {" << endl;
				outfile << "\t\t\t" << bit->sref << " = Scr::descramble(scr" << StrMod::cap(bit->sref) << ");" << endl;
				outfile << "\t\t\tadd(" << StrMod::uc(bit->sref) << ");" << endl;
				outfile << "\t\t};" << endl;
			};
		} else {
			// VOID, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, FLOAT, DOUBLE, STRING, UTINYINTVEC, USMALLINTVEC, INTVEC, UINTVEC, UBIGINTVEC, FLOATVEC, DOUBLEVEC, STRINGVEC
			outfile << "\t\tif (extract" << StrMod::cap(VecWznmVVartype::getSref(bit->ixWznmVVartype)) << "Uclc(docctx, basexpath, \"" << bit->sref << "\", \"\", " << bit->sref << ")) add(" << StrMod::uc(bit->sref) << ");" << endl;
		};
	};
};

void WznmWrsrv::wrBitvarWritexmlH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmAMBlockItem* bit
		) {
	WznmMVector* vec = NULL;

	string s;

	if (bit->ixWznmVVartype == VecWznmVVartype::VOID) {
		outfile << "const void " << bit->sref << " = 0";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) {
		outfile << "const bool " << bit->sref << " = ";
		if (bit->Defval.length() == 0) outfile << "false"; else outfile << bit->Defval;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::INT) {
		outfile << "const int " << bit->sref << " = ";
		if (bit->Defval.length() == 0) outfile << "0"; else outfile << bit->Defval;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOAT) {
		outfile << "const float " << bit->sref << " = ";
		if (bit->Defval.length() == 0) outfile << "0.0"; else outfile << bit->Defval;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE) {
		outfile << "const double " << bit->sref << " = ";
		if (bit->Defval.length() == 0) outfile << "0.0"; else outfile << bit->Defval;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRING) {
		outfile << "const std::string& " << bit->sref << " = \"" << StrMod::esc(bit->Defval) << "\"";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) {
		outfile << "const std::vector<bool>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) {
		outfile << "const std::vector<Sbecore::utinyint>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) {
		outfile << "const std::vector<Sbecore::usmallint>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) {
		outfile << "const std::vector<int>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC) {
		outfile << "const std::vector<Sbecore::uint>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) {
		outfile << "const std::vector<Sbecore::ubigint>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) {
		outfile << "const std::vector<float>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) {
		outfile << "const Sbecore::Floatmat& " << bit->sref << " = Floatmat()";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) {
		outfile << "const std::vector<double>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) {
		outfile << "const Sbecore::Doublemat& " << bit->sref << " = Doublemat()";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) {
		outfile << "const std::vector<std::string>& " << bit->sref << " = {}";
	} else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
		outfile << "const Sbecore::uint " << bit->sref << " = ";
		if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
			if (dbswznm->loadStringBySQL("SELECT sref FROM TblWznmMVectoritem WHERE ref = " + to_string(bit->refWznmMVectoritem), s)) {
				outfile << getVecclass(dbswznm, job, vec) << "::" << StrMod::uc(s);
			} else {
				outfile << "0";
			};
			delete vec;

		} else {
			outfile << "0";
		};
	} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
		outfile << "const Sbecore::ubigint " << bit->sref << " = 0";
	} else {
		// TINYINT, UTINYINT, SMALLINT, USMALLINT, UINT, BIGINT, UBIGINT
		outfile << "const Sbecore::" << VecWznmVVartype::getSref(bit->ixWznmVVartype) << " " << bit->sref << " = ";
		if (bit->Defval.length() == 0) outfile << "0"; else outfile << bit->Defval;
	};
};

void WznmWrsrv::wrBitvarWritexmlhdrCpp(
			fstream& outfile
			, WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) {
		outfile << "const bool " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRING) {
		outfile << "const string& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) {
		outfile << "const vector<bool>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) {
		outfile << "const vector<utinyint>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) {
		outfile << "const vector<usmallint>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) {
		outfile << "const vector<int>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC) {
		outfile << "const vector<uint>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) {
		outfile << "const vector<ubigint>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) {
		outfile << "const vector<float>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) {
		outfile << "const Floatmat& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) {
		outfile << "const vector<double>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) {
		outfile << "const Doublemat& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) {
		outfile << "const vector<string>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
		outfile << "const uint " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
		outfile << "const ubigint " << bit->sref << endl;
	} else {
		// VOID, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, FLOAT, DOUBLE
		outfile << "const " << VecWznmVVartype::getSref(bit->ixWznmVVartype) << " " << bit->sref << endl;
	};
};

void WznmWrsrv::wrBitvarWritejsonCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmAMBlockItem* bit
			, const bool mask
		) {
	WznmMVector* vec = NULL;

	string s;

	if (mask) {
		outfile << "\tif (has(" << StrMod::uc(bit->sref) << ")) ";
	} else {
		outfile << "\t";
	};

	if ((bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) || (bit->ixWznmVVartype == VecWznmVVartype::TINYINT) || (bit->ixWznmVVartype == VecWznmVVartype::UTINYINT) || (bit->ixWznmVVartype == VecWznmVVartype::SMALLINT)
				|| (bit->ixWznmVVartype == VecWznmVVartype::USMALLINT) || (bit->ixWznmVVartype == VecWznmVVartype::INT) || (bit->ixWznmVVartype == VecWznmVVartype::UINT) || (bit->ixWznmVVartype == VecWznmVVartype::BIGINT)
				|| (bit->ixWznmVVartype == VecWznmVVartype::UBIGINT) || (bit->ixWznmVVartype == VecWznmVVartype::FLOAT) || (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE) || (bit->ixWznmVVartype == VecWznmVVartype::STRING)) {

		outfile << "me[\"" << bit->sref << "\"] = " << bit->sref << ";" << endl;
	
	} else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
			if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
				outfile << "me[\"sref" << StrMod::cap(bit->sref) << "\"] = " << getVecclass(dbswznm, job, vec) << "::getSref(" << bit->sref << ");" << endl;
				delete vec;
			} else {
				outfile << "me[\"sref" << StrMod::cap(bit->sref) << "\"] = Vec" << bit->sref.substr(2) << "::getSref(" << bit->sref << ");" << endl;
			};

	} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
		outfile << "me[\"scr" << StrMod::cap(bit->sref) << "\"] = Scr::scramble(" << bit->sref << ");" << endl;

	} else {
		// VOID, BOOLEANVEC, UTINYINTVEC, USMALLINTVEC, INTVEC, UINTVEC, UBIGINTVEC, FLOATVEC, FLOATMAT, DOUBLEVEC, DOUBLEMAT, STRINGVEC
		if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) s = "Boolvec";
		else s = StrMod::cap(VecWznmVVartype::getSref(bit->ixWznmVVartype));

		outfile << "Jsonio::write" << s << "(me, \"" << bit->sref << "\", " << bit->sref << ");" << endl;
	};
};

void WznmWrsrv::wrBitvarWritexmlCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmAMBlockItem* bit
			, const bool mask
			, const bool attr
			, const bool scrsimple
		) {
	WznmMVector* vec = NULL;

	if (mask) {
		outfile << "\t\tif (has(" << StrMod::uc(bit->sref) << ")) ";
	} else {
		outfile << "\t\t";
	};

	if (attr) {
		if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) {
			outfile << "writeBoolAttr(wr, itemtag, \"sref\", \"" << bit->sref << "\", " << bit->sref << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) {
			outfile << "writeBoolvecAttr(wr, itemtag, \"sref\", \"" << bit->sref << "\"," << bit->sref << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) {
			outfile << "writeFloatmatAttr(wr, itemtag, \"sref\", \"" << bit->sref << "\"," << bit->sref << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) {
			outfile << "writeDoublematAttr(wr, itemtag, \"sref\", \"" << bit->sref << "\"," << bit->sref << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
			if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
				outfile << "writeStringAttr(wr, itemtag, \"sref\", \"sref" << StrMod::cap(bit->sref) << "\", " << getVecclass(dbswznm, job, vec) << "::getSref(" << bit->sref << "));" << endl;
				delete vec;
			} else {
				outfile << "writeStringAttr(wr, itemtag, \"sref\", \"sref" << StrMod::cap(bit->sref) << "\", Vec" << bit->sref.substr(2) << "::getSref(" << bit->sref << "));" << endl;
			};
		} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			outfile << "writeStringAttr(wr, itemtag, \"sref\", \"scr" << StrMod::cap(bit->sref) << "\", Scr::scramble(" << bit->sref << "));" << endl;
		} else {
			// VOID, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, FLOAT, DOUBLE, STRING, UTINYINTVEC, USMALLINTVEC, INTVEC, UINTVEC, UBIGINTVEC, FLOATVEC, DOUBLEVEC, STRINGVEC
			outfile << "write" << StrMod::cap(VecWznmVVartype::getSref(bit->ixWznmVVartype)) << "Attr(wr, itemtag, \"sref\", \"" << bit->sref << "\", " << bit->sref << ");" << endl;
		};

	} else {
		if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) {
			outfile << "writeBool(wr, \"" << bit->sref << "\", " << bit->sref << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) {
			outfile << "writeBoolvec(wr, \"" << bit->sref << "\"," << bit->sref << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) {
			outfile << "writeFloatmat(wr, \"" << bit->sref << "\"," << bit->sref << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) {
			outfile << "writeDoublemat(wr, \"" << bit->sref << "\"," << bit->sref << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
			if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
				outfile << "writeString(wr, \"sref" << StrMod::cap(bit->sref) << "\", " << getVecclass(dbswznm, job, vec) << "::getSref(" << bit->sref << "));" << endl;
				delete vec;
			} else {
				outfile << "writeString(wr, \"sref" << StrMod::cap(bit->sref) << "\", Vec" << bit->sref.substr(2) << "::getSref(" << bit->sref << "));" << endl;
			};
		} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			if (scrsimple) {
				outfile << "writeString(wr, \"scr" << StrMod::cap(bit->sref) << "\", scr" << StrMod::cap(bit->sref) << ");" << endl;
			} else {
				outfile << "writeString(wr, \"scr" << StrMod::cap(bit->sref) << "\", Scr::scramble(" << bit->sref << "));" << endl;
			};
		} else {
			// VOID, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, FLOAT, DOUBLE, STRING, UTINYINTVEC, USMALLINTVEC, INTVEC, UINTVEC, UBIGINTVEC, FLOATVEC, DOUBLEVEC, STRINGVEC
			outfile << "write" << StrMod::cap(VecWznmVVartype::getSref(bit->ixWznmVVartype)) << "(wr, \"" << bit->sref << "\", " << bit->sref << ");" << endl;
		};
	};
};

void WznmWrsrv::wrBitvarCompareCpp(
			fstream& outfile
			, WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::FLOAT) {
		outfile << "\tif (compareFloat(" << bit->sref << ", comp->" << bit->sref << ") < 1.0e-4) insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE) {
		outfile << "\tif (compareDouble(" << bit->sref << ", comp->" << bit->sref << ") < 1.0e-4) insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) {
		outfile << "\tif (compareBoolvec(" << bit->sref << ", comp->" << bit->sref << ")) insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) {
		outfile << "\tif (compareUtinyintvec(" << bit->sref << ", comp->" << bit->sref << ")) insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) {
		outfile << "\tif (compareUsmallintvec(" << bit->sref << ", comp->" << bit->sref << ")) insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) {
		outfile << "\tif (compareIntvec(" << bit->sref << ", comp->" << bit->sref << ")) insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC) {
		outfile << "\tif (compareUintvec(" << bit->sref << ", comp->" << bit->sref << ")) insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) {
		outfile << "\tif (compareUbigintvec(" << bit->sref << ", comp->" << bit->sref << ")) insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) {
		outfile << "\tif (compareFloatvec(" << bit->sref << ", comp->" << bit->sref << ") < 1.0e-4) insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) {
		outfile << "\tif (compareFloatmat(" << bit->sref << ", comp->" << bit->sref << ") < 1.0e-4) insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) {
		outfile << "\tif (compareDoublevec(" << bit->sref << ", comp->" << bit->sref << ") < 1.0e-4) insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) {
		outfile << "\tif (compareDoublemat(" << bit->sref << ", comp->" << bit->sref << ") < 1.0e-4) insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) {
		outfile << "\tif (compareStringvec(" << bit->sref << ", comp->" << bit->sref << ")) insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	} else {
		// VOID, BOOLEAN, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, STRING, VECSREF, SCRREF
		outfile << "\tif (" << bit->sref << " == comp->" << bit->sref << ") insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	};
};

void WznmWrsrv::writePreeval(
			const string& Prjshort
			, fstream& outfile
			, Expr::Node* node
		) {
	string PRJSHORT = StrMod::uc(Prjshort);

	if (node->logicfct()) {
		// only less or more make sense
		if ((node->key == "less") && (node->subs.size() == 2)) {
			writePreeval(Prjshort, outfile, node->subs[0]);
			writePreeval(Prjshort, outfile, node->subs[1]);

			outfile << "\tb = args.back(); args.pop_back();" << endl;
			outfile << "\ta = args.back(); args.pop_back();" << endl;
			outfile << "\tif (b != 0) args.push_back(b);" << endl;
			outfile << "\telse args.push_back(a);" << endl;

		} else if ((node->key == "more") && (node->subs.size() == 2)) {
			writePreeval(Prjshort, outfile, node->subs[0]);
			writePreeval(Prjshort, outfile, node->subs[1]);

			outfile << "\tb = args.back(); args.pop_back();" << endl;
			outfile << "\ta = args.back(); args.pop_back();" << endl;
			outfile << "\tif (a != 0) args.push_back(a);" << endl;
			outfile << "\telse args.push_back(b);" << endl;

		} else {
			outfile << "\targs.push_back(0);" << endl;
		};

	} else if (node->ixVNodetype == Expr::VecVNodetype::FCT) {
		// allow check for presets here
		if ((node->key.find("pre.") == 0) && (node->key.length() > 4)) {
			if (node->key.substr(4) == "void") {
				outfile << "\targs.push_back([](){uint preVoid = Vec" << Prjshort << "VPreset::VOID; return preVoid;}());" << endl;
			} else {
				outfile << "\targs.push_back((xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << StrMod::uc(node->key.substr(4)) << ", jref)) ? Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << StrMod::uc(node->key.substr(4)) << " : 0);" << endl;
			};
		} else {
			outfile << "\targs.push_back(0);" << endl;
		};
	};
};

void WznmWrsrv::writeBooleval(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, const ubigint refWznmMVersion
			, ListWznmMTable& rectbls
			, Expr::Node* node
			, const string& chkaltjref
		) {
	string srefPst;
	bool psteq, pstincl;
	WznmMPreset* pst = NULL;

	WznmMVector* vec = NULL;
	WznmMBlock* blk = NULL;
	WznmAMBlockItem* bit = NULL;

	string s;
	size_t ptr;

	string prjshort = StrMod::lc(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	if (node->logicfct()) {
		// only not, and, or make sense
		if ((node->key == "not") && (node->subs.size() == 1)) {
			writeBooleval(dbswznm, Prjshort, outfile, refWznmMVersion, rectbls, node->subs[0], chkaltjref);

			outfile << "\ta = args.back(); args.pop_back();" << endl;
			outfile << "\targs.push_back(!a);" << endl;

		} else if ((node->key == "and") && (node->subs.size() == 2)) {
			writeBooleval(dbswznm, Prjshort, outfile, refWznmMVersion, rectbls, node->subs[0], chkaltjref);
			writeBooleval(dbswznm, Prjshort, outfile, refWznmMVersion, rectbls, node->subs[1], chkaltjref);

			outfile << "\tb = args.back(); args.pop_back();" << endl;
			outfile << "\ta = args.back(); args.pop_back();" << endl;
			outfile << "\targs.push_back(a && b);" << endl;

		} else if ((node->key == "or") && (node->subs.size() == 2)) {
			writeBooleval(dbswznm, Prjshort, outfile, refWznmMVersion, rectbls, node->subs[0], chkaltjref);
			writeBooleval(dbswznm, Prjshort, outfile, refWznmMVersion, rectbls, node->subs[1], chkaltjref);

			outfile << "\tb = args.back(); args.pop_back();" << endl;
			outfile << "\ta = args.back(); args.pop_back();" << endl;
			outfile << "\targs.push_back(a || b);" << endl;

		} else {
			outfile << "\targs.push_back(false);" << endl;
		};

	} else if (node->ixVNodetype == Expr::VecVNodetype::FCT) {
		// vocabulary:
		// custom() - custom rule, implemented e.g. in panel refresh()
		//
		// sge() - stage equals
		// pre.xxx() - presence of preset
		// pre.xxxEq() - equivalence of preset
		// pre.xxxIncl() - preset includes (ix for vecor)
		// dirty() - flag in pnldetail
		// jobxxx.mast() - subjob is master
		// sel(), sel.first(), sel.last() - table row selection in pnllist, pnlreclist
		// LstXxx.sel() - list control selection
		// valid() - flag in dlgnew
		// virgin() - only temporary user exists
		// stgxxxx.yyyEq() - equivalence of global settings block item
		// <else> - find corresponding check
		// <not found> - internal call, e.g. xxxAvail(), xxxActive()

		// no nested functions to be expected here

		outfile << "\ta = false;";

		if (node->key == "custom") {

		} else if ((node->key == "sge") && (node->subs.size() == 1)) {
			outfile << " a = (ixVSge == VecVSge::" << StrMod::uc(node->subs[0]->key) << ");";

		} else if ((node->key.find("pre.") == 0) && (node->key.length() > 4)) {
			if (node->key.substr(4) != "void") {
				srefPst = node->key.substr(4);
				psteq = (srefPst.rfind("Eq") == (srefPst.size()-2));
				pstincl = (srefPst.rfind("Incl") == (srefPst.size()-4));

				if (psteq) srefPst = srefPst.substr(0, srefPst.size()-2);
				else if (pstincl) srefPst = srefPst.substr(0, srefPst.size()-4);

				srefPst = "Pre" + Prjshort + StrMod::cap(srefPst);

				if (dbswznm->tblwznmmpreset->loadRecBySQL("SELECT * FROM TblWznmMPreset WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND sref = '" + srefPst + "'", &pst)) {
					if ((psteq || pstincl) && (node->subs.size() == 1)) {
						vec = NULL;
						if (pst->ixWznmWArgtype == VecWznmWArgtype::IX) if (pst->refIxVTbl == VecWznmVMPresetRefTbl::VEC) dbswznm->tblwznmmvector->loadRecByRef(pst->refUref, &vec);

						outfile << " a = (xchg->get" << StrMod::cap(VecWznmWArgtype::getSrefs(pst->ixWznmWArgtype)) << "Preset(Vec" << Prjshort << "VPreset::" << StrMod::uc(srefPst) << ", jref)";

						if (psteq) { // IX*, SREF, TXTVAL, INTVAL, DBLVAL
							if ((pst->ixWznmWArgtype == VecWznmWArgtype::IX) && vec) outfile << " == " << vec->sref << "::" << StrMod::uc(node->subs[0]->key);
							else if (pst->ixWznmWArgtype == VecWznmWArgtype::SREF) outfile << " == \"" << node->subs[0]->key << "\"";
							else if (pst->ixWznmWArgtype == VecWznmWArgtype::TXTVAL) outfile << " == \"" << StrMod::esc(node->subs[0]->txtval) << "\"";
							else if (pst->ixWznmWArgtype == VecWznmWArgtype::DBLVAL) outfile << " == " << node->subs[0]->dblval;
						} else if (pstincl) { // IX*
							if ((pst->ixWznmWArgtype == VecWznmWArgtype::IX) && vec) outfile << " & " << vec->sref << "::" << StrMod::uc(node->subs[0]->key);
						};

						outfile << ");";
						
						if (vec) delete vec;

					} else {
						outfile << " a = (xchg->get" << StrMod::cap(VecWznmWArgtype::getSrefs(pst->ixWznmWArgtype)) << "Preset(Vec" << Prjshort << "VPreset::" << StrMod::uc(srefPst) << ", jref)";
						if ((pst->ixWznmWArgtype == VecWznmWArgtype::IX) || (pst->ixWznmWArgtype == VecWznmWArgtype::REF)) outfile << " != 0";
						else if (pst->ixWznmWArgtype == VecWznmWArgtype::REFS) outfile << ".size() > 0";
						else if ((pst->ixWznmWArgtype == VecWznmWArgtype::SREF) || (pst->ixWznmWArgtype == VecWznmWArgtype::TXTVAL)) outfile << ".length() > 0";
						else if (pst->ixWznmWArgtype == VecWznmWArgtype::INTVAL) outfile << " != intvalInvalid";
						else if (pst->ixWznmWArgtype == VecWznmWArgtype::DBLVAL) outfile << " != dblvalInvalid";
						outfile << ");";
					};

					delete pst;
				};
			};

		} else if (node->key == "dirty") {
			outfile << " a = dirty;";

		} else if ((node->key.rfind(".mast") == (node->key.length()-5)) && (node->key.length() > 5)) {
			// ex.: jobmechcon.mast
			outfile << " if (" << node->key.substr(0, node->key.length()-5) << ") a = xchg->getMsjobMastNotSlv(" << node->key.substr(0, node->key.length()-5) << ");";

		} else if (node->key == "sel") {
			outfile << " a = (qry->stgiac.jnum != 0);";

		} else if (node->key == "sel.first") {
			outfile << " a = (qry->stgiac.jnum == 1);";

		} else if (node->key == "sel.last") {
			outfile << " a = (qry->stgiac.jnum == qry->statshr.ntot);";

		} else if ((node->key.rfind(".sel") == (node->key.length()-4)) && (node->key.length() > 4)) {
			// ex.: LstXyz.sel (non-dit), LstEqpXyz.sel (non-dlg), DetLstXyz.sel (dit)
			ptr = node->key.find("Lst");

			if (ptr != string::npos) {
				if (ptr == 0) outfile << " a = (contiac.numF" << node->key.substr(0, node->key.length()-4) << " != 0);";
				else outfile << " a = (contiac" << StrMod::lc(node->key.substr(0, 3)) << ".numF" << node->key.substr(3, node->key.length()-3-4) << " != 0);";
			};

		} else if (node->key == "valid") {
			outfile << " a = valid;";

		} else if (node->key == "virgin") {
			outfile << " {uint cnt = 0; dbs" << prjshort << "->loadUintBySQL(\"SELECT COUNT(ref) FROM Tbl" << Prjshort << "MUser WHERE sref <> 'temp'\", cnt); a = (cnt == 0);};";

		} else if ((node->key.find("stg") == 0) && (node->key.find('.') != string::npos) && (node->key.rfind("Eq") == (node->key.length()-2)) && (node->subs.size() == 1)) {
			// ex.: stgjobidecvislacq.ixidecvcamtypeEq(mslife)
			ptr = node->key.find('.');

			if (dbswznm->tblwznmmblock->loadRecBySQL("SELECT * FROM TblWznmMBlock WHERE ixVBasetype = " + to_string(VecWznmVMBlockBasetype::STG) + " AND refWznmMVersion = "
						+ to_string(refWznmMVersion) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::VOID) + " AND LOWER(sref) LIKE '"
						+ StrMod::lc(node->key.substr(0, ptr)) + "'", &blk)) {

				if (dbswznm->tblwznmamblockitem->loadRecBySQL("SELECT * FROM TblWznmAMBlockItem WHERE blkRefWznmMBlock = " + to_string(blk->ref) + " AND ixVBasetype = "
							+ to_string(VecWznmVAMBlockItemBasetype::VAR) + " AND LOWER(sref) LIKE '" + StrMod::lc(node->key.substr(ptr+1, node->key.length()-(ptr+1)-2)) + "'", &bit)) {

					if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) {
						outfile << " a = (xchg->" << node->key.substr(0, ptr) << "." << bit->sref << " == " << node->subs[0]->key << ");"; // expect key to be 'true' or 'false'

					} else if (bit->ixWznmVVartype == VecWznmVVartype::STRING) {
						outfile << " a = (xchg->" << node->key.substr(0, ptr) << "." << bit->sref << " == \"" << StrMod::esc(node->subs[0]->txtval) << "\");";

					} else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
						if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
							outfile << " a = (xchg->" << node->key.substr(0, ptr) << "." << bit->sref << " == " << vec->sref << "::" << StrMod::uc(node->subs[0]->key) << ");";
							delete vec;
						};

					} else if ((bit->ixWznmVVartype == VecWznmVVartype::FLOAT) || (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE)) {
						outfile << " a = (xchg->" << node->key.substr(0, ptr) << "." << bit->sref << " == " << node->subs[0]->dblval << ");";

					} else {
						// TINYINT ... UBIGINT
						outfile << " a = (xchg->" << node->key.substr(0, ptr) << "." << bit->sref << " == " << node->subs[0]->intval << ");";
					};

					delete bit;
				};

				delete blk;
			};

		} else {
			s = getCaleval(dbswznm, refWznmMVersion, Prjshort, rectbls, node, true, chkaltjref);

			if (s != "") {
				outfile << " " + s;
			} else {
				outfile << " a = eval" << StrMod::cap(StrMod::dotToUsc(node->key)) << "(dbs" << prjshort << ");";
			};
		};

		outfile << endl;
		outfile << "\targs.push_back(a);" << endl;

	} else {
		outfile << "\targs.push_back(false);" << endl;
	};
};

void WznmWrsrv::writeEvalstatshr(
			fstream& outfile
			, const string& bit
			, const string& rule
			, const string& expr
			, const string& prjshort
		) {
	if (bit.length() > 0) {
		if (expr == "custom()") outfile << "\t//" << bit << " = CUSTOM;" << endl;
		else outfile << "\t" << bit << " = eval" << StrMod::cap(rule) << "(dbs" << prjshort << ");" << endl;
	};
};

string WznmWrsrv::getCaleval( // invoked from writeBooleval and WznmWrsrvPnl::getCondeval
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMTable& rectbls
			, Expr::Node* node
			, const bool reta
			, const string& chkaltjref
		) {
	string retval;

	WznmMCall* cal = NULL;

	if (dbswznm->tblwznmmcall->loadRecBySQL("SELECT * FROM TblWznmMCall WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMCallBasetype::CHK)
				+ " AND sref = 'Call" + Prjshort + StrMod::cap(node->key) + "'", &cal)) {

		retval = getChkeval(dbswznm, refWznmMVersion, Prjshort, rectbls, node, cal, reta, chkaltjref);
		
		delete cal;
	};

	return retval;
};

string WznmWrsrv::getChkeval( // invoked from getCaleval and WznmWrsrvJob::writeJobCpp
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMTable& rectbls
			, Expr::Node* node
			, WznmMCall* cal
			, const bool reta
			, const string& altjref
		) {
	string retval;

	WznmMCheck* chk = NULL;

	ListWznmMRelation rels;
	WznmMRelation* rel = NULL;

	WznmMTable* tbl = NULL;
	WznmMTable* tbl2 = NULL;

	ListWznmMTable tbl3s;
	WznmMTable* tbl3 = NULL;

	WznmMTablecol* tco = NULL;
	WznmMTablecol* tco2 = NULL;
	WznmMTablecol* tco3 = NULL;

	WznmMVector* vec = NULL;

	string jref;

	size_t ptr, ptr2;

	bool found;

	string prjshort = StrMod::lc(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	if (altjref != "") jref = altjref;
	else jref = "jref";

	if (dbswznm->tblwznmmcheck->loadRecBySQL("SELECT * FROM TblWznmMCheck WHERE refWznmMCall = " + to_string(cal->ref), &chk)) {
		found = false;
		for (unsigned int i = 0; i < rectbls.nodes.size(); i++) {
			tbl = rectbls.nodes[i];

			if (tbl->ref == chk->refWznmMTable) {
				found = true;
				break;
			};
		};

		if (found) {
			// - use recXxx
			if (dbswznm->tblwznmmtablecol->loadRecByRef(chk->refWznmMTablecol, &tco)) {
				if (chk->ixVBasetype == VecWznmVMCheckBasetype::SBS) {
					ptr = chk->sref.find('.');

					if (ptr == string::npos) {
						retval = "((ixWSubset" + StrMod::cap(tbl->Short) + " & ";
						if (node) {
							if (node->subs.size() == 1) {
								retval += "Vec" + Prjshort + "W" + tbl->sref.substr(3+4) + "Subset::SBS" + PRJSHORT + "B" + StrMod::uc(tbl->sref.substr(3+4)) + StrMod::uc(node->subs[0]->key);
							};
						} else {
							retval += "ixInv";
						};
						retval += ") != 0)";

					} else {
						tbl2 = NULL;
						tco2 = NULL;

						ptr2 = chk->sref.find('.', ptr+1);

						if (ptr2 == string::npos) {
							// (prt.)mdl.inSbs(mtp) case
							// mdl is a tco of prt and points to TblWdbeMModule (tbl2)
							if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL)) {
								dbswznm->tblwznmmtable->loadRecByRef(tco->fctUref, &tbl2);
							} else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV)) {
								// find subrel in which the from table features the sought for subset
								dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(tco->refWznmMRelation), false, rels);
								for (unsigned int i = 0; i < rels.nodes.size(); i++) {
									rel = rels.nodes[i];

									if (Wznm::hasSubset(dbswznm, rel->frRefWznmMTable)) {
										if (node) {
											if (node->subs.size() == 1) {
												if (dbswznm->tblwznmmtable->loadRecBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMTable.ref = " + to_string(rel->frRefWznmMTable) + " AND TblWznmMSubset.refWznmMTable = TblWznmMTable.ref AND TblWznmMSubset.Short = '"
															+ node->subs[0]->key + "'", &tbl2)) {
													break;
												};
											};
										} else {
											// subset short unknown: take first table with subset
											dbswznm->tblwznmmtable->loadRecByRef(rel->frRefWznmMTable, &tbl2);
											break;
										};
									};
								};
							};

						} else {
							// (vec.)hku.mdl.inSbs(mtp) case (inc/u1nsubinc)
							// hku is a tco of vec and points to TblWdbeMController (tbl3)
							// mdl (tco3) is a tco of TblWdbeMController (tbl3) and points to TblWdbeMModule (tbl2)
							// tco2 is a tco of TblWdbeMModule (tbl2) and establishes the relation to TblWdbeMController (tbl3)

							if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL)) {
								// 1n + {inc/u1nsubinc}
								if (dbswznm->tblwznmmtable->loadRecByRef(tco->fctUref, &tbl3)) {
									if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl3->ref) + " AND Short = '" + chk->sref.substr(ptr+1, ptr2-ptr-1) + "'", &tco3)) {
										if ((tco3->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco3->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) && (tco3->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL)) {
											// 1n + inc
											dbswznm->tblwznmmtable->loadRecByRef(tco3->fctUref, &tbl2);
											dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl2->ref) + " AND refWznmMRelation = " + to_string(tco3->refWznmMRelation), &tco2);

										} else if ((tco3->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco3->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV)) {
											// 1n + u1nsubinc

											// find subrel in which the from table features the sought for subset
											dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(tco3->refWznmMRelation), false, rels);
											for (unsigned int i = 0; i < rels.nodes.size(); i++) {
												rel = rels.nodes[i];

												if (Wznm::hasSubset(dbswznm, rel->frRefWznmMTable)) {
													if (node) {
														if (node->subs.size() == 1) {
															if (dbswznm->tblwznmmtable->loadRecBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMTable.ref = " + to_string(rel->frRefWznmMTable) + " AND TblWznmMSubset.refWznmMTable = TblWznmMTable.ref AND TblWznmMSubset.Short = '"
																		+ node->subs[0]->key + "'", &tbl2)) {
																dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl2->ref) + " AND refWznmMRelation = " + to_string(rel->ref), &tco2);
																break;
															};
														};
													} else {
														// subset short unknown: take first table with subset
														if (dbswznm->tblwznmmtable->loadRecByRef(rel->frRefWznmMTable, &tbl2)) {
															dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl2->ref) + " AND refWznmMRelation = " + to_string(rel->ref), &tco2);
															break;
														};
													}
												};
											};
										};
										delete tco3;
									};
									delete tbl3;
								};

							} else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV)) {
								// u1n + {inc/u1nsubinc}

								// traverse all subrel's from tables
								dbswznm->tblwznmmtable->loadRstBySQL("SELECT TblWznmMTable.* FROM TblWznmMRelation, TblWznmMTable WHERE TblWznmMRelation.supRefWznmMRelation = " + to_string(tco->refWznmMRelation) + " AND TblWznmMTable.ref = TblWznmMRelation.frRefWznmMTable", false, tbl3s);
								for (unsigned int i = 0; i < tbl3s.nodes.size(); i++) {
									tbl3 = tbl3s.nodes[i];

									if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl3->ref) + " AND Short = '" + chk->sref.substr(ptr+1, ptr2-ptr-1) + "'", &tco3)) {
										if ((tco3->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco3->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) && (tco3->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL)) {
											// u1n + inc (will also capture tco of u1nsubpref but there is no relation match)
											dbswznm->tblwznmmtable->loadRecByRef(tco3->fctUref, &tbl2);
											dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl2->ref) + " AND refWznmMRelation = " + to_string(tco3->refWznmMRelation), &tco2);

										} else if ((tco3->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco3->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV)) {
											// u1n + u1nsubinc

											// find subrel in which the from table features the sought for subset
											dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(tco3->refWznmMRelation), false, rels);
											for (unsigned int j = 0; j < rels.nodes.size(); j++) {
												rel = rels.nodes[j];

												if (Wznm::hasSubset(dbswznm, rel->frRefWznmMTable)) {
													if (node) {
														if (node->subs.size() == 1) {
															if (dbswznm->tblwznmmtable->loadRecBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMTable.ref = " + to_string(rel->frRefWznmMTable) + " AND TblWznmMSubset.refWznmMTable = TblWznmMTable.ref AND TblWznmMSubset.Short = '"
																		+ node->subs[0]->key + "'", &tbl2)) {
																dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl2->ref) + " AND refWznmMRelation = " + to_string(rel->ref), &tco2);
																break;
															};
														};
													} else {
														// subset short unknown: take first table with subset
														if (dbswznm->tblwznmmtable->loadRecByRef(rel->frRefWznmMTable, &tbl2)) {
															dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl2->ref) + " AND refWznmMRelation = " + to_string(rel->ref), &tco2);
															break;
														};
													};
												};
											};
										};
										delete tco3;
									};

									if (tbl2 && tco2) break;
								};
							};
						};

						if (tbl2) {
							retval = "((dbs" + prjshort + "->getIxWSubsetByRef" + tbl2->sref.substr(3) + "(";
							if (ptr2 == string::npos) retval += "rec" + StrMod::cap(tbl->Short) + "." + tco->sref;
							else if (tco2) {
								// ex.: SELECT ref FROM TblWznmMModule WHERE refWznmMController = recVec.hkUref
								retval += "[&](){ubigint ref; dbs" + prjshort + "->loadRefBySQL(\"SELECT ref FROM " + tbl2->sref + " WHERE " + tco2->sref + " = \" + to_string(rec" + StrMod::cap(tbl->Short) + "." + tco->sref + "), ref); return ref;}()";
							};
							retval += ") & ";

							if (node) {
								if (node->subs.size() == 1) {
									retval += "Vec" + Prjshort + "W" + tbl2->sref.substr(3+4) + "Subset::SBS" + PRJSHORT + "B" + StrMod::uc(tbl2->sref.substr(3+4)) + StrMod::uc(node->subs[0]->key);
								};
							} else {
								retval += "ixInv";
							};
							retval += ") != 0)";

							delete tbl2;
						};

						if (tco2) delete tco2;
					};

				} else {
					if ((chk->ixVBasetype == VecWznmVMCheckBasetype::EQ) || (chk->ixVBasetype == VecWznmVMCheckBasetype::INCL)) {
						if (chk->ixVBasetype == VecWznmVMCheckBasetype::EQ) {
							if ((cal->invIxWznmWArgtype == VecWznmWArgtype::IX) || (cal->invIxWznmWArgtype == VecWznmWArgtype::REF)) {
								// integer comparison
								retval = "(rec" + StrMod::cap(tbl->Short) + "." + tco->sref + " == ";
								if (node) {
									if (node->subs.size() == 1) {
										if (cal->invIxWznmWArgtype == VecWznmWArgtype::IX) {
											if (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) {
												if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
													retval += vec->sref + "::" + StrMod::uc(node->subs[0]->key);
													delete vec;
												};
											};
										} else retval += to_string(node->subs[0]->intval);
									};
								} else {
									if (cal->invIxWznmWArgtype == VecWznmWArgtype::IX) retval += "ixInv";
									else retval += "refInv";
								};
								retval += ")";

							} else if (cal->invIxWznmWArgtype == VecWznmWArgtype::SREF) {
								// string comparison
								retval = "(rec" + StrMod::cap(tbl->Short) + "." + tco->sref + " == ";
								if (node) {
									if (node->subs.size() == 1) retval += "\"" + node->subs[0]->key + "\"";
								} else {
									retval += "srefInv";
								};
								retval += ")";
							};

						} else if (chk->ixVBasetype == VecWznmVMCheckBasetype::INCL) {
							if (cal->invIxWznmWArgtype == VecWznmWArgtype::IX) {
								// integer logic and
								retval =  "((rec" + StrMod::cap(tbl->Short) + "." + tco->sref + " & ";
								if (node) {
									if (node->subs.size() == 1) {
										if (cal->invIxWznmWArgtype == VecWznmWArgtype::IX) {
											if (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) {
												if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
													retval += vec->sref + "::" + StrMod::uc(node->subs[0]->key);
													delete vec;
												};
											};
										} else retval += to_string(node->subs[0]->intval);
									};
								} else {
									retval += "ixInv";
								};
								retval += ") != 0)";

							} else if (cal->invIxWznmWArgtype == VecWznmWArgtype::SREF) {
								// srefInSrefs
								retval = "StrMod::srefInSrefs(rec" + StrMod::cap(tbl->Short) + "." + tco->sref + ", ";
								if (node) {
									if (node->subs.size() == 1) retval += "\"" + node->subs[0]->key + "\"";
								} else {
									retval += "srefInv";
								};
								retval += ")";
							};
						};

					} else if (chk->ixVBasetype == VecWznmVMCheckBasetype::LEAF) {
						retval = "[&](){uint cnt = 0; if (rec" + StrMod::cap(tbl->Short) + ".ref != 0) dbs" + prjshort + "->loadUintBySQL(\"SELECT COUNT(ref) FROM " + tbl->sref
									+ " WHERE " + tco->sref + " = \" + to_string(rec" + StrMod::cap(tbl->Short) + ".ref), cnt); return(cnt == 0);}()";
					};
				};

				if ((retval != "") && reta) retval = "a = " + retval + ";";

				delete tco;
			};

		} else if (node && reta) {

			// - use call
			if (cal->retIxWznmWArgtype == VecWznmWArgtype::BOOLVAL) {
				if ((cal->invIxWznmWArgtype == VecWznmWArgtype::REF) && (node->subs.size() == 1)) {
					retval = "xchg->triggerRefToBoolvalCall(dbs" + prjshort + ", Vec" + Prjshort + "VCall::" + StrMod::uc(StrMod::dotToUsc(cal->sref)) + ", " + jref + ", " + to_string(node->subs[0]->intval) + ", a);";
				} else if ((cal->invIxWznmWArgtype == VecWznmWArgtype::SREF) && (node->subs.size() == 1)) {
					retval = "xchg->triggerSrefToBoolvalCall(dbs" + prjshort + ", Vec" + Prjshort + "VCall::" + StrMod::uc(StrMod::dotToUsc(cal->sref)) + ", " + jref + ", \"" + node->subs[0]->key + "\", a);";

				} else if ((cal->invIxWznmWArgtype == VecWznmWArgtype::IX) && (node->subs.size() == 1)) {
					if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE ref = " + to_string(chk->refWznmMTablecol), &tco)) {

						if (chk->ixVBasetype == VecWznmVMCheckBasetype::SBS) {
							ptr = chk->sref.find('.');

							if (ptr == string::npos) {
								if (dbswznm->tblwznmmtable->loadRecByRef(chk->refWznmMTable, &tbl)) {
									retval = "xchg->triggerIxToBoolvalCall(dbs" + prjshort + ", Vec" + Prjshort + "VCall::" + StrMod::uc(StrMod::dotToUsc(cal->sref))
												+ ", " + jref + ", Vec" + Prjshort + "W" + tbl->sref.substr(3+4) + "::SBS" + PRJSHORT + "B" + StrMod::uc(tbl->sref.substr(3+4)) + StrMod::uc(node->subs[0]->key) + ", a);";
									delete tbl;
								};

							} else {
								tbl2 = NULL;

								ptr2 = chk->sref.find('.', ptr+1);

								if (ptr2 == string::npos) {
									// (prt.)mdl.inSbs(mtp) case
									// mdl is a tco of prt and points to TblWdbeMModule (tbl2)
									if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL)) {
										dbswznm->tblwznmmtable->loadRecByRef(tco->fctUref, &tbl2);

									} else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV)) {
										// find subrel in which the from table features the sought for subset
										dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(tco->refWznmMRelation), false, rels);
										for (unsigned int i = 0; i < rels.nodes.size(); i++) {
											rel = rels.nodes[i];

											if (Wznm::hasSubset(dbswznm, rel->frRefWznmMTable)) {
												if (dbswznm->tblwznmmtable->loadRecBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMTable.ref = " + to_string(rel->frRefWznmMTable) + " AND TblWznmMSubset.refWznmMTable = TblWznmMTable.ref AND TblWznmMSubset.Short = '"
															+ node->subs[0]->key + "'", &tbl2)) {
													break;
												};
											};
										};
									};
								
								} else {
									// (vec.)hku.mdl.inSbs(mtp) case (inc/u1nsubinc)
									// hku is a tco of vec and points to TblWdbeMController (tbl3)
									// mdl (tco3) is a tco of TblWdbeMController (tbl3) and points to TblWdbeMModule (tbl2)

									if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) && (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL)) {
										// 1n + {inc/u1nsubinc}
										if (dbswznm->tblwznmmtable->loadRecByRef(tco->fctUref, &tbl3)) {
											if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl3->ref) + " AND Short = '" + chk->sref.substr(ptr+1, ptr2-ptr-1) + "'", &tco3)) {
												if ((tco3->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco3->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) && (tco3->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL)) {
													// 1n + inc
													dbswznm->tblwznmmtable->loadRecByRef(tco3->fctUref, &tbl2);

												} else if ((tco3->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco3->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV)) {
													// 1n + u1nsubinc

													// find subrel in which the from table features the sought for subset
													dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(tco3->refWznmMRelation), false, rels);
													for (unsigned int i = 0; i < rels.nodes.size(); i++) {
														rel = rels.nodes[i];

														if (Wznm::hasSubset(dbswznm, rel->frRefWznmMTable)) {
															if (dbswznm->tblwznmmtable->loadRecBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMTable.ref = " + to_string(rel->frRefWznmMTable) + " AND TblWznmMSubset.refWznmMTable = TblWznmMTable.ref AND TblWznmMSubset.Short = '"
																		+ node->subs[0]->key + "'", &tbl2)) {
																break;
															};
														};
													};
												};
												delete tco3;
											};
											delete tbl3;
										};

									} else if ((tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV)) {
										// u1n + {inc/u1nsubinc}

										// traverse all subrel's from tables
										dbswznm->tblwznmmtable->loadRstBySQL("SELECT TblWznmMTable.* FROM TblWznmMRelation, TblWznmMTable WHERE TblWznmMRelation.supRefWznmMRelation = " + to_string(tco->refWznmMRelation) + " AND TblWznmMTable.ref = TblWznmMRelation.frRefWznmMTable", false, tbl3s);
										for (unsigned int i = 0; i < tbl3s.nodes.size(); i++) {
											tbl3 = tbl3s.nodes[i];

											if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl3->ref) + " AND Short = '" + chk->sref.substr(ptr+1, ptr2-ptr-1) + "'", &tco3)) {
												if ((tco3->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco3->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) && (tco3->fctIxVTbl == VecWznmVMTablecolFctTbl::TBL)) {
													// u1n + inc
													dbswznm->tblwznmmtable->loadRecByRef(tco3->fctUref, &tbl2);

												} else if ((tco3->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco3->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV)) {
													// u1n + u1nsubinc

													// find subrel in which the from table features the sought for subset
													dbswznm->tblwznmmrelation->loadRstBySQL("SELECT * FROM TblWznmMRelation WHERE supRefWznmMRelation = " + to_string(tco3->refWznmMRelation), false, rels);
													for (unsigned int j = 0; j < rels.nodes.size(); j++) {
														rel = rels.nodes[j];

														if (Wznm::hasSubset(dbswznm, rel->frRefWznmMTable)) {
															if (dbswznm->tblwznmmtable->loadRecBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMSubset WHERE TblWznmMTable.ref = " + to_string(rel->frRefWznmMTable) + " AND TblWznmMSubset.refWznmMTable = TblWznmMTable.ref AND TblWznmMSubset.Short = '"
																		+ node->subs[0]->key + "'", &tbl2)) {
																break;
															};
														};
													};
												};
												delete tco3;
											};

											if (tbl2) break;
										};
									};

									if (tbl2) {
										retval = "xchg->triggerIxToBoolvalCall(dbs" + prjshort + ", Vec" + Prjshort + "VCall::" + StrMod::uc(StrMod::dotToUsc(cal->sref))
													+ ", " + jref + ", Vec" + Prjshort + "W" + tbl2->sref.substr(3+4) + "Subset::SBS" + PRJSHORT + "B" + StrMod::uc(tbl2->sref.substr(3+4)) + StrMod::uc(node->subs[0]->key) + ", a);";
										delete tbl2;
									};
								};
							};
						} else {
							if (tco->fctIxVTbl == VecWznmVMTablecolFctTbl::VEC) {
								if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
									retval = "xchg->triggerIxToBoolvalCall(dbs" + prjshort + ", Vec" + Prjshort + "VCall::" + StrMod::uc(StrMod::dotToUsc(cal->sref)) + ", " + jref + ", " + vec->sref + "::" + StrMod::uc(node->subs[0]->key) + ", a);";
									delete vec;
								};
							};
						};

						delete tco;
					};
				};
			};
		};

		delete chk;
	};

	return retval;
};

void WznmWrsrv::wrReaddpchappCpp(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, ListWznmMBlock& blks
			, const bool jsonNotXml
		) {
	WznmMBlock* blk = NULL;

	WznmMJob* job = NULL;

	string subsref;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		outfile << "\t\t\t";
		if (i != 0) outfile << "} else ";
		outfile << "if (ix" << Prjshort << "VDpch == Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << ") {" << endl;

		if (dbswznm->tblwznmmjob->loadRecByRef(blk->refUref, &job)) {
			if ((job->ixVBasetype == VecWznmVMJobBasetype::CRD) || (job->ixVBasetype == VecWznmVMJobBasetype::PNL)) {
				// special rule for subsref
				// ex. DpchAppPlnrNavData -> CrdPlnrNav::DpchAppData
				subsref = "DpchApp" + blk->sref.substr(blk->sref.find(job->sref.substr(3)) + job->sref.length() - 3);
			} else {
				// regular rule for subsref
				// ex. DpchAppDlgPlnrNavLoainiData -> DlgPlnrNavLoaini::DpchAppData
				subsref = "DpchApp" + blk->sref.substr(blk->sref.find(job->sref) + job->sref.length());
			};

			outfile << "\t\t\t\treq->dpchapp = new " << job->sref << "::" << subsref << "();" << endl;
			if (!jsonNotXml) outfile << "\t\t\t\t((" << job->sref << "::" << subsref << "*) (req->dpchapp))->readXML(docctx, \"/\", true);" << endl;
			else outfile << "\t\t\t\t((" << job->sref << "::" << subsref << "*) (req->dpchapp))->readJSON(root, true);" << endl;

			delete job;

		} else {
			outfile << "\t\t\t\treq->dpchapp = new " << blk->sref << "();" << endl;
			if (!jsonNotXml) outfile << "\t\t\t\t((" << blk->sref << "*) (req->dpchapp))->readXML(docctx, \"/\", true);" << endl;
			else outfile << "\t\t\t\t((" << blk->sref << "*) (req->dpchapp))->readJSON(root, true);" << endl;
		};
	};

	if (blks.nodes.size() > 0) outfile << "\t\t\t};" << endl;
};

void WznmWrsrv::wrGetnewdpchengCpp(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, ListWznmAMBlockItem& bits
			, WznmMJob* job
			, ListWznmMBlock& jobblks
			, ListWznmRMJobMJob& jrjs
		) {
	WznmAMBlockItem* bit = NULL;

	WznmMBlock* subblk = NULL;

	string s;

	bool found;

	outfile << "\tDpchEng" << Prjshort << "* dpcheng = NULL;" << endl;
	outfile << endl;

	outfile << "\tif (items.empty()) {" << endl;
	outfile << "\t\tdpcheng = new DpchEng" << Prjshort << "Confirm(true, jref, \"\");" << endl;
	outfile << "\t} else {" << endl;
	outfile << "\t\tinsert(items, DpchEngData::JREF);" << endl;

	outfile << "\t\tdpcheng = new DpchEngData(jref";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
			if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
				if (isStatic(subblk)) {
					// only sub-blocks which are non-static
					delete subblk;
					subblk = NULL;

					continue;
				};
			};

		} else if ((bit->ixVBasetype != VecWznmVAMBlockItemBasetype::FEED) && (bit->ixVBasetype != VecWznmVAMBlockItemBasetype::RST)) {
			continue;
		};

		found = false;

		if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
			outfile << ", &" << bit->sref;
			found = true;

		} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
			// rst => qry->rst
			// rstxyz => qryxyz->rst
			if (bit->sref == "rst") {
				outfile << ", &(qry->rst)";
				found = true;
			} else {
				if (bit->sref.size() > 3) {
					outfile << ", &(qry" << bit->sref.substr(3) << "->rst)";
					found = true;
				};
			};

		} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
			s = getBlkvar(job, jobblks, jrjs, bit->sref);

			if (s.length() > 0) {
				outfile << ", &" << s;
				found = true;
			};
		};

		if (!found) outfile << ", NULL";
		
		if (subblk) {
			delete subblk;
			subblk = NULL;
		};
	};

	outfile << ", items);" << endl;

	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\treturn dpcheng;" << endl;
};

void WznmWrsrv::wrAlrCpp(
			DbsWznm* dbswznm
			, const string& orgname
			, const string& Prjshort
			, fstream& outfile
			, const ubigint refWznmMVersion
			, WznmMControl* alrcon
			, set<string>& plhs
		) {
	vector<ubigint> refsLcl;
	ubigint refLcl;

	ListWznmMLocale lcls;
	WznmMLocale* lcl = NULL;

	ListWznmMControl cons;
	WznmMControl* con = NULL;

	string conroot;

	WznmMTag* tag = NULL;

	vector<string> ss;
	string s, s2, s3;

	map<ubigint,string> andTits;
	map<ubigint,string> versionTits;
	map<ubigint,string> rlsdateTits;
	map<ubigint,string> ctbsTits;
	map<ubigint,string> pctbsTits;
	map<ubigint,string> libsTits;

	map<ubigint,string> warntermTits;

	set<ubigint> refsCtb;
	set<ubigint> refsPctb;
	set<ubigint> refsLib;

	unsigned int ix;

	string prjshort = StrMod::lc(Prjshort);

	Wznm::getVerlcls(dbswznm, refWznmMVersion, refLcl, refsLcl, lcls);

	conroot = alrcon->sref;
	if (conroot.length() > 3) conroot = conroot.substr(conroot.length() - 3);

	// - caption text
	if (dbswznm->tblwznmmcontrol->loadRecBySQL("SELECT * FROM TblWznmMControl WHERE supRefWznmMControl = " + to_string(alrcon->ref) + " AND sref = 'Txt" + conroot + "Cpt'", &con)) {
		if (con->srefsWznmMTag.length() > 0) {
			// title from tag
			StrMod::srefsToVector(con->srefsWznmMTag, ss);
			if (ss.size() == 1) outfile << "\tcontinf.TxtCpt = Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::" << StrMod::uc(ss[0]) << ", ix" << Prjshort << "VLocale);" << endl;

		} else {
			// specific localized title
			for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
				lcl = lcls.nodes[i];

				s = con->Title;
				dbswznm->tblwznmjmcontroltitle->loadTitByConLoc(con->ref, lcl->ref, s);

				outfile << "\t";
				if (i != 0) outfile << "else ";
				outfile << "if (ix" << Prjshort << "VLocale == Vec" << Prjshort << "VLocale::" << StrMod::uc(lcl->sref) << ") continf.TxtCpt = \"" << StrMod::esc(s) << "\";" << endl;
			};
		};
		if (StrMod::srefInSrefs(con->srefsKOption, "cap")) outfile << "\tcontinf.TxtCpt = StrMod::cap(continf.TxtCpt);" << endl;

		delete con;

	} else {
		outfile << "\tcontinf.TxtCpt = \"" << alrcon->sref << "\";" << endl;
	};
	outfile << endl;

	// - message text
	if (conroot == "Abt") {
		// special treatment for about alert
		Wznm::getTagtits(dbswznm, "and", "", "", {}, refLcl, refsLcl, andTits);
		Wznm::getTagtits(dbswznm, "version", "", "", {}, refLcl, refsLcl, versionTits);
		Wznm::getTagtits(dbswznm, "rlsdate", "", "", {}, refLcl, refsLcl, rlsdateTits);
		Wznm::getTagtits(dbswznm, "ctbs", "", "", {}, refLcl, refsLcl, ctbsTits);
		Wznm::getTagtits(dbswznm, "pctbs", "", "", {}, refLcl, refsLcl, pctbsTits);
		Wznm::getTagtits(dbswznm, "libs", "", "", {}, refLcl, refsLcl, libsTits);

		wrAlrCpp_abtctbini(dbswznm, refWznmMVersion, refsCtb, refsPctb);
		wrAlrCpp_abtlibini(dbswznm, refWznmMVersion, refsLib);

		for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
			lcl = lcls.nodes[i];

			outfile << "\t";
			if (i != 0) outfile << "} else ";
			outfile << "if (ix" << Prjshort << "VLocale == Vec" << Prjshort << "VLocale::" << StrMod::uc(lcl->sref) << ") {" << endl;

			ix = 1;

			outfile << "\t\tcontinf.TxtMsg1 = \"" << wrAlrCpp_abtver(dbswznm, refWznmMVersion, versionTits[lcl->ref], rlsdateTits[lcl->ref]) << "\";" << endl;
			ix++;

			outfile << "\t\tcontinf.TxtMsg2 = \"\\\\u00a9 " << orgname << "\";" << endl;
			ix++;

			if (!refsCtb.empty() || !refsPctb.empty()) ix++;
			if (!refsCtb.empty()) outfile << "\t\tcontinf.TxtMsg" << (ix++) << " = \"" << wrAlrCpp_abtctb(dbswznm, refsCtb, andTits[lcl->ref], ctbsTits[lcl->ref]) << "\";" << endl;
			if (!refsPctb.empty()) outfile << "\t\tcontinf.TxtMsg" << (ix++) << " = \"" << wrAlrCpp_abtctb(dbswznm, refsPctb, andTits[lcl->ref], pctbsTits[lcl->ref]) << "\";" << endl;

			if (!refsLib.empty()) {
				ix++;
				outfile << "\t\tcontinf.TxtMsg" << (ix++) << " = \"" << wrAlrCpp_abtlib(dbswznm, refsLib, andTits[lcl->ref], libsTits[lcl->ref]) << "\";" << endl;
			};

			wrAlrCpp_abt123(dbswznm, refWznmMVersion, lcl->ref, s, s2, s3);
			if ((s.length() > 0) || (s2.length() > 0) || (s3.length() > 0)) ix++;
			if (s.length() > 0) outfile << "\t\tcontinf.TxtMsg" << (ix++) << " = \"" << StrMod::esc(s) << "\";" << endl;
			if (s2.length() > 0) outfile << "\t\tcontinf.TxtMsg" << (ix++) << " = \"" << StrMod::esc(s2) << "\";" << endl;
			if (s3.length() > 0) outfile << "\t\tcontinf.TxtMsg" << (ix++) << " = \"" << StrMod::esc(s3) << "\";" << endl;
		};
		if (lcls.nodes.size() > 0) outfile << "\t};" << endl;

	} else if (conroot == "Trm") {
		// special treatment for termination alert
		Wznm::getTagtits(dbswznm, "warnterm", "", "", {}, refLcl, refsLcl, warntermTits);

		for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
			lcl = lcls.nodes[i];

			outfile << "\t";
			if (i != 0) outfile << "} else ";
			outfile << "if (ix" << Prjshort << "VLocale == Vec" << Prjshort << "VLocale::" << StrMod::uc(lcl->sref) << ") {" << endl;

			s = StrMod::replacePlh(warntermTits[lcl->ref], "sesstterm", "\" + prepareAlrTrm_dtToString(ix" + Prjshort + "VLocale, sesstterm) + \"");
			s = StrMod::replacePlh(s, "sesstwarn", "\" + prepareAlrTrm_dtToString(ix" + Prjshort + "VLocale, sesstwarn) + \"");

			outfile << "\t\tcontinf.TxtMsg1 = \"" << s << "\";" << endl;
		};
		if (lcls.nodes.size() > 0) outfile << "\t};" << endl;

	} else {
		dbswznm->tblwznmmcontrol->loadRstBySQL("SELECT * FROM TblWznmMControl WHERE supRefWznmMControl = " + to_string(alrcon->ref) + " AND sref LIKE 'Txt" + conroot + "Msg%' ORDER BY supNum ASC", false, cons);

		for (unsigned int i = 0; i < lcls.nodes.size(); i++) {
			lcl = lcls.nodes[i];

			outfile << "\t";
			if (i != 0) outfile << "} else ";
			outfile << "if (ix" << Prjshort << "VLocale == Vec" << Prjshort << "VLocale::" << StrMod::uc(lcl->sref) << ") {" << endl;

			for (unsigned int j = 0; j < cons.nodes.size(); j++) {
				con = cons.nodes[j];

				outfile << "\t\tcontinf.TxtMsg" << con->sref.substr(3 + conroot.length() + 3) << " = \"";

				s = "";
				if (con->srefsWznmMTag.length() > 0) {
					StrMod::srefsToVector(con->srefsWznmMTag, ss);
					if (ss.size() == 1) {
						if (ss[0].find("stdalr.") == 0) {
							if (dbswznm->tblwznmmtag->loadRecBySrfGrp(ss[0].substr(7), "stdalr", &tag)) {
								s = tag->Title;
								if (!dbswznm->tblwznmjmtagtitle->loadTitByTagLoc(tag->ref, lcl->ref, s)) dbswznm->tblwznmjmtagtitle->loadTitByTagLoc(tag->ref, lcl->ref, s);
								
								delete tag;
							};
						};
					};

				} else {
					s = con->Title;
					dbswznm->tblwznmjmcontroltitle->loadTitByConLoc(con->ref, lcl->ref, s);
				};

				for (auto it = plhs.begin(); it != plhs.end(); it++) s = StrMod::replacePlh(s, *it, "\" + " + *it + " + \"");

				if (StrMod::srefInSrefs(con->srefsKOption, "cap")) s = StrMod::cap(s);

				outfile << StrMod::esc(s) << "\";" << endl;
			};
		};
		if (lcls.nodes.size() > 0) outfile << "\t};" << endl;
	};
	outfile << endl;

	// - multiple-choice button (no associated feed, options in con->srefsWznmMTag)
	outfile << "\tfeedFMcbAlert.clear();" << endl;
	outfile << endl;

	if (dbswznm->tblwznmmcontrol->loadRecBySQL("SELECT * FROM TblWznmMControl WHERE supRefWznmMControl = " + to_string(alrcon->ref) + " AND sref = 'Mcb" + conroot + "'", &con)) {
		StrMod::srefsToVector(con->srefsWznmMTag, ss);

		for (unsigned int i = 0; i < ss.size(); i++)
					outfile << "\tVec" << Prjshort << "VTag::appendToFeed(Vec" << Prjshort << "VTag::" << StrMod::uc(ss[i]) << ", ix" << Prjshort << "VLocale, feedFMcbAlert);" << endl;

		if (StrMod::srefInSrefs(con->srefsKOption, "cap")) outfile << "\tfeedFMcbAlert.cap();" << endl;

		delete con;
	};
};

string WznmWrsrv::wrAlrCpp_abtver(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& version
			, const string& rlsdate
		) {
	// ex. "BeamRelay version 0.1.5 released on 13-10-2014"
	
	string s;
	size_t ptr;

	time_t rawtime;
	time(&rawtime);

	s = StubWznm::getStubVerStd(dbswznm, refWznmMVersion);
	ptr = s.rfind(' ');

	if (ptr != string::npos) s = s.substr(0, ptr) + " " + version + s.substr(ptr);

	s += " " + rlsdate + " " + Ftm::date(rawtime / (3600*24));

	return(s);
};

void WznmWrsrv::wrAlrCpp_abtctbini(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, set<ubigint>& refsCtb
			, set<ubigint>& refsPctb
		) {
	WznmMVersion* ver = NULL;

	ListWznmRMPersonMProject prsRprjs;
	WznmRMPersonMProject* prsRprj = NULL;

	time_t rawtime;
	time(&rawtime);

	refsCtb.clear();
	refsPctb.clear();

	if (dbswznm->tblwznmmversion->loadRecByRef(refWznmMVersion, &ver)) {
		dbswznm->tblwznmrmpersonmproject->loadRstByPrj(ver->prjRefWznmMProject, false, prsRprjs);

		for (unsigned int i = 0; i < prsRprjs.nodes.size(); i++) {
			prsRprj = prsRprjs.nodes[i];

			if ( (prsRprj->x1Startd == 0) && (prsRprj->x1Stopd == 0) ) {
				refsCtb.insert(prsRprj->refWznmMPerson);
			} else if ( (prsRprj->x1Startd == 0) && (prsRprj->x1Stopd != 0) ) {
				if (prsRprj->x1Stopd < (rawtime / (3600*24))) refsPctb.insert(prsRprj->refWznmMPerson);
				else refsCtb.insert(prsRprj->refWznmMPerson);
			} else if ( (prsRprj->x1Startd != 0) && (prsRprj->x1Stopd == 0) ) {
				if (prsRprj->x1Startd <= (rawtime / (3600*24))) refsCtb.insert(prsRprj->refWznmMPerson);
			} else {
				if (prsRprj->x1Startd <= (rawtime / (3600*24))) {
					if (prsRprj->x1Stopd < (rawtime / (3600*24))) refsPctb.insert(prsRprj->refWznmMPerson);
					else refsCtb.insert(prsRprj->refWznmMPerson);
				};
			};
		};

		// exclude set of contributors from set of past contributors
		for (auto it = refsCtb.begin(); it != refsCtb.end(); it++) refsPctb.erase(*it);

		delete ver;
	};
};

string WznmWrsrv::wrAlrCpp_abtctb(
			DbsWznm* dbswznm
			, set<ubigint>& refsCtb
			, const string& _and
			, const string& ctbs
		) {
	// ex. "contributors: Franz Schmidt, Ulla Keller and Frank Meyer"

	unsigned int i;
	set<ubigint>::iterator it;

	string s;

	s = ctbs + ": ";
	for (i=0, it = refsCtb.begin() ; it!=refsCtb.end() ; i++, it++) {
		if (i > 0) {
			if ((i+1) == refsCtb.size()) s += " " + _and + " ";
			else s += ", ";
		};
		s += StrMod::esc(StubWznm::getStubPrsStd(dbswznm, *it));
	};

	return(s);
};

void WznmWrsrv::wrAlrCpp_abtlibini(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, set<ubigint>& refsLib
		) {
	vector<ubigint> refs;
	ubigint ref;

	WznmMVersion* ver = NULL;

	refsLib.clear();

	// standard libraries
	if (dbswznm->tblwznmmlibrary->loadRefBySrf("libxml2", ref)) refsLib.insert(ref);

	if (dbswznm->tblwznmmversion->loadRecByRef(refWznmMVersion, &ver)) {
		if ((ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MARARIA + VecWznmWMVersionDbmstype::MARINNO)) != 0) {
			if (dbswznm->tblwznmmlibrary->loadRefBySrf("libmariadbclient", ref)) refsLib.insert(ref);
		};
		if ((ver->ixWDbmstype & (VecWznmWMVersionDbmstype::MYINNO + VecWznmWMVersionDbmstype::MYISAM)) != 0) {
			if (dbswznm->tblwznmmlibrary->loadRefBySrf("libmysqlclient", ref)) refsLib.insert(ref);
		};
		if ((ver->ixWDbmstype & VecWznmWMVersionDbmstype::PG) != 0) if (dbswznm->tblwznmmlibrary->loadRefBySrf("libpq", ref)) refsLib.insert(ref);
		if ((ver->ixWDbmstype & VecWznmWMVersionDbmstype::LITE) != 0) if (dbswznm->tblwznmmlibrary->loadRefBySrf("libsqlite3", ref)) refsLib.insert(ref);

		delete ver;
	};

	if (dbswznm->tblwznmmlibrary->loadRefBySrf("libMHD", ref)) refsLib.insert(ref);
	if (dbswznm->tblwznmmlibrary->loadRefBySrf("libcurl", ref)) refsLib.insert(ref);
//	if (dbswznm->tblwznmmlibrary->loadRefBySrf("pthread", ref)) refsLib.insert(ref);

	// specific libraries
	dbswznm->loadRefsBySQL("SELECT TblWznmRMComponentMLibrary.refWznmMLibrary FROM TblWznmRMComponentMLibrary, TblWznmMComponent WHERE TblWznmRMComponentMLibrary.refWznmMComponent = TblWznmMComponent.ref AND TblWznmMComponent.refWznmMVersion = "
				+ to_string(refWznmMVersion), false, refs);
	dbswznm->loadRefsBySQL("SELECT TblWznmRMLibraryMOppack.refWznmMLibrary FROM TblWznmRMLibraryMOppack, TblWznmMOppack WHERE TblWznmRMLibraryMOppack.refWznmMOppack = TblWznmMOppack.ref AND TblWznmMOppack.refWznmMVersion = "
				+ to_string(refWznmMVersion), true, refs);

	for (unsigned int i = 0; i < refs.size(); i++) refsLib.insert(refs[i]);
};

string WznmWrsrv::wrAlrCpp_abtlib(
			DbsWznm* dbswznm
			, set<ubigint>& refsLib
			, const string& _and
			, const string& libs
		) {
	// ex. "libraries: libxml2 2.7.8 and libMHD 0.9.16"

	unsigned int i;
	set<ubigint>::iterator it;

	string s;

	s = libs + ": ";
	for (i=0, it = refsLib.begin() ; it!=refsLib.end() ; i++, it++) {
		if (i > 0) {
			if ((i+1) == refsLib.size()) s += " " + _and + " ";
			else s += ", ";
		};
		s += StubWznm::getStubLibStd(dbswznm, *it);
	};

	return(s);
};

void WznmWrsrv::wrAlrCpp_abt123(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const ubigint refLcl
			, string& abt1
			, string& abt2
			, string& abt3
		) {
	WznmMVersion* ver = NULL;
	WznmJMVersion* verJ = NULL;

	abt1 = "";
	abt2 = "";
	abt3 = "";

	if (dbswznm->tblwznmjmversion->loadRecBySQL("SELECT * FROM TblWznmJMVersion WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND x1RefWznmMLocale = " + to_string(refLcl), &verJ)) {
		abt1 = verJ->About1;
		abt2 = verJ->About2;
		abt3 = verJ->About3;

		delete verJ;

	} else {
		if (dbswznm->tblwznmmversion->loadRecByRef(refWznmMVersion, &ver)) {
			abt1 = ver->About1;
			abt2 = ver->About2;
			abt3 = ver->About3;

			delete ver;
		};
	};
};

void WznmWrsrv::wrAlrTrmCpp_dtToString(
			const string& Prjshort
			, fstream& outfile
			, WznmMControl* con
		) {
	outfile << "string Alr" << Prjshort << "::prepareAlr" << con->sref.substr(3+4) << "_dtToString(" << endl;
	outfile << "\t\t\tconst uint ix" << Prjshort << "VLocale" << endl;
	outfile << "\t\t\t, const time_t dt" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tstring s;" << endl;
	outfile << endl;

	outfile << "\tif ((dt%3600) == 0) {" << endl;
	outfile << "\t\ts = to_string(dt/3600);" << endl;
	outfile << endl;

	outfile << "\t\tif (dt == 3600) s += \" \" + Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::HOUR, ix" << Prjshort << "VLocale);" << endl;
	outfile << "\t\telse s += \" \" + Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::HOURS, ix" << Prjshort << "VLocale);" << endl;
	outfile << endl;

	outfile << "\t} else if ((dt%60) == 0) {" << endl;
	outfile << "\t\ts = to_string(dt/60);" << endl;
	outfile << endl;

	outfile << "\t\tif (dt == 60) s += \" \" + Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::MINUTE, ix" << Prjshort << "VLocale);" << endl;
	outfile << "\t\telse s += \" \" + Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::MINUTES, ix" << Prjshort << "VLocale);" << endl;
	outfile << endl;

	outfile << "\t} else {" << endl;
	outfile << "\t\ts = to_string(dt);" << endl;
	outfile << endl;

	outfile << "\t\tif (dt == 1) s += \" \" + Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::SECOND, ix" << Prjshort << "VLocale);" << endl;
	outfile << "\t\telse s += \" \" + Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::SECONDS, ix" << Prjshort << "VLocale);" << endl;
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\treturn s;" << endl;
	outfile << "};" << endl;
	outfile << endl;

};

void WznmWrsrv::getAlrplhs(
			DbsWznm* dbswznm
			, const ubigint refAlr
			, set<string>& plhs
		) {
	WznmMControl* con = NULL;

	vector<string> ss;
	string s;

	plhs.clear();

	if (dbswznm->tblwznmmcontrol->loadRecBySQL("SELECT * FROM TblWznmMControl WHERE supRefWznmMControl = " + to_string(refAlr) + " AND sref LIKE 'Txt%Msg%'", &con)) {
		StrMod::srefsToVector(con->srefsWznmMTag, ss);

		for (unsigned int i = 0; i < ss.size(); i++) {
			s = ss[i];

			if (s.find("stdalr.") == 0) {
				if (dbswznm->loadStringBySQL("SELECT Title FROM TblWznmMTag WHERE sref = '" + s.substr(7) + "' AND osrefWznmKTaggrp = 'stdalr'", s)) {
					StrMod::findPlhs(s, plhs, true);
				};
			};
		};

		StrMod::findPlhs(con->Title, plhs, true);

		delete con;
	};
};

string WznmWrsrv::getBlkclass(
			DbsWznm* dbswznm
			, WznmMJob* job
			, WznmMBlock* blk
		) {
	string retval = blk->sref;

	WznmMJob* hostjob = NULL;

	if (blk->refIxVTbl == VecWznmVMBlockRefTbl::JOB) {
		if (blk->refUref == job->ref) {
			retval = Wznm::getSubsref(job, blk->sref);

		} else {
			if (dbswznm->tblwznmmjob->loadRecByRef(blk->refUref, &hostjob)) {
				retval = hostjob->sref + "::" + Wznm::getSubsref(hostjob, blk->sref);
				delete hostjob;
			};
		};
	};

	return retval;
};

string WznmWrsrv::getBlkvar(
			WznmMJob* job
			, ListWznmMBlock& jobblks
			, ListWznmRMJobMJob& jrjs
			, const string sref
		) {
	// statshr => statshr
	// statshrqry => qry->statshr

	string retval;

	WznmMBlock* jobblk = NULL;
	WznmRMJobMJob* jrj = NULL;

	size_t ptr;

	for (unsigned int i = 0; i < jobblks.nodes.size(); i++) {
		jobblk = jobblks.nodes[i];

		if (sref == StrMod::lc(Wznm::getSubsref(job, jobblk->sref))) {
			retval = sref;
			break;
		};
	};

	if (retval.length() == 0) {
		for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
			jrj = jrjs.nodes[i];

			ptr = sref.rfind(StrMod::lc(jrj->Short));
			if (ptr != string::npos) {
				retval = "(" + StrMod::lc(jrj->Short) + "->" + sref.substr(0, ptr) + ")";
				break;
			};
		};
	};

	return retval;
};

string WznmWrsrv::getIparpaCppType(
			const uint ixWznmVVartype
		) {
	// used in .cpp files only

	if (ixWznmVVartype == VecWznmVVartype::BOOLEAN) return("bool");
	if (ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) return("vector<bool>");
	if (ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) return("vector<utinyint>");
	if (ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) return("vector<usmallint>");
	if (ixWznmVVartype == VecWznmVVartype::INTVEC) return("vector<int>");
	if (ixWznmVVartype == VecWznmVVartype::UINTVEC) return("vector<uint>");
	if (ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) return("vector<ubigint>");
	if (ixWznmVVartype == VecWznmVVartype::FLOATVEC) return("vector<float>");
	if (ixWznmVVartype == VecWznmVVartype::FLOATMAT) return("Floatmat");
	if (ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) return("vector<double>");
	if (ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) return("Doublemat");
	if (ixWznmVVartype == VecWznmVVartype::STRINGVEC) return("vector<string>");
	if (ixWznmVVartype == VecWznmVVartype::VECSREF) return("uint");
	if (ixWznmVVartype == VecWznmVVartype::SCRREF) return("ubigint");

	return VecWznmVVartype::getSref(ixWznmVVartype);
};

string WznmWrsrv::getVecclass(
			DbsWznm* dbswznm
			, WznmMJob* job
			, WznmMVector* vec
		) {
	string retval = vec->sref;

	WznmMJob* hostjob = NULL;

	if (vec->hkIxVTbl == VecWznmVMVectorHkTbl::JOB) {
		if (vec->hkUref == job->ref) {
			retval = Wznm::getSubsref(job, vec->sref);

		} else {
			if (dbswznm->tblwznmmjob->loadRecByRef(vec->hkUref, &hostjob)) {
				retval = hostjob->sref + "::" + Wznm::getSubsref(hostjob, vec->sref);
				delete hostjob;
			};
		};
	};

	return retval;
};

bool WznmWrsrv::hasScrref(
			DbsWznm* dbswznm
			, const ubigint refWznmMBlock
		) {
	bool retval = false;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	dbswznm->tblwznmamblockitem->loadRstByBlk(refWznmMBlock, false, bits);

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			retval = true;
			break;
		};
	};

	return retval;
};

bool WznmWrsrv::isStatic(
			WznmMBlock* blk
		) {
	return((blk->sref.substr(0, 4+3) == "StatApp") || (blk->sref.substr(0, 3+3) == "StgInf") || (blk->ixVBasetype == VecWznmVMBlockBasetype::TAG));
};
// IP cust --- IEND
