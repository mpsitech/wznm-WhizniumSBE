/**
	* \file WznmWrjapiJob.cpp
	* Wznm operation processor - write Java API code for job (implementation)
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

#include "WznmWrjapiJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrjapi;

/******************************************************************************
 namespace WznmWrjapiJob
 ******************************************************************************/

DpchRetWznm* WznmWrjapiJob::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrjapiJob* dpchinv
		) {
	ubigint refWznmMComponent = dpchinv->refWznmMComponent;
	ubigint refWznmMJob = dpchinv->refWznmMJob;
	string orgweb = dpchinv->orgweb;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream jfile;

	WznmMJob* job = NULL;

	ListWznmMVector vecs;
	ListWznmMBlock blks;

	string s;

	dbswznm->tblwznmmjob->loadRecByRef(refWznmMJob, &job);

	dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND hkUref = " + to_string(job->ref) + " ORDER BY sref ASC", false, vecs);
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
				+ " AND (((reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0) OR ((wriIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0)) ORDER BY sref ASC", false, blks);

	// create files
	s = xchg->tmppath + "/" + folder + "/" + job->sref + ".java.ip";
	jfile.open(s.c_str(), ios::out);

	writeJobJ(dbswznm, jfile, job, vecs, blks, orgweb, Prjshort);

	jfile.close();

	delete job;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrjapiJob::writeJobJ(
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
		writeVecJ(dbswznm, Prjshort, outfile, vec, true, supsref, subsref);
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		subsref = Wznm::getSubsref(job, blk->sref);

		dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::CONT) {
			writeBlkcontJ(dbswznm, outfile, job, blk, subsref, bits);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::STAT) {
			writeBlkstatJ(dbswznm, outfile, job, blk, subsref, bits);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::STG) {
			writeBlkstgJ(dbswznm, outfile, job, blk, subsref, bits);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::TAG) {
			writeBlktagJ(dbswznm, outfile, job, blk, subsref, bits);
		};
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		subsref = Wznm::getSubsref(job, blk->sref);

		dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::DPCH) {
			writeBlkdpchJ(dbswznm, orgweb, Prjshort, outfile, job, blk, subsref, bits);
		};
	};

	outfile << "// IP blks --- IEND" << endl;
};

// read/write inverted version from WznmWrsrv.cpp
void WznmWrjapiJob::writeBlkcontJ(
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
	outfile << "\tpublic class " << subsref << " extends Block {" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		outfile << "\t\tpublic static final int " << StrMod::uc(bit->sref) << " = " << (i+1) << ";" << endl;
	};
	outfile << endl;

	// constructor
	outfile << "\t\tpublic " << subsref << "(" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		outfile << "\t\t\t\t\t";
		if (i != 0) outfile << ", ";
		wrBitvarConstrhdrJ(outfile, bit);
	};
	outfile << "\t\t\t\t) {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarConstrJ(outfile, bit);
	};
	outfile << endl;

	outfile << "\t\t\tmask = new HashSet<Integer>(Arrays.asList(";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << StrMod::uc(bit->sref);
	};
	outfile << "));" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	// variables
	refC = 0;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if ((i != 0) && (bit->refWznmCAMBlockItem != refC)) outfile << endl;

		outfile << "\t\tpublic " << getBitJType(bit) << " ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "scr" << StrMod::cap(bit->sref);
		else outfile << bit->sref;
		outfile << ";" << endl;

		refC = bit->refWznmCAMBlockItem;
	};
	outfile << endl;

	// readXML
	outfile << "\t\tpublic boolean readXML(" << endl;
	outfile << "\t\t\t\t\tDocument doc" << endl;
	outfile << "\t\t\t\t\t, String basexpath" << endl;
	outfile << "\t\t\t\t\t, boolean addbasetag" << endl;
	outfile << "\t\t\t\t) {" << endl;

	for (unsigned int j = 0; j < bits.nodes.size(); j++) {
		bit = bits.nodes[j];
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\t\t\tString sref" << StrMod::cap(bit->sref) << ";" << endl;
	};
	outfile << endl;

	outfile << "\t\t\tclear();" << endl;
	outfile << endl;

	outfile << "\t\t\tif (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, \"" << blk->sref << "\");" << endl;
	outfile << endl;

	outfile << "\t\t\tString itemtag = \"Contitem" << blk->sref.substr(4) << "\";" << endl;
	outfile << endl;

	outfile << "\t\t\tif (Xmlio.checkXPath(doc, basexpath)) {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarReadxmlJ(dbswznm, outfile, job, bit, true, "Ci");
	};
	outfile << endl;

	outfile << "\t\t\t\treturn true;" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << endl;

	outfile << "\t\t\treturn false;" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) {
		// writeXML
		outfile << "\t\tpublic void writeXML(" << endl;
		outfile << "\t\t\t\t\tDocument doc" << endl;
		outfile << "\t\t\t\t\t, Element sup" << endl;
		outfile << "\t\t\t\t\t, String difftag" << endl;
		outfile << "\t\t\t\t\t, boolean shorttags" << endl;
		outfile << "\t\t\t\t) {" << endl;
		outfile << "\t\t\tif (difftag.isEmpty()) difftag = \"" << blk->sref << "\";" << endl;
		outfile << endl;

		outfile << "\t\t\tString itemtag;" << endl;
		outfile << endl;

		outfile << "\t\t\tif (shorttags) itemtag = \"Ci\";" << endl;
		outfile << "\t\t\telse itemtag = \"Contitem" << blk->sref.substr(4) << "\";" << endl;
		outfile << endl;

		outfile << "\t\t\tElement el = doc.createElement(difftag);" << endl;
		outfile << endl;

		outfile << "\t\t\tif (sup == null) doc.appendChild(el);" << endl;
		outfile << "\t\t\telse sup.appendChild(el);" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarWritexmlJ(dbswznm, outfile, job, bit, false, true);
		};
		outfile << "\t\t};" << endl;
		outfile << endl;
	};

	// comm
	outfile << "\t\tpublic HashSet<Integer> comm(" << endl;
	outfile << "\t\t\t\t\t" << subsref << " comp" << endl;
	outfile << "\t\t\t\t) {" << endl;
	outfile << "\t\t\tHashSet<Integer> items = new HashSet<Integer>();" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarCompareJ(outfile, bit);
	};
	outfile << endl;

	outfile << "\t\t\treturn(items);" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	// diff
	outfile << "\t\tpublic HashSet<Integer> diff(" << endl;
	outfile << "\t\t\t\t\t" << subsref << " comp" << endl;
	outfile << "\t\t\t\t) {" << endl;
	outfile << "\t\t\tHashSet<Integer> commitems;" << endl;
	outfile << "\t\t\tHashSet<Integer> diffitems;" << endl;
	outfile << endl;

	outfile << "\t\t\tcommitems = comm(comp);" << endl;
	outfile << endl;

	outfile << "\t\t\tdiffitems = new HashSet<Integer>(Arrays.asList(";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << StrMod::uc(bit->sref);
	};
	outfile << "));" << endl;
	outfile << "\t\t\tfor (Integer ci: commitems) diffitems.remove(ci);" << endl;
	outfile << endl;

	outfile << "\t\t\treturn(diffitems);" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	outfile << "\t};" << endl;
	outfile << endl;
};

void WznmWrjapiJob::writeBlkdpchJ(
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
		outfile << "\tpublic class " << subsref << " extends DpchEng" << Prjshort << " {" << endl;
	} else {
		outfile << "\tpublic class " << subsref << " extends DpchApp" << Prjshort << " {" << endl;
	};
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		outfile << "\t\tpublic static final int ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
		outfile << StrMod::uc(bit->sref) << " = " << (i+1) << ";" << endl;
	};
	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) outfile << "\t\tpublic static final int ALL = " << (bits.nodes.size()+1) << ";" << endl;
	outfile << endl;

	// constructor
	if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
		outfile << "\t\tpublic " << subsref << "() {" << endl;
		outfile << "\t\t\tsuper(Vec" << Prjshort << "VDpch." << StrMod::uc(blk->sref) << ");" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->sref != "jref") {
				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
					outfile << "\t\t\t" << bit->sref << " = new Feed(\"" << StrMod::cap(bit->sref) << "\");" << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
					if (dbswznm->tblwznmmtable->loadRecByRef(bit->refWznmMTable, &tbl)) {
						outfile << "\t\t\t" << bit->sref << " = new List" << tbl->sref.substr(3) << "();" << endl;
						delete tbl;
					};
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						outfile << "\t\t\t" << bit->sref << " = " << getBlknew(dbswznm, job, subblk) << ";" << endl;
						delete subblk;
					};
				};
			};
		};

		outfile << "\t\t};" << endl;
		outfile << endl;

	} else {
		outfile << "\t\tpublic " << subsref << "(" << endl;
		outfile << "\t\t\t\t\tString scrJref" << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->sref != "jref") {
				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
					outfile << "\t\t\t\t\t, " << getBitJType(bit) << " ";
					if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "scr" << StrMod::cap(bit->sref) << endl;
					else outfile << bit->sref << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
					outfile << "\\t\t\t\t\t, Feed " << bit->sref << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						outfile << "\t\t\t\t\t, " << getBlkclass(dbswznm, job, subblk) << " " << StrMod::lc(bit->sref) << endl;
						delete subblk;
					};					
				};
			};
		};

		outfile << "\t\t\t\t\t, Integer[] mask" << endl;
		outfile << "\t\t\t\t) {" << endl;
		outfile << "\t\t\tsuper(Vec" << Prjshort << "VDpch." << StrMod::uc(blk->sref) << ", scrJref);" << endl;
		outfile << endl;

		outfile << "\t\t\tthis.mask = new HashSet<Integer>(Arrays.asList(mask));" << endl;
		outfile << endl;

		outfile << "\t\t\tfor (Integer i: mask)" << endl;
		outfile << "\t\t\t\tif (i == ALL) {" << endl;
		outfile << "\t\t\t\t\tthis.mask = new HashSet<Integer>(Arrays.asList(";
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (i != 0) outfile << ", ";
			if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
			outfile << StrMod::uc(bit->sref);
		};
		outfile << "));" << endl;
		outfile << "\t\t\t\t\tbreak;" << endl;
		outfile << "\t\t\t\t};" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->sref != "jref") {
				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
					wrBitvarConstrJ(outfile, bit);
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
					// TBD: deep copy
					outfile << "\t\t\tif (has(" << StrMod::uc(bit->sref) << ")) this." << bit->sref << " = " << bit->sref << ";" << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						// TBD: deep copy
						outfile << "\t\t\tif (has(" << StrMod::uc(bit->sref) << ")) this." << bit->sref << " = " << bit->sref << ";" << endl;
						delete subblk;
					};					
				};
			};
		};

		outfile << "\t\t};" << endl;
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

				outfile << "\t\tpublic " << getBitJType(bit) << " ";
				if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "scr" << StrMod::cap(bit->sref);
				else outfile << bit->sref;
				outfile << ";" << endl;

				refC = bit->refWznmCAMBlockItem;
				first = false;

			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
				if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
				outfile << "\t\tpublic Feed " << bit->sref << ";" << endl;
				refC = bit->refWznmCAMBlockItem;
				first = false;

			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
				if (dbswznm->tblwznmmtable->loadRecByRef(bit->refWznmMTable, &tbl)) {
					if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
					outfile << "\t\tpublic List" << tbl->sref.substr(3) << " " << bit->sref << ";" << endl;
					refC = bit->refWznmCAMBlockItem;
					first = false;

					delete tbl;
				};
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
				if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
					if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
					outfile << "\t\tpublic " << getBlkclass(dbswznm, job, subblk) << " " << StrMod::lc(bit->sref) << ";" << endl;
					refC = bit->refWznmCAMBlockItem;
					first = false;

					delete subblk;
				};
			};
		};
	};
	outfile << endl;

	// getSrefsMask
	outfile << "\t\tpublic String getSrefsMask() {" << endl;
	outfile << "\t\t\tArrayList<String> ss = new ArrayList<String>();" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "\t\t\tif (has(SCR" << StrMod::uc(bit->sref) << ")) ss.add(\"scr" << StrMod::cap(bit->sref) << "\");" << endl;
		else outfile << "\t\t\tif (has(" << StrMod::uc(bit->sref) << ")) ss.add(\"" << bit->sref << "\");" << endl;
	};
	outfile << endl;

	outfile << "\t\t\treturn StrMod.vectorToString(ss, ';');" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
		// readXML
		outfile << "\t\tpublic void readXML(" << endl;
		outfile << "\t\t\t\t\tDocument doc" << endl;
		outfile << "\t\t\t\t\t, String basexpath" << endl;
		outfile << "\t\t\t\t\t, boolean addbasetag" << endl;
		outfile << "\t\t\t\t) {" << endl;

		for (unsigned int j = 0; j < bits.nodes.size(); j++) {
			bit = bits.nodes[j];
			if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\t\t\tString sref" << StrMod::cap(bit->sref) << ";" << endl;
		};
		outfile << endl;

		outfile << "\t\t\tclear();" << endl;
		outfile << endl;

		outfile << "\t\t\tif (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, \"" << blk->sref <<  "\");" << endl;
		outfile << endl;

		outfile << "\t\t\tif (Xmlio.checkXPath(doc, basexpath)) {" << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
				wrBitvarReadxmlJ(dbswznm, outfile, job, bit, false, "");
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
				outfile << "\t\t\t\tif (" << bit->sref << ".readXML(doc, basexpath, true)) add(" << StrMod::uc(bit->sref) << ");" << endl;
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
				outfile << "\t\t\t\tif (" << bit->sref << ".readXML(doc, basexpath, true)) add(" << StrMod::uc(bit->sref) << ");" << endl;
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
				outfile << "\t\t\t\tif (" << StrMod::lc(bit->sref) << ".readXML(doc, basexpath, true)) add(" << StrMod::uc(bit->sref) << ");" << endl;
			};
		};

		outfile << "\t\t\t} else {" << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
				if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
					outfile << "\t\t\t\tsref" << StrMod::cap(bit->sref) << " = \"\";" << endl;
				} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
					outfile << "\t\t\t\tscr" << StrMod::cap(bit->sref) << " = \"\";" << endl;
				} else {
					outfile << "\t\t\t\t" << bit->sref << " = " << getJDefault(getBitJType(bit)) << ";" << endl;
				};
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
				outfile << "\t\t\t\t" << bit->sref << " = new Feed(\"" << StrMod::cap(bit->sref) << "\");" << endl;
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
				if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
					outfile << "\t\t\t\t" << bit->sref << " = " << getBlknew(dbswznm, job, subblk) << ";" << endl;
					delete subblk;
				};
			};
		};

		outfile << "\t\t\t};" << endl;
		outfile << "\t\t};" << endl;
		outfile << endl;
	};

	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) {
		// writeXML
		outfile << "\t\tpublic void writeXML(" << endl;
		outfile << "\t\t\t\t\tDocument doc" << endl;
		outfile << "\t\t\t\t\t, Element sup" << endl;
		outfile << "\t\t\t\t) {" << endl;
		outfile << "\t\t\tElement el = doc.createElement(\"" << blk->sref << "\");" << endl;
		outfile << endl;

		outfile << "\t\t\tif (sup == null) doc.appendChild(el);" << endl;
		outfile << "\t\t\telse sup.appendChild(el);" << endl;
		outfile << endl;
		
		outfile << "\t\t\tel.setAttribute(\"xmlns\", \"" << orgweb << "\");" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
				wrBitvarWritexmlJ(dbswznm, outfile, job, bit, true, false);
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
				outfile << "\t\t\tif (has(" << StrMod::uc(bit->sref) << ")) " << bit->sref << ".writeXML(doc, el, \"\");" << endl;
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
				if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
					outfile << "\t\t\tif (has(" << StrMod::uc(bit->sref) << ")) " << StrMod::lc(bit->sref) << ".writeXML(doc, el, \"\", true);" << endl;
					delete subblk;
				};
			};
		};

		outfile << "\t\t};" << endl;
		outfile << endl;
	};

	outfile << "\t};" << endl;
	outfile << endl;
};

void WznmWrjapiJob::writeBlkstatJ(
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
	outfile << "\tpublic class " << subsref << " extends Block {" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		outfile << "\t\tpublic static final int ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
		outfile << StrMod::uc(bit->sref);
		outfile << " = " << (i+1) << ";" << endl;
	};
	outfile << endl;

	// constructor
	outfile << "\t\tpublic " << subsref << "(" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		outfile << "\t\t\t\t\t";
		if (i != 0) outfile << ", ";
		wrBitvarConstrhdrJ(outfile, bit);
	};
	outfile << "\t\t\t\t) {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarConstrJ(outfile, bit);
	};
	outfile << endl;

	outfile << "\t\t\tmask = new HashSet<Integer>(Arrays.asList(";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";

		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
		outfile << StrMod::uc(bit->sref);
	};
	outfile << "));" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	// variables
	refC = 0;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if ((i != 0) && (bit->refWznmCAMBlockItem != refC)) outfile << endl;

		outfile << "\t\tpublic " << getBitJType(bit) << " ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "scr" << StrMod::cap(bit->sref);
		else outfile << bit->sref;
		outfile << ";" << endl;

		refC = bit->refWznmCAMBlockItem;
	};
	outfile << endl;

	// readXML
	outfile << "\t\tpublic boolean readXML(" << endl;
	outfile << "\t\t\t\t\tDocument doc" << endl;
	outfile << "\t\t\t\t\t, String basexpath" << endl;
	outfile << "\t\t\t\t\t, boolean addbasetag" << endl;
	outfile << "\t\t\t\t) {" << endl;

	for (unsigned int j = 0; j < bits.nodes.size(); j++) {
		bit = bits.nodes[j];
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\t\t\tString sref" << StrMod::cap(bit->sref) << ";" << endl;
	};
	outfile << endl;

	outfile << "\t\t\tclear();" << endl;
	outfile << endl;

	outfile << "\t\t\tif (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, \"" << blk->sref << "\");" << endl;
	outfile << endl;

	outfile << "\t\t\tString itemtag = \"Statitem" << blk->sref.substr(4) << "\";" << endl;
	outfile << endl;

	outfile << "\t\t\tif (Xmlio.checkXPath(doc, basexpath)) {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarReadxmlJ(dbswznm, outfile, job, bit, true, "Si");
	};
	outfile << endl;

	outfile << "\t\t\t\treturn true;" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << endl;

	outfile << "\t\t\treturn false;" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	// comm
	outfile << "\t\tpublic HashSet<Integer> comm(" << endl;
	outfile << "\t\t\t\t\t" << subsref << " comp" << endl;
	outfile << "\t\t\t\t) {" << endl;
	outfile << "\t\t\tHashSet<Integer> items = new HashSet<Integer>();" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarCompareJ(outfile, bit);
	};
	outfile << endl;

	outfile << "\t\t\treturn(items);" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	// diff
	outfile << "\t\tpublic HashSet<Integer> diff(" << endl;
	outfile << "\t\t\t\t\t" << subsref << " comp" << endl;
	outfile << "\t\t\t\t) {" << endl;
	outfile << "\t\t\tHashSet<Integer> commitems;" << endl;
	outfile << "\t\t\tHashSet<Integer> diffitems;" << endl;
	outfile << endl;

	outfile << "\t\t\tcommitems = comm(comp);" << endl;
	outfile << endl;

	outfile << "\t\t\tdiffitems = new HashSet<Integer>(Arrays.asList(";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		
		if (i != 0) outfile << ", ";

		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
		outfile << StrMod::uc(bit->sref);
	};
	outfile << "));" << endl;
	outfile << "\t\t\tfor (Integer ci: commitems) diffitems.remove(ci);" << endl;
	outfile << endl;

	outfile << "\t\t\treturn(diffitems);" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	outfile << "\t};" << endl;
	outfile << endl;
};

void WznmWrjapiJob::writeBlkstgJ(
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
	outfile << "\tpublic class " << subsref << " extends Block {" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		outfile << "\t\tpublic static final int " << StrMod::uc(bit->sref) << " = " << (i+1) << ";" << endl;
	};
	outfile << endl;

	// constructor
	outfile << "\t\tpublic " << subsref << "(" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		outfile << "\t\t\t\t\t";
		if (i != 0) outfile << ", ";
		wrBitvarConstrhdrJ(outfile, bit);
	};
	outfile << "\t\t\t\t) {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarConstrJ(outfile, bit);
	};
	outfile << endl;

	outfile << "\t\t\tmask = new HashSet<Integer>(Arrays.asList(";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << StrMod::uc(bit->sref);
	};
	outfile << "));" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	// variables
	refC = 0;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if ((i != 0) && (bit->refWznmCAMBlockItem != refC)) outfile << endl;

		outfile << "\t\tpublic " << getBitJType(bit) << " ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "scr" << StrMod::cap(bit->sref);
		else outfile << bit->sref;
		outfile << ";" << endl;

		refC = bit->refWznmCAMBlockItem;
	};
	outfile << endl;

	// readXML
	outfile << "\t\tpublic boolean readXML(" << endl;
	outfile << "\t\t\t\t\tDocument doc" << endl;
	outfile << "\t\t\t\t\t, String basexpath" << endl;
	outfile << "\t\t\t\t\t, boolean addbasetag" << endl;
	outfile << "\t\t\t\t) {" << endl;

	for (unsigned int j = 0; j < bits.nodes.size(); j++) {
		bit = bits.nodes[j];
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\t\t\tString sref" << StrMod::cap(bit->sref) << ";" << endl;
	};
	outfile << endl;

	outfile << "\t\t\tclear();" << endl;
	outfile << endl;

	outfile << "\t\t\tif (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, \"" << blk->sref << "\");" << endl;
	outfile << endl;

	outfile << "\t\t\tString itemtag = \"Stgitem" << blk->sref.substr(3) << "\";" << endl;
	outfile << endl;

	outfile << "\t\t\tif (Xmlio.checkXPath(doc, basexpath)) {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarReadxmlJ(dbswznm, outfile, job, bit, true, "Si");
	};
	outfile << endl;

	outfile << "\t\t\t\treturn true;" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << endl;

	outfile << "\t\t\treturn false;" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) {
		// writeXML
		outfile << "\t\tpublic void writeXML(" << endl;
		outfile << "\t\t\t\t\tDocument doc" << endl;
		outfile << "\t\t\t\t\t, Element sup" << endl;
		outfile << "\t\t\t\t\t, String difftag" << endl;
		outfile << "\t\t\t\t\t, boolean shorttags" << endl;
		outfile << "\t\t\t\t) {" << endl;
		outfile << "\t\t\tif (difftag.isEmpty()) difftag = \"" << blk->sref << "\";" << endl;
		outfile << endl;

		outfile << "\t\t\tString itemtag;" << endl;
		outfile << endl;

		outfile << "\t\t\tif (shorttags) itemtag = \"Si\";" << endl;
		outfile << "\t\t\telse itemtag = \"Stgitem" << blk->sref.substr(3) << "\";" << endl;
		outfile << endl;

		outfile << "\t\t\tElement el = doc.createElement(difftag);" << endl;
		outfile << endl;

		outfile << "\t\t\tif (sup == null) doc.appendChild(el);" << endl;
		outfile << "\t\t\telse sup.appendChild(el);" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];
			wrBitvarWritexmlJ(dbswznm, outfile, job, bit, false, true);
		};
		outfile << "\t\t};" << endl;
		outfile << endl;
	};

	// comm
	outfile << "\t\tpublic HashSet<Integer> comm(" << endl;
	outfile << "\t\t\t\t\t" << subsref << " comp" << endl;
	outfile << "\t\t\t\t) {" << endl;
	outfile << "\t\t\tHashSet<Integer> items = new HashSet<Integer>();" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarCompareJ(outfile, bit);
	};
	outfile << endl;

	outfile << "\t\t\treturn(items);" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	// diff
	outfile << "\t\tpublic HashSet<Integer> diff(" << endl;
	outfile << "\t\t\t\t\t" << subsref << " comp" << endl;
	outfile << "\t\t\t\t) {" << endl;
	outfile << "\t\t\tHashSet<Integer> commitems;" << endl;
	outfile << "\t\t\tHashSet<Integer> diffitems;" << endl;
	outfile << endl;

	outfile << "\t\t\tcommitems = comm(comp);" << endl;
	outfile << endl;

	outfile << "\t\t\tdiffitems = new HashSet<Integer>(Arrays.asList(";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << StrMod::uc(bit->sref);
	};
	outfile << "));" << endl;
	outfile << "\t\t\tfor (Integer ci: commitems) diffitems.remove(ci);" << endl;
	outfile << endl;

	outfile << "\t\t\treturn(diffitems);" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	outfile << "\t};" << endl;
	outfile << endl;
};

void WznmWrjapiJob::writeBlktagJ(
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
	outfile << "\tpublic class " << subsref << " extends Block {" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		outfile << "\t\tpublic static final int " << StrMod::uc(bit->sref) << " = " << (i+1) << ";" << endl;
	};
	outfile << endl;

	// constructor
	outfile << "\t\tpublic " << subsref << "(" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		outfile << "\t\t\t\t\t";
		if (i != 0) outfile << ", ";
		wrBitvarConstrhdrJ(outfile, bit);
	};
	outfile << "\t\t\t\t) {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarConstrJ(outfile, bit);
	};
	outfile << endl;

	outfile << "\t\t\tmask = new HashSet<Integer>(Arrays.asList(";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) outfile << ", ";
		outfile << StrMod::uc(bit->sref);
	};
	outfile << "));" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	// variables
	refC = 0;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if ((i != 0) && (bit->refWznmCAMBlockItem != refC)) outfile << endl;

		outfile << "\t\tpublic " << getBitJType(bit) << " ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "scr" << StrMod::cap(bit->sref);
		else outfile << bit->sref;
		outfile << ";" << endl;

		refC = bit->refWznmCAMBlockItem;
	};
	outfile << endl;

	// readXML
	outfile << "\t\tpublic boolean readXML(" << endl;
	outfile << "\t\t\t\t\tDocument doc" << endl;
	outfile << "\t\t\t\t\t, String basexpath" << endl;
	outfile << "\t\t\t\t\t, boolean addbasetag" << endl;
	outfile << "\t\t\t\t) {" << endl;

	for (unsigned int j = 0; j < bits.nodes.size(); j++) {
		bit = bits.nodes[j];
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "\t\t\tString sref" << StrMod::cap(bit->sref) << ";" << endl;
	};
	outfile << endl;

	outfile << "\t\t\tclear();" << endl;
	outfile << endl;

	outfile << "\t\t\tif (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, \"" << blk->sref << "\");" << endl;
	outfile << endl;

	outfile << "\t\t\tString itemtag = \"Tagitem" << blk->sref.substr(3) << "\";" << endl;
	outfile << endl;

	outfile << "\t\t\tif (Xmlio.checkXPath(doc, basexpath)) {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarReadxmlJ(dbswznm, outfile, job, bit, true, "Ti");
	};
	outfile << endl;

	outfile << "\t\t\t\treturn true;" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << endl;

	outfile << "\t\t\treturn false;" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	// comm
	outfile << "\t\tpublic HashSet<Integer> comm(" << endl;
	outfile << "\t\t\t\t\t" << subsref << " comp" << endl;
	outfile << "\t\t\t\t) {" << endl;
	outfile << "\t\t\tHashSet<Integer> items = new HashSet<Integer>();" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarCompareJ(outfile, bit);
	};
	outfile << endl;

	outfile << "\t\t\treturn(items);" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	// diff
	outfile << "\t\tpublic HashSet<Integer> diff(" << endl;
	outfile << "\t\t\t\t\t" << subsref << " comp" << endl;
	outfile << "\t\t\t\t) {" << endl;
	outfile << "\t\t\tHashSet<Integer> commitems;" << endl;
	outfile << "\t\t\tHashSet<Integer> diffitems;" << endl;
	outfile << endl;

	outfile << "\t\t\tcommitems = comm(comp);" << endl;
	outfile << endl;

	outfile << "\t\t\tdiffitems = new HashSet<Integer>(Arrays.asList(";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		
		if (i != 0) outfile << ", ";
		outfile << StrMod::uc(bit->sref);
	};
	outfile << "));" << endl;
	outfile << "\t\t\tfor (Integer ci: commitems) diffitems.remove(ci);" << endl;
	outfile << endl;

	outfile << "\t\t\treturn(diffitems);" << endl;
	outfile << "\t\t};" << endl;
	outfile << endl;

	outfile << "\t};" << endl;
	outfile << endl;
};

void WznmWrjapiJob::wrBitvarConstrhdrJ(
			fstream& outfile
			, WznmAMBlockItem* bit
		) {
	outfile << getBitJType(bit) << " ";
	
	if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "scr" << StrMod::cap(bit->sref) << endl;
	else outfile << bit->sref << endl;
};

// adapted version from WznmWrsrv.cpp
void WznmWrjapiJob::wrBitvarConstrJ(
			fstream& outfile
			, WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "\t\t\tthis.scr" << StrMod::cap(bit->sref) << " = scr" << StrMod::cap(bit->sref) << ";" << endl;
	else outfile << "\t\t\tthis." << bit->sref << " = " << bit->sref << ";" << endl;
};

// adapted version from WznmWrsrv.cpp
void WznmWrjapiJob::wrBitvarReadxmlJ(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmAMBlockItem* bit
			, const bool attr
			, const string& shorttag
		) {
	WznmMVector* vec = NULL;

	if (attr) {
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
			outfile << "\t\t\t\tsref" << StrMod::cap(bit->sref) << " = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, \"" << shorttag << "\", \"sref\", \"sref" << StrMod::cap(bit->sref) << "\", mask, " << StrMod::uc(bit->sref) << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			outfile << "\t\t\t\tscr" << StrMod::cap(bit->sref) << " = Xmlio.extract" << getBitXMLType(bit) << "AttrUclc(doc, basexpath, itemtag, \"" << shorttag << "\", \"sref\", \"scr" << StrMod::cap(bit->sref) << "\", mask, SCR" << StrMod::uc(bit->sref) << ");" << endl;
		} else {
			outfile << "\t\t\t\t" << bit->sref << " = Xmlio.extract" << getBitXMLType(bit) << "AttrUclc(doc, basexpath, itemtag, \"" << shorttag << "\", \"sref\", \"" << bit->sref << "\", mask, " << StrMod::uc(bit->sref) << ");" << endl;
		};

	} else {
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
			outfile << "\t\t\t\tsref" << StrMod::cap(bit->sref) << " = Xmlio.extractStringUclc(doc, basexpath, \"sref" << StrMod::cap(bit->sref) << "\", \"\", mask, " << StrMod::uc(bit->sref) << ");" << endl;
		} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			outfile << "\t\t\t\tscr" << StrMod::cap(bit->sref) << " = Xmlio.extract" << getBitXMLType(bit) << "Uclc(doc, basexpath, \"scr" << StrMod::cap(bit->sref) << "\", \"\", mask, SCR" << StrMod::uc(bit->sref) << ");" << endl;
		} else {
			outfile << "\t\t\t\t" << bit->sref << " = Xmlio.extract" << getBitXMLType(bit) << "Uclc(doc, basexpath, \"" << bit->sref << "\", \"\", mask, " << StrMod::uc(bit->sref) << ");" << endl;
		};
	};

	if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
		if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
			outfile << "\t\t\t\t" << bit->sref << " = " << getVecclass(dbswznm, job, vec) << ".getIx(sref" << StrMod::cap(bit->sref) << ");" << endl;
			delete vec;
		} else {
			outfile << "\t\t\t\t" << bit->sref << " = Vec" << bit->sref.substr(2) << ".getIx(sref" << StrMod::cap(bit->sref)  << ");" << endl;
		};
	};
};

// adapted version from WznmWrsrv.cpp
void WznmWrjapiJob::wrBitvarWritexmlJ(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmAMBlockItem* bit
			, const bool mask
			, const bool attr
		) {
	WznmMVector* vec = NULL;

	outfile << "\t\t\t";
	if (mask) {
		outfile << "if (has(";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
		outfile << StrMod::uc(bit->sref) << ")) ";
	};

	if (attr) {
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
			if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
				outfile << "Xmlio.writeStringAttr(doc, el, itemtag, \"sref\", \"sref" << StrMod::cap(bit->sref) << "\", " << getVecclass(dbswznm, job, vec) << ".getSref(" << bit->sref << "));" << endl;
				delete vec;
			} else {
				outfile << "Xmlio.writeStringAttr(doc, el, itemtag, \"sref\", \"sref" << StrMod::cap(bit->sref) << "\", Vec" << bit->sref.substr(2) << ".getSref(" << bit->sref << "));" << endl;
			};
		} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			outfile << "Xmlio.writeStringAttr(doc, el, itemtag, \"sref\", \"scr" << StrMod::cap(bit->sref) << "\", scr" << StrMod::cap(bit->sref) << ");" << endl;
		} else {
			// VOID, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, FLOAT, DOUBLE, STRING, BOOLEANVEC, UTINYINTVEC, USMALLINTVEC, INTVEC, UINTVEC, UBIGINTVEC, FLOATVEC, DOUBLEVEC, STRINGVEC
			outfile << "Xmlio.write" << getBitXMLType(bit) << "Attr(doc, el, itemtag, \"sref\", \"" << bit->sref << "\", " << bit->sref << ");" << endl;
		};

	} else {
		if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
			if (dbswznm->tblwznmmvector->loadRecByRef(bit->refWznmMVector, &vec)) {
				outfile << "Xmlio.writeString(doc, el, \"sref" << StrMod::cap(bit->sref) << "\", " << getVecclass(dbswznm, job, vec) << ".getSref(" << bit->sref << "));" << endl;
				delete vec;
			};
		} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			outfile << "Xmlio.writeString(doc, el, \"scr" << StrMod::cap(bit->sref) << "\", scr" << StrMod::cap(bit->sref) << ");" << endl;
		} else {
			outfile << "Xmlio.write" << getBitXMLType(bit) << "(doc, el, \"" << bit->sref << "\", " << bit->sref << ");" << endl;
		};
	};
};

// adapted version from WznmWrsrv.cpp
void WznmWrjapiJob::wrBitvarCompareJ(
			fstream& outfile
			, WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::FLOAT) {
		outfile << "\t\t\tif (Xmlio.compareFloat(" << bit->sref << ", comp." << bit->sref << ") < 1.0e-4) items.add(" << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE) {
		outfile << "\t\t\tif (Xmlio.compareDouble(" << bit->sref << ", comp." << bit->sref << ") < 1.0e-4) items.add(" << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRING) {
		outfile << "\t\t\tif (" << bit->sref << ".equals(comp." << bit->sref << ")) items.add(" << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) {
		outfile << "\t\t\tif (Xmlio.compareBooleanvec(" << bit->sref << ", comp." << bit->sref << ")) items.add(" << StrMod::uc(bit->sref) << ");" << endl;
	} else if ((bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) || (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) || (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) || (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC)) {
		outfile << "\t\t\tif (Xmlio.compareIntegervec(" << bit->sref << ", comp." << bit->sref << ")) items.add(" << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) {
		outfile << "\t\t\tif (Xmlio.compareLongvec(" << bit->sref << ", comp." << bit->sref << ")) items.add(" << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) {
		outfile << "\t\t\tif (Xmlio.compareFloatvec(" << bit->sref << ", comp." << bit->sref << ") < 1.0e-4) items.add(" << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) {
		outfile << "\t\t\tif (Xmlio.compareFloatmat(" << bit->sref << ", comp." << bit->sref << ") < 1.0e-4) items.add(" << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) {
		outfile << "\t\t\tif (Xmlio.compareDoublevec(" << bit->sref << ", comp." << bit->sref << ") < 1.0e-4) items.add(" << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) {
		outfile << "\t\t\tif (Xmlio.compareDoublemat(" << bit->sref << ", comp." << bit->sref << ") < 1.0e-4) items.add(" << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) {
		outfile << "\t\t\tif (Xmlio.compareStringvec(" << bit->sref << ", comp." << bit->sref << ")) items.add(" << StrMod::uc(bit->sref) << ");" << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
		outfile << "\t\t\tif (scr" << StrMod::cap(bit->sref) << ".equals(comp.scr" << StrMod::cap(bit->sref) << ")) items.add(SCR" << StrMod::uc(bit->sref) << ");" << endl;
	} else {
		// VOID, BOOLEAN, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, VECSREF
		outfile << "\t\t\tif (" << bit->sref << " == comp." << bit->sref << ") items.add(" << StrMod::uc(bit->sref) << ");" << endl;
	};
};

string WznmWrjapiJob::getBlkclass(
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

string WznmWrjapiJob::getBlknew(
			DbsWznm* dbswznm
			, WznmMJob* job
			, WznmMBlock* blk
		) {
	// ex. "new StatShr()", "(new QryWznmPrjList()).new StgIac(0, 0, 0)"
	string retval = blk->sref;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	WznmMJob* hostjob = NULL;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	if (blk->refIxVTbl == VecWznmVMBlockRefTbl::JOB) {
		if (blk->refUref == job->ref) {
			retval = "new " + Wznm::getSubsref(job, blk->sref);

		} else {
			if (dbswznm->tblwznmmjob->loadRecByRef(blk->refUref, &hostjob)) {
				retval = "(new " + hostjob->sref + "()).new " + Wznm::getSubsref(hostjob, blk->sref);
				delete hostjob;
			};
		};
	};

	retval += "(";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) retval += ", ";
		retval += getJDefault(getBitJType(bit));
	};
	retval += ")";

	return retval;
};

string WznmWrjapiJob::getBitJType(
			WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) return("boolean");
	if (bit->ixWznmVVartype == VecWznmVVartype::TINYINT) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINT) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::SMALLINT) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINT) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::INT) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::UINT) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::BIGINT) return("long");
	if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINT) return("long");
	if (bit->ixWznmVVartype == VecWznmVVartype::FLOAT) return("float");
	if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE) return("double");
	if (bit->ixWznmVVartype == VecWznmVVartype::STRING) return("String");
	if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) return("ArrayList<Boolean>");
	if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) return("ArrayList<Integer>");
	if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) return("ArrayList<Integer>");
	if (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) return("ArrayList<Integer>");
	if (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC) return("ArrayList<Integer>");
	if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) return("ArrayList<Long>");
	if (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) return("ArrayList<Float>");
	if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) return("Floatmat");
	if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) return("ArrayList<Double>");
	if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) return("Doublemat");
	if (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) return("ArrayList<String>");
	if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) return("String");

	return("");
};

string WznmWrjapiJob::getBitXMLType(
			WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::TINYINT) return("Integer");
	if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINT) return("Integer");
	if (bit->ixWznmVVartype == VecWznmVVartype::SMALLINT) return("Integer");
	if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINT) return("Integer");
	if (bit->ixWznmVVartype == VecWznmVVartype::INT) return("Integer");
	if (bit->ixWznmVVartype == VecWznmVVartype::UINT) return("Integer");
	if (bit->ixWznmVVartype == VecWznmVVartype::BIGINT) return("Long");
	if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINT) return("Long");
	if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) return("String");
	if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) return("String");

	return(StrMod::cap(VecWznmVVartype::getSref(bit->ixWznmVVartype)));
};

// exact copy from WznmWrsrv.cpp
string WznmWrjapiJob::getVecclass(
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
				retval = hostjob->sref + "." + Wznm::getSubsref(hostjob, vec->sref);
				delete hostjob;
			};
		};
	};

	return retval;
};
// IP cust --- IEND
