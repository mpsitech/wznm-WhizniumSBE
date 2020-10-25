/**
  * \file WznmQMtdList.h
  * Java API code for record of table TblWznmQMtdList
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQMtdList {
	
	public WznmQMtdList(
				int jnum
				, String sref
				, String stubRefWznmMJob
				, String yesnoExecsrv
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubRefWznmMJob = stubRefWznmMJob;
		this.yesnoExecsrv = yesnoExecsrv;
	};

	public int jnum;
	public String sref;
	public String stubRefWznmMJob;
	public String yesnoExecsrv;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQMtdList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWznmMJob = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMJob", "job", null, 0);
			yesnoExecsrv = Xmlio.extractStringUclc(doc, basexpath, "yesnoExecsrv", "exs", null, 0);
			
			return true;
		};

		return false;
	};
};

