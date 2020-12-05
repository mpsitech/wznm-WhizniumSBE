/**
  * \file PnlWznmSteAAction.java
  * Java API code for job PnlWznmSteAAction
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmSteAAction {
	/**
		* VecVDo (full: VecVWznmSteAActionDo)
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
	  * ContInf (full: ContInfWznmSteAAction)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmSteAAction");

			String itemtag = "ContitemInfWznmSteAAction";

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
	  * StatApp (full: StatAppWznmSteAAction)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmSteAAction");

			String itemtag = "StatitemAppWznmSteAAction";

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
	  * StatShr (full: StatShrWznmSteAAction)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmSteAAction");

			String itemtag = "StatitemShrWznmSteAAction";

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
	  * StgIac (full: StgIacWznmSteAAction)
	  */
	public class StgIac extends Block {

		public static final int TCOSCTWIDTH = 1;
		public static final int TCOTYPWIDTH = 2;
		public static final int TCOTRJWIDTH = 3;
		public static final int TCOVECWIDTH = 4;
		public static final int TCOVITWIDTH = 5;
		public static final int TCOSNXWIDTH = 6;
		public static final int TCOSEQWIDTH = 7;
		public static final int TCOTR1WIDTH = 8;
		public static final int TCOIP1WIDTH = 9;
		public static final int TCOTR2WIDTH = 10;
		public static final int TCOIP2WIDTH = 11;
		public static final int TCOTR3WIDTH = 12;
		public static final int TCOIP3WIDTH = 13;
		public static final int TCOTR4WIDTH = 14;
		public static final int TCOIP4WIDTH = 15;

		public StgIac(
					int TcoSctWidth
					, int TcoTypWidth
					, int TcoTrjWidth
					, int TcoVecWidth
					, int TcoVitWidth
					, int TcoSnxWidth
					, int TcoSeqWidth
					, int TcoTr1Width
					, int TcoIp1Width
					, int TcoTr2Width
					, int TcoIp2Width
					, int TcoTr3Width
					, int TcoIp3Width
					, int TcoTr4Width
					, int TcoIp4Width
				) {
			this.TcoSctWidth = TcoSctWidth;
			this.TcoTypWidth = TcoTypWidth;
			this.TcoTrjWidth = TcoTrjWidth;
			this.TcoVecWidth = TcoVecWidth;
			this.TcoVitWidth = TcoVitWidth;
			this.TcoSnxWidth = TcoSnxWidth;
			this.TcoSeqWidth = TcoSeqWidth;
			this.TcoTr1Width = TcoTr1Width;
			this.TcoIp1Width = TcoIp1Width;
			this.TcoTr2Width = TcoTr2Width;
			this.TcoIp2Width = TcoIp2Width;
			this.TcoTr3Width = TcoTr3Width;
			this.TcoIp3Width = TcoIp3Width;
			this.TcoTr4Width = TcoTr4Width;
			this.TcoIp4Width = TcoIp4Width;

			mask = new HashSet<Integer>(Arrays.asList(TCOSCTWIDTH, TCOTYPWIDTH, TCOTRJWIDTH, TCOVECWIDTH, TCOVITWIDTH, TCOSNXWIDTH, TCOSEQWIDTH, TCOTR1WIDTH, TCOIP1WIDTH, TCOTR2WIDTH, TCOIP2WIDTH, TCOTR3WIDTH, TCOIP3WIDTH, TCOTR4WIDTH, TCOIP4WIDTH));
		};

		public int TcoSctWidth;
		public int TcoTypWidth;
		public int TcoTrjWidth;
		public int TcoVecWidth;
		public int TcoVitWidth;
		public int TcoSnxWidth;
		public int TcoSeqWidth;
		public int TcoTr1Width;
		public int TcoIp1Width;
		public int TcoTr2Width;
		public int TcoIp2Width;
		public int TcoTr3Width;
		public int TcoIp3Width;
		public int TcoTr4Width;
		public int TcoIp4Width;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWznmSteAAction");

			String itemtag = "StgitemIacWznmSteAAction";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoSctWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSctWidth", mask, TCOSCTWIDTH);
				TcoTypWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTypWidth", mask, TCOTYPWIDTH);
				TcoTrjWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTrjWidth", mask, TCOTRJWIDTH);
				TcoVecWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoVecWidth", mask, TCOVECWIDTH);
				TcoVitWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoVitWidth", mask, TCOVITWIDTH);
				TcoSnxWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSnxWidth", mask, TCOSNXWIDTH);
				TcoSeqWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSeqWidth", mask, TCOSEQWIDTH);
				TcoTr1Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTr1Width", mask, TCOTR1WIDTH);
				TcoIp1Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoIp1Width", mask, TCOIP1WIDTH);
				TcoTr2Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTr2Width", mask, TCOTR2WIDTH);
				TcoIp2Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoIp2Width", mask, TCOIP2WIDTH);
				TcoTr3Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTr3Width", mask, TCOTR3WIDTH);
				TcoIp3Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoIp3Width", mask, TCOIP3WIDTH);
				TcoTr4Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTr4Width", mask, TCOTR4WIDTH);
				TcoIp4Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoIp4Width", mask, TCOIP4WIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWznmSteAAction";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWznmSteAAction";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSctWidth", TcoSctWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTypWidth", TcoTypWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTrjWidth", TcoTrjWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoVecWidth", TcoVecWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoVitWidth", TcoVitWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSnxWidth", TcoSnxWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSeqWidth", TcoSeqWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTr1Width", TcoTr1Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoIp1Width", TcoIp1Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTr2Width", TcoTr2Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoIp2Width", TcoIp2Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTr3Width", TcoTr3Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoIp3Width", TcoIp3Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTr4Width", TcoTr4Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoIp4Width", TcoIp4Width);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoSctWidth == comp.TcoSctWidth) items.add(TCOSCTWIDTH);
			if (TcoTypWidth == comp.TcoTypWidth) items.add(TCOTYPWIDTH);
			if (TcoTrjWidth == comp.TcoTrjWidth) items.add(TCOTRJWIDTH);
			if (TcoVecWidth == comp.TcoVecWidth) items.add(TCOVECWIDTH);
			if (TcoVitWidth == comp.TcoVitWidth) items.add(TCOVITWIDTH);
			if (TcoSnxWidth == comp.TcoSnxWidth) items.add(TCOSNXWIDTH);
			if (TcoSeqWidth == comp.TcoSeqWidth) items.add(TCOSEQWIDTH);
			if (TcoTr1Width == comp.TcoTr1Width) items.add(TCOTR1WIDTH);
			if (TcoIp1Width == comp.TcoIp1Width) items.add(TCOIP1WIDTH);
			if (TcoTr2Width == comp.TcoTr2Width) items.add(TCOTR2WIDTH);
			if (TcoIp2Width == comp.TcoIp2Width) items.add(TCOIP2WIDTH);
			if (TcoTr3Width == comp.TcoTr3Width) items.add(TCOTR3WIDTH);
			if (TcoIp3Width == comp.TcoIp3Width) items.add(TCOIP3WIDTH);
			if (TcoTr4Width == comp.TcoTr4Width) items.add(TCOTR4WIDTH);
			if (TcoIp4Width == comp.TcoIp4Width) items.add(TCOIP4WIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOSCTWIDTH, TCOTYPWIDTH, TCOTRJWIDTH, TCOVECWIDTH, TCOVITWIDTH, TCOSNXWIDTH, TCOSEQWIDTH, TCOTR1WIDTH, TCOIP1WIDTH, TCOTR2WIDTH, TCOIP2WIDTH, TCOTR3WIDTH, TCOIP3WIDTH, TCOTR4WIDTH, TCOIP4WIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmSteAAction)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTRECORD1 = 2;
		public static final int TXTRECORD2 = 3;
		public static final int TRS = 4;
		public static final int TXTSHOWING1 = 5;
		public static final int TXTSHOWING2 = 6;
		public static final int TCOSCT = 7;
		public static final int TCOTYP = 8;
		public static final int TCOTRJ = 9;
		public static final int TCOVEC = 10;
		public static final int TCOVIT = 11;
		public static final int TCOSNX = 12;
		public static final int TCOSEQ = 13;
		public static final int TCOTR1 = 14;
		public static final int TCOIP1 = 15;
		public static final int TCOTR2 = 16;
		public static final int TCOIP2 = 17;
		public static final int TCOTR3 = 18;
		public static final int TCOIP3 = 19;
		public static final int TCOTR4 = 20;
		public static final int TCOIP4 = 21;

		public Tag(
					String Cpt
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoSct
					, String TcoTyp
					, String TcoTrj
					, String TcoVec
					, String TcoVit
					, String TcoSnx
					, String TcoSeq
					, String TcoTr1
					, String TcoIp1
					, String TcoTr2
					, String TcoIp2
					, String TcoTr3
					, String TcoIp3
					, String TcoTr4
					, String TcoIp4
				) {
			this.Cpt = Cpt;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoSct = TcoSct;
			this.TcoTyp = TcoTyp;
			this.TcoTrj = TcoTrj;
			this.TcoVec = TcoVec;
			this.TcoVit = TcoVit;
			this.TcoSnx = TcoSnx;
			this.TcoSeq = TcoSeq;
			this.TcoTr1 = TcoTr1;
			this.TcoIp1 = TcoIp1;
			this.TcoTr2 = TcoTr2;
			this.TcoIp2 = TcoIp2;
			this.TcoTr3 = TcoTr3;
			this.TcoIp3 = TcoIp3;
			this.TcoTr4 = TcoTr4;
			this.TcoIp4 = TcoIp4;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSCT, TCOTYP, TCOTRJ, TCOVEC, TCOVIT, TCOSNX, TCOSEQ, TCOTR1, TCOIP1, TCOTR2, TCOIP2, TCOTR3, TCOIP3, TCOTR4, TCOIP4));
		};

		public String Cpt;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoSct;
		public String TcoTyp;
		public String TcoTrj;
		public String TcoVec;
		public String TcoVit;
		public String TcoSnx;
		public String TcoSeq;
		public String TcoTr1;
		public String TcoIp1;
		public String TcoTr2;
		public String TcoIp2;
		public String TcoTr3;
		public String TcoIp3;
		public String TcoTr4;
		public String TcoIp4;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmSteAAction");

			String itemtag = "TagitemWznmSteAAction";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoSct = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSct", mask, TCOSCT);
				TcoTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTyp", mask, TCOTYP);
				TcoTrj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTrj", mask, TCOTRJ);
				TcoVec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoVec", mask, TCOVEC);
				TcoVit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoVit", mask, TCOVIT);
				TcoSnx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSnx", mask, TCOSNX);
				TcoSeq = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSeq", mask, TCOSEQ);
				TcoTr1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTr1", mask, TCOTR1);
				TcoIp1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoIp1", mask, TCOIP1);
				TcoTr2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTr2", mask, TCOTR2);
				TcoIp2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoIp2", mask, TCOIP2);
				TcoTr3 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTr3", mask, TCOTR3);
				TcoIp3 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoIp3", mask, TCOIP3);
				TcoTr4 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTr4", mask, TCOTR4);
				TcoIp4 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoIp4", mask, TCOIP4);

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
			if (TcoSct.equals(comp.TcoSct)) items.add(TCOSCT);
			if (TcoTyp.equals(comp.TcoTyp)) items.add(TCOTYP);
			if (TcoTrj.equals(comp.TcoTrj)) items.add(TCOTRJ);
			if (TcoVec.equals(comp.TcoVec)) items.add(TCOVEC);
			if (TcoVit.equals(comp.TcoVit)) items.add(TCOVIT);
			if (TcoSnx.equals(comp.TcoSnx)) items.add(TCOSNX);
			if (TcoSeq.equals(comp.TcoSeq)) items.add(TCOSEQ);
			if (TcoTr1.equals(comp.TcoTr1)) items.add(TCOTR1);
			if (TcoIp1.equals(comp.TcoIp1)) items.add(TCOIP1);
			if (TcoTr2.equals(comp.TcoTr2)) items.add(TCOTR2);
			if (TcoIp2.equals(comp.TcoIp2)) items.add(TCOIP2);
			if (TcoTr3.equals(comp.TcoTr3)) items.add(TCOTR3);
			if (TcoIp3.equals(comp.TcoIp3)) items.add(TCOIP3);
			if (TcoTr4.equals(comp.TcoTr4)) items.add(TCOTR4);
			if (TcoIp4.equals(comp.TcoIp4)) items.add(TCOIP4);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSCT, TCOTYP, TCOTRJ, TCOVEC, TCOVIT, TCOSNX, TCOSEQ, TCOTR1, TCOIP1, TCOTR2, TCOIP2, TCOTR3, TCOIP3, TCOTR4, TCOIP4));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmSteAActionData)
		*/
	public class DpchAppData extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int STGIAC = 2;
		public static final int STGIACQRY = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, StgIac stgiac
					, QryWznmSteAAction.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPWZNMSTEAACTIONDATA, scrJref);

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
		public QryWznmSteAAction.StgIac stgiacqry;

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
			Element el = doc.createElement("DpchAppWznmSteAActionData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmSteAActionDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMSTEAACTIONDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmSteAActionDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmSteAActionData)
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
			super(VecWznmVDpch.DPCHENGWZNMSTEAACTIONDATA);

			continf = new ContInf(0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false);
			stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			rst = new ListWznmQSteAAction();
			statappqry = (new QryWznmSteAAction()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWznmSteAAction()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWznmSteAAction()).new StgIac(0, 0, 0);
		};

		public ContInf continf;
		public Feed feedFCsiQst;
		public StatApp statapp;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWznmQSteAAction rst;
		public QryWznmSteAAction.StatApp statappqry;
		public QryWznmSteAAction.StatShr statshrqry;
		public QryWznmSteAAction.StgIac stgiacqry;

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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmSteAActionData");

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
				stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
				statappqry = (new QryWznmSteAAction()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWznmSteAAction()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWznmSteAAction()).new StgIac(0, 0, 0);
			};
		};

	};

};

