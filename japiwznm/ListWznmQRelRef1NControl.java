/**
  * \file ListWznmQRelRef1NControl.java
  * Java API code for record set of table TblWznmQRelRef1NControl
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWznmQRelRef1NControl {

	public ListWznmQRelRef1NControl() {
		nodes = new ArrayList<WznmQRelRef1NControl>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WznmQRelRef1NControl> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WznmQRelRef1NControl rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWznmQRelRef1NControl");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WznmQRelRef1NControl", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WznmQRelRef1NControl(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WznmQRelRef1NControl[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};
