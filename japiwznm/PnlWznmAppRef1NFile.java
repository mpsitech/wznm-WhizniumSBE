/**
  * \file PnlWznmAppRef1NFile.java
  * Java API code for job PnlWznmAppRef1NFile
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmAppRef1NFile {
	/**
		* VecVDo (full: VecVWznmAppRef1NFileDo)
		*/
	public static class VecVDo {

		public static final int BUTVIEWCLICK = 1;
		public static final int BUTNEWCLICK = 2;
		public static final int BUTDELETECLICK = 3;
		public static final int BUTREFRESHCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butviewclick")) return BUTVIEWCLICK;
			if (s.equals("butnewclick")) return BUTNEWCLICK;
			if (s.equals("butdeleteclick")) return BUTDELETECLICK;
			if (s.equals("butrefreshclick")) return BUTREFRESHCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTVIEWCLICK) return("ButViewClick");
			if (ix == BUTNEWCLICK) return("ButNewClick");
			if (ix == BUTDELETECLICK) return("ButDeleteClick");
			if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWznmAppRef1NFile)
	  */
	public class ContInf extends Block {

		public static final int NUMFCSIQST = 1;

		public ContInf(
					int numFCsiQst
				) {
			this.numFCsiQst = numFCsiQst;

			mask = new HashSet<Integer>(Arrays.asList(NUMFCSIQST));
		};

		public int numFCsiQst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmAppRef1NFile");

			String itemtag = "ContitemInfWznmAppRef1NFile";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFCsiQst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFCsiQst", mask, NUMFCSIQST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFCsiQst == comp.numFCsiQst) items.add(NUMFCSIQST);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFCSIQST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmAppRef1NFile)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmAppRef1NFile");

			String itemtag = "StatitemAppWznmAppRef1NFile";

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
	  * StatShr (full: StatShrWznmAppRef1NFile)
	  */
	public class StatShr extends Block {

		public static final int BUTVIEWAVAIL = 1;
		public static final int BUTVIEWACTIVE = 2;
		public static final int BUTNEWAVAIL = 3;
		public static final int BUTDELETEAVAIL = 4;
		public static final int BUTDELETEACTIVE = 5;

		public StatShr(
					boolean ButViewAvail
					, boolean ButViewActive
					, boolean ButNewAvail
					, boolean ButDeleteAvail
					, boolean ButDeleteActive
				) {
			this.ButViewAvail = ButViewAvail;
			this.ButViewActive = ButViewActive;
			this.ButNewAvail = ButNewAvail;
			this.ButDeleteAvail = ButDeleteAvail;
			this.ButDeleteActive = ButDeleteActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTVIEWAVAIL, BUTVIEWACTIVE, BUTNEWAVAIL, BUTDELETEAVAIL, BUTDELETEACTIVE));
		};

		public boolean ButViewAvail;
		public boolean ButViewActive;
		public boolean ButNewAvail;
		public boolean ButDeleteAvail;
		public boolean ButDeleteActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmAppRef1NFile");

			String itemtag = "StatitemShrWznmAppRef1NFile";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButViewAvail", mask, BUTVIEWAVAIL);
				ButViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButViewActive", mask, BUTVIEWACTIVE);
				ButNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButNewAvail", mask, BUTNEWAVAIL);
				ButDeleteAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDeleteAvail", mask, BUTDELETEAVAIL);
				ButDeleteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDeleteActive", mask, BUTDELETEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButViewAvail == comp.ButViewAvail) items.add(BUTVIEWAVAIL);
			if (ButViewActive == comp.ButViewActive) items.add(BUTVIEWACTIVE);
			if (ButNewAvail == comp.ButNewAvail) items.add(BUTNEWAVAIL);
			if (ButDeleteAvail == comp.ButDeleteAvail) items.add(BUTDELETEAVAIL);
			if (ButDeleteActive == comp.ButDeleteActive) items.add(BUTDELETEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTVIEWAVAIL, BUTVIEWACTIVE, BUTNEWAVAIL, BUTDELETEAVAIL, BUTDELETEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacWznmAppRef1NFile)
	  */
	public class StgIac extends Block {

		public static final int TCOREFWIDTH = 1;

		public StgIac(
					int TcoRefWidth
				) {
			this.TcoRefWidth = TcoRefWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOREFWIDTH));
		};

		public int TcoRefWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWznmAppRef1NFile");

			String itemtag = "StgitemIacWznmAppRef1NFile";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoRefWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoRefWidth", mask, TCOREFWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWznmAppRef1NFile";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWznmAppRef1NFile";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoRefWidth", TcoRefWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoRefWidth == comp.TcoRefWidth) items.add(TCOREFWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOREFWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmAppRef1NFile)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTRECORD1 = 2;
		public static final int TXTRECORD2 = 3;
		public static final int TRS = 4;
		public static final int TXTSHOWING1 = 5;
		public static final int TXTSHOWING2 = 6;
		public static final int TCOREF = 7;

		public Tag(
					String Cpt
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoRef
				) {
			this.Cpt = Cpt;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoRef = TcoRef;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOREF));
		};

		public String Cpt;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoRef;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmAppRef1NFile");

			String itemtag = "TagitemWznmAppRef1NFile";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoRef = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoRef", mask, TCOREF);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (TxtRecord1.equals(comp.TxtRecord1)) items.add(TXTRECORD1);
			if (TxtRecord2.equals(comp.TxtRecord2)) items.add(TXTRECORD2);
			if (Trs.equals(comp.Trs)) items.add(TRS);
			if (TxtShowing1.equals(comp.TxtShowing1)) items.add(TXTSHOWING1);
			if (TxtShowing2.equals(comp.TxtShowing2)) items.add(TXTSHOWING2);
			if (TcoRef.equals(comp.TcoRef)) items.add(TCOREF);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOREF));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmAppRef1NFileData)
		*/
	public class DpchAppData extends DpchAppWznm {

		public static final int SCRJREF = 1;
		public static final int STGIAC = 2;
		public static final int STGIACQRY = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, StgIac stgiac
					, QryWznmAppRef1NFile.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWznmVDpch.DPCHAPPWZNMAPPREF1NFILEDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, STGIAC, STGIACQRY));
					break;
				};

			if (has(STGIAC)) this.stgiac = stgiac;
			if (has(STGIACQRY)) this.stgiacqry = stgiacqry;
		};

		public StgIac stgiac;
		public QryWznmAppRef1NFile.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWznmAppRef1NFileData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmAppRef1NFileDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMAPPREF1NFILEDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmAppRef1NFileDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmAppRef1NFileData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFCSIQST = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int STGIAC = 6;
		public static final int TAG = 7;
		public static final int RST = 8;
		public static final int STATAPPQRY = 9;
		public static final int STATSHRQRY = 10;
		public static final int STGIACQRY = 11;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMAPPREF1NFILEDATA);

			continf = new ContInf(0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false);
			stgiac = new StgIac(0);
			tag = new Tag("", "", "", "", "", "", "");
			rst = new ListWznmQAppRef1NFile();
			statappqry = (new QryWznmAppRef1NFile()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWznmAppRef1NFile()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWznmAppRef1NFile()).new StgIac(0, 0, 0);
		};

		public ContInf continf;
		public Feed feedFCsiQst;
		public StatApp statapp;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWznmQAppRef1NFile rst;
		public QryWznmAppRef1NFile.StatApp statappqry;
		public QryWznmAppRef1NFile.StatShr statshrqry;
		public QryWznmAppRef1NFile.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFCSIQST)) ss.add("feedFCsiQst");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(TAG)) ss.add("tag");
			if (has(RST)) ss.add("rst");
			if (has(STATAPPQRY)) ss.add("statappqry");
			if (has(STATSHRQRY)) ss.add("statshrqry");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmAppRef1NFileData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFCsiQst.readXML(doc, basexpath, true)) add(FEEDFCSIQST);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (stgiac.readXML(doc, basexpath, true)) add(STGIAC);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (rst.readXML(doc, basexpath, true)) add(RST);
				if (statappqry.readXML(doc, basexpath, true)) add(STATAPPQRY);
				if (statshrqry.readXML(doc, basexpath, true)) add(STATSHRQRY);
				if (stgiacqry.readXML(doc, basexpath, true)) add(STGIACQRY);
			} else {
				scrJref = "";
				continf = new ContInf(0);
				feedFCsiQst = new Feed("FeedFCsiQst");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false);
				stgiac = new StgIac(0);
				tag = new Tag("", "", "", "", "", "", "");
				statappqry = (new QryWznmAppRef1NFile()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWznmAppRef1NFile()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWznmAppRef1NFile()).new StgIac(0, 0, 0);
			};
		};

	};

};

