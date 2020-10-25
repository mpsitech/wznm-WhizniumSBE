/**
  * \file ListWznmQUsrAAccess.java
  * Java API code for record set of table TblWznmQUsrAAccess
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWznmQUsrAAccess {

	public ListWznmQUsrAAccess() {
		nodes = new ArrayList<WznmQUsrAAccess>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WznmQUsrAAccess> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WznmQUsrAAccess rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWznmQUsrAAccess");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WznmQUsrAAccess", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WznmQUsrAAccess(i+1, "", "", "", "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WznmQUsrAAccess[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

