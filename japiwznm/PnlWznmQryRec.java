/**
  * \file PnlWznmQryRec.java
  * Java API code for job PnlWznmQryRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmQryRec {
	/**
		* VecVDo (full: VecVWznmQryRecDo)
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
	  * ContInf (full: ContInfWznmQryRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmQryRec");

			String itemtag = "ContitemInfWznmQryRec";

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
	  * StatApp (full: StatAppWznmQryRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEACLAUSE = 2;
		public static final int INITDONEAORDER = 3;
		public static final int INITDONE1NQUERYMOD = 4;
		public static final int INITDONEQRY1NQUERYCOL = 5;
		public static final int INITDONESUP1NQUERY = 6;
		public static final int INITDONEMNTABLE = 7;
		public static final int INITDONEMNDIALOG = 8;
		public static final int INITDONEMNPANEL = 9;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneAClause
					, boolean initdoneAOrder
					, boolean initdone1NQuerymod
					, boolean initdoneQry1NQuerycol
					, boolean initdoneSup1NQuery
					, boolean initdoneMNTable
					, boolean initdoneMNDialog
					, boolean initdoneMNPanel
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneAClause = initdoneAClause;
			this.initdoneAOrder = initdoneAOrder;
			this.initdone1NQuerymod = initdone1NQuerymod;
			this.initdoneQry1NQuerycol = initdoneQry1NQuerycol;
			this.initdoneSup1NQuery = initdoneSup1NQuery;
			this.initdoneMNTable = initdoneMNTable;
			this.initdoneMNDialog = initdoneMNDialog;
			this.initdoneMNPanel = initdoneMNPanel;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEACLAUSE, INITDONEAORDER, INITDONE1NQUERYMOD, INITDONEQRY1NQUERYCOL, INITDONESUP1NQUERY, INITDONEMNTABLE, INITDONEMNDIALOG, INITDONEMNPANEL));
		};

		public boolean initdoneDetail;
		public boolean initdoneAClause;
		public boolean initdoneAOrder;
		public boolean initdone1NQuerymod;
		public boolean initdoneQry1NQuerycol;
		public boolean initdoneSup1NQuery;
		public boolean initdoneMNTable;
		public boolean initdoneMNDialog;
		public boolean initdoneMNPanel;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmQryRec");

			String itemtag = "StatitemAppWznmQryRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneAClause = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAClause", mask, INITDONEACLAUSE);
				initdoneAOrder = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAOrder", mask, INITDONEAORDER);
				initdone1NQuerymod = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NQuerymod", mask, INITDONE1NQUERYMOD);
				initdoneQry1NQuerycol = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneQry1NQuerycol", mask, INITDONEQRY1NQUERYCOL);
				initdoneSup1NQuery = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSup1NQuery", mask, INITDONESUP1NQUERY);
				initdoneMNTable = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNTable", mask, INITDONEMNTABLE);
				initdoneMNDialog = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNDialog", mask, INITDONEMNDIALOG);
				initdoneMNPanel = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNPanel", mask, INITDONEMNPANEL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdoneAClause == comp.initdoneAClause) items.add(INITDONEACLAUSE);
			if (initdoneAOrder == comp.initdoneAOrder) items.add(INITDONEAORDER);
			if (initdone1NQuerymod == comp.initdone1NQuerymod) items.add(INITDONE1NQUERYMOD);
			if (initdoneQry1NQuerycol == comp.initdoneQry1NQuerycol) items.add(INITDONEQRY1NQUERYCOL);
			if (initdoneSup1NQuery == comp.initdoneSup1NQuery) items.add(INITDONESUP1NQUERY);
			if (initdoneMNTable == comp.initdoneMNTable) items.add(INITDONEMNTABLE);
			if (initdoneMNDialog == comp.initdoneMNDialog) items.add(INITDONEMNDIALOG);
			if (initdoneMNPanel == comp.initdoneMNPanel) items.add(INITDONEMNPANEL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEACLAUSE, INITDONEAORDER, INITDONE1NQUERYMOD, INITDONEQRY1NQUERYCOL, INITDONESUP1NQUERY, INITDONEMNTABLE, INITDONEMNDIALOG, INITDONEMNPANEL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmQryRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFACLAUSE = 3;
		public static final int SCRJREFAORDER = 4;
		public static final int SCRJREF1NQUERYMOD = 5;
		public static final int SCRJREFQRY1NQUERYCOL = 6;
		public static final int SCRJREFSUP1NQUERY = 7;
		public static final int SCRJREFMNTABLE = 8;
		public static final int SCRJREFMNDIALOG = 9;
		public static final int SCRJREFMNPANEL = 10;
		public static final int BUTREGULARIZEACTIVE = 11;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefAClause
					, String scrJrefAOrder
					, String scrJref1NQuerymod
					, String scrJrefQry1NQuerycol
					, String scrJrefSup1NQuery
					, String scrJrefMNTable
					, String scrJrefMNDialog
					, String scrJrefMNPanel
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefAClause = scrJrefAClause;
			this.scrJrefAOrder = scrJrefAOrder;
			this.scrJref1NQuerymod = scrJref1NQuerymod;
			this.scrJrefQry1NQuerycol = scrJrefQry1NQuerycol;
			this.scrJrefSup1NQuery = scrJrefSup1NQuery;
			this.scrJrefMNTable = scrJrefMNTable;
			this.scrJrefMNDialog = scrJrefMNDialog;
			this.scrJrefMNPanel = scrJrefMNPanel;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFACLAUSE, SCRJREFAORDER, SCRJREF1NQUERYMOD, SCRJREFQRY1NQUERYCOL, SCRJREFSUP1NQUERY, SCRJREFMNTABLE, SCRJREFMNDIALOG, SCRJREFMNPANEL, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefAClause;
		public String scrJrefAOrder;
		public String scrJref1NQuerymod;
		public String scrJrefQry1NQuerycol;
		public String scrJrefSup1NQuery;
		public String scrJrefMNTable;
		public String scrJrefMNDialog;
		public String scrJrefMNPanel;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmQryRec");

			String itemtag = "StatitemShrWznmQryRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefAClause = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAClause", mask, SCRJREFACLAUSE);
				scrJrefAOrder = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAOrder", mask, SCRJREFAORDER);
				scrJref1NQuerymod = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NQuerymod", mask, SCRJREF1NQUERYMOD);
				scrJrefQry1NQuerycol = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefQry1NQuerycol", mask, SCRJREFQRY1NQUERYCOL);
				scrJrefSup1NQuery = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSup1NQuery", mask, SCRJREFSUP1NQUERY);
				scrJrefMNTable = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNTable", mask, SCRJREFMNTABLE);
				scrJrefMNDialog = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNDialog", mask, SCRJREFMNDIALOG);
				scrJrefMNPanel = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNPanel", mask, SCRJREFMNPANEL);
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
			if (scrJrefAClause.equals(comp.scrJrefAClause)) items.add(SCRJREFACLAUSE);
			if (scrJrefAOrder.equals(comp.scrJrefAOrder)) items.add(SCRJREFAORDER);
			if (scrJref1NQuerymod.equals(comp.scrJref1NQuerymod)) items.add(SCRJREF1NQUERYMOD);
			if (scrJrefQry1NQuerycol.equals(comp.scrJrefQry1NQuerycol)) items.add(SCRJREFQRY1NQUERYCOL);
			if (scrJrefSup1NQuery.equals(comp.scrJrefSup1NQuery)) items.add(SCRJREFSUP1NQUERY);
			if (scrJrefMNTable.equals(comp.scrJrefMNTable)) items.add(SCRJREFMNTABLE);
			if (scrJrefMNDialog.equals(comp.scrJrefMNDialog)) items.add(SCRJREFMNDIALOG);
			if (scrJrefMNPanel.equals(comp.scrJrefMNPanel)) items.add(SCRJREFMNPANEL);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFACLAUSE, SCRJREFAORDER, SCRJREF1NQUERYMOD, SCRJREFQRY1NQUERYCOL, SCRJREFSUP1NQUERY, SCRJREFMNTABLE, SCRJREFMNDIALOG, SCRJREFMNPANEL, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmQryRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmQryRec");

			String itemtag = "TagitemWznmQryRec";

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
		* DpchAppDo (full: DpchAppWznmQryRecDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMQRYRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmQryRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmQryRecData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMQRYRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmQryRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", false);
				tag = new Tag("");
			};
		};

	};

};
