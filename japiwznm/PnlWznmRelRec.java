/**
  * \file PnlWznmRelRec.java
  * Java API code for job PnlWznmRelRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmRelRec {
	/**
		* VecVDo (full: VecVWznmRelRecDo)
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
	  * ContInf (full: ContInfWznmRelRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmRelRec");

			String itemtag = "ContitemInfWznmRelRec";

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
	  * StatApp (full: StatAppWznmRelRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEATITLE = 2;
		public static final int INITDONE1NTABLECOL = 3;
		public static final int INITDONESUP1NRELATION = 4;
		public static final int INITDONEREF1NPANEL = 5;
		public static final int INITDONEREF1NDIALOG = 6;
		public static final int INITDONEREF1NCONTROL = 7;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneATitle
					, boolean initdone1NTablecol
					, boolean initdoneSup1NRelation
					, boolean initdoneRef1NPanel
					, boolean initdoneRef1NDialog
					, boolean initdoneRef1NControl
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneATitle = initdoneATitle;
			this.initdone1NTablecol = initdone1NTablecol;
			this.initdoneSup1NRelation = initdoneSup1NRelation;
			this.initdoneRef1NPanel = initdoneRef1NPanel;
			this.initdoneRef1NDialog = initdoneRef1NDialog;
			this.initdoneRef1NControl = initdoneRef1NControl;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEATITLE, INITDONE1NTABLECOL, INITDONESUP1NRELATION, INITDONEREF1NPANEL, INITDONEREF1NDIALOG, INITDONEREF1NCONTROL));
		};

		public boolean initdoneDetail;
		public boolean initdoneATitle;
		public boolean initdone1NTablecol;
		public boolean initdoneSup1NRelation;
		public boolean initdoneRef1NPanel;
		public boolean initdoneRef1NDialog;
		public boolean initdoneRef1NControl;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmRelRec");

			String itemtag = "StatitemAppWznmRelRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneATitle = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneATitle", mask, INITDONEATITLE);
				initdone1NTablecol = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NTablecol", mask, INITDONE1NTABLECOL);
				initdoneSup1NRelation = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSup1NRelation", mask, INITDONESUP1NRELATION);
				initdoneRef1NPanel = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NPanel", mask, INITDONEREF1NPANEL);
				initdoneRef1NDialog = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NDialog", mask, INITDONEREF1NDIALOG);
				initdoneRef1NControl = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NControl", mask, INITDONEREF1NCONTROL);

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
			if (initdone1NTablecol == comp.initdone1NTablecol) items.add(INITDONE1NTABLECOL);
			if (initdoneSup1NRelation == comp.initdoneSup1NRelation) items.add(INITDONESUP1NRELATION);
			if (initdoneRef1NPanel == comp.initdoneRef1NPanel) items.add(INITDONEREF1NPANEL);
			if (initdoneRef1NDialog == comp.initdoneRef1NDialog) items.add(INITDONEREF1NDIALOG);
			if (initdoneRef1NControl == comp.initdoneRef1NControl) items.add(INITDONEREF1NCONTROL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEATITLE, INITDONE1NTABLECOL, INITDONESUP1NRELATION, INITDONEREF1NPANEL, INITDONEREF1NDIALOG, INITDONEREF1NCONTROL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmRelRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFATITLE = 3;
		public static final int SCRJREF1NTABLECOL = 4;
		public static final int SCRJREFSUP1NRELATION = 5;
		public static final int SCRJREFREF1NPANEL = 6;
		public static final int SCRJREFREF1NDIALOG = 7;
		public static final int SCRJREFREF1NCONTROL = 8;
		public static final int BUTREGULARIZEACTIVE = 9;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefATitle
					, String scrJref1NTablecol
					, String scrJrefSup1NRelation
					, String scrJrefRef1NPanel
					, String scrJrefRef1NDialog
					, String scrJrefRef1NControl
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefATitle = scrJrefATitle;
			this.scrJref1NTablecol = scrJref1NTablecol;
			this.scrJrefSup1NRelation = scrJrefSup1NRelation;
			this.scrJrefRef1NPanel = scrJrefRef1NPanel;
			this.scrJrefRef1NDialog = scrJrefRef1NDialog;
			this.scrJrefRef1NControl = scrJrefRef1NControl;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, SCRJREF1NTABLECOL, SCRJREFSUP1NRELATION, SCRJREFREF1NPANEL, SCRJREFREF1NDIALOG, SCRJREFREF1NCONTROL, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefATitle;
		public String scrJref1NTablecol;
		public String scrJrefSup1NRelation;
		public String scrJrefRef1NPanel;
		public String scrJrefRef1NDialog;
		public String scrJrefRef1NControl;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmRelRec");

			String itemtag = "StatitemShrWznmRelRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefATitle = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefATitle", mask, SCRJREFATITLE);
				scrJref1NTablecol = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NTablecol", mask, SCRJREF1NTABLECOL);
				scrJrefSup1NRelation = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSup1NRelation", mask, SCRJREFSUP1NRELATION);
				scrJrefRef1NPanel = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NPanel", mask, SCRJREFREF1NPANEL);
				scrJrefRef1NDialog = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NDialog", mask, SCRJREFREF1NDIALOG);
				scrJrefRef1NControl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NControl", mask, SCRJREFREF1NCONTROL);
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
			if (scrJref1NTablecol.equals(comp.scrJref1NTablecol)) items.add(SCRJREF1NTABLECOL);
			if (scrJrefSup1NRelation.equals(comp.scrJrefSup1NRelation)) items.add(SCRJREFSUP1NRELATION);
			if (scrJrefRef1NPanel.equals(comp.scrJrefRef1NPanel)) items.add(SCRJREFREF1NPANEL);
			if (scrJrefRef1NDialog.equals(comp.scrJrefRef1NDialog)) items.add(SCRJREFREF1NDIALOG);
			if (scrJrefRef1NControl.equals(comp.scrJrefRef1NControl)) items.add(SCRJREFREF1NCONTROL);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, SCRJREF1NTABLECOL, SCRJREFSUP1NRELATION, SCRJREFREF1NPANEL, SCRJREFREF1NDIALOG, SCRJREFREF1NCONTROL, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmRelRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmRelRec");

			String itemtag = "TagitemWznmRelRec";

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
		* DpchAppDo (full: DpchAppWznmRelRecDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMRELRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmRelRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmRelRecData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMRELRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", "", false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmRelRecData");

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
				statshr = new StatShr(0, "", "", "", "", "", "", "", false);
				tag = new Tag("");
			};
		};

	};

};
