/**
  * \file QryWznmTblList.java
  * Java API code for job QryWznmTblList
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class QryWznmTblList {
	/**
		* VecVOrd (full: VecVQryWznmTblListOrd)
		*/
	public static class VecVOrd {

		public static final int RET = 1;
		public static final int REU = 2;
		public static final int VER = 3;
		public static final int SRF = 4;
		public static final int TYP = 5;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("ret")) return RET;
			if (s.equals("reu")) return REU;
			if (s.equals("ver")) return VER;
			if (s.equals("srf")) return SRF;
			if (s.equals("typ")) return TYP;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == RET) return("ret");
			if (ix == REU) return("reu");
			if (ix == VER) return("ver");
			if (ix == SRF) return("srf");
			if (ix == TYP) return("typ");

			return "";
		};

	};

	/**
	  * StatApp (full: StatAppQryWznmTblList)
	  */
	public class StatApp extends Block {

		public static final int FIRSTCOL = 1;
		public static final int JNUMFIRSTDISP = 2;
		public static final int NCOL = 3;
		public static final int NDISP = 4;

		public StatApp(
					int firstcol
					, int jnumFirstdisp
					, int ncol
					, int ndisp
				) {
			this.firstcol = firstcol;
			this.jnumFirstdisp = jnumFirstdisp;
			this.ncol = ncol;
			this.ndisp = ndisp;

			mask = new HashSet<Integer>(Arrays.asList(FIRSTCOL, JNUMFIRSTDISP, NCOL, NDISP));
		};

		public int firstcol;
		public int jnumFirstdisp;
		public int ncol;
		public int ndisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppQryWznmTblList");

			String itemtag = "StatitemAppQryWznmTblList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				firstcol = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "firstcol", mask, FIRSTCOL);
				jnumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "jnumFirstdisp", mask, JNUMFIRSTDISP);
				ncol = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ncol", mask, NCOL);
				ndisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ndisp", mask, NDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (firstcol == comp.firstcol) items.add(FIRSTCOL);
			if (jnumFirstdisp == comp.jnumFirstdisp) items.add(JNUMFIRSTDISP);
			if (ncol == comp.ncol) items.add(NCOL);
			if (ndisp == comp.ndisp) items.add(NDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(FIRSTCOL, JNUMFIRSTDISP, NCOL, NDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrQryWznmTblList)
	  */
	public class StatShr extends Block {

		public static final int NTOT = 1;
		public static final int JNUMFIRSTLOAD = 2;
		public static final int NLOAD = 3;

		public StatShr(
					int ntot
					, int jnumFirstload
					, int nload
				) {
			this.ntot = ntot;
			this.jnumFirstload = jnumFirstload;
			this.nload = nload;

			mask = new HashSet<Integer>(Arrays.asList(NTOT, JNUMFIRSTLOAD, NLOAD));
		};

		public int ntot;
		public int jnumFirstload;
		public int nload;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrQryWznmTblList");

			String itemtag = "StatitemShrQryWznmTblList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ntot = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ntot", mask, NTOT);
				jnumFirstload = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "jnumFirstload", mask, JNUMFIRSTLOAD);
				nload = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "nload", mask, NLOAD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ntot == comp.ntot) items.add(NTOT);
			if (jnumFirstload == comp.jnumFirstload) items.add(JNUMFIRSTLOAD);
			if (nload == comp.nload) items.add(NLOAD);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NTOT, JNUMFIRSTLOAD, NLOAD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacQryWznmTblList)
	  */
	public class StgIac extends Block {

		public static final int JNUM = 1;
		public static final int JNUMFIRSTLOAD = 2;
		public static final int NLOAD = 3;

		public StgIac(
					int jnum
					, int jnumFirstload
					, int nload
				) {
			this.jnum = jnum;
			this.jnumFirstload = jnumFirstload;
			this.nload = nload;

			mask = new HashSet<Integer>(Arrays.asList(JNUM, JNUMFIRSTLOAD, NLOAD));
		};

		public int jnum;
		public int jnumFirstload;
		public int nload;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacQryWznmTblList");

			String itemtag = "StgitemIacQryWznmTblList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				jnum = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "jnum", mask, JNUM);
				jnumFirstload = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "jnumFirstload", mask, JNUMFIRSTLOAD);
				nload = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "nload", mask, NLOAD);

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
			if (difftag.isEmpty()) difftag = "StgIacQryWznmTblList";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacQryWznmTblList";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "jnum", jnum);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "jnumFirstload", jnumFirstload);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "nload", nload);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (jnum == comp.jnum) items.add(JNUM);
			if (jnumFirstload == comp.jnumFirstload) items.add(JNUMFIRSTLOAD);
			if (nload == comp.nload) items.add(NLOAD);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(JNUM, JNUMFIRSTLOAD, NLOAD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

};

