/**
  * \file WznmQVerList.h
  * Java API code for record of table TblWznmQVerList
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQVerList {
	
	public WznmQVerList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String stubPrjRefWznmMProject
				, int Major
				, int Minor
				, int Sub
				, String stubBvrRefWznmMVersion
				, String stubRefWznmMLocale
				, String srefIxVState
				, String titIxVState
				, String srefsIxWDbmstype
				, String titsIxWDbmstype
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.stubPrjRefWznmMProject = stubPrjRefWznmMProject;
		this.Major = Major;
		this.Minor = Minor;
		this.Sub = Sub;
		this.stubBvrRefWznmMVersion = stubBvrRefWznmMVersion;
		this.stubRefWznmMLocale = stubRefWznmMLocale;
		this.srefIxVState = srefIxVState;
		this.titIxVState = titIxVState;
		this.srefsIxWDbmstype = srefsIxWDbmstype;
		this.titsIxWDbmstype = titsIxWDbmstype;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String stubPrjRefWznmMProject;
	public int Major;
	public int Minor;
	public int Sub;
	public String stubBvrRefWznmMVersion;
	public String stubRefWznmMLocale;
	public String srefIxVState;
	public String titIxVState;
	public String srefsIxWDbmstype;
	public String titsIxWDbmstype;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQVerList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			stubPrjRefWznmMProject = Xmlio.extractStringUclc(doc, basexpath, "stubPrjRefWznmMProject", "prj", null, 0);
			Major = Xmlio.extractIntegerUclc(doc, basexpath, "Major", "maj", null, 0);
			Minor = Xmlio.extractIntegerUclc(doc, basexpath, "Minor", "min", null, 0);
			Sub = Xmlio.extractIntegerUclc(doc, basexpath, "Sub", "sub", null, 0);
			stubBvrRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubBvrRefWznmMVersion", "bvr", null, 0);
			stubRefWznmMLocale = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMLocale", "loc", null, 0);
			srefIxVState = Xmlio.extractStringUclc(doc, basexpath, "srefIxVState", "ste", null, 0);
			titIxVState = Xmlio.extractStringUclc(doc, basexpath, "titIxVState", "ste2", null, 0);
			srefsIxWDbmstype = Xmlio.extractStringUclc(doc, basexpath, "srefsIxWDbmstype", "dty", null, 0);
			titsIxWDbmstype = Xmlio.extractStringUclc(doc, basexpath, "titsIxWDbmstype", "dty2", null, 0);
			
			return true;
		};

		return false;
	};
};

