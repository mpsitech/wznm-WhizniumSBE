/**
  * \file PnlWznmConList.java
  * Java API code for job PnlWznmConList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmConList {
	/**
		* VecVDo (full: VecVWznmConListDo)
		*/
	public static class VecVDo {

		public static final int BUTMINIMIZECLICK = 1;
		public static final int BUTREGULARIZECLICK = 2;
		public static final int BUTNEWCLICK = 3;
		public static final int BUTDELETECLICK = 4;
		public static final int BUTFILTERCLICK = 5;
		public static final int BUTREFRESHCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butnewclick")) return BUTNEWCLICK;
			if (s.equals("butdeleteclick")) return BUTDELETECLICK;
			if (s.equals("butfilterclick")) return BUTFILTERCLICK;
			if (s.equals("butrefreshclick")) return BUTREFRESHCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
			if (ix == BUTNEWCLICK) return("ButNewClick");
			if (ix == BUTDELETECLICK) return("ButDeleteClick");
			if (ix == BUTFILTERCLICK) return("ButFilterClick");
			if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmConList)
	  */
	public class ContIac extends Block {

		public static final int NUMFTOS = 1;

		public ContIac(
					int numFTos
				) {
			this.numFTos = numFTos;

			mask = new HashSet<Integer>(Arrays.asList(NUMFTOS));
		};

		public int numFTos;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmConList");

			String itemtag = "ContitemIacWznmConList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFTos = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFTos", mask, NUMFTOS);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmConList";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmConList";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFTos", numFTos);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFTos == comp.numFTos) items.add(NUMFTOS);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFTOS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmConList)
	  */
	public class ContInf extends Block {

		public static final int TXTFOR = 1;
		public static final int TXTPRE = 2;
		public static final int BUTFILTERON = 3;
		public static final int NUMFCSIQST = 4;

		public ContInf(
					String TxtFor
					, String TxtPre
					, boolean ButFilterOn
					, int numFCsiQst
				) {
			this.TxtFor = TxtFor;
			this.TxtPre = TxtPre;
			this.ButFilterOn = ButFilterOn;
			this.numFCsiQst = numFCsiQst;

			mask = new HashSet<Integer>(Arrays.asList(TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST));
		};

		public String TxtFor;
		public String TxtPre;
		public boolean ButFilterOn;
		public int numFCsiQst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmConList");

			String itemtag = "ContitemInfWznmConList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtFor = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtFor", mask, TXTFOR);
				TxtPre = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPre", mask, TXTPRE);
				ButFilterOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButFilterOn", mask, BUTFILTERON);
				numFCsiQst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFCsiQst", mask, NUMFCSIQST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtFor.equals(comp.TxtFor)) items.add(TXTFOR);
			if (TxtPre.equals(comp.TxtPre)) items.add(TXTPRE);
			if (ButFilterOn == comp.ButFilterOn) items.add(BUTFILTERON);
			if (numFCsiQst == comp.numFCsiQst) items.add(NUMFCSIQST);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTFOR, TXTPRE, BUTFILTERON, NUMFCSIQST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmConList)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int BUTDELETEACTIVE = 2;

		public StatShr(
					int ixWznmVExpstate
					, boolean ButDeleteActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.ButDeleteActive = ButDeleteActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, BUTDELETEACTIVE));
		};

		public int ixWznmVExpstate;
		public boolean ButDeleteActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmConList");

			String itemtag = "StatitemShrWznmConList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				ButDeleteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDeleteActive", mask, BUTDELETEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (ButDeleteActive == comp.ButDeleteActive) items.add(BUTDELETEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, BUTDELETEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacWznmConList)
	  */
	public class StgIac extends Block {

		public static final int TCOSRFWIDTH = 1;
		public static final int TCOTITWIDTH = 2;
		public static final int TCOTYPWIDTH = 3;
		public static final int TCOHKTWIDTH = 4;
		public static final int TCOHKUWIDTH = 5;
		public static final int TCOSCTWIDTH = 6;
		public static final int TCORETWIDTH = 7;
		public static final int TCOREUWIDTH = 8;
		public static final int TCOSUPWIDTH = 9;
		public static final int TCOSTYWIDTH = 10;

		public StgIac(
					int TcoSrfWidth
					, int TcoTitWidth
					, int TcoTypWidth
					, int TcoHktWidth
					, int TcoHkuWidth
					, int TcoSctWidth
					, int TcoRetWidth
					, int TcoReuWidth
					, int TcoSupWidth
					, int TcoStyWidth
				) {
			this.TcoSrfWidth = TcoSrfWidth;
			this.TcoTitWidth = TcoTitWidth;
			this.TcoTypWidth = TcoTypWidth;
			this.TcoHktWidth = TcoHktWidth;
			this.TcoHkuWidth = TcoHkuWidth;
			this.TcoSctWidth = TcoSctWidth;
			this.TcoRetWidth = TcoRetWidth;
			this.TcoReuWidth = TcoReuWidth;
			this.TcoSupWidth = TcoSupWidth;
			this.TcoStyWidth = TcoStyWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOSRFWIDTH, TCOTITWIDTH, TCOTYPWIDTH, TCOHKTWIDTH, TCOHKUWIDTH, TCOSCTWIDTH, TCORETWIDTH, TCOREUWIDTH, TCOSUPWIDTH, TCOSTYWIDTH));
		};

		public int TcoSrfWidth;
		public int TcoTitWidth;
		public int TcoTypWidth;
		public int TcoHktWidth;
		public int TcoHkuWidth;
		public int TcoSctWidth;
		public int TcoRetWidth;
		public int TcoReuWidth;
		public int TcoSupWidth;
		public int TcoStyWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWznmConList");

			String itemtag = "StgitemIacWznmConList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoSrfWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", mask, TCOSRFWIDTH);
				TcoTitWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTitWidth", mask, TCOTITWIDTH);
				TcoTypWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTypWidth", mask, TCOTYPWIDTH);
				TcoHktWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoHktWidth", mask, TCOHKTWIDTH);
				TcoHkuWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoHkuWidth", mask, TCOHKUWIDTH);
				TcoSctWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSctWidth", mask, TCOSCTWIDTH);
				TcoRetWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoRetWidth", mask, TCORETWIDTH);
				TcoReuWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoReuWidth", mask, TCOREUWIDTH);
				TcoSupWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSupWidth", mask, TCOSUPWIDTH);
				TcoStyWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoStyWidth", mask, TCOSTYWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWznmConList";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWznmConList";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTitWidth", TcoTitWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTypWidth", TcoTypWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoHktWidth", TcoHktWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoHkuWidth", TcoHkuWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSctWidth", TcoSctWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoRetWidth", TcoRetWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoReuWidth", TcoReuWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSupWidth", TcoSupWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoStyWidth", TcoStyWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoSrfWidth == comp.TcoSrfWidth) items.add(TCOSRFWIDTH);
			if (TcoTitWidth == comp.TcoTitWidth) items.add(TCOTITWIDTH);
			if (TcoTypWidth == comp.TcoTypWidth) items.add(TCOTYPWIDTH);
			if (TcoHktWidth == comp.TcoHktWidth) items.add(TCOHKTWIDTH);
			if (TcoHkuWidth == comp.TcoHkuWidth) items.add(TCOHKUWIDTH);
			if (TcoSctWidth == comp.TcoSctWidth) items.add(TCOSCTWIDTH);
			if (TcoRetWidth == comp.TcoRetWidth) items.add(TCORETWIDTH);
			if (TcoReuWidth == comp.TcoReuWidth) items.add(TCOREUWIDTH);
			if (TcoSupWidth == comp.TcoSupWidth) items.add(TCOSUPWIDTH);
			if (TcoStyWidth == comp.TcoStyWidth) items.add(TCOSTYWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOSRFWIDTH, TCOTITWIDTH, TCOTYPWIDTH, TCOHKTWIDTH, TCOHKUWIDTH, TCOSCTWIDTH, TCORETWIDTH, TCOREUWIDTH, TCOSUPWIDTH, TCOSTYWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmConList)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTFOR = 2;
		public static final int TXTRECORD1 = 3;
		public static final int TXTRECORD2 = 4;
		public static final int TRS = 5;
		public static final int TXTSHOWING1 = 6;
		public static final int TXTSHOWING2 = 7;
		public static final int TCOSRF = 8;
		public static final int TCOTIT = 9;
		public static final int TCOTYP = 10;
		public static final int TCOHKT = 11;
		public static final int TCOHKU = 12;
		public static final int TCOSCT = 13;
		public static final int TCORET = 14;
		public static final int TCOREU = 15;
		public static final int TCOSUP = 16;
		public static final int TCOSTY = 17;

		public Tag(
					String Cpt
					, String TxtFor
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoSrf
					, String TcoTit
					, String TcoTyp
					, String TcoHkt
					, String TcoHku
					, String TcoSct
					, String TcoRet
					, String TcoReu
					, String TcoSup
					, String TcoSty
				) {
			this.Cpt = Cpt;
			this.TxtFor = TxtFor;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoSrf = TcoSrf;
			this.TcoTit = TcoTit;
			this.TcoTyp = TcoTyp;
			this.TcoHkt = TcoHkt;
			this.TcoHku = TcoHku;
			this.TcoSct = TcoSct;
			this.TcoRet = TcoRet;
			this.TcoReu = TcoReu;
			this.TcoSup = TcoSup;
			this.TcoSty = TcoSty;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTFOR, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSRF, TCOTIT, TCOTYP, TCOHKT, TCOHKU, TCOSCT, TCORET, TCOREU, TCOSUP, TCOSTY));
		};

		public String Cpt;
		public String TxtFor;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoSrf;
		public String TcoTit;
		public String TcoTyp;
		public String TcoHkt;
		public String TcoHku;
		public String TcoSct;
		public String TcoRet;
		public String TcoReu;
		public String TcoSup;
		public String TcoSty;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmConList");

			String itemtag = "TagitemWznmConList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtFor = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtFor", mask, TXTFOR);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSrf", mask, TCOSRF);
				TcoTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTit", mask, TCOTIT);
				TcoTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTyp", mask, TCOTYP);
				TcoHkt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoHkt", mask, TCOHKT);
				TcoHku = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoHku", mask, TCOHKU);
				TcoSct = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSct", mask, TCOSCT);
				TcoRet = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoRet", mask, TCORET);
				TcoReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoReu", mask, TCOREU);
				TcoSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSup", mask, TCOSUP);
				TcoSty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSty", mask, TCOSTY);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (TxtFor.equals(comp.TxtFor)) items.add(TXTFOR);
			if (TxtRecord1.equals(comp.TxtRecord1)) items.add(TXTRECORD1);
			if (TxtRecord2.equals(comp.TxtRecord2)) items.add(TXTRECORD2);
			if (Trs.equals(comp.Trs)) items.add(TRS);
			if (TxtShowing1.equals(comp.TxtShowing1)) items.add(TXTSHOWING1);
			if (TxtShowing2.equals(comp.TxtShowing2)) items.add(TXTSHOWING2);
			if (TcoSrf.equals(comp.TcoSrf)) items.add(TCOSRF);
			if (TcoTit.equals(comp.TcoTit)) items.add(TCOTIT);
			if (TcoTyp.equals(comp.TcoTyp)) items.add(TCOTYP);
			if (TcoHkt.equals(comp.TcoHkt)) items.add(TCOHKT);
			if (TcoHku.equals(comp.TcoHku)) items.add(TCOHKU);
			if (TcoSct.equals(comp.TcoSct)) items.add(TCOSCT);
			if (TcoRet.equals(comp.TcoRet)) items.add(TCORET);
			if (TcoReu.equals(comp.TcoReu)) items.add(TCOREU);
			if (TcoSup.equals(comp.TcoSup)) items.add(TCOSUP);
			if (TcoSty.equals(comp.TcoSty)) items.add(TCOSTY);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTFOR, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSRF, TCOTIT, TCOTYP, TCOHKT, TCOHKU, TCOSCT, TCORET, TCOREU, TCOSUP, TCOSTY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmConListData)
		*/
	public class DpchAppData extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int STGIAC = 3;
		public static final int STGIACQRY = 4;
		public static final int ALL = 5;

		public DpchAppData(
					String scrJref
					, ContIac contiac
					, StgIac stgiac
					, QryWznmConList.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPWZNMCONLISTDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIAC, STGIAC, STGIACQRY));
					break;
				};

			if (has(CONTIAC)) this.contiac = contiac;
			if (has(STGIAC)) this.stgiac = stgiac;
			if (has(STGIACQRY)) this.stgiacqry = stgiacqry;
		};

		public ContIac contiac;
		public StgIac stgiac;
		public QryWznmConList.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWznmConListData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmConListDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMCONLISTDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmConListDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmConListData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFCSIQST = 4;
		public static final int FEEDFTOS = 5;
		public static final int STATSHR = 6;
		public static final int STGIAC = 7;
		public static final int TAG = 8;
		public static final int RST = 9;
		public static final int STATAPPQRY = 10;
		public static final int STATSHRQRY = 11;
		public static final int STGIACQRY = 12;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMCONLISTDATA);

			contiac = new ContIac(0);
			continf = new ContInf("", "", false, 0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			feedFTos = new Feed("FeedFTos");
			statshr = new StatShr(0, false);
			stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			rst = new ListWznmQConList();
			statappqry = (new QryWznmConList()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWznmConList()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWznmConList()).new StgIac(0, 0, 0);
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFCsiQst;
		public Feed feedFTos;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWznmQConList rst;
		public QryWznmConList.StatApp statappqry;
		public QryWznmConList.StatShr statshrqry;
		public QryWznmConList.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFCSIQST)) ss.add("feedFCsiQst");
			if (has(FEEDFTOS)) ss.add("feedFTos");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmConListData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFCsiQst.readXML(doc, basexpath, true)) add(FEEDFCSIQST);
				if (feedFTos.readXML(doc, basexpath, true)) add(FEEDFTOS);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (stgiac.readXML(doc, basexpath, true)) add(STGIAC);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (rst.readXML(doc, basexpath, true)) add(RST);
				if (statappqry.readXML(doc, basexpath, true)) add(STATAPPQRY);
				if (statshrqry.readXML(doc, basexpath, true)) add(STATSHRQRY);
				if (stgiacqry.readXML(doc, basexpath, true)) add(STGIACQRY);
			} else {
				scrJref = "";
				contiac = new ContIac(0);
				continf = new ContInf("", "", false, 0);
				feedFCsiQst = new Feed("FeedFCsiQst");
				feedFTos = new Feed("FeedFTos");
				statshr = new StatShr(0, false);
				stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
				statappqry = (new QryWznmConList()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWznmConList()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWznmConList()).new StgIac(0, 0, 0);
			};
		};

	};

};

