/**
  * \file ListWznmQConFedRef1NRtblock.java
  * Java API code for record set of table TblWznmQConFedRef1NRtblock
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWznmQConFedRef1NRtblock {

	public ListWznmQConFedRef1NRtblock() {
		nodes = new ArrayList<WznmQConFedRef1NRtblock>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WznmQConFedRef1NRtblock> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WznmQConFedRef1NRtblock rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWznmQConFedRef1NRtblock");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WznmQConFedRef1NRtblock", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WznmQConFedRef1NRtblock(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WznmQConFedRef1NRtblock[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

