/**
  * \file WznmQJobACmd.h
  * Java API code for record of table TblWznmQJobACmd
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwznm;

import org.w3c.dom.*;
import sbecore.*;

public class WznmQJobACmd {
	
	public WznmQJobACmd(
				int jnum
				, String sref
				, String Comment
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Comment = Comment;
	};

	public int jnum;
	public String sref;
	public String Comment;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WznmQJobACmd");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Comment = Xmlio.extractStringUclc(doc, basexpath, "Comment", "cmt", null, 0);
			
			return true;
		};

		return false;
	};
};
