/**
  * \file WznmQQryMNTable.h
  * Java API code for record of table TblWznmQQryMNTable
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQQryMNTable {
	
	public WznmQQryMNTable(
				int jnum
				, String stubMref
				, String stubsTrefWznmMQuerymod
				, String yesnoSource
				, String Prefix
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
		this.stubsTrefWznmMQuerymod = stubsTrefWznmMQuerymod;
		this.yesnoSource = yesnoSource;
		this.Prefix = Prefix;
	};

	public int jnum;
	public String stubMref;
	public String stubsTrefWznmMQuerymod;
	public String yesnoSource;
	public String Prefix;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQQryMNTable");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			stubsTrefWznmMQuerymod = Xmlio.extractStringUclc(doc, basexpath, "stubsTrefWznmMQuerymod", "tqmd", null, 0);
			yesnoSource = Xmlio.extractStringUclc(doc, basexpath, "yesnoSource", "src", null, 0);
			Prefix = Xmlio.extractStringUclc(doc, basexpath, "Prefix", "pfx", null, 0);
			
			return true;
		};

		return false;
	};
};

