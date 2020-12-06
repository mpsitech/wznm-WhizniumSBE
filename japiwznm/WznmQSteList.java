/**
	* \file WznmQSteList.h
	* Java API code for record of table TblWznmQSteList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQSteList {
	
	public WznmQSteList(
				int jnum
				, String sref
				, String stubSeqRefWznmMSequence
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubSeqRefWznmMSequence = stubSeqRefWznmMSequence;
	};

	public int jnum;
	public String sref;
	public String stubSeqRefWznmMSequence;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQSteList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubSeqRefWznmMSequence = Xmlio.extractStringUclc(doc, basexpath, "stubSeqRefWznmMSequence", "seq", null, 0);
			
			return true;
		};

		return false;
	};
};
