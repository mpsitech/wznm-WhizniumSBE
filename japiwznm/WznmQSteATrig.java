/**
  * \file WznmQSteATrig.h
  * Java API code for record of table TblWznmQSteATrig
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQSteATrig {
	
	public WznmQSteATrig(
				int jnum
				, String sref
				, String srefIxVType
				, String titIxVType
				, String stubRefWznmMEvent
				, String stubRefWznmMRtjob
				, String stubRefWznmMVectoritem
				, String xsref
				, String stubRefWznmMRtdpch
				, String srefsMask
				, String Cond
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVType = srefIxVType;
		this.titIxVType = titIxVType;
		this.stubRefWznmMEvent = stubRefWznmMEvent;
		this.stubRefWznmMRtjob = stubRefWznmMRtjob;
		this.stubRefWznmMVectoritem = stubRefWznmMVectoritem;
		this.xsref = xsref;
		this.stubRefWznmMRtdpch = stubRefWznmMRtdpch;
		this.srefsMask = srefsMask;
		this.Cond = Cond;
	};

	public int jnum;
	public String sref;
	public String srefIxVType;
	public String titIxVType;
	public String stubRefWznmMEvent;
	public String stubRefWznmMRtjob;
	public String stubRefWznmMVectoritem;
	public String xsref;
	public String stubRefWznmMRtdpch;
	public String srefsMask;
	public String Cond;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQSteATrig");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVType = Xmlio.extractStringUclc(doc, basexpath, "srefIxVType", "typ", null, 0);
			titIxVType = Xmlio.extractStringUclc(doc, basexpath, "titIxVType", "typ2", null, 0);
			stubRefWznmMEvent = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMEvent", "evt", null, 0);
			stubRefWznmMRtjob = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMRtjob", "rtj", null, 0);
			stubRefWznmMVectoritem = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVectoritem", "vit", null, 0);
			xsref = Xmlio.extractStringUclc(doc, basexpath, "xsref", "xsr", null, 0);
			stubRefWznmMRtdpch = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMRtdpch", "rtd", null, 0);
			srefsMask = Xmlio.extractStringUclc(doc, basexpath, "srefsMask", "msk", null, 0);
			Cond = Xmlio.extractStringUclc(doc, basexpath, "Cond", "cnd", null, 0);
			
			return true;
		};

		return false;
	};
};

