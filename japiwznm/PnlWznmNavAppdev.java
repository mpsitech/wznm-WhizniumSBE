/**
  * \file PnlWznmNavAppdev.java
  * Java API code for job PnlWznmNavAppdev
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmNavAppdev {
	/**
		* VecVDo (full: VecVWznmNavAppdevDo)
		*/
	public static class VecVDo {

		public static final int BUTAPPVIEWCLICK = 1;
		public static final int BUTAPPNEWCRDCLICK = 2;
		public static final int BUTRTJVIEWCLICK = 3;
		public static final int BUTRTJNEWCRDCLICK = 4;
		public static final int BUTEVTVIEWCLICK = 5;
		public static final int BUTEVTNEWCRDCLICK = 6;
		public static final int BUTSEQVIEWCLICK = 7;
		public static final int BUTSEQNEWCRDCLICK = 8;
		public static final int BUTSTEVIEWCLICK = 9;
		public static final int BUTSTENEWCRDCLICK = 10;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butappviewclick")) return BUTAPPVIEWCLICK;
			if (s.equals("butappnewcrdclick")) return BUTAPPNEWCRDCLICK;
			if (s.equals("butrtjviewclick")) return BUTRTJVIEWCLICK;
			if (s.equals("butrtjnewcrdclick")) return BUTRTJNEWCRDCLICK;
			if (s.equals("butevtviewclick")) return BUTEVTVIEWCLICK;
			if (s.equals("butevtnewcrdclick")) return BUTEVTNEWCRDCLICK;
			if (s.equals("butseqviewclick")) return BUTSEQVIEWCLICK;
			if (s.equals("butseqnewcrdclick")) return BUTSEQNEWCRDCLICK;
			if (s.equals("butsteviewclick")) return BUTSTEVIEWCLICK;
			if (s.equals("butstenewcrdclick")) return BUTSTENEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTAPPVIEWCLICK) return("ButAppViewClick");
			if (ix == BUTAPPNEWCRDCLICK) return("ButAppNewcrdClick");
			if (ix == BUTRTJVIEWCLICK) return("ButRtjViewClick");
			if (ix == BUTRTJNEWCRDCLICK) return("ButRtjNewcrdClick");
			if (ix == BUTEVTVIEWCLICK) return("ButEvtViewClick");
			if (ix == BUTEVTNEWCRDCLICK) return("ButEvtNewcrdClick");
			if (ix == BUTSEQVIEWCLICK) return("ButSeqViewClick");
			if (ix == BUTSEQNEWCRDCLICK) return("ButSeqNewcrdClick");
			if (ix == BUTSTEVIEWCLICK) return("ButSteViewClick");
			if (ix == BUTSTENEWCRDCLICK) return("ButSteNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmNavAppdev)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTAPP = 1;
		public static final int NUMFLSTRTJ = 2;
		public static final int NUMFLSTEVT = 3;
		public static final int NUMFLSTSEQ = 4;
		public static final int NUMFLSTSTE = 5;

		public ContIac(
					int numFLstApp
					, int numFLstRtj
					, int numFLstEvt
					, int numFLstSeq
					, int numFLstSte
				) {
			this.numFLstApp = numFLstApp;
			this.numFLstRtj = numFLstRtj;
			this.numFLstEvt = numFLstEvt;
			this.numFLstSeq = numFLstSeq;
			this.numFLstSte = numFLstSte;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTAPP, NUMFLSTRTJ, NUMFLSTEVT, NUMFLSTSEQ, NUMFLSTSTE));
		};

		public int numFLstApp;
		public int numFLstRtj;
		public int numFLstEvt;
		public int numFLstSeq;
		public int numFLstSte;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmNavAppdev");

			String itemtag = "ContitemIacWznmNavAppdev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstApp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstApp", mask, NUMFLSTAPP);
				numFLstRtj = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstRtj", mask, NUMFLSTRTJ);
				numFLstEvt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstEvt", mask, NUMFLSTEVT);
				numFLstSeq = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstSeq", mask, NUMFLSTSEQ);
				numFLstSte = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstSte", mask, NUMFLSTSTE);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmNavAppdev";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmNavAppdev";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstApp", numFLstApp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstRtj", numFLstRtj);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstEvt", numFLstEvt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstSeq", numFLstSeq);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstSte", numFLstSte);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstApp == comp.numFLstApp) items.add(NUMFLSTAPP);
			if (numFLstRtj == comp.numFLstRtj) items.add(NUMFLSTRTJ);
			if (numFLstEvt == comp.numFLstEvt) items.add(NUMFLSTEVT);
			if (numFLstSeq == comp.numFLstSeq) items.add(NUMFLSTSEQ);
			if (numFLstSte == comp.numFLstSte) items.add(NUMFLSTSTE);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTAPP, NUMFLSTRTJ, NUMFLSTEVT, NUMFLSTSEQ, NUMFLSTSTE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmNavAppdev)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTAPPALT = 2;
		public static final int LSTRTJALT = 3;
		public static final int LSTEVTALT = 4;
		public static final int LSTSEQALT = 5;
		public static final int LSTSTEALT = 6;
		public static final int LSTAPPNUMFIRSTDISP = 7;
		public static final int LSTRTJNUMFIRSTDISP = 8;
		public static final int LSTEVTNUMFIRSTDISP = 9;
		public static final int LSTSEQNUMFIRSTDISP = 10;
		public static final int LSTSTENUMFIRSTDISP = 11;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstAppAlt
					, boolean LstRtjAlt
					, boolean LstEvtAlt
					, boolean LstSeqAlt
					, boolean LstSteAlt
					, int LstAppNumFirstdisp
					, int LstRtjNumFirstdisp
					, int LstEvtNumFirstdisp
					, int LstSeqNumFirstdisp
					, int LstSteNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstAppAlt = LstAppAlt;
			this.LstRtjAlt = LstRtjAlt;
			this.LstEvtAlt = LstEvtAlt;
			this.LstSeqAlt = LstSeqAlt;
			this.LstSteAlt = LstSteAlt;
			this.LstAppNumFirstdisp = LstAppNumFirstdisp;
			this.LstRtjNumFirstdisp = LstRtjNumFirstdisp;
			this.LstEvtNumFirstdisp = LstEvtNumFirstdisp;
			this.LstSeqNumFirstdisp = LstSeqNumFirstdisp;
			this.LstSteNumFirstdisp = LstSteNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTAPPALT, LSTRTJALT, LSTEVTALT, LSTSEQALT, LSTSTEALT, LSTAPPNUMFIRSTDISP, LSTRTJNUMFIRSTDISP, LSTEVTNUMFIRSTDISP, LSTSEQNUMFIRSTDISP, LSTSTENUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstAppAlt;
		public boolean LstRtjAlt;
		public boolean LstEvtAlt;
		public boolean LstSeqAlt;
		public boolean LstSteAlt;
		public int LstAppNumFirstdisp;
		public int LstRtjNumFirstdisp;
		public int LstEvtNumFirstdisp;
		public int LstSeqNumFirstdisp;
		public int LstSteNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmNavAppdev");

			String itemtag = "StatitemAppWznmNavAppdev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstAppAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstAppAlt", mask, LSTAPPALT);
				LstRtjAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRtjAlt", mask, LSTRTJALT);
				LstEvtAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstEvtAlt", mask, LSTEVTALT);
				LstSeqAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSeqAlt", mask, LSTSEQALT);
				LstSteAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSteAlt", mask, LSTSTEALT);
				LstAppNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstAppNumFirstdisp", mask, LSTAPPNUMFIRSTDISP);
				LstRtjNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRtjNumFirstdisp", mask, LSTRTJNUMFIRSTDISP);
				LstEvtNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstEvtNumFirstdisp", mask, LSTEVTNUMFIRSTDISP);
				LstSeqNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSeqNumFirstdisp", mask, LSTSEQNUMFIRSTDISP);
				LstSteNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSteNumFirstdisp", mask, LSTSTENUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstAppAlt == comp.LstAppAlt) items.add(LSTAPPALT);
			if (LstRtjAlt == comp.LstRtjAlt) items.add(LSTRTJALT);
			if (LstEvtAlt == comp.LstEvtAlt) items.add(LSTEVTALT);
			if (LstSeqAlt == comp.LstSeqAlt) items.add(LSTSEQALT);
			if (LstSteAlt == comp.LstSteAlt) items.add(LSTSTEALT);
			if (LstAppNumFirstdisp == comp.LstAppNumFirstdisp) items.add(LSTAPPNUMFIRSTDISP);
			if (LstRtjNumFirstdisp == comp.LstRtjNumFirstdisp) items.add(LSTRTJNUMFIRSTDISP);
			if (LstEvtNumFirstdisp == comp.LstEvtNumFirstdisp) items.add(LSTEVTNUMFIRSTDISP);
			if (LstSeqNumFirstdisp == comp.LstSeqNumFirstdisp) items.add(LSTSEQNUMFIRSTDISP);
			if (LstSteNumFirstdisp == comp.LstSteNumFirstdisp) items.add(LSTSTENUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTAPPALT, LSTRTJALT, LSTEVTALT, LSTSEQALT, LSTSTEALT, LSTAPPNUMFIRSTDISP, LSTRTJNUMFIRSTDISP, LSTEVTNUMFIRSTDISP, LSTSEQNUMFIRSTDISP, LSTSTENUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmNavAppdev)
	  */
	public class StatShr extends Block {

		public static final int LSTAPPAVAIL = 1;
		public static final int BUTAPPVIEWACTIVE = 2;
		public static final int LSTRTJAVAIL = 3;
		public static final int BUTRTJVIEWACTIVE = 4;
		public static final int BUTRTJNEWCRDACTIVE = 5;
		public static final int LSTEVTAVAIL = 6;
		public static final int BUTEVTVIEWACTIVE = 7;
		public static final int BUTEVTNEWCRDACTIVE = 8;
		public static final int LSTSEQAVAIL = 9;
		public static final int BUTSEQVIEWACTIVE = 10;
		public static final int BUTSEQNEWCRDACTIVE = 11;
		public static final int LSTSTEAVAIL = 12;
		public static final int BUTSTEVIEWACTIVE = 13;
		public static final int BUTSTENEWCRDACTIVE = 14;

		public StatShr(
					boolean LstAppAvail
					, boolean ButAppViewActive
					, boolean LstRtjAvail
					, boolean ButRtjViewActive
					, boolean ButRtjNewcrdActive
					, boolean LstEvtAvail
					, boolean ButEvtViewActive
					, boolean ButEvtNewcrdActive
					, boolean LstSeqAvail
					, boolean ButSeqViewActive
					, boolean ButSeqNewcrdActive
					, boolean LstSteAvail
					, boolean ButSteViewActive
					, boolean ButSteNewcrdActive
				) {
			this.LstAppAvail = LstAppAvail;
			this.ButAppViewActive = ButAppViewActive;
			this.LstRtjAvail = LstRtjAvail;
			this.ButRtjViewActive = ButRtjViewActive;
			this.ButRtjNewcrdActive = ButRtjNewcrdActive;
			this.LstEvtAvail = LstEvtAvail;
			this.ButEvtViewActive = ButEvtViewActive;
			this.ButEvtNewcrdActive = ButEvtNewcrdActive;
			this.LstSeqAvail = LstSeqAvail;
			this.ButSeqViewActive = ButSeqViewActive;
			this.ButSeqNewcrdActive = ButSeqNewcrdActive;
			this.LstSteAvail = LstSteAvail;
			this.ButSteViewActive = ButSteViewActive;
			this.ButSteNewcrdActive = ButSteNewcrdActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTAPPAVAIL, BUTAPPVIEWACTIVE, LSTRTJAVAIL, BUTRTJVIEWACTIVE, BUTRTJNEWCRDACTIVE, LSTEVTAVAIL, BUTEVTVIEWACTIVE, BUTEVTNEWCRDACTIVE, LSTSEQAVAIL, BUTSEQVIEWACTIVE, BUTSEQNEWCRDACTIVE, LSTSTEAVAIL, BUTSTEVIEWACTIVE, BUTSTENEWCRDACTIVE));
		};

		public boolean LstAppAvail;
		public boolean ButAppViewActive;
		public boolean LstRtjAvail;
		public boolean ButRtjViewActive;
		public boolean ButRtjNewcrdActive;
		public boolean LstEvtAvail;
		public boolean ButEvtViewActive;
		public boolean ButEvtNewcrdActive;
		public boolean LstSeqAvail;
		public boolean ButSeqViewActive;
		public boolean ButSeqNewcrdActive;
		public boolean LstSteAvail;
		public boolean ButSteViewActive;
		public boolean ButSteNewcrdActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmNavAppdev");

			String itemtag = "StatitemShrWznmNavAppdev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstAppAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstAppAvail", mask, LSTAPPAVAIL);
				ButAppViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButAppViewActive", mask, BUTAPPVIEWACTIVE);
				LstRtjAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRtjAvail", mask, LSTRTJAVAIL);
				ButRtjViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRtjViewActive", mask, BUTRTJVIEWACTIVE);
				ButRtjNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRtjNewcrdActive", mask, BUTRTJNEWCRDACTIVE);
				LstEvtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstEvtAvail", mask, LSTEVTAVAIL);
				ButEvtViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButEvtViewActive", mask, BUTEVTVIEWACTIVE);
				ButEvtNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButEvtNewcrdActive", mask, BUTEVTNEWCRDACTIVE);
				LstSeqAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSeqAvail", mask, LSTSEQAVAIL);
				ButSeqViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSeqViewActive", mask, BUTSEQVIEWACTIVE);
				ButSeqNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSeqNewcrdActive", mask, BUTSEQNEWCRDACTIVE);
				LstSteAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSteAvail", mask, LSTSTEAVAIL);
				ButSteViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSteViewActive", mask, BUTSTEVIEWACTIVE);
				ButSteNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSteNewcrdActive", mask, BUTSTENEWCRDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstAppAvail == comp.LstAppAvail) items.add(LSTAPPAVAIL);
			if (ButAppViewActive == comp.ButAppViewActive) items.add(BUTAPPVIEWACTIVE);
			if (LstRtjAvail == comp.LstRtjAvail) items.add(LSTRTJAVAIL);
			if (ButRtjViewActive == comp.ButRtjViewActive) items.add(BUTRTJVIEWACTIVE);
			if (ButRtjNewcrdActive == comp.ButRtjNewcrdActive) items.add(BUTRTJNEWCRDACTIVE);
			if (LstEvtAvail == comp.LstEvtAvail) items.add(LSTEVTAVAIL);
			if (ButEvtViewActive == comp.ButEvtViewActive) items.add(BUTEVTVIEWACTIVE);
			if (ButEvtNewcrdActive == comp.ButEvtNewcrdActive) items.add(BUTEVTNEWCRDACTIVE);
			if (LstSeqAvail == comp.LstSeqAvail) items.add(LSTSEQAVAIL);
			if (ButSeqViewActive == comp.ButSeqViewActive) items.add(BUTSEQVIEWACTIVE);
			if (ButSeqNewcrdActive == comp.ButSeqNewcrdActive) items.add(BUTSEQNEWCRDACTIVE);
			if (LstSteAvail == comp.LstSteAvail) items.add(LSTSTEAVAIL);
			if (ButSteViewActive == comp.ButSteViewActive) items.add(BUTSTEVIEWACTIVE);
			if (ButSteNewcrdActive == comp.ButSteNewcrdActive) items.add(BUTSTENEWCRDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTAPPAVAIL, BUTAPPVIEWACTIVE, LSTRTJAVAIL, BUTRTJVIEWACTIVE, BUTRTJNEWCRDACTIVE, LSTEVTAVAIL, BUTEVTVIEWACTIVE, BUTEVTNEWCRDACTIVE, LSTSEQAVAIL, BUTSEQVIEWACTIVE, BUTSEQNEWCRDACTIVE, LSTSTEAVAIL, BUTSTEVIEWACTIVE, BUTSTENEWCRDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmNavAppdev)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTAPP = 2;
		public static final int CPTRTJ = 3;
		public static final int CPTEVT = 4;
		public static final int CPTSEQ = 5;
		public static final int CPTSTE = 6;

		public Tag(
					String Cpt
					, String CptApp
					, String CptRtj
					, String CptEvt
					, String CptSeq
					, String CptSte
				) {
			this.Cpt = Cpt;
			this.CptApp = CptApp;
			this.CptRtj = CptRtj;
			this.CptEvt = CptEvt;
			this.CptSeq = CptSeq;
			this.CptSte = CptSte;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTAPP, CPTRTJ, CPTEVT, CPTSEQ, CPTSTE));
		};

		public String Cpt;
		public String CptApp;
		public String CptRtj;
		public String CptEvt;
		public String CptSeq;
		public String CptSte;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmNavAppdev");

			String itemtag = "TagitemWznmNavAppdev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptApp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptApp", mask, CPTAPP);
				CptRtj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptRtj", mask, CPTRTJ);
				CptEvt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptEvt", mask, CPTEVT);
				CptSeq = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSeq", mask, CPTSEQ);
				CptSte = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSte", mask, CPTSTE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptApp.equals(comp.CptApp)) items.add(CPTAPP);
			if (CptRtj.equals(comp.CptRtj)) items.add(CPTRTJ);
			if (CptEvt.equals(comp.CptEvt)) items.add(CPTEVT);
			if (CptSeq.equals(comp.CptSeq)) items.add(CPTSEQ);
			if (CptSte.equals(comp.CptSte)) items.add(CPTSTE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTAPP, CPTRTJ, CPTEVT, CPTSEQ, CPTSTE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmNavAppdevData)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVAPPDEVDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavAppdevData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmNavAppdevDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVAPPDEVDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavAppdevDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmNavAppdevData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTAPP = 3;
		public static final int FEEDFLSTEVT = 4;
		public static final int FEEDFLSTRTJ = 5;
		public static final int FEEDFLSTSEQ = 6;
		public static final int FEEDFLSTSTE = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMNAVAPPDEVDATA);

			contiac = new ContIac(0, 0, 0, 0, 0);
			feedFLstApp = new Feed("FeedFLstApp");
			feedFLstEvt = new Feed("FeedFLstEvt");
			feedFLstRtj = new Feed("FeedFLstRtj");
			feedFLstSeq = new Feed("FeedFLstSeq");
			feedFLstSte = new Feed("FeedFLstSte");
			statapp = new StatApp(0, false, false, false, false, false, 0, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstApp;
		public Feed feedFLstEvt;
		public Feed feedFLstRtj;
		public Feed feedFLstSeq;
		public Feed feedFLstSte;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTAPP)) ss.add("feedFLstApp");
			if (has(FEEDFLSTEVT)) ss.add("feedFLstEvt");
			if (has(FEEDFLSTRTJ)) ss.add("feedFLstRtj");
			if (has(FEEDFLSTSEQ)) ss.add("feedFLstSeq");
			if (has(FEEDFLSTSTE)) ss.add("feedFLstSte");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmNavAppdevData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstApp.readXML(doc, basexpath, true)) add(FEEDFLSTAPP);
				if (feedFLstEvt.readXML(doc, basexpath, true)) add(FEEDFLSTEVT);
				if (feedFLstRtj.readXML(doc, basexpath, true)) add(FEEDFLSTRTJ);
				if (feedFLstSeq.readXML(doc, basexpath, true)) add(FEEDFLSTSEQ);
				if (feedFLstSte.readXML(doc, basexpath, true)) add(FEEDFLSTSTE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0, 0);
				feedFLstApp = new Feed("FeedFLstApp");
				feedFLstEvt = new Feed("FeedFLstEvt");
				feedFLstRtj = new Feed("FeedFLstRtj");
				feedFLstSeq = new Feed("FeedFLstSeq");
				feedFLstSte = new Feed("FeedFLstSte");
				statapp = new StatApp(0, false, false, false, false, false, 0, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};

