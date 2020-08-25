/**
  * \file PnlWznmNavDbstr.java
  * Java API code for job PnlWznmNavDbstr
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmNavDbstr {
	/**
		* VecVDo (full: VecVWznmNavDbstrDo)
		*/
	public static class VecVDo {

		public static final int BUTTBLVIEWCLICK = 1;
		public static final int BUTTBLNEWCRDCLICK = 2;
		public static final int BUTTCOVIEWCLICK = 3;
		public static final int BUTTCONEWCRDCLICK = 4;
		public static final int BUTSBSVIEWCLICK = 5;
		public static final int BUTSBSNEWCRDCLICK = 6;
		public static final int BUTRELVIEWCLICK = 7;
		public static final int BUTRELNEWCRDCLICK = 8;
		public static final int BUTVECVIEWCLICK = 9;
		public static final int BUTVECNEWCRDCLICK = 10;
		public static final int BUTVITVIEWCLICK = 11;
		public static final int BUTVITNEWCRDCLICK = 12;
		public static final int BUTCHKVIEWCLICK = 13;
		public static final int BUTCHKNEWCRDCLICK = 14;
		public static final int BUTSTBVIEWCLICK = 15;
		public static final int BUTSTBNEWCRDCLICK = 16;
		public static final int BUTIEXVIEWCLICK = 17;
		public static final int BUTIEXNEWCRDCLICK = 18;
		public static final int BUTIMEVIEWCLICK = 19;
		public static final int BUTIMENEWCRDCLICK = 20;
		public static final int BUTIELVIEWCLICK = 21;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("buttblviewclick")) return BUTTBLVIEWCLICK;
			if (s.equals("buttblnewcrdclick")) return BUTTBLNEWCRDCLICK;
			if (s.equals("buttcoviewclick")) return BUTTCOVIEWCLICK;
			if (s.equals("buttconewcrdclick")) return BUTTCONEWCRDCLICK;
			if (s.equals("butsbsviewclick")) return BUTSBSVIEWCLICK;
			if (s.equals("butsbsnewcrdclick")) return BUTSBSNEWCRDCLICK;
			if (s.equals("butrelviewclick")) return BUTRELVIEWCLICK;
			if (s.equals("butrelnewcrdclick")) return BUTRELNEWCRDCLICK;
			if (s.equals("butvecviewclick")) return BUTVECVIEWCLICK;
			if (s.equals("butvecnewcrdclick")) return BUTVECNEWCRDCLICK;
			if (s.equals("butvitviewclick")) return BUTVITVIEWCLICK;
			if (s.equals("butvitnewcrdclick")) return BUTVITNEWCRDCLICK;
			if (s.equals("butchkviewclick")) return BUTCHKVIEWCLICK;
			if (s.equals("butchknewcrdclick")) return BUTCHKNEWCRDCLICK;
			if (s.equals("butstbviewclick")) return BUTSTBVIEWCLICK;
			if (s.equals("butstbnewcrdclick")) return BUTSTBNEWCRDCLICK;
			if (s.equals("butiexviewclick")) return BUTIEXVIEWCLICK;
			if (s.equals("butiexnewcrdclick")) return BUTIEXNEWCRDCLICK;
			if (s.equals("butimeviewclick")) return BUTIMEVIEWCLICK;
			if (s.equals("butimenewcrdclick")) return BUTIMENEWCRDCLICK;
			if (s.equals("butielviewclick")) return BUTIELVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTTBLVIEWCLICK) return("ButTblViewClick");
			if (ix == BUTTBLNEWCRDCLICK) return("ButTblNewcrdClick");
			if (ix == BUTTCOVIEWCLICK) return("ButTcoViewClick");
			if (ix == BUTTCONEWCRDCLICK) return("ButTcoNewcrdClick");
			if (ix == BUTSBSVIEWCLICK) return("ButSbsViewClick");
			if (ix == BUTSBSNEWCRDCLICK) return("ButSbsNewcrdClick");
			if (ix == BUTRELVIEWCLICK) return("ButRelViewClick");
			if (ix == BUTRELNEWCRDCLICK) return("ButRelNewcrdClick");
			if (ix == BUTVECVIEWCLICK) return("ButVecViewClick");
			if (ix == BUTVECNEWCRDCLICK) return("ButVecNewcrdClick");
			if (ix == BUTVITVIEWCLICK) return("ButVitViewClick");
			if (ix == BUTVITNEWCRDCLICK) return("ButVitNewcrdClick");
			if (ix == BUTCHKVIEWCLICK) return("ButChkViewClick");
			if (ix == BUTCHKNEWCRDCLICK) return("ButChkNewcrdClick");
			if (ix == BUTSTBVIEWCLICK) return("ButStbViewClick");
			if (ix == BUTSTBNEWCRDCLICK) return("ButStbNewcrdClick");
			if (ix == BUTIEXVIEWCLICK) return("ButIexViewClick");
			if (ix == BUTIEXNEWCRDCLICK) return("ButIexNewcrdClick");
			if (ix == BUTIMEVIEWCLICK) return("ButImeViewClick");
			if (ix == BUTIMENEWCRDCLICK) return("ButImeNewcrdClick");
			if (ix == BUTIELVIEWCLICK) return("ButIelViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmNavDbstr)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTTBL = 1;
		public static final int NUMFLSTTCO = 2;
		public static final int NUMFLSTSBS = 3;
		public static final int NUMFLSTREL = 4;
		public static final int NUMFLSTVEC = 5;
		public static final int NUMFLSTVIT = 6;
		public static final int NUMFLSTCHK = 7;
		public static final int NUMFLSTSTB = 8;
		public static final int NUMFLSTIEX = 9;
		public static final int NUMFLSTIME = 10;
		public static final int NUMFLSTIEL = 11;

		public ContIac(
					int numFLstTbl
					, int numFLstTco
					, int numFLstSbs
					, int numFLstRel
					, int numFLstVec
					, int numFLstVit
					, int numFLstChk
					, int numFLstStb
					, int numFLstIex
					, int numFLstIme
					, int numFLstIel
				) {
			this.numFLstTbl = numFLstTbl;
			this.numFLstTco = numFLstTco;
			this.numFLstSbs = numFLstSbs;
			this.numFLstRel = numFLstRel;
			this.numFLstVec = numFLstVec;
			this.numFLstVit = numFLstVit;
			this.numFLstChk = numFLstChk;
			this.numFLstStb = numFLstStb;
			this.numFLstIex = numFLstIex;
			this.numFLstIme = numFLstIme;
			this.numFLstIel = numFLstIel;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTTBL, NUMFLSTTCO, NUMFLSTSBS, NUMFLSTREL, NUMFLSTVEC, NUMFLSTVIT, NUMFLSTCHK, NUMFLSTSTB, NUMFLSTIEX, NUMFLSTIME, NUMFLSTIEL));
		};

		public int numFLstTbl;
		public int numFLstTco;
		public int numFLstSbs;
		public int numFLstRel;
		public int numFLstVec;
		public int numFLstVit;
		public int numFLstChk;
		public int numFLstStb;
		public int numFLstIex;
		public int numFLstIme;
		public int numFLstIel;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmNavDbstr");

			String itemtag = "ContitemIacWznmNavDbstr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstTbl = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstTbl", mask, NUMFLSTTBL);
				numFLstTco = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstTco", mask, NUMFLSTTCO);
				numFLstSbs = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstSbs", mask, NUMFLSTSBS);
				numFLstRel = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstRel", mask, NUMFLSTREL);
				numFLstVec = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstVec", mask, NUMFLSTVEC);
				numFLstVit = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstVit", mask, NUMFLSTVIT);
				numFLstChk = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstChk", mask, NUMFLSTCHK);
				numFLstStb = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstStb", mask, NUMFLSTSTB);
				numFLstIex = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstIex", mask, NUMFLSTIEX);
				numFLstIme = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstIme", mask, NUMFLSTIME);
				numFLstIel = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstIel", mask, NUMFLSTIEL);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmNavDbstr";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmNavDbstr";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstTbl", numFLstTbl);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstTco", numFLstTco);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstSbs", numFLstSbs);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstRel", numFLstRel);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstVec", numFLstVec);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstVit", numFLstVit);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstChk", numFLstChk);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstStb", numFLstStb);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstIex", numFLstIex);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstIme", numFLstIme);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstIel", numFLstIel);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstTbl == comp.numFLstTbl) items.add(NUMFLSTTBL);
			if (numFLstTco == comp.numFLstTco) items.add(NUMFLSTTCO);
			if (numFLstSbs == comp.numFLstSbs) items.add(NUMFLSTSBS);
			if (numFLstRel == comp.numFLstRel) items.add(NUMFLSTREL);
			if (numFLstVec == comp.numFLstVec) items.add(NUMFLSTVEC);
			if (numFLstVit == comp.numFLstVit) items.add(NUMFLSTVIT);
			if (numFLstChk == comp.numFLstChk) items.add(NUMFLSTCHK);
			if (numFLstStb == comp.numFLstStb) items.add(NUMFLSTSTB);
			if (numFLstIex == comp.numFLstIex) items.add(NUMFLSTIEX);
			if (numFLstIme == comp.numFLstIme) items.add(NUMFLSTIME);
			if (numFLstIel == comp.numFLstIel) items.add(NUMFLSTIEL);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTTBL, NUMFLSTTCO, NUMFLSTSBS, NUMFLSTREL, NUMFLSTVEC, NUMFLSTVIT, NUMFLSTCHK, NUMFLSTSTB, NUMFLSTIEX, NUMFLSTIME, NUMFLSTIEL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmNavDbstr)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTTBLALT = 2;
		public static final int LSTTCOALT = 3;
		public static final int LSTSBSALT = 4;
		public static final int LSTRELALT = 5;
		public static final int LSTVECALT = 6;
		public static final int LSTVITALT = 7;
		public static final int LSTCHKALT = 8;
		public static final int LSTSTBALT = 9;
		public static final int LSTIEXALT = 10;
		public static final int LSTIMEALT = 11;
		public static final int LSTIELALT = 12;
		public static final int LSTTBLNUMFIRSTDISP = 13;
		public static final int LSTTCONUMFIRSTDISP = 14;
		public static final int LSTSBSNUMFIRSTDISP = 15;
		public static final int LSTRELNUMFIRSTDISP = 16;
		public static final int LSTVECNUMFIRSTDISP = 17;
		public static final int LSTVITNUMFIRSTDISP = 18;
		public static final int LSTCHKNUMFIRSTDISP = 19;
		public static final int LSTSTBNUMFIRSTDISP = 20;
		public static final int LSTIEXNUMFIRSTDISP = 21;
		public static final int LSTIMENUMFIRSTDISP = 22;
		public static final int LSTIELNUMFIRSTDISP = 23;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstTblAlt
					, boolean LstTcoAlt
					, boolean LstSbsAlt
					, boolean LstRelAlt
					, boolean LstVecAlt
					, boolean LstVitAlt
					, boolean LstChkAlt
					, boolean LstStbAlt
					, boolean LstIexAlt
					, boolean LstImeAlt
					, boolean LstIelAlt
					, int LstTblNumFirstdisp
					, int LstTcoNumFirstdisp
					, int LstSbsNumFirstdisp
					, int LstRelNumFirstdisp
					, int LstVecNumFirstdisp
					, int LstVitNumFirstdisp
					, int LstChkNumFirstdisp
					, int LstStbNumFirstdisp
					, int LstIexNumFirstdisp
					, int LstImeNumFirstdisp
					, int LstIelNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstTblAlt = LstTblAlt;
			this.LstTcoAlt = LstTcoAlt;
			this.LstSbsAlt = LstSbsAlt;
			this.LstRelAlt = LstRelAlt;
			this.LstVecAlt = LstVecAlt;
			this.LstVitAlt = LstVitAlt;
			this.LstChkAlt = LstChkAlt;
			this.LstStbAlt = LstStbAlt;
			this.LstIexAlt = LstIexAlt;
			this.LstImeAlt = LstImeAlt;
			this.LstIelAlt = LstIelAlt;
			this.LstTblNumFirstdisp = LstTblNumFirstdisp;
			this.LstTcoNumFirstdisp = LstTcoNumFirstdisp;
			this.LstSbsNumFirstdisp = LstSbsNumFirstdisp;
			this.LstRelNumFirstdisp = LstRelNumFirstdisp;
			this.LstVecNumFirstdisp = LstVecNumFirstdisp;
			this.LstVitNumFirstdisp = LstVitNumFirstdisp;
			this.LstChkNumFirstdisp = LstChkNumFirstdisp;
			this.LstStbNumFirstdisp = LstStbNumFirstdisp;
			this.LstIexNumFirstdisp = LstIexNumFirstdisp;
			this.LstImeNumFirstdisp = LstImeNumFirstdisp;
			this.LstIelNumFirstdisp = LstIelNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTTBLALT, LSTTCOALT, LSTSBSALT, LSTRELALT, LSTVECALT, LSTVITALT, LSTCHKALT, LSTSTBALT, LSTIEXALT, LSTIMEALT, LSTIELALT, LSTTBLNUMFIRSTDISP, LSTTCONUMFIRSTDISP, LSTSBSNUMFIRSTDISP, LSTRELNUMFIRSTDISP, LSTVECNUMFIRSTDISP, LSTVITNUMFIRSTDISP, LSTCHKNUMFIRSTDISP, LSTSTBNUMFIRSTDISP, LSTIEXNUMFIRSTDISP, LSTIMENUMFIRSTDISP, LSTIELNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstTblAlt;
		public boolean LstTcoAlt;
		public boolean LstSbsAlt;
		public boolean LstRelAlt;
		public boolean LstVecAlt;
		public boolean LstVitAlt;
		public boolean LstChkAlt;
		public boolean LstStbAlt;
		public boolean LstIexAlt;
		public boolean LstImeAlt;
		public boolean LstIelAlt;
		public int LstTblNumFirstdisp;
		public int LstTcoNumFirstdisp;
		public int LstSbsNumFirstdisp;
		public int LstRelNumFirstdisp;
		public int LstVecNumFirstdisp;
		public int LstVitNumFirstdisp;
		public int LstChkNumFirstdisp;
		public int LstStbNumFirstdisp;
		public int LstIexNumFirstdisp;
		public int LstImeNumFirstdisp;
		public int LstIelNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmNavDbstr");

			String itemtag = "StatitemAppWznmNavDbstr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstTblAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTblAlt", mask, LSTTBLALT);
				LstTcoAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTcoAlt", mask, LSTTCOALT);
				LstSbsAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSbsAlt", mask, LSTSBSALT);
				LstRelAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRelAlt", mask, LSTRELALT);
				LstVecAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVecAlt", mask, LSTVECALT);
				LstVitAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVitAlt", mask, LSTVITALT);
				LstChkAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstChkAlt", mask, LSTCHKALT);
				LstStbAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstStbAlt", mask, LSTSTBALT);
				LstIexAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIexAlt", mask, LSTIEXALT);
				LstImeAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstImeAlt", mask, LSTIMEALT);
				LstIelAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIelAlt", mask, LSTIELALT);
				LstTblNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTblNumFirstdisp", mask, LSTTBLNUMFIRSTDISP);
				LstTcoNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTcoNumFirstdisp", mask, LSTTCONUMFIRSTDISP);
				LstSbsNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSbsNumFirstdisp", mask, LSTSBSNUMFIRSTDISP);
				LstRelNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRelNumFirstdisp", mask, LSTRELNUMFIRSTDISP);
				LstVecNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVecNumFirstdisp", mask, LSTVECNUMFIRSTDISP);
				LstVitNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVitNumFirstdisp", mask, LSTVITNUMFIRSTDISP);
				LstChkNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstChkNumFirstdisp", mask, LSTCHKNUMFIRSTDISP);
				LstStbNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstStbNumFirstdisp", mask, LSTSTBNUMFIRSTDISP);
				LstIexNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIexNumFirstdisp", mask, LSTIEXNUMFIRSTDISP);
				LstImeNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstImeNumFirstdisp", mask, LSTIMENUMFIRSTDISP);
				LstIelNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIelNumFirstdisp", mask, LSTIELNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstTblAlt == comp.LstTblAlt) items.add(LSTTBLALT);
			if (LstTcoAlt == comp.LstTcoAlt) items.add(LSTTCOALT);
			if (LstSbsAlt == comp.LstSbsAlt) items.add(LSTSBSALT);
			if (LstRelAlt == comp.LstRelAlt) items.add(LSTRELALT);
			if (LstVecAlt == comp.LstVecAlt) items.add(LSTVECALT);
			if (LstVitAlt == comp.LstVitAlt) items.add(LSTVITALT);
			if (LstChkAlt == comp.LstChkAlt) items.add(LSTCHKALT);
			if (LstStbAlt == comp.LstStbAlt) items.add(LSTSTBALT);
			if (LstIexAlt == comp.LstIexAlt) items.add(LSTIEXALT);
			if (LstImeAlt == comp.LstImeAlt) items.add(LSTIMEALT);
			if (LstIelAlt == comp.LstIelAlt) items.add(LSTIELALT);
			if (LstTblNumFirstdisp == comp.LstTblNumFirstdisp) items.add(LSTTBLNUMFIRSTDISP);
			if (LstTcoNumFirstdisp == comp.LstTcoNumFirstdisp) items.add(LSTTCONUMFIRSTDISP);
			if (LstSbsNumFirstdisp == comp.LstSbsNumFirstdisp) items.add(LSTSBSNUMFIRSTDISP);
			if (LstRelNumFirstdisp == comp.LstRelNumFirstdisp) items.add(LSTRELNUMFIRSTDISP);
			if (LstVecNumFirstdisp == comp.LstVecNumFirstdisp) items.add(LSTVECNUMFIRSTDISP);
			if (LstVitNumFirstdisp == comp.LstVitNumFirstdisp) items.add(LSTVITNUMFIRSTDISP);
			if (LstChkNumFirstdisp == comp.LstChkNumFirstdisp) items.add(LSTCHKNUMFIRSTDISP);
			if (LstStbNumFirstdisp == comp.LstStbNumFirstdisp) items.add(LSTSTBNUMFIRSTDISP);
			if (LstIexNumFirstdisp == comp.LstIexNumFirstdisp) items.add(LSTIEXNUMFIRSTDISP);
			if (LstImeNumFirstdisp == comp.LstImeNumFirstdisp) items.add(LSTIMENUMFIRSTDISP);
			if (LstIelNumFirstdisp == comp.LstIelNumFirstdisp) items.add(LSTIELNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTTBLALT, LSTTCOALT, LSTSBSALT, LSTRELALT, LSTVECALT, LSTVITALT, LSTCHKALT, LSTSTBALT, LSTIEXALT, LSTIMEALT, LSTIELALT, LSTTBLNUMFIRSTDISP, LSTTCONUMFIRSTDISP, LSTSBSNUMFIRSTDISP, LSTRELNUMFIRSTDISP, LSTVECNUMFIRSTDISP, LSTVITNUMFIRSTDISP, LSTCHKNUMFIRSTDISP, LSTSTBNUMFIRSTDISP, LSTIEXNUMFIRSTDISP, LSTIMENUMFIRSTDISP, LSTIELNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmNavDbstr)
	  */
	public class StatShr extends Block {

		public static final int LSTTBLAVAIL = 1;
		public static final int BUTTBLVIEWACTIVE = 2;
		public static final int BUTTBLNEWCRDACTIVE = 3;
		public static final int LSTTCOAVAIL = 4;
		public static final int BUTTCOVIEWACTIVE = 5;
		public static final int BUTTCONEWCRDACTIVE = 6;
		public static final int LSTSBSAVAIL = 7;
		public static final int BUTSBSVIEWACTIVE = 8;
		public static final int BUTSBSNEWCRDACTIVE = 9;
		public static final int LSTRELAVAIL = 10;
		public static final int BUTRELVIEWACTIVE = 11;
		public static final int BUTRELNEWCRDACTIVE = 12;
		public static final int LSTVECAVAIL = 13;
		public static final int BUTVECVIEWACTIVE = 14;
		public static final int BUTVECNEWCRDACTIVE = 15;
		public static final int LSTVITAVAIL = 16;
		public static final int BUTVITVIEWACTIVE = 17;
		public static final int BUTVITNEWCRDACTIVE = 18;
		public static final int LSTCHKAVAIL = 19;
		public static final int BUTCHKVIEWACTIVE = 20;
		public static final int BUTCHKNEWCRDACTIVE = 21;
		public static final int LSTSTBAVAIL = 22;
		public static final int BUTSTBVIEWACTIVE = 23;
		public static final int BUTSTBNEWCRDACTIVE = 24;
		public static final int LSTIEXAVAIL = 25;
		public static final int BUTIEXVIEWACTIVE = 26;
		public static final int BUTIEXNEWCRDACTIVE = 27;
		public static final int LSTIMEAVAIL = 28;
		public static final int BUTIMEVIEWACTIVE = 29;
		public static final int BUTIMENEWCRDACTIVE = 30;
		public static final int LSTIELAVAIL = 31;
		public static final int BUTIELVIEWACTIVE = 32;

		public StatShr(
					boolean LstTblAvail
					, boolean ButTblViewActive
					, boolean ButTblNewcrdActive
					, boolean LstTcoAvail
					, boolean ButTcoViewActive
					, boolean ButTcoNewcrdActive
					, boolean LstSbsAvail
					, boolean ButSbsViewActive
					, boolean ButSbsNewcrdActive
					, boolean LstRelAvail
					, boolean ButRelViewActive
					, boolean ButRelNewcrdActive
					, boolean LstVecAvail
					, boolean ButVecViewActive
					, boolean ButVecNewcrdActive
					, boolean LstVitAvail
					, boolean ButVitViewActive
					, boolean ButVitNewcrdActive
					, boolean LstChkAvail
					, boolean ButChkViewActive
					, boolean ButChkNewcrdActive
					, boolean LstStbAvail
					, boolean ButStbViewActive
					, boolean ButStbNewcrdActive
					, boolean LstIexAvail
					, boolean ButIexViewActive
					, boolean ButIexNewcrdActive
					, boolean LstImeAvail
					, boolean ButImeViewActive
					, boolean ButImeNewcrdActive
					, boolean LstIelAvail
					, boolean ButIelViewActive
				) {
			this.LstTblAvail = LstTblAvail;
			this.ButTblViewActive = ButTblViewActive;
			this.ButTblNewcrdActive = ButTblNewcrdActive;
			this.LstTcoAvail = LstTcoAvail;
			this.ButTcoViewActive = ButTcoViewActive;
			this.ButTcoNewcrdActive = ButTcoNewcrdActive;
			this.LstSbsAvail = LstSbsAvail;
			this.ButSbsViewActive = ButSbsViewActive;
			this.ButSbsNewcrdActive = ButSbsNewcrdActive;
			this.LstRelAvail = LstRelAvail;
			this.ButRelViewActive = ButRelViewActive;
			this.ButRelNewcrdActive = ButRelNewcrdActive;
			this.LstVecAvail = LstVecAvail;
			this.ButVecViewActive = ButVecViewActive;
			this.ButVecNewcrdActive = ButVecNewcrdActive;
			this.LstVitAvail = LstVitAvail;
			this.ButVitViewActive = ButVitViewActive;
			this.ButVitNewcrdActive = ButVitNewcrdActive;
			this.LstChkAvail = LstChkAvail;
			this.ButChkViewActive = ButChkViewActive;
			this.ButChkNewcrdActive = ButChkNewcrdActive;
			this.LstStbAvail = LstStbAvail;
			this.ButStbViewActive = ButStbViewActive;
			this.ButStbNewcrdActive = ButStbNewcrdActive;
			this.LstIexAvail = LstIexAvail;
			this.ButIexViewActive = ButIexViewActive;
			this.ButIexNewcrdActive = ButIexNewcrdActive;
			this.LstImeAvail = LstImeAvail;
			this.ButImeViewActive = ButImeViewActive;
			this.ButImeNewcrdActive = ButImeNewcrdActive;
			this.LstIelAvail = LstIelAvail;
			this.ButIelViewActive = ButIelViewActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTTBLAVAIL, BUTTBLVIEWACTIVE, BUTTBLNEWCRDACTIVE, LSTTCOAVAIL, BUTTCOVIEWACTIVE, BUTTCONEWCRDACTIVE, LSTSBSAVAIL, BUTSBSVIEWACTIVE, BUTSBSNEWCRDACTIVE, LSTRELAVAIL, BUTRELVIEWACTIVE, BUTRELNEWCRDACTIVE, LSTVECAVAIL, BUTVECVIEWACTIVE, BUTVECNEWCRDACTIVE, LSTVITAVAIL, BUTVITVIEWACTIVE, BUTVITNEWCRDACTIVE, LSTCHKAVAIL, BUTCHKVIEWACTIVE, BUTCHKNEWCRDACTIVE, LSTSTBAVAIL, BUTSTBVIEWACTIVE, BUTSTBNEWCRDACTIVE, LSTIEXAVAIL, BUTIEXVIEWACTIVE, BUTIEXNEWCRDACTIVE, LSTIMEAVAIL, BUTIMEVIEWACTIVE, BUTIMENEWCRDACTIVE, LSTIELAVAIL, BUTIELVIEWACTIVE));
		};

		public boolean LstTblAvail;
		public boolean ButTblViewActive;
		public boolean ButTblNewcrdActive;
		public boolean LstTcoAvail;
		public boolean ButTcoViewActive;
		public boolean ButTcoNewcrdActive;
		public boolean LstSbsAvail;
		public boolean ButSbsViewActive;
		public boolean ButSbsNewcrdActive;
		public boolean LstRelAvail;
		public boolean ButRelViewActive;
		public boolean ButRelNewcrdActive;
		public boolean LstVecAvail;
		public boolean ButVecViewActive;
		public boolean ButVecNewcrdActive;
		public boolean LstVitAvail;
		public boolean ButVitViewActive;
		public boolean ButVitNewcrdActive;
		public boolean LstChkAvail;
		public boolean ButChkViewActive;
		public boolean ButChkNewcrdActive;
		public boolean LstStbAvail;
		public boolean ButStbViewActive;
		public boolean ButStbNewcrdActive;
		public boolean LstIexAvail;
		public boolean ButIexViewActive;
		public boolean ButIexNewcrdActive;
		public boolean LstImeAvail;
		public boolean ButImeViewActive;
		public boolean ButImeNewcrdActive;
		public boolean LstIelAvail;
		public boolean ButIelViewActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmNavDbstr");

			String itemtag = "StatitemShrWznmNavDbstr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstTblAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTblAvail", mask, LSTTBLAVAIL);
				ButTblViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTblViewActive", mask, BUTTBLVIEWACTIVE);
				ButTblNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTblNewcrdActive", mask, BUTTBLNEWCRDACTIVE);
				LstTcoAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTcoAvail", mask, LSTTCOAVAIL);
				ButTcoViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTcoViewActive", mask, BUTTCOVIEWACTIVE);
				ButTcoNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTcoNewcrdActive", mask, BUTTCONEWCRDACTIVE);
				LstSbsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSbsAvail", mask, LSTSBSAVAIL);
				ButSbsViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSbsViewActive", mask, BUTSBSVIEWACTIVE);
				ButSbsNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSbsNewcrdActive", mask, BUTSBSNEWCRDACTIVE);
				LstRelAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRelAvail", mask, LSTRELAVAIL);
				ButRelViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRelViewActive", mask, BUTRELVIEWACTIVE);
				ButRelNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRelNewcrdActive", mask, BUTRELNEWCRDACTIVE);
				LstVecAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVecAvail", mask, LSTVECAVAIL);
				ButVecViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVecViewActive", mask, BUTVECVIEWACTIVE);
				ButVecNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVecNewcrdActive", mask, BUTVECNEWCRDACTIVE);
				LstVitAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVitAvail", mask, LSTVITAVAIL);
				ButVitViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVitViewActive", mask, BUTVITVIEWACTIVE);
				ButVitNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVitNewcrdActive", mask, BUTVITNEWCRDACTIVE);
				LstChkAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstChkAvail", mask, LSTCHKAVAIL);
				ButChkViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButChkViewActive", mask, BUTCHKVIEWACTIVE);
				ButChkNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButChkNewcrdActive", mask, BUTCHKNEWCRDACTIVE);
				LstStbAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstStbAvail", mask, LSTSTBAVAIL);
				ButStbViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStbViewActive", mask, BUTSTBVIEWACTIVE);
				ButStbNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStbNewcrdActive", mask, BUTSTBNEWCRDACTIVE);
				LstIexAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIexAvail", mask, LSTIEXAVAIL);
				ButIexViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButIexViewActive", mask, BUTIEXVIEWACTIVE);
				ButIexNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButIexNewcrdActive", mask, BUTIEXNEWCRDACTIVE);
				LstImeAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstImeAvail", mask, LSTIMEAVAIL);
				ButImeViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButImeViewActive", mask, BUTIMEVIEWACTIVE);
				ButImeNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButImeNewcrdActive", mask, BUTIMENEWCRDACTIVE);
				LstIelAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIelAvail", mask, LSTIELAVAIL);
				ButIelViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButIelViewActive", mask, BUTIELVIEWACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstTblAvail == comp.LstTblAvail) items.add(LSTTBLAVAIL);
			if (ButTblViewActive == comp.ButTblViewActive) items.add(BUTTBLVIEWACTIVE);
			if (ButTblNewcrdActive == comp.ButTblNewcrdActive) items.add(BUTTBLNEWCRDACTIVE);
			if (LstTcoAvail == comp.LstTcoAvail) items.add(LSTTCOAVAIL);
			if (ButTcoViewActive == comp.ButTcoViewActive) items.add(BUTTCOVIEWACTIVE);
			if (ButTcoNewcrdActive == comp.ButTcoNewcrdActive) items.add(BUTTCONEWCRDACTIVE);
			if (LstSbsAvail == comp.LstSbsAvail) items.add(LSTSBSAVAIL);
			if (ButSbsViewActive == comp.ButSbsViewActive) items.add(BUTSBSVIEWACTIVE);
			if (ButSbsNewcrdActive == comp.ButSbsNewcrdActive) items.add(BUTSBSNEWCRDACTIVE);
			if (LstRelAvail == comp.LstRelAvail) items.add(LSTRELAVAIL);
			if (ButRelViewActive == comp.ButRelViewActive) items.add(BUTRELVIEWACTIVE);
			if (ButRelNewcrdActive == comp.ButRelNewcrdActive) items.add(BUTRELNEWCRDACTIVE);
			if (LstVecAvail == comp.LstVecAvail) items.add(LSTVECAVAIL);
			if (ButVecViewActive == comp.ButVecViewActive) items.add(BUTVECVIEWACTIVE);
			if (ButVecNewcrdActive == comp.ButVecNewcrdActive) items.add(BUTVECNEWCRDACTIVE);
			if (LstVitAvail == comp.LstVitAvail) items.add(LSTVITAVAIL);
			if (ButVitViewActive == comp.ButVitViewActive) items.add(BUTVITVIEWACTIVE);
			if (ButVitNewcrdActive == comp.ButVitNewcrdActive) items.add(BUTVITNEWCRDACTIVE);
			if (LstChkAvail == comp.LstChkAvail) items.add(LSTCHKAVAIL);
			if (ButChkViewActive == comp.ButChkViewActive) items.add(BUTCHKVIEWACTIVE);
			if (ButChkNewcrdActive == comp.ButChkNewcrdActive) items.add(BUTCHKNEWCRDACTIVE);
			if (LstStbAvail == comp.LstStbAvail) items.add(LSTSTBAVAIL);
			if (ButStbViewActive == comp.ButStbViewActive) items.add(BUTSTBVIEWACTIVE);
			if (ButStbNewcrdActive == comp.ButStbNewcrdActive) items.add(BUTSTBNEWCRDACTIVE);
			if (LstIexAvail == comp.LstIexAvail) items.add(LSTIEXAVAIL);
			if (ButIexViewActive == comp.ButIexViewActive) items.add(BUTIEXVIEWACTIVE);
			if (ButIexNewcrdActive == comp.ButIexNewcrdActive) items.add(BUTIEXNEWCRDACTIVE);
			if (LstImeAvail == comp.LstImeAvail) items.add(LSTIMEAVAIL);
			if (ButImeViewActive == comp.ButImeViewActive) items.add(BUTIMEVIEWACTIVE);
			if (ButImeNewcrdActive == comp.ButImeNewcrdActive) items.add(BUTIMENEWCRDACTIVE);
			if (LstIelAvail == comp.LstIelAvail) items.add(LSTIELAVAIL);
			if (ButIelViewActive == comp.ButIelViewActive) items.add(BUTIELVIEWACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTTBLAVAIL, BUTTBLVIEWACTIVE, BUTTBLNEWCRDACTIVE, LSTTCOAVAIL, BUTTCOVIEWACTIVE, BUTTCONEWCRDACTIVE, LSTSBSAVAIL, BUTSBSVIEWACTIVE, BUTSBSNEWCRDACTIVE, LSTRELAVAIL, BUTRELVIEWACTIVE, BUTRELNEWCRDACTIVE, LSTVECAVAIL, BUTVECVIEWACTIVE, BUTVECNEWCRDACTIVE, LSTVITAVAIL, BUTVITVIEWACTIVE, BUTVITNEWCRDACTIVE, LSTCHKAVAIL, BUTCHKVIEWACTIVE, BUTCHKNEWCRDACTIVE, LSTSTBAVAIL, BUTSTBVIEWACTIVE, BUTSTBNEWCRDACTIVE, LSTIEXAVAIL, BUTIEXVIEWACTIVE, BUTIEXNEWCRDACTIVE, LSTIMEAVAIL, BUTIMEVIEWACTIVE, BUTIMENEWCRDACTIVE, LSTIELAVAIL, BUTIELVIEWACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmNavDbstr)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTTBL = 2;
		public static final int CPTTCO = 3;
		public static final int CPTSBS = 4;
		public static final int CPTREL = 5;
		public static final int CPTVEC = 6;
		public static final int CPTVIT = 7;
		public static final int CPTCHK = 8;
		public static final int CPTSTB = 9;
		public static final int CPTIEX = 10;
		public static final int CPTIME = 11;
		public static final int CPTIEL = 12;

		public Tag(
					String Cpt
					, String CptTbl
					, String CptTco
					, String CptSbs
					, String CptRel
					, String CptVec
					, String CptVit
					, String CptChk
					, String CptStb
					, String CptIex
					, String CptIme
					, String CptIel
				) {
			this.Cpt = Cpt;
			this.CptTbl = CptTbl;
			this.CptTco = CptTco;
			this.CptSbs = CptSbs;
			this.CptRel = CptRel;
			this.CptVec = CptVec;
			this.CptVit = CptVit;
			this.CptChk = CptChk;
			this.CptStb = CptStb;
			this.CptIex = CptIex;
			this.CptIme = CptIme;
			this.CptIel = CptIel;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTTBL, CPTTCO, CPTSBS, CPTREL, CPTVEC, CPTVIT, CPTCHK, CPTSTB, CPTIEX, CPTIME, CPTIEL));
		};

		public String Cpt;
		public String CptTbl;
		public String CptTco;
		public String CptSbs;
		public String CptRel;
		public String CptVec;
		public String CptVit;
		public String CptChk;
		public String CptStb;
		public String CptIex;
		public String CptIme;
		public String CptIel;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmNavDbstr");

			String itemtag = "TagitemWznmNavDbstr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTbl", mask, CPTTBL);
				CptTco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTco", mask, CPTTCO);
				CptSbs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSbs", mask, CPTSBS);
				CptRel = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptRel", mask, CPTREL);
				CptVec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVec", mask, CPTVEC);
				CptVit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVit", mask, CPTVIT);
				CptChk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptChk", mask, CPTCHK);
				CptStb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptStb", mask, CPTSTB);
				CptIex = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIex", mask, CPTIEX);
				CptIme = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIme", mask, CPTIME);
				CptIel = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIel", mask, CPTIEL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptTbl.equals(comp.CptTbl)) items.add(CPTTBL);
			if (CptTco.equals(comp.CptTco)) items.add(CPTTCO);
			if (CptSbs.equals(comp.CptSbs)) items.add(CPTSBS);
			if (CptRel.equals(comp.CptRel)) items.add(CPTREL);
			if (CptVec.equals(comp.CptVec)) items.add(CPTVEC);
			if (CptVit.equals(comp.CptVit)) items.add(CPTVIT);
			if (CptChk.equals(comp.CptChk)) items.add(CPTCHK);
			if (CptStb.equals(comp.CptStb)) items.add(CPTSTB);
			if (CptIex.equals(comp.CptIex)) items.add(CPTIEX);
			if (CptIme.equals(comp.CptIme)) items.add(CPTIME);
			if (CptIel.equals(comp.CptIel)) items.add(CPTIEL);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTTBL, CPTTCO, CPTSBS, CPTREL, CPTVEC, CPTVIT, CPTCHK, CPTSTB, CPTIEX, CPTIME, CPTIEL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmNavDbstrData)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVDBSTRDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavDbstrData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmNavDbstrDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVDBSTRDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavDbstrDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmNavDbstrData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTCHK = 3;
		public static final int FEEDFLSTIEL = 4;
		public static final int FEEDFLSTIEX = 5;
		public static final int FEEDFLSTIME = 6;
		public static final int FEEDFLSTREL = 7;
		public static final int FEEDFLSTSBS = 8;
		public static final int FEEDFLSTSTB = 9;
		public static final int FEEDFLSTTBL = 10;
		public static final int FEEDFLSTTCO = 11;
		public static final int FEEDFLSTVEC = 12;
		public static final int FEEDFLSTVIT = 13;
		public static final int STATAPP = 14;
		public static final int STATSHR = 15;
		public static final int TAG = 16;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMNAVDBSTRDATA);

			contiac = new ContIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			feedFLstChk = new Feed("FeedFLstChk");
			feedFLstIel = new Feed("FeedFLstIel");
			feedFLstIex = new Feed("FeedFLstIex");
			feedFLstIme = new Feed("FeedFLstIme");
			feedFLstRel = new Feed("FeedFLstRel");
			feedFLstSbs = new Feed("FeedFLstSbs");
			feedFLstStb = new Feed("FeedFLstStb");
			feedFLstTbl = new Feed("FeedFLstTbl");
			feedFLstTco = new Feed("FeedFLstTco");
			feedFLstVec = new Feed("FeedFLstVec");
			feedFLstVit = new Feed("FeedFLstVit");
			statapp = new StatApp(0, false, false, false, false, false, false, false, false, false, false, false, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstChk;
		public Feed feedFLstIel;
		public Feed feedFLstIex;
		public Feed feedFLstIme;
		public Feed feedFLstRel;
		public Feed feedFLstSbs;
		public Feed feedFLstStb;
		public Feed feedFLstTbl;
		public Feed feedFLstTco;
		public Feed feedFLstVec;
		public Feed feedFLstVit;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTCHK)) ss.add("feedFLstChk");
			if (has(FEEDFLSTIEL)) ss.add("feedFLstIel");
			if (has(FEEDFLSTIEX)) ss.add("feedFLstIex");
			if (has(FEEDFLSTIME)) ss.add("feedFLstIme");
			if (has(FEEDFLSTREL)) ss.add("feedFLstRel");
			if (has(FEEDFLSTSBS)) ss.add("feedFLstSbs");
			if (has(FEEDFLSTSTB)) ss.add("feedFLstStb");
			if (has(FEEDFLSTTBL)) ss.add("feedFLstTbl");
			if (has(FEEDFLSTTCO)) ss.add("feedFLstTco");
			if (has(FEEDFLSTVEC)) ss.add("feedFLstVec");
			if (has(FEEDFLSTVIT)) ss.add("feedFLstVit");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmNavDbstrData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstChk.readXML(doc, basexpath, true)) add(FEEDFLSTCHK);
				if (feedFLstIel.readXML(doc, basexpath, true)) add(FEEDFLSTIEL);
				if (feedFLstIex.readXML(doc, basexpath, true)) add(FEEDFLSTIEX);
				if (feedFLstIme.readXML(doc, basexpath, true)) add(FEEDFLSTIME);
				if (feedFLstRel.readXML(doc, basexpath, true)) add(FEEDFLSTREL);
				if (feedFLstSbs.readXML(doc, basexpath, true)) add(FEEDFLSTSBS);
				if (feedFLstStb.readXML(doc, basexpath, true)) add(FEEDFLSTSTB);
				if (feedFLstTbl.readXML(doc, basexpath, true)) add(FEEDFLSTTBL);
				if (feedFLstTco.readXML(doc, basexpath, true)) add(FEEDFLSTTCO);
				if (feedFLstVec.readXML(doc, basexpath, true)) add(FEEDFLSTVEC);
				if (feedFLstVit.readXML(doc, basexpath, true)) add(FEEDFLSTVIT);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				feedFLstChk = new Feed("FeedFLstChk");
				feedFLstIel = new Feed("FeedFLstIel");
				feedFLstIex = new Feed("FeedFLstIex");
				feedFLstIme = new Feed("FeedFLstIme");
				feedFLstRel = new Feed("FeedFLstRel");
				feedFLstSbs = new Feed("FeedFLstSbs");
				feedFLstStb = new Feed("FeedFLstStb");
				feedFLstTbl = new Feed("FeedFLstTbl");
				feedFLstTco = new Feed("FeedFLstTco");
				feedFLstVec = new Feed("FeedFLstVec");
				feedFLstVit = new Feed("FeedFLstVit");
				statapp = new StatApp(0, false, false, false, false, false, false, false, false, false, false, false, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

