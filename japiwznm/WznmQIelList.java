/**
  * \file WznmQIelList.h
  * Java API code for record of table TblWznmQIelList
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQIelList {
	
	public WznmQIelList(
				int jnum
				, String sref
				, String Short
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubImeRefWznmMImpexp
				, String stubRefWznmMTablecol
				, String srefIxVConvtype
				, String titIxVConvtype
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Short = Short;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubImeRefWznmMImpexp = stubImeRefWznmMImpexp;
		this.stubRefWznmMTablecol = stubRefWznmMTablecol;
		this.srefIxVConvtype = srefIxVConvtype;
		this.titIxVConvtype = titIxVConvtype;
	};

	public int jnum;
	public String sref;
	public String Short;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubImeRefWznmMImpexp;
	public String stubRefWznmMTablecol;
	public String srefIxVConvtype;
	public String titIxVConvtype;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQIelList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Short = Xmlio.extractStringUclc(doc, basexpath, "Short", "sho", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubImeRefWznmMImpexp = Xmlio.extractStringUclc(doc, basexpath, "stubImeRefWznmMImpexp", "ime", null, 0);
			stubRefWznmMTablecol = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMTablecol", "tco", null, 0);
			srefIxVConvtype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVConvtype", "cty", null, 0);
			titIxVConvtype = Xmlio.extractStringUclc(doc, basexpath, "titIxVConvtype", "cty2", null, 0);
			
			return true;
		};

		return false;
	};
};

