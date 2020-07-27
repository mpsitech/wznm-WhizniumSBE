/**
  * \file ListWznmQLocList.java
  * Java API code for record set of table TblWznmQLocList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWznmQLocList {

	public ListWznmQLocList() {
		nodes = new ArrayList<WznmQLocList>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WznmQLocList> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WznmQLocList rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWznmQLocList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WznmQLocList", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WznmQLocList(i+1, "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WznmQLocList[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};
