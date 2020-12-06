/**
  * \file PnlWznmIexDetail.java
  * Java API code for job PnlWznmIexDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmIexDetail {
	/**
		* VecVDo (full: VecVWznmIexDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTJTIEDITCLICK = 2;
		public static final int BUTVERVIEWCLICK = 3;
		public static final int BUTJOBVIEWCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butjtieditclick")) return BUTJTIEDITCLICK;
			if (s.equals("butverviewclick")) return BUTVERVIEWCLICK;
			if (s.equals("butjobviewclick")) return BUTJOBVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTJTIEDITCLICK) return("ButJtiEditClick");
			if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
			if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmIexDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFSHO = 1;
		public static final int NUMFPUPJTI = 2;
		public static final int TXFMIV = 3;
		public static final int TXFCMT = 4;

		public ContIac(
					String TxfSho
					, int numFPupJti
					, String TxfMiv
					, String TxfCmt
				) {
			this.TxfSho = TxfSho;
			this.numFPupJti = numFPupJti;
			this.TxfMiv = TxfMiv;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(TXFSHO, NUMFPUPJTI, TXFMIV, TXFCMT));
		};

		public String TxfSho;
		public int numFPupJti;
		public String TxfMiv;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmIexDetail");

			String itemtag = "ContitemIacWznmIexDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSho", mask, TXFSHO);
				numFPupJti = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupJti", mask, NUMFPUPJTI);
				TxfMiv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfMiv", mask, TXFMIV);
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
			if (difftag.isEmpty()) difftag = "ContIacWznmIexDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmIexDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSho", TxfSho);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupJti", numFPupJti);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMiv", TxfMiv);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfSho.equals(comp.TxfSho)) items.add(TXFSHO);
			if (numFPupJti == comp.numFPupJti) items.add(NUMFPUPJTI);
			if (TxfMiv.equals(comp.TxfMiv)) items.add(TXFMIV);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFSHO, NUMFPUPJTI, TXFMIV, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmIexDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTTIT = 2;
		public static final int TXTVER = 3;
		public static final int TXTJOB = 4;

		public ContInf(
					String TxtSrf
					, String TxtTit
					, String TxtVer
					, String TxtJob
				) {
			this.TxtSrf = TxtSrf;
			this.TxtTit = TxtTit;
			this.TxtVer = TxtVer;
			this.TxtJob = TxtJob;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTIT, TXTVER, TXTJOB));
		};

		public String TxtSrf;
		public String TxtTit;
		public String TxtVer;
		public String TxtJob;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmIexDetail");

			String itemtag = "ContitemInfWznmIexDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTit", mask, TXTTIT);
				TxtVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVer", mask, TXTVER);
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
			if (TxtTit.equals(comp.TxtTit)) items.add(TXTTIT);
			if (TxtVer.equals(comp.TxtVer)) items.add(TXTVER);
			if (TxtJob.equals(comp.TxtJob)) items.add(TXTJOB);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTIT, TXTVER, TXTJOB));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmIexDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmIexDetail");

			String itemtag = "StatitemAppWznmIexDetail";

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
	  * StatShr (full: StatShrWznmIexDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int TXFSHOACTIVE = 4;
		public static final int PUPJTIACTIVE = 5;
		public static final int BUTJTIEDITAVAIL = 6;
		public static final int TXTTITACTIVE = 7;
		public static final int TXTVERACTIVE = 8;
		public static final int BUTVERVIEWAVAIL = 9;
		public static final int BUTVERVIEWACTIVE = 10;
		public static final int TXTJOBACTIVE = 11;
		public static final int BUTJOBVIEWAVAIL = 12;
		public static final int BUTJOBVIEWACTIVE = 13;
		public static final int TXFMIVACTIVE = 14;
		public static final int TXFCMTACTIVE = 15;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxfShoActive
					, boolean PupJtiActive
					, boolean ButJtiEditAvail
					, boolean TxtTitActive
					, boolean TxtVerActive
					, boolean ButVerViewAvail
					, boolean ButVerViewActive
					, boolean TxtJobActive
					, boolean ButJobViewAvail
					, boolean ButJobViewActive
					, boolean TxfMivActive
					, boolean TxfCmtActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxfShoActive = TxfShoActive;
			this.PupJtiActive = PupJtiActive;
			this.ButJtiEditAvail = ButJtiEditAvail;
			this.TxtTitActive = TxtTitActive;
			this.TxtVerActive = TxtVerActive;
			this.ButVerViewAvail = ButVerViewAvail;
			this.ButVerViewActive = ButVerViewActive;
			this.TxtJobActive = TxtJobActive;
			this.ButJobViewAvail = ButJobViewAvail;
			this.ButJobViewActive = ButJobViewActive;
			this.TxfMivActive = TxfMivActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFMIVACTIVE, TXFCMTACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxfShoActive;
		public boolean PupJtiActive;
		public boolean ButJtiEditAvail;
		public boolean TxtTitActive;
		public boolean TxtVerActive;
		public boolean ButVerViewAvail;
		public boolean ButVerViewActive;
		public boolean TxtJobActive;
		public boolean ButJobViewAvail;
		public boolean ButJobViewActive;
		public boolean TxfMivActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmIexDetail");

			String itemtag = "StatitemShrWznmIexDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxfShoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfShoActive", mask, TXFSHOACTIVE);
				PupJtiActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupJtiActive", mask, PUPJTIACTIVE);
				ButJtiEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJtiEditAvail", mask, BUTJTIEDITAVAIL);
				TxtTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTitActive", mask, TXTTITACTIVE);
				TxtVerActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVerActive", mask, TXTVERACTIVE);
				ButVerViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", mask, BUTVERVIEWAVAIL);
				ButVerViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewActive", mask, BUTVERVIEWACTIVE);
				TxtJobActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtJobActive", mask, TXTJOBACTIVE);
				ButJobViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJobViewAvail", mask, BUTJOBVIEWAVAIL);
				ButJobViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJobViewActive", mask, BUTJOBVIEWACTIVE);
				TxfMivActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfMivActive", mask, TXFMIVACTIVE);
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
			if (TxfShoActive == comp.TxfShoActive) items.add(TXFSHOACTIVE);
			if (PupJtiActive == comp.PupJtiActive) items.add(PUPJTIACTIVE);
			if (ButJtiEditAvail == comp.ButJtiEditAvail) items.add(BUTJTIEDITAVAIL);
			if (TxtTitActive == comp.TxtTitActive) items.add(TXTTITACTIVE);
			if (TxtVerActive == comp.TxtVerActive) items.add(TXTVERACTIVE);
			if (ButVerViewAvail == comp.ButVerViewAvail) items.add(BUTVERVIEWAVAIL);
			if (ButVerViewActive == comp.ButVerViewActive) items.add(BUTVERVIEWACTIVE);
			if (TxtJobActive == comp.TxtJobActive) items.add(TXTJOBACTIVE);
			if (ButJobViewAvail == comp.ButJobViewAvail) items.add(BUTJOBVIEWAVAIL);
			if (ButJobViewActive == comp.ButJobViewActive) items.add(BUTJOBVIEWACTIVE);
			if (TxfMivActive == comp.TxfMivActive) items.add(TXFMIVACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFMIVACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmIexDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTSHO = 3;
		public static final int CPTTIT = 4;
		public static final int CPTVER = 5;
		public static final int CPTJOB = 6;
		public static final int CPTMIV = 7;
		public static final int CPTCMT = 8;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptSho
					, String CptTit
					, String CptVer
					, String CptJob
					, String CptMiv
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptSho = CptSho;
			this.CptTit = CptTit;
			this.CptVer = CptVer;
			this.CptJob = CptJob;
			this.CptMiv = CptMiv;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSHO, CPTTIT, CPTVER, CPTJOB, CPTMIV, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptSho;
		public String CptTit;
		public String CptVer;
		public String CptJob;
		public String CptMiv;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmIexDetail");

			String itemtag = "TagitemWznmIexDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSho", mask, CPTSHO);
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTit", mask, CPTTIT);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptJob", mask, CPTJOB);
				CptMiv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMiv", mask, CPTMIV);
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
			if (CptSho.equals(comp.CptSho)) items.add(CPTSHO);
			if (CptTit.equals(comp.CptTit)) items.add(CPTTIT);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);
			if (CptJob.equals(comp.CptJob)) items.add(CPTJOB);
			if (CptMiv.equals(comp.CptMiv)) items.add(CPTMIV);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSHO, CPTTIT, CPTVER, CPTJOB, CPTMIV, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmIexDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMIEXDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmIexDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmIexDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMIEXDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmIexDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmIexDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPJTI = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMIEXDETAILDATA);

			contiac = new ContIac("", 0, "", "");
			continf = new ContInf("", "", "", "");
			feedFPupJti = new Feed("FeedFPupJti");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupJti;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPJTI)) ss.add("feedFPupJti");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmIexDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupJti.readXML(doc, basexpath, true)) add(FEEDFPUPJTI);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", 0, "", "");
				continf = new ContInf("", "", "", "");
				feedFPupJti = new Feed("FeedFPupJti");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "");
			};
		};

	};

};
