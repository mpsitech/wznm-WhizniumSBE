/**
  * \file WznmQMchList.h
  * Java API code for record of table TblWznmQMchList
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQMchList {
	
	public WznmQMchList(
				int jnum
				, String sref
				, String stubRefWznmMMachtype
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubRefWznmMMachtype = stubRefWznmMMachtype;
	};

	public int jnum;
	public String sref;
	public String stubRefWznmMMachtype;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQMchList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWznmMMachtype = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMMachtype", "tbl", null, 0);
			
			return true;
		};

		return false;
	};
};

