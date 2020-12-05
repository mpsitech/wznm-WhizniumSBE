/**
  * \file PnlWznmCarDetail.java
  * Java API code for job PnlWznmCarDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmCarDetail {
	/**
		* VecVDo (full: VecVWznmCarDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTJTIEDITCLICK = 2;
		public static final int BUTMDLVIEWCLICK = 3;
		public static final int BUTREUVIEWCLICK = 4;
		public static final int BUTJOBVIEWCLICK = 5;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butjtieditclick")) return BUTJTIEDITCLICK;
			if (s.equals("butmdlviewclick")) return BUTMDLVIEWCLICK;
			if (s.equals("butreuviewclick")) return BUTREUVIEWCLICK;
			if (s.equals("butjobviewclick")) return BUTJOBVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTJTIEDITCLICK) return("ButJtiEditClick");
			if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
			if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
			if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmCarDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPJTI = 1;
		public static final int NUMFPUPRET = 2;
		public static final int TXFAVL = 3;
		public static final int TXFACT = 4;

		public ContIac(
					int numFPupJti
					, int numFPupRet
					, String TxfAvl
					, String TxfAct
				) {
			this.numFPupJti = numFPupJti;
			this.numFPupRet = numFPupRet;
			this.TxfAvl = TxfAvl;
			this.TxfAct = TxfAct;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPJTI, NUMFPUPRET, TXFAVL, TXFACT));
		};

		public int numFPupJti;
		public int numFPupRet;
		public String TxfAvl;
		public String TxfAct;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmCarDetail");

			String itemtag = "ContitemIacWznmCarDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupJti = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupJti", mask, NUMFPUPJTI);
				numFPupRet = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupRet", mask, NUMFPUPRET);
				TxfAvl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfAvl", mask, TXFAVL);
				TxfAct = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfAct", mask, TXFACT);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmCarDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmCarDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupJti", numFPupJti);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupRet", numFPupRet);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfAvl", TxfAvl);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfAct", TxfAct);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupJti == comp.numFPupJti) items.add(NUMFPUPJTI);
			if (numFPupRet == comp.numFPupRet) items.add(NUMFPUPRET);
			if (TxfAvl.equals(comp.TxfAvl)) items.add(TXFAVL);
			if (TxfAct.equals(comp.TxfAct)) items.add(TXFACT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPJTI, NUMFPUPRET, TXFAVL, TXFACT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmCarDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTTIT = 2;
		public static final int TXTMDL = 3;
		public static final int TXTREU = 4;
		public static final int TXTJOB = 5;

		public ContInf(
					String TxtSrf
					, String TxtTit
					, String TxtMdl
					, String TxtReu
					, String TxtJob
				) {
			this.TxtSrf = TxtSrf;
			this.TxtTit = TxtTit;
			this.TxtMdl = TxtMdl;
			this.TxtReu = TxtReu;
			this.TxtJob = TxtJob;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTIT, TXTMDL, TXTREU, TXTJOB));
		};

		public String TxtSrf;
		public String TxtTit;
		public String TxtMdl;
		public String TxtReu;
		public String TxtJob;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmCarDetail");

			String itemtag = "ContitemInfWznmCarDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTit", mask, TXTTIT);
				TxtMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMdl", mask, TXTMDL);
				TxtReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtReu", mask, TXTREU);
				TxtJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtJob", mask, TXTJOB);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtTit.equals(comp.TxtTit)) items.add(TXTTIT);
			if (TxtMdl.equals(comp.TxtMdl)) items.add(TXTMDL);
			if (TxtReu.equals(comp.TxtReu)) items.add(TXTREU);
			if (TxtJob.equals(comp.TxtJob)) items.add(TXTJOB);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTIT, TXTMDL, TXTREU, TXTJOB));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmCarDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmCarDetail");

			String itemtag = "StatitemAppWznmCarDetail";

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
	  * StatShr (full: StatShrWznmCarDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int PUPJTIACTIVE = 4;
		public static final int BUTJTIEDITAVAIL = 5;
		public static final int TXTTITACTIVE = 6;
		public static final int TXTMDLACTIVE = 7;
		public static final int BUTMDLVIEWAVAIL = 8;
		public static final int BUTMDLVIEWACTIVE = 9;
		public static final int TXTREUACTIVE = 10;
		public static final int BUTREUVIEWAVAIL = 11;
		public static final int BUTREUVIEWACTIVE = 12;
		public static final int TXTJOBACTIVE = 13;
		public static final int BUTJOBVIEWAVAIL = 14;
		public static final int BUTJOBVIEWACTIVE = 15;
		public static final int TXFAVLACTIVE = 16;
		public static final int TXFACTACTIVE = 17;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupJtiActive
					, boolean ButJtiEditAvail
					, boolean TxtTitActive
					, boolean TxtMdlActive
					, boolean ButMdlViewAvail
					, boolean ButMdlViewActive
					, boolean TxtReuActive
					, boolean ButReuViewAvail
					, boolean ButReuViewActive
					, boolean TxtJobActive
					, boolean ButJobViewAvail
					, boolean ButJobViewActive
					, boolean TxfAvlActive
					, boolean TxfActActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupJtiActive = PupJtiActive;
			this.ButJtiEditAvail = ButJtiEditAvail;
			this.TxtTitActive = TxtTitActive;
			this.TxtMdlActive = TxtMdlActive;
			this.ButMdlViewAvail = ButMdlViewAvail;
			this.ButMdlViewActive = ButMdlViewActive;
			this.TxtReuActive = TxtReuActive;
			this.ButReuViewAvail = ButReuViewAvail;
			this.ButReuViewActive = ButReuViewActive;
			this.TxtJobActive = TxtJobActive;
			this.ButJobViewAvail = ButJobViewAvail;
			this.ButJobViewActive = ButJobViewActive;
			this.TxfAvlActive = TxfAvlActive;
			this.TxfActActive = TxfActActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFAVLACTIVE, TXFACTACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupJtiActive;
		public boolean ButJtiEditAvail;
		public boolean TxtTitActive;
		public boolean TxtMdlActive;
		public boolean ButMdlViewAvail;
		public boolean ButMdlViewActive;
		public boolean TxtReuActive;
		public boolean ButReuViewAvail;
		public boolean ButReuViewActive;
		public boolean TxtJobActive;
		public boolean ButJobViewAvail;
		public boolean ButJobViewActive;
		public boolean TxfAvlActive;
		public boolean TxfActActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmCarDetail");

			String itemtag = "StatitemShrWznmCarDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupJtiActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupJtiActive", mask, PUPJTIACTIVE);
				ButJtiEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJtiEditAvail", mask, BUTJTIEDITAVAIL);
				TxtTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTitActive", mask, TXTTITACTIVE);
				TxtMdlActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtMdlActive", mask, TXTMDLACTIVE);
				ButMdlViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlViewAvail", mask, BUTMDLVIEWAVAIL);
				ButMdlViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlViewActive", mask, BUTMDLVIEWACTIVE);
				TxtReuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtReuActive", mask, TXTREUACTIVE);
				ButReuViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", mask, BUTREUVIEWAVAIL);
				ButReuViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewActive", mask, BUTREUVIEWACTIVE);
				TxtJobActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtJobActive", mask, TXTJOBACTIVE);
				ButJobViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJobViewAvail", mask, BUTJOBVIEWAVAIL);
				ButJobViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJobViewActive", mask, BUTJOBVIEWACTIVE);
				TxfAvlActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfAvlActive", mask, TXFAVLACTIVE);
				TxfActActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfActActive", mask, TXFACTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (PupJtiActive == comp.PupJtiActive) items.add(PUPJTIACTIVE);
			if (ButJtiEditAvail == comp.ButJtiEditAvail) items.add(BUTJTIEDITAVAIL);
			if (TxtTitActive == comp.TxtTitActive) items.add(TXTTITACTIVE);
			if (TxtMdlActive == comp.TxtMdlActive) items.add(TXTMDLACTIVE);
			if (ButMdlViewAvail == comp.ButMdlViewAvail) items.add(BUTMDLVIEWAVAIL);
			if (ButMdlViewActive == comp.ButMdlViewActive) items.add(BUTMDLVIEWACTIVE);
			if (TxtReuActive == comp.TxtReuActive) items.add(TXTREUACTIVE);
			if (ButReuViewAvail == comp.ButReuViewAvail) items.add(BUTREUVIEWAVAIL);
			if (ButReuViewActive == comp.ButReuViewActive) items.add(BUTREUVIEWACTIVE);
			if (TxtJobActive == comp.TxtJobActive) items.add(TXTJOBACTIVE);
			if (ButJobViewAvail == comp.ButJobViewAvail) items.add(BUTJOBVIEWAVAIL);
			if (ButJobViewActive == comp.ButJobViewActive) items.add(BUTJOBVIEWACTIVE);
			if (TxfAvlActive == comp.TxfAvlActive) items.add(TXFAVLACTIVE);
			if (TxfActActive == comp.TxfActActive) items.add(TXFACTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTJOBACTIVE, BUTJOBVIEWAVAIL, BUTJOBVIEWACTIVE, TXFAVLACTIVE, TXFACTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmCarDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTIT = 3;
		public static final int CPTMDL = 4;
		public static final int CPTREU = 5;
		public static final int CPTJOB = 6;
		public static final int CPTAVL = 7;
		public static final int CPTACT = 8;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTit
					, String CptMdl
					, String CptReu
					, String CptJob
					, String CptAvl
					, String CptAct
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTit = CptTit;
			this.CptMdl = CptMdl;
			this.CptReu = CptReu;
			this.CptJob = CptJob;
			this.CptAvl = CptAvl;
			this.CptAct = CptAct;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTMDL, CPTREU, CPTJOB, CPTAVL, CPTACT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTit;
		public String CptMdl;
		public String CptReu;
		public String CptJob;
		public String CptAvl;
		public String CptAct;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmCarDetail");

			String itemtag = "TagitemWznmCarDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTit", mask, CPTTIT);
				CptMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMdl", mask, CPTMDL);
				CptReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptReu", mask, CPTREU);
				CptJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptJob", mask, CPTJOB);
				CptAvl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAvl", mask, CPTAVL);
				CptAct = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAct", mask, CPTACT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptSrf.equals(comp.CptSrf)) items.add(CPTSRF);
			if (CptTit.equals(comp.CptTit)) items.add(CPTTIT);
			if (CptMdl.equals(comp.CptMdl)) items.add(CPTMDL);
			if (CptReu.equals(comp.CptReu)) items.add(CPTREU);
			if (CptJob.equals(comp.CptJob)) items.add(CPTJOB);
			if (CptAvl.equals(comp.CptAvl)) items.add(CPTAVL);
			if (CptAct.equals(comp.CptAct)) items.add(CPTACT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTMDL, CPTREU, CPTJOB, CPTAVL, CPTACT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmCarDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMCARDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmCarDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmCarDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMCARDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmCarDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmCarDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPJTI = 4;
		public static final int FEEDFPUPRET = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMCARDETAILDATA);

			contiac = new ContIac(0, 0, "", "");
			continf = new ContInf("", "", "", "", "");
			feedFPupJti = new Feed("FeedFPupJti");
			feedFPupRet = new Feed("FeedFPupRet");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupJti;
		public Feed feedFPupRet;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPJTI)) ss.add("feedFPupJti");
			if (has(FEEDFPUPRET)) ss.add("feedFPupRet");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmCarDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupJti.readXML(doc, basexpath, true)) add(FEEDFPUPJTI);
				if (feedFPupRet.readXML(doc, basexpath, true)) add(FEEDFPUPRET);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, "", "");
				continf = new ContInf("", "", "", "", "");
				feedFPupJti = new Feed("FeedFPupJti");
				feedFPupRet = new Feed("FeedFPupRet");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "");
			};
		};

	};

};

