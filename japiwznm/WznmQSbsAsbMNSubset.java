/**
  * \file WznmQSbsAsbMNSubset.h
  * Java API code for record of table TblWznmQSbsAsbMNSubset
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQSbsAsbMNSubset {
	
	public WznmQSbsAsbMNSubset(
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
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQSbsAsbMNSubset");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			srefIxVReltype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVReltype", "rty", null, 0);
			titIxVReltype = Xmlio.extractStringUclc(doc, basexpath, "titIxVReltype", "rty2", null, 0);
			
			return true;
		};

		return false;
	};
};

