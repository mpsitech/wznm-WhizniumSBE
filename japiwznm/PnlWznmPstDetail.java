/**
  * \file PnlWznmPstDetail.java
  * Java API code for job PnlWznmPstDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmPstDetail {
	/**
		* VecVDo (full: VecVWznmPstDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTJTIEDITCLICK = 2;
		public static final int BUTVERVIEWCLICK = 3;
		public static final int BUTREUVIEWCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butjtieditclick")) return BUTJTIEDITCLICK;
			if (s.equals("butverviewclick")) return BUTVERVIEWCLICK;
			if (s.equals("butreuviewclick")) return BUTREUVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTJTIEDITCLICK) return("ButJtiEditClick");
			if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
			if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmPstDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPJTI = 1;
		public static final int NUMFPUPRET = 2;
		public static final int NUMFPUPSCO = 3;
		public static final int NUMFPUPATY = 4;

		public ContIac(
					int numFPupJti
					, int numFPupRet
					, int numFPupSco
					, int numFPupAty
				) {
			this.numFPupJti = numFPupJti;
			this.numFPupRet = numFPupRet;
			this.numFPupSco = numFPupSco;
			this.numFPupAty = numFPupAty;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPJTI, NUMFPUPRET, NUMFPUPSCO, NUMFPUPATY));
		};

		public int numFPupJti;
		public int numFPupRet;
		public int numFPupSco;
		public int numFPupAty;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmPstDetail");

			String itemtag = "ContitemIacWznmPstDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupJti = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupJti", mask, NUMFPUPJTI);
				numFPupRet = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupRet", mask, NUMFPUPRET);
				numFPupSco = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupSco", mask, NUMFPUPSCO);
				numFPupAty = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupAty", mask, NUMFPUPATY);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmPstDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmPstDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupJti", numFPupJti);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupRet", numFPupRet);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupSco", numFPupSco);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupAty", numFPupAty);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupJti == comp.numFPupJti) items.add(NUMFPUPJTI);
			if (numFPupRet == comp.numFPupRet) items.add(NUMFPUPRET);
			if (numFPupSco == comp.numFPupSco) items.add(NUMFPUPSCO);
			if (numFPupAty == comp.numFPupAty) items.add(NUMFPUPATY);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPJTI, NUMFPUPRET, NUMFPUPSCO, NUMFPUPATY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmPstDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTTIT = 2;
		public static final int TXTVER = 3;
		public static final int TXTREU = 4;

		public ContInf(
					String TxtSrf
					, String TxtTit
					, String TxtVer
					, String TxtReu
				) {
			this.TxtSrf = TxtSrf;
			this.TxtTit = TxtTit;
			this.TxtVer = TxtVer;
			this.TxtReu = TxtReu;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTIT, TXTVER, TXTREU));
		};

		public String TxtSrf;
		public String TxtTit;
		public String TxtVer;
		public String TxtReu;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmPstDetail");

			String itemtag = "ContitemInfWznmPstDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTit", mask, TXTTIT);
				TxtVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVer", mask, TXTVER);
				TxtReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtReu", mask, TXTREU);

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
			if (TxtReu.equals(comp.TxtReu)) items.add(TXTREU);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTIT, TXTVER, TXTREU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmPstDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmPstDetail");

			String itemtag = "StatitemAppWznmPstDetail";

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
	  * StatShr (full: StatShrWznmPstDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int PUPJTIACTIVE = 4;
		public static final int BUTJTIEDITAVAIL = 5;
		public static final int TXTTITACTIVE = 6;
		public static final int TXTVERACTIVE = 7;
		public static final int BUTVERVIEWAVAIL = 8;
		public static final int BUTVERVIEWACTIVE = 9;
		public static final int TXTREUACTIVE = 10;
		public static final int BUTREUVIEWAVAIL = 11;
		public static final int BUTREUVIEWACTIVE = 12;
		public static final int PUPSCOACTIVE = 13;
		public static final int PUPATYACTIVE = 14;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupJtiActive
					, boolean ButJtiEditAvail
					, boolean TxtTitActive
					, boolean TxtVerActive
					, boolean ButVerViewAvail
					, boolean ButVerViewActive
					, boolean TxtReuActive
					, boolean ButReuViewAvail
					, boolean ButReuViewActive
					, boolean PupScoActive
					, boolean PupAtyActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupJtiActive = PupJtiActive;
			this.ButJtiEditAvail = ButJtiEditAvail;
			this.TxtTitActive = TxtTitActive;
			this.TxtVerActive = TxtVerActive;
			this.ButVerViewAvail = ButVerViewAvail;
			this.ButVerViewActive = ButVerViewActive;
			this.TxtReuActive = TxtReuActive;
			this.ButReuViewAvail = ButReuViewAvail;
			this.ButReuViewActive = ButReuViewActive;
			this.PupScoActive = PupScoActive;
			this.PupAtyActive = PupAtyActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, PUPSCOACTIVE, PUPATYACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupJtiActive;
		public boolean ButJtiEditAvail;
		public boolean TxtTitActive;
		public boolean TxtVerActive;
		public boolean ButVerViewAvail;
		public boolean ButVerViewActive;
		public boolean TxtReuActive;
		public boolean ButReuViewAvail;
		public boolean ButReuViewActive;
		public boolean PupScoActive;
		public boolean PupAtyActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmPstDetail");

			String itemtag = "StatitemShrWznmPstDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupJtiActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupJtiActive", mask, PUPJTIACTIVE);
				ButJtiEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJtiEditAvail", mask, BUTJTIEDITAVAIL);
				TxtTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTitActive", mask, TXTTITACTIVE);
				TxtVerActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVerActive", mask, TXTVERACTIVE);
				ButVerViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", mask, BUTVERVIEWAVAIL);
				ButVerViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewActive", mask, BUTVERVIEWACTIVE);
				TxtReuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtReuActive", mask, TXTREUACTIVE);
				ButReuViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", mask, BUTREUVIEWAVAIL);
				ButReuViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewActive", mask, BUTREUVIEWACTIVE);
				PupScoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupScoActive", mask, PUPSCOACTIVE);
				PupAtyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupAtyActive", mask, PUPATYACTIVE);

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
			if (PupJtiActive == comp.PupJtiActive) items.add(PUPJTIACTIVE);
			if (ButJtiEditAvail == comp.ButJtiEditAvail) items.add(BUTJTIEDITAVAIL);
			if (TxtTitActive == comp.TxtTitActive) items.add(TXTTITACTIVE);
			if (TxtVerActive == comp.TxtVerActive) items.add(TXTVERACTIVE);
			if (ButVerViewAvail == comp.ButVerViewAvail) items.add(BUTVERVIEWAVAIL);
			if (ButVerViewActive == comp.ButVerViewActive) items.add(BUTVERVIEWACTIVE);
			if (TxtReuActive == comp.TxtReuActive) items.add(TXTREUACTIVE);
			if (ButReuViewAvail == comp.ButReuViewAvail) items.add(BUTREUVIEWAVAIL);
			if (ButReuViewActive == comp.ButReuViewActive) items.add(BUTREUVIEWACTIVE);
			if (PupScoActive == comp.PupScoActive) items.add(PUPSCOACTIVE);
			if (PupAtyActive == comp.PupAtyActive) items.add(PUPATYACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, PUPSCOACTIVE, PUPATYACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmPstDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTIT = 3;
		public static final int CPTVER = 4;
		public static final int CPTREU = 5;
		public static final int CPTSCO = 6;
		public static final int CPTATY = 7;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTit
					, String CptVer
					, String CptReu
					, String CptSco
					, String CptAty
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTit = CptTit;
			this.CptVer = CptVer;
			this.CptReu = CptReu;
			this.CptSco = CptSco;
			this.CptAty = CptAty;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTVER, CPTREU, CPTSCO, CPTATY));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTit;
		public String CptVer;
		public String CptReu;
		public String CptSco;
		public String CptAty;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmPstDetail");

			String itemtag = "TagitemWznmPstDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTit", mask, CPTTIT);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptReu", mask, CPTREU);
				CptSco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSco", mask, CPTSCO);
				CptAty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAty", mask, CPTATY);

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
			if (CptReu.equals(comp.CptReu)) items.add(CPTREU);
			if (CptSco.equals(comp.CptSco)) items.add(CPTSCO);
			if (CptAty.equals(comp.CptAty)) items.add(CPTATY);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTVER, CPTREU, CPTSCO, CPTATY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmPstDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMPSTDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmPstDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmPstDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMPSTDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmPstDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmPstDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPATY = 4;
		public static final int FEEDFPUPJTI = 5;
		public static final int FEEDFPUPRET = 6;
		public static final int FEEDFPUPSCO = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMPSTDETAILDATA);

			contiac = new ContIac(0, 0, 0, 0);
			continf = new ContInf("", "", "", "");
			feedFPupAty = new Feed("FeedFPupAty");
			feedFPupJti = new Feed("FeedFPupJti");
			feedFPupRet = new Feed("FeedFPupRet");
			feedFPupSco = new Feed("FeedFPupSco");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupAty;
		public Feed feedFPupJti;
		public Feed feedFPupRet;
		public Feed feedFPupSco;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPATY)) ss.add("feedFPupAty");
			if (has(FEEDFPUPJTI)) ss.add("feedFPupJti");
			if (has(FEEDFPUPRET)) ss.add("feedFPupRet");
			if (has(FEEDFPUPSCO)) ss.add("feedFPupSco");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmPstDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupAty.readXML(doc, basexpath, true)) add(FEEDFPUPATY);
				if (feedFPupJti.readXML(doc, basexpath, true)) add(FEEDFPUPJTI);
				if (feedFPupRet.readXML(doc, basexpath, true)) add(FEEDFPUPRET);
				if (feedFPupSco.readXML(doc, basexpath, true)) add(FEEDFPUPSCO);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0);
				continf = new ContInf("", "", "", "");
				feedFPupAty = new Feed("FeedFPupAty");
				feedFPupJti = new Feed("FeedFPupJti");
				feedFPupRet = new Feed("FeedFPupRet");
				feedFPupSco = new Feed("FeedFPupSco");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "");
			};
		};

	};

};
