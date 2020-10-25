/**
  * \file PnlWznmTcoRec.java
  * Java API code for job PnlWznmTcoRec
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmTcoRec {
	/**
		* VecVDo (full: VecVWznmTcoRecDo)
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
	  * ContInf (full: ContInfWznmTcoRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmTcoRec");

			String itemtag = "ContitemInfWznmTcoRec";

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
	  * StatApp (full: StatAppWznmTcoRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEATITLE = 2;
		public static final int INITDONE1NIMPEXPCOL = 3;
		public static final int INITDONE1NQUERYCOL = 4;
		public static final int INITDONEREF1NCONTROL = 5;
		public static final int INITDONEREF1NQUERYMOD = 6;
		public static final int INITDONE1NCHECK = 7;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneATitle
					, boolean initdone1NImpexpcol
					, boolean initdone1NQuerycol
					, boolean initdoneRef1NControl
					, boolean initdoneRef1NQuerymod
					, boolean initdone1NCheck
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneATitle = initdoneATitle;
			this.initdone1NImpexpcol = initdone1NImpexpcol;
			this.initdone1NQuerycol = initdone1NQuerycol;
			this.initdoneRef1NControl = initdoneRef1NControl;
			this.initdoneRef1NQuerymod = initdoneRef1NQuerymod;
			this.initdone1NCheck = initdone1NCheck;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEATITLE, INITDONE1NIMPEXPCOL, INITDONE1NQUERYCOL, INITDONEREF1NCONTROL, INITDONEREF1NQUERYMOD, INITDONE1NCHECK));
		};

		public boolean initdoneDetail;
		public boolean initdoneATitle;
		public boolean initdone1NImpexpcol;
		public boolean initdone1NQuerycol;
		public boolean initdoneRef1NControl;
		public boolean initdoneRef1NQuerymod;
		public boolean initdone1NCheck;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmTcoRec");

			String itemtag = "StatitemAppWznmTcoRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneATitle = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneATitle", mask, INITDONEATITLE);
				initdone1NImpexpcol = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NImpexpcol", mask, INITDONE1NIMPEXPCOL);
				initdone1NQuerycol = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NQuerycol", mask, INITDONE1NQUERYCOL);
				initdoneRef1NControl = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NControl", mask, INITDONEREF1NCONTROL);
				initdoneRef1NQuerymod = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NQuerymod", mask, INITDONEREF1NQUERYMOD);
				initdone1NCheck = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NCheck", mask, INITDONE1NCHECK);

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
			if (initdone1NImpexpcol == comp.initdone1NImpexpcol) items.add(INITDONE1NIMPEXPCOL);
			if (initdone1NQuerycol == comp.initdone1NQuerycol) items.add(INITDONE1NQUERYCOL);
			if (initdoneRef1NControl == comp.initdoneRef1NControl) items.add(INITDONEREF1NCONTROL);
			if (initdoneRef1NQuerymod == comp.initdoneRef1NQuerymod) items.add(INITDONEREF1NQUERYMOD);
			if (initdone1NCheck == comp.initdone1NCheck) items.add(INITDONE1NCHECK);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEATITLE, INITDONE1NIMPEXPCOL, INITDONE1NQUERYCOL, INITDONEREF1NCONTROL, INITDONEREF1NQUERYMOD, INITDONE1NCHECK));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmTcoRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFATITLE = 3;
		public static final int PNLATITLEAVAIL = 4;
		public static final int SCRJREF1NIMPEXPCOL = 5;
		public static final int PNL1NIMPEXPCOLAVAIL = 6;
		public static final int SCRJREF1NQUERYCOL = 7;
		public static final int PNL1NQUERYCOLAVAIL = 8;
		public static final int SCRJREFREF1NCONTROL = 9;
		public static final int PNLREF1NCONTROLAVAIL = 10;
		public static final int SCRJREFREF1NQUERYMOD = 11;
		public static final int PNLREF1NQUERYMODAVAIL = 12;
		public static final int SCRJREF1NCHECK = 13;
		public static final int BUTREGULARIZEACTIVE = 14;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefATitle
					, boolean pnlatitleAvail
					, String scrJref1NImpexpcol
					, boolean pnl1nimpexpcolAvail
					, String scrJref1NQuerycol
					, boolean pnl1nquerycolAvail
					, String scrJrefRef1NControl
					, boolean pnlref1ncontrolAvail
					, String scrJrefRef1NQuerymod
					, boolean pnlref1nquerymodAvail
					, String scrJref1NCheck
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefATitle = scrJrefATitle;
			this.pnlatitleAvail = pnlatitleAvail;
			this.scrJref1NImpexpcol = scrJref1NImpexpcol;
			this.pnl1nimpexpcolAvail = pnl1nimpexpcolAvail;
			this.scrJref1NQuerycol = scrJref1NQuerycol;
			this.pnl1nquerycolAvail = pnl1nquerycolAvail;
			this.scrJrefRef1NControl = scrJrefRef1NControl;
			this.pnlref1ncontrolAvail = pnlref1ncontrolAvail;
			this.scrJrefRef1NQuerymod = scrJrefRef1NQuerymod;
			this.pnlref1nquerymodAvail = pnlref1nquerymodAvail;
			this.scrJref1NCheck = scrJref1NCheck;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, PNLATITLEAVAIL, SCRJREF1NIMPEXPCOL, PNL1NIMPEXPCOLAVAIL, SCRJREF1NQUERYCOL, PNL1NQUERYCOLAVAIL, SCRJREFREF1NCONTROL, PNLREF1NCONTROLAVAIL, SCRJREFREF1NQUERYMOD, PNLREF1NQUERYMODAVAIL, SCRJREF1NCHECK, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefATitle;
		public boolean pnlatitleAvail;
		public String scrJref1NImpexpcol;
		public boolean pnl1nimpexpcolAvail;
		public String scrJref1NQuerycol;
		public boolean pnl1nquerycolAvail;
		public String scrJrefRef1NControl;
		public boolean pnlref1ncontrolAvail;
		public String scrJrefRef1NQuerymod;
		public boolean pnlref1nquerymodAvail;
		public String scrJref1NCheck;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmTcoRec");

			String itemtag = "StatitemShrWznmTcoRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefATitle = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefATitle", mask, SCRJREFATITLE);
				pnlatitleAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlatitleAvail", mask, PNLATITLEAVAIL);
				scrJref1NImpexpcol = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NImpexpcol", mask, SCRJREF1NIMPEXPCOL);
				pnl1nimpexpcolAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnl1nimpexpcolAvail", mask, PNL1NIMPEXPCOLAVAIL);
				scrJref1NQuerycol = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NQuerycol", mask, SCRJREF1NQUERYCOL);
				pnl1nquerycolAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnl1nquerycolAvail", mask, PNL1NQUERYCOLAVAIL);
				scrJrefRef1NControl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NControl", mask, SCRJREFREF1NCONTROL);
				pnlref1ncontrolAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlref1ncontrolAvail", mask, PNLREF1NCONTROLAVAIL);
				scrJrefRef1NQuerymod = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NQuerymod", mask, SCRJREFREF1NQUERYMOD);
				pnlref1nquerymodAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlref1nquerymodAvail", mask, PNLREF1NQUERYMODAVAIL);
				scrJref1NCheck = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NCheck", mask, SCRJREF1NCHECK);
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
			if (pnlatitleAvail == comp.pnlatitleAvail) items.add(PNLATITLEAVAIL);
			if (scrJref1NImpexpcol.equals(comp.scrJref1NImpexpcol)) items.add(SCRJREF1NIMPEXPCOL);
			if (pnl1nimpexpcolAvail == comp.pnl1nimpexpcolAvail) items.add(PNL1NIMPEXPCOLAVAIL);
			if (scrJref1NQuerycol.equals(comp.scrJref1NQuerycol)) items.add(SCRJREF1NQUERYCOL);
			if (pnl1nquerycolAvail == comp.pnl1nquerycolAvail) items.add(PNL1NQUERYCOLAVAIL);
			if (scrJrefRef1NControl.equals(comp.scrJrefRef1NControl)) items.add(SCRJREFREF1NCONTROL);
			if (pnlref1ncontrolAvail == comp.pnlref1ncontrolAvail) items.add(PNLREF1NCONTROLAVAIL);
			if (scrJrefRef1NQuerymod.equals(comp.scrJrefRef1NQuerymod)) items.add(SCRJREFREF1NQUERYMOD);
			if (pnlref1nquerymodAvail == comp.pnlref1nquerymodAvail) items.add(PNLREF1NQUERYMODAVAIL);
			if (scrJref1NCheck.equals(comp.scrJref1NCheck)) items.add(SCRJREF1NCHECK);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, PNLATITLEAVAIL, SCRJREF1NIMPEXPCOL, PNL1NIMPEXPCOLAVAIL, SCRJREF1NQUERYCOL, PNL1NQUERYCOLAVAIL, SCRJREFREF1NCONTROL, PNLREF1NCONTROLAVAIL, SCRJREFREF1NQUERYMOD, PNLREF1NQUERYMODAVAIL, SCRJREF1NCHECK, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmTcoRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmTcoRec");

			String itemtag = "TagitemWznmTcoRec";

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
		* DpchAppDo (full: DpchAppWznmTcoRecDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMTCORECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmTcoRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmTcoRecData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMTCORECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", false, "", false, "", false, "", false, "", false, "", false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmTcoRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", false, "", false, "", false, "", false, "", false, "", false);
				tag = new Tag("");
			};
		};

	};

};

