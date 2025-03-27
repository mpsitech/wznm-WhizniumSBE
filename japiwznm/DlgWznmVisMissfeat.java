/**
  * \file DlgWznmVisMissfeat.java
  * Java API code for job DlgWznmVisMissfeat
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWznmVisMissfeat {
	/**
		* VecVDo (full: VecVDlgWznmVisMissfeatDo)
		*/
	public static class VecVDo {

		public static final int CMFBUTRUNCLICK = 1;
		public static final int CMFBUTSTOCLICK = 2;
		public static final int BUTDNECLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("cmfbutrunclick")) return CMFBUTRUNCLICK;
			if (s.equals("cmfbutstoclick")) return CMFBUTSTOCLICK;
			if (s.equals("butdneclick")) return BUTDNECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == CMFBUTRUNCLICK) return("CmfButRunClick");
			if (ix == CMFBUTSTOCLICK) return("CmfButStoClick");
			if (ix == BUTDNECLICK) return("ButDneClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWznmVisMissfeatSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int COMPL = 2;
		public static final int DONE = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("compl")) return COMPL;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == COMPL) return("compl");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfDlgWznmVisMissfeat)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int CMFTXTPRG = 2;

		public ContInf(
					int numFSge
					, String CmfTxtPrg
				) {
			this.numFSge = numFSge;
			this.CmfTxtPrg = CmfTxtPrg;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, CMFTXTPRG));
		};

		public int numFSge;
		public String CmfTxtPrg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmVisMissfeat");

			String itemtag = "ContitemInfDlgWznmVisMissfeat";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				CmfTxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "CmfTxtPrg", mask, CMFTXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);
			if (CmfTxtPrg.equals(comp.CmfTxtPrg)) items.add(CMFTXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, CMFTXTPRG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWznmVisMissfeat)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWznmVisMissfeat");

			String itemtag = "StatitemAppDlgWznmVisMissfeat";

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
	  * StatShr (full: StatShrDlgWznmVisMissfeat)
	  */
	public class StatShr extends Block {

		public static final int CMFBUTRUNACTIVE = 1;
		public static final int CMFBUTSTOACTIVE = 2;
		public static final int BUTDNEACTIVE = 3;

		public StatShr(
					boolean CmfButRunActive
					, boolean CmfButStoActive
					, boolean ButDneActive
				) {
			this.CmfButRunActive = CmfButRunActive;
			this.CmfButStoActive = CmfButStoActive;
			this.ButDneActive = ButDneActive;

			mask = new HashSet<Integer>(Arrays.asList(CMFBUTRUNACTIVE, CMFBUTSTOACTIVE, BUTDNEACTIVE));
		};

		public boolean CmfButRunActive;
		public boolean CmfButStoActive;
		public boolean ButDneActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmVisMissfeat");

			String itemtag = "StatitemShrDlgWznmVisMissfeat";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CmfButRunActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "CmfButRunActive", mask, CMFBUTRUNACTIVE);
				CmfButStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "CmfButStoActive", mask, CMFBUTSTOACTIVE);
				ButDneActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDneActive", mask, BUTDNEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CmfButRunActive == comp.CmfButRunActive) items.add(CMFBUTRUNACTIVE);
			if (CmfButStoActive == comp.CmfButStoActive) items.add(CMFBUTSTOACTIVE);
			if (ButDneActive == comp.ButDneActive) items.add(BUTDNEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CMFBUTRUNACTIVE, CMFBUTSTOACTIVE, BUTDNEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWznmVisMissfeat)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CMFCPTPRG = 2;
		public static final int CMFBUTRUN = 3;
		public static final int CMFBUTSTO = 4;
		public static final int BUTDNE = 5;

		public Tag(
					String Cpt
					, String CmfCptPrg
					, String CmfButRun
					, String CmfButSto
					, String ButDne
				) {
			this.Cpt = Cpt;
			this.CmfCptPrg = CmfCptPrg;
			this.CmfButRun = CmfButRun;
			this.CmfButSto = CmfButSto;
			this.ButDne = ButDne;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CMFCPTPRG, CMFBUTRUN, CMFBUTSTO, BUTDNE));
		};

		public String Cpt;
		public String CmfCptPrg;
		public String CmfButRun;
		public String CmfButSto;
		public String ButDne;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmVisMissfeat");

			String itemtag = "TagitemDlgWznmVisMissfeat";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CmfCptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CmfCptPrg", mask, CMFCPTPRG);
				CmfButRun = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CmfButRun", mask, CMFBUTRUN);
				CmfButSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CmfButSto", mask, CMFBUTSTO);
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
			if (CmfCptPrg.equals(comp.CmfCptPrg)) items.add(CMFCPTPRG);
			if (CmfButRun.equals(comp.CmfButRun)) items.add(CMFBUTRUN);
			if (CmfButSto.equals(comp.CmfButSto)) items.add(CMFBUTSTO);
			if (ButDne.equals(comp.ButDne)) items.add(BUTDNE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CMFCPTPRG, CMFBUTRUN, CMFBUTSTO, BUTDNE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmVisMissfeatDo)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMVISMISSFEATDO, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmVisMissfeatDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWznmVisMissfeatData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGDLGWZNMVISMISSFEATDATA);

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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWznmVisMissfeatData");

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
