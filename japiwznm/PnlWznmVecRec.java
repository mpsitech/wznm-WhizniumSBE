/**
  * \file PnlWznmVecRec.java
  * Java API code for job PnlWznmVecRec
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmVecRec {
	/**
		* VecVDo (full: VecVWznmVecRecDo)
		*/
	public static class VecVDo {

		public static final int BUTMINIMIZECLICK = 1;
		public static final int BUTREGULARIZECLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWznmVecRec)
	  */
	public class ContInf extends Block {

		public static final int TXTREF = 1;

		public ContInf(
					String TxtRef
				) {
			this.TxtRef = TxtRef;

			mask = new HashSet<Integer>(Arrays.asList(TXTREF));
		};

		public String TxtRef;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmVecRec");

			String itemtag = "ContitemInfWznmVecRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtRef = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtRef", mask, TXTREF);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtRef.equals(comp.TxtRef)) items.add(TXTREF);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTREF));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmVecRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEATITLE = 2;
		public static final int INITDONEVEC1NVECTORITEM = 3;
		public static final int INITDONEFCT1NTABLECOL = 4;
		public static final int INITDONEREF1NPANEL = 5;
		public static final int INITDONESRC1NFEED = 6;
		public static final int INITDONEPST1NQUERYMOD = 7;
		public static final int INITDONEMNTABLE = 8;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneATitle
					, boolean initdoneVec1NVectoritem
					, boolean initdoneFct1NTablecol
					, boolean initdoneRef1NPanel
					, boolean initdoneSrc1NFeed
					, boolean initdonePst1NQuerymod
					, boolean initdoneMNTable
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneATitle = initdoneATitle;
			this.initdoneVec1NVectoritem = initdoneVec1NVectoritem;
			this.initdoneFct1NTablecol = initdoneFct1NTablecol;
			this.initdoneRef1NPanel = initdoneRef1NPanel;
			this.initdoneSrc1NFeed = initdoneSrc1NFeed;
			this.initdonePst1NQuerymod = initdonePst1NQuerymod;
			this.initdoneMNTable = initdoneMNTable;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEATITLE, INITDONEVEC1NVECTORITEM, INITDONEFCT1NTABLECOL, INITDONEREF1NPANEL, INITDONESRC1NFEED, INITDONEPST1NQUERYMOD, INITDONEMNTABLE));
		};

		public boolean initdoneDetail;
		public boolean initdoneATitle;
		public boolean initdoneVec1NVectoritem;
		public boolean initdoneFct1NTablecol;
		public boolean initdoneRef1NPanel;
		public boolean initdoneSrc1NFeed;
		public boolean initdonePst1NQuerymod;
		public boolean initdoneMNTable;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmVecRec");

			String itemtag = "StatitemAppWznmVecRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneATitle = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneATitle", mask, INITDONEATITLE);
				initdoneVec1NVectoritem = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneVec1NVectoritem", mask, INITDONEVEC1NVECTORITEM);
				initdoneFct1NTablecol = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneFct1NTablecol", mask, INITDONEFCT1NTABLECOL);
				initdoneRef1NPanel = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NPanel", mask, INITDONEREF1NPANEL);
				initdoneSrc1NFeed = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSrc1NFeed", mask, INITDONESRC1NFEED);
				initdonePst1NQuerymod = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdonePst1NQuerymod", mask, INITDONEPST1NQUERYMOD);
				initdoneMNTable = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNTable", mask, INITDONEMNTABLE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdoneATitle == comp.initdoneATitle) items.add(INITDONEATITLE);
			if (initdoneVec1NVectoritem == comp.initdoneVec1NVectoritem) items.add(INITDONEVEC1NVECTORITEM);
			if (initdoneFct1NTablecol == comp.initdoneFct1NTablecol) items.add(INITDONEFCT1NTABLECOL);
			if (initdoneRef1NPanel == comp.initdoneRef1NPanel) items.add(INITDONEREF1NPANEL);
			if (initdoneSrc1NFeed == comp.initdoneSrc1NFeed) items.add(INITDONESRC1NFEED);
			if (initdonePst1NQuerymod == comp.initdonePst1NQuerymod) items.add(INITDONEPST1NQUERYMOD);
			if (initdoneMNTable == comp.initdoneMNTable) items.add(INITDONEMNTABLE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEATITLE, INITDONEVEC1NVECTORITEM, INITDONEFCT1NTABLECOL, INITDONEREF1NPANEL, INITDONESRC1NFEED, INITDONEPST1NQUERYMOD, INITDONEMNTABLE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmVecRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFATITLE = 3;
		public static final int SCRJREFVEC1NVECTORITEM = 4;
		public static final int SCRJREFFCT1NTABLECOL = 5;
		public static final int PNLFCT1NTABLECOLAVAIL = 6;
		public static final int SCRJREFREF1NPANEL = 7;
		public static final int SCRJREFSRC1NFEED = 8;
		public static final int SCRJREFPST1NQUERYMOD = 9;
		public static final int PNLPST1NQUERYMODAVAIL = 10;
		public static final int SCRJREFMNTABLE = 11;
		public static final int PNLMNTABLEAVAIL = 12;
		public static final int BUTREGULARIZEACTIVE = 13;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefATitle
					, String scrJrefVec1NVectoritem
					, String scrJrefFct1NTablecol
					, boolean pnlfct1ntablecolAvail
					, String scrJrefRef1NPanel
					, String scrJrefSrc1NFeed
					, String scrJrefPst1NQuerymod
					, boolean pnlpst1nquerymodAvail
					, String scrJrefMNTable
					, boolean pnlmntableAvail
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefATitle = scrJrefATitle;
			this.scrJrefVec1NVectoritem = scrJrefVec1NVectoritem;
			this.scrJrefFct1NTablecol = scrJrefFct1NTablecol;
			this.pnlfct1ntablecolAvail = pnlfct1ntablecolAvail;
			this.scrJrefRef1NPanel = scrJrefRef1NPanel;
			this.scrJrefSrc1NFeed = scrJrefSrc1NFeed;
			this.scrJrefPst1NQuerymod = scrJrefPst1NQuerymod;
			this.pnlpst1nquerymodAvail = pnlpst1nquerymodAvail;
			this.scrJrefMNTable = scrJrefMNTable;
			this.pnlmntableAvail = pnlmntableAvail;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, SCRJREFVEC1NVECTORITEM, SCRJREFFCT1NTABLECOL, PNLFCT1NTABLECOLAVAIL, SCRJREFREF1NPANEL, SCRJREFSRC1NFEED, SCRJREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, SCRJREFMNTABLE, PNLMNTABLEAVAIL, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefATitle;
		public String scrJrefVec1NVectoritem;
		public String scrJrefFct1NTablecol;
		public boolean pnlfct1ntablecolAvail;
		public String scrJrefRef1NPanel;
		public String scrJrefSrc1NFeed;
		public String scrJrefPst1NQuerymod;
		public boolean pnlpst1nquerymodAvail;
		public String scrJrefMNTable;
		public boolean pnlmntableAvail;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmVecRec");

			String itemtag = "StatitemShrWznmVecRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefATitle = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefATitle", mask, SCRJREFATITLE);
				scrJrefVec1NVectoritem = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefVec1NVectoritem", mask, SCRJREFVEC1NVECTORITEM);
				scrJrefFct1NTablecol = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefFct1NTablecol", mask, SCRJREFFCT1NTABLECOL);
				pnlfct1ntablecolAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlfct1ntablecolAvail", mask, PNLFCT1NTABLECOLAVAIL);
				scrJrefRef1NPanel = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NPanel", mask, SCRJREFREF1NPANEL);
				scrJrefSrc1NFeed = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSrc1NFeed", mask, SCRJREFSRC1NFEED);
				scrJrefPst1NQuerymod = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefPst1NQuerymod", mask, SCRJREFPST1NQUERYMOD);
				pnlpst1nquerymodAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlpst1nquerymodAvail", mask, PNLPST1NQUERYMODAVAIL);
				scrJrefMNTable = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNTable", mask, SCRJREFMNTABLE);
				pnlmntableAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlmntableAvail", mask, PNLMNTABLEAVAIL);
				ButRegularizeActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", mask, BUTREGULARIZEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (scrJrefDetail.equals(comp.scrJrefDetail)) items.add(SCRJREFDETAIL);
			if (scrJrefATitle.equals(comp.scrJrefATitle)) items.add(SCRJREFATITLE);
			if (scrJrefVec1NVectoritem.equals(comp.scrJrefVec1NVectoritem)) items.add(SCRJREFVEC1NVECTORITEM);
			if (scrJrefFct1NTablecol.equals(comp.scrJrefFct1NTablecol)) items.add(SCRJREFFCT1NTABLECOL);
			if (pnlfct1ntablecolAvail == comp.pnlfct1ntablecolAvail) items.add(PNLFCT1NTABLECOLAVAIL);
			if (scrJrefRef1NPanel.equals(comp.scrJrefRef1NPanel)) items.add(SCRJREFREF1NPANEL);
			if (scrJrefSrc1NFeed.equals(comp.scrJrefSrc1NFeed)) items.add(SCRJREFSRC1NFEED);
			if (scrJrefPst1NQuerymod.equals(comp.scrJrefPst1NQuerymod)) items.add(SCRJREFPST1NQUERYMOD);
			if (pnlpst1nquerymodAvail == comp.pnlpst1nquerymodAvail) items.add(PNLPST1NQUERYMODAVAIL);
			if (scrJrefMNTable.equals(comp.scrJrefMNTable)) items.add(SCRJREFMNTABLE);
			if (pnlmntableAvail == comp.pnlmntableAvail) items.add(PNLMNTABLEAVAIL);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, SCRJREFVEC1NVECTORITEM, SCRJREFFCT1NTABLECOL, PNLFCT1NTABLECOLAVAIL, SCRJREFREF1NPANEL, SCRJREFSRC1NFEED, SCRJREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, SCRJREFMNTABLE, PNLMNTABLEAVAIL, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmVecRec)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;

		public Tag(
					String Cpt
				) {
			this.Cpt = Cpt;

			mask = new HashSet<Integer>(Arrays.asList(CPT));
		};

		public String Cpt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmVecRec");

			String itemtag = "TagitemWznmVecRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmVecRecDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMVECRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmVecRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmVecRecData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMVECRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", false, "", "", "", false, "", false, false);
			tag = new Tag("");
		};

		public ContInf continf;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmVecRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", false, "", "", "", false, "", false, false);
				tag = new Tag("");
			};
		};

	};

};

