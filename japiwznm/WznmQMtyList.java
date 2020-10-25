/**
  * \file WznmQMtyList.h
  * Java API code for record of table TblWznmQMtyList
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQMtyList {
	
	public WznmQMtyList(
				int jnum
				, String sref
				, String srefIxVArch
				, String titIxVArch
				, String srefKOs
				, String titSrefKOs
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVArch = srefIxVArch;
		this.titIxVArch = titIxVArch;
		this.srefKOs = srefKOs;
		this.titSrefKOs = titSrefKOs;
	};

	public int jnum;
	public String sref;
	public String srefIxVArch;
	public String titIxVArch;
	public String srefKOs;
	public String titSrefKOs;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQMtyList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVArch = Xmlio.extractStringUclc(doc, basexpath, "srefIxVArch", "ach", null, 0);
			titIxVArch = Xmlio.extractStringUclc(doc, basexpath, "titIxVArch", "ach2", null, 0);
			srefKOs = Xmlio.extractStringUclc(doc, basexpath, "srefKOs", "os", null, 0);
			titSrefKOs = Xmlio.extractStringUclc(doc, basexpath, "titSrefKOs", "os2", null, 0);
			
			return true;
		};

		return false;
	};
};

