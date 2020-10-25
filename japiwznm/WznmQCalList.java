/**
  * \file WznmQCalList.h
  * Java API code for record of table TblWznmQCalList
  * \author Alexander Wirthmueller
  * \date created: 27 Aug 2020
  * \date modified: 27 Aug 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQCalList {
	
	public WznmQCalList(
				int jnum
				, String sref
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubRefWznmMVersion
				, String srefRefIxVTbl
				, String titRefIxVTbl
				, String stubRefUref
				, String srefsInvIxWznmWArgtype
				, String titsInvIxWznmWArgtype
				, String srefsRetIxWznmWArgtype
				, String titsRetIxWznmWArgtype
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubRefWznmMVersion = stubRefWznmMVersion;
		this.srefRefIxVTbl = srefRefIxVTbl;
		this.titRefIxVTbl = titRefIxVTbl;
		this.stubRefUref = stubRefUref;
		this.srefsInvIxWznmWArgtype = srefsInvIxWznmWArgtype;
		this.titsInvIxWznmWArgtype = titsInvIxWznmWArgtype;
		this.srefsRetIxWznmWArgtype = srefsRetIxWznmWArgtype;
		this.titsRetIxWznmWArgtype = titsRetIxWznmWArgtype;
	};

	public int jnum;
	public String sref;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubRefWznmMVersion;
	public String srefRefIxVTbl;
	public String titRefIxVTbl;
	public String stubRefUref;
	public String srefsInvIxWznmWArgtype;
	public String titsInvIxWznmWArgtype;
	public String srefsRetIxWznmWArgtype;
	public String titsRetIxWznmWArgtype;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQCalList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubRefWznmMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWznmMVersion", "ver", null, 0);
			srefRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefRefIxVTbl", "ret", null, 0);
			titRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titRefIxVTbl", "ret2", null, 0);
			stubRefUref = Xmlio.extractStringUclc(doc, basexpath, "stubRefUref", "reu", null, 0);
			srefsInvIxWznmWArgtype = Xmlio.extractStringUclc(doc, basexpath, "srefsInvIxWznmWArgtype", "iat", null, 0);
			titsInvIxWznmWArgtype = Xmlio.extractStringUclc(doc, basexpath, "titsInvIxWznmWArgtype", "iat2", null, 0);
			srefsRetIxWznmWArgtype = Xmlio.extractStringUclc(doc, basexpath, "srefsRetIxWznmWArgtype", "rat", null, 0);
			titsRetIxWznmWArgtype = Xmlio.extractStringUclc(doc, basexpath, "titsRetIxWznmWArgtype", "rat2", null, 0);
			
			return true;
		};

		return false;
	};
};

