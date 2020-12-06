/**
	* \file WznmQUsgMNUser.h
	* Java API code for record of table TblWznmQUsgMNUser
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQUsgMNUser {
	
	public WznmQUsgMNUser(
				int jnum
				, String stubMref
				, String srefIxWznmVUserlevel
				, String titIxWznmVUserlevel
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
		this.srefIxWznmVUserlevel = srefIxWznmVUserlevel;
		this.titIxWznmVUserlevel = titIxWznmVUserlevel;
	};

	public int jnum;
	public String stubMref;
	public String srefIxWznmVUserlevel;
	public String titIxWznmVUserlevel;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQUsgMNUser");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			srefIxWznmVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "srefIxWznmVUserlevel", "ulv", null, 0);
			titIxWznmVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "titIxWznmVUserlevel", "ulv2", null, 0);
			
			return true;
		};

		return false;
	};
};
