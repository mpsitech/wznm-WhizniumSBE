/**
  * \file PnlWznmSgeDetail.java
  * Java API code for job PnlWznmSgeDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmSgeDetail {
	/**
		* VecVDo (full: VecVWznmSgeDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTJOBVIEWCLICK = 2;
		public static final int BUTSNXVIEWCLICK = 3;
		public static final int BUTFNXVIEWCLICK = 4;
		public static final int BUTSQKNEWCLICK = 5;
		public static final int BUTSQKDELETECLICK = 6;
		public static final int BUTSQKJTIEDITCLICK = 7;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butjobviewclick")) return BUTJOBVIEWCLICK;
			if (s.equals("butsnxviewclick")) return BUTSNXVIEWCLICK;
			if (s.equals("butfnxviewclick")) return BUTFNXVIEWCLICK;
			if (s.equals("butsqknewclick")) return BUTSQKNEWCLICK;
			if (s.equals("butsqkdeleteclick")) return BUTSQKDELETECLICK;
			if (s.equals("butsqkjtieditclick")) return BUTSQKJTIEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");
			if (ix == BUTSNXVIEWCLICK) return("ButSnxViewClick");
			if (ix == BUTFNXVIEWCLICK) return("ButFnxViewClick");
			if (ix == BUTSQKNEWCLICK) return("ButSqkNewClick");
			if (ix == BUTSQKDELETECLICK) return("ButSqkDeleteClick");
			if (ix == BUTSQKJTIEDITCLICK) return("ButSqkJtiEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmSgeDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPTYP = 1;
		public static final int TXFMON = 2;
		public static final int TXFCMT = 3;
		public static final int NUMFPUPSQKJTI = 4;
		public static final int TXFSQKEXA = 5;

		public ContIac(
					int numFPupTyp
					, String TxfMon
					, String TxfCmt
					, int numFPupSqkJti
					, String TxfSqkExa
				) {
			this.numFPupTyp = numFPupTyp;
			this.TxfMon = TxfMon;
			this.TxfCmt = TxfCmt;
			this.numFPupSqkJti = numFPupSqkJti;
			this.TxfSqkExa = TxfSqkExa;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, TXFMON, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA));
		};

		public int numFPupTyp;
		public String TxfMon;
		public String TxfCmt;
		public int numFPupSqkJti;
		public String TxfSqkExa;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmSgeDetail");

			String itemtag = "ContitemIacWznmSgeDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				TxfMon = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfMon", mask, TXFMON);
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
			if (difftag.isEmpty()) difftag = "ContIacWznmSgeDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmSgeDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMon", TxfMon);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupSqkJti", numFPupSqkJti);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSqkExa", TxfSqkExa);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (TxfMon.equals(comp.TxfMon)) items.add(TXFMON);
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

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, TXFMON, TXFCMT, NUMFPUPSQKJTI, TXFSQKEXA));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmSgeDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTJOB = 2;
		public static final int TXTSNX = 3;
		public static final int TXTFNX = 4;
		public static final int TXTSQKTIT = 5;

		public ContInf(
					String TxtSrf
					, String TxtJob
					, String TxtSnx
					, String TxtFnx
					, String TxtSqkTit
				) {
			this.TxtSrf = TxtSrf;
			this.TxtJob = TxtJob;
			this.TxtSnx = TxtSnx;
			this.TxtFnx = TxtFnx;
			this.TxtSqkTit = TxtSqkTit;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTJOB, TXTSNX, TXTFNX, TXTSQKTIT));
		};

		public String TxtSrf;
		public String TxtJob;
		public String TxtSnx;
		public String TxtFnx;
		public String TxtSqkTit;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmSgeDetail");

			String itemtag = "ContitemInfWznmSgeDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtJob", mask, TXTJOB);
				TxtSnx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSnx", mask, TXTSNX);
				TxtFnx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtFnx", mask, TXTFNX);
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
			if (TxtJob.equals(comp.TxtJob)) items.add(TXTJOB);
			if (TxtSnx.equals(comp.TxtSnx)) items.add(TXTSNX);
			if (TxtFnx.equals(comp.TxtFnx)) items.add(TXTFNX);
			if (TxtSqkTit.equals(comp.TxtSqkTit)) items.add(TXTSQKTIT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTJOB, TXTSNX, TXTFNX, TXTSQKTIT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmSgeDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmSgeDetail");

			String itemtag = "StatitemAppWznmSgeDetail";

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
	  * StatShr (full: StatShrWznmSgeDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int PUPTYPACTIVE = 4;
		public static final int TXTJOBACTIVE = 5;
		public static final int BUTJOBVIEWAVAIL = 6;
		public static final int BUTJOBVIEWACTIVE = 7;
		public static final int TXFMONACTIVE = 8;
		public static final int TXTSNXACTIVE = 9;
		public static final int BUTSNXVIEWAVAIL = 10;
		public static final int BUTSNXVIEWACTIVE = 11;
		public static final int TXTFNXACTIVE = 12;
		public static final int BUTFNXVIEWAVAIL = 13;
		public static final int BUTFNXVIEWACTIVE = 14;
		public static final int TXFCMTACTIVE = 15;
		public static final int BUTSQKNEWAVAIL = 16;
		public static final int BUTSQKDELETEAVAIL = 17;
		public static final int PUPSQKJTIAVAIL = 18;
		public static final int PUPSQKJTIACTIVE = 19;
		public static final int BUTSQKJTIEDITAVAIL = 20;
		public static final int TXTSQKTITAVAIL = 21;
		public static final int TXTSQKTITACTIVE = 22;
		public static final int TXFSQKEXAAVAIL = 23;
		public static final int TXFSQKEXAACTIVE = 24;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupTypActive
					, boolean TxtJobActive
					, boolean ButJobViewAvail
					, boolean ButJobViewActive
					, boolean TxfMonActive
					, boolean TxtSnxActive
					, boolean ButSnxViewAvail
					, boolean ButSnxViewActive
					, boolean TxtFnxActive
					, boolean ButFnxViewAvail
					, boolean ButFnxViewActive
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
			this.PupTypActive = PupTypActive;
			this.TxtJobActive = TxtJobActive;
			this.ButJobViewAvail = ButJobViewAvail;
			this.ButJobViewActive = ButJobViewActive;
			this.TxfMonActive = TxfMonActive;
			this.TxtSnxActive = TxtSnxActive;
			this.ButSnxViewAvail = ButSnxViewAvail;
			this.ButSnxViewActive = ButSnxViewActive;
			this.TxtFnxActive = TxtFnxActive;
			this.ButFnxViewAvail = ButFnxViewAvail;
			this.ButFnxViewActive = ButFnxViewActive;
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

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFMONACTIVE, TXTSNXACTIVE, BUTSNXVIEWAVAIL, BUTSNXVIEWACTIVE, TXTFNXACTIVE, BUTFNXVIEWAVAIL, BUTFNXVIEWACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupTypActive;
		public boolean TxtJobActive;
		public boolean ButJobViewAvail;
		public boolean ButJobViewActive;
		public boolean TxfMonActive;
		public boolean TxtSnxActive;
		public boolean ButSnxViewAvail;
		public boolean ButSnxViewActive;
		public boolean TxtFnxActive;
		public boolean ButFnxViewAvail;
		public boolean ButFnxViewActive;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmSgeDetail");

			String itemtag = "StatitemShrWznmSgeDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				TxtJobActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtJobActive", mask, TXTJOBACTIVE);
				ButJobViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJobViewAvail", mask, BUTJOBVIEWAVAIL);
				ButJobViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJobViewActive", mask, BUTJOBVIEWACTIVE);
				TxfMonActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfMonActive", mask, TXFMONACTIVE);
				TxtSnxActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSnxActive", mask, TXTSNXACTIVE);
				ButSnxViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSnxViewAvail", mask, BUTSNXVIEWAVAIL);
				ButSnxViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSnxViewActive", mask, BUTSNXVIEWACTIVE);
				TxtFnxActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtFnxActive", mask, TXTFNXACTIVE);
				ButFnxViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFnxViewAvail", mask, BUTFNXVIEWAVAIL);
				ButFnxViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFnxViewActive", mask, BUTFNXVIEWACTIVE);
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
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (TxtJobActive == comp.TxtJobActive) items.add(TXTJOBACTIVE);
			if (ButJobViewAvail == comp.ButJobViewAvail) items.add(BUTJOBVIEWAVAIL);
			if (ButJobViewActive == comp.ButJobViewActive) items.add(BUTJOBVIEWACTIVE);
			if (TxfMonActive == comp.TxfMonActive) items.add(TXFMONACTIVE);
			if (TxtSnxActive == comp.TxtSnxActive) items.add(TXTSNXACTIVE);
			if (ButSnxViewAvail == comp.ButSnxViewAvail) items.add(BUTSNXVIEWAVAIL);
			if (ButSnxViewActive == comp.ButSnxViewActive) items.add(BUTSNXVIEWACTIVE);
			if (TxtFnxActive == comp.TxtFnxActive) items.add(TXTFNXACTIVE);
			if (ButFnxViewAvail == comp.ButFnxViewAvail) items.add(BUTFNXVIEWAVAIL);
			if (ButFnxViewActive == comp.ButFnxViewActive) items.add(BUTFNXVIEWACTIVE);
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

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFMONACTIVE, TXTSNXACTIVE, BUTSNXVIEWAVAIL, BUTSNXVIEWACTIVE, TXTFNXACTIVE, BUTFNXVIEWAVAIL, BUTFNXVIEWACTIVE, TXFCMTACTIVE, BUTSQKNEWAVAIL, BUTSQKDELETEAVAIL, PUPSQKJTIAVAIL, PUPSQKJTIACTIVE, BUTSQKJTIEDITAVAIL, TXTSQKTITAVAIL, TXTSQKTITACTIVE, TXFSQKEXAAVAIL, TXFSQKEXAACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmSgeDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTYP = 3;
		public static final int CPTJOB = 4;
		public static final int CPTMON = 5;
		public static final int CPTSNX = 6;
		public static final int CPTFNX = 7;
		public static final int CPTCMT = 8;
		public static final int HDGSQK = 9;
		public static final int CPTSQKTIT = 10;
		public static final int CPTSQKEXA = 11;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTyp
					, String CptJob
					, String CptMon
					, String CptSnx
					, String CptFnx
					, String CptCmt
					, String HdgSqk
					, String CptSqkTit
					, String CptSqkExa
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTyp = CptTyp;
			this.CptJob = CptJob;
			this.CptMon = CptMon;
			this.CptSnx = CptSnx;
			this.CptFnx = CptFnx;
			this.CptCmt = CptCmt;
			this.HdgSqk = HdgSqk;
			this.CptSqkTit = CptSqkTit;
			this.CptSqkExa = CptSqkExa;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTJOB, CPTMON, CPTSNX, CPTFNX, CPTCMT, HDGSQK, CPTSQKTIT, CPTSQKEXA));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTyp;
		public String CptJob;
		public String CptMon;
		public String CptSnx;
		public String CptFnx;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmSgeDetail");

			String itemtag = "TagitemWznmSgeDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptJob", mask, CPTJOB);
				CptMon = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMon", mask, CPTMON);
				CptSnx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSnx", mask, CPTSNX);
				CptFnx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFnx", mask, CPTFNX);
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
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptJob.equals(comp.CptJob)) items.add(CPTJOB);
			if (CptMon.equals(comp.CptMon)) items.add(CPTMON);
			if (CptSnx.equals(comp.CptSnx)) items.add(CPTSNX);
			if (CptFnx.equals(comp.CptFnx)) items.add(CPTFNX);
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

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTJOB, CPTMON, CPTSNX, CPTFNX, CPTCMT, HDGSQK, CPTSQKTIT, CPTSQKEXA));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmSgeDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMSGEDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmSgeDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmSgeDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMSGEDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmSgeDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmSgeDetailData)
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
			super(VecWznmVDpch.DPCHENGWZNMSGEDETAILDATA);

			contiac = new ContIac(0, "", "", 0, "");
			continf = new ContInf("", "", "", "", "");
			feedFPupSqkJti = new Feed("FeedFPupSqkJti");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmSgeDetailData");

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
				contiac = new ContIac(0, "", "", 0, "");
				continf = new ContInf("", "", "", "", "");
				feedFPupSqkJti = new Feed("FeedFPupSqkJti");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};
