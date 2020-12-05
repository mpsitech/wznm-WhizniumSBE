/**
	* \file WznmQQryList.h
	* Java API code for record of table TblWznmQQryList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQQryList {
	
	public WznmQQryList(
				int jnum
				, String sref
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubRefWznmMVersion
				, String stubSupRefWznmMQuery
				, String srefSupIxVSubrole
				, String titSupIxVSubrole
				, String stubRefWznmMTable
				, String stubQtbRefWznmMTable
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubRefWznmMVersion = stubRefWznmMVersion;
		this.stubSupRefWznmMQuery = stubSupRefWznmMQuery;
		this.srefSupIxVSubrole = srefSupIxVSubrole;
		this.titSupIxVSubrole = titSupIxVSubrole;
		this.stubRefWznmMTable = stubRefWznmMTable;
		this.stubQtbRefWznmMTable = stubQtbRefWznmMTable;
	};

	public int jnum;
	public String sref;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubRefWznmMVersion;
	public String stubSupRefWznmMQuery;
	public String srefSupIxVSubrole;
	public String titSupIxVSubrole;
	public String stubRefWznmMTable;
	public String stubQtbRefWznmMTable;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQQryList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVersion", "ver", null, 0);
			stubSupRefWznmMQuery = Xmlio.extractStringUclc(doc, basexpath, "stubSupRefWznmMQuery", "sup", null, 0);
			srefSupIxVSubrole = Xmlio.extractStringUclc(doc, basexpath, "srefSupIxVSubrole", "srl", null, 0);
			titSupIxVSubrole = Xmlio.extractStringUclc(doc, basexpath, "titSupIxVSubrole", "srl2", null, 0);
			stubRefWznmMTable = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMTable", "tbl", null, 0);
			stubQtbRefWznmMTable = Xmlio.extractStringUclc(doc, basexpath, "stubQtbRefWznmMTable", "qtb", null, 0);
			
			return true;
		};

		return false;
	};
};

