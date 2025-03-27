/**
  * \file PnlWznmTblDetail.java
  * Java API code for job PnlWznmTblDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmTblDetail {
	/**
		* VecVDo (full: VecVWznmTblDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTVERVIEWCLICK = 2;
		public static final int BUTREUVIEWCLICK = 3;
		public static final int BUTCARVIEWCLICK = 4;
		public static final int BUTUNQVIEWCLICK = 5;
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
			if (s.equals("butreuviewclick")) return BUTREUVIEWCLICK;
			if (s.equals("butcarviewclick")) return BUTCARVIEWCLICK;
			if (s.equals("butunqviewclick")) return BUTUNQVIEWCLICK;
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
			if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
			if (ix == BUTCARVIEWCLICK) return("ButCarViewClick");
			if (ix == BUTUNQVIEWCLICK) return("ButUnqViewClick");
			if (ix == BUTPSTNEWCLICK) return("ButPstNewClick");
			if (ix == BUTPSTDELETECLICK) return("ButPstDeleteClick");
			if (ix == BUTPSTJTIEDITCLICK) return("ButPstJtiEditClick");
			if (ix == BUTPSTVERVIEWCLICK) return("ButPstVerViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmTblDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFSHO = 1;
		public static final int NUMFPUPTYP = 2;
		public static final int NUMFPUPRET = 3;
		public static final int NUMFLSTUNQ = 4;
		public static final int TXFUNQ = 5;
		public static final int TXFCMT = 6;
		public static final int NUMFPUPPSTJTI = 7;
		public static final int NUMFPUPPSTSCO = 8;
		public static final int NUMFPUPPSTATY = 9;

		public ContIac(
					String TxfSho
					, int numFPupTyp
					, int numFPupRet
					, int numFLstUnq
					, String TxfUnq
					, String TxfCmt
					, int numFPupPstJti
					, int numFPupPstSco
					, int numFPupPstAty
				) {
			this.TxfSho = TxfSho;
			this.numFPupTyp = numFPupTyp;
			this.numFPupRet = numFPupRet;
			this.numFLstUnq = numFLstUnq;
			this.TxfUnq = TxfUnq;
			this.TxfCmt = TxfCmt;
			this.numFPupPstJti = numFPupPstJti;
			this.numFPupPstSco = numFPupPstSco;
			this.numFPupPstAty = numFPupPstAty;

			mask = new HashSet<Integer>(Arrays.asList(TXFSHO, NUMFPUPTYP, NUMFPUPRET, NUMFLSTUNQ, TXFUNQ, TXFCMT, NUMFPUPPSTJTI, NUMFPUPPSTSCO, NUMFPUPPSTATY));
		};

		public String TxfSho;
		public int numFPupTyp;
		public int numFPupRet;
		public int numFLstUnq;
		public String TxfUnq;
		public String TxfCmt;
		public int numFPupPstJti;
		public int numFPupPstSco;
		public int numFPupPstAty;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmTblDetail");

			String itemtag = "ContitemIacWznmTblDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSho", mask, TXFSHO);
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				numFPupRet = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupRet", mask, NUMFPUPRET);
				numFLstUnq = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstUnq", mask, NUMFLSTUNQ);
				TxfUnq = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfUnq", mask, TXFUNQ);
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCmt", mask, TXFCMT);
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
			if (difftag.isEmpty()) difftag = "ContIacWznmTblDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmTblDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSho", TxfSho);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupRet", numFPupRet);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstUnq", numFLstUnq);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfUnq", TxfUnq);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupPstJti", numFPupPstJti);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupPstSco", numFPupPstSco);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupPstAty", numFPupPstAty);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfSho.equals(comp.TxfSho)) items.add(TXFSHO);
			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (numFPupRet == comp.numFPupRet) items.add(NUMFPUPRET);
			if (numFLstUnq == comp.numFLstUnq) items.add(NUMFLSTUNQ);
			if (TxfUnq.equals(comp.TxfUnq)) items.add(TXFUNQ);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);
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

			diffitems = new HashSet<Integer>(Arrays.asList(TXFSHO, NUMFPUPTYP, NUMFPUPRET, NUMFLSTUNQ, TXFUNQ, TXFCMT, NUMFPUPPSTJTI, NUMFPUPPSTSCO, NUMFPUPPSTATY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmTblDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTVER = 2;
		public static final int TXTREU = 3;
		public static final int TXTCAR = 4;
		public static final int TXTPSTSRF = 5;
		public static final int TXTPSTTIT = 6;
		public static final int TXTPSTVER = 7;

		public ContInf(
					String TxtSrf
					, String TxtVer
					, String TxtReu
					, String TxtCar
					, String TxtPstSrf
					, String TxtPstTit
					, String TxtPstVer
				) {
			this.TxtSrf = TxtSrf;
			this.TxtVer = TxtVer;
			this.TxtReu = TxtReu;
			this.TxtCar = TxtCar;
			this.TxtPstSrf = TxtPstSrf;
			this.TxtPstTit = TxtPstTit;
			this.TxtPstVer = TxtPstVer;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTVER, TXTREU, TXTCAR, TXTPSTSRF, TXTPSTTIT, TXTPSTVER));
		};

		public String TxtSrf;
		public String TxtVer;
		public String TxtReu;
		public String TxtCar;
		public String TxtPstSrf;
		public String TxtPstTit;
		public String TxtPstVer;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmTblDetail");

			String itemtag = "ContitemInfWznmTblDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVer", mask, TXTVER);
				TxtReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtReu", mask, TXTREU);
				TxtCar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCar", mask, TXTCAR);
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
			if (TxtReu.equals(comp.TxtReu)) items.add(TXTREU);
			if (TxtCar.equals(comp.TxtCar)) items.add(TXTCAR);
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

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTVER, TXTREU, TXTCAR, TXTPSTSRF, TXTPSTTIT, TXTPSTVER));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmTblDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTUNQALT = 2;
		public static final int LSTUNQNUMFIRSTDISP = 3;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstUnqAlt
					, int LstUnqNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstUnqAlt = LstUnqAlt;
			this.LstUnqNumFirstdisp = LstUnqNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTUNQALT, LSTUNQNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstUnqAlt;
		public int LstUnqNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmTblDetail");

			String itemtag = "StatitemAppWznmTblDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstUnqAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUnqAlt", mask, LSTUNQALT);
				LstUnqNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUnqNumFirstdisp", mask, LSTUNQNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstUnqAlt == comp.LstUnqAlt) items.add(LSTUNQALT);
			if (LstUnqNumFirstdisp == comp.LstUnqNumFirstdisp) items.add(LSTUNQNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTUNQALT, LSTUNQNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmTblDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int TXFSHOACTIVE = 4;
		public static final int PUPTYPACTIVE = 5;
		public static final int TXTVERACTIVE = 6;
		public static final int BUTVERVIEWAVAIL = 7;
		public static final int BUTVERVIEWACTIVE = 8;
		public static final int TXTREUACTIVE = 9;
		public static final int BUTREUVIEWAVAIL = 10;
		public static final int BUTREUVIEWACTIVE = 11;
		public static final int TXTCARAVAIL = 12;
		public static final int TXTCARACTIVE = 13;
		public static final int BUTCARVIEWAVAIL = 14;
		public static final int BUTCARVIEWACTIVE = 15;
		public static final int LSTUNQAVAIL = 16;
		public static final int LSTUNQACTIVE = 17;
		public static final int TXFUNQVALID = 18;
		public static final int BUTUNQVIEWAVAIL = 19;
		public static final int BUTUNQVIEWACTIVE = 20;
		public static final int TXFCMTACTIVE = 21;
		public static final int SEPPSTAVAIL = 22;
		public static final int HDGPSTAVAIL = 23;
		public static final int BUTPSTNEWAVAIL = 24;
		public static final int BUTPSTDELETEAVAIL = 25;
		public static final int TXTPSTSRFAVAIL = 26;
		public static final int TXTPSTSRFACTIVE = 27;
		public static final int PUPPSTJTIAVAIL = 28;
		public static final int PUPPSTJTIACTIVE = 29;
		public static final int BUTPSTJTIEDITAVAIL = 30;
		public static final int TXTPSTTITAVAIL = 31;
		public static final int TXTPSTTITACTIVE = 32;
		public static final int TXTPSTVERAVAIL = 33;
		public static final int TXTPSTVERACTIVE = 34;
		public static final int BUTPSTVERVIEWAVAIL = 35;
		public static final int BUTPSTVERVIEWACTIVE = 36;
		public static final int PUPPSTSCOAVAIL = 37;
		public static final int PUPPSTSCOACTIVE = 38;
		public static final int PUPPSTATYAVAIL = 39;
		public static final int PUPPSTATYACTIVE = 40;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxfShoActive
					, boolean PupTypActive
					, boolean TxtVerActive
					, boolean ButVerViewAvail
					, boolean ButVerViewActive
					, boolean TxtReuActive
					, boolean ButReuViewAvail
					, boolean ButReuViewActive
					, boolean TxtCarAvail
					, boolean TxtCarActive
					, boolean ButCarViewAvail
					, boolean ButCarViewActive
					, boolean LstUnqAvail
					, boolean LstUnqActive
					, boolean TxfUnqValid
					, boolean ButUnqViewAvail
					, boolean ButUnqViewActive
					, boolean TxfCmtActive
					, boolean SepPstAvail
					, boolean HdgPstAvail
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
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxfShoActive = TxfShoActive;
			this.PupTypActive = PupTypActive;
			this.TxtVerActive = TxtVerActive;
			this.ButVerViewAvail = ButVerViewAvail;
			this.ButVerViewActive = ButVerViewActive;
			this.TxtReuActive = TxtReuActive;
			this.ButReuViewAvail = ButReuViewAvail;
			this.ButReuViewActive = ButReuViewActive;
			this.TxtCarAvail = TxtCarAvail;
			this.TxtCarActive = TxtCarActive;
			this.ButCarViewAvail = ButCarViewAvail;
			this.ButCarViewActive = ButCarViewActive;
			this.LstUnqAvail = LstUnqAvail;
			this.LstUnqActive = LstUnqActive;
			this.TxfUnqValid = TxfUnqValid;
			this.ButUnqViewAvail = ButUnqViewAvail;
			this.ButUnqViewActive = ButUnqViewActive;
			this.TxfCmtActive = TxfCmtActive;
			this.SepPstAvail = SepPstAvail;
			this.HdgPstAvail = HdgPstAvail;
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

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTCARAVAIL, TXTCARACTIVE, BUTCARVIEWAVAIL, BUTCARVIEWACTIVE, LSTUNQAVAIL, LSTUNQACTIVE, TXFUNQVALID, BUTUNQVIEWAVAIL, BUTUNQVIEWACTIVE, TXFCMTACTIVE, SEPPSTAVAIL, HDGPSTAVAIL, BUTPSTNEWAVAIL, BUTPSTDELETEAVAIL, TXTPSTSRFAVAIL, TXTPSTSRFACTIVE, PUPPSTJTIAVAIL, PUPPSTJTIACTIVE, BUTPSTJTIEDITAVAIL, TXTPSTTITAVAIL, TXTPSTTITACTIVE, TXTPSTVERAVAIL, TXTPSTVERACTIVE, BUTPSTVERVIEWAVAIL, BUTPSTVERVIEWACTIVE, PUPPSTSCOAVAIL, PUPPSTSCOACTIVE, PUPPSTATYAVAIL, PUPPSTATYACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxfShoActive;
		public boolean PupTypActive;
		public boolean TxtVerActive;
		public boolean ButVerViewAvail;
		public boolean ButVerViewActive;
		public boolean TxtReuActive;
		public boolean ButReuViewAvail;
		public boolean ButReuViewActive;
		public boolean TxtCarAvail;
		public boolean TxtCarActive;
		public boolean ButCarViewAvail;
		public boolean ButCarViewActive;
		public boolean LstUnqAvail;
		public boolean LstUnqActive;
		public boolean TxfUnqValid;
		public boolean ButUnqViewAvail;
		public boolean ButUnqViewActive;
		public boolean TxfCmtActive;
		public boolean SepPstAvail;
		public boolean HdgPstAvail;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmTblDetail");

			String itemtag = "StatitemShrWznmTblDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxfShoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfShoActive", mask, TXFSHOACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				TxtVerActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVerActive", mask, TXTVERACTIVE);
				ButVerViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", mask, BUTVERVIEWAVAIL);
				ButVerViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewActive", mask, BUTVERVIEWACTIVE);
				TxtReuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtReuActive", mask, TXTREUACTIVE);
				ButReuViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", mask, BUTREUVIEWAVAIL);
				ButReuViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewActive", mask, BUTREUVIEWACTIVE);
				TxtCarAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCarAvail", mask, TXTCARAVAIL);
				TxtCarActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCarActive", mask, TXTCARACTIVE);
				ButCarViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCarViewAvail", mask, BUTCARVIEWAVAIL);
				ButCarViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCarViewActive", mask, BUTCARVIEWACTIVE);
				LstUnqAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUnqAvail", mask, LSTUNQAVAIL);
				LstUnqActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUnqActive", mask, LSTUNQACTIVE);
				TxfUnqValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfUnqValid", mask, TXFUNQVALID);
				ButUnqViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUnqViewAvail", mask, BUTUNQVIEWAVAIL);
				ButUnqViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUnqViewActive", mask, BUTUNQVIEWACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);
				SepPstAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SepPstAvail", mask, SEPPSTAVAIL);
				HdgPstAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "HdgPstAvail", mask, HDGPSTAVAIL);
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

			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (TxfShoActive == comp.TxfShoActive) items.add(TXFSHOACTIVE);
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (TxtVerActive == comp.TxtVerActive) items.add(TXTVERACTIVE);
			if (ButVerViewAvail == comp.ButVerViewAvail) items.add(BUTVERVIEWAVAIL);
			if (ButVerViewActive == comp.ButVerViewActive) items.add(BUTVERVIEWACTIVE);
			if (TxtReuActive == comp.TxtReuActive) items.add(TXTREUACTIVE);
			if (ButReuViewAvail == comp.ButReuViewAvail) items.add(BUTREUVIEWAVAIL);
			if (ButReuViewActive == comp.ButReuViewActive) items.add(BUTREUVIEWACTIVE);
			if (TxtCarAvail == comp.TxtCarAvail) items.add(TXTCARAVAIL);
			if (TxtCarActive == comp.TxtCarActive) items.add(TXTCARACTIVE);
			if (ButCarViewAvail == comp.ButCarViewAvail) items.add(BUTCARVIEWAVAIL);
			if (ButCarViewActive == comp.ButCarViewActive) items.add(BUTCARVIEWACTIVE);
			if (LstUnqAvail == comp.LstUnqAvail) items.add(LSTUNQAVAIL);
			if (LstUnqActive == comp.LstUnqActive) items.add(LSTUNQACTIVE);
			if (TxfUnqValid == comp.TxfUnqValid) items.add(TXFUNQVALID);
			if (ButUnqViewAvail == comp.ButUnqViewAvail) items.add(BUTUNQVIEWAVAIL);
			if (ButUnqViewActive == comp.ButUnqViewActive) items.add(BUTUNQVIEWACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);
			if (SepPstAvail == comp.SepPstAvail) items.add(SEPPSTAVAIL);
			if (HdgPstAvail == comp.HdgPstAvail) items.add(HDGPSTAVAIL);
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

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTCARAVAIL, TXTCARACTIVE, BUTCARVIEWAVAIL, BUTCARVIEWACTIVE, LSTUNQAVAIL, LSTUNQACTIVE, TXFUNQVALID, BUTUNQVIEWAVAIL, BUTUNQVIEWACTIVE, TXFCMTACTIVE, SEPPSTAVAIL, HDGPSTAVAIL, BUTPSTNEWAVAIL, BUTPSTDELETEAVAIL, TXTPSTSRFAVAIL, TXTPSTSRFACTIVE, PUPPSTJTIAVAIL, PUPPSTJTIACTIVE, BUTPSTJTIEDITAVAIL, TXTPSTTITAVAIL, TXTPSTTITACTIVE, TXTPSTVERAVAIL, TXTPSTVERACTIVE, BUTPSTVERVIEWAVAIL, BUTPSTVERVIEWACTIVE, PUPPSTSCOAVAIL, PUPPSTSCOACTIVE, PUPPSTATYAVAIL, PUPPSTATYACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmTblDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTSHO = 3;
		public static final int CPTTYP = 4;
		public static final int CPTVER = 5;
		public static final int CPTREU = 6;
		public static final int CPTCAR = 7;
		public static final int CPTUNQ = 8;
		public static final int CPTCMT = 9;
		public static final int HDGPST = 10;
		public static final int CPTPSTSRF = 11;
		public static final int CPTPSTTIT = 12;
		public static final int CPTPSTVER = 13;
		public static final int CPTPSTSCO = 14;
		public static final int CPTPSTATY = 15;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptSho
					, String CptTyp
					, String CptVer
					, String CptReu
					, String CptCar
					, String CptUnq
					, String CptCmt
					, String HdgPst
					, String CptPstSrf
					, String CptPstTit
					, String CptPstVer
					, String CptPstSco
					, String CptPstAty
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptSho = CptSho;
			this.CptTyp = CptTyp;
			this.CptVer = CptVer;
			this.CptReu = CptReu;
			this.CptCar = CptCar;
			this.CptUnq = CptUnq;
			this.CptCmt = CptCmt;
			this.HdgPst = HdgPst;
			this.CptPstSrf = CptPstSrf;
			this.CptPstTit = CptPstTit;
			this.CptPstVer = CptPstVer;
			this.CptPstSco = CptPstSco;
			this.CptPstAty = CptPstAty;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSHO, CPTTYP, CPTVER, CPTREU, CPTCAR, CPTUNQ, CPTCMT, HDGPST, CPTPSTSRF, CPTPSTTIT, CPTPSTVER, CPTPSTSCO, CPTPSTATY));
		};

		public String Cpt;
		public String CptSrf;
		public String CptSho;
		public String CptTyp;
		public String CptVer;
		public String CptReu;
		public String CptCar;
		public String CptUnq;
		public String CptCmt;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmTblDetail");

			String itemtag = "TagitemWznmTblDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSho", mask, CPTSHO);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptReu", mask, CPTREU);
				CptCar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCar", mask, CPTCAR);
				CptUnq = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUnq", mask, CPTUNQ);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);
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
			if (CptSho.equals(comp.CptSho)) items.add(CPTSHO);
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);
			if (CptReu.equals(comp.CptReu)) items.add(CPTREU);
			if (CptCar.equals(comp.CptCar)) items.add(CPTCAR);
			if (CptUnq.equals(comp.CptUnq)) items.add(CPTUNQ);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);
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

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSHO, CPTTYP, CPTVER, CPTREU, CPTCAR, CPTUNQ, CPTCMT, HDGPST, CPTPSTSRF, CPTPSTTIT, CPTPSTVER, CPTPSTSCO, CPTPSTATY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmTblDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMTBLDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmTblDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmTblDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMTBLDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmTblDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmTblDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTUNQ = 4;
		public static final int FEEDFPUPPSTATY = 5;
		public static final int FEEDFPUPPSTJTI = 6;
		public static final int FEEDFPUPPSTSCO = 7;
		public static final int FEEDFPUPRET = 8;
		public static final int FEEDFPUPTYP = 9;
		public static final int STATAPP = 10;
		public static final int STATSHR = 11;
		public static final int TAG = 12;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMTBLDETAILDATA);

			contiac = new ContIac("", 0, 0, 0, "", "", 0, 0, 0);
			continf = new ContInf("", "", "", "", "", "", "");
			feedFLstUnq = new Feed("FeedFLstUnq");
			feedFPupPstAty = new Feed("FeedFPupPstAty");
			feedFPupPstJti = new Feed("FeedFPupPstJti");
			feedFPupPstSco = new Feed("FeedFPupPstSco");
			feedFPupRet = new Feed("FeedFPupRet");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstUnq;
		public Feed feedFPupPstAty;
		public Feed feedFPupPstJti;
		public Feed feedFPupPstSco;
		public Feed feedFPupRet;
		public Feed feedFPupTyp;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTUNQ)) ss.add("feedFLstUnq");
			if (has(FEEDFPUPPSTATY)) ss.add("feedFPupPstAty");
			if (has(FEEDFPUPPSTJTI)) ss.add("feedFPupPstJti");
			if (has(FEEDFPUPPSTSCO)) ss.add("feedFPupPstSco");
			if (has(FEEDFPUPRET)) ss.add("feedFPupRet");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmTblDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstUnq.readXML(doc, basexpath, true)) add(FEEDFLSTUNQ);
				if (feedFPupPstAty.readXML(doc, basexpath, true)) add(FEEDFPUPPSTATY);
				if (feedFPupPstJti.readXML(doc, basexpath, true)) add(FEEDFPUPPSTJTI);
				if (feedFPupPstSco.readXML(doc, basexpath, true)) add(FEEDFPUPPSTSCO);
				if (feedFPupRet.readXML(doc, basexpath, true)) add(FEEDFPUPRET);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", 0, 0, 0, "", "", 0, 0, 0);
				continf = new ContInf("", "", "", "", "", "", "");
				feedFLstUnq = new Feed("FeedFLstUnq");
				feedFPupPstAty = new Feed("FeedFPupPstAty");
				feedFPupPstJti = new Feed("FeedFPupPstJti");
				feedFPupPstSco = new Feed("FeedFPupPstSco");
				feedFPupRet = new Feed("FeedFPupRet");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};
