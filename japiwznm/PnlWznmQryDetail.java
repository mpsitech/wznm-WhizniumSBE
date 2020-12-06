/**
  * \file PnlWznmQryDetail.java
  * Java API code for job PnlWznmQryDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmQryDetail {
	/**
		* VecVDo (full: VecVWznmQryDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTVERVIEWCLICK = 2;
		public static final int BUTSUPVIEWCLICK = 3;
		public static final int BUTJOBVIEWCLICK = 4;
		public static final int BUTINOVIEWCLICK = 5;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butverviewclick")) return BUTVERVIEWCLICK;
			if (s.equals("butsupviewclick")) return BUTSUPVIEWCLICK;
			if (s.equals("butjobviewclick")) return BUTJOBVIEWCLICK;
			if (s.equals("butinoviewclick")) return BUTINOVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
			if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
			if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");
			if (ix == BUTINOVIEWCLICK) return("ButInoViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmQryDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPTYP = 1;
		public static final int CHKLOF = 2;
		public static final int NUMFLSTINO = 3;
		public static final int TXFINO = 4;
		public static final int TXFCMT = 5;

		public ContIac(
					int numFPupTyp
					, boolean ChkLof
					, int numFLstIno
					, String TxfIno
					, String TxfCmt
				) {
			this.numFPupTyp = numFPupTyp;
			this.ChkLof = ChkLof;
			this.numFLstIno = numFLstIno;
			this.TxfIno = TxfIno;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, CHKLOF, NUMFLSTINO, TXFINO, TXFCMT));
		};

		public int numFPupTyp;
		public boolean ChkLof;
		public int numFLstIno;
		public String TxfIno;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmQryDetail");

			String itemtag = "ContitemIacWznmQryDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				ChkLof = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkLof", mask, CHKLOF);
				numFLstIno = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstIno", mask, NUMFLSTINO);
				TxfIno = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfIno", mask, TXFINO);
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
			if (difftag.isEmpty()) difftag = "ContIacWznmQryDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmQryDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkLof", ChkLof);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstIno", numFLstIno);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfIno", TxfIno);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (ChkLof == comp.ChkLof) items.add(CHKLOF);
			if (numFLstIno == comp.numFLstIno) items.add(NUMFLSTINO);
			if (TxfIno.equals(comp.TxfIno)) items.add(TXFINO);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, CHKLOF, NUMFLSTINO, TXFINO, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmQryDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTVER = 2;
		public static final int TXTSUP = 3;
		public static final int TXTTBL = 4;
		public static final int TXTQTB = 5;
		public static final int TXTJOB = 6;

		public ContInf(
					String TxtSrf
					, String TxtVer
					, String TxtSup
					, String TxtTbl
					, String TxtQtb
					, String TxtJob
				) {
			this.TxtSrf = TxtSrf;
			this.TxtVer = TxtVer;
			this.TxtSup = TxtSup;
			this.TxtTbl = TxtTbl;
			this.TxtQtb = TxtQtb;
			this.TxtJob = TxtJob;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTVER, TXTSUP, TXTTBL, TXTQTB, TXTJOB));
		};

		public String TxtSrf;
		public String TxtVer;
		public String TxtSup;
		public String TxtTbl;
		public String TxtQtb;
		public String TxtJob;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmQryDetail");

			String itemtag = "ContitemInfWznmQryDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVer", mask, TXTVER);
				TxtSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSup", mask, TXTSUP);
				TxtTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTbl", mask, TXTTBL);
				TxtQtb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtQtb", mask, TXTQTB);
				TxtJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtJob", mask, TXTJOB);

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
			if (TxtSup.equals(comp.TxtSup)) items.add(TXTSUP);
			if (TxtTbl.equals(comp.TxtTbl)) items.add(TXTTBL);
			if (TxtQtb.equals(comp.TxtQtb)) items.add(TXTQTB);
			if (TxtJob.equals(comp.TxtJob)) items.add(TXTJOB);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTVER, TXTSUP, TXTTBL, TXTQTB, TXTJOB));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmQryDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTINOALT = 2;
		public static final int LSTINONUMFIRSTDISP = 3;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstInoAlt
					, int LstInoNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstInoAlt = LstInoAlt;
			this.LstInoNumFirstdisp = LstInoNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTINOALT, LSTINONUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstInoAlt;
		public int LstInoNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmQryDetail");

			String itemtag = "StatitemAppWznmQryDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstInoAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstInoAlt", mask, LSTINOALT);
				LstInoNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstInoNumFirstdisp", mask, LSTINONUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstInoAlt == comp.LstInoAlt) items.add(LSTINOALT);
			if (LstInoNumFirstdisp == comp.LstInoNumFirstdisp) items.add(LSTINONUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTINOALT, LSTINONUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmQryDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFINOVALID = 1;
		public static final int BUTSAVEAVAIL = 2;
		public static final int BUTSAVEACTIVE = 3;
		public static final int TXTSRFACTIVE = 4;
		public static final int PUPTYPACTIVE = 5;
		public static final int TXTVERACTIVE = 6;
		public static final int BUTVERVIEWAVAIL = 7;
		public static final int BUTVERVIEWACTIVE = 8;
		public static final int TXTSUPACTIVE = 9;
		public static final int BUTSUPVIEWAVAIL = 10;
		public static final int BUTSUPVIEWACTIVE = 11;
		public static final int TXTTBLACTIVE = 12;
		public static final int TXTQTBACTIVE = 13;
		public static final int TXTJOBACTIVE = 14;
		public static final int BUTJOBVIEWAVAIL = 15;
		public static final int BUTJOBVIEWACTIVE = 16;
		public static final int CHKLOFACTIVE = 17;
		public static final int LSTINOACTIVE = 18;
		public static final int BUTINOVIEWAVAIL = 19;
		public static final int BUTINOVIEWACTIVE = 20;
		public static final int TXFCMTACTIVE = 21;

		public StatShr(
					boolean TxfInoValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupTypActive
					, boolean TxtVerActive
					, boolean ButVerViewAvail
					, boolean ButVerViewActive
					, boolean TxtSupActive
					, boolean ButSupViewAvail
					, boolean ButSupViewActive
					, boolean TxtTblActive
					, boolean TxtQtbActive
					, boolean TxtJobActive
					, boolean ButJobViewAvail
					, boolean ButJobViewActive
					, boolean ChkLofActive
					, boolean LstInoActive
					, boolean ButInoViewAvail
					, boolean ButInoViewActive
					, boolean TxfCmtActive
				) {
			this.TxfInoValid = TxfInoValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupTypActive = PupTypActive;
			this.TxtVerActive = TxtVerActive;
			this.ButVerViewAvail = ButVerViewAvail;
			this.ButVerViewActive = ButVerViewActive;
			this.TxtSupActive = TxtSupActive;
			this.ButSupViewAvail = ButSupViewAvail;
			this.ButSupViewActive = ButSupViewActive;
			this.TxtTblActive = TxtTblActive;
			this.TxtQtbActive = TxtQtbActive;
			this.TxtJobActive = TxtJobActive;
			this.ButJobViewAvail = ButJobViewAvail;
			this.ButJobViewActive = ButJobViewActive;
			this.ChkLofActive = ChkLofActive;
			this.LstInoActive = LstInoActive;
			this.ButInoViewAvail = ButInoViewAvail;
			this.ButInoViewActive = ButInoViewActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFINOVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, TXTQTBACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, CHKLOFACTIVE, LSTINOACTIVE, BUTINOVIEWAVAIL, BUTINOVIEWACTIVE, TXFCMTACTIVE));
		};

		public boolean TxfInoValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupTypActive;
		public boolean TxtVerActive;
		public boolean ButVerViewAvail;
		public boolean ButVerViewActive;
		public boolean TxtSupActive;
		public boolean ButSupViewAvail;
		public boolean ButSupViewActive;
		public boolean TxtTblActive;
		public boolean TxtQtbActive;
		public boolean TxtJobActive;
		public boolean ButJobViewAvail;
		public boolean ButJobViewActive;
		public boolean ChkLofActive;
		public boolean LstInoActive;
		public boolean ButInoViewAvail;
		public boolean ButInoViewActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmQryDetail");

			String itemtag = "StatitemShrWznmQryDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfInoValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfInoValid", mask, TXFINOVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				TxtVerActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVerActive", mask, TXTVERACTIVE);
				ButVerViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewAvail", mask, BUTVERVIEWAVAIL);
				ButVerViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewActive", mask, BUTVERVIEWACTIVE);
				TxtSupActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSupActive", mask, TXTSUPACTIVE);
				ButSupViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", mask, BUTSUPVIEWAVAIL);
				ButSupViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewActive", mask, BUTSUPVIEWACTIVE);
				TxtTblActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTblActive", mask, TXTTBLACTIVE);
				TxtQtbActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtQtbActive", mask, TXTQTBACTIVE);
				TxtJobActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtJobActive", mask, TXTJOBACTIVE);
				ButJobViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJobViewAvail", mask, BUTJOBVIEWAVAIL);
				ButJobViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJobViewActive", mask, BUTJOBVIEWACTIVE);
				ChkLofActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkLofActive", mask, CHKLOFACTIVE);
				LstInoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstInoActive", mask, LSTINOACTIVE);
				ButInoViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButInoViewAvail", mask, BUTINOVIEWAVAIL);
				ButInoViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButInoViewActive", mask, BUTINOVIEWACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfInoValid == comp.TxfInoValid) items.add(TXFINOVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (TxtVerActive == comp.TxtVerActive) items.add(TXTVERACTIVE);
			if (ButVerViewAvail == comp.ButVerViewAvail) items.add(BUTVERVIEWAVAIL);
			if (ButVerViewActive == comp.ButVerViewActive) items.add(BUTVERVIEWACTIVE);
			if (TxtSupActive == comp.TxtSupActive) items.add(TXTSUPACTIVE);
			if (ButSupViewAvail == comp.ButSupViewAvail) items.add(BUTSUPVIEWAVAIL);
			if (ButSupViewActive == comp.ButSupViewActive) items.add(BUTSUPVIEWACTIVE);
			if (TxtTblActive == comp.TxtTblActive) items.add(TXTTBLACTIVE);
			if (TxtQtbActive == comp.TxtQtbActive) items.add(TXTQTBACTIVE);
			if (TxtJobActive == comp.TxtJobActive) items.add(TXTJOBACTIVE);
			if (ButJobViewAvail == comp.ButJobViewAvail) items.add(BUTJOBVIEWAVAIL);
			if (ButJobViewActive == comp.ButJobViewActive) items.add(BUTJOBVIEWACTIVE);
			if (ChkLofActive == comp.ChkLofActive) items.add(CHKLOFACTIVE);
			if (LstInoActive == comp.LstInoActive) items.add(LSTINOACTIVE);
			if (ButInoViewAvail == comp.ButInoViewAvail) items.add(BUTINOVIEWAVAIL);
			if (ButInoViewActive == comp.ButInoViewActive) items.add(BUTINOVIEWACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFINOVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTVERACTIVE, BUTVERVIEWAVAIL, BUTVERVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTBLACTIVE, TXTQTBACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, CHKLOFACTIVE, LSTINOACTIVE, BUTINOVIEWAVAIL, BUTINOVIEWACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmQryDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTYP = 3;
		public static final int CPTVER = 4;
		public static final int CPTSUP = 5;
		public static final int CPTTBL = 6;
		public static final int CPTQTB = 7;
		public static final int CPTJOB = 8;
		public static final int CPTLOF = 9;
		public static final int CPTINO = 10;
		public static final int CPTCMT = 11;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTyp
					, String CptVer
					, String CptSup
					, String CptTbl
					, String CptQtb
					, String CptJob
					, String CptLof
					, String CptIno
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTyp = CptTyp;
			this.CptVer = CptVer;
			this.CptSup = CptSup;
			this.CptTbl = CptTbl;
			this.CptQtb = CptQtb;
			this.CptJob = CptJob;
			this.CptLof = CptLof;
			this.CptIno = CptIno;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTVER, CPTSUP, CPTTBL, CPTQTB, CPTJOB, CPTLOF, CPTINO, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTyp;
		public String CptVer;
		public String CptSup;
		public String CptTbl;
		public String CptQtb;
		public String CptJob;
		public String CptLof;
		public String CptIno;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmQryDetail");

			String itemtag = "TagitemWznmQryDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSup", mask, CPTSUP);
				CptTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTbl", mask, CPTTBL);
				CptQtb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptQtb", mask, CPTQTB);
				CptJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptJob", mask, CPTJOB);
				CptLof = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLof", mask, CPTLOF);
				CptIno = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIno", mask, CPTINO);
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
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);
			if (CptSup.equals(comp.CptSup)) items.add(CPTSUP);
			if (CptTbl.equals(comp.CptTbl)) items.add(CPTTBL);
			if (CptQtb.equals(comp.CptQtb)) items.add(CPTQTB);
			if (CptJob.equals(comp.CptJob)) items.add(CPTJOB);
			if (CptLof.equals(comp.CptLof)) items.add(CPTLOF);
			if (CptIno.equals(comp.CptIno)) items.add(CPTINO);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTVER, CPTSUP, CPTTBL, CPTQTB, CPTJOB, CPTLOF, CPTINO, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmQryDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMQRYDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmQryDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmQryDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMQRYDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmQryDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmQryDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTINO = 4;
		public static final int FEEDFPUPTYP = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMQRYDETAILDATA);

			contiac = new ContIac(0, false, 0, "", "");
			continf = new ContInf("", "", "", "", "", "");
			feedFLstIno = new Feed("FeedFLstIno");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstIno;
		public Feed feedFPupTyp;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTINO)) ss.add("feedFLstIno");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmQryDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstIno.readXML(doc, basexpath, true)) add(FEEDFLSTINO);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, false, 0, "", "");
				continf = new ContInf("", "", "", "", "", "");
				feedFLstIno = new Feed("FeedFLstIno");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};
