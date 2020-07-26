/**
  * \file DlgWznmNavLoaini.java
  * Java API code for job DlgWznmNavLoaini
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWznmNavLoaini {
	/**
		* VecVDit (full: VecVDlgWznmNavLoainiDit)
		*/
	public static class VecVDit {

		public static final int IFI = 1;
		public static final int IMP = 2;
		public static final int ACV = 3;
		public static final int LFI = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("ifi")) return IFI;
			if (s.equals("imp")) return IMP;
			if (s.equals("acv")) return ACV;
			if (s.equals("lfi")) return LFI;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IFI) return("Ifi");
			if (ix == IMP) return("Imp");
			if (ix == ACV) return("Acv");
			if (ix == LFI) return("Lfi");

			return "";
		};

	};

	/**
		* VecVDo (full: VecVDlgWznmNavLoainiDo)
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
		* VecVDoImp (full: VecVDlgWznmNavLoainiDoImp)
		*/
	public static class VecVDoImp {

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
		* VecVSge (full: VecVDlgWznmNavLoainiSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int PRSIDLE = 2;
		public static final int PARSE = 3;
		public static final int ALRWZNMPER = 4;
		public static final int PRSDONE = 5;
		public static final int IMPIDLE = 6;
		public static final int IMPORT = 7;
		public static final int ALRWZNMIER = 8;
		public static final int IMPDONE = 9;
		public static final int UPKIDLE = 10;
		public static final int UNPACK = 11;
		public static final int DONE = 12;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("prsidle")) return PRSIDLE;
			if (s.equals("parse")) return PARSE;
			if (s.equals("alrwznmper")) return ALRWZNMPER;
			if (s.equals("prsdone")) return PRSDONE;
			if (s.equals("impidle")) return IMPIDLE;
			if (s.equals("import")) return IMPORT;
			if (s.equals("alrwznmier")) return ALRWZNMIER;
			if (s.equals("impdone")) return IMPDONE;
			if (s.equals("upkidle")) return UPKIDLE;
			if (s.equals("unpack")) return UNPACK;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == PRSIDLE) return("prsidle");
			if (ix == PARSE) return("parse");
			if (ix == ALRWZNMPER) return("alrwznmper");
			if (ix == PRSDONE) return("prsdone");
			if (ix == IMPIDLE) return("impidle");
			if (ix == IMPORT) return("import");
			if (ix == ALRWZNMIER) return("alrwznmier");
			if (ix == IMPDONE) return("impdone");
			if (ix == UPKIDLE) return("upkidle");
			if (ix == UNPACK) return("unpack");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWznmNavLoaini)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWznmNavLoaini");

			String itemtag = "ContitemIacDlgWznmNavLoaini";

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWznmNavLoaini";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWznmNavLoaini";

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
	  * ContInf (full: ContInfDlgWznmNavLoaini)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmNavLoaini");

			String itemtag = "ContitemInfDlgWznmNavLoaini";

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
	  * ContInfImp (full: ContInfDlgWznmNavLoainiImp)
	  */
	public class ContInfImp extends Block {

		public static final int TXTPRG = 1;

		public ContInfImp(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmNavLoainiImp");

			String itemtag = "ContitemInfDlgWznmNavLoainiImp";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrg", mask, TXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfImp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtPrg.equals(comp.TxtPrg)) items.add(TXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfImp comp
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
	  * ContInfLfi (full: ContInfDlgWznmNavLoainiLfi)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmNavLoainiLfi");

			String itemtag = "ContitemInfDlgWznmNavLoainiLfi";

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
	  * StatApp (full: StatAppDlgWznmNavLoaini)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWznmNavLoaini");

			String itemtag = "StatitemAppDlgWznmNavLoaini";

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
	  * StatShr (full: StatShrDlgWznmNavLoaini)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmNavLoaini");

			String itemtag = "StatitemShrDlgWznmNavLoaini";

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
	  * StatShrAcv (full: StatShrDlgWznmNavLoainiAcv)
	  */
	public class StatShrAcv extends Block {

		public static final int ULDACTIVE = 1;

		public StatShrAcv(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmNavLoainiAcv");

			String itemtag = "StatitemShrDlgWznmNavLoainiAcv";

			if (Xmlio.checkXPath(doc, basexpath)) {
				UldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UldActive", mask, ULDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrAcv comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (UldActive == comp.UldActive) items.add(ULDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrAcv comp
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
	  * StatShrIfi (full: StatShrDlgWznmNavLoainiIfi)
	  */
	public class StatShrIfi extends Block {

		public static final int ULDACTIVE = 1;

		public StatShrIfi(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmNavLoainiIfi");

			String itemtag = "StatitemShrDlgWznmNavLoainiIfi";

			if (Xmlio.checkXPath(doc, basexpath)) {
				UldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UldActive", mask, ULDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrIfi comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (UldActive == comp.UldActive) items.add(ULDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrIfi comp
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
	  * StatShrImp (full: StatShrDlgWznmNavLoainiImp)
	  */
	public class StatShrImp extends Block {

		public static final int BUTRUNACTIVE = 1;
		public static final int BUTSTOACTIVE = 2;

		public StatShrImp(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmNavLoainiImp");

			String itemtag = "StatitemShrDlgWznmNavLoainiImp";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButRunActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRunActive", mask, BUTRUNACTIVE);
				ButStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStoActive", mask, BUTSTOACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrImp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButRunActive == comp.ButRunActive) items.add(BUTRUNACTIVE);
			if (ButStoActive == comp.ButStoActive) items.add(BUTSTOACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrImp comp
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
	  * StatShrLfi (full: StatShrDlgWznmNavLoainiLfi)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmNavLoainiLfi");

			String itemtag = "StatitemShrDlgWznmNavLoainiLfi";

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
	  * Tag (full: TagDlgWznmNavLoaini)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmNavLoaini");

			String itemtag = "TagitemDlgWznmNavLoaini";

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
	  * TagAcv (full: TagDlgWznmNavLoainiAcv)
	  */
	public class TagAcv extends Block {

		public static final int ULD = 1;
		public static final int CPT = 2;

		public TagAcv(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmNavLoainiAcv");

			String itemtag = "TagitemDlgWznmNavLoainiAcv";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Uld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Uld", mask, ULD);
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagAcv comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Uld.equals(comp.Uld)) items.add(ULD);
			if (Cpt.equals(comp.Cpt)) items.add(CPT);

			return(items);
		};

		public HashSet<Integer> diff(
					TagAcv comp
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
	  * TagIfi (full: TagDlgWznmNavLoainiIfi)
	  */
	public class TagIfi extends Block {

		public static final int ULD = 1;
		public static final int CPT = 2;

		public TagIfi(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmNavLoainiIfi");

			String itemtag = "TagitemDlgWznmNavLoainiIfi";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Uld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Uld", mask, ULD);
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagIfi comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Uld.equals(comp.Uld)) items.add(ULD);
			if (Cpt.equals(comp.Cpt)) items.add(CPT);

			return(items);
		};

		public HashSet<Integer> diff(
					TagIfi comp
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
	  * TagImp (full: TagDlgWznmNavLoainiImp)
	  */
	public class TagImp extends Block {

		public static final int CPTPRG = 1;
		public static final int BUTRUN = 2;
		public static final int BUTSTO = 3;

		public TagImp(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmNavLoainiImp");

			String itemtag = "TagitemDlgWznmNavLoainiImp";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrg", mask, CPTPRG);
				ButRun = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButRun", mask, BUTRUN);
				ButSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButSto", mask, BUTSTO);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagImp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptPrg.equals(comp.CptPrg)) items.add(CPTPRG);
			if (ButRun.equals(comp.ButRun)) items.add(BUTRUN);
			if (ButSto.equals(comp.ButSto)) items.add(BUTSTO);

			return(items);
		};

		public HashSet<Integer> diff(
					TagImp comp
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
	  * TagLfi (full: TagDlgWznmNavLoainiLfi)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmNavLoainiLfi");

			String itemtag = "TagitemDlgWznmNavLoainiLfi";

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
		* DpchAppData (full: DpchAppDlgWznmNavLoainiData)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMNAVLOAINIDATA, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmNavLoainiData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmNavLoainiDo)
		*/
	public class DpchAppDo extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int IXVDO = 2;
		public static final int IXVDOIMP = 3;
		public static final int ALL = 4;

		public DpchAppDo(
					String scrJref
					, int ixVDo
					, int ixVDoImp
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPDLGWZNMNAVLOAINIDO, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, IXVDO, IXVDOIMP));
					break;
				};

			this.ixVDo = ixVDo;
			this.ixVDoImp = ixVDoImp;
		};

		public int ixVDo;
		public int ixVDoImp;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(IXVDO)) ss.add("ixVDo");
			if (has(IXVDOIMP)) ss.add("ixVDoImp");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppDlgWznmNavLoainiDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
			if (has(IXVDOIMP)) Xmlio.writeString(doc, el, "srefIxVDoImp", VecVDoImp.getSref(ixVDoImp));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWznmNavLoainiData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int CONTINFIMP = 4;
		public static final int CONTINFLFI = 5;
		public static final int FEEDFDSE = 6;
		public static final int FEEDFSGE = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int STATSHRACV = 10;
		public static final int STATSHRIFI = 11;
		public static final int STATSHRIMP = 12;
		public static final int STATSHRLFI = 13;
		public static final int TAG = 14;
		public static final int TAGACV = 15;
		public static final int TAGIFI = 16;
		public static final int TAGIMP = 17;
		public static final int TAGLFI = 18;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGDLGWZNMNAVLOAINIDATA);

			contiac = new ContIac(0);
			continf = new ContInf(0);
			continfimp = new ContInfImp("");
			continflfi = new ContInfLfi("");
			feedFDse = new Feed("FeedFDse");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(false, "");
			statshr = new StatShr(false);
			statshracv = new StatShrAcv(false);
			statshrifi = new StatShrIfi(false);
			statshrimp = new StatShrImp(false, false);
			statshrlfi = new StatShrLfi(false);
			tag = new Tag("", "");
			tagacv = new TagAcv("", "");
			tagifi = new TagIfi("", "");
			tagimp = new TagImp("", "", "");
			taglfi = new TagLfi("");
		};

		public ContIac contiac;
		public ContInf continf;
		public ContInfImp continfimp;
		public ContInfLfi continflfi;
		public Feed feedFDse;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public StatShrAcv statshracv;
		public StatShrIfi statshrifi;
		public StatShrImp statshrimp;
		public StatShrLfi statshrlfi;
		public Tag tag;
		public TagAcv tagacv;
		public TagIfi tagifi;
		public TagImp tagimp;
		public TagLfi taglfi;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(CONTINFIMP)) ss.add("continfimp");
			if (has(CONTINFLFI)) ss.add("continflfi");
			if (has(FEEDFDSE)) ss.add("feedFDse");
			if (has(FEEDFSGE)) ss.add("feedFSge");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STATSHRACV)) ss.add("statshracv");
			if (has(STATSHRIFI)) ss.add("statshrifi");
			if (has(STATSHRIMP)) ss.add("statshrimp");
			if (has(STATSHRLFI)) ss.add("statshrlfi");
			if (has(TAG)) ss.add("tag");
			if (has(TAGACV)) ss.add("tagacv");
			if (has(TAGIFI)) ss.add("tagifi");
			if (has(TAGIMP)) ss.add("tagimp");
			if (has(TAGLFI)) ss.add("taglfi");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWznmNavLoainiData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (continfimp.readXML(doc, basexpath, true)) add(CONTINFIMP);
				if (continflfi.readXML(doc, basexpath, true)) add(CONTINFLFI);
				if (feedFDse.readXML(doc, basexpath, true)) add(FEEDFDSE);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (statshracv.readXML(doc, basexpath, true)) add(STATSHRACV);
				if (statshrifi.readXML(doc, basexpath, true)) add(STATSHRIFI);
				if (statshrimp.readXML(doc, basexpath, true)) add(STATSHRIMP);
				if (statshrlfi.readXML(doc, basexpath, true)) add(STATSHRLFI);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (tagacv.readXML(doc, basexpath, true)) add(TAGACV);
				if (tagifi.readXML(doc, basexpath, true)) add(TAGIFI);
				if (tagimp.readXML(doc, basexpath, true)) add(TAGIMP);
				if (taglfi.readXML(doc, basexpath, true)) add(TAGLFI);
			} else {
				scrJref = "";
				contiac = new ContIac(0);
				continf = new ContInf(0);
				continfimp = new ContInfImp("");
				continflfi = new ContInfLfi("");
				feedFDse = new Feed("FeedFDse");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(false, "");
				statshr = new StatShr(false);
				statshracv = new StatShrAcv(false);
				statshrifi = new StatShrIfi(false);
				statshrimp = new StatShrImp(false, false);
				statshrlfi = new StatShrLfi(false);
				tag = new Tag("", "");
				tagacv = new TagAcv("", "");
				tagifi = new TagIfi("", "");
				tagimp = new TagImp("", "", "");
				taglfi = new TagLfi("");
			};
		};

	};

};

