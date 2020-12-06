/**
  * \file PnlWznmSteATrig.java
  * Java API code for job PnlWznmSteATrig
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmSteATrig {
	/**
		* VecVDo (full: VecVWznmSteATrigDo)
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
	  * ContInf (full: ContInfWznmSteATrig)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmSteATrig");

			String itemtag = "ContitemInfWznmSteATrig";

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
	  * StatApp (full: StatAppWznmSteATrig)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmSteATrig");

			String itemtag = "StatitemAppWznmSteATrig";

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
	  * StatShr (full: StatShrWznmSteATrig)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmSteATrig");

			String itemtag = "StatitemShrWznmSteATrig";

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
	  * StgIac (full: StgIacWznmSteATrig)
	  */
	public class StgIac extends Block {

		public static final int TCOSRFWIDTH = 1;
		public static final int TCOTYPWIDTH = 2;
		public static final int TCOEVTWIDTH = 3;
		public static final int TCORTJWIDTH = 4;
		public static final int TCOVITWIDTH = 5;
		public static final int TCOXSRWIDTH = 6;
		public static final int TCORTDWIDTH = 7;
		public static final int TCOMSKWIDTH = 8;
		public static final int TCOCNDWIDTH = 9;

		public StgIac(
					int TcoSrfWidth
					, int TcoTypWidth
					, int TcoEvtWidth
					, int TcoRtjWidth
					, int TcoVitWidth
					, int TcoXsrWidth
					, int TcoRtdWidth
					, int TcoMskWidth
					, int TcoCndWidth
				) {
			this.TcoSrfWidth = TcoSrfWidth;
			this.TcoTypWidth = TcoTypWidth;
			this.TcoEvtWidth = TcoEvtWidth;
			this.TcoRtjWidth = TcoRtjWidth;
			this.TcoVitWidth = TcoVitWidth;
			this.TcoXsrWidth = TcoXsrWidth;
			this.TcoRtdWidth = TcoRtdWidth;
			this.TcoMskWidth = TcoMskWidth;
			this.TcoCndWidth = TcoCndWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOSRFWIDTH, TCOTYPWIDTH, TCOEVTWIDTH, TCORTJWIDTH, TCOVITWIDTH, TCOXSRWIDTH, TCORTDWIDTH, TCOMSKWIDTH, TCOCNDWIDTH));
		};

		public int TcoSrfWidth;
		public int TcoTypWidth;
		public int TcoEvtWidth;
		public int TcoRtjWidth;
		public int TcoVitWidth;
		public int TcoXsrWidth;
		public int TcoRtdWidth;
		public int TcoMskWidth;
		public int TcoCndWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWznmSteATrig");

			String itemtag = "StgitemIacWznmSteATrig";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoSrfWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", mask, TCOSRFWIDTH);
				TcoTypWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTypWidth", mask, TCOTYPWIDTH);
				TcoEvtWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoEvtWidth", mask, TCOEVTWIDTH);
				TcoRtjWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoRtjWidth", mask, TCORTJWIDTH);
				TcoVitWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoVitWidth", mask, TCOVITWIDTH);
				TcoXsrWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoXsrWidth", mask, TCOXSRWIDTH);
				TcoRtdWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoRtdWidth", mask, TCORTDWIDTH);
				TcoMskWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoMskWidth", mask, TCOMSKWIDTH);
				TcoCndWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoCndWidth", mask, TCOCNDWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWznmSteATrig";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWznmSteATrig";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTypWidth", TcoTypWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoEvtWidth", TcoEvtWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoRtjWidth", TcoRtjWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoVitWidth", TcoVitWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoXsrWidth", TcoXsrWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoRtdWidth", TcoRtdWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoMskWidth", TcoMskWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoCndWidth", TcoCndWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoSrfWidth == comp.TcoSrfWidth) items.add(TCOSRFWIDTH);
			if (TcoTypWidth == comp.TcoTypWidth) items.add(TCOTYPWIDTH);
			if (TcoEvtWidth == comp.TcoEvtWidth) items.add(TCOEVTWIDTH);
			if (TcoRtjWidth == comp.TcoRtjWidth) items.add(TCORTJWIDTH);
			if (TcoVitWidth == comp.TcoVitWidth) items.add(TCOVITWIDTH);
			if (TcoXsrWidth == comp.TcoXsrWidth) items.add(TCOXSRWIDTH);
			if (TcoRtdWidth == comp.TcoRtdWidth) items.add(TCORTDWIDTH);
			if (TcoMskWidth == comp.TcoMskWidth) items.add(TCOMSKWIDTH);
			if (TcoCndWidth == comp.TcoCndWidth) items.add(TCOCNDWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOSRFWIDTH, TCOTYPWIDTH, TCOEVTWIDTH, TCORTJWIDTH, TCOVITWIDTH, TCOXSRWIDTH, TCORTDWIDTH, TCOMSKWIDTH, TCOCNDWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmSteATrig)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTRECORD1 = 2;
		public static final int TXTRECORD2 = 3;
		public static final int TRS = 4;
		public static final int TXTSHOWING1 = 5;
		public static final int TXTSHOWING2 = 6;
		public static final int TCOSRF = 7;
		public static final int TCOTYP = 8;
		public static final int TCOEVT = 9;
		public static final int TCORTJ = 10;
		public static final int TCOVIT = 11;
		public static final int TCOXSR = 12;
		public static final int TCORTD = 13;
		public static final int TCOMSK = 14;
		public static final int TCOCND = 15;

		public Tag(
					String Cpt
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoSrf
					, String TcoTyp
					, String TcoEvt
					, String TcoRtj
					, String TcoVit
					, String TcoXsr
					, String TcoRtd
					, String TcoMsk
					, String TcoCnd
				) {
			this.Cpt = Cpt;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoSrf = TcoSrf;
			this.TcoTyp = TcoTyp;
			this.TcoEvt = TcoEvt;
			this.TcoRtj = TcoRtj;
			this.TcoVit = TcoVit;
			this.TcoXsr = TcoXsr;
			this.TcoRtd = TcoRtd;
			this.TcoMsk = TcoMsk;
			this.TcoCnd = TcoCnd;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSRF, TCOTYP, TCOEVT, TCORTJ, TCOVIT, TCOXSR, TCORTD, TCOMSK, TCOCND));
		};

		public String Cpt;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoSrf;
		public String TcoTyp;
		public String TcoEvt;
		public String TcoRtj;
		public String TcoVit;
		public String TcoXsr;
		public String TcoRtd;
		public String TcoMsk;
		public String TcoCnd;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmSteATrig");

			String itemtag = "TagitemWznmSteATrig";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSrf", mask, TCOSRF);
				TcoTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTyp", mask, TCOTYP);
				TcoEvt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoEvt", mask, TCOEVT);
				TcoRtj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoRtj", mask, TCORTJ);
				TcoVit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoVit", mask, TCOVIT);
				TcoXsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoXsr", mask, TCOXSR);
				TcoRtd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoRtd", mask, TCORTD);
				TcoMsk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoMsk", mask, TCOMSK);
				TcoCnd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoCnd", mask, TCOCND);

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
			if (TcoSrf.equals(comp.TcoSrf)) items.add(TCOSRF);
			if (TcoTyp.equals(comp.TcoTyp)) items.add(TCOTYP);
			if (TcoEvt.equals(comp.TcoEvt)) items.add(TCOEVT);
			if (TcoRtj.equals(comp.TcoRtj)) items.add(TCORTJ);
			if (TcoVit.equals(comp.TcoVit)) items.add(TCOVIT);
			if (TcoXsr.equals(comp.TcoXsr)) items.add(TCOXSR);
			if (TcoRtd.equals(comp.TcoRtd)) items.add(TCORTD);
			if (TcoMsk.equals(comp.TcoMsk)) items.add(TCOMSK);
			if (TcoCnd.equals(comp.TcoCnd)) items.add(TCOCND);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSRF, TCOTYP, TCOEVT, TCORTJ, TCOVIT, TCOXSR, TCORTD, TCOMSK, TCOCND));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmSteATrigData)
		*/
	public class DpchAppData extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int STGIAC = 2;
		public static final int STGIACQRY = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, StgIac stgiac
					, QryWznmSteATrig.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPWZNMSTEATRIGDATA, scrJref);

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
		public QryWznmSteATrig.StgIac stgiacqry;

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
			Element el = doc.createElement("DpchAppWznmSteATrigData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmSteATrigDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMSTEATRIGDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmSteATrigDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmSteATrigData)
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
			super(VecWznmVDpch.DPCHENGWZNMSTEATRIGDATA);

			continf = new ContInf(0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false);
			stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			rst = new ListWznmQSteATrig();
			statappqry = (new QryWznmSteATrig()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWznmSteATrig()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWznmSteATrig()).new StgIac(0, 0, 0);
		};

		public ContInf continf;
		public Feed feedFCsiQst;
		public StatApp statapp;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWznmQSteATrig rst;
		public QryWznmSteATrig.StatApp statappqry;
		public QryWznmSteATrig.StatShr statshrqry;
		public QryWznmSteATrig.StgIac stgiacqry;

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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmSteATrigData");

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
				stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
				statappqry = (new QryWznmSteATrig()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWznmSteATrig()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWznmSteATrig()).new StgIac(0, 0, 0);
			};
		};

	};

};
