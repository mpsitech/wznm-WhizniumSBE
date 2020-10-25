/**
  * \file WznmQErrList.h
  * Java API code for record of table TblWznmQErrList
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQErrList {
	
	public WznmQErrList(
				int jnum
				, String sref
				, String Title
				, String stubVerRefWznmMVersion
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.stubVerRefWznmMVersion = stubVerRefWznmMVersion;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String stubVerRefWznmMVersion;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQErrList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubVerRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubVerRefWznmMVersion", "ver", null, 0);
			
			return true;
		};

		return false;
	};
};

