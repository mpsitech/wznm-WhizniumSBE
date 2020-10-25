/**
  * \file PnlWznmVerDetail.java
  * Java API code for job PnlWznmVerDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmVerDetail {
	/**
		* VecVDo (full: VecVWznmVerDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTPRJVIEWCLICK = 2;
		public static final int BUTBVRVIEWCLICK = 3;
		public static final int BUTLOCVIEWCLICK = 4;
		public static final int BUTJSTEDITCLICK = 5;
		public static final int BUTJEDITCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butprjviewclick")) return BUTPRJVIEWCLICK;
			if (s.equals("butbvrviewclick")) return BUTBVRVIEWCLICK;
			if (s.equals("butlocviewclick")) return BUTLOCVIEWCLICK;
			if (s.equals("butjsteditclick")) return BUTJSTEDITCLICK;
			if (s.equals("butjeditclick")) return BUTJEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
			if (ix == BUTBVRVIEWCLICK) return("ButBvrViewClick");
			if (ix == BUTLOCVIEWCLICK) return("ButLocViewClick");
			if (ix == BUTJSTEDITCLICK) return("ButJstEditClick");
			if (ix == BUTJEDITCLICK) return("ButJEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmVerDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFMAJ = 1;
		public static final int TXFMIN = 2;
		public static final int TXFSUB = 3;
		public static final int NUMFPUPJST = 4;
		public static final int NUMFPUPSTE = 5;
		public static final int NUMSFLSTDTY = 6;
		public static final int NUMSFLSTOPT = 7;
		public static final int NUMFPUPJ = 8;
		public static final int TXFCMT = 9;

		public ContIac(
					String TxfMaj
					, String TxfMin
					, String TxfSub
					, int numFPupJst
					, int numFPupSte
					, ArrayList<Integer> numsFLstDty
					, ArrayList<Integer> numsFLstOpt
					, int numFPupJ
					, String TxfCmt
				) {
			this.TxfMaj = TxfMaj;
			this.TxfMin = TxfMin;
			this.TxfSub = TxfSub;
			this.numFPupJst = numFPupJst;
			this.numFPupSte = numFPupSte;
			this.numsFLstDty = numsFLstDty;
			this.numsFLstOpt = numsFLstOpt;
			this.numFPupJ = numFPupJ;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(TXFMAJ, TXFMIN, TXFSUB, NUMFPUPJST, NUMFPUPSTE, NUMSFLSTDTY, NUMSFLSTOPT, NUMFPUPJ, TXFCMT));
		};

		public String TxfMaj;
		public String TxfMin;
		public String TxfSub;
		public int numFPupJst;
		public int numFPupSte;
		public ArrayList<Integer> numsFLstDty;
		public ArrayList<Integer> numsFLstOpt;
		public int numFPupJ;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmVerDetail");

			String itemtag = "ContitemIacWznmVerDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfMaj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfMaj", mask, TXFMAJ);
				TxfMin = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfMin", mask, TXFMIN);
				TxfSub = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSub", mask, TXFSUB);
				numFPupJst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupJst", mask, NUMFPUPJST);
				numFPupSte = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupSte", mask, NUMFPUPSTE);
				numsFLstDty = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstDty", mask, NUMSFLSTDTY);
				numsFLstOpt = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", mask, NUMSFLSTOPT);
				numFPupJ = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupJ", mask, NUMFPUPJ);
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCmt", mask, TXFCMT);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmVerDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmVerDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMaj", TxfMaj);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMin", TxfMin);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSub", TxfSub);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupJst", numFPupJst);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupSte", numFPupSte);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstDty", numsFLstDty);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupJ", numFPupJ);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfMaj.equals(comp.TxfMaj)) items.add(TXFMAJ);
			if (TxfMin.equals(comp.TxfMin)) items.add(TXFMIN);
			if (TxfSub.equals(comp.TxfSub)) items.add(TXFSUB);
			if (numFPupJst == comp.numFPupJst) items.add(NUMFPUPJST);
			if (numFPupSte == comp.numFPupSte) items.add(NUMFPUPSTE);
			if (Xmlio.compareIntegervec(numsFLstDty, comp.numsFLstDty)) items.add(NUMSFLSTDTY);
			if (Xmlio.compareIntegervec(numsFLstOpt, comp.numsFLstOpt)) items.add(NUMSFLSTOPT);
			if (numFPupJ == comp.numFPupJ) items.add(NUMFPUPJ);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFMAJ, TXFMIN, TXFSUB, NUMFPUPJST, NUMFPUPSTE, NUMSFLSTDTY, NUMSFLSTOPT, NUMFPUPJ, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmVerDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTPRJ = 1;
		public static final int TXTBVR = 2;
		public static final int TXTLOC = 3;
		public static final int TXTDTY = 4;
		public static final int TXTOPT = 5;
		public static final int TXTAB1 = 6;
		public static final int TXTAB2 = 7;
		public static final int TXTAB3 = 8;

		public ContInf(
					String TxtPrj
					, String TxtBvr
					, String TxtLoc
					, String TxtDty
					, String TxtOpt
					, String TxtAb1
					, String TxtAb2
					, String TxtAb3
				) {
			this.TxtPrj = TxtPrj;
			this.TxtBvr = TxtBvr;
			this.TxtLoc = TxtLoc;
			this.TxtDty = TxtDty;
			this.TxtOpt = TxtOpt;
			this.TxtAb1 = TxtAb1;
			this.TxtAb2 = TxtAb2;
			this.TxtAb3 = TxtAb3;

			mask = new HashSet<Integer>(Arrays.asList(TXTPRJ, TXTBVR, TXTLOC, TXTDTY, TXTOPT, TXTAB1, TXTAB2, TXTAB3));
		};

		public String TxtPrj;
		public String TxtBvr;
		public String TxtLoc;
		public String TxtDty;
		public String TxtOpt;
		public String TxtAb1;
		public String TxtAb2;
		public String TxtAb3;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmVerDetail");

			String itemtag = "ContitemInfWznmVerDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtPrj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrj", mask, TXTPRJ);
				TxtBvr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtBvr", mask, TXTBVR);
				TxtLoc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtLoc", mask, TXTLOC);
				TxtDty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtDty", mask, TXTDTY);
				TxtOpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtOpt", mask, TXTOPT);
				TxtAb1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtAb1", mask, TXTAB1);
				TxtAb2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtAb2", mask, TXTAB2);
				TxtAb3 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtAb3", mask, TXTAB3);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtPrj.equals(comp.TxtPrj)) items.add(TXTPRJ);
			if (TxtBvr.equals(comp.TxtBvr)) items.add(TXTBVR);
			if (TxtLoc.equals(comp.TxtLoc)) items.add(TXTLOC);
			if (TxtDty.equals(comp.TxtDty)) items.add(TXTDTY);
			if (TxtOpt.equals(comp.TxtOpt)) items.add(TXTOPT);
			if (TxtAb1.equals(comp.TxtAb1)) items.add(TXTAB1);
			if (TxtAb2.equals(comp.TxtAb2)) items.add(TXTAB2);
			if (TxtAb3.equals(comp.TxtAb3)) items.add(TXTAB3);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTPRJ, TXTBVR, TXTLOC, TXTDTY, TXTOPT, TXTAB1, TXTAB2, TXTAB3));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmVerDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTDTYALT = 2;
		public static final int LSTOPTALT = 3;
		public static final int LSTDTYNUMFIRSTDISP = 4;
		public static final int LSTOPTNUMFIRSTDISP = 5;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstDtyAlt
					, boolean LstOptAlt
					, int LstDtyNumFirstdisp
					, int LstOptNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstDtyAlt = LstDtyAlt;
			this.LstOptAlt = LstOptAlt;
			this.LstDtyNumFirstdisp = LstDtyNumFirstdisp;
			this.LstOptNumFirstdisp = LstOptNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTDTYALT, LSTOPTALT, LSTDTYNUMFIRSTDISP, LSTOPTNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstDtyAlt;
		public boolean LstOptAlt;
		public int LstDtyNumFirstdisp;
		public int LstOptNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmVerDetail");

			String itemtag = "StatitemAppWznmVerDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstDtyAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDtyAlt", mask, LSTDTYALT);
				LstOptAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptAlt", mask, LSTOPTALT);
				LstDtyNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDtyNumFirstdisp", mask, LSTDTYNUMFIRSTDISP);
				LstOptNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptNumFirstdisp", mask, LSTOPTNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstDtyAlt == comp.LstDtyAlt) items.add(LSTDTYALT);
			if (LstOptAlt == comp.LstOptAlt) items.add(LSTOPTALT);
			if (LstDtyNumFirstdisp == comp.LstDtyNumFirstdisp) items.add(LSTDTYNUMFIRSTDISP);
			if (LstOptNumFirstdisp == comp.LstOptNumFirstdisp) items.add(LSTOPTNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTDTYALT, LSTOPTALT, LSTDTYNUMFIRSTDISP, LSTOPTNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmVerDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTPRJACTIVE = 3;
		public static final int BUTPRJVIEWAVAIL = 4;
		public static final int BUTPRJVIEWACTIVE = 5;
		public static final int TXFMAJACTIVE = 6;
		public static final int TXFMINACTIVE = 7;
		public static final int TXFSUBACTIVE = 8;
		public static final int TXTBVRACTIVE = 9;
		public static final int BUTBVRVIEWAVAIL = 10;
		public static final int BUTBVRVIEWACTIVE = 11;
		public static final int TXTLOCACTIVE = 12;
		public static final int BUTLOCVIEWAVAIL = 13;
		public static final int BUTLOCVIEWACTIVE = 14;
		public static final int PUPJSTACTIVE = 15;
		public static final int BUTJSTEDITAVAIL = 16;
		public static final int PUPSTEACTIVE = 17;
		public static final int LSTDTYACTIVE = 18;
		public static final int LSTOPTACTIVE = 19;
		public static final int PUPJACTIVE = 20;
		public static final int BUTJEDITAVAIL = 21;
		public static final int TXTAB1ACTIVE = 22;
		public static final int TXTAB2ACTIVE = 23;
		public static final int TXTAB3ACTIVE = 24;
		public static final int TXFCMTACTIVE = 25;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtPrjActive
					, boolean ButPrjViewAvail
					, boolean ButPrjViewActive
					, boolean TxfMajActive
					, boolean TxfMinActive
					, boolean TxfSubActive
					, boolean TxtBvrActive
					, boolean ButBvrViewAvail
					, boolean ButBvrViewActive
					, boolean TxtLocActive
					, boolean ButLocViewAvail
					, boolean ButLocViewActive
					, boolean PupJstActive
					, boolean ButJstEditAvail
					, boolean PupSteActive
					, boolean LstDtyActive
					, boolean LstOptActive
					, boolean PupJActive
					, boolean ButJEditAvail
					, boolean TxtAb1Active
					, boolean TxtAb2Active
					, boolean TxtAb3Active
					, boolean TxfCmtActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtPrjActive = TxtPrjActive;
			this.ButPrjViewAvail = ButPrjViewAvail;
			this.ButPrjViewActive = ButPrjViewActive;
			this.TxfMajActive = TxfMajActive;
			this.TxfMinActive = TxfMinActive;
			this.TxfSubActive = TxfSubActive;
			this.TxtBvrActive = TxtBvrActive;
			this.ButBvrViewAvail = ButBvrViewAvail;
			this.ButBvrViewActive = ButBvrViewActive;
			this.TxtLocActive = TxtLocActive;
			this.ButLocViewAvail = ButLocViewAvail;
			this.ButLocViewActive = ButLocViewActive;
			this.PupJstActive = PupJstActive;
			this.ButJstEditAvail = ButJstEditAvail;
			this.PupSteActive = PupSteActive;
			this.LstDtyActive = LstDtyActive;
			this.LstOptActive = LstOptActive;
			this.PupJActive = PupJActive;
			this.ButJEditAvail = ButJEditAvail;
			this.TxtAb1Active = TxtAb1Active;
			this.TxtAb2Active = TxtAb2Active;
			this.TxtAb3Active = TxtAb3Active;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRJACTIVE, BUTPRJVIEWAVAIL, BUTPRJVIEWACTIVE, TXFMAJACTIVE, TXFMINACTIVE, TXFSUBACTIVE, TXTBVRACTIVE, BUTBVRVIEWAVAIL, BUTBVRVIEWACTIVE, TXTLOCACTIVE, BUTLOCVIEWAVAIL, BUTLOCVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, LSTDTYACTIVE, LSTOPTACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTAB1ACTIVE, TXTAB2ACTIVE, TXTAB3ACTIVE, TXFCMTACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtPrjActive;
		public boolean ButPrjViewAvail;
		public boolean ButPrjViewActive;
		public boolean TxfMajActive;
		public boolean TxfMinActive;
		public boolean TxfSubActive;
		public boolean TxtBvrActive;
		public boolean ButBvrViewAvail;
		public boolean ButBvrViewActive;
		public boolean TxtLocActive;
		public boolean ButLocViewAvail;
		public boolean ButLocViewActive;
		public boolean PupJstActive;
		public boolean ButJstEditAvail;
		public boolean PupSteActive;
		public boolean LstDtyActive;
		public boolean LstOptActive;
		public boolean PupJActive;
		public boolean ButJEditAvail;
		public boolean TxtAb1Active;
		public boolean TxtAb2Active;
		public boolean TxtAb3Active;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmVerDetail");

			String itemtag = "StatitemShrWznmVerDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtPrjActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPrjActive", mask, TXTPRJACTIVE);
				ButPrjViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrjViewAvail", mask, BUTPRJVIEWAVAIL);
				ButPrjViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrjViewActive", mask, BUTPRJVIEWACTIVE);
				TxfMajActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfMajActive", mask, TXFMAJACTIVE);
				TxfMinActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfMinActive", mask, TXFMINACTIVE);
				TxfSubActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfSubActive", mask, TXFSUBACTIVE);
				TxtBvrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtBvrActive", mask, TXTBVRACTIVE);
				ButBvrViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBvrViewAvail", mask, BUTBVRVIEWAVAIL);
				ButBvrViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBvrViewActive", mask, BUTBVRVIEWACTIVE);
				TxtLocActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtLocActive", mask, TXTLOCACTIVE);
				ButLocViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButLocViewAvail", mask, BUTLOCVIEWAVAIL);
				ButLocViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButLocViewActive", mask, BUTLOCVIEWACTIVE);
				PupJstActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupJstActive", mask, PUPJSTACTIVE);
				ButJstEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJstEditAvail", mask, BUTJSTEDITAVAIL);
				PupSteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupSteActive", mask, PUPSTEACTIVE);
				LstDtyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDtyActive", mask, LSTDTYACTIVE);
				LstOptActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptActive", mask, LSTOPTACTIVE);
				PupJActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupJActive", mask, PUPJACTIVE);
				ButJEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJEditAvail", mask, BUTJEDITAVAIL);
				TxtAb1Active = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtAb1Active", mask, TXTAB1ACTIVE);
				TxtAb2Active = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtAb2Active", mask, TXTAB2ACTIVE);
				TxtAb3Active = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtAb3Active", mask, TXTAB3ACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtPrjActive == comp.TxtPrjActive) items.add(TXTPRJACTIVE);
			if (ButPrjViewAvail == comp.ButPrjViewAvail) items.add(BUTPRJVIEWAVAIL);
			if (ButPrjViewActive == comp.ButPrjViewActive) items.add(BUTPRJVIEWACTIVE);
			if (TxfMajActive == comp.TxfMajActive) items.add(TXFMAJACTIVE);
			if (TxfMinActive == comp.TxfMinActive) items.add(TXFMINACTIVE);
			if (TxfSubActive == comp.TxfSubActive) items.add(TXFSUBACTIVE);
			if (TxtBvrActive == comp.TxtBvrActive) items.add(TXTBVRACTIVE);
			if (ButBvrViewAvail == comp.ButBvrViewAvail) items.add(BUTBVRVIEWAVAIL);
			if (ButBvrViewActive == comp.ButBvrViewActive) items.add(BUTBVRVIEWACTIVE);
			if (TxtLocActive == comp.TxtLocActive) items.add(TXTLOCACTIVE);
			if (ButLocViewAvail == comp.ButLocViewAvail) items.add(BUTLOCVIEWAVAIL);
			if (ButLocViewActive == comp.ButLocViewActive) items.add(BUTLOCVIEWACTIVE);
			if (PupJstActive == comp.PupJstActive) items.add(PUPJSTACTIVE);
			if (ButJstEditAvail == comp.ButJstEditAvail) items.add(BUTJSTEDITAVAIL);
			if (PupSteActive == comp.PupSteActive) items.add(PUPSTEACTIVE);
			if (LstDtyActive == comp.LstDtyActive) items.add(LSTDTYACTIVE);
			if (LstOptActive == comp.LstOptActive) items.add(LSTOPTACTIVE);
			if (PupJActive == comp.PupJActive) items.add(PUPJACTIVE);
			if (ButJEditAvail == comp.ButJEditAvail) items.add(BUTJEDITAVAIL);
			if (TxtAb1Active == comp.TxtAb1Active) items.add(TXTAB1ACTIVE);
			if (TxtAb2Active == comp.TxtAb2Active) items.add(TXTAB2ACTIVE);
			if (TxtAb3Active == comp.TxtAb3Active) items.add(TXTAB3ACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRJACTIVE, BUTPRJVIEWAVAIL, BUTPRJVIEWACTIVE, TXFMAJACTIVE, TXFMINACTIVE, TXFSUBACTIVE, TXTBVRACTIVE, BUTBVRVIEWAVAIL, BUTBVRVIEWACTIVE, TXTLOCACTIVE, BUTLOCVIEWAVAIL, BUTLOCVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, LSTDTYACTIVE, LSTOPTACTIVE, PUPJACTIVE, BUTJEDITAVAIL, TXTAB1ACTIVE, TXTAB2ACTIVE, TXTAB3ACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmVerDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTPRJ = 2;
		public static final int CPTMAJ = 3;
		public static final int CPTMIN = 4;
		public static final int CPTSUB = 5;
		public static final int CPTBVR = 6;
		public static final int CPTLOC = 7;
		public static final int CPTSTE = 8;
		public static final int CPTDTY = 9;
		public static final int CPTOPT = 10;
		public static final int CPTAB1 = 11;
		public static final int CPTAB2 = 12;
		public static final int CPTAB3 = 13;
		public static final int CPTCMT = 14;

		public Tag(
					String Cpt
					, String CptPrj
					, String CptMaj
					, String CptMin
					, String CptSub
					, String CptBvr
					, String CptLoc
					, String CptSte
					, String CptDty
					, String CptOpt
					, String CptAb1
					, String CptAb2
					, String CptAb3
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptPrj = CptPrj;
			this.CptMaj = CptMaj;
			this.CptMin = CptMin;
			this.CptSub = CptSub;
			this.CptBvr = CptBvr;
			this.CptLoc = CptLoc;
			this.CptSte = CptSte;
			this.CptDty = CptDty;
			this.CptOpt = CptOpt;
			this.CptAb1 = CptAb1;
			this.CptAb2 = CptAb2;
			this.CptAb3 = CptAb3;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTPRJ, CPTMAJ, CPTMIN, CPTSUB, CPTBVR, CPTLOC, CPTSTE, CPTDTY, CPTOPT, CPTAB1, CPTAB2, CPTAB3, CPTCMT));
		};

		public String Cpt;
		public String CptPrj;
		public String CptMaj;
		public String CptMin;
		public String CptSub;
		public String CptBvr;
		public String CptLoc;
		public String CptSte;
		public String CptDty;
		public String CptOpt;
		public String CptAb1;
		public String CptAb2;
		public String CptAb3;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmVerDetail");

			String itemtag = "TagitemWznmVerDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptPrj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrj", mask, CPTPRJ);
				CptMaj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMaj", mask, CPTMAJ);
				CptMin = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMin", mask, CPTMIN);
				CptSub = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSub", mask, CPTSUB);
				CptBvr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptBvr", mask, CPTBVR);
				CptLoc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLoc", mask, CPTLOC);
				CptSte = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSte", mask, CPTSTE);
				CptDty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDty", mask, CPTDTY);
				CptOpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOpt", mask, CPTOPT);
				CptAb1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAb1", mask, CPTAB1);
				CptAb2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAb2", mask, CPTAB2);
				CptAb3 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAb3", mask, CPTAB3);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptPrj.equals(comp.CptPrj)) items.add(CPTPRJ);
			if (CptMaj.equals(comp.CptMaj)) items.add(CPTMAJ);
			if (CptMin.equals(comp.CptMin)) items.add(CPTMIN);
			if (CptSub.equals(comp.CptSub)) items.add(CPTSUB);
			if (CptBvr.equals(comp.CptBvr)) items.add(CPTBVR);
			if (CptLoc.equals(comp.CptLoc)) items.add(CPTLOC);
			if (CptSte.equals(comp.CptSte)) items.add(CPTSTE);
			if (CptDty.equals(comp.CptDty)) items.add(CPTDTY);
			if (CptOpt.equals(comp.CptOpt)) items.add(CPTOPT);
			if (CptAb1.equals(comp.CptAb1)) items.add(CPTAB1);
			if (CptAb2.equals(comp.CptAb2)) items.add(CPTAB2);
			if (CptAb3.equals(comp.CptAb3)) items.add(CPTAB3);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTPRJ, CPTMAJ, CPTMIN, CPTSUB, CPTBVR, CPTLOC, CPTSTE, CPTDTY, CPTOPT, CPTAB1, CPTAB2, CPTAB3, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmVerDetailData)
		*/
	public class DpchAppData extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int ALL = 3;

		public DpchAppData(
					String scrJref
					, ContIac contiac
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPWZNMVERDETAILDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIAC));
					break;
				};

			if (has(CONTIAC)) this.contiac = contiac;
		};

		public ContIac contiac;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWznmVerDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmVerDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMVERDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmVerDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmVerDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTDTY = 4;
		public static final int FEEDFLSTOPT = 5;
		public static final int FEEDFPUPJ = 6;
		public static final int FEEDFPUPJST = 7;
		public static final int FEEDFPUPSTE = 8;
		public static final int STATAPP = 9;
		public static final int STATSHR = 10;
		public static final int TAG = 11;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMVERDETAILDATA);

			contiac = new ContIac("", "", "", 0, 0, new ArrayList<Integer>(), new ArrayList<Integer>(), 0, "");
			continf = new ContInf("", "", "", "", "", "", "", "");
			feedFLstDty = new Feed("FeedFLstDty");
			feedFLstOpt = new Feed("FeedFLstOpt");
			feedFPupJ = new Feed("FeedFPupJ");
			feedFPupJst = new Feed("FeedFPupJst");
			feedFPupSte = new Feed("FeedFPupSte");
			statapp = new StatApp(0, false, false, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstDty;
		public Feed feedFLstOpt;
		public Feed feedFPupJ;
		public Feed feedFPupJst;
		public Feed feedFPupSte;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTDTY)) ss.add("feedFLstDty");
			if (has(FEEDFLSTOPT)) ss.add("feedFLstOpt");
			if (has(FEEDFPUPJ)) ss.add("feedFPupJ");
			if (has(FEEDFPUPJST)) ss.add("feedFPupJst");
			if (has(FEEDFPUPSTE)) ss.add("feedFPupSte");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmVerDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstDty.readXML(doc, basexpath, true)) add(FEEDFLSTDTY);
				if (feedFLstOpt.readXML(doc, basexpath, true)) add(FEEDFLSTOPT);
				if (feedFPupJ.readXML(doc, basexpath, true)) add(FEEDFPUPJ);
				if (feedFPupJst.readXML(doc, basexpath, true)) add(FEEDFPUPJST);
				if (feedFPupSte.readXML(doc, basexpath, true)) add(FEEDFPUPSTE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", "", 0, 0, new ArrayList<Integer>(), new ArrayList<Integer>(), 0, "");
				continf = new ContInf("", "", "", "", "", "", "", "");
				feedFLstDty = new Feed("FeedFLstDty");
				feedFLstOpt = new Feed("FeedFLstOpt");
				feedFPupJ = new Feed("FeedFPupJ");
				feedFPupJst = new Feed("FeedFPupJst");
				feedFPupSte = new Feed("FeedFPupSte");
				statapp = new StatApp(0, false, false, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

