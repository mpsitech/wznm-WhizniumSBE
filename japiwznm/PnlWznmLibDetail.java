/**
  * \file PnlWznmLibDetail.java
  * Java API code for job PnlWznmLibDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmLibDetail {
	/**
		* VecVDo (full: VecVWznmLibDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTLTYEDITCLICK = 2;
		public static final int BUTDEPVIEWCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butltyeditclick")) return BUTLTYEDITCLICK;
			if (s.equals("butdepviewclick")) return BUTDEPVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTLTYEDITCLICK) return("ButLtyEditClick");
			if (ix == BUTDEPVIEWCLICK) return("ButDepViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmLibDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFTIT = 1;
		public static final int TXFVER = 2;
		public static final int NUMFPUPLTY = 3;
		public static final int TXFLTY = 4;
		public static final int NUMFLSTDEP = 5;
		public static final int TXFDEP = 6;
		public static final int TXFCMT = 7;

		public ContIac(
					String TxfTit
					, String TxfVer
					, int numFPupLty
					, String TxfLty
					, int numFLstDep
					, String TxfDep
					, String TxfCmt
				) {
			this.TxfTit = TxfTit;
			this.TxfVer = TxfVer;
			this.numFPupLty = numFPupLty;
			this.TxfLty = TxfLty;
			this.numFLstDep = numFLstDep;
			this.TxfDep = TxfDep;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(TXFTIT, TXFVER, NUMFPUPLTY, TXFLTY, NUMFLSTDEP, TXFDEP, TXFCMT));
		};

		public String TxfTit;
		public String TxfVer;
		public int numFPupLty;
		public String TxfLty;
		public int numFLstDep;
		public String TxfDep;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmLibDetail");

			String itemtag = "ContitemIacWznmLibDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfTit", mask, TXFTIT);
				TxfVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfVer", mask, TXFVER);
				numFPupLty = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupLty", mask, NUMFPUPLTY);
				TxfLty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfLty", mask, TXFLTY);
				numFLstDep = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstDep", mask, NUMFLSTDEP);
				TxfDep = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfDep", mask, TXFDEP);
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
			if (difftag.isEmpty()) difftag = "ContIacWznmLibDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmLibDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTit", TxfTit);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfVer", TxfVer);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupLty", numFPupLty);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfLty", TxfLty);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstDep", numFLstDep);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfDep", TxfDep);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfTit.equals(comp.TxfTit)) items.add(TXFTIT);
			if (TxfVer.equals(comp.TxfVer)) items.add(TXFVER);
			if (numFPupLty == comp.numFPupLty) items.add(NUMFPUPLTY);
			if (TxfLty.equals(comp.TxfLty)) items.add(TXFLTY);
			if (numFLstDep == comp.numFLstDep) items.add(NUMFLSTDEP);
			if (TxfDep.equals(comp.TxfDep)) items.add(TXFDEP);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFTIT, TXFVER, NUMFPUPLTY, TXFLTY, NUMFLSTDEP, TXFDEP, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmLibDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;

		public ContInf(
					String TxtSrf
				) {
			this.TxtSrf = TxtSrf;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF));
		};

		public String TxtSrf;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmLibDetail");

			String itemtag = "ContitemInfWznmLibDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmLibDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int PUPLTYALT = 2;
		public static final int LSTDEPALT = 3;
		public static final int LSTDEPNUMFIRSTDISP = 4;

		public StatApp(
					int ixWznmVExpstate
					, boolean PupLtyAlt
					, boolean LstDepAlt
					, int LstDepNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.PupLtyAlt = PupLtyAlt;
			this.LstDepAlt = LstDepAlt;
			this.LstDepNumFirstdisp = LstDepNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, PUPLTYALT, LSTDEPALT, LSTDEPNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean PupLtyAlt;
		public boolean LstDepAlt;
		public int LstDepNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmLibDetail");

			String itemtag = "StatitemAppWznmLibDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				PupLtyAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupLtyAlt", mask, PUPLTYALT);
				LstDepAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDepAlt", mask, LSTDEPALT);
				LstDepNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDepNumFirstdisp", mask, LSTDEPNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (PupLtyAlt == comp.PupLtyAlt) items.add(PUPLTYALT);
			if (LstDepAlt == comp.LstDepAlt) items.add(LSTDEPALT);
			if (LstDepNumFirstdisp == comp.LstDepNumFirstdisp) items.add(LSTDEPNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, PUPLTYALT, LSTDEPALT, LSTDEPNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmLibDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int TXFTITACTIVE = 4;
		public static final int TXFVERACTIVE = 5;
		public static final int PUPLTYACTIVE = 6;
		public static final int TXFLTYVALID = 7;
		public static final int BUTLTYEDITAVAIL = 8;
		public static final int LSTDEPACTIVE = 9;
		public static final int TXFDEPVALID = 10;
		public static final int BUTDEPVIEWAVAIL = 11;
		public static final int BUTDEPVIEWACTIVE = 12;
		public static final int TXFCMTACTIVE = 13;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxfTitActive
					, boolean TxfVerActive
					, boolean PupLtyActive
					, boolean TxfLtyValid
					, boolean ButLtyEditAvail
					, boolean LstDepActive
					, boolean TxfDepValid
					, boolean ButDepViewAvail
					, boolean ButDepViewActive
					, boolean TxfCmtActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxfTitActive = TxfTitActive;
			this.TxfVerActive = TxfVerActive;
			this.PupLtyActive = PupLtyActive;
			this.TxfLtyValid = TxfLtyValid;
			this.ButLtyEditAvail = ButLtyEditAvail;
			this.LstDepActive = LstDepActive;
			this.TxfDepValid = TxfDepValid;
			this.ButDepViewAvail = ButDepViewAvail;
			this.ButDepViewActive = ButDepViewActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXFVERACTIVE, PUPLTYACTIVE, TXFLTYVALID, BUTLTYEDITAVAIL, LSTDEPACTIVE, TXFDEPVALID, BUTDEPVIEWAVAIL, BUTDEPVIEWACTIVE, TXFCMTACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxfTitActive;
		public boolean TxfVerActive;
		public boolean PupLtyActive;
		public boolean TxfLtyValid;
		public boolean ButLtyEditAvail;
		public boolean LstDepActive;
		public boolean TxfDepValid;
		public boolean ButDepViewAvail;
		public boolean ButDepViewActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmLibDetail");

			String itemtag = "StatitemShrWznmLibDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxfTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfTitActive", mask, TXFTITACTIVE);
				TxfVerActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfVerActive", mask, TXFVERACTIVE);
				PupLtyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupLtyActive", mask, PUPLTYACTIVE);
				TxfLtyValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfLtyValid", mask, TXFLTYVALID);
				ButLtyEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButLtyEditAvail", mask, BUTLTYEDITAVAIL);
				LstDepActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDepActive", mask, LSTDEPACTIVE);
				TxfDepValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfDepValid", mask, TXFDEPVALID);
				ButDepViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDepViewAvail", mask, BUTDEPVIEWAVAIL);
				ButDepViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDepViewActive", mask, BUTDEPVIEWACTIVE);
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
			if (TxfTitActive == comp.TxfTitActive) items.add(TXFTITACTIVE);
			if (TxfVerActive == comp.TxfVerActive) items.add(TXFVERACTIVE);
			if (PupLtyActive == comp.PupLtyActive) items.add(PUPLTYACTIVE);
			if (TxfLtyValid == comp.TxfLtyValid) items.add(TXFLTYVALID);
			if (ButLtyEditAvail == comp.ButLtyEditAvail) items.add(BUTLTYEDITAVAIL);
			if (LstDepActive == comp.LstDepActive) items.add(LSTDEPACTIVE);
			if (TxfDepValid == comp.TxfDepValid) items.add(TXFDEPVALID);
			if (ButDepViewAvail == comp.ButDepViewAvail) items.add(BUTDEPVIEWAVAIL);
			if (ButDepViewActive == comp.ButDepViewActive) items.add(BUTDEPVIEWACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXFVERACTIVE, PUPLTYACTIVE, TXFLTYVALID, BUTLTYEDITAVAIL, LSTDEPACTIVE, TXFDEPVALID, BUTDEPVIEWAVAIL, BUTDEPVIEWACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmLibDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTIT = 3;
		public static final int CPTVER = 4;
		public static final int CPTLTY = 5;
		public static final int CPTDEP = 6;
		public static final int CPTCMT = 7;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTit
					, String CptVer
					, String CptLty
					, String CptDep
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTit = CptTit;
			this.CptVer = CptVer;
			this.CptLty = CptLty;
			this.CptDep = CptDep;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTVER, CPTLTY, CPTDEP, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTit;
		public String CptVer;
		public String CptLty;
		public String CptDep;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmLibDetail");

			String itemtag = "TagitemWznmLibDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTit", mask, CPTTIT);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptLty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLty", mask, CPTLTY);
				CptDep = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDep", mask, CPTDEP);
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
			if (CptTit.equals(comp.CptTit)) items.add(CPTTIT);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);
			if (CptLty.equals(comp.CptLty)) items.add(CPTLTY);
			if (CptDep.equals(comp.CptDep)) items.add(CPTDEP);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTVER, CPTLTY, CPTDEP, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmLibDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMLIBDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmLibDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmLibDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMLIBDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmLibDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmLibDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTDEP = 4;
		public static final int FEEDFPUPLTY = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMLIBDETAILDATA);

			contiac = new ContIac("", "", 0, "", 0, "", "");
			continf = new ContInf("");
			feedFLstDep = new Feed("FeedFLstDep");
			feedFPupLty = new Feed("FeedFPupLty");
			statapp = new StatApp(0, false, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstDep;
		public Feed feedFPupLty;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTDEP)) ss.add("feedFLstDep");
			if (has(FEEDFPUPLTY)) ss.add("feedFPupLty");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmLibDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstDep.readXML(doc, basexpath, true)) add(FEEDFLSTDEP);
				if (feedFPupLty.readXML(doc, basexpath, true)) add(FEEDFPUPLTY);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", 0, "", 0, "", "");
				continf = new ContInf("");
				feedFLstDep = new Feed("FeedFLstDep");
				feedFPupLty = new Feed("FeedFPupLty");
				statapp = new StatApp(0, false, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "");
			};
		};

	};

};
