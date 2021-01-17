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
		public static final int INITDONEACMD = 2;
		public static final int INITDONEAVAR = 3;
		public static final int INITDONE1NSENSITIVITY = 4;
		public static final int INITDONEJOB1NSTAGE = 5;
		public static final int INITDONE1NRTJOB = 6;
		public static final int INITDONE1NMETHOD = 7;
		public static final int INITDONEREF1NBLOCK = 8;
		public static final int INITDONEHK1NVECTOR = 9;
		public static final int INITDONESUPMNJOB = 10;
		public static final int INITDONEMNOP = 11;
		public static final int INITDONEMNOPPACK = 12;
		public static final int INITDONESUBMNJOB = 13;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneACmd
					, boolean initdoneAVar
					, boolean initdone1NSensitivity
					, boolean initdoneJob1NStage
					, boolean initdone1NRtjob
					, boolean initdone1NMethod
					, boolean initdoneRef1NBlock
					, boolean initdoneHk1NVector
					, boolean initdoneSupMNJob
					, boolean initdoneMNOp
					, boolean initdoneMNOppack
					, boolean initdoneSubMNJob
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneACmd = initdoneACmd;
			this.initdoneAVar = initdoneAVar;
			this.initdone1NSensitivity = initdone1NSensitivity;
			this.initdoneJob1NStage = initdoneJob1NStage;
			this.initdone1NRtjob = initdone1NRtjob;
			this.initdone1NMethod = initdone1NMethod;
			this.initdoneRef1NBlock = initdoneRef1NBlock;
			this.initdoneHk1NVector = initdoneHk1NVector;
			this.initdoneSupMNJob = initdoneSupMNJob;
			this.initdoneMNOp = initdoneMNOp;
			this.initdoneMNOppack = initdoneMNOppack;
			this.initdoneSubMNJob = initdoneSubMNJob;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEACMD, INITDONEAVAR, INITDONE1NSENSITIVITY, INITDONEJOB1NSTAGE, INITDONE1NRTJOB, INITDONE1NMETHOD, INITDONEREF1NBLOCK, INITDONEHK1NVECTOR, INITDONESUPMNJOB, INITDONEMNOP, INITDONEMNOPPACK, INITDONESUBMNJOB));
		};

		public boolean initdoneDetail;
		public boolean initdoneACmd;
		public boolean initdoneAVar;
		public boolean initdone1NSensitivity;
		public boolean initdoneJob1NStage;
		public boolean initdone1NRtjob;
		public boolean initdone1NMethod;
		public boolean initdoneRef1NBlock;
		public boolean initdoneHk1NVector;
		public boolean initdoneSupMNJob;
		public boolean initdoneMNOp;
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
				initdoneACmd = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneACmd", mask, INITDONEACMD);
				initdoneAVar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAVar", mask, INITDONEAVAR);
				initdone1NSensitivity = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NSensitivity", mask, INITDONE1NSENSITIVITY);
				initdoneJob1NStage = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneJob1NStage", mask, INITDONEJOB1NSTAGE);
				initdone1NRtjob = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NRtjob", mask, INITDONE1NRTJOB);
				initdone1NMethod = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NMethod", mask, INITDONE1NMETHOD);
				initdoneRef1NBlock = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NBlock", mask, INITDONEREF1NBLOCK);
				initdoneHk1NVector = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHk1NVector", mask, INITDONEHK1NVECTOR);
				initdoneSupMNJob = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSupMNJob", mask, INITDONESUPMNJOB);
				initdoneMNOp = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNOp", mask, INITDONEMNOP);
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
			if (initdoneACmd == comp.initdoneACmd) items.add(INITDONEACMD);
			if (initdoneAVar == comp.initdoneAVar) items.add(INITDONEAVAR);
			if (initdone1NSensitivity == comp.initdone1NSensitivity) items.add(INITDONE1NSENSITIVITY);
			if (initdoneJob1NStage == comp.initdoneJob1NStage) items.add(INITDONEJOB1NSTAGE);
			if (initdone1NRtjob == comp.initdone1NRtjob) items.add(INITDONE1NRTJOB);
			if (initdone1NMethod == comp.initdone1NMethod) items.add(INITDONE1NMETHOD);
			if (initdoneRef1NBlock == comp.initdoneRef1NBlock) items.add(INITDONEREF1NBLOCK);
			if (initdoneHk1NVector == comp.initdoneHk1NVector) items.add(INITDONEHK1NVECTOR);
			if (initdoneSupMNJob == comp.initdoneSupMNJob) items.add(INITDONESUPMNJOB);
			if (initdoneMNOp == comp.initdoneMNOp) items.add(INITDONEMNOP);
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

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEACMD, INITDONEAVAR, INITDONE1NSENSITIVITY, INITDONEJOB1NSTAGE, INITDONE1NRTJOB, INITDONE1NMETHOD, INITDONEREF1NBLOCK, INITDONEHK1NVECTOR, INITDONESUPMNJOB, INITDONEMNOP, INITDONEMNOPPACK, INITDONESUBMNJOB));
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
		public static final int SCRJREFACMD = 3;
		public static final int SCRJREFAVAR = 4;
		public static final int SCRJREF1NSENSITIVITY = 5;
		public static final int SCRJREFJOB1NSTAGE = 6;
		public static final int SCRJREF1NRTJOB = 7;
		public static final int SCRJREF1NMETHOD = 8;
		public static final int SCRJREFREF1NBLOCK = 9;
		public static final int SCRJREFHK1NVECTOR = 10;
		public static final int SCRJREFSUPMNJOB = 11;
		public static final int SCRJREFMNOP = 12;
		public static final int SCRJREFMNOPPACK = 13;
		public static final int SCRJREFSUBMNJOB = 14;
		public static final int PNLSUBMNJOBAVAIL = 15;
		public static final int BUTREGULARIZEACTIVE = 16;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefACmd
					, String scrJrefAVar
					, String scrJref1NSensitivity
					, String scrJrefJob1NStage
					, String scrJref1NRtjob
					, String scrJref1NMethod
					, String scrJrefRef1NBlock
					, String scrJrefHk1NVector
					, String scrJrefSupMNJob
					, String scrJrefMNOp
					, String scrJrefMNOppack
					, String scrJrefSubMNJob
					, boolean pnlsubmnjobAvail
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefACmd = scrJrefACmd;
			this.scrJrefAVar = scrJrefAVar;
			this.scrJref1NSensitivity = scrJref1NSensitivity;
			this.scrJrefJob1NStage = scrJrefJob1NStage;
			this.scrJref1NRtjob = scrJref1NRtjob;
			this.scrJref1NMethod = scrJref1NMethod;
			this.scrJrefRef1NBlock = scrJrefRef1NBlock;
			this.scrJrefHk1NVector = scrJrefHk1NVector;
			this.scrJrefSupMNJob = scrJrefSupMNJob;
			this.scrJrefMNOp = scrJrefMNOp;
			this.scrJrefMNOppack = scrJrefMNOppack;
			this.scrJrefSubMNJob = scrJrefSubMNJob;
			this.pnlsubmnjobAvail = pnlsubmnjobAvail;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFACMD, SCRJREFAVAR, SCRJREF1NSENSITIVITY, SCRJREFJOB1NSTAGE, SCRJREF1NRTJOB, SCRJREF1NMETHOD, SCRJREFREF1NBLOCK, SCRJREFHK1NVECTOR, SCRJREFSUPMNJOB, SCRJREFMNOP, SCRJREFMNOPPACK, SCRJREFSUBMNJOB, PNLSUBMNJOBAVAIL, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefACmd;
		public String scrJrefAVar;
		public String scrJref1NSensitivity;
		public String scrJrefJob1NStage;
		public String scrJref1NRtjob;
		public String scrJref1NMethod;
		public String scrJrefRef1NBlock;
		public String scrJrefHk1NVector;
		public String scrJrefSupMNJob;
		public String scrJrefMNOp;
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
				scrJrefACmd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefACmd", mask, SCRJREFACMD);
				scrJrefAVar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAVar", mask, SCRJREFAVAR);
				scrJref1NSensitivity = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NSensitivity", mask, SCRJREF1NSENSITIVITY);
				scrJrefJob1NStage = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefJob1NStage", mask, SCRJREFJOB1NSTAGE);
				scrJref1NRtjob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NRtjob", mask, SCRJREF1NRTJOB);
				scrJref1NMethod = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NMethod", mask, SCRJREF1NMETHOD);
				scrJrefRef1NBlock = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NBlock", mask, SCRJREFREF1NBLOCK);
				scrJrefHk1NVector = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHk1NVector", mask, SCRJREFHK1NVECTOR);
				scrJrefSupMNJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSupMNJob", mask, SCRJREFSUPMNJOB);
				scrJrefMNOp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNOp", mask, SCRJREFMNOP);
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
			if (scrJrefACmd.equals(comp.scrJrefACmd)) items.add(SCRJREFACMD);
			if (scrJrefAVar.equals(comp.scrJrefAVar)) items.add(SCRJREFAVAR);
			if (scrJref1NSensitivity.equals(comp.scrJref1NSensitivity)) items.add(SCRJREF1NSENSITIVITY);
			if (scrJrefJob1NStage.equals(comp.scrJrefJob1NStage)) items.add(SCRJREFJOB1NSTAGE);
			if (scrJref1NRtjob.equals(comp.scrJref1NRtjob)) items.add(SCRJREF1NRTJOB);
			if (scrJref1NMethod.equals(comp.scrJref1NMethod)) items.add(SCRJREF1NMETHOD);
			if (scrJrefRef1NBlock.equals(comp.scrJrefRef1NBlock)) items.add(SCRJREFREF1NBLOCK);
			if (scrJrefHk1NVector.equals(comp.scrJrefHk1NVector)) items.add(SCRJREFHK1NVECTOR);
			if (scrJrefSupMNJob.equals(comp.scrJrefSupMNJob)) items.add(SCRJREFSUPMNJOB);
			if (scrJrefMNOp.equals(comp.scrJrefMNOp)) items.add(SCRJREFMNOP);
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

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFACMD, SCRJREFAVAR, SCRJREF1NSENSITIVITY, SCRJREFJOB1NSTAGE, SCRJREF1NRTJOB, SCRJREF1NMETHOD, SCRJREFREF1NBLOCK, SCRJREFHK1NVECTOR, SCRJREFSUPMNJOB, SCRJREFMNOP, SCRJREFMNOPPACK, SCRJREFSUBMNJOB, PNLSUBMNJOBAVAIL, BUTREGULARIZEACTIVE));
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
