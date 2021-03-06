/**
  * \file PnlWznmLibRec.java
  * Java API code for job PnlWznmLibRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmLibRec {
	/**
		* VecVDo (full: VecVWznmLibRecDo)
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
	  * ContInf (full: ContInfWznmLibRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmLibRec");

			String itemtag = "ContitemInfWznmLibRec";

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
	  * StatApp (full: StatAppWznmLibRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEAPKGLIST = 2;
		public static final int INITDONEAMAKEFILE = 3;
		public static final int INITDONEREF1NFILE = 4;
		public static final int INITDONEMNOPPACK = 5;
		public static final int INITDONEMNCOMPONENT = 6;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneAPkglist
					, boolean initdoneAMakefile
					, boolean initdoneRef1NFile
					, boolean initdoneMNOppack
					, boolean initdoneMNComponent
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneAPkglist = initdoneAPkglist;
			this.initdoneAMakefile = initdoneAMakefile;
			this.initdoneRef1NFile = initdoneRef1NFile;
			this.initdoneMNOppack = initdoneMNOppack;
			this.initdoneMNComponent = initdoneMNComponent;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEAPKGLIST, INITDONEAMAKEFILE, INITDONEREF1NFILE, INITDONEMNOPPACK, INITDONEMNCOMPONENT));
		};

		public boolean initdoneDetail;
		public boolean initdoneAPkglist;
		public boolean initdoneAMakefile;
		public boolean initdoneRef1NFile;
		public boolean initdoneMNOppack;
		public boolean initdoneMNComponent;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmLibRec");

			String itemtag = "StatitemAppWznmLibRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneAPkglist = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAPkglist", mask, INITDONEAPKGLIST);
				initdoneAMakefile = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAMakefile", mask, INITDONEAMAKEFILE);
				initdoneRef1NFile = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", mask, INITDONEREF1NFILE);
				initdoneMNOppack = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNOppack", mask, INITDONEMNOPPACK);
				initdoneMNComponent = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNComponent", mask, INITDONEMNCOMPONENT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdoneAPkglist == comp.initdoneAPkglist) items.add(INITDONEAPKGLIST);
			if (initdoneAMakefile == comp.initdoneAMakefile) items.add(INITDONEAMAKEFILE);
			if (initdoneRef1NFile == comp.initdoneRef1NFile) items.add(INITDONEREF1NFILE);
			if (initdoneMNOppack == comp.initdoneMNOppack) items.add(INITDONEMNOPPACK);
			if (initdoneMNComponent == comp.initdoneMNComponent) items.add(INITDONEMNCOMPONENT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEAPKGLIST, INITDONEAMAKEFILE, INITDONEREF1NFILE, INITDONEMNOPPACK, INITDONEMNCOMPONENT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmLibRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFAPKGLIST = 3;
		public static final int SCRJREFAMAKEFILE = 4;
		public static final int SCRJREFREF1NFILE = 5;
		public static final int SCRJREFMNOPPACK = 6;
		public static final int SCRJREFMNCOMPONENT = 7;
		public static final int BUTREGULARIZEACTIVE = 8;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefAPkglist
					, String scrJrefAMakefile
					, String scrJrefRef1NFile
					, String scrJrefMNOppack
					, String scrJrefMNComponent
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefAPkglist = scrJrefAPkglist;
			this.scrJrefAMakefile = scrJrefAMakefile;
			this.scrJrefRef1NFile = scrJrefRef1NFile;
			this.scrJrefMNOppack = scrJrefMNOppack;
			this.scrJrefMNComponent = scrJrefMNComponent;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAPKGLIST, SCRJREFAMAKEFILE, SCRJREFREF1NFILE, SCRJREFMNOPPACK, SCRJREFMNCOMPONENT, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefAPkglist;
		public String scrJrefAMakefile;
		public String scrJrefRef1NFile;
		public String scrJrefMNOppack;
		public String scrJrefMNComponent;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmLibRec");

			String itemtag = "StatitemShrWznmLibRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefAPkglist = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAPkglist", mask, SCRJREFAPKGLIST);
				scrJrefAMakefile = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAMakefile", mask, SCRJREFAMAKEFILE);
				scrJrefRef1NFile = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", mask, SCRJREFREF1NFILE);
				scrJrefMNOppack = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNOppack", mask, SCRJREFMNOPPACK);
				scrJrefMNComponent = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNComponent", mask, SCRJREFMNCOMPONENT);
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
			if (scrJrefAPkglist.equals(comp.scrJrefAPkglist)) items.add(SCRJREFAPKGLIST);
			if (scrJrefAMakefile.equals(comp.scrJrefAMakefile)) items.add(SCRJREFAMAKEFILE);
			if (scrJrefRef1NFile.equals(comp.scrJrefRef1NFile)) items.add(SCRJREFREF1NFILE);
			if (scrJrefMNOppack.equals(comp.scrJrefMNOppack)) items.add(SCRJREFMNOPPACK);
			if (scrJrefMNComponent.equals(comp.scrJrefMNComponent)) items.add(SCRJREFMNCOMPONENT);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFAPKGLIST, SCRJREFAMAKEFILE, SCRJREFREF1NFILE, SCRJREFMNOPPACK, SCRJREFMNCOMPONENT, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmLibRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmLibRec");

			String itemtag = "TagitemWznmLibRec";

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
		* DpchAppDo (full: DpchAppWznmLibRecDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMLIBRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmLibRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmLibRecData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMLIBRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmLibRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", "", "", false);
				tag = new Tag("");
			};
		};

	};

};
