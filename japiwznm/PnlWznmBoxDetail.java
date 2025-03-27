/**
  * \file PnlWznmBoxDetail.java
  * Java API code for job PnlWznmBoxDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmBoxDetail {
	/**
		* VecVDo (full: VecVWznmBoxDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTSHTVIEWCLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butshtviewclick")) return BUTSHTVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTSHTVIEWCLICK) return("ButShtViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmBoxDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPY = 1;
		public static final int TXFX = 2;
		public static final int TXFY = 3;

		public ContIac(
					int numFPupY
					, String TxfX
					, String TxfY
				) {
			this.numFPupY = numFPupY;
			this.TxfX = TxfX;
			this.TxfY = TxfY;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPY, TXFX, TXFY));
		};

		public int numFPupY;
		public String TxfX;
		public String TxfY;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmBoxDetail");

			String itemtag = "ContitemIacWznmBoxDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupY = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupY", mask, NUMFPUPY);
				TxfX = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfX", mask, TXFX);
				TxfY = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfY", mask, TXFY);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmBoxDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmBoxDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupY", numFPupY);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfX", TxfX);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfY", TxfY);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupY == comp.numFPupY) items.add(NUMFPUPY);
			if (TxfX.equals(comp.TxfX)) items.add(TXFX);
			if (TxfY.equals(comp.TxfY)) items.add(TXFY);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPY, TXFX, TXFY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmBoxDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSHT = 1;
		public static final int TXTUNV = 2;

		public ContInf(
					String TxtSht
					, String TxtUnv
				) {
			this.TxtSht = TxtSht;
			this.TxtUnv = TxtUnv;

			mask = new HashSet<Integer>(Arrays.asList(TXTSHT, TXTUNV));
		};

		public String TxtSht;
		public String TxtUnv;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmBoxDetail");

			String itemtag = "ContitemInfWznmBoxDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSht = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSht", mask, TXTSHT);
				TxtUnv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtUnv", mask, TXTUNV);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSht.equals(comp.TxtSht)) items.add(TXTSHT);
			if (TxtUnv.equals(comp.TxtUnv)) items.add(TXTUNV);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSHT, TXTUNV));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmBoxDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmBoxDetail");

			String itemtag = "StatitemAppWznmBoxDetail";

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
	  * StatShr (full: StatShrWznmBoxDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSHTACTIVE = 3;
		public static final int BUTSHTVIEWAVAIL = 4;
		public static final int BUTSHTVIEWACTIVE = 5;
		public static final int TXTUNVACTIVE = 6;
		public static final int TXFXACTIVE = 7;
		public static final int TXFYACTIVE = 8;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtShtActive
					, boolean ButShtViewAvail
					, boolean ButShtViewActive
					, boolean TxtUnvActive
					, boolean TxfXActive
					, boolean TxfYActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtShtActive = TxtShtActive;
			this.ButShtViewAvail = ButShtViewAvail;
			this.ButShtViewActive = ButShtViewActive;
			this.TxtUnvActive = TxtUnvActive;
			this.TxfXActive = TxfXActive;
			this.TxfYActive = TxfYActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSHTACTIVE, BUTSHTVIEWAVAIL, BUTSHTVIEWACTIVE, TXTUNVACTIVE, TXFXACTIVE, TXFYACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtShtActive;
		public boolean ButShtViewAvail;
		public boolean ButShtViewActive;
		public boolean TxtUnvActive;
		public boolean TxfXActive;
		public boolean TxfYActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmBoxDetail");

			String itemtag = "StatitemShrWznmBoxDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtShtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtShtActive", mask, TXTSHTACTIVE);
				ButShtViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButShtViewAvail", mask, BUTSHTVIEWAVAIL);
				ButShtViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButShtViewActive", mask, BUTSHTVIEWACTIVE);
				TxtUnvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtUnvActive", mask, TXTUNVACTIVE);
				TxfXActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfXActive", mask, TXFXACTIVE);
				TxfYActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfYActive", mask, TXFYACTIVE);

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
			if (TxtShtActive == comp.TxtShtActive) items.add(TXTSHTACTIVE);
			if (ButShtViewAvail == comp.ButShtViewAvail) items.add(BUTSHTVIEWAVAIL);
			if (ButShtViewActive == comp.ButShtViewActive) items.add(BUTSHTVIEWACTIVE);
			if (TxtUnvActive == comp.TxtUnvActive) items.add(TXTUNVACTIVE);
			if (TxfXActive == comp.TxfXActive) items.add(TXFXACTIVE);
			if (TxfYActive == comp.TxfYActive) items.add(TXFYACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSHTACTIVE, BUTSHTVIEWAVAIL, BUTSHTVIEWACTIVE, TXTUNVACTIVE, TXFXACTIVE, TXFYACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmBoxDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSHT = 2;
		public static final int CPTUNV = 3;
		public static final int CPTX = 4;
		public static final int CPTY = 5;

		public Tag(
					String Cpt
					, String CptSht
					, String CptUnv
					, String CptX
					, String CptY
				) {
			this.Cpt = Cpt;
			this.CptSht = CptSht;
			this.CptUnv = CptUnv;
			this.CptX = CptX;
			this.CptY = CptY;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSHT, CPTUNV, CPTX, CPTY));
		};

		public String Cpt;
		public String CptSht;
		public String CptUnv;
		public String CptX;
		public String CptY;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmBoxDetail");

			String itemtag = "TagitemWznmBoxDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSht = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSht", mask, CPTSHT);
				CptUnv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUnv", mask, CPTUNV);
				CptX = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptX", mask, CPTX);
				CptY = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptY", mask, CPTY);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptSht.equals(comp.CptSht)) items.add(CPTSHT);
			if (CptUnv.equals(comp.CptUnv)) items.add(CPTUNV);
			if (CptX.equals(comp.CptX)) items.add(CPTX);
			if (CptY.equals(comp.CptY)) items.add(CPTY);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSHT, CPTUNV, CPTX, CPTY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmBoxDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMBOXDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmBoxDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmBoxDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMBOXDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmBoxDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmBoxDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPY = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMBOXDETAILDATA);

			contiac = new ContIac(0, "", "");
			continf = new ContInf("", "");
			feedFPupY = new Feed("FeedFPupY");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupY;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPY)) ss.add("feedFPupY");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmBoxDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupY.readXML(doc, basexpath, true)) add(FEEDFPUPY);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "", "");
				continf = new ContInf("", "");
				feedFPupY = new Feed("FeedFPupY");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};
