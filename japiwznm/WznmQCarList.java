/**
  * \file WznmQCarList.h
  * Java API code for record of table TblWznmQCarList
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQCarList {
	
	public WznmQCarList(
				int jnum
				, String sref
				, String Title
				, String stubMdlRefWznmMModule
				, String srefRefIxVTbl
				, String titRefIxVTbl
				, String stubRefUref
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.stubMdlRefWznmMModule = stubMdlRefWznmMModule;
		this.srefRefIxVTbl = srefRefIxVTbl;
		this.titRefIxVTbl = titRefIxVTbl;
		this.stubRefUref = stubRefUref;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String stubMdlRefWznmMModule;
	public String srefRefIxVTbl;
	public String titRefIxVTbl;
	public String stubRefUref;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQCarList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubMdlRefWznmMModule = Xmlio.extractStringUclc(doc, basexpath, "stubMdlRefWznmMModule", "mdl", null, 0);
			srefRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefRefIxVTbl", "ret", null, 0);
			titRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titRefIxVTbl", "ret2", null, 0);
			stubRefUref = Xmlio.extractStringUclc(doc, basexpath, "stubRefUref", "reu", null, 0);
			
			return true;
		};

		return false;
	};
};

