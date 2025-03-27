/**
  * \file QryWznmVisLinkctx.java
  * Java API code for job QryWznmVisLinkctx
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class QryWznmVisLinkctx {
	/**
	  * StatShr (full: StatShrQryWznmVisLinkctx)
	  */
	public class StatShr extends Block {

		public static final int NTOT = 1;

		public StatShr(
					int ntot
				) {
			this.ntot = ntot;

			mask = new HashSet<Integer>(Arrays.asList(NTOT));
		};

		public int ntot;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrQryWznmVisLinkctx");

			String itemtag = "StatitemShrQryWznmVisLinkctx";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ntot = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ntot", mask, NTOT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ntot == comp.ntot) items.add(NTOT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NTOT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacQryWznmVisLinkctx)
	  */
	public class StgIac extends Block {

		public static final int JNUM = 1;

		public StgIac(
					int jnum
				) {
			this.jnum = jnum;

			mask = new HashSet<Integer>(Arrays.asList(JNUM));
		};

		public int jnum;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacQryWznmVisLinkctx");

			String itemtag = "StgitemIacQryWznmVisLinkctx";

			if (Xmlio.checkXPath(doc, basexpath)) {
				jnum = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "jnum", mask, JNUM);

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
			if (difftag.isEmpty()) difftag = "StgIacQryWznmVisLinkctx";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacQryWznmVisLinkctx";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "jnum", jnum);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (jnum == comp.jnum) items.add(JNUM);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(JNUM));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

};
