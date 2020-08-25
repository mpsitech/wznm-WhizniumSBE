/**
  * \file PnlWznmTblRec.java
  * Java API code for job PnlWznmTblRec
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmTblRec {
	/**
		* VecVDo (full: VecVWznmTblRecDo)
		*/
	public static class VecVDo {

		public static final int BUTMINIMIZECLICK = 1;
		public static final int BUTREGULARIZECLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWznmTblRec)
	  */
	public class ContInf extends Block {

		public static final int TXTREF = 1;

		public ContInf(
					String TxtRef
				) {
			this.TxtRef = TxtRef;

			mask = new HashSet<Integer>(Arrays.asList(TXTREF));
		};

		public String TxtRef;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmTblRec");

			String itemtag = "ContitemInfWznmTblRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtRef = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtRef", mask, TXTREF);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtRef.equals(comp.TxtRef)) items.add(TXTREF);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTREF));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmTblRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEATITLE = 2;
		public static final int INITDONEALOADFCT = 3;
		public static final int INITDONE1NSTUB = 4;
		public static final int INITDONETBL1NTABLECOL = 5;
		public static final int INITDONE1NCHECK = 6;
		public static final int INITDONE1NSUBSET = 7;
		public static final int INITDONE1NIMPEXP = 8;
		public static final int INITDONETO1NRELATION = 9;
		public static final int INITDONEFR1NRELATION = 10;
		public static final int INITDONEREF1NRTBLOCK = 11;
		public static final int INITDONEREF1NQUERYMOD = 12;
		public static final int INITDONEHK1NVECTOR = 13;
		public static final int INITDONEFCT1NTABLECOL = 14;
		public static final int INITDONESRC1NFEED = 15;
		public static final int INITDONEREF1NCALL = 16;
		public static final int INITDONEREF1NDIALOG = 17;
		public static final int INITDONEREF1NPANEL = 18;
		public static final int INITDONEPST1NQUERYMOD = 19;
		public static final int INITDONEMNVECTOR = 20;
		public static final int INITDONEMNQUERY = 21;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneATitle
					, boolean initdoneALoadfct
					, boolean initdone1NStub
					, boolean initdoneTbl1NTablecol
					, boolean initdone1NCheck
					, boolean initdone1NSubset
					, boolean initdone1NImpexp
					, boolean initdoneTo1NRelation
					, boolean initdoneFr1NRelation
					, boolean initdoneRef1NRtblock
					, boolean initdoneRef1NQuerymod
					, boolean initdoneHk1NVector
					, boolean initdoneFct1NTablecol
					, boolean initdoneSrc1NFeed
					, boolean initdoneRef1NCall
					, boolean initdoneRef1NDialog
					, boolean initdoneRef1NPanel
					, boolean initdonePst1NQuerymod
					, boolean initdoneMNVector
					, boolean initdoneMNQuery
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneATitle = initdoneATitle;
			this.initdoneALoadfct = initdoneALoadfct;
			this.initdone1NStub = initdone1NStub;
			this.initdoneTbl1NTablecol = initdoneTbl1NTablecol;
			this.initdone1NCheck = initdone1NCheck;
			this.initdone1NSubset = initdone1NSubset;
			this.initdone1NImpexp = initdone1NImpexp;
			this.initdoneTo1NRelation = initdoneTo1NRelation;
			this.initdoneFr1NRelation = initdoneFr1NRelation;
			this.initdoneRef1NRtblock = initdoneRef1NRtblock;
			this.initdoneRef1NQuerymod = initdoneRef1NQuerymod;
			this.initdoneHk1NVector = initdoneHk1NVector;
			this.initdoneFct1NTablecol = initdoneFct1NTablecol;
			this.initdoneSrc1NFeed = initdoneSrc1NFeed;
			this.initdoneRef1NCall = initdoneRef1NCall;
			this.initdoneRef1NDialog = initdoneRef1NDialog;
			this.initdoneRef1NPanel = initdoneRef1NPanel;
			this.initdonePst1NQuerymod = initdonePst1NQuerymod;
			this.initdoneMNVector = initdoneMNVector;
			this.initdoneMNQuery = initdoneMNQuery;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEATITLE, INITDONEALOADFCT, INITDONE1NSTUB, INITDONETBL1NTABLECOL, INITDONE1NCHECK, INITDONE1NSUBSET, INITDONE1NIMPEXP, INITDONETO1NRELATION, INITDONEFR1NRELATION, INITDONEREF1NRTBLOCK, INITDONEREF1NQUERYMOD, INITDONEHK1NVECTOR, INITDONEFCT1NTABLECOL, INITDONESRC1NFEED, INITDONEREF1NCALL, INITDONEREF1NDIALOG, INITDONEREF1NPANEL, INITDONEPST1NQUERYMOD, INITDONEMNVECTOR, INITDONEMNQUERY));
		};

		public boolean initdoneDetail;
		public boolean initdoneATitle;
		public boolean initdoneALoadfct;
		public boolean initdone1NStub;
		public boolean initdoneTbl1NTablecol;
		public boolean initdone1NCheck;
		public boolean initdone1NSubset;
		public boolean initdone1NImpexp;
		public boolean initdoneTo1NRelation;
		public boolean initdoneFr1NRelation;
		public boolean initdoneRef1NRtblock;
		public boolean initdoneRef1NQuerymod;
		public boolean initdoneHk1NVector;
		public boolean initdoneFct1NTablecol;
		public boolean initdoneSrc1NFeed;
		public boolean initdoneRef1NCall;
		public boolean initdoneRef1NDialog;
		public boolean initdoneRef1NPanel;
		public boolean initdonePst1NQuerymod;
		public boolean initdoneMNVector;
		public boolean initdoneMNQuery;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmTblRec");

			String itemtag = "StatitemAppWznmTblRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneATitle = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneATitle", mask, INITDONEATITLE);
				initdoneALoadfct = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneALoadfct", mask, INITDONEALOADFCT);
				initdone1NStub = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NStub", mask, INITDONE1NSTUB);
				initdoneTbl1NTablecol = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTbl1NTablecol", mask, INITDONETBL1NTABLECOL);
				initdone1NCheck = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NCheck", mask, INITDONE1NCHECK);
				initdone1NSubset = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NSubset", mask, INITDONE1NSUBSET);
				initdone1NImpexp = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NImpexp", mask, INITDONE1NIMPEXP);
				initdoneTo1NRelation = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTo1NRelation", mask, INITDONETO1NRELATION);
				initdoneFr1NRelation = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneFr1NRelation", mask, INITDONEFR1NRELATION);
				initdoneRef1NRtblock = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NRtblock", mask, INITDONEREF1NRTBLOCK);
				initdoneRef1NQuerymod = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NQuerymod", mask, INITDONEREF1NQUERYMOD);
				initdoneHk1NVector = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHk1NVector", mask, INITDONEHK1NVECTOR);
				initdoneFct1NTablecol = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneFct1NTablecol", mask, INITDONEFCT1NTABLECOL);
				initdoneSrc1NFeed = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSrc1NFeed", mask, INITDONESRC1NFEED);
				initdoneRef1NCall = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NCall", mask, INITDONEREF1NCALL);
				initdoneRef1NDialog = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NDialog", mask, INITDONEREF1NDIALOG);
				initdoneRef1NPanel = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NPanel", mask, INITDONEREF1NPANEL);
				initdonePst1NQuerymod = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdonePst1NQuerymod", mask, INITDONEPST1NQUERYMOD);
				initdoneMNVector = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNVector", mask, INITDONEMNVECTOR);
				initdoneMNQuery = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNQuery", mask, INITDONEMNQUERY);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdoneATitle == comp.initdoneATitle) items.add(INITDONEATITLE);
			if (initdoneALoadfct == comp.initdoneALoadfct) items.add(INITDONEALOADFCT);
			if (initdone1NStub == comp.initdone1NStub) items.add(INITDONE1NSTUB);
			if (initdoneTbl1NTablecol == comp.initdoneTbl1NTablecol) items.add(INITDONETBL1NTABLECOL);
			if (initdone1NCheck == comp.initdone1NCheck) items.add(INITDONE1NCHECK);
			if (initdone1NSubset == comp.initdone1NSubset) items.add(INITDONE1NSUBSET);
			if (initdone1NImpexp == comp.initdone1NImpexp) items.add(INITDONE1NIMPEXP);
			if (initdoneTo1NRelation == comp.initdoneTo1NRelation) items.add(INITDONETO1NRELATION);
			if (initdoneFr1NRelation == comp.initdoneFr1NRelation) items.add(INITDONEFR1NRELATION);
			if (initdoneRef1NRtblock == comp.initdoneRef1NRtblock) items.add(INITDONEREF1NRTBLOCK);
			if (initdoneRef1NQuerymod == comp.initdoneRef1NQuerymod) items.add(INITDONEREF1NQUERYMOD);
			if (initdoneHk1NVector == comp.initdoneHk1NVector) items.add(INITDONEHK1NVECTOR);
			if (initdoneFct1NTablecol == comp.initdoneFct1NTablecol) items.add(INITDONEFCT1NTABLECOL);
			if (initdoneSrc1NFeed == comp.initdoneSrc1NFeed) items.add(INITDONESRC1NFEED);
			if (initdoneRef1NCall == comp.initdoneRef1NCall) items.add(INITDONEREF1NCALL);
			if (initdoneRef1NDialog == comp.initdoneRef1NDialog) items.add(INITDONEREF1NDIALOG);
			if (initdoneRef1NPanel == comp.initdoneRef1NPanel) items.add(INITDONEREF1NPANEL);
			if (initdonePst1NQuerymod == comp.initdonePst1NQuerymod) items.add(INITDONEPST1NQUERYMOD);
			if (initdoneMNVector == comp.initdoneMNVector) items.add(INITDONEMNVECTOR);
			if (initdoneMNQuery == comp.initdoneMNQuery) items.add(INITDONEMNQUERY);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEATITLE, INITDONEALOADFCT, INITDONE1NSTUB, INITDONETBL1NTABLECOL, INITDONE1NCHECK, INITDONE1NSUBSET, INITDONE1NIMPEXP, INITDONETO1NRELATION, INITDONEFR1NRELATION, INITDONEREF1NRTBLOCK, INITDONEREF1NQUERYMOD, INITDONEHK1NVECTOR, INITDONEFCT1NTABLECOL, INITDONESRC1NFEED, INITDONEREF1NCALL, INITDONEREF1NDIALOG, INITDONEREF1NPANEL, INITDONEPST1NQUERYMOD, INITDONEMNVECTOR, INITDONEMNQUERY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmTblRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFATITLE = 3;
		public static final int PNLATITLEAVAIL = 4;
		public static final int SCRJREFALOADFCT = 5;
		public static final int PNLALOADFCTAVAIL = 6;
		public static final int SCRJREF1NSTUB = 7;
		public static final int PNL1NSTUBAVAIL = 8;
		public static final int SCRJREFTBL1NTABLECOL = 9;
		public static final int SCRJREF1NCHECK = 10;
		public static final int PNL1NCHECKAVAIL = 11;
		public static final int SCRJREF1NSUBSET = 12;
		public static final int PNL1NSUBSETAVAIL = 13;
		public static final int SCRJREF1NIMPEXP = 14;
		public static final int PNL1NIMPEXPAVAIL = 15;
		public static final int SCRJREFTO1NRELATION = 16;
		public static final int PNLTO1NRELATIONAVAIL = 17;
		public static final int SCRJREFFR1NRELATION = 18;
		public static final int PNLFR1NRELATIONAVAIL = 19;
		public static final int SCRJREFREF1NRTBLOCK = 20;
		public static final int SCRJREFREF1NQUERYMOD = 21;
		public static final int SCRJREFHK1NVECTOR = 22;
		public static final int SCRJREFFCT1NTABLECOL = 23;
		public static final int PNLFCT1NTABLECOLAVAIL = 24;
		public static final int SCRJREFSRC1NFEED = 25;
		public static final int SCRJREFREF1NCALL = 26;
		public static final int PNLREF1NCALLAVAIL = 27;
		public static final int SCRJREFREF1NDIALOG = 28;
		public static final int PNLREF1NDIALOGAVAIL = 29;
		public static final int SCRJREFREF1NPANEL = 30;
		public static final int SCRJREFPST1NQUERYMOD = 31;
		public static final int PNLPST1NQUERYMODAVAIL = 32;
		public static final int SCRJREFMNVECTOR = 33;
		public static final int PNLMNVECTORAVAIL = 34;
		public static final int SCRJREFMNQUERY = 35;
		public static final int PNLMNQUERYAVAIL = 36;
		public static final int BUTREGULARIZEACTIVE = 37;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefATitle
					, boolean pnlatitleAvail
					, String scrJrefALoadfct
					, boolean pnlaloadfctAvail
					, String scrJref1NStub
					, boolean pnl1nstubAvail
					, String scrJrefTbl1NTablecol
					, String scrJref1NCheck
					, boolean pnl1ncheckAvail
					, String scrJref1NSubset
					, boolean pnl1nsubsetAvail
					, String scrJref1NImpexp
					, boolean pnl1nimpexpAvail
					, String scrJrefTo1NRelation
					, boolean pnlto1nrelationAvail
					, String scrJrefFr1NRelation
					, boolean pnlfr1nrelationAvail
					, String scrJrefRef1NRtblock
					, String scrJrefRef1NQuerymod
					, String scrJrefHk1NVector
					, String scrJrefFct1NTablecol
					, boolean pnlfct1ntablecolAvail
					, String scrJrefSrc1NFeed
					, String scrJrefRef1NCall
					, boolean pnlref1ncallAvail
					, String scrJrefRef1NDialog
					, boolean pnlref1ndialogAvail
					, String scrJrefRef1NPanel
					, String scrJrefPst1NQuerymod
					, boolean pnlpst1nquerymodAvail
					, String scrJrefMNVector
					, boolean pnlmnvectorAvail
					, String scrJrefMNQuery
					, boolean pnlmnqueryAvail
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefATitle = scrJrefATitle;
			this.pnlatitleAvail = pnlatitleAvail;
			this.scrJrefALoadfct = scrJrefALoadfct;
			this.pnlaloadfctAvail = pnlaloadfctAvail;
			this.scrJref1NStub = scrJref1NStub;
			this.pnl1nstubAvail = pnl1nstubAvail;
			this.scrJrefTbl1NTablecol = scrJrefTbl1NTablecol;
			this.scrJref1NCheck = scrJref1NCheck;
			this.pnl1ncheckAvail = pnl1ncheckAvail;
			this.scrJref1NSubset = scrJref1NSubset;
			this.pnl1nsubsetAvail = pnl1nsubsetAvail;
			this.scrJref1NImpexp = scrJref1NImpexp;
			this.pnl1nimpexpAvail = pnl1nimpexpAvail;
			this.scrJrefTo1NRelation = scrJrefTo1NRelation;
			this.pnlto1nrelationAvail = pnlto1nrelationAvail;
			this.scrJrefFr1NRelation = scrJrefFr1NRelation;
			this.pnlfr1nrelationAvail = pnlfr1nrelationAvail;
			this.scrJrefRef1NRtblock = scrJrefRef1NRtblock;
			this.scrJrefRef1NQuerymod = scrJrefRef1NQuerymod;
			this.scrJrefHk1NVector = scrJrefHk1NVector;
			this.scrJrefFct1NTablecol = scrJrefFct1NTablecol;
			this.pnlfct1ntablecolAvail = pnlfct1ntablecolAvail;
			this.scrJrefSrc1NFeed = scrJrefSrc1NFeed;
			this.scrJrefRef1NCall = scrJrefRef1NCall;
			this.pnlref1ncallAvail = pnlref1ncallAvail;
			this.scrJrefRef1NDialog = scrJrefRef1NDialog;
			this.pnlref1ndialogAvail = pnlref1ndialogAvail;
			this.scrJrefRef1NPanel = scrJrefRef1NPanel;
			this.scrJrefPst1NQuerymod = scrJrefPst1NQuerymod;
			this.pnlpst1nquerymodAvail = pnlpst1nquerymodAvail;
			this.scrJrefMNVector = scrJrefMNVector;
			this.pnlmnvectorAvail = pnlmnvectorAvail;
			this.scrJrefMNQuery = scrJrefMNQuery;
			this.pnlmnqueryAvail = pnlmnqueryAvail;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, PNLATITLEAVAIL, SCRJREFALOADFCT, PNLALOADFCTAVAIL, SCRJREF1NSTUB, PNL1NSTUBAVAIL, SCRJREFTBL1NTABLECOL, SCRJREF1NCHECK, PNL1NCHECKAVAIL, SCRJREF1NSUBSET, PNL1NSUBSETAVAIL, SCRJREF1NIMPEXP, PNL1NIMPEXPAVAIL, SCRJREFTO1NRELATION, PNLTO1NRELATIONAVAIL, SCRJREFFR1NRELATION, PNLFR1NRELATIONAVAIL, SCRJREFREF1NRTBLOCK, SCRJREFREF1NQUERYMOD, SCRJREFHK1NVECTOR, SCRJREFFCT1NTABLECOL, PNLFCT1NTABLECOLAVAIL, SCRJREFSRC1NFEED, SCRJREFREF1NCALL, PNLREF1NCALLAVAIL, SCRJREFREF1NDIALOG, PNLREF1NDIALOGAVAIL, SCRJREFREF1NPANEL, SCRJREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, SCRJREFMNVECTOR, PNLMNVECTORAVAIL, SCRJREFMNQUERY, PNLMNQUERYAVAIL, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefATitle;
		public boolean pnlatitleAvail;
		public String scrJrefALoadfct;
		public boolean pnlaloadfctAvail;
		public String scrJref1NStub;
		public boolean pnl1nstubAvail;
		public String scrJrefTbl1NTablecol;
		public String scrJref1NCheck;
		public boolean pnl1ncheckAvail;
		public String scrJref1NSubset;
		public boolean pnl1nsubsetAvail;
		public String scrJref1NImpexp;
		public boolean pnl1nimpexpAvail;
		public String scrJrefTo1NRelation;
		public boolean pnlto1nrelationAvail;
		public String scrJrefFr1NRelation;
		public boolean pnlfr1nrelationAvail;
		public String scrJrefRef1NRtblock;
		public String scrJrefRef1NQuerymod;
		public String scrJrefHk1NVector;
		public String scrJrefFct1NTablecol;
		public boolean pnlfct1ntablecolAvail;
		public String scrJrefSrc1NFeed;
		public String scrJrefRef1NCall;
		public boolean pnlref1ncallAvail;
		public String scrJrefRef1NDialog;
		public boolean pnlref1ndialogAvail;
		public String scrJrefRef1NPanel;
		public String scrJrefPst1NQuerymod;
		public boolean pnlpst1nquerymodAvail;
		public String scrJrefMNVector;
		public boolean pnlmnvectorAvail;
		public String scrJrefMNQuery;
		public boolean pnlmnqueryAvail;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmTblRec");

			String itemtag = "StatitemShrWznmTblRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefATitle = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefATitle", mask, SCRJREFATITLE);
				pnlatitleAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlatitleAvail", mask, PNLATITLEAVAIL);
				scrJrefALoadfct = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefALoadfct", mask, SCRJREFALOADFCT);
				pnlaloadfctAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlaloadfctAvail", mask, PNLALOADFCTAVAIL);
				scrJref1NStub = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NStub", mask, SCRJREF1NSTUB);
				pnl1nstubAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnl1nstubAvail", mask, PNL1NSTUBAVAIL);
				scrJrefTbl1NTablecol = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTbl1NTablecol", mask, SCRJREFTBL1NTABLECOL);
				scrJref1NCheck = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NCheck", mask, SCRJREF1NCHECK);
				pnl1ncheckAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnl1ncheckAvail", mask, PNL1NCHECKAVAIL);
				scrJref1NSubset = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NSubset", mask, SCRJREF1NSUBSET);
				pnl1nsubsetAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnl1nsubsetAvail", mask, PNL1NSUBSETAVAIL);
				scrJref1NImpexp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NImpexp", mask, SCRJREF1NIMPEXP);
				pnl1nimpexpAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnl1nimpexpAvail", mask, PNL1NIMPEXPAVAIL);
				scrJrefTo1NRelation = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTo1NRelation", mask, SCRJREFTO1NRELATION);
				pnlto1nrelationAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlto1nrelationAvail", mask, PNLTO1NRELATIONAVAIL);
				scrJrefFr1NRelation = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefFr1NRelation", mask, SCRJREFFR1NRELATION);
				pnlfr1nrelationAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlfr1nrelationAvail", mask, PNLFR1NRELATIONAVAIL);
				scrJrefRef1NRtblock = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NRtblock", mask, SCRJREFREF1NRTBLOCK);
				scrJrefRef1NQuerymod = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NQuerymod", mask, SCRJREFREF1NQUERYMOD);
				scrJrefHk1NVector = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHk1NVector", mask, SCRJREFHK1NVECTOR);
				scrJrefFct1NTablecol = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefFct1NTablecol", mask, SCRJREFFCT1NTABLECOL);
				pnlfct1ntablecolAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlfct1ntablecolAvail", mask, PNLFCT1NTABLECOLAVAIL);
				scrJrefSrc1NFeed = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSrc1NFeed", mask, SCRJREFSRC1NFEED);
				scrJrefRef1NCall = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NCall", mask, SCRJREFREF1NCALL);
				pnlref1ncallAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlref1ncallAvail", mask, PNLREF1NCALLAVAIL);
				scrJrefRef1NDialog = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NDialog", mask, SCRJREFREF1NDIALOG);
				pnlref1ndialogAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlref1ndialogAvail", mask, PNLREF1NDIALOGAVAIL);
				scrJrefRef1NPanel = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NPanel", mask, SCRJREFREF1NPANEL);
				scrJrefPst1NQuerymod = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefPst1NQuerymod", mask, SCRJREFPST1NQUERYMOD);
				pnlpst1nquerymodAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlpst1nquerymodAvail", mask, PNLPST1NQUERYMODAVAIL);
				scrJrefMNVector = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNVector", mask, SCRJREFMNVECTOR);
				pnlmnvectorAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlmnvectorAvail", mask, PNLMNVECTORAVAIL);
				scrJrefMNQuery = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNQuery", mask, SCRJREFMNQUERY);
				pnlmnqueryAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlmnqueryAvail", mask, PNLMNQUERYAVAIL);
				ButRegularizeActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", mask, BUTREGULARIZEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (scrJrefDetail.equals(comp.scrJrefDetail)) items.add(SCRJREFDETAIL);
			if (scrJrefATitle.equals(comp.scrJrefATitle)) items.add(SCRJREFATITLE);
			if (pnlatitleAvail == comp.pnlatitleAvail) items.add(PNLATITLEAVAIL);
			if (scrJrefALoadfct.equals(comp.scrJrefALoadfct)) items.add(SCRJREFALOADFCT);
			if (pnlaloadfctAvail == comp.pnlaloadfctAvail) items.add(PNLALOADFCTAVAIL);
			if (scrJref1NStub.equals(comp.scrJref1NStub)) items.add(SCRJREF1NSTUB);
			if (pnl1nstubAvail == comp.pnl1nstubAvail) items.add(PNL1NSTUBAVAIL);
			if (scrJrefTbl1NTablecol.equals(comp.scrJrefTbl1NTablecol)) items.add(SCRJREFTBL1NTABLECOL);
			if (scrJref1NCheck.equals(comp.scrJref1NCheck)) items.add(SCRJREF1NCHECK);
			if (pnl1ncheckAvail == comp.pnl1ncheckAvail) items.add(PNL1NCHECKAVAIL);
			if (scrJref1NSubset.equals(comp.scrJref1NSubset)) items.add(SCRJREF1NSUBSET);
			if (pnl1nsubsetAvail == comp.pnl1nsubsetAvail) items.add(PNL1NSUBSETAVAIL);
			if (scrJref1NImpexp.equals(comp.scrJref1NImpexp)) items.add(SCRJREF1NIMPEXP);
			if (pnl1nimpexpAvail == comp.pnl1nimpexpAvail) items.add(PNL1NIMPEXPAVAIL);
			if (scrJrefTo1NRelation.equals(comp.scrJrefTo1NRelation)) items.add(SCRJREFTO1NRELATION);
			if (pnlto1nrelationAvail == comp.pnlto1nrelationAvail) items.add(PNLTO1NRELATIONAVAIL);
			if (scrJrefFr1NRelation.equals(comp.scrJrefFr1NRelation)) items.add(SCRJREFFR1NRELATION);
			if (pnlfr1nrelationAvail == comp.pnlfr1nrelationAvail) items.add(PNLFR1NRELATIONAVAIL);
			if (scrJrefRef1NRtblock.equals(comp.scrJrefRef1NRtblock)) items.add(SCRJREFREF1NRTBLOCK);
			if (scrJrefRef1NQuerymod.equals(comp.scrJrefRef1NQuerymod)) items.add(SCRJREFREF1NQUERYMOD);
			if (scrJrefHk1NVector.equals(comp.scrJrefHk1NVector)) items.add(SCRJREFHK1NVECTOR);
			if (scrJrefFct1NTablecol.equals(comp.scrJrefFct1NTablecol)) items.add(SCRJREFFCT1NTABLECOL);
			if (pnlfct1ntablecolAvail == comp.pnlfct1ntablecolAvail) items.add(PNLFCT1NTABLECOLAVAIL);
			if (scrJrefSrc1NFeed.equals(comp.scrJrefSrc1NFeed)) items.add(SCRJREFSRC1NFEED);
			if (scrJrefRef1NCall.equals(comp.scrJrefRef1NCall)) items.add(SCRJREFREF1NCALL);
			if (pnlref1ncallAvail == comp.pnlref1ncallAvail) items.add(PNLREF1NCALLAVAIL);
			if (scrJrefRef1NDialog.equals(comp.scrJrefRef1NDialog)) items.add(SCRJREFREF1NDIALOG);
			if (pnlref1ndialogAvail == comp.pnlref1ndialogAvail) items.add(PNLREF1NDIALOGAVAIL);
			if (scrJrefRef1NPanel.equals(comp.scrJrefRef1NPanel)) items.add(SCRJREFREF1NPANEL);
			if (scrJrefPst1NQuerymod.equals(comp.scrJrefPst1NQuerymod)) items.add(SCRJREFPST1NQUERYMOD);
			if (pnlpst1nquerymodAvail == comp.pnlpst1nquerymodAvail) items.add(PNLPST1NQUERYMODAVAIL);
			if (scrJrefMNVector.equals(comp.scrJrefMNVector)) items.add(SCRJREFMNVECTOR);
			if (pnlmnvectorAvail == comp.pnlmnvectorAvail) items.add(PNLMNVECTORAVAIL);
			if (scrJrefMNQuery.equals(comp.scrJrefMNQuery)) items.add(SCRJREFMNQUERY);
			if (pnlmnqueryAvail == comp.pnlmnqueryAvail) items.add(PNLMNQUERYAVAIL);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFATITLE, PNLATITLEAVAIL, SCRJREFALOADFCT, PNLALOADFCTAVAIL, SCRJREF1NSTUB, PNL1NSTUBAVAIL, SCRJREFTBL1NTABLECOL, SCRJREF1NCHECK, PNL1NCHECKAVAIL, SCRJREF1NSUBSET, PNL1NSUBSETAVAIL, SCRJREF1NIMPEXP, PNL1NIMPEXPAVAIL, SCRJREFTO1NRELATION, PNLTO1NRELATIONAVAIL, SCRJREFFR1NRELATION, PNLFR1NRELATIONAVAIL, SCRJREFREF1NRTBLOCK, SCRJREFREF1NQUERYMOD, SCRJREFHK1NVECTOR, SCRJREFFCT1NTABLECOL, PNLFCT1NTABLECOLAVAIL, SCRJREFSRC1NFEED, SCRJREFREF1NCALL, PNLREF1NCALLAVAIL, SCRJREFREF1NDIALOG, PNLREF1NDIALOGAVAIL, SCRJREFREF1NPANEL, SCRJREFPST1NQUERYMOD, PNLPST1NQUERYMODAVAIL, SCRJREFMNVECTOR, PNLMNVECTORAVAIL, SCRJREFMNQUERY, PNLMNQUERYAVAIL, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmTblRec)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;

		public Tag(
					String Cpt
				) {
			this.Cpt = Cpt;

			mask = new HashSet<Integer>(Arrays.asList(CPT));
		};

		public String Cpt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmTblRec");

			String itemtag = "TagitemWznmTblRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmTblRecDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMTBLRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmTblRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmTblRecData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMTBLRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", false, "", false, "", false, "", "", false, "", false, "", false, "", false, "", false, "", "", "", "", false, "", "", false, "", false, "", "", false, "", false, "", false, false);
			tag = new Tag("");
		};

		public ContInf continf;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmTblRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", false, "", false, "", false, "", "", false, "", false, "", false, "", false, "", false, "", "", "", "", false, "", "", false, "", false, "", "", false, "", false, "", false, false);
				tag = new Tag("");
			};
		};

	};

};

