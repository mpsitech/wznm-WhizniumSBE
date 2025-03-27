/**
  * \file PnlWznmNavPre.java
  * Java API code for job PnlWznmNavPre
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmNavPre {
	/**
		* VecVDo (full: VecVWznmNavPreDo)
		*/
	public static class VecVDo {

		public static final int BUTAPPREMOVECLICK = 1;
		public static final int BUTVERREMOVECLICK = 2;
		public static final int BUTVISREMOVECLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butappremoveclick")) return BUTAPPREMOVECLICK;
			if (s.equals("butverremoveclick")) return BUTVERREMOVECLICK;
			if (s.equals("butvisremoveclick")) return BUTVISREMOVECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTAPPREMOVECLICK) return("ButAppRemoveClick");
			if (ix == BUTVERREMOVECLICK) return("ButVerRemoveClick");
			if (ix == BUTVISREMOVECLICK) return("ButVisRemoveClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWznmNavPre)
	  */
	public class ContInf extends Block {

		public static final int TXTAPP = 1;
		public static final int TXTVER = 2;
		public static final int TXTVIS = 3;

		public ContInf(
					String TxtApp
					, String TxtVer
					, String TxtVis
				) {
			this.TxtApp = TxtApp;
			this.TxtVer = TxtVer;
			this.TxtVis = TxtVis;

			mask = new HashSet<Integer>(Arrays.asList(TXTAPP, TXTVER, TXTVIS));
		};

		public String TxtApp;
		public String TxtVer;
		public String TxtVis;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmNavPre");

			String itemtag = "ContitemInfWznmNavPre";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtApp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtApp", mask, TXTAPP);
				TxtVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVer", mask, TXTVER);
				TxtVis = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVis", mask, TXTVIS);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtApp.equals(comp.TxtApp)) items.add(TXTAPP);
			if (TxtVer.equals(comp.TxtVer)) items.add(TXTVER);
			if (TxtVis.equals(comp.TxtVis)) items.add(TXTVIS);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTAPP, TXTVER, TXTVIS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmNavPre)
	  */
	public class StatShr extends Block {

		public static final int TXTAPPAVAIL = 1;
		public static final int TXTVERAVAIL = 2;
		public static final int TXTVISAVAIL = 3;

		public StatShr(
					boolean TxtAppAvail
					, boolean TxtVerAvail
					, boolean TxtVisAvail
				) {
			this.TxtAppAvail = TxtAppAvail;
			this.TxtVerAvail = TxtVerAvail;
			this.TxtVisAvail = TxtVisAvail;

			mask = new HashSet<Integer>(Arrays.asList(TXTAPPAVAIL, TXTVERAVAIL, TXTVISAVAIL));
		};

		public boolean TxtAppAvail;
		public boolean TxtVerAvail;
		public boolean TxtVisAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmNavPre");

			String itemtag = "StatitemShrWznmNavPre";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtAppAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtAppAvail", mask, TXTAPPAVAIL);
				TxtVerAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVerAvail", mask, TXTVERAVAIL);
				TxtVisAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVisAvail", mask, TXTVISAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtAppAvail == comp.TxtAppAvail) items.add(TXTAPPAVAIL);
			if (TxtVerAvail == comp.TxtVerAvail) items.add(TXTVERAVAIL);
			if (TxtVisAvail == comp.TxtVisAvail) items.add(TXTVISAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTAPPAVAIL, TXTVERAVAIL, TXTVISAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmNavPre)
	  */
	public class Tag extends Block {

		public static final int CPTAPP = 1;
		public static final int CPTVER = 2;
		public static final int CPTVIS = 3;

		public Tag(
					String CptApp
					, String CptVer
					, String CptVis
				) {
			this.CptApp = CptApp;
			this.CptVer = CptVer;
			this.CptVis = CptVis;

			mask = new HashSet<Integer>(Arrays.asList(CPTAPP, CPTVER, CPTVIS));
		};

		public String CptApp;
		public String CptVer;
		public String CptVis;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmNavPre");

			String itemtag = "TagitemWznmNavPre";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptApp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptApp", mask, CPTAPP);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptVis = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVis", mask, CPTVIS);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptApp.equals(comp.CptApp)) items.add(CPTAPP);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);
			if (CptVis.equals(comp.CptVis)) items.add(CPTVIS);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPTAPP, CPTVER, CPTVIS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmNavPreDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVPREDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavPreDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmNavPreData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATSHR = 3;
		public static final int TAG = 4;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMNAVPREDATA);

			continf = new ContInf("", "", "");
			statshr = new StatShr(false, false, false);
			tag = new Tag("", "", "");
		};

		public ContInf continf;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmNavPreData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("", "", "");
				statshr = new StatShr(false, false, false);
				tag = new Tag("", "", "");
			};
		};

	};

};
