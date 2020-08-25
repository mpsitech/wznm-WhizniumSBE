/**
  * \file PnlWznmVecDetail.java
  * Java API code for job PnlWznmVecDetail
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmVecDetail {
	/**
		* VecVDo (full: VecVWznmVecDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTVERVIEWCLICK = 2;
		public static final int BUTHKUVIEWCLICK = 3;
		public static final int BUTTGREDITCLICK = 4;
		public static final int BUTOPTEDITCLICK = 5;
		public static final int BUTPSTNEWCLICK = 6;
		public static final int BUTPSTDELETECLICK = 7;
		public static final int BUTPSTJTIEDITCLICK = 8;
		public static final int BUTPSTVERVIEWCLICK = 9;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butverviewclick")) return BUTVERVIEWCLICK;
			if (s.equals("buthkuviewclick")) return BUTHKUVIEWCLICK;
			if (s.equals("buttgreditclick")) return BUTTGREDITCLICK;
			if (s.equals("butopteditclick")) return BUTOPTEDITCLICK;
			if (s.equals("butpstnewclick")) return BUTPSTNEWCLICK;
			if (s.equals("butpstdeleteclick")) return BUTPSTDELETECLICK;
			if (s.equals("butpstjtieditclick")) return BUTPSTJTIEDITCLICK;
			if (s.equals("butpstverviewclick")) return BUTPSTVERVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
			if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");
			if (ix == BUTTGREDITCLICK) return("ButTgrEditClick");
			if (ix == BUTOPTEDITCLICK) return("ButOptEditClick");
			if (ix == BUTPSTNEWCLICK) return("ButPstNewClick");
			if (ix == BUTPSTDELETECLICK) return("ButPstDeleteClick");
			if (ix == BUTPSTJTIEDITCLICK) return("ButPstJtiEditClick");
			if (ix == BUTPSTVERVIEWCLICK) return("ButPstVerViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmVecDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPTYP = 1;
		public static final int NUMFPUPHKT = 2;
		public static final int NUMFPUPTGR = 3;
		public static final int TXFTGR = 4;
		public static final int NUMSFLSTOPT = 5;
		public static final int TXFOPT = 6;
		public static final int NUMFPUPPSTJTI = 7;
		public static final int NUMFPUPPSTSCO = 8;
		public static final int NUMFPUPPSTATY = 9;

		public ContIac(
					int numFPupTyp
					, int numFPupHkt
					, int numFPupTgr
					, String TxfTgr
					, ArrayList<Integer> numsFLstOpt
					, String TxfOpt
					, int numFPupPstJti
					, int numFPupPstSco
					, int numFPupPstAty
				) {
			this.numFPupTyp = numFPupTyp;
			this.numFPupHkt = numFPupHkt;
			this.numFPupTgr = numFPupTgr;
			this.TxfTgr = TxfTgr;
			this.numsFLstOpt = numsFLstOpt;
			this.TxfOpt = TxfOpt;
			this.numFPupPstJti = numFPupPstJti;
			this.numFPupPstSco = numFPupPstSco;
			this.numFPupPstAty = numFPupPstAty;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, NUMFPUPHKT, NUMFPUPTGR, TXFTGR, NUMSFLSTOPT, TXFOPT, NUMFPUPPSTJTI, NUMFPUPPSTSCO, NUMFPUPPSTATY));
		};

		public int numFPupTyp;
		public int numFPupHkt;
		public int numFPupTgr;
		public String TxfTgr;
		public ArrayList<Integer> numsFLstOpt;
		public String TxfOpt;
		public int numFPupPstJti;
		public int numFPupPstSco;
		public int numFPupPstAty;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmVecDetail");

			String itemtag = "ContitemIacWznmVecDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				numFPupHkt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupHkt", mask, NUMFPUPHKT);
				numFPupTgr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTgr", mask, NUMFPUPTGR);
				TxfTgr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfTgr", mask, TXFTGR);
				numsFLstOpt = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", mask, NUMSFLSTOPT);
				TxfOpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfOpt", mask, TXFOPT);
				numFPupPstJti = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupPstJti", mask, NUMFPUPPSTJTI);
				numFPupPstSco = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupPstSco", mask, NUMFPUPPSTSCO);
				numFPupPstAty = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupPstAty", mask, NUMFPUPPSTATY);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmVecDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmVecDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupHkt", numFPupHkt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTgr", numFPupTgr);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTgr", TxfTgr);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfOpt", TxfOpt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupPstJti", numFPupPstJti);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupPstSco", numFPupPstSco);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupPstAty", numFPupPstAty);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (numFPupHkt == comp.numFPupHkt) items.add(NUMFPUPHKT);
			if (numFPupTgr == comp.numFPupTgr) items.add(NUMFPUPTGR);
			if (TxfTgr.equals(comp.TxfTgr)) items.add(TXFTGR);
			if (Xmlio.compareIntegervec(numsFLstOpt, comp.numsFLstOpt)) items.add(NUMSFLSTOPT);
			if (TxfOpt.equals(comp.TxfOpt)) items.add(TXFOPT);
			if (numFPupPstJti == comp.numFPupPstJti) items.add(NUMFPUPPSTJTI);
			if (numFPupPstSco == comp.numFPupPstSco) items.add(NUMFPUPPSTSCO);
			if (numFPupPstAty == comp.numFPupPstAty) items.add(NUMFPUPPSTATY);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, NUMFPUPHKT, NUMFPUPTGR, TXFTGR, NUMSFLSTOPT, TXFOPT, NUMFPUPPSTJTI, NUMFPUPPSTSCO, NUMFPUPPSTATY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmVecDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTVER = 2;
		public static final int TXTHKU = 3;
		public static final int TXTPSTSRF = 4;
		public static final int TXTPSTTIT = 5;
		public static final int TXTPSTVER = 6;

		public ContInf(
					String TxtSrf
					, String TxtVer
					, String TxtHku
					, String TxtPstSrf
					, String TxtPstTit
					, String TxtPstVer
				) {
			this.TxtSrf = TxtSrf;
			this.TxtVer = TxtVer;
			this.TxtHku = TxtHku;
			this.TxtPstSrf = TxtPstSrf;
			this.TxtPstTit = TxtPstTit;
			this.TxtPstVer = TxtPstVer;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTVER, TXTHKU, TXTPSTSRF, TXTPSTTIT, TXTPSTVER));
		};

		public String TxtSrf;
		public String TxtVer;
		public String TxtHku;
		public String TxtPstSrf;
		public String TxtPstTit;
		public String TxtPstVer;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmVecDetail");

			String itemtag = "ContitemInfWznmVecDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVer", mask, TXTVER);
				TxtHku = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtHku", mask, TXTHKU);
				TxtPstSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPstSrf", mask, TXTPSTSRF);
				TxtPstTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPstTit", mask, TXTPSTTIT);
				TxtPstVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPstVer", mask, TXTPSTVER);

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
			if (TxtHku.equals(comp.TxtHku)) items.add(TXTHKU);
			if (TxtPstSrf.equals(comp.TxtPstSrf)) items.add(TXTPSTSRF);
			if (TxtPstTit.equals(comp.TxtPstTit)) items.add(TXTPSTTIT);
			if (TxtPstVer.equals(comp.TxtPstVer)) items.add(TXTPSTVER);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTVER, TXTHKU, TXTPSTSRF, TXTPSTTIT, TXTPSTVER));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmVecDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int PUPTGRALT = 2;
		public static final int LSTOPTALT = 3;
		public static final int LSTOPTNUMFIRSTDISP = 4;

		public StatApp(
					int ixWznmVExpstate
					, boolean PupTgrAlt
					, boolean LstOptAlt
					, int LstOptNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.PupTgrAlt = PupTgrAlt;
			this.LstOptAlt = LstOptAlt;
			this.LstOptNumFirstdisp = LstOptNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, PUPTGRALT, LSTOPTALT, LSTOPTNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean PupTgrAlt;
		public boolean LstOptAlt;
		public int LstOptNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmVecDetail");

			String itemtag = "StatitemAppWznmVecDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				PupTgrAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTgrAlt", mask, PUPTGRALT);
				LstOptAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptAlt", mask, LSTOPTALT);
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
			if (PupTgrAlt == comp.PupTgrAlt) items.add(PUPTGRALT);
			if (LstOptAlt == comp.LstOptAlt) items.add(LSTOPTALT);
			if (LstOptNumFirstdisp == comp.LstOptNumFirstdisp) items.add(LSTOPTNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, PUPTGRALT, LSTOPTALT, LSTOPTNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmVecDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFTGRVALID = 1;
		public static final int TXFOPTVALID = 2;
		public static final int BUTSAVEAVAIL = 3;
		public static final int BUTSAVEACTIVE = 4;
		public static final int TXTSRFACTIVE = 5;
		public static final int PUPTYPACTIVE = 6;
		public static final int TXTVERACTIVE = 7;
		public static final int BUTVERVIEWAVAIL = 8;
		public static final int BUTVERVIEWACTIVE = 9;
		public static final int TXTHKUACTIVE = 10;
		public static final int BUTHKUVIEWAVAIL = 11;
		public static final int BUTHKUVIEWACTIVE = 12;
		public static final int PUPTGRACTIVE = 13;
		public static final int BUTTGREDITAVAIL = 14;
		public static final int LSTOPTACTIVE = 15;
		public static final int BUTOPTEDITAVAIL = 16;
		public static final int BUTPSTNEWAVAIL = 17;
		public static final int BUTPSTDELETEAVAIL = 18;
		public static final int TXTPSTSRFAVAIL = 19;
		public static final int TXTPSTSRFACTIVE = 20;
		public static final int PUPPSTJTIAVAIL = 21;
		public static final int PUPPSTJTIACTIVE = 22;
		public static final int BUTPSTJTIEDITAVAIL = 23;
		public static final int TXTPSTTITAVAIL = 24;
		public static final int TXTPSTTITACTIVE = 25;
		public static final int TXTPSTVERAVAIL = 26;
		public static final int TXTPSTVERACTIVE = 27;
		public static final int BUTPSTVERVIEWAVAIL = 28;
		public static final int BUTPSTVERVIEWACTIVE = 29;
		public static final int PUPPSTSCOAVAIL = 30;
		public static final int PUPPSTSCOACTIVE = 31;
		public static final int PUPPSTATYAVAIL = 32;
		public static final int PUPPSTATYACTIVE = 33;

		public StatShr(
					boolean TxfTgrValid
					, boolean TxfOptValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupTypActive
					, boolean TxtVerActive
					, boolean ButVerViewAvail
					, boolean ButVerViewActive
					, boolean TxtHkuActive
					, boolean ButHkuViewAvail
					, boolean ButHkuViewActive
					, boolean PupTgrActive
					, boolean ButTgrEditAvail
					, boolean LstOptActive
					, boolean ButOptEditAvail
					, boolean ButPstNewAvail
					, boolean ButPstDeleteAvail
					, boolean TxtPstSrfAvail
					, boolean TxtPstSrfActive
					, boolean PupPstJtiAvail
					, boolean PupPstJtiActive
					, boolean ButPstJtiEditAvail
					, boolean TxtPstTitAvail
					, boolean TxtPstTitActive
					, boolean TxtPstVerAvail
					, boolean TxtPstVerActive
					, boolean ButPstVerViewAvail
					, boolean ButPstVerViewActive
					, boolean PupPstScoAvail
					, boolean PupPstScoActive
					, boolean PupPstAtyAvail
					, boolean PupPstAtyActive
				) {
			this.TxfTgrValid = TxfTgrValid;
			this.TxfOptValid = TxfOptValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupTypActive = PupTypActive;
			this.TxtVerActive = TxtVerActive;
			this.ButVerViewAvail = ButVerViewAvail;
			this.ButVerViewActive = ButVerViewActive;
			this.TxtHkuActive = TxtHkuActive;
			this.ButHkuViewAvail = ButHkuViewAvail;
			this.ButHkuViewActive = ButHkuViewActive;
			this.PupTgrActive = PupTgrActive;
			this.ButTgrEditAvail = ButTgrEditAvail;
			this.LstOptActive = LstOptActive;
			this.ButOptEditAvail = ButOptEditAvail;
			this.ButPstNewAvail = ButPstNewAvail;
			this.ButPstDeleteAvail = ButPstDeleteAvail;
			this.TxtPstSrfAvail = TxtPstSrfAvail;
			this.TxtPstSrfActive = TxtPstSrfActive;
			this.PupPstJtiAvail = PupPstJtiAvail;
			this.PupPstJtiActive = PupPstJtiActive;
			this.ButPstJtiEditAvail = ButPstJtiEditAvail;
			this.TxtPstTitAvail = TxtPstTitAvail;
			this.TxtPstTitActive = TxtPstTitActive;
			this.TxtPstVerAvail = TxtPstVerAvail;
			this.TxtPstVerActive = TxtPstVerActive;
			this.ButPstVerViewAvail = ButPstVerViewAvail;
			this.ButPstVerViewActive = ButPstVerViewActive;
			this.PupPstScoAvail = PupPstScoAvail;
			this.PupPstScoActive = PupPstScoActive;
			this.PupPstAtyAvail = PupPstAtyAvail;
			this.PupPstAtyActive = PupPstAtyActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFTGRVALID, TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, PUPTGRACTIVE, BUTTGREDITAVAIL, LSTOPTACTIVE, BUTOPTEDITAVAIL, BUTPSTNEWAVAIL, BUTPSTDELETEAVAIL, TXTPSTSRFAVAIL, TXTPSTSRFACTIVE, PUPPSTJTIAVAIL, PUPPSTJTIACTIVE, BUTPSTJTIEDITAVAIL, TXTPSTTITAVAIL, TXTPSTTITACTIVE, TXTPSTVERAVAIL, TXTPSTVERACTIVE, BUTPSTVERVIEWAVAIL, BUTPSTVERVIEWACTIVE, PUPPSTSCOAVAIL, PUPPSTSCOACTIVE, PUPPSTATYAVAIL, PUPPSTATYACTIVE));
		};

		public boolean TxfTgrValid;
		public boolean TxfOptValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupTypActive;
		public boolean TxtVerActive;
		public boolean ButVerViewAvail;
		public boolean ButVerViewActive;
		public boolean TxtHkuActive;
		public boolean ButHkuViewAvail;
		public boolean ButHkuViewActive;
		public boolean PupTgrActive;
		public boolean ButTgrEditAvail;
		public boolean LstOptActive;
		public boolean ButOptEditAvail;
		public boolean ButPstNewAvail;
		public boolean ButPstDeleteAvail;
		public boolean TxtPstSrfAvail;
		public boolean TxtPstSrfActive;
		public boolean PupPstJtiAvail;
		public boolean PupPstJtiActive;
		public boolean ButPstJtiEditAvail;
		public boolean TxtPstTitAvail;
		public boolean TxtPstTitActive;
		public boolean TxtPstVerAvail;
		public boolean TxtPstVerActive;
		public boolean ButPstVerViewAvail;
		public boolean ButPstVerViewActive;
		public boolean PupPstScoAvail;
		public boolean PupPstScoActive;
		public boolean PupPstAtyAvail;
		public boolean PupPstAtyActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmVecDetail");

			String itemtag = "StatitemShrWznmVecDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfTgrValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfTgrValid", mask, TXFTGRVALID);
				TxfOptValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfOptValid", mask, TXFOPTVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				TxtVerActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVerActive", mask, TXTVERACTIVE);
				ButVerViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", mask, BUTVERVIEWAVAIL);
				ButVerViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewActive", mask, BUTVERVIEWACTIVE);
				TxtHkuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtHkuActive", mask, TXTHKUACTIVE);
				ButHkuViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButHkuViewAvail", mask, BUTHKUVIEWAVAIL);
				ButHkuViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButHkuViewActive", mask, BUTHKUVIEWACTIVE);
				PupTgrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTgrActive", mask, PUPTGRACTIVE);
				ButTgrEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTgrEditAvail", mask, BUTTGREDITAVAIL);
				LstOptActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptActive", mask, LSTOPTACTIVE);
				ButOptEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButOptEditAvail", mask, BUTOPTEDITAVAIL);
				ButPstNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPstNewAvail", mask, BUTPSTNEWAVAIL);
				ButPstDeleteAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPstDeleteAvail", mask, BUTPSTDELETEAVAIL);
				TxtPstSrfAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPstSrfAvail", mask, TXTPSTSRFAVAIL);
				TxtPstSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPstSrfActive", mask, TXTPSTSRFACTIVE);
				PupPstJtiAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPstJtiAvail", mask, PUPPSTJTIAVAIL);
				PupPstJtiActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPstJtiActive", mask, PUPPSTJTIACTIVE);
				ButPstJtiEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPstJtiEditAvail", mask, BUTPSTJTIEDITAVAIL);
				TxtPstTitAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPstTitAvail", mask, TXTPSTTITAVAIL);
				TxtPstTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPstTitActive", mask, TXTPSTTITACTIVE);
				TxtPstVerAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPstVerAvail", mask, TXTPSTVERAVAIL);
				TxtPstVerActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPstVerActive", mask, TXTPSTVERACTIVE);
				ButPstVerViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPstVerViewAvail", mask, BUTPSTVERVIEWAVAIL);
				ButPstVerViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPstVerViewActive", mask, BUTPSTVERVIEWACTIVE);
				PupPstScoAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPstScoAvail", mask, PUPPSTSCOAVAIL);
				PupPstScoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPstScoActive", mask, PUPPSTSCOACTIVE);
				PupPstAtyAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPstAtyAvail", mask, PUPPSTATYAVAIL);
				PupPstAtyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPstAtyActive", mask, PUPPSTATYACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfTgrValid == comp.TxfTgrValid) items.add(TXFTGRVALID);
			if (TxfOptValid == comp.TxfOptValid) items.add(TXFOPTVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (TxtVerActive == comp.TxtVerActive) items.add(TXTVERACTIVE);
			if (ButVerViewAvail == comp.ButVerViewAvail) items.add(BUTVERVIEWAVAIL);
			if (ButVerViewActive == comp.ButVerViewActive) items.add(BUTVERVIEWACTIVE);
			if (TxtHkuActive == comp.TxtHkuActive) items.add(TXTHKUACTIVE);
			if (ButHkuViewAvail == comp.ButHkuViewAvail) items.add(BUTHKUVIEWAVAIL);
			if (ButHkuViewActive == comp.ButHkuViewActive) items.add(BUTHKUVIEWACTIVE);
			if (PupTgrActive == comp.PupTgrActive) items.add(PUPTGRACTIVE);
			if (ButTgrEditAvail == comp.ButTgrEditAvail) items.add(BUTTGREDITAVAIL);
			if (LstOptActive == comp.LstOptActive) items.add(LSTOPTACTIVE);
			if (ButOptEditAvail == comp.ButOptEditAvail) items.add(BUTOPTEDITAVAIL);
			if (ButPstNewAvail == comp.ButPstNewAvail) items.add(BUTPSTNEWAVAIL);
			if (ButPstDeleteAvail == comp.ButPstDeleteAvail) items.add(BUTPSTDELETEAVAIL);
			if (TxtPstSrfAvail == comp.TxtPstSrfAvail) items.add(TXTPSTSRFAVAIL);
			if (TxtPstSrfActive == comp.TxtPstSrfActive) items.add(TXTPSTSRFACTIVE);
			if (PupPstJtiAvail == comp.PupPstJtiAvail) items.add(PUPPSTJTIAVAIL);
			if (PupPstJtiActive == comp.PupPstJtiActive) items.add(PUPPSTJTIACTIVE);
			if (ButPstJtiEditAvail == comp.ButPstJtiEditAvail) items.add(BUTPSTJTIEDITAVAIL);
			if (TxtPstTitAvail == comp.TxtPstTitAvail) items.add(TXTPSTTITAVAIL);
			if (TxtPstTitActive == comp.TxtPstTitActive) items.add(TXTPSTTITACTIVE);
			if (TxtPstVerAvail == comp.TxtPstVerAvail) items.add(TXTPSTVERAVAIL);
			if (TxtPstVerActive == comp.TxtPstVerActive) items.add(TXTPSTVERACTIVE);
			if (ButPstVerViewAvail == comp.ButPstVerViewAvail) items.add(BUTPSTVERVIEWAVAIL);
			if (ButPstVerViewActive == comp.ButPstVerViewActive) items.add(BUTPSTVERVIEWACTIVE);
			if (PupPstScoAvail == comp.PupPstScoAvail) items.add(PUPPSTSCOAVAIL);
			if (PupPstScoActive == comp.PupPstScoActive) items.add(PUPPSTSCOACTIVE);
			if (PupPstAtyAvail == comp.PupPstAtyAvail) items.add(PUPPSTATYAVAIL);
			if (PupPstAtyActive == comp.PupPstAtyActive) items.add(PUPPSTATYACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFTGRVALID, TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, PUPTGRACTIVE, BUTTGREDITAVAIL, LSTOPTACTIVE, BUTOPTEDITAVAIL, BUTPSTNEWAVAIL, BUTPSTDELETEAVAIL, TXTPSTSRFAVAIL, TXTPSTSRFACTIVE, PUPPSTJTIAVAIL, PUPPSTJTIACTIVE, BUTPSTJTIEDITAVAIL, TXTPSTTITAVAIL, TXTPSTTITACTIVE, TXTPSTVERAVAIL, TXTPSTVERACTIVE, BUTPSTVERVIEWAVAIL, BUTPSTVERVIEWACTIVE, PUPPSTSCOAVAIL, PUPPSTSCOACTIVE, PUPPSTATYAVAIL, PUPPSTATYACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmVecDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTYP = 3;
		public static final int CPTVER = 4;
		public static final int CPTHKU = 5;
		public static final int CPTTGR = 6;
		public static final int CPTOPT = 7;
		public static final int HDGPST = 8;
		public static final int CPTPSTSRF = 9;
		public static final int CPTPSTTIT = 10;
		public static final int CPTPSTVER = 11;
		public static final int CPTPSTSCO = 12;
		public static final int CPTPSTATY = 13;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTyp
					, String CptVer
					, String CptHku
					, String CptTgr
					, String CptOpt
					, String HdgPst
					, String CptPstSrf
					, String CptPstTit
					, String CptPstVer
					, String CptPstSco
					, String CptPstAty
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTyp = CptTyp;
			this.CptVer = CptVer;
			this.CptHku = CptHku;
			this.CptTgr = CptTgr;
			this.CptOpt = CptOpt;
			this.HdgPst = HdgPst;
			this.CptPstSrf = CptPstSrf;
			this.CptPstTit = CptPstTit;
			this.CptPstVer = CptPstVer;
			this.CptPstSco = CptPstSco;
			this.CptPstAty = CptPstAty;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTVER, CPTHKU, CPTTGR, CPTOPT, HDGPST, CPTPSTSRF, CPTPSTTIT, CPTPSTVER, CPTPSTSCO, CPTPSTATY));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTyp;
		public String CptVer;
		public String CptHku;
		public String CptTgr;
		public String CptOpt;
		public String HdgPst;
		public String CptPstSrf;
		public String CptPstTit;
		public String CptPstVer;
		public String CptPstSco;
		public String CptPstAty;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmVecDetail");

			String itemtag = "TagitemWznmVecDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptHku = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptHku", mask, CPTHKU);
				CptTgr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTgr", mask, CPTTGR);
				CptOpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOpt", mask, CPTOPT);
				HdgPst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgPst", mask, HDGPST);
				CptPstSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPstSrf", mask, CPTPSTSRF);
				CptPstTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPstTit", mask, CPTPSTTIT);
				CptPstVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPstVer", mask, CPTPSTVER);
				CptPstSco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPstSco", mask, CPTPSTSCO);
				CptPstAty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPstAty", mask, CPTPSTATY);

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
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);
			if (CptHku.equals(comp.CptHku)) items.add(CPTHKU);
			if (CptTgr.equals(comp.CptTgr)) items.add(CPTTGR);
			if (CptOpt.equals(comp.CptOpt)) items.add(CPTOPT);
			if (HdgPst.equals(comp.HdgPst)) items.add(HDGPST);
			if (CptPstSrf.equals(comp.CptPstSrf)) items.add(CPTPSTSRF);
			if (CptPstTit.equals(comp.CptPstTit)) items.add(CPTPSTTIT);
			if (CptPstVer.equals(comp.CptPstVer)) items.add(CPTPSTVER);
			if (CptPstSco.equals(comp.CptPstSco)) items.add(CPTPSTSCO);
			if (CptPstAty.equals(comp.CptPstAty)) items.add(CPTPSTATY);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTVER, CPTHKU, CPTTGR, CPTOPT, HDGPST, CPTPSTSRF, CPTPSTTIT, CPTPSTVER, CPTPSTSCO, CPTPSTATY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmVecDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMVECDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmVecDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmVecDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMVECDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmVecDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmVecDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTOPT = 4;
		public static final int FEEDFPUPHKT = 5;
		public static final int FEEDFPUPPSTATY = 6;
		public static final int FEEDFPUPPSTJTI = 7;
		public static final int FEEDFPUPPSTSCO = 8;
		public static final int FEEDFPUPTGR = 9;
		public static final int FEEDFPUPTYP = 10;
		public static final int STATAPP = 11;
		public static final int STATSHR = 12;
		public static final int TAG = 13;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMVECDETAILDATA);

			contiac = new ContIac(0, 0, 0, "", new ArrayList<Integer>(), "", 0, 0, 0);
			continf = new ContInf("", "", "", "", "", "");
			feedFLstOpt = new Feed("FeedFLstOpt");
			feedFPupHkt = new Feed("FeedFPupHkt");
			feedFPupPstAty = new Feed("FeedFPupPstAty");
			feedFPupPstJti = new Feed("FeedFPupPstJti");
			feedFPupPstSco = new Feed("FeedFPupPstSco");
			feedFPupTgr = new Feed("FeedFPupTgr");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0, false, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstOpt;
		public Feed feedFPupHkt;
		public Feed feedFPupPstAty;
		public Feed feedFPupPstJti;
		public Feed feedFPupPstSco;
		public Feed feedFPupTgr;
		public Feed feedFPupTyp;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTOPT)) ss.add("feedFLstOpt");
			if (has(FEEDFPUPHKT)) ss.add("feedFPupHkt");
			if (has(FEEDFPUPPSTATY)) ss.add("feedFPupPstAty");
			if (has(FEEDFPUPPSTJTI)) ss.add("feedFPupPstJti");
			if (has(FEEDFPUPPSTSCO)) ss.add("feedFPupPstSco");
			if (has(FEEDFPUPTGR)) ss.add("feedFPupTgr");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmVecDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstOpt.readXML(doc, basexpath, true)) add(FEEDFLSTOPT);
				if (feedFPupHkt.readXML(doc, basexpath, true)) add(FEEDFPUPHKT);
				if (feedFPupPstAty.readXML(doc, basexpath, true)) add(FEEDFPUPPSTATY);
				if (feedFPupPstJti.readXML(doc, basexpath, true)) add(FEEDFPUPPSTJTI);
				if (feedFPupPstSco.readXML(doc, basexpath, true)) add(FEEDFPUPPSTSCO);
				if (feedFPupTgr.readXML(doc, basexpath, true)) add(FEEDFPUPTGR);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, "", new ArrayList<Integer>(), "", 0, 0, 0);
				continf = new ContInf("", "", "", "", "", "");
				feedFLstOpt = new Feed("FeedFLstOpt");
				feedFPupHkt = new Feed("FeedFPupHkt");
				feedFPupPstAty = new Feed("FeedFPupPstAty");
				feedFPupPstJti = new Feed("FeedFPupPstJti");
				feedFPupPstSco = new Feed("FeedFPupPstSco");
				feedFPupTgr = new Feed("FeedFPupTgr");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0, false, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

