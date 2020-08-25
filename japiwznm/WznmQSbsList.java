/**
  * \file WznmQSbsList.h
  * Java API code for record of table TblWznmQSbsList
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQSbsList {
	
	public WznmQSbsList(
				int jnum
				, String sref
				, String Short
				, String stubRefWznmMTable
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Short = Short;
		this.stubRefWznmMTable = stubRefWznmMTable;
	};

	public int jnum;
	public String sref;
	public String Short;
	public String stubRefWznmMTable;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQSbsList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Short = Xmlio.extractStringUclc(doc, basexpath, "Short", "sho", null, 0);
			stubRefWznmMTable = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMTable", "tbl", null, 0);
			
			return true;
		};

		return false;
	};
};

