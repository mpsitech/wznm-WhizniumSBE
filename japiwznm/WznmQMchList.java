/**
	* \file WznmQMchList.h
	* Java API code for record of table TblWznmQMchList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQMchList {
	
	public WznmQMchList(
				int jnum
				, String sref
				, String stubSupRefWznmMMachine
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubSupRefWznmMMachine = stubSupRefWznmMMachine;
	};

	public int jnum;
	public String sref;
	public String stubSupRefWznmMMachine;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQMchList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubSupRefWznmMMachine = Xmlio.extractStringUclc(doc, basexpath, "stubSupRefWznmMMachine", "sup", null, 0);
			
			return true;
		};

		return false;
	};
};

