/**
  * \file PnlWznmBlkDetail.java
  * Java API code for job PnlWznmBlkDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmBlkDetail {
	/**
		* VecVDo (full: VecVWznmBlkDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTVERVIEWCLICK = 2;
		public static final int BUTREUVIEWCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butverviewclick")) return BUTVERVIEWCLICK;
			if (s.equals("butreuviewclick")) return BUTREUVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
			if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmBlkDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPTYP = 1;
		public static final int NUMFPUPRET = 2;
		public static final int NUMSFLSTREA = 3;
		public static final int NUMSFLSTWRI = 4;
		public static final int TXFCMT = 5;

		public ContIac(
					int numFPupTyp
					, int numFPupRet
					, ArrayList<Integer> numsFLstRea
					, ArrayList<Integer> numsFLstWri
					, String TxfCmt
				) {
			this.numFPupTyp = numFPupTyp;
			this.numFPupRet = numFPupRet;
			this.numsFLstRea = numsFLstRea;
			this.numsFLstWri = numsFLstWri;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, NUMFPUPRET, NUMSFLSTREA, NUMSFLSTWRI, TXFCMT));
		};

		public int numFPupTyp;
		public int numFPupRet;
		public ArrayList<Integer> numsFLstRea;
		public ArrayList<Integer> numsFLstWri;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmBlkDetail");

			String itemtag = "ContitemIacWznmBlkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				numFPupRet = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupRet", mask, NUMFPUPRET);
				numsFLstRea = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstRea", mask, NUMSFLSTREA);
				numsFLstWri = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstWri", mask, NUMSFLSTWRI);
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCmt", mask, TXFCMT);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmBlkDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmBlkDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupRet", numFPupRet);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstRea", numsFLstRea);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstWri", numsFLstWri);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (numFPupRet == comp.numFPupRet) items.add(NUMFPUPRET);
			if (Xmlio.compareIntegervec(numsFLstRea, comp.numsFLstRea)) items.add(NUMSFLSTREA);
			if (Xmlio.compareIntegervec(numsFLstWri, comp.numsFLstWri)) items.add(NUMSFLSTWRI);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, NUMFPUPRET, NUMSFLSTREA, NUMSFLSTWRI, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmBlkDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTVER = 2;
		public static final int TXTREU = 3;
		public static final int TXTREA = 4;
		public static final int TXTWRI = 5;

		public ContInf(
					String TxtSrf
					, String TxtVer
					, String TxtReu
					, String TxtRea
					, String TxtWri
				) {
			this.TxtSrf = TxtSrf;
			this.TxtVer = TxtVer;
			this.TxtReu = TxtReu;
			this.TxtRea = TxtRea;
			this.TxtWri = TxtWri;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTVER, TXTREU, TXTREA, TXTWRI));
		};

		public String TxtSrf;
		public String TxtVer;
		public String TxtReu;
		public String TxtRea;
		public String TxtWri;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmBlkDetail");

			String itemtag = "ContitemInfWznmBlkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVer", mask, TXTVER);
				TxtReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtReu", mask, TXTREU);
				TxtRea = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtRea", mask, TXTREA);
				TxtWri = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtWri", mask, TXTWRI);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtVer.equals(comp.TxtVer)) items.add(TXTVER);
			if (TxtReu.equals(comp.TxtReu)) items.add(TXTREU);
			if (TxtRea.equals(comp.TxtRea)) items.add(TXTREA);
			if (TxtWri.equals(comp.TxtWri)) items.add(TXTWRI);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTVER, TXTREU, TXTREA, TXTWRI));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmBlkDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTREAALT = 2;
		public static final int LSTWRIALT = 3;
		public static final int LSTREANUMFIRSTDISP = 4;
		public static final int LSTWRINUMFIRSTDISP = 5;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstReaAlt
					, boolean LstWriAlt
					, int LstReaNumFirstdisp
					, int LstWriNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstReaAlt = LstReaAlt;
			this.LstWriAlt = LstWriAlt;
			this.LstReaNumFirstdisp = LstReaNumFirstdisp;
			this.LstWriNumFirstdisp = LstWriNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTREAALT, LSTWRIALT, LSTREANUMFIRSTDISP, LSTWRINUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstReaAlt;
		public boolean LstWriAlt;
		public int LstReaNumFirstdisp;
		public int LstWriNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmBlkDetail");

			String itemtag = "StatitemAppWznmBlkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstReaAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstReaAlt", mask, LSTREAALT);
				LstWriAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstWriAlt", mask, LSTWRIALT);
				LstReaNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstReaNumFirstdisp", mask, LSTREANUMFIRSTDISP);
				LstWriNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstWriNumFirstdisp", mask, LSTWRINUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstReaAlt == comp.LstReaAlt) items.add(LSTREAALT);
			if (LstWriAlt == comp.LstWriAlt) items.add(LSTWRIALT);
			if (LstReaNumFirstdisp == comp.LstReaNumFirstdisp) items.add(LSTREANUMFIRSTDISP);
			if (LstWriNumFirstdisp == comp.LstWriNumFirstdisp) items.add(LSTWRINUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTREAALT, LSTWRIALT, LSTREANUMFIRSTDISP, LSTWRINUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmBlkDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int PUPTYPACTIVE = 4;
		public static final int TXTVERACTIVE = 5;
		public static final int BUTVERVIEWAVAIL = 6;
		public static final int BUTVERVIEWACTIVE = 7;
		public static final int TXTREUACTIVE = 8;
		public static final int BUTREUVIEWAVAIL = 9;
		public static final int BUTREUVIEWACTIVE = 10;
		public static final int LSTREAACTIVE = 11;
		public static final int LSTWRIACTIVE = 12;
		public static final int TXFCMTACTIVE = 13;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupTypActive
					, boolean TxtVerActive
					, boolean ButVerViewAvail
					, boolean ButVerViewActive
					, boolean TxtReuActive
					, boolean ButReuViewAvail
					, boolean ButReuViewActive
					, boolean LstReaActive
					, boolean LstWriActive
					, boolean TxfCmtActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupTypActive = PupTypActive;
			this.TxtVerActive = TxtVerActive;
			this.ButVerViewAvail = ButVerViewAvail;
			this.ButVerViewActive = ButVerViewActive;
			this.TxtReuActive = TxtReuActive;
			this.ButReuViewAvail = ButReuViewAvail;
			this.ButReuViewActive = ButReuViewActive;
			this.LstReaActive = LstReaActive;
			this.LstWriActive = LstWriActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, LSTREAACTIVE, LSTWRIACTIVE, TXFCMTACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupTypActive;
		public boolean TxtVerActive;
		public boolean ButVerViewAvail;
		public boolean ButVerViewActive;
		public boolean TxtReuActive;
		public boolean ButReuViewAvail;
		public boolean ButReuViewActive;
		public boolean LstReaActive;
		public boolean LstWriActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmBlkDetail");

			String itemtag = "StatitemShrWznmBlkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				TxtVerActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVerActive", mask, TXTVERACTIVE);
				ButVerViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", mask, BUTVERVIEWAVAIL);
				ButVerViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewActive", mask, BUTVERVIEWACTIVE);
				TxtReuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtReuActive", mask, TXTREUACTIVE);
				ButReuViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", mask, BUTREUVIEWAVAIL);
				ButReuViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewActive", mask, BUTREUVIEWACTIVE);
				LstReaActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstReaActive", mask, LSTREAACTIVE);
				LstWriActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstWriActive", mask, LSTWRIACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

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
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (TxtVerActive == comp.TxtVerActive) items.add(TXTVERACTIVE);
			if (ButVerViewAvail == comp.ButVerViewAvail) items.add(BUTVERVIEWAVAIL);
			if (ButVerViewActive == comp.ButVerViewActive) items.add(BUTVERVIEWACTIVE);
			if (TxtReuActive == comp.TxtReuActive) items.add(TXTREUACTIVE);
			if (ButReuViewAvail == comp.ButReuViewAvail) items.add(BUTREUVIEWAVAIL);
			if (ButReuViewActive == comp.ButReuViewActive) items.add(BUTREUVIEWACTIVE);
			if (LstReaActive == comp.LstReaActive) items.add(LSTREAACTIVE);
			if (LstWriActive == comp.LstWriActive) items.add(LSTWRIACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, LSTREAACTIVE, LSTWRIACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmBlkDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTYP = 3;
		public static final int CPTVER = 4;
		public static final int CPTREU = 5;
		public static final int CPTREA = 6;
		public static final int CPTWRI = 7;
		public static final int CPTCMT = 8;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTyp
					, String CptVer
					, String CptReu
					, String CptRea
					, String CptWri
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTyp = CptTyp;
			this.CptVer = CptVer;
			this.CptReu = CptReu;
			this.CptRea = CptRea;
			this.CptWri = CptWri;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTVER, CPTREU, CPTREA, CPTWRI, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTyp;
		public String CptVer;
		public String CptReu;
		public String CptRea;
		public String CptWri;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmBlkDetail");

			String itemtag = "TagitemWznmBlkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptReu", mask, CPTREU);
				CptRea = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptRea", mask, CPTREA);
				CptWri = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptWri", mask, CPTWRI);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);

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
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);
			if (CptReu.equals(comp.CptReu)) items.add(CPTREU);
			if (CptRea.equals(comp.CptRea)) items.add(CPTREA);
			if (CptWri.equals(comp.CptWri)) items.add(CPTWRI);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTVER, CPTREU, CPTREA, CPTWRI, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmBlkDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMBLKDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmBlkDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmBlkDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMBLKDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmBlkDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmBlkDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTREA = 4;
		public static final int FEEDFLSTWRI = 5;
		public static final int FEEDFPUPRET = 6;
		public static final int FEEDFPUPTYP = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMBLKDETAILDATA);

			contiac = new ContIac(0, 0, new ArrayList<Integer>(), new ArrayList<Integer>(), "");
			continf = new ContInf("", "", "", "", "");
			feedFLstRea = new Feed("FeedFLstRea");
			feedFLstWri = new Feed("FeedFLstWri");
			feedFPupRet = new Feed("FeedFPupRet");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0, false, false, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstRea;
		public Feed feedFLstWri;
		public Feed feedFPupRet;
		public Feed feedFPupTyp;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTREA)) ss.add("feedFLstRea");
			if (has(FEEDFLSTWRI)) ss.add("feedFLstWri");
			if (has(FEEDFPUPRET)) ss.add("feedFPupRet");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmBlkDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstRea.readXML(doc, basexpath, true)) add(FEEDFLSTREA);
				if (feedFLstWri.readXML(doc, basexpath, true)) add(FEEDFLSTWRI);
				if (feedFPupRet.readXML(doc, basexpath, true)) add(FEEDFPUPRET);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, new ArrayList<Integer>(), new ArrayList<Integer>(), "");
				continf = new ContInf("", "", "", "", "");
				feedFLstRea = new Feed("FeedFLstRea");
				feedFLstWri = new Feed("FeedFLstWri");
				feedFPupRet = new Feed("FeedFPupRet");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0, false, false, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "");
			};
		};

	};

};

