/**
  * \file WznmQTcoList.h
  * Java API code for record of table TblWznmQTcoList
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQTcoList {
	
	public WznmQTcoList(
				int jnum
				, String sref
				, String Short
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubTblRefWznmMTable
				, String srefFctIxVTbl
				, String titFctIxVTbl
				, String srefIxVSubtype
				, String titIxVSubtype
				, String srefIxVAxisfct
				, String titIxVAxisfct
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Short = Short;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubTblRefWznmMTable = stubTblRefWznmMTable;
		this.srefFctIxVTbl = srefFctIxVTbl;
		this.titFctIxVTbl = titFctIxVTbl;
		this.srefIxVSubtype = srefIxVSubtype;
		this.titIxVSubtype = titIxVSubtype;
		this.srefIxVAxisfct = srefIxVAxisfct;
		this.titIxVAxisfct = titIxVAxisfct;
	};

	public int jnum;
	public String sref;
	public String Short;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubTblRefWznmMTable;
	public String srefFctIxVTbl;
	public String titFctIxVTbl;
	public String srefIxVSubtype;
	public String titIxVSubtype;
	public String srefIxVAxisfct;
	public String titIxVAxisfct;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQTcoList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Short = Xmlio.extractStringUclc(doc, basexpath, "Short", "sho", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubTblRefWznmMTable = Xmlio.extractStringUclc(doc, basexpath, "stubTblRefWznmMTable", "tbl", null, 0);
			srefFctIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefFctIxVTbl", "fct", null, 0);
			titFctIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titFctIxVTbl", "fct2", null, 0);
			srefIxVSubtype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVSubtype", "sty", null, 0);
			titIxVSubtype = Xmlio.extractStringUclc(doc, basexpath, "titIxVSubtype", "sty2", null, 0);
			srefIxVAxisfct = Xmlio.extractStringUclc(doc, basexpath, "srefIxVAxisfct", "axf", null, 0);
			titIxVAxisfct = Xmlio.extractStringUclc(doc, basexpath, "titIxVAxisfct", "axf2", null, 0);
			
			return true;
		};

		return false;
	};
};

