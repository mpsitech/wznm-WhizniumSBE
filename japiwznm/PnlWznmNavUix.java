/**
  * \file PnlWznmNavUix.java
  * Java API code for job PnlWznmNavUix
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmNavUix {
	/**
		* VecVDo (full: VecVWznmNavUixDo)
		*/
	public static class VecVDo {

		public static final int BUTPSTVIEWCLICK = 1;
		public static final int BUTPSTNEWCRDCLICK = 2;
		public static final int BUTMDLVIEWCLICK = 3;
		public static final int BUTMDLNEWCRDCLICK = 4;
		public static final int BUTCARVIEWCLICK = 5;
		public static final int BUTCARNEWCRDCLICK = 6;
		public static final int BUTDLGVIEWCLICK = 7;
		public static final int BUTDLGNEWCRDCLICK = 8;
		public static final int BUTPNLVIEWCLICK = 9;
		public static final int BUTPNLNEWCRDCLICK = 10;
		public static final int BUTQRYVIEWCLICK = 11;
		public static final int BUTQRYNEWCRDCLICK = 12;
		public static final int BUTQCOVIEWCLICK = 13;
		public static final int BUTQCONEWCRDCLICK = 14;
		public static final int BUTQMDVIEWCLICK = 15;
		public static final int BUTQMDNEWCRDCLICK = 16;
		public static final int BUTCONVIEWCLICK = 17;
		public static final int BUTCONNEWCRDCLICK = 18;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butpstviewclick")) return BUTPSTVIEWCLICK;
			if (s.equals("butpstnewcrdclick")) return BUTPSTNEWCRDCLICK;
			if (s.equals("butmdlviewclick")) return BUTMDLVIEWCLICK;
			if (s.equals("butmdlnewcrdclick")) return BUTMDLNEWCRDCLICK;
			if (s.equals("butcarviewclick")) return BUTCARVIEWCLICK;
			if (s.equals("butcarnewcrdclick")) return BUTCARNEWCRDCLICK;
			if (s.equals("butdlgviewclick")) return BUTDLGVIEWCLICK;
			if (s.equals("butdlgnewcrdclick")) return BUTDLGNEWCRDCLICK;
			if (s.equals("butpnlviewclick")) return BUTPNLVIEWCLICK;
			if (s.equals("butpnlnewcrdclick")) return BUTPNLNEWCRDCLICK;
			if (s.equals("butqryviewclick")) return BUTQRYVIEWCLICK;
			if (s.equals("butqrynewcrdclick")) return BUTQRYNEWCRDCLICK;
			if (s.equals("butqcoviewclick")) return BUTQCOVIEWCLICK;
			if (s.equals("butqconewcrdclick")) return BUTQCONEWCRDCLICK;
			if (s.equals("butqmdviewclick")) return BUTQMDVIEWCLICK;
			if (s.equals("butqmdnewcrdclick")) return BUTQMDNEWCRDCLICK;
			if (s.equals("butconviewclick")) return BUTCONVIEWCLICK;
			if (s.equals("butconnewcrdclick")) return BUTCONNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTPSTVIEWCLICK) return("ButPstViewClick");
			if (ix == BUTPSTNEWCRDCLICK) return("ButPstNewcrdClick");
			if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
			if (ix == BUTMDLNEWCRDCLICK) return("ButMdlNewcrdClick");
			if (ix == BUTCARVIEWCLICK) return("ButCarViewClick");
			if (ix == BUTCARNEWCRDCLICK) return("ButCarNewcrdClick");
			if (ix == BUTDLGVIEWCLICK) return("ButDlgViewClick");
			if (ix == BUTDLGNEWCRDCLICK) return("ButDlgNewcrdClick");
			if (ix == BUTPNLVIEWCLICK) return("ButPnlViewClick");
			if (ix == BUTPNLNEWCRDCLICK) return("ButPnlNewcrdClick");
			if (ix == BUTQRYVIEWCLICK) return("ButQryViewClick");
			if (ix == BUTQRYNEWCRDCLICK) return("ButQryNewcrdClick");
			if (ix == BUTQCOVIEWCLICK) return("ButQcoViewClick");
			if (ix == BUTQCONEWCRDCLICK) return("ButQcoNewcrdClick");
			if (ix == BUTQMDVIEWCLICK) return("ButQmdViewClick");
			if (ix == BUTQMDNEWCRDCLICK) return("ButQmdNewcrdClick");
			if (ix == BUTCONVIEWCLICK) return("ButConViewClick");
			if (ix == BUTCONNEWCRDCLICK) return("ButConNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmNavUix)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTPST = 1;
		public static final int NUMFLSTMDL = 2;
		public static final int NUMFLSTCAR = 3;
		public static final int NUMFLSTDLG = 4;
		public static final int NUMFLSTPNL = 5;
		public static final int NUMFLSTQRY = 6;
		public static final int NUMFLSTQCO = 7;
		public static final int NUMFLSTQMD = 8;
		public static final int NUMFLSTCON = 9;

		public ContIac(
					int numFLstPst
					, int numFLstMdl
					, int numFLstCar
					, int numFLstDlg
					, int numFLstPnl
					, int numFLstQry
					, int numFLstQco
					, int numFLstQmd
					, int numFLstCon
				) {
			this.numFLstPst = numFLstPst;
			this.numFLstMdl = numFLstMdl;
			this.numFLstCar = numFLstCar;
			this.numFLstDlg = numFLstDlg;
			this.numFLstPnl = numFLstPnl;
			this.numFLstQry = numFLstQry;
			this.numFLstQco = numFLstQco;
			this.numFLstQmd = numFLstQmd;
			this.numFLstCon = numFLstCon;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTPST, NUMFLSTMDL, NUMFLSTCAR, NUMFLSTDLG, NUMFLSTPNL, NUMFLSTQRY, NUMFLSTQCO, NUMFLSTQMD, NUMFLSTCON));
		};

		public int numFLstPst;
		public int numFLstMdl;
		public int numFLstCar;
		public int numFLstDlg;
		public int numFLstPnl;
		public int numFLstQry;
		public int numFLstQco;
		public int numFLstQmd;
		public int numFLstCon;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmNavUix");

			String itemtag = "ContitemIacWznmNavUix";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstPst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPst", mask, NUMFLSTPST);
				numFLstMdl = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstMdl", mask, NUMFLSTMDL);
				numFLstCar = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstCar", mask, NUMFLSTCAR);
				numFLstDlg = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstDlg", mask, NUMFLSTDLG);
				numFLstPnl = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPnl", mask, NUMFLSTPNL);
				numFLstQry = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstQry", mask, NUMFLSTQRY);
				numFLstQco = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstQco", mask, NUMFLSTQCO);
				numFLstQmd = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstQmd", mask, NUMFLSTQMD);
				numFLstCon = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstCon", mask, NUMFLSTCON);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmNavUix";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmNavUix";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPst", numFLstPst);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstMdl", numFLstMdl);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstCar", numFLstCar);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstDlg", numFLstDlg);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPnl", numFLstPnl);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstQry", numFLstQry);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstQco", numFLstQco);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstQmd", numFLstQmd);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstCon", numFLstCon);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstPst == comp.numFLstPst) items.add(NUMFLSTPST);
			if (numFLstMdl == comp.numFLstMdl) items.add(NUMFLSTMDL);
			if (numFLstCar == comp.numFLstCar) items.add(NUMFLSTCAR);
			if (numFLstDlg == comp.numFLstDlg) items.add(NUMFLSTDLG);
			if (numFLstPnl == comp.numFLstPnl) items.add(NUMFLSTPNL);
			if (numFLstQry == comp.numFLstQry) items.add(NUMFLSTQRY);
			if (numFLstQco == comp.numFLstQco) items.add(NUMFLSTQCO);
			if (numFLstQmd == comp.numFLstQmd) items.add(NUMFLSTQMD);
			if (numFLstCon == comp.numFLstCon) items.add(NUMFLSTCON);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTPST, NUMFLSTMDL, NUMFLSTCAR, NUMFLSTDLG, NUMFLSTPNL, NUMFLSTQRY, NUMFLSTQCO, NUMFLSTQMD, NUMFLSTCON));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmNavUix)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTPSTALT = 2;
		public static final int LSTMDLALT = 3;
		public static final int LSTCARALT = 4;
		public static final int LSTDLGALT = 5;
		public static final int LSTPNLALT = 6;
		public static final int LSTQRYALT = 7;
		public static final int LSTQCOALT = 8;
		public static final int LSTQMDALT = 9;
		public static final int LSTCONALT = 10;
		public static final int LSTPSTNUMFIRSTDISP = 11;
		public static final int LSTMDLNUMFIRSTDISP = 12;
		public static final int LSTCARNUMFIRSTDISP = 13;
		public static final int LSTDLGNUMFIRSTDISP = 14;
		public static final int LSTPNLNUMFIRSTDISP = 15;
		public static final int LSTQRYNUMFIRSTDISP = 16;
		public static final int LSTQCONUMFIRSTDISP = 17;
		public static final int LSTQMDNUMFIRSTDISP = 18;
		public static final int LSTCONNUMFIRSTDISP = 19;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstPstAlt
					, boolean LstMdlAlt
					, boolean LstCarAlt
					, boolean LstDlgAlt
					, boolean LstPnlAlt
					, boolean LstQryAlt
					, boolean LstQcoAlt
					, boolean LstQmdAlt
					, boolean LstConAlt
					, int LstPstNumFirstdisp
					, int LstMdlNumFirstdisp
					, int LstCarNumFirstdisp
					, int LstDlgNumFirstdisp
					, int LstPnlNumFirstdisp
					, int LstQryNumFirstdisp
					, int LstQcoNumFirstdisp
					, int LstQmdNumFirstdisp
					, int LstConNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstPstAlt = LstPstAlt;
			this.LstMdlAlt = LstMdlAlt;
			this.LstCarAlt = LstCarAlt;
			this.LstDlgAlt = LstDlgAlt;
			this.LstPnlAlt = LstPnlAlt;
			this.LstQryAlt = LstQryAlt;
			this.LstQcoAlt = LstQcoAlt;
			this.LstQmdAlt = LstQmdAlt;
			this.LstConAlt = LstConAlt;
			this.LstPstNumFirstdisp = LstPstNumFirstdisp;
			this.LstMdlNumFirstdisp = LstMdlNumFirstdisp;
			this.LstCarNumFirstdisp = LstCarNumFirstdisp;
			this.LstDlgNumFirstdisp = LstDlgNumFirstdisp;
			this.LstPnlNumFirstdisp = LstPnlNumFirstdisp;
			this.LstQryNumFirstdisp = LstQryNumFirstdisp;
			this.LstQcoNumFirstdisp = LstQcoNumFirstdisp;
			this.LstQmdNumFirstdisp = LstQmdNumFirstdisp;
			this.LstConNumFirstdisp = LstConNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTPSTALT, LSTMDLALT, LSTCARALT, LSTDLGALT, LSTPNLALT, LSTQRYALT, LSTQCOALT, LSTQMDALT, LSTCONALT, LSTPSTNUMFIRSTDISP, LSTMDLNUMFIRSTDISP, LSTCARNUMFIRSTDISP, LSTDLGNUMFIRSTDISP, LSTPNLNUMFIRSTDISP, LSTQRYNUMFIRSTDISP, LSTQCONUMFIRSTDISP, LSTQMDNUMFIRSTDISP, LSTCONNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstPstAlt;
		public boolean LstMdlAlt;
		public boolean LstCarAlt;
		public boolean LstDlgAlt;
		public boolean LstPnlAlt;
		public boolean LstQryAlt;
		public boolean LstQcoAlt;
		public boolean LstQmdAlt;
		public boolean LstConAlt;
		public int LstPstNumFirstdisp;
		public int LstMdlNumFirstdisp;
		public int LstCarNumFirstdisp;
		public int LstDlgNumFirstdisp;
		public int LstPnlNumFirstdisp;
		public int LstQryNumFirstdisp;
		public int LstQcoNumFirstdisp;
		public int LstQmdNumFirstdisp;
		public int LstConNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmNavUix");

			String itemtag = "StatitemAppWznmNavUix";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstPstAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPstAlt", mask, LSTPSTALT);
				LstMdlAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMdlAlt", mask, LSTMDLALT);
				LstCarAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCarAlt", mask, LSTCARALT);
				LstDlgAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDlgAlt", mask, LSTDLGALT);
				LstPnlAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPnlAlt", mask, LSTPNLALT);
				LstQryAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstQryAlt", mask, LSTQRYALT);
				LstQcoAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstQcoAlt", mask, LSTQCOALT);
				LstQmdAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstQmdAlt", mask, LSTQMDALT);
				LstConAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstConAlt", mask, LSTCONALT);
				LstPstNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPstNumFirstdisp", mask, LSTPSTNUMFIRSTDISP);
				LstMdlNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMdlNumFirstdisp", mask, LSTMDLNUMFIRSTDISP);
				LstCarNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCarNumFirstdisp", mask, LSTCARNUMFIRSTDISP);
				LstDlgNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDlgNumFirstdisp", mask, LSTDLGNUMFIRSTDISP);
				LstPnlNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPnlNumFirstdisp", mask, LSTPNLNUMFIRSTDISP);
				LstQryNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstQryNumFirstdisp", mask, LSTQRYNUMFIRSTDISP);
				LstQcoNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstQcoNumFirstdisp", mask, LSTQCONUMFIRSTDISP);
				LstQmdNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstQmdNumFirstdisp", mask, LSTQMDNUMFIRSTDISP);
				LstConNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstConNumFirstdisp", mask, LSTCONNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstPstAlt == comp.LstPstAlt) items.add(LSTPSTALT);
			if (LstMdlAlt == comp.LstMdlAlt) items.add(LSTMDLALT);
			if (LstCarAlt == comp.LstCarAlt) items.add(LSTCARALT);
			if (LstDlgAlt == comp.LstDlgAlt) items.add(LSTDLGALT);
			if (LstPnlAlt == comp.LstPnlAlt) items.add(LSTPNLALT);
			if (LstQryAlt == comp.LstQryAlt) items.add(LSTQRYALT);
			if (LstQcoAlt == comp.LstQcoAlt) items.add(LSTQCOALT);
			if (LstQmdAlt == comp.LstQmdAlt) items.add(LSTQMDALT);
			if (LstConAlt == comp.LstConAlt) items.add(LSTCONALT);
			if (LstPstNumFirstdisp == comp.LstPstNumFirstdisp) items.add(LSTPSTNUMFIRSTDISP);
			if (LstMdlNumFirstdisp == comp.LstMdlNumFirstdisp) items.add(LSTMDLNUMFIRSTDISP);
			if (LstCarNumFirstdisp == comp.LstCarNumFirstdisp) items.add(LSTCARNUMFIRSTDISP);
			if (LstDlgNumFirstdisp == comp.LstDlgNumFirstdisp) items.add(LSTDLGNUMFIRSTDISP);
			if (LstPnlNumFirstdisp == comp.LstPnlNumFirstdisp) items.add(LSTPNLNUMFIRSTDISP);
			if (LstQryNumFirstdisp == comp.LstQryNumFirstdisp) items.add(LSTQRYNUMFIRSTDISP);
			if (LstQcoNumFirstdisp == comp.LstQcoNumFirstdisp) items.add(LSTQCONUMFIRSTDISP);
			if (LstQmdNumFirstdisp == comp.LstQmdNumFirstdisp) items.add(LSTQMDNUMFIRSTDISP);
			if (LstConNumFirstdisp == comp.LstConNumFirstdisp) items.add(LSTCONNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTPSTALT, LSTMDLALT, LSTCARALT, LSTDLGALT, LSTPNLALT, LSTQRYALT, LSTQCOALT, LSTQMDALT, LSTCONALT, LSTPSTNUMFIRSTDISP, LSTMDLNUMFIRSTDISP, LSTCARNUMFIRSTDISP, LSTDLGNUMFIRSTDISP, LSTPNLNUMFIRSTDISP, LSTQRYNUMFIRSTDISP, LSTQCONUMFIRSTDISP, LSTQMDNUMFIRSTDISP, LSTCONNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmNavUix)
	  */
	public class StatShr extends Block {

		public static final int LSTPSTAVAIL = 1;
		public static final int BUTPSTVIEWACTIVE = 2;
		public static final int BUTPSTNEWCRDACTIVE = 3;
		public static final int LSTMDLAVAIL = 4;
		public static final int BUTMDLVIEWACTIVE = 5;
		public static final int BUTMDLNEWCRDACTIVE = 6;
		public static final int LSTCARAVAIL = 7;
		public static final int BUTCARVIEWACTIVE = 8;
		public static final int BUTCARNEWCRDACTIVE = 9;
		public static final int LSTDLGAVAIL = 10;
		public static final int BUTDLGVIEWACTIVE = 11;
		public static final int BUTDLGNEWCRDACTIVE = 12;
		public static final int LSTPNLAVAIL = 13;
		public static final int BUTPNLVIEWACTIVE = 14;
		public static final int BUTPNLNEWCRDACTIVE = 15;
		public static final int LSTQRYAVAIL = 16;
		public static final int BUTQRYVIEWACTIVE = 17;
		public static final int BUTQRYNEWCRDACTIVE = 18;
		public static final int LSTQCOAVAIL = 19;
		public static final int BUTQCOVIEWACTIVE = 20;
		public static final int BUTQCONEWCRDACTIVE = 21;
		public static final int LSTQMDAVAIL = 22;
		public static final int BUTQMDVIEWACTIVE = 23;
		public static final int BUTQMDNEWCRDACTIVE = 24;
		public static final int LSTCONAVAIL = 25;
		public static final int BUTCONVIEWACTIVE = 26;
		public static final int BUTCONNEWCRDACTIVE = 27;

		public StatShr(
					boolean LstPstAvail
					, boolean ButPstViewActive
					, boolean ButPstNewcrdActive
					, boolean LstMdlAvail
					, boolean ButMdlViewActive
					, boolean ButMdlNewcrdActive
					, boolean LstCarAvail
					, boolean ButCarViewActive
					, boolean ButCarNewcrdActive
					, boolean LstDlgAvail
					, boolean ButDlgViewActive
					, boolean ButDlgNewcrdActive
					, boolean LstPnlAvail
					, boolean ButPnlViewActive
					, boolean ButPnlNewcrdActive
					, boolean LstQryAvail
					, boolean ButQryViewActive
					, boolean ButQryNewcrdActive
					, boolean LstQcoAvail
					, boolean ButQcoViewActive
					, boolean ButQcoNewcrdActive
					, boolean LstQmdAvail
					, boolean ButQmdViewActive
					, boolean ButQmdNewcrdActive
					, boolean LstConAvail
					, boolean ButConViewActive
					, boolean ButConNewcrdActive
				) {
			this.LstPstAvail = LstPstAvail;
			this.ButPstViewActive = ButPstViewActive;
			this.ButPstNewcrdActive = ButPstNewcrdActive;
			this.LstMdlAvail = LstMdlAvail;
			this.ButMdlViewActive = ButMdlViewActive;
			this.ButMdlNewcrdActive = ButMdlNewcrdActive;
			this.LstCarAvail = LstCarAvail;
			this.ButCarViewActive = ButCarViewActive;
			this.ButCarNewcrdActive = ButCarNewcrdActive;
			this.LstDlgAvail = LstDlgAvail;
			this.ButDlgViewActive = ButDlgViewActive;
			this.ButDlgNewcrdActive = ButDlgNewcrdActive;
			this.LstPnlAvail = LstPnlAvail;
			this.ButPnlViewActive = ButPnlViewActive;
			this.ButPnlNewcrdActive = ButPnlNewcrdActive;
			this.LstQryAvail = LstQryAvail;
			this.ButQryViewActive = ButQryViewActive;
			this.ButQryNewcrdActive = ButQryNewcrdActive;
			this.LstQcoAvail = LstQcoAvail;
			this.ButQcoViewActive = ButQcoViewActive;
			this.ButQcoNewcrdActive = ButQcoNewcrdActive;
			this.LstQmdAvail = LstQmdAvail;
			this.ButQmdViewActive = ButQmdViewActive;
			this.ButQmdNewcrdActive = ButQmdNewcrdActive;
			this.LstConAvail = LstConAvail;
			this.ButConViewActive = ButConViewActive;
			this.ButConNewcrdActive = ButConNewcrdActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTPSTAVAIL, BUTPSTVIEWACTIVE, BUTPSTNEWCRDACTIVE, LSTMDLAVAIL, BUTMDLVIEWACTIVE, BUTMDLNEWCRDACTIVE, LSTCARAVAIL, BUTCARVIEWACTIVE, BUTCARNEWCRDACTIVE, LSTDLGAVAIL, BUTDLGVIEWACTIVE, BUTDLGNEWCRDACTIVE, LSTPNLAVAIL, BUTPNLVIEWACTIVE, BUTPNLNEWCRDACTIVE, LSTQRYAVAIL, BUTQRYVIEWACTIVE, BUTQRYNEWCRDACTIVE, LSTQCOAVAIL, BUTQCOVIEWACTIVE, BUTQCONEWCRDACTIVE, LSTQMDAVAIL, BUTQMDVIEWACTIVE, BUTQMDNEWCRDACTIVE, LSTCONAVAIL, BUTCONVIEWACTIVE, BUTCONNEWCRDACTIVE));
		};

		public boolean LstPstAvail;
		public boolean ButPstViewActive;
		public boolean ButPstNewcrdActive;
		public boolean LstMdlAvail;
		public boolean ButMdlViewActive;
		public boolean ButMdlNewcrdActive;
		public boolean LstCarAvail;
		public boolean ButCarViewActive;
		public boolean ButCarNewcrdActive;
		public boolean LstDlgAvail;
		public boolean ButDlgViewActive;
		public boolean ButDlgNewcrdActive;
		public boolean LstPnlAvail;
		public boolean ButPnlViewActive;
		public boolean ButPnlNewcrdActive;
		public boolean LstQryAvail;
		public boolean ButQryViewActive;
		public boolean ButQryNewcrdActive;
		public boolean LstQcoAvail;
		public boolean ButQcoViewActive;
		public boolean ButQcoNewcrdActive;
		public boolean LstQmdAvail;
		public boolean ButQmdViewActive;
		public boolean ButQmdNewcrdActive;
		public boolean LstConAvail;
		public boolean ButConViewActive;
		public boolean ButConNewcrdActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmNavUix");

			String itemtag = "StatitemShrWznmNavUix";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstPstAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPstAvail", mask, LSTPSTAVAIL);
				ButPstViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPstViewActive", mask, BUTPSTVIEWACTIVE);
				ButPstNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPstNewcrdActive", mask, BUTPSTNEWCRDACTIVE);
				LstMdlAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMdlAvail", mask, LSTMDLAVAIL);
				ButMdlViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlViewActive", mask, BUTMDLVIEWACTIVE);
				ButMdlNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlNewcrdActive", mask, BUTMDLNEWCRDACTIVE);
				LstCarAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCarAvail", mask, LSTCARAVAIL);
				ButCarViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCarViewActive", mask, BUTCARVIEWACTIVE);
				ButCarNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCarNewcrdActive", mask, BUTCARNEWCRDACTIVE);
				LstDlgAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDlgAvail", mask, LSTDLGAVAIL);
				ButDlgViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDlgViewActive", mask, BUTDLGVIEWACTIVE);
				ButDlgNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDlgNewcrdActive", mask, BUTDLGNEWCRDACTIVE);
				LstPnlAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPnlAvail", mask, LSTPNLAVAIL);
				ButPnlViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPnlViewActive", mask, BUTPNLVIEWACTIVE);
				ButPnlNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPnlNewcrdActive", mask, BUTPNLNEWCRDACTIVE);
				LstQryAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstQryAvail", mask, LSTQRYAVAIL);
				ButQryViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButQryViewActive", mask, BUTQRYVIEWACTIVE);
				ButQryNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButQryNewcrdActive", mask, BUTQRYNEWCRDACTIVE);
				LstQcoAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstQcoAvail", mask, LSTQCOAVAIL);
				ButQcoViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButQcoViewActive", mask, BUTQCOVIEWACTIVE);
				ButQcoNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButQcoNewcrdActive", mask, BUTQCONEWCRDACTIVE);
				LstQmdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstQmdAvail", mask, LSTQMDAVAIL);
				ButQmdViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButQmdViewActive", mask, BUTQMDVIEWACTIVE);
				ButQmdNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButQmdNewcrdActive", mask, BUTQMDNEWCRDACTIVE);
				LstConAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstConAvail", mask, LSTCONAVAIL);
				ButConViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButConViewActive", mask, BUTCONVIEWACTIVE);
				ButConNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButConNewcrdActive", mask, BUTCONNEWCRDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstPstAvail == comp.LstPstAvail) items.add(LSTPSTAVAIL);
			if (ButPstViewActive == comp.ButPstViewActive) items.add(BUTPSTVIEWACTIVE);
			if (ButPstNewcrdActive == comp.ButPstNewcrdActive) items.add(BUTPSTNEWCRDACTIVE);
			if (LstMdlAvail == comp.LstMdlAvail) items.add(LSTMDLAVAIL);
			if (ButMdlViewActive == comp.ButMdlViewActive) items.add(BUTMDLVIEWACTIVE);
			if (ButMdlNewcrdActive == comp.ButMdlNewcrdActive) items.add(BUTMDLNEWCRDACTIVE);
			if (LstCarAvail == comp.LstCarAvail) items.add(LSTCARAVAIL);
			if (ButCarViewActive == comp.ButCarViewActive) items.add(BUTCARVIEWACTIVE);
			if (ButCarNewcrdActive == comp.ButCarNewcrdActive) items.add(BUTCARNEWCRDACTIVE);
			if (LstDlgAvail == comp.LstDlgAvail) items.add(LSTDLGAVAIL);
			if (ButDlgViewActive == comp.ButDlgViewActive) items.add(BUTDLGVIEWACTIVE);
			if (ButDlgNewcrdActive == comp.ButDlgNewcrdActive) items.add(BUTDLGNEWCRDACTIVE);
			if (LstPnlAvail == comp.LstPnlAvail) items.add(LSTPNLAVAIL);
			if (ButPnlViewActive == comp.ButPnlViewActive) items.add(BUTPNLVIEWACTIVE);
			if (ButPnlNewcrdActive == comp.ButPnlNewcrdActive) items.add(BUTPNLNEWCRDACTIVE);
			if (LstQryAvail == comp.LstQryAvail) items.add(LSTQRYAVAIL);
			if (ButQryViewActive == comp.ButQryViewActive) items.add(BUTQRYVIEWACTIVE);
			if (ButQryNewcrdActive == comp.ButQryNewcrdActive) items.add(BUTQRYNEWCRDACTIVE);
			if (LstQcoAvail == comp.LstQcoAvail) items.add(LSTQCOAVAIL);
			if (ButQcoViewActive == comp.ButQcoViewActive) items.add(BUTQCOVIEWACTIVE);
			if (ButQcoNewcrdActive == comp.ButQcoNewcrdActive) items.add(BUTQCONEWCRDACTIVE);
			if (LstQmdAvail == comp.LstQmdAvail) items.add(LSTQMDAVAIL);
			if (ButQmdViewActive == comp.ButQmdViewActive) items.add(BUTQMDVIEWACTIVE);
			if (ButQmdNewcrdActive == comp.ButQmdNewcrdActive) items.add(BUTQMDNEWCRDACTIVE);
			if (LstConAvail == comp.LstConAvail) items.add(LSTCONAVAIL);
			if (ButConViewActive == comp.ButConViewActive) items.add(BUTCONVIEWACTIVE);
			if (ButConNewcrdActive == comp.ButConNewcrdActive) items.add(BUTCONNEWCRDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTPSTAVAIL, BUTPSTVIEWACTIVE, BUTPSTNEWCRDACTIVE, LSTMDLAVAIL, BUTMDLVIEWACTIVE, BUTMDLNEWCRDACTIVE, LSTCARAVAIL, BUTCARVIEWACTIVE, BUTCARNEWCRDACTIVE, LSTDLGAVAIL, BUTDLGVIEWACTIVE, BUTDLGNEWCRDACTIVE, LSTPNLAVAIL, BUTPNLVIEWACTIVE, BUTPNLNEWCRDACTIVE, LSTQRYAVAIL, BUTQRYVIEWACTIVE, BUTQRYNEWCRDACTIVE, LSTQCOAVAIL, BUTQCOVIEWACTIVE, BUTQCONEWCRDACTIVE, LSTQMDAVAIL, BUTQMDVIEWACTIVE, BUTQMDNEWCRDACTIVE, LSTCONAVAIL, BUTCONVIEWACTIVE, BUTCONNEWCRDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmNavUix)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTPST = 2;
		public static final int CPTMDL = 3;
		public static final int CPTCAR = 4;
		public static final int CPTDLG = 5;
		public static final int CPTPNL = 6;
		public static final int CPTQRY = 7;
		public static final int CPTQCO = 8;
		public static final int CPTQMD = 9;
		public static final int CPTCON = 10;

		public Tag(
					String Cpt
					, String CptPst
					, String CptMdl
					, String CptCar
					, String CptDlg
					, String CptPnl
					, String CptQry
					, String CptQco
					, String CptQmd
					, String CptCon
				) {
			this.Cpt = Cpt;
			this.CptPst = CptPst;
			this.CptMdl = CptMdl;
			this.CptCar = CptCar;
			this.CptDlg = CptDlg;
			this.CptPnl = CptPnl;
			this.CptQry = CptQry;
			this.CptQco = CptQco;
			this.CptQmd = CptQmd;
			this.CptCon = CptCon;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTPST, CPTMDL, CPTCAR, CPTDLG, CPTPNL, CPTQRY, CPTQCO, CPTQMD, CPTCON));
		};

		public String Cpt;
		public String CptPst;
		public String CptMdl;
		public String CptCar;
		public String CptDlg;
		public String CptPnl;
		public String CptQry;
		public String CptQco;
		public String CptQmd;
		public String CptCon;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmNavUix");

			String itemtag = "TagitemWznmNavUix";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptPst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPst", mask, CPTPST);
				CptMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMdl", mask, CPTMDL);
				CptCar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCar", mask, CPTCAR);
				CptDlg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDlg", mask, CPTDLG);
				CptPnl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPnl", mask, CPTPNL);
				CptQry = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptQry", mask, CPTQRY);
				CptQco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptQco", mask, CPTQCO);
				CptQmd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptQmd", mask, CPTQMD);
				CptCon = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCon", mask, CPTCON);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptPst.equals(comp.CptPst)) items.add(CPTPST);
			if (CptMdl.equals(comp.CptMdl)) items.add(CPTMDL);
			if (CptCar.equals(comp.CptCar)) items.add(CPTCAR);
			if (CptDlg.equals(comp.CptDlg)) items.add(CPTDLG);
			if (CptPnl.equals(comp.CptPnl)) items.add(CPTPNL);
			if (CptQry.equals(comp.CptQry)) items.add(CPTQRY);
			if (CptQco.equals(comp.CptQco)) items.add(CPTQCO);
			if (CptQmd.equals(comp.CptQmd)) items.add(CPTQMD);
			if (CptCon.equals(comp.CptCon)) items.add(CPTCON);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTPST, CPTMDL, CPTCAR, CPTDLG, CPTPNL, CPTQRY, CPTQCO, CPTQMD, CPTCON));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmNavUixData)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVUIXDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavUixData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmNavUixDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVUIXDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavUixDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmNavUixData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTCAR = 3;
		public static final int FEEDFLSTCON = 4;
		public static final int FEEDFLSTDLG = 5;
		public static final int FEEDFLSTMDL = 6;
		public static final int FEEDFLSTPNL = 7;
		public static final int FEEDFLSTPST = 8;
		public static final int FEEDFLSTQCO = 9;
		public static final int FEEDFLSTQMD = 10;
		public static final int FEEDFLSTQRY = 11;
		public static final int STATAPP = 12;
		public static final int STATSHR = 13;
		public static final int TAG = 14;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMNAVUIXDATA);

			contiac = new ContIac(0, 0, 0, 0, 0, 0, 0, 0, 0);
			feedFLstCar = new Feed("FeedFLstCar");
			feedFLstCon = new Feed("FeedFLstCon");
			feedFLstDlg = new Feed("FeedFLstDlg");
			feedFLstMdl = new Feed("FeedFLstMdl");
			feedFLstPnl = new Feed("FeedFLstPnl");
			feedFLstPst = new Feed("FeedFLstPst");
			feedFLstQco = new Feed("FeedFLstQco");
			feedFLstQmd = new Feed("FeedFLstQmd");
			feedFLstQry = new Feed("FeedFLstQry");
			statapp = new StatApp(0, false, false, false, false, false, false, false, false, false, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstCar;
		public Feed feedFLstCon;
		public Feed feedFLstDlg;
		public Feed feedFLstMdl;
		public Feed feedFLstPnl;
		public Feed feedFLstPst;
		public Feed feedFLstQco;
		public Feed feedFLstQmd;
		public Feed feedFLstQry;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTCAR)) ss.add("feedFLstCar");
			if (has(FEEDFLSTCON)) ss.add("feedFLstCon");
			if (has(FEEDFLSTDLG)) ss.add("feedFLstDlg");
			if (has(FEEDFLSTMDL)) ss.add("feedFLstMdl");
			if (has(FEEDFLSTPNL)) ss.add("feedFLstPnl");
			if (has(FEEDFLSTPST)) ss.add("feedFLstPst");
			if (has(FEEDFLSTQCO)) ss.add("feedFLstQco");
			if (has(FEEDFLSTQMD)) ss.add("feedFLstQmd");
			if (has(FEEDFLSTQRY)) ss.add("feedFLstQry");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmNavUixData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstCar.readXML(doc, basexpath, true)) add(FEEDFLSTCAR);
				if (feedFLstCon.readXML(doc, basexpath, true)) add(FEEDFLSTCON);
				if (feedFLstDlg.readXML(doc, basexpath, true)) add(FEEDFLSTDLG);
				if (feedFLstMdl.readXML(doc, basexpath, true)) add(FEEDFLSTMDL);
				if (feedFLstPnl.readXML(doc, basexpath, true)) add(FEEDFLSTPNL);
				if (feedFLstPst.readXML(doc, basexpath, true)) add(FEEDFLSTPST);
				if (feedFLstQco.readXML(doc, basexpath, true)) add(FEEDFLSTQCO);
				if (feedFLstQmd.readXML(doc, basexpath, true)) add(FEEDFLSTQMD);
				if (feedFLstQry.readXML(doc, basexpath, true)) add(FEEDFLSTQRY);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0, 0, 0, 0, 0, 0);
				feedFLstCar = new Feed("FeedFLstCar");
				feedFLstCon = new Feed("FeedFLstCon");
				feedFLstDlg = new Feed("FeedFLstDlg");
				feedFLstMdl = new Feed("FeedFLstMdl");
				feedFLstPnl = new Feed("FeedFLstPnl");
				feedFLstPst = new Feed("FeedFLstPst");
				feedFLstQco = new Feed("FeedFLstQco");
				feedFLstQmd = new Feed("FeedFLstQmd");
				feedFLstQry = new Feed("FeedFLstQry");
				statapp = new StatApp(0, false, false, false, false, false, false, false, false, false, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

