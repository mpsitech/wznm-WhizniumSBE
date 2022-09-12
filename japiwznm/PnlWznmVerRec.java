/**
  * \file PnlWznmVerRec.java
  * Java API code for job PnlWznmVerRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmVerRec {
	/**
		* VecVDo (full: VecVWznmVerRecDo)
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
	  * ContInf (full: ContInfWznmVerRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmVerRec");

			String itemtag = "ContitemInfWznmVerRec";

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
	  * StatApp (full: StatAppWznmVerRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEVER1NERROR = 2;
		public static final int INITDONEVER1NAPP = 3;
		public static final int INITDONE1NCAPABILITY = 4;
		public static final int INITDONE1NVECTOR = 5;
		public static final int INITDONE1NTABLE = 6;
		public static final int INITDONE1NRELATION = 7;
		public static final int INITDONE1NQUERY = 8;
		public static final int INITDONE1NPRESET = 9;
		public static final int INITDONEVER1NMODULE = 10;
		public static final int INITDONE1NOPPACK = 11;
		public static final int INITDONE1NJOB = 12;
		public static final int INITDONE1NIMPEXPCPLX = 13;
		public static final int INITDONE1NCALL = 14;
		public static final int INITDONE1NCOMPONENT = 15;
		public static final int INITDONEBVR1NVERSION = 16;
		public static final int INITDONE1NBLOCK = 17;
		public static final int INITDONEREF1NFILE = 18;
		public static final int INITDONEMNLOCALE = 19;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneVer1NError
					, boolean initdoneVer1NApp
					, boolean initdone1NCapability
					, boolean initdone1NVector
					, boolean initdone1NTable
					, boolean initdone1NRelation
					, boolean initdone1NQuery
					, boolean initdone1NPreset
					, boolean initdoneVer1NModule
					, boolean initdone1NOppack
					, boolean initdone1NJob
					, boolean initdone1NImpexpcplx
					, boolean initdone1NCall
					, boolean initdone1NComponent
					, boolean initdoneBvr1NVersion
					, boolean initdone1NBlock
					, boolean initdoneRef1NFile
					, boolean initdoneMNLocale
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneVer1NError = initdoneVer1NError;
			this.initdoneVer1NApp = initdoneVer1NApp;
			this.initdone1NCapability = initdone1NCapability;
			this.initdone1NVector = initdone1NVector;
			this.initdone1NTable = initdone1NTable;
			this.initdone1NRelation = initdone1NRelation;
			this.initdone1NQuery = initdone1NQuery;
			this.initdone1NPreset = initdone1NPreset;
			this.initdoneVer1NModule = initdoneVer1NModule;
			this.initdone1NOppack = initdone1NOppack;
			this.initdone1NJob = initdone1NJob;
			this.initdone1NImpexpcplx = initdone1NImpexpcplx;
			this.initdone1NCall = initdone1NCall;
			this.initdone1NComponent = initdone1NComponent;
			this.initdoneBvr1NVersion = initdoneBvr1NVersion;
			this.initdone1NBlock = initdone1NBlock;
			this.initdoneRef1NFile = initdoneRef1NFile;
			this.initdoneMNLocale = initdoneMNLocale;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEVER1NERROR, INITDONEVER1NAPP, INITDONE1NCAPABILITY, INITDONE1NVECTOR, INITDONE1NTABLE, INITDONE1NRELATION, INITDONE1NQUERY, INITDONE1NPRESET, INITDONEVER1NMODULE, INITDONE1NOPPACK, INITDONE1NJOB, INITDONE1NIMPEXPCPLX, INITDONE1NCALL, INITDONE1NCOMPONENT, INITDONEBVR1NVERSION, INITDONE1NBLOCK, INITDONEREF1NFILE, INITDONEMNLOCALE));
		};

		public boolean initdoneDetail;
		public boolean initdoneVer1NError;
		public boolean initdoneVer1NApp;
		public boolean initdone1NCapability;
		public boolean initdone1NVector;
		public boolean initdone1NTable;
		public boolean initdone1NRelation;
		public boolean initdone1NQuery;
		public boolean initdone1NPreset;
		public boolean initdoneVer1NModule;
		public boolean initdone1NOppack;
		public boolean initdone1NJob;
		public boolean initdone1NImpexpcplx;
		public boolean initdone1NCall;
		public boolean initdone1NComponent;
		public boolean initdoneBvr1NVersion;
		public boolean initdone1NBlock;
		public boolean initdoneRef1NFile;
		public boolean initdoneMNLocale;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmVerRec");

			String itemtag = "StatitemAppWznmVerRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneVer1NError = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneVer1NError", mask, INITDONEVER1NERROR);
				initdoneVer1NApp = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneVer1NApp", mask, INITDONEVER1NAPP);
				initdone1NCapability = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NCapability", mask, INITDONE1NCAPABILITY);
				initdone1NVector = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NVector", mask, INITDONE1NVECTOR);
				initdone1NTable = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NTable", mask, INITDONE1NTABLE);
				initdone1NRelation = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NRelation", mask, INITDONE1NRELATION);
				initdone1NQuery = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NQuery", mask, INITDONE1NQUERY);
				initdone1NPreset = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NPreset", mask, INITDONE1NPRESET);
				initdoneVer1NModule = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneVer1NModule", mask, INITDONEVER1NMODULE);
				initdone1NOppack = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NOppack", mask, INITDONE1NOPPACK);
				initdone1NJob = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NJob", mask, INITDONE1NJOB);
				initdone1NImpexpcplx = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NImpexpcplx", mask, INITDONE1NIMPEXPCPLX);
				initdone1NCall = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NCall", mask, INITDONE1NCALL);
				initdone1NComponent = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NComponent", mask, INITDONE1NCOMPONENT);
				initdoneBvr1NVersion = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneBvr1NVersion", mask, INITDONEBVR1NVERSION);
				initdone1NBlock = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NBlock", mask, INITDONE1NBLOCK);
				initdoneRef1NFile = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", mask, INITDONEREF1NFILE);
				initdoneMNLocale = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNLocale", mask, INITDONEMNLOCALE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdoneVer1NError == comp.initdoneVer1NError) items.add(INITDONEVER1NERROR);
			if (initdoneVer1NApp == comp.initdoneVer1NApp) items.add(INITDONEVER1NAPP);
			if (initdone1NCapability == comp.initdone1NCapability) items.add(INITDONE1NCAPABILITY);
			if (initdone1NVector == comp.initdone1NVector) items.add(INITDONE1NVECTOR);
			if (initdone1NTable == comp.initdone1NTable) items.add(INITDONE1NTABLE);
			if (initdone1NRelation == comp.initdone1NRelation) items.add(INITDONE1NRELATION);
			if (initdone1NQuery == comp.initdone1NQuery) items.add(INITDONE1NQUERY);
			if (initdone1NPreset == comp.initdone1NPreset) items.add(INITDONE1NPRESET);
			if (initdoneVer1NModule == comp.initdoneVer1NModule) items.add(INITDONEVER1NMODULE);
			if (initdone1NOppack == comp.initdone1NOppack) items.add(INITDONE1NOPPACK);
			if (initdone1NJob == comp.initdone1NJob) items.add(INITDONE1NJOB);
			if (initdone1NImpexpcplx == comp.initdone1NImpexpcplx) items.add(INITDONE1NIMPEXPCPLX);
			if (initdone1NCall == comp.initdone1NCall) items.add(INITDONE1NCALL);
			if (initdone1NComponent == comp.initdone1NComponent) items.add(INITDONE1NCOMPONENT);
			if (initdoneBvr1NVersion == comp.initdoneBvr1NVersion) items.add(INITDONEBVR1NVERSION);
			if (initdone1NBlock == comp.initdone1NBlock) items.add(INITDONE1NBLOCK);
			if (initdoneRef1NFile == comp.initdoneRef1NFile) items.add(INITDONEREF1NFILE);
			if (initdoneMNLocale == comp.initdoneMNLocale) items.add(INITDONEMNLOCALE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEVER1NERROR, INITDONEVER1NAPP, INITDONE1NCAPABILITY, INITDONE1NVECTOR, INITDONE1NTABLE, INITDONE1NRELATION, INITDONE1NQUERY, INITDONE1NPRESET, INITDONEVER1NMODULE, INITDONE1NOPPACK, INITDONE1NJOB, INITDONE1NIMPEXPCPLX, INITDONE1NCALL, INITDONE1NCOMPONENT, INITDONEBVR1NVERSION, INITDONE1NBLOCK, INITDONEREF1NFILE, INITDONEMNLOCALE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmVerRec)
	  */
	public class StatShr extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFVER1NERROR = 3;
		public static final int SCRJREFVER1NAPP = 4;
		public static final int SCRJREF1NCAPABILITY = 5;
		public static final int SCRJREF1NVECTOR = 6;
		public static final int SCRJREF1NTABLE = 7;
		public static final int SCRJREF1NRELATION = 8;
		public static final int SCRJREF1NQUERY = 9;
		public static final int SCRJREF1NPRESET = 10;
		public static final int SCRJREFVER1NMODULE = 11;
		public static final int SCRJREF1NOPPACK = 12;
		public static final int SCRJREF1NJOB = 13;
		public static final int SCRJREF1NIMPEXPCPLX = 14;
		public static final int SCRJREF1NCALL = 15;
		public static final int SCRJREF1NCOMPONENT = 16;
		public static final int SCRJREFBVR1NVERSION = 17;
		public static final int SCRJREF1NBLOCK = 18;
		public static final int SCRJREFREF1NFILE = 19;
		public static final int SCRJREFMNLOCALE = 20;
		public static final int BUTREGULARIZEACTIVE = 21;

		public StatShr(
					int ixWznmVExpstate
					, String scrJrefDetail
					, String scrJrefVer1NError
					, String scrJrefVer1NApp
					, String scrJref1NCapability
					, String scrJref1NVector
					, String scrJref1NTable
					, String scrJref1NRelation
					, String scrJref1NQuery
					, String scrJref1NPreset
					, String scrJrefVer1NModule
					, String scrJref1NOppack
					, String scrJref1NJob
					, String scrJref1NImpexpcplx
					, String scrJref1NCall
					, String scrJref1NComponent
					, String scrJrefBvr1NVersion
					, String scrJref1NBlock
					, String scrJrefRef1NFile
					, String scrJrefMNLocale
					, boolean ButRegularizeActive
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefVer1NError = scrJrefVer1NError;
			this.scrJrefVer1NApp = scrJrefVer1NApp;
			this.scrJref1NCapability = scrJref1NCapability;
			this.scrJref1NVector = scrJref1NVector;
			this.scrJref1NTable = scrJref1NTable;
			this.scrJref1NRelation = scrJref1NRelation;
			this.scrJref1NQuery = scrJref1NQuery;
			this.scrJref1NPreset = scrJref1NPreset;
			this.scrJrefVer1NModule = scrJrefVer1NModule;
			this.scrJref1NOppack = scrJref1NOppack;
			this.scrJref1NJob = scrJref1NJob;
			this.scrJref1NImpexpcplx = scrJref1NImpexpcplx;
			this.scrJref1NCall = scrJref1NCall;
			this.scrJref1NComponent = scrJref1NComponent;
			this.scrJrefBvr1NVersion = scrJrefBvr1NVersion;
			this.scrJref1NBlock = scrJref1NBlock;
			this.scrJrefRef1NFile = scrJrefRef1NFile;
			this.scrJrefMNLocale = scrJrefMNLocale;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFVER1NERROR, SCRJREFVER1NAPP, SCRJREF1NCAPABILITY, SCRJREF1NVECTOR, SCRJREF1NTABLE, SCRJREF1NRELATION, SCRJREF1NQUERY, SCRJREF1NPRESET, SCRJREFVER1NMODULE, SCRJREF1NOPPACK, SCRJREF1NJOB, SCRJREF1NIMPEXPCPLX, SCRJREF1NCALL, SCRJREF1NCOMPONENT, SCRJREFBVR1NVERSION, SCRJREF1NBLOCK, SCRJREFREF1NFILE, SCRJREFMNLOCALE, BUTREGULARIZEACTIVE));
		};

		public int ixWznmVExpstate;
		public String scrJrefDetail;
		public String scrJrefVer1NError;
		public String scrJrefVer1NApp;
		public String scrJref1NCapability;
		public String scrJref1NVector;
		public String scrJref1NTable;
		public String scrJref1NRelation;
		public String scrJref1NQuery;
		public String scrJref1NPreset;
		public String scrJrefVer1NModule;
		public String scrJref1NOppack;
		public String scrJref1NJob;
		public String scrJref1NImpexpcplx;
		public String scrJref1NCall;
		public String scrJref1NComponent;
		public String scrJrefBvr1NVersion;
		public String scrJref1NBlock;
		public String scrJrefRef1NFile;
		public String scrJrefMNLocale;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmVerRec");

			String itemtag = "StatitemShrWznmVerRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefVer1NError = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefVer1NError", mask, SCRJREFVER1NERROR);
				scrJrefVer1NApp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefVer1NApp", mask, SCRJREFVER1NAPP);
				scrJref1NCapability = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NCapability", mask, SCRJREF1NCAPABILITY);
				scrJref1NVector = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NVector", mask, SCRJREF1NVECTOR);
				scrJref1NTable = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NTable", mask, SCRJREF1NTABLE);
				scrJref1NRelation = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NRelation", mask, SCRJREF1NRELATION);
				scrJref1NQuery = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NQuery", mask, SCRJREF1NQUERY);
				scrJref1NPreset = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NPreset", mask, SCRJREF1NPRESET);
				scrJrefVer1NModule = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefVer1NModule", mask, SCRJREFVER1NMODULE);
				scrJref1NOppack = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NOppack", mask, SCRJREF1NOPPACK);
				scrJref1NJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NJob", mask, SCRJREF1NJOB);
				scrJref1NImpexpcplx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NImpexpcplx", mask, SCRJREF1NIMPEXPCPLX);
				scrJref1NCall = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NCall", mask, SCRJREF1NCALL);
				scrJref1NComponent = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NComponent", mask, SCRJREF1NCOMPONENT);
				scrJrefBvr1NVersion = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefBvr1NVersion", mask, SCRJREFBVR1NVERSION);
				scrJref1NBlock = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NBlock", mask, SCRJREF1NBLOCK);
				scrJrefRef1NFile = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", mask, SCRJREFREF1NFILE);
				scrJrefMNLocale = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNLocale", mask, SCRJREFMNLOCALE);
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
			if (scrJrefVer1NError.equals(comp.scrJrefVer1NError)) items.add(SCRJREFVER1NERROR);
			if (scrJrefVer1NApp.equals(comp.scrJrefVer1NApp)) items.add(SCRJREFVER1NAPP);
			if (scrJref1NCapability.equals(comp.scrJref1NCapability)) items.add(SCRJREF1NCAPABILITY);
			if (scrJref1NVector.equals(comp.scrJref1NVector)) items.add(SCRJREF1NVECTOR);
			if (scrJref1NTable.equals(comp.scrJref1NTable)) items.add(SCRJREF1NTABLE);
			if (scrJref1NRelation.equals(comp.scrJref1NRelation)) items.add(SCRJREF1NRELATION);
			if (scrJref1NQuery.equals(comp.scrJref1NQuery)) items.add(SCRJREF1NQUERY);
			if (scrJref1NPreset.equals(comp.scrJref1NPreset)) items.add(SCRJREF1NPRESET);
			if (scrJrefVer1NModule.equals(comp.scrJrefVer1NModule)) items.add(SCRJREFVER1NMODULE);
			if (scrJref1NOppack.equals(comp.scrJref1NOppack)) items.add(SCRJREF1NOPPACK);
			if (scrJref1NJob.equals(comp.scrJref1NJob)) items.add(SCRJREF1NJOB);
			if (scrJref1NImpexpcplx.equals(comp.scrJref1NImpexpcplx)) items.add(SCRJREF1NIMPEXPCPLX);
			if (scrJref1NCall.equals(comp.scrJref1NCall)) items.add(SCRJREF1NCALL);
			if (scrJref1NComponent.equals(comp.scrJref1NComponent)) items.add(SCRJREF1NCOMPONENT);
			if (scrJrefBvr1NVersion.equals(comp.scrJrefBvr1NVersion)) items.add(SCRJREFBVR1NVERSION);
			if (scrJref1NBlock.equals(comp.scrJref1NBlock)) items.add(SCRJREF1NBLOCK);
			if (scrJrefRef1NFile.equals(comp.scrJrefRef1NFile)) items.add(SCRJREFREF1NFILE);
			if (scrJrefMNLocale.equals(comp.scrJrefMNLocale)) items.add(SCRJREFMNLOCALE);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, SCRJREFDETAIL, SCRJREFVER1NERROR, SCRJREFVER1NAPP, SCRJREF1NCAPABILITY, SCRJREF1NVECTOR, SCRJREF1NTABLE, SCRJREF1NRELATION, SCRJREF1NQUERY, SCRJREF1NPRESET, SCRJREFVER1NMODULE, SCRJREF1NOPPACK, SCRJREF1NJOB, SCRJREF1NIMPEXPCPLX, SCRJREF1NCALL, SCRJREF1NCOMPONENT, SCRJREFBVR1NVERSION, SCRJREF1NBLOCK, SCRJREFREF1NFILE, SCRJREFMNLOCALE, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmVerRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmVerRec");

			String itemtag = "TagitemWznmVerRec";

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
		* DpchAppDo (full: DpchAppWznmVerRecDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMVERRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmVerRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmVerRecData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMVERRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmVerRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", false);
				tag = new Tag("");
			};
		};

	};

};
