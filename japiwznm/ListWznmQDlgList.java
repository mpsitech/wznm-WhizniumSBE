/**
	* \file ListWznmQDlgList.java
	* Java API code for record set of table TblWznmQDlgList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWznmQDlgList {

	public ListWznmQDlgList() {
		nodes = new ArrayList<WznmQDlgList>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WznmQDlgList> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WznmQDlgList rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWznmQDlgList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WznmQDlgList", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WznmQDlgList(i+1, "", "", "", "", "", "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WznmQDlgList[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};
