/**
  * \file ListWznmQImeIme1NImpexpcol.java
  * Java API code for record set of table TblWznmQImeIme1NImpexpcol
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWznmQImeIme1NImpexpcol {

	public ListWznmQImeIme1NImpexpcol() {
		nodes = new ArrayList<WznmQImeIme1NImpexpcol>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WznmQImeIme1NImpexpcol> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WznmQImeIme1NImpexpcol rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWznmQImeIme1NImpexpcol");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WznmQImeIme1NImpexpcol", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WznmQImeIme1NImpexpcol(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WznmQImeIme1NImpexpcol[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

