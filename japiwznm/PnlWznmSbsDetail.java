/**
  * \file PnlWznmSbsDetail.java
  * Java API code for job PnlWznmSbsDetail
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmSbsDetail {
	/**
		* VecVDo (full: VecVWznmSbsDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTCARVIEWCLICK = 2;
		public static final int BUTPSTNEWCLICK = 3;
		public static final int BUTPSTDELETECLICK = 4;
		public static final int BUTPSTJTIEDITCLICK = 5;
		public static final int BUTPSTVERVIEWCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butcarviewclick")) return BUTCARVIEWCLICK;
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
			if (ix == BUTCARVIEWCLICK) return("ButCarViewClick");
			if (ix == BUTPSTNEWCLICK) return("ButPstNewClick");
			if (ix == BUTPSTDELETECLICK) return("ButPstDeleteClick");
			if (ix == BUTPSTJTIEDITCLICK) return("ButPstJtiEditClick");
			if (ix == BUTPSTVERVIEWCLICK) return("ButPstVerViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmSbsDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFSHO = 1;
		public static final int TXFCND = 2;
		public static final int TXFCMT = 3;
		public static final int NUMFPUPPSTJTI = 4;
		public static final int NUMFPUPPSTSCO = 5;
		public static final int NUMFPUPPSTATY = 6;

		public ContIac(
					String TxfSho
					, String TxfCnd
					, String TxfCmt
					, int numFPupPstJti
					, int numFPupPstSco
					, int numFPupPstAty
				) {
			this.TxfSho = TxfSho;
			this.TxfCnd = TxfCnd;
			this.TxfCmt = TxfCmt;
			this.numFPupPstJti = numFPupPstJti;
			this.numFPupPstSco = numFPupPstSco;
			this.numFPupPstAty = numFPupPstAty;

			mask = new HashSet<Integer>(Arrays.asList(TXFSHO, TXFCND, TXFCMT, NUMFPUPPSTJTI, NUMFPUPPSTSCO, NUMFPUPPSTATY));
		};

		public String TxfSho;
		public String TxfCnd;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmSbsDetail");

			String itemtag = "ContitemIacWznmSbsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSho", mask, TXFSHO);
				TxfCnd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCnd", mask, TXFCND);
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
			if (difftag.isEmpty()) difftag = "ContIacWznmSbsDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmSbsDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSho", TxfSho);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCnd", TxfCnd);
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
			if (TxfCnd.equals(comp.TxfCnd)) items.add(TXFCND);
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

			diffitems = new HashSet<Integer>(Arrays.asList(TXFSHO, TXFCND, TXFCMT, NUMFPUPPSTJTI, NUMFPUPPSTSCO, NUMFPUPPSTATY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmSbsDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTTBL = 2;
		public static final int TXTCAR = 3;
		public static final int TXTPSTSRF = 4;
		public static final int TXTPSTTIT = 5;
		public static final int TXTPSTVER = 6;

		public ContInf(
					String TxtSrf
					, String TxtTbl
					, String TxtCar
					, String TxtPstSrf
					, String TxtPstTit
					, String TxtPstVer
				) {
			this.TxtSrf = TxtSrf;
			this.TxtTbl = TxtTbl;
			this.TxtCar = TxtCar;
			this.TxtPstSrf = TxtPstSrf;
			this.TxtPstTit = TxtPstTit;
			this.TxtPstVer = TxtPstVer;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTBL, TXTCAR, TXTPSTSRF, TXTPSTTIT, TXTPSTVER));
		};

		public String TxtSrf;
		public String TxtTbl;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmSbsDetail");

			String itemtag = "ContitemInfWznmSbsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTbl", mask, TXTTBL);
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
			if (TxtTbl.equals(comp.TxtTbl)) items.add(TXTTBL);
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

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTBL, TXTCAR, TXTPSTSRF, TXTPSTTIT, TXTPSTVER));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmSbsDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmSbsDetail");

			String itemtag = "StatitemAppWznmSbsDetail";

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
	  * StatShr (full: StatShrWznmSbsDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int TXFSHOACTIVE = 4;
		public static final int TXTTBLACTIVE = 5;
		public static final int TXTCARACTIVE = 6;
		public static final int BUTCARVIEWAVAIL = 7;
		public static final int BUTCARVIEWACTIVE = 8;
		public static final int TXFCNDACTIVE = 9;
		public static final int TXFCMTACTIVE = 10;
		public static final int BUTPSTNEWAVAIL = 11;
		public static final int BUTPSTDELETEAVAIL = 12;
		public static final int TXTPSTSRFAVAIL = 13;
		public static final int TXTPSTSRFACTIVE = 14;
		public static final int PUPPSTJTIAVAIL = 15;
		public static final int PUPPSTJTIACTIVE = 16;
		public static final int BUTPSTJTIEDITAVAIL = 17;
		public static final int TXTPSTTITAVAIL = 18;
		public static final int TXTPSTTITACTIVE = 19;
		public static final int TXTPSTVERAVAIL = 20;
		public static final int TXTPSTVERACTIVE = 21;
		public static final int BUTPSTVERVIEWAVAIL = 22;
		public static final int BUTPSTVERVIEWACTIVE = 23;
		public static final int PUPPSTSCOAVAIL = 24;
		public static final int PUPPSTSCOACTIVE = 25;
		public static final int PUPPSTATYAVAIL = 26;
		public static final int PUPPSTATYACTIVE = 27;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxfShoActive
					, boolean TxtTblActive
					, boolean TxtCarActive
					, boolean ButCarViewAvail
					, boolean ButCarViewActive
					, boolean TxfCndActive
					, boolean TxfCmtActive
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
			this.TxtTblActive = TxtTblActive;
			this.TxtCarActive = TxtCarActive;
			this.ButCarViewAvail = ButCarViewAvail;
			this.ButCarViewActive = ButCarViewActive;
			this.TxfCndActive = TxfCndActive;
			this.TxfCmtActive = TxfCmtActive;
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

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, TXTTBLACTIVE, TXTCARACTIVE, BUTCARVIEWAVAIL, BUTCARVIEWACTIVE, TXFCNDACTIVE, TXFCMTACTIVE, BUTPSTNEWAVAIL, BUTPSTDELETEAVAIL, TXTPSTSRFAVAIL, TXTPSTSRFACTIVE, PUPPSTJTIAVAIL, PUPPSTJTIACTIVE, BUTPSTJTIEDITAVAIL, TXTPSTTITAVAIL, TXTPSTTITACTIVE, TXTPSTVERAVAIL, TXTPSTVERACTIVE, BUTPSTVERVIEWAVAIL, BUTPSTVERVIEWACTIVE, PUPPSTSCOAVAIL, PUPPSTSCOACTIVE, PUPPSTATYAVAIL, PUPPSTATYACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxfShoActive;
		public boolean TxtTblActive;
		public boolean TxtCarActive;
		public boolean ButCarViewAvail;
		public boolean ButCarViewActive;
		public boolean TxfCndActive;
		public boolean TxfCmtActive;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmSbsDetail");

			String itemtag = "StatitemShrWznmSbsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxfShoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfShoActive", mask, TXFSHOACTIVE);
				TxtTblActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTblActive", mask, TXTTBLACTIVE);
				TxtCarActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCarActive", mask, TXTCARACTIVE);
				ButCarViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCarViewAvail", mask, BUTCARVIEWAVAIL);
				ButCarViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCarViewActive", mask, BUTCARVIEWACTIVE);
				TxfCndActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCndActive", mask, TXFCNDACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);
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
			if (TxtTblActive == comp.TxtTblActive) items.add(TXTTBLACTIVE);
			if (TxtCarActive == comp.TxtCarActive) items.add(TXTCARACTIVE);
			if (ButCarViewAvail == comp.ButCarViewAvail) items.add(BUTCARVIEWAVAIL);
			if (ButCarViewActive == comp.ButCarViewActive) items.add(BUTCARVIEWACTIVE);
			if (TxfCndActive == comp.TxfCndActive) items.add(TXFCNDACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);
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

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFSHOACTIVE, TXTTBLACTIVE, TXTCARACTIVE, BUTCARVIEWAVAIL, BUTCARVIEWACTIVE, TXFCNDACTIVE, TXFCMTACTIVE, BUTPSTNEWAVAIL, BUTPSTDELETEAVAIL, TXTPSTSRFAVAIL, TXTPSTSRFACTIVE, PUPPSTJTIAVAIL, PUPPSTJTIACTIVE, BUTPSTJTIEDITAVAIL, TXTPSTTITAVAIL, TXTPSTTITACTIVE, TXTPSTVERAVAIL, TXTPSTVERACTIVE, BUTPSTVERVIEWAVAIL, BUTPSTVERVIEWACTIVE, PUPPSTSCOAVAIL, PUPPSTSCOACTIVE, PUPPSTATYAVAIL, PUPPSTATYACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmSbsDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTSHO = 3;
		public static final int CPTTBL = 4;
		public static final int CPTCAR = 5;
		public static final int CPTCND = 6;
		public static final int CPTCMT = 7;
		public static final int HDGPST = 8;
		public static final int CPTPSTSRF = 9;
		public static final int CPTPSTTIT = 10;
		public static final int CPTPSTVER = 11;
		public static final int CPTPSTSCO = 12;
		public static final int CPTPSTATY = 13;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptSho
					, String CptTbl
					, String CptCar
					, String CptCnd
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
			this.CptTbl = CptTbl;
			this.CptCar = CptCar;
			this.CptCnd = CptCnd;
			this.CptCmt = CptCmt;
			this.HdgPst = HdgPst;
			this.CptPstSrf = CptPstSrf;
			this.CptPstTit = CptPstTit;
			this.CptPstVer = CptPstVer;
			this.CptPstSco = CptPstSco;
			this.CptPstAty = CptPstAty;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSHO, CPTTBL, CPTCAR, CPTCND, CPTCMT, HDGPST, CPTPSTSRF, CPTPSTTIT, CPTPSTVER, CPTPSTSCO, CPTPSTATY));
		};

		public String Cpt;
		public String CptSrf;
		public String CptSho;
		public String CptTbl;
		public String CptCar;
		public String CptCnd;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmSbsDetail");

			String itemtag = "TagitemWznmSbsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptSho = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSho", mask, CPTSHO);
				CptTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTbl", mask, CPTTBL);
				CptCar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCar", mask, CPTCAR);
				CptCnd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCnd", mask, CPTCND);
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
			if (CptTbl.equals(comp.CptTbl)) items.add(CPTTBL);
			if (CptCar.equals(comp.CptCar)) items.add(CPTCAR);
			if (CptCnd.equals(comp.CptCnd)) items.add(CPTCND);
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

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSHO, CPTTBL, CPTCAR, CPTCND, CPTCMT, HDGPST, CPTPSTSRF, CPTPSTTIT, CPTPSTVER, CPTPSTSCO, CPTPSTATY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmSbsDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMSBSDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmSbsDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmSbsDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMSBSDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmSbsDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmSbsDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPPSTATY = 4;
		public static final int FEEDFPUPPSTJTI = 5;
		public static final int FEEDFPUPPSTSCO = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMSBSDETAILDATA);

			contiac = new ContIac("", "", "", 0, 0, 0);
			continf = new ContInf("", "", "", "", "", "");
			feedFPupPstAty = new Feed("FeedFPupPstAty");
			feedFPupPstJti = new Feed("FeedFPupPstJti");
			feedFPupPstSco = new Feed("FeedFPupPstSco");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupPstAty;
		public Feed feedFPupPstJti;
		public Feed feedFPupPstSco;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPPSTATY)) ss.add("feedFPupPstAty");
			if (has(FEEDFPUPPSTJTI)) ss.add("feedFPupPstJti");
			if (has(FEEDFPUPPSTSCO)) ss.add("feedFPupPstSco");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmSbsDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupPstAty.readXML(doc, basexpath, true)) add(FEEDFPUPPSTATY);
				if (feedFPupPstJti.readXML(doc, basexpath, true)) add(FEEDFPUPPSTJTI);
				if (feedFPupPstSco.readXML(doc, basexpath, true)) add(FEEDFPUPPSTSCO);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", "", 0, 0, 0);
				continf = new ContInf("", "", "", "", "", "");
				feedFPupPstAty = new Feed("FeedFPupPstAty");
				feedFPupPstJti = new Feed("FeedFPupPstJti");
				feedFPupPstSco = new Feed("FeedFPupPstSco");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

