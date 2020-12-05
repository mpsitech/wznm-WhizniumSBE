/**
	* \file ListWznmQJobJob1NStage.java
	* Java API code for record set of table TblWznmQJobJob1NStage
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwznm;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWznmQJobJob1NStage {

	public ListWznmQJobJob1NStage() {
		nodes = new ArrayList<WznmQJobJob1NStage>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WznmQJobJob1NStage> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WznmQJobJob1NStage rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWznmQJobJob1NStage");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WznmQJobJob1NStage", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WznmQJobJob1NStage(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WznmQJobJob1NStage[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

