/**
  * \file WznmQJobSupMNJob.h
  * Java API code for record of table TblWznmQJobSupMNJob
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQJobSupMNJob {
	
	public WznmQJobSupMNJob(
				int jnum
				, String stubMref
				, String Short
				, String yesnoMulti
				, String srefIxVConstract
				, String titIxVConstract
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
		this.Short = Short;
		this.yesnoMulti = yesnoMulti;
		this.srefIxVConstract = srefIxVConstract;
		this.titIxVConstract = titIxVConstract;
	};

	public int jnum;
	public String stubMref;
	public String Short;
	public String yesnoMulti;
	public String srefIxVConstract;
	public String titIxVConstract;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQJobSupMNJob");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			Short = Xmlio.extractStringUclc(doc, basexpath, "Short", "sho", null, 0);
			yesnoMulti = Xmlio.extractStringUclc(doc, basexpath, "yesnoMulti", "mlt", null, 0);
			srefIxVConstract = Xmlio.extractStringUclc(doc, basexpath, "srefIxVConstract", "csa", null, 0);
			titIxVConstract = Xmlio.extractStringUclc(doc, basexpath, "titIxVConstract", "csa2", null, 0);
			
			return true;
		};

		return false;
	};
};

