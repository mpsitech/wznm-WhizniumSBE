/**
	* \file WznmQLibAPkglist.h
	* Java API code for record of table TblWznmQLibAPkglist
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQLibAPkglist {
	
	public WznmQLibAPkglist(
				int jnum
				, String stubX1RefWznmMMachine
				, String Pkglist
			) {
		this.jnum = jnum;
		this.stubX1RefWznmMMachine = stubX1RefWznmMMachine;
		this.Pkglist = Pkglist;
	};

	public int jnum;
	public String stubX1RefWznmMMachine;
	public String Pkglist;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQLibAPkglist");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubX1RefWznmMMachine = Xmlio.extractStringUclc(doc, basexpath, "stubX1RefWznmMMachine", "mch", null, 0);
			Pkglist = Xmlio.extractStringUclc(doc, basexpath, "Pkglist", "pkl", null, 0);
			
			return true;
		};

		return false;
	};
};

