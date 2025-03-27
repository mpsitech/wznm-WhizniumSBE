/**
  * \file PnlWznmNavVisual.java
  * Java API code for job PnlWznmNavVisual
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmNavVisual {
	/**
		* VecVDo (full: VecVWznmNavVisualDo)
		*/
	public static class VecVDo {

		public static final int BUTVISVIEWCLICK = 1;
		public static final int BUTVISNEWCRDCLICK = 2;
		public static final int BUTSHTVIEWCLICK = 3;
		public static final int BUTSHTNEWCRDCLICK = 4;
		public static final int BUTBOXVIEWCLICK = 5;
		public static final int BUTBOXNEWCRDCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butvisviewclick")) return BUTVISVIEWCLICK;
			if (s.equals("butvisnewcrdclick")) return BUTVISNEWCRDCLICK;
			if (s.equals("butshtviewclick")) return BUTSHTVIEWCLICK;
			if (s.equals("butshtnewcrdclick")) return BUTSHTNEWCRDCLICK;
			if (s.equals("butboxviewclick")) return BUTBOXVIEWCLICK;
			if (s.equals("butboxnewcrdclick")) return BUTBOXNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTVISVIEWCLICK) return("ButVisViewClick");
			if (ix == BUTVISNEWCRDCLICK) return("ButVisNewcrdClick");
			if (ix == BUTSHTVIEWCLICK) return("ButShtViewClick");
			if (ix == BUTSHTNEWCRDCLICK) return("ButShtNewcrdClick");
			if (ix == BUTBOXVIEWCLICK) return("ButBoxViewClick");
			if (ix == BUTBOXNEWCRDCLICK) return("ButBoxNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmNavVisual)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTVIS = 1;
		public static final int NUMFLSTSHT = 2;
		public static final int NUMFLSTBOX = 3;

		public ContIac(
					int numFLstVis
					, int numFLstSht
					, int numFLstBox
				) {
			this.numFLstVis = numFLstVis;
			this.numFLstSht = numFLstSht;
			this.numFLstBox = numFLstBox;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTVIS, NUMFLSTSHT, NUMFLSTBOX));
		};

		public int numFLstVis;
		public int numFLstSht;
		public int numFLstBox;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmNavVisual");

			String itemtag = "ContitemIacWznmNavVisual";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstVis = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstVis", mask, NUMFLSTVIS);
				numFLstSht = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstSht", mask, NUMFLSTSHT);
				numFLstBox = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstBox", mask, NUMFLSTBOX);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmNavVisual";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmNavVisual";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstVis", numFLstVis);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstSht", numFLstSht);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstBox", numFLstBox);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstVis == comp.numFLstVis) items.add(NUMFLSTVIS);
			if (numFLstSht == comp.numFLstSht) items.add(NUMFLSTSHT);
			if (numFLstBox == comp.numFLstBox) items.add(NUMFLSTBOX);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTVIS, NUMFLSTSHT, NUMFLSTBOX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmNavVisual)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTVISALT = 2;
		public static final int LSTSHTALT = 3;
		public static final int LSTBOXALT = 4;
		public static final int LSTVISNUMFIRSTDISP = 5;
		public static final int LSTSHTNUMFIRSTDISP = 6;
		public static final int LSTBOXNUMFIRSTDISP = 7;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstVisAlt
					, boolean LstShtAlt
					, boolean LstBoxAlt
					, int LstVisNumFirstdisp
					, int LstShtNumFirstdisp
					, int LstBoxNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstVisAlt = LstVisAlt;
			this.LstShtAlt = LstShtAlt;
			this.LstBoxAlt = LstBoxAlt;
			this.LstVisNumFirstdisp = LstVisNumFirstdisp;
			this.LstShtNumFirstdisp = LstShtNumFirstdisp;
			this.LstBoxNumFirstdisp = LstBoxNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTVISALT, LSTSHTALT, LSTBOXALT, LSTVISNUMFIRSTDISP, LSTSHTNUMFIRSTDISP, LSTBOXNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstVisAlt;
		public boolean LstShtAlt;
		public boolean LstBoxAlt;
		public int LstVisNumFirstdisp;
		public int LstShtNumFirstdisp;
		public int LstBoxNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmNavVisual");

			String itemtag = "StatitemAppWznmNavVisual";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstVisAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVisAlt", mask, LSTVISALT);
				LstShtAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstShtAlt", mask, LSTSHTALT);
				LstBoxAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstBoxAlt", mask, LSTBOXALT);
				LstVisNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVisNumFirstdisp", mask, LSTVISNUMFIRSTDISP);
				LstShtNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstShtNumFirstdisp", mask, LSTSHTNUMFIRSTDISP);
				LstBoxNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstBoxNumFirstdisp", mask, LSTBOXNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstVisAlt == comp.LstVisAlt) items.add(LSTVISALT);
			if (LstShtAlt == comp.LstShtAlt) items.add(LSTSHTALT);
			if (LstBoxAlt == comp.LstBoxAlt) items.add(LSTBOXALT);
			if (LstVisNumFirstdisp == comp.LstVisNumFirstdisp) items.add(LSTVISNUMFIRSTDISP);
			if (LstShtNumFirstdisp == comp.LstShtNumFirstdisp) items.add(LSTSHTNUMFIRSTDISP);
			if (LstBoxNumFirstdisp == comp.LstBoxNumFirstdisp) items.add(LSTBOXNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTVISALT, LSTSHTALT, LSTBOXALT, LSTVISNUMFIRSTDISP, LSTSHTNUMFIRSTDISP, LSTBOXNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmNavVisual)
	  */
	public class StatShr extends Block {

		public static final int LSTVISAVAIL = 1;
		public static final int BUTVISVIEWACTIVE = 2;
		public static final int LSTSHTAVAIL = 3;
		public static final int BUTSHTVIEWACTIVE = 4;
		public static final int BUTSHTNEWCRDACTIVE = 5;
		public static final int LSTBOXAVAIL = 6;
		public static final int BUTBOXVIEWACTIVE = 7;
		public static final int BUTBOXNEWCRDACTIVE = 8;

		public StatShr(
					boolean LstVisAvail
					, boolean ButVisViewActive
					, boolean LstShtAvail
					, boolean ButShtViewActive
					, boolean ButShtNewcrdActive
					, boolean LstBoxAvail
					, boolean ButBoxViewActive
					, boolean ButBoxNewcrdActive
				) {
			this.LstVisAvail = LstVisAvail;
			this.ButVisViewActive = ButVisViewActive;
			this.LstShtAvail = LstShtAvail;
			this.ButShtViewActive = ButShtViewActive;
			this.ButShtNewcrdActive = ButShtNewcrdActive;
			this.LstBoxAvail = LstBoxAvail;
			this.ButBoxViewActive = ButBoxViewActive;
			this.ButBoxNewcrdActive = ButBoxNewcrdActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTVISAVAIL, BUTVISVIEWACTIVE, LSTSHTAVAIL, BUTSHTVIEWACTIVE, BUTSHTNEWCRDACTIVE, LSTBOXAVAIL, BUTBOXVIEWACTIVE, BUTBOXNEWCRDACTIVE));
		};

		public boolean LstVisAvail;
		public boolean ButVisViewActive;
		public boolean LstShtAvail;
		public boolean ButShtViewActive;
		public boolean ButShtNewcrdActive;
		public boolean LstBoxAvail;
		public boolean ButBoxViewActive;
		public boolean ButBoxNewcrdActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmNavVisual");

			String itemtag = "StatitemShrWznmNavVisual";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstVisAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVisAvail", mask, LSTVISAVAIL);
				ButVisViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVisViewActive", mask, BUTVISVIEWACTIVE);
				LstShtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstShtAvail", mask, LSTSHTAVAIL);
				ButShtViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButShtViewActive", mask, BUTSHTVIEWACTIVE);
				ButShtNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButShtNewcrdActive", mask, BUTSHTNEWCRDACTIVE);
				LstBoxAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstBoxAvail", mask, LSTBOXAVAIL);
				ButBoxViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBoxViewActive", mask, BUTBOXVIEWACTIVE);
				ButBoxNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBoxNewcrdActive", mask, BUTBOXNEWCRDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstVisAvail == comp.LstVisAvail) items.add(LSTVISAVAIL);
			if (ButVisViewActive == comp.ButVisViewActive) items.add(BUTVISVIEWACTIVE);
			if (LstShtAvail == comp.LstShtAvail) items.add(LSTSHTAVAIL);
			if (ButShtViewActive == comp.ButShtViewActive) items.add(BUTSHTVIEWACTIVE);
			if (ButShtNewcrdActive == comp.ButShtNewcrdActive) items.add(BUTSHTNEWCRDACTIVE);
			if (LstBoxAvail == comp.LstBoxAvail) items.add(LSTBOXAVAIL);
			if (ButBoxViewActive == comp.ButBoxViewActive) items.add(BUTBOXVIEWACTIVE);
			if (ButBoxNewcrdActive == comp.ButBoxNewcrdActive) items.add(BUTBOXNEWCRDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTVISAVAIL, BUTVISVIEWACTIVE, LSTSHTAVAIL, BUTSHTVIEWACTIVE, BUTSHTNEWCRDACTIVE, LSTBOXAVAIL, BUTBOXVIEWACTIVE, BUTBOXNEWCRDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmNavVisual)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTVIS = 2;
		public static final int CPTSHT = 3;
		public static final int CPTBOX = 4;

		public Tag(
					String Cpt
					, String CptVis
					, String CptSht
					, String CptBox
				) {
			this.Cpt = Cpt;
			this.CptVis = CptVis;
			this.CptSht = CptSht;
			this.CptBox = CptBox;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTVIS, CPTSHT, CPTBOX));
		};

		public String Cpt;
		public String CptVis;
		public String CptSht;
		public String CptBox;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmNavVisual");

			String itemtag = "TagitemWznmNavVisual";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptVis = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVis", mask, CPTVIS);
				CptSht = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSht", mask, CPTSHT);
				CptBox = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptBox", mask, CPTBOX);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptVis.equals(comp.CptVis)) items.add(CPTVIS);
			if (CptSht.equals(comp.CptSht)) items.add(CPTSHT);
			if (CptBox.equals(comp.CptBox)) items.add(CPTBOX);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTVIS, CPTSHT, CPTBOX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmNavVisualData)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVVISUALDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavVisualData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmNavVisualDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVVISUALDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavVisualDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmNavVisualData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTBOX = 3;
		public static final int FEEDFLSTSHT = 4;
		public static final int FEEDFLSTVIS = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMNAVVISUALDATA);

			contiac = new ContIac(0, 0, 0);
			feedFLstBox = new Feed("FeedFLstBox");
			feedFLstSht = new Feed("FeedFLstSht");
			feedFLstVis = new Feed("FeedFLstVis");
			statapp = new StatApp(0, false, false, false, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstBox;
		public Feed feedFLstSht;
		public Feed feedFLstVis;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTBOX)) ss.add("feedFLstBox");
			if (has(FEEDFLSTSHT)) ss.add("feedFLstSht");
			if (has(FEEDFLSTVIS)) ss.add("feedFLstVis");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmNavVisualData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstBox.readXML(doc, basexpath, true)) add(FEEDFLSTBOX);
				if (feedFLstSht.readXML(doc, basexpath, true)) add(FEEDFLSTSHT);
				if (feedFLstVis.readXML(doc, basexpath, true)) add(FEEDFLSTVIS);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0);
				feedFLstBox = new Feed("FeedFLstBox");
				feedFLstSht = new Feed("FeedFLstSht");
				feedFLstVis = new Feed("FeedFLstVis");
				statapp = new StatApp(0, false, false, false, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "");
			};
		};

	};

};
