/**
	* \file WznmQLocList.h
	* Java API code for record of table TblWznmQLocList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQLocList {
	
	public WznmQLocList(
				int jnum
				, String sref
				, String Title
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
	};

	public int jnum;
	public String sref;
	public String Title;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQLocList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			
			return true;
		};

		return false;
	};
};
