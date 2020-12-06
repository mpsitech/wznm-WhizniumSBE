/**
  * \file PnlWznmSbsRec.java
  * Java API code for job PnlWznmSbsRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmSbsRec {
	/**
		* VecVDo (full: VecVWznmSbsRecDo)
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
	  * ContInf (full: ContInfWznmSbsRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmSbsRec");

			String itemtag = "ContitemInfWznmSbsRec";

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
	  * StatApp (full: StatAppWznmSbsRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEATITLE = 2;
		public static final int INITDONETOS1NRELATION = 3;
		public static final int INITDONE1NSTUB = 4;
		public static final int INITDONE1NTABLECOL = 5;
		public static final int INITDONEFRS1NRELATION = 6;
		public static final int INITDONEPST1NQUERYMOD = 7;
		public static final int INITDONEASBMNSUBSET = 8;
		public static final int INITDONEBSBMNSUBSET = 9;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneATitle
					, boolean initdoneTos1NRelation
					, boolean initdone1NStub
					, boolean initdone1NTablecol
					, boolean initdoneFrs1NRelation
					, boolean initdonePst1NQuerymod
					, boolean initdoneAsbMNSubset
					, boolean initdoneBsbMNSubset
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneATitle = initdoneATitle;
			this.initdoneTos1NRelation = initdoneTos1NRelation;
			this.initdone1NStub = initdone1NStub;
			this.initdone1NTablecol = initdone1NTablecol;
			this.initdoneFrs1NRelation = initdoneFrs1NRelation;
			this.initdonePst1NQuerymod = initdonePst1NQuerymod;
			this.initdoneAsbMNSubset = initdoneAsbMNSubset;
			this.initdoneBsbMNSubset = initdoneBsbMNSubset;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEATITLE, INITDONETOS1NRELATION, INITDONE1NSTUB, INITDONE1NTABLECOL, INITDONEFRS1NRELATION, INITDONEPST1NQUERYMOD, INITDONEASBMNSUBSET, INITDONEBSBMNSUBSET));
		};

		public boolean initdoneDetail;
		public boolean initdoneATitle;
		public boolean initdoneTos1NRelation;
		public boolean initdone1NStub;
		public boolean initdone1NTablecol;
		public boolean initdoneFrs1NRelation;
		public boolean initdonePst1NQuerymod;
		public boolean initdoneAsbMNSubset;
		public boolean initdoneBsbMNSubset;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmSbsRec");

			String itemtag = "StatitemAppWznmSbsRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneATitle = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneATitle", mask, INITDONEATITLE);
				initdoneTos1NRelation = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTos1NRelation", mask, INITDONETOS1NRELATION);
				initdone1NStub = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NStub", mask, INITDONE1NSTUB);
				initdone1NTablecol = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NTablecol", mask, INITDONE1NTABLECOL);
				initdoneFrs1NRelation = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneFrs1NRelation", mask, INITDONEFRS1NRELATION);
				initdonePst1NQuerymod = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdonePst1NQuerymod", mask, INITDONEPST1NQUERYMOD);
				initdoneAsbMNSubset = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAsbMNSubset", mask, INITDONEASBMNSUBSET);
				initdoneBsbMNSubset = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneBsbMNSubset", mask, INITDONEBSBMNSUBSET);

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
			if (initdoneTos1NRelation == comp.initdoneTos1NRelation) items.add(INITDONETOS1NRELATION);
			if (initdone1NStub == comp.initdone1NStub) items.add(INITDONE1NSTUB);
			if (initdone1NTablecol == comp.initdone1NTablecol) items.add(INITDONE1NTABLECOL);
			if (initdoneFrs1NRelation == comp.initdoneFrs1NRelation) items.add(INITDONEFRS1NRELATION);
			if (initdonePst1NQuerymod == comp.initdonePst1NQuerymod) items.add(INITDONEPST1NQUERYMOD);
			if (initdoneAsbMNSubset == comp.initdoneAsbMNSubset) items.add(INITDONEASBMNSUBSET);
			if (initdoneBsbMNSubset == comp.initdoneBsbMNSubset) items.add(INITDONEBSBMNSUBSET);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEATITLE, INITDONETOS1NRELATION, INITDONE1NSTUB, INITDONE1NTABLECOL, INITDONEFRS1NRELATION, INITDONEPST1NQUERYMOD, INITDONEASBMNSUBSET, INITDONEBSBMNSUBSET));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmSbsRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFATITLE = 3;
		public static final int SCRJREFTOS1NRELATION = 4;
		public static final int SCRJREF1NSTUB = 5;
		public static final int SCRJREF1NTABLECOL = 6;
		public static final int SCRJREFFRS1NRELATION = 7;
		public static final int SCRJREFPST1NQUERYMOD = 8;
		public static final int PNLPST1NQUERYMODAVAIL = 9;
		public static final int SCRJREFASBMNSUBSET = 10;
		public static final int SCRJREFBSBMNSUBSET = 11;
		public static final int BUTREGULARIZEACTIVE = 12;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefATitle
					, String scrJrefTos1NRelation
					, String scrJref1NStub
					, String scrJref1NTablecol
					, String scrJrefFrs1NRelation
					, String scrJrefPst1NQuerymod
					, boolean pnlpst1nquerymodAvail
					, String scrJrefAsbMNSubset
					, String scrJrefBsbMNSubset
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefATitle = scrJrefATitle;
			this.scrJrefTos1NRelation = scrJrefTos1NRelation;
			this.scrJref1NStub = scrJref1NStub;
			this.scrJref1NTablecol = scrJref1NTablecol;
			this.scrJrefFrs1NRelation = scrJrefFrs1NRelation;
			this.scrJrefPst1NQuerymod = scrJrefPst1NQuerymod;
			this.pnlpst1nquerymodAvail = pnlpst1nquerymodAvail;
			this.scrJrefAsbMNSubset = scrJrefAsbMNSubset;
			this.scrJrefBsbMNSubset = scrJrefBsbMNSubset;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, SCRJREFTOS1NRELATION, SCRJREF1NSTUB, SCRJREF1NTABLECOL, SCRJREFFRS1NRELATION, SCRJREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, SCRJREFASBMNSUBSET, SCRJREFBSBMNSUBSET, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefATitle;
		public String scrJrefTos1NRelation;
		public String scrJref1NStub;
		public String scrJref1NTablecol;
		public String scrJrefFrs1NRelation;
		public String scrJrefPst1NQuerymod;
		public boolean pnlpst1nquerymodAvail;
		public String scrJrefAsbMNSubset;
		public String scrJrefBsbMNSubset;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmSbsRec");

			String itemtag = "StatitemShrWznmSbsRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefATitle = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefATitle", mask, SCRJREFATITLE);
				scrJrefTos1NRelation = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTos1NRelation", mask, SCRJREFTOS1NRELATION);
				scrJref1NStub = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NStub", mask, SCRJREF1NSTUB);
				scrJref1NTablecol = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NTablecol", mask, SCRJREF1NTABLECOL);
				scrJrefFrs1NRelation = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefFrs1NRelation", mask, SCRJREFFRS1NRELATION);
				scrJrefPst1NQuerymod = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefPst1NQuerymod", mask, SCRJREFPST1NQUERYMOD);
				pnlpst1nquerymodAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlpst1nquerymodAvail", mask, PNLPST1NQUERYMODAVAIL);
				scrJrefAsbMNSubset = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAsbMNSubset", mask, SCRJREFASBMNSUBSET);
				scrJrefBsbMNSubset = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefBsbMNSubset", mask, SCRJREFBSBMNSUBSET);
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
			if (scrJrefTos1NRelation.equals(comp.scrJrefTos1NRelation)) items.add(SCRJREFTOS1NRELATION);
			if (scrJref1NStub.equals(comp.scrJref1NStub)) items.add(SCRJREF1NSTUB);
			if (scrJref1NTablecol.equals(comp.scrJref1NTablecol)) items.add(SCRJREF1NTABLECOL);
			if (scrJrefFrs1NRelation.equals(comp.scrJrefFrs1NRelation)) items.add(SCRJREFFRS1NRELATION);
			if (scrJrefPst1NQuerymod.equals(comp.scrJrefPst1NQuerymod)) items.add(SCRJREFPST1NQUERYMOD);
			if (pnlpst1nquerymodAvail == comp.pnlpst1nquerymodAvail) items.add(PNLPST1NQUERYMODAVAIL);
			if (scrJrefAsbMNSubset.equals(comp.scrJrefAsbMNSubset)) items.add(SCRJREFASBMNSUBSET);
			if (scrJrefBsbMNSubset.equals(comp.scrJrefBsbMNSubset)) items.add(SCRJREFBSBMNSUBSET);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, SCRJREFTOS1NRELATION, SCRJREF1NSTUB, SCRJREF1NTABLECOL, SCRJREFFRS1NRELATION, SCRJREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, SCRJREFASBMNSUBSET, SCRJREFBSBMNSUBSET, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmSbsRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmSbsRec");

			String itemtag = "TagitemWznmSbsRec";

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
		* DpchAppDo (full: DpchAppWznmSbsRecDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMSBSRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmSbsRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmSbsRecData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMSBSRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", "", false, "", "", false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmSbsRecData");

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
				statshr = new StatShr(0, "", "", "", "", "", "", "", false, "", "", false);
				tag = new Tag("");
			};
		};

	};

};
