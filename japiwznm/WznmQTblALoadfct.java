/**
  * \file WznmQTblALoadfct.h
  * Java API code for record of table TblWznmQTblALoadfct
  * \author Alexander Wirthmueller
  * \date created: 25 Aug 2020
  * \date modified: 25 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQTblALoadfct {
	
	public WznmQTblALoadfct(
				int jnum
				, String srefIxVLoadtype
				, String titIxVLoadtype
				, String Fctname
				, String ldSrefWznmMTablecol
				, String lbySrefsWznmMTablecol
				, String ordSrefsWznmMTablecol
				, String srefIxVLimtype
				, String titIxVLimtype
			) {
		this.jnum = jnum;
		this.srefIxVLoadtype = srefIxVLoadtype;
		this.titIxVLoadtype = titIxVLoadtype;
		this.Fctname = Fctname;
		this.ldSrefWznmMTablecol = ldSrefWznmMTablecol;
		this.lbySrefsWznmMTablecol = lbySrefsWznmMTablecol;
		this.ordSrefsWznmMTablecol = ordSrefsWznmMTablecol;
		this.srefIxVLimtype = srefIxVLimtype;
		this.titIxVLimtype = titIxVLimtype;
	};

	public int jnum;
	public String srefIxVLoadtype;
	public String titIxVLoadtype;
	public String Fctname;
	public String ldSrefWznmMTablecol;
	public String lbySrefsWznmMTablecol;
	public String ordSrefsWznmMTablecol;
	public String srefIxVLimtype;
	public String titIxVLimtype;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQTblALoadfct");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefIxVLoadtype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVLoadtype", "lot", null, 0);
			titIxVLoadtype = Xmlio.extractStringUclc(doc, basexpath, "titIxVLoadtype", "lot2", null, 0);
			Fctname = Xmlio.extractStringUclc(doc, basexpath, "Fctname", "fna", null, 0);
			ldSrefWznmMTablecol = Xmlio.extractStringUclc(doc, basexpath, "ldSrefWznmMTablecol", "ldx", null, 0);
			lbySrefsWznmMTablecol = Xmlio.extractStringUclc(doc, basexpath, "lbySrefsWznmMTablecol", "lby", null, 0);
			ordSrefsWznmMTablecol = Xmlio.extractStringUclc(doc, basexpath, "ordSrefsWznmMTablecol", "ord", null, 0);
			srefIxVLimtype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVLimtype", "lit", null, 0);
			titIxVLimtype = Xmlio.extractStringUclc(doc, basexpath, "titIxVLimtype", "lit2", null, 0);
			
			return true;
		};

		return false;
	};
};

