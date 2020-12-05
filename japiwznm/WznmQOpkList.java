/**
	* \file WznmQOpkList.h
	* Java API code for record of table TblWznmQOpkList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQOpkList {
	
	public WznmQOpkList(
				int jnum
				, String sref
				, String Title
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubRefWznmMVersion
				, String yesnoShrdat
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubRefWznmMVersion = stubRefWznmMVersion;
		this.yesnoShrdat = yesnoShrdat;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubRefWznmMVersion;
	public String yesnoShrdat;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQOpkList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVersion", "ver", null, 0);
			yesnoShrdat = Xmlio.extractStringUclc(doc, basexpath, "yesnoShrdat", "shd", null, 0);
			
			return true;
		};

		return false;
	};
};

