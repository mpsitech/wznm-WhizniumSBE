/**
  * \file DlgWznmVerGenjtr.java
  * Java API code for job DlgWznmVerGenjtr
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWznmVerGenjtr {
	/**
		* VecVDit (full: VecVDlgWznmVerGenjtrDit)
		*/
	public static class VecVDit {

		public static final int GJT = 1;
		public static final int LFI = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("gjt")) return GJT;
			if (s.equals("lfi")) return LFI;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == GJT) return("Gjt");
			if (ix == LFI) return("Lfi");

			return "";
		};

	};

	/**
		* VecVDo (full: VecVDlgWznmVerGenjtrDo)
		*/
	public static class VecVDo {

		public static final int GJTBUTRUNCLICK = 1;
		public static final int GJTBUTSTOCLICK = 2;
		public static final int BUTDNECLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("gjtbutrunclick")) return GJTBUTRUNCLICK;
			if (s.equals("gjtbutstoclick")) return GJTBUTSTOCLICK;
			if (s.equals("butdneclick")) return BUTDNECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == GJTBUTRUNCLICK) return("GjtButRunClick");
			if (ix == GJTBUTSTOCLICK) return("GjtButStoClick");
			if (ix == BUTDNECLICK) return("ButDneClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWznmVerGenjtrSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRGER = 2;
		public static final int GENQTB = 3;
		public static final int GENJOB = 4;
		public static final int GENCALL = 5;
		public static final int GENCTP = 6;
		public static final int ASMLFI = 7;
		public static final int FAIL = 8;
		public static final int DONE = 9;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alrger")) return ALRGER;
			if (s.equals("genqtb")) return GENQTB;
			if (s.equals("genjob")) return GENJOB;
			if (s.equals("gencall")) return GENCALL;
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
			if (ix == GENQTB) return("genqtb");
			if (ix == GENJOB) return("genjob");
			if (ix == GENCALL) return("gencall");
			if (ix == GENCTP) return("genctp");
			if (ix == ASMLFI) return("asmlfi");
			if (ix == FAIL) return("fail");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWznmVerGenjtr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWznmVerGenjtr");

			String itemtag = "ContitemIacDlgWznmVerGenjtr";

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWznmVerGenjtr";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWznmVerGenjtr";

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
	  * ContInf (full: ContInfDlgWznmVerGenjtr)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int GJTTXTPRG = 2;

		public ContInf(
					int numFSge
					, String GjtTxtPrg
				) {
			this.numFSge = numFSge;
			this.GjtTxtPrg = GjtTxtPrg;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, GJTTXTPRG));
		};

		public int numFSge;
		public String GjtTxtPrg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmVerGenjtr");

			String itemtag = "ContitemInfDlgWznmVerGenjtr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				GjtTxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "GjtTxtPrg", mask, GJTTXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);
			if (GjtTxtPrg.equals(comp.GjtTxtPrg)) items.add(GJTTXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, GJTTXTPRG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInfLfi (full: ContInfDlgWznmVerGenjtrLfi)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmVerGenjtrLfi");

			String itemtag = "ContitemInfDlgWznmVerGenjtrLfi";

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
	  * StatApp (full: StatAppDlgWznmVerGenjtr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWznmVerGenjtr");

			String itemtag = "StatitemAppDlgWznmVerGenjtr";

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
	  * StatShr (full: StatShrDlgWznmVerGenjtr)
	  */
	public class StatShr extends Block {

		public static final int GJTBUTRUNACTIVE = 1;
		public static final int GJTBUTSTOACTIVE = 2;
		public static final int BUTDNEACTIVE = 3;

		public StatShr(
					boolean GjtButRunActive
					, boolean GjtButStoActive
					, boolean ButDneActive
				) {
			this.GjtButRunActive = GjtButRunActive;
			this.GjtButStoActive = GjtButStoActive;
			this.ButDneActive = ButDneActive;

			mask = new HashSet<Integer>(Arrays.asList(GJTBUTRUNACTIVE, GJTBUTSTOACTIVE, BUTDNEACTIVE));
		};

		public boolean GjtButRunActive;
		public boolean GjtButStoActive;
		public boolean ButDneActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmVerGenjtr");

			String itemtag = "StatitemShrDlgWznmVerGenjtr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				GjtButRunActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "GjtButRunActive", mask, GJTBUTRUNACTIVE);
				GjtButStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "GjtButStoActive", mask, GJTBUTSTOACTIVE);
				ButDneActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDneActive", mask, BUTDNEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (GjtButRunActive == comp.GjtButRunActive) items.add(GJTBUTRUNACTIVE);
			if (GjtButStoActive == comp.GjtButStoActive) items.add(GJTBUTSTOACTIVE);
			if (ButDneActive == comp.ButDneActive) items.add(BUTDNEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(GJTBUTRUNACTIVE, GJTBUTSTOACTIVE, BUTDNEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrLfi (full: StatShrDlgWznmVerGenjtrLfi)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmVerGenjtrLfi");

			String itemtag = "StatitemShrDlgWznmVerGenjtrLfi";

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
	  * Tag (full: TagDlgWznmVerGenjtr)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int GJTBUTRUN = 2;
		public static final int GJTBUTSTO = 3;
		public static final int BUTDNE = 4;

		public Tag(
					String Cpt
					, String GjtButRun
					, String GjtButSto
					, String ButDne
				) {
			this.Cpt = Cpt;
			this.GjtButRun = GjtButRun;
			this.GjtButSto = GjtButSto;
			this.ButDne = ButDne;

			mask = new HashSet<Integer>(Arrays.asList(CPT, GJTBUTRUN, GJTBUTSTO, BUTDNE));
		};

		public String Cpt;
		public String GjtButRun;
		public String GjtButSto;
		public String ButDne;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmVerGenjtr");

			String itemtag = "TagitemDlgWznmVerGenjtr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				GjtButRun = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "GjtButRun", mask, GJTBUTRUN);
				GjtButSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "GjtButSto", mask, GJTBUTSTO);
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
			if (GjtButRun.equals(comp.GjtButRun)) items.add(GJTBUTRUN);
			if (GjtButSto.equals(comp.GjtButSto)) items.add(GJTBUTSTO);
			if (ButDne.equals(comp.ButDne)) items.add(BUTDNE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, GJTBUTRUN, GJTBUTSTO, BUTDNE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagGjt (full: TagDlgWznmVerGenjtrGjt)
	  */
	public class TagGjt extends Block {

		public static final int CPTPRG = 1;

		public TagGjt(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmVerGenjtrGjt");

			String itemtag = "TagitemDlgWznmVerGenjtrGjt";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrg", mask, CPTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagGjt comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptPrg.equals(comp.CptPrg)) items.add(CPTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					TagGjt comp
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
	  * TagLfi (full: TagDlgWznmVerGenjtrLfi)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmVerGenjtrLfi");

			String itemtag = "TagitemDlgWznmVerGenjtrLfi";

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
		* DpchAppData (full: DpchAppDlgWznmVerGenjtrData)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMVERGENJTRDATA, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmVerGenjtrData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmVerGenjtrDo)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMVERGENJTRDO, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmVerGenjtrDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWznmVerGenjtrData)
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
		public static final int TAGGJT = 11;
		public static final int TAGLFI = 12;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGDLGWZNMVERGENJTRDATA);

			contiac = new ContIac(0);
			continf = new ContInf(0, "");
			continflfi = new ContInfLfi("");
			feedFDse = new Feed("FeedFDse");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(false, "");
			statshr = new StatShr(false, false, false);
			statshrlfi = new StatShrLfi(false);
			tag = new Tag("", "", "", "");
			taggjt = new TagGjt("");
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
		public TagGjt taggjt;
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
			if (has(TAGGJT)) ss.add("taggjt");
			if (has(TAGLFI)) ss.add("taglfi");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWznmVerGenjtrData");

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
				if (taggjt.readXML(doc, basexpath, true)) add(TAGGJT);
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
				taggjt = new TagGjt("");
				taglfi = new TagLfi("");
			};
		};

	};

};
