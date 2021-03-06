/**
	* \file WznmQVecList.h
	* Java API code for record of table TblWznmQVecList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQVecList {
	
	public WznmQVecList(
				int jnum
				, String sref
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubRefWznmMVersion
				, String srefHkIxVTbl
				, String titHkIxVTbl
				, String stubHkUref
				, String osrefWznmKTaggrp
				, String titOsrefWznmKTaggrp
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubRefWznmMVersion = stubRefWznmMVersion;
		this.srefHkIxVTbl = srefHkIxVTbl;
		this.titHkIxVTbl = titHkIxVTbl;
		this.stubHkUref = stubHkUref;
		this.osrefWznmKTaggrp = osrefWznmKTaggrp;
		this.titOsrefWznmKTaggrp = titOsrefWznmKTaggrp;
	};

	public int jnum;
	public String sref;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubRefWznmMVersion;
	public String srefHkIxVTbl;
	public String titHkIxVTbl;
	public String stubHkUref;
	public String osrefWznmKTaggrp;
	public String titOsrefWznmKTaggrp;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQVecList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVersion", "ver", null, 0);
			srefHkIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefHkIxVTbl", "hkt", null, 0);
			titHkIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titHkIxVTbl", "hkt2", null, 0);
			stubHkUref = Xmlio.extractStringUclc(doc, basexpath, "stubHkUref", "hku", null, 0);
			osrefWznmKTaggrp = Xmlio.extractStringUclc(doc, basexpath, "osrefWznmKTaggrp", "tgr", null, 0);
			titOsrefWznmKTaggrp = Xmlio.extractStringUclc(doc, basexpath, "titOsrefWznmKTaggrp", "tgr2", null, 0);
			
			return true;
		};

		return false;
	};
};
