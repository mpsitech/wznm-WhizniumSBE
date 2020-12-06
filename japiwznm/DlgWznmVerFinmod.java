/**
  * \file DlgWznmVerFinmod.java
  * Java API code for job DlgWznmVerFinmod
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWznmVerFinmod {
	/**
		* VecVDo (full: VecVDlgWznmVerFinmodDo)
		*/
	public static class VecVDo {

		public static final int FNMBUTRUNCLICK = 1;
		public static final int FNMBUTSTOCLICK = 2;
		public static final int BUTDNECLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("fnmbutrunclick")) return FNMBUTRUNCLICK;
			if (s.equals("fnmbutstoclick")) return FNMBUTSTOCLICK;
			if (s.equals("butdneclick")) return BUTDNECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == FNMBUTRUNCLICK) return("FnmButRunClick");
			if (ix == FNMBUTSTOCLICK) return("FnmButStoClick");
			if (ix == BUTDNECLICK) return("ButDneClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWznmVerFinmodSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int FINMOD = 2;
		public static final int SYNC = 3;
		public static final int DONE = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("finmod")) return FINMOD;
			if (s.equals("sync")) return SYNC;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == FINMOD) return("finmod");
			if (ix == SYNC) return("sync");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfDlgWznmVerFinmod)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int FNMTXTPRG = 2;

		public ContInf(
					int numFSge
					, String FnmTxtPrg
				) {
			this.numFSge = numFSge;
			this.FnmTxtPrg = FnmTxtPrg;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, FNMTXTPRG));
		};

		public int numFSge;
		public String FnmTxtPrg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmVerFinmod");

			String itemtag = "ContitemInfDlgWznmVerFinmod";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				FnmTxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "FnmTxtPrg", mask, FNMTXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);
			if (FnmTxtPrg.equals(comp.FnmTxtPrg)) items.add(FNMTXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, FNMTXTPRG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWznmVerFinmod)
	  */
	public class StatApp extends Block {

		public static final int SHORTMENU = 1;

		public StatApp(
					String shortMenu
				) {
			this.shortMenu = shortMenu;

			mask = new HashSet<Integer>(Arrays.asList(SHORTMENU));
		};

		public String shortMenu;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWznmVerFinmod");

			String itemtag = "StatitemAppDlgWznmVerFinmod";

			if (Xmlio.checkXPath(doc, basexpath)) {
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SHORTMENU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrDlgWznmVerFinmod)
	  */
	public class StatShr extends Block {

		public static final int FNMBUTRUNACTIVE = 1;
		public static final int FNMBUTSTOACTIVE = 2;
		public static final int BUTDNEACTIVE = 3;

		public StatShr(
					boolean FnmButRunActive
					, boolean FnmButStoActive
					, boolean ButDneActive
				) {
			this.FnmButRunActive = FnmButRunActive;
			this.FnmButStoActive = FnmButStoActive;
			this.ButDneActive = ButDneActive;

			mask = new HashSet<Integer>(Arrays.asList(FNMBUTRUNACTIVE, FNMBUTSTOACTIVE, BUTDNEACTIVE));
		};

		public boolean FnmButRunActive;
		public boolean FnmButStoActive;
		public boolean ButDneActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmVerFinmod");

			String itemtag = "StatitemShrDlgWznmVerFinmod";

			if (Xmlio.checkXPath(doc, basexpath)) {
				FnmButRunActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "FnmButRunActive", mask, FNMBUTRUNACTIVE);
				FnmButStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "FnmButStoActive", mask, FNMBUTSTOACTIVE);
				ButDneActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDneActive", mask, BUTDNEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (FnmButRunActive == comp.FnmButRunActive) items.add(FNMBUTRUNACTIVE);
			if (FnmButStoActive == comp.FnmButStoActive) items.add(FNMBUTSTOACTIVE);
			if (ButDneActive == comp.ButDneActive) items.add(BUTDNEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(FNMBUTRUNACTIVE, FNMBUTSTOACTIVE, BUTDNEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWznmVerFinmod)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int FNMCPTPRG = 2;
		public static final int FNMBUTRUN = 3;
		public static final int FNMBUTSTO = 4;
		public static final int BUTDNE = 5;

		public Tag(
					String Cpt
					, String FnmCptPrg
					, String FnmButRun
					, String FnmButSto
					, String ButDne
				) {
			this.Cpt = Cpt;
			this.FnmCptPrg = FnmCptPrg;
			this.FnmButRun = FnmButRun;
			this.FnmButSto = FnmButSto;
			this.ButDne = ButDne;

			mask = new HashSet<Integer>(Arrays.asList(CPT, FNMCPTPRG, FNMBUTRUN, FNMBUTSTO, BUTDNE));
		};

		public String Cpt;
		public String FnmCptPrg;
		public String FnmButRun;
		public String FnmButSto;
		public String ButDne;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmVerFinmod");

			String itemtag = "TagitemDlgWznmVerFinmod";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				FnmCptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "FnmCptPrg", mask, FNMCPTPRG);
				FnmButRun = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "FnmButRun", mask, FNMBUTRUN);
				FnmButSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "FnmButSto", mask, FNMBUTSTO);
				ButDne = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButDne", mask, BUTDNE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (FnmCptPrg.equals(comp.FnmCptPrg)) items.add(FNMCPTPRG);
			if (FnmButRun.equals(comp.FnmButRun)) items.add(FNMBUTRUN);
			if (FnmButSto.equals(comp.FnmButSto)) items.add(FNMBUTSTO);
			if (ButDne.equals(comp.ButDne)) items.add(BUTDNE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, FNMCPTPRG, FNMBUTRUN, FNMBUTSTO, BUTDNE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmVerFinmodDo)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMVERFINMODDO, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmVerFinmodDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWznmVerFinmodData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGDLGWZNMVERFINMODDATA);

			continf = new ContInf(0, "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp("");
			statshr = new StatShr(false, false, false);
			tag = new Tag("", "", "", "", "");
		};

		public ContInf continf;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFSGE)) ss.add("feedFSge");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWznmVerFinmodData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf(0, "");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp("");
				statshr = new StatShr(false, false, false);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};
