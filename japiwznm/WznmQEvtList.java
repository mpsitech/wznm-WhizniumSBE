/**
  * \file WznmQEvtList.h
  * Java API code for record of table TblWznmQEvtList
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQEvtList {
	
	public WznmQEvtList(
				int jnum
				, String sref
				, String stubRefWznmMApp
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubRefWznmMApp = stubRefWznmMApp;
	};

	public int jnum;
	public String sref;
	public String stubRefWznmMApp;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQEvtList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWznmMApp = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMApp", "app", null, 0);
			
			return true;
		};

		return false;
	};
};

