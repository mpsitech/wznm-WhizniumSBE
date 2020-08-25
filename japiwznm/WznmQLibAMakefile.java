/**
  * \file WznmQLibAMakefile.h
  * Java API code for record of table TblWznmQLibAMakefile
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQLibAMakefile {
	
	public WznmQLibAMakefile(
				int jnum
				, String srefX1RefIxVTbl
				, String titX1RefIxVTbl
				, String stubX1RefUref
				, String x2SrefKTag
				, String titX2SrefKTag
				, String Val
			) {
		this.jnum = jnum;
		this.srefX1RefIxVTbl = srefX1RefIxVTbl;
		this.titX1RefIxVTbl = titX1RefIxVTbl;
		this.stubX1RefUref = stubX1RefUref;
		this.x2SrefKTag = x2SrefKTag;
		this.titX2SrefKTag = titX2SrefKTag;
		this.Val = Val;
	};

	public int jnum;
	public String srefX1RefIxVTbl;
	public String titX1RefIxVTbl;
	public String stubX1RefUref;
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
			srefX1RefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefX1RefIxVTbl", "ret", null, 0);
			titX1RefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titX1RefIxVTbl", "ret2", null, 0);
			stubX1RefUref = Xmlio.extractStringUclc(doc, basexpath, "stubX1RefUref", "reu", null, 0);
			x2SrefKTag = Xmlio.extractStringUclc(doc, basexpath, "x2SrefKTag", "tag", null, 0);
			titX2SrefKTag = Xmlio.extractStringUclc(doc, basexpath, "titX2SrefKTag", "tag2", null, 0);
			Val = Xmlio.extractStringUclc(doc, basexpath, "Val", "val", null, 0);
			
			return true;
		};

		return false;
	};
};

