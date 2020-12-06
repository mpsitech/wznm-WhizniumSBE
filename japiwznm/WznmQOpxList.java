/**
	* \file WznmQOpxList.h
	* Java API code for record of table TblWznmQOpxList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQOpxList {
	
	public WznmQOpxList(
				int jnum
				, String sref
				, String stubRefWznmMOppack
				, String yesnoShrdat
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubRefWznmMOppack = stubRefWznmMOppack;
		this.yesnoShrdat = yesnoShrdat;
	};

	public int jnum;
	public String sref;
	public String stubRefWznmMOppack;
	public String yesnoShrdat;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQOpxList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWznmMOppack = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMOppack", "opk", null, 0);
			yesnoShrdat = Xmlio.extractStringUclc(doc, basexpath, "yesnoShrdat", "shd", null, 0);
			
			return true;
		};

		return false;
	};
};
