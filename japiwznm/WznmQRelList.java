/**
  * \file WznmQRelList.h
  * Java API code for record of table TblWznmQRelList
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQRelList {
	
	public WznmQRelList(
				int jnum
				, String stubFrRefWznmMTable
				, String stubFrsRefWznmMSubset
				, String stubToRefWznmMTable
				, String stubTosRefWznmMSubset
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubRefWznmMVersion
				, String stubSupRefWznmMRelation
				, String srefSupIxVSubrole
				, String titSupIxVSubrole
				, String stubRefWznmMTable
				, String Prefix
			) {
		this.jnum = jnum;
		this.stubFrRefWznmMTable = stubFrRefWznmMTable;
		this.stubFrsRefWznmMSubset = stubFrsRefWznmMSubset;
		this.stubToRefWznmMTable = stubToRefWznmMTable;
		this.stubTosRefWznmMSubset = stubTosRefWznmMSubset;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubRefWznmMVersion = stubRefWznmMVersion;
		this.stubSupRefWznmMRelation = stubSupRefWznmMRelation;
		this.srefSupIxVSubrole = srefSupIxVSubrole;
		this.titSupIxVSubrole = titSupIxVSubrole;
		this.stubRefWznmMTable = stubRefWznmMTable;
		this.Prefix = Prefix;
	};

	public int jnum;
	public String stubFrRefWznmMTable;
	public String stubFrsRefWznmMSubset;
	public String stubToRefWznmMTable;
	public String stubTosRefWznmMSubset;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubRefWznmMVersion;
	public String stubSupRefWznmMRelation;
	public String srefSupIxVSubrole;
	public String titSupIxVSubrole;
	public String stubRefWznmMTable;
	public String Prefix;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQRelList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubFrRefWznmMTable = Xmlio.extractStringUclc(doc, basexpath, "stubFrRefWznmMTable", "frt", null, 0);
			stubFrsRefWznmMSubset = Xmlio.extractStringUclc(doc, basexpath, "stubFrsRefWznmMSubset", "frs", null, 0);
			stubToRefWznmMTable = Xmlio.extractStringUclc(doc, basexpath, "stubToRefWznmMTable", "tot", null, 0);
			stubTosRefWznmMSubset = Xmlio.extractStringUclc(doc, basexpath, "stubTosRefWznmMSubset", "tos", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVersion", "ver", null, 0);
			stubSupRefWznmMRelation = Xmlio.extractStringUclc(doc, basexpath, "stubSupRefWznmMRelation", "sup", null, 0);
			srefSupIxVSubrole = Xmlio.extractStringUclc(doc, basexpath, "srefSupIxVSubrole", "srl", null, 0);
			titSupIxVSubrole = Xmlio.extractStringUclc(doc, basexpath, "titSupIxVSubrole", "srl2", null, 0);
			stubRefWznmMTable = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMTable", "tbl", null, 0);
			Prefix = Xmlio.extractStringUclc(doc, basexpath, "Prefix", "pfx", null, 0);
			
			return true;
		};

		return false;
	};
};

