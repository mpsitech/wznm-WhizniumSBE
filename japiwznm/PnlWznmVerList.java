/**
  * \file PnlWznmVerList.java
  * Java API code for job PnlWznmVerList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmVerList {
	/**
		* VecVDo (full: VecVWznmVerListDo)
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
	  * ContIac (full: ContIacWznmVerList)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmVerList");

			String itemtag = "ContitemIacWznmVerList";

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
			if (difftag.isEmpty()) difftag = "ContIacWznmVerList";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmVerList";

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
	  * ContInf (full: ContInfWznmVerList)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmVerList");

			String itemtag = "ContitemInfWznmVerList";

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
	  * StatShr (full: StatShrWznmVerList)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmVerList");

			String itemtag = "StatitemShrWznmVerList";

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
	  * StgIac (full: StgIacWznmVerList)
	  */
	public class StgIac extends Block {

		public static final int TCOGRPWIDTH = 1;
		public static final int TCOOWNWIDTH = 2;
		public static final int TCOPRJWIDTH = 3;
		public static final int TCOMAJWIDTH = 4;
		public static final int TCOMINWIDTH = 5;
		public static final int TCOSUBWIDTH = 6;
		public static final int TCOBVRWIDTH = 7;
		public static final int TCOLOCWIDTH = 8;
		public static final int TCOSTEWIDTH = 9;
		public static final int TCODTYWIDTH = 10;

		public StgIac(
					int TcoGrpWidth
					, int TcoOwnWidth
					, int TcoPrjWidth
					, int TcoMajWidth
					, int TcoMinWidth
					, int TcoSubWidth
					, int TcoBvrWidth
					, int TcoLocWidth
					, int TcoSteWidth
					, int TcoDtyWidth
				) {
			this.TcoGrpWidth = TcoGrpWidth;
			this.TcoOwnWidth = TcoOwnWidth;
			this.TcoPrjWidth = TcoPrjWidth;
			this.TcoMajWidth = TcoMajWidth;
			this.TcoMinWidth = TcoMinWidth;
			this.TcoSubWidth = TcoSubWidth;
			this.TcoBvrWidth = TcoBvrWidth;
			this.TcoLocWidth = TcoLocWidth;
			this.TcoSteWidth = TcoSteWidth;
			this.TcoDtyWidth = TcoDtyWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOGRPWIDTH, TCOOWNWIDTH, TCOPRJWIDTH, TCOMAJWIDTH, TCOMINWIDTH, TCOSUBWIDTH, TCOBVRWIDTH, TCOLOCWIDTH, TCOSTEWIDTH, TCODTYWIDTH));
		};

		public int TcoGrpWidth;
		public int TcoOwnWidth;
		public int TcoPrjWidth;
		public int TcoMajWidth;
		public int TcoMinWidth;
		public int TcoSubWidth;
		public int TcoBvrWidth;
		public int TcoLocWidth;
		public int TcoSteWidth;
		public int TcoDtyWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWznmVerList");

			String itemtag = "StgitemIacWznmVerList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoGrpWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoGrpWidth", mask, TCOGRPWIDTH);
				TcoOwnWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoOwnWidth", mask, TCOOWNWIDTH);
				TcoPrjWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoPrjWidth", mask, TCOPRJWIDTH);
				TcoMajWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoMajWidth", mask, TCOMAJWIDTH);
				TcoMinWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoMinWidth", mask, TCOMINWIDTH);
				TcoSubWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSubWidth", mask, TCOSUBWIDTH);
				TcoBvrWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoBvrWidth", mask, TCOBVRWIDTH);
				TcoLocWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoLocWidth", mask, TCOLOCWIDTH);
				TcoSteWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSteWidth", mask, TCOSTEWIDTH);
				TcoDtyWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoDtyWidth", mask, TCODTYWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWznmVerList";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWznmVerList";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoGrpWidth", TcoGrpWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoOwnWidth", TcoOwnWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoPrjWidth", TcoPrjWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoMajWidth", TcoMajWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoMinWidth", TcoMinWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSubWidth", TcoSubWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoBvrWidth", TcoBvrWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoLocWidth", TcoLocWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSteWidth", TcoSteWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoDtyWidth", TcoDtyWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoGrpWidth == comp.TcoGrpWidth) items.add(TCOGRPWIDTH);
			if (TcoOwnWidth == comp.TcoOwnWidth) items.add(TCOOWNWIDTH);
			if (TcoPrjWidth == comp.TcoPrjWidth) items.add(TCOPRJWIDTH);
			if (TcoMajWidth == comp.TcoMajWidth) items.add(TCOMAJWIDTH);
			if (TcoMinWidth == comp.TcoMinWidth) items.add(TCOMINWIDTH);
			if (TcoSubWidth == comp.TcoSubWidth) items.add(TCOSUBWIDTH);
			if (TcoBvrWidth == comp.TcoBvrWidth) items.add(TCOBVRWIDTH);
			if (TcoLocWidth == comp.TcoLocWidth) items.add(TCOLOCWIDTH);
			if (TcoSteWidth == comp.TcoSteWidth) items.add(TCOSTEWIDTH);
			if (TcoDtyWidth == comp.TcoDtyWidth) items.add(TCODTYWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOGRPWIDTH, TCOOWNWIDTH, TCOPRJWIDTH, TCOMAJWIDTH, TCOMINWIDTH, TCOSUBWIDTH, TCOBVRWIDTH, TCOLOCWIDTH, TCOSTEWIDTH, TCODTYWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmVerList)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTFOR = 2;
		public static final int TXTRECORD1 = 3;
		public static final int TXTRECORD2 = 4;
		public static final int TRS = 5;
		public static final int TXTSHOWING1 = 6;
		public static final int TXTSHOWING2 = 7;
		public static final int TCOGRP = 8;
		public static final int TCOOWN = 9;
		public static final int TCOPRJ = 10;
		public static final int TCOMAJ = 11;
		public static final int TCOMIN = 12;
		public static final int TCOSUB = 13;
		public static final int TCOBVR = 14;
		public static final int TCOLOC = 15;
		public static final int TCOSTE = 16;
		public static final int TCODTY = 17;

		public Tag(
					String Cpt
					, String TxtFor
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoGrp
					, String TcoOwn
					, String TcoPrj
					, String TcoMaj
					, String TcoMin
					, String TcoSub
					, String TcoBvr
					, String TcoLoc
					, String TcoSte
					, String TcoDty
				) {
			this.Cpt = Cpt;
			this.TxtFor = TxtFor;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoGrp = TcoGrp;
			this.TcoOwn = TcoOwn;
			this.TcoPrj = TcoPrj;
			this.TcoMaj = TcoMaj;
			this.TcoMin = TcoMin;
			this.TcoSub = TcoSub;
			this.TcoBvr = TcoBvr;
			this.TcoLoc = TcoLoc;
			this.TcoSte = TcoSte;
			this.TcoDty = TcoDty;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTFOR, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOGRP, TCOOWN, TCOPRJ, TCOMAJ, TCOMIN, TCOSUB, TCOBVR, TCOLOC, TCOSTE, TCODTY));
		};

		public String Cpt;
		public String TxtFor;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoGrp;
		public String TcoOwn;
		public String TcoPrj;
		public String TcoMaj;
		public String TcoMin;
		public String TcoSub;
		public String TcoBvr;
		public String TcoLoc;
		public String TcoSte;
		public String TcoDty;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmVerList");

			String itemtag = "TagitemWznmVerList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtFor = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtFor", mask, TXTFOR);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoGrp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoGrp", mask, TCOGRP);
				TcoOwn = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoOwn", mask, TCOOWN);
				TcoPrj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoPrj", mask, TCOPRJ);
				TcoMaj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoMaj", mask, TCOMAJ);
				TcoMin = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoMin", mask, TCOMIN);
				TcoSub = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSub", mask, TCOSUB);
				TcoBvr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoBvr", mask, TCOBVR);
				TcoLoc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoLoc", mask, TCOLOC);
				TcoSte = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSte", mask, TCOSTE);
				TcoDty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoDty", mask, TCODTY);

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
			if (TcoGrp.equals(comp.TcoGrp)) items.add(TCOGRP);
			if (TcoOwn.equals(comp.TcoOwn)) items.add(TCOOWN);
			if (TcoPrj.equals(comp.TcoPrj)) items.add(TCOPRJ);
			if (TcoMaj.equals(comp.TcoMaj)) items.add(TCOMAJ);
			if (TcoMin.equals(comp.TcoMin)) items.add(TCOMIN);
			if (TcoSub.equals(comp.TcoSub)) items.add(TCOSUB);
			if (TcoBvr.equals(comp.TcoBvr)) items.add(TCOBVR);
			if (TcoLoc.equals(comp.TcoLoc)) items.add(TCOLOC);
			if (TcoSte.equals(comp.TcoSte)) items.add(TCOSTE);
			if (TcoDty.equals(comp.TcoDty)) items.add(TCODTY);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTFOR, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOGRP, TCOOWN, TCOPRJ, TCOMAJ, TCOMIN, TCOSUB, TCOBVR, TCOLOC, TCOSTE, TCODTY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmVerListData)
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
					, QryWznmVerList.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPWZNMVERLISTDATA, scrJref);

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
		public QryWznmVerList.StgIac stgiacqry;

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
			Element el = doc.createElement("DpchAppWznmVerListData");

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
		* DpchAppDo (full: DpchAppWznmVerListDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMVERLISTDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmVerListDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmVerListData)
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
			super(VecWznmVDpch.DPCHENGWZNMVERLISTDATA);

			contiac = new ContIac(0);
			continf = new ContInf("", "", false, 0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			feedFTos = new Feed("FeedFTos");
			statshr = new StatShr(0, false);
			stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			rst = new ListWznmQVerList();
			statappqry = (new QryWznmVerList()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWznmVerList()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWznmVerList()).new StgIac(0, 0, 0);
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFCsiQst;
		public Feed feedFTos;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWznmQVerList rst;
		public QryWznmVerList.StatApp statappqry;
		public QryWznmVerList.StatShr statshrqry;
		public QryWznmVerList.StgIac stgiacqry;

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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmVerListData");

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
				statappqry = (new QryWznmVerList()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWznmVerList()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWznmVerList()).new StgIac(0, 0, 0);
			};
		};

	};

};
