/**
	* \file WznmQPnlList.h
	* Java API code for record of table TblWznmQPnlList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQPnlList {
	
	public WznmQPnlList(
				int jnum
				, String sref
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubCarRefWznmMCard
				, String srefRefIxVTbl
				, String titRefIxVTbl
				, String stubRefUref
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubCarRefWznmMCard = stubCarRefWznmMCard;
		this.srefRefIxVTbl = srefRefIxVTbl;
		this.titRefIxVTbl = titRefIxVTbl;
		this.stubRefUref = stubRefUref;
	};

	public int jnum;
	public String sref;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubCarRefWznmMCard;
	public String srefRefIxVTbl;
	public String titRefIxVTbl;
	public String stubRefUref;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQPnlList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubCarRefWznmMCard = Xmlio.extractStringUclc(doc, basexpath, "stubCarRefWznmMCard", "car", null, 0);
			srefRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefRefIxVTbl", "ret", null, 0);
			titRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titRefIxVTbl", "ret2", null, 0);
			stubRefUref = Xmlio.extractStringUclc(doc, basexpath, "stubRefUref", "reu", null, 0);
			
			return true;
		};

		return false;
	};
};

