/**
	* \file WznmQQcoList.h
	* Java API code for record of table TblWznmQQcoList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQQcoList {
	
	public WznmQQcoList(
				int jnum
				, String sref
				, String Short
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubQryRefWznmMQuery
				, String stubRefWznmMTablecol
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Short = Short;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubQryRefWznmMQuery = stubQryRefWznmMQuery;
		this.stubRefWznmMTablecol = stubRefWznmMTablecol;
	};

	public int jnum;
	public String sref;
	public String Short;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubQryRefWznmMQuery;
	public String stubRefWznmMTablecol;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQQcoList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Short = Xmlio.extractStringUclc(doc, basexpath, "Short", "sho", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubQryRefWznmMQuery = Xmlio.extractStringUclc(doc, basexpath, "stubQryRefWznmMQuery", "qry", null, 0);
			stubRefWznmMTablecol = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMTablecol", "tco", null, 0);
			
			return true;
		};

		return false;
	};
};

