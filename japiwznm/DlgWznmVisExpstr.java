/**
  * \file DlgWznmVisExpstr.java
  * Java API code for job DlgWznmVisExpstr
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWznmVisExpstr {
	/**
		* VecVDit (full: VecVDlgWznmVisExpstrDit)
		*/
	public static class VecVDit {

		public static final int WRI = 1;
		public static final int MFI = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("wri")) return WRI;
			if (s.equals("mfi")) return MFI;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == WRI) return("Wri");
			if (ix == MFI) return("Mfi");

			return "";
		};

	};

	/**
		* VecVDo (full: VecVDlgWznmVisExpstrDo)
		*/
	public static class VecVDo {

		public static final int BUTDNECLICK = 1;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butdneclick")) return BUTDNECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTDNECLICK) return("ButDneClick");

			return "";
		};

	};

	/**
		* VecVDoWri (full: VecVDlgWznmVisExpstrDoWri)
		*/
	public static class VecVDoWri {

		public static final int BUTRUNCLICK = 1;
		public static final int BUTSTOCLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butrunclick")) return BUTRUNCLICK;
			if (s.equals("butstoclick")) return BUTSTOCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTRUNCLICK) return("ButRunClick");
			if (ix == BUTSTOCLICK) return("ButStoClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWznmVisExpstrSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int EXPORT = 2;
		public static final int DONE = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("export")) return EXPORT;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == EXPORT) return("export");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWznmVisExpstr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWznmVisExpstr");

			String itemtag = "ContitemIacDlgWznmVisExpstr";

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWznmVisExpstr";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWznmVisExpstr";

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
	  * ContInf (full: ContInfDlgWznmVisExpstr)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;

		public ContInf(
					int numFSge
				) {
			this.numFSge = numFSge;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE));
		};

		public int numFSge;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmVisExpstr");

			String itemtag = "ContitemInfDlgWznmVisExpstr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInfMfi (full: ContInfDlgWznmVisExpstrMfi)
	  */
	public class ContInfMfi extends Block {

		public static final int DLD = 1;

		public ContInfMfi(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmVisExpstrMfi");

			String itemtag = "ContitemInfDlgWznmVisExpstrMfi";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Dld", mask, DLD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfMfi comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfMfi comp
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
	  * ContInfWri (full: ContInfDlgWznmVisExpstrWri)
	  */
	public class ContInfWri extends Block {

		public static final int TXTPRG = 1;

		public ContInfWri(
					String TxtPrg
				) {
			this.TxtPrg = TxtPrg;

			mask = new HashSet<Integer>(Arrays.asList(TXTPRG));
		};

		public String TxtPrg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmVisExpstrWri");

			String itemtag = "ContitemInfDlgWznmVisExpstrWri";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrg", mask, TXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfWri comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtPrg.equals(comp.TxtPrg)) items.add(TXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfWri comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTPRG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWznmVisExpstr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWznmVisExpstr");

			String itemtag = "StatitemAppDlgWznmVisExpstr";

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
	  * StatShr (full: StatShrDlgWznmVisExpstr)
	  */
	public class StatShr extends Block {

		public static final int BUTDNEACTIVE = 1;

		public StatShr(
					boolean ButDneActive
				) {
			this.ButDneActive = ButDneActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTDNEACTIVE));
		};

		public boolean ButDneActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmVisExpstr");

			String itemtag = "StatitemShrDlgWznmVisExpstr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButDneActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDneActive", mask, BUTDNEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButDneActive == comp.ButDneActive) items.add(BUTDNEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTDNEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrMfi (full: StatShrDlgWznmVisExpstrMfi)
	  */
	public class StatShrMfi extends Block {

		public static final int DLDACTIVE = 1;

		public StatShrMfi(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmVisExpstrMfi");

			String itemtag = "StatitemShrDlgWznmVisExpstrMfi";

			if (Xmlio.checkXPath(doc, basexpath)) {
				DldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DldActive", mask, DLDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrMfi comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (DldActive == comp.DldActive) items.add(DLDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrMfi comp
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
	  * StatShrWri (full: StatShrDlgWznmVisExpstrWri)
	  */
	public class StatShrWri extends Block {

		public static final int BUTRUNACTIVE = 1;
		public static final int BUTSTOACTIVE = 2;

		public StatShrWri(
					boolean ButRunActive
					, boolean ButStoActive
				) {
			this.ButRunActive = ButRunActive;
			this.ButStoActive = ButStoActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTRUNACTIVE, BUTSTOACTIVE));
		};

		public boolean ButRunActive;
		public boolean ButStoActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmVisExpstrWri");

			String itemtag = "StatitemShrDlgWznmVisExpstrWri";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButRunActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRunActive", mask, BUTRUNACTIVE);
				ButStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStoActive", mask, BUTSTOACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrWri comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButRunActive == comp.ButRunActive) items.add(BUTRUNACTIVE);
			if (ButStoActive == comp.ButStoActive) items.add(BUTSTOACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrWri comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTRUNACTIVE, BUTSTOACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWznmVisExpstr)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int BUTDNE = 2;

		public Tag(
					String Cpt
					, String ButDne
				) {
			this.Cpt = Cpt;
			this.ButDne = ButDne;

			mask = new HashSet<Integer>(Arrays.asList(CPT, BUTDNE));
		};

		public String Cpt;
		public String ButDne;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmVisExpstr");

			String itemtag = "TagitemDlgWznmVisExpstr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
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
			if (ButDne.equals(comp.ButDne)) items.add(BUTDNE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, BUTDNE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagMfi (full: TagDlgWznmVisExpstrMfi)
	  */
	public class TagMfi extends Block {

		public static final int DLD = 1;

		public TagMfi(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmVisExpstrMfi");

			String itemtag = "TagitemDlgWznmVisExpstrMfi";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Dld", mask, DLD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagMfi comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);

			return(items);
		};

		public HashSet<Integer> diff(
					TagMfi comp
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
	  * TagWri (full: TagDlgWznmVisExpstrWri)
	  */
	public class TagWri extends Block {

		public static final int CPTPRG = 1;
		public static final int BUTRUN = 2;
		public static final int BUTSTO = 3;

		public TagWri(
					String CptPrg
					, String ButRun
					, String ButSto
				) {
			this.CptPrg = CptPrg;
			this.ButRun = ButRun;
			this.ButSto = ButSto;

			mask = new HashSet<Integer>(Arrays.asList(CPTPRG, BUTRUN, BUTSTO));
		};

		public String CptPrg;
		public String ButRun;
		public String ButSto;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmVisExpstrWri");

			String itemtag = "TagitemDlgWznmVisExpstrWri";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrg", mask, CPTPRG);
				ButRun = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButRun", mask, BUTRUN);
				ButSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButSto", mask, BUTSTO);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagWri comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptPrg.equals(comp.CptPrg)) items.add(CPTPRG);
			if (ButRun.equals(comp.ButRun)) items.add(BUTRUN);
			if (ButSto.equals(comp.ButSto)) items.add(BUTSTO);

			return(items);
		};

		public HashSet<Integer> diff(
					TagWri comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPTPRG, BUTRUN, BUTSTO));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppDlgWznmVisExpstrData)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMVISEXPSTRDATA, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmVisExpstrData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmVisExpstrDo)
		*/
	public class DpchAppDo extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int IXVDO = 2;
		public static final int IXVDOWRI = 3;
		public static final int ALL = 4;

		public DpchAppDo(
					String scrJref
					, int ixVDo
					, int ixVDoWri
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPDLGWZNMVISEXPSTRDO, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, IXVDO, IXVDOWRI));
					break;
				};

			this.ixVDo = ixVDo;
			this.ixVDoWri = ixVDoWri;
		};

		public int ixVDo;
		public int ixVDoWri;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(IXVDO)) ss.add("ixVDo");
			if (has(IXVDOWRI)) ss.add("ixVDoWri");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppDlgWznmVisExpstrDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
			if (has(IXVDOWRI)) Xmlio.writeString(doc, el, "srefIxVDoWri", VecVDoWri.getSref(ixVDoWri));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWznmVisExpstrData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int CONTINFMFI = 4;
		public static final int CONTINFWRI = 5;
		public static final int FEEDFDSE = 6;
		public static final int FEEDFSGE = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int STATSHRMFI = 10;
		public static final int STATSHRWRI = 11;
		public static final int TAG = 12;
		public static final int TAGMFI = 13;
		public static final int TAGWRI = 14;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGDLGWZNMVISEXPSTRDATA);

			contiac = new ContIac(0);
			continf = new ContInf(0);
			continfmfi = new ContInfMfi("");
			continfwri = new ContInfWri("");
			feedFDse = new Feed("FeedFDse");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(false, "");
			statshr = new StatShr(false);
			statshrmfi = new StatShrMfi(false);
			statshrwri = new StatShrWri(false, false);
			tag = new Tag("", "");
			tagmfi = new TagMfi("");
			tagwri = new TagWri("", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public ContInfMfi continfmfi;
		public ContInfWri continfwri;
		public Feed feedFDse;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public StatShrMfi statshrmfi;
		public StatShrWri statshrwri;
		public Tag tag;
		public TagMfi tagmfi;
		public TagWri tagwri;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(CONTINFMFI)) ss.add("continfmfi");
			if (has(CONTINFWRI)) ss.add("continfwri");
			if (has(FEEDFDSE)) ss.add("feedFDse");
			if (has(FEEDFSGE)) ss.add("feedFSge");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STATSHRMFI)) ss.add("statshrmfi");
			if (has(STATSHRWRI)) ss.add("statshrwri");
			if (has(TAG)) ss.add("tag");
			if (has(TAGMFI)) ss.add("tagmfi");
			if (has(TAGWRI)) ss.add("tagwri");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWznmVisExpstrData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (continfmfi.readXML(doc, basexpath, true)) add(CONTINFMFI);
				if (continfwri.readXML(doc, basexpath, true)) add(CONTINFWRI);
				if (feedFDse.readXML(doc, basexpath, true)) add(FEEDFDSE);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (statshrmfi.readXML(doc, basexpath, true)) add(STATSHRMFI);
				if (statshrwri.readXML(doc, basexpath, true)) add(STATSHRWRI);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (tagmfi.readXML(doc, basexpath, true)) add(TAGMFI);
				if (tagwri.readXML(doc, basexpath, true)) add(TAGWRI);
			} else {
				scrJref = "";
				contiac = new ContIac(0);
				continf = new ContInf(0);
				continfmfi = new ContInfMfi("");
				continfwri = new ContInfWri("");
				feedFDse = new Feed("FeedFDse");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(false, "");
				statshr = new StatShr(false);
				statshrmfi = new StatShrMfi(false);
				statshrwri = new StatShrWri(false, false);
				tag = new Tag("", "");
				tagmfi = new TagMfi("");
				tagwri = new TagWri("", "", "");
			};
		};

	};

};
