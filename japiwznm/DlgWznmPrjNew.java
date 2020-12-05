/**
  * \file DlgWznmPrjNew.java
  * Java API code for job DlgWznmPrjNew
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWznmPrjNew {
	/**
		* VecVDo (full: VecVDlgWznmPrjNewDo)
		*/
	public static class VecVDo {

		public static final int DETBUTAUTCLICK = 1;
		public static final int BUTCNCCLICK = 2;
		public static final int BUTCRECLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("detbutautclick")) return DETBUTAUTCLICK;
			if (s.equals("butcncclick")) return BUTCNCCLICK;
			if (s.equals("butcreclick")) return BUTCRECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == DETBUTAUTCLICK) return("DetButAutClick");
			if (ix == BUTCNCCLICK) return("ButCncClick");
			if (ix == BUTCRECLICK) return("ButCreClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWznmPrjNewSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRAER = 2;
		public static final int AUTH = 3;
		public static final int AUTDONE = 4;
		public static final int CREATE = 5;
		public static final int SYNC = 6;
		public static final int DONE = 7;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alraer")) return ALRAER;
			if (s.equals("auth")) return AUTH;
			if (s.equals("autdone")) return AUTDONE;
			if (s.equals("create")) return CREATE;
			if (s.equals("sync")) return SYNC;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == ALRAER) return("alraer");
			if (ix == AUTH) return("auth");
			if (ix == AUTDONE) return("autdone");
			if (ix == CREATE) return("create");
			if (ix == SYNC) return("sync");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWznmPrjNew)
	  */
	public class ContIac extends Block {

		public static final int DETTXFSHO = 1;
		public static final int DETTXFTIT = 2;
		public static final int DETTXFABT = 3;
		public static final int NUMSFDETLSTDTY = 4;
		public static final int NUMSFDETLSTLOC = 5;
		public static final int NUMFDETPUPPLC = 6;
		public static final int NUMFDETPUPPMC = 7;

		public ContIac(
					String DetTxfSho
					, String DetTxfTit
					, String DetTxfAbt
					, ArrayList<Integer> numsFDetLstDty
					, ArrayList<Integer> numsFDetLstLoc
					, int numFDetPupPlc
					, int numFDetPupPmc
				) {
			this.DetTxfSho = DetTxfSho;
			this.DetTxfTit = DetTxfTit;
			this.DetTxfAbt = DetTxfAbt;
			this.numsFDetLstDty = numsFDetLstDty;
			this.numsFDetLstLoc = numsFDetLstLoc;
			this.numFDetPupPlc = numFDetPupPlc;
			this.numFDetPupPmc = numFDetPupPmc;

			mask = new HashSet<Integer>(Arrays.asList(DETTXFSHO, DETTXFTIT, DETTXFABT, NUMSFDETLSTDTY, NUMSFDETLSTLOC, NUMFDETPUPPLC, NUMFDETPUPPMC));
		};

		public String DetTxfSho;
		public String DetTxfTit;
		public String DetTxfAbt;
		public ArrayList<Integer> numsFDetLstDty;
		public ArrayList<Integer> numsFDetLstLoc;
		public int numFDetPupPlc;
		public int numFDetPupPmc;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWznmPrjNew");

			String itemtag = "ContitemIacDlgWznmPrjNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				DetTxfSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxfSho", mask, DETTXFSHO);
				DetTxfTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxfTit", mask, DETTXFTIT);
				DetTxfAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxfAbt", mask, DETTXFABT);
				numsFDetLstDty = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFDetLstDty", mask, NUMSFDETLSTDTY);
				numsFDetLstLoc = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFDetLstLoc", mask, NUMSFDETLSTLOC);
				numFDetPupPlc = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetPupPlc", mask, NUMFDETPUPPLC);
				numFDetPupPmc = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetPupPmc", mask, NUMFDETPUPPMC);

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWznmPrjNew";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWznmPrjNew";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "DetTxfSho", DetTxfSho);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "DetTxfTit", DetTxfTit);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "DetTxfAbt", DetTxfAbt);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFDetLstDty", numsFDetLstDty);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFDetLstLoc", numsFDetLstLoc);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetPupPlc", numFDetPupPlc);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetPupPmc", numFDetPupPmc);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (DetTxfSho.equals(comp.DetTxfSho)) items.add(DETTXFSHO);
			if (DetTxfTit.equals(comp.DetTxfTit)) items.add(DETTXFTIT);
			if (DetTxfAbt.equals(comp.DetTxfAbt)) items.add(DETTXFABT);
			if (Xmlio.compareIntegervec(numsFDetLstDty, comp.numsFDetLstDty)) items.add(NUMSFDETLSTDTY);
			if (Xmlio.compareIntegervec(numsFDetLstLoc, comp.numsFDetLstLoc)) items.add(NUMSFDETLSTLOC);
			if (numFDetPupPlc == comp.numFDetPupPlc) items.add(NUMFDETPUPPLC);
			if (numFDetPupPmc == comp.numFDetPupPmc) items.add(NUMFDETPUPPMC);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DETTXFSHO, DETTXFTIT, DETTXFABT, NUMSFDETLSTDTY, NUMSFDETLSTLOC, NUMFDETPUPPLC, NUMFDETPUPPMC));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfDlgWznmPrjNew)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWznmPrjNew");

			String itemtag = "ContitemInfDlgWznmPrjNew";

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
	  * StatApp (full: StatAppDlgWznmPrjNew)
	  */
	public class StatApp extends Block {

		public static final int SHORTMENU = 1;
		public static final int DETLSTDTYNUMFIRSTDISP = 2;
		public static final int DETLSTLOCNUMFIRSTDISP = 3;

		public StatApp(
					String shortMenu
					, int DetLstDtyNumFirstdisp
					, int DetLstLocNumFirstdisp
				) {
			this.shortMenu = shortMenu;
			this.DetLstDtyNumFirstdisp = DetLstDtyNumFirstdisp;
			this.DetLstLocNumFirstdisp = DetLstLocNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(SHORTMENU, DETLSTDTYNUMFIRSTDISP, DETLSTLOCNUMFIRSTDISP));
		};

		public String shortMenu;
		public int DetLstDtyNumFirstdisp;
		public int DetLstLocNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWznmPrjNew");

			String itemtag = "StatitemAppDlgWznmPrjNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				DetLstDtyNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DetLstDtyNumFirstdisp", mask, DETLSTDTYNUMFIRSTDISP);
				DetLstLocNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DetLstLocNumFirstdisp", mask, DETLSTLOCNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);
			if (DetLstDtyNumFirstdisp == comp.DetLstDtyNumFirstdisp) items.add(DETLSTDTYNUMFIRSTDISP);
			if (DetLstLocNumFirstdisp == comp.DetLstLocNumFirstdisp) items.add(DETLSTLOCNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SHORTMENU, DETLSTDTYNUMFIRSTDISP, DETLSTLOCNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrDlgWznmPrjNew)
	  */
	public class StatShr extends Block {

		public static final int DETBUTAUTACTIVE = 1;
		public static final int BUTCNCACTIVE = 2;
		public static final int BUTCREACTIVE = 3;

		public StatShr(
					boolean DetButAutActive
					, boolean ButCncActive
					, boolean ButCreActive
				) {
			this.DetButAutActive = DetButAutActive;
			this.ButCncActive = ButCncActive;
			this.ButCreActive = ButCreActive;

			mask = new HashSet<Integer>(Arrays.asList(DETBUTAUTACTIVE, BUTCNCACTIVE, BUTCREACTIVE));
		};

		public boolean DetButAutActive;
		public boolean ButCncActive;
		public boolean ButCreActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWznmPrjNew");

			String itemtag = "StatitemShrDlgWznmPrjNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				DetButAutActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DetButAutActive", mask, DETBUTAUTACTIVE);
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

			if (DetButAutActive == comp.DetButAutActive) items.add(DETBUTAUTACTIVE);
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

			diffitems = new HashSet<Integer>(Arrays.asList(DETBUTAUTACTIVE, BUTCNCACTIVE, BUTCREACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWznmPrjNew)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int DETCPTSHO = 2;
		public static final int DETCPTTIT = 3;
		public static final int DETCPTABT = 4;
		public static final int DETCPTDTY = 5;
		public static final int DETCPTLOC = 6;
		public static final int DETCPTPLC = 7;
		public static final int DETCPTTMC = 8;
		public static final int DETBUTAUT = 9;
		public static final int BUTCNC = 10;
		public static final int BUTCRE = 11;

		public Tag(
					String Cpt
					, String DetCptSho
					, String DetCptTit
					, String DetCptAbt
					, String DetCptDty
					, String DetCptLoc
					, String DetCptPlc
					, String DetCptTmc
					, String DetButAut
					, String ButCnc
					, String ButCre
				) {
			this.Cpt = Cpt;
			this.DetCptSho = DetCptSho;
			this.DetCptTit = DetCptTit;
			this.DetCptAbt = DetCptAbt;
			this.DetCptDty = DetCptDty;
			this.DetCptLoc = DetCptLoc;
			this.DetCptPlc = DetCptPlc;
			this.DetCptTmc = DetCptTmc;
			this.DetButAut = DetButAut;
			this.ButCnc = ButCnc;
			this.ButCre = ButCre;

			mask = new HashSet<Integer>(Arrays.asList(CPT, DETCPTSHO, DETCPTTIT, DETCPTABT, DETCPTDTY, DETCPTLOC, DETCPTPLC, DETCPTTMC, DETBUTAUT, BUTCNC, BUTCRE));
		};

		public String Cpt;
		public String DetCptSho;
		public String DetCptTit;
		public String DetCptAbt;
		public String DetCptDty;
		public String DetCptLoc;
		public String DetCptPlc;
		public String DetCptTmc;
		public String DetButAut;
		public String ButCnc;
		public String ButCre;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWznmPrjNew");

			String itemtag = "TagitemDlgWznmPrjNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				DetCptSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptSho", mask, DETCPTSHO);
				DetCptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptTit", mask, DETCPTTIT);
				DetCptAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptAbt", mask, DETCPTABT);
				DetCptDty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptDty", mask, DETCPTDTY);
				DetCptLoc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptLoc", mask, DETCPTLOC);
				DetCptPlc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptPlc", mask, DETCPTPLC);
				DetCptTmc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptTmc", mask, DETCPTTMC);
				DetButAut = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetButAut", mask, DETBUTAUT);
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
			if (DetCptSho.equals(comp.DetCptSho)) items.add(DETCPTSHO);
			if (DetCptTit.equals(comp.DetCptTit)) items.add(DETCPTTIT);
			if (DetCptAbt.equals(comp.DetCptAbt)) items.add(DETCPTABT);
			if (DetCptDty.equals(comp.DetCptDty)) items.add(DETCPTDTY);
			if (DetCptLoc.equals(comp.DetCptLoc)) items.add(DETCPTLOC);
			if (DetCptPlc.equals(comp.DetCptPlc)) items.add(DETCPTPLC);
			if (DetCptTmc.equals(comp.DetCptTmc)) items.add(DETCPTTMC);
			if (DetButAut.equals(comp.DetButAut)) items.add(DETBUTAUT);
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

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, DETCPTSHO, DETCPTTIT, DETCPTABT, DETCPTDTY, DETCPTLOC, DETCPTPLC, DETCPTTMC, DETBUTAUT, BUTCNC, BUTCRE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppDlgWznmPrjNewData)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMPRJNEWDATA, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmPrjNewData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWznmPrjNewDo)
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
			super(VecWznmVDpch.DPCHAPPDLGWZNMPRJNEWDO, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWznmPrjNewDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWznmPrjNewData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFDETLSTDTY = 4;
		public static final int FEEDFDETLSTLOC = 5;
		public static final int FEEDFDETPUPPLC = 6;
		public static final int FEEDFDETPUPPMC = 7;
		public static final int FEEDFSGE = 8;
		public static final int STATAPP = 9;
		public static final int STATSHR = 10;
		public static final int TAG = 11;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGDLGWZNMPRJNEWDATA);

			contiac = new ContIac("", "", "", new ArrayList<Integer>(), new ArrayList<Integer>(), 0, 0);
			continf = new ContInf(0);
			feedFDetLstDty = new Feed("FeedFDetLstDty");
			feedFDetLstLoc = new Feed("FeedFDetLstLoc");
			feedFDetPupPlc = new Feed("FeedFDetPupPlc");
			feedFDetPupPmc = new Feed("FeedFDetPupPmc");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp("", 0, 0);
			statshr = new StatShr(false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFDetLstDty;
		public Feed feedFDetLstLoc;
		public Feed feedFDetPupPlc;
		public Feed feedFDetPupPmc;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFDETLSTDTY)) ss.add("feedFDetLstDty");
			if (has(FEEDFDETLSTLOC)) ss.add("feedFDetLstLoc");
			if (has(FEEDFDETPUPPLC)) ss.add("feedFDetPupPlc");
			if (has(FEEDFDETPUPPMC)) ss.add("feedFDetPupPmc");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWznmPrjNewData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFDetLstDty.readXML(doc, basexpath, true)) add(FEEDFDETLSTDTY);
				if (feedFDetLstLoc.readXML(doc, basexpath, true)) add(FEEDFDETLSTLOC);
				if (feedFDetPupPlc.readXML(doc, basexpath, true)) add(FEEDFDETPUPPLC);
				if (feedFDetPupPmc.readXML(doc, basexpath, true)) add(FEEDFDETPUPPMC);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", "", new ArrayList<Integer>(), new ArrayList<Integer>(), 0, 0);
				continf = new ContInf(0);
				feedFDetLstDty = new Feed("FeedFDetLstDty");
				feedFDetLstLoc = new Feed("FeedFDetLstLoc");
				feedFDetPupPlc = new Feed("FeedFDetPupPlc");
				feedFDetPupPmc = new Feed("FeedFDetPupPmc");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp("", 0, 0);
				statshr = new StatShr(false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

