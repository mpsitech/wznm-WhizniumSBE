/**
  * \file PnlWznmNavProject.java
  * Java API code for job PnlWznmNavProject
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmNavProject {
	/**
		* VecVDo (full: VecVWznmNavProjectDo)
		*/
	public static class VecVDo {

		public static final int BUTPRJVIEWCLICK = 1;
		public static final int BUTPRJNEWCRDCLICK = 2;
		public static final int BUTVERVIEWCLICK = 3;
		public static final int BUTVERNEWCRDCLICK = 4;
		public static final int BUTCAPVIEWCLICK = 5;
		public static final int BUTCAPNEWCRDCLICK = 6;
		public static final int BUTERRVIEWCLICK = 7;
		public static final int BUTERRNEWCRDCLICK = 8;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butprjviewclick")) return BUTPRJVIEWCLICK;
			if (s.equals("butprjnewcrdclick")) return BUTPRJNEWCRDCLICK;
			if (s.equals("butverviewclick")) return BUTVERVIEWCLICK;
			if (s.equals("butvernewcrdclick")) return BUTVERNEWCRDCLICK;
			if (s.equals("butcapviewclick")) return BUTCAPVIEWCLICK;
			if (s.equals("butcapnewcrdclick")) return BUTCAPNEWCRDCLICK;
			if (s.equals("buterrviewclick")) return BUTERRVIEWCLICK;
			if (s.equals("buterrnewcrdclick")) return BUTERRNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
			if (ix == BUTPRJNEWCRDCLICK) return("ButPrjNewcrdClick");
			if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
			if (ix == BUTVERNEWCRDCLICK) return("ButVerNewcrdClick");
			if (ix == BUTCAPVIEWCLICK) return("ButCapViewClick");
			if (ix == BUTCAPNEWCRDCLICK) return("ButCapNewcrdClick");
			if (ix == BUTERRVIEWCLICK) return("ButErrViewClick");
			if (ix == BUTERRNEWCRDCLICK) return("ButErrNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmNavProject)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTPRJ = 1;
		public static final int NUMFLSTVER = 2;
		public static final int NUMFLSTCAP = 3;
		public static final int NUMFLSTERR = 4;

		public ContIac(
					int numFLstPrj
					, int numFLstVer
					, int numFLstCap
					, int numFLstErr
				) {
			this.numFLstPrj = numFLstPrj;
			this.numFLstVer = numFLstVer;
			this.numFLstCap = numFLstCap;
			this.numFLstErr = numFLstErr;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTPRJ, NUMFLSTVER, NUMFLSTCAP, NUMFLSTERR));
		};

		public int numFLstPrj;
		public int numFLstVer;
		public int numFLstCap;
		public int numFLstErr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmNavProject");

			String itemtag = "ContitemIacWznmNavProject";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstPrj = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPrj", mask, NUMFLSTPRJ);
				numFLstVer = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstVer", mask, NUMFLSTVER);
				numFLstCap = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstCap", mask, NUMFLSTCAP);
				numFLstErr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstErr", mask, NUMFLSTERR);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmNavProject";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmNavProject";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPrj", numFLstPrj);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstVer", numFLstVer);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstCap", numFLstCap);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstErr", numFLstErr);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstPrj == comp.numFLstPrj) items.add(NUMFLSTPRJ);
			if (numFLstVer == comp.numFLstVer) items.add(NUMFLSTVER);
			if (numFLstCap == comp.numFLstCap) items.add(NUMFLSTCAP);
			if (numFLstErr == comp.numFLstErr) items.add(NUMFLSTERR);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTPRJ, NUMFLSTVER, NUMFLSTCAP, NUMFLSTERR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmNavProject)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTPRJALT = 2;
		public static final int LSTVERALT = 3;
		public static final int LSTCAPALT = 4;
		public static final int LSTERRALT = 5;
		public static final int LSTPRJNUMFIRSTDISP = 6;
		public static final int LSTVERNUMFIRSTDISP = 7;
		public static final int LSTCAPNUMFIRSTDISP = 8;
		public static final int LSTERRNUMFIRSTDISP = 9;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstPrjAlt
					, boolean LstVerAlt
					, boolean LstCapAlt
					, boolean LstErrAlt
					, int LstPrjNumFirstdisp
					, int LstVerNumFirstdisp
					, int LstCapNumFirstdisp
					, int LstErrNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstPrjAlt = LstPrjAlt;
			this.LstVerAlt = LstVerAlt;
			this.LstCapAlt = LstCapAlt;
			this.LstErrAlt = LstErrAlt;
			this.LstPrjNumFirstdisp = LstPrjNumFirstdisp;
			this.LstVerNumFirstdisp = LstVerNumFirstdisp;
			this.LstCapNumFirstdisp = LstCapNumFirstdisp;
			this.LstErrNumFirstdisp = LstErrNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTPRJALT, LSTVERALT, LSTCAPALT, LSTERRALT, LSTPRJNUMFIRSTDISP, LSTVERNUMFIRSTDISP, LSTCAPNUMFIRSTDISP, LSTERRNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstPrjAlt;
		public boolean LstVerAlt;
		public boolean LstCapAlt;
		public boolean LstErrAlt;
		public int LstPrjNumFirstdisp;
		public int LstVerNumFirstdisp;
		public int LstCapNumFirstdisp;
		public int LstErrNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmNavProject");

			String itemtag = "StatitemAppWznmNavProject";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstPrjAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrjAlt", mask, LSTPRJALT);
				LstVerAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVerAlt", mask, LSTVERALT);
				LstCapAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCapAlt", mask, LSTCAPALT);
				LstErrAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstErrAlt", mask, LSTERRALT);
				LstPrjNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrjNumFirstdisp", mask, LSTPRJNUMFIRSTDISP);
				LstVerNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVerNumFirstdisp", mask, LSTVERNUMFIRSTDISP);
				LstCapNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCapNumFirstdisp", mask, LSTCAPNUMFIRSTDISP);
				LstErrNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstErrNumFirstdisp", mask, LSTERRNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstPrjAlt == comp.LstPrjAlt) items.add(LSTPRJALT);
			if (LstVerAlt == comp.LstVerAlt) items.add(LSTVERALT);
			if (LstCapAlt == comp.LstCapAlt) items.add(LSTCAPALT);
			if (LstErrAlt == comp.LstErrAlt) items.add(LSTERRALT);
			if (LstPrjNumFirstdisp == comp.LstPrjNumFirstdisp) items.add(LSTPRJNUMFIRSTDISP);
			if (LstVerNumFirstdisp == comp.LstVerNumFirstdisp) items.add(LSTVERNUMFIRSTDISP);
			if (LstCapNumFirstdisp == comp.LstCapNumFirstdisp) items.add(LSTCAPNUMFIRSTDISP);
			if (LstErrNumFirstdisp == comp.LstErrNumFirstdisp) items.add(LSTERRNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTPRJALT, LSTVERALT, LSTCAPALT, LSTERRALT, LSTPRJNUMFIRSTDISP, LSTVERNUMFIRSTDISP, LSTCAPNUMFIRSTDISP, LSTERRNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmNavProject)
	  */
	public class StatShr extends Block {

		public static final int LSTPRJAVAIL = 1;
		public static final int BUTPRJVIEWACTIVE = 2;
		public static final int LSTVERAVAIL = 3;
		public static final int BUTVERVIEWACTIVE = 4;
		public static final int LSTCAPAVAIL = 5;
		public static final int BUTCAPVIEWACTIVE = 6;
		public static final int BUTCAPNEWCRDACTIVE = 7;
		public static final int LSTERRAVAIL = 8;
		public static final int BUTERRVIEWACTIVE = 9;
		public static final int BUTERRNEWCRDACTIVE = 10;

		public StatShr(
					boolean LstPrjAvail
					, boolean ButPrjViewActive
					, boolean LstVerAvail
					, boolean ButVerViewActive
					, boolean LstCapAvail
					, boolean ButCapViewActive
					, boolean ButCapNewcrdActive
					, boolean LstErrAvail
					, boolean ButErrViewActive
					, boolean ButErrNewcrdActive
				) {
			this.LstPrjAvail = LstPrjAvail;
			this.ButPrjViewActive = ButPrjViewActive;
			this.LstVerAvail = LstVerAvail;
			this.ButVerViewActive = ButVerViewActive;
			this.LstCapAvail = LstCapAvail;
			this.ButCapViewActive = ButCapViewActive;
			this.ButCapNewcrdActive = ButCapNewcrdActive;
			this.LstErrAvail = LstErrAvail;
			this.ButErrViewActive = ButErrViewActive;
			this.ButErrNewcrdActive = ButErrNewcrdActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTCAPAVAIL, BUTCAPVIEWACTIVE, BUTCAPNEWCRDACTIVE, LSTERRAVAIL, BUTERRVIEWACTIVE, BUTERRNEWCRDACTIVE));
		};

		public boolean LstPrjAvail;
		public boolean ButPrjViewActive;
		public boolean LstVerAvail;
		public boolean ButVerViewActive;
		public boolean LstCapAvail;
		public boolean ButCapViewActive;
		public boolean ButCapNewcrdActive;
		public boolean LstErrAvail;
		public boolean ButErrViewActive;
		public boolean ButErrNewcrdActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmNavProject");

			String itemtag = "StatitemShrWznmNavProject";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstPrjAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrjAvail", mask, LSTPRJAVAIL);
				ButPrjViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrjViewActive", mask, BUTPRJVIEWACTIVE);
				LstVerAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVerAvail", mask, LSTVERAVAIL);
				ButVerViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewActive", mask, BUTVERVIEWACTIVE);
				LstCapAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCapAvail", mask, LSTCAPAVAIL);
				ButCapViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCapViewActive", mask, BUTCAPVIEWACTIVE);
				ButCapNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCapNewcrdActive", mask, BUTCAPNEWCRDACTIVE);
				LstErrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstErrAvail", mask, LSTERRAVAIL);
				ButErrViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButErrViewActive", mask, BUTERRVIEWACTIVE);
				ButErrNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButErrNewcrdActive", mask, BUTERRNEWCRDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstPrjAvail == comp.LstPrjAvail) items.add(LSTPRJAVAIL);
			if (ButPrjViewActive == comp.ButPrjViewActive) items.add(BUTPRJVIEWACTIVE);
			if (LstVerAvail == comp.LstVerAvail) items.add(LSTVERAVAIL);
			if (ButVerViewActive == comp.ButVerViewActive) items.add(BUTVERVIEWACTIVE);
			if (LstCapAvail == comp.LstCapAvail) items.add(LSTCAPAVAIL);
			if (ButCapViewActive == comp.ButCapViewActive) items.add(BUTCAPVIEWACTIVE);
			if (ButCapNewcrdActive == comp.ButCapNewcrdActive) items.add(BUTCAPNEWCRDACTIVE);
			if (LstErrAvail == comp.LstErrAvail) items.add(LSTERRAVAIL);
			if (ButErrViewActive == comp.ButErrViewActive) items.add(BUTERRVIEWACTIVE);
			if (ButErrNewcrdActive == comp.ButErrNewcrdActive) items.add(BUTERRNEWCRDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTCAPAVAIL, BUTCAPVIEWACTIVE, BUTCAPNEWCRDACTIVE, LSTERRAVAIL, BUTERRVIEWACTIVE, BUTERRNEWCRDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmNavProject)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTPRJ = 2;
		public static final int CPTVER = 3;
		public static final int CPTCAP = 4;
		public static final int CPTERR = 5;

		public Tag(
					String Cpt
					, String CptPrj
					, String CptVer
					, String CptCap
					, String CptErr
				) {
			this.Cpt = Cpt;
			this.CptPrj = CptPrj;
			this.CptVer = CptVer;
			this.CptCap = CptCap;
			this.CptErr = CptErr;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTPRJ, CPTVER, CPTCAP, CPTERR));
		};

		public String Cpt;
		public String CptPrj;
		public String CptVer;
		public String CptCap;
		public String CptErr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmNavProject");

			String itemtag = "TagitemWznmNavProject";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptPrj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrj", mask, CPTPRJ);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptCap = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCap", mask, CPTCAP);
				CptErr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptErr", mask, CPTERR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptPrj.equals(comp.CptPrj)) items.add(CPTPRJ);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);
			if (CptCap.equals(comp.CptCap)) items.add(CPTCAP);
			if (CptErr.equals(comp.CptErr)) items.add(CPTERR);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTPRJ, CPTVER, CPTCAP, CPTERR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmNavProjectData)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVPROJECTDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavProjectData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmNavProjectDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVPROJECTDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavProjectDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmNavProjectData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTCAP = 3;
		public static final int FEEDFLSTERR = 4;
		public static final int FEEDFLSTPRJ = 5;
		public static final int FEEDFLSTVER = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMNAVPROJECTDATA);

			contiac = new ContIac(0, 0, 0, 0);
			feedFLstCap = new Feed("FeedFLstCap");
			feedFLstErr = new Feed("FeedFLstErr");
			feedFLstPrj = new Feed("FeedFLstPrj");
			feedFLstVer = new Feed("FeedFLstVer");
			statapp = new StatApp(0, false, false, false, false, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstCap;
		public Feed feedFLstErr;
		public Feed feedFLstPrj;
		public Feed feedFLstVer;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTCAP)) ss.add("feedFLstCap");
			if (has(FEEDFLSTERR)) ss.add("feedFLstErr");
			if (has(FEEDFLSTPRJ)) ss.add("feedFLstPrj");
			if (has(FEEDFLSTVER)) ss.add("feedFLstVer");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmNavProjectData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstCap.readXML(doc, basexpath, true)) add(FEEDFLSTCAP);
				if (feedFLstErr.readXML(doc, basexpath, true)) add(FEEDFLSTERR);
				if (feedFLstPrj.readXML(doc, basexpath, true)) add(FEEDFLSTPRJ);
				if (feedFLstVer.readXML(doc, basexpath, true)) add(FEEDFLSTVER);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0);
				feedFLstCap = new Feed("FeedFLstCap");
				feedFLstErr = new Feed("FeedFLstErr");
				feedFLstPrj = new Feed("FeedFLstPrj");
				feedFLstVer = new Feed("FeedFLstVer");
				statapp = new StatApp(0, false, false, false, false, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};

