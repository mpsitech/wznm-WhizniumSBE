/**
  * \file WznmQMdlMdl1NCard.h
  * Java API code for record of table TblWznmQMdlMdl1NCard
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQMdlMdl1NCard {
	
	public WznmQMdlMdl1NCard(
				int jnum
				, String stubRef
			) {
		this.jnum = jnum;
		this.stubRef = stubRef;
	};

	public int jnum;
	public String stubRef;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQMdlMdl1NCard");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubRef = Xmlio.extractStringUclc(doc, basexpath, "stubRef", "ref", null, 0);
			
			return true;
		};

		return false;
	};
};

