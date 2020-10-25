/**
  * \file WznmQVecMNTable.h
  * Java API code for record of table TblWznmQVecMNTable
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQVecMNTable {
	
	public WznmQVecMNTable(
				int jnum
				, String stubMref
				, String stubRefWznmMSubset
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
		this.stubRefWznmMSubset = stubRefWznmMSubset;
	};

	public int jnum;
	public String stubMref;
	public String stubRefWznmMSubset;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQVecMNTable");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			stubRefWznmMSubset = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMSubset", "sbs", null, 0);
			
			return true;
		};

		return false;
	};
};

