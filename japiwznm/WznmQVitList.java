/**
	* \file WznmQVitList.h
	* Java API code for record of table TblWznmQVitList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQVitList {
	
	public WznmQVitList(
				int jnum
				, String sref
				, String Title
				, String stubVecRefWznmMVector
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.stubVecRefWznmMVector = stubVecRefWznmMVector;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String stubVecRefWznmMVector;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQVitList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubVecRefWznmMVector = Xmlio.extractStringUclc(doc, basexpath, "stubVecRefWznmMVector", "vec", null, 0);
			
			return true;
		};

		return false;
	};
};
