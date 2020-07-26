/**
  * \file ListWznmQSbsBsbMNSubset.java
  * Java API code for record set of table TblWznmQSbsBsbMNSubset
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWznmQSbsBsbMNSubset {

	public ListWznmQSbsBsbMNSubset() {
		nodes = new ArrayList<WznmQSbsBsbMNSubset>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WznmQSbsBsbMNSubset> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WznmQSbsBsbMNSubset rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWznmQSbsBsbMNSubset");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WznmQSbsBsbMNSubset", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WznmQSbsBsbMNSubset(i+1, "", "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WznmQSbsBsbMNSubset[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

