/**
  * \file PnlWznmMtdDetail.java
  * Java API code for job PnlWznmMtdDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmMtdDetail {
	/**
		* VecVDo (full: VecVWznmMtdDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTJOBVIEWCLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butjobviewclick")) return BUTJOBVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmMtdDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFCMT = 1;
		public static final int CHKEXS = 2;

		public ContIac(
					String TxfCmt
					, boolean ChkExs
				) {
			this.TxfCmt = TxfCmt;
			this.ChkExs = ChkExs;

			mask = new HashSet<Integer>(Arrays.asList(TXFCMT, CHKEXS));
		};

		public String TxfCmt;
		public boolean ChkExs;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmMtdDetail");

			String itemtag = "ContitemIacWznmMtdDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCmt", mask, TXFCMT);
				ChkExs = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkExs", mask, CHKEXS);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmMtdDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmMtdDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkExs", ChkExs);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);
			if (ChkExs == comp.ChkExs) items.add(CHKEXS);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFCMT, CHKEXS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmMtdDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTJOB = 2;

		public ContInf(
					String TxtSrf
					, String TxtJob
				) {
			this.TxtSrf = TxtSrf;
			this.TxtJob = TxtJob;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTJOB));
		};

		public String TxtSrf;
		public String TxtJob;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmMtdDetail");

			String itemtag = "ContitemInfWznmMtdDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtJob", mask, TXTJOB);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtJob.equals(comp.TxtJob)) items.add(TXTJOB);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTJOB));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmMtdDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmMtdDetail");

			String itemtag = "StatitemAppWznmMtdDetail";

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
	  * StatShr (full: StatShrWznmMtdDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int TXFCMTACTIVE = 4;
		public static final int TXTJOBACTIVE = 5;
		public static final int BUTJOBVIEWAVAIL = 6;
		public static final int BUTJOBVIEWACTIVE = 7;
		public static final int CHKEXSACTIVE = 8;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxfCmtActive
					, boolean TxtJobActive
					, boolean ButJobViewAvail
					, boolean ButJobViewActive
					, boolean ChkExsActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxfCmtActive = TxfCmtActive;
			this.TxtJobActive = TxtJobActive;
			this.ButJobViewAvail = ButJobViewAvail;
			this.ButJobViewActive = ButJobViewActive;
			this.ChkExsActive = ChkExsActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFCMTACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, CHKEXSACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxfCmtActive;
		public boolean TxtJobActive;
		public boolean ButJobViewAvail;
		public boolean ButJobViewActive;
		public boolean ChkExsActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmMtdDetail");

			String itemtag = "StatitemShrWznmMtdDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);
				TxtJobActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtJobActive", mask, TXTJOBACTIVE);
				ButJobViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJobViewAvail", mask, BUTJOBVIEWAVAIL);
				ButJobViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJobViewActive", mask, BUTJOBVIEWACTIVE);
				ChkExsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkExsActive", mask, CHKEXSACTIVE);

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
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);
			if (TxtJobActive == comp.TxtJobActive) items.add(TXTJOBACTIVE);
			if (ButJobViewAvail == comp.ButJobViewAvail) items.add(BUTJOBVIEWAVAIL);
			if (ButJobViewActive == comp.ButJobViewActive) items.add(BUTJOBVIEWACTIVE);
			if (ChkExsActive == comp.ChkExsActive) items.add(CHKEXSACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFCMTACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, CHKEXSACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmMtdDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTCMT = 3;
		public static final int CPTJOB = 4;
		public static final int CPTEXS = 5;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptCmt
					, String CptJob
					, String CptExs
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptCmt = CptCmt;
			this.CptJob = CptJob;
			this.CptExs = CptExs;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTCMT, CPTJOB, CPTEXS));
		};

		public String Cpt;
		public String CptSrf;
		public String CptCmt;
		public String CptJob;
		public String CptExs;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmMtdDetail");

			String itemtag = "TagitemWznmMtdDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);
				CptJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptJob", mask, CPTJOB);
				CptExs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptExs", mask, CPTEXS);

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
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);
			if (CptJob.equals(comp.CptJob)) items.add(CPTJOB);
			if (CptExs.equals(comp.CptExs)) items.add(CPTEXS);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTCMT, CPTJOB, CPTEXS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmMtdDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMMTDDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmMtdDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmMtdDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMMTDDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmMtdDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmMtdDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMMTDDETAILDATA);

			contiac = new ContIac("", false);
			continf = new ContInf("", "");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmMtdDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", false);
				continf = new ContInf("", "");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};
