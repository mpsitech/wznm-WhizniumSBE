/**
  * \file PnlWznmVitDetail.java
  * Java API code for job PnlWznmVitDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmVitDetail {
	/**
		* VecVDo (full: VecVWznmVitDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTJEDITCLICK = 2;
		public static final int BUTVECVIEWCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butjeditclick")) return BUTJEDITCLICK;
			if (s.equals("butvecviewclick")) return BUTVECVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTJEDITCLICK) return("ButJEditClick");
			if (ix == BUTVECVIEWCLICK) return("ButVecViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmVitDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPJ = 1;
		public static final int TXFAVL = 2;
		public static final int TXFIMP = 3;
		public static final int TXFCMT = 4;

		public ContIac(
					int numFPupJ
					, String TxfAvl
					, String TxfImp
					, String TxfCmt
				) {
			this.numFPupJ = numFPupJ;
			this.TxfAvl = TxfAvl;
			this.TxfImp = TxfImp;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPJ, TXFAVL, TXFIMP, TXFCMT));
		};

		public int numFPupJ;
		public String TxfAvl;
		public String TxfImp;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmVitDetail");

			String itemtag = "ContitemIacWznmVitDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupJ = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupJ", mask, NUMFPUPJ);
				TxfAvl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfAvl", mask, TXFAVL);
				TxfImp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfImp", mask, TXFIMP);
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
			if (difftag.isEmpty()) difftag = "ContIacWznmVitDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmVitDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupJ", numFPupJ);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfAvl", TxfAvl);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfImp", TxfImp);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupJ == comp.numFPupJ) items.add(NUMFPUPJ);
			if (TxfAvl.equals(comp.TxfAvl)) items.add(TXFAVL);
			if (TxfImp.equals(comp.TxfImp)) items.add(TXFIMP);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPJ, TXFAVL, TXFIMP, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmVitDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTTIT = 2;
		public static final int TXTVEC = 3;

		public ContInf(
					String TxtSrf
					, String TxtTit
					, String TxtVec
				) {
			this.TxtSrf = TxtSrf;
			this.TxtTit = TxtTit;
			this.TxtVec = TxtVec;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTIT, TXTVEC));
		};

		public String TxtSrf;
		public String TxtTit;
		public String TxtVec;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmVitDetail");

			String itemtag = "ContitemInfWznmVitDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTit", mask, TXTTIT);
				TxtVec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVec", mask, TXTVEC);

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
			if (TxtVec.equals(comp.TxtVec)) items.add(TXTVEC);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTIT, TXTVEC));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmVitDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmVitDetail");

			String itemtag = "StatitemAppWznmVitDetail";

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
	  * StatShr (full: StatShrWznmVitDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int PUPJACTIVE = 4;
		public static final int BUTJEDITAVAIL = 5;
		public static final int TXTTITACTIVE = 6;
		public static final int TXTVECACTIVE = 7;
		public static final int BUTVECVIEWAVAIL = 8;
		public static final int BUTVECVIEWACTIVE = 9;
		public static final int TXFAVLACTIVE = 10;
		public static final int TXFIMPACTIVE = 11;
		public static final int TXFCMTACTIVE = 12;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupJActive
					, boolean ButJEditAvail
					, boolean TxtTitActive
					, boolean TxtVecActive
					, boolean ButVecViewAvail
					, boolean ButVecViewActive
					, boolean TxfAvlActive
					, boolean TxfImpActive
					, boolean TxfCmtActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupJActive = PupJActive;
			this.ButJEditAvail = ButJEditAvail;
			this.TxtTitActive = TxtTitActive;
			this.TxtVecActive = TxtVecActive;
			this.ButVecViewAvail = ButVecViewAvail;
			this.ButVecViewActive = ButVecViewActive;
			this.TxfAvlActive = TxfAvlActive;
			this.TxfImpActive = TxfImpActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTTITACTIVE, TXTVECACTIVE, BUTVECVIEWAVAIL, BUTVECVIEWACTIVE, TXFAVLACTIVE, TXFIMPACTIVE, TXFCMTACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupJActive;
		public boolean ButJEditAvail;
		public boolean TxtTitActive;
		public boolean TxtVecActive;
		public boolean ButVecViewAvail;
		public boolean ButVecViewActive;
		public boolean TxfAvlActive;
		public boolean TxfImpActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmVitDetail");

			String itemtag = "StatitemShrWznmVitDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupJActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupJActive", mask, PUPJACTIVE);
				ButJEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJEditAvail", mask, BUTJEDITAVAIL);
				TxtTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTitActive", mask, TXTTITACTIVE);
				TxtVecActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVecActive", mask, TXTVECACTIVE);
				ButVecViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVecViewAvail", mask, BUTVECVIEWAVAIL);
				ButVecViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVecViewActive", mask, BUTVECVIEWACTIVE);
				TxfAvlActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfAvlActive", mask, TXFAVLACTIVE);
				TxfImpActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfImpActive", mask, TXFIMPACTIVE);
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
			if (PupJActive == comp.PupJActive) items.add(PUPJACTIVE);
			if (ButJEditAvail == comp.ButJEditAvail) items.add(BUTJEDITAVAIL);
			if (TxtTitActive == comp.TxtTitActive) items.add(TXTTITACTIVE);
			if (TxtVecActive == comp.TxtVecActive) items.add(TXTVECACTIVE);
			if (ButVecViewAvail == comp.ButVecViewAvail) items.add(BUTVECVIEWAVAIL);
			if (ButVecViewActive == comp.ButVecViewActive) items.add(BUTVECVIEWACTIVE);
			if (TxfAvlActive == comp.TxfAvlActive) items.add(TXFAVLACTIVE);
			if (TxfImpActive == comp.TxfImpActive) items.add(TXFIMPACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTTITACTIVE, TXTVECACTIVE, BUTVECVIEWAVAIL, BUTVECVIEWACTIVE, TXFAVLACTIVE, TXFIMPACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmVitDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTIT = 3;
		public static final int CPTVEC = 4;
		public static final int CPTAVL = 5;
		public static final int CPTIMP = 6;
		public static final int CPTCMT = 7;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTit
					, String CptVec
					, String CptAvl
					, String CptImp
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTit = CptTit;
			this.CptVec = CptVec;
			this.CptAvl = CptAvl;
			this.CptImp = CptImp;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTVEC, CPTAVL, CPTIMP, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTit;
		public String CptVec;
		public String CptAvl;
		public String CptImp;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmVitDetail");

			String itemtag = "TagitemWznmVitDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTit", mask, CPTTIT);
				CptVec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVec", mask, CPTVEC);
				CptAvl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAvl", mask, CPTAVL);
				CptImp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptImp", mask, CPTIMP);
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
			if (CptVec.equals(comp.CptVec)) items.add(CPTVEC);
			if (CptAvl.equals(comp.CptAvl)) items.add(CPTAVL);
			if (CptImp.equals(comp.CptImp)) items.add(CPTIMP);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTVEC, CPTAVL, CPTIMP, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmVitDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMVITDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmVitDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmVitDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMVITDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmVitDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmVitDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPJ = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMVITDETAILDATA);

			contiac = new ContIac(0, "", "", "");
			continf = new ContInf("", "", "");
			feedFPupJ = new Feed("FeedFPupJ");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupJ;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPJ)) ss.add("feedFPupJ");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmVitDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupJ.readXML(doc, basexpath, true)) add(FEEDFPUPJ);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "", "", "");
				continf = new ContInf("", "", "");
				feedFPupJ = new Feed("FeedFPupJ");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "");
			};
		};

	};

};

