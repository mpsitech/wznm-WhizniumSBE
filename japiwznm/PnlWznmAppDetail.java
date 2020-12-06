/**
  * \file PnlWznmAppDetail.java
  * Java API code for job PnlWznmAppDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmAppDetail {
	/**
		* VecVDo (full: VecVWznmAppDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTVERVIEWCLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butverviewclick")) return BUTVERVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmAppDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFSHO = 1;
		public static final int TXFTIT = 2;
		public static final int NUMFPUPTRG = 3;
		public static final int TXFCMT = 4;

		public ContIac(
					String TxfSho
					, String TxfTit
					, int numFPupTrg
					, String TxfCmt
				) {
			this.TxfSho = TxfSho;
			this.TxfTit = TxfTit;
			this.numFPupTrg = numFPupTrg;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(TXFSHO, TXFTIT, NUMFPUPTRG, TXFCMT));
		};

		public String TxfSho;
		public String TxfTit;
		public int numFPupTrg;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmAppDetail");

			String itemtag = "ContitemIacWznmAppDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSho", mask, TXFSHO);
				TxfTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfTit", mask, TXFTIT);
				numFPupTrg = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTrg", mask, NUMFPUPTRG);
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
			if (difftag.isEmpty()) difftag = "ContIacWznmAppDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmAppDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSho", TxfSho);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTit", TxfTit);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTrg", numFPupTrg);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfSho.equals(comp.TxfSho)) items.add(TXFSHO);
			if (TxfTit.equals(comp.TxfTit)) items.add(TXFTIT);
			if (numFPupTrg == comp.numFPupTrg) items.add(NUMFPUPTRG);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFSHO, TXFTIT, NUMFPUPTRG, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmAppDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTVER = 1;

		public ContInf(
					String TxtVer
				) {
			this.TxtVer = TxtVer;

			mask = new HashSet<Integer>(Arrays.asList(TXTVER));
		};

		public String TxtVer;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmAppDetail");

			String itemtag = "ContitemInfWznmAppDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVer", mask, TXTVER);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtVer.equals(comp.TxtVer)) items.add(TXTVER);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTVER));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmAppDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmAppDetail");

			String itemtag = "StatitemAppWznmAppDetail";

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
	  * StatShr (full: StatShrWznmAppDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXFSHOACTIVE = 3;
		public static final int TXFTITACTIVE = 4;
		public static final int PUPTRGACTIVE = 5;
		public static final int TXTVERACTIVE = 6;
		public static final int BUTVERVIEWAVAIL = 7;
		public static final int BUTVERVIEWACTIVE = 8;
		public static final int TXFCMTACTIVE = 9;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxfShoActive
					, boolean TxfTitActive
					, boolean PupTrgActive
					, boolean TxtVerActive
					, boolean ButVerViewAvail
					, boolean ButVerViewActive
					, boolean TxfCmtActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxfShoActive = TxfShoActive;
			this.TxfTitActive = TxfTitActive;
			this.PupTrgActive = PupTrgActive;
			this.TxtVerActive = TxtVerActive;
			this.ButVerViewAvail = ButVerViewAvail;
			this.ButVerViewActive = ButVerViewActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXFSHOACTIVE, TXFTITACTIVE, PUPTRGACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXFCMTACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxfShoActive;
		public boolean TxfTitActive;
		public boolean PupTrgActive;
		public boolean TxtVerActive;
		public boolean ButVerViewAvail;
		public boolean ButVerViewActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmAppDetail");

			String itemtag = "StatitemShrWznmAppDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxfShoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfShoActive", mask, TXFSHOACTIVE);
				TxfTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfTitActive", mask, TXFTITACTIVE);
				PupTrgActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTrgActive", mask, PUPTRGACTIVE);
				TxtVerActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVerActive", mask, TXTVERACTIVE);
				ButVerViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", mask, BUTVERVIEWAVAIL);
				ButVerViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewActive", mask, BUTVERVIEWACTIVE);
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
			if (TxfShoActive == comp.TxfShoActive) items.add(TXFSHOACTIVE);
			if (TxfTitActive == comp.TxfTitActive) items.add(TXFTITACTIVE);
			if (PupTrgActive == comp.PupTrgActive) items.add(PUPTRGACTIVE);
			if (TxtVerActive == comp.TxtVerActive) items.add(TXTVERACTIVE);
			if (ButVerViewAvail == comp.ButVerViewAvail) items.add(BUTVERVIEWAVAIL);
			if (ButVerViewActive == comp.ButVerViewActive) items.add(BUTVERVIEWACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXFSHOACTIVE, TXFTITACTIVE, PUPTRGACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmAppDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSHO = 2;
		public static final int CPTTIT = 3;
		public static final int CPTTRG = 4;
		public static final int CPTVER = 5;
		public static final int CPTCMT = 6;

		public Tag(
					String Cpt
					, String CptSho
					, String CptTit
					, String CptTrg
					, String CptVer
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSho = CptSho;
			this.CptTit = CptTit;
			this.CptTrg = CptTrg;
			this.CptVer = CptVer;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSHO, CPTTIT, CPTTRG, CPTVER, CPTCMT));
		};

		public String Cpt;
		public String CptSho;
		public String CptTit;
		public String CptTrg;
		public String CptVer;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmAppDetail");

			String itemtag = "TagitemWznmAppDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSho", mask, CPTSHO);
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTit", mask, CPTTIT);
				CptTrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTrg", mask, CPTTRG);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
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
			if (CptSho.equals(comp.CptSho)) items.add(CPTSHO);
			if (CptTit.equals(comp.CptTit)) items.add(CPTTIT);
			if (CptTrg.equals(comp.CptTrg)) items.add(CPTTRG);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSHO, CPTTIT, CPTTRG, CPTVER, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmAppDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMAPPDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmAppDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmAppDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMAPPDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmAppDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmAppDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPTRG = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMAPPDETAILDATA);

			contiac = new ContIac("", "", 0, "");
			continf = new ContInf("");
			feedFPupTrg = new Feed("FeedFPupTrg");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupTrg;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPTRG)) ss.add("feedFPupTrg");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmAppDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupTrg.readXML(doc, basexpath, true)) add(FEEDFPUPTRG);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", 0, "");
				continf = new ContInf("");
				feedFPupTrg = new Feed("FeedFPupTrg");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};
