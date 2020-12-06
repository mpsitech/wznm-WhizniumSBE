/**
	* \file WznmQQryAOrder.h
	* Java API code for record of table TblWznmQQryAOrder
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQQryAOrder {
	
	public WznmQQryAOrder(
				int jnum
				, String Short
				, String srefsWznmMTablecol
			) {
		this.jnum = jnum;
		this.Short = Short;
		this.srefsWznmMTablecol = srefsWznmMTablecol;
	};

	public int jnum;
	public String Short;
	public String srefsWznmMTablecol;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQQryAOrder");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Short = Xmlio.extractStringUclc(doc, basexpath, "Short", "sho", null, 0);
			srefsWznmMTablecol = Xmlio.extractStringUclc(doc, basexpath, "srefsWznmMTablecol", "tco", null, 0);
			
			return true;
		};

		return false;
	};
};
