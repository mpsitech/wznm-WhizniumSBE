/**
  * \file PnlWznmBlkRec.java
  * Java API code for job PnlWznmBlkRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmBlkRec {
	/**
		* VecVDo (full: VecVWznmBlkRecDo)
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
	  * ContInf (full: ContInfWznmBlkRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmBlkRec");

			String itemtag = "ContitemInfWznmBlkRec";

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
	  * StatApp (full: StatAppWznmBlkRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEAITEM = 2;
		public static final int INITDONE1NRTDPCH = 3;
		public static final int INITDONEREF1NRTBLOCK = 4;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneAItem
					, boolean initdone1NRtdpch
					, boolean initdoneRef1NRtblock
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneAItem = initdoneAItem;
			this.initdone1NRtdpch = initdone1NRtdpch;
			this.initdoneRef1NRtblock = initdoneRef1NRtblock;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEAITEM, INITDONE1NRTDPCH, INITDONEREF1NRTBLOCK));
		};

		public boolean initdoneDetail;
		public boolean initdoneAItem;
		public boolean initdone1NRtdpch;
		public boolean initdoneRef1NRtblock;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmBlkRec");

			String itemtag = "StatitemAppWznmBlkRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneAItem = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAItem", mask, INITDONEAITEM);
				initdone1NRtdpch = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NRtdpch", mask, INITDONE1NRTDPCH);
				initdoneRef1NRtblock = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NRtblock", mask, INITDONEREF1NRTBLOCK);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdoneAItem == comp.initdoneAItem) items.add(INITDONEAITEM);
			if (initdone1NRtdpch == comp.initdone1NRtdpch) items.add(INITDONE1NRTDPCH);
			if (initdoneRef1NRtblock == comp.initdoneRef1NRtblock) items.add(INITDONEREF1NRTBLOCK);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEAITEM, INITDONE1NRTDPCH, INITDONEREF1NRTBLOCK));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmBlkRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFAITEM = 3;
		public static final int SCRJREF1NRTDPCH = 4;
		public static final int SCRJREFREF1NRTBLOCK = 5;
		public static final int BUTREGULARIZEACTIVE = 6;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefAItem
					, String scrJref1NRtdpch
					, String scrJrefRef1NRtblock
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefAItem = scrJrefAItem;
			this.scrJref1NRtdpch = scrJref1NRtdpch;
			this.scrJrefRef1NRtblock = scrJrefRef1NRtblock;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAITEM, SCRJREF1NRTDPCH, SCRJREFREF1NRTBLOCK, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefAItem;
		public String scrJref1NRtdpch;
		public String scrJrefRef1NRtblock;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmBlkRec");

			String itemtag = "StatitemShrWznmBlkRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefAItem = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAItem", mask, SCRJREFAITEM);
				scrJref1NRtdpch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NRtdpch", mask, SCRJREF1NRTDPCH);
				scrJrefRef1NRtblock = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NRtblock", mask, SCRJREFREF1NRTBLOCK);
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
			if (scrJrefAItem.equals(comp.scrJrefAItem)) items.add(SCRJREFAITEM);
			if (scrJref1NRtdpch.equals(comp.scrJref1NRtdpch)) items.add(SCRJREF1NRTDPCH);
			if (scrJrefRef1NRtblock.equals(comp.scrJrefRef1NRtblock)) items.add(SCRJREFREF1NRTBLOCK);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAITEM, SCRJREF1NRTDPCH, SCRJREFREF1NRTBLOCK, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmBlkRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmBlkRec");

			String itemtag = "TagitemWznmBlkRec";

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
		* DpchAppDo (full: DpchAppWznmBlkRecDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMBLKRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmBlkRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmBlkRecData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMBLKRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmBlkRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", false);
				tag = new Tag("");
			};
		};

	};

};
