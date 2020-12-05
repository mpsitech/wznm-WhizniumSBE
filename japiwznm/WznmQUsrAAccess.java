/**
	* \file WznmQUsrAAccess.h
	* Java API code for record of table TblWznmQUsrAAccess
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQUsrAAccess {
	
	public WznmQUsrAAccess(
				int jnum
				, String srefX1IxWznmVFeatgroup
				, String titX1IxWznmVFeatgroup
				, String x2FeaSrefUix
				, String srefsIxWznmWAccess
				, String titsIxWznmWAccess
			) {
		this.jnum = jnum;
		this.srefX1IxWznmVFeatgroup = srefX1IxWznmVFeatgroup;
		this.titX1IxWznmVFeatgroup = titX1IxWznmVFeatgroup;
		this.x2FeaSrefUix = x2FeaSrefUix;
		this.srefsIxWznmWAccess = srefsIxWznmWAccess;
		this.titsIxWznmWAccess = titsIxWznmWAccess;
	};

	public int jnum;
	public String srefX1IxWznmVFeatgroup;
	public String titX1IxWznmVFeatgroup;
	public String x2FeaSrefUix;
	public String srefsIxWznmWAccess;
	public String titsIxWznmWAccess;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQUsrAAccess");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefX1IxWznmVFeatgroup = Xmlio.extractStringUclc(doc, basexpath, "srefX1IxWznmVFeatgroup", "feg", null, 0);
			titX1IxWznmVFeatgroup = Xmlio.extractStringUclc(doc, basexpath, "titX1IxWznmVFeatgroup", "feg2", null, 0);
			x2FeaSrefUix = Xmlio.extractStringUclc(doc, basexpath, "x2FeaSrefUix", "fea", null, 0);
			srefsIxWznmWAccess = Xmlio.extractStringUclc(doc, basexpath, "srefsIxWznmWAccess", "acc", null, 0);
			titsIxWznmWAccess = Xmlio.extractStringUclc(doc, basexpath, "titsIxWznmWAccess", "acc2", null, 0);
			
			return true;
		};

		return false;
	};
};

