/**
  * \file PnlWznmTblALoadfct.java
  * Java API code for job PnlWznmTblALoadfct
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmTblALoadfct {
	/**
		* VecVDo (full: VecVWznmTblALoadfctDo)
		*/
	public static class VecVDo {

		public static final int BUTNEWCLICK = 1;
		public static final int BUTDUPLICATECLICK = 2;
		public static final int BUTDELETECLICK = 3;
		public static final int BUTREFRESHCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butnewclick")) return BUTNEWCLICK;
			if (s.equals("butduplicateclick")) return BUTDUPLICATECLICK;
			if (s.equals("butdeleteclick")) return BUTDELETECLICK;
			if (s.equals("butrefreshclick")) return BUTREFRESHCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTNEWCLICK) return("ButNewClick");
			if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
			if (ix == BUTDELETECLICK) return("ButDeleteClick");
			if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWznmTblALoadfct)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmTblALoadfct");

			String itemtag = "ContitemInfWznmTblALoadfct";

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
	  * StatApp (full: StatAppWznmTblALoadfct)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmTblALoadfct");

			String itemtag = "StatitemAppWznmTblALoadfct";

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
	  * StatShr (full: StatShrWznmTblALoadfct)
	  */
	public class StatShr extends Block {

		public static final int BUTNEWAVAIL = 1;
		public static final int BUTDUPLICATEAVAIL = 2;
		public static final int BUTDUPLICATEACTIVE = 3;
		public static final int BUTDELETEAVAIL = 4;
		public static final int BUTDELETEACTIVE = 5;

		public StatShr(
					boolean ButNewAvail
					, boolean ButDuplicateAvail
					, boolean ButDuplicateActive
					, boolean ButDeleteAvail
					, boolean ButDeleteActive
				) {
			this.ButNewAvail = ButNewAvail;
			this.ButDuplicateAvail = ButDuplicateAvail;
			this.ButDuplicateActive = ButDuplicateActive;
			this.ButDeleteAvail = ButDeleteAvail;
			this.ButDeleteActive = ButDeleteActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE));
		};

		public boolean ButNewAvail;
		public boolean ButDuplicateAvail;
		public boolean ButDuplicateActive;
		public boolean ButDeleteAvail;
		public boolean ButDeleteActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmTblALoadfct");

			String itemtag = "StatitemShrWznmTblALoadfct";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButNewAvail", mask, BUTNEWAVAIL);
				ButDuplicateAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDuplicateAvail", mask, BUTDUPLICATEAVAIL);
				ButDuplicateActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDuplicateActive", mask, BUTDUPLICATEACTIVE);
				ButDeleteAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDeleteAvail", mask, BUTDELETEAVAIL);
				ButDeleteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDeleteActive", mask, BUTDELETEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButNewAvail == comp.ButNewAvail) items.add(BUTNEWAVAIL);
			if (ButDuplicateAvail == comp.ButDuplicateAvail) items.add(BUTDUPLICATEAVAIL);
			if (ButDuplicateActive == comp.ButDuplicateActive) items.add(BUTDUPLICATEACTIVE);
			if (ButDeleteAvail == comp.ButDeleteAvail) items.add(BUTDELETEAVAIL);
			if (ButDeleteActive == comp.ButDeleteActive) items.add(BUTDELETEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacWznmTblALoadfct)
	  */
	public class StgIac extends Block {

		public static final int TCOLOTWIDTH = 1;
		public static final int TCOFNAWIDTH = 2;
		public static final int TCOLDXWIDTH = 3;
		public static final int TCOLBYWIDTH = 4;
		public static final int TCOORDWIDTH = 5;
		public static final int TCOLITWIDTH = 6;

		public StgIac(
					int TcoLotWidth
					, int TcoFnaWidth
					, int TcoLdxWidth
					, int TcoLbyWidth
					, int TcoOrdWidth
					, int TcoLitWidth
				) {
			this.TcoLotWidth = TcoLotWidth;
			this.TcoFnaWidth = TcoFnaWidth;
			this.TcoLdxWidth = TcoLdxWidth;
			this.TcoLbyWidth = TcoLbyWidth;
			this.TcoOrdWidth = TcoOrdWidth;
			this.TcoLitWidth = TcoLitWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOLOTWIDTH, TCOFNAWIDTH, TCOLDXWIDTH, TCOLBYWIDTH, TCOORDWIDTH, TCOLITWIDTH));
		};

		public int TcoLotWidth;
		public int TcoFnaWidth;
		public int TcoLdxWidth;
		public int TcoLbyWidth;
		public int TcoOrdWidth;
		public int TcoLitWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWznmTblALoadfct");

			String itemtag = "StgitemIacWznmTblALoadfct";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoLotWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoLotWidth", mask, TCOLOTWIDTH);
				TcoFnaWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoFnaWidth", mask, TCOFNAWIDTH);
				TcoLdxWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoLdxWidth", mask, TCOLDXWIDTH);
				TcoLbyWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoLbyWidth", mask, TCOLBYWIDTH);
				TcoOrdWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoOrdWidth", mask, TCOORDWIDTH);
				TcoLitWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoLitWidth", mask, TCOLITWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWznmTblALoadfct";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWznmTblALoadfct";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoLotWidth", TcoLotWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoFnaWidth", TcoFnaWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoLdxWidth", TcoLdxWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoLbyWidth", TcoLbyWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoOrdWidth", TcoOrdWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoLitWidth", TcoLitWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoLotWidth == comp.TcoLotWidth) items.add(TCOLOTWIDTH);
			if (TcoFnaWidth == comp.TcoFnaWidth) items.add(TCOFNAWIDTH);
			if (TcoLdxWidth == comp.TcoLdxWidth) items.add(TCOLDXWIDTH);
			if (TcoLbyWidth == comp.TcoLbyWidth) items.add(TCOLBYWIDTH);
			if (TcoOrdWidth == comp.TcoOrdWidth) items.add(TCOORDWIDTH);
			if (TcoLitWidth == comp.TcoLitWidth) items.add(TCOLITWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOLOTWIDTH, TCOFNAWIDTH, TCOLDXWIDTH, TCOLBYWIDTH, TCOORDWIDTH, TCOLITWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmTblALoadfct)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTRECORD1 = 2;
		public static final int TXTRECORD2 = 3;
		public static final int TRS = 4;
		public static final int TXTSHOWING1 = 5;
		public static final int TXTSHOWING2 = 6;
		public static final int TCOLOT = 7;
		public static final int TCOFNA = 8;
		public static final int TCOLDX = 9;
		public static final int TCOLBY = 10;
		public static final int TCOORD = 11;
		public static final int TCOLIT = 12;

		public Tag(
					String Cpt
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoLot
					, String TcoFna
					, String TcoLdx
					, String TcoLby
					, String TcoOrd
					, String TcoLit
				) {
			this.Cpt = Cpt;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoLot = TcoLot;
			this.TcoFna = TcoFna;
			this.TcoLdx = TcoLdx;
			this.TcoLby = TcoLby;
			this.TcoOrd = TcoOrd;
			this.TcoLit = TcoLit;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOLOT, TCOFNA, TCOLDX, TCOLBY, TCOORD, TCOLIT));
		};

		public String Cpt;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoLot;
		public String TcoFna;
		public String TcoLdx;
		public String TcoLby;
		public String TcoOrd;
		public String TcoLit;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmTblALoadfct");

			String itemtag = "TagitemWznmTblALoadfct";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoLot = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoLot", mask, TCOLOT);
				TcoFna = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoFna", mask, TCOFNA);
				TcoLdx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoLdx", mask, TCOLDX);
				TcoLby = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoLby", mask, TCOLBY);
				TcoOrd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoOrd", mask, TCOORD);
				TcoLit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoLit", mask, TCOLIT);

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
			if (TcoLot.equals(comp.TcoLot)) items.add(TCOLOT);
			if (TcoFna.equals(comp.TcoFna)) items.add(TCOFNA);
			if (TcoLdx.equals(comp.TcoLdx)) items.add(TCOLDX);
			if (TcoLby.equals(comp.TcoLby)) items.add(TCOLBY);
			if (TcoOrd.equals(comp.TcoOrd)) items.add(TCOORD);
			if (TcoLit.equals(comp.TcoLit)) items.add(TCOLIT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOLOT, TCOFNA, TCOLDX, TCOLBY, TCOORD, TCOLIT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmTblALoadfctData)
		*/
	public class DpchAppData extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int STGIAC = 2;
		public static final int STGIACQRY = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, StgIac stgiac
					, QryWznmTblALoadfct.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPWZNMTBLALOADFCTDATA, scrJref);

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
		public QryWznmTblALoadfct.StgIac stgiacqry;

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
			Element el = doc.createElement("DpchAppWznmTblALoadfctData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmTblALoadfctDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMTBLALOADFCTDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmTblALoadfctDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmTblALoadfctData)
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
			super(VecWznmVDpch.DPCHENGWZNMTBLALOADFCTDATA);

			continf = new ContInf(0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false);
			stgiac = new StgIac(0, 0, 0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "");
			rst = new ListWznmQTblALoadfct();
			statappqry = (new QryWznmTblALoadfct()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWznmTblALoadfct()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWznmTblALoadfct()).new StgIac(0, 0, 0);
		};

		public ContInf continf;
		public Feed feedFCsiQst;
		public StatApp statapp;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWznmQTblALoadfct rst;
		public QryWznmTblALoadfct.StatApp statappqry;
		public QryWznmTblALoadfct.StatShr statshrqry;
		public QryWznmTblALoadfct.StgIac stgiacqry;

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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmTblALoadfctData");

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
				statshr = new StatShr(false, false, false, false, false);
				stgiac = new StgIac(0, 0, 0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "");
				statappqry = (new QryWznmTblALoadfct()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWznmTblALoadfct()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWznmTblALoadfct()).new StgIac(0, 0, 0);
			};
		};

	};

};
