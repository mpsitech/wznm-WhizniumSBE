/**
  * \file WznmQAppList.h
  * Java API code for record of table TblWznmQAppList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQAppList {
	
	public WznmQAppList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String Short
				, String Title
				, String srefIxVTarget
				, String titIxVTarget
				, String stubVerRefWznmMVersion
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.Short = Short;
		this.Title = Title;
		this.srefIxVTarget = srefIxVTarget;
		this.titIxVTarget = titIxVTarget;
		this.stubVerRefWznmMVersion = stubVerRefWznmMVersion;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String Short;
	public String Title;
	public String srefIxVTarget;
	public String titIxVTarget;
	public String stubVerRefWznmMVersion;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQAppList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			Short = Xmlio.extractStringUclc(doc, basexpath, "Short", "sho", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			srefIxVTarget = Xmlio.extractStringUclc(doc, basexpath, "srefIxVTarget", "trg", null, 0);
			titIxVTarget = Xmlio.extractStringUclc(doc, basexpath, "titIxVTarget", "trg2", null, 0);
			stubVerRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubVerRefWznmMVersion", "ver", null, 0);
			
			return true;
		};

		return false;
	};
};

