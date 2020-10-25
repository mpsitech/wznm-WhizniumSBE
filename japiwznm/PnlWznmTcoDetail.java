/**
  * \file PnlWznmTcoDetail.java
  * Java API code for job PnlWznmTcoDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmTcoDetail {
	/**
		* VecVDo (full: VecVWznmTcoDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTTBLVIEWCLICK = 2;
		public static final int BUTSBSVIEWCLICK = 3;
		public static final int BUTRELVIEWCLICK = 4;
		public static final int BUTFCUVIEWCLICK = 5;
		public static final int BUTOPTEDITCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("buttblviewclick")) return BUTTBLVIEWCLICK;
			if (s.equals("butsbsviewclick")) return BUTSBSVIEWCLICK;
			if (s.equals("butrelviewclick")) return BUTRELVIEWCLICK;
			if (s.equals("butfcuviewclick")) return BUTFCUVIEWCLICK;
			if (s.equals("butopteditclick")) return BUTOPTEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTTBLVIEWCLICK) return("ButTblViewClick");
			if (ix == BUTSBSVIEWCLICK) return("ButSbsViewClick");
			if (ix == BUTRELVIEWCLICK) return("ButRelViewClick");
			if (ix == BUTFCUVIEWCLICK) return("ButFcuViewClick");
			if (ix == BUTOPTEDITCLICK) return("ButOptEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmTcoDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFSHO = 1;
		public static final int NUMFPUPTYP = 2;
		public static final int NUMFPUPFCT = 3;
		public static final int NUMFPUPSTY = 4;
		public static final int NUMFPUPAXF = 5;
		public static final int NUMSFLSTOPT = 6;
		public static final int TXFOPT = 7;
		public static final int CHKPNC = 8;
		public static final int CHKEPO = 9;

		public ContIac(
					String TxfSho
					, int numFPupTyp
					, int numFPupFct
					, int numFPupSty
					, int numFPupAxf
					, ArrayList<Integer> numsFLstOpt
					, String TxfOpt
					, boolean ChkPnc
					, boolean ChkEpo
				) {
			this.TxfSho = TxfSho;
			this.numFPupTyp = numFPupTyp;
			this.numFPupFct = numFPupFct;
			this.numFPupSty = numFPupSty;
			this.numFPupAxf = numFPupAxf;
			this.numsFLstOpt = numsFLstOpt;
			this.TxfOpt = TxfOpt;
			this.ChkPnc = ChkPnc;
			this.ChkEpo = ChkEpo;

			mask = new HashSet<Integer>(Arrays.asList(TXFSHO, NUMFPUPTYP, NUMFPUPFCT, NUMFPUPSTY, NUMFPUPAXF, NUMSFLSTOPT, TXFOPT, CHKPNC, CHKEPO));
		};

		public String TxfSho;
		public int numFPupTyp;
		public int numFPupFct;
		public int numFPupSty;
		public int numFPupAxf;
		public ArrayList<Integer> numsFLstOpt;
		public String TxfOpt;
		public boolean ChkPnc;
		public boolean ChkEpo;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmTcoDetail");

			String itemtag = "ContitemIacWznmTcoDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSho", mask, TXFSHO);
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				numFPupFct = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupFct", mask, NUMFPUPFCT);
				numFPupSty = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupSty", mask, NUMFPUPSTY);
				numFPupAxf = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupAxf", mask, NUMFPUPAXF);
				numsFLstOpt = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", mask, NUMSFLSTOPT);
				TxfOpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfOpt", mask, TXFOPT);
				ChkPnc = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkPnc", mask, CHKPNC);
				ChkEpo = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkEpo", mask, CHKEPO);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmTcoDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmTcoDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSho", TxfSho);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupFct", numFPupFct);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupSty", numFPupSty);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupAxf", numFPupAxf);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfOpt", TxfOpt);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkPnc", ChkPnc);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkEpo", ChkEpo);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfSho.equals(comp.TxfSho)) items.add(TXFSHO);
			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (numFPupFct == comp.numFPupFct) items.add(NUMFPUPFCT);
			if (numFPupSty == comp.numFPupSty) items.add(NUMFPUPSTY);
			if (numFPupAxf == comp.numFPupAxf) items.add(NUMFPUPAXF);
			if (Xmlio.compareIntegervec(numsFLstOpt, comp.numsFLstOpt)) items.add(NUMSFLSTOPT);
			if (TxfOpt.equals(comp.TxfOpt)) items.add(TXFOPT);
			if (ChkPnc == comp.ChkPnc) items.add(CHKPNC);
			if (ChkEpo == comp.ChkEpo) items.add(CHKEPO);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFSHO, NUMFPUPTYP, NUMFPUPFCT, NUMFPUPSTY, NUMFPUPAXF, NUMSFLSTOPT, TXFOPT, CHKPNC, CHKEPO));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmTcoDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTTBL = 2;
		public static final int TXTSBS = 3;
		public static final int TXTREL = 4;
		public static final int TXTFCU = 5;

		public ContInf(
					String TxtSrf
					, String TxtTbl
					, String TxtSbs
					, String TxtRel
					, String TxtFcu
				) {
			this.TxtSrf = TxtSrf;
			this.TxtTbl = TxtTbl;
			this.TxtSbs = TxtSbs;
			this.TxtRel = TxtRel;
			this.TxtFcu = TxtFcu;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTBL, TXTSBS, TXTREL, TXTFCU));
		};

		public String TxtSrf;
		public String TxtTbl;
		public String TxtSbs;
		public String TxtRel;
		public String TxtFcu;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmTcoDetail");

			String itemtag = "ContitemInfWznmTcoDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTbl", mask, TXTTBL);
				TxtSbs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSbs", mask, TXTSBS);
				TxtRel = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtRel", mask, TXTREL);
				TxtFcu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtFcu", mask, TXTFCU);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtTbl.equals(comp.TxtTbl)) items.add(TXTTBL);
			if (TxtSbs.equals(comp.TxtSbs)) items.add(TXTSBS);
			if (TxtRel.equals(comp.TxtRel)) items.add(TXTREL);
			if (TxtFcu.equals(comp.TxtFcu)) items.add(TXTFCU);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTBL, TXTSBS, TXTREL, TXTFCU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmTcoDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTOPTALT = 2;
		public static final int LSTOPTNUMFIRSTDISP = 3;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstOptAlt
					, int LstOptNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstOptAlt = LstOptAlt;
			this.LstOptNumFirstdisp = LstOptNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTOPTALT, LSTOPTNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstOptAlt;
		public int LstOptNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmTcoDetail");

			String itemtag = "StatitemAppWznmTcoDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstOptAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptAlt", mask, LSTOPTALT);
				LstOptNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptNumFirstdisp", mask, LSTOPTNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstOptAlt == comp.LstOptAlt) items.add(LSTOPTALT);
			if (LstOptNumFirstdisp == comp.LstOptNumFirstdisp) items.add(LSTOPTNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTOPTALT, LSTOPTNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmTcoDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFOPTVALID = 1;
		public static final int BUTSAVEAVAIL = 2;
		public static final int BUTSAVEACTIVE = 3;
		public static final int TXTSRFACTIVE = 4;
		public static final int TXFSHOACTIVE = 5;
		public static final int PUPTYPACTIVE = 6;
		public static final int TXTTBLACTIVE = 7;
		public static final int BUTTBLVIEWAVAIL = 8;
		public static final int BUTTBLVIEWACTIVE = 9;
		public static final int TXTSBSAVAIL = 10;
		public static final int TXTSBSACTIVE = 11;
		public static final int BUTSBSVIEWAVAIL = 12;
		public static final int BUTSBSVIEWACTIVE = 13;
		public static final int TXTRELAVAIL = 14;
		public static final int TXTRELACTIVE = 15;
		public static final int BUTRELVIEWAVAIL = 16;
		public static final int BUTRELVIEWACTIVE = 17;
		public static final int TXTFCUAVAIL = 18;
		public static final int TXTFCUACTIVE = 19;
		public static final int BUTFCUVIEWAVAIL = 20;
		public static final int BUTFCUVIEWACTIVE = 21;
		public static final int PUPSTYACTIVE = 22;
		public static final int PUPAXFACTIVE = 23;
		public static final int LSTOPTACTIVE = 24;
		public static final int BUTOPTEDITAVAIL = 25;
		public static final int CHKPNCACTIVE = 26;
		public static final int CHKEPOACTIVE = 27;

		public StatShr(
					boolean TxfOptValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxfShoActive
					, boolean PupTypActive
					, boolean TxtTblActive
					, boolean ButTblViewAvail
					, boolean ButTblViewActive
					, boolean TxtSbsAvail
					, boolean TxtSbsActive
					, boolean ButSbsViewAvail
					, boolean ButSbsViewActive
					, boolean TxtRelAvail
					, boolean TxtRelActive
					, boolean ButRelViewAvail
					, boolean ButRelViewActive
					, boolean TxtFcuAvail
					, boolean TxtFcuActive
					, boolean ButFcuViewAvail
					, boolean ButFcuViewActive
					, boolean PupStyActive
					, boolean PupAxfActive
					, boolean LstOptActive
					, boolean ButOptEditAvail
					, boolean ChkPncActive
					, boolean ChkEpoActive
				) {
			this.TxfOptValid = TxfOptValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxfShoActive = TxfShoActive;
			this.PupTypActive = PupTypActive;
			this.TxtTblActive = TxtTblActive;
			this.ButTblViewAvail = ButTblViewAvail;
			this.ButTblViewActive = ButTblViewActive;
			this.TxtSbsAvail = TxtSbsAvail;
			this.TxtSbsActive = TxtSbsActive;
			this.ButSbsViewAvail = ButSbsViewAvail;
			this.ButSbsViewActive = ButSbsViewActive;
			this.TxtRelAvail = TxtRelAvail;
			this.TxtRelActive = TxtRelActive;
			this.ButRelViewAvail = ButRelViewAvail;
			this.ButRelViewActive = ButRelViewActive;
			this.TxtFcuAvail = TxtFcuAvail;
			this.TxtFcuActive = TxtFcuActive;
			this.ButFcuViewAvail = ButFcuViewAvail;
			this.ButFcuViewActive = ButFcuViewActive;
			this.PupStyActive = PupStyActive;
			this.PupAxfActive = PupAxfActive;
			this.LstOptActive = LstOptActive;
			this.ButOptEditAvail = ButOptEditAvail;
			this.ChkPncActive = ChkPncActive;
			this.ChkEpoActive = ChkEpoActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, TXTTBLACTIVE, BUTTBLVIEWAVAIL, BUTTBLVIEWACTIVE, TXTSBSAVAIL, TXTSBSACTIVE, BUTSBSVIEWAVAIL, BUTSBSVIEWACTIVE, TXTRELAVAIL, TXTRELACTIVE, BUTRELVIEWAVAIL, BUTRELVIEWACTIVE, TXTFCUAVAIL, TXTFCUACTIVE, BUTFCUVIEWAVAIL, BUTFCUVIEWACTIVE, PUPSTYACTIVE, PUPAXFACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, CHKPNCACTIVE, CHKEPOACTIVE));
		};

		public boolean TxfOptValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxfShoActive;
		public boolean PupTypActive;
		public boolean TxtTblActive;
		public boolean ButTblViewAvail;
		public boolean ButTblViewActive;
		public boolean TxtSbsAvail;
		public boolean TxtSbsActive;
		public boolean ButSbsViewAvail;
		public boolean ButSbsViewActive;
		public boolean TxtRelAvail;
		public boolean TxtRelActive;
		public boolean ButRelViewAvail;
		public boolean ButRelViewActive;
		public boolean TxtFcuAvail;
		public boolean TxtFcuActive;
		public boolean ButFcuViewAvail;
		public boolean ButFcuViewActive;
		public boolean PupStyActive;
		public boolean PupAxfActive;
		public boolean LstOptActive;
		public boolean ButOptEditAvail;
		public boolean ChkPncActive;
		public boolean ChkEpoActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmTcoDetail");

			String itemtag = "StatitemShrWznmTcoDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfOptValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfOptValid", mask, TXFOPTVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxfShoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfShoActive", mask, TXFSHOACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				TxtTblActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTblActive", mask, TXTTBLACTIVE);
				ButTblViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTblViewAvail", mask, BUTTBLVIEWAVAIL);
				ButTblViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTblViewActive", mask, BUTTBLVIEWACTIVE);
				TxtSbsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSbsAvail", mask, TXTSBSAVAIL);
				TxtSbsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSbsActive", mask, TXTSBSACTIVE);
				ButSbsViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSbsViewAvail", mask, BUTSBSVIEWAVAIL);
				ButSbsViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSbsViewActive", mask, BUTSBSVIEWACTIVE);
				TxtRelAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtRelAvail", mask, TXTRELAVAIL);
				TxtRelActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtRelActive", mask, TXTRELACTIVE);
				ButRelViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRelViewAvail", mask, BUTRELVIEWAVAIL);
				ButRelViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRelViewActive", mask, BUTRELVIEWACTIVE);
				TxtFcuAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtFcuAvail", mask, TXTFCUAVAIL);
				TxtFcuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtFcuActive", mask, TXTFCUACTIVE);
				ButFcuViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFcuViewAvail", mask, BUTFCUVIEWAVAIL);
				ButFcuViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFcuViewActive", mask, BUTFCUVIEWACTIVE);
				PupStyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupStyActive", mask, PUPSTYACTIVE);
				PupAxfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupAxfActive", mask, PUPAXFACTIVE);
				LstOptActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptActive", mask, LSTOPTACTIVE);
				ButOptEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButOptEditAvail", mask, BUTOPTEDITAVAIL);
				ChkPncActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkPncActive", mask, CHKPNCACTIVE);
				ChkEpoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkEpoActive", mask, CHKEPOACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfOptValid == comp.TxfOptValid) items.add(TXFOPTVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (TxfShoActive == comp.TxfShoActive) items.add(TXFSHOACTIVE);
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (TxtTblActive == comp.TxtTblActive) items.add(TXTTBLACTIVE);
			if (ButTblViewAvail == comp.ButTblViewAvail) items.add(BUTTBLVIEWAVAIL);
			if (ButTblViewActive == comp.ButTblViewActive) items.add(BUTTBLVIEWACTIVE);
			if (TxtSbsAvail == comp.TxtSbsAvail) items.add(TXTSBSAVAIL);
			if (TxtSbsActive == comp.TxtSbsActive) items.add(TXTSBSACTIVE);
			if (ButSbsViewAvail == comp.ButSbsViewAvail) items.add(BUTSBSVIEWAVAIL);
			if (ButSbsViewActive == comp.ButSbsViewActive) items.add(BUTSBSVIEWACTIVE);
			if (TxtRelAvail == comp.TxtRelAvail) items.add(TXTRELAVAIL);
			if (TxtRelActive == comp.TxtRelActive) items.add(TXTRELACTIVE);
			if (ButRelViewAvail == comp.ButRelViewAvail) items.add(BUTRELVIEWAVAIL);
			if (ButRelViewActive == comp.ButRelViewActive) items.add(BUTRELVIEWACTIVE);
			if (TxtFcuAvail == comp.TxtFcuAvail) items.add(TXTFCUAVAIL);
			if (TxtFcuActive == comp.TxtFcuActive) items.add(TXTFCUACTIVE);
			if (ButFcuViewAvail == comp.ButFcuViewAvail) items.add(BUTFCUVIEWAVAIL);
			if (ButFcuViewActive == comp.ButFcuViewActive) items.add(BUTFCUVIEWACTIVE);
			if (PupStyActive == comp.PupStyActive) items.add(PUPSTYACTIVE);
			if (PupAxfActive == comp.PupAxfActive) items.add(PUPAXFACTIVE);
			if (LstOptActive == comp.LstOptActive) items.add(LSTOPTACTIVE);
			if (ButOptEditAvail == comp.ButOptEditAvail) items.add(BUTOPTEDITAVAIL);
			if (ChkPncActive == comp.ChkPncActive) items.add(CHKPNCACTIVE);
			if (ChkEpoActive == comp.ChkEpoActive) items.add(CHKEPOACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, TXTTBLACTIVE, BUTTBLVIEWAVAIL, BUTTBLVIEWACTIVE, TXTSBSAVAIL, TXTSBSACTIVE, BUTSBSVIEWAVAIL, BUTSBSVIEWACTIVE, TXTRELAVAIL, TXTRELACTIVE, BUTRELVIEWAVAIL, BUTRELVIEWACTIVE, TXTFCUAVAIL, TXTFCUACTIVE, BUTFCUVIEWAVAIL, BUTFCUVIEWACTIVE, PUPSTYACTIVE, PUPAXFACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, CHKPNCACTIVE, CHKEPOACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmTcoDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTSHO = 3;
		public static final int CPTTYP = 4;
		public static final int CPTTBL = 5;
		public static final int CPTSBS = 6;
		public static final int CPTREL = 7;
		public static final int CPTFCU = 8;
		public static final int CPTSTY = 9;
		public static final int CPTAXF = 10;
		public static final int CPTOPT = 11;
		public static final int CPTPNC = 12;
		public static final int CPTEPO = 13;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptSho
					, String CptTyp
					, String CptTbl
					, String CptSbs
					, String CptRel
					, String CptFcu
					, String CptSty
					, String CptAxf
					, String CptOpt
					, String CptPnc
					, String CptEpo
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptSho = CptSho;
			this.CptTyp = CptTyp;
			this.CptTbl = CptTbl;
			this.CptSbs = CptSbs;
			this.CptRel = CptRel;
			this.CptFcu = CptFcu;
			this.CptSty = CptSty;
			this.CptAxf = CptAxf;
			this.CptOpt = CptOpt;
			this.CptPnc = CptPnc;
			this.CptEpo = CptEpo;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSHO, CPTTYP, CPTTBL, CPTSBS, CPTREL, CPTFCU, CPTSTY, CPTAXF, CPTOPT, CPTPNC, CPTEPO));
		};

		public String Cpt;
		public String CptSrf;
		public String CptSho;
		public String CptTyp;
		public String CptTbl;
		public String CptSbs;
		public String CptRel;
		public String CptFcu;
		public String CptSty;
		public String CptAxf;
		public String CptOpt;
		public String CptPnc;
		public String CptEpo;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmTcoDetail");

			String itemtag = "TagitemWznmTcoDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSho", mask, CPTSHO);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTbl", mask, CPTTBL);
				CptSbs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSbs", mask, CPTSBS);
				CptRel = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptRel", mask, CPTREL);
				CptFcu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFcu", mask, CPTFCU);
				CptSty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSty", mask, CPTSTY);
				CptAxf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAxf", mask, CPTAXF);
				CptOpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOpt", mask, CPTOPT);
				CptPnc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPnc", mask, CPTPNC);
				CptEpo = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptEpo", mask, CPTEPO);

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
			if (CptTbl.equals(comp.CptTbl)) items.add(CPTTBL);
			if (CptSbs.equals(comp.CptSbs)) items.add(CPTSBS);
			if (CptRel.equals(comp.CptRel)) items.add(CPTREL);
			if (CptFcu.equals(comp.CptFcu)) items.add(CPTFCU);
			if (CptSty.equals(comp.CptSty)) items.add(CPTSTY);
			if (CptAxf.equals(comp.CptAxf)) items.add(CPTAXF);
			if (CptOpt.equals(comp.CptOpt)) items.add(CPTOPT);
			if (CptPnc.equals(comp.CptPnc)) items.add(CPTPNC);
			if (CptEpo.equals(comp.CptEpo)) items.add(CPTEPO);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSHO, CPTTYP, CPTTBL, CPTSBS, CPTREL, CPTFCU, CPTSTY, CPTAXF, CPTOPT, CPTPNC, CPTEPO));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmTcoDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMTCODETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmTcoDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmTcoDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMTCODETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmTcoDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmTcoDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTOPT = 4;
		public static final int FEEDFPUPAXF = 5;
		public static final int FEEDFPUPFCT = 6;
		public static final int FEEDFPUPSTY = 7;
		public static final int FEEDFPUPTYP = 8;
		public static final int STATAPP = 9;
		public static final int STATSHR = 10;
		public static final int TAG = 11;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMTCODETAILDATA);

			contiac = new ContIac("", 0, 0, 0, 0, new ArrayList<Integer>(), "", false, false);
			continf = new ContInf("", "", "", "", "");
			feedFLstOpt = new Feed("FeedFLstOpt");
			feedFPupAxf = new Feed("FeedFPupAxf");
			feedFPupFct = new Feed("FeedFPupFct");
			feedFPupSty = new Feed("FeedFPupSty");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstOpt;
		public Feed feedFPupAxf;
		public Feed feedFPupFct;
		public Feed feedFPupSty;
		public Feed feedFPupTyp;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTOPT)) ss.add("feedFLstOpt");
			if (has(FEEDFPUPAXF)) ss.add("feedFPupAxf");
			if (has(FEEDFPUPFCT)) ss.add("feedFPupFct");
			if (has(FEEDFPUPSTY)) ss.add("feedFPupSty");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmTcoDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstOpt.readXML(doc, basexpath, true)) add(FEEDFLSTOPT);
				if (feedFPupAxf.readXML(doc, basexpath, true)) add(FEEDFPUPAXF);
				if (feedFPupFct.readXML(doc, basexpath, true)) add(FEEDFPUPFCT);
				if (feedFPupSty.readXML(doc, basexpath, true)) add(FEEDFPUPSTY);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", 0, 0, 0, 0, new ArrayList<Integer>(), "", false, false);
				continf = new ContInf("", "", "", "", "");
				feedFLstOpt = new Feed("FeedFLstOpt");
				feedFPupAxf = new Feed("FeedFPupAxf");
				feedFPupFct = new Feed("FeedFPupFct");
				feedFPupSty = new Feed("FeedFPupSty");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

