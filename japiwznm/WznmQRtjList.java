/**
	* \file WznmQRtjList.h
	* Java API code for record of table TblWznmQRtjList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQRtjList {
	
	public WznmQRtjList(
				int jnum
				, String sref
				, String stubRefWznmMApp
				, String stubSupRefWznmMRtjob
				, String stubRefWznmMJob
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubRefWznmMApp = stubRefWznmMApp;
		this.stubSupRefWznmMRtjob = stubSupRefWznmMRtjob;
		this.stubRefWznmMJob = stubRefWznmMJob;
	};

	public int jnum;
	public String sref;
	public String stubRefWznmMApp;
	public String stubSupRefWznmMRtjob;
	public String stubRefWznmMJob;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQRtjList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWznmMApp = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMApp", "app", null, 0);
			stubSupRefWznmMRtjob = Xmlio.extractStringUclc(doc, basexpath, "stubSupRefWznmMRtjob", "sup", null, 0);
			stubRefWznmMJob = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMJob", "job", null, 0);
			
			return true;
		};

		return false;
	};
};
