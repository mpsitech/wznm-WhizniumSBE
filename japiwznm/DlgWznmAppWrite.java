/**
  * \file DlgWznmAppWrite.java
  * Java API code for job DlgWznmAppWrite
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWznmAppWrite {
	/**
		* VecVDit (full: VecVDlgWznmAppWriteDit)
		*/
	public static class VecVDit {

		public static final int DET = 1;
		public static final int CUC = 2;
		public static final int WRC = 3;
		public static final int LFI = 4;
		public static final int FIA = 5;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("det")) return DET;
			if (s.equals("cuc")) return CUC;
			if (s.equals("wrc")) return WRC;
			if (s.equals("lfi")) return LFI;
			if (s.equals("fia")) return FIA;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == DET) return("Det");
			if (ix == CUC) return("Cuc");
			if (ix == WRC) return("Wrc");
			if (ix == LFI) return("Lfi");
			if (ix == FIA) return("Fia");

			return "";
		};

	};

	/**
		* VecVDo (full: VecVDlgWznmAppWriteDo)
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
		* VecVDoWrc (full: VecVDlgWznmAppWriteDoWrc)
		*/
	public static class VecVDoWrc {

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
		* VecVSge (full: VecVDlgWznmAppWriteSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRMER = 2;
		public static final int UPKIDLE = 3;
		public static final int UNPACK = 4;
		public static final int UPKDONE = 5;
		public static final int WRITE = 6;
		public static final int MRGGNR = 7;
		public static final int MRGCUST = 8;
		public static final int PACK = 9;
		public static final int FAIL = 10;
		public static final int DONE = 11;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alrmer")) return ALRMER;
			if (s.equals("upkidle")) return UPKIDLE;
			if (s.equals("unpack")) return UNPACK;
			if (s.equals("upkdone")) return UPKDONE;
			if (s.equals("write")) return WRITE;
			if (s.equals("mrggnr")) return MRGGNR;
			if (s.equals("mrgcust")) return MRGCUST;
			if (s.equals("pack")) return PACK;
			if (s.equals("fail")) return FAIL;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == ALRMER) return("alrmer");
			if (ix == UPKIDLE) return("upkidle");
			if (ix == UNPACK) return("unpack");
			if (ix == UPKDONE) return("upkdone");
			if (ix == WRITE) return("write");
			if (ix == MRGGNR) return("mrggnr");
			if (ix == MRGCUST) return("mrgcust");
			if (ix == PACK) return("pack");
			if (ix == FAIL) return("fail");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWznmAppWrite)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWznmAppWrite");

			String itemtag = "ContitemIacDlgWznmAppWrite";

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWznmAppWrite";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWznmAppWrite";

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
	  * ContIacDet (full: ContIacDlgWznmAppWriteDet)
	  */
	public class ContIacDet extends Block {

		public static final int CHKUSF = 1;

		public ContIacDet(
					boolean ChkUsf
				) {
			this.ChkUsf = ChkUsf;

			mask = new HashSet<Integer>(Arrays.asList(CHKUSF));
		};

		public boolean ChkUsf;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWznmAppWriteDet");

			String itemtag = "ContitemIacDlgWznmAppWriteDet";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ChkUsf = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkUsf", mask, CHKUSF);

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWznmAppWriteDet";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWznmAppWriteDet";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkUsf", ChkUsf);
		};

		public HashSet<Integer> comm(
					ContIacDet comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ChkUsf == comp.ChkUsf) items.add(CHKUSF);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIacDet comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CHKUSF));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfDlgWznmAppWrite)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmAppWrite");

			String itemtag = "ContitemInfDlgWznmAppWrite";

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
	  * ContInfFia (full: ContInfDlgWznmAppWriteFia)
	  */
	public class ContInfFia extends Block {

		public static final int DLD = 1;

		public ContInfFia(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmAppWriteFia");

			String itemtag = "ContitemInfDlgWznmAppWriteFia";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Dld", mask, DLD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfFia comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfFia comp
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
	  * ContInfLfi (full: ContInfDlgWznmAppWriteLfi)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmAppWriteLfi");

			String itemtag = "ContitemInfDlgWznmAppWriteLfi";

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
	  * ContInfWrc (full: ContInfDlgWznmAppWriteWrc)
	  */
	public class ContInfWrc extends Block {

		public static final int TXTPRG = 1;

		public ContInfWrc(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmAppWriteWrc");

			String itemtag = "ContitemInfDlgWznmAppWriteWrc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrg", mask, TXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfWrc comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtPrg.equals(comp.TxtPrg)) items.add(TXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfWrc comp
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
	  * StatApp (full: StatAppDlgWznmAppWrite)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWznmAppWrite");

			String itemtag = "StatitemAppDlgWznmAppWrite";

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
	  * StatShr (full: StatShrDlgWznmAppWrite)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmAppWrite");

			String itemtag = "StatitemShrDlgWznmAppWrite";

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
	  * StatShrCuc (full: StatShrDlgWznmAppWriteCuc)
	  */
	public class StatShrCuc extends Block {

		public static final int ULDACTIVE = 1;

		public StatShrCuc(
					boolean UldActive
				) {
			this.UldActive = UldActive;

			mask = new HashSet<Integer>(Arrays.asList(ULDACTIVE));
		};

		public boolean UldActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmAppWriteCuc");

			String itemtag = "StatitemShrDlgWznmAppWriteCuc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				UldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UldActive", mask, ULDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrCuc comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (UldActive == comp.UldActive) items.add(ULDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrCuc comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(ULDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrFia (full: StatShrDlgWznmAppWriteFia)
	  */
	public class StatShrFia extends Block {

		public static final int DLDACTIVE = 1;

		public StatShrFia(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmAppWriteFia");

			String itemtag = "StatitemShrDlgWznmAppWriteFia";

			if (Xmlio.checkXPath(doc, basexpath)) {
				DldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DldActive", mask, DLDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrFia comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (DldActive == comp.DldActive) items.add(DLDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrFia comp
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
	  * StatShrLfi (full: StatShrDlgWznmAppWriteLfi)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmAppWriteLfi");

			String itemtag = "StatitemShrDlgWznmAppWriteLfi";

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
	  * StatShrWrc (full: StatShrDlgWznmAppWriteWrc)
	  */
	public class StatShrWrc extends Block {

		public static final int BUTRUNACTIVE = 1;
		public static final int BUTSTOACTIVE = 2;

		public StatShrWrc(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmAppWriteWrc");

			String itemtag = "StatitemShrDlgWznmAppWriteWrc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButRunActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRunActive", mask, BUTRUNACTIVE);
				ButStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStoActive", mask, BUTSTOACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrWrc comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButRunActive == comp.ButRunActive) items.add(BUTRUNACTIVE);
			if (ButStoActive == comp.ButStoActive) items.add(BUTSTOACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrWrc comp
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
	  * Tag (full: TagDlgWznmAppWrite)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmAppWrite");

			String itemtag = "TagitemDlgWznmAppWrite";

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
	  * TagCuc (full: TagDlgWznmAppWriteCuc)
	  */
	public class TagCuc extends Block {

		public static final int ULD = 1;
		public static final int CPT = 2;

		public TagCuc(
					String Uld
					, String Cpt
				) {
			this.Uld = Uld;
			this.Cpt = Cpt;

			mask = new HashSet<Integer>(Arrays.asList(ULD, CPT));
		};

		public String Uld;
		public String Cpt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmAppWriteCuc");

			String itemtag = "TagitemDlgWznmAppWriteCuc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Uld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Uld", mask, ULD);
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagCuc comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Uld.equals(comp.Uld)) items.add(ULD);
			if (Cpt.equals(comp.Cpt)) items.add(CPT);

			return(items);
		};

		public HashSet<Integer> diff(
					TagCuc comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(ULD, CPT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagDet (full: TagDlgWznmAppWriteDet)
	  */
	public class TagDet extends Block {

		public static final int CPTUSF = 1;

		public TagDet(
					String CptUsf
				) {
			this.CptUsf = CptUsf;

			mask = new HashSet<Integer>(Arrays.asList(CPTUSF));
		};

		public String CptUsf;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmAppWriteDet");

			String itemtag = "TagitemDlgWznmAppWriteDet";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptUsf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUsf", mask, CPTUSF);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagDet comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptUsf.equals(comp.CptUsf)) items.add(CPTUSF);

			return(items);
		};

		public HashSet<Integer> diff(
					TagDet comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPTUSF));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagFia (full: TagDlgWznmAppWriteFia)
	  */
	public class TagFia extends Block {

		public static final int DLD = 1;

		public TagFia(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmAppWriteFia");

			String itemtag = "TagitemDlgWznmAppWriteFia";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Dld", mask, DLD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagFia comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);

			return(items);
		};

		public HashSet<Integer> diff(
					TagFia comp
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
	  * TagLfi (full: TagDlgWznmAppWriteLfi)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmAppWriteLfi");

			String itemtag = "TagitemDlgWznmAppWriteLfi";

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
	  * TagWrc (full: TagDlgWznmAppWriteWrc)
	  */
	public class TagWrc extends Block {

		public static final int CPTPRG = 1;
		public static final int BUTRUN = 2;
		public static final int BUTSTO = 3;

		public TagWrc(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmAppWriteWrc");

			String itemtag = "TagitemDlgWznmAppWriteWrc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrg", mask, CPTPRG);
				ButRun = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButRun", mask, BUTRUN);
				ButSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButSto", mask, BUTSTO);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagWrc comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptPrg.equals(comp.CptPrg)) items.add(CPTPRG);
			if (ButRun.equals(comp.ButRun)) items.add(BUTRUN);
			if (ButSto.equals(comp.ButSto)) items.add(BUTSTO);

			return(items);
		};

		public HashSet<Integer> diff(
					TagWrc comp
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
		* DpchAppData (full: DpchAppDlgWznmAppWriteData)
		*/
	public class DpchAppData extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTIACDET = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, ContIac contiac
					, ContIacDet contiacdet
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPDLGWZNMAPPWRITEDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIAC, CONTIACDET));
					break;
				};

			if (has(CONTIAC)) this.contiac = contiac;
			if (has(CONTIACDET)) this.contiacdet = contiacdet;
		};

		public ContIac contiac;
		public ContIacDet contiacdet;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTIACDET)) ss.add("contiacdet");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppDlgWznmAppWriteData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
			if (has(CONTIACDET)) contiacdet.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmAppWriteDo)
		*/
	public class DpchAppDo extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int IXVDO = 2;
		public static final int IXVDOWRC = 3;
		public static final int ALL = 4;

		public DpchAppDo(
					String scrJref
					, int ixVDo
					, int ixVDoWrc
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPDLGWZNMAPPWRITEDO, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, IXVDO, IXVDOWRC));
					break;
				};

			this.ixVDo = ixVDo;
			this.ixVDoWrc = ixVDoWrc;
		};

		public int ixVDo;
		public int ixVDoWrc;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(IXVDO)) ss.add("ixVDo");
			if (has(IXVDOWRC)) ss.add("ixVDoWrc");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppDlgWznmAppWriteDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
			if (has(IXVDOWRC)) Xmlio.writeString(doc, el, "srefIxVDoWrc", VecVDoWrc.getSref(ixVDoWrc));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWznmAppWriteData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTIACDET = 3;
		public static final int CONTINF = 4;
		public static final int CONTINFFIA = 5;
		public static final int CONTINFLFI = 6;
		public static final int CONTINFWRC = 7;
		public static final int FEEDFDSE = 8;
		public static final int FEEDFSGE = 9;
		public static final int STATAPP = 10;
		public static final int STATSHR = 11;
		public static final int STATSHRCUC = 12;
		public static final int STATSHRFIA = 13;
		public static final int STATSHRLFI = 14;
		public static final int STATSHRWRC = 15;
		public static final int TAG = 16;
		public static final int TAGCUC = 17;
		public static final int TAGDET = 18;
		public static final int TAGFIA = 19;
		public static final int TAGLFI = 20;
		public static final int TAGWRC = 21;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGDLGWZNMAPPWRITEDATA);

			contiac = new ContIac(0);
			contiacdet = new ContIacDet(false);
			continf = new ContInf(0);
			continffia = new ContInfFia("");
			continflfi = new ContInfLfi("");
			continfwrc = new ContInfWrc("");
			feedFDse = new Feed("FeedFDse");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(false, "");
			statshr = new StatShr(false);
			statshrcuc = new StatShrCuc(false);
			statshrfia = new StatShrFia(false);
			statshrlfi = new StatShrLfi(false);
			statshrwrc = new StatShrWrc(false, false);
			tag = new Tag("", "");
			tagcuc = new TagCuc("", "");
			tagdet = new TagDet("");
			tagfia = new TagFia("");
			taglfi = new TagLfi("");
			tagwrc = new TagWrc("", "", "");
		};

		public ContIac contiac;
		public ContIacDet contiacdet;
		public ContInf continf;
		public ContInfFia continffia;
		public ContInfLfi continflfi;
		public ContInfWrc continfwrc;
		public Feed feedFDse;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public StatShrCuc statshrcuc;
		public StatShrFia statshrfia;
		public StatShrLfi statshrlfi;
		public StatShrWrc statshrwrc;
		public Tag tag;
		public TagCuc tagcuc;
		public TagDet tagdet;
		public TagFia tagfia;
		public TagLfi taglfi;
		public TagWrc tagwrc;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTIACDET)) ss.add("contiacdet");
			if (has(CONTINF)) ss.add("continf");
			if (has(CONTINFFIA)) ss.add("continffia");
			if (has(CONTINFLFI)) ss.add("continflfi");
			if (has(CONTINFWRC)) ss.add("continfwrc");
			if (has(FEEDFDSE)) ss.add("feedFDse");
			if (has(FEEDFSGE)) ss.add("feedFSge");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STATSHRCUC)) ss.add("statshrcuc");
			if (has(STATSHRFIA)) ss.add("statshrfia");
			if (has(STATSHRLFI)) ss.add("statshrlfi");
			if (has(STATSHRWRC)) ss.add("statshrwrc");
			if (has(TAG)) ss.add("tag");
			if (has(TAGCUC)) ss.add("tagcuc");
			if (has(TAGDET)) ss.add("tagdet");
			if (has(TAGFIA)) ss.add("tagfia");
			if (has(TAGLFI)) ss.add("taglfi");
			if (has(TAGWRC)) ss.add("tagwrc");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWznmAppWriteData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (contiacdet.readXML(doc, basexpath, true)) add(CONTIACDET);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (continffia.readXML(doc, basexpath, true)) add(CONTINFFIA);
				if (continflfi.readXML(doc, basexpath, true)) add(CONTINFLFI);
				if (continfwrc.readXML(doc, basexpath, true)) add(CONTINFWRC);
				if (feedFDse.readXML(doc, basexpath, true)) add(FEEDFDSE);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (statshrcuc.readXML(doc, basexpath, true)) add(STATSHRCUC);
				if (statshrfia.readXML(doc, basexpath, true)) add(STATSHRFIA);
				if (statshrlfi.readXML(doc, basexpath, true)) add(STATSHRLFI);
				if (statshrwrc.readXML(doc, basexpath, true)) add(STATSHRWRC);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (tagcuc.readXML(doc, basexpath, true)) add(TAGCUC);
				if (tagdet.readXML(doc, basexpath, true)) add(TAGDET);
				if (tagfia.readXML(doc, basexpath, true)) add(TAGFIA);
				if (taglfi.readXML(doc, basexpath, true)) add(TAGLFI);
				if (tagwrc.readXML(doc, basexpath, true)) add(TAGWRC);
			} else {
				scrJref = "";
				contiac = new ContIac(0);
				contiacdet = new ContIacDet(false);
				continf = new ContInf(0);
				continffia = new ContInfFia("");
				continflfi = new ContInfLfi("");
				continfwrc = new ContInfWrc("");
				feedFDse = new Feed("FeedFDse");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(false, "");
				statshr = new StatShr(false);
				statshrcuc = new StatShrCuc(false);
				statshrfia = new StatShrFia(false);
				statshrlfi = new StatShrLfi(false);
				statshrwrc = new StatShrWrc(false, false);
				tag = new Tag("", "");
				tagcuc = new TagCuc("", "");
				tagdet = new TagDet("");
				tagfia = new TagFia("");
				taglfi = new TagLfi("");
				tagwrc = new TagWrc("", "", "");
			};
		};

	};

};

