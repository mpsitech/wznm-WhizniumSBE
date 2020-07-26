/**
  * \file WznmQLibAPkglist.h
  * Java API code for record of table TblWznmQLibAPkglist
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQLibAPkglist {
	
	public WznmQLibAPkglist(
				int jnum
				, String srefX1RefIxVTbl
				, String titX1RefIxVTbl
				, String stubX1RefUref
				, String Pkglist
			) {
		this.jnum = jnum;
		this.srefX1RefIxVTbl = srefX1RefIxVTbl;
		this.titX1RefIxVTbl = titX1RefIxVTbl;
		this.stubX1RefUref = stubX1RefUref;
		this.Pkglist = Pkglist;
	};

	public int jnum;
	public String srefX1RefIxVTbl;
	public String titX1RefIxVTbl;
	public String stubX1RefUref;
	public String Pkglist;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQLibAPkglist");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefX1RefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefX1RefIxVTbl", "ret", null, 0);
			titX1RefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titX1RefIxVTbl", "ret2", null, 0);
			stubX1RefUref = Xmlio.extractStringUclc(doc, basexpath, "stubX1RefUref", "reu", null, 0);
			Pkglist = Xmlio.extractStringUclc(doc, basexpath, "Pkglist", "pkl", null, 0);
			
			return true;
		};

		return false;
	};
};

