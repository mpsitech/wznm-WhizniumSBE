/**
  * \file PnlWznmStbDetail.java
  * Java API code for job PnlWznmStbDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmStbDetail {
	/**
		* VecVDo (full: VecVWznmStbDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTSBSVIEWCLICK = 2;
		public static final int BUTTCOVIEWCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butsbsviewclick")) return BUTSBSVIEWCLICK;
			if (s.equals("buttcoviewclick")) return BUTTCOVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTSBSVIEWCLICK) return("ButSbsViewClick");
			if (ix == BUTTCOVIEWCLICK) return("ButTcoViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmStbDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPTYP = 1;
		public static final int CHKHRC = 2;
		public static final int CHKLCL = 3;
		public static final int TXFEXA = 4;

		public ContIac(
					int numFPupTyp
					, boolean ChkHrc
					, boolean ChkLcl
					, String TxfExa
				) {
			this.numFPupTyp = numFPupTyp;
			this.ChkHrc = ChkHrc;
			this.ChkLcl = ChkLcl;
			this.TxfExa = TxfExa;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, CHKHRC, CHKLCL, TXFEXA));
		};

		public int numFPupTyp;
		public boolean ChkHrc;
		public boolean ChkLcl;
		public String TxfExa;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmStbDetail");

			String itemtag = "ContitemIacWznmStbDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				ChkHrc = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkHrc", mask, CHKHRC);
				ChkLcl = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkLcl", mask, CHKLCL);
				TxfExa = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfExa", mask, TXFEXA);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmStbDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmStbDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkHrc", ChkHrc);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkLcl", ChkLcl);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfExa", TxfExa);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (ChkHrc == comp.ChkHrc) items.add(CHKHRC);
			if (ChkLcl == comp.ChkLcl) items.add(CHKLCL);
			if (TxfExa.equals(comp.TxfExa)) items.add(TXFEXA);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, CHKHRC, CHKLCL, TXFEXA));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmStbDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTTBL = 2;
		public static final int TXTSBS = 3;
		public static final int TXTTCO = 4;

		public ContInf(
					String TxtSrf
					, String TxtTbl
					, String TxtSbs
					, String TxtTco
				) {
			this.TxtSrf = TxtSrf;
			this.TxtTbl = TxtTbl;
			this.TxtSbs = TxtSbs;
			this.TxtTco = TxtTco;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTBL, TXTSBS, TXTTCO));
		};

		public String TxtSrf;
		public String TxtTbl;
		public String TxtSbs;
		public String TxtTco;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmStbDetail");

			String itemtag = "ContitemInfWznmStbDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTbl", mask, TXTTBL);
				TxtSbs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSbs", mask, TXTSBS);
				TxtTco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTco", mask, TXTTCO);

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
			if (TxtTco.equals(comp.TxtTco)) items.add(TXTTCO);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTBL, TXTSBS, TXTTCO));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmStbDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;

		public StatApp(
					int ixWznmVExpstate
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE));
		};

		public int ixWznmVExpstate;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmStbDetail");

			String itemtag = "StatitemAppWznmStbDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmStbDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int PUPTYPACTIVE = 4;
		public static final int TXTTBLACTIVE = 5;
		public static final int TXTSBSACTIVE = 6;
		public static final int BUTSBSVIEWAVAIL = 7;
		public static final int BUTSBSVIEWACTIVE = 8;
		public static final int CHKHRCACTIVE = 9;
		public static final int TXTTCOACTIVE = 10;
		public static final int BUTTCOVIEWAVAIL = 11;
		public static final int BUTTCOVIEWACTIVE = 12;
		public static final int CHKLCLACTIVE = 13;
		public static final int TXFEXAACTIVE = 14;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupTypActive
					, boolean TxtTblActive
					, boolean TxtSbsActive
					, boolean ButSbsViewAvail
					, boolean ButSbsViewActive
					, boolean ChkHrcActive
					, boolean TxtTcoActive
					, boolean ButTcoViewAvail
					, boolean ButTcoViewActive
					, boolean ChkLclActive
					, boolean TxfExaActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupTypActive = PupTypActive;
			this.TxtTblActive = TxtTblActive;
			this.TxtSbsActive = TxtSbsActive;
			this.ButSbsViewAvail = ButSbsViewAvail;
			this.ButSbsViewActive = ButSbsViewActive;
			this.ChkHrcActive = ChkHrcActive;
			this.TxtTcoActive = TxtTcoActive;
			this.ButTcoViewAvail = ButTcoViewAvail;
			this.ButTcoViewActive = ButTcoViewActive;
			this.ChkLclActive = ChkLclActive;
			this.TxfExaActive = TxfExaActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTTBLACTIVE, TXTSBSACTIVE, BUTSBSVIEWAVAIL, BUTSBSVIEWACTIVE, CHKHRCACTIVE, TXTTCOACTIVE, BUTTCOVIEWAVAIL, BUTTCOVIEWACTIVE, CHKLCLACTIVE, TXFEXAACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupTypActive;
		public boolean TxtTblActive;
		public boolean TxtSbsActive;
		public boolean ButSbsViewAvail;
		public boolean ButSbsViewActive;
		public boolean ChkHrcActive;
		public boolean TxtTcoActive;
		public boolean ButTcoViewAvail;
		public boolean ButTcoViewActive;
		public boolean ChkLclActive;
		public boolean TxfExaActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmStbDetail");

			String itemtag = "StatitemShrWznmStbDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				TxtTblActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTblActive", mask, TXTTBLACTIVE);
				TxtSbsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSbsActive", mask, TXTSBSACTIVE);
				ButSbsViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSbsViewAvail", mask, BUTSBSVIEWAVAIL);
				ButSbsViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSbsViewActive", mask, BUTSBSVIEWACTIVE);
				ChkHrcActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkHrcActive", mask, CHKHRCACTIVE);
				TxtTcoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTcoActive", mask, TXTTCOACTIVE);
				ButTcoViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTcoViewAvail", mask, BUTTCOVIEWAVAIL);
				ButTcoViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTcoViewActive", mask, BUTTCOVIEWACTIVE);
				ChkLclActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkLclActive", mask, CHKLCLACTIVE);
				TxfExaActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfExaActive", mask, TXFEXAACTIVE);

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
			if (TxtTblActive == comp.TxtTblActive) items.add(TXTTBLACTIVE);
			if (TxtSbsActive == comp.TxtSbsActive) items.add(TXTSBSACTIVE);
			if (ButSbsViewAvail == comp.ButSbsViewAvail) items.add(BUTSBSVIEWAVAIL);
			if (ButSbsViewActive == comp.ButSbsViewActive) items.add(BUTSBSVIEWACTIVE);
			if (ChkHrcActive == comp.ChkHrcActive) items.add(CHKHRCACTIVE);
			if (TxtTcoActive == comp.TxtTcoActive) items.add(TXTTCOACTIVE);
			if (ButTcoViewAvail == comp.ButTcoViewAvail) items.add(BUTTCOVIEWAVAIL);
			if (ButTcoViewActive == comp.ButTcoViewActive) items.add(BUTTCOVIEWACTIVE);
			if (ChkLclActive == comp.ChkLclActive) items.add(CHKLCLACTIVE);
			if (TxfExaActive == comp.TxfExaActive) items.add(TXFEXAACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTTBLACTIVE, TXTSBSACTIVE, BUTSBSVIEWAVAIL, BUTSBSVIEWACTIVE, CHKHRCACTIVE, TXTTCOACTIVE, BUTTCOVIEWAVAIL, BUTTCOVIEWACTIVE, CHKLCLACTIVE, TXFEXAACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmStbDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTYP = 3;
		public static final int CPTTBL = 4;
		public static final int CPTSBS = 5;
		public static final int CPTHRC = 6;
		public static final int CPTTCO = 7;
		public static final int CPTLCL = 8;
		public static final int CPTEXA = 9;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTyp
					, String CptTbl
					, String CptSbs
					, String CptHrc
					, String CptTco
					, String CptLcl
					, String CptExa
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTyp = CptTyp;
			this.CptTbl = CptTbl;
			this.CptSbs = CptSbs;
			this.CptHrc = CptHrc;
			this.CptTco = CptTco;
			this.CptLcl = CptLcl;
			this.CptExa = CptExa;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTTBL, CPTSBS, CPTHRC, CPTTCO, CPTLCL, CPTEXA));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTyp;
		public String CptTbl;
		public String CptSbs;
		public String CptHrc;
		public String CptTco;
		public String CptLcl;
		public String CptExa;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmStbDetail");

			String itemtag = "TagitemWznmStbDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTbl", mask, CPTTBL);
				CptSbs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSbs", mask, CPTSBS);
				CptHrc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptHrc", mask, CPTHRC);
				CptTco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTco", mask, CPTTCO);
				CptLcl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLcl", mask, CPTLCL);
				CptExa = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptExa", mask, CPTEXA);

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
			if (CptTbl.equals(comp.CptTbl)) items.add(CPTTBL);
			if (CptSbs.equals(comp.CptSbs)) items.add(CPTSBS);
			if (CptHrc.equals(comp.CptHrc)) items.add(CPTHRC);
			if (CptTco.equals(comp.CptTco)) items.add(CPTTCO);
			if (CptLcl.equals(comp.CptLcl)) items.add(CPTLCL);
			if (CptExa.equals(comp.CptExa)) items.add(CPTEXA);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTTBL, CPTSBS, CPTHRC, CPTTCO, CPTLCL, CPTEXA));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmStbDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMSTBDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmStbDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmStbDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMSTBDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmStbDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmStbDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPTYP = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMSTBDETAILDATA);

			contiac = new ContIac(0, false, false, "");
			continf = new ContInf("", "", "", "");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupTyp;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmStbDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, false, false, "");
				continf = new ContInf("", "", "", "");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "");
			};
		};

	};

};
