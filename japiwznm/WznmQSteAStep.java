/**
  * \file WznmQSteAStep.h
  * Java API code for record of table TblWznmQSteAStep
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQSteAStep {
	
	public WznmQSteAStep(
				int jnum
				, String stubSnxRefWznmMState
				, String srefIxVTrigger
				, String titIxVTrigger
				, String stubRefWznmMRtjob
				, String stubRefWznmMVectoritem
				, String xsref
				, String stubRefWznmMRtdpch
				, String srefsMask
				, String Cond
				, String yesnoCustcode
			) {
		this.jnum = jnum;
		this.stubSnxRefWznmMState = stubSnxRefWznmMState;
		this.srefIxVTrigger = srefIxVTrigger;
		this.titIxVTrigger = titIxVTrigger;
		this.stubRefWznmMRtjob = stubRefWznmMRtjob;
		this.stubRefWznmMVectoritem = stubRefWznmMVectoritem;
		this.xsref = xsref;
		this.stubRefWznmMRtdpch = stubRefWznmMRtdpch;
		this.srefsMask = srefsMask;
		this.Cond = Cond;
		this.yesnoCustcode = yesnoCustcode;
	};

	public int jnum;
	public String stubSnxRefWznmMState;
	public String srefIxVTrigger;
	public String titIxVTrigger;
	public String stubRefWznmMRtjob;
	public String stubRefWznmMVectoritem;
	public String xsref;
	public String stubRefWznmMRtdpch;
	public String srefsMask;
	public String Cond;
	public String yesnoCustcode;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQSteAStep");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubSnxRefWznmMState = Xmlio.extractStringUclc(doc, basexpath, "stubSnxRefWznmMState", "snx", null, 0);
			srefIxVTrigger = Xmlio.extractStringUclc(doc, basexpath, "srefIxVTrigger", "trg", null, 0);
			titIxVTrigger = Xmlio.extractStringUclc(doc, basexpath, "titIxVTrigger", "trg2", null, 0);
			stubRefWznmMRtjob = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMRtjob", "rtj", null, 0);
			stubRefWznmMVectoritem = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVectoritem", "vit", null, 0);
			xsref = Xmlio.extractStringUclc(doc, basexpath, "xsref", "xsr", null, 0);
			stubRefWznmMRtdpch = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMRtdpch", "rtd", null, 0);
			srefsMask = Xmlio.extractStringUclc(doc, basexpath, "srefsMask", "msk", null, 0);
			Cond = Xmlio.extractStringUclc(doc, basexpath, "Cond", "cnd", null, 0);
			yesnoCustcode = Xmlio.extractStringUclc(doc, basexpath, "yesnoCustcode", "ccd", null, 0);
			
			return true;
		};

		return false;
	};
};

