/**
  * \file PnlWznmMtyDetail.java
  * Java API code for job PnlWznmMtyDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmMtyDetail {
	/**
		* VecVDo (full: VecVWznmMtyDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTOSEDITCLICK = 2;
		public static final int BUTCCHVIEWCLICK = 3;
		public static final int BUTPKMEDITCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butoseditclick")) return BUTOSEDITCLICK;
			if (s.equals("butcchviewclick")) return BUTCCHVIEWCLICK;
			if (s.equals("butpkmeditclick")) return BUTPKMEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTOSEDITCLICK) return("ButOsEditClick");
			if (ix == BUTCCHVIEWCLICK) return("ButCchViewClick");
			if (ix == BUTPKMEDITCLICK) return("ButPkmEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmMtyDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPACH = 1;
		public static final int NUMFPUPOS = 2;
		public static final int TXFOS = 3;
		public static final int NUMFPUPPKM = 4;
		public static final int TXFPKM = 5;
		public static final int TXFCMT = 6;

		public ContIac(
					int numFPupAch
					, int numFPupOs
					, String TxfOs
					, int numFPupPkm
					, String TxfPkm
					, String TxfCmt
				) {
			this.numFPupAch = numFPupAch;
			this.numFPupOs = numFPupOs;
			this.TxfOs = TxfOs;
			this.numFPupPkm = numFPupPkm;
			this.TxfPkm = TxfPkm;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPACH, NUMFPUPOS, TXFOS, NUMFPUPPKM, TXFPKM, TXFCMT));
		};

		public int numFPupAch;
		public int numFPupOs;
		public String TxfOs;
		public int numFPupPkm;
		public String TxfPkm;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmMtyDetail");

			String itemtag = "ContitemIacWznmMtyDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupAch = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupAch", mask, NUMFPUPACH);
				numFPupOs = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupOs", mask, NUMFPUPOS);
				TxfOs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfOs", mask, TXFOS);
				numFPupPkm = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupPkm", mask, NUMFPUPPKM);
				TxfPkm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfPkm", mask, TXFPKM);
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCmt", mask, TXFCMT);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmMtyDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmMtyDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupAch", numFPupAch);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupOs", numFPupOs);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfOs", TxfOs);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupPkm", numFPupPkm);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfPkm", TxfPkm);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupAch == comp.numFPupAch) items.add(NUMFPUPACH);
			if (numFPupOs == comp.numFPupOs) items.add(NUMFPUPOS);
			if (TxfOs.equals(comp.TxfOs)) items.add(TXFOS);
			if (numFPupPkm == comp.numFPupPkm) items.add(NUMFPUPPKM);
			if (TxfPkm.equals(comp.TxfPkm)) items.add(TXFPKM);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPACH, NUMFPUPOS, TXFOS, NUMFPUPPKM, TXFPKM, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmMtyDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTCCH = 2;

		public ContInf(
					String TxtSrf
					, String TxtCch
				) {
			this.TxtSrf = TxtSrf;
			this.TxtCch = TxtCch;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCCH));
		};

		public String TxtSrf;
		public String TxtCch;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmMtyDetail");

			String itemtag = "ContitemInfWznmMtyDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtCch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCch", mask, TXTCCH);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtCch.equals(comp.TxtCch)) items.add(TXTCCH);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCCH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmMtyDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int PUPOSALT = 2;
		public static final int PUPPKMALT = 3;

		public StatApp(
					int ixWznmVExpstate
					, boolean PupOsAlt
					, boolean PupPkmAlt
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.PupOsAlt = PupOsAlt;
			this.PupPkmAlt = PupPkmAlt;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, PUPOSALT, PUPPKMALT));
		};

		public int ixWznmVExpstate;
		public boolean PupOsAlt;
		public boolean PupPkmAlt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmMtyDetail");

			String itemtag = "StatitemAppWznmMtyDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				PupOsAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupOsAlt", mask, PUPOSALT);
				PupPkmAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPkmAlt", mask, PUPPKMALT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (PupOsAlt == comp.PupOsAlt) items.add(PUPOSALT);
			if (PupPkmAlt == comp.PupPkmAlt) items.add(PUPPKMALT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, PUPOSALT, PUPPKMALT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmMtyDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFOSVALID = 1;
		public static final int TXFPKMVALID = 2;
		public static final int BUTSAVEAVAIL = 3;
		public static final int BUTSAVEACTIVE = 4;
		public static final int TXTSRFACTIVE = 5;
		public static final int PUPACHACTIVE = 6;
		public static final int PUPOSACTIVE = 7;
		public static final int BUTOSEDITAVAIL = 8;
		public static final int TXTCCHACTIVE = 9;
		public static final int BUTCCHVIEWAVAIL = 10;
		public static final int BUTCCHVIEWACTIVE = 11;
		public static final int PUPPKMACTIVE = 12;
		public static final int BUTPKMEDITAVAIL = 13;
		public static final int TXFCMTACTIVE = 14;

		public StatShr(
					boolean TxfOsValid
					, boolean TxfPkmValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupAchActive
					, boolean PupOsActive
					, boolean ButOsEditAvail
					, boolean TxtCchActive
					, boolean ButCchViewAvail
					, boolean ButCchViewActive
					, boolean PupPkmActive
					, boolean ButPkmEditAvail
					, boolean TxfCmtActive
				) {
			this.TxfOsValid = TxfOsValid;
			this.TxfPkmValid = TxfPkmValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupAchActive = PupAchActive;
			this.PupOsActive = PupOsActive;
			this.ButOsEditAvail = ButOsEditAvail;
			this.TxtCchActive = TxtCchActive;
			this.ButCchViewAvail = ButCchViewAvail;
			this.ButCchViewActive = ButCchViewActive;
			this.PupPkmActive = PupPkmActive;
			this.ButPkmEditAvail = ButPkmEditAvail;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFOSVALID, TXFPKMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPACHACTIVE, PUPOSACTIVE, BUTOSEDITAVAIL, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, PUPPKMACTIVE, BUTPKMEDITAVAIL, TXFCMTACTIVE));
		};

		public boolean TxfOsValid;
		public boolean TxfPkmValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupAchActive;
		public boolean PupOsActive;
		public boolean ButOsEditAvail;
		public boolean TxtCchActive;
		public boolean ButCchViewAvail;
		public boolean ButCchViewActive;
		public boolean PupPkmActive;
		public boolean ButPkmEditAvail;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmMtyDetail");

			String itemtag = "StatitemShrWznmMtyDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfOsValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfOsValid", mask, TXFOSVALID);
				TxfPkmValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfPkmValid", mask, TXFPKMVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupAchActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupAchActive", mask, PUPACHACTIVE);
				PupOsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupOsActive", mask, PUPOSACTIVE);
				ButOsEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButOsEditAvail", mask, BUTOSEDITAVAIL);
				TxtCchActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCchActive", mask, TXTCCHACTIVE);
				ButCchViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCchViewAvail", mask, BUTCCHVIEWAVAIL);
				ButCchViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCchViewActive", mask, BUTCCHVIEWACTIVE);
				PupPkmActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPkmActive", mask, PUPPKMACTIVE);
				ButPkmEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPkmEditAvail", mask, BUTPKMEDITAVAIL);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfOsValid == comp.TxfOsValid) items.add(TXFOSVALID);
			if (TxfPkmValid == comp.TxfPkmValid) items.add(TXFPKMVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (PupAchActive == comp.PupAchActive) items.add(PUPACHACTIVE);
			if (PupOsActive == comp.PupOsActive) items.add(PUPOSACTIVE);
			if (ButOsEditAvail == comp.ButOsEditAvail) items.add(BUTOSEDITAVAIL);
			if (TxtCchActive == comp.TxtCchActive) items.add(TXTCCHACTIVE);
			if (ButCchViewAvail == comp.ButCchViewAvail) items.add(BUTCCHVIEWAVAIL);
			if (ButCchViewActive == comp.ButCchViewActive) items.add(BUTCCHVIEWACTIVE);
			if (PupPkmActive == comp.PupPkmActive) items.add(PUPPKMACTIVE);
			if (ButPkmEditAvail == comp.ButPkmEditAvail) items.add(BUTPKMEDITAVAIL);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFOSVALID, TXFPKMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPACHACTIVE, PUPOSACTIVE, BUTOSEDITAVAIL, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, PUPPKMACTIVE, BUTPKMEDITAVAIL, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmMtyDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTACH = 3;
		public static final int CPTOS = 4;
		public static final int CPTCCH = 5;
		public static final int CPTPKM = 6;
		public static final int CPTCMT = 7;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptAch
					, String CptOs
					, String CptCch
					, String CptPkm
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptAch = CptAch;
			this.CptOs = CptOs;
			this.CptCch = CptCch;
			this.CptPkm = CptPkm;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTACH, CPTOS, CPTCCH, CPTPKM, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptAch;
		public String CptOs;
		public String CptCch;
		public String CptPkm;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmMtyDetail");

			String itemtag = "TagitemWznmMtyDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptAch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAch", mask, CPTACH);
				CptOs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOs", mask, CPTOS);
				CptCch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCch", mask, CPTCCH);
				CptPkm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPkm", mask, CPTPKM);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);

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
			if (CptAch.equals(comp.CptAch)) items.add(CPTACH);
			if (CptOs.equals(comp.CptOs)) items.add(CPTOS);
			if (CptCch.equals(comp.CptCch)) items.add(CPTCCH);
			if (CptPkm.equals(comp.CptPkm)) items.add(CPTPKM);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTACH, CPTOS, CPTCCH, CPTPKM, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmMtyDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMMTYDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmMtyDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmMtyDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMMTYDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmMtyDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmMtyDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPACH = 4;
		public static final int FEEDFPUPOS = 5;
		public static final int FEEDFPUPPKM = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMMTYDETAILDATA);

			contiac = new ContIac(0, 0, "", 0, "", "");
			continf = new ContInf("", "");
			feedFPupAch = new Feed("FeedFPupAch");
			feedFPupOs = new Feed("FeedFPupOs");
			feedFPupPkm = new Feed("FeedFPupPkm");
			statapp = new StatApp(0, false, false);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupAch;
		public Feed feedFPupOs;
		public Feed feedFPupPkm;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPACH)) ss.add("feedFPupAch");
			if (has(FEEDFPUPOS)) ss.add("feedFPupOs");
			if (has(FEEDFPUPPKM)) ss.add("feedFPupPkm");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmMtyDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupAch.readXML(doc, basexpath, true)) add(FEEDFPUPACH);
				if (feedFPupOs.readXML(doc, basexpath, true)) add(FEEDFPUPOS);
				if (feedFPupPkm.readXML(doc, basexpath, true)) add(FEEDFPUPPKM);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, "", 0, "", "");
				continf = new ContInf("", "");
				feedFPupAch = new Feed("FeedFPupAch");
				feedFPupOs = new Feed("FeedFPupOs");
				feedFPupPkm = new Feed("FeedFPupPkm");
				statapp = new StatApp(0, false, false);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "");
			};
		};

	};

};

