/**
  * \file WznmQJobMNOp.h
  * Java API code for record of table TblWznmQJobMNOp
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQJobMNOp {
	
	public WznmQJobMNOp(
				int jnum
				, String stubMref
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
	};

	public int jnum;
	public String stubMref;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQJobMNOp");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			
			return true;
		};

		return false;
	};
};

