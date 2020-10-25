/**
  * \file PnlWznmRelDetail.java
  * Java API code for job PnlWznmRelDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmRelDetail {
	/**
		* VecVDo (full: VecVWznmRelDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTFRSVIEWCLICK = 2;
		public static final int BUTTOSVIEWCLICK = 3;
		public static final int BUTCLUVIEWCLICK = 4;
		public static final int BUTCLUCLUSTERCLICK = 5;
		public static final int BUTCLUUNCLUSTERCLICK = 6;
		public static final int BUTVERVIEWCLICK = 7;
		public static final int BUTSUPVIEWCLICK = 8;
		public static final int BUTOPTEDITCLICK = 9;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butfrsviewclick")) return BUTFRSVIEWCLICK;
			if (s.equals("buttosviewclick")) return BUTTOSVIEWCLICK;
			if (s.equals("butcluviewclick")) return BUTCLUVIEWCLICK;
			if (s.equals("butcluclusterclick")) return BUTCLUCLUSTERCLICK;
			if (s.equals("butcluunclusterclick")) return BUTCLUUNCLUSTERCLICK;
			if (s.equals("butverviewclick")) return BUTVERVIEWCLICK;
			if (s.equals("butsupviewclick")) return BUTSUPVIEWCLICK;
			if (s.equals("butopteditclick")) return BUTOPTEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTFRSVIEWCLICK) return("ButFrsViewClick");
			if (ix == BUTTOSVIEWCLICK) return("ButTosViewClick");
			if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
			if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
			if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
			if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
			if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
			if (ix == BUTOPTEDITCLICK) return("ButOptEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmRelDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPTYP = 1;
		public static final int NUMFLSTCLU = 2;
		public static final int TXFPFX = 3;
		public static final int NUMSFLSTOPT = 4;
		public static final int TXFOPT = 5;

		public ContIac(
					int numFPupTyp
					, int numFLstClu
					, String TxfPfx
					, ArrayList<Integer> numsFLstOpt
					, String TxfOpt
				) {
			this.numFPupTyp = numFPupTyp;
			this.numFLstClu = numFLstClu;
			this.TxfPfx = TxfPfx;
			this.numsFLstOpt = numsFLstOpt;
			this.TxfOpt = TxfOpt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, NUMFLSTCLU, TXFPFX, NUMSFLSTOPT, TXFOPT));
		};

		public int numFPupTyp;
		public int numFLstClu;
		public String TxfPfx;
		public ArrayList<Integer> numsFLstOpt;
		public String TxfOpt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmRelDetail");

			String itemtag = "ContitemIacWznmRelDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				numFLstClu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstClu", mask, NUMFLSTCLU);
				TxfPfx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfPfx", mask, TXFPFX);
				numsFLstOpt = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", mask, NUMSFLSTOPT);
				TxfOpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfOpt", mask, TXFOPT);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmRelDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmRelDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstClu", numFLstClu);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfPfx", TxfPfx);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfOpt", TxfOpt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (numFLstClu == comp.numFLstClu) items.add(NUMFLSTCLU);
			if (TxfPfx.equals(comp.TxfPfx)) items.add(TXFPFX);
			if (Xmlio.compareIntegervec(numsFLstOpt, comp.numsFLstOpt)) items.add(NUMSFLSTOPT);
			if (TxfOpt.equals(comp.TxfOpt)) items.add(TXFOPT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, NUMFLSTCLU, TXFPFX, NUMSFLSTOPT, TXFOPT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmRelDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTFRT = 1;
		public static final int TXTFRS = 2;
		public static final int TXTTOT = 3;
		public static final int TXTTOS = 4;
		public static final int TXTCLU = 5;
		public static final int TXTVER = 6;
		public static final int TXTSUP = 7;
		public static final int TXTTBL = 8;

		public ContInf(
					String TxtFrt
					, String TxtFrs
					, String TxtTot
					, String TxtTos
					, String TxtClu
					, String TxtVer
					, String TxtSup
					, String TxtTbl
				) {
			this.TxtFrt = TxtFrt;
			this.TxtFrs = TxtFrs;
			this.TxtTot = TxtTot;
			this.TxtTos = TxtTos;
			this.TxtClu = TxtClu;
			this.TxtVer = TxtVer;
			this.TxtSup = TxtSup;
			this.TxtTbl = TxtTbl;

			mask = new HashSet<Integer>(Arrays.asList(TXTFRT, TXTFRS, TXTTOT, TXTTOS, TXTCLU, TXTVER, TXTSUP, TXTTBL));
		};

		public String TxtFrt;
		public String TxtFrs;
		public String TxtTot;
		public String TxtTos;
		public String TxtClu;
		public String TxtVer;
		public String TxtSup;
		public String TxtTbl;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmRelDetail");

			String itemtag = "ContitemInfWznmRelDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtFrt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtFrt", mask, TXTFRT);
				TxtFrs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtFrs", mask, TXTFRS);
				TxtTot = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTot", mask, TXTTOT);
				TxtTos = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTos", mask, TXTTOS);
				TxtClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtClu", mask, TXTCLU);
				TxtVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVer", mask, TXTVER);
				TxtSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSup", mask, TXTSUP);
				TxtTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTbl", mask, TXTTBL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtFrt.equals(comp.TxtFrt)) items.add(TXTFRT);
			if (TxtFrs.equals(comp.TxtFrs)) items.add(TXTFRS);
			if (TxtTot.equals(comp.TxtTot)) items.add(TXTTOT);
			if (TxtTos.equals(comp.TxtTos)) items.add(TXTTOS);
			if (TxtClu.equals(comp.TxtClu)) items.add(TXTCLU);
			if (TxtVer.equals(comp.TxtVer)) items.add(TXTVER);
			if (TxtSup.equals(comp.TxtSup)) items.add(TXTSUP);
			if (TxtTbl.equals(comp.TxtTbl)) items.add(TXTTBL);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTFRT, TXTFRS, TXTTOT, TXTTOS, TXTCLU, TXTVER, TXTSUP, TXTTBL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmRelDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTCLUALT = 2;
		public static final int LSTOPTALT = 3;
		public static final int LSTCLUNUMFIRSTDISP = 4;
		public static final int LSTOPTNUMFIRSTDISP = 5;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstCluAlt
					, boolean LstOptAlt
					, int LstCluNumFirstdisp
					, int LstOptNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstCluAlt = LstCluAlt;
			this.LstOptAlt = LstOptAlt;
			this.LstCluNumFirstdisp = LstCluNumFirstdisp;
			this.LstOptNumFirstdisp = LstOptNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTCLUALT, LSTOPTALT, LSTCLUNUMFIRSTDISP, LSTOPTNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstCluAlt;
		public boolean LstOptAlt;
		public int LstCluNumFirstdisp;
		public int LstOptNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmRelDetail");

			String itemtag = "StatitemAppWznmRelDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstCluAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluAlt", mask, LSTCLUALT);
				LstOptAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptAlt", mask, LSTOPTALT);
				LstCluNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluNumFirstdisp", mask, LSTCLUNUMFIRSTDISP);
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
			if (LstCluAlt == comp.LstCluAlt) items.add(LSTCLUALT);
			if (LstOptAlt == comp.LstOptAlt) items.add(LSTOPTALT);
			if (LstCluNumFirstdisp == comp.LstCluNumFirstdisp) items.add(LSTCLUNUMFIRSTDISP);
			if (LstOptNumFirstdisp == comp.LstOptNumFirstdisp) items.add(LSTOPTNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTCLUALT, LSTOPTALT, LSTCLUNUMFIRSTDISP, LSTOPTNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmRelDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFOPTVALID = 1;
		public static final int BUTSAVEAVAIL = 2;
		public static final int BUTSAVEACTIVE = 3;
		public static final int TXTFRTACTIVE = 4;
		public static final int TXTFRSACTIVE = 5;
		public static final int BUTFRSVIEWAVAIL = 6;
		public static final int BUTFRSVIEWACTIVE = 7;
		public static final int TXTTOTACTIVE = 8;
		public static final int TXTTOSACTIVE = 9;
		public static final int BUTTOSVIEWAVAIL = 10;
		public static final int BUTTOSVIEWACTIVE = 11;
		public static final int PUPTYPACTIVE = 12;
		public static final int LSTCLUACTIVE = 13;
		public static final int BUTCLUVIEWACTIVE = 14;
		public static final int BUTCLUCLUSTERAVAIL = 15;
		public static final int BUTCLUUNCLUSTERAVAIL = 16;
		public static final int TXTVERACTIVE = 17;
		public static final int BUTVERVIEWAVAIL = 18;
		public static final int BUTVERVIEWACTIVE = 19;
		public static final int TXTSUPACTIVE = 20;
		public static final int BUTSUPVIEWAVAIL = 21;
		public static final int BUTSUPVIEWACTIVE = 22;
		public static final int TXTTBLACTIVE = 23;
		public static final int TXFPFXACTIVE = 24;
		public static final int LSTOPTACTIVE = 25;
		public static final int BUTOPTEDITAVAIL = 26;

		public StatShr(
					boolean TxfOptValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtFrtActive
					, boolean TxtFrsActive
					, boolean ButFrsViewAvail
					, boolean ButFrsViewActive
					, boolean TxtTotActive
					, boolean TxtTosActive
					, boolean ButTosViewAvail
					, boolean ButTosViewActive
					, boolean PupTypActive
					, boolean LstCluActive
					, boolean ButCluViewActive
					, boolean ButCluClusterAvail
					, boolean ButCluUnclusterAvail
					, boolean TxtVerActive
					, boolean ButVerViewAvail
					, boolean ButVerViewActive
					, boolean TxtSupActive
					, boolean ButSupViewAvail
					, boolean ButSupViewActive
					, boolean TxtTblActive
					, boolean TxfPfxActive
					, boolean LstOptActive
					, boolean ButOptEditAvail
				) {
			this.TxfOptValid = TxfOptValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtFrtActive = TxtFrtActive;
			this.TxtFrsActive = TxtFrsActive;
			this.ButFrsViewAvail = ButFrsViewAvail;
			this.ButFrsViewActive = ButFrsViewActive;
			this.TxtTotActive = TxtTotActive;
			this.TxtTosActive = TxtTosActive;
			this.ButTosViewAvail = ButTosViewAvail;
			this.ButTosViewActive = ButTosViewActive;
			this.PupTypActive = PupTypActive;
			this.LstCluActive = LstCluActive;
			this.ButCluViewActive = ButCluViewActive;
			this.ButCluClusterAvail = ButCluClusterAvail;
			this.ButCluUnclusterAvail = ButCluUnclusterAvail;
			this.TxtVerActive = TxtVerActive;
			this.ButVerViewAvail = ButVerViewAvail;
			this.ButVerViewActive = ButVerViewActive;
			this.TxtSupActive = TxtSupActive;
			this.ButSupViewAvail = ButSupViewAvail;
			this.ButSupViewActive = ButSupViewActive;
			this.TxtTblActive = TxtTblActive;
			this.TxfPfxActive = TxfPfxActive;
			this.LstOptActive = LstOptActive;
			this.ButOptEditAvail = ButOptEditAvail;

			mask = new HashSet<Integer>(Arrays.asList(TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFRTACTIVE, TXTFRSACTIVE, BUTFRSVIEWAVAIL, BUTFRSVIEWACTIVE, TXTTOTACTIVE, TXTTOSACTIVE, BUTTOSVIEWAVAIL, BUTTOSVIEWACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, TXFPFXACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL));
		};

		public boolean TxfOptValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtFrtActive;
		public boolean TxtFrsActive;
		public boolean ButFrsViewAvail;
		public boolean ButFrsViewActive;
		public boolean TxtTotActive;
		public boolean TxtTosActive;
		public boolean ButTosViewAvail;
		public boolean ButTosViewActive;
		public boolean PupTypActive;
		public boolean LstCluActive;
		public boolean ButCluViewActive;
		public boolean ButCluClusterAvail;
		public boolean ButCluUnclusterAvail;
		public boolean TxtVerActive;
		public boolean ButVerViewAvail;
		public boolean ButVerViewActive;
		public boolean TxtSupActive;
		public boolean ButSupViewAvail;
		public boolean ButSupViewActive;
		public boolean TxtTblActive;
		public boolean TxfPfxActive;
		public boolean LstOptActive;
		public boolean ButOptEditAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmRelDetail");

			String itemtag = "StatitemShrWznmRelDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfOptValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfOptValid", mask, TXFOPTVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtFrtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtFrtActive", mask, TXTFRTACTIVE);
				TxtFrsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtFrsActive", mask, TXTFRSACTIVE);
				ButFrsViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFrsViewAvail", mask, BUTFRSVIEWAVAIL);
				ButFrsViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFrsViewActive", mask, BUTFRSVIEWACTIVE);
				TxtTotActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTotActive", mask, TXTTOTACTIVE);
				TxtTosActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTosActive", mask, TXTTOSACTIVE);
				ButTosViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTosViewAvail", mask, BUTTOSVIEWAVAIL);
				ButTosViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTosViewActive", mask, BUTTOSVIEWACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				LstCluActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluActive", mask, LSTCLUACTIVE);
				ButCluViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluViewActive", mask, BUTCLUVIEWACTIVE);
				ButCluClusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", mask, BUTCLUCLUSTERAVAIL);
				ButCluUnclusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", mask, BUTCLUUNCLUSTERAVAIL);
				TxtVerActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVerActive", mask, TXTVERACTIVE);
				ButVerViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", mask, BUTVERVIEWAVAIL);
				ButVerViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewActive", mask, BUTVERVIEWACTIVE);
				TxtSupActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSupActive", mask, TXTSUPACTIVE);
				ButSupViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", mask, BUTSUPVIEWAVAIL);
				ButSupViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewActive", mask, BUTSUPVIEWACTIVE);
				TxtTblActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTblActive", mask, TXTTBLACTIVE);
				TxfPfxActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfPfxActive", mask, TXFPFXACTIVE);
				LstOptActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptActive", mask, LSTOPTACTIVE);
				ButOptEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButOptEditAvail", mask, BUTOPTEDITAVAIL);

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
			if (TxtFrtActive == comp.TxtFrtActive) items.add(TXTFRTACTIVE);
			if (TxtFrsActive == comp.TxtFrsActive) items.add(TXTFRSACTIVE);
			if (ButFrsViewAvail == comp.ButFrsViewAvail) items.add(BUTFRSVIEWAVAIL);
			if (ButFrsViewActive == comp.ButFrsViewActive) items.add(BUTFRSVIEWACTIVE);
			if (TxtTotActive == comp.TxtTotActive) items.add(TXTTOTACTIVE);
			if (TxtTosActive == comp.TxtTosActive) items.add(TXTTOSACTIVE);
			if (ButTosViewAvail == comp.ButTosViewAvail) items.add(BUTTOSVIEWAVAIL);
			if (ButTosViewActive == comp.ButTosViewActive) items.add(BUTTOSVIEWACTIVE);
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (LstCluActive == comp.LstCluActive) items.add(LSTCLUACTIVE);
			if (ButCluViewActive == comp.ButCluViewActive) items.add(BUTCLUVIEWACTIVE);
			if (ButCluClusterAvail == comp.ButCluClusterAvail) items.add(BUTCLUCLUSTERAVAIL);
			if (ButCluUnclusterAvail == comp.ButCluUnclusterAvail) items.add(BUTCLUUNCLUSTERAVAIL);
			if (TxtVerActive == comp.TxtVerActive) items.add(TXTVERACTIVE);
			if (ButVerViewAvail == comp.ButVerViewAvail) items.add(BUTVERVIEWAVAIL);
			if (ButVerViewActive == comp.ButVerViewActive) items.add(BUTVERVIEWACTIVE);
			if (TxtSupActive == comp.TxtSupActive) items.add(TXTSUPACTIVE);
			if (ButSupViewAvail == comp.ButSupViewAvail) items.add(BUTSUPVIEWAVAIL);
			if (ButSupViewActive == comp.ButSupViewActive) items.add(BUTSUPVIEWACTIVE);
			if (TxtTblActive == comp.TxtTblActive) items.add(TXTTBLACTIVE);
			if (TxfPfxActive == comp.TxfPfxActive) items.add(TXFPFXACTIVE);
			if (LstOptActive == comp.LstOptActive) items.add(LSTOPTACTIVE);
			if (ButOptEditAvail == comp.ButOptEditAvail) items.add(BUTOPTEDITAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFRTACTIVE, TXTFRSACTIVE, BUTFRSVIEWAVAIL, BUTFRSVIEWACTIVE, TXTTOTACTIVE, TXTTOSACTIVE, BUTTOSVIEWAVAIL, BUTTOSVIEWACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, TXFPFXACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmRelDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTFRT = 2;
		public static final int CPTFRS = 3;
		public static final int CPTTOT = 4;
		public static final int CPTTOS = 5;
		public static final int CPTTYP = 6;
		public static final int CPTCLU = 7;
		public static final int CPTVER = 8;
		public static final int CPTSUP = 9;
		public static final int CPTTBL = 10;
		public static final int CPTPFX = 11;
		public static final int CPTOPT = 12;

		public Tag(
					String Cpt
					, String CptFrt
					, String CptFrs
					, String CptTot
					, String CptTos
					, String CptTyp
					, String CptClu
					, String CptVer
					, String CptSup
					, String CptTbl
					, String CptPfx
					, String CptOpt
				) {
			this.Cpt = Cpt;
			this.CptFrt = CptFrt;
			this.CptFrs = CptFrs;
			this.CptTot = CptTot;
			this.CptTos = CptTos;
			this.CptTyp = CptTyp;
			this.CptClu = CptClu;
			this.CptVer = CptVer;
			this.CptSup = CptSup;
			this.CptTbl = CptTbl;
			this.CptPfx = CptPfx;
			this.CptOpt = CptOpt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTFRT, CPTFRS, CPTTOT, CPTTOS, CPTTYP, CPTCLU, CPTVER, CPTSUP, CPTTBL, CPTPFX, CPTOPT));
		};

		public String Cpt;
		public String CptFrt;
		public String CptFrs;
		public String CptTot;
		public String CptTos;
		public String CptTyp;
		public String CptClu;
		public String CptVer;
		public String CptSup;
		public String CptTbl;
		public String CptPfx;
		public String CptOpt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmRelDetail");

			String itemtag = "TagitemWznmRelDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptFrt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFrt", mask, CPTFRT);
				CptFrs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFrs", mask, CPTFRS);
				CptTot = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTot", mask, CPTTOT);
				CptTos = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTos", mask, CPTTOS);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptClu", mask, CPTCLU);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSup", mask, CPTSUP);
				CptTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTbl", mask, CPTTBL);
				CptPfx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPfx", mask, CPTPFX);
				CptOpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOpt", mask, CPTOPT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptFrt.equals(comp.CptFrt)) items.add(CPTFRT);
			if (CptFrs.equals(comp.CptFrs)) items.add(CPTFRS);
			if (CptTot.equals(comp.CptTot)) items.add(CPTTOT);
			if (CptTos.equals(comp.CptTos)) items.add(CPTTOS);
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptClu.equals(comp.CptClu)) items.add(CPTCLU);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);
			if (CptSup.equals(comp.CptSup)) items.add(CPTSUP);
			if (CptTbl.equals(comp.CptTbl)) items.add(CPTTBL);
			if (CptPfx.equals(comp.CptPfx)) items.add(CPTPFX);
			if (CptOpt.equals(comp.CptOpt)) items.add(CPTOPT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTFRT, CPTFRS, CPTTOT, CPTTOS, CPTTYP, CPTCLU, CPTVER, CPTSUP, CPTTBL, CPTPFX, CPTOPT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmRelDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMRELDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmRelDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmRelDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMRELDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmRelDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmRelDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTCLU = 4;
		public static final int FEEDFLSTOPT = 5;
		public static final int FEEDFPUPTYP = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMRELDETAILDATA);

			contiac = new ContIac(0, 0, "", new ArrayList<Integer>(), "");
			continf = new ContInf("", "", "", "", "", "", "", "");
			feedFLstClu = new Feed("FeedFLstClu");
			feedFLstOpt = new Feed("FeedFLstOpt");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0, false, false, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstClu;
		public Feed feedFLstOpt;
		public Feed feedFPupTyp;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTCLU)) ss.add("feedFLstClu");
			if (has(FEEDFLSTOPT)) ss.add("feedFLstOpt");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmRelDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstClu.readXML(doc, basexpath, true)) add(FEEDFLSTCLU);
				if (feedFLstOpt.readXML(doc, basexpath, true)) add(FEEDFLSTOPT);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, "", new ArrayList<Integer>(), "");
				continf = new ContInf("", "", "", "", "", "", "", "");
				feedFLstClu = new Feed("FeedFLstClu");
				feedFLstOpt = new Feed("FeedFLstOpt");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0, false, false, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

