/**
	* \file WznmWrapiJob.cpp
	* Wznm operation processor - write API code for job (implementation)
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

#include "WznmWrapiJob.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrapi;

/******************************************************************************
 namespace WznmWrapiJob
 ******************************************************************************/

DpchRetWznm* WznmWrapiJob::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrapiJob* dpchinv
		) {
	ubigint refWznmMComponent = dpchinv->refWznmMComponent;
	ubigint refWznmMJob = dpchinv->refWznmMJob;
	string orgweb = dpchinv->orgweb;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream hfile;
	fstream cppfile;

	WznmMJob* job = NULL;

	ListWznmMVector vecs;
	ListWznmMBlock blks;

	string s;

	dbswznm->tblwznmmjob->loadRecByRef(refWznmMJob, &job);

	dbswznm->tblwznmmvector->loadRstBySQL("SELECT * FROM TblWznmMVector WHERE hkIxVTbl = " + to_string(VecWznmVMVectorHkTbl::JOB) + " AND hkUref = " + to_string(job->ref) + " ORDER BY sref ASC", false, vecs);
	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
				+ " AND (((reaIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0) OR ((wriIxWznmWScope & " + to_string(VecWznmWScope::APP) + ") <> 0)) ORDER BY sref ASC", false, blks);

	// create files
	s = xchg->tmppath + "/" + folder + "/" + job->sref + ".h.ip";
	hfile.open(s.c_str(), ios::out);
	s = xchg->tmppath + "/" + folder + "/" + job->sref + ".cpp.ip";
	cppfile.open(s.c_str(), ios::out);

	writeJobH(dbswznm, hfile, job, vecs, blks, Prjshort);
	writeJobCpp(dbswznm, cppfile, job, vecs, blks, orgweb, Prjshort);

	hfile.close();
	cppfile.close();

	delete job;
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrapiJob::writeJobH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, const ListWznmMVector& vecs
			, const ListWznmMBlock& blks
			, const string& Prjshort
		) {
	ubigint ref;

	WznmMVector* vec = NULL;
	WznmMBlock* blk = NULL;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	vector<ubigint> refsInctbl;
	ListWznmMTable inctbls;
	WznmMTable* inctbl = NULL;

	vector<ubigint> refsIncjob;
	ListWznmMJob incjobs;
	WznmMJob* incjob = NULL;

	string subsref;

	bool found;

	// --- incs
	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if ((blk->ixVBasetype == VecWznmVMBlockBasetype::DPCH) && ((blk->reaIxWznmWScope & VecWznmWScope::APP) || (blk->wriIxWznmWScope & VecWznmWScope::APP))) {
			dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

			for (unsigned int j = 0; j < bits.nodes.size(); j++) {
				bit = bits.nodes[j];

				if ((bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) && (bit->refWznmMTable != 0)) {
					found = false;

					for (unsigned int k = 0; k < refsInctbl.size(); k++) {
						if (refsInctbl[k] == bit->refWznmMTable) {
							found = true;
							break;
						};
					};

					if (!found) refsInctbl.push_back(bit->refWznmMTable);

				} else if ((bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) && (bit->refWznmMBlock != 0)) {
					found = false;

					for (unsigned int k = 0; k < blks.nodes.size(); k++) {
						blk = blks.nodes[k];
						
						if (blk->ref == bit->refWznmMBlock) {
							found = true;
							break;
						};
					};

					if (!found) {

						if (dbswznm->loadRefBySQL("SELECT refUref FROM TblWznmMBlock WHERE ref = " + to_string(bit->refWznmMBlock) + " AND refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB), ref)) {
							for (unsigned int k = 0; k < refsIncjob.size(); k++) {
								if (refsIncjob[k] == ref) {
									found = true;
									break;
								};
							};

							if (!found) refsIncjob.push_back(ref);
						};
					};
				};
			};
		};
	};

	dbswznm->tblwznmmtable->loadRstByRefs(refsInctbl, false, inctbls);
	dbswznm->tblwznmmjob->loadRstByRefs(refsIncjob, false, incjobs);

	outfile << "// IP include --- IBEGIN" << endl;
	for (unsigned int i = 0; i < inctbls.nodes.size(); i++) {
		inctbl = inctbls.nodes[i];
		outfile << "#include \"" << inctbl->sref.substr(3) << ".h\"" << endl;
	};

	if ((inctbls.nodes.size() > 0) && (incjobs.nodes.size() > 0)) outfile << endl;

	for (unsigned int i = 0; i < incjobs.nodes.size(); i++) {
		incjob = incjobs.nodes[i];
		outfile << "#include \"" << incjob->sref << ".h\"" << endl;
	};
	outfile << "// IP include --- IEND" << endl;

	// --- fsrs.blks
	outfile << "// IP fsrs.blks --- IBEGIN" << endl;
	// order: vec's, blocks ex. dpch, dpch's

	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		subsref = Wznm::getSubsref(job, vec->sref);
		outfile << "#define " << vec->sref << " " << job->sref << "::" << subsref << endl;
	};
	outfile << endl;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if (blk->ixVBasetype != VecWznmVMBlockBasetype::DPCH) {
			subsref = Wznm::getSubsref(job, blk->sref);
			outfile << "#define " << blk->sref << " " << job->sref << "::" << subsref << endl;
		};
	};
	outfile << endl;

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::DPCH) {
			subsref = Wznm::getSubsref(job, blk->sref);
			outfile << "#define " << blk->sref << " " << job->sref << "::" << subsref << endl;
		};
	};
	outfile << "// IP fsrs.blks --- IEND" << endl;

	// --- blks
	outfile << "// IP blks --- IBEGIN" << endl;
	// order: vec's, blocks ex. dpch, dpch's

	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		subsref = Wznm::getSubsref(job, vec->sref);
		writeVecH(dbswznm, Prjshort, outfile, vec, true, subsref);
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		subsref = Wznm::getSubsref(job, blk->sref);

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::CONT) {
			writeBlkcontH(dbswznm, outfile, job, blk, subsref);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::STAT) {
			writeBlkstatH(dbswznm, outfile, job, blk, subsref);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::STG) {
			writeBlkstgH(dbswznm, outfile, job, blk, subsref);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::TAG) {
			writeBlktagH(dbswznm, outfile, job, blk, subsref);
		};
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::DPCH) {
			subsref = Wznm::getSubsref(job, blk->sref);
			writeBlkdpchH(dbswznm, Prjshort, outfile, job, blk, subsref);
		};
	};

	outfile << "// IP blks --- IEND" << endl;
};

void WznmWrapiJob::writeJobCpp(
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

	string subsref;

	// --- blks
	outfile << "// IP blks --- IBEGIN" << endl;
	// order: vec's, blocks ex. dpch, dpch's

	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		subsref = Wznm::getSubsref(job, vec->sref);
		writeVecCpp(dbswznm, Prjshort, outfile, vec, true, job->sref, subsref);
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		subsref = Wznm::getSubsref(job, blk->sref);

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::CONT) {
			writeBlkcontCpp(dbswznm, outfile, job, blk, subsref);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::STAT) {
			writeBlkstatCpp(dbswznm, Prjshort, outfile, job, blk, subsref);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::STG) {
			writeBlkstgCpp(dbswznm, Prjshort, outfile, job, blk, subsref);
		} else if (blk->ixVBasetype == VecWznmVMBlockBasetype::TAG) {
			writeBlktagCpp(dbswznm, outfile, job, blk, subsref);
		};
	};

	for (unsigned int i = 0; i < blks.nodes.size(); i++) {
		blk = blks.nodes[i];

		if (blk->ixVBasetype == VecWznmVMBlockBasetype::DPCH) {
			subsref = Wznm::getSubsref(job, blk->sref);
			writeBlkdpchCpp(dbswznm, orgweb, Prjshort, outfile, job, blk, subsref);
		};
	};

	outfile << "// IP blks --- IEND" << endl;
};

// read/write inverted version from WznmWrsrv.cpp
void WznmWrapiJob::writeBlkcontH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, always cmbeng/eng and app ; read-only for ContInf

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	ubigint refC;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	outfile << "\t/**" << endl;
	outfile << "\t  * " << subsref << " (full: " << blk->sref << ")" << endl;
	outfile << "\t  */" << endl;
	outfile << "\tclass " << subsref << " : public Sbecore::Xmlio::Block {" << endl;
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
	outfile << "\t\tbool readXML(xmlXPathContext* docctx, std::string basexpath = \"\", bool addbasetag = false);" << endl;
	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) outfile << "\t\tvoid writeXML(xmlTextWriter* wr, std::string difftag = \"\", bool shorttags = true);" << endl;
	outfile << "\t\tstd::set<Sbecore::uint> comm(const " << subsref << "* comp);" << endl;
	outfile << "\t\tstd::set<Sbecore::uint> diff(const " << subsref << "* comp);" << endl;
	outfile << "\t};" << endl;
	outfile << endl;
};

// read/write inverted version from WznmWrsrv.cpp
void WznmWrapiJob::writeBlkcontCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, always cmbeng/eng and app ; read-only for ContInf

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

	// writeXML
	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) {
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
	};

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

// read/write inverted and stripped down version from WznmWrsrv.cpp
void WznmWrapiJob::writeBlkdpchH(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// sub-block of job for engine <-> app ; read for DpchEng, write for DpchApp

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	WznmMTable* tbl = NULL;
	WznmMBlock* subblk = NULL;

	unsigned int ix;

	ubigint refC;

	bool first;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

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

		outfile << "\t\tstatic const Sbecore::uint ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR" << StrMod::uc(bit->sref);
		else outfile << StrMod::uc(bit->sref);
		outfile << " = " << (i+1) << ";" << endl;
	};
	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) outfile << "\t\tstatic const Sbecore::uint ALL = " << (bits.nodes.size()+1) << ";" << endl;
	outfile << endl;

	// constructor
	outfile << "\tpublic:" << endl;
	if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
		outfile << "\t\t" << subsref << "();" << endl;

	} else {
		outfile << "\t\t" << subsref << "(const std::string& scrJref = \"\"";

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->sref != "jref") {
				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
					outfile << ", ";
					wrBitvarWritexmlH(dbswznm, outfile, job, bit);
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
					outfile << ", Sbecore::Xmlio::Feed* " << bit->sref << " = NULL";
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						// all sub-blocks should be non-static
						outfile << ", " << getBlkclass(dbswznm, job, subblk) << "* " << StrMod::lc(bit->sref) << " = NULL";
						delete subblk;
					};					
				};
			};
		};

		outfile << ", const std::set<Sbecore::uint>& mask = {NONE});" << endl;
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
				outfile << "\t\tSbecore::Xmlio::Feed " << bit->sref << ";" << endl;
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
					// sub-blocks that are static in engine are not static here
					if (!first && (bit->refWznmCAMBlockItem != refC)) outfile << endl;
					outfile << "\t\t" << getBlkclass(dbswznm, job, subblk) << " " << StrMod::lc(bit->sref) << ";" << endl;
					refC = bit->refWznmCAMBlockItem;
					first = false;

					delete subblk;
				};
			};
		};
	};
	outfile << endl;

	outfile << "\tpublic:" << endl;
	outfile << "\t\tstd::string getSrefsMask();" << endl;
	outfile << endl;
	
	if (blk->reaIxWznmWScope & VecWznmWScope::APP) outfile << "\t\tvoid readXML(xmlXPathContext* docctx, std::string basexpath = \"\", bool addbasetag = false);" << endl;
	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) outfile << "\t\tvoid writeXML(xmlTextWriter* wr);" << endl;
	outfile << "\t};" << endl;
	outfile << endl;
};

// read/write inverted and stripped down version from WznmWrsrv.cpp
void WznmWrapiJob::writeBlkdpchCpp(
			DbsWznm* dbswznm
			, const string& orgweb
			, const string& Prjshort
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// sub-block of job for engine <-> app ; read for DpchEng, write for DpchApp

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	WznmMTable* tbl = NULL;
	WznmMBlock* subblk = NULL;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	outfile << "/******************************************************************************" << endl;
	outfile << " class " << job->sref << "::" << subsref << endl;
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	// constructor
	if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
		outfile << job->sref << "::" << subsref << "::" << subsref << "() :" << endl;
		outfile << "\t\t\tDpchEng" << Prjshort << "(Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << ")" << endl;
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
								|| (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) || (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) || (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC)
								|| (bit->ixWznmVVartype == VecWznmVVartype::SCRREF)) {
					} else {
						// TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, VECSREF
						outfile << "\t" << bit->sref << " = 0;" << endl;
					};
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
					outfile << "\t" << bit->sref << ".tag = \"" << StrMod::cap(bit->sref) << "\";" << endl;
				};
			};
		};

		outfile << "};" << endl;

	} else {
		outfile << job->sref << "::" << subsref << "::" << subsref << "(" << endl;
		outfile << "\t\t\tconst string& scrJref" << endl;

		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->sref != "jref") {
				if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
					outfile << "\t\t\t, ";
					wrBitvarWritexmlhdrCpp(outfile, bit);
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
					outfile << "\t\t\t, Feed* " << bit->sref << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						// all sub-blocks should be non-static
						outfile << "\t\t\t, " << getBlkclass(dbswznm, job, subblk) << "* " << StrMod::lc(bit->sref) << endl;
						delete subblk;
					};					
				};
			};
		};

		outfile << "\t\t\t, const set<uint>& mask" << endl;
		outfile << "\t\t) :" << endl;
		outfile << "\t\t\tDpchApp" << Prjshort << "(Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << ", scrJref)" << endl;
		outfile << "\t\t{" << endl;

		outfile << "\tif (find(mask, ALL)) this->mask = {";
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (i != 0) outfile << ", ";
			if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
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
					outfile << "\t\tif (find(this->mask, " << StrMod::uc(bit->sref) << ") && " << bit->sref << ") this->" << bit->sref << " = *" << bit->sref << ";" << endl;
				} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
					if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
						// all sub-blocks should be non-static
						outfile << "\t\tif (find(this->mask, " << StrMod::uc(bit->sref) << ") && " << bit->sref << ") this->" << bit->sref << " = *" << bit->sref << ";" << endl;
						delete subblk;
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

		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "\tif (has(SCR" << StrMod::uc(bit->sref) << ")) ss.push_back(\"scr" << StrMod::cap(bit->sref) << "\");" << endl;
		else outfile << "\tif (has(" << StrMod::uc(bit->sref) << ")) ss.push_back(\"" << bit->sref << "\");" << endl;
	};
	outfile << endl;

	outfile << "\tStrMod::vectorToString(ss, srefs);" << endl;
	outfile << endl;

	outfile << "\treturn(srefs);" << endl;
	outfile << "};" << endl;
	outfile << endl;

	if (blk->reaIxWznmWScope & VecWznmWScope::APP) {
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
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
				outfile << "\t\tif (" << bit->sref << ".readXML(docctx, basexpath, true)) add(" << StrMod::uc(bit->sref) << ");" << endl;
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
				outfile << "\t\tif (" << bit->sref << ".readXML(docctx, basexpath, true)) add(" << StrMod::uc(bit->sref) << ");" << endl;
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
				outfile << "\t\tif (" << StrMod::lc(bit->sref) << ".readXML(docctx, basexpath, true)) add(" << StrMod::uc(bit->sref) << ");" << endl;
			};
		};
		outfile << "\t} else {" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
				outfile << "\t\t" << bit->sref << ".clear();" << endl;
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::RST) {
				outfile << "\t\t" << bit->sref << ".clear();" << endl;
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
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

	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) {
		// writeXML
		outfile << "void " << job->sref << "::" << subsref << "::writeXML(" << endl;
		outfile << "\t\t\txmlTextWriter* wr" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\txmlTextWriterStartElement(wr, BAD_CAST \"" << blk->sref << "\");" << endl;
		outfile << "\txmlTextWriterWriteAttribute(wr, BAD_CAST \"xmlns\", BAD_CAST \"" << orgweb << "/" << StrMod::lc(Prjshort) << "\");" << endl;
		for (unsigned int i = 0; i < bits.nodes.size(); i++) {
			bit = bits.nodes[i];

			if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::VAR) {
				wrBitvarWritexmlCpp(dbswznm, outfile, job, bit, true, false);
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::FEED) {
				outfile << "\t\tif (has(" << StrMod::uc(bit->sref) << ")) " << bit->sref << ".writeXML(wr);" << endl;
			} else if (bit->ixVBasetype == VecWznmVAMBlockItemBasetype::SUB) {
				if (dbswznm->tblwznmmblock->loadRecByRef(bit->refWznmMBlock, &subblk)) {
					// all sub-blocks should be non-static
					outfile << "\t\tif (has(" << StrMod::uc(bit->sref) << ")) " << StrMod::lc(bit->sref) << ".writeXML(wr);" << endl;
					delete subblk;
				};
			};
		};
		outfile << "\txmlTextWriterEndElement(wr);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::writeBlkstatH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, always cmbeng/eng and app ; read-only

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	ubigint refC;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	outfile << "\t/**" << endl;
	outfile << "\t  * " << subsref << " (full: " << blk->sref << ")" << endl;
	outfile << "\t  */" << endl;
	outfile << "\tclass " << subsref << " : public Sbecore::Xmlio::Block {" << endl;
	outfile << endl;

	outfile << "\tpublic:" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		outfile << "\t\tstatic const Sbecore::uint ";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR" << StrMod::uc(bit->sref);
		else outfile << StrMod::uc(bit->sref);
		outfile << " = " << (i+1) << ";" << endl;
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
	outfile << "\t\tbool readXML(xmlXPathContext* docctx, std::string basexpath = \"\", bool addbasetag = false);" << endl;
	outfile << "\t\tstd::set<Sbecore::uint> comm(const " << subsref << "* comp);" << endl;
	outfile << "\t\tstd::set<Sbecore::uint> diff(const " << subsref << "* comp);" << endl;
	outfile << "\t};" << endl;
	outfile << endl;
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::writeBlkstatCpp(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, always cmbeng/eng and app ; read-only

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
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
		outfile << StrMod::uc(bit->sref);
	};
	outfile << "};" << endl;

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

	outfile << "\tstring itemtag = \"Statitem" << blk->sref.substr(4) << "\";" << endl;
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

		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR" << StrMod::uc(bit->sref);
		else outfile << StrMod::uc(bit->sref);
	};
	outfile << "};" << endl;
	outfile << "\tfor (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);" << endl;
	outfile << endl;

	outfile << "\treturn(diffitems);" << endl;
	outfile << "};" << endl;
	outfile << endl;
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::writeBlkstgH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, always cmbeng/eng and app ; read-only for StgApp

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	ubigint refC;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	outfile << "\t/**" << endl;
	outfile << "\t  * " << subsref << " (full: " << blk->sref << ")" << endl;
	outfile << "\t  */" << endl;
	outfile << "\tclass " << subsref << " : public Sbecore::Xmlio::Block {" << endl;
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
	outfile << "\t\tbool readXML(xmlXPathContext* docctx, std::string basexpath = \"\", bool addbasetag = false);" << endl;
	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) outfile << "\t\tvoid writeXML(xmlTextWriter* wr, std::string difftag = \"\", bool shorttags = true);" << endl;
	outfile << "\t\tstd::set<Sbecore::uint> comm(const " << subsref << "* comp);" << endl;
	outfile << "\t\tstd::set<Sbecore::uint> diff(const " << subsref << "* comp);" << endl;
	outfile << "\t};" << endl;
	outfile << endl;
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::writeBlkstgCpp(
			DbsWznm* dbswznm
			, const string& Prjshort
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, always cmbeng/eng and app ; read-only for StgApp

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

	// writeXML
	if (blk->reaIxWznmWScope & VecWznmWScope::CMBENG) {
		outfile << "void " << job->sref << "::" << subsref << "::writeXML(" << endl;
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
	};

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

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::writeBlktagH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, always cmbeng/eng and app ; read-only

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	ubigint refC;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	outfile << "\t/**" << endl;
	outfile << "\t  * " << subsref << " (full: " << blk->sref << ")" << endl;
	outfile << "\t  */" << endl;
	outfile << "\tclass " << subsref << " : public Sbecore::Xmlio::Block {" << endl;
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
	outfile << "\t\tbool readXML(xmlXPathContext* docctx, std::string basexpath = \"\", bool addbasetag = false);" << endl;
	outfile << "\t};" << endl;
	outfile << endl;
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::writeBlktagCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMBlock* blk
			, const string& subsref
		) {
	// always sub-block of job, always cmbeng/eng and app ; read-only

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

	outfile << "\tstring itemtag = \"Tagitem" << blk->sref.substr(3) << "\";" << endl;
	outfile << endl;

	outfile << "\tif (basefound) {" << endl;
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];
		wrBitvarReadxmlCpp(dbswznm, outfile, job, bit, true, "Ti");
	};
	outfile << "\t};" << endl;
	outfile << endl;

	outfile << "\treturn basefound;" << endl;
	outfile << "};" << endl;
	outfile << endl;
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::wrBitvarConstrH(
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
		outfile << "const std::string& scr" << StrMod::cap(bit->sref) << " = \"\"";
	} else {
		// TINYINT, UTINYINT, SMALLINT, USMALLINT, UINT, BIGINT, UBIGINT
		outfile << "const Sbecore::" << VecWznmVVartype::getSref(bit->ixWznmVVartype) << " " << bit->sref << " = ";
		if (bit->Defval.length() == 0) outfile << "0"; else outfile << bit->Defval;
	};
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::wrVarDeclH(
			fstream& outfile
			, const uint ixWznmVVartype
			, const string& sref
			, const unsigned int il
		) {
	outfile << "\t";
	for (unsigned int i = 0; i < il; i++) outfile << "\t";

	if (ixWznmVVartype == VecWznmVVartype::SCRREF) {
		outfile << "std::string scr" << StrMod::cap(sref) << ";" << endl;

	} else {
		if (ixWznmVVartype == VecWznmVVartype::VOID) outfile << "void";
		else if (ixWznmVVartype == VecWznmVVartype::BOOLEAN) outfile << "bool";
		else if (ixWznmVVartype == VecWznmVVartype::INT) outfile << "int";
		else if (ixWznmVVartype == VecWznmVVartype::FLOAT) outfile << "float";
		else if (ixWznmVVartype == VecWznmVVartype::DOUBLE) outfile << "double";
		else if (ixWznmVVartype == VecWznmVVartype::STRING) outfile << "std::string";
		else if (ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) outfile << "std::vector<bool>";
		else if (ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) outfile << "std::vector<Sbecore::utinyint>";
		else if (ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) outfile << "std::vector<Sbecore::usmallint>";
		else if (ixWznmVVartype == VecWznmVVartype::INTVEC) outfile << "std::vector<int>";
		else if (ixWznmVVartype == VecWznmVVartype::UINTVEC) outfile << "std::vector<Sbecore::uint>";
		else if (ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) outfile << "std::vector<Sbecore::ubigint>";
		else if (ixWznmVVartype == VecWznmVVartype::FLOATVEC) outfile << "std::vector<float>";
		else if (ixWznmVVartype == VecWznmVVartype::FLOATMAT) outfile << "Sbecore::Floatmat";
		else if (ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) outfile << "std::vector<double>";
		else if (ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) outfile << "Sbecore::Doublemat";
		else if (ixWznmVVartype == VecWznmVVartype::STRINGVEC) outfile << "std::vector<std::string>";
		else if (ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "Sbecore::uint";
		else {
			// TINYINT, UTINYINT, SMALLINT, USMALLINT, UINT, BIGINT, UBIGINT
			outfile << "Sbecore::" << VecWznmVVartype::getSref(ixWznmVVartype);
		};

		outfile << " " << sref << ";" << endl;
	};
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::wrBitvarConstrhdrCpp(
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
		outfile << "const string& scr" << StrMod::cap(bit->sref) << endl;
	} else {
		// VOID, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, FLOAT, DOUBLE
		outfile << "const " << VecWznmVVartype::getSref(bit->ixWznmVVartype) << " " << bit->sref << endl;
	};
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::wrBitvarConstrCpp(
			fstream& outfile
			, WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "\tthis->scr" << StrMod::cap(bit->sref) << " = scr" << StrMod::cap(bit->sref) << ";" << endl;
	else outfile << "\tthis->" << bit->sref << " = " << bit->sref << ";" << endl;
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::wrBitvarReadxmlCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmAMBlockItem* bit
			, const bool attr
			, const string& shorttag
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
			outfile << "\t\tif (extractStringAttrUclc(docctx, basexpath, itemtag, \"" << shorttag << "\", \"sref\", \"scr" << StrMod::cap(bit->sref) << "\", scr" << StrMod::cap(bit->sref) << ")) add(SCR" << StrMod::uc(bit->sref) << ");" << endl;
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
			outfile << "\t\tif (extractStringUclc(docctx, basexpath, \"scr" << StrMod::cap(bit->sref) << "\", \"\", scr" << StrMod::cap(bit->sref) << ")) add(SCR" << StrMod::uc(bit->sref) << ");" << endl;
		} else {
			// VOID, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, FLOAT, DOUBLE, STRING, UTINYINTVEC, USMALLINTVEC, INTVEC, UINTVEC, UBIGINTVEC, FLOATVEC, DOUBLEVEC, STRINGVEC
			outfile << "\t\tif (extract" << StrMod::cap(VecWznmVVartype::getSref(bit->ixWznmVVartype)) << "Uclc(docctx, basexpath, \"" << bit->sref << "\", \"\", " << bit->sref << ")) add(" << StrMod::uc(bit->sref) << ");" << endl;
		};
	};
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::wrBitvarWritexmlH(
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
		outfile << "const std::string& scr" << StrMod::cap(bit->sref) << " = \"\"";
	} else {
		// TINYINT, UTINYINT, SMALLINT, USMALLINT, UINT, BIGINT, UBIGINT
		outfile << "const Sbecore::" << VecWznmVVartype::getSref(bit->ixWznmVVartype) << " " << bit->sref << " = ";
		if (bit->Defval.length() == 0) outfile << "0"; else outfile << bit->Defval;
	};
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::wrBitvarWritexmlhdrCpp(
			fstream& outfile
			, WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) {
		outfile << "const bool " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRING) {
		outfile << "const string& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) {
		outfile << ", const vector<bool>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) {
		outfile << ", const vector<utinyint>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) {
		outfile << ", const vector<usmallint>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) {
		outfile << ", const vector<int>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC) {
		outfile << ", const vector<uint>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) {
		outfile << ", const vector<ubigint>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) {
		outfile << ", const vector<float>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) {
		outfile << ", const Floatmat& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) {
		outfile << ", const vector<double>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) {
		outfile << ", const Doublemat& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) {
		outfile << "const vector<string>& " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) {
		outfile << "const uint " << bit->sref << endl;
	} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
		outfile << "const string& scr" << StrMod::cap(bit->sref) << endl;
	} else {
		// VOID, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, FLOAT, DOUBLE
		outfile << "const " << VecWznmVVartype::getSref(bit->ixWznmVVartype) << " " << bit->sref << endl;
	};
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::wrBitvarWritexmlCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmAMBlockItem* bit
			, const bool mask
			, const bool attr
		) {
	WznmMVector* vec = NULL;

	if (mask) {
		outfile << "\t\tif (has(";
		if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) outfile << "SCR";
		outfile << StrMod::uc(bit->sref) << ")) ";
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
			outfile << "writeStringAttr(wr, itemtag, \"sref\", \"scr" << StrMod::cap(bit->sref) << "\", scr" << StrMod::cap(bit->sref) << ");" << endl;
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
			};
		} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
			outfile << "writeString(wr, \"scr" << StrMod::cap(bit->sref) << "\", scr" << StrMod::cap(bit->sref) << ");" << endl;
		} else {
			// VOID, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, FLOAT, DOUBLE, STRING, BOOLEANVEC, UTINYINTVEC, USMALLINTVEC, INTVEC, UINTVEC, UBIGINTVEC, FLOATVEC, DOUBLEVEC, STRINGVEC
			outfile << "write" << StrMod::cap(VecWznmVVartype::getSref(bit->ixWznmVVartype)) << "(wr, \"" << bit->sref << "\", " << bit->sref << ");" << endl;
		};
	};
};

// adapted version from WznmWrsrv.cpp
void WznmWrapiJob::wrBitvarCompareCpp(
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
	} else if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) {
		outfile << "\tif (scr" << StrMod::cap(bit->sref) << " == comp->scr" << StrMod::cap(bit->sref) << ") insert(items, SCR" << StrMod::uc(bit->sref) << ");" << endl;
	} else {
		// VOID, BOOLEAN, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BIGINT, UBIGINT, STRING, VECSREF
		outfile << "\tif (" << bit->sref << " == comp->" << bit->sref << ") insert(items, " << StrMod::uc(bit->sref) << ");" << endl;
	};
};

// exact copy from WznmWrsrv.cpp
string WznmWrapiJob::getBlkclass(
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

// exact copy from WznmWrsrv.cpp
string WznmWrapiJob::getVecclass(
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
// IP cust --- IEND
