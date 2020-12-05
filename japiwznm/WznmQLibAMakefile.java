/**
	* \file WznmQLibAMakefile.h
	* Java API code for record of table TblWznmQLibAMakefile
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQLibAMakefile {
	
	public WznmQLibAMakefile(
				int jnum
				, String stubX1RefWznmMMachine
				, String x2SrefKTag
				, String titX2SrefKTag
				, String Val
			) {
		this.jnum = jnum;
		this.stubX1RefWznmMMachine = stubX1RefWznmMMachine;
		this.x2SrefKTag = x2SrefKTag;
		this.titX2SrefKTag = titX2SrefKTag;
		this.Val = Val;
	};

	public int jnum;
	public String stubX1RefWznmMMachine;
	public String x2SrefKTag;
	public String titX2SrefKTag;
	public String Val;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQLibAMakefile");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubX1RefWznmMMachine = Xmlio.extractStringUclc(doc, basexpath, "stubX1RefWznmMMachine", "mch", null, 0);
			x2SrefKTag = Xmlio.extractStringUclc(doc, basexpath, "x2SrefKTag", "tag", null, 0);
			titX2SrefKTag = Xmlio.extractStringUclc(doc, basexpath, "titX2SrefKTag", "tag2", null, 0);
			Val = Xmlio.extractStringUclc(doc, basexpath, "Val", "val", null, 0);
			
			return true;
		};

		return false;
	};
};

