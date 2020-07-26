/**
  * \file CrdWznmNav.java
  * Java API code for job CrdWznmNav
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class CrdWznmNav {
	/**
		* VecVDo (full: VecVWznmNavDo)
		*/
	public static class VecVDo {

		public static final int CLOSE = 1;
		public static final int MITAPPABTCLICK = 2;
		public static final int MITSESSPSCLICK = 3;
		public static final int MITSESTRMCLICK = 4;
		public static final int MITCRDUSGCLICK = 5;
		public static final int MITCRDUSRCLICK = 6;
		public static final int MITCRDPRSCLICK = 7;
		public static final int MITCRDFILCLICK = 8;
		public static final int MITCRDLOCCLICK = 9;
		public static final int MITCRDTAGCLICK = 10;
		public static final int MITCRDCTPCLICK = 11;
		public static final int MITCRDMTYCLICK = 12;
		public static final int MITCRDMCHCLICK = 13;
		public static final int MITCRDLIBCLICK = 14;
		public static final int MITCRDPRJCLICK = 15;
		public static final int MITCRDVERCLICK = 16;
		public static final int MITCRDCAPCLICK = 17;
		public static final int MITCRDERRCLICK = 18;
		public static final int MITCRDTBLCLICK = 19;
		public static final int MITCRDTCOCLICK = 20;
		public static final int MITCRDSBSCLICK = 21;
		public static final int MITCRDRELCLICK = 22;
		public static final int MITCRDVECCLICK = 23;
		public static final int MITCRDVITCLICK = 24;
		public static final int MITCRDCHKCLICK = 25;
		public static final int MITCRDSTBCLICK = 26;
		public static final int MITCRDIEXCLICK = 27;
		public static final int MITCRDIMECLICK = 28;
		public static final int MITCRDPSTCLICK = 29;
		public static final int MITCRDMDLCLICK = 30;
		public static final int MITCRDCARCLICK = 31;
		public static final int MITCRDDLGCLICK = 32;
		public static final int MITCRDPNLCLICK = 33;
		public static final int MITCRDQRYCLICK = 34;
		public static final int MITCRDQCOCLICK = 35;
		public static final int MITCRDQMDCLICK = 36;
		public static final int MITCRDCONCLICK = 37;
		public static final int MITCRDOPKCLICK = 38;
		public static final int MITCRDOPXCLICK = 39;
		public static final int MITCRDJOBCLICK = 40;
		public static final int MITCRDSGECLICK = 41;
		public static final int MITCRDMTDCLICK = 42;
		public static final int MITCRDBLKCLICK = 43;
		public static final int MITCRDCALCLICK = 44;
		public static final int MITCRDCMPCLICK = 45;
		public static final int MITCRDRLSCLICK = 46;
		public static final int MITCRDAPPCLICK = 47;
		public static final int MITCRDRTJCLICK = 48;
		public static final int MITCRDSEQCLICK = 49;
		public static final int MITCRDSTECLICK = 50;
		public static final int MITCRDUTLCLICK = 51;
		public static final int MITAPPMLCCLICK = 52;
		public static final int MITAPPLOICLICK = 53;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("close")) return CLOSE;
			if (s.equals("mitappabtclick")) return MITAPPABTCLICK;
			if (s.equals("mitsesspsclick")) return MITSESSPSCLICK;
			if (s.equals("mitsestrmclick")) return MITSESTRMCLICK;
			if (s.equals("mitcrdusgclick")) return MITCRDUSGCLICK;
			if (s.equals("mitcrdusrclick")) return MITCRDUSRCLICK;
			if (s.equals("mitcrdprsclick")) return MITCRDPRSCLICK;
			if (s.equals("mitcrdfilclick")) return MITCRDFILCLICK;
			if (s.equals("mitcrdlocclick")) return MITCRDLOCCLICK;
			if (s.equals("mitcrdtagclick")) return MITCRDTAGCLICK;
			if (s.equals("mitcrdctpclick")) return MITCRDCTPCLICK;
			if (s.equals("mitcrdmtyclick")) return MITCRDMTYCLICK;
			if (s.equals("mitcrdmchclick")) return MITCRDMCHCLICK;
			if (s.equals("mitcrdlibclick")) return MITCRDLIBCLICK;
			if (s.equals("mitcrdprjclick")) return MITCRDPRJCLICK;
			if (s.equals("mitcrdverclick")) return MITCRDVERCLICK;
			if (s.equals("mitcrdcapclick")) return MITCRDCAPCLICK;
			if (s.equals("mitcrderrclick")) return MITCRDERRCLICK;
			if (s.equals("mitcrdtblclick")) return MITCRDTBLCLICK;
			if (s.equals("mitcrdtcoclick")) return MITCRDTCOCLICK;
			if (s.equals("mitcrdsbsclick")) return MITCRDSBSCLICK;
			if (s.equals("mitcrdrelclick")) return MITCRDRELCLICK;
			if (s.equals("mitcrdvecclick")) return MITCRDVECCLICK;
			if (s.equals("mitcrdvitclick")) return MITCRDVITCLICK;
			if (s.equals("mitcrdchkclick")) return MITCRDCHKCLICK;
			if (s.equals("mitcrdstbclick")) return MITCRDSTBCLICK;
			if (s.equals("mitcrdiexclick")) return MITCRDIEXCLICK;
			if (s.equals("mitcrdimeclick")) return MITCRDIMECLICK;
			if (s.equals("mitcrdpstclick")) return MITCRDPSTCLICK;
			if (s.equals("mitcrdmdlclick")) return MITCRDMDLCLICK;
			if (s.equals("mitcrdcarclick")) return MITCRDCARCLICK;
			if (s.equals("mitcrddlgclick")) return MITCRDDLGCLICK;
			if (s.equals("mitcrdpnlclick")) return MITCRDPNLCLICK;
			if (s.equals("mitcrdqryclick")) return MITCRDQRYCLICK;
			if (s.equals("mitcrdqcoclick")) return MITCRDQCOCLICK;
			if (s.equals("mitcrdqmdclick")) return MITCRDQMDCLICK;
			if (s.equals("mitcrdconclick")) return MITCRDCONCLICK;
			if (s.equals("mitcrdopkclick")) return MITCRDOPKCLICK;
			if (s.equals("mitcrdopxclick")) return MITCRDOPXCLICK;
			if (s.equals("mitcrdjobclick")) return MITCRDJOBCLICK;
			if (s.equals("mitcrdsgeclick")) return MITCRDSGECLICK;
			if (s.equals("mitcrdmtdclick")) return MITCRDMTDCLICK;
			if (s.equals("mitcrdblkclick")) return MITCRDBLKCLICK;
			if (s.equals("mitcrdcalclick")) return MITCRDCALCLICK;
			if (s.equals("mitcrdcmpclick")) return MITCRDCMPCLICK;
			if (s.equals("mitcrdrlsclick")) return MITCRDRLSCLICK;
			if (s.equals("mitcrdappclick")) return MITCRDAPPCLICK;
			if (s.equals("mitcrdrtjclick")) return MITCRDRTJCLICK;
			if (s.equals("mitcrdseqclick")) return MITCRDSEQCLICK;
			if (s.equals("mitcrdsteclick")) return MITCRDSTECLICK;
			if (s.equals("mitcrdutlclick")) return MITCRDUTLCLICK;
			if (s.equals("mitappmlcclick")) return MITAPPMLCCLICK;
			if (s.equals("mitapploiclick")) return MITAPPLOICLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == CLOSE) return("close");
			if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
			if (ix == MITSESSPSCLICK) return("MitSesSpsClick");
			if (ix == MITSESTRMCLICK) return("MitSesTrmClick");
			if (ix == MITCRDUSGCLICK) return("MitCrdUsgClick");
			if (ix == MITCRDUSRCLICK) return("MitCrdUsrClick");
			if (ix == MITCRDPRSCLICK) return("MitCrdPrsClick");
			if (ix == MITCRDFILCLICK) return("MitCrdFilClick");
			if (ix == MITCRDLOCCLICK) return("MitCrdLocClick");
			if (ix == MITCRDTAGCLICK) return("MitCrdTagClick");
			if (ix == MITCRDCTPCLICK) return("MitCrdCtpClick");
			if (ix == MITCRDMTYCLICK) return("MitCrdMtyClick");
			if (ix == MITCRDMCHCLICK) return("MitCrdMchClick");
			if (ix == MITCRDLIBCLICK) return("MitCrdLibClick");
			if (ix == MITCRDPRJCLICK) return("MitCrdPrjClick");
			if (ix == MITCRDVERCLICK) return("MitCrdVerClick");
			if (ix == MITCRDCAPCLICK) return("MitCrdCapClick");
			if (ix == MITCRDERRCLICK) return("MitCrdErrClick");
			if (ix == MITCRDTBLCLICK) return("MitCrdTblClick");
			if (ix == MITCRDTCOCLICK) return("MitCrdTcoClick");
			if (ix == MITCRDSBSCLICK) return("MitCrdSbsClick");
			if (ix == MITCRDRELCLICK) return("MitCrdRelClick");
			if (ix == MITCRDVECCLICK) return("MitCrdVecClick");
			if (ix == MITCRDVITCLICK) return("MitCrdVitClick");
			if (ix == MITCRDCHKCLICK) return("MitCrdChkClick");
			if (ix == MITCRDSTBCLICK) return("MitCrdStbClick");
			if (ix == MITCRDIEXCLICK) return("MitCrdIexClick");
			if (ix == MITCRDIMECLICK) return("MitCrdImeClick");
			if (ix == MITCRDPSTCLICK) return("MitCrdPstClick");
			if (ix == MITCRDMDLCLICK) return("MitCrdMdlClick");
			if (ix == MITCRDCARCLICK) return("MitCrdCarClick");
			if (ix == MITCRDDLGCLICK) return("MitCrdDlgClick");
			if (ix == MITCRDPNLCLICK) return("MitCrdPnlClick");
			if (ix == MITCRDQRYCLICK) return("MitCrdQryClick");
			if (ix == MITCRDQCOCLICK) return("MitCrdQcoClick");
			if (ix == MITCRDQMDCLICK) return("MitCrdQmdClick");
			if (ix == MITCRDCONCLICK) return("MitCrdConClick");
			if (ix == MITCRDOPKCLICK) return("MitCrdOpkClick");
			if (ix == MITCRDOPXCLICK) return("MitCrdOpxClick");
			if (ix == MITCRDJOBCLICK) return("MitCrdJobClick");
			if (ix == MITCRDSGECLICK) return("MitCrdSgeClick");
			if (ix == MITCRDMTDCLICK) return("MitCrdMtdClick");
			if (ix == MITCRDBLKCLICK) return("MitCrdBlkClick");
			if (ix == MITCRDCALCLICK) return("MitCrdCalClick");
			if (ix == MITCRDCMPCLICK) return("MitCrdCmpClick");
			if (ix == MITCRDRLSCLICK) return("MitCrdRlsClick");
			if (ix == MITCRDAPPCLICK) return("MitCrdAppClick");
			if (ix == MITCRDRTJCLICK) return("MitCrdRtjClick");
			if (ix == MITCRDSEQCLICK) return("MitCrdSeqClick");
			if (ix == MITCRDSTECLICK) return("MitCrdSteClick");
			if (ix == MITCRDUTLCLICK) return("MitCrdUtlClick");
			if (ix == MITAPPMLCCLICK) return("MitAppMlcClick");
			if (ix == MITAPPLOICLICK) return("MitAppLoiClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVWznmNavSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRWZNMABT = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alrwznmabt")) return ALRWZNMABT;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == ALRWZNMABT) return("alrwznmabt");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWznmNav)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MTXSESSES1 = 3;
		public static final int MTXSESSES2 = 4;
		public static final int MTXSESSES3 = 5;

		public ContInf(
					int numFSge
					, String MrlAppHlp
					, String MtxSesSes1
					, String MtxSesSes2
					, String MtxSesSes3
				) {
			this.numFSge = numFSge;
			this.MrlAppHlp = MrlAppHlp;
			this.MtxSesSes1 = MtxSesSes1;
			this.MtxSesSes2 = MtxSesSes2;
			this.MtxSesSes3 = MtxSesSes3;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3));
		};

		public int numFSge;
		public String MrlAppHlp;
		public String MtxSesSes1;
		public String MtxSesSes2;
		public String MtxSesSes3;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmNav");

			String itemtag = "ContitemInfWznmNav";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MtxSesSes1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxSesSes1", mask, MTXSESSES1);
				MtxSesSes2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxSesSes2", mask, MTXSESSES2);
				MtxSesSes3 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxSesSes3", mask, MTXSESSES3);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);
			if (MrlAppHlp.equals(comp.MrlAppHlp)) items.add(MRLAPPHLP);
			if (MtxSesSes1.equals(comp.MtxSesSes1)) items.add(MTXSESSES1);
			if (MtxSesSes2.equals(comp.MtxSesSes2)) items.add(MTXSESSES2);
			if (MtxSesSes3.equals(comp.MtxSesSes3)) items.add(MTXSESSES3);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmNav)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVREQITMODE = 1;
		public static final int LATENCY = 2;
		public static final int SHORTMENU = 3;
		public static final int WIDTHMENU = 4;
		public static final int INITDONEHEADBAR = 5;
		public static final int INITDONEPRE = 6;
		public static final int INITDONEADMIN = 7;
		public static final int INITDONEGLOBAL = 8;
		public static final int INITDONEPROJECT = 9;
		public static final int INITDONEDBSTR = 10;
		public static final int INITDONEUIX = 11;
		public static final int INITDONECOMP = 12;
		public static final int INITDONEJOB = 13;
		public static final int INITDONEDEPLOY = 14;
		public static final int INITDONEAPPDEV = 15;
		public static final int INITDONEAUXFCT = 16;

		public StatApp(
					int ixWznmVReqitmode
					, int latency
					, String shortMenu
					, int widthMenu
					, boolean initdoneHeadbar
					, boolean initdonePre
					, boolean initdoneAdmin
					, boolean initdoneGlobal
					, boolean initdoneProject
					, boolean initdoneDbstr
					, boolean initdoneUix
					, boolean initdoneComp
					, boolean initdoneJob
					, boolean initdoneDeploy
					, boolean initdoneAppdev
					, boolean initdoneAuxfct
				) {
			this.ixWznmVReqitmode = ixWznmVReqitmode;
			this.latency = latency;
			this.shortMenu = shortMenu;
			this.widthMenu = widthMenu;
			this.initdoneHeadbar = initdoneHeadbar;
			this.initdonePre = initdonePre;
			this.initdoneAdmin = initdoneAdmin;
			this.initdoneGlobal = initdoneGlobal;
			this.initdoneProject = initdoneProject;
			this.initdoneDbstr = initdoneDbstr;
			this.initdoneUix = initdoneUix;
			this.initdoneComp = initdoneComp;
			this.initdoneJob = initdoneJob;
			this.initdoneDeploy = initdoneDeploy;
			this.initdoneAppdev = initdoneAppdev;
			this.initdoneAuxfct = initdoneAuxfct;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEGLOBAL, INITDONEPROJECT, INITDONEDBSTR, INITDONEUIX, INITDONECOMP, INITDONEJOB, INITDONEDEPLOY, INITDONEAPPDEV, INITDONEAUXFCT));
		};

		public int ixWznmVReqitmode;
		public int latency;
		public String shortMenu;
		public int widthMenu;
		public boolean initdoneHeadbar;
		public boolean initdonePre;
		public boolean initdoneAdmin;
		public boolean initdoneGlobal;
		public boolean initdoneProject;
		public boolean initdoneDbstr;
		public boolean initdoneUix;
		public boolean initdoneComp;
		public boolean initdoneJob;
		public boolean initdoneDeploy;
		public boolean initdoneAppdev;
		public boolean initdoneAuxfct;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVReqitmode;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmNav");

			String itemtag = "StatitemAppWznmNav";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVReqitmode", mask, IXWZNMVREQITMODE);
				ixWznmVReqitmode = VecWznmVReqitmode.getIx(srefIxWznmVReqitmode);
				latency = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "latency", mask, LATENCY);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				widthMenu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "widthMenu", mask, WIDTHMENU);
				initdoneHeadbar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", mask, INITDONEHEADBAR);
				initdonePre = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdonePre", mask, INITDONEPRE);
				initdoneAdmin = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAdmin", mask, INITDONEADMIN);
				initdoneGlobal = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneGlobal", mask, INITDONEGLOBAL);
				initdoneProject = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneProject", mask, INITDONEPROJECT);
				initdoneDbstr = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDbstr", mask, INITDONEDBSTR);
				initdoneUix = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneUix", mask, INITDONEUIX);
				initdoneComp = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneComp", mask, INITDONECOMP);
				initdoneJob = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneJob", mask, INITDONEJOB);
				initdoneDeploy = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDeploy", mask, INITDONEDEPLOY);
				initdoneAppdev = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAppdev", mask, INITDONEAPPDEV);
				initdoneAuxfct = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAuxfct", mask, INITDONEAUXFCT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVReqitmode == comp.ixWznmVReqitmode) items.add(IXWZNMVREQITMODE);
			if (latency == comp.latency) items.add(LATENCY);
			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);
			if (widthMenu == comp.widthMenu) items.add(WIDTHMENU);
			if (initdoneHeadbar == comp.initdoneHeadbar) items.add(INITDONEHEADBAR);
			if (initdonePre == comp.initdonePre) items.add(INITDONEPRE);
			if (initdoneAdmin == comp.initdoneAdmin) items.add(INITDONEADMIN);
			if (initdoneGlobal == comp.initdoneGlobal) items.add(INITDONEGLOBAL);
			if (initdoneProject == comp.initdoneProject) items.add(INITDONEPROJECT);
			if (initdoneDbstr == comp.initdoneDbstr) items.add(INITDONEDBSTR);
			if (initdoneUix == comp.initdoneUix) items.add(INITDONEUIX);
			if (initdoneComp == comp.initdoneComp) items.add(INITDONECOMP);
			if (initdoneJob == comp.initdoneJob) items.add(INITDONEJOB);
			if (initdoneDeploy == comp.initdoneDeploy) items.add(INITDONEDEPLOY);
			if (initdoneAppdev == comp.initdoneAppdev) items.add(INITDONEAPPDEV);
			if (initdoneAuxfct == comp.initdoneAuxfct) items.add(INITDONEAUXFCT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEGLOBAL, INITDONEPROJECT, INITDONEDBSTR, INITDONEUIX, INITDONECOMP, INITDONEJOB, INITDONEDEPLOY, INITDONEAPPDEV, INITDONEAUXFCT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmNav)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFDLGLOAINI = 1;
		public static final int SCRJREFDLGMNGLIC = 2;
		public static final int SCRJREFHEADBAR = 3;
		public static final int SCRJREFPRE = 4;
		public static final int PNLPREAVAIL = 5;
		public static final int SCRJREFADMIN = 6;
		public static final int PNLADMINAVAIL = 7;
		public static final int SCRJREFGLOBAL = 8;
		public static final int PNLGLOBALAVAIL = 9;
		public static final int SCRJREFPROJECT = 10;
		public static final int PNLPROJECTAVAIL = 11;
		public static final int SCRJREFDBSTR = 12;
		public static final int PNLDBSTRAVAIL = 13;
		public static final int SCRJREFUIX = 14;
		public static final int PNLUIXAVAIL = 15;
		public static final int SCRJREFCOMP = 16;
		public static final int PNLCOMPAVAIL = 17;
		public static final int SCRJREFJOB = 18;
		public static final int PNLJOBAVAIL = 19;
		public static final int SCRJREFDEPLOY = 20;
		public static final int PNLDEPLOYAVAIL = 21;
		public static final int SCRJREFAPPDEV = 22;
		public static final int PNLAPPDEVAVAIL = 23;
		public static final int SCRJREFAUXFCT = 24;
		public static final int PNLAUXFCTAVAIL = 25;
		public static final int MITSESSPSAVAIL = 26;
		public static final int MSPCRD1AVAIL = 27;
		public static final int MITCRDUSGAVAIL = 28;
		public static final int MITCRDUSRAVAIL = 29;
		public static final int MITCRDPRSAVAIL = 30;
		public static final int MITCRDFILAVAIL = 31;
		public static final int MSPCRD2AVAIL = 32;
		public static final int MITCRDLOCAVAIL = 33;
		public static final int MITCRDTAGAVAIL = 34;
		public static final int MITCRDCTPAVAIL = 35;
		public static final int MITCRDMTYAVAIL = 36;
		public static final int MITCRDMCHAVAIL = 37;
		public static final int MITCRDLIBAVAIL = 38;
		public static final int MSPCRD3AVAIL = 39;
		public static final int MITCRDPRJAVAIL = 40;
		public static final int MITCRDVERAVAIL = 41;
		public static final int MITCRDCAPAVAIL = 42;
		public static final int MITCRDCAPACTIVE = 43;
		public static final int MITCRDERRAVAIL = 44;
		public static final int MITCRDERRACTIVE = 45;
		public static final int MSPCRD4AVAIL = 46;
		public static final int MITCRDTBLAVAIL = 47;
		public static final int MITCRDTBLACTIVE = 48;
		public static final int MITCRDTCOAVAIL = 49;
		public static final int MITCRDTCOACTIVE = 50;
		public static final int MITCRDSBSAVAIL = 51;
		public static final int MITCRDSBSACTIVE = 52;
		public static final int MITCRDRELAVAIL = 53;
		public static final int MITCRDRELACTIVE = 54;
		public static final int MITCRDVECAVAIL = 55;
		public static final int MITCRDVECACTIVE = 56;
		public static final int MITCRDVITAVAIL = 57;
		public static final int MITCRDVITACTIVE = 58;
		public static final int MITCRDCHKAVAIL = 59;
		public static final int MITCRDCHKACTIVE = 60;
		public static final int MITCRDSTBAVAIL = 61;
		public static final int MITCRDSTBACTIVE = 62;
		public static final int MITCRDIEXAVAIL = 63;
		public static final int MITCRDIEXACTIVE = 64;
		public static final int MITCRDIMEAVAIL = 65;
		public static final int MITCRDIMEACTIVE = 66;
		public static final int MSPCRD5AVAIL = 67;
		public static final int MITCRDPSTAVAIL = 68;
		public static final int MITCRDPSTACTIVE = 69;
		public static final int MITCRDMDLAVAIL = 70;
		public static final int MITCRDMDLACTIVE = 71;
		public static final int MITCRDCARAVAIL = 72;
		public static final int MITCRDCARACTIVE = 73;
		public static final int MITCRDDLGAVAIL = 74;
		public static final int MITCRDDLGACTIVE = 75;
		public static final int MITCRDPNLAVAIL = 76;
		public static final int MITCRDPNLACTIVE = 77;
		public static final int MITCRDQRYAVAIL = 78;
		public static final int MITCRDQRYACTIVE = 79;
		public static final int MITCRDQCOAVAIL = 80;
		public static final int MITCRDQCOACTIVE = 81;
		public static final int MITCRDQMDAVAIL = 82;
		public static final int MITCRDQMDACTIVE = 83;
		public static final int MITCRDCONAVAIL = 84;
		public static final int MITCRDCONACTIVE = 85;
		public static final int MSPCRD6AVAIL = 86;
		public static final int MITCRDOPKAVAIL = 87;
		public static final int MITCRDOPKACTIVE = 88;
		public static final int MITCRDOPXAVAIL = 89;
		public static final int MITCRDOPXACTIVE = 90;
		public static final int MSPCRD7AVAIL = 91;
		public static final int MITCRDJOBAVAIL = 92;
		public static final int MITCRDJOBACTIVE = 93;
		public static final int MITCRDSGEAVAIL = 94;
		public static final int MITCRDSGEACTIVE = 95;
		public static final int MITCRDMTDAVAIL = 96;
		public static final int MITCRDMTDACTIVE = 97;
		public static final int MITCRDBLKAVAIL = 98;
		public static final int MITCRDBLKACTIVE = 99;
		public static final int MITCRDCALAVAIL = 100;
		public static final int MITCRDCALACTIVE = 101;
		public static final int MSPCRD8AVAIL = 102;
		public static final int MITCRDCMPAVAIL = 103;
		public static final int MITCRDRLSAVAIL = 104;
		public static final int MITCRDRLSACTIVE = 105;
		public static final int MSPCRD9AVAIL = 106;
		public static final int MITCRDAPPAVAIL = 107;
		public static final int MITCRDRTJAVAIL = 108;
		public static final int MITCRDRTJACTIVE = 109;
		public static final int MITCRDSEQAVAIL = 110;
		public static final int MITCRDSEQACTIVE = 111;
		public static final int MITCRDSTEAVAIL = 112;
		public static final int MITCRDSTEACTIVE = 113;
		public static final int MSPCRD10AVAIL = 114;
		public static final int MITCRDUTLAVAIL = 115;
		public static final int MSPAPP2AVAIL = 116;
		public static final int MITAPPMLCAVAIL = 117;
		public static final int MITAPPLOIAVAIL = 118;

		public StatShr(
					String scrJrefDlgloaini
					, String scrJrefDlgmnglic
					, String scrJrefHeadbar
					, String scrJrefPre
					, boolean pnlpreAvail
					, String scrJrefAdmin
					, boolean pnladminAvail
					, String scrJrefGlobal
					, boolean pnlglobalAvail
					, String scrJrefProject
					, boolean pnlprojectAvail
					, String scrJrefDbstr
					, boolean pnldbstrAvail
					, String scrJrefUix
					, boolean pnluixAvail
					, String scrJrefComp
					, boolean pnlcompAvail
					, String scrJrefJob
					, boolean pnljobAvail
					, String scrJrefDeploy
					, boolean pnldeployAvail
					, String scrJrefAppdev
					, boolean pnlappdevAvail
					, String scrJrefAuxfct
					, boolean pnlauxfctAvail
					, boolean MitSesSpsAvail
					, boolean MspCrd1Avail
					, boolean MitCrdUsgAvail
					, boolean MitCrdUsrAvail
					, boolean MitCrdPrsAvail
					, boolean MitCrdFilAvail
					, boolean MspCrd2Avail
					, boolean MitCrdLocAvail
					, boolean MitCrdTagAvail
					, boolean MitCrdCtpAvail
					, boolean MitCrdMtyAvail
					, boolean MitCrdMchAvail
					, boolean MitCrdLibAvail
					, boolean MspCrd3Avail
					, boolean MitCrdPrjAvail
					, boolean MitCrdVerAvail
					, boolean MitCrdCapAvail
					, boolean MitCrdCapActive
					, boolean MitCrdErrAvail
					, boolean MitCrdErrActive
					, boolean MspCrd4Avail
					, boolean MitCrdTblAvail
					, boolean MitCrdTblActive
					, boolean MitCrdTcoAvail
					, boolean MitCrdTcoActive
					, boolean MitCrdSbsAvail
					, boolean MitCrdSbsActive
					, boolean MitCrdRelAvail
					, boolean MitCrdRelActive
					, boolean MitCrdVecAvail
					, boolean MitCrdVecActive
					, boolean MitCrdVitAvail
					, boolean MitCrdVitActive
					, boolean MitCrdChkAvail
					, boolean MitCrdChkActive
					, boolean MitCrdStbAvail
					, boolean MitCrdStbActive
					, boolean MitCrdIexAvail
					, boolean MitCrdIexActive
					, boolean MitCrdImeAvail
					, boolean MitCrdImeActive
					, boolean MspCrd5Avail
					, boolean MitCrdPstAvail
					, boolean MitCrdPstActive
					, boolean MitCrdMdlAvail
					, boolean MitCrdMdlActive
					, boolean MitCrdCarAvail
					, boolean MitCrdCarActive
					, boolean MitCrdDlgAvail
					, boolean MitCrdDlgActive
					, boolean MitCrdPnlAvail
					, boolean MitCrdPnlActive
					, boolean MitCrdQryAvail
					, boolean MitCrdQryActive
					, boolean MitCrdQcoAvail
					, boolean MitCrdQcoActive
					, boolean MitCrdQmdAvail
					, boolean MitCrdQmdActive
					, boolean MitCrdConAvail
					, boolean MitCrdConActive
					, boolean MspCrd6Avail
					, boolean MitCrdOpkAvail
					, boolean MitCrdOpkActive
					, boolean MitCrdOpxAvail
					, boolean MitCrdOpxActive
					, boolean MspCrd7Avail
					, boolean MitCrdJobAvail
					, boolean MitCrdJobActive
					, boolean MitCrdSgeAvail
					, boolean MitCrdSgeActive
					, boolean MitCrdMtdAvail
					, boolean MitCrdMtdActive
					, boolean MitCrdBlkAvail
					, boolean MitCrdBlkActive
					, boolean MitCrdCalAvail
					, boolean MitCrdCalActive
					, boolean MspCrd8Avail
					, boolean MitCrdCmpAvail
					, boolean MitCrdRlsAvail
					, boolean MitCrdRlsActive
					, boolean MspCrd9Avail
					, boolean MitCrdAppAvail
					, boolean MitCrdRtjAvail
					, boolean MitCrdRtjActive
					, boolean MitCrdSeqAvail
					, boolean MitCrdSeqActive
					, boolean MitCrdSteAvail
					, boolean MitCrdSteActive
					, boolean MspCrd10Avail
					, boolean MitCrdUtlAvail
					, boolean MspApp2Avail
					, boolean MitAppMlcAvail
					, boolean MitAppLoiAvail
				) {
			this.scrJrefDlgloaini = scrJrefDlgloaini;
			this.scrJrefDlgmnglic = scrJrefDlgmnglic;
			this.scrJrefHeadbar = scrJrefHeadbar;
			this.scrJrefPre = scrJrefPre;
			this.pnlpreAvail = pnlpreAvail;
			this.scrJrefAdmin = scrJrefAdmin;
			this.pnladminAvail = pnladminAvail;
			this.scrJrefGlobal = scrJrefGlobal;
			this.pnlglobalAvail = pnlglobalAvail;
			this.scrJrefProject = scrJrefProject;
			this.pnlprojectAvail = pnlprojectAvail;
			this.scrJrefDbstr = scrJrefDbstr;
			this.pnldbstrAvail = pnldbstrAvail;
			this.scrJrefUix = scrJrefUix;
			this.pnluixAvail = pnluixAvail;
			this.scrJrefComp = scrJrefComp;
			this.pnlcompAvail = pnlcompAvail;
			this.scrJrefJob = scrJrefJob;
			this.pnljobAvail = pnljobAvail;
			this.scrJrefDeploy = scrJrefDeploy;
			this.pnldeployAvail = pnldeployAvail;
			this.scrJrefAppdev = scrJrefAppdev;
			this.pnlappdevAvail = pnlappdevAvail;
			this.scrJrefAuxfct = scrJrefAuxfct;
			this.pnlauxfctAvail = pnlauxfctAvail;
			this.MitSesSpsAvail = MitSesSpsAvail;
			this.MspCrd1Avail = MspCrd1Avail;
			this.MitCrdUsgAvail = MitCrdUsgAvail;
			this.MitCrdUsrAvail = MitCrdUsrAvail;
			this.MitCrdPrsAvail = MitCrdPrsAvail;
			this.MitCrdFilAvail = MitCrdFilAvail;
			this.MspCrd2Avail = MspCrd2Avail;
			this.MitCrdLocAvail = MitCrdLocAvail;
			this.MitCrdTagAvail = MitCrdTagAvail;
			this.MitCrdCtpAvail = MitCrdCtpAvail;
			this.MitCrdMtyAvail = MitCrdMtyAvail;
			this.MitCrdMchAvail = MitCrdMchAvail;
			this.MitCrdLibAvail = MitCrdLibAvail;
			this.MspCrd3Avail = MspCrd3Avail;
			this.MitCrdPrjAvail = MitCrdPrjAvail;
			this.MitCrdVerAvail = MitCrdVerAvail;
			this.MitCrdCapAvail = MitCrdCapAvail;
			this.MitCrdCapActive = MitCrdCapActive;
			this.MitCrdErrAvail = MitCrdErrAvail;
			this.MitCrdErrActive = MitCrdErrActive;
			this.MspCrd4Avail = MspCrd4Avail;
			this.MitCrdTblAvail = MitCrdTblAvail;
			this.MitCrdTblActive = MitCrdTblActive;
			this.MitCrdTcoAvail = MitCrdTcoAvail;
			this.MitCrdTcoActive = MitCrdTcoActive;
			this.MitCrdSbsAvail = MitCrdSbsAvail;
			this.MitCrdSbsActive = MitCrdSbsActive;
			this.MitCrdRelAvail = MitCrdRelAvail;
			this.MitCrdRelActive = MitCrdRelActive;
			this.MitCrdVecAvail = MitCrdVecAvail;
			this.MitCrdVecActive = MitCrdVecActive;
			this.MitCrdVitAvail = MitCrdVitAvail;
			this.MitCrdVitActive = MitCrdVitActive;
			this.MitCrdChkAvail = MitCrdChkAvail;
			this.MitCrdChkActive = MitCrdChkActive;
			this.MitCrdStbAvail = MitCrdStbAvail;
			this.MitCrdStbActive = MitCrdStbActive;
			this.MitCrdIexAvail = MitCrdIexAvail;
			this.MitCrdIexActive = MitCrdIexActive;
			this.MitCrdImeAvail = MitCrdImeAvail;
			this.MitCrdImeActive = MitCrdImeActive;
			this.MspCrd5Avail = MspCrd5Avail;
			this.MitCrdPstAvail = MitCrdPstAvail;
			this.MitCrdPstActive = MitCrdPstActive;
			this.MitCrdMdlAvail = MitCrdMdlAvail;
			this.MitCrdMdlActive = MitCrdMdlActive;
			this.MitCrdCarAvail = MitCrdCarAvail;
			this.MitCrdCarActive = MitCrdCarActive;
			this.MitCrdDlgAvail = MitCrdDlgAvail;
			this.MitCrdDlgActive = MitCrdDlgActive;
			this.MitCrdPnlAvail = MitCrdPnlAvail;
			this.MitCrdPnlActive = MitCrdPnlActive;
			this.MitCrdQryAvail = MitCrdQryAvail;
			this.MitCrdQryActive = MitCrdQryActive;
			this.MitCrdQcoAvail = MitCrdQcoAvail;
			this.MitCrdQcoActive = MitCrdQcoActive;
			this.MitCrdQmdAvail = MitCrdQmdAvail;
			this.MitCrdQmdActive = MitCrdQmdActive;
			this.MitCrdConAvail = MitCrdConAvail;
			this.MitCrdConActive = MitCrdConActive;
			this.MspCrd6Avail = MspCrd6Avail;
			this.MitCrdOpkAvail = MitCrdOpkAvail;
			this.MitCrdOpkActive = MitCrdOpkActive;
			this.MitCrdOpxAvail = MitCrdOpxAvail;
			this.MitCrdOpxActive = MitCrdOpxActive;
			this.MspCrd7Avail = MspCrd7Avail;
			this.MitCrdJobAvail = MitCrdJobAvail;
			this.MitCrdJobActive = MitCrdJobActive;
			this.MitCrdSgeAvail = MitCrdSgeAvail;
			this.MitCrdSgeActive = MitCrdSgeActive;
			this.MitCrdMtdAvail = MitCrdMtdAvail;
			this.MitCrdMtdActive = MitCrdMtdActive;
			this.MitCrdBlkAvail = MitCrdBlkAvail;
			this.MitCrdBlkActive = MitCrdBlkActive;
			this.MitCrdCalAvail = MitCrdCalAvail;
			this.MitCrdCalActive = MitCrdCalActive;
			this.MspCrd8Avail = MspCrd8Avail;
			this.MitCrdCmpAvail = MitCrdCmpAvail;
			this.MitCrdRlsAvail = MitCrdRlsAvail;
			this.MitCrdRlsActive = MitCrdRlsActive;
			this.MspCrd9Avail = MspCrd9Avail;
			this.MitCrdAppAvail = MitCrdAppAvail;
			this.MitCrdRtjAvail = MitCrdRtjAvail;
			this.MitCrdRtjActive = MitCrdRtjActive;
			this.MitCrdSeqAvail = MitCrdSeqAvail;
			this.MitCrdSeqActive = MitCrdSeqActive;
			this.MitCrdSteAvail = MitCrdSteAvail;
			this.MitCrdSteActive = MitCrdSteActive;
			this.MspCrd10Avail = MspCrd10Avail;
			this.MitCrdUtlAvail = MitCrdUtlAvail;
			this.MspApp2Avail = MspApp2Avail;
			this.MitAppMlcAvail = MitAppMlcAvail;
			this.MitAppLoiAvail = MitAppLoiAvail;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFDLGLOAINI, SCRJREFDLGMNGLIC, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFGLOBAL, PNLGLOBALAVAIL, SCRJREFPROJECT, PNLPROJECTAVAIL, SCRJREFDBSTR, PNLDBSTRAVAIL, SCRJREFUIX, PNLUIXAVAIL, SCRJREFCOMP, PNLCOMPAVAIL, SCRJREFJOB, PNLJOBAVAIL, SCRJREFDEPLOY, PNLDEPLOYAVAIL, SCRJREFAPPDEV, PNLAPPDEVAVAIL, SCRJREFAUXFCT, PNLAUXFCTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDLOCAVAIL, MITCRDTAGAVAIL, MITCRDCTPAVAIL, MITCRDMTYAVAIL, MITCRDMCHAVAIL, MITCRDLIBAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDVERAVAIL, MITCRDCAPAVAIL, MITCRDCAPACTIVE, MITCRDERRAVAIL, MITCRDERRACTIVE, MSPCRD4AVAIL, MITCRDTBLAVAIL, MITCRDTBLACTIVE, MITCRDTCOAVAIL, MITCRDTCOACTIVE, MITCRDSBSAVAIL, MITCRDSBSACTIVE, MITCRDRELAVAIL, MITCRDRELACTIVE, MITCRDVECAVAIL, MITCRDVECACTIVE, MITCRDVITAVAIL, MITCRDVITACTIVE, MITCRDCHKAVAIL, MITCRDCHKACTIVE, MITCRDSTBAVAIL, MITCRDSTBACTIVE, MITCRDIEXAVAIL, MITCRDIEXACTIVE, MITCRDIMEAVAIL, MITCRDIMEACTIVE, MSPCRD5AVAIL, MITCRDPSTAVAIL, MITCRDPSTACTIVE, MITCRDMDLAVAIL, MITCRDMDLACTIVE, MITCRDCARAVAIL, MITCRDCARACTIVE, MITCRDDLGAVAIL, MITCRDDLGACTIVE, MITCRDPNLAVAIL, MITCRDPNLACTIVE, MITCRDQRYAVAIL, MITCRDQRYACTIVE, MITCRDQCOAVAIL, MITCRDQCOACTIVE, MITCRDQMDAVAIL, MITCRDQMDACTIVE, MITCRDCONAVAIL, MITCRDCONACTIVE, MSPCRD6AVAIL, MITCRDOPKAVAIL, MITCRDOPKACTIVE, MITCRDOPXAVAIL, MITCRDOPXACTIVE, MSPCRD7AVAIL, MITCRDJOBAVAIL, MITCRDJOBACTIVE, MITCRDSGEAVAIL, MITCRDSGEACTIVE, MITCRDMTDAVAIL, MITCRDMTDACTIVE, MITCRDBLKAVAIL, MITCRDBLKACTIVE, MITCRDCALAVAIL, MITCRDCALACTIVE, MSPCRD8AVAIL, MITCRDCMPAVAIL, MITCRDRLSAVAIL, MITCRDRLSACTIVE, MSPCRD9AVAIL, MITCRDAPPAVAIL, MITCRDRTJAVAIL, MITCRDRTJACTIVE, MITCRDSEQAVAIL, MITCRDSEQACTIVE, MITCRDSTEAVAIL, MITCRDSTEACTIVE, MSPCRD10AVAIL, MITCRDUTLAVAIL, MSPAPP2AVAIL, MITAPPMLCAVAIL, MITAPPLOIAVAIL));
		};

		public String scrJrefDlgloaini;
		public String scrJrefDlgmnglic;
		public String scrJrefHeadbar;
		public String scrJrefPre;
		public boolean pnlpreAvail;
		public String scrJrefAdmin;
		public boolean pnladminAvail;
		public String scrJrefGlobal;
		public boolean pnlglobalAvail;
		public String scrJrefProject;
		public boolean pnlprojectAvail;
		public String scrJrefDbstr;
		public boolean pnldbstrAvail;
		public String scrJrefUix;
		public boolean pnluixAvail;
		public String scrJrefComp;
		public boolean pnlcompAvail;
		public String scrJrefJob;
		public boolean pnljobAvail;
		public String scrJrefDeploy;
		public boolean pnldeployAvail;
		public String scrJrefAppdev;
		public boolean pnlappdevAvail;
		public String scrJrefAuxfct;
		public boolean pnlauxfctAvail;
		public boolean MitSesSpsAvail;
		public boolean MspCrd1Avail;
		public boolean MitCrdUsgAvail;
		public boolean MitCrdUsrAvail;
		public boolean MitCrdPrsAvail;
		public boolean MitCrdFilAvail;
		public boolean MspCrd2Avail;
		public boolean MitCrdLocAvail;
		public boolean MitCrdTagAvail;
		public boolean MitCrdCtpAvail;
		public boolean MitCrdMtyAvail;
		public boolean MitCrdMchAvail;
		public boolean MitCrdLibAvail;
		public boolean MspCrd3Avail;
		public boolean MitCrdPrjAvail;
		public boolean MitCrdVerAvail;
		public boolean MitCrdCapAvail;
		public boolean MitCrdCapActive;
		public boolean MitCrdErrAvail;
		public boolean MitCrdErrActive;
		public boolean MspCrd4Avail;
		public boolean MitCrdTblAvail;
		public boolean MitCrdTblActive;
		public boolean MitCrdTcoAvail;
		public boolean MitCrdTcoActive;
		public boolean MitCrdSbsAvail;
		public boolean MitCrdSbsActive;
		public boolean MitCrdRelAvail;
		public boolean MitCrdRelActive;
		public boolean MitCrdVecAvail;
		public boolean MitCrdVecActive;
		public boolean MitCrdVitAvail;
		public boolean MitCrdVitActive;
		public boolean MitCrdChkAvail;
		public boolean MitCrdChkActive;
		public boolean MitCrdStbAvail;
		public boolean MitCrdStbActive;
		public boolean MitCrdIexAvail;
		public boolean MitCrdIexActive;
		public boolean MitCrdImeAvail;
		public boolean MitCrdImeActive;
		public boolean MspCrd5Avail;
		public boolean MitCrdPstAvail;
		public boolean MitCrdPstActive;
		public boolean MitCrdMdlAvail;
		public boolean MitCrdMdlActive;
		public boolean MitCrdCarAvail;
		public boolean MitCrdCarActive;
		public boolean MitCrdDlgAvail;
		public boolean MitCrdDlgActive;
		public boolean MitCrdPnlAvail;
		public boolean MitCrdPnlActive;
		public boolean MitCrdQryAvail;
		public boolean MitCrdQryActive;
		public boolean MitCrdQcoAvail;
		public boolean MitCrdQcoActive;
		public boolean MitCrdQmdAvail;
		public boolean MitCrdQmdActive;
		public boolean MitCrdConAvail;
		public boolean MitCrdConActive;
		public boolean MspCrd6Avail;
		public boolean MitCrdOpkAvail;
		public boolean MitCrdOpkActive;
		public boolean MitCrdOpxAvail;
		public boolean MitCrdOpxActive;
		public boolean MspCrd7Avail;
		public boolean MitCrdJobAvail;
		public boolean MitCrdJobActive;
		public boolean MitCrdSgeAvail;
		public boolean MitCrdSgeActive;
		public boolean MitCrdMtdAvail;
		public boolean MitCrdMtdActive;
		public boolean MitCrdBlkAvail;
		public boolean MitCrdBlkActive;
		public boolean MitCrdCalAvail;
		public boolean MitCrdCalActive;
		public boolean MspCrd8Avail;
		public boolean MitCrdCmpAvail;
		public boolean MitCrdRlsAvail;
		public boolean MitCrdRlsActive;
		public boolean MspCrd9Avail;
		public boolean MitCrdAppAvail;
		public boolean MitCrdRtjAvail;
		public boolean MitCrdRtjActive;
		public boolean MitCrdSeqAvail;
		public boolean MitCrdSeqActive;
		public boolean MitCrdSteAvail;
		public boolean MitCrdSteActive;
		public boolean MspCrd10Avail;
		public boolean MitCrdUtlAvail;
		public boolean MspApp2Avail;
		public boolean MitAppMlcAvail;
		public boolean MitAppLoiAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmNav");

			String itemtag = "StatitemShrWznmNav";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefDlgloaini = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgloaini", mask, SCRJREFDLGLOAINI);
				scrJrefDlgmnglic = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgmnglic", mask, SCRJREFDLGMNGLIC);
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);
				scrJrefPre = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefPre", mask, SCRJREFPRE);
				pnlpreAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlpreAvail", mask, PNLPREAVAIL);
				scrJrefAdmin = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAdmin", mask, SCRJREFADMIN);
				pnladminAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnladminAvail", mask, PNLADMINAVAIL);
				scrJrefGlobal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefGlobal", mask, SCRJREFGLOBAL);
				pnlglobalAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlglobalAvail", mask, PNLGLOBALAVAIL);
				scrJrefProject = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefProject", mask, SCRJREFPROJECT);
				pnlprojectAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlprojectAvail", mask, PNLPROJECTAVAIL);
				scrJrefDbstr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDbstr", mask, SCRJREFDBSTR);
				pnldbstrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnldbstrAvail", mask, PNLDBSTRAVAIL);
				scrJrefUix = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefUix", mask, SCRJREFUIX);
				pnluixAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnluixAvail", mask, PNLUIXAVAIL);
				scrJrefComp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefComp", mask, SCRJREFCOMP);
				pnlcompAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlcompAvail", mask, PNLCOMPAVAIL);
				scrJrefJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefJob", mask, SCRJREFJOB);
				pnljobAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnljobAvail", mask, PNLJOBAVAIL);
				scrJrefDeploy = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDeploy", mask, SCRJREFDEPLOY);
				pnldeployAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnldeployAvail", mask, PNLDEPLOYAVAIL);
				scrJrefAppdev = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAppdev", mask, SCRJREFAPPDEV);
				pnlappdevAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlappdevAvail", mask, PNLAPPDEVAVAIL);
				scrJrefAuxfct = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAuxfct", mask, SCRJREFAUXFCT);
				pnlauxfctAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlauxfctAvail", mask, PNLAUXFCTAVAIL);
				MitSesSpsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitSesSpsAvail", mask, MITSESSPSAVAIL);
				MspCrd1Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", mask, MSPCRD1AVAIL);
				MitCrdUsgAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdUsgAvail", mask, MITCRDUSGAVAIL);
				MitCrdUsrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdUsrAvail", mask, MITCRDUSRAVAIL);
				MitCrdPrsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPrsAvail", mask, MITCRDPRSAVAIL);
				MitCrdFilAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdFilAvail", mask, MITCRDFILAVAIL);
				MspCrd2Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd2Avail", mask, MSPCRD2AVAIL);
				MitCrdLocAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdLocAvail", mask, MITCRDLOCAVAIL);
				MitCrdTagAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdTagAvail", mask, MITCRDTAGAVAIL);
				MitCrdCtpAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCtpAvail", mask, MITCRDCTPAVAIL);
				MitCrdMtyAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdMtyAvail", mask, MITCRDMTYAVAIL);
				MitCrdMchAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdMchAvail", mask, MITCRDMCHAVAIL);
				MitCrdLibAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdLibAvail", mask, MITCRDLIBAVAIL);
				MspCrd3Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd3Avail", mask, MSPCRD3AVAIL);
				MitCrdPrjAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPrjAvail", mask, MITCRDPRJAVAIL);
				MitCrdVerAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdVerAvail", mask, MITCRDVERAVAIL);
				MitCrdCapAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCapAvail", mask, MITCRDCAPAVAIL);
				MitCrdCapActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCapActive", mask, MITCRDCAPACTIVE);
				MitCrdErrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdErrAvail", mask, MITCRDERRAVAIL);
				MitCrdErrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdErrActive", mask, MITCRDERRACTIVE);
				MspCrd4Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd4Avail", mask, MSPCRD4AVAIL);
				MitCrdTblAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdTblAvail", mask, MITCRDTBLAVAIL);
				MitCrdTblActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdTblActive", mask, MITCRDTBLACTIVE);
				MitCrdTcoAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdTcoAvail", mask, MITCRDTCOAVAIL);
				MitCrdTcoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdTcoActive", mask, MITCRDTCOACTIVE);
				MitCrdSbsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSbsAvail", mask, MITCRDSBSAVAIL);
				MitCrdSbsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSbsActive", mask, MITCRDSBSACTIVE);
				MitCrdRelAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdRelAvail", mask, MITCRDRELAVAIL);
				MitCrdRelActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdRelActive", mask, MITCRDRELACTIVE);
				MitCrdVecAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdVecAvail", mask, MITCRDVECAVAIL);
				MitCrdVecActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdVecActive", mask, MITCRDVECACTIVE);
				MitCrdVitAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdVitAvail", mask, MITCRDVITAVAIL);
				MitCrdVitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdVitActive", mask, MITCRDVITACTIVE);
				MitCrdChkAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdChkAvail", mask, MITCRDCHKAVAIL);
				MitCrdChkActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdChkActive", mask, MITCRDCHKACTIVE);
				MitCrdStbAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdStbAvail", mask, MITCRDSTBAVAIL);
				MitCrdStbActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdStbActive", mask, MITCRDSTBACTIVE);
				MitCrdIexAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIexAvail", mask, MITCRDIEXAVAIL);
				MitCrdIexActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIexActive", mask, MITCRDIEXACTIVE);
				MitCrdImeAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdImeAvail", mask, MITCRDIMEAVAIL);
				MitCrdImeActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdImeActive", mask, MITCRDIMEACTIVE);
				MspCrd5Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd5Avail", mask, MSPCRD5AVAIL);
				MitCrdPstAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPstAvail", mask, MITCRDPSTAVAIL);
				MitCrdPstActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPstActive", mask, MITCRDPSTACTIVE);
				MitCrdMdlAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdMdlAvail", mask, MITCRDMDLAVAIL);
				MitCrdMdlActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdMdlActive", mask, MITCRDMDLACTIVE);
				MitCrdCarAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCarAvail", mask, MITCRDCARAVAIL);
				MitCrdCarActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCarActive", mask, MITCRDCARACTIVE);
				MitCrdDlgAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdDlgAvail", mask, MITCRDDLGAVAIL);
				MitCrdDlgActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdDlgActive", mask, MITCRDDLGACTIVE);
				MitCrdPnlAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPnlAvail", mask, MITCRDPNLAVAIL);
				MitCrdPnlActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPnlActive", mask, MITCRDPNLACTIVE);
				MitCrdQryAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdQryAvail", mask, MITCRDQRYAVAIL);
				MitCrdQryActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdQryActive", mask, MITCRDQRYACTIVE);
				MitCrdQcoAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdQcoAvail", mask, MITCRDQCOAVAIL);
				MitCrdQcoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdQcoActive", mask, MITCRDQCOACTIVE);
				MitCrdQmdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdQmdAvail", mask, MITCRDQMDAVAIL);
				MitCrdQmdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdQmdActive", mask, MITCRDQMDACTIVE);
				MitCrdConAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdConAvail", mask, MITCRDCONAVAIL);
				MitCrdConActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdConActive", mask, MITCRDCONACTIVE);
				MspCrd6Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd6Avail", mask, MSPCRD6AVAIL);
				MitCrdOpkAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdOpkAvail", mask, MITCRDOPKAVAIL);
				MitCrdOpkActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdOpkActive", mask, MITCRDOPKACTIVE);
				MitCrdOpxAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdOpxAvail", mask, MITCRDOPXAVAIL);
				MitCrdOpxActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdOpxActive", mask, MITCRDOPXACTIVE);
				MspCrd7Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd7Avail", mask, MSPCRD7AVAIL);
				MitCrdJobAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdJobAvail", mask, MITCRDJOBAVAIL);
				MitCrdJobActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdJobActive", mask, MITCRDJOBACTIVE);
				MitCrdSgeAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSgeAvail", mask, MITCRDSGEAVAIL);
				MitCrdSgeActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSgeActive", mask, MITCRDSGEACTIVE);
				MitCrdMtdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdMtdAvail", mask, MITCRDMTDAVAIL);
				MitCrdMtdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdMtdActive", mask, MITCRDMTDACTIVE);
				MitCrdBlkAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdBlkAvail", mask, MITCRDBLKAVAIL);
				MitCrdBlkActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdBlkActive", mask, MITCRDBLKACTIVE);
				MitCrdCalAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCalAvail", mask, MITCRDCALAVAIL);
				MitCrdCalActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCalActive", mask, MITCRDCALACTIVE);
				MspCrd8Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd8Avail", mask, MSPCRD8AVAIL);
				MitCrdCmpAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCmpAvail", mask, MITCRDCMPAVAIL);
				MitCrdRlsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdRlsAvail", mask, MITCRDRLSAVAIL);
				MitCrdRlsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdRlsActive", mask, MITCRDRLSACTIVE);
				MspCrd9Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd9Avail", mask, MSPCRD9AVAIL);
				MitCrdAppAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdAppAvail", mask, MITCRDAPPAVAIL);
				MitCrdRtjAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdRtjAvail", mask, MITCRDRTJAVAIL);
				MitCrdRtjActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdRtjActive", mask, MITCRDRTJACTIVE);
				MitCrdSeqAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSeqAvail", mask, MITCRDSEQAVAIL);
				MitCrdSeqActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSeqActive", mask, MITCRDSEQACTIVE);
				MitCrdSteAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSteAvail", mask, MITCRDSTEAVAIL);
				MitCrdSteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSteActive", mask, MITCRDSTEACTIVE);
				MspCrd10Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd10Avail", mask, MSPCRD10AVAIL);
				MitCrdUtlAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdUtlAvail", mask, MITCRDUTLAVAIL);
				MspApp2Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspApp2Avail", mask, MSPAPP2AVAIL);
				MitAppMlcAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitAppMlcAvail", mask, MITAPPMLCAVAIL);
				MitAppLoiAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitAppLoiAvail", mask, MITAPPLOIAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefDlgloaini.equals(comp.scrJrefDlgloaini)) items.add(SCRJREFDLGLOAINI);
			if (scrJrefDlgmnglic.equals(comp.scrJrefDlgmnglic)) items.add(SCRJREFDLGMNGLIC);
			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);
			if (scrJrefPre.equals(comp.scrJrefPre)) items.add(SCRJREFPRE);
			if (pnlpreAvail == comp.pnlpreAvail) items.add(PNLPREAVAIL);
			if (scrJrefAdmin.equals(comp.scrJrefAdmin)) items.add(SCRJREFADMIN);
			if (pnladminAvail == comp.pnladminAvail) items.add(PNLADMINAVAIL);
			if (scrJrefGlobal.equals(comp.scrJrefGlobal)) items.add(SCRJREFGLOBAL);
			if (pnlglobalAvail == comp.pnlglobalAvail) items.add(PNLGLOBALAVAIL);
			if (scrJrefProject.equals(comp.scrJrefProject)) items.add(SCRJREFPROJECT);
			if (pnlprojectAvail == comp.pnlprojectAvail) items.add(PNLPROJECTAVAIL);
			if (scrJrefDbstr.equals(comp.scrJrefDbstr)) items.add(SCRJREFDBSTR);
			if (pnldbstrAvail == comp.pnldbstrAvail) items.add(PNLDBSTRAVAIL);
			if (scrJrefUix.equals(comp.scrJrefUix)) items.add(SCRJREFUIX);
			if (pnluixAvail == comp.pnluixAvail) items.add(PNLUIXAVAIL);
			if (scrJrefComp.equals(comp.scrJrefComp)) items.add(SCRJREFCOMP);
			if (pnlcompAvail == comp.pnlcompAvail) items.add(PNLCOMPAVAIL);
			if (scrJrefJob.equals(comp.scrJrefJob)) items.add(SCRJREFJOB);
			if (pnljobAvail == comp.pnljobAvail) items.add(PNLJOBAVAIL);
			if (scrJrefDeploy.equals(comp.scrJrefDeploy)) items.add(SCRJREFDEPLOY);
			if (pnldeployAvail == comp.pnldeployAvail) items.add(PNLDEPLOYAVAIL);
			if (scrJrefAppdev.equals(comp.scrJrefAppdev)) items.add(SCRJREFAPPDEV);
			if (pnlappdevAvail == comp.pnlappdevAvail) items.add(PNLAPPDEVAVAIL);
			if (scrJrefAuxfct.equals(comp.scrJrefAuxfct)) items.add(SCRJREFAUXFCT);
			if (pnlauxfctAvail == comp.pnlauxfctAvail) items.add(PNLAUXFCTAVAIL);
			if (MitSesSpsAvail == comp.MitSesSpsAvail) items.add(MITSESSPSAVAIL);
			if (MspCrd1Avail == comp.MspCrd1Avail) items.add(MSPCRD1AVAIL);
			if (MitCrdUsgAvail == comp.MitCrdUsgAvail) items.add(MITCRDUSGAVAIL);
			if (MitCrdUsrAvail == comp.MitCrdUsrAvail) items.add(MITCRDUSRAVAIL);
			if (MitCrdPrsAvail == comp.MitCrdPrsAvail) items.add(MITCRDPRSAVAIL);
			if (MitCrdFilAvail == comp.MitCrdFilAvail) items.add(MITCRDFILAVAIL);
			if (MspCrd2Avail == comp.MspCrd2Avail) items.add(MSPCRD2AVAIL);
			if (MitCrdLocAvail == comp.MitCrdLocAvail) items.add(MITCRDLOCAVAIL);
			if (MitCrdTagAvail == comp.MitCrdTagAvail) items.add(MITCRDTAGAVAIL);
			if (MitCrdCtpAvail == comp.MitCrdCtpAvail) items.add(MITCRDCTPAVAIL);
			if (MitCrdMtyAvail == comp.MitCrdMtyAvail) items.add(MITCRDMTYAVAIL);
			if (MitCrdMchAvail == comp.MitCrdMchAvail) items.add(MITCRDMCHAVAIL);
			if (MitCrdLibAvail == comp.MitCrdLibAvail) items.add(MITCRDLIBAVAIL);
			if (MspCrd3Avail == comp.MspCrd3Avail) items.add(MSPCRD3AVAIL);
			if (MitCrdPrjAvail == comp.MitCrdPrjAvail) items.add(MITCRDPRJAVAIL);
			if (MitCrdVerAvail == comp.MitCrdVerAvail) items.add(MITCRDVERAVAIL);
			if (MitCrdCapAvail == comp.MitCrdCapAvail) items.add(MITCRDCAPAVAIL);
			if (MitCrdCapActive == comp.MitCrdCapActive) items.add(MITCRDCAPACTIVE);
			if (MitCrdErrAvail == comp.MitCrdErrAvail) items.add(MITCRDERRAVAIL);
			if (MitCrdErrActive == comp.MitCrdErrActive) items.add(MITCRDERRACTIVE);
			if (MspCrd4Avail == comp.MspCrd4Avail) items.add(MSPCRD4AVAIL);
			if (MitCrdTblAvail == comp.MitCrdTblAvail) items.add(MITCRDTBLAVAIL);
			if (MitCrdTblActive == comp.MitCrdTblActive) items.add(MITCRDTBLACTIVE);
			if (MitCrdTcoAvail == comp.MitCrdTcoAvail) items.add(MITCRDTCOAVAIL);
			if (MitCrdTcoActive == comp.MitCrdTcoActive) items.add(MITCRDTCOACTIVE);
			if (MitCrdSbsAvail == comp.MitCrdSbsAvail) items.add(MITCRDSBSAVAIL);
			if (MitCrdSbsActive == comp.MitCrdSbsActive) items.add(MITCRDSBSACTIVE);
			if (MitCrdRelAvail == comp.MitCrdRelAvail) items.add(MITCRDRELAVAIL);
			if (MitCrdRelActive == comp.MitCrdRelActive) items.add(MITCRDRELACTIVE);
			if (MitCrdVecAvail == comp.MitCrdVecAvail) items.add(MITCRDVECAVAIL);
			if (MitCrdVecActive == comp.MitCrdVecActive) items.add(MITCRDVECACTIVE);
			if (MitCrdVitAvail == comp.MitCrdVitAvail) items.add(MITCRDVITAVAIL);
			if (MitCrdVitActive == comp.MitCrdVitActive) items.add(MITCRDVITACTIVE);
			if (MitCrdChkAvail == comp.MitCrdChkAvail) items.add(MITCRDCHKAVAIL);
			if (MitCrdChkActive == comp.MitCrdChkActive) items.add(MITCRDCHKACTIVE);
			if (MitCrdStbAvail == comp.MitCrdStbAvail) items.add(MITCRDSTBAVAIL);
			if (MitCrdStbActive == comp.MitCrdStbActive) items.add(MITCRDSTBACTIVE);
			if (MitCrdIexAvail == comp.MitCrdIexAvail) items.add(MITCRDIEXAVAIL);
			if (MitCrdIexActive == comp.MitCrdIexActive) items.add(MITCRDIEXACTIVE);
			if (MitCrdImeAvail == comp.MitCrdImeAvail) items.add(MITCRDIMEAVAIL);
			if (MitCrdImeActive == comp.MitCrdImeActive) items.add(MITCRDIMEACTIVE);
			if (MspCrd5Avail == comp.MspCrd5Avail) items.add(MSPCRD5AVAIL);
			if (MitCrdPstAvail == comp.MitCrdPstAvail) items.add(MITCRDPSTAVAIL);
			if (MitCrdPstActive == comp.MitCrdPstActive) items.add(MITCRDPSTACTIVE);
			if (MitCrdMdlAvail == comp.MitCrdMdlAvail) items.add(MITCRDMDLAVAIL);
			if (MitCrdMdlActive == comp.MitCrdMdlActive) items.add(MITCRDMDLACTIVE);
			if (MitCrdCarAvail == comp.MitCrdCarAvail) items.add(MITCRDCARAVAIL);
			if (MitCrdCarActive == comp.MitCrdCarActive) items.add(MITCRDCARACTIVE);
			if (MitCrdDlgAvail == comp.MitCrdDlgAvail) items.add(MITCRDDLGAVAIL);
			if (MitCrdDlgActive == comp.MitCrdDlgActive) items.add(MITCRDDLGACTIVE);
			if (MitCrdPnlAvail == comp.MitCrdPnlAvail) items.add(MITCRDPNLAVAIL);
			if (MitCrdPnlActive == comp.MitCrdPnlActive) items.add(MITCRDPNLACTIVE);
			if (MitCrdQryAvail == comp.MitCrdQryAvail) items.add(MITCRDQRYAVAIL);
			if (MitCrdQryActive == comp.MitCrdQryActive) items.add(MITCRDQRYACTIVE);
			if (MitCrdQcoAvail == comp.MitCrdQcoAvail) items.add(MITCRDQCOAVAIL);
			if (MitCrdQcoActive == comp.MitCrdQcoActive) items.add(MITCRDQCOACTIVE);
			if (MitCrdQmdAvail == comp.MitCrdQmdAvail) items.add(MITCRDQMDAVAIL);
			if (MitCrdQmdActive == comp.MitCrdQmdActive) items.add(MITCRDQMDACTIVE);
			if (MitCrdConAvail == comp.MitCrdConAvail) items.add(MITCRDCONAVAIL);
			if (MitCrdConActive == comp.MitCrdConActive) items.add(MITCRDCONACTIVE);
			if (MspCrd6Avail == comp.MspCrd6Avail) items.add(MSPCRD6AVAIL);
			if (MitCrdOpkAvail == comp.MitCrdOpkAvail) items.add(MITCRDOPKAVAIL);
			if (MitCrdOpkActive == comp.MitCrdOpkActive) items.add(MITCRDOPKACTIVE);
			if (MitCrdOpxAvail == comp.MitCrdOpxAvail) items.add(MITCRDOPXAVAIL);
			if (MitCrdOpxActive == comp.MitCrdOpxActive) items.add(MITCRDOPXACTIVE);
			if (MspCrd7Avail == comp.MspCrd7Avail) items.add(MSPCRD7AVAIL);
			if (MitCrdJobAvail == comp.MitCrdJobAvail) items.add(MITCRDJOBAVAIL);
			if (MitCrdJobActive == comp.MitCrdJobActive) items.add(MITCRDJOBACTIVE);
			if (MitCrdSgeAvail == comp.MitCrdSgeAvail) items.add(MITCRDSGEAVAIL);
			if (MitCrdSgeActive == comp.MitCrdSgeActive) items.add(MITCRDSGEACTIVE);
			if (MitCrdMtdAvail == comp.MitCrdMtdAvail) items.add(MITCRDMTDAVAIL);
			if (MitCrdMtdActive == comp.MitCrdMtdActive) items.add(MITCRDMTDACTIVE);
			if (MitCrdBlkAvail == comp.MitCrdBlkAvail) items.add(MITCRDBLKAVAIL);
			if (MitCrdBlkActive == comp.MitCrdBlkActive) items.add(MITCRDBLKACTIVE);
			if (MitCrdCalAvail == comp.MitCrdCalAvail) items.add(MITCRDCALAVAIL);
			if (MitCrdCalActive == comp.MitCrdCalActive) items.add(MITCRDCALACTIVE);
			if (MspCrd8Avail == comp.MspCrd8Avail) items.add(MSPCRD8AVAIL);
			if (MitCrdCmpAvail == comp.MitCrdCmpAvail) items.add(MITCRDCMPAVAIL);
			if (MitCrdRlsAvail == comp.MitCrdRlsAvail) items.add(MITCRDRLSAVAIL);
			if (MitCrdRlsActive == comp.MitCrdRlsActive) items.add(MITCRDRLSACTIVE);
			if (MspCrd9Avail == comp.MspCrd9Avail) items.add(MSPCRD9AVAIL);
			if (MitCrdAppAvail == comp.MitCrdAppAvail) items.add(MITCRDAPPAVAIL);
			if (MitCrdRtjAvail == comp.MitCrdRtjAvail) items.add(MITCRDRTJAVAIL);
			if (MitCrdRtjActive == comp.MitCrdRtjActive) items.add(MITCRDRTJACTIVE);
			if (MitCrdSeqAvail == comp.MitCrdSeqAvail) items.add(MITCRDSEQAVAIL);
			if (MitCrdSeqActive == comp.MitCrdSeqActive) items.add(MITCRDSEQACTIVE);
			if (MitCrdSteAvail == comp.MitCrdSteAvail) items.add(MITCRDSTEAVAIL);
			if (MitCrdSteActive == comp.MitCrdSteActive) items.add(MITCRDSTEACTIVE);
			if (MspCrd10Avail == comp.MspCrd10Avail) items.add(MSPCRD10AVAIL);
			if (MitCrdUtlAvail == comp.MitCrdUtlAvail) items.add(MITCRDUTLAVAIL);
			if (MspApp2Avail == comp.MspApp2Avail) items.add(MSPAPP2AVAIL);
			if (MitAppMlcAvail == comp.MitAppMlcAvail) items.add(MITAPPMLCAVAIL);
			if (MitAppLoiAvail == comp.MitAppLoiAvail) items.add(MITAPPLOIAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFDLGLOAINI, SCRJREFDLGMNGLIC, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFGLOBAL, PNLGLOBALAVAIL, SCRJREFPROJECT, PNLPROJECTAVAIL, SCRJREFDBSTR, PNLDBSTRAVAIL, SCRJREFUIX, PNLUIXAVAIL, SCRJREFCOMP, PNLCOMPAVAIL, SCRJREFJOB, PNLJOBAVAIL, SCRJREFDEPLOY, PNLDEPLOYAVAIL, SCRJREFAPPDEV, PNLAPPDEVAVAIL, SCRJREFAUXFCT, PNLAUXFCTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDLOCAVAIL, MITCRDTAGAVAIL, MITCRDCTPAVAIL, MITCRDMTYAVAIL, MITCRDMCHAVAIL, MITCRDLIBAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDVERAVAIL, MITCRDCAPAVAIL, MITCRDCAPACTIVE, MITCRDERRAVAIL, MITCRDERRACTIVE, MSPCRD4AVAIL, MITCRDTBLAVAIL, MITCRDTBLACTIVE, MITCRDTCOAVAIL, MITCRDTCOACTIVE, MITCRDSBSAVAIL, MITCRDSBSACTIVE, MITCRDRELAVAIL, MITCRDRELACTIVE, MITCRDVECAVAIL, MITCRDVECACTIVE, MITCRDVITAVAIL, MITCRDVITACTIVE, MITCRDCHKAVAIL, MITCRDCHKACTIVE, MITCRDSTBAVAIL, MITCRDSTBACTIVE, MITCRDIEXAVAIL, MITCRDIEXACTIVE, MITCRDIMEAVAIL, MITCRDIMEACTIVE, MSPCRD5AVAIL, MITCRDPSTAVAIL, MITCRDPSTACTIVE, MITCRDMDLAVAIL, MITCRDMDLACTIVE, MITCRDCARAVAIL, MITCRDCARACTIVE, MITCRDDLGAVAIL, MITCRDDLGACTIVE, MITCRDPNLAVAIL, MITCRDPNLACTIVE, MITCRDQRYAVAIL, MITCRDQRYACTIVE, MITCRDQCOAVAIL, MITCRDQCOACTIVE, MITCRDQMDAVAIL, MITCRDQMDACTIVE, MITCRDCONAVAIL, MITCRDCONACTIVE, MSPCRD6AVAIL, MITCRDOPKAVAIL, MITCRDOPKACTIVE, MITCRDOPXAVAIL, MITCRDOPXACTIVE, MSPCRD7AVAIL, MITCRDJOBAVAIL, MITCRDJOBACTIVE, MITCRDSGEAVAIL, MITCRDSGEACTIVE, MITCRDMTDAVAIL, MITCRDMTDACTIVE, MITCRDBLKAVAIL, MITCRDBLKACTIVE, MITCRDCALAVAIL, MITCRDCALACTIVE, MSPCRD8AVAIL, MITCRDCMPAVAIL, MITCRDRLSAVAIL, MITCRDRLSACTIVE, MSPCRD9AVAIL, MITCRDAPPAVAIL, MITCRDRTJAVAIL, MITCRDRTJACTIVE, MITCRDSEQAVAIL, MITCRDSEQACTIVE, MITCRDSTEAVAIL, MITCRDSTEACTIVE, MSPCRD10AVAIL, MITCRDUTLAVAIL, MSPAPP2AVAIL, MITAPPMLCAVAIL, MITAPPLOIAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmNav)
	  */
	public class Tag extends Block {

		public static final int MITAPPABT = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MITSESSPS = 3;
		public static final int MITSESTRM = 4;
		public static final int MITCRDUSG = 5;
		public static final int MITCRDUSR = 6;
		public static final int MITCRDPRS = 7;
		public static final int MITCRDFIL = 8;
		public static final int MITCRDLOC = 9;
		public static final int MITCRDTAG = 10;
		public static final int MITCRDCTP = 11;
		public static final int MITCRDMTY = 12;
		public static final int MITCRDMCH = 13;
		public static final int MITCRDLIB = 14;
		public static final int MITCRDPRJ = 15;
		public static final int MITCRDVER = 16;
		public static final int MITCRDCAP = 17;
		public static final int MITCRDERR = 18;
		public static final int MITCRDTBL = 19;
		public static final int MITCRDTCO = 20;
		public static final int MITCRDSBS = 21;
		public static final int MITCRDREL = 22;
		public static final int MITCRDVEC = 23;
		public static final int MITCRDVIT = 24;
		public static final int MITCRDCHK = 25;
		public static final int MITCRDSTB = 26;
		public static final int MITCRDIEX = 27;
		public static final int MITCRDIME = 28;
		public static final int MITCRDPST = 29;
		public static final int MITCRDMDL = 30;
		public static final int MITCRDCAR = 31;
		public static final int MITCRDDLG = 32;
		public static final int MITCRDPNL = 33;
		public static final int MITCRDQRY = 34;
		public static final int MITCRDQCO = 35;
		public static final int MITCRDQMD = 36;
		public static final int MITCRDCON = 37;
		public static final int MITCRDOPK = 38;
		public static final int MITCRDOPX = 39;
		public static final int MITCRDJOB = 40;
		public static final int MITCRDSGE = 41;
		public static final int MITCRDMTD = 42;
		public static final int MITCRDBLK = 43;
		public static final int MITCRDCAL = 44;
		public static final int MITCRDCMP = 45;
		public static final int MITCRDRLS = 46;
		public static final int MITCRDAPP = 47;
		public static final int MITCRDRTJ = 48;
		public static final int MITCRDSEQ = 49;
		public static final int MITCRDSTE = 50;
		public static final int MITCRDUTL = 51;
		public static final int MITAPPMLC = 52;
		public static final int MITAPPLOI = 53;

		public Tag(
					String MitAppAbt
					, String MrlAppHlp
					, String MitSesSps
					, String MitSesTrm
					, String MitCrdUsg
					, String MitCrdUsr
					, String MitCrdPrs
					, String MitCrdFil
					, String MitCrdLoc
					, String MitCrdTag
					, String MitCrdCtp
					, String MitCrdMty
					, String MitCrdMch
					, String MitCrdLib
					, String MitCrdPrj
					, String MitCrdVer
					, String MitCrdCap
					, String MitCrdErr
					, String MitCrdTbl
					, String MitCrdTco
					, String MitCrdSbs
					, String MitCrdRel
					, String MitCrdVec
					, String MitCrdVit
					, String MitCrdChk
					, String MitCrdStb
					, String MitCrdIex
					, String MitCrdIme
					, String MitCrdPst
					, String MitCrdMdl
					, String MitCrdCar
					, String MitCrdDlg
					, String MitCrdPnl
					, String MitCrdQry
					, String MitCrdQco
					, String MitCrdQmd
					, String MitCrdCon
					, String MitCrdOpk
					, String MitCrdOpx
					, String MitCrdJob
					, String MitCrdSge
					, String MitCrdMtd
					, String MitCrdBlk
					, String MitCrdCal
					, String MitCrdCmp
					, String MitCrdRls
					, String MitCrdApp
					, String MitCrdRtj
					, String MitCrdSeq
					, String MitCrdSte
					, String MitCrdUtl
					, String MitAppMlc
					, String MitAppLoi
				) {
			this.MitAppAbt = MitAppAbt;
			this.MrlAppHlp = MrlAppHlp;
			this.MitSesSps = MitSesSps;
			this.MitSesTrm = MitSesTrm;
			this.MitCrdUsg = MitCrdUsg;
			this.MitCrdUsr = MitCrdUsr;
			this.MitCrdPrs = MitCrdPrs;
			this.MitCrdFil = MitCrdFil;
			this.MitCrdLoc = MitCrdLoc;
			this.MitCrdTag = MitCrdTag;
			this.MitCrdCtp = MitCrdCtp;
			this.MitCrdMty = MitCrdMty;
			this.MitCrdMch = MitCrdMch;
			this.MitCrdLib = MitCrdLib;
			this.MitCrdPrj = MitCrdPrj;
			this.MitCrdVer = MitCrdVer;
			this.MitCrdCap = MitCrdCap;
			this.MitCrdErr = MitCrdErr;
			this.MitCrdTbl = MitCrdTbl;
			this.MitCrdTco = MitCrdTco;
			this.MitCrdSbs = MitCrdSbs;
			this.MitCrdRel = MitCrdRel;
			this.MitCrdVec = MitCrdVec;
			this.MitCrdVit = MitCrdVit;
			this.MitCrdChk = MitCrdChk;
			this.MitCrdStb = MitCrdStb;
			this.MitCrdIex = MitCrdIex;
			this.MitCrdIme = MitCrdIme;
			this.MitCrdPst = MitCrdPst;
			this.MitCrdMdl = MitCrdMdl;
			this.MitCrdCar = MitCrdCar;
			this.MitCrdDlg = MitCrdDlg;
			this.MitCrdPnl = MitCrdPnl;
			this.MitCrdQry = MitCrdQry;
			this.MitCrdQco = MitCrdQco;
			this.MitCrdQmd = MitCrdQmd;
			this.MitCrdCon = MitCrdCon;
			this.MitCrdOpk = MitCrdOpk;
			this.MitCrdOpx = MitCrdOpx;
			this.MitCrdJob = MitCrdJob;
			this.MitCrdSge = MitCrdSge;
			this.MitCrdMtd = MitCrdMtd;
			this.MitCrdBlk = MitCrdBlk;
			this.MitCrdCal = MitCrdCal;
			this.MitCrdCmp = MitCrdCmp;
			this.MitCrdRls = MitCrdRls;
			this.MitCrdApp = MitCrdApp;
			this.MitCrdRtj = MitCrdRtj;
			this.MitCrdSeq = MitCrdSeq;
			this.MitCrdSte = MitCrdSte;
			this.MitCrdUtl = MitCrdUtl;
			this.MitAppMlc = MitAppMlc;
			this.MitAppLoi = MitAppLoi;

			mask = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITSESSPS, MITSESTRM, MITCRDUSG, MITCRDUSR, MITCRDPRS, MITCRDFIL, MITCRDLOC, MITCRDTAG, MITCRDCTP, MITCRDMTY, MITCRDMCH, MITCRDLIB, MITCRDPRJ, MITCRDVER, MITCRDCAP, MITCRDERR, MITCRDTBL, MITCRDTCO, MITCRDSBS, MITCRDREL, MITCRDVEC, MITCRDVIT, MITCRDCHK, MITCRDSTB, MITCRDIEX, MITCRDIME, MITCRDPST, MITCRDMDL, MITCRDCAR, MITCRDDLG, MITCRDPNL, MITCRDQRY, MITCRDQCO, MITCRDQMD, MITCRDCON, MITCRDOPK, MITCRDOPX, MITCRDJOB, MITCRDSGE, MITCRDMTD, MITCRDBLK, MITCRDCAL, MITCRDCMP, MITCRDRLS, MITCRDAPP, MITCRDRTJ, MITCRDSEQ, MITCRDSTE, MITCRDUTL, MITAPPMLC, MITAPPLOI));
		};

		public String MitAppAbt;
		public String MrlAppHlp;
		public String MitSesSps;
		public String MitSesTrm;
		public String MitCrdUsg;
		public String MitCrdUsr;
		public String MitCrdPrs;
		public String MitCrdFil;
		public String MitCrdLoc;
		public String MitCrdTag;
		public String MitCrdCtp;
		public String MitCrdMty;
		public String MitCrdMch;
		public String MitCrdLib;
		public String MitCrdPrj;
		public String MitCrdVer;
		public String MitCrdCap;
		public String MitCrdErr;
		public String MitCrdTbl;
		public String MitCrdTco;
		public String MitCrdSbs;
		public String MitCrdRel;
		public String MitCrdVec;
		public String MitCrdVit;
		public String MitCrdChk;
		public String MitCrdStb;
		public String MitCrdIex;
		public String MitCrdIme;
		public String MitCrdPst;
		public String MitCrdMdl;
		public String MitCrdCar;
		public String MitCrdDlg;
		public String MitCrdPnl;
		public String MitCrdQry;
		public String MitCrdQco;
		public String MitCrdQmd;
		public String MitCrdCon;
		public String MitCrdOpk;
		public String MitCrdOpx;
		public String MitCrdJob;
		public String MitCrdSge;
		public String MitCrdMtd;
		public String MitCrdBlk;
		public String MitCrdCal;
		public String MitCrdCmp;
		public String MitCrdRls;
		public String MitCrdApp;
		public String MitCrdRtj;
		public String MitCrdSeq;
		public String MitCrdSte;
		public String MitCrdUtl;
		public String MitAppMlc;
		public String MitAppLoi;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmNav");

			String itemtag = "TagitemWznmNav";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppAbt", mask, MITAPPABT);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MitSesSps = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitSesSps", mask, MITSESSPS);
				MitSesTrm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitSesTrm", mask, MITSESTRM);
				MitCrdUsg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdUsg", mask, MITCRDUSG);
				MitCrdUsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdUsr", mask, MITCRDUSR);
				MitCrdPrs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdPrs", mask, MITCRDPRS);
				MitCrdFil = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdFil", mask, MITCRDFIL);
				MitCrdLoc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdLoc", mask, MITCRDLOC);
				MitCrdTag = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdTag", mask, MITCRDTAG);
				MitCrdCtp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdCtp", mask, MITCRDCTP);
				MitCrdMty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdMty", mask, MITCRDMTY);
				MitCrdMch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdMch", mask, MITCRDMCH);
				MitCrdLib = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdLib", mask, MITCRDLIB);
				MitCrdPrj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdPrj", mask, MITCRDPRJ);
				MitCrdVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdVer", mask, MITCRDVER);
				MitCrdCap = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdCap", mask, MITCRDCAP);
				MitCrdErr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdErr", mask, MITCRDERR);
				MitCrdTbl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdTbl", mask, MITCRDTBL);
				MitCrdTco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdTco", mask, MITCRDTCO);
				MitCrdSbs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdSbs", mask, MITCRDSBS);
				MitCrdRel = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdRel", mask, MITCRDREL);
				MitCrdVec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdVec", mask, MITCRDVEC);
				MitCrdVit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdVit", mask, MITCRDVIT);
				MitCrdChk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdChk", mask, MITCRDCHK);
				MitCrdStb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdStb", mask, MITCRDSTB);
				MitCrdIex = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIex", mask, MITCRDIEX);
				MitCrdIme = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIme", mask, MITCRDIME);
				MitCrdPst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdPst", mask, MITCRDPST);
				MitCrdMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdMdl", mask, MITCRDMDL);
				MitCrdCar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdCar", mask, MITCRDCAR);
				MitCrdDlg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdDlg", mask, MITCRDDLG);
				MitCrdPnl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdPnl", mask, MITCRDPNL);
				MitCrdQry = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdQry", mask, MITCRDQRY);
				MitCrdQco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdQco", mask, MITCRDQCO);
				MitCrdQmd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdQmd", mask, MITCRDQMD);
				MitCrdCon = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdCon", mask, MITCRDCON);
				MitCrdOpk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdOpk", mask, MITCRDOPK);
				MitCrdOpx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdOpx", mask, MITCRDOPX);
				MitCrdJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdJob", mask, MITCRDJOB);
				MitCrdSge = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdSge", mask, MITCRDSGE);
				MitCrdMtd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdMtd", mask, MITCRDMTD);
				MitCrdBlk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdBlk", mask, MITCRDBLK);
				MitCrdCal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdCal", mask, MITCRDCAL);
				MitCrdCmp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdCmp", mask, MITCRDCMP);
				MitCrdRls = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdRls", mask, MITCRDRLS);
				MitCrdApp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdApp", mask, MITCRDAPP);
				MitCrdRtj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdRtj", mask, MITCRDRTJ);
				MitCrdSeq = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdSeq", mask, MITCRDSEQ);
				MitCrdSte = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdSte", mask, MITCRDSTE);
				MitCrdUtl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdUtl", mask, MITCRDUTL);
				MitAppMlc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppMlc", mask, MITAPPMLC);
				MitAppLoi = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppLoi", mask, MITAPPLOI);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (MitAppAbt.equals(comp.MitAppAbt)) items.add(MITAPPABT);
			if (MrlAppHlp.equals(comp.MrlAppHlp)) items.add(MRLAPPHLP);
			if (MitSesSps.equals(comp.MitSesSps)) items.add(MITSESSPS);
			if (MitSesTrm.equals(comp.MitSesTrm)) items.add(MITSESTRM);
			if (MitCrdUsg.equals(comp.MitCrdUsg)) items.add(MITCRDUSG);
			if (MitCrdUsr.equals(comp.MitCrdUsr)) items.add(MITCRDUSR);
			if (MitCrdPrs.equals(comp.MitCrdPrs)) items.add(MITCRDPRS);
			if (MitCrdFil.equals(comp.MitCrdFil)) items.add(MITCRDFIL);
			if (MitCrdLoc.equals(comp.MitCrdLoc)) items.add(MITCRDLOC);
			if (MitCrdTag.equals(comp.MitCrdTag)) items.add(MITCRDTAG);
			if (MitCrdCtp.equals(comp.MitCrdCtp)) items.add(MITCRDCTP);
			if (MitCrdMty.equals(comp.MitCrdMty)) items.add(MITCRDMTY);
			if (MitCrdMch.equals(comp.MitCrdMch)) items.add(MITCRDMCH);
			if (MitCrdLib.equals(comp.MitCrdLib)) items.add(MITCRDLIB);
			if (MitCrdPrj.equals(comp.MitCrdPrj)) items.add(MITCRDPRJ);
			if (MitCrdVer.equals(comp.MitCrdVer)) items.add(MITCRDVER);
			if (MitCrdCap.equals(comp.MitCrdCap)) items.add(MITCRDCAP);
			if (MitCrdErr.equals(comp.MitCrdErr)) items.add(MITCRDERR);
			if (MitCrdTbl.equals(comp.MitCrdTbl)) items.add(MITCRDTBL);
			if (MitCrdTco.equals(comp.MitCrdTco)) items.add(MITCRDTCO);
			if (MitCrdSbs.equals(comp.MitCrdSbs)) items.add(MITCRDSBS);
			if (MitCrdRel.equals(comp.MitCrdRel)) items.add(MITCRDREL);
			if (MitCrdVec.equals(comp.MitCrdVec)) items.add(MITCRDVEC);
			if (MitCrdVit.equals(comp.MitCrdVit)) items.add(MITCRDVIT);
			if (MitCrdChk.equals(comp.MitCrdChk)) items.add(MITCRDCHK);
			if (MitCrdStb.equals(comp.MitCrdStb)) items.add(MITCRDSTB);
			if (MitCrdIex.equals(comp.MitCrdIex)) items.add(MITCRDIEX);
			if (MitCrdIme.equals(comp.MitCrdIme)) items.add(MITCRDIME);
			if (MitCrdPst.equals(comp.MitCrdPst)) items.add(MITCRDPST);
			if (MitCrdMdl.equals(comp.MitCrdMdl)) items.add(MITCRDMDL);
			if (MitCrdCar.equals(comp.MitCrdCar)) items.add(MITCRDCAR);
			if (MitCrdDlg.equals(comp.MitCrdDlg)) items.add(MITCRDDLG);
			if (MitCrdPnl.equals(comp.MitCrdPnl)) items.add(MITCRDPNL);
			if (MitCrdQry.equals(comp.MitCrdQry)) items.add(MITCRDQRY);
			if (MitCrdQco.equals(comp.MitCrdQco)) items.add(MITCRDQCO);
			if (MitCrdQmd.equals(comp.MitCrdQmd)) items.add(MITCRDQMD);
			if (MitCrdCon.equals(comp.MitCrdCon)) items.add(MITCRDCON);
			if (MitCrdOpk.equals(comp.MitCrdOpk)) items.add(MITCRDOPK);
			if (MitCrdOpx.equals(comp.MitCrdOpx)) items.add(MITCRDOPX);
			if (MitCrdJob.equals(comp.MitCrdJob)) items.add(MITCRDJOB);
			if (MitCrdSge.equals(comp.MitCrdSge)) items.add(MITCRDSGE);
			if (MitCrdMtd.equals(comp.MitCrdMtd)) items.add(MITCRDMTD);
			if (MitCrdBlk.equals(comp.MitCrdBlk)) items.add(MITCRDBLK);
			if (MitCrdCal.equals(comp.MitCrdCal)) items.add(MITCRDCAL);
			if (MitCrdCmp.equals(comp.MitCrdCmp)) items.add(MITCRDCMP);
			if (MitCrdRls.equals(comp.MitCrdRls)) items.add(MITCRDRLS);
			if (MitCrdApp.equals(comp.MitCrdApp)) items.add(MITCRDAPP);
			if (MitCrdRtj.equals(comp.MitCrdRtj)) items.add(MITCRDRTJ);
			if (MitCrdSeq.equals(comp.MitCrdSeq)) items.add(MITCRDSEQ);
			if (MitCrdSte.equals(comp.MitCrdSte)) items.add(MITCRDSTE);
			if (MitCrdUtl.equals(comp.MitCrdUtl)) items.add(MITCRDUTL);
			if (MitAppMlc.equals(comp.MitAppMlc)) items.add(MITAPPMLC);
			if (MitAppLoi.equals(comp.MitAppLoi)) items.add(MITAPPLOI);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITSESSPS, MITSESTRM, MITCRDUSG, MITCRDUSR, MITCRDPRS, MITCRDFIL, MITCRDLOC, MITCRDTAG, MITCRDCTP, MITCRDMTY, MITCRDMCH, MITCRDLIB, MITCRDPRJ, MITCRDVER, MITCRDCAP, MITCRDERR, MITCRDTBL, MITCRDTCO, MITCRDSBS, MITCRDREL, MITCRDVEC, MITCRDVIT, MITCRDCHK, MITCRDSTB, MITCRDIEX, MITCRDIME, MITCRDPST, MITCRDMDL, MITCRDCAR, MITCRDDLG, MITCRDPNL, MITCRDQRY, MITCRDQCO, MITCRDQMD, MITCRDCON, MITCRDOPK, MITCRDOPX, MITCRDJOB, MITCRDSGE, MITCRDMTD, MITCRDBLK, MITCRDCAL, MITCRDCMP, MITCRDRLS, MITCRDAPP, MITCRDRTJ, MITCRDSEQ, MITCRDSTE, MITCRDUTL, MITAPPMLC, MITAPPLOI));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmNavDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmNavData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMNAVDATA);

			continf = new ContInf(0, "", "", "", "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(0, 0, "", 0, false, false, false, false, false, false, false, false, false, false, false, false);
			statshr = new StatShr("", "", "", "", false, "", false, "", false, "", false, "", false, "", false, "", false, "", false, "", false, "", false, "", false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContInf continf;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFSGE)) ss.add("feedFSge");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmNavData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf(0, "", "", "", "");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(0, 0, "", 0, false, false, false, false, false, false, false, false, false, false, false, false);
				statshr = new StatShr("", "", "", "", false, "", false, "", false, "", false, "", false, "", false, "", false, "", false, "", false, "", false, "", false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

