/**
  * \file DlgWznmVerGenui.java
  * Java API code for job DlgWznmVerGenui
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWznmVerGenui {
	/**
		* VecVDit (full: VecVDlgWznmVerGenuiDit)
		*/
	public static class VecVDit {

		public static final int GUI = 1;
		public static final int LFI = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("gui")) return GUI;
			if (s.equals("lfi")) return LFI;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == GUI) return("Gui");
			if (ix == LFI) return("Lfi");

			return "";
		};

	};

	/**
		* VecVDo (full: VecVDlgWznmVerGenuiDo)
		*/
	public static class VecVDo {

		public static final int GUIBUTRUNCLICK = 1;
		public static final int GUIBUTSTOCLICK = 2;
		public static final int BUTDNECLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("guibutrunclick")) return GUIBUTRUNCLICK;
			if (s.equals("guibutstoclick")) return GUIBUTSTOCLICK;
			if (s.equals("butdneclick")) return BUTDNECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == GUIBUTRUNCLICK) return("GuiButRunClick");
			if (ix == GUIBUTSTOCLICK) return("GuiButStoClick");
			if (ix == BUTDNECLICK) return("ButDneClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWznmVerGenuiSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRGER = 2;
		public static final int GENUI = 3;
		public static final int GENCTP = 4;
		public static final int ASMLFI = 5;
		public static final int FAIL = 6;
		public static final int DONE = 7;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alrger")) return ALRGER;
			if (s.equals("genui")) return GENUI;
			if (s.equals("genctp")) return GENCTP;
			if (s.equals("asmlfi")) return ASMLFI;
			if (s.equals("fail")) return FAIL;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == ALRGER) return("alrger");
			if (ix == GENUI) return("genui");
			if (ix == GENCTP) return("genctp");
			if (ix == ASMLFI) return("asmlfi");
			if (ix == FAIL) return("fail");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWznmVerGenui)
	  */
	public class ContIac extends Block {

		public static final int NUMFDSE = 1;

		public ContIac(
					int numFDse
				) {
			this.numFDse = numFDse;

			mask = new HashSet<Integer>(Arrays.asList(NUMFDSE));
		};

		public int numFDse;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWznmVerGenui");

			String itemtag = "ContitemIacDlgWznmVerGenui";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFDse = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDse", mask, NUMFDSE);

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWznmVerGenui";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWznmVerGenui";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDse", numFDse);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFDse == comp.numFDse) items.add(NUMFDSE);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFDSE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfDlgWznmVerGenui)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int GUITXTPRG = 2;

		public ContInf(
					int numFSge
					, String GuiTxtPrg
				) {
			this.numFSge = numFSge;
			this.GuiTxtPrg = GuiTxtPrg;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, GUITXTPRG));
		};

		public int numFSge;
		public String GuiTxtPrg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmVerGenui");

			String itemtag = "ContitemInfDlgWznmVerGenui";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				GuiTxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "GuiTxtPrg", mask, GUITXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);
			if (GuiTxtPrg.equals(comp.GuiTxtPrg)) items.add(GUITXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, GUITXTPRG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInfLfi (full: ContInfDlgWznmVerGenuiLfi)
	  */
	public class ContInfLfi extends Block {

		public static final int DLD = 1;

		public ContInfLfi(
					String Dld
				) {
			this.Dld = Dld;

			mask = new HashSet<Integer>(Arrays.asList(DLD));
		};

		public String Dld;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmVerGenuiLfi");

			String itemtag = "ContitemInfDlgWznmVerGenuiLfi";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Dld", mask, DLD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfLfi comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfLfi comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWznmVerGenui)
	  */
	public class StatApp extends Block {

		public static final int INITDONE = 1;
		public static final int SHORTMENU = 2;

		public StatApp(
					boolean initdone
					, String shortMenu
				) {
			this.initdone = initdone;
			this.shortMenu = shortMenu;

			mask = new HashSet<Integer>(Arrays.asList(INITDONE, SHORTMENU));
		};

		public boolean initdone;
		public String shortMenu;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWznmVerGenui");

			String itemtag = "StatitemAppDlgWznmVerGenui";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdone = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone", mask, INITDONE);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdone == comp.initdone) items.add(INITDONE);
			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONE, SHORTMENU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrDlgWznmVerGenui)
	  */
	public class StatShr extends Block {

		public static final int GUIBUTRUNACTIVE = 1;
		public static final int GUIBUTSTOACTIVE = 2;
		public static final int BUTDNEACTIVE = 3;

		public StatShr(
					boolean GuiButRunActive
					, boolean GuiButStoActive
					, boolean ButDneActive
				) {
			this.GuiButRunActive = GuiButRunActive;
			this.GuiButStoActive = GuiButStoActive;
			this.ButDneActive = ButDneActive;

			mask = new HashSet<Integer>(Arrays.asList(GUIBUTRUNACTIVE, GUIBUTSTOACTIVE, BUTDNEACTIVE));
		};

		public boolean GuiButRunActive;
		public boolean GuiButStoActive;
		public boolean ButDneActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmVerGenui");

			String itemtag = "StatitemShrDlgWznmVerGenui";

			if (Xmlio.checkXPath(doc, basexpath)) {
				GuiButRunActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "GuiButRunActive", mask, GUIBUTRUNACTIVE);
				GuiButStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "GuiButStoActive", mask, GUIBUTSTOACTIVE);
				ButDneActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDneActive", mask, BUTDNEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (GuiButRunActive == comp.GuiButRunActive) items.add(GUIBUTRUNACTIVE);
			if (GuiButStoActive == comp.GuiButStoActive) items.add(GUIBUTSTOACTIVE);
			if (ButDneActive == comp.ButDneActive) items.add(BUTDNEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(GUIBUTRUNACTIVE, GUIBUTSTOACTIVE, BUTDNEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrLfi (full: StatShrDlgWznmVerGenuiLfi)
	  */
	public class StatShrLfi extends Block {

		public static final int DLDACTIVE = 1;

		public StatShrLfi(
					boolean DldActive
				) {
			this.DldActive = DldActive;

			mask = new HashSet<Integer>(Arrays.asList(DLDACTIVE));
		};

		public boolean DldActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmVerGenuiLfi");

			String itemtag = "StatitemShrDlgWznmVerGenuiLfi";

			if (Xmlio.checkXPath(doc, basexpath)) {
				DldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DldActive", mask, DLDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrLfi comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (DldActive == comp.DldActive) items.add(DLDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrLfi comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWznmVerGenui)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int GUIBUTRUN = 2;
		public static final int GUIBUTSTO = 3;
		public static final int BUTDNE = 4;

		public Tag(
					String Cpt
					, String GuiButRun
					, String GuiButSto
					, String ButDne
				) {
			this.Cpt = Cpt;
			this.GuiButRun = GuiButRun;
			this.GuiButSto = GuiButSto;
			this.ButDne = ButDne;

			mask = new HashSet<Integer>(Arrays.asList(CPT, GUIBUTRUN, GUIBUTSTO, BUTDNE));
		};

		public String Cpt;
		public String GuiButRun;
		public String GuiButSto;
		public String ButDne;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmVerGenui");

			String itemtag = "TagitemDlgWznmVerGenui";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				GuiButRun = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "GuiButRun", mask, GUIBUTRUN);
				GuiButSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "GuiButSto", mask, GUIBUTSTO);
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
			if (GuiButRun.equals(comp.GuiButRun)) items.add(GUIBUTRUN);
			if (GuiButSto.equals(comp.GuiButSto)) items.add(GUIBUTSTO);
			if (ButDne.equals(comp.ButDne)) items.add(BUTDNE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, GUIBUTRUN, GUIBUTSTO, BUTDNE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagGui (full: TagDlgWznmVerGenuiGui)
	  */
	public class TagGui extends Block {

		public static final int CPTPRG = 1;

		public TagGui(
					String CptPrg
				) {
			this.CptPrg = CptPrg;

			mask = new HashSet<Integer>(Arrays.asList(CPTPRG));
		};

		public String CptPrg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmVerGenuiGui");

			String itemtag = "TagitemDlgWznmVerGenuiGui";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrg", mask, CPTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagGui comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptPrg.equals(comp.CptPrg)) items.add(CPTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					TagGui comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPTPRG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagLfi (full: TagDlgWznmVerGenuiLfi)
	  */
	public class TagLfi extends Block {

		public static final int DLD = 1;

		public TagLfi(
					String Dld
				) {
			this.Dld = Dld;

			mask = new HashSet<Integer>(Arrays.asList(DLD));
		};

		public String Dld;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmVerGenuiLfi");

			String itemtag = "TagitemDlgWznmVerGenuiLfi";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Dld", mask, DLD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagLfi comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);

			return(items);
		};

		public HashSet<Integer> diff(
					TagLfi comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppDlgWznmVerGenuiData)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMVERGENUIDATA, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmVerGenuiData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmVerGenuiDo)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMVERGENUIDO, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmVerGenuiDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWznmVerGenuiData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int CONTINFLFI = 4;
		public static final int FEEDFDSE = 5;
		public static final int FEEDFSGE = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int STATSHRLFI = 9;
		public static final int TAG = 10;
		public static final int TAGGUI = 11;
		public static final int TAGLFI = 12;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGDLGWZNMVERGENUIDATA);

			contiac = new ContIac(0);
			continf = new ContInf(0, "");
			continflfi = new ContInfLfi("");
			feedFDse = new Feed("FeedFDse");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(false, "");
			statshr = new StatShr(false, false, false);
			statshrlfi = new StatShrLfi(false);
			tag = new Tag("", "", "", "");
			taggui = new TagGui("");
			taglfi = new TagLfi("");
		};

		public ContIac contiac;
		public ContInf continf;
		public ContInfLfi continflfi;
		public Feed feedFDse;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public StatShrLfi statshrlfi;
		public Tag tag;
		public TagGui taggui;
		public TagLfi taglfi;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(CONTINFLFI)) ss.add("continflfi");
			if (has(FEEDFDSE)) ss.add("feedFDse");
			if (has(FEEDFSGE)) ss.add("feedFSge");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STATSHRLFI)) ss.add("statshrlfi");
			if (has(TAG)) ss.add("tag");
			if (has(TAGGUI)) ss.add("taggui");
			if (has(TAGLFI)) ss.add("taglfi");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWznmVerGenuiData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (continflfi.readXML(doc, basexpath, true)) add(CONTINFLFI);
				if (feedFDse.readXML(doc, basexpath, true)) add(FEEDFDSE);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (statshrlfi.readXML(doc, basexpath, true)) add(STATSHRLFI);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (taggui.readXML(doc, basexpath, true)) add(TAGGUI);
				if (taglfi.readXML(doc, basexpath, true)) add(TAGLFI);
			} else {
				scrJref = "";
				contiac = new ContIac(0);
				continf = new ContInf(0, "");
				continflfi = new ContInfLfi("");
				feedFDse = new Feed("FeedFDse");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(false, "");
				statshr = new StatShr(false, false, false);
				statshrlfi = new StatShrLfi(false);
				tag = new Tag("", "", "", "");
				taggui = new TagGui("");
				taglfi = new TagLfi("");
			};
		};

	};

};

