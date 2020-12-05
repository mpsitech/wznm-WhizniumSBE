/**
	* \file WznmQSbsBsbMNSubset.h
	* Java API code for record of table TblWznmQSbsBsbMNSubset
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQSbsBsbMNSubset {
	
	public WznmQSbsBsbMNSubset(
				int jnum
				, String stubMref
				, String srefIxVReltype
				, String titIxVReltype
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
		this.srefIxVReltype = srefIxVReltype;
		this.titIxVReltype = titIxVReltype;
	};

	public int jnum;
	public String stubMref;
	public String srefIxVReltype;
	public String titIxVReltype;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQSbsBsbMNSubset");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			srefIxVReltype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVReltype", "rty", null, 0);
			titIxVReltype = Xmlio.extractStringUclc(doc, basexpath, "titIxVReltype", "rty2", null, 0);
			
			return true;
		};

		return false;
	};
};

