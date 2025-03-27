/**
	* \file WznmQBoxDstMNBox.java
	* Java API code for record of table TblWznmQBoxDstMNBox
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQBoxDstMNBox {
	
	public WznmQBoxDstMNBox(
				int jnum
				, String stubMref
				, int orgClk
				, int dstClk
				, int Weight
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
		this.orgClk = orgClk;
		this.dstClk = dstClk;
		this.Weight = Weight;
	};

	public int jnum;
	public String stubMref;
	public int orgClk;
	public int dstClk;
	public int Weight;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQBoxDstMNBox");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			orgClk = Xmlio.extractIntegerUclc(doc, basexpath, "orgClk", "ocl", null, 0);
			dstClk = Xmlio.extractIntegerUclc(doc, basexpath, "dstClk", "dcl", null, 0);
			Weight = Xmlio.extractIntegerUclc(doc, basexpath, "Weight", "wgt", null, 0);
			
			return true;
		};

		return false;
	};
};
