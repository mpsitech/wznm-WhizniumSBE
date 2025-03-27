/**
  * \file PnlWznmTagDetail.java
  * Java API code for job PnlWznmTagDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmTagDetail {
	/**
		* VecVDo (full: VecVWznmTagDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTJTIEDITCLICK = 2;
		public static final int BUTCPBVIEWCLICK = 3;
		public static final int BUTGRPEDITCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butjtieditclick")) return BUTJTIEDITCLICK;
			if (s.equals("butcpbviewclick")) return BUTCPBVIEWCLICK;
			if (s.equals("butgrpeditclick")) return BUTGRPEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTJTIEDITCLICK) return("ButJtiEditClick");
			if (ix == BUTCPBVIEWCLICK) return("ButCpbViewClick");
			if (ix == BUTGRPEDITCLICK) return("ButGrpEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmTagDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPJTI = 1;
		public static final int NUMFPUPGRP = 2;
		public static final int TXFGRP = 3;

		public ContIac(
					int numFPupJti
					, int numFPupGrp
					, String TxfGrp
				) {
			this.numFPupJti = numFPupJti;
			this.numFPupGrp = numFPupGrp;
			this.TxfGrp = TxfGrp;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPJTI, NUMFPUPGRP, TXFGRP));
		};

		public int numFPupJti;
		public int numFPupGrp;
		public String TxfGrp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmTagDetail");

			String itemtag = "ContitemIacWznmTagDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupJti = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupJti", mask, NUMFPUPJTI);
				numFPupGrp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupGrp", mask, NUMFPUPGRP);
				TxfGrp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfGrp", mask, TXFGRP);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmTagDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmTagDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupJti", numFPupJti);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupGrp", numFPupGrp);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfGrp", TxfGrp);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupJti == comp.numFPupJti) items.add(NUMFPUPJTI);
			if (numFPupGrp == comp.numFPupGrp) items.add(NUMFPUPGRP);
			if (TxfGrp.equals(comp.TxfGrp)) items.add(TXFGRP);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPJTI, NUMFPUPGRP, TXFGRP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmTagDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTTIT = 2;
		public static final int TXTCPB = 3;

		public ContInf(
					String TxtSrf
					, String TxtTit
					, String TxtCpb
				) {
			this.TxtSrf = TxtSrf;
			this.TxtTit = TxtTit;
			this.TxtCpb = TxtCpb;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTIT, TXTCPB));
		};

		public String TxtSrf;
		public String TxtTit;
		public String TxtCpb;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmTagDetail");

			String itemtag = "ContitemInfWznmTagDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTit", mask, TXTTIT);
				TxtCpb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCpb", mask, TXTCPB);

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
			if (TxtCpb.equals(comp.TxtCpb)) items.add(TXTCPB);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTIT, TXTCPB));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmTagDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int PUPGRPALT = 2;

		public StatApp(
					int ixWznmVExpstate
					, boolean PupGrpAlt
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.PupGrpAlt = PupGrpAlt;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, PUPGRPALT));
		};

		public int ixWznmVExpstate;
		public boolean PupGrpAlt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmTagDetail");

			String itemtag = "StatitemAppWznmTagDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				PupGrpAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupGrpAlt", mask, PUPGRPALT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (PupGrpAlt == comp.PupGrpAlt) items.add(PUPGRPALT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, PUPGRPALT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmTagDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int PUPJTIACTIVE = 4;
		public static final int BUTJTIEDITAVAIL = 5;
		public static final int TXTTITACTIVE = 6;
		public static final int TXTCPBACTIVE = 7;
		public static final int BUTCPBVIEWAVAIL = 8;
		public static final int BUTCPBVIEWACTIVE = 9;
		public static final int PUPGRPACTIVE = 10;
		public static final int TXFGRPVALID = 11;
		public static final int BUTGRPEDITAVAIL = 12;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupJtiActive
					, boolean ButJtiEditAvail
					, boolean TxtTitActive
					, boolean TxtCpbActive
					, boolean ButCpbViewAvail
					, boolean ButCpbViewActive
					, boolean PupGrpActive
					, boolean TxfGrpValid
					, boolean ButGrpEditAvail
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupJtiActive = PupJtiActive;
			this.ButJtiEditAvail = ButJtiEditAvail;
			this.TxtTitActive = TxtTitActive;
			this.TxtCpbActive = TxtCpbActive;
			this.ButCpbViewAvail = ButCpbViewAvail;
			this.ButCpbViewActive = ButCpbViewActive;
			this.PupGrpActive = PupGrpActive;
			this.TxfGrpValid = TxfGrpValid;
			this.ButGrpEditAvail = ButGrpEditAvail;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTCPBACTIVE, BUTCPBVIEWAVAIL, BUTCPBVIEWACTIVE, PUPGRPACTIVE, TXFGRPVALID, BUTGRPEDITAVAIL));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupJtiActive;
		public boolean ButJtiEditAvail;
		public boolean TxtTitActive;
		public boolean TxtCpbActive;
		public boolean ButCpbViewAvail;
		public boolean ButCpbViewActive;
		public boolean PupGrpActive;
		public boolean TxfGrpValid;
		public boolean ButGrpEditAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmTagDetail");

			String itemtag = "StatitemShrWznmTagDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupJtiActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupJtiActive", mask, PUPJTIACTIVE);
				ButJtiEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJtiEditAvail", mask, BUTJTIEDITAVAIL);
				TxtTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTitActive", mask, TXTTITACTIVE);
				TxtCpbActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCpbActive", mask, TXTCPBACTIVE);
				ButCpbViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCpbViewAvail", mask, BUTCPBVIEWAVAIL);
				ButCpbViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCpbViewActive", mask, BUTCPBVIEWACTIVE);
				PupGrpActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupGrpActive", mask, PUPGRPACTIVE);
				TxfGrpValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfGrpValid", mask, TXFGRPVALID);
				ButGrpEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButGrpEditAvail", mask, BUTGRPEDITAVAIL);

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
			if (TxtCpbActive == comp.TxtCpbActive) items.add(TXTCPBACTIVE);
			if (ButCpbViewAvail == comp.ButCpbViewAvail) items.add(BUTCPBVIEWAVAIL);
			if (ButCpbViewActive == comp.ButCpbViewActive) items.add(BUTCPBVIEWACTIVE);
			if (PupGrpActive == comp.PupGrpActive) items.add(PUPGRPACTIVE);
			if (TxfGrpValid == comp.TxfGrpValid) items.add(TXFGRPVALID);
			if (ButGrpEditAvail == comp.ButGrpEditAvail) items.add(BUTGRPEDITAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTCPBACTIVE, BUTCPBVIEWAVAIL, BUTCPBVIEWACTIVE, PUPGRPACTIVE, TXFGRPVALID, BUTGRPEDITAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmTagDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTIT = 3;
		public static final int CPTCPB = 4;
		public static final int CPTGRP = 5;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTit
					, String CptCpb
					, String CptGrp
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTit = CptTit;
			this.CptCpb = CptCpb;
			this.CptGrp = CptGrp;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTCPB, CPTGRP));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTit;
		public String CptCpb;
		public String CptGrp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmTagDetail");

			String itemtag = "TagitemWznmTagDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTit", mask, CPTTIT);
				CptCpb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCpb", mask, CPTCPB);
				CptGrp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptGrp", mask, CPTGRP);

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
			if (CptCpb.equals(comp.CptCpb)) items.add(CPTCPB);
			if (CptGrp.equals(comp.CptGrp)) items.add(CPTGRP);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTCPB, CPTGRP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmTagDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMTAGDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmTagDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmTagDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMTAGDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmTagDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmTagDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPGRP = 4;
		public static final int FEEDFPUPJTI = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMTAGDETAILDATA);

			contiac = new ContIac(0, 0, "");
			continf = new ContInf("", "", "");
			feedFPupGrp = new Feed("FeedFPupGrp");
			feedFPupJti = new Feed("FeedFPupJti");
			statapp = new StatApp(0, false);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupGrp;
		public Feed feedFPupJti;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPGRP)) ss.add("feedFPupGrp");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmTagDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupGrp.readXML(doc, basexpath, true)) add(FEEDFPUPGRP);
				if (feedFPupJti.readXML(doc, basexpath, true)) add(FEEDFPUPJTI);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, "");
				continf = new ContInf("", "", "");
				feedFPupGrp = new Feed("FeedFPupGrp");
				feedFPupJti = new Feed("FeedFPupJti");
				statapp = new StatApp(0, false);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};
