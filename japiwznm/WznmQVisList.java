/**
	* \file WznmQVisList.java
	* Java API code for record of table TblWznmQVisList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQVisList {
	
	public WznmQVisList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubVerRefWznmMVersion
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubVerRefWznmMVersion = stubVerRefWznmMVersion;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubVerRefWznmMVersion;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQVisList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubVerRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubVerRefWznmMVersion", "ver", null, 0);
			
			return true;
		};

		return false;
	};
};
