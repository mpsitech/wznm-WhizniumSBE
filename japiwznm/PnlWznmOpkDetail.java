/**
  * \file PnlWznmOpkDetail.java
  * Java API code for job PnlWznmOpkDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmOpkDetail {
	/**
		* VecVDo (full: VecVWznmOpkDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTVERVIEWCLICK = 2;
		public static final int BUTSQKNEWCLICK = 3;
		public static final int BUTSQKDELETECLICK = 4;
		public static final int BUTSQKJTIEDITCLICK = 5;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butverviewclick")) return BUTVERVIEWCLICK;
			if (s.equals("butsqknewclick")) return BUTSQKNEWCLICK;
			if (s.equals("butsqkdeleteclick")) return BUTSQKDELETECLICK;
			if (s.equals("butsqkjtieditclick")) return BUTSQKJTIEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
			if (ix == BUTSQKNEWCLICK) return("ButSqkNewClick");
			if (ix == BUTSQKDELETECLICK) return("ButSqkDeleteClick");
			if (ix == BUTSQKJTIEDITCLICK) return("ButSqkJtiEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmOpkDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFTIT = 1;
		public static final int NUMFPUPTYP = 2;
		public static final int CHKSHD = 3;
		public static final int TXFCMT = 4;
		public static final int NUMFPUPSQKJTI = 5;
		public static final int TXFSQKEXA = 6;

		public ContIac(
					String TxfTit
					, int numFPupTyp
					, boolean ChkShd
					, String TxfCmt
					, int numFPupSqkJti
					, String TxfSqkExa
				) {
			this.TxfTit = TxfTit;
			this.numFPupTyp = numFPupTyp;
			this.ChkShd = ChkShd;
			this.TxfCmt = TxfCmt;
			this.numFPupSqkJti = numFPupSqkJti;
			this.TxfSqkExa = TxfSqkExa;

			mask = new HashSet<Integer>(Arrays.asList(TXFTIT, NUMFPUPTYP, CHKSHD, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA));
		};

		public String TxfTit;
		public int numFPupTyp;
		public boolean ChkShd;
		public String TxfCmt;
		public int numFPupSqkJti;
		public String TxfSqkExa;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmOpkDetail");

			String itemtag = "ContitemIacWznmOpkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfTit", mask, TXFTIT);
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				ChkShd = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkShd", mask, CHKSHD);
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCmt", mask, TXFCMT);
				numFPupSqkJti = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupSqkJti", mask, NUMFPUPSQKJTI);
				TxfSqkExa = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSqkExa", mask, TXFSQKEXA);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmOpkDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmOpkDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTit", TxfTit);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkShd", ChkShd);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupSqkJti", numFPupSqkJti);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSqkExa", TxfSqkExa);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfTit.equals(comp.TxfTit)) items.add(TXFTIT);
			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (ChkShd == comp.ChkShd) items.add(CHKSHD);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);
			if (numFPupSqkJti == comp.numFPupSqkJti) items.add(NUMFPUPSQKJTI);
			if (TxfSqkExa.equals(comp.TxfSqkExa)) items.add(TXFSQKEXA);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFTIT, NUMFPUPTYP, CHKSHD, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmOpkDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTVER = 2;
		public static final int TXTSQKTIT = 3;

		public ContInf(
					String TxtSrf
					, String TxtVer
					, String TxtSqkTit
				) {
			this.TxtSrf = TxtSrf;
			this.TxtVer = TxtVer;
			this.TxtSqkTit = TxtSqkTit;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTVER, TXTSQKTIT));
		};

		public String TxtSrf;
		public String TxtVer;
		public String TxtSqkTit;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmOpkDetail");

			String itemtag = "ContitemInfWznmOpkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVer", mask, TXTVER);
				TxtSqkTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSqkTit", mask, TXTSQKTIT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtVer.equals(comp.TxtVer)) items.add(TXTVER);
			if (TxtSqkTit.equals(comp.TxtSqkTit)) items.add(TXTSQKTIT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTVER, TXTSQKTIT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmOpkDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmOpkDetail");

			String itemtag = "StatitemAppWznmOpkDetail";

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
	  * StatShr (full: StatShrWznmOpkDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int TXFTITACTIVE = 4;
		public static final int PUPTYPACTIVE = 5;
		public static final int TXTVERACTIVE = 6;
		public static final int BUTVERVIEWAVAIL = 7;
		public static final int BUTVERVIEWACTIVE = 8;
		public static final int CHKSHDACTIVE = 9;
		public static final int TXFCMTACTIVE = 10;
		public static final int BUTSQKNEWAVAIL = 11;
		public static final int BUTSQKDELETEAVAIL = 12;
		public static final int PUPSQKJTIAVAIL = 13;
		public static final int PUPSQKJTIACTIVE = 14;
		public static final int BUTSQKJTIEDITAVAIL = 15;
		public static final int TXTSQKTITAVAIL = 16;
		public static final int TXTSQKTITACTIVE = 17;
		public static final int TXFSQKEXAAVAIL = 18;
		public static final int TXFSQKEXAACTIVE = 19;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxfTitActive
					, boolean PupTypActive
					, boolean TxtVerActive
					, boolean ButVerViewAvail
					, boolean ButVerViewActive
					, boolean ChkShdActive
					, boolean TxfCmtActive
					, boolean ButSqkNewAvail
					, boolean ButSqkDeleteAvail
					, boolean PupSqkJtiAvail
					, boolean PupSqkJtiActive
					, boolean ButSqkJtiEditAvail
					, boolean TxtSqkTitAvail
					, boolean TxtSqkTitActive
					, boolean TxfSqkExaAvail
					, boolean TxfSqkExaActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxfTitActive = TxfTitActive;
			this.PupTypActive = PupTypActive;
			this.TxtVerActive = TxtVerActive;
			this.ButVerViewAvail = ButVerViewAvail;
			this.ButVerViewActive = ButVerViewActive;
			this.ChkShdActive = ChkShdActive;
			this.TxfCmtActive = TxfCmtActive;
			this.ButSqkNewAvail = ButSqkNewAvail;
			this.ButSqkDeleteAvail = ButSqkDeleteAvail;
			this.PupSqkJtiAvail = PupSqkJtiAvail;
			this.PupSqkJtiActive = PupSqkJtiActive;
			this.ButSqkJtiEditAvail = ButSqkJtiEditAvail;
			this.TxtSqkTitAvail = TxtSqkTitAvail;
			this.TxtSqkTitActive = TxtSqkTitActive;
			this.TxfSqkExaAvail = TxfSqkExaAvail;
			this.TxfSqkExaActive = TxfSqkExaActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, CHKSHDACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxfTitActive;
		public boolean PupTypActive;
		public boolean TxtVerActive;
		public boolean ButVerViewAvail;
		public boolean ButVerViewActive;
		public boolean ChkShdActive;
		public boolean TxfCmtActive;
		public boolean ButSqkNewAvail;
		public boolean ButSqkDeleteAvail;
		public boolean PupSqkJtiAvail;
		public boolean PupSqkJtiActive;
		public boolean ButSqkJtiEditAvail;
		public boolean TxtSqkTitAvail;
		public boolean TxtSqkTitActive;
		public boolean TxfSqkExaAvail;
		public boolean TxfSqkExaActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmOpkDetail");

			String itemtag = "StatitemShrWznmOpkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxfTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfTitActive", mask, TXFTITACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				TxtVerActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVerActive", mask, TXTVERACTIVE);
				ButVerViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", mask, BUTVERVIEWAVAIL);
				ButVerViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewActive", mask, BUTVERVIEWACTIVE);
				ChkShdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkShdActive", mask, CHKSHDACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);
				ButSqkNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSqkNewAvail", mask, BUTSQKNEWAVAIL);
				ButSqkDeleteAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSqkDeleteAvail", mask, BUTSQKDELETEAVAIL);
				PupSqkJtiAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupSqkJtiAvail", mask, PUPSQKJTIAVAIL);
				PupSqkJtiActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupSqkJtiActive", mask, PUPSQKJTIACTIVE);
				ButSqkJtiEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSqkJtiEditAvail", mask, BUTSQKJTIEDITAVAIL);
				TxtSqkTitAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSqkTitAvail", mask, TXTSQKTITAVAIL);
				TxtSqkTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSqkTitActive", mask, TXTSQKTITACTIVE);
				TxfSqkExaAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfSqkExaAvail", mask, TXFSQKEXAAVAIL);
				TxfSqkExaActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfSqkExaActive", mask, TXFSQKEXAACTIVE);

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
			if (TxfTitActive == comp.TxfTitActive) items.add(TXFTITACTIVE);
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (TxtVerActive == comp.TxtVerActive) items.add(TXTVERACTIVE);
			if (ButVerViewAvail == comp.ButVerViewAvail) items.add(BUTVERVIEWAVAIL);
			if (ButVerViewActive == comp.ButVerViewActive) items.add(BUTVERVIEWACTIVE);
			if (ChkShdActive == comp.ChkShdActive) items.add(CHKSHDACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);
			if (ButSqkNewAvail == comp.ButSqkNewAvail) items.add(BUTSQKNEWAVAIL);
			if (ButSqkDeleteAvail == comp.ButSqkDeleteAvail) items.add(BUTSQKDELETEAVAIL);
			if (PupSqkJtiAvail == comp.PupSqkJtiAvail) items.add(PUPSQKJTIAVAIL);
			if (PupSqkJtiActive == comp.PupSqkJtiActive) items.add(PUPSQKJTIACTIVE);
			if (ButSqkJtiEditAvail == comp.ButSqkJtiEditAvail) items.add(BUTSQKJTIEDITAVAIL);
			if (TxtSqkTitAvail == comp.TxtSqkTitAvail) items.add(TXTSQKTITAVAIL);
			if (TxtSqkTitActive == comp.TxtSqkTitActive) items.add(TXTSQKTITACTIVE);
			if (TxfSqkExaAvail == comp.TxfSqkExaAvail) items.add(TXFSQKEXAAVAIL);
			if (TxfSqkExaActive == comp.TxfSqkExaActive) items.add(TXFSQKEXAACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, CHKSHDACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmOpkDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTIT = 3;
		public static final int CPTTYP = 4;
		public static final int CPTVER = 5;
		public static final int CPTSHD = 6;
		public static final int CPTCMT = 7;
		public static final int HDGSQK = 8;
		public static final int CPTSQKTIT = 9;
		public static final int CPTSQKEXA = 10;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTit
					, String CptTyp
					, String CptVer
					, String CptShd
					, String CptCmt
					, String HdgSqk
					, String CptSqkTit
					, String CptSqkExa
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTit = CptTit;
			this.CptTyp = CptTyp;
			this.CptVer = CptVer;
			this.CptShd = CptShd;
			this.CptCmt = CptCmt;
			this.HdgSqk = HdgSqk;
			this.CptSqkTit = CptSqkTit;
			this.CptSqkExa = CptSqkExa;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTTYP, CPTVER, CPTSHD, CPTCMT, HDGSQK, CPTSQKTIT, CPTSQKEXA));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTit;
		public String CptTyp;
		public String CptVer;
		public String CptShd;
		public String CptCmt;
		public String HdgSqk;
		public String CptSqkTit;
		public String CptSqkExa;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmOpkDetail");

			String itemtag = "TagitemWznmOpkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTit", mask, CPTTIT);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptShd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptShd", mask, CPTSHD);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);
				HdgSqk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgSqk", mask, HDGSQK);
				CptSqkTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSqkTit", mask, CPTSQKTIT);
				CptSqkExa = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSqkExa", mask, CPTSQKEXA);

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
			if (CptTit.equals(comp.CptTit)) items.add(CPTTIT);
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);
			if (CptShd.equals(comp.CptShd)) items.add(CPTSHD);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);
			if (HdgSqk.equals(comp.HdgSqk)) items.add(HDGSQK);
			if (CptSqkTit.equals(comp.CptSqkTit)) items.add(CPTSQKTIT);
			if (CptSqkExa.equals(comp.CptSqkExa)) items.add(CPTSQKEXA);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTTYP, CPTVER, CPTSHD, CPTCMT, HDGSQK, CPTSQKTIT, CPTSQKEXA));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmOpkDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMOPKDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmOpkDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmOpkDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMOPKDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmOpkDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmOpkDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPSQKJTI = 4;
		public static final int FEEDFPUPTYP = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMOPKDETAILDATA);

			contiac = new ContIac("", 0, false, "", 0, "");
			continf = new ContInf("", "", "");
			feedFPupSqkJti = new Feed("FeedFPupSqkJti");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupSqkJti;
		public Feed feedFPupTyp;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPSQKJTI)) ss.add("feedFPupSqkJti");
			if (has(FEEDFPUPTYP)) ss.add("feedFPupTyp");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmOpkDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupSqkJti.readXML(doc, basexpath, true)) add(FEEDFPUPSQKJTI);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", 0, false, "", 0, "");
				continf = new ContInf("", "", "");
				feedFPupSqkJti = new Feed("FeedFPupSqkJti");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

