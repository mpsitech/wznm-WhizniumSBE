/**
	* \file WznmQShtList.java
	* Java API code for record of table TblWznmQShtList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQShtList {
	
	public WznmQShtList(
				int jnum
				, String Title
				, String stubVisRefWznmMVisual
			) {
		this.jnum = jnum;
		this.Title = Title;
		this.stubVisRefWznmMVisual = stubVisRefWznmMVisual;
	};

	public int jnum;
	public String Title;
	public String stubVisRefWznmMVisual;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQShtList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubVisRefWznmMVisual = Xmlio.extractStringUclc(doc, basexpath, "stubVisRefWznmMVisual", "vis", null, 0);
			
			return true;
		};

		return false;
	};
};
