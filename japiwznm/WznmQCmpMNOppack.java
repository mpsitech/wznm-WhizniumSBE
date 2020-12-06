/**
	* \file WznmQCmpMNOppack.h
	* Java API code for record of table TblWznmQCmpMNOppack
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQCmpMNOppack {
	
	public WznmQCmpMNOppack(
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
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQCmpMNOppack");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			
			return true;
		};

		return false;
	};
};
