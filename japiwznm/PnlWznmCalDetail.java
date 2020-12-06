/**
  * \file PnlWznmCalDetail.java
  * Java API code for job PnlWznmCalDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmCalDetail {
	/**
		* VecVDo (full: VecVWznmCalDetailDo)
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
	  * ContIac (full: ContIacWznmCalDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPTYP = 1;
		public static final int NUMFPUPRET = 2;
		public static final int NUMSFLSTIAT = 3;
		public static final int NUMSFLSTRAT = 4;
		public static final int TXFCMT = 5;

		public ContIac(
					int numFPupTyp
					, int numFPupRet
					, ArrayList<Integer> numsFLstIat
					, ArrayList<Integer> numsFLstRat
					, String TxfCmt
				) {
			this.numFPupTyp = numFPupTyp;
			this.numFPupRet = numFPupRet;
			this.numsFLstIat = numsFLstIat;
			this.numsFLstRat = numsFLstRat;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, NUMFPUPRET, NUMSFLSTIAT, NUMSFLSTRAT, TXFCMT));
		};

		public int numFPupTyp;
		public int numFPupRet;
		public ArrayList<Integer> numsFLstIat;
		public ArrayList<Integer> numsFLstRat;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmCalDetail");

			String itemtag = "ContitemIacWznmCalDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				numFPupRet = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupRet", mask, NUMFPUPRET);
				numsFLstIat = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstIat", mask, NUMSFLSTIAT);
				numsFLstRat = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstRat", mask, NUMSFLSTRAT);
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
			if (difftag.isEmpty()) difftag = "ContIacWznmCalDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmCalDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupRet", numFPupRet);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstIat", numsFLstIat);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstRat", numsFLstRat);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (numFPupRet == comp.numFPupRet) items.add(NUMFPUPRET);
			if (Xmlio.compareIntegervec(numsFLstIat, comp.numsFLstIat)) items.add(NUMSFLSTIAT);
			if (Xmlio.compareIntegervec(numsFLstRat, comp.numsFLstRat)) items.add(NUMSFLSTRAT);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, NUMFPUPRET, NUMSFLSTIAT, NUMSFLSTRAT, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmCalDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTVER = 2;
		public static final int TXTREU = 3;
		public static final int TXTIAT = 4;
		public static final int TXTRAT = 5;

		public ContInf(
					String TxtSrf
					, String TxtVer
					, String TxtReu
					, String TxtIat
					, String TxtRat
				) {
			this.TxtSrf = TxtSrf;
			this.TxtVer = TxtVer;
			this.TxtReu = TxtReu;
			this.TxtIat = TxtIat;
			this.TxtRat = TxtRat;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTVER, TXTREU, TXTIAT, TXTRAT));
		};

		public String TxtSrf;
		public String TxtVer;
		public String TxtReu;
		public String TxtIat;
		public String TxtRat;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmCalDetail");

			String itemtag = "ContitemInfWznmCalDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVer", mask, TXTVER);
				TxtReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtReu", mask, TXTREU);
				TxtIat = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtIat", mask, TXTIAT);
				TxtRat = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtRat", mask, TXTRAT);

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
			if (TxtIat.equals(comp.TxtIat)) items.add(TXTIAT);
			if (TxtRat.equals(comp.TxtRat)) items.add(TXTRAT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTVER, TXTREU, TXTIAT, TXTRAT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmCalDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTIATALT = 2;
		public static final int LSTRATALT = 3;
		public static final int LSTIATNUMFIRSTDISP = 4;
		public static final int LSTRATNUMFIRSTDISP = 5;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstIatAlt
					, boolean LstRatAlt
					, int LstIatNumFirstdisp
					, int LstRatNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstIatAlt = LstIatAlt;
			this.LstRatAlt = LstRatAlt;
			this.LstIatNumFirstdisp = LstIatNumFirstdisp;
			this.LstRatNumFirstdisp = LstRatNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTIATALT, LSTRATALT, LSTIATNUMFIRSTDISP, LSTRATNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstIatAlt;
		public boolean LstRatAlt;
		public int LstIatNumFirstdisp;
		public int LstRatNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmCalDetail");

			String itemtag = "StatitemAppWznmCalDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstIatAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIatAlt", mask, LSTIATALT);
				LstRatAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRatAlt", mask, LSTRATALT);
				LstIatNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIatNumFirstdisp", mask, LSTIATNUMFIRSTDISP);
				LstRatNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRatNumFirstdisp", mask, LSTRATNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstIatAlt == comp.LstIatAlt) items.add(LSTIATALT);
			if (LstRatAlt == comp.LstRatAlt) items.add(LSTRATALT);
			if (LstIatNumFirstdisp == comp.LstIatNumFirstdisp) items.add(LSTIATNUMFIRSTDISP);
			if (LstRatNumFirstdisp == comp.LstRatNumFirstdisp) items.add(LSTRATNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTIATALT, LSTRATALT, LSTIATNUMFIRSTDISP, LSTRATNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmCalDetail)
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
		public static final int LSTIATACTIVE = 11;
		public static final int LSTRATACTIVE = 12;
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
					, boolean LstIatActive
					, boolean LstRatActive
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
			this.LstIatActive = LstIatActive;
			this.LstRatActive = LstRatActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, LSTIATACTIVE, LSTRATACTIVE, TXFCMTACTIVE));
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
		public boolean LstIatActive;
		public boolean LstRatActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmCalDetail");

			String itemtag = "StatitemShrWznmCalDetail";

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
				LstIatActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIatActive", mask, LSTIATACTIVE);
				LstRatActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRatActive", mask, LSTRATACTIVE);
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
			if (LstIatActive == comp.LstIatActive) items.add(LSTIATACTIVE);
			if (LstRatActive == comp.LstRatActive) items.add(LSTRATACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, LSTIATACTIVE, LSTRATACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmCalDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTYP = 3;
		public static final int CPTVER = 4;
		public static final int CPTREU = 5;
		public static final int CPTIAT = 6;
		public static final int CPTRAT = 7;
		public static final int CPTCMT = 8;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTyp
					, String CptVer
					, String CptReu
					, String CptIat
					, String CptRat
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTyp = CptTyp;
			this.CptVer = CptVer;
			this.CptReu = CptReu;
			this.CptIat = CptIat;
			this.CptRat = CptRat;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTVER, CPTREU, CPTIAT, CPTRAT, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTyp;
		public String CptVer;
		public String CptReu;
		public String CptIat;
		public String CptRat;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmCalDetail");

			String itemtag = "TagitemWznmCalDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptReu", mask, CPTREU);
				CptIat = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIat", mask, CPTIAT);
				CptRat = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptRat", mask, CPTRAT);
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
			if (CptIat.equals(comp.CptIat)) items.add(CPTIAT);
			if (CptRat.equals(comp.CptRat)) items.add(CPTRAT);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTVER, CPTREU, CPTIAT, CPTRAT, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmCalDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMCALDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmCalDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmCalDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMCALDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmCalDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmCalDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTIAT = 4;
		public static final int FEEDFLSTRAT = 5;
		public static final int FEEDFPUPRET = 6;
		public static final int FEEDFPUPTYP = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMCALDETAILDATA);

			contiac = new ContIac(0, 0, new ArrayList<Integer>(), new ArrayList<Integer>(), "");
			continf = new ContInf("", "", "", "", "");
			feedFLstIat = new Feed("FeedFLstIat");
			feedFLstRat = new Feed("FeedFLstRat");
			feedFPupRet = new Feed("FeedFPupRet");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0, false, false, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstIat;
		public Feed feedFLstRat;
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
			if (has(FEEDFLSTIAT)) ss.add("feedFLstIat");
			if (has(FEEDFLSTRAT)) ss.add("feedFLstRat");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmCalDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstIat.readXML(doc, basexpath, true)) add(FEEDFLSTIAT);
				if (feedFLstRat.readXML(doc, basexpath, true)) add(FEEDFLSTRAT);
				if (feedFPupRet.readXML(doc, basexpath, true)) add(FEEDFPUPRET);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, new ArrayList<Integer>(), new ArrayList<Integer>(), "");
				continf = new ContInf("", "", "", "", "");
				feedFLstIat = new Feed("FeedFLstIat");
				feedFLstRat = new Feed("FeedFLstRat");
				feedFPupRet = new Feed("FeedFPupRet");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0, false, false, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "");
			};
		};

	};

};
