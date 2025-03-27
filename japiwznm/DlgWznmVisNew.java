/**
  * \file DlgWznmVisNew.java
  * Java API code for job DlgWznmVisNew
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWznmVisNew {
	/**
		* VecVDo (full: VecVDlgWznmVisNewDo)
		*/
	public static class VecVDo {

		public static final int BUTCNCCLICK = 1;
		public static final int BUTCRECLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butcncclick")) return BUTCNCCLICK;
			if (s.equals("butcreclick")) return BUTCRECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTCNCCLICK) return("ButCncClick");
			if (ix == BUTCRECLICK) return("ButCreClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWznmVisNewSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int CREATE = 2;
		public static final int DONE = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("create")) return CREATE;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == CREATE) return("create");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWznmVisNew)
	  */
	public class ContIac extends Block {

		public static final int NUMFDETPUPTYP = 1;
		public static final int NUMFDETPUPVER = 2;
		public static final int DETTXFCMT = 3;

		public ContIac(
					int numFDetPupTyp
					, int numFDetPupVer
					, String DetTxfCmt
				) {
			this.numFDetPupTyp = numFDetPupTyp;
			this.numFDetPupVer = numFDetPupVer;
			this.DetTxfCmt = DetTxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFDETPUPTYP, NUMFDETPUPVER, DETTXFCMT));
		};

		public int numFDetPupTyp;
		public int numFDetPupVer;
		public String DetTxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWznmVisNew");

			String itemtag = "ContitemIacDlgWznmVisNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFDetPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetPupTyp", mask, NUMFDETPUPTYP);
				numFDetPupVer = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetPupVer", mask, NUMFDETPUPVER);
				DetTxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxfCmt", mask, DETTXFCMT);

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWznmVisNew";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWznmVisNew";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetPupTyp", numFDetPupTyp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetPupVer", numFDetPupVer);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "DetTxfCmt", DetTxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFDetPupTyp == comp.numFDetPupTyp) items.add(NUMFDETPUPTYP);
			if (numFDetPupVer == comp.numFDetPupVer) items.add(NUMFDETPUPVER);
			if (DetTxfCmt.equals(comp.DetTxfCmt)) items.add(DETTXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFDETPUPTYP, NUMFDETPUPVER, DETTXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfDlgWznmVisNew)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;

		public ContInf(
					int numFSge
				) {
			this.numFSge = numFSge;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE));
		};

		public int numFSge;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmVisNew");

			String itemtag = "ContitemInfDlgWznmVisNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWznmVisNew)
	  */
	public class StatApp extends Block {

		public static final int SHORTMENU = 1;

		public StatApp(
					String shortMenu
				) {
			this.shortMenu = shortMenu;

			mask = new HashSet<Integer>(Arrays.asList(SHORTMENU));
		};

		public String shortMenu;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWznmVisNew");

			String itemtag = "StatitemAppDlgWznmVisNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SHORTMENU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrDlgWznmVisNew)
	  */
	public class StatShr extends Block {

		public static final int BUTCNCACTIVE = 1;
		public static final int BUTCREACTIVE = 2;

		public StatShr(
					boolean ButCncActive
					, boolean ButCreActive
				) {
			this.ButCncActive = ButCncActive;
			this.ButCreActive = ButCreActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTCNCACTIVE, BUTCREACTIVE));
		};

		public boolean ButCncActive;
		public boolean ButCreActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmVisNew");

			String itemtag = "StatitemShrDlgWznmVisNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButCncActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCncActive", mask, BUTCNCACTIVE);
				ButCreActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCreActive", mask, BUTCREACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButCncActive == comp.ButCncActive) items.add(BUTCNCACTIVE);
			if (ButCreActive == comp.ButCreActive) items.add(BUTCREACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTCNCACTIVE, BUTCREACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWznmVisNew)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int DETCPTTYP = 2;
		public static final int DETCPTVER = 3;
		public static final int DETCPTCMT = 4;
		public static final int BUTCNC = 5;
		public static final int BUTCRE = 6;

		public Tag(
					String Cpt
					, String DetCptTyp
					, String DetCptVer
					, String DetCptCmt
					, String ButCnc
					, String ButCre
				) {
			this.Cpt = Cpt;
			this.DetCptTyp = DetCptTyp;
			this.DetCptVer = DetCptVer;
			this.DetCptCmt = DetCptCmt;
			this.ButCnc = ButCnc;
			this.ButCre = ButCre;

			mask = new HashSet<Integer>(Arrays.asList(CPT, DETCPTTYP, DETCPTVER, DETCPTCMT, BUTCNC, BUTCRE));
		};

		public String Cpt;
		public String DetCptTyp;
		public String DetCptVer;
		public String DetCptCmt;
		public String ButCnc;
		public String ButCre;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmVisNew");

			String itemtag = "TagitemDlgWznmVisNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				DetCptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptTyp", mask, DETCPTTYP);
				DetCptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptVer", mask, DETCPTVER);
				DetCptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptCmt", mask, DETCPTCMT);
				ButCnc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButCnc", mask, BUTCNC);
				ButCre = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButCre", mask, BUTCRE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (DetCptTyp.equals(comp.DetCptTyp)) items.add(DETCPTTYP);
			if (DetCptVer.equals(comp.DetCptVer)) items.add(DETCPTVER);
			if (DetCptCmt.equals(comp.DetCptCmt)) items.add(DETCPTCMT);
			if (ButCnc.equals(comp.ButCnc)) items.add(BUTCNC);
			if (ButCre.equals(comp.ButCre)) items.add(BUTCRE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, DETCPTTYP, DETCPTVER, DETCPTCMT, BUTCNC, BUTCRE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppDlgWznmVisNewData)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMVISNEWDATA, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmVisNewData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmVisNewDo)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMVISNEWDO, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmVisNewDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWznmVisNewData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFDETPUPTYP = 4;
		public static final int FEEDFDETPUPVER = 5;
		public static final int FEEDFSGE = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGDLGWZNMVISNEWDATA);

			contiac = new ContIac(0, 0, "");
			continf = new ContInf(0);
			feedFDetPupTyp = new Feed("FeedFDetPupTyp");
			feedFDetPupVer = new Feed("FeedFDetPupVer");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp("");
			statshr = new StatShr(false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFDetPupTyp;
		public Feed feedFDetPupVer;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFDETPUPTYP)) ss.add("feedFDetPupTyp");
			if (has(FEEDFDETPUPVER)) ss.add("feedFDetPupVer");
			if (has(FEEDFSGE)) ss.add("feedFSge");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWznmVisNewData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFDetPupTyp.readXML(doc, basexpath, true)) add(FEEDFDETPUPTYP);
				if (feedFDetPupVer.readXML(doc, basexpath, true)) add(FEEDFDETPUPVER);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, "");
				continf = new ContInf(0);
				feedFDetPupTyp = new Feed("FeedFDetPupTyp");
				feedFDetPupVer = new Feed("FeedFDetPupVer");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp("");
				statshr = new StatShr(false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};
