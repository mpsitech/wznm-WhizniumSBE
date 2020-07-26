/**
	* \file WznmWrsrvDds.cpp
	* Wznm operation processor - write C++ code for DDS publisher (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrsrvDds.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

/******************************************************************************
 namespace WznmWrsrvDds
 ******************************************************************************/

DpchRetWznm* WznmWrsrvDds::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvDds* dpchinv
		) {
	ubigint refWznmMComponent = dpchinv->refWznmMComponent;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;
	string inifolder = dpchinv->inifolder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	ListWznmRMJobMJob jrjs;
	ListWznmMJob jobs;

	WznmMComponent* cmp = NULL;
	string Cmpsref;

	fstream idlfile;
	fstream hfile;
	fstream cppfile;

	string s;

	if (dbswznm->tblwznmmcomponent->loadRecByRef(refWznmMComponent, &cmp)) {
		Cmpsref = StrMod::cap(cmp->sref);

		if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(cmp->refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMJobBasetype::SESS) + " AND sref = 'M2msess" + Prjshort + "'", ref)) {
			dbswznm->tblwznmrmjobmjob->loadRstBySup(ref, false, jrjs);

			jobs.nodes.resize(jrjs.nodes.size(), NULL);
			for (unsigned int i = 0; i < jrjs.nodes.size(); i++) dbswznm->tblwznmmjob->loadRecByRef(jrjs.nodes[i]->subRefWznmMJob, &(jobs.nodes[i]));

			if (cmp->ixVBasetype == VecWznmVMComponentBasetype::CMBENG) {
				s = xchg->tmppath + "/" + inifolder + "/Dds" + Prjshort + ".idl.ip";
				idlfile.open(s.c_str(), ios::out);
				writeIdlfileIdl(dbswznm, idlfile, Prjshort, jobs);
				idlfile.close();
			};

			s = xchg->tmppath + "/" + folder + "/" + Cmpsref + "Ddspub.h.ip";
			hfile.open(s.c_str(), ios::out);
			writeDdspubH(dbswznm, hfile, Prjshort, jobs);
			hfile.close();

			s = xchg->tmppath + "/" + folder + "/" + Cmpsref + "Ddspub.cpp.ip";
			cppfile.open(s.c_str(), ios::out);
			writeDdspubCpp(dbswznm, cppfile, Prjshort, Cmpsref, jrjs, jobs);
			cppfile.close();
		};

		delete cmp;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvDds::writeIdlfileIdl(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, ListWznmMJob& jobs
		) {
	WznmMJob* job = NULL;

	ListWznmMMethod mtds;
	WznmMMethod* mtd = NULL;

	ListWznmAMJobVar vars;
	WznmAMJobVar* var = NULL;

	vector<string> varsrefs;
	string varsref;
	vector<bool> Shrs;
	vector<unsigned int> Ns;

	ListWznmAMMethodInvpar ipas;
	WznmAMMethodInvpar* ipa = NULL;

	ListWznmAMMethodRetpar rpas;
	WznmAMMethodRetpar* rpa = NULL;

	// --- defs
	outfile << "// IP defs --- IBEGIN" << endl;

	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		dbswznm->tblwznmmmethod->loadRstByJob(job->ref, false, mtds);
		Wznm::getJobvars(dbswznm, job->ref, vars, varsrefs, Shrs, Ns);

		if ((mtds.nodes.size() > 0) || (varsrefs.size() > 0)) {
			outfile << "module Dds" << job->sref << " {" << endl;

			for (unsigned int j = 0; j < mtds.nodes.size(); j++) {
				mtd = mtds.nodes[j];

				dbswznm->tblwznmammethodinvpar->loadRstByMtd(mtd->ref, false, ipas);
				dbswznm->tblwznmammethodretpar->loadRstByMtd(mtd->ref, false, rpas);

				if (j != 0) outfile << endl;

				outfile << "\tstruct " << mtd->sref << "_req {" << endl;

				if (ipas.nodes.size() == 0) {
					outfile << "\t\tboolean dummy;" << endl;
				} else {
					for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
						ipa = ipas.nodes[k];
						outfile << "\t\t" << getVarIdltype(ipa->ixWznmVVartype, ipa->Length) << " " << ipa->sref << ";" << endl;
					};
				};

				outfile << "\t};" << endl;
				outfile << endl;

				outfile << "\tstruct " << mtd->sref << "_reply {" << endl;
				outfile << "\t\tboolean success;" << endl;

				for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
					rpa = rpas.nodes[k];
					outfile << "\t\t" << getVarIdltype(rpa->ixWznmVVartype, rpa->Length) << " " << rpa->sref << ";" << endl;
				};

				outfile << "\t};" << endl;
			};

			unsigned int k = 0;

			for (unsigned int j = 0; j < varsrefs.size(); j++) {
				varsref = varsrefs[j];

				if ((mtds.nodes.size() > 0) || (j != 0)) outfile << endl;

				outfile << "\tstruct " << varsref << " {" << endl;

				for (unsigned int l = 0; l < Ns[j]; l++, k++) {
					var = vars.nodes[k];

					outfile << "\t\t" << getVarIdltype(var->ixWznmVVartype, var->Length) << " ";
					if (Ns[j] == 1) outfile << "_";
					outfile << var->sref << ";" << endl;
				};

				outfile << "\t};" << endl;
			};

			outfile << "};" << endl;
			outfile << endl;
		};
	};

	outfile << "// IP defs --- IEND" << endl;
};

void WznmWrsrvDds::writeDdspubH(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, ListWznmMJob& jobs
		) {
	WznmMJob* job = NULL;

	ListWznmMMethod mtds;
	WznmMMethod* mtd = NULL;

	ListWznmAMJobVar vars;

	vector<string> varsrefs;
	string varsref;
	vector<bool> Shrs;
	vector<unsigned int> Ns;

	bool first;

	// --- Repliers
	outfile << "// IP Repliers --- IBEGIN" << endl;

	first = true;

	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		dbswznm->tblwznmmmethod->loadRstByJob(job->ref, false, mtds);

		if (mtds.nodes.size() > 0) {
			if (first) first = false;
			else outfile << endl;

			for (unsigned int j = 0; j < mtds.nodes.size(); j++) {
				mtd = mtds.nodes[j];
				outfile << "\t\trti::request::Replier<Dds" << job->sref << "::" << mtd->sref << "_req,Dds" << job->sref << "::" << mtd->sref << "_reply>* replier" << job->sref << "_" << mtd->sref << ";" << endl;
			};
		};
	};
	outfile << "// IP Repliers --- IEND" << endl;

	// --- DataWriters
	outfile << "// IP DataWriters --- IBEGIN" << endl;

	first = true;

	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		Wznm::getJobvars(dbswznm, job->ref, vars, varsrefs, Shrs, Ns);

		for (unsigned int j = 0; j < varsrefs.size(); j++) {
			varsref = varsrefs[j];

			if (first) first = false;
			else outfile << endl;

    	outfile << "\t\tdds::topic::Topic<Dds" << job->sref << "::" << varsref << ">* topic" << job->sref << "_" << varsref << ";" << endl;
    	outfile << "\t\tdds::pub::DataWriter<Dds" << job->sref << "::" << varsref << ">* writer" << job->sref << "_" << varsref << ";" << endl;
    	outfile << "\t\tDds" << job->sref << "::" << varsref << "* " << job->sref << "_" << varsref << ";" << endl;
		};
	};
	outfile << "// IP DataWriters --- IEND" << endl;
};

void WznmWrsrvDds::writeDdspubCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, const string& Cmpsref
			, ListWznmRMJobMJob& jrjs
			, ListWznmMJob& jobs
		) {
	WznmRMJobMJob* jrj = NULL;
	WznmMJob* job = NULL;

	ListWznmMMethod mtds;
	WznmMMethod* mtd = NULL;

	ListWznmAMJobVar vars;
	WznmAMJobVar* var = NULL;

	vector<string> varsrefs;
	string varsref;
	vector<bool> Shrs;
	vector<unsigned int> Ns;

	ListWznmAMMethodInvpar ipas;
	WznmAMMethodInvpar* ipa = NULL;

	ListWznmAMMethodRetpar rpas;
	WznmAMMethodRetpar* rpa = NULL;

	string PRJSHORT = StrMod::uc(Prjshort);

	bool first;

	// --- onReqAvls
	outfile << "// IP onReqAvls --- IBEGIN" << endl;

	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
		jrj = jrjs.nodes[i];
		job = jobs.nodes[i];

		dbswznm->tblwznmmmethod->loadRstByJob(job->ref, false, mtds);

		for (unsigned int j = 0; j < mtds.nodes.size(); j++) {
			mtd = mtds.nodes[j];

			dbswznm->tblwznmammethodinvpar->loadRstByMtd(mtd->ref, false, ipas);
			dbswznm->tblwznmammethodretpar->loadRstByMtd(mtd->ref, false, rpas);

			outfile << "\t\ttemplate<> void ReplierListener<Dds" << job->sref << "::" << mtd->sref << "_req,Dds" << job->sref << "::" << mtd->sref << "_reply>::on_request_available(" << endl;
			outfile << "\t\t\t\t\tReplier<Dds" << job->sref << "::" << mtd->sref << "_req,Dds" << job->sref << "::" << mtd->sref << "_reply>& replier" << endl;
			outfile << "\t\t\t\t) {" << endl;
			outfile << "\t\t\tauto requests = replier.receive_requests(dds::core::Duration());" << endl;
			outfile << "\t\t\tDds" << job->sref << "::" << mtd->sref << "_reply reply;" << endl;
			outfile << endl;

			outfile << "\t\t\tfor (const auto& request: requests) {" << endl;
			outfile << "\t\t\t\tif (!request.info().valid()) continue;" << endl;
			outfile << endl;

			outfile << "\t\t\t\t" << Cmpsref << "Ddspub::runMethod(" << Cmpsref << "Ddspub::statshr.jref" << StrMod::cap(jrj->Short) << ", Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "METHOD, \"" << mtd->sref << "\"," << endl;

			outfile << "\t\t\t\t\t\t\t{";
			if (ipas.nodes.size() == 0) outfile << "&request.data().dummy()";
			else {
				for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
					ipa = ipas.nodes[k];

					if (k != 0) outfile << ", ";
					outfile << "&request.data()." << ipa->sref << "()";
				};
			};
			outfile << "}," << endl;

			outfile << "\t\t\t\t\t\t\t{&reply.success()";
			for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
				rpa = rpas.nodes[k];
				outfile << ", &reply." << rpa->sref << "()";
			};
			outfile << "});" << endl;

			outfile << endl;

			outfile << "\t\t\t\treplier.send_reply(reply, request.info());" << endl;
			outfile << "\t\t\t};" << endl;
			outfile << "\t\t};" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP onReqAvls --- IEND" << endl;

	// --- Repliers.constructor
	outfile << "// IP Repliers.constructor --- IBEGIN" << endl;

	first = true;

	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		dbswznm->tblwznmmmethod->loadRstByJob(job->ref, false, mtds);

		if (mtds.nodes.size() > 0) {
			if (first) first = false;
			else outfile << endl;

			for (unsigned int j = 0; j < mtds.nodes.size(); j++) {
				mtd = mtds.nodes[j];
				outfile << "\treplier" << job->sref << "_" << mtd->sref << " = NULL;" << endl;
			};
		};
	};
	outfile << "// IP Repliers.constructor --- IEND" << endl;

	// --- Repliers.destructor
	outfile << "// IP Repliers.destructor --- IBEGIN" << endl;
	first = true;

	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		dbswznm->tblwznmmmethod->loadRstByJob(job->ref, false, mtds);

		if (mtds.nodes.size() > 0) {
			if (first) first = false;
			else outfile << endl;

			for (unsigned int j = 0; j < mtds.nodes.size(); j++) {
				mtd = mtds.nodes[j];
				outfile << "\tif (replier" << job->sref << "_" << mtd->sref << ") delete replier" << job->sref << "_" << mtd->sref << ";" << endl;
			};
		};
	};
	outfile << "// IP Repliers.destructor --- IEND" << endl;

	// --- DataWriters.constructor
	outfile << "// IP DataWriters.constructor --- IBEGIN" << endl;

	first = true;

	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		Wznm::getJobvars(dbswznm, job->ref, vars, varsrefs, Shrs, Ns);

		for (unsigned int j = 0; j < varsrefs.size(); j++) {
			varsref = varsrefs[j];

			if (first) first = false;
			else outfile << endl;

    	outfile << "\ttopic" << job->sref << "_" << varsref << " = NULL;" << endl;
    	outfile << "\twriter" << job->sref << "_" << varsref << " = NULL;" << endl;
    	outfile << "\t" << job->sref << "_" << varsref << " = NULL;" << endl;
		};
	};
	outfile << "// IP DataWriters.constructor --- IEND" << endl;

	// --- DataWriters.destructor
	outfile << "// IP DataWriters.destructor --- IBEGIN" << endl;
	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		Wznm::getJobvars(dbswznm, job->ref, vars, varsrefs, Shrs, Ns);

		for (unsigned int j = 0; j < varsrefs.size(); j++) {
			varsref = varsrefs[j];

			outfile << "\tif (topic" << job->sref << "_" << varsref << ") {" << endl;
    	outfile << "\t\tdelete topic" << job->sref << "_" << varsref << ";" << endl;
    	outfile << "\t\tdelete writer" << job->sref << "_" << varsref << ";" << endl;
    	outfile << "\t\tdelete " << job->sref << "_" << varsref << ";" << endl;
			outfile << "\t};" << endl;
		};
	};
	outfile << "// IP DataWriters.destructor --- IEND" << endl;

	// --- run.repliers
	outfile << "// IP run.repliers --- IBEGIN" << endl;
	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
		jrj = jrjs.nodes[i];
		job = jobs.nodes[i];

		dbswznm->tblwznmmmethod->loadRstByJob(job->ref, false, mtds);

		if (mtds.nodes.size() > 0) {
			outfile << "\tif (statshr.jref" << StrMod::cap(jrj->Short) << " != 0) {" << endl;
			for (unsigned int j = 0; j < mtds.nodes.size(); j++) {
				mtd = mtds.nodes[j];

				outfile << "\t\txchg->triggerIxSrefToIxCall(NULL, Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "ACCESS, statshr.jref" << StrMod::cap(jrj->Short) << ", Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "METHOD, \"" << mtd->sref << "\", ixAcc);" << endl;
				outfile << "\t\tif ((ixAcc & Vec" << Prjshort << "WAccess::EXEC) == Vec" << Prjshort << "WAccess::EXEC) {" << endl;
				outfile << "\t\t\tparams.service_name(\"" << job->sref << "." << mtd->sref << "\");" << endl;
				//outfile << "\t\t\tparams.request_topic_name(\"" << job->sref << "." << mtd->sref << "_req\");" << endl;
				//outfile << "\t\t\tparams.reply_topic_name(\"" << job->sref << "." << mtd->sref << "_reply\");" << endl;
				outfile << "\t\t\trepliers.replier" << job->sref << "_" << mtd->sref << " = new rti::request::Replier<Dds" << job->sref << "::" << mtd->sref << "_req,Dds" << job->sref << "::" << mtd->sref << "_reply>(params);" << endl;
				outfile << "\t\t};" << endl;
			};
			outfile << "\t};" << endl;
		};
	};
	outfile << "// IP run.repliers --- IEND" << endl;

	// --- run.dataWriters
	outfile << "// IP run.dataWriters --- IBEGIN" << endl;
	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
		jrj = jrjs.nodes[i];
		job = jobs.nodes[i];

		Wznm::getJobvars(dbswznm, job->ref, vars, varsrefs, Shrs, Ns);

		if (varsrefs.size() > 0) {
			outfile << "\tif (statshr.jref" << StrMod::cap(jrj->Short) << " != 0) {" << endl;

			for (unsigned int j = 0; j < varsrefs.size(); j++) {
				varsref = varsrefs[j];

				outfile << "\t\txchg->triggerIxSrefToIxCall(NULL, Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "ACCESS, statshr.jref" << StrMod::cap(jrj->Short) << ", Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "VAR, \"" << varsref << "\", ixAcc);" << endl;
				outfile << "\t\tif ((ixAcc & Vec" << Prjshort << "WAccess::VIEW) == Vec" << Prjshort << "WAccess::VIEW) {" << endl;
				outfile << "\t\t\tdataWriters." << job->sref << "_" << varsref << " = new Dds" << job->sref << "::" << varsref << "();" << endl;
				outfile << "\t\t\tdataWriters.topic" << job->sref << "_" << varsref << " = new dds::topic::Topic<Dds" << job->sref << "::" << varsref << ">(participant, \"" << job->sref << "." << varsref << "\");" << endl;

				outfile << "\t\t\t";
				outfile << "dataWriters.writer" << job->sref << "_" << varsref << " = new dds::pub::DataWriter<Dds" << job->sref << "::" << varsref << ">(dds::pub::Publisher(participant), *dataWriters.topic" << job->sref << "_" << varsref << ");" << endl;
				outfile << endl;

				outfile << "\t\t\txchg->addClstnDdspub(statshr.jref" << StrMod::cap(jrj->Short) << ", \"" << varsref << "\"";
				if (Shrs[j]) outfile << ", true";
				else outfile << ", false";
				outfile << ");" << endl;
				outfile << "\t\t};" << endl;
			};

			outfile << "\t};" << endl;
		};
	};
	outfile << "// IP run.dataWriters --- IEND" << endl;

	// --- run.varupdate
	outfile << "// IP run.varupdate --- IBEGIN" << endl;

	first = true;

	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
		jrj = jrjs.nodes[i];
		job = jobs.nodes[i];

		Wznm::getJobvars(dbswznm, job->ref, vars, varsrefs, Shrs, Ns);

		unsigned int k = 0;

		for (unsigned int j = 0; j < varsrefs.size(); j++) {
			varsref = varsrefs[j];

			outfile << "\t\t";
			if (first) first = false;
			else outfile << "} else ";

			outfile << "if ((xchg->ddspubcall->jref == statshr.jref" << StrMod::cap(jrj->Short) << ") && (xchg->ddspubcall->argInv.sref == \"" << varsref << "\")) {" << endl;

			// TBD: non-shrdat
			outfile << "\t\t\t" << job->sref << "::shrdat.rlockAccess(\"" << Cmpsref << "Ddspub\", \"run\");" << endl;

			for (unsigned int l = 0; l < Ns[j]; l++, k++) {
				var = vars.nodes[k];

				outfile << "\t\t\tdataWriters." << job->sref << "_" << varsref << "->";
				if (Ns[j] == 1) outfile << "_";
				outfile << var->sref << "(" << job->sref << "::shrdat." << var->sref << ");" << endl;
			};

			outfile << "\t\t\t" << job->sref << "::shrdat.runlockAccess(\"" << Cmpsref << "Ddspub\", \"run\");" << endl;
			outfile << endl;

			outfile << "\t\t\tdataWriters.writer" << job->sref << "_" << varsref << "->write(*(dataWriters." << job->sref << "_" << varsref << "));" << endl;
		};
	};
	if (!first) outfile << "\t\t};" << endl;
	outfile << "// IP run.varupdate --- IEND" << endl;
};

string WznmWrsrvDds::getVarIdltype(
			const uint ixWznmVVartype
			, const uint Length
		) {
	string retval = VecWznmVVartype::getSref(ixWznmVVartype);

	if ( (ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) || (ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) || (ixWznmVVartype == VecWznmVVartype::USMALLINTVEC)
				|| (ixWznmVVartype == VecWznmVVartype::INTVEC) || (ixWznmVVartype == VecWznmVVartype::UINTVEC) || (ixWznmVVartype == VecWznmVVartype::UBIGINTVEC)
				|| (ixWznmVVartype == VecWznmVVartype::FLOATVEC) || (ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) ) {

		retval = "sequence<";
		
		if (ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) retval += "boolean";
		else if (ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) retval += "octet";
		else if (ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) retval += "unsigned short";
		else if (ixWznmVVartype == VecWznmVVartype::INTVEC) retval += "long";
		else if (ixWznmVVartype == VecWznmVVartype::UINTVEC) retval += "unsigned long";
		else if (ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) retval += "unsigned long long";
		else if (ixWznmVVartype == VecWznmVVartype::FLOATVEC) retval += "float";
		else if (ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) retval += "double";

		if (Length != 0) retval += ", " + to_string(Length);
		retval += ">";

	} else if (ixWznmVVartype == VecWznmVVartype::FLOATMAT) retval = "DdsFloatmat";
	else if (ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) retval = "DdsDoublemat";
	else retval = VecWznmVVartype::getSref(ixWznmVVartype);

	return retval;
};
// IP cust --- IEND


