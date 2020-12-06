/**
  * \file PnlWznmNavGlobal.java
  * Java API code for job PnlWznmNavGlobal
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmNavGlobal {
	/**
		* VecVDo (full: VecVWznmNavGlobalDo)
		*/
	public static class VecVDo {

		public static final int BUTLOCVIEWCLICK = 1;
		public static final int BUTLOCNEWCRDCLICK = 2;
		public static final int BUTTAGVIEWCLICK = 3;
		public static final int BUTTAGNEWCRDCLICK = 4;
		public static final int BUTCTPVIEWCLICK = 5;
		public static final int BUTCTPNEWCRDCLICK = 6;
		public static final int BUTMCHVIEWCLICK = 7;
		public static final int BUTMCHNEWCRDCLICK = 8;
		public static final int BUTLIBVIEWCLICK = 9;
		public static final int BUTLIBNEWCRDCLICK = 10;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butlocviewclick")) return BUTLOCVIEWCLICK;
			if (s.equals("butlocnewcrdclick")) return BUTLOCNEWCRDCLICK;
			if (s.equals("buttagviewclick")) return BUTTAGVIEWCLICK;
			if (s.equals("buttagnewcrdclick")) return BUTTAGNEWCRDCLICK;
			if (s.equals("butctpviewclick")) return BUTCTPVIEWCLICK;
			if (s.equals("butctpnewcrdclick")) return BUTCTPNEWCRDCLICK;
			if (s.equals("butmchviewclick")) return BUTMCHVIEWCLICK;
			if (s.equals("butmchnewcrdclick")) return BUTMCHNEWCRDCLICK;
			if (s.equals("butlibviewclick")) return BUTLIBVIEWCLICK;
			if (s.equals("butlibnewcrdclick")) return BUTLIBNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTLOCVIEWCLICK) return("ButLocViewClick");
			if (ix == BUTLOCNEWCRDCLICK) return("ButLocNewcrdClick");
			if (ix == BUTTAGVIEWCLICK) return("ButTagViewClick");
			if (ix == BUTTAGNEWCRDCLICK) return("ButTagNewcrdClick");
			if (ix == BUTCTPVIEWCLICK) return("ButCtpViewClick");
			if (ix == BUTCTPNEWCRDCLICK) return("ButCtpNewcrdClick");
			if (ix == BUTMCHVIEWCLICK) return("ButMchViewClick");
			if (ix == BUTMCHNEWCRDCLICK) return("ButMchNewcrdClick");
			if (ix == BUTLIBVIEWCLICK) return("ButLibViewClick");
			if (ix == BUTLIBNEWCRDCLICK) return("ButLibNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmNavGlobal)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTLOC = 1;
		public static final int NUMFLSTTAG = 2;
		public static final int NUMFLSTCTP = 3;
		public static final int NUMFLSTMCH = 4;
		public static final int NUMFLSTLIB = 5;

		public ContIac(
					int numFLstLoc
					, int numFLstTag
					, int numFLstCtp
					, int numFLstMch
					, int numFLstLib
				) {
			this.numFLstLoc = numFLstLoc;
			this.numFLstTag = numFLstTag;
			this.numFLstCtp = numFLstCtp;
			this.numFLstMch = numFLstMch;
			this.numFLstLib = numFLstLib;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTLOC, NUMFLSTTAG, NUMFLSTCTP, NUMFLSTMCH, NUMFLSTLIB));
		};

		public int numFLstLoc;
		public int numFLstTag;
		public int numFLstCtp;
		public int numFLstMch;
		public int numFLstLib;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmNavGlobal");

			String itemtag = "ContitemIacWznmNavGlobal";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstLoc = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstLoc", mask, NUMFLSTLOC);
				numFLstTag = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstTag", mask, NUMFLSTTAG);
				numFLstCtp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstCtp", mask, NUMFLSTCTP);
				numFLstMch = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstMch", mask, NUMFLSTMCH);
				numFLstLib = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstLib", mask, NUMFLSTLIB);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmNavGlobal";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmNavGlobal";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstLoc", numFLstLoc);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstTag", numFLstTag);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstCtp", numFLstCtp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstMch", numFLstMch);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstLib", numFLstLib);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstLoc == comp.numFLstLoc) items.add(NUMFLSTLOC);
			if (numFLstTag == comp.numFLstTag) items.add(NUMFLSTTAG);
			if (numFLstCtp == comp.numFLstCtp) items.add(NUMFLSTCTP);
			if (numFLstMch == comp.numFLstMch) items.add(NUMFLSTMCH);
			if (numFLstLib == comp.numFLstLib) items.add(NUMFLSTLIB);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTLOC, NUMFLSTTAG, NUMFLSTCTP, NUMFLSTMCH, NUMFLSTLIB));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmNavGlobal)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTLOCALT = 2;
		public static final int LSTTAGALT = 3;
		public static final int LSTCTPALT = 4;
		public static final int LSTMCHALT = 5;
		public static final int LSTLIBALT = 6;
		public static final int LSTLOCNUMFIRSTDISP = 7;
		public static final int LSTTAGNUMFIRSTDISP = 8;
		public static final int LSTCTPNUMFIRSTDISP = 9;
		public static final int LSTMCHNUMFIRSTDISP = 10;
		public static final int LSTLIBNUMFIRSTDISP = 11;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstLocAlt
					, boolean LstTagAlt
					, boolean LstCtpAlt
					, boolean LstMchAlt
					, boolean LstLibAlt
					, int LstLocNumFirstdisp
					, int LstTagNumFirstdisp
					, int LstCtpNumFirstdisp
					, int LstMchNumFirstdisp
					, int LstLibNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstLocAlt = LstLocAlt;
			this.LstTagAlt = LstTagAlt;
			this.LstCtpAlt = LstCtpAlt;
			this.LstMchAlt = LstMchAlt;
			this.LstLibAlt = LstLibAlt;
			this.LstLocNumFirstdisp = LstLocNumFirstdisp;
			this.LstTagNumFirstdisp = LstTagNumFirstdisp;
			this.LstCtpNumFirstdisp = LstCtpNumFirstdisp;
			this.LstMchNumFirstdisp = LstMchNumFirstdisp;
			this.LstLibNumFirstdisp = LstLibNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTLOCALT, LSTTAGALT, LSTCTPALT, LSTMCHALT, LSTLIBALT, LSTLOCNUMFIRSTDISP, LSTTAGNUMFIRSTDISP, LSTCTPNUMFIRSTDISP, LSTMCHNUMFIRSTDISP, LSTLIBNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstLocAlt;
		public boolean LstTagAlt;
		public boolean LstCtpAlt;
		public boolean LstMchAlt;
		public boolean LstLibAlt;
		public int LstLocNumFirstdisp;
		public int LstTagNumFirstdisp;
		public int LstCtpNumFirstdisp;
		public int LstMchNumFirstdisp;
		public int LstLibNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmNavGlobal");

			String itemtag = "StatitemAppWznmNavGlobal";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstLocAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstLocAlt", mask, LSTLOCALT);
				LstTagAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTagAlt", mask, LSTTAGALT);
				LstCtpAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCtpAlt", mask, LSTCTPALT);
				LstMchAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMchAlt", mask, LSTMCHALT);
				LstLibAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstLibAlt", mask, LSTLIBALT);
				LstLocNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstLocNumFirstdisp", mask, LSTLOCNUMFIRSTDISP);
				LstTagNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTagNumFirstdisp", mask, LSTTAGNUMFIRSTDISP);
				LstCtpNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCtpNumFirstdisp", mask, LSTCTPNUMFIRSTDISP);
				LstMchNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMchNumFirstdisp", mask, LSTMCHNUMFIRSTDISP);
				LstLibNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstLibNumFirstdisp", mask, LSTLIBNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstLocAlt == comp.LstLocAlt) items.add(LSTLOCALT);
			if (LstTagAlt == comp.LstTagAlt) items.add(LSTTAGALT);
			if (LstCtpAlt == comp.LstCtpAlt) items.add(LSTCTPALT);
			if (LstMchAlt == comp.LstMchAlt) items.add(LSTMCHALT);
			if (LstLibAlt == comp.LstLibAlt) items.add(LSTLIBALT);
			if (LstLocNumFirstdisp == comp.LstLocNumFirstdisp) items.add(LSTLOCNUMFIRSTDISP);
			if (LstTagNumFirstdisp == comp.LstTagNumFirstdisp) items.add(LSTTAGNUMFIRSTDISP);
			if (LstCtpNumFirstdisp == comp.LstCtpNumFirstdisp) items.add(LSTCTPNUMFIRSTDISP);
			if (LstMchNumFirstdisp == comp.LstMchNumFirstdisp) items.add(LSTMCHNUMFIRSTDISP);
			if (LstLibNumFirstdisp == comp.LstLibNumFirstdisp) items.add(LSTLIBNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTLOCALT, LSTTAGALT, LSTCTPALT, LSTMCHALT, LSTLIBALT, LSTLOCNUMFIRSTDISP, LSTTAGNUMFIRSTDISP, LSTCTPNUMFIRSTDISP, LSTMCHNUMFIRSTDISP, LSTLIBNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmNavGlobal)
	  */
	public class StatShr extends Block {

		public static final int LSTLOCAVAIL = 1;
		public static final int BUTLOCVIEWACTIVE = 2;
		public static final int LSTTAGAVAIL = 3;
		public static final int BUTTAGVIEWACTIVE = 4;
		public static final int LSTCTPAVAIL = 5;
		public static final int BUTCTPVIEWACTIVE = 6;
		public static final int LSTMCHAVAIL = 7;
		public static final int BUTMCHVIEWACTIVE = 8;
		public static final int LSTLIBAVAIL = 9;
		public static final int BUTLIBVIEWACTIVE = 10;

		public StatShr(
					boolean LstLocAvail
					, boolean ButLocViewActive
					, boolean LstTagAvail
					, boolean ButTagViewActive
					, boolean LstCtpAvail
					, boolean ButCtpViewActive
					, boolean LstMchAvail
					, boolean ButMchViewActive
					, boolean LstLibAvail
					, boolean ButLibViewActive
				) {
			this.LstLocAvail = LstLocAvail;
			this.ButLocViewActive = ButLocViewActive;
			this.LstTagAvail = LstTagAvail;
			this.ButTagViewActive = ButTagViewActive;
			this.LstCtpAvail = LstCtpAvail;
			this.ButCtpViewActive = ButCtpViewActive;
			this.LstMchAvail = LstMchAvail;
			this.ButMchViewActive = ButMchViewActive;
			this.LstLibAvail = LstLibAvail;
			this.ButLibViewActive = ButLibViewActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTLOCAVAIL, BUTLOCVIEWACTIVE, LSTTAGAVAIL, BUTTAGVIEWACTIVE, LSTCTPAVAIL, BUTCTPVIEWACTIVE, LSTMCHAVAIL, BUTMCHVIEWACTIVE, LSTLIBAVAIL, BUTLIBVIEWACTIVE));
		};

		public boolean LstLocAvail;
		public boolean ButLocViewActive;
		public boolean LstTagAvail;
		public boolean ButTagViewActive;
		public boolean LstCtpAvail;
		public boolean ButCtpViewActive;
		public boolean LstMchAvail;
		public boolean ButMchViewActive;
		public boolean LstLibAvail;
		public boolean ButLibViewActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmNavGlobal");

			String itemtag = "StatitemShrWznmNavGlobal";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstLocAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstLocAvail", mask, LSTLOCAVAIL);
				ButLocViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButLocViewActive", mask, BUTLOCVIEWACTIVE);
				LstTagAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTagAvail", mask, LSTTAGAVAIL);
				ButTagViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTagViewActive", mask, BUTTAGVIEWACTIVE);
				LstCtpAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCtpAvail", mask, LSTCTPAVAIL);
				ButCtpViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCtpViewActive", mask, BUTCTPVIEWACTIVE);
				LstMchAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMchAvail", mask, LSTMCHAVAIL);
				ButMchViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMchViewActive", mask, BUTMCHVIEWACTIVE);
				LstLibAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstLibAvail", mask, LSTLIBAVAIL);
				ButLibViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButLibViewActive", mask, BUTLIBVIEWACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstLocAvail == comp.LstLocAvail) items.add(LSTLOCAVAIL);
			if (ButLocViewActive == comp.ButLocViewActive) items.add(BUTLOCVIEWACTIVE);
			if (LstTagAvail == comp.LstTagAvail) items.add(LSTTAGAVAIL);
			if (ButTagViewActive == comp.ButTagViewActive) items.add(BUTTAGVIEWACTIVE);
			if (LstCtpAvail == comp.LstCtpAvail) items.add(LSTCTPAVAIL);
			if (ButCtpViewActive == comp.ButCtpViewActive) items.add(BUTCTPVIEWACTIVE);
			if (LstMchAvail == comp.LstMchAvail) items.add(LSTMCHAVAIL);
			if (ButMchViewActive == comp.ButMchViewActive) items.add(BUTMCHVIEWACTIVE);
			if (LstLibAvail == comp.LstLibAvail) items.add(LSTLIBAVAIL);
			if (ButLibViewActive == comp.ButLibViewActive) items.add(BUTLIBVIEWACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTLOCAVAIL, BUTLOCVIEWACTIVE, LSTTAGAVAIL, BUTTAGVIEWACTIVE, LSTCTPAVAIL, BUTCTPVIEWACTIVE, LSTMCHAVAIL, BUTMCHVIEWACTIVE, LSTLIBAVAIL, BUTLIBVIEWACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmNavGlobal)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTLOC = 2;
		public static final int CPTTAG = 3;
		public static final int CPTCTP = 4;
		public static final int CPTMCH = 5;
		public static final int CPTLIB = 6;

		public Tag(
					String Cpt
					, String CptLoc
					, String CptTag
					, String CptCtp
					, String CptMch
					, String CptLib
				) {
			this.Cpt = Cpt;
			this.CptLoc = CptLoc;
			this.CptTag = CptTag;
			this.CptCtp = CptCtp;
			this.CptMch = CptMch;
			this.CptLib = CptLib;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTLOC, CPTTAG, CPTCTP, CPTMCH, CPTLIB));
		};

		public String Cpt;
		public String CptLoc;
		public String CptTag;
		public String CptCtp;
		public String CptMch;
		public String CptLib;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmNavGlobal");

			String itemtag = "TagitemWznmNavGlobal";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptLoc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLoc", mask, CPTLOC);
				CptTag = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTag", mask, CPTTAG);
				CptCtp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCtp", mask, CPTCTP);
				CptMch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMch", mask, CPTMCH);
				CptLib = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLib", mask, CPTLIB);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptLoc.equals(comp.CptLoc)) items.add(CPTLOC);
			if (CptTag.equals(comp.CptTag)) items.add(CPTTAG);
			if (CptCtp.equals(comp.CptCtp)) items.add(CPTCTP);
			if (CptMch.equals(comp.CptMch)) items.add(CPTMCH);
			if (CptLib.equals(comp.CptLib)) items.add(CPTLIB);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTLOC, CPTTAG, CPTCTP, CPTMCH, CPTLIB));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmNavGlobalData)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVGLOBALDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavGlobalData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmNavGlobalDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVGLOBALDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavGlobalDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmNavGlobalData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTCTP = 3;
		public static final int FEEDFLSTLIB = 4;
		public static final int FEEDFLSTLOC = 5;
		public static final int FEEDFLSTMCH = 6;
		public static final int FEEDFLSTTAG = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMNAVGLOBALDATA);

			contiac = new ContIac(0, 0, 0, 0, 0);
			feedFLstCtp = new Feed("FeedFLstCtp");
			feedFLstLib = new Feed("FeedFLstLib");
			feedFLstLoc = new Feed("FeedFLstLoc");
			feedFLstMch = new Feed("FeedFLstMch");
			feedFLstTag = new Feed("FeedFLstTag");
			statapp = new StatApp(0, false, false, false, false, false, 0, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstCtp;
		public Feed feedFLstLib;
		public Feed feedFLstLoc;
		public Feed feedFLstMch;
		public Feed feedFLstTag;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTCTP)) ss.add("feedFLstCtp");
			if (has(FEEDFLSTLIB)) ss.add("feedFLstLib");
			if (has(FEEDFLSTLOC)) ss.add("feedFLstLoc");
			if (has(FEEDFLSTMCH)) ss.add("feedFLstMch");
			if (has(FEEDFLSTTAG)) ss.add("feedFLstTag");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmNavGlobalData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstCtp.readXML(doc, basexpath, true)) add(FEEDFLSTCTP);
				if (feedFLstLib.readXML(doc, basexpath, true)) add(FEEDFLSTLIB);
				if (feedFLstLoc.readXML(doc, basexpath, true)) add(FEEDFLSTLOC);
				if (feedFLstMch.readXML(doc, basexpath, true)) add(FEEDFLSTMCH);
				if (feedFLstTag.readXML(doc, basexpath, true)) add(FEEDFLSTTAG);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0, 0);
				feedFLstCtp = new Feed("FeedFLstCtp");
				feedFLstLib = new Feed("FeedFLstLib");
				feedFLstLoc = new Feed("FeedFLstLoc");
				feedFLstMch = new Feed("FeedFLstMch");
				feedFLstTag = new Feed("FeedFLstTag");
				statapp = new StatApp(0, false, false, false, false, false, 0, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};
