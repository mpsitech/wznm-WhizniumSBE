/**
  * \file PnlWznmImeDetail.java
  * Java API code for job PnlWznmImeDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmImeDetail {
	/**
		* VecVDo (full: VecVWznmImeDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTIEXVIEWCLICK = 2;
		public static final int BUTSUPVIEWCLICK = 3;
		public static final int BUTRTRVIEWCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butiexviewclick")) return BUTIEXVIEWCLICK;
			if (s.equals("butsupviewclick")) return BUTSUPVIEWCLICK;
			if (s.equals("butrtrviewclick")) return BUTRTRVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTIEXVIEWCLICK) return("ButIexViewClick");
			if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
			if (ix == BUTRTRVIEWCLICK) return("ButRtrViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmImeDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMSFLSTIOP = 1;
		public static final int NUMFLSTRTR = 2;
		public static final int TXFRTR = 3;
		public static final int TXFCMT = 4;

		public ContIac(
					ArrayList<Integer> numsFLstIop
					, int numFLstRtr
					, String TxfRtr
					, String TxfCmt
				) {
			this.numsFLstIop = numsFLstIop;
			this.numFLstRtr = numFLstRtr;
			this.TxfRtr = TxfRtr;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMSFLSTIOP, NUMFLSTRTR, TXFRTR, TXFCMT));
		};

		public ArrayList<Integer> numsFLstIop;
		public int numFLstRtr;
		public String TxfRtr;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmImeDetail");

			String itemtag = "ContitemIacWznmImeDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numsFLstIop = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstIop", mask, NUMSFLSTIOP);
				numFLstRtr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstRtr", mask, NUMFLSTRTR);
				TxfRtr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfRtr", mask, TXFRTR);
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
			if (difftag.isEmpty()) difftag = "ContIacWznmImeDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmImeDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstIop", numsFLstIop);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstRtr", numFLstRtr);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfRtr", TxfRtr);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Xmlio.compareIntegervec(numsFLstIop, comp.numsFLstIop)) items.add(NUMSFLSTIOP);
			if (numFLstRtr == comp.numFLstRtr) items.add(NUMFLSTRTR);
			if (TxfRtr.equals(comp.TxfRtr)) items.add(TXFRTR);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMSFLSTIOP, NUMFLSTRTR, TXFRTR, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmImeDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTIEX = 2;
		public static final int TXTSUP = 3;
		public static final int TXTTBL = 4;
		public static final int TXTIOP = 5;

		public ContInf(
					String TxtSrf
					, String TxtIex
					, String TxtSup
					, String TxtTbl
					, String TxtIop
				) {
			this.TxtSrf = TxtSrf;
			this.TxtIex = TxtIex;
			this.TxtSup = TxtSup;
			this.TxtTbl = TxtTbl;
			this.TxtIop = TxtIop;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTIEX, TXTSUP, TXTTBL, TXTIOP));
		};

		public String TxtSrf;
		public String TxtIex;
		public String TxtSup;
		public String TxtTbl;
		public String TxtIop;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmImeDetail");

			String itemtag = "ContitemInfWznmImeDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtIex = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtIex", mask, TXTIEX);
				TxtSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSup", mask, TXTSUP);
				TxtTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTbl", mask, TXTTBL);
				TxtIop = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtIop", mask, TXTIOP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtIex.equals(comp.TxtIex)) items.add(TXTIEX);
			if (TxtSup.equals(comp.TxtSup)) items.add(TXTSUP);
			if (TxtTbl.equals(comp.TxtTbl)) items.add(TXTTBL);
			if (TxtIop.equals(comp.TxtIop)) items.add(TXTIOP);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTIEX, TXTSUP, TXTTBL, TXTIOP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmImeDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTIOPALT = 2;
		public static final int LSTRTRALT = 3;
		public static final int LSTIOPNUMFIRSTDISP = 4;
		public static final int LSTRTRNUMFIRSTDISP = 5;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstIopAlt
					, boolean LstRtrAlt
					, int LstIopNumFirstdisp
					, int LstRtrNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstIopAlt = LstIopAlt;
			this.LstRtrAlt = LstRtrAlt;
			this.LstIopNumFirstdisp = LstIopNumFirstdisp;
			this.LstRtrNumFirstdisp = LstRtrNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTIOPALT, LSTRTRALT, LSTIOPNUMFIRSTDISP, LSTRTRNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstIopAlt;
		public boolean LstRtrAlt;
		public int LstIopNumFirstdisp;
		public int LstRtrNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmImeDetail");

			String itemtag = "StatitemAppWznmImeDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstIopAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIopAlt", mask, LSTIOPALT);
				LstRtrAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRtrAlt", mask, LSTRTRALT);
				LstIopNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIopNumFirstdisp", mask, LSTIOPNUMFIRSTDISP);
				LstRtrNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRtrNumFirstdisp", mask, LSTRTRNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstIopAlt == comp.LstIopAlt) items.add(LSTIOPALT);
			if (LstRtrAlt == comp.LstRtrAlt) items.add(LSTRTRALT);
			if (LstIopNumFirstdisp == comp.LstIopNumFirstdisp) items.add(LSTIOPNUMFIRSTDISP);
			if (LstRtrNumFirstdisp == comp.LstRtrNumFirstdisp) items.add(LSTRTRNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTIOPALT, LSTRTRALT, LSTIOPNUMFIRSTDISP, LSTRTRNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmImeDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFRTRVALID = 1;
		public static final int BUTSAVEAVAIL = 2;
		public static final int BUTSAVEACTIVE = 3;
		public static final int TXTSRFACTIVE = 4;
		public static final int TXTIEXACTIVE = 5;
		public static final int BUTIEXVIEWAVAIL = 6;
		public static final int BUTIEXVIEWACTIVE = 7;
		public static final int TXTSUPACTIVE = 8;
		public static final int BUTSUPVIEWAVAIL = 9;
		public static final int BUTSUPVIEWACTIVE = 10;
		public static final int TXTTBLACTIVE = 11;
		public static final int LSTIOPACTIVE = 12;
		public static final int LSTRTRACTIVE = 13;
		public static final int BUTRTRVIEWAVAIL = 14;
		public static final int BUTRTRVIEWACTIVE = 15;
		public static final int TXFCMTACTIVE = 16;

		public StatShr(
					boolean TxfRtrValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxtIexActive
					, boolean ButIexViewAvail
					, boolean ButIexViewActive
					, boolean TxtSupActive
					, boolean ButSupViewAvail
					, boolean ButSupViewActive
					, boolean TxtTblActive
					, boolean LstIopActive
					, boolean LstRtrActive
					, boolean ButRtrViewAvail
					, boolean ButRtrViewActive
					, boolean TxfCmtActive
				) {
			this.TxfRtrValid = TxfRtrValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxtIexActive = TxtIexActive;
			this.ButIexViewAvail = ButIexViewAvail;
			this.ButIexViewActive = ButIexViewActive;
			this.TxtSupActive = TxtSupActive;
			this.ButSupViewAvail = ButSupViewAvail;
			this.ButSupViewActive = ButSupViewActive;
			this.TxtTblActive = TxtTblActive;
			this.LstIopActive = LstIopActive;
			this.LstRtrActive = LstRtrActive;
			this.ButRtrViewAvail = ButRtrViewAvail;
			this.ButRtrViewActive = ButRtrViewActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFRTRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTIEXACTIVE, BUTIEXVIEWAVAIL, BUTIEXVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, LSTIOPACTIVE, LSTRTRACTIVE, BUTRTRVIEWAVAIL, BUTRTRVIEWACTIVE, TXFCMTACTIVE));
		};

		public boolean TxfRtrValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxtIexActive;
		public boolean ButIexViewAvail;
		public boolean ButIexViewActive;
		public boolean TxtSupActive;
		public boolean ButSupViewAvail;
		public boolean ButSupViewActive;
		public boolean TxtTblActive;
		public boolean LstIopActive;
		public boolean LstRtrActive;
		public boolean ButRtrViewAvail;
		public boolean ButRtrViewActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmImeDetail");

			String itemtag = "StatitemShrWznmImeDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfRtrValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfRtrValid", mask, TXFRTRVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxtIexActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtIexActive", mask, TXTIEXACTIVE);
				ButIexViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButIexViewAvail", mask, BUTIEXVIEWAVAIL);
				ButIexViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButIexViewActive", mask, BUTIEXVIEWACTIVE);
				TxtSupActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSupActive", mask, TXTSUPACTIVE);
				ButSupViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", mask, BUTSUPVIEWAVAIL);
				ButSupViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewActive", mask, BUTSUPVIEWACTIVE);
				TxtTblActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTblActive", mask, TXTTBLACTIVE);
				LstIopActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIopActive", mask, LSTIOPACTIVE);
				LstRtrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRtrActive", mask, LSTRTRACTIVE);
				ButRtrViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRtrViewAvail", mask, BUTRTRVIEWAVAIL);
				ButRtrViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRtrViewActive", mask, BUTRTRVIEWACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfRtrValid == comp.TxfRtrValid) items.add(TXFRTRVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (TxtIexActive == comp.TxtIexActive) items.add(TXTIEXACTIVE);
			if (ButIexViewAvail == comp.ButIexViewAvail) items.add(BUTIEXVIEWAVAIL);
			if (ButIexViewActive == comp.ButIexViewActive) items.add(BUTIEXVIEWACTIVE);
			if (TxtSupActive == comp.TxtSupActive) items.add(TXTSUPACTIVE);
			if (ButSupViewAvail == comp.ButSupViewAvail) items.add(BUTSUPVIEWAVAIL);
			if (ButSupViewActive == comp.ButSupViewActive) items.add(BUTSUPVIEWACTIVE);
			if (TxtTblActive == comp.TxtTblActive) items.add(TXTTBLACTIVE);
			if (LstIopActive == comp.LstIopActive) items.add(LSTIOPACTIVE);
			if (LstRtrActive == comp.LstRtrActive) items.add(LSTRTRACTIVE);
			if (ButRtrViewAvail == comp.ButRtrViewAvail) items.add(BUTRTRVIEWAVAIL);
			if (ButRtrViewActive == comp.ButRtrViewActive) items.add(BUTRTRVIEWACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFRTRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTIEXACTIVE, BUTIEXVIEWAVAIL, BUTIEXVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, LSTIOPACTIVE, LSTRTRACTIVE, BUTRTRVIEWAVAIL, BUTRTRVIEWACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmImeDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTIEX = 3;
		public static final int CPTSUP = 4;
		public static final int CPTTBL = 5;
		public static final int CPTIOP = 6;
		public static final int CPTRTR = 7;
		public static final int CPTCMT = 8;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptIex
					, String CptSup
					, String CptTbl
					, String CptIop
					, String CptRtr
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptIex = CptIex;
			this.CptSup = CptSup;
			this.CptTbl = CptTbl;
			this.CptIop = CptIop;
			this.CptRtr = CptRtr;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTIEX, CPTSUP, CPTTBL, CPTIOP, CPTRTR, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptIex;
		public String CptSup;
		public String CptTbl;
		public String CptIop;
		public String CptRtr;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmImeDetail");

			String itemtag = "TagitemWznmImeDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptIex = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIex", mask, CPTIEX);
				CptSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSup", mask, CPTSUP);
				CptTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTbl", mask, CPTTBL);
				CptIop = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIop", mask, CPTIOP);
				CptRtr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptRtr", mask, CPTRTR);
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
			if (CptSrf.equals(comp.CptSrf)) items.add(CPTSRF);
			if (CptIex.equals(comp.CptIex)) items.add(CPTIEX);
			if (CptSup.equals(comp.CptSup)) items.add(CPTSUP);
			if (CptTbl.equals(comp.CptTbl)) items.add(CPTTBL);
			if (CptIop.equals(comp.CptIop)) items.add(CPTIOP);
			if (CptRtr.equals(comp.CptRtr)) items.add(CPTRTR);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTIEX, CPTSUP, CPTTBL, CPTIOP, CPTRTR, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmImeDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMIMEDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmImeDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmImeDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMIMEDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmImeDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmImeDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTIOP = 4;
		public static final int FEEDFLSTRTR = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMIMEDETAILDATA);

			contiac = new ContIac(new ArrayList<Integer>(), 0, "", "");
			continf = new ContInf("", "", "", "", "");
			feedFLstIop = new Feed("FeedFLstIop");
			feedFLstRtr = new Feed("FeedFLstRtr");
			statapp = new StatApp(0, false, false, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstIop;
		public Feed feedFLstRtr;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTIOP)) ss.add("feedFLstIop");
			if (has(FEEDFLSTRTR)) ss.add("feedFLstRtr");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmImeDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstIop.readXML(doc, basexpath, true)) add(FEEDFLSTIOP);
				if (feedFLstRtr.readXML(doc, basexpath, true)) add(FEEDFLSTRTR);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(new ArrayList<Integer>(), 0, "", "");
				continf = new ContInf("", "", "", "", "");
				feedFLstIop = new Feed("FeedFLstIop");
				feedFLstRtr = new Feed("FeedFLstRtr");
				statapp = new StatApp(0, false, false, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "");
			};
		};

	};

};

