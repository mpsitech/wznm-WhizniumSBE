/**
  * \file PnlWznmQryMNTable.java
  * Java API code for job PnlWznmQryMNTable
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmQryMNTable {
	/**
		* VecVDo (full: VecVWznmQryMNTableDo)
		*/
	public static class VecVDo {

		public static final int BUTADDCLICK = 1;
		public static final int BUTSUBCLICK = 2;
		public static final int BUTREFRESHCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butaddclick")) return BUTADDCLICK;
			if (s.equals("butsubclick")) return BUTSUBCLICK;
			if (s.equals("butrefreshclick")) return BUTREFRESHCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTADDCLICK) return("ButAddClick");
			if (ix == BUTSUBCLICK) return("ButSubClick");
			if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWznmQryMNTable)
	  */
	public class ContInf extends Block {

		public static final int NUMFCSIQST = 1;

		public ContInf(
					int numFCsiQst
				) {
			this.numFCsiQst = numFCsiQst;

			mask = new HashSet<Integer>(Arrays.asList(NUMFCSIQST));
		};

		public int numFCsiQst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmQryMNTable");

			String itemtag = "ContitemInfWznmQryMNTable";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFCsiQst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFCsiQst", mask, NUMFCSIQST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFCsiQst == comp.numFCsiQst) items.add(NUMFCSIQST);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFCSIQST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmQryMNTable)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmQryMNTable");

			String itemtag = "StatitemAppWznmQryMNTable";

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
	  * StatShr (full: StatShrWznmQryMNTable)
	  */
	public class StatShr extends Block {

		public static final int BUTADDAVAIL = 1;
		public static final int BUTSUBAVAIL = 2;
		public static final int BUTSUBACTIVE = 3;

		public StatShr(
					boolean ButAddAvail
					, boolean ButSubAvail
					, boolean ButSubActive
				) {
			this.ButAddAvail = ButAddAvail;
			this.ButSubAvail = ButSubAvail;
			this.ButSubActive = ButSubActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE));
		};

		public boolean ButAddAvail;
		public boolean ButSubAvail;
		public boolean ButSubActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmQryMNTable");

			String itemtag = "StatitemShrWznmQryMNTable";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButAddAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButAddAvail", mask, BUTADDAVAIL);
				ButSubAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSubAvail", mask, BUTSUBAVAIL);
				ButSubActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSubActive", mask, BUTSUBACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButAddAvail == comp.ButAddAvail) items.add(BUTADDAVAIL);
			if (ButSubAvail == comp.ButSubAvail) items.add(BUTSUBAVAIL);
			if (ButSubActive == comp.ButSubActive) items.add(BUTSUBACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTADDAVAIL, BUTSUBAVAIL, BUTSUBACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacWznmQryMNTable)
	  */
	public class StgIac extends Block {

		public static final int TCOMREFWIDTH = 1;
		public static final int TCOTQMDWIDTH = 2;
		public static final int TCOSRCWIDTH = 3;
		public static final int TCOPFXWIDTH = 4;

		public StgIac(
					int TcoMrefWidth
					, int TcoTqmdWidth
					, int TcoSrcWidth
					, int TcoPfxWidth
				) {
			this.TcoMrefWidth = TcoMrefWidth;
			this.TcoTqmdWidth = TcoTqmdWidth;
			this.TcoSrcWidth = TcoSrcWidth;
			this.TcoPfxWidth = TcoPfxWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOMREFWIDTH, TCOTQMDWIDTH, TCOSRCWIDTH, TCOPFXWIDTH));
		};

		public int TcoMrefWidth;
		public int TcoTqmdWidth;
		public int TcoSrcWidth;
		public int TcoPfxWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWznmQryMNTable");

			String itemtag = "StgitemIacWznmQryMNTable";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoMrefWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoMrefWidth", mask, TCOMREFWIDTH);
				TcoTqmdWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTqmdWidth", mask, TCOTQMDWIDTH);
				TcoSrcWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSrcWidth", mask, TCOSRCWIDTH);
				TcoPfxWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoPfxWidth", mask, TCOPFXWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWznmQryMNTable";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWznmQryMNTable";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoMrefWidth", TcoMrefWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTqmdWidth", TcoTqmdWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSrcWidth", TcoSrcWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoPfxWidth", TcoPfxWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoMrefWidth == comp.TcoMrefWidth) items.add(TCOMREFWIDTH);
			if (TcoTqmdWidth == comp.TcoTqmdWidth) items.add(TCOTQMDWIDTH);
			if (TcoSrcWidth == comp.TcoSrcWidth) items.add(TCOSRCWIDTH);
			if (TcoPfxWidth == comp.TcoPfxWidth) items.add(TCOPFXWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOMREFWIDTH, TCOTQMDWIDTH, TCOSRCWIDTH, TCOPFXWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmQryMNTable)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTRECORD1 = 2;
		public static final int TXTRECORD2 = 3;
		public static final int TRS = 4;
		public static final int TXTSHOWING1 = 5;
		public static final int TXTSHOWING2 = 6;
		public static final int TCOMREF = 7;
		public static final int TCOTQMD = 8;
		public static final int TCOSRC = 9;
		public static final int TCOPFX = 10;

		public Tag(
					String Cpt
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoMref
					, String TcoTqmd
					, String TcoSrc
					, String TcoPfx
				) {
			this.Cpt = Cpt;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoMref = TcoMref;
			this.TcoTqmd = TcoTqmd;
			this.TcoSrc = TcoSrc;
			this.TcoPfx = TcoPfx;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOMREF, TCOTQMD, TCOSRC, TCOPFX));
		};

		public String Cpt;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoMref;
		public String TcoTqmd;
		public String TcoSrc;
		public String TcoPfx;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmQryMNTable");

			String itemtag = "TagitemWznmQryMNTable";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoMref = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoMref", mask, TCOMREF);
				TcoTqmd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTqmd", mask, TCOTQMD);
				TcoSrc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSrc", mask, TCOSRC);
				TcoPfx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoPfx", mask, TCOPFX);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (TxtRecord1.equals(comp.TxtRecord1)) items.add(TXTRECORD1);
			if (TxtRecord2.equals(comp.TxtRecord2)) items.add(TXTRECORD2);
			if (Trs.equals(comp.Trs)) items.add(TRS);
			if (TxtShowing1.equals(comp.TxtShowing1)) items.add(TXTSHOWING1);
			if (TxtShowing2.equals(comp.TxtShowing2)) items.add(TXTSHOWING2);
			if (TcoMref.equals(comp.TcoMref)) items.add(TCOMREF);
			if (TcoTqmd.equals(comp.TcoTqmd)) items.add(TCOTQMD);
			if (TcoSrc.equals(comp.TcoSrc)) items.add(TCOSRC);
			if (TcoPfx.equals(comp.TcoPfx)) items.add(TCOPFX);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOMREF, TCOTQMD, TCOSRC, TCOPFX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmQryMNTableData)
		*/
	public class DpchAppData extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int STGIAC = 2;
		public static final int STGIACQRY = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, StgIac stgiac
					, QryWznmQryMNTable.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPWZNMQRYMNTABLEDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, STGIAC, STGIACQRY));
					break;
				};

			if (has(STGIAC)) this.stgiac = stgiac;
			if (has(STGIACQRY)) this.stgiacqry = stgiacqry;
		};

		public StgIac stgiac;
		public QryWznmQryMNTable.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWznmQryMNTableData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmQryMNTableDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMQRYMNTABLEDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmQryMNTableDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmQryMNTableData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFCSIQST = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int STGIAC = 6;
		public static final int TAG = 7;
		public static final int RST = 8;
		public static final int STATAPPQRY = 9;
		public static final int STATSHRQRY = 10;
		public static final int STGIACQRY = 11;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMQRYMNTABLEDATA);

			continf = new ContInf(0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false);
			stgiac = new StgIac(0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "");
			rst = new ListWznmQQryMNTable();
			statappqry = (new QryWznmQryMNTable()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWznmQryMNTable()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWznmQryMNTable()).new StgIac(0, 0, 0);
		};

		public ContInf continf;
		public Feed feedFCsiQst;
		public StatApp statapp;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWznmQQryMNTable rst;
		public QryWznmQryMNTable.StatApp statappqry;
		public QryWznmQryMNTable.StatShr statshrqry;
		public QryWznmQryMNTable.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFCSIQST)) ss.add("feedFCsiQst");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(TAG)) ss.add("tag");
			if (has(RST)) ss.add("rst");
			if (has(STATAPPQRY)) ss.add("statappqry");
			if (has(STATSHRQRY)) ss.add("statshrqry");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmQryMNTableData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFCsiQst.readXML(doc, basexpath, true)) add(FEEDFCSIQST);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (stgiac.readXML(doc, basexpath, true)) add(STGIAC);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (rst.readXML(doc, basexpath, true)) add(RST);
				if (statappqry.readXML(doc, basexpath, true)) add(STATAPPQRY);
				if (statshrqry.readXML(doc, basexpath, true)) add(STATSHRQRY);
				if (stgiacqry.readXML(doc, basexpath, true)) add(STGIACQRY);
			} else {
				scrJref = "";
				continf = new ContInf(0);
				feedFCsiQst = new Feed("FeedFCsiQst");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false);
				stgiac = new StgIac(0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "");
				statappqry = (new QryWznmQryMNTable()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWznmQryMNTable()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWznmQryMNTable()).new StgIac(0, 0, 0);
			};
		};

	};

};
