/**
	* \file WznmQRelATitle.h
	* Java API code for record of table TblWznmQRelATitle
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQRelATitle {
	
	public WznmQRelATitle(
				int jnum
				, String srefX1IxVType
				, String titX1IxVType
				, String stubX2RefWznmMLocale
				, String Title
			) {
		this.jnum = jnum;
		this.srefX1IxVType = srefX1IxVType;
		this.titX1IxVType = titX1IxVType;
		this.stubX2RefWznmMLocale = stubX2RefWznmMLocale;
		this.Title = Title;
	};

	public int jnum;
	public String srefX1IxVType;
	public String titX1IxVType;
	public String stubX2RefWznmMLocale;
	public String Title;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQRelATitle");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefX1IxVType = Xmlio.extractStringUclc(doc, basexpath, "srefX1IxVType", "typ", null, 0);
			titX1IxVType = Xmlio.extractStringUclc(doc, basexpath, "titX1IxVType", "typ2", null, 0);
			stubX2RefWznmMLocale = Xmlio.extractStringUclc(doc, basexpath, "stubX2RefWznmMLocale", "loc", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			
			return true;
		};

		return false;
	};
};
