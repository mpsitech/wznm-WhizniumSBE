/**
  * \file WznmQQryAClause.h
  * Java API code for record of table TblWznmQQryAClause
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQQryAClause {
	
	public WznmQQryAClause(
				int jnum
				, String stubX1RefWznmMQuerymod
				, String srefIxVBasetype
				, String titIxVBasetype
				, String Clause
				, String stubRefWznmMPreset
				, String stubRefWznmMVector
				, String stubRefWznmMVectoritem
			) {
		this.jnum = jnum;
		this.stubX1RefWznmMQuerymod = stubX1RefWznmMQuerymod;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.Clause = Clause;
		this.stubRefWznmMPreset = stubRefWznmMPreset;
		this.stubRefWznmMVector = stubRefWznmMVector;
		this.stubRefWznmMVectoritem = stubRefWznmMVectoritem;
	};

	public int jnum;
	public String stubX1RefWznmMQuerymod;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String Clause;
	public String stubRefWznmMPreset;
	public String stubRefWznmMVector;
	public String stubRefWznmMVectoritem;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQQryAClause");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubX1RefWznmMQuerymod = Xmlio.extractStringUclc(doc, basexpath, "stubX1RefWznmMQuerymod", "qmd", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			Clause = Xmlio.extractStringUclc(doc, basexpath, "Clause", "cse", null, 0);
			stubRefWznmMPreset = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMPreset", "pst", null, 0);
			stubRefWznmMVector = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVector", "vec", null, 0);
			stubRefWznmMVectoritem = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVectoritem", "vit", null, 0);
			
			return true;
		};

		return false;
	};
};

