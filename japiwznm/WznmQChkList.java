/**
  * \file WznmQChkList.h
  * Java API code for record of table TblWznmQChkList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQChkList {
	
	public WznmQChkList(
				int jnum
				, String sref
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubRefWznmMTable
				, String stubRefWznmMTablecol
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubRefWznmMTable = stubRefWznmMTable;
		this.stubRefWznmMTablecol = stubRefWznmMTablecol;
	};

	public int jnum;
	public String sref;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubRefWznmMTable;
	public String stubRefWznmMTablecol;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQChkList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubRefWznmMTable = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMTable", "tbl", null, 0);
			stubRefWznmMTablecol = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMTablecol", "tco", null, 0);
			
			return true;
		};

		return false;
	};
};

