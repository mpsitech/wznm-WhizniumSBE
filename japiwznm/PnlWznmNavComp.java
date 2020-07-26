/**
  * \file PnlWznmNavComp.java
  * Java API code for job PnlWznmNavComp
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmNavComp {
	/**
		* VecVDo (full: VecVWznmNavCompDo)
		*/
	public static class VecVDo {

		public static final int BUTOPKVIEWCLICK = 1;
		public static final int BUTOPKNEWCRDCLICK = 2;
		public static final int BUTOPXVIEWCLICK = 3;
		public static final int BUTOPXNEWCRDCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butopkviewclick")) return BUTOPKVIEWCLICK;
			if (s.equals("butopknewcrdclick")) return BUTOPKNEWCRDCLICK;
			if (s.equals("butopxviewclick")) return BUTOPXVIEWCLICK;
			if (s.equals("butopxnewcrdclick")) return BUTOPXNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTOPKVIEWCLICK) return("ButOpkViewClick");
			if (ix == BUTOPKNEWCRDCLICK) return("ButOpkNewcrdClick");
			if (ix == BUTOPXVIEWCLICK) return("ButOpxViewClick");
			if (ix == BUTOPXNEWCRDCLICK) return("ButOpxNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmNavComp)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTOPK = 1;
		public static final int NUMFLSTOPX = 2;

		public ContIac(
					int numFLstOpk
					, int numFLstOpx
				) {
			this.numFLstOpk = numFLstOpk;
			this.numFLstOpx = numFLstOpx;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTOPK, NUMFLSTOPX));
		};

		public int numFLstOpk;
		public int numFLstOpx;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmNavComp");

			String itemtag = "ContitemIacWznmNavComp";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstOpk = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstOpk", mask, NUMFLSTOPK);
				numFLstOpx = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstOpx", mask, NUMFLSTOPX);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmNavComp";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmNavComp";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstOpk", numFLstOpk);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstOpx", numFLstOpx);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstOpk == comp.numFLstOpk) items.add(NUMFLSTOPK);
			if (numFLstOpx == comp.numFLstOpx) items.add(NUMFLSTOPX);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTOPK, NUMFLSTOPX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmNavComp)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTOPKALT = 2;
		public static final int LSTOPXALT = 3;
		public static final int LSTOPKNUMFIRSTDISP = 4;
		public static final int LSTOPXNUMFIRSTDISP = 5;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstOpkAlt
					, boolean LstOpxAlt
					, int LstOpkNumFirstdisp
					, int LstOpxNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstOpkAlt = LstOpkAlt;
			this.LstOpxAlt = LstOpxAlt;
			this.LstOpkNumFirstdisp = LstOpkNumFirstdisp;
			this.LstOpxNumFirstdisp = LstOpxNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTOPKALT, LSTOPXALT, LSTOPKNUMFIRSTDISP, LSTOPXNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstOpkAlt;
		public boolean LstOpxAlt;
		public int LstOpkNumFirstdisp;
		public int LstOpxNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmNavComp");

			String itemtag = "StatitemAppWznmNavComp";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstOpkAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOpkAlt", mask, LSTOPKALT);
				LstOpxAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOpxAlt", mask, LSTOPXALT);
				LstOpkNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOpkNumFirstdisp", mask, LSTOPKNUMFIRSTDISP);
				LstOpxNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOpxNumFirstdisp", mask, LSTOPXNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstOpkAlt == comp.LstOpkAlt) items.add(LSTOPKALT);
			if (LstOpxAlt == comp.LstOpxAlt) items.add(LSTOPXALT);
			if (LstOpkNumFirstdisp == comp.LstOpkNumFirstdisp) items.add(LSTOPKNUMFIRSTDISP);
			if (LstOpxNumFirstdisp == comp.LstOpxNumFirstdisp) items.add(LSTOPXNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTOPKALT, LSTOPXALT, LSTOPKNUMFIRSTDISP, LSTOPXNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmNavComp)
	  */
	public class StatShr extends Block {

		public static final int LSTOPKAVAIL = 1;
		public static final int BUTOPKVIEWACTIVE = 2;
		public static final int BUTOPKNEWCRDACTIVE = 3;
		public static final int LSTOPXAVAIL = 4;
		public static final int BUTOPXVIEWACTIVE = 5;
		public static final int BUTOPXNEWCRDACTIVE = 6;

		public StatShr(
					boolean LstOpkAvail
					, boolean ButOpkViewActive
					, boolean ButOpkNewcrdActive
					, boolean LstOpxAvail
					, boolean ButOpxViewActive
					, boolean ButOpxNewcrdActive
				) {
			this.LstOpkAvail = LstOpkAvail;
			this.ButOpkViewActive = ButOpkViewActive;
			this.ButOpkNewcrdActive = ButOpkNewcrdActive;
			this.LstOpxAvail = LstOpxAvail;
			this.ButOpxViewActive = ButOpxViewActive;
			this.ButOpxNewcrdActive = ButOpxNewcrdActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTOPKAVAIL, BUTOPKVIEWACTIVE, BUTOPKNEWCRDACTIVE, LSTOPXAVAIL, BUTOPXVIEWACTIVE, BUTOPXNEWCRDACTIVE));
		};

		public boolean LstOpkAvail;
		public boolean ButOpkViewActive;
		public boolean ButOpkNewcrdActive;
		public boolean LstOpxAvail;
		public boolean ButOpxViewActive;
		public boolean ButOpxNewcrdActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmNavComp");

			String itemtag = "StatitemShrWznmNavComp";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstOpkAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOpkAvail", mask, LSTOPKAVAIL);
				ButOpkViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButOpkViewActive", mask, BUTOPKVIEWACTIVE);
				ButOpkNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButOpkNewcrdActive", mask, BUTOPKNEWCRDACTIVE);
				LstOpxAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOpxAvail", mask, LSTOPXAVAIL);
				ButOpxViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButOpxViewActive", mask, BUTOPXVIEWACTIVE);
				ButOpxNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButOpxNewcrdActive", mask, BUTOPXNEWCRDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstOpkAvail == comp.LstOpkAvail) items.add(LSTOPKAVAIL);
			if (ButOpkViewActive == comp.ButOpkViewActive) items.add(BUTOPKVIEWACTIVE);
			if (ButOpkNewcrdActive == comp.ButOpkNewcrdActive) items.add(BUTOPKNEWCRDACTIVE);
			if (LstOpxAvail == comp.LstOpxAvail) items.add(LSTOPXAVAIL);
			if (ButOpxViewActive == comp.ButOpxViewActive) items.add(BUTOPXVIEWACTIVE);
			if (ButOpxNewcrdActive == comp.ButOpxNewcrdActive) items.add(BUTOPXNEWCRDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTOPKAVAIL, BUTOPKVIEWACTIVE, BUTOPKNEWCRDACTIVE, LSTOPXAVAIL, BUTOPXVIEWACTIVE, BUTOPXNEWCRDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmNavComp)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTOPK = 2;
		public static final int CPTOPX = 3;

		public Tag(
					String Cpt
					, String CptOpk
					, String CptOpx
				) {
			this.Cpt = Cpt;
			this.CptOpk = CptOpk;
			this.CptOpx = CptOpx;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTOPK, CPTOPX));
		};

		public String Cpt;
		public String CptOpk;
		public String CptOpx;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmNavComp");

			String itemtag = "TagitemWznmNavComp";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptOpk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOpk", mask, CPTOPK);
				CptOpx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOpx", mask, CPTOPX);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptOpk.equals(comp.CptOpk)) items.add(CPTOPK);
			if (CptOpx.equals(comp.CptOpx)) items.add(CPTOPX);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTOPK, CPTOPX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmNavCompData)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVCOMPDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavCompData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmNavCompDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVCOMPDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavCompDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmNavCompData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTOPK = 3;
		public static final int FEEDFLSTOPX = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMNAVCOMPDATA);

			contiac = new ContIac(0, 0);
			feedFLstOpk = new Feed("FeedFLstOpk");
			feedFLstOpx = new Feed("FeedFLstOpx");
			statapp = new StatApp(0, false, false, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false);
			tag = new Tag("", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstOpk;
		public Feed feedFLstOpx;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTOPK)) ss.add("feedFLstOpk");
			if (has(FEEDFLSTOPX)) ss.add("feedFLstOpx");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmNavCompData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstOpk.readXML(doc, basexpath, true)) add(FEEDFLSTOPK);
				if (feedFLstOpx.readXML(doc, basexpath, true)) add(FEEDFLSTOPX);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0);
				feedFLstOpk = new Feed("FeedFLstOpk");
				feedFLstOpx = new Feed("FeedFLstOpx");
				statapp = new StatApp(0, false, false, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false);
				tag = new Tag("", "", "");
			};
		};

	};

};

