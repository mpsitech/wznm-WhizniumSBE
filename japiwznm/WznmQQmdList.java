/**
  * \file WznmQQmdList.h
  * Java API code for record of table TblWznmQQmdList
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQQmdList {
	
	public WznmQQmdList(
				int jnum
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubQryRefWznmMQuery
				, String stubRefWznmMPreset
				, String srefRefIxVTbl
				, String titRefIxVTbl
				, String stubRefUref
			) {
		this.jnum = jnum;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubQryRefWznmMQuery = stubQryRefWznmMQuery;
		this.stubRefWznmMPreset = stubRefWznmMPreset;
		this.srefRefIxVTbl = srefRefIxVTbl;
		this.titRefIxVTbl = titRefIxVTbl;
		this.stubRefUref = stubRefUref;
	};

	public int jnum;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubQryRefWznmMQuery;
	public String stubRefWznmMPreset;
	public String srefRefIxVTbl;
	public String titRefIxVTbl;
	public String stubRefUref;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQQmdList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubQryRefWznmMQuery = Xmlio.extractStringUclc(doc, basexpath, "stubQryRefWznmMQuery", "qry", null, 0);
			stubRefWznmMPreset = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMPreset", "pst", null, 0);
			srefRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefRefIxVTbl", "ret", null, 0);
			titRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titRefIxVTbl", "ret2", null, 0);
			stubRefUref = Xmlio.extractStringUclc(doc, basexpath, "stubRefUref", "reu", null, 0);
			
			return true;
		};

		return false;
	};
};

