/**
  * \file WznmQSteList.h
  * Java API code for record of table TblWznmQSteList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQSteList {
	
	public WznmQSteList(
				int jnum
				, String sref
				, String stubSeqRefWznmMSequence
				, String srefEacIxVAction
				, String titEacIxVAction
				, String srefLacIxVAction
				, String titLacIxVAction
				, String yesnoCuststep
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubSeqRefWznmMSequence = stubSeqRefWznmMSequence;
		this.srefEacIxVAction = srefEacIxVAction;
		this.titEacIxVAction = titEacIxVAction;
		this.srefLacIxVAction = srefLacIxVAction;
		this.titLacIxVAction = titLacIxVAction;
		this.yesnoCuststep = yesnoCuststep;
	};

	public int jnum;
	public String sref;
	public String stubSeqRefWznmMSequence;
	public String srefEacIxVAction;
	public String titEacIxVAction;
	public String srefLacIxVAction;
	public String titLacIxVAction;
	public String yesnoCuststep;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQSteList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubSeqRefWznmMSequence = Xmlio.extractStringUclc(doc, basexpath, "stubSeqRefWznmMSequence", "seq", null, 0);
			srefEacIxVAction = Xmlio.extractStringUclc(doc, basexpath, "srefEacIxVAction", "eac", null, 0);
			titEacIxVAction = Xmlio.extractStringUclc(doc, basexpath, "titEacIxVAction", "eac2", null, 0);
			srefLacIxVAction = Xmlio.extractStringUclc(doc, basexpath, "srefLacIxVAction", "lac", null, 0);
			titLacIxVAction = Xmlio.extractStringUclc(doc, basexpath, "titLacIxVAction", "lac2", null, 0);
			yesnoCuststep = Xmlio.extractStringUclc(doc, basexpath, "yesnoCuststep", "cst", null, 0);
			
			return true;
		};

		return false;
	};
};

