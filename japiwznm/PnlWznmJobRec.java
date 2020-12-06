/**
  * \file PnlWznmJobRec.java
  * Java API code for job PnlWznmJobRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmJobRec {
	/**
		* VecVDo (full: VecVWznmJobRecDo)
		*/
	public static class VecVDo {

		public static final int BUTMINIMIZECLICK = 1;
		public static final int BUTREGULARIZECLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWznmJobRec)
	  */
	public class ContInf extends Block {

		public static final int TXTREF = 1;

		public ContInf(
					String TxtRef
				) {
			this.TxtRef = TxtRef;

			mask = new HashSet<Integer>(Arrays.asList(TXTREF));
		};

		public String TxtRef;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmJobRec");

			String itemtag = "ContitemInfWznmJobRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtRef = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtRef", mask, TXTREF);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtRef.equals(comp.TxtRef)) items.add(TXTREF);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTREF));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmJobRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEAVAR = 2;
		public static final int INITDONEACMD = 3;
		public static final int INITDONE1NRTJOB = 4;
		public static final int INITDONE1NMETHOD = 5;
		public static final int INITDONEJOB1NSTAGE = 6;
		public static final int INITDONE1NSENSITIVITY = 7;
		public static final int INITDONEHK1NVECTOR = 8;
		public static final int INITDONEREF1NBLOCK = 9;
		public static final int INITDONEMNOP = 10;
		public static final int INITDONESUPMNJOB = 11;
		public static final int INITDONEMNOPPACK = 12;
		public static final int INITDONESUBMNJOB = 13;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneAVar
					, boolean initdoneACmd
					, boolean initdone1NRtjob
					, boolean initdone1NMethod
					, boolean initdoneJob1NStage
					, boolean initdone1NSensitivity
					, boolean initdoneHk1NVector
					, boolean initdoneRef1NBlock
					, boolean initdoneMNOp
					, boolean initdoneSupMNJob
					, boolean initdoneMNOppack
					, boolean initdoneSubMNJob
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneAVar = initdoneAVar;
			this.initdoneACmd = initdoneACmd;
			this.initdone1NRtjob = initdone1NRtjob;
			this.initdone1NMethod = initdone1NMethod;
			this.initdoneJob1NStage = initdoneJob1NStage;
			this.initdone1NSensitivity = initdone1NSensitivity;
			this.initdoneHk1NVector = initdoneHk1NVector;
			this.initdoneRef1NBlock = initdoneRef1NBlock;
			this.initdoneMNOp = initdoneMNOp;
			this.initdoneSupMNJob = initdoneSupMNJob;
			this.initdoneMNOppack = initdoneMNOppack;
			this.initdoneSubMNJob = initdoneSubMNJob;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEAVAR, INITDONEACMD, INITDONE1NRTJOB, INITDONE1NMETHOD, INITDONEJOB1NSTAGE, INITDONE1NSENSITIVITY, INITDONEHK1NVECTOR, INITDONEREF1NBLOCK, INITDONEMNOP, INITDONESUPMNJOB, INITDONEMNOPPACK, INITDONESUBMNJOB));
		};

		public boolean initdoneDetail;
		public boolean initdoneAVar;
		public boolean initdoneACmd;
		public boolean initdone1NRtjob;
		public boolean initdone1NMethod;
		public boolean initdoneJob1NStage;
		public boolean initdone1NSensitivity;
		public boolean initdoneHk1NVector;
		public boolean initdoneRef1NBlock;
		public boolean initdoneMNOp;
		public boolean initdoneSupMNJob;
		public boolean initdoneMNOppack;
		public boolean initdoneSubMNJob;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmJobRec");

			String itemtag = "StatitemAppWznmJobRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneAVar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAVar", mask, INITDONEAVAR);
				initdoneACmd = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneACmd", mask, INITDONEACMD);
				initdone1NRtjob = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NRtjob", mask, INITDONE1NRTJOB);
				initdone1NMethod = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NMethod", mask, INITDONE1NMETHOD);
				initdoneJob1NStage = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneJob1NStage", mask, INITDONEJOB1NSTAGE);
				initdone1NSensitivity = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NSensitivity", mask, INITDONE1NSENSITIVITY);
				initdoneHk1NVector = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHk1NVector", mask, INITDONEHK1NVECTOR);
				initdoneRef1NBlock = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NBlock", mask, INITDONEREF1NBLOCK);
				initdoneMNOp = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNOp", mask, INITDONEMNOP);
				initdoneSupMNJob = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSupMNJob", mask, INITDONESUPMNJOB);
				initdoneMNOppack = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNOppack", mask, INITDONEMNOPPACK);
				initdoneSubMNJob = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSubMNJob", mask, INITDONESUBMNJOB);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdoneAVar == comp.initdoneAVar) items.add(INITDONEAVAR);
			if (initdoneACmd == comp.initdoneACmd) items.add(INITDONEACMD);
			if (initdone1NRtjob == comp.initdone1NRtjob) items.add(INITDONE1NRTJOB);
			if (initdone1NMethod == comp.initdone1NMethod) items.add(INITDONE1NMETHOD);
			if (initdoneJob1NStage == comp.initdoneJob1NStage) items.add(INITDONEJOB1NSTAGE);
			if (initdone1NSensitivity == comp.initdone1NSensitivity) items.add(INITDONE1NSENSITIVITY);
			if (initdoneHk1NVector == comp.initdoneHk1NVector) items.add(INITDONEHK1NVECTOR);
			if (initdoneRef1NBlock == comp.initdoneRef1NBlock) items.add(INITDONEREF1NBLOCK);
			if (initdoneMNOp == comp.initdoneMNOp) items.add(INITDONEMNOP);
			if (initdoneSupMNJob == comp.initdoneSupMNJob) items.add(INITDONESUPMNJOB);
			if (initdoneMNOppack == comp.initdoneMNOppack) items.add(INITDONEMNOPPACK);
			if (initdoneSubMNJob == comp.initdoneSubMNJob) items.add(INITDONESUBMNJOB);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEAVAR, INITDONEACMD, INITDONE1NRTJOB, INITDONE1NMETHOD, INITDONEJOB1NSTAGE, INITDONE1NSENSITIVITY, INITDONEHK1NVECTOR, INITDONEREF1NBLOCK, INITDONEMNOP, INITDONESUPMNJOB, INITDONEMNOPPACK, INITDONESUBMNJOB));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmJobRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFAVAR = 3;
		public static final int SCRJREFACMD = 4;
		public static final int SCRJREF1NRTJOB = 5;
		public static final int SCRJREF1NMETHOD = 6;
		public static final int SCRJREFJOB1NSTAGE = 7;
		public static final int SCRJREF1NSENSITIVITY = 8;
		public static final int SCRJREFHK1NVECTOR = 9;
		public static final int SCRJREFREF1NBLOCK = 10;
		public static final int SCRJREFMNOP = 11;
		public static final int SCRJREFSUPMNJOB = 12;
		public static final int SCRJREFMNOPPACK = 13;
		public static final int SCRJREFSUBMNJOB = 14;
		public static final int PNLSUBMNJOBAVAIL = 15;
		public static final int BUTREGULARIZEACTIVE = 16;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefAVar
					, String scrJrefACmd
					, String scrJref1NRtjob
					, String scrJref1NMethod
					, String scrJrefJob1NStage
					, String scrJref1NSensitivity
					, String scrJrefHk1NVector
					, String scrJrefRef1NBlock
					, String scrJrefMNOp
					, String scrJrefSupMNJob
					, String scrJrefMNOppack
					, String scrJrefSubMNJob
					, boolean pnlsubmnjobAvail
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefAVar = scrJrefAVar;
			this.scrJrefACmd = scrJrefACmd;
			this.scrJref1NRtjob = scrJref1NRtjob;
			this.scrJref1NMethod = scrJref1NMethod;
			this.scrJrefJob1NStage = scrJrefJob1NStage;
			this.scrJref1NSensitivity = scrJref1NSensitivity;
			this.scrJrefHk1NVector = scrJrefHk1NVector;
			this.scrJrefRef1NBlock = scrJrefRef1NBlock;
			this.scrJrefMNOp = scrJrefMNOp;
			this.scrJrefSupMNJob = scrJrefSupMNJob;
			this.scrJrefMNOppack = scrJrefMNOppack;
			this.scrJrefSubMNJob = scrJrefSubMNJob;
			this.pnlsubmnjobAvail = pnlsubmnjobAvail;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAVAR, SCRJREFACMD, SCRJREF1NRTJOB, SCRJREF1NMETHOD, SCRJREFJOB1NSTAGE, SCRJREF1NSENSITIVITY, SCRJREFHK1NVECTOR, SCRJREFREF1NBLOCK, SCRJREFMNOP, SCRJREFSUPMNJOB, SCRJREFMNOPPACK, SCRJREFSUBMNJOB, PNLSUBMNJOBAVAIL, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefAVar;
		public String scrJrefACmd;
		public String scrJref1NRtjob;
		public String scrJref1NMethod;
		public String scrJrefJob1NStage;
		public String scrJref1NSensitivity;
		public String scrJrefHk1NVector;
		public String scrJrefRef1NBlock;
		public String scrJrefMNOp;
		public String scrJrefSupMNJob;
		public String scrJrefMNOppack;
		public String scrJrefSubMNJob;
		public boolean pnlsubmnjobAvail;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmJobRec");

			String itemtag = "StatitemShrWznmJobRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefAVar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAVar", mask, SCRJREFAVAR);
				scrJrefACmd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefACmd", mask, SCRJREFACMD);
				scrJref1NRtjob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NRtjob", mask, SCRJREF1NRTJOB);
				scrJref1NMethod = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NMethod", mask, SCRJREF1NMETHOD);
				scrJrefJob1NStage = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefJob1NStage", mask, SCRJREFJOB1NSTAGE);
				scrJref1NSensitivity = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NSensitivity", mask, SCRJREF1NSENSITIVITY);
				scrJrefHk1NVector = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHk1NVector", mask, SCRJREFHK1NVECTOR);
				scrJrefRef1NBlock = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NBlock", mask, SCRJREFREF1NBLOCK);
				scrJrefMNOp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNOp", mask, SCRJREFMNOP);
				scrJrefSupMNJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSupMNJob", mask, SCRJREFSUPMNJOB);
				scrJrefMNOppack = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNOppack", mask, SCRJREFMNOPPACK);
				scrJrefSubMNJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSubMNJob", mask, SCRJREFSUBMNJOB);
				pnlsubmnjobAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlsubmnjobAvail", mask, PNLSUBMNJOBAVAIL);
				ButRegularizeActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", mask, BUTREGULARIZEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (scrJrefDetail.equals(comp.scrJrefDetail)) items.add(SCRJREFDETAIL);
			if (scrJrefAVar.equals(comp.scrJrefAVar)) items.add(SCRJREFAVAR);
			if (scrJrefACmd.equals(comp.scrJrefACmd)) items.add(SCRJREFACMD);
			if (scrJref1NRtjob.equals(comp.scrJref1NRtjob)) items.add(SCRJREF1NRTJOB);
			if (scrJref1NMethod.equals(comp.scrJref1NMethod)) items.add(SCRJREF1NMETHOD);
			if (scrJrefJob1NStage.equals(comp.scrJrefJob1NStage)) items.add(SCRJREFJOB1NSTAGE);
			if (scrJref1NSensitivity.equals(comp.scrJref1NSensitivity)) items.add(SCRJREF1NSENSITIVITY);
			if (scrJrefHk1NVector.equals(comp.scrJrefHk1NVector)) items.add(SCRJREFHK1NVECTOR);
			if (scrJrefRef1NBlock.equals(comp.scrJrefRef1NBlock)) items.add(SCRJREFREF1NBLOCK);
			if (scrJrefMNOp.equals(comp.scrJrefMNOp)) items.add(SCRJREFMNOP);
			if (scrJrefSupMNJob.equals(comp.scrJrefSupMNJob)) items.add(SCRJREFSUPMNJOB);
			if (scrJrefMNOppack.equals(comp.scrJrefMNOppack)) items.add(SCRJREFMNOPPACK);
			if (scrJrefSubMNJob.equals(comp.scrJrefSubMNJob)) items.add(SCRJREFSUBMNJOB);
			if (pnlsubmnjobAvail == comp.pnlsubmnjobAvail) items.add(PNLSUBMNJOBAVAIL);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAVAR, SCRJREFACMD, SCRJREF1NRTJOB, SCRJREF1NMETHOD, SCRJREFJOB1NSTAGE, SCRJREF1NSENSITIVITY, SCRJREFHK1NVECTOR, SCRJREFREF1NBLOCK, SCRJREFMNOP, SCRJREFSUPMNJOB, SCRJREFMNOPPACK, SCRJREFSUBMNJOB, PNLSUBMNJOBAVAIL, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmJobRec)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;

		public Tag(
					String Cpt
				) {
			this.Cpt = Cpt;

			mask = new HashSet<Integer>(Arrays.asList(CPT));
		};

		public String Cpt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmJobRec");

			String itemtag = "TagitemWznmJobRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmJobRecDo)
		*/
	public class DpchAppDo extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int IXVDO = 2;
		public static final int ALL = 3;

		public DpchAppDo(
					String scrJref
					, int ixVDo
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPWZNMJOBRECDO, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, IXVDO));
					break;
				};

			this.ixVDo = ixVDo;
		};

		public int ixVDo;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(IXVDO)) ss.add("ixVDo");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWznmJobRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmJobRecData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMJOBRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", "", "", "", "", false, false);
			tag = new Tag("");
		};

		public ContInf continf;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(TAG)) ss.add("tag");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmJobRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false, false, false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", "", "", "", "", false, false);
				tag = new Tag("");
			};
		};

	};

};
