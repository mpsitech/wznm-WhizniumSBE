/**
  * \file PnlWznmConDetail.java
  * Java API code for job PnlWznmConDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmConDetail {
	/**
		* VecVDo (full: VecVWznmConDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTJTIEDITCLICK = 2;
		public static final int BUTCLUVIEWCLICK = 3;
		public static final int BUTCLUCLUSTERCLICK = 4;
		public static final int BUTCLUUNCLUSTERCLICK = 5;
		public static final int BUTHKUVIEWCLICK = 6;
		public static final int BUTREUVIEWCLICK = 7;
		public static final int BUTSUPVIEWCLICK = 8;
		public static final int BUTTAGVIEWCLICK = 9;
		public static final int BUTSTSVIEWCLICK = 10;
		public static final int BUTSHSVIEWCLICK = 11;
		public static final int BUTOPTEDITCLICK = 12;
		public static final int BUTFEDNEWCLICK = 13;
		public static final int BUTFEDDELETECLICK = 14;
		public static final int BUTFEDSRUVIEWCLICK = 15;
		public static final int BUTFEDVITVIEWCLICK = 16;
		public static final int BUTFEDTAGVIEWCLICK = 17;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butjtieditclick")) return BUTJTIEDITCLICK;
			if (s.equals("butcluviewclick")) return BUTCLUVIEWCLICK;
			if (s.equals("butcluclusterclick")) return BUTCLUCLUSTERCLICK;
			if (s.equals("butcluunclusterclick")) return BUTCLUUNCLUSTERCLICK;
			if (s.equals("buthkuviewclick")) return BUTHKUVIEWCLICK;
			if (s.equals("butreuviewclick")) return BUTREUVIEWCLICK;
			if (s.equals("butsupviewclick")) return BUTSUPVIEWCLICK;
			if (s.equals("buttagviewclick")) return BUTTAGVIEWCLICK;
			if (s.equals("butstsviewclick")) return BUTSTSVIEWCLICK;
			if (s.equals("butshsviewclick")) return BUTSHSVIEWCLICK;
			if (s.equals("butopteditclick")) return BUTOPTEDITCLICK;
			if (s.equals("butfednewclick")) return BUTFEDNEWCLICK;
			if (s.equals("butfeddeleteclick")) return BUTFEDDELETECLICK;
			if (s.equals("butfedsruviewclick")) return BUTFEDSRUVIEWCLICK;
			if (s.equals("butfedvitviewclick")) return BUTFEDVITVIEWCLICK;
			if (s.equals("butfedtagviewclick")) return BUTFEDTAGVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTJTIEDITCLICK) return("ButJtiEditClick");
			if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
			if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
			if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
			if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");
			if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
			if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
			if (ix == BUTTAGVIEWCLICK) return("ButTagViewClick");
			if (ix == BUTSTSVIEWCLICK) return("ButStsViewClick");
			if (ix == BUTSHSVIEWCLICK) return("ButShsViewClick");
			if (ix == BUTOPTEDITCLICK) return("ButOptEditClick");
			if (ix == BUTFEDNEWCLICK) return("ButFedNewClick");
			if (ix == BUTFEDDELETECLICK) return("ButFedDeleteClick");
			if (ix == BUTFEDSRUVIEWCLICK) return("ButFedSruViewClick");
			if (ix == BUTFEDVITVIEWCLICK) return("ButFedVitViewClick");
			if (ix == BUTFEDTAGVIEWCLICK) return("ButFedTagViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmConDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPJTI = 1;
		public static final int NUMFPUPTYP = 2;
		public static final int NUMFLSTCLU = 3;
		public static final int NUMFPUPHKT = 4;
		public static final int NUMFPUPRET = 5;
		public static final int NUMFPUPSCO = 6;
		public static final int NUMFPUPSTY = 7;
		public static final int NUMFLSTTAG = 8;
		public static final int TXFTAG = 9;
		public static final int TXFAVL = 10;
		public static final int TXFACT = 11;
		public static final int NUMSFLSTOPT = 12;
		public static final int TXFOPT = 13;
		public static final int NUMFPUPFEDSRT = 14;
		public static final int NUMFLSTFEDVIT = 15;
		public static final int TXFFEDVIT = 16;
		public static final int NUMFLSTFEDTAG = 17;
		public static final int TXFFEDTAG = 18;
		public static final int TXFFEDCMT = 19;

		public ContIac(
					int numFPupJti
					, int numFPupTyp
					, int numFLstClu
					, int numFPupHkt
					, int numFPupRet
					, int numFPupSco
					, int numFPupSty
					, int numFLstTag
					, String TxfTag
					, String TxfAvl
					, String TxfAct
					, ArrayList<Integer> numsFLstOpt
					, String TxfOpt
					, int numFPupFedSrt
					, int numFLstFedVit
					, String TxfFedVit
					, int numFLstFedTag
					, String TxfFedTag
					, String TxfFedCmt
				) {
			this.numFPupJti = numFPupJti;
			this.numFPupTyp = numFPupTyp;
			this.numFLstClu = numFLstClu;
			this.numFPupHkt = numFPupHkt;
			this.numFPupRet = numFPupRet;
			this.numFPupSco = numFPupSco;
			this.numFPupSty = numFPupSty;
			this.numFLstTag = numFLstTag;
			this.TxfTag = TxfTag;
			this.TxfAvl = TxfAvl;
			this.TxfAct = TxfAct;
			this.numsFLstOpt = numsFLstOpt;
			this.TxfOpt = TxfOpt;
			this.numFPupFedSrt = numFPupFedSrt;
			this.numFLstFedVit = numFLstFedVit;
			this.TxfFedVit = TxfFedVit;
			this.numFLstFedTag = numFLstFedTag;
			this.TxfFedTag = TxfFedTag;
			this.TxfFedCmt = TxfFedCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPJTI, NUMFPUPTYP, NUMFLSTCLU, NUMFPUPHKT, NUMFPUPRET, NUMFPUPSCO, NUMFPUPSTY, NUMFLSTTAG, TXFTAG, TXFAVL, TXFACT, NUMSFLSTOPT, TXFOPT, NUMFPUPFEDSRT, NUMFLSTFEDVIT, TXFFEDVIT, NUMFLSTFEDTAG, TXFFEDTAG, TXFFEDCMT));
		};

		public int numFPupJti;
		public int numFPupTyp;
		public int numFLstClu;
		public int numFPupHkt;
		public int numFPupRet;
		public int numFPupSco;
		public int numFPupSty;
		public int numFLstTag;
		public String TxfTag;
		public String TxfAvl;
		public String TxfAct;
		public ArrayList<Integer> numsFLstOpt;
		public String TxfOpt;
		public int numFPupFedSrt;
		public int numFLstFedVit;
		public String TxfFedVit;
		public int numFLstFedTag;
		public String TxfFedTag;
		public String TxfFedCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmConDetail");

			String itemtag = "ContitemIacWznmConDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupJti = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupJti", mask, NUMFPUPJTI);
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				numFLstClu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstClu", mask, NUMFLSTCLU);
				numFPupHkt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupHkt", mask, NUMFPUPHKT);
				numFPupRet = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupRet", mask, NUMFPUPRET);
				numFPupSco = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupSco", mask, NUMFPUPSCO);
				numFPupSty = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupSty", mask, NUMFPUPSTY);
				numFLstTag = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstTag", mask, NUMFLSTTAG);
				TxfTag = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfTag", mask, TXFTAG);
				TxfAvl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfAvl", mask, TXFAVL);
				TxfAct = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfAct", mask, TXFACT);
				numsFLstOpt = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", mask, NUMSFLSTOPT);
				TxfOpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfOpt", mask, TXFOPT);
				numFPupFedSrt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupFedSrt", mask, NUMFPUPFEDSRT);
				numFLstFedVit = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstFedVit", mask, NUMFLSTFEDVIT);
				TxfFedVit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfFedVit", mask, TXFFEDVIT);
				numFLstFedTag = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstFedTag", mask, NUMFLSTFEDTAG);
				TxfFedTag = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfFedTag", mask, TXFFEDTAG);
				TxfFedCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfFedCmt", mask, TXFFEDCMT);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmConDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmConDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupJti", numFPupJti);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstClu", numFLstClu);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupHkt", numFPupHkt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupRet", numFPupRet);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupSco", numFPupSco);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupSty", numFPupSty);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstTag", numFLstTag);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTag", TxfTag);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfAvl", TxfAvl);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfAct", TxfAct);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfOpt", TxfOpt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupFedSrt", numFPupFedSrt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstFedVit", numFLstFedVit);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFedVit", TxfFedVit);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstFedTag", numFLstFedTag);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFedTag", TxfFedTag);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFedCmt", TxfFedCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupJti == comp.numFPupJti) items.add(NUMFPUPJTI);
			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (numFLstClu == comp.numFLstClu) items.add(NUMFLSTCLU);
			if (numFPupHkt == comp.numFPupHkt) items.add(NUMFPUPHKT);
			if (numFPupRet == comp.numFPupRet) items.add(NUMFPUPRET);
			if (numFPupSco == comp.numFPupSco) items.add(NUMFPUPSCO);
			if (numFPupSty == comp.numFPupSty) items.add(NUMFPUPSTY);
			if (numFLstTag == comp.numFLstTag) items.add(NUMFLSTTAG);
			if (TxfTag.equals(comp.TxfTag)) items.add(TXFTAG);
			if (TxfAvl.equals(comp.TxfAvl)) items.add(TXFAVL);
			if (TxfAct.equals(comp.TxfAct)) items.add(TXFACT);
			if (Xmlio.compareIntegervec(numsFLstOpt, comp.numsFLstOpt)) items.add(NUMSFLSTOPT);
			if (TxfOpt.equals(comp.TxfOpt)) items.add(TXFOPT);
			if (numFPupFedSrt == comp.numFPupFedSrt) items.add(NUMFPUPFEDSRT);
			if (numFLstFedVit == comp.numFLstFedVit) items.add(NUMFLSTFEDVIT);
			if (TxfFedVit.equals(comp.TxfFedVit)) items.add(TXFFEDVIT);
			if (numFLstFedTag == comp.numFLstFedTag) items.add(NUMFLSTFEDTAG);
			if (TxfFedTag.equals(comp.TxfFedTag)) items.add(TXFFEDTAG);
			if (TxfFedCmt.equals(comp.TxfFedCmt)) items.add(TXFFEDCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPJTI, NUMFPUPTYP, NUMFLSTCLU, NUMFPUPHKT, NUMFPUPRET, NUMFPUPSCO, NUMFPUPSTY, NUMFLSTTAG, TXFTAG, TXFAVL, TXFACT, NUMSFLSTOPT, TXFOPT, NUMFPUPFEDSRT, NUMFLSTFEDVIT, TXFFEDVIT, NUMFLSTFEDTAG, TXFFEDTAG, TXFFEDCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWznmConDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTTIT = 2;
		public static final int TXTCLU = 3;
		public static final int TXTHKU = 4;
		public static final int TXTREU = 5;
		public static final int TXTSUP = 6;
		public static final int TXTSTS = 7;
		public static final int TXTSHS = 8;
		public static final int TXTFEDSRF = 9;
		public static final int TXTFEDSRU = 10;

		public ContInf(
					String TxtSrf
					, String TxtTit
					, String TxtClu
					, String TxtHku
					, String TxtReu
					, String TxtSup
					, String TxtSts
					, String TxtShs
					, String TxtFedSrf
					, String TxtFedSru
				) {
			this.TxtSrf = TxtSrf;
			this.TxtTit = TxtTit;
			this.TxtClu = TxtClu;
			this.TxtHku = TxtHku;
			this.TxtReu = TxtReu;
			this.TxtSup = TxtSup;
			this.TxtSts = TxtSts;
			this.TxtShs = TxtShs;
			this.TxtFedSrf = TxtFedSrf;
			this.TxtFedSru = TxtFedSru;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTIT, TXTCLU, TXTHKU, TXTREU, TXTSUP, TXTSTS, TXTSHS, TXTFEDSRF, TXTFEDSRU));
		};

		public String TxtSrf;
		public String TxtTit;
		public String TxtClu;
		public String TxtHku;
		public String TxtReu;
		public String TxtSup;
		public String TxtSts;
		public String TxtShs;
		public String TxtFedSrf;
		public String TxtFedSru;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWznmConDetail");

			String itemtag = "ContitemInfWznmConDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTit", mask, TXTTIT);
				TxtClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtClu", mask, TXTCLU);
				TxtHku = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtHku", mask, TXTHKU);
				TxtReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtReu", mask, TXTREU);
				TxtSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSup", mask, TXTSUP);
				TxtSts = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSts", mask, TXTSTS);
				TxtShs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtShs", mask, TXTSHS);
				TxtFedSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtFedSrf", mask, TXTFEDSRF);
				TxtFedSru = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtFedSru", mask, TXTFEDSRU);

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
			if (TxtClu.equals(comp.TxtClu)) items.add(TXTCLU);
			if (TxtHku.equals(comp.TxtHku)) items.add(TXTHKU);
			if (TxtReu.equals(comp.TxtReu)) items.add(TXTREU);
			if (TxtSup.equals(comp.TxtSup)) items.add(TXTSUP);
			if (TxtSts.equals(comp.TxtSts)) items.add(TXTSTS);
			if (TxtShs.equals(comp.TxtShs)) items.add(TXTSHS);
			if (TxtFedSrf.equals(comp.TxtFedSrf)) items.add(TXTFEDSRF);
			if (TxtFedSru.equals(comp.TxtFedSru)) items.add(TXTFEDSRU);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTTIT, TXTCLU, TXTHKU, TXTREU, TXTSUP, TXTSTS, TXTSHS, TXTFEDSRF, TXTFEDSRU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmConDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTCLUALT = 2;
		public static final int LSTTAGALT = 3;
		public static final int LSTOPTALT = 4;
		public static final int LSTFEDVITALT = 5;
		public static final int LSTFEDTAGALT = 6;
		public static final int LSTCLUNUMFIRSTDISP = 7;
		public static final int LSTTAGNUMFIRSTDISP = 8;
		public static final int LSTOPTNUMFIRSTDISP = 9;
		public static final int LSTFEDVITNUMFIRSTDISP = 10;
		public static final int LSTFEDTAGNUMFIRSTDISP = 11;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstCluAlt
					, boolean LstTagAlt
					, boolean LstOptAlt
					, boolean LstFedVitAlt
					, boolean LstFedTagAlt
					, int LstCluNumFirstdisp
					, int LstTagNumFirstdisp
					, int LstOptNumFirstdisp
					, int LstFedVitNumFirstdisp
					, int LstFedTagNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstCluAlt = LstCluAlt;
			this.LstTagAlt = LstTagAlt;
			this.LstOptAlt = LstOptAlt;
			this.LstFedVitAlt = LstFedVitAlt;
			this.LstFedTagAlt = LstFedTagAlt;
			this.LstCluNumFirstdisp = LstCluNumFirstdisp;
			this.LstTagNumFirstdisp = LstTagNumFirstdisp;
			this.LstOptNumFirstdisp = LstOptNumFirstdisp;
			this.LstFedVitNumFirstdisp = LstFedVitNumFirstdisp;
			this.LstFedTagNumFirstdisp = LstFedTagNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTCLUALT, LSTTAGALT, LSTOPTALT, LSTFEDVITALT, LSTFEDTAGALT, LSTCLUNUMFIRSTDISP, LSTTAGNUMFIRSTDISP, LSTOPTNUMFIRSTDISP, LSTFEDVITNUMFIRSTDISP, LSTFEDTAGNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstCluAlt;
		public boolean LstTagAlt;
		public boolean LstOptAlt;
		public boolean LstFedVitAlt;
		public boolean LstFedTagAlt;
		public int LstCluNumFirstdisp;
		public int LstTagNumFirstdisp;
		public int LstOptNumFirstdisp;
		public int LstFedVitNumFirstdisp;
		public int LstFedTagNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmConDetail");

			String itemtag = "StatitemAppWznmConDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstCluAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluAlt", mask, LSTCLUALT);
				LstTagAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTagAlt", mask, LSTTAGALT);
				LstOptAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptAlt", mask, LSTOPTALT);
				LstFedVitAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFedVitAlt", mask, LSTFEDVITALT);
				LstFedTagAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFedTagAlt", mask, LSTFEDTAGALT);
				LstCluNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluNumFirstdisp", mask, LSTCLUNUMFIRSTDISP);
				LstTagNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTagNumFirstdisp", mask, LSTTAGNUMFIRSTDISP);
				LstOptNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptNumFirstdisp", mask, LSTOPTNUMFIRSTDISP);
				LstFedVitNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFedVitNumFirstdisp", mask, LSTFEDVITNUMFIRSTDISP);
				LstFedTagNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFedTagNumFirstdisp", mask, LSTFEDTAGNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstCluAlt == comp.LstCluAlt) items.add(LSTCLUALT);
			if (LstTagAlt == comp.LstTagAlt) items.add(LSTTAGALT);
			if (LstOptAlt == comp.LstOptAlt) items.add(LSTOPTALT);
			if (LstFedVitAlt == comp.LstFedVitAlt) items.add(LSTFEDVITALT);
			if (LstFedTagAlt == comp.LstFedTagAlt) items.add(LSTFEDTAGALT);
			if (LstCluNumFirstdisp == comp.LstCluNumFirstdisp) items.add(LSTCLUNUMFIRSTDISP);
			if (LstTagNumFirstdisp == comp.LstTagNumFirstdisp) items.add(LSTTAGNUMFIRSTDISP);
			if (LstOptNumFirstdisp == comp.LstOptNumFirstdisp) items.add(LSTOPTNUMFIRSTDISP);
			if (LstFedVitNumFirstdisp == comp.LstFedVitNumFirstdisp) items.add(LSTFEDVITNUMFIRSTDISP);
			if (LstFedTagNumFirstdisp == comp.LstFedTagNumFirstdisp) items.add(LSTFEDTAGNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTCLUALT, LSTTAGALT, LSTOPTALT, LSTFEDVITALT, LSTFEDTAGALT, LSTCLUNUMFIRSTDISP, LSTTAGNUMFIRSTDISP, LSTOPTNUMFIRSTDISP, LSTFEDVITNUMFIRSTDISP, LSTFEDTAGNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmConDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFTAGVALID = 1;
		public static final int TXFOPTVALID = 2;
		public static final int TXFFEDVITVALID = 3;
		public static final int TXFFEDTAGVALID = 4;
		public static final int BUTSAVEAVAIL = 5;
		public static final int BUTSAVEACTIVE = 6;
		public static final int TXTSRFACTIVE = 7;
		public static final int PUPJTIACTIVE = 8;
		public static final int BUTJTIEDITAVAIL = 9;
		public static final int TXTTITACTIVE = 10;
		public static final int PUPTYPACTIVE = 11;
		public static final int LSTCLUACTIVE = 12;
		public static final int BUTCLUVIEWACTIVE = 13;
		public static final int BUTCLUCLUSTERAVAIL = 14;
		public static final int BUTCLUUNCLUSTERAVAIL = 15;
		public static final int TXTHKUACTIVE = 16;
		public static final int BUTHKUVIEWAVAIL = 17;
		public static final int BUTHKUVIEWACTIVE = 18;
		public static final int TXTREUACTIVE = 19;
		public static final int BUTREUVIEWAVAIL = 20;
		public static final int BUTREUVIEWACTIVE = 21;
		public static final int TXTSUPACTIVE = 22;
		public static final int BUTSUPVIEWAVAIL = 23;
		public static final int BUTSUPVIEWACTIVE = 24;
		public static final int PUPSCOACTIVE = 25;
		public static final int PUPSTYACTIVE = 26;
		public static final int LSTTAGACTIVE = 27;
		public static final int BUTTAGVIEWAVAIL = 28;
		public static final int BUTTAGVIEWACTIVE = 29;
		public static final int TXTSTSACTIVE = 30;
		public static final int BUTSTSVIEWAVAIL = 31;
		public static final int BUTSTSVIEWACTIVE = 32;
		public static final int TXTSHSACTIVE = 33;
		public static final int BUTSHSVIEWAVAIL = 34;
		public static final int BUTSHSVIEWACTIVE = 35;
		public static final int TXFAVLACTIVE = 36;
		public static final int TXFACTACTIVE = 37;
		public static final int LSTOPTACTIVE = 38;
		public static final int BUTOPTEDITAVAIL = 39;
		public static final int SEPFEDAVAIL = 40;
		public static final int HDGFEDAVAIL = 41;
		public static final int BUTFEDNEWAVAIL = 42;
		public static final int BUTFEDDELETEAVAIL = 43;
		public static final int TXTFEDSRFAVAIL = 44;
		public static final int TXTFEDSRFACTIVE = 45;
		public static final int TXTFEDSRUAVAIL = 46;
		public static final int TXTFEDSRUACTIVE = 47;
		public static final int BUTFEDSRUVIEWAVAIL = 48;
		public static final int BUTFEDSRUVIEWACTIVE = 49;
		public static final int LSTFEDVITAVAIL = 50;
		public static final int LSTFEDVITACTIVE = 51;
		public static final int BUTFEDVITVIEWAVAIL = 52;
		public static final int BUTFEDVITVIEWACTIVE = 53;
		public static final int LSTFEDTAGAVAIL = 54;
		public static final int LSTFEDTAGACTIVE = 55;
		public static final int BUTFEDTAGVIEWAVAIL = 56;
		public static final int BUTFEDTAGVIEWACTIVE = 57;
		public static final int TXFFEDCMTAVAIL = 58;
		public static final int TXFFEDCMTACTIVE = 59;

		public StatShr(
					boolean TxfTagValid
					, boolean TxfOptValid
					, boolean TxfFedVitValid
					, boolean TxfFedTagValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupJtiActive
					, boolean ButJtiEditAvail
					, boolean TxtTitActive
					, boolean PupTypActive
					, boolean LstCluActive
					, boolean ButCluViewActive
					, boolean ButCluClusterAvail
					, boolean ButCluUnclusterAvail
					, boolean TxtHkuActive
					, boolean ButHkuViewAvail
					, boolean ButHkuViewActive
					, boolean TxtReuActive
					, boolean ButReuViewAvail
					, boolean ButReuViewActive
					, boolean TxtSupActive
					, boolean ButSupViewAvail
					, boolean ButSupViewActive
					, boolean PupScoActive
					, boolean PupStyActive
					, boolean LstTagActive
					, boolean ButTagViewAvail
					, boolean ButTagViewActive
					, boolean TxtStsActive
					, boolean ButStsViewAvail
					, boolean ButStsViewActive
					, boolean TxtShsActive
					, boolean ButShsViewAvail
					, boolean ButShsViewActive
					, boolean TxfAvlActive
					, boolean TxfActActive
					, boolean LstOptActive
					, boolean ButOptEditAvail
					, boolean SepFedAvail
					, boolean HdgFedAvail
					, boolean ButFedNewAvail
					, boolean ButFedDeleteAvail
					, boolean TxtFedSrfAvail
					, boolean TxtFedSrfActive
					, boolean TxtFedSruAvail
					, boolean TxtFedSruActive
					, boolean ButFedSruViewAvail
					, boolean ButFedSruViewActive
					, boolean LstFedVitAvail
					, boolean LstFedVitActive
					, boolean ButFedVitViewAvail
					, boolean ButFedVitViewActive
					, boolean LstFedTagAvail
					, boolean LstFedTagActive
					, boolean ButFedTagViewAvail
					, boolean ButFedTagViewActive
					, boolean TxfFedCmtAvail
					, boolean TxfFedCmtActive
				) {
			this.TxfTagValid = TxfTagValid;
			this.TxfOptValid = TxfOptValid;
			this.TxfFedVitValid = TxfFedVitValid;
			this.TxfFedTagValid = TxfFedTagValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupJtiActive = PupJtiActive;
			this.ButJtiEditAvail = ButJtiEditAvail;
			this.TxtTitActive = TxtTitActive;
			this.PupTypActive = PupTypActive;
			this.LstCluActive = LstCluActive;
			this.ButCluViewActive = ButCluViewActive;
			this.ButCluClusterAvail = ButCluClusterAvail;
			this.ButCluUnclusterAvail = ButCluUnclusterAvail;
			this.TxtHkuActive = TxtHkuActive;
			this.ButHkuViewAvail = ButHkuViewAvail;
			this.ButHkuViewActive = ButHkuViewActive;
			this.TxtReuActive = TxtReuActive;
			this.ButReuViewAvail = ButReuViewAvail;
			this.ButReuViewActive = ButReuViewActive;
			this.TxtSupActive = TxtSupActive;
			this.ButSupViewAvail = ButSupViewAvail;
			this.ButSupViewActive = ButSupViewActive;
			this.PupScoActive = PupScoActive;
			this.PupStyActive = PupStyActive;
			this.LstTagActive = LstTagActive;
			this.ButTagViewAvail = ButTagViewAvail;
			this.ButTagViewActive = ButTagViewActive;
			this.TxtStsActive = TxtStsActive;
			this.ButStsViewAvail = ButStsViewAvail;
			this.ButStsViewActive = ButStsViewActive;
			this.TxtShsActive = TxtShsActive;
			this.ButShsViewAvail = ButShsViewAvail;
			this.ButShsViewActive = ButShsViewActive;
			this.TxfAvlActive = TxfAvlActive;
			this.TxfActActive = TxfActActive;
			this.LstOptActive = LstOptActive;
			this.ButOptEditAvail = ButOptEditAvail;
			this.SepFedAvail = SepFedAvail;
			this.HdgFedAvail = HdgFedAvail;
			this.ButFedNewAvail = ButFedNewAvail;
			this.ButFedDeleteAvail = ButFedDeleteAvail;
			this.TxtFedSrfAvail = TxtFedSrfAvail;
			this.TxtFedSrfActive = TxtFedSrfActive;
			this.TxtFedSruAvail = TxtFedSruAvail;
			this.TxtFedSruActive = TxtFedSruActive;
			this.ButFedSruViewAvail = ButFedSruViewAvail;
			this.ButFedSruViewActive = ButFedSruViewActive;
			this.LstFedVitAvail = LstFedVitAvail;
			this.LstFedVitActive = LstFedVitActive;
			this.ButFedVitViewAvail = ButFedVitViewAvail;
			this.ButFedVitViewActive = ButFedVitViewActive;
			this.LstFedTagAvail = LstFedTagAvail;
			this.LstFedTagActive = LstFedTagActive;
			this.ButFedTagViewAvail = ButFedTagViewAvail;
			this.ButFedTagViewActive = ButFedTagViewActive;
			this.TxfFedCmtAvail = TxfFedCmtAvail;
			this.TxfFedCmtActive = TxfFedCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFTAGVALID, TXFOPTVALID, TXFFEDVITVALID, TXFFEDTAGVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, PUPSCOACTIVE, PUPSTYACTIVE, LSTTAGACTIVE, BUTTAGVIEWAVAIL, BUTTAGVIEWACTIVE, TXTSTSACTIVE, BUTSTSVIEWAVAIL, BUTSTSVIEWACTIVE, TXTSHSACTIVE, BUTSHSVIEWAVAIL, BUTSHSVIEWACTIVE, TXFAVLACTIVE, TXFACTACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, SEPFEDAVAIL, HDGFEDAVAIL, BUTFEDNEWAVAIL, BUTFEDDELETEAVAIL, TXTFEDSRFAVAIL, TXTFEDSRFACTIVE, TXTFEDSRUAVAIL, TXTFEDSRUACTIVE, BUTFEDSRUVIEWAVAIL, BUTFEDSRUVIEWACTIVE, LSTFEDVITAVAIL, LSTFEDVITACTIVE, BUTFEDVITVIEWAVAIL, BUTFEDVITVIEWACTIVE, LSTFEDTAGAVAIL, LSTFEDTAGACTIVE, BUTFEDTAGVIEWAVAIL, BUTFEDTAGVIEWACTIVE, TXFFEDCMTAVAIL, TXFFEDCMTACTIVE));
		};

		public boolean TxfTagValid;
		public boolean TxfOptValid;
		public boolean TxfFedVitValid;
		public boolean TxfFedTagValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupJtiActive;
		public boolean ButJtiEditAvail;
		public boolean TxtTitActive;
		public boolean PupTypActive;
		public boolean LstCluActive;
		public boolean ButCluViewActive;
		public boolean ButCluClusterAvail;
		public boolean ButCluUnclusterAvail;
		public boolean TxtHkuActive;
		public boolean ButHkuViewAvail;
		public boolean ButHkuViewActive;
		public boolean TxtReuActive;
		public boolean ButReuViewAvail;
		public boolean ButReuViewActive;
		public boolean TxtSupActive;
		public boolean ButSupViewAvail;
		public boolean ButSupViewActive;
		public boolean PupScoActive;
		public boolean PupStyActive;
		public boolean LstTagActive;
		public boolean ButTagViewAvail;
		public boolean ButTagViewActive;
		public boolean TxtStsActive;
		public boolean ButStsViewAvail;
		public boolean ButStsViewActive;
		public boolean TxtShsActive;
		public boolean ButShsViewAvail;
		public boolean ButShsViewActive;
		public boolean TxfAvlActive;
		public boolean TxfActActive;
		public boolean LstOptActive;
		public boolean ButOptEditAvail;
		public boolean SepFedAvail;
		public boolean HdgFedAvail;
		public boolean ButFedNewAvail;
		public boolean ButFedDeleteAvail;
		public boolean TxtFedSrfAvail;
		public boolean TxtFedSrfActive;
		public boolean TxtFedSruAvail;
		public boolean TxtFedSruActive;
		public boolean ButFedSruViewAvail;
		public boolean ButFedSruViewActive;
		public boolean LstFedVitAvail;
		public boolean LstFedVitActive;
		public boolean ButFedVitViewAvail;
		public boolean ButFedVitViewActive;
		public boolean LstFedTagAvail;
		public boolean LstFedTagActive;
		public boolean ButFedTagViewAvail;
		public boolean ButFedTagViewActive;
		public boolean TxfFedCmtAvail;
		public boolean TxfFedCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmConDetail");

			String itemtag = "StatitemShrWznmConDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfTagValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfTagValid", mask, TXFTAGVALID);
				TxfOptValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfOptValid", mask, TXFOPTVALID);
				TxfFedVitValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfFedVitValid", mask, TXFFEDVITVALID);
				TxfFedTagValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfFedTagValid", mask, TXFFEDTAGVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupJtiActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupJtiActive", mask, PUPJTIACTIVE);
				ButJtiEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJtiEditAvail", mask, BUTJTIEDITAVAIL);
				TxtTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTitActive", mask, TXTTITACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				LstCluActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluActive", mask, LSTCLUACTIVE);
				ButCluViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluViewActive", mask, BUTCLUVIEWACTIVE);
				ButCluClusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", mask, BUTCLUCLUSTERAVAIL);
				ButCluUnclusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", mask, BUTCLUUNCLUSTERAVAIL);
				TxtHkuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtHkuActive", mask, TXTHKUACTIVE);
				ButHkuViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButHkuViewAvail", mask, BUTHKUVIEWAVAIL);
				ButHkuViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButHkuViewActive", mask, BUTHKUVIEWACTIVE);
				TxtReuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtReuActive", mask, TXTREUACTIVE);
				ButReuViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", mask, BUTREUVIEWAVAIL);
				ButReuViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewActive", mask, BUTREUVIEWACTIVE);
				TxtSupActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSupActive", mask, TXTSUPACTIVE);
				ButSupViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", mask, BUTSUPVIEWAVAIL);
				ButSupViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewActive", mask, BUTSUPVIEWACTIVE);
				PupScoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupScoActive", mask, PUPSCOACTIVE);
				PupStyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupStyActive", mask, PUPSTYACTIVE);
				LstTagActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTagActive", mask, LSTTAGACTIVE);
				ButTagViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTagViewAvail", mask, BUTTAGVIEWAVAIL);
				ButTagViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTagViewActive", mask, BUTTAGVIEWACTIVE);
				TxtStsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtStsActive", mask, TXTSTSACTIVE);
				ButStsViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStsViewAvail", mask, BUTSTSVIEWAVAIL);
				ButStsViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStsViewActive", mask, BUTSTSVIEWACTIVE);
				TxtShsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtShsActive", mask, TXTSHSACTIVE);
				ButShsViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButShsViewAvail", mask, BUTSHSVIEWAVAIL);
				ButShsViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButShsViewActive", mask, BUTSHSVIEWACTIVE);
				TxfAvlActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfAvlActive", mask, TXFAVLACTIVE);
				TxfActActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfActActive", mask, TXFACTACTIVE);
				LstOptActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptActive", mask, LSTOPTACTIVE);
				ButOptEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButOptEditAvail", mask, BUTOPTEDITAVAIL);
				SepFedAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SepFedAvail", mask, SEPFEDAVAIL);
				HdgFedAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "HdgFedAvail", mask, HDGFEDAVAIL);
				ButFedNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFedNewAvail", mask, BUTFEDNEWAVAIL);
				ButFedDeleteAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFedDeleteAvail", mask, BUTFEDDELETEAVAIL);
				TxtFedSrfAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtFedSrfAvail", mask, TXTFEDSRFAVAIL);
				TxtFedSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtFedSrfActive", mask, TXTFEDSRFACTIVE);
				TxtFedSruAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtFedSruAvail", mask, TXTFEDSRUAVAIL);
				TxtFedSruActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtFedSruActive", mask, TXTFEDSRUACTIVE);
				ButFedSruViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFedSruViewAvail", mask, BUTFEDSRUVIEWAVAIL);
				ButFedSruViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFedSruViewActive", mask, BUTFEDSRUVIEWACTIVE);
				LstFedVitAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFedVitAvail", mask, LSTFEDVITAVAIL);
				LstFedVitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFedVitActive", mask, LSTFEDVITACTIVE);
				ButFedVitViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFedVitViewAvail", mask, BUTFEDVITVIEWAVAIL);
				ButFedVitViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFedVitViewActive", mask, BUTFEDVITVIEWACTIVE);
				LstFedTagAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFedTagAvail", mask, LSTFEDTAGAVAIL);
				LstFedTagActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFedTagActive", mask, LSTFEDTAGACTIVE);
				ButFedTagViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFedTagViewAvail", mask, BUTFEDTAGVIEWAVAIL);
				ButFedTagViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFedTagViewActive", mask, BUTFEDTAGVIEWACTIVE);
				TxfFedCmtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfFedCmtAvail", mask, TXFFEDCMTAVAIL);
				TxfFedCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfFedCmtActive", mask, TXFFEDCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfTagValid == comp.TxfTagValid) items.add(TXFTAGVALID);
			if (TxfOptValid == comp.TxfOptValid) items.add(TXFOPTVALID);
			if (TxfFedVitValid == comp.TxfFedVitValid) items.add(TXFFEDVITVALID);
			if (TxfFedTagValid == comp.TxfFedTagValid) items.add(TXFFEDTAGVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (PupJtiActive == comp.PupJtiActive) items.add(PUPJTIACTIVE);
			if (ButJtiEditAvail == comp.ButJtiEditAvail) items.add(BUTJTIEDITAVAIL);
			if (TxtTitActive == comp.TxtTitActive) items.add(TXTTITACTIVE);
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (LstCluActive == comp.LstCluActive) items.add(LSTCLUACTIVE);
			if (ButCluViewActive == comp.ButCluViewActive) items.add(BUTCLUVIEWACTIVE);
			if (ButCluClusterAvail == comp.ButCluClusterAvail) items.add(BUTCLUCLUSTERAVAIL);
			if (ButCluUnclusterAvail == comp.ButCluUnclusterAvail) items.add(BUTCLUUNCLUSTERAVAIL);
			if (TxtHkuActive == comp.TxtHkuActive) items.add(TXTHKUACTIVE);
			if (ButHkuViewAvail == comp.ButHkuViewAvail) items.add(BUTHKUVIEWAVAIL);
			if (ButHkuViewActive == comp.ButHkuViewActive) items.add(BUTHKUVIEWACTIVE);
			if (TxtReuActive == comp.TxtReuActive) items.add(TXTREUACTIVE);
			if (ButReuViewAvail == comp.ButReuViewAvail) items.add(BUTREUVIEWAVAIL);
			if (ButReuViewActive == comp.ButReuViewActive) items.add(BUTREUVIEWACTIVE);
			if (TxtSupActive == comp.TxtSupActive) items.add(TXTSUPACTIVE);
			if (ButSupViewAvail == comp.ButSupViewAvail) items.add(BUTSUPVIEWAVAIL);
			if (ButSupViewActive == comp.ButSupViewActive) items.add(BUTSUPVIEWACTIVE);
			if (PupScoActive == comp.PupScoActive) items.add(PUPSCOACTIVE);
			if (PupStyActive == comp.PupStyActive) items.add(PUPSTYACTIVE);
			if (LstTagActive == comp.LstTagActive) items.add(LSTTAGACTIVE);
			if (ButTagViewAvail == comp.ButTagViewAvail) items.add(BUTTAGVIEWAVAIL);
			if (ButTagViewActive == comp.ButTagViewActive) items.add(BUTTAGVIEWACTIVE);
			if (TxtStsActive == comp.TxtStsActive) items.add(TXTSTSACTIVE);
			if (ButStsViewAvail == comp.ButStsViewAvail) items.add(BUTSTSVIEWAVAIL);
			if (ButStsViewActive == comp.ButStsViewActive) items.add(BUTSTSVIEWACTIVE);
			if (TxtShsActive == comp.TxtShsActive) items.add(TXTSHSACTIVE);
			if (ButShsViewAvail == comp.ButShsViewAvail) items.add(BUTSHSVIEWAVAIL);
			if (ButShsViewActive == comp.ButShsViewActive) items.add(BUTSHSVIEWACTIVE);
			if (TxfAvlActive == comp.TxfAvlActive) items.add(TXFAVLACTIVE);
			if (TxfActActive == comp.TxfActActive) items.add(TXFACTACTIVE);
			if (LstOptActive == comp.LstOptActive) items.add(LSTOPTACTIVE);
			if (ButOptEditAvail == comp.ButOptEditAvail) items.add(BUTOPTEDITAVAIL);
			if (SepFedAvail == comp.SepFedAvail) items.add(SEPFEDAVAIL);
			if (HdgFedAvail == comp.HdgFedAvail) items.add(HDGFEDAVAIL);
			if (ButFedNewAvail == comp.ButFedNewAvail) items.add(BUTFEDNEWAVAIL);
			if (ButFedDeleteAvail == comp.ButFedDeleteAvail) items.add(BUTFEDDELETEAVAIL);
			if (TxtFedSrfAvail == comp.TxtFedSrfAvail) items.add(TXTFEDSRFAVAIL);
			if (TxtFedSrfActive == comp.TxtFedSrfActive) items.add(TXTFEDSRFACTIVE);
			if (TxtFedSruAvail == comp.TxtFedSruAvail) items.add(TXTFEDSRUAVAIL);
			if (TxtFedSruActive == comp.TxtFedSruActive) items.add(TXTFEDSRUACTIVE);
			if (ButFedSruViewAvail == comp.ButFedSruViewAvail) items.add(BUTFEDSRUVIEWAVAIL);
			if (ButFedSruViewActive == comp.ButFedSruViewActive) items.add(BUTFEDSRUVIEWACTIVE);
			if (LstFedVitAvail == comp.LstFedVitAvail) items.add(LSTFEDVITAVAIL);
			if (LstFedVitActive == comp.LstFedVitActive) items.add(LSTFEDVITACTIVE);
			if (ButFedVitViewAvail == comp.ButFedVitViewAvail) items.add(BUTFEDVITVIEWAVAIL);
			if (ButFedVitViewActive == comp.ButFedVitViewActive) items.add(BUTFEDVITVIEWACTIVE);
			if (LstFedTagAvail == comp.LstFedTagAvail) items.add(LSTFEDTAGAVAIL);
			if (LstFedTagActive == comp.LstFedTagActive) items.add(LSTFEDTAGACTIVE);
			if (ButFedTagViewAvail == comp.ButFedTagViewAvail) items.add(BUTFEDTAGVIEWAVAIL);
			if (ButFedTagViewActive == comp.ButFedTagViewActive) items.add(BUTFEDTAGVIEWACTIVE);
			if (TxfFedCmtAvail == comp.TxfFedCmtAvail) items.add(TXFFEDCMTAVAIL);
			if (TxfFedCmtActive == comp.TxfFedCmtActive) items.add(TXFFEDCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFTAGVALID, TXFOPTVALID, TXFFEDVITVALID, TXFFEDTAGVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPJTIACTIVE, BUTJTIEDITAVAIL, TXTTITACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, PUPSCOACTIVE, PUPSTYACTIVE, LSTTAGACTIVE, BUTTAGVIEWAVAIL, BUTTAGVIEWACTIVE, TXTSTSACTIVE, BUTSTSVIEWAVAIL, BUTSTSVIEWACTIVE, TXTSHSACTIVE, BUTSHSVIEWAVAIL, BUTSHSVIEWACTIVE, TXFAVLACTIVE, TXFACTACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, SEPFEDAVAIL, HDGFEDAVAIL, BUTFEDNEWAVAIL, BUTFEDDELETEAVAIL, TXTFEDSRFAVAIL, TXTFEDSRFACTIVE, TXTFEDSRUAVAIL, TXTFEDSRUACTIVE, BUTFEDSRUVIEWAVAIL, BUTFEDSRUVIEWACTIVE, LSTFEDVITAVAIL, LSTFEDVITACTIVE, BUTFEDVITVIEWAVAIL, BUTFEDVITVIEWACTIVE, LSTFEDTAGAVAIL, LSTFEDTAGACTIVE, BUTFEDTAGVIEWAVAIL, BUTFEDTAGVIEWACTIVE, TXFFEDCMTAVAIL, TXFFEDCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmConDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTIT = 3;
		public static final int CPTTYP = 4;
		public static final int CPTCLU = 5;
		public static final int CPTHKU = 6;
		public static final int CPTREU = 7;
		public static final int CPTSUP = 8;
		public static final int CPTSCO = 9;
		public static final int CPTSTY = 10;
		public static final int CPTTAG = 11;
		public static final int CPTSTS = 12;
		public static final int CPTSHS = 13;
		public static final int CPTAVL = 14;
		public static final int CPTACT = 15;
		public static final int CPTOPT = 16;
		public static final int HDGFED = 17;
		public static final int CPTFEDSRF = 18;
		public static final int CPTFEDSRU = 19;
		public static final int CPTFEDVIT = 20;
		public static final int CPTFEDTAG = 21;
		public static final int CPTFEDCMT = 22;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTit
					, String CptTyp
					, String CptClu
					, String CptHku
					, String CptReu
					, String CptSup
					, String CptSco
					, String CptSty
					, String CptTag
					, String CptSts
					, String CptShs
					, String CptAvl
					, String CptAct
					, String CptOpt
					, String HdgFed
					, String CptFedSrf
					, String CptFedSru
					, String CptFedVit
					, String CptFedTag
					, String CptFedCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTit = CptTit;
			this.CptTyp = CptTyp;
			this.CptClu = CptClu;
			this.CptHku = CptHku;
			this.CptReu = CptReu;
			this.CptSup = CptSup;
			this.CptSco = CptSco;
			this.CptSty = CptSty;
			this.CptTag = CptTag;
			this.CptSts = CptSts;
			this.CptShs = CptShs;
			this.CptAvl = CptAvl;
			this.CptAct = CptAct;
			this.CptOpt = CptOpt;
			this.HdgFed = HdgFed;
			this.CptFedSrf = CptFedSrf;
			this.CptFedSru = CptFedSru;
			this.CptFedVit = CptFedVit;
			this.CptFedTag = CptFedTag;
			this.CptFedCmt = CptFedCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTTYP, CPTCLU, CPTHKU, CPTREU, CPTSUP, CPTSCO, CPTSTY, CPTTAG, CPTSTS, CPTSHS, CPTAVL, CPTACT, CPTOPT, HDGFED, CPTFEDSRF, CPTFEDSRU, CPTFEDVIT, CPTFEDTAG, CPTFEDCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTit;
		public String CptTyp;
		public String CptClu;
		public String CptHku;
		public String CptReu;
		public String CptSup;
		public String CptSco;
		public String CptSty;
		public String CptTag;
		public String CptSts;
		public String CptShs;
		public String CptAvl;
		public String CptAct;
		public String CptOpt;
		public String HdgFed;
		public String CptFedSrf;
		public String CptFedSru;
		public String CptFedVit;
		public String CptFedTag;
		public String CptFedCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmConDetail");

			String itemtag = "TagitemWznmConDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTit", mask, CPTTIT);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptClu", mask, CPTCLU);
				CptHku = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptHku", mask, CPTHKU);
				CptReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptReu", mask, CPTREU);
				CptSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSup", mask, CPTSUP);
				CptSco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSco", mask, CPTSCO);
				CptSty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSty", mask, CPTSTY);
				CptTag = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTag", mask, CPTTAG);
				CptSts = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSts", mask, CPTSTS);
				CptShs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptShs", mask, CPTSHS);
				CptAvl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAvl", mask, CPTAVL);
				CptAct = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAct", mask, CPTACT);
				CptOpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOpt", mask, CPTOPT);
				HdgFed = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgFed", mask, HDGFED);
				CptFedSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFedSrf", mask, CPTFEDSRF);
				CptFedSru = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFedSru", mask, CPTFEDSRU);
				CptFedVit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFedVit", mask, CPTFEDVIT);
				CptFedTag = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFedTag", mask, CPTFEDTAG);
				CptFedCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFedCmt", mask, CPTFEDCMT);

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
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptClu.equals(comp.CptClu)) items.add(CPTCLU);
			if (CptHku.equals(comp.CptHku)) items.add(CPTHKU);
			if (CptReu.equals(comp.CptReu)) items.add(CPTREU);
			if (CptSup.equals(comp.CptSup)) items.add(CPTSUP);
			if (CptSco.equals(comp.CptSco)) items.add(CPTSCO);
			if (CptSty.equals(comp.CptSty)) items.add(CPTSTY);
			if (CptTag.equals(comp.CptTag)) items.add(CPTTAG);
			if (CptSts.equals(comp.CptSts)) items.add(CPTSTS);
			if (CptShs.equals(comp.CptShs)) items.add(CPTSHS);
			if (CptAvl.equals(comp.CptAvl)) items.add(CPTAVL);
			if (CptAct.equals(comp.CptAct)) items.add(CPTACT);
			if (CptOpt.equals(comp.CptOpt)) items.add(CPTOPT);
			if (HdgFed.equals(comp.HdgFed)) items.add(HDGFED);
			if (CptFedSrf.equals(comp.CptFedSrf)) items.add(CPTFEDSRF);
			if (CptFedSru.equals(comp.CptFedSru)) items.add(CPTFEDSRU);
			if (CptFedVit.equals(comp.CptFedVit)) items.add(CPTFEDVIT);
			if (CptFedTag.equals(comp.CptFedTag)) items.add(CPTFEDTAG);
			if (CptFedCmt.equals(comp.CptFedCmt)) items.add(CPTFEDCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTTYP, CPTCLU, CPTHKU, CPTREU, CPTSUP, CPTSCO, CPTSTY, CPTTAG, CPTSTS, CPTSHS, CPTAVL, CPTACT, CPTOPT, HDGFED, CPTFEDSRF, CPTFEDSRU, CPTFEDVIT, CPTFEDTAG, CPTFEDCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmConDetailData)
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
			super(VecWznmVDpch.DPCHAPPWZNMCONDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmConDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmConDetailDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMCONDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmConDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmConDetailData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTCLU = 4;
		public static final int FEEDFLSTFEDTAG = 5;
		public static final int FEEDFLSTFEDVIT = 6;
		public static final int FEEDFLSTOPT = 7;
		public static final int FEEDFLSTTAG = 8;
		public static final int FEEDFPUPFEDSRT = 9;
		public static final int FEEDFPUPHKT = 10;
		public static final int FEEDFPUPJTI = 11;
		public static final int FEEDFPUPRET = 12;
		public static final int FEEDFPUPSCO = 13;
		public static final int FEEDFPUPSTY = 14;
		public static final int FEEDFPUPTYP = 15;
		public static final int STATAPP = 16;
		public static final int STATSHR = 17;
		public static final int TAG = 18;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMCONDETAILDATA);

			contiac = new ContIac(0, 0, 0, 0, 0, 0, 0, 0, "", "", "", new ArrayList<Integer>(), "", 0, 0, "", 0, "", "");
			continf = new ContInf("", "", "", "", "", "", "", "", "", "");
			feedFLstClu = new Feed("FeedFLstClu");
			feedFLstFedTag = new Feed("FeedFLstFedTag");
			feedFLstFedVit = new Feed("FeedFLstFedVit");
			feedFLstOpt = new Feed("FeedFLstOpt");
			feedFLstTag = new Feed("FeedFLstTag");
			feedFPupFedSrt = new Feed("FeedFPupFedSrt");
			feedFPupHkt = new Feed("FeedFPupHkt");
			feedFPupJti = new Feed("FeedFPupJti");
			feedFPupRet = new Feed("FeedFPupRet");
			feedFPupSco = new Feed("FeedFPupSco");
			feedFPupSty = new Feed("FeedFPupSty");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0, false, false, false, false, false, 0, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstClu;
		public Feed feedFLstFedTag;
		public Feed feedFLstFedVit;
		public Feed feedFLstOpt;
		public Feed feedFLstTag;
		public Feed feedFPupFedSrt;
		public Feed feedFPupHkt;
		public Feed feedFPupJti;
		public Feed feedFPupRet;
		public Feed feedFPupSco;
		public Feed feedFPupSty;
		public Feed feedFPupTyp;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTCLU)) ss.add("feedFLstClu");
			if (has(FEEDFLSTFEDTAG)) ss.add("feedFLstFedTag");
			if (has(FEEDFLSTFEDVIT)) ss.add("feedFLstFedVit");
			if (has(FEEDFLSTOPT)) ss.add("feedFLstOpt");
			if (has(FEEDFLSTTAG)) ss.add("feedFLstTag");
			if (has(FEEDFPUPFEDSRT)) ss.add("feedFPupFedSrt");
			if (has(FEEDFPUPHKT)) ss.add("feedFPupHkt");
			if (has(FEEDFPUPJTI)) ss.add("feedFPupJti");
			if (has(FEEDFPUPRET)) ss.add("feedFPupRet");
			if (has(FEEDFPUPSCO)) ss.add("feedFPupSco");
			if (has(FEEDFPUPSTY)) ss.add("feedFPupSty");
			if (has(FEEDFPUPTYP)) ss.add("feedFPupTyp");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmConDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstClu.readXML(doc, basexpath, true)) add(FEEDFLSTCLU);
				if (feedFLstFedTag.readXML(doc, basexpath, true)) add(FEEDFLSTFEDTAG);
				if (feedFLstFedVit.readXML(doc, basexpath, true)) add(FEEDFLSTFEDVIT);
				if (feedFLstOpt.readXML(doc, basexpath, true)) add(FEEDFLSTOPT);
				if (feedFLstTag.readXML(doc, basexpath, true)) add(FEEDFLSTTAG);
				if (feedFPupFedSrt.readXML(doc, basexpath, true)) add(FEEDFPUPFEDSRT);
				if (feedFPupHkt.readXML(doc, basexpath, true)) add(FEEDFPUPHKT);
				if (feedFPupJti.readXML(doc, basexpath, true)) add(FEEDFPUPJTI);
				if (feedFPupRet.readXML(doc, basexpath, true)) add(FEEDFPUPRET);
				if (feedFPupSco.readXML(doc, basexpath, true)) add(FEEDFPUPSCO);
				if (feedFPupSty.readXML(doc, basexpath, true)) add(FEEDFPUPSTY);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0, 0, 0, 0, 0, "", "", "", new ArrayList<Integer>(), "", 0, 0, "", 0, "", "");
				continf = new ContInf("", "", "", "", "", "", "", "", "", "");
				feedFLstClu = new Feed("FeedFLstClu");
				feedFLstFedTag = new Feed("FeedFLstFedTag");
				feedFLstFedVit = new Feed("FeedFLstFedVit");
				feedFLstOpt = new Feed("FeedFLstOpt");
				feedFLstTag = new Feed("FeedFLstTag");
				feedFPupFedSrt = new Feed("FeedFPupFedSrt");
				feedFPupHkt = new Feed("FeedFPupHkt");
				feedFPupJti = new Feed("FeedFPupJti");
				feedFPupRet = new Feed("FeedFPupRet");
				feedFPupSco = new Feed("FeedFPupSco");
				feedFPupSty = new Feed("FeedFPupSty");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0, false, false, false, false, false, 0, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

