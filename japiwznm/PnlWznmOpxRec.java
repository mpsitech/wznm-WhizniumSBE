/**
  * \file PnlWznmOpxRec.java
  * Java API code for job PnlWznmOpxRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmOpxRec {
	/**
		* VecVDo (full: VecVWznmOpxRecDo)
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
	  * ContInf (full: ContInfWznmOpxRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmOpxRec");

			String itemtag = "ContitemInfWznmOpxRec";

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
	  * StatApp (full: StatAppWznmOpxRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEARETVAL = 2;
		public static final int INITDONEAINVARG = 3;
		public static final int INITDONEREF1NBLOCK = 4;
		public static final int INITDONEMNJOB = 5;
		public static final int INITDONESQKMNSTUB = 6;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneARetval
					, boolean initdoneAInvarg
					, boolean initdoneRef1NBlock
					, boolean initdoneMNJob
					, boolean initdoneSqkMNStub
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneARetval = initdoneARetval;
			this.initdoneAInvarg = initdoneAInvarg;
			this.initdoneRef1NBlock = initdoneRef1NBlock;
			this.initdoneMNJob = initdoneMNJob;
			this.initdoneSqkMNStub = initdoneSqkMNStub;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEARETVAL, INITDONEAINVARG, INITDONEREF1NBLOCK, INITDONEMNJOB, INITDONESQKMNSTUB));
		};

		public boolean initdoneDetail;
		public boolean initdoneARetval;
		public boolean initdoneAInvarg;
		public boolean initdoneRef1NBlock;
		public boolean initdoneMNJob;
		public boolean initdoneSqkMNStub;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmOpxRec");

			String itemtag = "StatitemAppWznmOpxRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneARetval = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneARetval", mask, INITDONEARETVAL);
				initdoneAInvarg = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAInvarg", mask, INITDONEAINVARG);
				initdoneRef1NBlock = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NBlock", mask, INITDONEREF1NBLOCK);
				initdoneMNJob = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNJob", mask, INITDONEMNJOB);
				initdoneSqkMNStub = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSqkMNStub", mask, INITDONESQKMNSTUB);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdoneARetval == comp.initdoneARetval) items.add(INITDONEARETVAL);
			if (initdoneAInvarg == comp.initdoneAInvarg) items.add(INITDONEAINVARG);
			if (initdoneRef1NBlock == comp.initdoneRef1NBlock) items.add(INITDONEREF1NBLOCK);
			if (initdoneMNJob == comp.initdoneMNJob) items.add(INITDONEMNJOB);
			if (initdoneSqkMNStub == comp.initdoneSqkMNStub) items.add(INITDONESQKMNSTUB);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEARETVAL, INITDONEAINVARG, INITDONEREF1NBLOCK, INITDONEMNJOB, INITDONESQKMNSTUB));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmOpxRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFARETVAL = 3;
		public static final int SCRJREFAINVARG = 4;
		public static final int SCRJREFREF1NBLOCK = 5;
		public static final int SCRJREFMNJOB = 6;
		public static final int SCRJREFSQKMNSTUB = 7;
		public static final int PNLSQKMNSTUBAVAIL = 8;
		public static final int BUTREGULARIZEACTIVE = 9;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefARetval
					, String scrJrefAInvarg
					, String scrJrefRef1NBlock
					, String scrJrefMNJob
					, String scrJrefSqkMNStub
					, boolean pnlsqkmnstubAvail
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefARetval = scrJrefARetval;
			this.scrJrefAInvarg = scrJrefAInvarg;
			this.scrJrefRef1NBlock = scrJrefRef1NBlock;
			this.scrJrefMNJob = scrJrefMNJob;
			this.scrJrefSqkMNStub = scrJrefSqkMNStub;
			this.pnlsqkmnstubAvail = pnlsqkmnstubAvail;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFARETVAL, SCRJREFAINVARG, SCRJREFREF1NBLOCK, SCRJREFMNJOB, SCRJREFSQKMNSTUB, PNLSQKMNSTUBAVAIL, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefARetval;
		public String scrJrefAInvarg;
		public String scrJrefRef1NBlock;
		public String scrJrefMNJob;
		public String scrJrefSqkMNStub;
		public boolean pnlsqkmnstubAvail;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmOpxRec");

			String itemtag = "StatitemShrWznmOpxRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefARetval = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefARetval", mask, SCRJREFARETVAL);
				scrJrefAInvarg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAInvarg", mask, SCRJREFAINVARG);
				scrJrefRef1NBlock = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NBlock", mask, SCRJREFREF1NBLOCK);
				scrJrefMNJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNJob", mask, SCRJREFMNJOB);
				scrJrefSqkMNStub = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSqkMNStub", mask, SCRJREFSQKMNSTUB);
				pnlsqkmnstubAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlsqkmnstubAvail", mask, PNLSQKMNSTUBAVAIL);
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
			if (scrJrefARetval.equals(comp.scrJrefARetval)) items.add(SCRJREFARETVAL);
			if (scrJrefAInvarg.equals(comp.scrJrefAInvarg)) items.add(SCRJREFAINVARG);
			if (scrJrefRef1NBlock.equals(comp.scrJrefRef1NBlock)) items.add(SCRJREFREF1NBLOCK);
			if (scrJrefMNJob.equals(comp.scrJrefMNJob)) items.add(SCRJREFMNJOB);
			if (scrJrefSqkMNStub.equals(comp.scrJrefSqkMNStub)) items.add(SCRJREFSQKMNSTUB);
			if (pnlsqkmnstubAvail == comp.pnlsqkmnstubAvail) items.add(PNLSQKMNSTUBAVAIL);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFARETVAL, SCRJREFAINVARG, SCRJREFREF1NBLOCK, SCRJREFMNJOB, SCRJREFSQKMNSTUB, PNLSQKMNSTUBAVAIL, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmOpxRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmOpxRec");

			String itemtag = "TagitemWznmOpxRec";

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
		* DpchAppDo (full: DpchAppWznmOpxRecDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMOPXRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmOpxRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmOpxRecData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMOPXRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", false, false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmOpxRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", "", "", false, false);
				tag = new Tag("");
			};
		};

	};

};
