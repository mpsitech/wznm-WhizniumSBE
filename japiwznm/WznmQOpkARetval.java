/**
	* \file WznmQOpkARetval.h
	* Java API code for record of table TblWznmQOpkARetval
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQOpkARetval {
	
	public WznmQOpkARetval(
				int jnum
				, String sref
				, String srefIxWznmVVartype
				, String titIxWznmVVartype
				, String stubRefWznmMVector
				, String Comment
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxWznmVVartype = srefIxWznmVVartype;
		this.titIxWznmVVartype = titIxWznmVVartype;
		this.stubRefWznmMVector = stubRefWznmMVector;
		this.Comment = Comment;
	};

	public int jnum;
	public String sref;
	public String srefIxWznmVVartype;
	public String titIxWznmVVartype;
	public String stubRefWznmMVector;
	public String Comment;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQOpkARetval");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxWznmVVartype = Xmlio.extractStringUclc(doc, basexpath, "srefIxWznmVVartype", "vty", null, 0);
			titIxWznmVVartype = Xmlio.extractStringUclc(doc, basexpath, "titIxWznmVVartype", "vty2", null, 0);
			stubRefWznmMVector = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVector", "vec", null, 0);
			Comment = Xmlio.extractStringUclc(doc, basexpath, "Comment", "cmt", null, 0);
			
			return true;
		};

		return false;
	};
};
