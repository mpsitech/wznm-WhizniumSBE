/**
  * \file PnlWznmNavJob.java
  * Java API code for job PnlWznmNavJob
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWznmNavJob {
	/**
		* VecVDo (full: VecVWznmNavJobDo)
		*/
	public static class VecVDo {

		public static final int BUTJOBVIEWCLICK = 1;
		public static final int BUTJOBNEWCRDCLICK = 2;
		public static final int BUTSGEVIEWCLICK = 3;
		public static final int BUTSGENEWCRDCLICK = 4;
		public static final int BUTMTDVIEWCLICK = 5;
		public static final int BUTMTDNEWCRDCLICK = 6;
		public static final int BUTBLKVIEWCLICK = 7;
		public static final int BUTBLKNEWCRDCLICK = 8;
		public static final int BUTCALVIEWCLICK = 9;
		public static final int BUTCALNEWCRDCLICK = 10;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butjobviewclick")) return BUTJOBVIEWCLICK;
			if (s.equals("butjobnewcrdclick")) return BUTJOBNEWCRDCLICK;
			if (s.equals("butsgeviewclick")) return BUTSGEVIEWCLICK;
			if (s.equals("butsgenewcrdclick")) return BUTSGENEWCRDCLICK;
			if (s.equals("butmtdviewclick")) return BUTMTDVIEWCLICK;
			if (s.equals("butmtdnewcrdclick")) return BUTMTDNEWCRDCLICK;
			if (s.equals("butblkviewclick")) return BUTBLKVIEWCLICK;
			if (s.equals("butblknewcrdclick")) return BUTBLKNEWCRDCLICK;
			if (s.equals("butcalviewclick")) return BUTCALVIEWCLICK;
			if (s.equals("butcalnewcrdclick")) return BUTCALNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTJOBVIEWCLICK) return("ButJobViewClick");
			if (ix == BUTJOBNEWCRDCLICK) return("ButJobNewcrdClick");
			if (ix == BUTSGEVIEWCLICK) return("ButSgeViewClick");
			if (ix == BUTSGENEWCRDCLICK) return("ButSgeNewcrdClick");
			if (ix == BUTMTDVIEWCLICK) return("ButMtdViewClick");
			if (ix == BUTMTDNEWCRDCLICK) return("ButMtdNewcrdClick");
			if (ix == BUTBLKVIEWCLICK) return("ButBlkViewClick");
			if (ix == BUTBLKNEWCRDCLICK) return("ButBlkNewcrdClick");
			if (ix == BUTCALVIEWCLICK) return("ButCalViewClick");
			if (ix == BUTCALNEWCRDCLICK) return("ButCalNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWznmNavJob)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTJOB = 1;
		public static final int NUMFLSTSGE = 2;
		public static final int NUMFLSTMTD = 3;
		public static final int NUMFLSTBLK = 4;
		public static final int NUMFLSTCAL = 5;

		public ContIac(
					int numFLstJob
					, int numFLstSge
					, int numFLstMtd
					, int numFLstBlk
					, int numFLstCal
				) {
			this.numFLstJob = numFLstJob;
			this.numFLstSge = numFLstSge;
			this.numFLstMtd = numFLstMtd;
			this.numFLstBlk = numFLstBlk;
			this.numFLstCal = numFLstCal;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTJOB, NUMFLSTSGE, NUMFLSTMTD, NUMFLSTBLK, NUMFLSTCAL));
		};

		public int numFLstJob;
		public int numFLstSge;
		public int numFLstMtd;
		public int numFLstBlk;
		public int numFLstCal;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWznmNavJob");

			String itemtag = "ContitemIacWznmNavJob";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstJob = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstJob", mask, NUMFLSTJOB);
				numFLstSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstSge", mask, NUMFLSTSGE);
				numFLstMtd = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstMtd", mask, NUMFLSTMTD);
				numFLstBlk = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstBlk", mask, NUMFLSTBLK);
				numFLstCal = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstCal", mask, NUMFLSTCAL);

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
			if (difftag.isEmpty()) difftag = "ContIacWznmNavJob";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWznmNavJob";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstJob", numFLstJob);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstSge", numFLstSge);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstMtd", numFLstMtd);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstBlk", numFLstBlk);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstCal", numFLstCal);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstJob == comp.numFLstJob) items.add(NUMFLSTJOB);
			if (numFLstSge == comp.numFLstSge) items.add(NUMFLSTSGE);
			if (numFLstMtd == comp.numFLstMtd) items.add(NUMFLSTMTD);
			if (numFLstBlk == comp.numFLstBlk) items.add(NUMFLSTBLK);
			if (numFLstCal == comp.numFLstCal) items.add(NUMFLSTCAL);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTJOB, NUMFLSTSGE, NUMFLSTMTD, NUMFLSTBLK, NUMFLSTCAL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWznmNavJob)
	  */
	public class StatApp extends Block {

		public static final int IXWZNMVEXPSTATE = 1;
		public static final int LSTJOBALT = 2;
		public static final int LSTSGEALT = 3;
		public static final int LSTMTDALT = 4;
		public static final int LSTBLKALT = 5;
		public static final int LSTCALALT = 6;
		public static final int LSTJOBNUMFIRSTDISP = 7;
		public static final int LSTSGENUMFIRSTDISP = 8;
		public static final int LSTMTDNUMFIRSTDISP = 9;
		public static final int LSTBLKNUMFIRSTDISP = 10;
		public static final int LSTCALNUMFIRSTDISP = 11;

		public StatApp(
					int ixWznmVExpstate
					, boolean LstJobAlt
					, boolean LstSgeAlt
					, boolean LstMtdAlt
					, boolean LstBlkAlt
					, boolean LstCalAlt
					, int LstJobNumFirstdisp
					, int LstSgeNumFirstdisp
					, int LstMtdNumFirstdisp
					, int LstBlkNumFirstdisp
					, int LstCalNumFirstdisp
				) {
			this.ixWznmVExpstate = ixWznmVExpstate;
			this.LstJobAlt = LstJobAlt;
			this.LstSgeAlt = LstSgeAlt;
			this.LstMtdAlt = LstMtdAlt;
			this.LstBlkAlt = LstBlkAlt;
			this.LstCalAlt = LstCalAlt;
			this.LstJobNumFirstdisp = LstJobNumFirstdisp;
			this.LstSgeNumFirstdisp = LstSgeNumFirstdisp;
			this.LstMtdNumFirstdisp = LstMtdNumFirstdisp;
			this.LstBlkNumFirstdisp = LstBlkNumFirstdisp;
			this.LstCalNumFirstdisp = LstCalNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTJOBALT, LSTSGEALT, LSTMTDALT, LSTBLKALT, LSTCALALT, LSTJOBNUMFIRSTDISP, LSTSGENUMFIRSTDISP, LSTMTDNUMFIRSTDISP, LSTBLKNUMFIRSTDISP, LSTCALNUMFIRSTDISP));
		};

		public int ixWznmVExpstate;
		public boolean LstJobAlt;
		public boolean LstSgeAlt;
		public boolean LstMtdAlt;
		public boolean LstBlkAlt;
		public boolean LstCalAlt;
		public int LstJobNumFirstdisp;
		public int LstSgeNumFirstdisp;
		public int LstMtdNumFirstdisp;
		public int LstBlkNumFirstdisp;
		public int LstCalNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWznmVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWznmNavJob");

			String itemtag = "StatitemAppWznmNavJob";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWznmVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWznmVExpstate", mask, IXWZNMVEXPSTATE);
				ixWznmVExpstate = VecWznmVExpstate.getIx(srefIxWznmVExpstate);
				LstJobAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstJobAlt", mask, LSTJOBALT);
				LstSgeAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSgeAlt", mask, LSTSGEALT);
				LstMtdAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMtdAlt", mask, LSTMTDALT);
				LstBlkAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstBlkAlt", mask, LSTBLKALT);
				LstCalAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCalAlt", mask, LSTCALALT);
				LstJobNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstJobNumFirstdisp", mask, LSTJOBNUMFIRSTDISP);
				LstSgeNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSgeNumFirstdisp", mask, LSTSGENUMFIRSTDISP);
				LstMtdNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMtdNumFirstdisp", mask, LSTMTDNUMFIRSTDISP);
				LstBlkNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstBlkNumFirstdisp", mask, LSTBLKNUMFIRSTDISP);
				LstCalNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCalNumFirstdisp", mask, LSTCALNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWznmVExpstate == comp.ixWznmVExpstate) items.add(IXWZNMVEXPSTATE);
			if (LstJobAlt == comp.LstJobAlt) items.add(LSTJOBALT);
			if (LstSgeAlt == comp.LstSgeAlt) items.add(LSTSGEALT);
			if (LstMtdAlt == comp.LstMtdAlt) items.add(LSTMTDALT);
			if (LstBlkAlt == comp.LstBlkAlt) items.add(LSTBLKALT);
			if (LstCalAlt == comp.LstCalAlt) items.add(LSTCALALT);
			if (LstJobNumFirstdisp == comp.LstJobNumFirstdisp) items.add(LSTJOBNUMFIRSTDISP);
			if (LstSgeNumFirstdisp == comp.LstSgeNumFirstdisp) items.add(LSTSGENUMFIRSTDISP);
			if (LstMtdNumFirstdisp == comp.LstMtdNumFirstdisp) items.add(LSTMTDNUMFIRSTDISP);
			if (LstBlkNumFirstdisp == comp.LstBlkNumFirstdisp) items.add(LSTBLKNUMFIRSTDISP);
			if (LstCalNumFirstdisp == comp.LstCalNumFirstdisp) items.add(LSTCALNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWZNMVEXPSTATE, LSTJOBALT, LSTSGEALT, LSTMTDALT, LSTBLKALT, LSTCALALT, LSTJOBNUMFIRSTDISP, LSTSGENUMFIRSTDISP, LSTMTDNUMFIRSTDISP, LSTBLKNUMFIRSTDISP, LSTCALNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWznmNavJob)
	  */
	public class StatShr extends Block {

		public static final int LSTJOBAVAIL = 1;
		public static final int BUTJOBVIEWACTIVE = 2;
		public static final int BUTJOBNEWCRDACTIVE = 3;
		public static final int LSTSGEAVAIL = 4;
		public static final int BUTSGEVIEWACTIVE = 5;
		public static final int BUTSGENEWCRDACTIVE = 6;
		public static final int LSTMTDAVAIL = 7;
		public static final int BUTMTDVIEWACTIVE = 8;
		public static final int BUTMTDNEWCRDACTIVE = 9;
		public static final int LSTBLKAVAIL = 10;
		public static final int BUTBLKVIEWACTIVE = 11;
		public static final int BUTBLKNEWCRDACTIVE = 12;
		public static final int LSTCALAVAIL = 13;
		public static final int BUTCALVIEWACTIVE = 14;
		public static final int BUTCALNEWCRDACTIVE = 15;

		public StatShr(
					boolean LstJobAvail
					, boolean ButJobViewActive
					, boolean ButJobNewcrdActive
					, boolean LstSgeAvail
					, boolean ButSgeViewActive
					, boolean ButSgeNewcrdActive
					, boolean LstMtdAvail
					, boolean ButMtdViewActive
					, boolean ButMtdNewcrdActive
					, boolean LstBlkAvail
					, boolean ButBlkViewActive
					, boolean ButBlkNewcrdActive
					, boolean LstCalAvail
					, boolean ButCalViewActive
					, boolean ButCalNewcrdActive
				) {
			this.LstJobAvail = LstJobAvail;
			this.ButJobViewActive = ButJobViewActive;
			this.ButJobNewcrdActive = ButJobNewcrdActive;
			this.LstSgeAvail = LstSgeAvail;
			this.ButSgeViewActive = ButSgeViewActive;
			this.ButSgeNewcrdActive = ButSgeNewcrdActive;
			this.LstMtdAvail = LstMtdAvail;
			this.ButMtdViewActive = ButMtdViewActive;
			this.ButMtdNewcrdActive = ButMtdNewcrdActive;
			this.LstBlkAvail = LstBlkAvail;
			this.ButBlkViewActive = ButBlkViewActive;
			this.ButBlkNewcrdActive = ButBlkNewcrdActive;
			this.LstCalAvail = LstCalAvail;
			this.ButCalViewActive = ButCalViewActive;
			this.ButCalNewcrdActive = ButCalNewcrdActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTJOBAVAIL, BUTJOBVIEWACTIVE, BUTJOBNEWCRDACTIVE, LSTSGEAVAIL, BUTSGEVIEWACTIVE, BUTSGENEWCRDACTIVE, LSTMTDAVAIL, BUTMTDVIEWACTIVE, BUTMTDNEWCRDACTIVE, LSTBLKAVAIL, BUTBLKVIEWACTIVE, BUTBLKNEWCRDACTIVE, LSTCALAVAIL, BUTCALVIEWACTIVE, BUTCALNEWCRDACTIVE));
		};

		public boolean LstJobAvail;
		public boolean ButJobViewActive;
		public boolean ButJobNewcrdActive;
		public boolean LstSgeAvail;
		public boolean ButSgeViewActive;
		public boolean ButSgeNewcrdActive;
		public boolean LstMtdAvail;
		public boolean ButMtdViewActive;
		public boolean ButMtdNewcrdActive;
		public boolean LstBlkAvail;
		public boolean ButBlkViewActive;
		public boolean ButBlkNewcrdActive;
		public boolean LstCalAvail;
		public boolean ButCalViewActive;
		public boolean ButCalNewcrdActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWznmNavJob");

			String itemtag = "StatitemShrWznmNavJob";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstJobAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstJobAvail", mask, LSTJOBAVAIL);
				ButJobViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJobViewActive", mask, BUTJOBVIEWACTIVE);
				ButJobNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJobNewcrdActive", mask, BUTJOBNEWCRDACTIVE);
				LstSgeAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSgeAvail", mask, LSTSGEAVAIL);
				ButSgeViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSgeViewActive", mask, BUTSGEVIEWACTIVE);
				ButSgeNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSgeNewcrdActive", mask, BUTSGENEWCRDACTIVE);
				LstMtdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMtdAvail", mask, LSTMTDAVAIL);
				ButMtdViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMtdViewActive", mask, BUTMTDVIEWACTIVE);
				ButMtdNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMtdNewcrdActive", mask, BUTMTDNEWCRDACTIVE);
				LstBlkAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstBlkAvail", mask, LSTBLKAVAIL);
				ButBlkViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBlkViewActive", mask, BUTBLKVIEWACTIVE);
				ButBlkNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBlkNewcrdActive", mask, BUTBLKNEWCRDACTIVE);
				LstCalAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCalAvail", mask, LSTCALAVAIL);
				ButCalViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCalViewActive", mask, BUTCALVIEWACTIVE);
				ButCalNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCalNewcrdActive", mask, BUTCALNEWCRDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstJobAvail == comp.LstJobAvail) items.add(LSTJOBAVAIL);
			if (ButJobViewActive == comp.ButJobViewActive) items.add(BUTJOBVIEWACTIVE);
			if (ButJobNewcrdActive == comp.ButJobNewcrdActive) items.add(BUTJOBNEWCRDACTIVE);
			if (LstSgeAvail == comp.LstSgeAvail) items.add(LSTSGEAVAIL);
			if (ButSgeViewActive == comp.ButSgeViewActive) items.add(BUTSGEVIEWACTIVE);
			if (ButSgeNewcrdActive == comp.ButSgeNewcrdActive) items.add(BUTSGENEWCRDACTIVE);
			if (LstMtdAvail == comp.LstMtdAvail) items.add(LSTMTDAVAIL);
			if (ButMtdViewActive == comp.ButMtdViewActive) items.add(BUTMTDVIEWACTIVE);
			if (ButMtdNewcrdActive == comp.ButMtdNewcrdActive) items.add(BUTMTDNEWCRDACTIVE);
			if (LstBlkAvail == comp.LstBlkAvail) items.add(LSTBLKAVAIL);
			if (ButBlkViewActive == comp.ButBlkViewActive) items.add(BUTBLKVIEWACTIVE);
			if (ButBlkNewcrdActive == comp.ButBlkNewcrdActive) items.add(BUTBLKNEWCRDACTIVE);
			if (LstCalAvail == comp.LstCalAvail) items.add(LSTCALAVAIL);
			if (ButCalViewActive == comp.ButCalViewActive) items.add(BUTCALVIEWACTIVE);
			if (ButCalNewcrdActive == comp.ButCalNewcrdActive) items.add(BUTCALNEWCRDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTJOBAVAIL, BUTJOBVIEWACTIVE, BUTJOBNEWCRDACTIVE, LSTSGEAVAIL, BUTSGEVIEWACTIVE, BUTSGENEWCRDACTIVE, LSTMTDAVAIL, BUTMTDVIEWACTIVE, BUTMTDNEWCRDACTIVE, LSTBLKAVAIL, BUTBLKVIEWACTIVE, BUTBLKNEWCRDACTIVE, LSTCALAVAIL, BUTCALVIEWACTIVE, BUTCALNEWCRDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWznmNavJob)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTJOB = 2;
		public static final int CPTSGE = 3;
		public static final int CPTMTD = 4;
		public static final int CPTBLK = 5;
		public static final int CPTCAL = 6;

		public Tag(
					String Cpt
					, String CptJob
					, String CptSge
					, String CptMtd
					, String CptBlk
					, String CptCal
				) {
			this.Cpt = Cpt;
			this.CptJob = CptJob;
			this.CptSge = CptSge;
			this.CptMtd = CptMtd;
			this.CptBlk = CptBlk;
			this.CptCal = CptCal;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTJOB, CPTSGE, CPTMTD, CPTBLK, CPTCAL));
		};

		public String Cpt;
		public String CptJob;
		public String CptSge;
		public String CptMtd;
		public String CptBlk;
		public String CptCal;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWznmNavJob");

			String itemtag = "TagitemWznmNavJob";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptJob = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptJob", mask, CPTJOB);
				CptSge = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSge", mask, CPTSGE);
				CptMtd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMtd", mask, CPTMTD);
				CptBlk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptBlk", mask, CPTBLK);
				CptCal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCal", mask, CPTCAL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptJob.equals(comp.CptJob)) items.add(CPTJOB);
			if (CptSge.equals(comp.CptSge)) items.add(CPTSGE);
			if (CptMtd.equals(comp.CptMtd)) items.add(CPTMTD);
			if (CptBlk.equals(comp.CptBlk)) items.add(CPTBLK);
			if (CptCal.equals(comp.CptCal)) items.add(CPTCAL);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTJOB, CPTSGE, CPTMTD, CPTBLK, CPTCAL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWznmNavJobData)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVJOBDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavJobData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWznmNavJobDo)
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
			super(VecWznmVDpch.DPCHAPPWZNMNAVJOBDO, scrJref);

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
			Element el = doc.createElement("DpchAppWznmNavJobDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWznmNavJobData)
		*/
	public class DpchEngData extends DpchEngWznm {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTBLK = 3;
		public static final int FEEDFLSTCAL = 4;
		public static final int FEEDFLSTJOB = 5;
		public static final int FEEDFLSTMTD = 6;
		public static final int FEEDFLSTSGE = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWznmVDpch.DPCHENGWZNMNAVJOBDATA);

			contiac = new ContIac(0, 0, 0, 0, 0);
			feedFLstBlk = new Feed("FeedFLstBlk");
			feedFLstCal = new Feed("FeedFLstCal");
			feedFLstJob = new Feed("FeedFLstJob");
			feedFLstMtd = new Feed("FeedFLstMtd");
			feedFLstSge = new Feed("FeedFLstSge");
			statapp = new StatApp(0, false, false, false, false, false, 0, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstBlk;
		public Feed feedFLstCal;
		public Feed feedFLstJob;
		public Feed feedFLstMtd;
		public Feed feedFLstSge;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTBLK)) ss.add("feedFLstBlk");
			if (has(FEEDFLSTCAL)) ss.add("feedFLstCal");
			if (has(FEEDFLSTJOB)) ss.add("feedFLstJob");
			if (has(FEEDFLSTMTD)) ss.add("feedFLstMtd");
			if (has(FEEDFLSTSGE)) ss.add("feedFLstSge");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWznmNavJobData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstBlk.readXML(doc, basexpath, true)) add(FEEDFLSTBLK);
				if (feedFLstCal.readXML(doc, basexpath, true)) add(FEEDFLSTCAL);
				if (feedFLstJob.readXML(doc, basexpath, true)) add(FEEDFLSTJOB);
				if (feedFLstMtd.readXML(doc, basexpath, true)) add(FEEDFLSTMTD);
				if (feedFLstSge.readXML(doc, basexpath, true)) add(FEEDFLSTSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0, 0);
				feedFLstBlk = new Feed("FeedFLstBlk");
				feedFLstCal = new Feed("FeedFLstCal");
				feedFLstJob = new Feed("FeedFLstJob");
				feedFLstMtd = new Feed("FeedFLstMtd");
				feedFLstSge = new Feed("FeedFLstSge");
				statapp = new StatApp(0, false, false, false, false, false, 0, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};

