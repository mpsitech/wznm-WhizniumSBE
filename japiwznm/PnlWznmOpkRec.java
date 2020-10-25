/**
  * \file PnlWznmOpkRec.java
  * Java API code for job PnlWznmOpkRec
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmOpkRec {
	/**
		* VecVDo (full: VecVWznmOpkRecDo)
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
	  * ContInf (full: ContInfWznmOpkRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmOpkRec");

			String itemtag = "ContitemInfWznmOpkRec";

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
	  * StatApp (full: StatAppWznmOpkRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEAINVARG = 2;
		public static final int INITDONEARETVAL = 3;
		public static final int INITDONE1NOP = 4;
		public static final int INITDONEREF1NBLOCK = 5;
		public static final int INITDONEMNCOMPONENT = 6;
		public static final int INITDONEMNLIBRARY = 7;
		public static final int INITDONEMNJOB = 8;
		public static final int INITDONESQKMNSTUB = 9;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneAInvarg
					, boolean initdoneARetval
					, boolean initdone1NOp
					, boolean initdoneRef1NBlock
					, boolean initdoneMNComponent
					, boolean initdoneMNLibrary
					, boolean initdoneMNJob
					, boolean initdoneSqkMNStub
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneAInvarg = initdoneAInvarg;
			this.initdoneARetval = initdoneARetval;
			this.initdone1NOp = initdone1NOp;
			this.initdoneRef1NBlock = initdoneRef1NBlock;
			this.initdoneMNComponent = initdoneMNComponent;
			this.initdoneMNLibrary = initdoneMNLibrary;
			this.initdoneMNJob = initdoneMNJob;
			this.initdoneSqkMNStub = initdoneSqkMNStub;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEAINVARG, INITDONEARETVAL, INITDONE1NOP, INITDONEREF1NBLOCK, INITDONEMNCOMPONENT, INITDONEMNLIBRARY, INITDONEMNJOB, INITDONESQKMNSTUB));
		};

		public boolean initdoneDetail;
		public boolean initdoneAInvarg;
		public boolean initdoneARetval;
		public boolean initdone1NOp;
		public boolean initdoneRef1NBlock;
		public boolean initdoneMNComponent;
		public boolean initdoneMNLibrary;
		public boolean initdoneMNJob;
		public boolean initdoneSqkMNStub;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmOpkRec");

			String itemtag = "StatitemAppWznmOpkRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneAInvarg = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAInvarg", mask, INITDONEAINVARG);
				initdoneARetval = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneARetval", mask, INITDONEARETVAL);
				initdone1NOp = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NOp", mask, INITDONE1NOP);
				initdoneRef1NBlock = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NBlock", mask, INITDONEREF1NBLOCK);
				initdoneMNComponent = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNComponent", mask, INITDONEMNCOMPONENT);
				initdoneMNLibrary = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNLibrary", mask, INITDONEMNLIBRARY);
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
			if (initdoneAInvarg == comp.initdoneAInvarg) items.add(INITDONEAINVARG);
			if (initdoneARetval == comp.initdoneARetval) items.add(INITDONEARETVAL);
			if (initdone1NOp == comp.initdone1NOp) items.add(INITDONE1NOP);
			if (initdoneRef1NBlock == comp.initdoneRef1NBlock) items.add(INITDONEREF1NBLOCK);
			if (initdoneMNComponent == comp.initdoneMNComponent) items.add(INITDONEMNCOMPONENT);
			if (initdoneMNLibrary == comp.initdoneMNLibrary) items.add(INITDONEMNLIBRARY);
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

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEAINVARG, INITDONEARETVAL, INITDONE1NOP, INITDONEREF1NBLOCK, INITDONEMNCOMPONENT, INITDONEMNLIBRARY, INITDONEMNJOB, INITDONESQKMNSTUB));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmOpkRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFAINVARG = 3;
		public static final int SCRJREFARETVAL = 4;
		public static final int SCRJREF1NOP = 5;
		public static final int SCRJREFREF1NBLOCK = 6;
		public static final int SCRJREFMNCOMPONENT = 7;
		public static final int SCRJREFMNLIBRARY = 8;
		public static final int SCRJREFMNJOB = 9;
		public static final int SCRJREFSQKMNSTUB = 10;
		public static final int PNLSQKMNSTUBAVAIL = 11;
		public static final int BUTREGULARIZEACTIVE = 12;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefAInvarg
					, String scrJrefARetval
					, String scrJref1NOp
					, String scrJrefRef1NBlock
					, String scrJrefMNComponent
					, String scrJrefMNLibrary
					, String scrJrefMNJob
					, String scrJrefSqkMNStub
					, boolean pnlsqkmnstubAvail
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefAInvarg = scrJrefAInvarg;
			this.scrJrefARetval = scrJrefARetval;
			this.scrJref1NOp = scrJref1NOp;
			this.scrJrefRef1NBlock = scrJrefRef1NBlock;
			this.scrJrefMNComponent = scrJrefMNComponent;
			this.scrJrefMNLibrary = scrJrefMNLibrary;
			this.scrJrefMNJob = scrJrefMNJob;
			this.scrJrefSqkMNStub = scrJrefSqkMNStub;
			this.pnlsqkmnstubAvail = pnlsqkmnstubAvail;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAINVARG, SCRJREFARETVAL, SCRJREF1NOP, SCRJREFREF1NBLOCK, SCRJREFMNCOMPONENT, SCRJREFMNLIBRARY, SCRJREFMNJOB, SCRJREFSQKMNSTUB, PNLSQKMNSTUBAVAIL, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefAInvarg;
		public String scrJrefARetval;
		public String scrJref1NOp;
		public String scrJrefRef1NBlock;
		public String scrJrefMNComponent;
		public String scrJrefMNLibrary;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmOpkRec");

			String itemtag = "StatitemShrWznmOpkRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefAInvarg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAInvarg", mask, SCRJREFAINVARG);
				scrJrefARetval = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefARetval", mask, SCRJREFARETVAL);
				scrJref1NOp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NOp", mask, SCRJREF1NOP);
				scrJrefRef1NBlock = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NBlock", mask, SCRJREFREF1NBLOCK);
				scrJrefMNComponent = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNComponent", mask, SCRJREFMNCOMPONENT);
				scrJrefMNLibrary = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNLibrary", mask, SCRJREFMNLIBRARY);
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
			if (scrJrefAInvarg.equals(comp.scrJrefAInvarg)) items.add(SCRJREFAINVARG);
			if (scrJrefARetval.equals(comp.scrJrefARetval)) items.add(SCRJREFARETVAL);
			if (scrJref1NOp.equals(comp.scrJref1NOp)) items.add(SCRJREF1NOP);
			if (scrJrefRef1NBlock.equals(comp.scrJrefRef1NBlock)) items.add(SCRJREFREF1NBLOCK);
			if (scrJrefMNComponent.equals(comp.scrJrefMNComponent)) items.add(SCRJREFMNCOMPONENT);
			if (scrJrefMNLibrary.equals(comp.scrJrefMNLibrary)) items.add(SCRJREFMNLIBRARY);
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

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAINVARG, SCRJREFARETVAL, SCRJREF1NOP, SCRJREFREF1NBLOCK, SCRJREFMNCOMPONENT, SCRJREFMNLIBRARY, SCRJREFMNJOB, SCRJREFSQKMNSTUB, PNLSQKMNSTUBAVAIL, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmOpkRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmOpkRec");

			String itemtag = "TagitemWznmOpkRec";

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
		* DpchAppDo (full: DpchAppWznmOpkRecDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMOPKRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmOpkRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmOpkRecData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMOPKRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", false, false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmOpkRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", false, false);
				tag = new Tag("");
			};
		};

	};

};

