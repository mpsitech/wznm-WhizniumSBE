/**
	* \file WznmWrswapiJob.cpp
	* Wznm operation processor - write Swift API code for job (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrswapiJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrswapi;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrswapiJob
 ******************************************************************************/

DpchRetWznm* WznmWrswapiJob::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrswapiJob* dpchinv
		) {
	ubigint refWznmMComponent = dpchinv->refWznmMComponent;
	ubigint refWznmMJob = dpchinv->refWznmMJob;
	string orgweb = dpchinv->orgweb;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream swfile;

	WznmMJob* job = NULL;

	ListWznmMVector vecs;
	ListWznmMBlock blks;

	string s;

	dbswznm->tblwznmmjob->loadRecByRef(refWznmMJob, &job);

	dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND hkUref = " + to_string(job->ref) + " ORDER BY sref ASC", false, vecs);
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
				+ " AND (((reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0) OR ((wriIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0)) ORDER BY sref ASC", false, blks);

	// create files
	s = xchg->tmppath + "/" + folder + "/" + job->sref + ".swift.ip";
	swfile.open(s.c_str(), ios::out);

	writeJobSw(dbswznm, swfile, job, vecs, blks, orgweb, Prjshort);

	swfile.close();

	delete job;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrswapiJob::writeJobSw(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, const ListWznmMVector& vecs
			, const ListWznmMBlock& blks
			, const string& orgweb
			, const string& Prjshort
		) {
	WznmMVector* vec = NULL;

	WznmMBlock* blk = NULL;

	ListWznmAMBlockItem bits;

	string supsref, subsref;

	// --- blks
	outfile << "// IP blks --- IBEGIN" << endl;
	// order: vec's, blocks ex. dpch, dpch's

	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		subsref = Wznm::getSubsref(job, vec->sref);
		writeVecSw(dbswznm, Prjshort, outfile, vec, true, supsref, subsref);
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		subsref = Wznm::getSubsref(job, blk->sref);

		dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::CONT) {
			writeBlkcontSw(dbswznm, outfile, job, blk, subsref, bits);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::STAT) {
			writeBlkstatSw(dbswznm, outfile, job, blk, subsref, bits);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::STG) {
			writeBlkstgSw(dbswznm, outfile, job, blk, subsref, bits);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::TAG) {
			writeBlktagSw(dbswznm, outfile, job, blk, subsref, bits);
		};
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		subsref = Wznm::getSubsref(job, blk->sref);

		dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::DPCH) {
			writeBlkdpchSw(dbswznm, orgweb, Prjshort, outfile, job, blk, subsref, bits);
		};
	};

	outfile << "// IP blks --- IEND" << endl;
};

// read/write inverted version from WznmWrsrv.cpp
void WznmWrswapiJob::writeBlkcontSw(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
			, ListWznmAMBlockItem bits
		) {
	// always sub-block of job, always cmbeng/eng and app ; read-only for ContInf

	WznmAMBlockItem* bit = NULL;

	ubigint refC;

	outfile << "\t/**" << endl;
	outfile << "\t  * " << subsref << " (full: " << blk->sref << ")" << endl;
	outfile << "\t  */" << endl;
	outfile << "\tpublic class " << subsref << ": Block {" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		outfile << "\t\tpublic static let " << StrMod::uc(bit->sref) << ": Int = " << (i+1) << endl;
	};
	outfile << endl;

	// constructor
	outfile << "\t\tpublic init(" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		outfile << "\t\t\t\t\t";
		if (i != 0) outfile << ", ";
		wrBitvarConstrhdrSw(outfile, bit);
	};
	outfile << "\t\t\t\t) {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarConstrSw(outfile, bit);
	};
	outfile << endl;

	outfile << "\t\t\tsuper.init()" << endl;
	outfile << endl;

	outfile << "\t\t\tmask = [";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << subsref << "." << StrMod::uc(bit->sref);
	};
	outfile << "]" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	// variables
	refC = 0;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if ((i != 0) && (bit->refWznmCAMBlockItem != refC)) outfile << endl;

		outfile << "\t\tpublic var ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "scr" << StrMod::cap(bit->sref);
		else outfile << bit->sref;
		outfile << ": " << getBitSwType(bit) << endl;

		refC = bit->refWznmCAMBlockItem;
	};
	outfile << endl;

	// readXML
	outfile << "\t\tpublic func readXML(" << endl;
	outfile << "\t\t\t\t\t_ doc: XMLDocument" << endl;
	outfile << "\t\t\t\t\t, _ _basexpath: String" << endl;
	outfile << "\t\t\t\t\t, _ addbasetag: Bool" << endl;
	outfile << "\t\t\t\t) -> Bool {" << endl;

	outfile << "\t\t\tvar valid: Bool" << endl;
	outfile << "\t\t\tvar basexpath: String? = _basexpath" << endl;
	outfile << endl;

	for (unsigned int j = 0; j < bits.nodes.size(); j++) {
		bit = bits.nodes[j];
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\t\t\tvar sref" << StrMod::cap(bit->sref) << ": String" << endl;
	};
	outfile << endl;

	outfile << "\t\t\tclear()" << endl;
	outfile << endl;

	outfile << "\t\t\tif addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, \"" << blk->sref << "\")}" << endl;
	outfile << "\t\t\tvalid = basexpath != nil" << endl;
	outfile << endl;

	outfile << "\t\t\tlet itemtag: String = \"Contitem" << blk->sref.substr(4) << "\"" << endl;
	outfile << endl;

	outfile << "\t\t\tif valid {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarReadxmlSw(dbswznm, outfile, job, subsref, bit, true, "Ci");
	};
	outfile << "\t\t\t}" << endl;
	outfile << endl;

	outfile << "\t\t\treturn valid" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) {
		// writeXML
		outfile << "\t\tpublic func writeXML(" << endl;
		outfile << "\t\t\t\t\t_ doc: XMLDocument" << endl;
		outfile << "\t\t\t\t\t, _ sup: XMLElement?" << endl;
		outfile << "\t\t\t\t\t, _ difftag: String" << endl;
		outfile << "\t\t\t\t\t, _ shorttags: Bool" << endl;
		outfile << "\t\t\t\t) {" << endl;

		outfile << "\t\t\tvar tag: String? = difftag" << endl;
		outfile << "\t\t\tif tag == nil {tag = \"" << blk->sref << "\"}" << endl;
		outfile << endl;

		outfile << "\t\t\tlet itemtag: String = shorttags ? \"Ci\" : \"Contitem" << blk->sref.substr(4) << "\"" << endl;
		outfile << endl;

		outfile << "\t\t\tlet el = XMLElement(name: tag!)" << endl;
		outfile << endl;

		outfile << "\t\t\tif sup == nil {doc.setRootElement(el)}" << endl;
		outfile << "\t\t\telse {sup!.addChild(el)}" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarWritexmlSw(dbswznm, outfile, job, subsref, bit, false, true);
		};
		outfile << "\t\t}" << endl;
		outfile << endl;
	};

	// comm
	outfile << "\t\tpublic func comm(" << endl;
	outfile << "\t\t\t\t\t_ comp: " << subsref << endl;
	outfile << "\t\t\t\t) -> Set<Int> {" << endl;
	outfile << "\t\t\tvar items: Set<Int> = []" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarCompareSw(outfile, subsref, bit);
	};
	outfile << endl;

	outfile << "\t\t\treturn items" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	// diff
	outfile << "\t\tpublic func diff(" << endl;
	outfile << "\t\t\t\t\t_ comp: " << subsref << endl;
	outfile << "\t\t\t\t) -> Set<Int> {" << endl;
	outfile << "\t\t\tlet commitems: Set<Int> = comm(comp)" << endl;

	outfile << "\t\t\tvar diffitems: Set<Int> = [";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << subsref << "." << StrMod::uc(bit->sref);
	};
	outfile << "]" << endl;
	outfile << endl;

	outfile << "\t\t\tfor ci in commitems {diffitems.remove(ci)}" << endl;
	outfile << endl;

	outfile << "\t\t\treturn diffitems" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	outfile << "\t}" << endl;
	outfile << endl;
};

void WznmWrswapiJob::writeBlkdpchSw(
			DbsWznm* dbswznm
			, const string& orgweb
			, const string& Prjshort
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
			, ListWznmAMBlockItem bits
		) {
	// sub-block of job for engine <-> app ; read for DpchEng, write for DpchApp

	WznmAMBlockItem* bit = NULL;

	WznmMTable* tbl = NULL;
	WznmMBlock* subblk = NULL;

	ubigint refC;

	bool first;

	outfile << "\t/**" << endl;
	outfile << "\t\t* " << subsref << " (full: " << blk->sref << ")" << endl;
	outfile << "\t\t*/" << endl;

	if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
		outfile << "\tpublic class " << subsref << ": DpchEng" << Prjshort << " {" << endl;
	} else {
		outfile << "\tpublic class " << subsref << ": DpchApp" << Prjshort << " {" << endl;
	};
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		outfile << "\t\tpublic static let ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
		outfile << StrMod::uc(bit->sref) << ": Int = " << (i+1) << endl;
	};
	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) outfile << "\t\tpublic static let ALL: Int  = " << (bits.nodes.size()+1) << endl;
	outfile << endl;

	// constructor
	if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
		outfile << "\t\tpublic init() {" << endl;
		outfile << "\t\t\tsuper.init(Vec" << Prjshort << "VDpch." << StrMod::uc(blk->sref) << ")" << endl;
		outfile << "\t\t}" << endl;
		outfile << endl;

	} else {
		outfile << "\t\tpublic init(" << endl;
		outfile << "\t\t\t\t\t_ scrJref: String = \"\"" << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->sref != "jref") {
				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
					outfile << "\t\t\t\t\t, _ ";
					if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "scr" << StrMod::cap(bit->sref);
					else outfile << bit->sref;
					outfile << ": " << getBitSwType(bit) << " = " << getSwDefault(getBitSwType(bit)) << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
					outfile << "\\t\t\t\t\t, _ "  << bit->sref <<  ": Feed? = nil" << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						outfile << "\t\t\t\t\t, _ " << StrMod::lc(bit->sref) << ": " << getBlkclass(dbswznm, job, subblk) << "? = nil" << endl;
						delete subblk;
					};					
				};
			};
		};

		outfile << "\t\t\t\t\t, mask: Set<Int> = []" << endl;
		outfile << "\t\t\t\t) {" << endl;
		outfile << "\t\t\tsuper.init(Vec" << Prjshort << "VDpch." << StrMod::uc(blk->sref) << ", scrJref)" << endl;
		outfile << endl;

		outfile << "\t\t\tif mask.contains(" << subsref << ".ALL) {self.mask = [";
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (i != 0) outfile << ", ";
			outfile << subsref << ".";
			if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
			outfile << StrMod::uc(bit->sref);
		};
		outfile << "]}" << endl;
		outfile << "\t\t\telse {self.mask = mask}" << endl;
		outfile << endl;	

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->sref != "jref") {
				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
					wrBitvarConstrSw(outfile, bit);
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
					// TBD: deep copy
					outfile << "\t\t\tif has(" << subsref << "." << StrMod::uc(bit->sref) << ") {if " << bit->sref << " != nil {self." << bit->sref << " = " << bit->sref << "!}}" << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						// TBD: deep copy
						outfile << "\t\t\tif has(" << subsref << "." << StrMod::uc(bit->sref) << ") {if " << bit->sref << " != nil {self." << bit->sref << " = " << bit->sref << "!}}" << endl;
						delete subblk;
					};					
				};
			};
		};

		outfile << "\t\t}" << endl;
		outfile << endl;
	};

	// variables
	refC = 0;
	first = true;
	for (unsigned int j = 0; j < bits.nodes.size(); j++) {
		bit = bits.nodes[j];

		if (bit->sref != "jref") {
			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
				if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;

				outfile << "\t\tpublic var ";
				if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "scr" << StrMod::cap(bit->sref);
				else outfile << bit->sref;
				outfile << ": " << getBitSwType(bit) << " = " << getSwDefault(getBitSwType(bit)) << endl;

				refC = bit->refWznmCAMBlockItem;
				first = false;

			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
				if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
				outfile << "\t\tpublic var " << bit->sref << ": Feed = Feed(\"" << StrMod::cap(bit->sref) << "\")" << endl;
				refC = bit->refWznmCAMBlockItem;
				first = false;

			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
				if (dbswznm->tblwznmmtable->loadRecByRef(bit->refWznmMTable, &tbl)) {
					if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
					outfile << "\t\tpublic var " << bit->sref << ": List" << tbl->sref.substr(3) << " = List" << tbl->sref.substr(3) << "()" << endl;
					refC = bit->refWznmCAMBlockItem;
					first = false;

					delete tbl;
				};
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
				if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
					if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
					outfile << "\t\tpublic var " << StrMod::lc(bit->sref) << ": " << getBlkclass(dbswznm, job, subblk) << " = " << getBlkclass(dbswznm, job, subblk) << "()" << endl;
					refC = bit->refWznmCAMBlockItem;
					first = false;

					delete subblk;
				};
			};
		};
	};
	outfile << endl;

	// getSrefsMask
	outfile << "\t\tpublic override func getSrefsMask() -> String {" << endl;
	outfile << "\t\t\tvar ss: Array<String> = []" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "\t\t\tif has(" << subsref << ".SCR" << StrMod::uc(bit->sref) << ") {ss.append(\"scr" << StrMod::cap(bit->sref) << "\")}" << endl;
		else outfile << "\t\t\tif has(" << subsref << "." << StrMod::uc(bit->sref) << ") {ss.append(\"" << bit->sref << "\")}" << endl;
	};
	outfile << endl;

	outfile << "\t\t\treturn StrMod.vectorToString(ss)" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
		// readXML
		outfile << "\t\tpublic override func readXML(" << endl;
		outfile << "\t\t\t\t\t_ doc: XMLDocument" << endl;
		outfile << "\t\t\t\t\t, _ _basexpath: String" << endl;
		outfile << "\t\t\t\t\t, _ addbasetag: Bool" << endl;
		outfile << "\t\t\t\t) {" << endl;

		outfile << "\t\t\tvar valid: Bool" << endl;
		outfile << "\t\t\tvar basexpath: String? = _basexpath" << endl;
		outfile << endl;

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];
			if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\t\t\tvar sref" << StrMod::cap(bit->sref) << ": String" << endl;
		};
		outfile << endl;

		outfile << "\t\t\tclear()" << endl;
		outfile << endl;

		outfile << "\t\t\tif addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, \"" << blk->sref << "\")}" << endl;
		outfile << "\t\t\tvalid = basexpath != nil" << endl;
		outfile << endl;

		outfile << "\t\t\tif valid {valid = Xmlio.checkXPath(doc, basexpath!)}" << endl;
		outfile << endl;

		outfile << "\t\t\tif valid {" << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
				wrBitvarReadxmlSw(dbswznm, outfile, job, subsref, bit, false, "");
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
				outfile << "\t\t\t\tif " << bit->sref << ".readXML(doc, basexpath!, true) {add(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
				outfile << "\t\t\t\tif " << bit->sref << ".readXML(doc, basexpath!, true) {add(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
				outfile << "\t\t\t\tif " << StrMod::lc(bit->sref) << ".readXML(doc, basexpath!, true) {add(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
			};
		};

		outfile << "\t\t\t} else {" << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
				if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
					outfile << "\t\t\t\tsref" << StrMod::cap(bit->sref) << " = \"\"" << endl;
				} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
					outfile << "\t\t\t\tscr" << StrMod::cap(bit->sref) << " = \"\"" << endl;
				} else {
					outfile << "\t\t\t\t" << bit->sref << " = " << getSwDefault(getBitSwType(bit)) << endl;
				};
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
				outfile << "\t\t\t\t" << bit->sref << " = Feed(\"" << StrMod::cap(bit->sref) << "\")" << endl;
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
				if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
					outfile << "\t\t\t\t" << bit->sref << " = " << getBlknew(dbswznm, job, subblk) << endl;
					delete subblk;
				};
			};
		};

		outfile << "\t\t\t}" << endl;
		outfile << "\t\t}" << endl;
		outfile << endl;
	};

	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) {
		// writeXML
		outfile << "\t\tpublic override func writeXML(" << endl;
		outfile << "\t\t\t\t\t_ doc: XMLDocument" << endl;
		outfile << "\t\t\t\t\t, _ sup: XMLElement?" << endl;
		outfile << "\t\t\t\t) {" << endl;
		outfile << "\t\t\tlet el = XMLElement(name: \"" << blk->sref << "\")" << endl;
		outfile << endl;

		outfile << "\t\t\tif sup == nil {doc.setRootElement(el)}" << endl;
		outfile << "\t\t\telse {sup!.addChild(el)}" << endl;
		outfile << endl;
		
		outfile << "\t\t\tel.addAttribute(XMLNode.attribute(withName: \"xmlns\", stringValue: \"" << orgweb << "\") as! XMLNode)" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
				wrBitvarWritexmlSw(dbswznm, outfile, job, subsref, bit, true, false);
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
				outfile << "\t\t\tif has(" << subsref << "." << StrMod::uc(bit->sref) << ") {" << bit->sref << ".writeXML(doc, el, \"\")}" << endl;
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
				if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
					outfile << "\t\t\tif has(" << subsref << "." << StrMod::uc(bit->sref) << ") {" << StrMod::lc(bit->sref) << ".writeXML(doc, el, \"\", true)}" << endl;
					delete subblk;
				};
			};
		};

		outfile << "\t\t}" << endl;
		outfile << endl;
	};

	outfile << "\t}" << endl;
	outfile << endl;
};

void WznmWrswapiJob::writeBlkstatSw(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
			, ListWznmAMBlockItem bits
		) {
	// always sub-block of job, always cmbeng/eng and app ; read-only

	WznmAMBlockItem* bit = NULL;

	ubigint refC;

	outfile << "\t/**" << endl;
	outfile << "\t  * " << subsref << " (full: " << blk->sref << ")" << endl;
	outfile << "\t  */" << endl;
	outfile << "\tpublic class " << subsref << ": Block {" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		outfile << "\t\tpublic static let ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
		outfile << StrMod::uc(bit->sref);
		outfile << ": Int = " << (i+1) << endl;
	};
	outfile << endl;

	// constructor
	outfile << "\t\tpublic init(" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		outfile << "\t\t\t\t\t";
		if (i != 0) outfile << ", ";
		wrBitvarConstrhdrSw(outfile, bit);
	};
	outfile << "\t\t\t\t) {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarConstrSw(outfile, bit);
	};
	outfile << endl;

	outfile << "\t\t\tsuper.init()" << endl;
	outfile << endl;

	outfile << "\t\t\tmask = [";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << subsref << ".";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
		outfile << StrMod::uc(bit->sref);
	};
	outfile << "]" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	// variables
	refC = 0;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if ((i != 0) && (bit->refWznmCAMBlockItem != refC)) outfile << endl;

		outfile << "\t\tpublic var ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "scr" << StrMod::cap(bit->sref);
		else outfile << bit->sref;
		outfile << ": " << getBitSwType(bit) << endl;

		refC = bit->refWznmCAMBlockItem;
	};
	outfile << endl;

	// readXML
	outfile << "\t\tpublic func readXML(" << endl;
	outfile << "\t\t\t\t\t_ doc: XMLDocument" << endl;
	outfile << "\t\t\t\t\t, _ _basexpath: String" << endl;
	outfile << "\t\t\t\t\t, _ addbasetag: Bool" << endl;
	outfile << "\t\t\t\t) -> Bool {" << endl;

	outfile << "\t\t\tvar valid: Bool" << endl;
	outfile << "\t\t\tvar basexpath: String? = _basexpath" << endl;
	outfile << endl;

	for (unsigned int j = 0; j < bits.nodes.size(); j++) {
		bit = bits.nodes[j];
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\t\t\tvar sref" << StrMod::cap(bit->sref) << ": String" << endl;
	};
	outfile << endl;

	outfile << "\t\t\tclear()" << endl;
	outfile << endl;

	outfile << "\t\t\tif addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, \"" << blk->sref << "\")}" << endl;
	outfile << "\t\t\tvalid = basexpath != nil" << endl;
	outfile << endl;

	outfile << "\t\t\tlet itemtag: String = \"Statitem" << blk->sref.substr(4) << "\"" << endl;
	outfile << endl;

	outfile << "\t\t\tif valid {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarReadxmlSw(dbswznm, outfile, job, subsref, bit, true, "Ci");
	};
	outfile << "\t\t\t}" << endl;
	outfile << endl;

	outfile << "\t\t\treturn valid" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	// comm
	outfile << "\t\tpublic func comm(" << endl;
	outfile << "\t\t\t\t\t_ comp: " << subsref << endl;
	outfile << "\t\t\t\t) -> Set<Int> {" << endl;
	outfile << "\t\t\tvar items: Set<Int> = []" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarCompareSw(outfile, subsref, bit);
	};
	outfile << endl;

	outfile << "\t\t\treturn items" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	// diff
	outfile << "\t\tpublic func diff(" << endl;
	outfile << "\t\t\t\t\t_ comp: " << subsref << endl;
	outfile << "\t\t\t\t) -> Set<Int> {" << endl;
	outfile << "\t\t\tlet commitems: Set<Int> = comm(comp)" << endl;

	outfile << "\t\t\tvar diffitems: Set<Int> = [";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << subsref << ".";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
		outfile << StrMod::uc(bit->sref);
	};
	outfile << "]" << endl;
	outfile << endl;

	outfile << "\t\t\tfor ci in commitems {diffitems.remove(ci)}" << endl;
	outfile << endl;

	outfile << "\t\t\treturn diffitems" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	outfile << "\t}" << endl;
	outfile << endl;
};

void WznmWrswapiJob::writeBlkstgSw(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
			, ListWznmAMBlockItem bits
		) {
	// always sub-block of job, always cmbeng/eng and app ; read-only for StgApp
	WznmAMBlockItem* bit = NULL;

	ubigint refC;

	outfile << "\t/**" << endl;
	outfile << "\t  * " << subsref << " (full: " << blk->sref << ")" << endl;
	outfile << "\t  */" << endl;
	outfile << "\tpublic class " << subsref << ": Block {" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		outfile << "\t\tpublic static let " << StrMod::uc(bit->sref) << ": Int = " << (i+1) << endl;
	};
	outfile << endl;

	// constructor
	outfile << "\t\tpublic init(" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		outfile << "\t\t\t\t\t";
		if (i != 0) outfile << ", ";
		wrBitvarConstrhdrSw(outfile, bit);
	};
	outfile << "\t\t\t\t) {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarConstrSw(outfile, bit);
	};
	outfile << endl;

	outfile << "\t\t\tsuper.init()" << endl;
	outfile << endl;

	outfile << "\t\t\tmask = [";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << subsref << "." << StrMod::uc(bit->sref);
	};
	outfile << "]" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	// variables
	refC = 0;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if ((i != 0) && (bit->refWznmCAMBlockItem != refC)) outfile << endl;

		outfile << "\t\tpublic var ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "scr" << StrMod::cap(bit->sref);
		else outfile << bit->sref;
		outfile << ": " << getBitSwType(bit) << endl;

		refC = bit->refWznmCAMBlockItem;
	};
	outfile << endl;

	// readXML
	outfile << "\t\tpublic func readXML(" << endl;
	outfile << "\t\t\t\t\t_ doc: XMLDocument" << endl;
	outfile << "\t\t\t\t\t, _ _basexpath: String" << endl;
	outfile << "\t\t\t\t\t, _ addbasetag: Bool" << endl;
	outfile << "\t\t\t\t) -> Bool {" << endl;

	outfile << "\t\t\tvar valid: Bool" << endl;
	outfile << "\t\t\tvar basexpath: String? = _basexpath" << endl;
	outfile << endl;

	for (unsigned int j = 0; j < bits.nodes.size(); j++) {
		bit = bits.nodes[j];
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\t\t\tvar sref" << StrMod::cap(bit->sref) << ": String" << endl;
	};
	outfile << endl;

	outfile << "\t\t\tclear()" << endl;
	outfile << endl;

	outfile << "\t\t\tif addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, \"" << blk->sref << "\")}" << endl;
	outfile << "\t\t\tvalid = basexpath != nil" << endl;
	outfile << endl;

	outfile << "\t\t\tlet itemtag: String = \"Stgitem" << blk->sref.substr(4) << "\"" << endl;
	outfile << endl;

	outfile << "\t\t\tif valid {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarReadxmlSw(dbswznm, outfile, job, subsref, bit, true, "Si");
	};
	outfile << "\t\t\t}" << endl;
	outfile << endl;

	outfile << "\t\t\treturn valid" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) {
		// writeXML
		outfile << "\t\tpublic func writeXML(" << endl;
		outfile << "\t\t\t\t\t_ doc: XMLDocument" << endl;
		outfile << "\t\t\t\t\t, _ sup: XMLElement?" << endl;
		outfile << "\t\t\t\t\t, _ difftag: String" << endl;
		outfile << "\t\t\t\t\t, _ shorttags: Bool" << endl;
		outfile << "\t\t\t\t) {" << endl;

		outfile << "\t\t\tvar tag: String? = difftag" << endl;
		outfile << "\t\t\tif tag == nil {tag = \"" << blk->sref << "\"}" << endl;
		outfile << endl;

		outfile << "\t\t\tlet itemtag: String = shorttags ? \"Si\" : \"Stgitem" << blk->sref.substr(4) << "\"" << endl;
		outfile << endl;

		outfile << "\t\t\tlet el = XMLElement(name: tag!)" << endl;
		outfile << endl;

		outfile << "\t\t\tif sup == nil {doc.setRootElement(el)}" << endl;
		outfile << "\t\t\telse {sup!.addChild(el)}" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarWritexmlSw(dbswznm, outfile, job, subsref, bit, false, true);
		};
		outfile << "\t\t}" << endl;
		outfile << endl;
	};

	// comm
	outfile << "\t\tpublic func comm(" << endl;
	outfile << "\t\t\t\t\t_ comp: " << subsref << endl;
	outfile << "\t\t\t\t) -> Set<Int> {" << endl;
	outfile << "\t\t\tvar items: Set<Int> = []" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarCompareSw(outfile, subsref, bit);
	};
	outfile << endl;

	outfile << "\t\t\treturn items" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	// diff
	outfile << "\t\tpublic func diff(" << endl;
	outfile << "\t\t\t\t\t_ comp: " << subsref << endl;
	outfile << "\t\t\t\t) -> Set<Int> {" << endl;
	outfile << "\t\t\tlet commitems: Set<Int> = comm(comp)" << endl;

	outfile << "\t\t\tvar diffitems: Set<Int> = [";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << subsref << "." << StrMod::uc(bit->sref);
	};
	outfile << "]" << endl;
	outfile << endl;

	outfile << "\t\t\tfor ci in commitems {diffitems.remove(ci)}" << endl;
	outfile << endl;

	outfile << "\t\t\treturn diffitems" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	outfile << "\t}" << endl;
	outfile << endl;
};

void WznmWrswapiJob::writeBlktagSw(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
			, ListWznmAMBlockItem bits
		) {
	// always sub-block of job, always cmbeng/eng and app ; read-only

	WznmAMBlockItem* bit = NULL;

	ubigint refC;

	outfile << "\t/**" << endl;
	outfile << "\t  * " << subsref << " (full: " << blk->sref << ")" << endl;
	outfile << "\t  */" << endl;
	outfile << "\tpublic class " << subsref << ": Block {" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		outfile << "\t\tpublic static let " << StrMod::uc(bit->sref) << ": Int = " << (i+1) << endl;
	};
	outfile << endl;

	// constructor
	outfile << "\t\tpublic init(" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		outfile << "\t\t\t\t\t";
		if (i != 0) outfile << ", ";
		wrBitvarConstrhdrSw(outfile, bit);
	};
	outfile << "\t\t\t\t) {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarConstrSw(outfile, bit);
	};
	outfile << endl;

	outfile << "\t\t\tsuper.init()" << endl;
	outfile << endl;

	outfile << "\t\t\tmask = [";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << subsref << "." << StrMod::uc(bit->sref);
	};
	outfile << "]" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	// variables
	refC = 0;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if ((i != 0) && (bit->refWznmCAMBlockItem != refC)) outfile << endl;

		outfile << "\t\tpublic var ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "scr" << StrMod::cap(bit->sref);
		else outfile << bit->sref;
		outfile << ": " << getBitSwType(bit) << endl;

		refC = bit->refWznmCAMBlockItem;
	};
	outfile << endl;

	// readXML
	outfile << "\t\tpublic func readXML(" << endl;
	outfile << "\t\t\t\t\t_ doc: XMLDocument" << endl;
	outfile << "\t\t\t\t\t, _ _basexpath: String" << endl;
	outfile << "\t\t\t\t\t, _ addbasetag: Bool" << endl;
	outfile << "\t\t\t\t) -> Bool {" << endl;

	outfile << "\t\t\tvar valid: Bool" << endl;
	outfile << "\t\t\tvar basexpath: String? = _basexpath" << endl;
	outfile << endl;

	for (unsigned int j = 0; j < bits.nodes.size(); j++) {
		bit = bits.nodes[j];
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\t\t\tvar sref" << StrMod::cap(bit->sref) << ": String" << endl;
	};
	outfile << endl;

	outfile << "\t\t\tclear()" << endl;
	outfile << endl;

	outfile << "\t\t\tif addbasetag {basexpath = Xmlio.checkUclcXPaths(doc, _basexpath, \"" << blk->sref << "\")}" << endl;
	outfile << "\t\t\tvalid = basexpath != nil" << endl;
	outfile << endl;

	outfile << "\t\t\tlet itemtag: String = \"Tagitem" << blk->sref.substr(4) << "\"" << endl;
	outfile << endl;

	outfile << "\t\t\tif valid {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarReadxmlSw(dbswznm, outfile, job, subsref, bit, true, "Ti");
	};
	outfile << "\t\t\t}" << endl;
	outfile << endl;

	outfile << "\t\t\treturn valid" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	// comm
	outfile << "\t\tpublic func comm(" << endl;
	outfile << "\t\t\t\t\t_ comp: " << subsref << endl;
	outfile << "\t\t\t\t) -> Set<Int> {" << endl;
	outfile << "\t\t\tvar items: Set<Int> = []" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarCompareSw(outfile, subsref, bit);
	};
	outfile << endl;

	outfile << "\t\t\treturn items" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	// diff
	outfile << "\t\tpublic func diff(" << endl;
	outfile << "\t\t\t\t\t_ comp: " << subsref << endl;
	outfile << "\t\t\t\t) -> Set<Int> {" << endl;
	outfile << "\t\t\tlet commitems: Set<Int> = comm(comp)" << endl;

	outfile << "\t\t\tvar diffitems: Set<Int> = [";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << subsref << "." << StrMod::uc(bit->sref);
	};
	outfile << "]" << endl;
	outfile << endl;

	outfile << "\t\t\tfor ci in commitems {diffitems.remove(ci)}" << endl;
	outfile << endl;

	outfile << "\t\t\treturn diffitems" << endl;
	outfile << "\t\t}" << endl;
	outfile << endl;

	outfile << "\t}" << endl;
	outfile << endl;
};

void WznmWrswapiJob::wrBitvarConstrhdrSw(
			fstream& outfile
			, WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "_ scr" << StrMod::cap(bit->sref);
	else outfile << "_ " << bit->sref;

	outfile << ": " << getBitSwType(bit) << " = " << getSwDefault(getBitSwType(bit)) << endl;
};

// adapted version from WznmWrsrv.cpp
void WznmWrswapiJob::wrBitvarConstrSw(
			fstream& outfile
			, WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "\t\t\tself.scr" << StrMod::cap(bit->sref) << " = scr" << StrMod::cap(bit->sref) << endl;
	else outfile << "\t\t\tself." << bit->sref << " = " << bit->sref << endl;
};

// adapted version from WznmWrsrv.cpp
void WznmWrswapiJob::wrBitvarReadxmlSw(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, const string& subsref
			, WznmAMBlockItem* bit
			, const bool attr
			, const string& shorttag
		) {
	WznmMVector* vec = NULL;

	if (attr) {
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
			outfile << "\t\t\t\tsref" << StrMod::cap(bit->sref) << " = Xmlio.extractStringAttrUclc(doc, basexpath!, itemtag, \"" << shorttag << "\", \"sref\", \"sref" << StrMod::cap(bit->sref) << "\", &mask, " << subsref << "." << StrMod::uc(bit->sref) << ")" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			outfile << "\t\t\t\tscr" << StrMod::cap(bit->sref) << " = Xmlio.extract" << getBitXMLType(bit) << "AttrUclc(doc, basexpath!, itemtag, \"" << shorttag << "\", \"sref\", \"scr" << StrMod::cap(bit->sref) << "\", &mask, " << subsref << ".SCR" << StrMod::uc(bit->sref) << ")" << endl;
		} else {
			outfile << "\t\t\t\t" << bit->sref << " = Xmlio.extract" << getBitXMLType(bit) << "AttrUclc(doc, basexpath!, itemtag, \"" << shorttag << "\", \"sref\", \"" << bit->sref << "\", &mask, " << subsref << "." << StrMod::uc(bit->sref) << ")" << endl;
		};

	} else {
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
			outfile << "\t\t\t\tsref" << StrMod::cap(bit->sref) << " = Xmlio.extractStringUclc(doc, basexpath!, \"sref" << StrMod::cap(bit->sref) << "\", \"\", &mask, " << subsref << "." << StrMod::uc(bit->sref) << ")" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			outfile << "\t\t\t\tscr" << StrMod::cap(bit->sref) << " = Xmlio.extract" << getBitXMLType(bit) << "Uclc(doc, basexpath!, \"scr" << StrMod::cap(bit->sref) << "\", \"\", &mask, " << subsref << ".SCR" << StrMod::uc(bit->sref) << ")" << endl;
		} else {
			outfile << "\t\t\t\t" << bit->sref << " = Xmlio.extract" << getBitXMLType(bit) << "Uclc(doc, basexpath!, \"" << bit->sref << "\", \"\", &mask, " << subsref << "." << StrMod::uc(bit->sref) << ")" << endl;
		};
	};

	if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
		if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
			outfile << "\t\t\t\t" << bit->sref << " = " << getVecclass(dbswznm, job, vec) << ".getIx(sref" << StrMod::cap(bit->sref) << ")" << endl;
			delete vec;
		} else {
			outfile << "\t\t\t\t" << bit->sref << " = Vec" << bit->sref.substr(2) << ".getIx(sref" << StrMod::cap(bit->sref)  << ")" << endl;
		};
	};
};

// adapted version from WznmWrsrv.cpp
void WznmWrswapiJob::wrBitvarWritexmlSw(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, const string& subsref
			, WznmAMBlockItem* bit
			, const bool mask
			, const bool attr
		) {
	WznmMVector* vec = NULL;

	outfile << "\t\t\t";
	if (mask) {
		outfile << "if has(" << subsref << ".";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
		outfile << StrMod::uc(bit->sref) << ") {";
	};

	if (attr) {
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
			if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
				outfile << "Xmlio.writeStringAttr(doc, el, itemtag, \"sref\", \"sref" << StrMod::cap(bit->sref) << "\", " << getVecclass(dbswznm, job, vec) << ".getSref(" << bit->sref << "))";
				delete vec;
			} else {
				outfile << "Xmlio.writeStringAttr(doc, el, itemtag, \"sref\", \"sref" << StrMod::cap(bit->sref) << "\", Vec" << bit->sref.substr(2) << ".getSref(" << bit->sref << "))";
			};
		} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			outfile << "Xmlio.writeStringAttr(doc, el, itemtag, \"sref\", \"scr" << StrMod::cap(bit->sref) << "\", scr" << StrMod::cap(bit->sref) << ")";
		} else {
			// VOID, BOOLEAN, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, FLOAT, DOUBLE, STRING, BOOLEANVEC, UTINYINTVEC, USMALLINTVEC, INTVEC, UINTVEC, UBIGINTVEC, FLOATVEC, DOUBLEVEC, STRINGVEC
			outfile << "Xmlio.write" << getBitXMLType(bit) << "Attr(doc, el, itemtag, \"sref\", \"" << bit->sref << "\", " << bit->sref << ")";
		};

	} else {
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
			if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
				outfile << "el.addChild(XMLElement(name: \"sref" << StrMod::cap(bit->sref) << "\", stringValue: " << getVecclass(dbswznm, job, vec) << ".getSref(" << bit->sref << ")))";
				delete vec;
			};
		} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			outfile << "el.addChild(XMLElement(name: \"scr" << StrMod::cap(bit->sref) << "\", stringValue: scr" << StrMod::cap(bit->sref) << "))";
		} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) {
			outfile << "el.addChild(XMLElement(name: \"scr" << StrMod::cap(bit->sref) << "\", stringValue: (" << bit->sref << " ? \"true\" : \"false\")))";
		} else if ((bit->ixWznmVVartype == VecWznmVVartype::TINYINT) || (bit->ixWznmVVartype == VecWznmVVartype::UTINYINT) || (bit->ixWznmVVartype == VecWznmVVartype::SMALLINT)
					|| (bit->ixWznmVVartype == VecWznmVVartype::USMALLINT) || (bit->ixWznmVVartype == VecWznmVVartype::INT) || (bit->ixWznmVVartype == VecWznmVVartype::UINT)
					|| (bit->ixWznmVVartype == VecWznmVVartype::BIGINT) || (bit->ixWznmVVartype == VecWznmVVartype::UBIGINT) || (bit->ixWznmVVartype == VecWznmVVartype::FLOAT)
					|| (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE)) {
			outfile << "el.addChild(XMLElement(name: \"" << bit->sref << "\", stringValue: String(" << bit->sref << ")))";
		} else if (bit->ixWznmVVartype == VecWznmVVartype::STRING) {
			outfile << "el.addChild(XMLElement(name: \"scr" << StrMod::cap(bit->sref) << "\", stringValue: " << bit->sref << "))";
		} else {
			// VOID, BOOLEANVEC, UTINYINTVEC, USMALLINTVEC, INTVEC, UINTVEC, UBIGINTVEC, FLOATVEC, DOUBLEVEC, STRINGVEC
			outfile << "Xmlio.write" << getBitXMLType(bit) << "(doc, el, \"" << bit->sref << "\", " << bit->sref << ")";
		};
	};

	if (mask) outfile << "}";
	outfile << endl;
};

// adapted version from WznmWrsrv.cpp
void WznmWrswapiJob::wrBitvarCompareSw(
			fstream& outfile
			, const string& subsref
			, WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::FLOAT) {
		outfile << "\t\t\tif Xmlio.compareFloat(" << bit->sref << ", comp." << bit->sref << ") < 1.0e-4 {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE) {
		outfile << "\t\t\tif Xmlio.compareDouble(" << bit->sref << ", comp." << bit->sref << ") < 1.0e-4 {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) {
		outfile << "\t\t\tif Xmlio.compareBoolvec(" << bit->sref << ", comp." << bit->sref << ") {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) {
		outfile << "\t\t\tif Xmlio.compareUtinyintvec(" << bit->sref << ", comp." << bit->sref << ") {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) {
		outfile << "\t\t\tif Xmlio.compareUsmallintvec(" << bit->sref << ", comp." << bit->sref << ") {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) {
		outfile << "\t\t\tif Xmlio.compareIntvec(" << bit->sref << ", comp." << bit->sref << ") {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC) {
		outfile << "\t\t\tif Xmlio.compareUintvec(" << bit->sref << ", comp." << bit->sref << ") {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) {
		outfile << "\t\t\tif Xmlio.compareUbigintvec(" << bit->sref << ", comp." << bit->sref << ") {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) {
		outfile << "\t\t\tif Xmlio.compareFloatvec(" << bit->sref << ", comp." << bit->sref << ") < 1.0e-4 {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) {
		outfile << "\t\t\tif Xmlio.compareFloatmat(" << bit->sref << ", comp." << bit->sref << ") < 1.0e-4 {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) {
		outfile << "\t\t\tif Xmlio.compareDoublevec(" << bit->sref << ", comp." << bit->sref << ") < 1.0e-4 {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) {
		outfile << "\t\t\tif Xmlio.compareDoublemat(" << bit->sref << ", comp." << bit->sref << ") < 1.0e-4 {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) {
		outfile << "\t\t\tif Xmlio.compareStringvec(" << bit->sref << ", comp." << bit->sref << ") {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
		outfile << "\t\t\tif scr" << StrMod::cap(bit->sref) << " == comp.scr" << StrMod::cap(bit->sref) << " {items.insert(" << subsref << ".SCR" << StrMod::uc(bit->sref) << ")}" << endl;
	} else {
		// VOID, BOOLEAN, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, STRING, VECSREF
		outfile << "\t\t\tif " << bit->sref << " == comp." << bit->sref << " {items.insert(" << subsref << "." << StrMod::uc(bit->sref) << ")}" << endl;
	};
};

string WznmWrswapiJob::getBlkclass(
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
				retval = hostjob->sref + "." + Wznm::getSubsref(hostjob, blk->sref);
				delete hostjob;
			};
		};
	};

	return retval;
};

string WznmWrswapiJob::getBlknew(
			DbsWznm* dbswznm
			, WznmMJob* job
			, WznmMBlock* blk
		) {
	// ex. "StatShr()", "QryWznmPrjList.StgIac()"
	string retval = blk->sref;

	WznmMJob* hostjob = NULL;

	if (blk->refIxVTbl == VecWznmVMBlockRefTbl::JOB) {
		if (blk->refUref == job->ref) {
			retval = Wznm::getSubsref(job, blk->sref);

		} else {
			if (dbswznm->tblwznmmjob->loadRecByRef(blk->refUref, &hostjob)) {
				retval = hostjob->sref + "." + Wznm::getSubsref(hostjob, blk->sref);
				delete hostjob;
			};
		};
	};

	retval += "()";

	return retval;
};

string WznmWrswapiJob::getBitSwType(
			WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) return("Bool");
	if (bit->ixWznmVVartype == VecWznmVVartype::TINYINT) return("Int");
	if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINT) return("Int");
	if (bit->ixWznmVVartype == VecWznmVVartype::SMALLINT) return("Int");
	if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINT) return("Int");
	if (bit->ixWznmVVartype == VecWznmVVartype::INT) return("Int");
	if (bit->ixWznmVVartype == VecWznmVVartype::UINT) return("Int");
	if (bit->ixWznmVVartype == VecWznmVVartype::BIGINT) return("Int64");
	if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINT) return("Int64");
	if (bit->ixWznmVVartype == VecWznmVVartype::FLOAT) return("Float");
	if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE) return("Double");
	if (bit->ixWznmVVartype == VecWznmVVartype::STRING) return("String");
	if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) return("[Bool]");
	if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) return("[UInt8]");
	if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) return("[UInt16]");
	if (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) return("[Int32]");
	if (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC) return("[UInt32]");
	if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) return("[UInt64]");
	if (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) return("[Float]");
	if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) return("Floatmat");
	if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) return("[Double]");
	if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) return("Doublemat");
	if (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) return("[String]");
	if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) return("Int");
	if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) return("String");

	return("");
};

string WznmWrswapiJob::getBitXMLType(
			WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) return("Bool");
	if (bit->ixWznmVVartype == VecWznmVVartype::TINYINT) return("Int");
	if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINT) return("Int");
	if (bit->ixWznmVVartype == VecWznmVVartype::SMALLINT) return("Int");
	if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINT) return("Int");
	if (bit->ixWznmVVartype == VecWznmVVartype::INT) return("Int");
	if (bit->ixWznmVVartype == VecWznmVVartype::UINT) return("Int");
	if (bit->ixWznmVVartype == VecWznmVVartype::BIGINT) return("Long");
	if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINT) return("Long");
	if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) return("Boolvec");
	if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) return("String");
	if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) return("String");

	return(StrMod::cap(VecWznmVVartype::getSref(bit->ixWznmVVartype)));
};

// exact copy from WznmWrsrv.cpp
string WznmWrswapiJob::getVecclass(
			DbsWznm* dbswznm
			, WznmMJob* job
			, WznmMVector* vec
		) {
	string retval = vec->sref;

	WznmMJob* hostjob = NULL;

	if ((vec->hkIxVTbl == VecWznmVMVectorHkTbl::JOB) && (job != NULL)) {
		if (vec->hkUref == job->ref) {
			retval = Wznm::getSubsref(job, vec->sref);

		} else {
			if (dbswznm->tblwznmmjob->loadRecByRef(vec->hkUref, &hostjob)) {
				retval = hostjob->sref + "." + Wznm::getSubsref(hostjob, vec->sref);
				delete hostjob;
			};
		};
	};

	return retval;
};
// IP cust --- IEND
