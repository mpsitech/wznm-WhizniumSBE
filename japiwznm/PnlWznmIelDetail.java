/**
  * \file PnlWznmIelDetail.java
  * Java API code for job PnlWznmIelDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmIelDetail {
	/**
		* VecVDo (full: VecVWznmIelDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTIMEVIEWCLICK = 2;
		public static final int BUTIM2VIEWCLICK = 3;
		public static final int BUTPSTVIEWCLICK = 4;
		public static final int BUTSTBVIEWCLICK = 5;
		public static final int BUTVITVIEWCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butimeviewclick")) return BUTIMEVIEWCLICK;
			if (s.equals("butim2viewclick")) return BUTIM2VIEWCLICK;
			if (s.equals("butpstviewclick")) return BUTPSTVIEWCLICK;
			if (s.equals("butstbviewclick")) return BUTSTBVIEWCLICK;
			if (s.equals("butvitviewclick")) return BUTVITVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTIMEVIEWCLICK) return("ButImeViewClick");
			if (ix == BUTIM2VIEWCLICK) return("ButIm2ViewClick");
			if (ix == BUTPSTVIEWCLICK) return("ButPstViewClick");
			if (ix == BUTSTBVIEWCLICK) return("ButStbViewClick");
			if (ix == BUTVITVIEWCLICK) return("ButVitViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmIelDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFSHO = 1;
		public static final int NUMFPUPTYP = 2;
		public static final int NUMSFLSTOCC = 3;
		public static final int NUMFPUPCTY = 4;
		public static final int TXFDFV = 5;

		public ContIac(
					String TxfSho
					, int numFPupTyp
					, ArrayList<Integer> numsFLstOcc
					, int numFPupCty
					, String TxfDfv
				) {
			this.TxfSho = TxfSho;
			this.numFPupTyp = numFPupTyp;
			this.numsFLstOcc = numsFLstOcc;
			this.numFPupCty = numFPupCty;
			this.TxfDfv = TxfDfv;

			mask = new HashSet<Integer>(Arrays.asList(TXFSHO, NUMFPUPTYP, NUMSFLSTOCC, NUMFPUPCTY, TXFDFV));
		};

		public String TxfSho;
		public int numFPupTyp;
		public ArrayList<Integer> numsFLstOcc;
		public int numFPupCty;
		public String TxfDfv;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmIelDetail");

			String itemtag = "ContitemIacWznmIelDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSho", mask, TXFSHO);
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				numsFLstOcc = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstOcc", mask, NUMSFLSTOCC);
				numFPupCty = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupCty", mask, NUMFPUPCTY);
				TxfDfv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfDfv", mask, TXFDFV);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmIelDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmIelDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSho", TxfSho);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstOcc", numsFLstOcc);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupCty", numFPupCty);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfDfv", TxfDfv);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfSho.equals(comp.TxfSho)) items.add(TXFSHO);
			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (Xmlio.compareIntegervec(numsFLstOcc, comp.numsFLstOcc)) items.add(NUMSFLSTOCC);
			if (numFPupCty == comp.numFPupCty) items.add(NUMFPUPCTY);
			if (TxfDfv.equals(comp.TxfDfv)) items.add(TXFDFV);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFSHO, NUMFPUPTYP, NUMSFLSTOCC, NUMFPUPCTY, TXFDFV));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmIelDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTOCC = 2;
		public static final int TXTIME = 3;
		public static final int TXTTCO = 4;
		public static final int TXTIM2 = 5;
		public static final int TXTPST = 6;
		public static final int TXTSTB = 7;
		public static final int TXTVIT = 8;

		public ContInf(
					String TxtSrf
					, String TxtOcc
					, String TxtIme
					, String TxtTco
					, String TxtIm2
					, String TxtPst
					, String TxtStb
					, String TxtVit
				) {
			this.TxtSrf = TxtSrf;
			this.TxtOcc = TxtOcc;
			this.TxtIme = TxtIme;
			this.TxtTco = TxtTco;
			this.TxtIm2 = TxtIm2;
			this.TxtPst = TxtPst;
			this.TxtStb = TxtStb;
			this.TxtVit = TxtVit;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTOCC, TXTIME, TXTTCO, TXTIM2, TXTPST, TXTSTB, TXTVIT));
		};

		public String TxtSrf;
		public String TxtOcc;
		public String TxtIme;
		public String TxtTco;
		public String TxtIm2;
		public String TxtPst;
		public String TxtStb;
		public String TxtVit;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmIelDetail");

			String itemtag = "ContitemInfWznmIelDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtOcc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtOcc", mask, TXTOCC);
				TxtIme = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtIme", mask, TXTIME);
				TxtTco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTco", mask, TXTTCO);
				TxtIm2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtIm2", mask, TXTIM2);
				TxtPst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPst", mask, TXTPST);
				TxtStb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtStb", mask, TXTSTB);
				TxtVit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVit", mask, TXTVIT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtOcc.equals(comp.TxtOcc)) items.add(TXTOCC);
			if (TxtIme.equals(comp.TxtIme)) items.add(TXTIME);
			if (TxtTco.equals(comp.TxtTco)) items.add(TXTTCO);
			if (TxtIm2.equals(comp.TxtIm2)) items.add(TXTIM2);
			if (TxtPst.equals(comp.TxtPst)) items.add(TXTPST);
			if (TxtStb.equals(comp.TxtStb)) items.add(TXTSTB);
			if (TxtVit.equals(comp.TxtVit)) items.add(TXTVIT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTOCC, TXTIME, TXTTCO, TXTIM2, TXTPST, TXTSTB, TXTVIT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmIelDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTOCCALT = 2;
		public static final int LSTOCCNUMFIRSTDISP = 3;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstOccAlt
					, int LstOccNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstOccAlt = LstOccAlt;
			this.LstOccNumFirstdisp = LstOccNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTOCCALT, LSTOCCNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstOccAlt;
		public int LstOccNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmIelDetail");

			String itemtag = "StatitemAppWznmIelDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstOccAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOccAlt", mask, LSTOCCALT);
				LstOccNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOccNumFirstdisp", mask, LSTOCCNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstOccAlt == comp.LstOccAlt) items.add(LSTOCCALT);
			if (LstOccNumFirstdisp == comp.LstOccNumFirstdisp) items.add(LSTOCCNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTOCCALT, LSTOCCNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmIelDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int TXFSHOACTIVE = 4;
		public static final int PUPTYPACTIVE = 5;
		public static final int LSTOCCACTIVE = 6;
		public static final int TXTIMEACTIVE = 7;
		public static final int BUTIMEVIEWAVAIL = 8;
		public static final int BUTIMEVIEWACTIVE = 9;
		public static final int TXTTCOACTIVE = 10;
		public static final int TXTIM2ACTIVE = 11;
		public static final int BUTIM2VIEWAVAIL = 12;
		public static final int BUTIM2VIEWACTIVE = 13;
		public static final int PUPCTYACTIVE = 14;
		public static final int TXFDFVACTIVE = 15;
		public static final int TXTPSTACTIVE = 16;
		public static final int BUTPSTVIEWAVAIL = 17;
		public static final int BUTPSTVIEWACTIVE = 18;
		public static final int TXTSTBACTIVE = 19;
		public static final int BUTSTBVIEWAVAIL = 20;
		public static final int BUTSTBVIEWACTIVE = 21;
		public static final int TXTVITACTIVE = 22;
		public static final int BUTVITVIEWAVAIL = 23;
		public static final int BUTVITVIEWACTIVE = 24;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxfShoActive
					, boolean PupTypActive
					, boolean LstOccActive
					, boolean TxtImeActive
					, boolean ButImeViewAvail
					, boolean ButImeViewActive
					, boolean TxtTcoActive
					, boolean TxtIm2Active
					, boolean ButIm2ViewAvail
					, boolean ButIm2ViewActive
					, boolean PupCtyActive
					, boolean TxfDfvActive
					, boolean TxtPstActive
					, boolean ButPstViewAvail
					, boolean ButPstViewActive
					, boolean TxtStbActive
					, boolean ButStbViewAvail
					, boolean ButStbViewActive
					, boolean TxtVitActive
					, boolean ButVitViewAvail
					, boolean ButVitViewActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxfShoActive = TxfShoActive;
			this.PupTypActive = PupTypActive;
			this.LstOccActive = LstOccActive;
			this.TxtImeActive = TxtImeActive;
			this.ButImeViewAvail = ButImeViewAvail;
			this.ButImeViewActive = ButImeViewActive;
			this.TxtTcoActive = TxtTcoActive;
			this.TxtIm2Active = TxtIm2Active;
			this.ButIm2ViewAvail = ButIm2ViewAvail;
			this.ButIm2ViewActive = ButIm2ViewActive;
			this.PupCtyActive = PupCtyActive;
			this.TxfDfvActive = TxfDfvActive;
			this.TxtPstActive = TxtPstActive;
			this.ButPstViewAvail = ButPstViewAvail;
			this.ButPstViewActive = ButPstViewActive;
			this.TxtStbActive = TxtStbActive;
			this.ButStbViewAvail = ButStbViewAvail;
			this.ButStbViewActive = ButStbViewActive;
			this.TxtVitActive = TxtVitActive;
			this.ButVitViewAvail = ButVitViewAvail;
			this.ButVitViewActive = ButVitViewActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, LSTOCCACTIVE, TXTIMEACTIVE, BUTIMEVIEWAVAIL, BUTIMEVIEWACTIVE, TXTTCOACTIVE, TXTIM2ACTIVE, BUTIM2VIEWAVAIL, BUTIM2VIEWACTIVE, PUPCTYACTIVE, TXFDFVACTIVE, TXTPSTACTIVE, BUTPSTVIEWAVAIL, BUTPSTVIEWACTIVE, TXTSTBACTIVE, BUTSTBVIEWAVAIL, BUTSTBVIEWACTIVE, TXTVITACTIVE, BUTVITVIEWAVAIL, BUTVITVIEWACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxfShoActive;
		public boolean PupTypActive;
		public boolean LstOccActive;
		public boolean TxtImeActive;
		public boolean ButImeViewAvail;
		public boolean ButImeViewActive;
		public boolean TxtTcoActive;
		public boolean TxtIm2Active;
		public boolean ButIm2ViewAvail;
		public boolean ButIm2ViewActive;
		public boolean PupCtyActive;
		public boolean TxfDfvActive;
		public boolean TxtPstActive;
		public boolean ButPstViewAvail;
		public boolean ButPstViewActive;
		public boolean TxtStbActive;
		public boolean ButStbViewAvail;
		public boolean ButStbViewActive;
		public boolean TxtVitActive;
		public boolean ButVitViewAvail;
		public boolean ButVitViewActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmIelDetail");

			String itemtag = "StatitemShrWznmIelDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxfShoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfShoActive", mask, TXFSHOACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				LstOccActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOccActive", mask, LSTOCCACTIVE);
				TxtImeActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtImeActive", mask, TXTIMEACTIVE);
				ButImeViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButImeViewAvail", mask, BUTIMEVIEWAVAIL);
				ButImeViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButImeViewActive", mask, BUTIMEVIEWACTIVE);
				TxtTcoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTcoActive", mask, TXTTCOACTIVE);
				TxtIm2Active = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtIm2Active", mask, TXTIM2ACTIVE);
				ButIm2ViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButIm2ViewAvail", mask, BUTIM2VIEWAVAIL);
				ButIm2ViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButIm2ViewActive", mask, BUTIM2VIEWACTIVE);
				PupCtyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupCtyActive", mask, PUPCTYACTIVE);
				TxfDfvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfDfvActive", mask, TXFDFVACTIVE);
				TxtPstActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPstActive", mask, TXTPSTACTIVE);
				ButPstViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPstViewAvail", mask, BUTPSTVIEWAVAIL);
				ButPstViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPstViewActive", mask, BUTPSTVIEWACTIVE);
				TxtStbActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtStbActive", mask, TXTSTBACTIVE);
				ButStbViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStbViewAvail", mask, BUTSTBVIEWAVAIL);
				ButStbViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStbViewActive", mask, BUTSTBVIEWACTIVE);
				TxtVitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVitActive", mask, TXTVITACTIVE);
				ButVitViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVitViewAvail", mask, BUTVITVIEWAVAIL);
				ButVitViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVitViewActive", mask, BUTVITVIEWACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (TxfShoActive == comp.TxfShoActive) items.add(TXFSHOACTIVE);
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (LstOccActive == comp.LstOccActive) items.add(LSTOCCACTIVE);
			if (TxtImeActive == comp.TxtImeActive) items.add(TXTIMEACTIVE);
			if (ButImeViewAvail == comp.ButImeViewAvail) items.add(BUTIMEVIEWAVAIL);
			if (ButImeViewActive == comp.ButImeViewActive) items.add(BUTIMEVIEWACTIVE);
			if (TxtTcoActive == comp.TxtTcoActive) items.add(TXTTCOACTIVE);
			if (TxtIm2Active == comp.TxtIm2Active) items.add(TXTIM2ACTIVE);
			if (ButIm2ViewAvail == comp.ButIm2ViewAvail) items.add(BUTIM2VIEWAVAIL);
			if (ButIm2ViewActive == comp.ButIm2ViewActive) items.add(BUTIM2VIEWACTIVE);
			if (PupCtyActive == comp.PupCtyActive) items.add(PUPCTYACTIVE);
			if (TxfDfvActive == comp.TxfDfvActive) items.add(TXFDFVACTIVE);
			if (TxtPstActive == comp.TxtPstActive) items.add(TXTPSTACTIVE);
			if (ButPstViewAvail == comp.ButPstViewAvail) items.add(BUTPSTVIEWAVAIL);
			if (ButPstViewActive == comp.ButPstViewActive) items.add(BUTPSTVIEWACTIVE);
			if (TxtStbActive == comp.TxtStbActive) items.add(TXTSTBACTIVE);
			if (ButStbViewAvail == comp.ButStbViewAvail) items.add(BUTSTBVIEWAVAIL);
			if (ButStbViewActive == comp.ButStbViewActive) items.add(BUTSTBVIEWACTIVE);
			if (TxtVitActive == comp.TxtVitActive) items.add(TXTVITACTIVE);
			if (ButVitViewAvail == comp.ButVitViewAvail) items.add(BUTVITVIEWAVAIL);
			if (ButVitViewActive == comp.ButVitViewActive) items.add(BUTVITVIEWACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, LSTOCCACTIVE, TXTIMEACTIVE, BUTIMEVIEWAVAIL, BUTIMEVIEWACTIVE, TXTTCOACTIVE, TXTIM2ACTIVE, BUTIM2VIEWAVAIL, BUTIM2VIEWACTIVE, PUPCTYACTIVE, TXFDFVACTIVE, TXTPSTACTIVE, BUTPSTVIEWAVAIL, BUTPSTVIEWACTIVE, TXTSTBACTIVE, BUTSTBVIEWAVAIL, BUTSTBVIEWACTIVE, TXTVITACTIVE, BUTVITVIEWAVAIL, BUTVITVIEWACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmIelDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTSHO = 3;
		public static final int CPTTYP = 4;
		public static final int CPTOCC = 5;
		public static final int CPTIME = 6;
		public static final int CPTTCO = 7;
		public static final int CPTIM2 = 8;
		public static final int CPTCTY = 9;
		public static final int CPTDFV = 10;
		public static final int CPTPST = 11;
		public static final int CPTSTB = 12;
		public static final int CPTVIT = 13;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptSho
					, String CptTyp
					, String CptOcc
					, String CptIme
					, String CptTco
					, String CptIm2
					, String CptCty
					, String CptDfv
					, String CptPst
					, String CptStb
					, String CptVit
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptSho = CptSho;
			this.CptTyp = CptTyp;
			this.CptOcc = CptOcc;
			this.CptIme = CptIme;
			this.CptTco = CptTco;
			this.CptIm2 = CptIm2;
			this.CptCty = CptCty;
			this.CptDfv = CptDfv;
			this.CptPst = CptPst;
			this.CptStb = CptStb;
			this.CptVit = CptVit;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSHO, CPTTYP, CPTOCC, CPTIME, CPTTCO, CPTIM2, CPTCTY, CPTDFV, CPTPST, CPTSTB, CPTVIT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptSho;
		public String CptTyp;
		public String CptOcc;
		public String CptIme;
		public String CptTco;
		public String CptIm2;
		public String CptCty;
		public String CptDfv;
		public String CptPst;
		public String CptStb;
		public String CptVit;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmIelDetail");

			String itemtag = "TagitemWznmIelDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSho", mask, CPTSHO);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptOcc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOcc", mask, CPTOCC);
				CptIme = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIme", mask, CPTIME);
				CptTco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTco", mask, CPTTCO);
				CptIm2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIm2", mask, CPTIM2);
				CptCty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCty", mask, CPTCTY);
				CptDfv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDfv", mask, CPTDFV);
				CptPst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPst", mask, CPTPST);
				CptStb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptStb", mask, CPTSTB);
				CptVit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVit", mask, CPTVIT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptSrf.equals(comp.CptSrf)) items.add(CPTSRF);
			if (CptSho.equals(comp.CptSho)) items.add(CPTSHO);
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptOcc.equals(comp.CptOcc)) items.add(CPTOCC);
			if (CptIme.equals(comp.CptIme)) items.add(CPTIME);
			if (CptTco.equals(comp.CptTco)) items.add(CPTTCO);
			if (CptIm2.equals(comp.CptIm2)) items.add(CPTIM2);
			if (CptCty.equals(comp.CptCty)) items.add(CPTCTY);
			if (CptDfv.equals(comp.CptDfv)) items.add(CPTDFV);
			if (CptPst.equals(comp.CptPst)) items.add(CPTPST);
			if (CptStb.equals(comp.CptStb)) items.add(CPTSTB);
			if (CptVit.equals(comp.CptVit)) items.add(CPTVIT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSHO, CPTTYP, CPTOCC, CPTIME, CPTTCO, CPTIM2, CPTCTY, CPTDFV, CPTPST, CPTSTB, CPTVIT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmIelDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMIELDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmIelDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmIelDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMIELDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmIelDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmIelDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTOCC = 4;
		public static final int FEEDFPUPCTY = 5;
		public static final int FEEDFPUPTYP = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMIELDETAILDATA);

			contiac = new ContIac("", 0, new ArrayList<Integer>(), 0, "");
			continf = new ContInf("", "", "", "", "", "", "", "");
			feedFLstOcc = new Feed("FeedFLstOcc");
			feedFPupCty = new Feed("FeedFPupCty");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstOcc;
		public Feed feedFPupCty;
		public Feed feedFPupTyp;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTOCC)) ss.add("feedFLstOcc");
			if (has(FEEDFPUPCTY)) ss.add("feedFPupCty");
			if (has(FEEDFPUPTYP)) ss.add("feedFPupTyp");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmIelDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstOcc.readXML(doc, basexpath, true)) add(FEEDFLSTOCC);
				if (feedFPupCty.readXML(doc, basexpath, true)) add(FEEDFPUPCTY);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", 0, new ArrayList<Integer>(), 0, "");
				continf = new ContInf("", "", "", "", "", "", "", "");
				feedFLstOcc = new Feed("FeedFLstOcc");
				feedFPupCty = new Feed("FeedFPupCty");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

