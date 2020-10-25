/**
  * \file WznmQConAPar.h
  * Java API code for record of table TblWznmQConAPar
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQConAPar {
	
	public WznmQConAPar(
				int jnum
				, String x1SrefKKey
				, String titX1SrefKKey
				, String stubX2RefWznmMLocale
				, String osrefKVal
				, String titOsrefKVal
			) {
		this.jnum = jnum;
		this.x1SrefKKey = x1SrefKKey;
		this.titX1SrefKKey = titX1SrefKKey;
		this.stubX2RefWznmMLocale = stubX2RefWznmMLocale;
		this.osrefKVal = osrefKVal;
		this.titOsrefKVal = titOsrefKVal;
	};

	public int jnum;
	public String x1SrefKKey;
	public String titX1SrefKKey;
	public String stubX2RefWznmMLocale;
	public String osrefKVal;
	public String titOsrefKVal;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQConAPar");

		if (Xmlio.checkXPath(doc, basexpath)) {
			x1SrefKKey = Xmlio.extractStringUclc(doc, basexpath, "x1SrefKKey", "key", null, 0);
			titX1SrefKKey = Xmlio.extractStringUclc(doc, basexpath, "titX1SrefKKey", "key2", null, 0);
			stubX2RefWznmMLocale = Xmlio.extractStringUclc(doc, basexpath, "stubX2RefWznmMLocale", "loc", null, 0);
			osrefKVal = Xmlio.extractStringUclc(doc, basexpath, "osrefKVal", "val", null, 0);
			titOsrefKVal = Xmlio.extractStringUclc(doc, basexpath, "titOsrefKVal", "val2", null, 0);
			
			return true;
		};

		return false;
	};
};

