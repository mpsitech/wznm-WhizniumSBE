/**
  * \file PnlWznmQcoDetail.java
  * Java API code for job PnlWznmQcoDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmQcoDetail {
	/**
		* VecVDo (full: VecVWznmQcoDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTQRYVIEWCLICK = 2;
		public static final int BUTSTBVIEWCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butqryviewclick")) return BUTQRYVIEWCLICK;
			if (s.equals("butstbviewclick")) return BUTSTBVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTQRYVIEWCLICK) return("ButQryViewClick");
			if (ix == BUTSTBVIEWCLICK) return("ButStbViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmQcoDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFSHO = 1;
		public static final int NUMFPUPTYP = 2;
		public static final int NUMSFLSTOCC = 3;

		public ContIac(
					String TxfSho
					, int numFPupTyp
					, ArrayList<Integer> numsFLstOcc
				) {
			this.TxfSho = TxfSho;
			this.numFPupTyp = numFPupTyp;
			this.numsFLstOcc = numsFLstOcc;

			mask = new HashSet<Integer>(Arrays.asList(TXFSHO, NUMFPUPTYP, NUMSFLSTOCC));
		};

		public String TxfSho;
		public int numFPupTyp;
		public ArrayList<Integer> numsFLstOcc;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmQcoDetail");

			String itemtag = "ContitemIacWznmQcoDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSho", mask, TXFSHO);
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				numsFLstOcc = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstOcc", mask, NUMSFLSTOCC);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmQcoDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmQcoDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSho", TxfSho);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstOcc", numsFLstOcc);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfSho.equals(comp.TxfSho)) items.add(TXFSHO);
			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (Xmlio.compareIntegervec(numsFLstOcc, comp.numsFLstOcc)) items.add(NUMSFLSTOCC);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFSHO, NUMFPUPTYP, NUMSFLSTOCC));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmQcoDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTOCC = 2;
		public static final int TXTQRY = 3;
		public static final int TXTTCO = 4;
		public static final int TXTSTB = 5;

		public ContInf(
					String TxtSrf
					, String TxtOcc
					, String TxtQry
					, String TxtTco
					, String TxtStb
				) {
			this.TxtSrf = TxtSrf;
			this.TxtOcc = TxtOcc;
			this.TxtQry = TxtQry;
			this.TxtTco = TxtTco;
			this.TxtStb = TxtStb;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTOCC, TXTQRY, TXTTCO, TXTSTB));
		};

		public String TxtSrf;
		public String TxtOcc;
		public String TxtQry;
		public String TxtTco;
		public String TxtStb;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmQcoDetail");

			String itemtag = "ContitemInfWznmQcoDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtOcc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtOcc", mask, TXTOCC);
				TxtQry = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtQry", mask, TXTQRY);
				TxtTco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTco", mask, TXTTCO);
				TxtStb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtStb", mask, TXTSTB);

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
			if (TxtQry.equals(comp.TxtQry)) items.add(TXTQRY);
			if (TxtTco.equals(comp.TxtTco)) items.add(TXTTCO);
			if (TxtStb.equals(comp.TxtStb)) items.add(TXTSTB);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTOCC, TXTQRY, TXTTCO, TXTSTB));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmQcoDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmQcoDetail");

			String itemtag = "StatitemAppWznmQcoDetail";

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
	  * StatShr (full: StatShrWznmQcoDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int TXFSHOACTIVE = 4;
		public static final int PUPTYPACTIVE = 5;
		public static final int LSTOCCACTIVE = 6;
		public static final int TXTQRYACTIVE = 7;
		public static final int BUTQRYVIEWAVAIL = 8;
		public static final int BUTQRYVIEWACTIVE = 9;
		public static final int TXTTCOACTIVE = 10;
		public static final int TXTSTBACTIVE = 11;
		public static final int BUTSTBVIEWAVAIL = 12;
		public static final int BUTSTBVIEWACTIVE = 13;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxfShoActive
					, boolean PupTypActive
					, boolean LstOccActive
					, boolean TxtQryActive
					, boolean ButQryViewAvail
					, boolean ButQryViewActive
					, boolean TxtTcoActive
					, boolean TxtStbActive
					, boolean ButStbViewAvail
					, boolean ButStbViewActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxfShoActive = TxfShoActive;
			this.PupTypActive = PupTypActive;
			this.LstOccActive = LstOccActive;
			this.TxtQryActive = TxtQryActive;
			this.ButQryViewAvail = ButQryViewAvail;
			this.ButQryViewActive = ButQryViewActive;
			this.TxtTcoActive = TxtTcoActive;
			this.TxtStbActive = TxtStbActive;
			this.ButStbViewAvail = ButStbViewAvail;
			this.ButStbViewActive = ButStbViewActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, LSTOCCACTIVE, TXTQRYACTIVE, BUTQRYVIEWAVAIL, BUTQRYVIEWACTIVE, TXTTCOACTIVE, TXTSTBACTIVE, BUTSTBVIEWAVAIL, BUTSTBVIEWACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxfShoActive;
		public boolean PupTypActive;
		public boolean LstOccActive;
		public boolean TxtQryActive;
		public boolean ButQryViewAvail;
		public boolean ButQryViewActive;
		public boolean TxtTcoActive;
		public boolean TxtStbActive;
		public boolean ButStbViewAvail;
		public boolean ButStbViewActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmQcoDetail");

			String itemtag = "StatitemShrWznmQcoDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxfShoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfShoActive", mask, TXFSHOACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				LstOccActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOccActive", mask, LSTOCCACTIVE);
				TxtQryActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtQryActive", mask, TXTQRYACTIVE);
				ButQryViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButQryViewAvail", mask, BUTQRYVIEWAVAIL);
				ButQryViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButQryViewActive", mask, BUTQRYVIEWACTIVE);
				TxtTcoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTcoActive", mask, TXTTCOACTIVE);
				TxtStbActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtStbActive", mask, TXTSTBACTIVE);
				ButStbViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStbViewAvail", mask, BUTSTBVIEWAVAIL);
				ButStbViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStbViewActive", mask, BUTSTBVIEWACTIVE);

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
			if (TxtQryActive == comp.TxtQryActive) items.add(TXTQRYACTIVE);
			if (ButQryViewAvail == comp.ButQryViewAvail) items.add(BUTQRYVIEWAVAIL);
			if (ButQryViewActive == comp.ButQryViewActive) items.add(BUTQRYVIEWACTIVE);
			if (TxtTcoActive == comp.TxtTcoActive) items.add(TXTTCOACTIVE);
			if (TxtStbActive == comp.TxtStbActive) items.add(TXTSTBACTIVE);
			if (ButStbViewAvail == comp.ButStbViewAvail) items.add(BUTSTBVIEWAVAIL);
			if (ButStbViewActive == comp.ButStbViewActive) items.add(BUTSTBVIEWACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, LSTOCCACTIVE, TXTQRYACTIVE, BUTQRYVIEWAVAIL, BUTQRYVIEWACTIVE, TXTTCOACTIVE, TXTSTBACTIVE, BUTSTBVIEWAVAIL, BUTSTBVIEWACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmQcoDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTSHO = 3;
		public static final int CPTTYP = 4;
		public static final int CPTOCC = 5;
		public static final int CPTQRY = 6;
		public static final int CPTTCO = 7;
		public static final int CPTSTB = 8;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptSho
					, String CptTyp
					, String CptOcc
					, String CptQry
					, String CptTco
					, String CptStb
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptSho = CptSho;
			this.CptTyp = CptTyp;
			this.CptOcc = CptOcc;
			this.CptQry = CptQry;
			this.CptTco = CptTco;
			this.CptStb = CptStb;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSHO, CPTTYP, CPTOCC, CPTQRY, CPTTCO, CPTSTB));
		};

		public String Cpt;
		public String CptSrf;
		public String CptSho;
		public String CptTyp;
		public String CptOcc;
		public String CptQry;
		public String CptTco;
		public String CptStb;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmQcoDetail");

			String itemtag = "TagitemWznmQcoDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSho", mask, CPTSHO);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptOcc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOcc", mask, CPTOCC);
				CptQry = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptQry", mask, CPTQRY);
				CptTco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTco", mask, CPTTCO);
				CptStb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptStb", mask, CPTSTB);

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
			if (CptQry.equals(comp.CptQry)) items.add(CPTQRY);
			if (CptTco.equals(comp.CptTco)) items.add(CPTTCO);
			if (CptStb.equals(comp.CptStb)) items.add(CPTSTB);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSHO, CPTTYP, CPTOCC, CPTQRY, CPTTCO, CPTSTB));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmQcoDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMQCODETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmQcoDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmQcoDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMQCODETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmQcoDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmQcoDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTOCC = 4;
		public static final int FEEDFPUPTYP = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMQCODETAILDATA);

			contiac = new ContIac("", 0, new ArrayList<Integer>());
			continf = new ContInf("", "", "", "", "");
			feedFLstOcc = new Feed("FeedFLstOcc");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstOcc;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmQcoDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstOcc.readXML(doc, basexpath, true)) add(FEEDFLSTOCC);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", 0, new ArrayList<Integer>());
				continf = new ContInf("", "", "", "", "");
				feedFLstOcc = new Feed("FeedFLstOcc");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "");
			};
		};

	};

};

