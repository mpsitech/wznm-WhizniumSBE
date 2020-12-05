/**
	* \file WznmQUsrList.h
	* Java API code for record of table TblWznmQUsrList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQUsrList {
	
	public WznmQUsrList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String stubRefWznmMPerson
				, String sref
				, String stubRefWznmMUsergroup
				, String srefIxVState
				, String titIxVState
				, String srefIxWznmVLocale
				, String titIxWznmVLocale
				, String srefIxWznmVUserlevel
				, String titIxWznmVUserlevel
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.stubRefWznmMPerson = stubRefWznmMPerson;
		this.sref = sref;
		this.stubRefWznmMUsergroup = stubRefWznmMUsergroup;
		this.srefIxVState = srefIxVState;
		this.titIxVState = titIxVState;
		this.srefIxWznmVLocale = srefIxWznmVLocale;
		this.titIxWznmVLocale = titIxWznmVLocale;
		this.srefIxWznmVUserlevel = srefIxWznmVUserlevel;
		this.titIxWznmVUserlevel = titIxWznmVUserlevel;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String stubRefWznmMPerson;
	public String sref;
	public String stubRefWznmMUsergroup;
	public String srefIxVState;
	public String titIxVState;
	public String srefIxWznmVLocale;
	public String titIxWznmVLocale;
	public String srefIxWznmVUserlevel;
	public String titIxWznmVUserlevel;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQUsrList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			stubRefWznmMPerson = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMPerson", "prs", null, 0);
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWznmMUsergroup = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMUsergroup", "usg", null, 0);
			srefIxVState = Xmlio.extractStringUclc(doc, basexpath, "srefIxVState", "ste", null, 0);
			titIxVState = Xmlio.extractStringUclc(doc, basexpath, "titIxVState", "ste2", null, 0);
			srefIxWznmVLocale = Xmlio.extractStringUclc(doc, basexpath, "srefIxWznmVLocale", "lcl", null, 0);
			titIxWznmVLocale = Xmlio.extractStringUclc(doc, basexpath, "titIxWznmVLocale", "lcl2", null, 0);
			srefIxWznmVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "srefIxWznmVUserlevel", "ulv", null, 0);
			titIxWznmVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "titIxWznmVUserlevel", "ulv2", null, 0);
			
			return true;
		};

		return false;
	};
};

