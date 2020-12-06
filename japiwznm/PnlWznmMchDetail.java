/**
  * \file PnlWznmMchDetail.java
  * Java API code for job PnlWznmMchDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmMchDetail {
	/**
		* VecVDo (full: VecVWznmMchDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTSUPVIEWCLICK = 2;
		public static final int BUTCCHVIEWCLICK = 3;
		public static final int BUTPKMEDITCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butsupviewclick")) return BUTSUPVIEWCLICK;
			if (s.equals("butcchviewclick")) return BUTCCHVIEWCLICK;
			if (s.equals("butpkmeditclick")) return BUTPKMEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
			if (ix == BUTCCHVIEWCLICK) return("ButCchViewClick");
			if (ix == BUTPKMEDITCLICK) return("ButPkmEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmMchDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPPKM = 1;
		public static final int TXFPKM = 2;
		public static final int TXFCMT = 3;

		public ContIac(
					int numFPupPkm
					, String TxfPkm
					, String TxfCmt
				) {
			this.numFPupPkm = numFPupPkm;
			this.TxfPkm = TxfPkm;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPPKM, TXFPKM, TXFCMT));
		};

		public int numFPupPkm;
		public String TxfPkm;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmMchDetail");

			String itemtag = "ContitemIacWznmMchDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupPkm = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupPkm", mask, NUMFPUPPKM);
				TxfPkm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfPkm", mask, TXFPKM);
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
			if (difftag.isEmpty()) difftag = "ContIacWznmMchDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmMchDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupPkm", numFPupPkm);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfPkm", TxfPkm);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupPkm == comp.numFPupPkm) items.add(NUMFPUPPKM);
			if (TxfPkm.equals(comp.TxfPkm)) items.add(TXFPKM);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPPKM, TXFPKM, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmMchDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTSUP = 2;
		public static final int TXTCCH = 3;

		public ContInf(
					String TxtSrf
					, String TxtSup
					, String TxtCch
				) {
			this.TxtSrf = TxtSrf;
			this.TxtSup = TxtSup;
			this.TxtCch = TxtCch;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTSUP, TXTCCH));
		};

		public String TxtSrf;
		public String TxtSup;
		public String TxtCch;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmMchDetail");

			String itemtag = "ContitemInfWznmMchDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSup", mask, TXTSUP);
				TxtCch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCch", mask, TXTCCH);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtSup.equals(comp.TxtSup)) items.add(TXTSUP);
			if (TxtCch.equals(comp.TxtCch)) items.add(TXTCCH);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTSUP, TXTCCH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmMchDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int PUPPKMALT = 2;

		public StatApp(
					int ixWznmVExpstate
					, boolean PupPkmAlt
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.PupPkmAlt = PupPkmAlt;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, PUPPKMALT));
		};

		public int ixWznmVExpstate;
		public boolean PupPkmAlt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmMchDetail");

			String itemtag = "StatitemAppWznmMchDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				PupPkmAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPkmAlt", mask, PUPPKMALT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (PupPkmAlt == comp.PupPkmAlt) items.add(PUPPKMALT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, PUPPKMALT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmMchDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFPKMVALID = 1;
		public static final int BUTSAVEAVAIL = 2;
		public static final int BUTSAVEACTIVE = 3;
		public static final int TXTSRFACTIVE = 4;
		public static final int TXTSUPACTIVE = 5;
		public static final int BUTSUPVIEWAVAIL = 6;
		public static final int BUTSUPVIEWACTIVE = 7;
		public static final int TXTCCHACTIVE = 8;
		public static final int BUTCCHVIEWAVAIL = 9;
		public static final int BUTCCHVIEWACTIVE = 10;
		public static final int PUPPKMACTIVE = 11;
		public static final int BUTPKMEDITAVAIL = 12;
		public static final int TXFCMTACTIVE = 13;

		public StatShr(
					boolean TxfPkmValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxtSupActive
					, boolean ButSupViewAvail
					, boolean ButSupViewActive
					, boolean TxtCchActive
					, boolean ButCchViewAvail
					, boolean ButCchViewActive
					, boolean PupPkmActive
					, boolean ButPkmEditAvail
					, boolean TxfCmtActive
				) {
			this.TxfPkmValid = TxfPkmValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxtSupActive = TxtSupActive;
			this.ButSupViewAvail = ButSupViewAvail;
			this.ButSupViewActive = ButSupViewActive;
			this.TxtCchActive = TxtCchActive;
			this.ButCchViewAvail = ButCchViewAvail;
			this.ButCchViewActive = ButCchViewActive;
			this.PupPkmActive = PupPkmActive;
			this.ButPkmEditAvail = ButPkmEditAvail;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFPKMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, PUPPKMACTIVE, BUTPKMEDITAVAIL, TXFCMTACTIVE));
		};

		public boolean TxfPkmValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxtSupActive;
		public boolean ButSupViewAvail;
		public boolean ButSupViewActive;
		public boolean TxtCchActive;
		public boolean ButCchViewAvail;
		public boolean ButCchViewActive;
		public boolean PupPkmActive;
		public boolean ButPkmEditAvail;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmMchDetail");

			String itemtag = "StatitemShrWznmMchDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfPkmValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfPkmValid", mask, TXFPKMVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxtSupActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSupActive", mask, TXTSUPACTIVE);
				ButSupViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", mask, BUTSUPVIEWAVAIL);
				ButSupViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewActive", mask, BUTSUPVIEWACTIVE);
				TxtCchActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCchActive", mask, TXTCCHACTIVE);
				ButCchViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCchViewAvail", mask, BUTCCHVIEWAVAIL);
				ButCchViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCchViewActive", mask, BUTCCHVIEWACTIVE);
				PupPkmActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPkmActive", mask, PUPPKMACTIVE);
				ButPkmEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPkmEditAvail", mask, BUTPKMEDITAVAIL);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfPkmValid == comp.TxfPkmValid) items.add(TXFPKMVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (TxtSupActive == comp.TxtSupActive) items.add(TXTSUPACTIVE);
			if (ButSupViewAvail == comp.ButSupViewAvail) items.add(BUTSUPVIEWAVAIL);
			if (ButSupViewActive == comp.ButSupViewActive) items.add(BUTSUPVIEWACTIVE);
			if (TxtCchActive == comp.TxtCchActive) items.add(TXTCCHACTIVE);
			if (ButCchViewAvail == comp.ButCchViewAvail) items.add(BUTCCHVIEWAVAIL);
			if (ButCchViewActive == comp.ButCchViewActive) items.add(BUTCCHVIEWACTIVE);
			if (PupPkmActive == comp.PupPkmActive) items.add(PUPPKMACTIVE);
			if (ButPkmEditAvail == comp.ButPkmEditAvail) items.add(BUTPKMEDITAVAIL);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFPKMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, PUPPKMACTIVE, BUTPKMEDITAVAIL, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmMchDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTSUP = 3;
		public static final int CPTCCH = 4;
		public static final int CPTPKM = 5;
		public static final int CPTCMT = 6;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptSup
					, String CptCch
					, String CptPkm
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptSup = CptSup;
			this.CptCch = CptCch;
			this.CptPkm = CptPkm;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSUP, CPTCCH, CPTPKM, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptSup;
		public String CptCch;
		public String CptPkm;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmMchDetail");

			String itemtag = "TagitemWznmMchDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSup", mask, CPTSUP);
				CptCch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCch", mask, CPTCCH);
				CptPkm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPkm", mask, CPTPKM);
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
			if (CptSup.equals(comp.CptSup)) items.add(CPTSUP);
			if (CptCch.equals(comp.CptCch)) items.add(CPTCCH);
			if (CptPkm.equals(comp.CptPkm)) items.add(CPTPKM);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSUP, CPTCCH, CPTPKM, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmMchDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMMCHDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmMchDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmMchDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMMCHDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmMchDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmMchDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPPKM = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMMCHDETAILDATA);

			contiac = new ContIac(0, "", "");
			continf = new ContInf("", "", "");
			feedFPupPkm = new Feed("FeedFPupPkm");
			statapp = new StatApp(0, false);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupPkm;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPPKM)) ss.add("feedFPupPkm");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmMchDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupPkm.readXML(doc, basexpath, true)) add(FEEDFPUPPKM);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "", "");
				continf = new ContInf("", "", "");
				feedFPupPkm = new Feed("FeedFPupPkm");
				statapp = new StatApp(0, false);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};
