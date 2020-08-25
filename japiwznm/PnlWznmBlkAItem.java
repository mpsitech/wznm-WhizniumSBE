/**
  * \file PnlWznmBlkAItem.java
  * Java API code for job PnlWznmBlkAItem
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmBlkAItem {
	/**
		* VecVDo (full: VecVWznmBlkAItemDo)
		*/
	public static class VecVDo {

		public static final int BUTUPCLICK = 1;
		public static final int BUTDOWNCLICK = 2;
		public static final int BUTNEWCLICK = 3;
		public static final int BUTDUPLICATECLICK = 4;
		public static final int BUTDELETECLICK = 5;
		public static final int BUTREFRESHCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butupclick")) return BUTUPCLICK;
			if (s.equals("butdownclick")) return BUTDOWNCLICK;
			if (s.equals("butnewclick")) return BUTNEWCLICK;
			if (s.equals("butduplicateclick")) return BUTDUPLICATECLICK;
			if (s.equals("butdeleteclick")) return BUTDELETECLICK;
			if (s.equals("butrefreshclick")) return BUTREFRESHCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTUPCLICK) return("ButUpClick");
			if (ix == BUTDOWNCLICK) return("ButDownClick");
			if (ix == BUTNEWCLICK) return("ButNewClick");
			if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
			if (ix == BUTDELETECLICK) return("ButDeleteClick");
			if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWznmBlkAItem)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmBlkAItem");

			String itemtag = "ContitemInfWznmBlkAItem";

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
	  * StatApp (full: StatAppWznmBlkAItem)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmBlkAItem");

			String itemtag = "StatitemAppWznmBlkAItem";

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
	  * StatShr (full: StatShrWznmBlkAItem)
	  */
	public class StatShr extends Block {

		public static final int BUTUPAVAIL = 1;
		public static final int BUTUPACTIVE = 2;
		public static final int BUTDOWNAVAIL = 3;
		public static final int BUTDOWNACTIVE = 4;
		public static final int BUTNEWAVAIL = 5;
		public static final int BUTDUPLICATEAVAIL = 6;
		public static final int BUTDUPLICATEACTIVE = 7;
		public static final int BUTDELETEAVAIL = 8;
		public static final int BUTDELETEACTIVE = 9;

		public StatShr(
					boolean ButUpAvail
					, boolean ButUpActive
					, boolean ButDownAvail
					, boolean ButDownActive
					, boolean ButNewAvail
					, boolean ButDuplicateAvail
					, boolean ButDuplicateActive
					, boolean ButDeleteAvail
					, boolean ButDeleteActive
				) {
			this.ButUpAvail = ButUpAvail;
			this.ButUpActive = ButUpActive;
			this.ButDownAvail = ButDownAvail;
			this.ButDownActive = ButDownActive;
			this.ButNewAvail = ButNewAvail;
			this.ButDuplicateAvail = ButDuplicateAvail;
			this.ButDuplicateActive = ButDuplicateActive;
			this.ButDeleteAvail = ButDeleteAvail;
			this.ButDeleteActive = ButDeleteActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTUPAVAIL, BUTUPACTIVE, BUTDOWNAVAIL, BUTDOWNACTIVE, BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE));
		};

		public boolean ButUpAvail;
		public boolean ButUpActive;
		public boolean ButDownAvail;
		public boolean ButDownActive;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmBlkAItem");

			String itemtag = "StatitemShrWznmBlkAItem";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButUpAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUpAvail", mask, BUTUPAVAIL);
				ButUpActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUpActive", mask, BUTUPACTIVE);
				ButDownAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDownAvail", mask, BUTDOWNAVAIL);
				ButDownActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDownActive", mask, BUTDOWNACTIVE);
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

			if (ButUpAvail == comp.ButUpAvail) items.add(BUTUPAVAIL);
			if (ButUpActive == comp.ButUpActive) items.add(BUTUPACTIVE);
			if (ButDownAvail == comp.ButDownAvail) items.add(BUTDOWNAVAIL);
			if (ButDownActive == comp.ButDownActive) items.add(BUTDOWNACTIVE);
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

			diffitems = new HashSet<Integer>(Arrays.asList(BUTUPAVAIL, BUTUPACTIVE, BUTDOWNAVAIL, BUTDOWNACTIVE, BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacWznmBlkAItem)
	  */
	public class StgIac extends Block {

		public static final int TCOTYPWIDTH = 1;
		public static final int TCOSRFWIDTH = 2;
		public static final int TCOVTYWIDTH = 3;
		public static final int TCOCONWIDTH = 4;
		public static final int TCOVECWIDTH = 5;
		public static final int TCOFEDWIDTH = 6;
		public static final int TCOTBLWIDTH = 7;
		public static final int TCOBL2WIDTH = 8;
		public static final int TCODFVWIDTH = 9;
		public static final int TCOVITWIDTH = 10;
		public static final int TCOCMTWIDTH = 11;

		public StgIac(
					int TcoTypWidth
					, int TcoSrfWidth
					, int TcoVtyWidth
					, int TcoConWidth
					, int TcoVecWidth
					, int TcoFedWidth
					, int TcoTblWidth
					, int TcoBl2Width
					, int TcoDfvWidth
					, int TcoVitWidth
					, int TcoCmtWidth
				) {
			this.TcoTypWidth = TcoTypWidth;
			this.TcoSrfWidth = TcoSrfWidth;
			this.TcoVtyWidth = TcoVtyWidth;
			this.TcoConWidth = TcoConWidth;
			this.TcoVecWidth = TcoVecWidth;
			this.TcoFedWidth = TcoFedWidth;
			this.TcoTblWidth = TcoTblWidth;
			this.TcoBl2Width = TcoBl2Width;
			this.TcoDfvWidth = TcoDfvWidth;
			this.TcoVitWidth = TcoVitWidth;
			this.TcoCmtWidth = TcoCmtWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOTYPWIDTH, TCOSRFWIDTH, TCOVTYWIDTH, TCOCONWIDTH, TCOVECWIDTH, TCOFEDWIDTH, TCOTBLWIDTH, TCOBL2WIDTH, TCODFVWIDTH, TCOVITWIDTH, TCOCMTWIDTH));
		};

		public int TcoTypWidth;
		public int TcoSrfWidth;
		public int TcoVtyWidth;
		public int TcoConWidth;
		public int TcoVecWidth;
		public int TcoFedWidth;
		public int TcoTblWidth;
		public int TcoBl2Width;
		public int TcoDfvWidth;
		public int TcoVitWidth;
		public int TcoCmtWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWznmBlkAItem");

			String itemtag = "StgitemIacWznmBlkAItem";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoTypWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTypWidth", mask, TCOTYPWIDTH);
				TcoSrfWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", mask, TCOSRFWIDTH);
				TcoVtyWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoVtyWidth", mask, TCOVTYWIDTH);
				TcoConWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoConWidth", mask, TCOCONWIDTH);
				TcoVecWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoVecWidth", mask, TCOVECWIDTH);
				TcoFedWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoFedWidth", mask, TCOFEDWIDTH);
				TcoTblWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTblWidth", mask, TCOTBLWIDTH);
				TcoBl2Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoBl2Width", mask, TCOBL2WIDTH);
				TcoDfvWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoDfvWidth", mask, TCODFVWIDTH);
				TcoVitWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoVitWidth", mask, TCOVITWIDTH);
				TcoCmtWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoCmtWidth", mask, TCOCMTWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWznmBlkAItem";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWznmBlkAItem";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTypWidth", TcoTypWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoVtyWidth", TcoVtyWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoConWidth", TcoConWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoVecWidth", TcoVecWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoFedWidth", TcoFedWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTblWidth", TcoTblWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoBl2Width", TcoBl2Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoDfvWidth", TcoDfvWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoVitWidth", TcoVitWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoCmtWidth", TcoCmtWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoTypWidth == comp.TcoTypWidth) items.add(TCOTYPWIDTH);
			if (TcoSrfWidth == comp.TcoSrfWidth) items.add(TCOSRFWIDTH);
			if (TcoVtyWidth == comp.TcoVtyWidth) items.add(TCOVTYWIDTH);
			if (TcoConWidth == comp.TcoConWidth) items.add(TCOCONWIDTH);
			if (TcoVecWidth == comp.TcoVecWidth) items.add(TCOVECWIDTH);
			if (TcoFedWidth == comp.TcoFedWidth) items.add(TCOFEDWIDTH);
			if (TcoTblWidth == comp.TcoTblWidth) items.add(TCOTBLWIDTH);
			if (TcoBl2Width == comp.TcoBl2Width) items.add(TCOBL2WIDTH);
			if (TcoDfvWidth == comp.TcoDfvWidth) items.add(TCODFVWIDTH);
			if (TcoVitWidth == comp.TcoVitWidth) items.add(TCOVITWIDTH);
			if (TcoCmtWidth == comp.TcoCmtWidth) items.add(TCOCMTWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOTYPWIDTH, TCOSRFWIDTH, TCOVTYWIDTH, TCOCONWIDTH, TCOVECWIDTH, TCOFEDWIDTH, TCOTBLWIDTH, TCOBL2WIDTH, TCODFVWIDTH, TCOVITWIDTH, TCOCMTWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmBlkAItem)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTRECORD1 = 2;
		public static final int TXTRECORD2 = 3;
		public static final int TRS = 4;
		public static final int TXTSHOWING1 = 5;
		public static final int TXTSHOWING2 = 6;
		public static final int TCOTYP = 7;
		public static final int TCOSRF = 8;
		public static final int TCOVTY = 9;
		public static final int TCOCON = 10;
		public static final int TCOVEC = 11;
		public static final int TCOFED = 12;
		public static final int TCOTBL = 13;
		public static final int TCOBL2 = 14;
		public static final int TCODFV = 15;
		public static final int TCOVIT = 16;
		public static final int TCOCMT = 17;

		public Tag(
					String Cpt
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoTyp
					, String TcoSrf
					, String TcoVty
					, String TcoCon
					, String TcoVec
					, String TcoFed
					, String TcoTbl
					, String TcoBl2
					, String TcoDfv
					, String TcoVit
					, String TcoCmt
				) {
			this.Cpt = Cpt;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoTyp = TcoTyp;
			this.TcoSrf = TcoSrf;
			this.TcoVty = TcoVty;
			this.TcoCon = TcoCon;
			this.TcoVec = TcoVec;
			this.TcoFed = TcoFed;
			this.TcoTbl = TcoTbl;
			this.TcoBl2 = TcoBl2;
			this.TcoDfv = TcoDfv;
			this.TcoVit = TcoVit;
			this.TcoCmt = TcoCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOTYP, TCOSRF, TCOVTY, TCOCON, TCOVEC, TCOFED, TCOTBL, TCOBL2, TCODFV, TCOVIT, TCOCMT));
		};

		public String Cpt;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoTyp;
		public String TcoSrf;
		public String TcoVty;
		public String TcoCon;
		public String TcoVec;
		public String TcoFed;
		public String TcoTbl;
		public String TcoBl2;
		public String TcoDfv;
		public String TcoVit;
		public String TcoCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmBlkAItem");

			String itemtag = "TagitemWznmBlkAItem";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTyp", mask, TCOTYP);
				TcoSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSrf", mask, TCOSRF);
				TcoVty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoVty", mask, TCOVTY);
				TcoCon = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoCon", mask, TCOCON);
				TcoVec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoVec", mask, TCOVEC);
				TcoFed = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoFed", mask, TCOFED);
				TcoTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTbl", mask, TCOTBL);
				TcoBl2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoBl2", mask, TCOBL2);
				TcoDfv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoDfv", mask, TCODFV);
				TcoVit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoVit", mask, TCOVIT);
				TcoCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoCmt", mask, TCOCMT);

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
			if (TcoTyp.equals(comp.TcoTyp)) items.add(TCOTYP);
			if (TcoSrf.equals(comp.TcoSrf)) items.add(TCOSRF);
			if (TcoVty.equals(comp.TcoVty)) items.add(TCOVTY);
			if (TcoCon.equals(comp.TcoCon)) items.add(TCOCON);
			if (TcoVec.equals(comp.TcoVec)) items.add(TCOVEC);
			if (TcoFed.equals(comp.TcoFed)) items.add(TCOFED);
			if (TcoTbl.equals(comp.TcoTbl)) items.add(TCOTBL);
			if (TcoBl2.equals(comp.TcoBl2)) items.add(TCOBL2);
			if (TcoDfv.equals(comp.TcoDfv)) items.add(TCODFV);
			if (TcoVit.equals(comp.TcoVit)) items.add(TCOVIT);
			if (TcoCmt.equals(comp.TcoCmt)) items.add(TCOCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOTYP, TCOSRF, TCOVTY, TCOCON, TCOVEC, TCOFED, TCOTBL, TCOBL2, TCODFV, TCOVIT, TCOCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmBlkAItemData)
		*/
	public class DpchAppData extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int STGIAC = 2;
		public static final int STGIACQRY = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, StgIac stgiac
					, QryWznmBlkAItem.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPWZNMBLKAITEMDATA, scrJref);

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
		public QryWznmBlkAItem.StgIac stgiacqry;

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
			Element el = doc.createElement("DpchAppWznmBlkAItemData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmBlkAItemDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMBLKAITEMDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmBlkAItemDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmBlkAItemData)
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
			super(VecWznmVDpch.DPCHENGWZNMBLKAITEMDATA);

			continf = new ContInf(0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false);
			stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			rst = new ListWznmQBlkAItem();
			statappqry = (new QryWznmBlkAItem()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWznmBlkAItem()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWznmBlkAItem()).new StgIac(0, 0, 0);
		};

		public ContInf continf;
		public Feed feedFCsiQst;
		public StatApp statapp;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWznmQBlkAItem rst;
		public QryWznmBlkAItem.StatApp statappqry;
		public QryWznmBlkAItem.StatShr statshrqry;
		public QryWznmBlkAItem.StgIac stgiacqry;

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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmBlkAItemData");

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
				statshr = new StatShr(false, false, false, false, false, false, false, false, false);
				stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
				statappqry = (new QryWznmBlkAItem()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWznmBlkAItem()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWznmBlkAItem()).new StgIac(0, 0, 0);
			};
		};

	};

};

