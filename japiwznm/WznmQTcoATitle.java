/**
  * \file WznmQTcoATitle.h
  * Java API code for record of table TblWznmQTcoATitle
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQTcoATitle {
	
	public WznmQTcoATitle(
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
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQTcoATitle");

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

