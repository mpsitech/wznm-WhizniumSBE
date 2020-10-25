/**
  * \file PnlWznmNavDeploy.java
  * Java API code for job PnlWznmNavDeploy
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmNavDeploy {
	/**
		* VecVDo (full: VecVWznmNavDeployDo)
		*/
	public static class VecVDo {

		public static final int BUTCMPVIEWCLICK = 1;
		public static final int BUTCMPNEWCRDCLICK = 2;
		public static final int BUTRLSVIEWCLICK = 3;
		public static final int BUTRLSNEWCRDCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butcmpviewclick")) return BUTCMPVIEWCLICK;
			if (s.equals("butcmpnewcrdclick")) return BUTCMPNEWCRDCLICK;
			if (s.equals("butrlsviewclick")) return BUTRLSVIEWCLICK;
			if (s.equals("butrlsnewcrdclick")) return BUTRLSNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTCMPVIEWCLICK) return("ButCmpViewClick");
			if (ix == BUTCMPNEWCRDCLICK) return("ButCmpNewcrdClick");
			if (ix == BUTRLSVIEWCLICK) return("ButRlsViewClick");
			if (ix == BUTRLSNEWCRDCLICK) return("ButRlsNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmNavDeploy)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTCMP = 1;
		public static final int NUMFLSTRLS = 2;

		public ContIac(
					int numFLstCmp
					, int numFLstRls
				) {
			this.numFLstCmp = numFLstCmp;
			this.numFLstRls = numFLstRls;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTCMP, NUMFLSTRLS));
		};

		public int numFLstCmp;
		public int numFLstRls;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmNavDeploy");

			String itemtag = "ContitemIacWznmNavDeploy";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstCmp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstCmp", mask, NUMFLSTCMP);
				numFLstRls = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstRls", mask, NUMFLSTRLS);

				return true;
			};

			return false;
		};

		public void writeXML(
					Document doc
					, Element sup
					, String difftag
					, boolean shorttags
				) {
			if (difftag.isEmpty()) difftag = "ContIacWznmNavDeploy";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmNavDeploy";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstCmp", numFLstCmp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstRls", numFLstRls);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstCmp == comp.numFLstCmp) items.add(NUMFLSTCMP);
			if (numFLstRls == comp.numFLstRls) items.add(NUMFLSTRLS);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTCMP, NUMFLSTRLS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmNavDeploy)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTCMPALT = 2;
		public static final int LSTRLSALT = 3;
		public static final int LSTCMPNUMFIRSTDISP = 4;
		public static final int LSTRLSNUMFIRSTDISP = 5;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstCmpAlt
					, boolean LstRlsAlt
					, int LstCmpNumFirstdisp
					, int LstRlsNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstCmpAlt = LstCmpAlt;
			this.LstRlsAlt = LstRlsAlt;
			this.LstCmpNumFirstdisp = LstCmpNumFirstdisp;
			this.LstRlsNumFirstdisp = LstRlsNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTCMPALT, LSTRLSALT, LSTCMPNUMFIRSTDISP, LSTRLSNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstCmpAlt;
		public boolean LstRlsAlt;
		public int LstCmpNumFirstdisp;
		public int LstRlsNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmNavDeploy");

			String itemtag = "StatitemAppWznmNavDeploy";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstCmpAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCmpAlt", mask, LSTCMPALT);
				LstRlsAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRlsAlt", mask, LSTRLSALT);
				LstCmpNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCmpNumFirstdisp", mask, LSTCMPNUMFIRSTDISP);
				LstRlsNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRlsNumFirstdisp", mask, LSTRLSNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstCmpAlt == comp.LstCmpAlt) items.add(LSTCMPALT);
			if (LstRlsAlt == comp.LstRlsAlt) items.add(LSTRLSALT);
			if (LstCmpNumFirstdisp == comp.LstCmpNumFirstdisp) items.add(LSTCMPNUMFIRSTDISP);
			if (LstRlsNumFirstdisp == comp.LstRlsNumFirstdisp) items.add(LSTRLSNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTCMPALT, LSTRLSALT, LSTCMPNUMFIRSTDISP, LSTRLSNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmNavDeploy)
	  */
	public class StatShr extends Block {

		public static final int LSTCMPAVAIL = 1;
		public static final int BUTCMPVIEWACTIVE = 2;
		public static final int BUTCMPNEWCRDACTIVE = 3;
		public static final int LSTRLSAVAIL = 4;
		public static final int BUTRLSVIEWACTIVE = 5;
		public static final int BUTRLSNEWCRDACTIVE = 6;

		public StatShr(
					boolean LstCmpAvail
					, boolean ButCmpViewActive
					, boolean ButCmpNewcrdActive
					, boolean LstRlsAvail
					, boolean ButRlsViewActive
					, boolean ButRlsNewcrdActive
				) {
			this.LstCmpAvail = LstCmpAvail;
			this.ButCmpViewActive = ButCmpViewActive;
			this.ButCmpNewcrdActive = ButCmpNewcrdActive;
			this.LstRlsAvail = LstRlsAvail;
			this.ButRlsViewActive = ButRlsViewActive;
			this.ButRlsNewcrdActive = ButRlsNewcrdActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTCMPAVAIL, BUTCMPVIEWACTIVE, BUTCMPNEWCRDACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE));
		};

		public boolean LstCmpAvail;
		public boolean ButCmpViewActive;
		public boolean ButCmpNewcrdActive;
		public boolean LstRlsAvail;
		public boolean ButRlsViewActive;
		public boolean ButRlsNewcrdActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmNavDeploy");

			String itemtag = "StatitemShrWznmNavDeploy";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstCmpAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCmpAvail", mask, LSTCMPAVAIL);
				ButCmpViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCmpViewActive", mask, BUTCMPVIEWACTIVE);
				ButCmpNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCmpNewcrdActive", mask, BUTCMPNEWCRDACTIVE);
				LstRlsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRlsAvail", mask, LSTRLSAVAIL);
				ButRlsViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRlsViewActive", mask, BUTRLSVIEWACTIVE);
				ButRlsNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRlsNewcrdActive", mask, BUTRLSNEWCRDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstCmpAvail == comp.LstCmpAvail) items.add(LSTCMPAVAIL);
			if (ButCmpViewActive == comp.ButCmpViewActive) items.add(BUTCMPVIEWACTIVE);
			if (ButCmpNewcrdActive == comp.ButCmpNewcrdActive) items.add(BUTCMPNEWCRDACTIVE);
			if (LstRlsAvail == comp.LstRlsAvail) items.add(LSTRLSAVAIL);
			if (ButRlsViewActive == comp.ButRlsViewActive) items.add(BUTRLSVIEWACTIVE);
			if (ButRlsNewcrdActive == comp.ButRlsNewcrdActive) items.add(BUTRLSNEWCRDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTCMPAVAIL, BUTCMPVIEWACTIVE, BUTCMPNEWCRDACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmNavDeploy)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTCMP = 2;
		public static final int CPTRLS = 3;

		public Tag(
					String Cpt
					, String CptCmp
					, String CptRls
				) {
			this.Cpt = Cpt;
			this.CptCmp = CptCmp;
			this.CptRls = CptRls;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTCMP, CPTRLS));
		};

		public String Cpt;
		public String CptCmp;
		public String CptRls;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmNavDeploy");

			String itemtag = "TagitemWznmNavDeploy";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptCmp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmp", mask, CPTCMP);
				CptRls = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptRls", mask, CPTRLS);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptCmp.equals(comp.CptCmp)) items.add(CPTCMP);
			if (CptRls.equals(comp.CptRls)) items.add(CPTRLS);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTCMP, CPTRLS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmNavDeployData)
		*/
	public class DpchAppData extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int ALL = 3;

		public DpchAppData(
					String scrJref
					, ContIac contiac
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPWZNMNAVDEPLOYDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIAC));
					break;
				};

			if (has(CONTIAC)) this.contiac = contiac;
		};

		public ContIac contiac;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWznmNavDeployData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmNavDeployDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVDEPLOYDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavDeployDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmNavDeployData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTCMP = 3;
		public static final int FEEDFLSTRLS = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMNAVDEPLOYDATA);

			contiac = new ContIac(0, 0);
			feedFLstCmp = new Feed("FeedFLstCmp");
			feedFLstRls = new Feed("FeedFLstRls");
			statapp = new StatApp(0, false, false, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false);
			tag = new Tag("", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstCmp;
		public Feed feedFLstRls;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTCMP)) ss.add("feedFLstCmp");
			if (has(FEEDFLSTRLS)) ss.add("feedFLstRls");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmNavDeployData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstCmp.readXML(doc, basexpath, true)) add(FEEDFLSTCMP);
				if (feedFLstRls.readXML(doc, basexpath, true)) add(FEEDFLSTRLS);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0);
				feedFLstCmp = new Feed("FeedFLstCmp");
				feedFLstRls = new Feed("FeedFLstRls");
				statapp = new StatApp(0, false, false, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false);
				tag = new Tag("", "", "");
			};
		};

	};

};

