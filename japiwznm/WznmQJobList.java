/**
  * \file WznmQJobList.h
  * Java API code for record of table TblWznmQJobList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQJobList {
	
	public WznmQJobList(
				int jnum
				, String sref
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubRefWznmMVersion
				, String srefRefIxVTbl
				, String titRefIxVTbl
				, String stubRefUref
				, String yesnoGlobal
				, String yesnoClisrv
				, String yesnoShrdat
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubRefWznmMVersion = stubRefWznmMVersion;
		this.srefRefIxVTbl = srefRefIxVTbl;
		this.titRefIxVTbl = titRefIxVTbl;
		this.stubRefUref = stubRefUref;
		this.yesnoGlobal = yesnoGlobal;
		this.yesnoClisrv = yesnoClisrv;
		this.yesnoShrdat = yesnoShrdat;
	};

	public int jnum;
	public String sref;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubRefWznmMVersion;
	public String srefRefIxVTbl;
	public String titRefIxVTbl;
	public String stubRefUref;
	public String yesnoGlobal;
	public String yesnoClisrv;
	public String yesnoShrdat;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQJobList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVersion", "ver", null, 0);
			srefRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefRefIxVTbl", "ret", null, 0);
			titRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titRefIxVTbl", "ret2", null, 0);
			stubRefUref = Xmlio.extractStringUclc(doc, basexpath, "stubRefUref", "reu", null, 0);
			yesnoGlobal = Xmlio.extractStringUclc(doc, basexpath, "yesnoGlobal", "gbl", null, 0);
			yesnoClisrv = Xmlio.extractStringUclc(doc, basexpath, "yesnoClisrv", "cls", null, 0);
			yesnoShrdat = Xmlio.extractStringUclc(doc, basexpath, "yesnoShrdat", "shd", null, 0);
			
			return true;
		};

		return false;
	};
};

