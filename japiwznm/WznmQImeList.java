/**
  * \file WznmQImeList.h
  * Java API code for record of table TblWznmQImeList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQImeList {
	
	public WznmQImeList(
				int jnum
				, String sref
				, String stubRefWznmMImpexpcplx
				, String stubSupRefWznmMImpexp
				, String stubRefWznmMTable
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubRefWznmMImpexpcplx = stubRefWznmMImpexpcplx;
		this.stubSupRefWznmMImpexp = stubSupRefWznmMImpexp;
		this.stubRefWznmMTable = stubRefWznmMTable;
	};

	public int jnum;
	public String sref;
	public String stubRefWznmMImpexpcplx;
	public String stubSupRefWznmMImpexp;
	public String stubRefWznmMTable;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQImeList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWznmMImpexpcplx = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMImpexpcplx", "iex", null, 0);
			stubSupRefWznmMImpexp = Xmlio.extractStringUclc(doc, basexpath, "stubSupRefWznmMImpexp", "sup", null, 0);
			stubRefWznmMTable = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMTable", "tbl", null, 0);
			
			return true;
		};

		return false;
	};
};

