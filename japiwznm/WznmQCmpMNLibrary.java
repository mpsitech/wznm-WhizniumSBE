/**
	* \file WznmQCmpMNLibrary.h
	* Java API code for record of table TblWznmQCmpMNLibrary
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQCmpMNLibrary {
	
	public WznmQCmpMNLibrary(
				int jnum
				, String stubMref
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
	};

	public int jnum;
	public String stubMref;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQCmpMNLibrary");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			
			return true;
		};

		return false;
	};
};
