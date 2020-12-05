/**
	* \file WznmQConList.h
	* Java API code for record of table TblWznmQConList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQConList {
	
	public WznmQConList(
				int jnum
				, String sref
				, String Title
				, String srefIxVBasetype
				, String titIxVBasetype
				, String srefHkIxVTbl
				, String titHkIxVTbl
				, String stubHkUref
				, String srefHkIxVSection
				, String titHkIxVSection
				, String srefRefIxVTbl
				, String titRefIxVTbl
				, String stubRefUref
				, String stubSupRefWznmMControl
				, String srefIxVSubtype
				, String titIxVSubtype
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.srefHkIxVTbl = srefHkIxVTbl;
		this.titHkIxVTbl = titHkIxVTbl;
		this.stubHkUref = stubHkUref;
		this.srefHkIxVSection = srefHkIxVSection;
		this.titHkIxVSection = titHkIxVSection;
		this.srefRefIxVTbl = srefRefIxVTbl;
		this.titRefIxVTbl = titRefIxVTbl;
		this.stubRefUref = stubRefUref;
		this.stubSupRefWznmMControl = stubSupRefWznmMControl;
		this.srefIxVSubtype = srefIxVSubtype;
		this.titIxVSubtype = titIxVSubtype;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String srefHkIxVTbl;
	public String titHkIxVTbl;
	public String stubHkUref;
	public String srefHkIxVSection;
	public String titHkIxVSection;
	public String srefRefIxVTbl;
	public String titRefIxVTbl;
	public String stubRefUref;
	public String stubSupRefWznmMControl;
	public String srefIxVSubtype;
	public String titIxVSubtype;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQConList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			srefHkIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefHkIxVTbl", "hkt", null, 0);
			titHkIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titHkIxVTbl", "hkt2", null, 0);
			stubHkUref = Xmlio.extractStringUclc(doc, basexpath, "stubHkUref", "hku", null, 0);
			srefHkIxVSection = Xmlio.extractStringUclc(doc, basexpath, "srefHkIxVSection", "sct", null, 0);
			titHkIxVSection = Xmlio.extractStringUclc(doc, basexpath, "titHkIxVSection", "sct2", null, 0);
			srefRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefRefIxVTbl", "ret", null, 0);
			titRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titRefIxVTbl", "ret2", null, 0);
			stubRefUref = Xmlio.extractStringUclc(doc, basexpath, "stubRefUref", "reu", null, 0);
			stubSupRefWznmMControl = Xmlio.extractStringUclc(doc, basexpath, "stubSupRefWznmMControl", "sup", null, 0);
			srefIxVSubtype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVSubtype", "sty", null, 0);
			titIxVSubtype = Xmlio.extractStringUclc(doc, basexpath, "titIxVSubtype", "sty2", null, 0);
			
			return true;
		};

		return false;
	};
};

