/**
  * \file WznmQSteAAction.h
  * Java API code for record of table TblWznmQSteAAction
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQSteAAction {
	
	public WznmQSteAAction(
				int jnum
				, String srefIxVSection
				, String titIxVSection
				, String srefIxVType
				, String titIxVType
				, String stubRefWznmMRtjob
				, String stubRefWznmMVector
				, String stubRefWznmMVectoritem
				, String stubSnxRefWznmMState
				, String stubRefWznmMSequence
				, String tr1SrefATrig
				, String Ip1
				, String tr2SrefATrig
				, String Ip2
				, String tr3SrefATrig
				, String Ip3
				, String tr4SrefATrig
				, String Ip4
			) {
		this.jnum = jnum;
		this.srefIxVSection = srefIxVSection;
		this.titIxVSection = titIxVSection;
		this.srefIxVType = srefIxVType;
		this.titIxVType = titIxVType;
		this.stubRefWznmMRtjob = stubRefWznmMRtjob;
		this.stubRefWznmMVector = stubRefWznmMVector;
		this.stubRefWznmMVectoritem = stubRefWznmMVectoritem;
		this.stubSnxRefWznmMState = stubSnxRefWznmMState;
		this.stubRefWznmMSequence = stubRefWznmMSequence;
		this.tr1SrefATrig = tr1SrefATrig;
		this.Ip1 = Ip1;
		this.tr2SrefATrig = tr2SrefATrig;
		this.Ip2 = Ip2;
		this.tr3SrefATrig = tr3SrefATrig;
		this.Ip3 = Ip3;
		this.tr4SrefATrig = tr4SrefATrig;
		this.Ip4 = Ip4;
	};

	public int jnum;
	public String srefIxVSection;
	public String titIxVSection;
	public String srefIxVType;
	public String titIxVType;
	public String stubRefWznmMRtjob;
	public String stubRefWznmMVector;
	public String stubRefWznmMVectoritem;
	public String stubSnxRefWznmMState;
	public String stubRefWznmMSequence;
	public String tr1SrefATrig;
	public String Ip1;
	public String tr2SrefATrig;
	public String Ip2;
	public String tr3SrefATrig;
	public String Ip3;
	public String tr4SrefATrig;
	public String Ip4;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQSteAAction");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefIxVSection = Xmlio.extractStringUclc(doc, basexpath, "srefIxVSection", "sct", null, 0);
			titIxVSection = Xmlio.extractStringUclc(doc, basexpath, "titIxVSection", "sct2", null, 0);
			srefIxVType = Xmlio.extractStringUclc(doc, basexpath, "srefIxVType", "typ", null, 0);
			titIxVType = Xmlio.extractStringUclc(doc, basexpath, "titIxVType", "typ2", null, 0);
			stubRefWznmMRtjob = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMRtjob", "trj", null, 0);
			stubRefWznmMVector = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVector", "vec", null, 0);
			stubRefWznmMVectoritem = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVectoritem", "vit", null, 0);
			stubSnxRefWznmMState = Xmlio.extractStringUclc(doc, basexpath, "stubSnxRefWznmMState", "snx", null, 0);
			stubRefWznmMSequence = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMSequence", "seq", null, 0);
			tr1SrefATrig = Xmlio.extractStringUclc(doc, basexpath, "tr1SrefATrig", "tr1", null, 0);
			Ip1 = Xmlio.extractStringUclc(doc, basexpath, "Ip1", "ip1", null, 0);
			tr2SrefATrig = Xmlio.extractStringUclc(doc, basexpath, "tr2SrefATrig", "tr2", null, 0);
			Ip2 = Xmlio.extractStringUclc(doc, basexpath, "Ip2", "ip2", null, 0);
			tr3SrefATrig = Xmlio.extractStringUclc(doc, basexpath, "tr3SrefATrig", "tr3", null, 0);
			Ip3 = Xmlio.extractStringUclc(doc, basexpath, "Ip3", "ip3", null, 0);
			tr4SrefATrig = Xmlio.extractStringUclc(doc, basexpath, "tr4SrefATrig", "tr4", null, 0);
			Ip4 = Xmlio.extractStringUclc(doc, basexpath, "Ip4", "ip4", null, 0);
			
			return true;
		};

		return false;
	};
};

