/**
  * \file CrdWznmVer.java
  * Java API code for job CrdWznmVer
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class CrdWznmVer {
	/**
		* VecVDo (full: VecVWznmVerDo)
		*/
	public static class VecVDo {

		public static final int CLOSE = 1;
		public static final int MITAPPABTCLICK = 2;
		public static final int MITCRDNEWCLICK = 3;
		public static final int MITCRDPCVCLICK = 4;
		public static final int MITCRDIDPCLICK = 5;
		public static final int MITCRDIGBCLICK = 6;
		public static final int MITCRDWSKCLICK = 7;
		public static final int MITCRDIDBCLICK = 8;
		public static final int MITCRDIBUCLICK = 9;
		public static final int MITCRDIIECLICK = 10;
		public static final int MITCRDIOPCLICK = 11;
		public static final int MITCRDICJCLICK = 12;
		public static final int MITCRDGUICLICK = 13;
		public static final int MITCRDAUICLICK = 14;
		public static final int MITCRDGJTCLICK = 15;
		public static final int MITCRDAJTCLICK = 16;
		public static final int MITCRDFNMCLICK = 17;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("close")) return CLOSE;
			if (s.equals("mitappabtclick")) return MITAPPABTCLICK;
			if (s.equals("mitcrdnewclick")) return MITCRDNEWCLICK;
			if (s.equals("mitcrdpcvclick")) return MITCRDPCVCLICK;
			if (s.equals("mitcrdidpclick")) return MITCRDIDPCLICK;
			if (s.equals("mitcrdigbclick")) return MITCRDIGBCLICK;
			if (s.equals("mitcrdwskclick")) return MITCRDWSKCLICK;
			if (s.equals("mitcrdidbclick")) return MITCRDIDBCLICK;
			if (s.equals("mitcrdibuclick")) return MITCRDIBUCLICK;
			if (s.equals("mitcrdiieclick")) return MITCRDIIECLICK;
			if (s.equals("mitcrdiopclick")) return MITCRDIOPCLICK;
			if (s.equals("mitcrdicjclick")) return MITCRDICJCLICK;
			if (s.equals("mitcrdguiclick")) return MITCRDGUICLICK;
			if (s.equals("mitcrdauiclick")) return MITCRDAUICLICK;
			if (s.equals("mitcrdgjtclick")) return MITCRDGJTCLICK;
			if (s.equals("mitcrdajtclick")) return MITCRDAJTCLICK;
			if (s.equals("mitcrdfnmclick")) return MITCRDFNMCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == CLOSE) return("close");
			if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
			if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
			if (ix == MITCRDPCVCLICK) return("MitCrdPcvClick");
			if (ix == MITCRDIDPCLICK) return("MitCrdIdpClick");
			if (ix == MITCRDIGBCLICK) return("MitCrdIgbClick");
			if (ix == MITCRDWSKCLICK) return("MitCrdWskClick");
			if (ix == MITCRDIDBCLICK) return("MitCrdIdbClick");
			if (ix == MITCRDIBUCLICK) return("MitCrdIbuClick");
			if (ix == MITCRDIIECLICK) return("MitCrdIieClick");
			if (ix == MITCRDIOPCLICK) return("MitCrdIopClick");
			if (ix == MITCRDICJCLICK) return("MitCrdIcjClick");
			if (ix == MITCRDGUICLICK) return("MitCrdGuiClick");
			if (ix == MITCRDAUICLICK) return("MitCrdAuiClick");
			if (ix == MITCRDGJTCLICK) return("MitCrdGjtClick");
			if (ix == MITCRDAJTCLICK) return("MitCrdAjtClick");
			if (ix == MITCRDFNMCLICK) return("MitCrdFnmClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVWznmVerSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRWZNMABT = 2;
		public static final int ALRCVW = 3;
		public static final int SETPRJCVR = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alrwznmabt")) return ALRWZNMABT;
			if (s.equals("alrcvw")) return ALRCVW;
			if (s.equals("setprjcvr")) return SETPRJCVR;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == ALRWZNMABT) return("alrwznmabt");
			if (ix == ALRCVW) return("alrcvw");
			if (ix == SETPRJCVR) return("setprjcvr");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWznmVer)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MTXCRDVER = 3;

		public ContInf(
					int numFSge
					, String MrlAppHlp
					, String MtxCrdVer
				) {
			this.numFSge = numFSge;
			this.MrlAppHlp = MrlAppHlp;
			this.MtxCrdVer = MtxCrdVer;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXCRDVER));
		};

		public int numFSge;
		public String MrlAppHlp;
		public String MtxCrdVer;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmVer");

			String itemtag = "ContitemInfWznmVer";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MtxCrdVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxCrdVer", mask, MTXCRDVER);

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
			if (MtxCrdVer.equals(comp.MtxCrdVer)) items.add(MTXCRDVER);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXCRDVER));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmVer)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVREQITMODE = 1;
		public static final int LATENCY = 2;
		public static final int SHORTMENU = 3;
		public static final int WIDTHMENU = 4;
		public static final int INITDONEHEADBAR = 5;
		public static final int INITDONELIST = 6;
		public static final int INITDONEREC = 7;

		public StatApp(
					int ixWznmVReqitmode
					, int latency
					, String shortMenu
					, int widthMenu
					, boolean initdoneHeadbar
					, boolean initdoneList
					, boolean initdoneRec
				) {
			this.ixWznmVReqitmode = ixWznmVReqitmode;
			this.latency = latency;
			this.shortMenu = shortMenu;
			this.widthMenu = widthMenu;
			this.initdoneHeadbar = initdoneHeadbar;
			this.initdoneList = initdoneList;
			this.initdoneRec = initdoneRec;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC));
		};

		public int ixWznmVReqitmode;
		public int latency;
		public String shortMenu;
		public int widthMenu;
		public boolean initdoneHeadbar;
		public boolean initdoneList;
		public boolean initdoneRec;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVReqitmode;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmVer");

			String itemtag = "StatitemAppWznmVer";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVReqitmode", mask, IXWZNMVREQITMODE);
				ixWznmVReqitmode = VecWznmVReqitmode.getIx(srefIxWznmVReqitmode);
				latency = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "latency", mask, LATENCY);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				widthMenu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "widthMenu", mask, WIDTHMENU);
				initdoneHeadbar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", mask, INITDONEHEADBAR);
				initdoneList = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneList", mask, INITDONELIST);
				initdoneRec = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRec", mask, INITDONEREC);

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
			if (initdoneList == comp.initdoneList) items.add(INITDONELIST);
			if (initdoneRec == comp.initdoneRec) items.add(INITDONEREC);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmVer)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFDLGBSCUI = 1;
		public static final int SCRJREFDLGCUSTJOB = 2;
		public static final int SCRJREFDLGCUSTJTR = 3;
		public static final int SCRJREFDLGCUSTUI = 4;
		public static final int SCRJREFDLGDBSTR = 5;
		public static final int SCRJREFDLGDEPLOY = 6;
		public static final int SCRJREFDLGFINMOD = 7;
		public static final int SCRJREFDLGGENJTR = 8;
		public static final int SCRJREFDLGGENUI = 9;
		public static final int SCRJREFDLGGLOBAL = 10;
		public static final int SCRJREFDLGIMPEXP = 11;
		public static final int SCRJREFDLGNEW = 12;
		public static final int SCRJREFDLGOPPACK = 13;
		public static final int SCRJREFDLGWRSTKIT = 14;
		public static final int SCRJREFHEADBAR = 15;
		public static final int SCRJREFLIST = 16;
		public static final int SCRJREFREC = 17;
		public static final int MSPCRD1AVAIL = 18;
		public static final int MITCRDNEWAVAIL = 19;
		public static final int MITCRDPCVAVAIL = 20;
		public static final int MITCRDPCVACTIVE = 21;
		public static final int MSPCRD3AVAIL = 22;
		public static final int MITCRDIDPAVAIL = 23;
		public static final int MITCRDIDPACTIVE = 24;
		public static final int MITCRDIGBAVAIL = 25;
		public static final int MITCRDIGBACTIVE = 26;
		public static final int MSPCRD4AVAIL = 27;
		public static final int MITCRDWSKAVAIL = 28;
		public static final int MITCRDWSKACTIVE = 29;
		public static final int MSPCRD5AVAIL = 30;
		public static final int MITCRDIDBAVAIL = 31;
		public static final int MITCRDIDBACTIVE = 32;
		public static final int MITCRDIBUAVAIL = 33;
		public static final int MITCRDIBUACTIVE = 34;
		public static final int MITCRDIIEAVAIL = 35;
		public static final int MITCRDIIEACTIVE = 36;
		public static final int MITCRDIOPAVAIL = 37;
		public static final int MITCRDIOPACTIVE = 38;
		public static final int MITCRDICJAVAIL = 39;
		public static final int MITCRDICJACTIVE = 40;
		public static final int MSPCRD6AVAIL = 41;
		public static final int MITCRDGUIAVAIL = 42;
		public static final int MITCRDGUIACTIVE = 43;
		public static final int MITCRDAUIAVAIL = 44;
		public static final int MITCRDAUIACTIVE = 45;
		public static final int MITCRDGJTAVAIL = 46;
		public static final int MITCRDGJTACTIVE = 47;
		public static final int MITCRDAJTAVAIL = 48;
		public static final int MITCRDAJTACTIVE = 49;
		public static final int MSPCRD7AVAIL = 50;
		public static final int MITCRDFNMAVAIL = 51;
		public static final int MITCRDFNMACTIVE = 52;

		public StatShr(
					String scrJrefDlgbscui
					, String scrJrefDlgcustjob
					, String scrJrefDlgcustjtr
					, String scrJrefDlgcustui
					, String scrJrefDlgdbstr
					, String scrJrefDlgdeploy
					, String scrJrefDlgfinmod
					, String scrJrefDlggenjtr
					, String scrJrefDlggenui
					, String scrJrefDlgglobal
					, String scrJrefDlgimpexp
					, String scrJrefDlgnew
					, String scrJrefDlgoppack
					, String scrJrefDlgwrstkit
					, String scrJrefHeadbar
					, String scrJrefList
					, String scrJrefRec
					, boolean MspCrd1Avail
					, boolean MitCrdNewAvail
					, boolean MitCrdPcvAvail
					, boolean MitCrdPcvActive
					, boolean MspCrd3Avail
					, boolean MitCrdIdpAvail
					, boolean MitCrdIdpActive
					, boolean MitCrdIgbAvail
					, boolean MitCrdIgbActive
					, boolean MspCrd4Avail
					, boolean MitCrdWskAvail
					, boolean MitCrdWskActive
					, boolean MspCrd5Avail
					, boolean MitCrdIdbAvail
					, boolean MitCrdIdbActive
					, boolean MitCrdIbuAvail
					, boolean MitCrdIbuActive
					, boolean MitCrdIieAvail
					, boolean MitCrdIieActive
					, boolean MitCrdIopAvail
					, boolean MitCrdIopActive
					, boolean MitCrdIcjAvail
					, boolean MitCrdIcjActive
					, boolean MspCrd6Avail
					, boolean MitCrdGuiAvail
					, boolean MitCrdGuiActive
					, boolean MitCrdAuiAvail
					, boolean MitCrdAuiActive
					, boolean MitCrdGjtAvail
					, boolean MitCrdGjtActive
					, boolean MitCrdAjtAvail
					, boolean MitCrdAjtActive
					, boolean MspCrd7Avail
					, boolean MitCrdFnmAvail
					, boolean MitCrdFnmActive
				) {
			this.scrJrefDlgbscui = scrJrefDlgbscui;
			this.scrJrefDlgcustjob = scrJrefDlgcustjob;
			this.scrJrefDlgcustjtr = scrJrefDlgcustjtr;
			this.scrJrefDlgcustui = scrJrefDlgcustui;
			this.scrJrefDlgdbstr = scrJrefDlgdbstr;
			this.scrJrefDlgdeploy = scrJrefDlgdeploy;
			this.scrJrefDlgfinmod = scrJrefDlgfinmod;
			this.scrJrefDlggenjtr = scrJrefDlggenjtr;
			this.scrJrefDlggenui = scrJrefDlggenui;
			this.scrJrefDlgglobal = scrJrefDlgglobal;
			this.scrJrefDlgimpexp = scrJrefDlgimpexp;
			this.scrJrefDlgnew = scrJrefDlgnew;
			this.scrJrefDlgoppack = scrJrefDlgoppack;
			this.scrJrefDlgwrstkit = scrJrefDlgwrstkit;
			this.scrJrefHeadbar = scrJrefHeadbar;
			this.scrJrefList = scrJrefList;
			this.scrJrefRec = scrJrefRec;
			this.MspCrd1Avail = MspCrd1Avail;
			this.MitCrdNewAvail = MitCrdNewAvail;
			this.MitCrdPcvAvail = MitCrdPcvAvail;
			this.MitCrdPcvActive = MitCrdPcvActive;
			this.MspCrd3Avail = MspCrd3Avail;
			this.MitCrdIdpAvail = MitCrdIdpAvail;
			this.MitCrdIdpActive = MitCrdIdpActive;
			this.MitCrdIgbAvail = MitCrdIgbAvail;
			this.MitCrdIgbActive = MitCrdIgbActive;
			this.MspCrd4Avail = MspCrd4Avail;
			this.MitCrdWskAvail = MitCrdWskAvail;
			this.MitCrdWskActive = MitCrdWskActive;
			this.MspCrd5Avail = MspCrd5Avail;
			this.MitCrdIdbAvail = MitCrdIdbAvail;
			this.MitCrdIdbActive = MitCrdIdbActive;
			this.MitCrdIbuAvail = MitCrdIbuAvail;
			this.MitCrdIbuActive = MitCrdIbuActive;
			this.MitCrdIieAvail = MitCrdIieAvail;
			this.MitCrdIieActive = MitCrdIieActive;
			this.MitCrdIopAvail = MitCrdIopAvail;
			this.MitCrdIopActive = MitCrdIopActive;
			this.MitCrdIcjAvail = MitCrdIcjAvail;
			this.MitCrdIcjActive = MitCrdIcjActive;
			this.MspCrd6Avail = MspCrd6Avail;
			this.MitCrdGuiAvail = MitCrdGuiAvail;
			this.MitCrdGuiActive = MitCrdGuiActive;
			this.MitCrdAuiAvail = MitCrdAuiAvail;
			this.MitCrdAuiActive = MitCrdAuiActive;
			this.MitCrdGjtAvail = MitCrdGjtAvail;
			this.MitCrdGjtActive = MitCrdGjtActive;
			this.MitCrdAjtAvail = MitCrdAjtAvail;
			this.MitCrdAjtActive = MitCrdAjtActive;
			this.MspCrd7Avail = MspCrd7Avail;
			this.MitCrdFnmAvail = MitCrdFnmAvail;
			this.MitCrdFnmActive = MitCrdFnmActive;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFDLGBSCUI, SCRJREFDLGCUSTJOB, SCRJREFDLGCUSTJTR, SCRJREFDLGCUSTUI, SCRJREFDLGDBSTR, SCRJREFDLGDEPLOY, SCRJREFDLGFINMOD, SCRJREFDLGGENJTR, SCRJREFDLGGENUI, SCRJREFDLGGLOBAL, SCRJREFDLGIMPEXP, SCRJREFDLGNEW, SCRJREFDLGOPPACK, SCRJREFDLGWRSTKIT, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDPCVAVAIL, MITCRDPCVACTIVE, MSPCRD3AVAIL, MITCRDIDPAVAIL, MITCRDIDPACTIVE, MITCRDIGBAVAIL, MITCRDIGBACTIVE, MSPCRD4AVAIL, MITCRDWSKAVAIL, MITCRDWSKACTIVE, MSPCRD5AVAIL, MITCRDIDBAVAIL, MITCRDIDBACTIVE, MITCRDIBUAVAIL, MITCRDIBUACTIVE, MITCRDIIEAVAIL, MITCRDIIEACTIVE, MITCRDIOPAVAIL, MITCRDIOPACTIVE, MITCRDICJAVAIL, MITCRDICJACTIVE, MSPCRD6AVAIL, MITCRDGUIAVAIL, MITCRDGUIACTIVE, MITCRDAUIAVAIL, MITCRDAUIACTIVE, MITCRDGJTAVAIL, MITCRDGJTACTIVE, MITCRDAJTAVAIL, MITCRDAJTACTIVE, MSPCRD7AVAIL, MITCRDFNMAVAIL, MITCRDFNMACTIVE));
		};

		public String scrJrefDlgbscui;
		public String scrJrefDlgcustjob;
		public String scrJrefDlgcustjtr;
		public String scrJrefDlgcustui;
		public String scrJrefDlgdbstr;
		public String scrJrefDlgdeploy;
		public String scrJrefDlgfinmod;
		public String scrJrefDlggenjtr;
		public String scrJrefDlggenui;
		public String scrJrefDlgglobal;
		public String scrJrefDlgimpexp;
		public String scrJrefDlgnew;
		public String scrJrefDlgoppack;
		public String scrJrefDlgwrstkit;
		public String scrJrefHeadbar;
		public String scrJrefList;
		public String scrJrefRec;
		public boolean MspCrd1Avail;
		public boolean MitCrdNewAvail;
		public boolean MitCrdPcvAvail;
		public boolean MitCrdPcvActive;
		public boolean MspCrd3Avail;
		public boolean MitCrdIdpAvail;
		public boolean MitCrdIdpActive;
		public boolean MitCrdIgbAvail;
		public boolean MitCrdIgbActive;
		public boolean MspCrd4Avail;
		public boolean MitCrdWskAvail;
		public boolean MitCrdWskActive;
		public boolean MspCrd5Avail;
		public boolean MitCrdIdbAvail;
		public boolean MitCrdIdbActive;
		public boolean MitCrdIbuAvail;
		public boolean MitCrdIbuActive;
		public boolean MitCrdIieAvail;
		public boolean MitCrdIieActive;
		public boolean MitCrdIopAvail;
		public boolean MitCrdIopActive;
		public boolean MitCrdIcjAvail;
		public boolean MitCrdIcjActive;
		public boolean MspCrd6Avail;
		public boolean MitCrdGuiAvail;
		public boolean MitCrdGuiActive;
		public boolean MitCrdAuiAvail;
		public boolean MitCrdAuiActive;
		public boolean MitCrdGjtAvail;
		public boolean MitCrdGjtActive;
		public boolean MitCrdAjtAvail;
		public boolean MitCrdAjtActive;
		public boolean MspCrd7Avail;
		public boolean MitCrdFnmAvail;
		public boolean MitCrdFnmActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmVer");

			String itemtag = "StatitemShrWznmVer";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefDlgbscui = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgbscui", mask, SCRJREFDLGBSCUI);
				scrJrefDlgcustjob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgcustjob", mask, SCRJREFDLGCUSTJOB);
				scrJrefDlgcustjtr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgcustjtr", mask, SCRJREFDLGCUSTJTR);
				scrJrefDlgcustui = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgcustui", mask, SCRJREFDLGCUSTUI);
				scrJrefDlgdbstr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgdbstr", mask, SCRJREFDLGDBSTR);
				scrJrefDlgdeploy = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgdeploy", mask, SCRJREFDLGDEPLOY);
				scrJrefDlgfinmod = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgfinmod", mask, SCRJREFDLGFINMOD);
				scrJrefDlggenjtr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlggenjtr", mask, SCRJREFDLGGENJTR);
				scrJrefDlggenui = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlggenui", mask, SCRJREFDLGGENUI);
				scrJrefDlgglobal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgglobal", mask, SCRJREFDLGGLOBAL);
				scrJrefDlgimpexp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgimpexp", mask, SCRJREFDLGIMPEXP);
				scrJrefDlgnew = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgnew", mask, SCRJREFDLGNEW);
				scrJrefDlgoppack = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgoppack", mask, SCRJREFDLGOPPACK);
				scrJrefDlgwrstkit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgwrstkit", mask, SCRJREFDLGWRSTKIT);
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);
				scrJrefList = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefList", mask, SCRJREFLIST);
				scrJrefRec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRec", mask, SCRJREFREC);
				MspCrd1Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", mask, MSPCRD1AVAIL);
				MitCrdNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdNewAvail", mask, MITCRDNEWAVAIL);
				MitCrdPcvAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPcvAvail", mask, MITCRDPCVAVAIL);
				MitCrdPcvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPcvActive", mask, MITCRDPCVACTIVE);
				MspCrd3Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd3Avail", mask, MSPCRD3AVAIL);
				MitCrdIdpAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIdpAvail", mask, MITCRDIDPAVAIL);
				MitCrdIdpActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIdpActive", mask, MITCRDIDPACTIVE);
				MitCrdIgbAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIgbAvail", mask, MITCRDIGBAVAIL);
				MitCrdIgbActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIgbActive", mask, MITCRDIGBACTIVE);
				MspCrd4Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd4Avail", mask, MSPCRD4AVAIL);
				MitCrdWskAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdWskAvail", mask, MITCRDWSKAVAIL);
				MitCrdWskActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdWskActive", mask, MITCRDWSKACTIVE);
				MspCrd5Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd5Avail", mask, MSPCRD5AVAIL);
				MitCrdIdbAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIdbAvail", mask, MITCRDIDBAVAIL);
				MitCrdIdbActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIdbActive", mask, MITCRDIDBACTIVE);
				MitCrdIbuAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIbuAvail", mask, MITCRDIBUAVAIL);
				MitCrdIbuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIbuActive", mask, MITCRDIBUACTIVE);
				MitCrdIieAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIieAvail", mask, MITCRDIIEAVAIL);
				MitCrdIieActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIieActive", mask, MITCRDIIEACTIVE);
				MitCrdIopAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIopAvail", mask, MITCRDIOPAVAIL);
				MitCrdIopActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIopActive", mask, MITCRDIOPACTIVE);
				MitCrdIcjAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIcjAvail", mask, MITCRDICJAVAIL);
				MitCrdIcjActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIcjActive", mask, MITCRDICJACTIVE);
				MspCrd6Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd6Avail", mask, MSPCRD6AVAIL);
				MitCrdGuiAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdGuiAvail", mask, MITCRDGUIAVAIL);
				MitCrdGuiActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdGuiActive", mask, MITCRDGUIACTIVE);
				MitCrdAuiAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdAuiAvail", mask, MITCRDAUIAVAIL);
				MitCrdAuiActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdAuiActive", mask, MITCRDAUIACTIVE);
				MitCrdGjtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdGjtAvail", mask, MITCRDGJTAVAIL);
				MitCrdGjtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdGjtActive", mask, MITCRDGJTACTIVE);
				MitCrdAjtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdAjtAvail", mask, MITCRDAJTAVAIL);
				MitCrdAjtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdAjtActive", mask, MITCRDAJTACTIVE);
				MspCrd7Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd7Avail", mask, MSPCRD7AVAIL);
				MitCrdFnmAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdFnmAvail", mask, MITCRDFNMAVAIL);
				MitCrdFnmActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdFnmActive", mask, MITCRDFNMACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefDlgbscui.equals(comp.scrJrefDlgbscui)) items.add(SCRJREFDLGBSCUI);
			if (scrJrefDlgcustjob.equals(comp.scrJrefDlgcustjob)) items.add(SCRJREFDLGCUSTJOB);
			if (scrJrefDlgcustjtr.equals(comp.scrJrefDlgcustjtr)) items.add(SCRJREFDLGCUSTJTR);
			if (scrJrefDlgcustui.equals(comp.scrJrefDlgcustui)) items.add(SCRJREFDLGCUSTUI);
			if (scrJrefDlgdbstr.equals(comp.scrJrefDlgdbstr)) items.add(SCRJREFDLGDBSTR);
			if (scrJrefDlgdeploy.equals(comp.scrJrefDlgdeploy)) items.add(SCRJREFDLGDEPLOY);
			if (scrJrefDlgfinmod.equals(comp.scrJrefDlgfinmod)) items.add(SCRJREFDLGFINMOD);
			if (scrJrefDlggenjtr.equals(comp.scrJrefDlggenjtr)) items.add(SCRJREFDLGGENJTR);
			if (scrJrefDlggenui.equals(comp.scrJrefDlggenui)) items.add(SCRJREFDLGGENUI);
			if (scrJrefDlgglobal.equals(comp.scrJrefDlgglobal)) items.add(SCRJREFDLGGLOBAL);
			if (scrJrefDlgimpexp.equals(comp.scrJrefDlgimpexp)) items.add(SCRJREFDLGIMPEXP);
			if (scrJrefDlgnew.equals(comp.scrJrefDlgnew)) items.add(SCRJREFDLGNEW);
			if (scrJrefDlgoppack.equals(comp.scrJrefDlgoppack)) items.add(SCRJREFDLGOPPACK);
			if (scrJrefDlgwrstkit.equals(comp.scrJrefDlgwrstkit)) items.add(SCRJREFDLGWRSTKIT);
			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);
			if (scrJrefList.equals(comp.scrJrefList)) items.add(SCRJREFLIST);
			if (scrJrefRec.equals(comp.scrJrefRec)) items.add(SCRJREFREC);
			if (MspCrd1Avail == comp.MspCrd1Avail) items.add(MSPCRD1AVAIL);
			if (MitCrdNewAvail == comp.MitCrdNewAvail) items.add(MITCRDNEWAVAIL);
			if (MitCrdPcvAvail == comp.MitCrdPcvAvail) items.add(MITCRDPCVAVAIL);
			if (MitCrdPcvActive == comp.MitCrdPcvActive) items.add(MITCRDPCVACTIVE);
			if (MspCrd3Avail == comp.MspCrd3Avail) items.add(MSPCRD3AVAIL);
			if (MitCrdIdpAvail == comp.MitCrdIdpAvail) items.add(MITCRDIDPAVAIL);
			if (MitCrdIdpActive == comp.MitCrdIdpActive) items.add(MITCRDIDPACTIVE);
			if (MitCrdIgbAvail == comp.MitCrdIgbAvail) items.add(MITCRDIGBAVAIL);
			if (MitCrdIgbActive == comp.MitCrdIgbActive) items.add(MITCRDIGBACTIVE);
			if (MspCrd4Avail == comp.MspCrd4Avail) items.add(MSPCRD4AVAIL);
			if (MitCrdWskAvail == comp.MitCrdWskAvail) items.add(MITCRDWSKAVAIL);
			if (MitCrdWskActive == comp.MitCrdWskActive) items.add(MITCRDWSKACTIVE);
			if (MspCrd5Avail == comp.MspCrd5Avail) items.add(MSPCRD5AVAIL);
			if (MitCrdIdbAvail == comp.MitCrdIdbAvail) items.add(MITCRDIDBAVAIL);
			if (MitCrdIdbActive == comp.MitCrdIdbActive) items.add(MITCRDIDBACTIVE);
			if (MitCrdIbuAvail == comp.MitCrdIbuAvail) items.add(MITCRDIBUAVAIL);
			if (MitCrdIbuActive == comp.MitCrdIbuActive) items.add(MITCRDIBUACTIVE);
			if (MitCrdIieAvail == comp.MitCrdIieAvail) items.add(MITCRDIIEAVAIL);
			if (MitCrdIieActive == comp.MitCrdIieActive) items.add(MITCRDIIEACTIVE);
			if (MitCrdIopAvail == comp.MitCrdIopAvail) items.add(MITCRDIOPAVAIL);
			if (MitCrdIopActive == comp.MitCrdIopActive) items.add(MITCRDIOPACTIVE);
			if (MitCrdIcjAvail == comp.MitCrdIcjAvail) items.add(MITCRDICJAVAIL);
			if (MitCrdIcjActive == comp.MitCrdIcjActive) items.add(MITCRDICJACTIVE);
			if (MspCrd6Avail == comp.MspCrd6Avail) items.add(MSPCRD6AVAIL);
			if (MitCrdGuiAvail == comp.MitCrdGuiAvail) items.add(MITCRDGUIAVAIL);
			if (MitCrdGuiActive == comp.MitCrdGuiActive) items.add(MITCRDGUIACTIVE);
			if (MitCrdAuiAvail == comp.MitCrdAuiAvail) items.add(MITCRDAUIAVAIL);
			if (MitCrdAuiActive == comp.MitCrdAuiActive) items.add(MITCRDAUIACTIVE);
			if (MitCrdGjtAvail == comp.MitCrdGjtAvail) items.add(MITCRDGJTAVAIL);
			if (MitCrdGjtActive == comp.MitCrdGjtActive) items.add(MITCRDGJTACTIVE);
			if (MitCrdAjtAvail == comp.MitCrdAjtAvail) items.add(MITCRDAJTAVAIL);
			if (MitCrdAjtActive == comp.MitCrdAjtActive) items.add(MITCRDAJTACTIVE);
			if (MspCrd7Avail == comp.MspCrd7Avail) items.add(MSPCRD7AVAIL);
			if (MitCrdFnmAvail == comp.MitCrdFnmAvail) items.add(MITCRDFNMAVAIL);
			if (MitCrdFnmActive == comp.MitCrdFnmActive) items.add(MITCRDFNMACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFDLGBSCUI, SCRJREFDLGCUSTJOB, SCRJREFDLGCUSTJTR, SCRJREFDLGCUSTUI, SCRJREFDLGDBSTR, SCRJREFDLGDEPLOY, SCRJREFDLGFINMOD, SCRJREFDLGGENJTR, SCRJREFDLGGENUI, SCRJREFDLGGLOBAL, SCRJREFDLGIMPEXP, SCRJREFDLGNEW, SCRJREFDLGOPPACK, SCRJREFDLGWRSTKIT, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDPCVAVAIL, MITCRDPCVACTIVE, MSPCRD3AVAIL, MITCRDIDPAVAIL, MITCRDIDPACTIVE, MITCRDIGBAVAIL, MITCRDIGBACTIVE, MSPCRD4AVAIL, MITCRDWSKAVAIL, MITCRDWSKACTIVE, MSPCRD5AVAIL, MITCRDIDBAVAIL, MITCRDIDBACTIVE, MITCRDIBUAVAIL, MITCRDIBUACTIVE, MITCRDIIEAVAIL, MITCRDIIEACTIVE, MITCRDIOPAVAIL, MITCRDIOPACTIVE, MITCRDICJAVAIL, MITCRDICJACTIVE, MSPCRD6AVAIL, MITCRDGUIAVAIL, MITCRDGUIACTIVE, MITCRDAUIAVAIL, MITCRDAUIACTIVE, MITCRDGJTAVAIL, MITCRDGJTACTIVE, MITCRDAJTAVAIL, MITCRDAJTACTIVE, MSPCRD7AVAIL, MITCRDFNMAVAIL, MITCRDFNMACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmVer)
	  */
	public class Tag extends Block {

		public static final int MITAPPABT = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MITCRDNEW = 3;
		public static final int MITCRDPCV = 4;
		public static final int MITCRDIDP = 5;
		public static final int MITCRDIGB = 6;
		public static final int MITCRDWSK = 7;
		public static final int MITCRDIDB = 8;
		public static final int MITCRDIBU = 9;
		public static final int MITCRDIIE = 10;
		public static final int MITCRDIOP = 11;
		public static final int MITCRDICJ = 12;
		public static final int MITCRDGUI = 13;
		public static final int MITCRDAUI = 14;
		public static final int MITCRDGJT = 15;
		public static final int MITCRDAJT = 16;
		public static final int MITCRDFNM = 17;

		public Tag(
					String MitAppAbt
					, String MrlAppHlp
					, String MitCrdNew
					, String MitCrdPcv
					, String MitCrdIdp
					, String MitCrdIgb
					, String MitCrdWsk
					, String MitCrdIdb
					, String MitCrdIbu
					, String MitCrdIie
					, String MitCrdIop
					, String MitCrdIcj
					, String MitCrdGui
					, String MitCrdAui
					, String MitCrdGjt
					, String MitCrdAjt
					, String MitCrdFnm
				) {
			this.MitAppAbt = MitAppAbt;
			this.MrlAppHlp = MrlAppHlp;
			this.MitCrdNew = MitCrdNew;
			this.MitCrdPcv = MitCrdPcv;
			this.MitCrdIdp = MitCrdIdp;
			this.MitCrdIgb = MitCrdIgb;
			this.MitCrdWsk = MitCrdWsk;
			this.MitCrdIdb = MitCrdIdb;
			this.MitCrdIbu = MitCrdIbu;
			this.MitCrdIie = MitCrdIie;
			this.MitCrdIop = MitCrdIop;
			this.MitCrdIcj = MitCrdIcj;
			this.MitCrdGui = MitCrdGui;
			this.MitCrdAui = MitCrdAui;
			this.MitCrdGjt = MitCrdGjt;
			this.MitCrdAjt = MitCrdAjt;
			this.MitCrdFnm = MitCrdFnm;

			mask = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDPCV, MITCRDIDP, MITCRDIGB, MITCRDWSK, MITCRDIDB, MITCRDIBU, MITCRDIIE, MITCRDIOP, MITCRDICJ, MITCRDGUI, MITCRDAUI, MITCRDGJT, MITCRDAJT, MITCRDFNM));
		};

		public String MitAppAbt;
		public String MrlAppHlp;
		public String MitCrdNew;
		public String MitCrdPcv;
		public String MitCrdIdp;
		public String MitCrdIgb;
		public String MitCrdWsk;
		public String MitCrdIdb;
		public String MitCrdIbu;
		public String MitCrdIie;
		public String MitCrdIop;
		public String MitCrdIcj;
		public String MitCrdGui;
		public String MitCrdAui;
		public String MitCrdGjt;
		public String MitCrdAjt;
		public String MitCrdFnm;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmVer");

			String itemtag = "TagitemWznmVer";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppAbt", mask, MITAPPABT);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MitCrdNew = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdNew", mask, MITCRDNEW);
				MitCrdPcv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdPcv", mask, MITCRDPCV);
				MitCrdIdp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIdp", mask, MITCRDIDP);
				MitCrdIgb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIgb", mask, MITCRDIGB);
				MitCrdWsk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdWsk", mask, MITCRDWSK);
				MitCrdIdb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIdb", mask, MITCRDIDB);
				MitCrdIbu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIbu", mask, MITCRDIBU);
				MitCrdIie = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIie", mask, MITCRDIIE);
				MitCrdIop = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIop", mask, MITCRDIOP);
				MitCrdIcj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIcj", mask, MITCRDICJ);
				MitCrdGui = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdGui", mask, MITCRDGUI);
				MitCrdAui = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdAui", mask, MITCRDAUI);
				MitCrdGjt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdGjt", mask, MITCRDGJT);
				MitCrdAjt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdAjt", mask, MITCRDAJT);
				MitCrdFnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdFnm", mask, MITCRDFNM);

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
			if (MitCrdNew.equals(comp.MitCrdNew)) items.add(MITCRDNEW);
			if (MitCrdPcv.equals(comp.MitCrdPcv)) items.add(MITCRDPCV);
			if (MitCrdIdp.equals(comp.MitCrdIdp)) items.add(MITCRDIDP);
			if (MitCrdIgb.equals(comp.MitCrdIgb)) items.add(MITCRDIGB);
			if (MitCrdWsk.equals(comp.MitCrdWsk)) items.add(MITCRDWSK);
			if (MitCrdIdb.equals(comp.MitCrdIdb)) items.add(MITCRDIDB);
			if (MitCrdIbu.equals(comp.MitCrdIbu)) items.add(MITCRDIBU);
			if (MitCrdIie.equals(comp.MitCrdIie)) items.add(MITCRDIIE);
			if (MitCrdIop.equals(comp.MitCrdIop)) items.add(MITCRDIOP);
			if (MitCrdIcj.equals(comp.MitCrdIcj)) items.add(MITCRDICJ);
			if (MitCrdGui.equals(comp.MitCrdGui)) items.add(MITCRDGUI);
			if (MitCrdAui.equals(comp.MitCrdAui)) items.add(MITCRDAUI);
			if (MitCrdGjt.equals(comp.MitCrdGjt)) items.add(MITCRDGJT);
			if (MitCrdAjt.equals(comp.MitCrdAjt)) items.add(MITCRDAJT);
			if (MitCrdFnm.equals(comp.MitCrdFnm)) items.add(MITCRDFNM);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDPCV, MITCRDIDP, MITCRDIGB, MITCRDWSK, MITCRDIDB, MITCRDIBU, MITCRDIIE, MITCRDIOP, MITCRDICJ, MITCRDGUI, MITCRDAUI, MITCRDGJT, MITCRDAJT, MITCRDFNM));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmVerDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMVERDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmVerDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmVerData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMVERDATA);

			continf = new ContInf(0, "", "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(0, 0, "", 0, false, false, false);
			statshr = new StatShr("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmVerData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf(0, "", "");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(0, 0, "", 0, false, false, false);
				statshr = new StatShr("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

