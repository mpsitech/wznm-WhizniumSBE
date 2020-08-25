/**
  * \file WznmQStbList.h
  * Java API code for record of table TblWznmQStbList
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQStbList {
	
	public WznmQStbList(
				int jnum
				, String sref
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubRefWznmMTable
				, String stubRefWznmMSubset
				, String Example
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubRefWznmMTable = stubRefWznmMTable;
		this.stubRefWznmMSubset = stubRefWznmMSubset;
		this.Example = Example;
	};

	public int jnum;
	public String sref;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubRefWznmMTable;
	public String stubRefWznmMSubset;
	public String Example;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQStbList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubRefWznmMTable = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMTable", "tbl", null, 0);
			stubRefWznmMSubset = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMSubset", "sbs", null, 0);
			Example = Xmlio.extractStringUclc(doc, basexpath, "Example", "exa", null, 0);
			
			return true;
		};

		return false;
	};
};

