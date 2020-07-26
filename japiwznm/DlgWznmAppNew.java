/**
  * \file DlgWznmAppNew.java
  * Java API code for job DlgWznmAppNew
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWznmAppNew {
	/**
		* VecVDo (full: VecVDlgWznmAppNewDo)
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
		* VecVSge (full: VecVDlgWznmAppNewSge)
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
	  * ContIac (full: ContIacDlgWznmAppNew)
	  */
	public class ContIac extends Block {

		public static final int NUMFDETPUPTRG = 1;
		public static final int NUMFDETPUPVER = 2;
		public static final int DETTXFSHO = 3;
		public static final int DETTXFTIT = 4;

		public ContIac(
					int numFDetPupTrg
					, int numFDetPupVer
					, String DetTxfSho
					, String DetTxfTit
				) {
			this.numFDetPupTrg = numFDetPupTrg;
			this.numFDetPupVer = numFDetPupVer;
			this.DetTxfSho = DetTxfSho;
			this.DetTxfTit = DetTxfTit;

			mask = new HashSet<Integer>(Arrays.asList(NUMFDETPUPTRG, NUMFDETPUPVER, DETTXFSHO, DETTXFTIT));
		};

		public int numFDetPupTrg;
		public int numFDetPupVer;
		public String DetTxfSho;
		public String DetTxfTit;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWznmAppNew");

			String itemtag = "ContitemIacDlgWznmAppNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFDetPupTrg = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetPupTrg", mask, NUMFDETPUPTRG);
				numFDetPupVer = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetPupVer", mask, NUMFDETPUPVER);
				DetTxfSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxfSho", mask, DETTXFSHO);
				DetTxfTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxfTit", mask, DETTXFTIT);

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWznmAppNew";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWznmAppNew";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetPupTrg", numFDetPupTrg);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetPupVer", numFDetPupVer);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "DetTxfSho", DetTxfSho);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "DetTxfTit", DetTxfTit);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFDetPupTrg == comp.numFDetPupTrg) items.add(NUMFDETPUPTRG);
			if (numFDetPupVer == comp.numFDetPupVer) items.add(NUMFDETPUPVER);
			if (DetTxfSho.equals(comp.DetTxfSho)) items.add(DETTXFSHO);
			if (DetTxfTit.equals(comp.DetTxfTit)) items.add(DETTXFTIT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFDETPUPTRG, NUMFDETPUPVER, DETTXFSHO, DETTXFTIT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfDlgWznmAppNew)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmAppNew");

			String itemtag = "ContitemInfDlgWznmAppNew";

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
	  * StatApp (full: StatAppDlgWznmAppNew)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWznmAppNew");

			String itemtag = "StatitemAppDlgWznmAppNew";

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
	  * StatShr (full: StatShrDlgWznmAppNew)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmAppNew");

			String itemtag = "StatitemShrDlgWznmAppNew";

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
	  * Tag (full: TagDlgWznmAppNew)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int DETCPTTRG = 2;
		public static final int DETCPTVER = 3;
		public static final int DETCPTSHO = 4;
		public static final int DETCPTTIT = 5;
		public static final int BUTCNC = 6;
		public static final int BUTCRE = 7;

		public Tag(
					String Cpt
					, String DetCptTrg
					, String DetCptVer
					, String DetCptSho
					, String DetCptTit
					, String ButCnc
					, String ButCre
				) {
			this.Cpt = Cpt;
			this.DetCptTrg = DetCptTrg;
			this.DetCptVer = DetCptVer;
			this.DetCptSho = DetCptSho;
			this.DetCptTit = DetCptTit;
			this.ButCnc = ButCnc;
			this.ButCre = ButCre;

			mask = new HashSet<Integer>(Arrays.asList(CPT, DETCPTTRG, DETCPTVER, DETCPTSHO, DETCPTTIT, BUTCNC, BUTCRE));
		};

		public String Cpt;
		public String DetCptTrg;
		public String DetCptVer;
		public String DetCptSho;
		public String DetCptTit;
		public String ButCnc;
		public String ButCre;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmAppNew");

			String itemtag = "TagitemDlgWznmAppNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				DetCptTrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptTrg", mask, DETCPTTRG);
				DetCptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptVer", mask, DETCPTVER);
				DetCptSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptSho", mask, DETCPTSHO);
				DetCptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptTit", mask, DETCPTTIT);
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
			if (DetCptTrg.equals(comp.DetCptTrg)) items.add(DETCPTTRG);
			if (DetCptVer.equals(comp.DetCptVer)) items.add(DETCPTVER);
			if (DetCptSho.equals(comp.DetCptSho)) items.add(DETCPTSHO);
			if (DetCptTit.equals(comp.DetCptTit)) items.add(DETCPTTIT);
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

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, DETCPTTRG, DETCPTVER, DETCPTSHO, DETCPTTIT, BUTCNC, BUTCRE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppDlgWznmAppNewData)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMAPPNEWDATA, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmAppNewData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmAppNewDo)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMAPPNEWDO, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmAppNewDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWznmAppNewData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFDETPUPTRG = 4;
		public static final int FEEDFDETPUPVER = 5;
		public static final int FEEDFSGE = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGDLGWZNMAPPNEWDATA);

			contiac = new ContIac(0, 0, "", "");
			continf = new ContInf(0);
			feedFDetPupTrg = new Feed("FeedFDetPupTrg");
			feedFDetPupVer = new Feed("FeedFDetPupVer");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp("");
			statshr = new StatShr(false, false);
			tag = new Tag("", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFDetPupTrg;
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
			if (has(FEEDFDETPUPTRG)) ss.add("feedFDetPupTrg");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWznmAppNewData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFDetPupTrg.readXML(doc, basexpath, true)) add(FEEDFDETPUPTRG);
				if (feedFDetPupVer.readXML(doc, basexpath, true)) add(FEEDFDETPUPVER);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, "", "");
				continf = new ContInf(0);
				feedFDetPupTrg = new Feed("FeedFDetPupTrg");
				feedFDetPupVer = new Feed("FeedFDetPupVer");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp("");
				statshr = new StatShr(false, false);
				tag = new Tag("", "", "", "", "", "", "");
			};
		};

	};

};

