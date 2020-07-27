/**
  * \file PnlWznmPrsDetail.java
  * Java API code for job PnlWznmPrsDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmPrsDetail {
	/**
		* VecVDo (full: VecVWznmPrsDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTJLNEDITCLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butjlneditclick")) return BUTJLNEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTJLNEDITCLICK) return("ButJlnEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmPrsDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFTIT = 1;
		public static final int TXFFNM = 2;
		public static final int NUMFPUPJLN = 3;
		public static final int NUMSFLSTDRV = 4;
		public static final int NUMFPUPSEX = 5;
		public static final int TXFTEL = 6;
		public static final int TXFEML = 7;
		public static final int TXFSAL = 8;

		public ContIac(
					String TxfTit
					, String TxfFnm
					, int numFPupJln
					, ArrayList<Integer> numsFLstDrv
					, int numFPupSex
					, String TxfTel
					, String TxfEml
					, String TxfSal
				) {
			this.TxfTit = TxfTit;
			this.TxfFnm = TxfFnm;
			this.numFPupJln = numFPupJln;
			this.numsFLstDrv = numsFLstDrv;
			this.numFPupSex = numFPupSex;
			this.TxfTel = TxfTel;
			this.TxfEml = TxfEml;
			this.TxfSal = TxfSal;

			mask = new HashSet<Integer>(Arrays.asList(TXFTIT, TXFFNM, NUMFPUPJLN, NUMSFLSTDRV, NUMFPUPSEX, TXFTEL, TXFEML, TXFSAL));
		};

		public String TxfTit;
		public String TxfFnm;
		public int numFPupJln;
		public ArrayList<Integer> numsFLstDrv;
		public int numFPupSex;
		public String TxfTel;
		public String TxfEml;
		public String TxfSal;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmPrsDetail");

			String itemtag = "ContitemIacWznmPrsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfTit", mask, TXFTIT);
				TxfFnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfFnm", mask, TXFFNM);
				numFPupJln = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupJln", mask, NUMFPUPJLN);
				numsFLstDrv = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstDrv", mask, NUMSFLSTDRV);
				numFPupSex = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupSex", mask, NUMFPUPSEX);
				TxfTel = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfTel", mask, TXFTEL);
				TxfEml = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfEml", mask, TXFEML);
				TxfSal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSal", mask, TXFSAL);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmPrsDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmPrsDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTit", TxfTit);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFnm", TxfFnm);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupJln", numFPupJln);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstDrv", numsFLstDrv);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupSex", numFPupSex);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTel", TxfTel);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfEml", TxfEml);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSal", TxfSal);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfTit.equals(comp.TxfTit)) items.add(TXFTIT);
			if (TxfFnm.equals(comp.TxfFnm)) items.add(TXFFNM);
			if (numFPupJln == comp.numFPupJln) items.add(NUMFPUPJLN);
			if (Xmlio.compareIntegervec(numsFLstDrv, comp.numsFLstDrv)) items.add(NUMSFLSTDRV);
			if (numFPupSex == comp.numFPupSex) items.add(NUMFPUPSEX);
			if (TxfTel.equals(comp.TxfTel)) items.add(TXFTEL);
			if (TxfEml.equals(comp.TxfEml)) items.add(TXFEML);
			if (TxfSal.equals(comp.TxfSal)) items.add(TXFSAL);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFTIT, TXFFNM, NUMFPUPJLN, NUMSFLSTDRV, NUMFPUPSEX, TXFTEL, TXFEML, TXFSAL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmPrsDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTLNM = 1;
		public static final int TXTDRV = 2;

		public ContInf(
					String TxtLnm
					, String TxtDrv
				) {
			this.TxtLnm = TxtLnm;
			this.TxtDrv = TxtDrv;

			mask = new HashSet<Integer>(Arrays.asList(TXTLNM, TXTDRV));
		};

		public String TxtLnm;
		public String TxtDrv;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmPrsDetail");

			String itemtag = "ContitemInfWznmPrsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtLnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtLnm", mask, TXTLNM);
				TxtDrv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtDrv", mask, TXTDRV);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtLnm.equals(comp.TxtLnm)) items.add(TXTLNM);
			if (TxtDrv.equals(comp.TxtDrv)) items.add(TXTDRV);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTLNM, TXTDRV));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmPrsDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTDRVALT = 2;
		public static final int LSTDRVNUMFIRSTDISP = 3;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstDrvAlt
					, int LstDrvNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstDrvAlt = LstDrvAlt;
			this.LstDrvNumFirstdisp = LstDrvNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTDRVALT, LSTDRVNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstDrvAlt;
		public int LstDrvNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmPrsDetail");

			String itemtag = "StatitemAppWznmPrsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstDrvAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDrvAlt", mask, LSTDRVALT);
				LstDrvNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDrvNumFirstdisp", mask, LSTDRVNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstDrvAlt == comp.LstDrvAlt) items.add(LSTDRVALT);
			if (LstDrvNumFirstdisp == comp.LstDrvNumFirstdisp) items.add(LSTDRVNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTDRVALT, LSTDRVNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmPrsDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXFTITACTIVE = 3;
		public static final int TXFFNMACTIVE = 4;
		public static final int PUPJLNACTIVE = 5;
		public static final int BUTJLNEDITAVAIL = 6;
		public static final int TXTLNMACTIVE = 7;
		public static final int LSTDRVACTIVE = 8;
		public static final int PUPSEXACTIVE = 9;
		public static final int TXFTELACTIVE = 10;
		public static final int TXFEMLACTIVE = 11;
		public static final int TXFSALACTIVE = 12;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxfTitActive
					, boolean TxfFnmActive
					, boolean PupJlnActive
					, boolean ButJlnEditAvail
					, boolean TxtLnmActive
					, boolean LstDrvActive
					, boolean PupSexActive
					, boolean TxfTelActive
					, boolean TxfEmlActive
					, boolean TxfSalActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxfTitActive = TxfTitActive;
			this.TxfFnmActive = TxfFnmActive;
			this.PupJlnActive = PupJlnActive;
			this.ButJlnEditAvail = ButJlnEditAvail;
			this.TxtLnmActive = TxtLnmActive;
			this.LstDrvActive = LstDrvActive;
			this.PupSexActive = PupSexActive;
			this.TxfTelActive = TxfTelActive;
			this.TxfEmlActive = TxfEmlActive;
			this.TxfSalActive = TxfSalActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXFFNMACTIVE, PUPJLNACTIVE, BUTJLNEDITAVAIL, TXTLNMACTIVE, LSTDRVACTIVE, PUPSEXACTIVE, TXFTELACTIVE, TXFEMLACTIVE, TXFSALACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxfTitActive;
		public boolean TxfFnmActive;
		public boolean PupJlnActive;
		public boolean ButJlnEditAvail;
		public boolean TxtLnmActive;
		public boolean LstDrvActive;
		public boolean PupSexActive;
		public boolean TxfTelActive;
		public boolean TxfEmlActive;
		public boolean TxfSalActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmPrsDetail");

			String itemtag = "StatitemShrWznmPrsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxfTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfTitActive", mask, TXFTITACTIVE);
				TxfFnmActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfFnmActive", mask, TXFFNMACTIVE);
				PupJlnActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupJlnActive", mask, PUPJLNACTIVE);
				ButJlnEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJlnEditAvail", mask, BUTJLNEDITAVAIL);
				TxtLnmActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtLnmActive", mask, TXTLNMACTIVE);
				LstDrvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstDrvActive", mask, LSTDRVACTIVE);
				PupSexActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupSexActive", mask, PUPSEXACTIVE);
				TxfTelActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfTelActive", mask, TXFTELACTIVE);
				TxfEmlActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfEmlActive", mask, TXFEMLACTIVE);
				TxfSalActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfSalActive", mask, TXFSALACTIVE);

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
			if (TxfTitActive == comp.TxfTitActive) items.add(TXFTITACTIVE);
			if (TxfFnmActive == comp.TxfFnmActive) items.add(TXFFNMACTIVE);
			if (PupJlnActive == comp.PupJlnActive) items.add(PUPJLNACTIVE);
			if (ButJlnEditAvail == comp.ButJlnEditAvail) items.add(BUTJLNEDITAVAIL);
			if (TxtLnmActive == comp.TxtLnmActive) items.add(TXTLNMACTIVE);
			if (LstDrvActive == comp.LstDrvActive) items.add(LSTDRVACTIVE);
			if (PupSexActive == comp.PupSexActive) items.add(PUPSEXACTIVE);
			if (TxfTelActive == comp.TxfTelActive) items.add(TXFTELACTIVE);
			if (TxfEmlActive == comp.TxfEmlActive) items.add(TXFEMLACTIVE);
			if (TxfSalActive == comp.TxfSalActive) items.add(TXFSALACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXFFNMACTIVE, PUPJLNACTIVE, BUTJLNEDITAVAIL, TXTLNMACTIVE, LSTDRVACTIVE, PUPSEXACTIVE, TXFTELACTIVE, TXFEMLACTIVE, TXFSALACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmPrsDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTTIT = 2;
		public static final int CPTFNM = 3;
		public static final int CPTLNM = 4;
		public static final int CPTDRV = 5;
		public static final int CPTSEX = 6;
		public static final int CPTTEL = 7;
		public static final int CPTEML = 8;
		public static final int CPTSAL = 9;

		public Tag(
					String Cpt
					, String CptTit
					, String CptFnm
					, String CptLnm
					, String CptDrv
					, String CptSex
					, String CptTel
					, String CptEml
					, String CptSal
				) {
			this.Cpt = Cpt;
			this.CptTit = CptTit;
			this.CptFnm = CptFnm;
			this.CptLnm = CptLnm;
			this.CptDrv = CptDrv;
			this.CptSex = CptSex;
			this.CptTel = CptTel;
			this.CptEml = CptEml;
			this.CptSal = CptSal;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTTIT, CPTFNM, CPTLNM, CPTDRV, CPTSEX, CPTTEL, CPTEML, CPTSAL));
		};

		public String Cpt;
		public String CptTit;
		public String CptFnm;
		public String CptLnm;
		public String CptDrv;
		public String CptSex;
		public String CptTel;
		public String CptEml;
		public String CptSal;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmPrsDetail");

			String itemtag = "TagitemWznmPrsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTit", mask, CPTTIT);
				CptFnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFnm", mask, CPTFNM);
				CptLnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLnm", mask, CPTLNM);
				CptDrv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDrv", mask, CPTDRV);
				CptSex = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSex", mask, CPTSEX);
				CptTel = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTel", mask, CPTTEL);
				CptEml = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptEml", mask, CPTEML);
				CptSal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSal", mask, CPTSAL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptTit.equals(comp.CptTit)) items.add(CPTTIT);
			if (CptFnm.equals(comp.CptFnm)) items.add(CPTFNM);
			if (CptLnm.equals(comp.CptLnm)) items.add(CPTLNM);
			if (CptDrv.equals(comp.CptDrv)) items.add(CPTDRV);
			if (CptSex.equals(comp.CptSex)) items.add(CPTSEX);
			if (CptTel.equals(comp.CptTel)) items.add(CPTTEL);
			if (CptEml.equals(comp.CptEml)) items.add(CPTEML);
			if (CptSal.equals(comp.CptSal)) items.add(CPTSAL);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTTIT, CPTFNM, CPTLNM, CPTDRV, CPTSEX, CPTTEL, CPTEML, CPTSAL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmPrsDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMPRSDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmPrsDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmPrsDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMPRSDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmPrsDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmPrsDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTDRV = 4;
		public static final int FEEDFPUPJLN = 5;
		public static final int FEEDFPUPSEX = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMPRSDETAILDATA);

			contiac = new ContIac("", "", 0, new ArrayList<Integer>(), 0, "", "", "");
			continf = new ContInf("", "");
			feedFLstDrv = new Feed("FeedFLstDrv");
			feedFPupJln = new Feed("FeedFPupJln");
			feedFPupSex = new Feed("FeedFPupSex");
			statapp = new StatApp(0, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstDrv;
		public Feed feedFPupJln;
		public Feed feedFPupSex;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTDRV)) ss.add("feedFLstDrv");
			if (has(FEEDFPUPJLN)) ss.add("feedFPupJln");
			if (has(FEEDFPUPSEX)) ss.add("feedFPupSex");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmPrsDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstDrv.readXML(doc, basexpath, true)) add(FEEDFLSTDRV);
				if (feedFPupJln.readXML(doc, basexpath, true)) add(FEEDFPUPJLN);
				if (feedFPupSex.readXML(doc, basexpath, true)) add(FEEDFPUPSEX);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", 0, new ArrayList<Integer>(), 0, "", "", "");
				continf = new ContInf("", "");
				feedFLstDrv = new Feed("FeedFLstDrv");
				feedFPupJln = new Feed("FeedFPupJln");
				feedFPupSex = new Feed("FeedFPupSex");
				statapp = new StatApp(0, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "");
			};
		};

	};

};
