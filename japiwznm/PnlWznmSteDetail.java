/**
  * \file PnlWznmSteDetail.java
  * Java API code for job PnlWznmSteDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmSteDetail {
	/**
		* VecVDo (full: VecVWznmSteDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTSEQVIEWCLICK = 2;
		public static final int BUTERJVIEWCLICK = 3;
		public static final int BUTEVEVIEWCLICK = 4;
		public static final int BUTEVIVIEWCLICK = 5;
		public static final int BUTESNVIEWCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butseqviewclick")) return BUTSEQVIEWCLICK;
			if (s.equals("buterjviewclick")) return BUTERJVIEWCLICK;
			if (s.equals("buteveviewclick")) return BUTEVEVIEWCLICK;
			if (s.equals("buteviviewclick")) return BUTEVIVIEWCLICK;
			if (s.equals("butesnviewclick")) return BUTESNVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTSEQVIEWCLICK) return("ButSeqViewClick");
			if (ix == BUTERJVIEWCLICK) return("ButErjViewClick");
			if (ix == BUTEVEVIEWCLICK) return("ButEveViewClick");
			if (ix == BUTEVIVIEWCLICK) return("ButEviViewClick");
			if (ix == BUTESNVIEWCLICK) return("ButEsnViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmSteDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPEAC = 1;
		public static final int NUMFPUPLAC = 2;
		public static final int CHKCST = 3;
		public static final int TXFCMT = 4;

		public ContIac(
					int numFPupEac
					, int numFPupLac
					, boolean ChkCst
					, String TxfCmt
				) {
			this.numFPupEac = numFPupEac;
			this.numFPupLac = numFPupLac;
			this.ChkCst = ChkCst;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPEAC, NUMFPUPLAC, CHKCST, TXFCMT));
		};

		public int numFPupEac;
		public int numFPupLac;
		public boolean ChkCst;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmSteDetail");

			String itemtag = "ContitemIacWznmSteDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupEac = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupEac", mask, NUMFPUPEAC);
				numFPupLac = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupLac", mask, NUMFPUPLAC);
				ChkCst = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkCst", mask, CHKCST);
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
			if (difftag.isEmpty()) difftag = "ContIacWznmSteDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmSteDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupEac", numFPupEac);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupLac", numFPupLac);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkCst", ChkCst);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupEac == comp.numFPupEac) items.add(NUMFPUPEAC);
			if (numFPupLac == comp.numFPupLac) items.add(NUMFPUPLAC);
			if (ChkCst == comp.ChkCst) items.add(CHKCST);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPEAC, NUMFPUPLAC, CHKCST, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmSteDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTSEQ = 2;
		public static final int TXTERJ = 3;
		public static final int TXTEVE = 4;
		public static final int TXTEVI = 5;
		public static final int TXTESN = 6;

		public ContInf(
					String TxtSrf
					, String TxtSeq
					, String TxtErj
					, String TxtEve
					, String TxtEvi
					, String TxtEsn
				) {
			this.TxtSrf = TxtSrf;
			this.TxtSeq = TxtSeq;
			this.TxtErj = TxtErj;
			this.TxtEve = TxtEve;
			this.TxtEvi = TxtEvi;
			this.TxtEsn = TxtEsn;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTSEQ, TXTERJ, TXTEVE, TXTEVI, TXTESN));
		};

		public String TxtSrf;
		public String TxtSeq;
		public String TxtErj;
		public String TxtEve;
		public String TxtEvi;
		public String TxtEsn;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmSteDetail");

			String itemtag = "ContitemInfWznmSteDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtSeq = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSeq", mask, TXTSEQ);
				TxtErj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtErj", mask, TXTERJ);
				TxtEve = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtEve", mask, TXTEVE);
				TxtEvi = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtEvi", mask, TXTEVI);
				TxtEsn = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtEsn", mask, TXTESN);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtSeq.equals(comp.TxtSeq)) items.add(TXTSEQ);
			if (TxtErj.equals(comp.TxtErj)) items.add(TXTERJ);
			if (TxtEve.equals(comp.TxtEve)) items.add(TXTEVE);
			if (TxtEvi.equals(comp.TxtEvi)) items.add(TXTEVI);
			if (TxtEsn.equals(comp.TxtEsn)) items.add(TXTESN);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTSEQ, TXTERJ, TXTEVE, TXTEVI, TXTESN));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmSteDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmSteDetail");

			String itemtag = "StatitemAppWznmSteDetail";

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
	  * StatShr (full: StatShrWznmSteDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int TXTSEQACTIVE = 4;
		public static final int BUTSEQVIEWAVAIL = 5;
		public static final int BUTSEQVIEWACTIVE = 6;
		public static final int PUPEACACTIVE = 7;
		public static final int TXTERJACTIVE = 8;
		public static final int BUTERJVIEWAVAIL = 9;
		public static final int BUTERJVIEWACTIVE = 10;
		public static final int TXTEVEACTIVE = 11;
		public static final int BUTEVEVIEWAVAIL = 12;
		public static final int BUTEVEVIEWACTIVE = 13;
		public static final int TXTEVIACTIVE = 14;
		public static final int BUTEVIVIEWAVAIL = 15;
		public static final int BUTEVIVIEWACTIVE = 16;
		public static final int TXTESNACTIVE = 17;
		public static final int BUTESNVIEWAVAIL = 18;
		public static final int BUTESNVIEWACTIVE = 19;
		public static final int PUPLACACTIVE = 20;
		public static final int CHKCSTACTIVE = 21;
		public static final int TXFCMTACTIVE = 22;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxtSeqActive
					, boolean ButSeqViewAvail
					, boolean ButSeqViewActive
					, boolean PupEacActive
					, boolean TxtErjActive
					, boolean ButErjViewAvail
					, boolean ButErjViewActive
					, boolean TxtEveActive
					, boolean ButEveViewAvail
					, boolean ButEveViewActive
					, boolean TxtEviActive
					, boolean ButEviViewAvail
					, boolean ButEviViewActive
					, boolean TxtEsnActive
					, boolean ButEsnViewAvail
					, boolean ButEsnViewActive
					, boolean PupLacActive
					, boolean ChkCstActive
					, boolean TxfCmtActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxtSeqActive = TxtSeqActive;
			this.ButSeqViewAvail = ButSeqViewAvail;
			this.ButSeqViewActive = ButSeqViewActive;
			this.PupEacActive = PupEacActive;
			this.TxtErjActive = TxtErjActive;
			this.ButErjViewAvail = ButErjViewAvail;
			this.ButErjViewActive = ButErjViewActive;
			this.TxtEveActive = TxtEveActive;
			this.ButEveViewAvail = ButEveViewAvail;
			this.ButEveViewActive = ButEveViewActive;
			this.TxtEviActive = TxtEviActive;
			this.ButEviViewAvail = ButEviViewAvail;
			this.ButEviViewActive = ButEviViewActive;
			this.TxtEsnActive = TxtEsnActive;
			this.ButEsnViewAvail = ButEsnViewAvail;
			this.ButEsnViewActive = ButEsnViewActive;
			this.PupLacActive = PupLacActive;
			this.ChkCstActive = ChkCstActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSEQACTIVE, BUTSEQVIEWAVAIL, BUTSEQVIEWACTIVE, PUPEACACTIVE, TXTERJACTIVE, BUTERJVIEWAVAIL, BUTERJVIEWACTIVE, TXTEVEACTIVE, BUTEVEVIEWAVAIL, BUTEVEVIEWACTIVE, TXTEVIACTIVE, BUTEVIVIEWAVAIL, BUTEVIVIEWACTIVE, TXTESNACTIVE, BUTESNVIEWAVAIL, BUTESNVIEWACTIVE, PUPLACACTIVE, CHKCSTACTIVE, TXFCMTACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxtSeqActive;
		public boolean ButSeqViewAvail;
		public boolean ButSeqViewActive;
		public boolean PupEacActive;
		public boolean TxtErjActive;
		public boolean ButErjViewAvail;
		public boolean ButErjViewActive;
		public boolean TxtEveActive;
		public boolean ButEveViewAvail;
		public boolean ButEveViewActive;
		public boolean TxtEviActive;
		public boolean ButEviViewAvail;
		public boolean ButEviViewActive;
		public boolean TxtEsnActive;
		public boolean ButEsnViewAvail;
		public boolean ButEsnViewActive;
		public boolean PupLacActive;
		public boolean ChkCstActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmSteDetail");

			String itemtag = "StatitemShrWznmSteDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxtSeqActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSeqActive", mask, TXTSEQACTIVE);
				ButSeqViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSeqViewAvail", mask, BUTSEQVIEWAVAIL);
				ButSeqViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSeqViewActive", mask, BUTSEQVIEWACTIVE);
				PupEacActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupEacActive", mask, PUPEACACTIVE);
				TxtErjActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtErjActive", mask, TXTERJACTIVE);
				ButErjViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButErjViewAvail", mask, BUTERJVIEWAVAIL);
				ButErjViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButErjViewActive", mask, BUTERJVIEWACTIVE);
				TxtEveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtEveActive", mask, TXTEVEACTIVE);
				ButEveViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButEveViewAvail", mask, BUTEVEVIEWAVAIL);
				ButEveViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButEveViewActive", mask, BUTEVEVIEWACTIVE);
				TxtEviActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtEviActive", mask, TXTEVIACTIVE);
				ButEviViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButEviViewAvail", mask, BUTEVIVIEWAVAIL);
				ButEviViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButEviViewActive", mask, BUTEVIVIEWACTIVE);
				TxtEsnActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtEsnActive", mask, TXTESNACTIVE);
				ButEsnViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButEsnViewAvail", mask, BUTESNVIEWAVAIL);
				ButEsnViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButEsnViewActive", mask, BUTESNVIEWACTIVE);
				PupLacActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupLacActive", mask, PUPLACACTIVE);
				ChkCstActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkCstActive", mask, CHKCSTACTIVE);
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
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (TxtSeqActive == comp.TxtSeqActive) items.add(TXTSEQACTIVE);
			if (ButSeqViewAvail == comp.ButSeqViewAvail) items.add(BUTSEQVIEWAVAIL);
			if (ButSeqViewActive == comp.ButSeqViewActive) items.add(BUTSEQVIEWACTIVE);
			if (PupEacActive == comp.PupEacActive) items.add(PUPEACACTIVE);
			if (TxtErjActive == comp.TxtErjActive) items.add(TXTERJACTIVE);
			if (ButErjViewAvail == comp.ButErjViewAvail) items.add(BUTERJVIEWAVAIL);
			if (ButErjViewActive == comp.ButErjViewActive) items.add(BUTERJVIEWACTIVE);
			if (TxtEveActive == comp.TxtEveActive) items.add(TXTEVEACTIVE);
			if (ButEveViewAvail == comp.ButEveViewAvail) items.add(BUTEVEVIEWAVAIL);
			if (ButEveViewActive == comp.ButEveViewActive) items.add(BUTEVEVIEWACTIVE);
			if (TxtEviActive == comp.TxtEviActive) items.add(TXTEVIACTIVE);
			if (ButEviViewAvail == comp.ButEviViewAvail) items.add(BUTEVIVIEWAVAIL);
			if (ButEviViewActive == comp.ButEviViewActive) items.add(BUTEVIVIEWACTIVE);
			if (TxtEsnActive == comp.TxtEsnActive) items.add(TXTESNACTIVE);
			if (ButEsnViewAvail == comp.ButEsnViewAvail) items.add(BUTESNVIEWAVAIL);
			if (ButEsnViewActive == comp.ButEsnViewActive) items.add(BUTESNVIEWACTIVE);
			if (PupLacActive == comp.PupLacActive) items.add(PUPLACACTIVE);
			if (ChkCstActive == comp.ChkCstActive) items.add(CHKCSTACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSEQACTIVE, BUTSEQVIEWAVAIL, BUTSEQVIEWACTIVE, PUPEACACTIVE, TXTERJACTIVE, BUTERJVIEWAVAIL, BUTERJVIEWACTIVE, TXTEVEACTIVE, BUTEVEVIEWAVAIL, BUTEVEVIEWACTIVE, TXTEVIACTIVE, BUTEVIVIEWAVAIL, BUTEVIVIEWACTIVE, TXTESNACTIVE, BUTESNVIEWAVAIL, BUTESNVIEWACTIVE, PUPLACACTIVE, CHKCSTACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmSteDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTSEQ = 3;
		public static final int CPTEAC = 4;
		public static final int CPTERJ = 5;
		public static final int CPTEVE = 6;
		public static final int CPTEVI = 7;
		public static final int CPTESN = 8;
		public static final int CPTLAC = 9;
		public static final int CPTCST = 10;
		public static final int CPTCMT = 11;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptSeq
					, String CptEac
					, String CptErj
					, String CptEve
					, String CptEvi
					, String CptEsn
					, String CptLac
					, String CptCst
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptSeq = CptSeq;
			this.CptEac = CptEac;
			this.CptErj = CptErj;
			this.CptEve = CptEve;
			this.CptEvi = CptEvi;
			this.CptEsn = CptEsn;
			this.CptLac = CptLac;
			this.CptCst = CptCst;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSEQ, CPTEAC, CPTERJ, CPTEVE, CPTEVI, CPTESN, CPTLAC, CPTCST, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptSeq;
		public String CptEac;
		public String CptErj;
		public String CptEve;
		public String CptEvi;
		public String CptEsn;
		public String CptLac;
		public String CptCst;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmSteDetail");

			String itemtag = "TagitemWznmSteDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptSeq = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSeq", mask, CPTSEQ);
				CptEac = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptEac", mask, CPTEAC);
				CptErj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptErj", mask, CPTERJ);
				CptEve = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptEve", mask, CPTEVE);
				CptEvi = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptEvi", mask, CPTEVI);
				CptEsn = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptEsn", mask, CPTESN);
				CptLac = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLac", mask, CPTLAC);
				CptCst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCst", mask, CPTCST);
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
			if (CptSeq.equals(comp.CptSeq)) items.add(CPTSEQ);
			if (CptEac.equals(comp.CptEac)) items.add(CPTEAC);
			if (CptErj.equals(comp.CptErj)) items.add(CPTERJ);
			if (CptEve.equals(comp.CptEve)) items.add(CPTEVE);
			if (CptEvi.equals(comp.CptEvi)) items.add(CPTEVI);
			if (CptEsn.equals(comp.CptEsn)) items.add(CPTESN);
			if (CptLac.equals(comp.CptLac)) items.add(CPTLAC);
			if (CptCst.equals(comp.CptCst)) items.add(CPTCST);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSEQ, CPTEAC, CPTERJ, CPTEVE, CPTEVI, CPTESN, CPTLAC, CPTCST, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmSteDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMSTEDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmSteDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmSteDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMSTEDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmSteDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmSteDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPEAC = 4;
		public static final int FEEDFPUPLAC = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMSTEDETAILDATA);

			contiac = new ContIac(0, 0, false, "");
			continf = new ContInf("", "", "", "", "", "");
			feedFPupEac = new Feed("FeedFPupEac");
			feedFPupLac = new Feed("FeedFPupLac");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupEac;
		public Feed feedFPupLac;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPEAC)) ss.add("feedFPupEac");
			if (has(FEEDFPUPLAC)) ss.add("feedFPupLac");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmSteDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupEac.readXML(doc, basexpath, true)) add(FEEDFPUPEAC);
				if (feedFPupLac.readXML(doc, basexpath, true)) add(FEEDFPUPLAC);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, false, "");
				continf = new ContInf("", "", "", "", "", "");
				feedFPupEac = new Feed("FeedFPupEac");
				feedFPupLac = new Feed("FeedFPupLac");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

