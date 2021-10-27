/**
  * \file PnlWznmStbRec.java
  * Java API code for job PnlWznmStbRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmStbRec {
	/**
		* VecVDo (full: VecVWznmStbRecDo)
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
	  * ContInf (full: ContInfWznmStbRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmStbRec");

			String itemtag = "ContitemInfWznmStbRec";

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
	  * StatApp (full: StatAppWznmStbRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONESUPMNSTUB = 2;
		public static final int INITDONESUBMNSTUB = 3;
		public static final int INITDONEMNSQUAWK = 4;
		public static final int INITDONEMNCALL = 5;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneSupMNStub
					, boolean initdoneSubMNStub
					, boolean initdoneMNSquawk
					, boolean initdoneMNCall
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneSupMNStub = initdoneSupMNStub;
			this.initdoneSubMNStub = initdoneSubMNStub;
			this.initdoneMNSquawk = initdoneMNSquawk;
			this.initdoneMNCall = initdoneMNCall;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONESUPMNSTUB, INITDONESUBMNSTUB, INITDONEMNSQUAWK, INITDONEMNCALL));
		};

		public boolean initdoneDetail;
		public boolean initdoneSupMNStub;
		public boolean initdoneSubMNStub;
		public boolean initdoneMNSquawk;
		public boolean initdoneMNCall;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmStbRec");

			String itemtag = "StatitemAppWznmStbRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneSupMNStub = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSupMNStub", mask, INITDONESUPMNSTUB);
				initdoneSubMNStub = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSubMNStub", mask, INITDONESUBMNSTUB);
				initdoneMNSquawk = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNSquawk", mask, INITDONEMNSQUAWK);
				initdoneMNCall = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNCall", mask, INITDONEMNCALL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdoneSupMNStub == comp.initdoneSupMNStub) items.add(INITDONESUPMNSTUB);
			if (initdoneSubMNStub == comp.initdoneSubMNStub) items.add(INITDONESUBMNSTUB);
			if (initdoneMNSquawk == comp.initdoneMNSquawk) items.add(INITDONEMNSQUAWK);
			if (initdoneMNCall == comp.initdoneMNCall) items.add(INITDONEMNCALL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONESUPMNSTUB, INITDONESUBMNSTUB, INITDONEMNSQUAWK, INITDONEMNCALL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmStbRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFSUPMNSTUB = 3;
		public static final int SCRJREFSUBMNSTUB = 4;
		public static final int SCRJREFMNSQUAWK = 5;
		public static final int SCRJREFMNCALL = 6;
		public static final int BUTREGULARIZEACTIVE = 7;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefSupMNStub
					, String scrJrefSubMNStub
					, String scrJrefMNSquawk
					, String scrJrefMNCall
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefSupMNStub = scrJrefSupMNStub;
			this.scrJrefSubMNStub = scrJrefSubMNStub;
			this.scrJrefMNSquawk = scrJrefMNSquawk;
			this.scrJrefMNCall = scrJrefMNCall;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFSUPMNSTUB, SCRJREFSUBMNSTUB, SCRJREFMNSQUAWK, SCRJREFMNCALL, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefSupMNStub;
		public String scrJrefSubMNStub;
		public String scrJrefMNSquawk;
		public String scrJrefMNCall;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmStbRec");

			String itemtag = "StatitemShrWznmStbRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefSupMNStub = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSupMNStub", mask, SCRJREFSUPMNSTUB);
				scrJrefSubMNStub = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSubMNStub", mask, SCRJREFSUBMNSTUB);
				scrJrefMNSquawk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNSquawk", mask, SCRJREFMNSQUAWK);
				scrJrefMNCall = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNCall", mask, SCRJREFMNCALL);
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
			if (scrJrefSupMNStub.equals(comp.scrJrefSupMNStub)) items.add(SCRJREFSUPMNSTUB);
			if (scrJrefSubMNStub.equals(comp.scrJrefSubMNStub)) items.add(SCRJREFSUBMNSTUB);
			if (scrJrefMNSquawk.equals(comp.scrJrefMNSquawk)) items.add(SCRJREFMNSQUAWK);
			if (scrJrefMNCall.equals(comp.scrJrefMNCall)) items.add(SCRJREFMNCALL);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFSUPMNSTUB, SCRJREFSUBMNSTUB, SCRJREFMNSQUAWK, SCRJREFMNCALL, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmStbRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmStbRec");

			String itemtag = "TagitemWznmStbRec";

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
		* DpchAppDo (full: DpchAppWznmStbRecDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMSTBRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmStbRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmStbRecData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMSTBRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmStbRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", "", false);
				tag = new Tag("");
			};
		};

	};

};
