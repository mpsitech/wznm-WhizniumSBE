/**
	* \file WznmQBoxList.java
	* Java API code for record of table TblWznmQBoxList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQBoxList {
	
	public WznmQBoxList(
				int jnum
				, String stubRefWznmMSheet
				, String srefUnvIxWznmVMaintable
				, String titUnvIxWznmVMaintable
				, String stubUnvUref
			) {
		this.jnum = jnum;
		this.stubRefWznmMSheet = stubRefWznmMSheet;
		this.srefUnvIxWznmVMaintable = srefUnvIxWznmVMaintable;
		this.titUnvIxWznmVMaintable = titUnvIxWznmVMaintable;
		this.stubUnvUref = stubUnvUref;
	};

	public int jnum;
	public String stubRefWznmMSheet;
	public String srefUnvIxWznmVMaintable;
	public String titUnvIxWznmVMaintable;
	public String stubUnvUref;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQBoxList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubRefWznmMSheet = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMSheet", "sht", null, 0);
			srefUnvIxWznmVMaintable = Xmlio.extractStringUclc(doc, basexpath, "srefUnvIxWznmVMaintable", "mtb", null, 0);
			titUnvIxWznmVMaintable = Xmlio.extractStringUclc(doc, basexpath, "titUnvIxWznmVMaintable", "mtb2", null, 0);
			stubUnvUref = Xmlio.extractStringUclc(doc, basexpath, "stubUnvUref", "unv", null, 0);
			
			return true;
		};

		return false;
	};
};
