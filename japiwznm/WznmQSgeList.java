/**
	* \file WznmQSgeList.h
	* Java API code for record of table TblWznmQSgeList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQSgeList {
	
	public WznmQSgeList(
				int jnum
				, String sref
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubJobRefWznmMJob
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubJobRefWznmMJob = stubJobRefWznmMJob;
	};

	public int jnum;
	public String sref;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubJobRefWznmMJob;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQSgeList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubJobRefWznmMJob = Xmlio.extractStringUclc(doc, basexpath, "stubJobRefWznmMJob", "job", null, 0);
			
			return true;
		};

		return false;
	};
};
