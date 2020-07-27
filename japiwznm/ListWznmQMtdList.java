/**
  * \file ListWznmQMtdList.java
  * Java API code for record set of table TblWznmQMtdList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWznmQMtdList {

	public ListWznmQMtdList() {
		nodes = new ArrayList<WznmQMtdList>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WznmQMtdList> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WznmQMtdList rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWznmQMtdList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WznmQMtdList", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WznmQMtdList(i+1, "", "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WznmQMtdList[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};
