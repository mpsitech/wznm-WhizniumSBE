/**
	* \file WznmQPrjList.h
	* Java API code for record of table TblWznmQPrjList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQPrjList {
	
	public WznmQPrjList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String Short
				, String Title
				, String stubRefWznmMVersion
				, String Giturl
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.Short = Short;
		this.Title = Title;
		this.stubRefWznmMVersion = stubRefWznmMVersion;
		this.Giturl = Giturl;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String Short;
	public String Title;
	public String stubRefWznmMVersion;
	public String Giturl;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQPrjList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			Short = Xmlio.extractStringUclc(doc, basexpath, "Short", "sho", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVersion", "ver", null, 0);
			Giturl = Xmlio.extractStringUclc(doc, basexpath, "Giturl", "grl", null, 0);
			
			return true;
		};

		return false;
	};
};
