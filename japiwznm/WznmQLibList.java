/**
  * \file WznmQLibList.h
  * Java API code for record of table TblWznmQLibList
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQLibList {
	
	public WznmQLibList(
				int jnum
				, String sref
				, String Title
				, String Version
				, String srefKLictype
				, String titSrefKLictype
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.Version = Version;
		this.srefKLictype = srefKLictype;
		this.titSrefKLictype = titSrefKLictype;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String Version;
	public String srefKLictype;
	public String titSrefKLictype;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQLibList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			Version = Xmlio.extractStringUclc(doc, basexpath, "Version", "ver", null, 0);
			srefKLictype = Xmlio.extractStringUclc(doc, basexpath, "srefKLictype", "lty", null, 0);
			titSrefKLictype = Xmlio.extractStringUclc(doc, basexpath, "titSrefKLictype", "lty2", null, 0);
			
			return true;
		};

		return false;
	};
};

