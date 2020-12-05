/**
	* \file WznmQSeqList.h
	* Java API code for record of table TblWznmQSeqList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQSeqList {
	
	public WznmQSeqList(
				int jnum
				, String sref
				, String Title
				, String stubAppRefWznmMApp
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.stubAppRefWznmMApp = stubAppRefWznmMApp;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String stubAppRefWznmMApp;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQSeqList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubAppRefWznmMApp = Xmlio.extractStringUclc(doc, basexpath, "stubAppRefWznmMApp", "app", null, 0);
			
			return true;
		};

		return false;
	};
};

