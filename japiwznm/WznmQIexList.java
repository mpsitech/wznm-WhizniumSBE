/**
	* \file WznmQIexList.h
	* Java API code for record of table TblWznmQIexList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQIexList {
	
	public WznmQIexList(
				int jnum
				, String sref
				, String Short
				, String Title
				, String stubRefWznmMVersion
				, String Minversion
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Short = Short;
		this.Title = Title;
		this.stubRefWznmMVersion = stubRefWznmMVersion;
		this.Minversion = Minversion;
	};

	public int jnum;
	public String sref;
	public String Short;
	public String Title;
	public String stubRefWznmMVersion;
	public String Minversion;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQIexList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Short = Xmlio.extractStringUclc(doc, basexpath, "Short", "sho", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVersion", "ver", null, 0);
			Minversion = Xmlio.extractStringUclc(doc, basexpath, "Minversion", "miv", null, 0);
			
			return true;
		};

		return false;
	};
};
