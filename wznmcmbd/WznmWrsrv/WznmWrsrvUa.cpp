/**
	* \file WznmWrsrvUa.cpp
	* Wznm operation processor - write C++ code for OPC UA server (implementation)
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

#include "WznmWrsrvUa.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

/******************************************************************************
 namespace WznmWrsrvUa
 ******************************************************************************/

DpchRetWznm* WznmWrsrvUa::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvUa* dpchinv
		) {
	ubigint refWznmMVersion = dpchinv->refWznmMVersion;
	string Prjshort = dpchinv->Prjshort;
	string Cmpsref = dpchinv->Cmpsref;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	ubigint ref;

	ListWznmRMJobMJob jrjs;
	ListWznmMJob jobs;

	fstream cppfile;

	string s;

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMJob WHERE refWznmMVersion = " + to_string(refWznmMVersion) + " AND ixVBasetype = " + to_string(VecWznmVMJobBasetype::SESS) + " AND sref = 'M2msess" + Prjshort + "'", ref)) {
		dbswznm->tblwznmrmjobmjob->loadRstBySup(ref, false, jrjs);

		jobs.nodes.resize(jrjs.nodes.size(), NULL);
		for (unsigned int i = 0; i < jrjs.nodes.size(); i++) dbswznm->tblwznmmjob->loadRecByRef(jrjs.nodes[i]->subRefWznmMJob, &(jobs.nodes[i]));

		s = xchg->tmppath + "/" + folder + "/" + Cmpsref + "Uasrv.cpp.ip";
		cppfile.open(s.c_str(), ios::out);
		writeUasrvCpp(dbswznm, cppfile, Prjshort, Cmpsref, jrjs, jobs);
		cppfile.close();
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvUa::writeUasrvCpp(
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

	WznmMVector* vec = NULL;

	string PRJSHORT = StrMod::uc(Prjshort);

	string SDKtype, SDKitemtype;

	unsigned int cnt;

	bool first, first2;

	// --- Session.constructor
	outfile << "// IP Session.constructor --- IBEGIN" << endl;
	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
		jrj = jrjs.nodes[i];
		job = jobs.nodes[i];

		dbswznm->tblwznmmmethod->loadRstByJob(job->ref, false, mtds);
		Wznm::getJobvars(dbswznm, job->ref, vars, varsrefs, Shrs, Ns);

		if ((mtds.nodes.size() > 0) || (varsrefs.size() > 0)) {
			outfile << "\t\tif (statshr.jref" << StrMod::cap(jrj->Short) << " != 0) {" << endl;
			outfile << "\t\t\tinsert(jobaccs, Vec" << Prjshort << "VJob::" << StrMod::uc(job->sref) << ");" << endl;
			outfile << endl;

			for (unsigned int j = 0; j < mtds.nodes.size(); j++) {
				mtd = mtds.nodes[j];

				outfile << "\t\t\txchg->triggerIxSrefToIxCall(NULL, Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "ACCESS, statshr.jref" << StrMod::cap(jrj->Short) << ", Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "METHOD, \"" << mtd->sref << "\", ixAcc);" << endl;
				outfile << "\t\t\tif (ixAcc != 0) accs[featix_t(Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "METHOD, \"" << mtd->sref << "\")] = ixAcc;" << endl;
			};
			if (mtds.nodes.size() > 0) outfile << endl;

			if (varsrefs.size() > 0) outfile << "\t\t\tixVFeatgroups[statshr.jref" << StrMod::cap(jrj->Short) << "] = Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "VAR;" << endl;

			for (unsigned int j = 0; j < varsrefs.size(); j++) {
				varsref = varsrefs[j];

				outfile << "\t\t\txchg->triggerIxSrefToIxCall(NULL, Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "ACCESS, statshr.jref" << StrMod::cap(jrj->Short) << ", Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "VAR, \"" << varsref << "\", ixAcc);" << endl;
				outfile << "\t\t\tif (ixAcc != 0) {" << endl;
				outfile << "\t\t\t\taccs[featix_t(Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "VAR, \"" << varsref << "\")] = ixAcc;" << endl;

				outfile << "\t\t\t\txchg->addClstnUasrv(statshr.jref" << StrMod::cap(jrj->Short) << ", \"" << varsref << "\"";
				if (Shrs[j]) outfile << ", true";
				else outfile << ", false";
				outfile << ");" << endl;

				outfile << "\t\t\t};" << endl;
			};
			outfile << "\t\t};" << endl;
		};
	};

	outfile << "// IP Session.constructor --- IEND" << endl;

	// --- CallMethodBegin.jref
	outfile << "// IP CallMethodBegin.jref --- IBEGIN" << endl;

	first = true;

	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
		jrj = jrjs.nodes[i];
		job = jobs.nodes[i];

		dbswznm->tblwznmmmethod->loadRstByJob(job->ref, false, mtds);

		if (mtds.nodes.size() > 0) {
			outfile << "\t\t";

			if (first) first = false;
			else outfile << "else ";

			outfile << "if (ix" << Prjshort << "VFeatgroup == Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "METHOD) jref = session->statshr.jref" << StrMod::cap(jrj->Short) << ";" << endl;
		};
	};
	outfile << "// IP CallMethodBegin.jref --- IEND" << endl;

	// --- CallMethodBegin.run
	outfile << "// IP CallMethodBegin.run --- IBEGIN" << endl;

	first = true;

	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		dbswznm->tblwznmmmethod->loadRstByJob(job->ref, false, mtds);

		for (unsigned int j = 0; j < mtds.nodes.size(); j++) {
			mtd = mtds.nodes[j];

			dbswznm->tblwznmammethodinvpar->loadRstByMtd(mtd->ref, false, ipas);
			dbswznm->tblwznmammethodretpar->loadRstByMtd(mtd->ref, false, rpas);

			if (!first) outfile << endl;

			outfile << "\t\t";

			if (first) first = false;
			else outfile << " } else ";

			outfile << "if ((ix" << Prjshort << "VFeatgroup == Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "METHOD) && (srefIxVMethod == \"" << mtd->sref << "\")) {" << endl;

			cnt = 0;
			for (unsigned int k = 0; k < ipas.nodes.size(); k++) if ((ipas.nodes[k]->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (ipas.nodes[k]->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) cnt += 3; else cnt++;

			outfile << "\t\t\tif (requestParameters->InputArguments().Size() == " << cnt << ") {" << endl;

			for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
				ipa = ipas.nodes[k];

				if ((ipa->ixWznmVVartype == VecWznmVVartype::STRING) || (ipa->ixWznmVVartype == VecWznmVVartype::VECSREF)) {
					outfile << "\t\t\t\tScopedPtr_t<Array_t<char> > dummy;" << endl;
					outfile << endl;

					break;
				};
			};

			if (ipas.nodes.size() > 0) {
				for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
					ipa = ipas.nodes[k];

					SDKtype = getVartypeSDKtype(ipa->ixWznmVVartype);

					outfile << "\t\t\t\tIntrusivePtr_t<const " << SDKtype << "> ";
					if (ipa->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "sref" << StrMod::cap(ipa->sref);
					else outfile << ipa->sref;
					outfile << "_inv_UA;" << endl;
					if ((ipa->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (ipa->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) {
						outfile << "\t\t\t\tIntrusivePtr_t<const UInt32_t> " << ipa->sref << "M_inv_UA;" << endl;
						outfile << "\t\t\t\tIntrusivePtr_t<const UInt32_t> " << ipa->sref << "N_inv_UA;" << endl;
					};

					outfile << "\t\t\t\t" << getIparpaCppType(ipa->ixWznmVVartype) << " " << ipa->sref << "_inv;" << endl;
				};
				outfile << endl;

				cnt = 0;
				for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
					ipa = ipas.nodes[k];

					outfile << "\t\t\t\tAddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[" << cnt++ << "]), ";
					if (ipa->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "sref" << StrMod::cap(ipa->sref);
					else outfile << ipa->sref;
					outfile << "_inv_UA);" << endl;
					if ((ipa->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (ipa->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) {
						outfile << "\t\t\t\tAddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[" << cnt++ << "]), " << ipa->sref << "M_inv_UA);" << endl;
						outfile << "\t\t\t\tAddressSpaceUtilities_t::CastInputArgument(*(requestParameters->InputArguments()[" << cnt++ << "]), " << ipa->sref << "N_inv_UA);" << endl;
					};

					outfile << "\t\t\t\t" << ipa->sref << "_inv = ";
					if (ipa->ixWznmVVartype == VecWznmVVartype::STRING) {
						outfile << ipa->sref << "_inv_UA->ToCString(dummy);" << endl;
					} else if ((ipa->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (ipa->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) {
						// TBD
					} else if (ipa->ixWznmVVartype == VecWznmVVartype::VECSREF) {
						if (dbswznm->tblwznmmvector->loadRecByRef(ipa->refWznmMVector, &vec)) {
							outfile << vec->sref << "::getIx(string(sref" << StrMod::cap(ipa->sref) << "_inv_UA->ToCString(dummy)));" << endl;
							delete vec;
						};
					} else outfile <<  ipa->sref << "_inv_UA->Value();" << endl;
				};
				outfile << endl;
			};

			outfile << "\t\t\t\tbool success_ret;" << endl;
			outfile << "\t\t\t\tIntrusivePtr_t<Boolean_t> success_ret_UA = new SafeRefCount_t<Boolean_t>();" << endl;
			for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
				rpa = rpas.nodes[k];

				outfile << "\t\t\t\t" << getIparpaCppType(rpa->ixWznmVVartype) << " " << rpa->sref << "_ret;" << endl;

				SDKtype = getVartypeSDKtype(rpa->ixWznmVVartype);

				outfile << "\t\t\t\tIntrusivePtr_t<" << SDKtype << "> ";
				if (rpa->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "sref" << StrMod::cap(rpa->sref);
				else outfile << rpa->sref;
				outfile << "_ret_UA = new SafeRefCount_t<" << SDKtype << ">();" << endl;
				if ((rpa->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (rpa->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) {
					outfile << "\t\t\t\tIntrusivePtr_t<UInt32_t> " << rpa->sref << "M_ret_UA = new SafeRefCount_t<UInt32_t>();" << endl;
					outfile << "\t\t\t\tIntrusivePtr_t<UInt32_t> " << rpa->sref << "N_ret_UA = new SafeRefCount_t<UInt32_t>();" << endl;
				};
			};
			outfile << endl;

			outfile << "\t\t\t\trunMethod(jref, Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "METHOD, \"" << mtd->sref << "\"," << endl;

			cnt = 0;
			first2 = true;

			outfile << "\t\t\t\t\t\t\t{";
			for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
				ipa = ipas.nodes[k];

				if (first2) first2 = false;
				else outfile << ",";

				outfile << "&" << ipa->sref << "_inv";
				if ((ipa->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (ipa->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) {
					outfile << ",&" << ipa->sref << "M_inv";
					outfile << ",&" << ipa->sref << "N_inv";
				};
			};
			outfile << "}," << endl;

			outfile << "\t\t\t\t\t\t\t{&success_ret";
			for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
				rpa = rpas.nodes[k];

				outfile << ",&" << rpa->sref << "_ret";
				if ((rpa->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (rpa->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) {
					outfile << ",&" << rpa->sref << "M_ret";
					outfile << ",&" << rpa->sref << "N_ret";
				};
			};
			outfile << "});" << endl;
			outfile << endl;

			outfile << "\t\t\t\tresult.reset(new SafeRefCount_t<CallMethodResult_t>());" << endl;

			cnt = 1;
			for (unsigned int k = 0; k < rpas.nodes.size(); k++) if ((rpas.nodes[k]->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (rpas.nodes[k]->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) cnt += 3; else cnt++;

			outfile << "\t\t\t\tresult->OutputArguments().Initialise(" << cnt << ");" << endl;
			outfile << endl;

			outfile << "\t\t\t\tsuccess_ret_UA->Value(success_ret);" << endl;
			outfile << "\t\t\t\tsuccess_ret_UA->CopyTo((result->OutputArguments())[0]);" << endl;

			cnt = 1;
			for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
				rpa = rpas.nodes[k];

				outfile << "\t\t\t\t";
				if (rpa->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "sref" << StrMod::cap(rpa->sref);
				else outfile << rpa->sref;
				outfile << "_ret_UA";

				if (rpa->ixWznmVVartype == VecWznmVVartype::STRING) {
					outfile << "->CopyFrom(" << rpa->sref << "_ret.c_str());" << endl;
				} else if ((rpa->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (rpa->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) {
					// TBD
				} else if (rpa->ixWznmVVartype == VecWznmVVartype::VECSREF) {
					if (dbswznm->tblwznmmvector->loadRecByRef(rpa->refWznmMVector, &vec)) {
						outfile << "->CopyFrom(" << vec->sref << "::getSref(" << rpa->sref << "_ret).c_str());" << endl;
						delete vec;
					};
				} else outfile << "->Value(" << rpa->sref << "_ret);" << endl;
				if ((rpa->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (rpa->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) {
					outfile << "\t\t\t\t" << rpa->sref << "M_ret_UA->Value(" << rpa->sref << "M_ret);" << endl;
					outfile << "\t\t\t\t" << rpa->sref << "N_ret_UA->Value(" << rpa->sref << "N_ret);" << endl;
				};

				outfile << "\t\t\t\t";
				if (rpa->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "sref" << StrMod::cap(rpa->sref);
				else outfile << rpa->sref;
				outfile << "_ret_UA->CopyTo(result->OutputArguments()[" << cnt++ << "]);" << endl;
				if ((rpa->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (rpa->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) {
					outfile << "\t\t\t\t" << rpa->sref << "M_ret_UA->CopyTo(result->OutputArguments()[" << cnt++ << "]);" << endl;
					outfile << "\t\t\t\t" << rpa->sref << "N_ret_UA->CopyTo(result->OutputArguments()[" << cnt++ << "]);" << endl;
				};
			};
			outfile << endl;

			outfile << "\t\t\t\tresult->StatusCode() = OpcUa_Good;" << endl;
			outfile << "\t\t\t};" << endl;
		};
	};

	if (!first) outfile << "\t\t};" << endl;

	outfile << "// IP CallMethodBegin.run --- IEND" << endl;

	// --- ReadValueAttribute
	outfile << "// IP ReadValueAttribute --- IBEGIN" << endl;

	first = true;

	for (unsigned int i = 0; i < jobs.nodes.size(); i++) {
		job = jobs.nodes[i];

		Wznm::getJobvars(dbswznm, job->ref, vars, varsrefs, Shrs, Ns);

		unsigned int k = 0;

		for (unsigned int j = 0; j < varsrefs.size(); j++) {
			varsref = varsrefs[j];

			if (!first) outfile << endl;

			outfile << "\t\t";

			if (first) first = false;
			else outfile << " } else ";

			outfile << "if ((ix" << Prjshort << "VFeatgroup == Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "VAR) && (srefIxVVar == \"" << varsref << "\")) {" << endl;

			// TBD: non-shrdat
      outfile << "\t\t\t" << job->sref << "::shrdat.rlockAccess(\"" << Cmpsref << "Uasrv::ValueAttributeReaderWriter\", \"ReadValueAttribute\");" << endl;
			outfile << endl;

      outfile << "\t\t\tif (setSourceTimestamp) {" << endl;
      outfile << "\t\t\t\tdataValue->SourceTimestamp() = new SafeRefCount_t<DateTime_t>();" << endl;
      outfile << "\t\t\t\t*(dataValue->SourceTimestamp()) = timestamps[it->second];" << endl;
			outfile << "\t\t\t};" << endl;
			outfile << endl;

			for (unsigned int l = 0; l < Ns[j];l++) {
				var = vars.nodes[k];

				SDKtype = getVartypeSDKtype(var->ixWznmVVartype);

				outfile << "\t\t\t";
				if (l != 0) outfile << "} else ";
				outfile << "if (subvar == \"" << var->sref << "\") {" << endl;

				if ( (var->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) || (var->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) || (var->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC)
							|| (var->ixWznmVVartype == VecWznmVVartype::INTVEC) || (var->ixWznmVVartype == VecWznmVVartype::UINTVEC) || (var->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC)
							|| (var->ixWznmVVartype == VecWznmVVartype::FLOATVEC) || (var->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) || (var->ixWznmVVartype == VecWznmVVartype::FLOATMAT)
							|| (var->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) || (var->ixWznmVVartype == VecWznmVVartype::STRINGVEC) ) {

					// TBD: FLOATMAT, DOUBLEMAT
					SDKitemtype = getVartypeSDKitemtype(var->ixWznmVVartype);

					outfile << "\t\t\t\tunsigned int len = " << job->sref << "::shrdat." << var->sref << ".size();" << endl;
					outfile << "\t\t\t\tIntrusivePtr_t<" << SDKtype << "> " << var->sref << " = new SafeRefCount_t<" << SDKtype << ">();" << endl;
					outfile << "\t\t\t\t" << var->sref << "->Initialise(len);" << endl;
					outfile << "\t\t\t\tfor (unsigned int i = 0; i < len; i++) {" << endl;
					outfile << "\t\t\t\t\tIntrusivePtr_t<" << SDKitemtype << "> item = new SafeRefCount_t<" << SDKitemtype << ">();" << endl;
					outfile << "\t\t\t\t\titem->Value(" << job->sref << "::shrdat." << var->sref << "[i]);" << endl;
					outfile << "\t\t\t\t\t(*" << var->sref << ")[i] = item;" << endl;
					outfile << "\t\t\t\t};" << endl;
					outfile << "\t\t\t\tdataValue->Value() = " << var->sref << ";" << endl;

				} else {
					outfile << "\t\t\t\tIntrusivePtr_t<" << SDKtype << "> ";
					if (var->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "sref" << StrMod::cap(var->sref);
					else outfile << var->sref;
					outfile << " = new SafeRefCount_t<" << SDKtype << ">();" << endl;

					if (var->ixWznmVVartype == VecWznmVVartype::STRING) {
						outfile << "\t\t\t\t" << var->sref << "->CopyFrom(" << job->sref << "::shrdat." << var->sref << ".c_str());" << endl;
					} else if (var->ixWznmVVartype == VecWznmVVartype::VECSREF) {
/*
						if (dbswznm->tblwznmmvector->loadRecByRef(var->refWznmMVector, &vec)) {
							outfile << "\t\t\t\tsref" << StrMod::cap(var->sref) << "->CopyFrom(" << vec->sref << "::getIx(shrdat." << var->sref << ").c_str());" << endl;
							delete vec;
						};
*/
					} else outfile << "\t\t\t\t*" << var->sref << " = " << job->sref << "::shrdat." << var->sref << ";" << endl;
	
					outfile << "\t\t\t\tdataValue->Value() = ";
					if (var->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "sref" << StrMod::cap(var->sref);
					else outfile << var->sref;
					outfile << ";" << endl;
				};

				k++;
			};
			outfile << "\t\t\t};" << endl;
			outfile << endl;

      outfile << "\t\t\t" << job->sref << "::shrdat.runlockAccess(\"" << Cmpsref << "Uasrv::ValueAttributeReaderWriter\", \"ReadValueAttribute\");" << endl;
		};
	};

	if (!first) outfile << "\t\t};" << endl;

	outfile << "// IP ReadValueAttribute --- IEND" << endl;

	// --- fillAddressSpace
	outfile << "// IP fillAddressSpace --- IBEGIN" << endl;
	for (unsigned int i = 0; i < jrjs.nodes.size(); i++) {
		jrj = jrjs.nodes[i];
		job = jobs.nodes[i];

		dbswznm->tblwznmmmethod->loadRstByJob(job->ref, false, mtds);
		Wznm::getJobvars(dbswznm, job->ref, vars, varsrefs, Shrs, Ns);

		if ((mtds.nodes.size() > 0) || (varsrefs.size() > 0)) {
			outfile << "\tfAS_addJobFolder(Vec" << Prjshort << "VJob::" << StrMod::uc(job->sref) << ", addressSpace, objectsFolder, jobFolder);" << endl;
			outfile << endl;

			for (unsigned int j = 0; j < mtds.nodes.size(); j++) {
				mtd = mtds.nodes[j];

				dbswznm->tblwznmammethodinvpar->loadRstByMtd(mtd->ref, false, ipas);
				dbswznm->tblwznmammethodretpar->loadRstByMtd(mtd->ref, false, rpas);

				cnt = 0;
				for (unsigned int k = 0; k < ipas.nodes.size(); k++) if ((ipas.nodes[k]->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (ipas.nodes[k]->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) cnt += 3; else cnt++;
				outfile << "\tsrefsParsInv.resize(" << cnt << "); opcUaIdsParsInv.resize(" << cnt << ");" << endl;

				cnt = 0;
				for (unsigned int k = 0; k < ipas.nodes.size(); k++) {
					ipa = ipas.nodes[k];

					outfile << "\tsrefsParsInv[" << cnt << "] = \"";
					if (ipa->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "sref" << StrMod::cap(ipa->sref);
					else outfile << ipa->sref;
					outfile << "\"; opcUaIdsParsInv[" << cnt << "] = " << getVartypeOpcUaId(ipa->ixWznmVVartype) << ";" << endl;
					cnt++;

					if ((ipa->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (ipa->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) {
						outfile << "\tsrefsParsInv[" << cnt << "] = \"" << ipa->sref << "M\"; opcUaIdsParsInv[" << cnt << "] = OpcUaId_UInt32;" << endl;
						cnt++;
						outfile << "\tsrefsParsInv[" << cnt << "] = \"" << ipa->sref << "N\"; opcUaIdsParsInv[" << cnt << "] = OpcUaId_UInt32;" << endl;
						cnt++;
					};
				};
				outfile << endl;

				cnt = 1;
				for (unsigned int k = 0; k < rpas.nodes.size(); k++) if ((rpas.nodes[k]->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (rpas.nodes[k]->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) cnt += 3; else cnt++;
				outfile << "\tsrefsParsRet.resize(" << cnt << "); opcUaIdsParsRet.resize(" << cnt << ");" << endl;
				outfile << "\tsrefsParsRet[0] = \"success\"; opcUaIdsParsRet[0] = OpcUaId_Boolean;" << endl;

				cnt = 1;
				for (unsigned int k = 0; k < rpas.nodes.size(); k++) {
					rpa = rpas.nodes[k];

					outfile << "\tsrefsParsRet[" << cnt << "] = \"";
					if (rpa->ixWznmVVartype == VecWznmVVartype::VECSREF) outfile << "sref" << StrMod::cap(rpa->sref);
					else outfile << rpa->sref;
					outfile << "\"; opcUaIdsParsRet[" << cnt << "] = " << getVartypeOpcUaId(rpa->ixWznmVVartype) << ";" << endl;
					cnt++;

					if ((rpa->ixWznmVVartype == VecWznmVVartype::FLOATMAT) || (rpa->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT)) {
						outfile << "\tsrefsParsRet[" << cnt << "] = \"" << rpa->sref << "M\"; opcUaIdsParsRet[" << cnt << "] = OpcUaId_UInt32;" << endl;
						cnt++;
						outfile << "\tsrefsParsRet[" << cnt << "] = \"" << rpa->sref << "N\"; opcUaIdsParsRet[" << cnt << "] = OpcUaId_UInt32;" << endl;
						cnt++;
					};
				};
				outfile << endl;

				outfile << "\tfAS_addMethod(Vec" << Prjshort << "VJob::" << StrMod::uc(job->sref) << ", Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "METHOD , \"" << mtd->sref << "\", methodHandler, addressSpace, jobFolder, srefsParsInv, opcUaIdsParsInv, srefsParsRet, opcUaIdsParsRet);" << endl;
				outfile << endl;
			};

			unsigned int k = 0;

			for (unsigned int j = 0; j < varsrefs.size(); j++) {
				varsref = varsrefs[j];

				outfile << "\tsrefsSubvars.resize(" << Ns[j] << "); icsVVartypeSubvars.resize(" << Ns[j] << ");" << endl;

				for (unsigned int l = 0; l < Ns[j];l++) {
					var = vars.nodes[k];

					// TBD: FLOATMAT, DOUBLEMAT

					outfile << "\tsrefsSubvars[" << l << "] = \"" << var->sref << "\"; icsVVartypeSubvars[" << l << "] = VecVVartype::" << StrMod::uc(VecWznmVVartype::getSref(var->ixWznmVVartype)) << ";" << endl;

					k++;
				};
				outfile << endl;

				outfile << "\tfAS_addVar(Vec" << Prjshort << "VJob::" << StrMod::uc(job->sref) << ", Vec" << Prjshort << "VFeatgroup::VECV" << StrMod::uc(job->sref) << "VAR , \"" << varsref << "\", readerWriter, addressSpace, jobFolder, srefsSubvars, icsVVartypeSubvars);" << endl;
				outfile << endl;
			};
		};
	};
	outfile << "// IP fillAddressSpace --- IEND" << endl;
};

string WznmWrsrvUa::getVartypeSDKtype(
			const uint ixWznmVVartype
		) {
	if (ixWznmVVartype == VecWznmVVartype::BOOLEAN) return "Boolean_t";
	if (ixWznmVVartype == VecWznmVVartype::TINYINT) return "SByte_t";
	if (ixWznmVVartype == VecWznmVVartype::UTINYINT) return "Byte_t";
	if (ixWznmVVartype == VecWznmVVartype::SMALLINT) return "Int16_t";
	if (ixWznmVVartype == VecWznmVVartype::USMALLINT) return "UInt16_t";
	if (ixWznmVVartype == VecWznmVVartype::INT) return "Int32_t";
	if (ixWznmVVartype == VecWznmVVartype::UINT) return "UInt32_t";
	if (ixWznmVVartype == VecWznmVVartype::BIGINT) return "Int64_t";
	if (ixWznmVVartype == VecWznmVVartype::UBIGINT) return "UInt64_t";
	if (ixWznmVVartype == VecWznmVVartype::FLOAT) return "Float_t";
	if (ixWznmVVartype == VecWznmVVartype::DOUBLE) return "Double_t";
	if (ixWznmVVartype == VecWznmVVartype::STRING) return "String_t";
	if (ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) return "ArrayUA_t<Boolean_t> ";
	if (ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) return "ArrayUA_t<Byte_t> ";
	if (ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) return "ArrayUA_t<UInt16_t> ";
	if (ixWznmVVartype == VecWznmVVartype::INTVEC) return "ArrayUA_t<Int32_t> ";
	if (ixWznmVVartype == VecWznmVVartype::UINTVEC) return "ArrayUA_t<UInt32_t> ";
	if (ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) return "ArrayUA_t<UInt64_t> ";
	if (ixWznmVVartype == VecWznmVVartype::FLOATVEC) return "ArrayUA_t<Float_t> ";
	if (ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) return "ArrayUA_t<Double_t> ";
	if (ixWznmVVartype == VecWznmVVartype::FLOATMAT) return "ArrayUA_t<Float_t> ";
	if (ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) return "ArrayUA_t<Double_t> ";
	if (ixWznmVVartype == VecWznmVVartype::STRINGVEC) return "ArrayUA_t<String_t> ";
	if (ixWznmVVartype == VecWznmVVartype::VECSREF) return "String_t";

	return "";
};

string WznmWrsrvUa::getVartypeSDKitemtype(
			const uint ixWznmVVartype
		) {
	if (ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) return "Boolean_t";
	if (ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) return "Byte_t";
	if (ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) return "UInt16_t";
	if (ixWznmVVartype == VecWznmVVartype::INTVEC) return "Int32_t";
	if (ixWznmVVartype == VecWznmVVartype::UINTVEC) return "UInt32_t";
	if (ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) return "UInt64_t";
	if (ixWznmVVartype == VecWznmVVartype::FLOATVEC) return "Float_t";
	if (ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) return "Double_t";
	if (ixWznmVVartype == VecWznmVVartype::FLOATMAT) return "Float_t";
	if (ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) return "Double_t";
	if (ixWznmVVartype == VecWznmVVartype::STRINGVEC) return "String_t";

	return "";
};

string WznmWrsrvUa::getVartypeOpcUaId(
			const uint ixWznmVVartype
		) {
	if (ixWznmVVartype == VecWznmVVartype::BOOLEAN) return "OpcUaId_Boolean";
	if (ixWznmVVartype == VecWznmVVartype::TINYINT) return "OpcUaId_SByte";
	if (ixWznmVVartype == VecWznmVVartype::UTINYINT) return "OpcUaId_Byte";
	if (ixWznmVVartype == VecWznmVVartype::SMALLINT) return "OpcUaId_Int16";
	if (ixWznmVVartype == VecWznmVVartype::USMALLINT) return "OpcUaId_UInt16";
	if (ixWznmVVartype == VecWznmVVartype::INT) return "OpcUaId_Int32";
	if (ixWznmVVartype == VecWznmVVartype::UINT) return "OpcUaId_UInt32";
	if (ixWznmVVartype == VecWznmVVartype::BIGINT) return "OpcUaId_Int64";
	if (ixWznmVVartype == VecWznmVVartype::UBIGINT) return "OpcUaId_UInt64";
	if (ixWznmVVartype == VecWznmVVartype::FLOAT) return "OpcUaId_Float";
	if (ixWznmVVartype == VecWznmVVartype::DOUBLE) return "OpcUaId_Double";
	if (ixWznmVVartype == VecWznmVVartype::STRING) return "OpcUaId_String";
	if (ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) return "OpcUaId_ByteString";
	if (ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) return "OpcUaId_ByteString";
	if (ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) return "OpcUaId_ByteString";
	if (ixWznmVVartype == VecWznmVVartype::INTVEC) return "OpcUaId_ByteString";
	if (ixWznmVVartype == VecWznmVVartype::UINTVEC) return "OpcUaId_ByteString";
	if (ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) return "OpcUaId_ByteString";
	if (ixWznmVVartype == VecWznmVVartype::FLOATVEC) return "OpcUaId_ByteString";
	if (ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) return "OpcUaId_ByteString";
	if (ixWznmVVartype == VecWznmVVartype::FLOATMAT) return "OpcUaId_ByteString";
	if (ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) return "OpcUaId_ByteString";
	if (ixWznmVVartype == VecWznmVVartype::STRINGVEC) return "OpcUaId_String";
	if (ixWznmVVartype == VecWznmVVartype::VECSREF) return "OpcUaId_String";

	return "";
};
// IP cust --- IEND



