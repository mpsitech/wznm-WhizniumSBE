/**
	* \file WznmQCtpList.h
	* Java API code for record of table TblWznmQCtpList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQCtpList {
	
	public WznmQCtpList(
				int jnum
				, String sref
				, String Title
				, String stubRefWznmMVersion
				, String srefsIxWArtefact
				, String titsIxWArtefact
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.stubRefWznmMVersion = stubRefWznmMVersion;
		this.srefsIxWArtefact = srefsIxWArtefact;
		this.titsIxWArtefact = titsIxWArtefact;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String stubRefWznmMVersion;
	public String srefsIxWArtefact;
	public String titsIxWArtefact;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQCtpList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVersion", "ver", null, 0);
			srefsIxWArtefact = Xmlio.extractStringUclc(doc, basexpath, "srefsIxWArtefact", "atf", null, 0);
			titsIxWArtefact = Xmlio.extractStringUclc(doc, basexpath, "titsIxWArtefact", "atf2", null, 0);
			
			return true;
		};

		return false;
	};
};

