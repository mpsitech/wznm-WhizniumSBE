/**
	* \file WznmQRlsList.h
	* Java API code for record of table TblWznmQRlsList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQRlsList {
	
	public WznmQRlsList(
				int jnum
				, String sref
				, String stubRefWznmMComponent
				, String stubRefWznmMMachine
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubRefWznmMComponent = stubRefWznmMComponent;
		this.stubRefWznmMMachine = stubRefWznmMMachine;
	};

	public int jnum;
	public String sref;
	public String stubRefWznmMComponent;
	public String stubRefWznmMMachine;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQRlsList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWznmMComponent = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMComponent", "cmp", null, 0);
			stubRefWznmMMachine = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMMachine", "mch", null, 0);
			
			return true;
		};

		return false;
	};
};
