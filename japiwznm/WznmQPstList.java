/**
	* \file WznmQPstList.h
	* Java API code for record of table TblWznmQPstList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQPstList {
	
	public WznmQPstList(
				int jnum
				, String sref
				, String Title
				, String stubRefWznmMVersion
				, String srefRefIxVTbl
				, String titRefIxVTbl
				, String stubRefUref
				, String srefIxWznmWArgtype
				, String titIxWznmWArgtype
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.stubRefWznmMVersion = stubRefWznmMVersion;
		this.srefRefIxVTbl = srefRefIxVTbl;
		this.titRefIxVTbl = titRefIxVTbl;
		this.stubRefUref = stubRefUref;
		this.srefIxWznmWArgtype = srefIxWznmWArgtype;
		this.titIxWznmWArgtype = titIxWznmWArgtype;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String stubRefWznmMVersion;
	public String srefRefIxVTbl;
	public String titRefIxVTbl;
	public String stubRefUref;
	public String srefIxWznmWArgtype;
	public String titIxWznmWArgtype;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQPstList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVersion", "ver", null, 0);
			srefRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefRefIxVTbl", "ret", null, 0);
			titRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titRefIxVTbl", "ret2", null, 0);
			stubRefUref = Xmlio.extractStringUclc(doc, basexpath, "stubRefUref", "reu", null, 0);
			srefIxWznmWArgtype = Xmlio.extractStringUclc(doc, basexpath, "srefIxWznmWArgtype", "aty", null, 0);
			titIxWznmWArgtype = Xmlio.extractStringUclc(doc, basexpath, "titIxWznmWArgtype", "aty2", null, 0);
			
			return true;
		};

		return false;
	};
};

