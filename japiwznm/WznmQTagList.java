/**
  * \file WznmQTagList.h
  * Java API code for record of table TblWznmQTagList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQTagList {
	
	public WznmQTagList(
				int jnum
				, String sref
				, String Title
				, String stubRefWznmMCapability
				, String osrefWznmKTaggrp
				, String titOsrefWznmKTaggrp
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.stubRefWznmMCapability = stubRefWznmMCapability;
		this.osrefWznmKTaggrp = osrefWznmKTaggrp;
		this.titOsrefWznmKTaggrp = titOsrefWznmKTaggrp;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String stubRefWznmMCapability;
	public String osrefWznmKTaggrp;
	public String titOsrefWznmKTaggrp;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQTagList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubRefWznmMCapability = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMCapability", "cpb", null, 0);
			osrefWznmKTaggrp = Xmlio.extractStringUclc(doc, basexpath, "osrefWznmKTaggrp", "grp", null, 0);
			titOsrefWznmKTaggrp = Xmlio.extractStringUclc(doc, basexpath, "titOsrefWznmKTaggrp", "grp2", null, 0);
			
			return true;
		};

		return false;
	};
};

